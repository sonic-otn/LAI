/**
 * Copyright (c) 2021 Alibaba Group.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 * @file    laimetadatautils.c
 *
 * @brief   This module implements LAI Metadata Utilities
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <lai.h>
#include "laimetadatautils.h"
#include "laimetadata.h"

bool lai_metadata_is_allowed_object_type(
        _In_ const lai_attr_metadata_t* metadata,
        _In_ lai_object_type_t object_type)
{
    if (metadata == NULL || metadata->allowedobjecttypes == NULL)
    {
        return false;
    }

    size_t i = 0;

    for (; i < metadata->allowedobjecttypeslength; ++i)
    {
        if (metadata->allowedobjecttypes[i] == object_type)
        {
            return true;
        }
    }

    return false;
}

bool lai_metadata_is_allowed_enum_value(
        _In_ const lai_attr_metadata_t* metadata,
        _In_ int value)
{
    if (metadata == NULL || metadata->enummetadata == NULL)
    {
        return false;
    }

    size_t i = 0;

    const lai_enum_metadata_t *emd = metadata->enummetadata;

    for (; i < emd->valuescount; ++i)
    {
        if (emd->values[i] == value)
        {
            return true;
        }
    }

    return false;
}

const lai_stat_metadata_t* lai_metadata_get_stat_metadata(
        _In_ lai_object_type_t objecttype,
        _In_ lai_stat_id_t statid)
{
    if (lai_metadata_is_object_type_valid(objecttype))
    {
        const lai_stat_metadata_t* const* const md = lai_metadata_stat_by_object_type[objecttype];

        const lai_object_type_info_t* oi = lai_metadata_all_object_type_infos[objecttype];
        if (statid < oi->statenum->valuescount)
        {
            return md[statid];
        }
    }

    return NULL;
}

const lai_attr_metadata_t* lai_metadata_get_attr_metadata(
        _In_ lai_object_type_t objecttype,
        _In_ lai_attr_id_t attrid)
{
    if (lai_metadata_is_object_type_valid(objecttype))
    {
        const lai_attr_metadata_t* const* const md = lai_metadata_attr_by_object_type[objecttype];

        /*
         * Most obejct attributes are not flags, so we can use direct index to
         * find attribute metadata, this should speed up search.
         */

        const lai_object_type_info_t* oi = lai_metadata_all_object_type_infos[objecttype];

        if (!oi->enummetadata->containsflags && attrid < oi->enummetadata->valuescount)
        {
            return md[attrid];
        }

        /* otherwise search one by one */

        size_t index = 0;

        for (; md[index] != NULL; index++)
        {
            if (md[index]->attrid == attrid)
            {
                return md[index];
            }
        }
    }

    return NULL;
}

const lai_attr_metadata_t* lai_metadata_get_attr_metadata_by_attr_id_name(
        _In_ const char *attr_id_name)
{
    if (attr_id_name == NULL)
    {
        return NULL;
    }

    /* use binary search */

    ssize_t first = 0;
    ssize_t last = (ssize_t)(lai_metadata_attr_sorted_by_id_name_count - 1);

    while (first <= last)
    {
        ssize_t middle = (first + last) / 2;

        int res = strcmp(attr_id_name, lai_metadata_attr_sorted_by_id_name[middle]->attridname);

        if (res > 0)
        {
            first = middle + 1;
        }
        else if (res < 0)
        {
            last = middle - 1;
        }
        else
        {
            /* found */

            return lai_metadata_attr_sorted_by_id_name[middle];
        }
    }

    /* not found */

    return NULL;
}

const lai_stat_metadata_t* lai_metadata_get_stat_metadata_by_stat_id_name(
        _In_ const char *stat_id_name)
{
    if (stat_id_name == NULL)
    {
        return NULL;
    }

    /* use binary search */

    ssize_t first = 0;
    ssize_t last = (ssize_t)(lai_metadata_stat_sorted_by_id_name_count - 1);

    while (first <= last)
    {
        ssize_t middle = (first + last) / 2;

        int res = strcmp(stat_id_name, lai_metadata_stat_sorted_by_id_name[middle]->statidname);

        if (res > 0)
        {
            first = middle + 1;
        }
        else if (res < 0)
        {
            last = middle - 1;
        }
        else
        {
            /* found */

            return lai_metadata_stat_sorted_by_id_name[middle];
        }
    }

    /* not found */

    return NULL;
}

const char* lai_metadata_get_enum_value_name(
        _In_ const lai_enum_metadata_t* metadata,
        _In_ int value)
{
    if (metadata == NULL)
    {
        return NULL;
    }

    size_t i = 0;

    for (; i < metadata->valuescount; ++i)
    {
        if (metadata->values[i] == value)
        {
            return metadata->valuesnames[i];
        }
    }

    return NULL;
}

const lai_attribute_t* lai_metadata_get_attr_by_id(
        _In_ lai_attr_id_t id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list)
{
    if (attr_list == NULL)
    {
        return NULL;
    }

    uint32_t i = 0;

    for (; i < attr_count; ++i)
    {
        if (attr_list[i].id == id)
        {
            return &attr_list[i];
        }
    }

    return NULL;
}

const lai_object_type_info_t* lai_metadata_get_object_type_info(
        _In_ lai_object_type_t object_type)
{
    if (lai_metadata_is_object_type_valid(object_type))
    {
        return lai_metadata_all_object_type_infos[object_type];
    }

    return NULL;
}

bool lai_metadata_is_object_type_oid(
        _In_ lai_object_type_t object_type)
{
    const lai_object_type_info_t* oti = lai_metadata_get_object_type_info(object_type);

    if (oti != NULL)
    {
        return oti->isobjectid;
    }

    return false;
}

bool lai_metadata_is_object_type_valid(
        _In_ lai_object_type_t object_type)
{
    return object_type > LAI_OBJECT_TYPE_NULL && object_type < LAI_OBJECT_TYPE_MAX;
}

bool lai_metadata_is_condition_met(
        _In_ const lai_attr_metadata_t *metadata,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list)
{
    if (metadata == NULL || !metadata->isconditional || attr_list == NULL)
    {
        return false;
    }

    size_t idx = 0;

    bool met = (metadata->conditiontype == LAI_ATTR_CONDITION_TYPE_AND);

    for (; idx < metadata->conditionslength; ++idx)
    {
        const lai_attr_condition_t *condition = metadata->conditions[idx];

        /*
         * Conditons may only be on the same object type.
         *
         * Default value may not exists if conditional object is marked as
         * MANDATORY_ON_CREATE.
         */

        const lai_attr_metadata_t *cmd = lai_metadata_get_attr_metadata(metadata->objecttype, condition->attrid);

        const lai_attribute_t *cattr = lai_metadata_get_attr_by_id(condition->attrid, attr_count, attr_list);

        const lai_attribute_value_t* cvalue = NULL;

        if (cattr == NULL)
        {
            /*
             * User didn't passed conditional attribute, so check if there is
             * default value.
             */

            cvalue = cmd->defaultvalue;
        }
        else
        {
            cvalue = &cattr->value;
        }

        if (cvalue == NULL)
        {
            /*
             * There is no default value and user didn't passed attribute.
             */

            if (metadata->conditiontype == LAI_ATTR_CONDITION_TYPE_AND)
            {
                return false;
            }

            continue;
        }

        bool current = false;

        switch (cmd->attrvaluetype)
        {
            case LAI_ATTR_VALUE_TYPE_BOOL:
                current = (condition->condition.booldata == cvalue->booldata);
                break;
            case LAI_ATTR_VALUE_TYPE_INT8:
                current = (condition->condition.s8 == cvalue->s8);
                break;
            case LAI_ATTR_VALUE_TYPE_INT16:
                current = (condition->condition.s16 == cvalue->s16);
                break;
            case LAI_ATTR_VALUE_TYPE_INT32:
                current = (condition->condition.s32 == cvalue->s32);
                break;
            case LAI_ATTR_VALUE_TYPE_INT64:
                current = (condition->condition.s64 == cvalue->s64);
                break;
            case LAI_ATTR_VALUE_TYPE_UINT8:
                current = (condition->condition.u8 == cvalue->u8);
                break;
            case LAI_ATTR_VALUE_TYPE_UINT16:
                current = (condition->condition.u16 == cvalue->u16);
                break;
            case LAI_ATTR_VALUE_TYPE_UINT32:
                current = (condition->condition.u32 == cvalue->u32);
                break;
            case LAI_ATTR_VALUE_TYPE_UINT64:
                current = (condition->condition.u64 == cvalue->u64);
                break;

            default:

                /*
                 * We should never get here since sanity check tests all
                 * attributes and all conditions.
                 */

                LAI_META_LOG_ERROR("condition value type %d is not supported, FIXME", cmd->attrvaluetype);

                return false;
        }

        if (metadata->conditiontype == LAI_ATTR_CONDITION_TYPE_AND)
        {
            met &= current;
        }
        else /* OR */
        {
            met |= current;
        }
    }

    return met;
}

