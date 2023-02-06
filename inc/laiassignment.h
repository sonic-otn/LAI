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
 * @file    laiassignment.h
 * @brief   This module defines the assignment for the LAI
 */

#if !defined (__LAIASSIGNMENT_H_)
#define __LAIASSIGNMENT_H_

#include <laitypes.h>

/**
 * @defgroup LAIASSIGNMENT LAI - Assignment specific API definitions
 *
 * @{
 */

/** @brief The assignment type */
typedef enum _lai_assignment_type_t
{
    LAI_ASSIGNMENT_TYPE_LOGICAL_CHANNEL,
    LAI_ASSIGNMENT_TYPE_OPTICAL_CHANNEL,
} lai_assignment_type_t;

/** @brief Assignment mapping type */
typedef enum _lai_assignment_mapping_t
{
    LAI_ASSIGNMENT_MAPPING_AMP,
    LAI_ASSIGNMENT_MAPPING_GMP,
    LAI_ASSIGNMENT_MAPPING_BMP,
    LAI_ASSIGNMENT_MAPPING_CBR,
    LAI_ASSIGNMENT_MAPPING_GFP_T,
    LAI_ASSIGNMENT_MAPPING_GFP_F,
} lai_assignment_mapping_t;

/**
 * @brief Assignment attribute IDs
 */
typedef enum _lai_assignment_attr_t
{
    /**
     * @brief Start of attributes
     */
    LAI_ASSIGNMENT_ATTR_START,

    /**
     * @brief The logical channel ID.
     *
     * @type lai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_ASSIGNMENT_ATTR_CHANNEL_ID = LAI_ASSIGNMENT_ATTR_START,

    /**
     * @brief Assignment ID.
     *
     * @type lai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_ASSIGNMENT_ATTR_ID,

    /**
     * @brief Description
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_ASSIGNMENT_ATTR_DESCRIPTION,

    /**
     * @brief Assignment type
     *
     * @type lai_assignment_type_t
     * @flags READ_ONLY
     */
    LAI_ASSIGNMENT_ATTR_ASSIGNMENT_TYPE,

    /**
     * @brief Optical channel name
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_ASSIGNMENT_ATTR_OPTICAL_CHANNEL,

    /**
     * @brief Logical channel index
     *
     * @type lai_uint32_t
     * @flags READ_ONLY
     */
    LAI_ASSIGNMENT_ATTR_LOGICAL_CHANNEL,

    /**
     * @brief Allocation
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_ASSIGNMENT_ATTR_ALLOCATION,

    /**
     * @brief Tributary slot index
     *
     * @type lai_int32_t
     * @flags READ_ONLY
     */
    LAI_ASSIGNMENT_ATTR_TRIBUTARY_SLOT_INDEX,

    /**
     * @brief Mapping
     *
     * @type lai_assignment_mapping_t
     * @flags READ_ONLY
     */
    LAI_ASSIGNMENT_ATTR_MAPPING,

    /**
     * @brief End of attributes
     */
    LAI_ASSIGNMENT_ATTR_END,

    /** Custom range base value */
    LAI_ASSIGNMENT_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    LAI_ASSIGNMENT_ATTR_CUSTOM_RANGE_END

} lai_assignment_attr_t;

/**
 * @brief Assignment stat IDs in lai_get_assignment_stats() call
 *
 * @flags Contains flags
 */
typedef enum _lai_assignment_stat_t
{
    /**
     * @brief Start of statistics
     */
    LAI_ASSIGNMENT_STAT_START,

    /**
     * @brief A placeholder
     *
     * @type lai_uint64_t
     */
    LAI_ASSIGNMENT_STAT_NOT_USE = LAI_ASSIGNMENT_STAT_START,

    /**
     * @brief End of statistics
     */
    LAI_ASSIGNMENT_STAT_END,

} lai_assignment_stat_t;

/**
 * @brief Create assignment.
 *
 * Allocates and initializes a assignment.
 *
 * @param[out] assignment_id Assignment id
 * @param[in] linecard_id Linecard id on which the assignment exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_create_assignment_fn)(
        _Out_ lai_object_id_t *assignment_id,
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Remove assignment
 *
 * @param[in] assignment_id Assignment id
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_remove_assignment_fn)(
        _In_ lai_object_id_t assignment_id);

/**
 * @brief Set assignment attribute
 *
 * @param[in] assignment_id Assignment id
 * @param[in] attr Attribute
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_set_assignment_attribute_fn)(
        _In_ lai_object_id_t assignment_id,
        _In_ const lai_attribute_t *attr);

/**
 * @brief Get assignment attribute
 *
 * @param[in] assignment_id Assignment id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_assignment_attribute_fn)(
        _In_ lai_object_id_t assignment_id,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

/**
 * @brief Get assignment counters. Deprecated for backward compatibility.
 *
 * @param[in] assignment_id Assignment id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_assignment_stats_fn)(
        _In_ lai_object_id_t assignment_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Get assignment statistics counters extended.
 *
 * @param[in] assignment_id Assignment id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_assignment_stats_ext_fn)(
        _In_ lai_object_id_t assignment_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _In_ lai_stats_mode_t mode,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Clear assignment statistics counters.
 *
 * @param[in] assignment_id Assignment id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_clear_assignment_stats_fn)(
        _In_ lai_object_id_t assignment_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with lai_api_query()
 */
typedef struct _lai_assignment_api_t
{
    lai_create_assignment_fn              create_assignment;
    lai_remove_assignment_fn              remove_assignment;
    lai_set_assignment_attribute_fn       set_assignment_attribute;
    lai_get_assignment_attribute_fn       get_assignment_attribute;
    lai_get_assignment_stats_fn           get_assignment_stats;
    lai_get_assignment_stats_ext_fn       get_assignment_stats_ext;
    lai_clear_assignment_stats_fn         clear_assignment_stats;
} lai_assignment_api_t;

/**
 * @}
 */
#endif /** __LAIASSIGNMENT_H_ */
