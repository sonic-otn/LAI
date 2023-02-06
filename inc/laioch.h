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
 * @file    laioch.h
 * @brief   This module defines the optical channel for the LAI
 */

#if !defined (__LAIOCH_H_)
#define __LAIOCH_H_

#include <laitypes.h>

/**
 * @defgroup LAIOCH LAI - Optical channel specific API definitions
 *
 * @{
 */

/**
 * @brief Optical channel attribute IDs
 */
typedef enum _lai_och_attr_t
{
    /**
     * @brief Start of attributes
     */
    LAI_OCH_ATTR_START,

    /**
     * @brief Client port or line port.
     *
     * @type lai_port_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_OCH_ATTR_PORT_TYPE = LAI_OCH_ATTR_START,

    /**
     * @brief Port ID.
     *
     * @type lai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_OCH_ATTR_PORT_ID,

    /**
     * @brief Type for optical spectrum frequency values
     *
     * @type lai_uint64_t
     * @flags CREATE_AND_SET
     */
    LAI_OCH_ATTR_FREQUENCY,

    /**
     * @brief Target output optical power level of the optical channel,
     * expressed in increments of 0.01 dBm
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OCH_ATTR_TARGET_OUTPUT_POWER,

    /**
     * @brief Vendor-specific mode identifier -- sets the operational
     * mode for the channel. The specified operational mode must
     * exist in the list of supported operational modes supplied
     * by the device
     *
     * @type char
     * @flags CREATE_AND_SET
     */
    LAI_OCH_ATTR_OPERATIONAL_MODE,

    /**
     * @brief The operational state of the och
     *
     * @type lai_oper_status_t
     * @flags READ_ONLY
     */
    LAI_OCH_ATTR_OPER_STATUS,

    /**
     * @brief End of attributes
     */
    LAI_OCH_ATTR_END,

    /** Custom range base value */
    LAI_OCH_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    LAI_OCH_ATTR_CUSTOM_RANGE_END

} lai_och_attr_t;

/**
 * @brief Optical channel counter IDs in lai_get_och_stats() call
 *
 * @flags Contains flags
 */
typedef enum _lai_och_stat_t
{
    /**
     * @brief Start of statistics
     */
    LAI_OCH_STAT_START,

    /**
     * @brief Group delay
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_OCH_STAT_GROUP_DELAY = LAI_OCH_STAT_START,

    /**
     * @brief Input power
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_OCH_STAT_INPUT_POWER,

    /**
     * @brief Chromatic dispersion
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_OCH_STAT_CHROMATIC_DISPERSION,

    /**
     * @brief Output power
     *
     * @type lai_double_t
     * @precision precision2
     * @unit dBm
     * @iscounter false
     */
    LAI_OCH_STAT_OUTPUT_POWER,

    /**
     * @brief Laser bias current
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_OCH_STAT_LASER_BIAS_CURRENT,

    /**
     * @brief Second ORDER polarization mode dispersion
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_OCH_STAT_SECOND_ORDER_POLARIZATION_MODE_DISPERSION,

    /**
     * @brief Polarization mode dispersion
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_OCH_STAT_POLARIZATION_MODE_DISPERSION,

    /**
     * @brief OSNR
     *
     * @type lai_double_t
     * @unit dB
     * @precision precision2
     * @iscounter false
     */
    LAI_OCH_STAT_OSNR,

    /**
     * @brief SOP Vector S1
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_OCH_STAT_SOP_VECTOR_S1,

    /**
     * @brief SOP Vector S2
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_OCH_STAT_SOP_VECTOR_S2,

    /**
     * @brief SOP Vector S3
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_OCH_STAT_SOP_VECTOR_S3,

    /**
     * @brief SOP change rate
     *
     * @type lai_uint32_t
     * @iscounter false
     */
    LAI_OCH_STAT_SOP_CHANGE_RATE,

    /**
     * @brief Tx laser age
     *
     * @type lai_uint32_t
     * @iscounter false
     */
    LAI_OCH_STAT_TX_LASER_AGE,

    /**
     * @brief Polarization dependent loss
     *
     * @type lai_double_t
     * @unit dB
     * @precision precision2
     * @iscounter false
     */
    LAI_OCH_STAT_POLARIZATION_DEPENDENT_LOSS,

    /**
     * @brief Input signal power
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_OCH_STAT_INPUT_SIGNAL_POWER,

    /**
     * @brief EDFA bias current
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_OCH_STAT_EDFA_BIAS_CURRENT,

    /**
     * @brief Actual received frequency offset. unit: MHz
     *
     * @type lai_int32_t
     * @iscounter false
     */
    LAI_OCH_STAT_ACTUAL_FREQUENCY_OFFSET,

    /**
     * @brief End of statistics
     */
    LAI_OCH_STAT_END,

} lai_och_stat_t;

/**
 * @brief Create optical channel.
 *
 * Allocates and initializes a optical channel.
 *
 * @param[out] och_id Optical channel id
 * @param[in] linecard_id Linecard id on which the optical channel exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_create_och_fn)(
        _Out_ lai_object_id_t *och_id,
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Remove optical channel
 *
 * @param[in] och_id Optical channel id
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_remove_och_fn)(
        _In_ lai_object_id_t och_id);

/**
 * @brief Set optical channel attribute
 *
 * @param[in] och_id Optical channel id
 * @param[in] attr Attribute
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_set_och_attribute_fn)(
        _In_ lai_object_id_t och_id,
        _In_ const lai_attribute_t *attr);

/**
 * @brief Get optical channel attribute
 *
 * @param[in] och_id Optical channel id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_och_attribute_fn)(
        _In_ lai_object_id_t och_id,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

/**
 * @brief Get optical channel counters. Deprecated for backward compatibility.
 *
 * @param[in] och_id Optical channel id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_och_stats_fn)(
        _In_ lai_object_id_t och_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Get optical channel statistics counters extended.
 *
 * @param[in] och_id Optical channel id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_och_stats_ext_fn)(
        _In_ lai_object_id_t och_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _In_ lai_stats_mode_t mode,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Clear optical channel statistics counters.
 *
 * @param[in] och_id Optical channel id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_clear_och_stats_fn)(
        _In_ lai_object_id_t och_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with lai_api_query()
 */
typedef struct _lai_och_api_t
{
    lai_create_och_fn              create_och;
    lai_remove_och_fn              remove_och;
    lai_set_och_attribute_fn       set_och_attribute;
    lai_get_och_attribute_fn       get_och_attribute;
    lai_get_och_stats_fn           get_och_stats;
    lai_get_och_stats_ext_fn       get_och_stats_ext;
    lai_clear_och_stats_fn         clear_och_stats;
} lai_och_api_t;

/**
 * @}
 */
#endif /** __LAIOCH_H_ */
