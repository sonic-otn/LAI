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
 * @file    laiport.h
 * @brief   This module defines the port for the LAI
 */

#if !defined (__LAIPORT_H_)
#define __LAIPORT_H_

#include <laitypes.h>

/**
 * @defgroup LAIPORT LAI - Port specific API definitions
 *
 * @{
 */
typedef enum _lai_port_optical_port_type_t
{
    LAI_PORT_OPTICAL_PORT_TYPE_EGRESS,
    LAI_PORT_OPTICAL_PORT_TYPE_ADD,
    LAI_PORT_OPTICAL_PORT_TYPE_DROP,
    LAI_PORT_OPTICAL_PORT_TYPE_MONITOR,
    LAI_PORT_OPTICAL_PORT_TYPE_TERMINAL_CLIENT,
    LAI_PORT_OPTICAL_PORT_TYPE_TERMINAL_LINE,
} lai_port_optical_port_type_t;

/**
 * @brief Port attribute IDs
 */
typedef enum _lai_port_attr_t
{
    /**
     * @brief Start of attributes
     */
    LAI_PORT_ATTR_START,

    /**
     * @brief Client port or line port.
     *
     * @type lai_port_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_PORT_ATTR_PORT_TYPE = LAI_PORT_ATTR_START,

    /**
     * @brief Port ID.
     *
     * @type lai_uint32_t
     * @flags CREATE_ONLY
     */
    LAI_PORT_ATTR_PORT_ID,

    /**
     * @brief Operational status
     *
     * @type lai_oper_status_t
     * @flags READ_ONLY
     */
    LAI_PORT_ATTR_OPER_STATUS,

    /**
     * @brief Admin state
     *
     * @type lai_admin_state_t
     * @flags CREATE_AND_SET
     */
    LAI_PORT_ATTR_ADMIN_STATE,

    /**
     * @brief Rx cd range
     *
     * @type lai_s32_range_t
     * @flags CREATE_AND_SET
     */
    LAI_PORT_ATTR_RX_CD_RANGE,

    /**
     * @brief Roll off
     *
     * @type lai_uint32_t
     * @flags CREATE_AND_SET
     */
    LAI_PORT_ATTR_ROLL_OFF,

    /**
     * @brief Led mode
     *
     * @type lai_led_mode_t
     * @flags CREATE_AND_SET
     * @isrecoverable false
     */
    LAI_PORT_ATTR_LED_MODE,

    /**
     * @brief Led flash interval
     *
     * @type lai_uint16_t
     * @flags CREATE_AND_SET
     * @isrecoverable false
     */
    LAI_PORT_ATTR_LED_FLASH_INTERVAL,

    /**
     * @brief Led color
     *
     * @type lai_led_color_t
     * @flags READ_ONLY
     */
    LAI_PORT_ATTR_LED_COLOR,

    /**
     * @brief Los threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_PORT_ATTR_LOS_THRESHOLD,

    /**
     * @brief Optical port type
     *
     * @type lai_port_optical_port_type_t
     * @flags READ_ONLY
     */
    LAI_PORT_ATTR_OPTICAL_PORT_TYPE,

    /**
     * @brief Empty
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_PORT_ATTR_EMPTY,

    /**
     * @brief Removable
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_PORT_ATTR_REMOVABLE,

    /**
     * @brief Equipment failure
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_PORT_ATTR_EQUIPMENT_FAILURE,

    /**
     * @brief Equipment mismatch
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_PORT_ATTR_EQUIPMENT_MISMATCH,

    /**
     * @brief Low threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_PORT_ATTR_LOW_THRESHOLD,

    /**
     * @brief High threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_PORT_ATTR_HIGH_THRESHOLD,

    /**
     * @brief Input offset
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_PORT_ATTR_INPUT_OFFSET,

    /**
     * @brief Output offset
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_PORT_ATTR_OUTPUT_OFFSET,

    /**
     * @brief Led name
     *
     * @type char
     * @flags CREATE_AND_SET
     * @isrecoverable false
     */
    LAI_PORT_ATTR_LED_NAME,

    /**
     * @brief End of attributes
     */
    LAI_PORT_ATTR_END,

    /** Custom range base value */
    LAI_PORT_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    LAI_PORT_ATTR_CUSTOM_RANGE_END

} lai_port_attr_t;

/**
 * @brief Port stat IDs
 *
 * @flags Contains flags
 */
typedef enum _lai_port_stat_t
{
    /**
     * @brief Start of statistics
     */
    LAI_PORT_STAT_START,

    /**
     * @brief Input power
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_PORT_STAT_INPUT_POWER = LAI_PORT_STAT_START,

    /**
     * @brief Output power
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_PORT_STAT_OUTPUT_POWER,

    /**
     * @brief OSC input power
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_PORT_STAT_OSC_INPUT_POWER,

    /**
     * @brief OSC output power
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_PORT_STAT_OSC_OUTPUT_POWER,

    /**
     * @brief End of statistics
     */
    LAI_PORT_STAT_END,

} lai_port_stat_t;

/**
 * @brief Create port.
 *
 * Allocates and initializes a port.
 *
 * @param[out] port_id Port id
 * @param[in] linecard_id Linecard id on which the port exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_create_port_fn)(
        _Out_ lai_object_id_t *port_id,
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Remove port
 *
 * @param[in] port_id Port id
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_remove_port_fn)(
        _In_ lai_object_id_t port_id);

/**
 * @brief Set port attribute
 *
 * @param[in] port_id Port id
 * @param[in] attr Attribute
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_set_port_attribute_fn)(
        _In_ lai_object_id_t port_id,
        _In_ const lai_attribute_t *attr);

/**
 * @brief Get port attribute
 *
 * @param[in] port_id Port id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_port_attribute_fn)(
        _In_ lai_object_id_t port_id,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

/**
 * @brief Get port statistics.
 *
 * @param[in] port_id Port id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_port_stats_fn)(
        _In_ lai_object_id_t port_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Get port statistics extended.
 *
 * @param[in] port_id Port id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_port_stats_ext_fn)(
        _In_ lai_object_id_t port_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _In_ lai_stats_mode_t mode,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Clear port statistics.
 *
 * @param[in] port_id Port id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_clear_port_stats_fn)(
        _In_ lai_object_id_t port_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids);

/**
 * @brief Port methods table retrieved with lai_api_query()
 */
typedef struct _lai_port_api_t
{
    lai_create_port_fn          create_port;
    lai_remove_port_fn          remove_port;
    lai_set_port_attribute_fn   set_port_attribute;
    lai_get_port_attribute_fn   get_port_attribute;
    lai_get_port_stats_fn       get_port_stats;
    lai_get_port_stats_ext_fn   get_port_stats_ext;
    lai_clear_port_stats_fn     clear_port_stats;
} lai_port_api_t;

/**
 * @}
 */
#endif /** __LAIPORT_H_ */
