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
 * @file    laiotdr.h
 * @brief   This module defines the OTDR for the LAI
 */

#if !defined (__LAIOTDR_H_)
#define __LAIOTDR_H_

#include <laitypes.h>

/**
 * @defgroup LAIOTDR LAI - OTDR specific API definitions
 *
 * @{
 */

/**
 * @brief OTDR attribute IDs
 */
typedef enum _lai_otdr_attr_t
{
    /**
     * @brief Start of attributes
     */
    LAI_OTDR_ATTR_START,

    /**
     * @brief Id
     *
     * @type lai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_OTDR_ATTR_ID = LAI_OTDR_ATTR_START,

    /**
     * @brief Refractive index
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OTDR_ATTR_REFRACTIVE_INDEX,

    /**
     * @brief Backscatter index
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OTDR_ATTR_BACKSCATTER_INDEX,

    /**
     * @brief Reflection threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OTDR_ATTR_REFLECTION_THRESHOLD,

    /**
     * @brief Splice loss threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OTDR_ATTR_SPLICE_LOSS_THRESHOLD,

    /**
     * @brief End of fiber threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OTDR_ATTR_END_OF_FIBER_THRESHOLD,

    /**
     * @brief Distance range
     *
     * @type lai_uint32_t
     * @flags CREATE_AND_SET
     */
    LAI_OTDR_ATTR_DISTANCE_RANGE,

    /**
     * @brief Pulse width
     *
     * @type lai_uint32_t
     * @flags CREATE_AND_SET
     */
    LAI_OTDR_ATTR_PULSE_WIDTH,

    /**
     * @brief Average time
     *
     * @type lai_uint32_t
     * @flags CREATE_AND_SET
     */
    LAI_OTDR_ATTR_AVERAGE_TIME,

    /**
     * @brief Output frequency
     *
     * @type lai_uint64_t
     * @flags CREATE_AND_SET
     */
    LAI_OTDR_ATTR_OUTPUT_FREQUENCY,

    /**
     * @brief Enabled
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    LAI_OTDR_ATTR_ENABLED,

    /**
     * @brief Scan
     *
     * @type bool
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_OTDR_ATTR_SCAN,

    /**
     * @brief Start time
     *
     * @type char
     * @flags CREATE_AND_SET
     */
    LAI_OTDR_ATTR_START_TIME,

    /**
     * @brief Period
     *
     * @type lai_uint32_t
     * @flags CREATE_AND_SET
     */
    LAI_OTDR_ATTR_PERIOD,

    /**
     * @brief Dynamic range
     *
     * @type lai_uint32_t
     * @flags READ_ONLY
     */
    LAI_OTDR_ATTR_DYNAMIC_RANGE,

    /**
     * @brief Distance accuracy
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_OTDR_ATTR_DISTANCE_ACCURACY,

    /**
     * @brief Sampling resolution
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_OTDR_ATTR_SAMPLING_RESOLUTION,

    /**
     * @brief Loss dead zone
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_OTDR_ATTR_LOSS_DEAD_ZONE,

    /**
     * @brief Reflection dead zone
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_OTDR_ATTR_REFLECTION_DEAD_ZONE,

    /**
     * @brief Scanning status
     *
     * @type lai_scanning_status_t
     * @flags READ_ONLY
     */
    LAI_OTDR_ATTR_SCANNING_STATUS,

    /**
     * @brief Serial No
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OTDR_ATTR_SERIAL_NO,

    /**
     * @brief Part no
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OTDR_ATTR_PART_NO,

    /**
     * @brief Manufacture name
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OTDR_ATTR_MFG_NAME,

    /**
     * @brief Manufacture date
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OTDR_ATTR_MFG_DATE,

    /**
     * @brief Hardware version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OTDR_ATTR_HARDWARE_VERSION,

    /**
     * @brief The operational state of the OTDR
     *
     * @type lai_oper_status_t
     * @flags READ_ONLY
     */
    LAI_OTDR_ATTR_OPER_STATUS,

    /**
     * @brief Whether the OTDR is present or not
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_OTDR_ATTR_EMPTY,

    /**
     * @brief Whether the OTDR is removable
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_OTDR_ATTR_REMOVABLE,

    /**
     * @brief Software version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OTDR_ATTR_SOFTWARE_VERSION,

    /**
     * @brief Firmware version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OTDR_ATTR_FIRMWARE_VERSION,

    /**
     * @brief End of attributes
     */
    LAI_OTDR_ATTR_END,

    /** Custom range base value */
    LAI_OTDR_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    LAI_OTDR_ATTR_CUSTOM_RANGE_END

} lai_otdr_attr_t;

/**
 * @brief OTDR stat IDs
 *
 * @flags Contains flags
 */
typedef enum _lai_otdr_stat_t
{
    /**
     * @brief Start of statistics
     */
    LAI_OTDR_STAT_START,

    /**
     * @brief A placeholder
     *
     * @type lai_uint64_t
     */
    LAI_OTDR_STAT_NOT_USE = LAI_OTDR_STAT_START,

    /**
     * @brief End of statistics
     */
    LAI_OTDR_STAT_END,

} lai_otdr_stat_t;

/**
 * @brief Create OTDR.
 *
 * Allocates and initializes a OTDR.
 *
 * @param[out] otdr_id OTDR id
 * @param[in] linecard_id Linecard id on which the OTDR exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_create_otdr_fn)(
        _Out_ lai_object_id_t *otdr_id,
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Remove OTDR
 *
 * @param[in] otdr_id OTDR id
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_remove_otdr_fn)(
        _In_ lai_object_id_t otdr_id);

/**
 * @brief Set OTDR attribute
 *
 * @param[in] otdr_id OTDR id
 * @param[in] attr Attribute
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_set_otdr_attribute_fn)(
        _In_ lai_object_id_t otdr_id,
        _In_ const lai_attribute_t *attr);

/**
 * @brief Get OTDR attribute
 *
 * @param[in] otdr_id OTDR id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_otdr_attribute_fn)(
        _In_ lai_object_id_t otdr_id,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

/**
 * @brief Get OTDR statistics.
 *
 * @param[in] otdr_id OTDR id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_otdr_stats_fn)(
        _In_ lai_object_id_t otdr_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Get OTDR statistics extended.
 *
 * @param[in] otdr_id OTDR id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_otdr_stats_ext_fn)(
        _In_ lai_object_id_t otdr_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _In_ lai_stats_mode_t mode,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Clear OTDR statistics counters.
 *
 * @param[in] otdr_id OTDR id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_clear_otdr_stats_fn)(
        _In_ lai_object_id_t otdr_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with lai_api_query()
 */
typedef struct _lai_otdr_api_t
{
    lai_create_otdr_fn                create_otdr;
    lai_remove_otdr_fn                remove_otdr;
    lai_set_otdr_attribute_fn         set_otdr_attribute;
    lai_get_otdr_attribute_fn         get_otdr_attribute;
    lai_get_otdr_stats_fn             get_otdr_stats;
    lai_get_otdr_stats_ext_fn         get_otdr_stats_ext;
    lai_clear_otdr_stats_fn           clear_otdr_stats;
} lai_otdr_api_t;

/**
 * @}
 */
#endif /** __LAIOTDR_H_ */
