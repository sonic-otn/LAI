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
 * @file    laiapsport.h
 * @brief   This module defines the APSPORT for the LAI
 */

#if !defined (__LAIAPSPORT_H_)
#define __LAIAPSPORT_H_

#include <laitypes.h>

/**
 * @defgroup LAIAPSPORT LAI - APSPORT specific API definitions
 *
 * @{
 */

/** @brief APSPORT port type */
typedef enum _lai_apsport_port_type_t
{
    LAI_APSPORT_PORT_TYPE_LINE_PRIMARY_IN,
    LAI_APSPORT_PORT_TYPE_LINE_SECONDARY_IN,
    LAI_APSPORT_PORT_TYPE_COMMON_IN,
    LAI_APSPORT_PORT_TYPE_LINE_PRIMARY_OUT,
    LAI_APSPORT_PORT_TYPE_LINE_SECONDARY_OUT,
    LAI_APSPORT_PORT_TYPE_COMMON_OUTPUT
} lai_apsport_port_type_t;

/**
 * @brief APSPORT attribute IDs
 */
typedef enum _lai_apsport_attr_t
{
    /**
     * @brief Start of attributes
     */
    LAI_APSPORT_ATTR_START,

    /**
     * @brief ID
     *
     * @type lai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_APSPORT_ATTR_ID = LAI_APSPORT_ATTR_START,

    /**
     * @brief Port type
     *
     * @type lai_apsport_port_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_APSPORT_ATTR_PORT_TYPE,

    /**
     * @brief Power LOS threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_APSPORT_ATTR_POWER_LOS_THRESHOLD,

    /**
     * @brief Power low threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_APSPORT_ATTR_POWER_LOW_THRESHOLD,

    /**
     * @brief Enabled
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    LAI_APSPORT_ATTR_ENABLED,

    /**
     * @brief Target attenuation
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_APSPORT_ATTR_TARGET_ATTENUATION,

    /**
     * @brief End of attributes
     */
    LAI_APSPORT_ATTR_END,

    /** Custom range base value */
    LAI_APSPORT_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    LAI_APSPORT_ATTR_CUSTOM_RANGE_END

} lai_apsport_attr_t;

/**
 * @brief APSPORT stat IDs
 *
 * @flags Contains flags
 */
typedef enum _lai_apsport_stat_t
{
    /**
     * @brief Start of statistics
     */
    LAI_APSPORT_STAT_START,

    /**
     * @brief Optical power
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_APSPORT_STAT_OPTICAL_POWER = LAI_APSPORT_STAT_START,

    /**
     * @brief Attenuation
     *
     * @type lai_double_t
     * @unit dB
     * @precision precision2
     * @iscounter false
     */
    LAI_APSPORT_STAT_ATTENUATION,

    /**
     * @brief End of statistics
     */
    LAI_APSPORT_STAT_END,

} lai_apsport_stat_t;

/**
 * @brief Create APSPORT.
 *
 * Allocates and initializes a APSPORT.
 *
 * @param[out] apsport_id APSPORT id
 * @param[in] linecard_id Linecard id on which the APSPORT exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_create_apsport_fn)(
        _Out_ lai_object_id_t *apsport_id,
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Remove APSPORT
 *
 * @param[in] apsport_id APSPORT id
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_remove_apsport_fn)(
        _In_ lai_object_id_t apsport_id);

/**
 * @brief Set APSPORT attribute
 *
 * @param[in] apsport_id APSPORT id
 * @param[in] attr Attribute
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_set_apsport_attribute_fn)(
        _In_ lai_object_id_t apsport_id,
        _In_ const lai_attribute_t *attr);

/**
 * @brief Get APSPORT attribute
 *
 * @param[in] apsport_id APSPORT id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_apsport_attribute_fn)(
        _In_ lai_object_id_t apsport_id,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

/**
 * @brief Get APSPORT statistics.
 *
 * @param[in] apsport_id APSPORT id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_apsport_stats_fn)(
        _In_ lai_object_id_t apsport_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Get APSPORT statistics extended.
 *
 * @param[in] apsport_id APSPORT id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_apsport_stats_ext_fn)(
        _In_ lai_object_id_t apsport_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _In_ lai_stats_mode_t mode,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Clear APSPORT statistics counters.
 *
 * @param[in] apsport_id APSPORT id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_clear_apsport_stats_fn)(
        _In_ lai_object_id_t apsport_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with lai_api_query()
 */
typedef struct _lai_apsport_api_t
{
    lai_create_apsport_fn                create_apsport;
    lai_remove_apsport_fn                remove_apsport;
    lai_set_apsport_attribute_fn         set_apsport_attribute;
    lai_get_apsport_attribute_fn         get_apsport_attribute;
    lai_get_apsport_stats_fn             get_apsport_stats;
    lai_get_apsport_stats_ext_fn         get_apsport_stats_ext;
    lai_clear_apsport_stats_fn           clear_apsport_stats;
} lai_apsport_api_t;

/**
 * @}
 */
#endif /** __LAIAPSPORT_H_ */
