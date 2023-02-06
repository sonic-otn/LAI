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
 * @file    laiobject.h
 *
 * @brief   This module defines LAI APIs for bulk retrieval for each object-type
 */

#if !defined (__LAIOBJECT_H_)
#define __LAIOBJECT_H_

#include <laitypes.h>

/**
 * @defgroup LAIOBJECT LAI - Object API definitions.
 *
 * @{
 */

/**
 * @extraparam lai_object_type_t object_type
 */
typedef union _lai_object_key_entry_t
{
    /**
     * @brief Key is object ID.
     *
     * @validonly lai_metadata_is_object_type_oid(object_type) == true
     */
    lai_object_id_t           object_id;

} lai_object_key_entry_t;

/**
 * @brief Structure for bulk retrieval of object ids, attribute and values for
 * each object-type. Key will be used in case of object-types not having
 * object-ids.
 *
 * @extraparam lai_object_type_t object_type
 */
typedef struct _lai_object_key_t
{
    /** @passparam object_type */
    lai_object_key_entry_t key;

} lai_object_key_t;

/**
 * @brief Structure for attribute capabilities per operation
 */
typedef struct _lai_attr_capability_t
{
    /**
     * @brief Create is implemented
     */
    bool create_implemented;

    /**
     * @brief Set is implemented
     */
    bool set_implemented;

    /**
     * @brief Get is implemented
     */
    bool get_implemented;
} lai_attr_capability_t;

/**
 * @brief Query attribute capability
 *
 * @param[in] linecard_gid LAI Linecard object id
 * @param[in] object_type LAI object type
 * @param[in] attr_id LAI attribute ID
 * @param[out] attr_capability Capability per operation
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
lai_status_t lai_query_attribute_capability(
        _In_ lai_object_id_t linecard_gid,
        _In_ lai_object_type_t object_type,
        _In_ lai_attr_id_t attr_id,
        _Out_ lai_attr_capability_t *attr_capability);

/**
 * @brief Query an enum attribute (enum or enum list) list of implemented enum values
 *
 * @param[in] linecard_gid LAI Linecard object id
 * @param[in] object_type LAI object type
 * @param[in] attr_id LAI attribute ID
 * @param[inout] enum_values_capability List of implemented enum values
 *
 * @return #LAI_STATUS_SUCCESS on success, #LAI_STATUS_BUFFER_OVERFLOW if list size insufficient, failure status code on error
 */
lai_status_t lai_query_attribute_enum_values_capability(
        _In_ lai_object_id_t linecard_gid,
        _In_ lai_object_type_t object_type,
        _In_ lai_attr_id_t attr_id,
        _Inout_ lai_s32_list_t *enum_values_capability);

/**
 * @}
 */
#endif /** __LAIOBJECT_H_ */
