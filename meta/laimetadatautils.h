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
 * @file    laimetadatautils.h
 *
 * @brief   This module defines LAI Metadata Utilities
 */

#ifndef __LAIMETADATAUTILS_H_
#define __LAIMETADATAUTILS_H_

#include "laimetadatatypes.h"

/**
 * @defgroup LAIMETADATAUTILS LAI - Metadata Utilities Definitions
 *
 * @{
 */

/**
 * @brief Is allowed object type
 *
 * @param[in] metadata Attribute metadata
 * @param[in] object_type Object type to be checked
 *
 * @return True if object is allowed on this attribute, false otherwise
 */
extern bool lai_metadata_is_allowed_object_type(
        _In_ const lai_attr_metadata_t *metadata,
        _In_ lai_object_type_t object_type);

/**
 * @brief Is allowed enum value
 *
 * @param[in] metadata Attribute metadata
 * @param[in] value Enum value to be checked
 *
 * @return True if enum value is allowed on this attribute, false otherwise
 */
extern bool lai_metadata_is_allowed_enum_value(
        _In_ const lai_attr_metadata_t *metadata,
        _In_ int value);

/**
 * @brief Gets statistics metadata based on object type and statistics id
 *
 * @param[in] object_type Object type
 * @param[in] stat_id Statistics Id
 *
 * @return Pointer to object metadata or NULL in case of failure
 */
extern const lai_stat_metadata_t* lai_metadata_get_stat_metadata(
        _In_ lai_object_type_t object_type,
        _In_ lai_stat_id_t stat_id);

/**
 * @brief Gets attribute metadata based on object type and attribute id
 *
 * @param[in] object_type Object type
 * @param[in] attr_id Attribute Id
 *
 * @return Pointer to object metadata or NULL in case of failure
 */
extern const lai_attr_metadata_t* lai_metadata_get_attr_metadata(
        _In_ lai_object_type_t object_type,
        _In_ lai_attr_id_t attr_id);

/**
 * @brief Gets attribute metadata based on attribute id name
 *
 * @param[in] attr_id_name Attribute id name
 *
 * @return Pointer to object metadata or NULL in case of failure
 */
extern const lai_attr_metadata_t* lai_metadata_get_attr_metadata_by_attr_id_name(
        _In_ const char *attr_id_name);

/**
 * @brief Gets statistics metadata based on statistics id name
 *
 * @param[in] stat_id_name Statistics id name
 *
 * @return Pointer to object metadata or NULL in case of failure
 */
extern const lai_stat_metadata_t* lai_metadata_get_stat_metadata_by_stat_id_name(
        _In_ const char *stat_id_name);

/**
 * @brief Gets string representation of enum value
 *
 * @param[in] metadata Enum metadata
 * @param[in] value Enum value to be converted to string
 *
 * @return String representation of enum value or NULL if value was not found
 */
extern const char* lai_metadata_get_enum_value_name(
        _In_ const lai_enum_metadata_t *metadata,
        _In_ int value);

/**
 * @brief Gets attribute from attribute list by attribute id.
 *
 * @param[in] id Attribute id to be found.
 * @param[in] attr_count Total number of attributes.
 * @param[in] attr_list List of attributes to search.
 *
 * @return Attribute pointer with requested ID or NULL if not found.
 * When multiple attributes with the same id are passed, only first
 * attribute is returned.
 */
extern const lai_attribute_t* lai_metadata_get_attr_by_id(
        _In_ lai_attr_id_t id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Gets object type info
 *
 * @param[in] object_type Object type
 *
 * @return Object type info structure or NULL if not found
 */
extern const lai_object_type_info_t* lai_metadata_get_object_type_info(
        _In_ lai_object_type_t object_type);

/**
 * @brief Checks if object type is valid
 *
 * @param[in] object_type Object type
 *
 * @return True if object type is valid, false otherwise
 */
extern bool lai_metadata_is_object_type_valid(
        _In_ lai_object_type_t object_type);

/**
 * @brief Checks whether object type is OID object type.
 *
 * @param[in] object_type Object type to be checked.
 *
 * @return True if object type is OID type, false otherwise.
 */
extern bool lai_metadata_is_object_type_oid(
        _In_ lai_object_type_t object_type);

/**
 * @brief Check if condition met.
 *
 * List of attributes will be examined in terms of conditions. This is
 * convenient since user can pass list when calling create API. If
 * condition attribute is not on the list, then default value will be
 * examined.
 *
 * NOTE: When multiple attributes with the same ID are passed,
 * lai_metadata_get_attr_by_id will select only first one.
 * Function will not be able to handle multiple attributes
 *
 * @param[in] metadata Metadata of attribute that we need to check.
 * @param[in] attr_count Number of attributes.
 * @param[in] attr_list Attribute list to check. All attributes must
 * belong to the same object type as metadata parameter.
 *
 * @return True if condition is in force, false otherwise. False will be also
 * returned if any of input pointers is NULL or attribute is not conditional.
 */
extern bool lai_metadata_is_condition_met(
        _In_ const lai_attr_metadata_t *metadata,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Allocation info
 *
 * hint for the allocation
 */
typedef struct _lai_alloc_info_t
{
    uint32_t list_size;

    /**
     * @brief Reference attribute for size information
     */
    const lai_attribute_t *reference;
} lai_alloc_info_t;

/**
 * @brief Allocate lai_attribute_t value
 *
 * By passing info == NULL, it will use default list size for the list value
 * allocation
 *
 * @param[in] metadata Attribute metadata
 * @param[in] attr Attribute to allocate
 * @param[in] info Allocation information
 *
 * @return #LAI_STATUS_SUCCESS on success,
 * #LAI_STATUS_INVALID_PARAMETER/#LAI_STATUS_NO_MEMORY on failure
 */
extern lai_status_t lai_metadata_alloc_attr_value(
        _In_ const lai_attr_metadata_t *metadata,
        _In_ const lai_attribute_t *attr,
        _In_ const lai_alloc_info_t *info);

/**
 * @brief Free lai_attribute_t value
 *
 * @param[in] metadata Attribute metadata
 * @param[in] attr Attribute to free
 * @param[in] info Allocation information
 *
 * @return #LAI_STATUS_SUCCESS on success,
 * #LAI_STATUS_INVALID_PARAMETER on failure
 */
extern lai_status_t lai_metadata_free_attr_value(
        _In_ const lai_attr_metadata_t *metadata,
        _In_ const lai_attribute_t *attr,
        _In_ const lai_alloc_info_t *info);

/**
 * @brief Clear lai_attribute_t value
 *
 * @param[in] metadata Attribute metadata
 * @param[in] attr Attribute to clear
 *
 * @return #LAI_STATUS_SUCCESS on success,
 * #LAI_STATUS_INVALID_PARAMETER on failure
 */
extern lai_status_t lai_metadata_clear_attr_value(
        _In_ const lai_attr_metadata_t *metadata,
        _In_ const lai_attribute_t *attr);

/**
 * @brief Deep copy lai_attribute_t value
 *
 * @param[in] metadata Attribute metadata
 * @param[in] src Original attribute for the copy
 * @param[inout] dest Destination for the copy
 *
 * @return #LAI_STATUS_SUCCESS on success,
 * #LAI_STATUS_INVALID_PARAMETER on failure
 */
extern lai_status_t lai_metadata_deepcopy_attr_value(
        _In_ const lai_attr_metadata_t *metadata,
        _In_ const lai_attribute_t *src,
        _Inout_ lai_attribute_t *dest);

/**
 * @brief Deep equal lai_attribute_t value
 *
 * @param[in] metadata Attribute metadata
 * @param[in] lhs Left
 * @param[in] rhs Right
 * @param[out] result Result
 *
 * @return #LAI_STATUS_SUCCESS on success,
 * #LAI_STATUS_INVALID_PARAMETER on failure
 */
extern lai_status_t lai_metadata_deepequal_attr_value(
        _In_ const lai_attr_metadata_t *metadata,
        _In_ const lai_attribute_t *lhs,
        _In_ const lai_attribute_t *rhs,
        _Out_ bool *result);

/**
 * @}
 */
#endif /** __LAIMETADATAUTILS_H_ */
