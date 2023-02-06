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
 * @file    lailogicalchannel.h
 * @brief   This module defines the logical channel for the LAI
 */

#if !defined (__LAILOGICALCHANNEL_H_)
#define __LAILOGICALCHANNEL_H_

#include <laitypes.h>

/**
 * @defgroup LAILOGICALCHANNEL LAI - Logical channel specific API definitions
 *
 * @{
 */

/** @brief The loopback mode */
typedef enum _lai_logicalchannel_loopback_mode_t
{
    LAI_LOGICALCHANNEL_LOOPBACK_MODE_NONE,
    LAI_LOGICALCHANNEL_LOOPBACK_MODE_FACILITY,
    LAI_LOGICALCHANNEL_LOOPBACK_MODE_TERMINAL,
    LAI_LOGICALCHANNEL_LOOPBACK_MODE_MAX
} lai_logicalchannel_loopback_mode_t;

/** @brief The logical channel type */
typedef enum _lai_logicalchannel_type_t
{
    LAI_LOGICALCHANNEL_TYPE_PROT_OTN,
    LAI_LOGICALCHANNEL_TYPE_PROT_ETHERNET,
    LAI_LOGICALCHANNEL_TYPE_MAX
} lai_logicalchannel_type_t;

/** @brief Rate class */
typedef enum _lai_logicalchannel_rate_class_t
{
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_1G,       /**< 1G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_2_5G,     /**< 2.5G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_10G,      /**< 10G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_40G,      /**< 40G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_100G,     /**< 100G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_150G,     /**< 150G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_200G,     /**< 200G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_250G,     /**< 250G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_300G,     /**< 300G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_350G,     /**< 350G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_400G,     /**< 400G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_450G,     /**< 450G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_500G,     /**< 500G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_550G,     /**< 550G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_600G,     /**< 600G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_650G,     /**< 650G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_700G,     /**< 700G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_750G,     /**< 750G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_800G,     /**< 800G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_850G,     /**< 850G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_900G,     /**< 900G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_950G,     /**< 9500G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_1000G,     /**< 1000G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_1050G,     /**< 1050G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_1100G,     /**< 1100G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_1150G,     /**< 1150G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_1200G,     /**< 1200G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_1250G,     /**< 1250G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_1300G,     /**< 1300G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_1350G,     /**< 13500G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_1400G,     /**< 1400G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_1450G,     /**< 14500G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_1500G,     /**< 1500G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_1550G,     /**< 15500G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_1600G,     /**< 1600G tributary signal rate */
    LAI_LOGICALCHANNEL_RATE_CLASS_TRIB_RATE_MAX
} lai_logicalchannel_rate_class_t;

/** @brief Tributary protocol type */
typedef enum _lai_logicalchannel_trib_protocol_t
{
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_1GE,          /**< 1G Ethernet protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_OC48,         /**< OC48 protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_STM16,        /**< STM 16 protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_10GE_LAN,     /**< 10G Ethernet LAN protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_10GE_WAN,     /**< 10G Ethernet WAN protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_OC192,        /**< OC 192 (9.6GB) port protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_STM64,        /**< STM 64 protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_OTU2,         /**< OTU 2 protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_OTU2E,        /**< OTU 2e protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_OTU1E,        /**< OTU 1e protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_ODU2,         /**< ODU 2 protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_ODU2E,        /**< ODU 2e protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_40GE,         /**< 40G Ethernet port protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_OC768,        /**< OC 768 protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_STM256,       /**< STM 256 protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_OTU3,         /**< OTU 3 protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_ODU3,         /**< ODU 3 protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_100GE,        /**< 100G Ethernet protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_100G_MLG,     /**< 100G MLG protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_OTU4,         /**< OTU4 signal protocol (112G) protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_OTUCN,        /**< OTU Cn protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_ODUCN,        /**< ODU Cn protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_ODU4,         /**< ODU 4 protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_400GE,        /**< 400G Ethernet protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_OTSIG,        /**< Optical tributary signal group protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_ODUFLEX_CBR,  /**< ODU Flex with CBR protocol */
    LAI_LOGICALCHANNEL_TRIB_PROTOCOL_PROT_ODUFLEX_GFP,  /**< ODU Flex with GFP protocol */
} lai_logicalchannel_trib_protocol_t;

/** @brief Link state of the Ethernet protocol on the logical channel, SONET / SDH framed signal, etc. */
typedef enum _lai_logicalchannel_link_state_t
{
    /**< Logical channel is operationally up */
    LAI_LOGICALCHANNEL_LINK_STATE_UP,

    /**< Logical channel is operationally down */
    LAI_LOGICALCHANNEL_LINK_STATE_DOWN,

    /**< Logical channel is under test as a result of  enabling test-signal */
    LAI_LOGICALCHANNEL_LINK_STATE_TESTING,
} lai_logicalchannel_link_state_t;

typedef enum _lai_logicalchannel_test_signal_pattern_t
{
    LAI_LOGICALCHANNEL_TEST_SIGNAL_PATTERN_PRBS_PATTERN_TYPE_2E7,
    LAI_LOGICALCHANNEL_TEST_SIGNAL_PATTERN_PRBS_PATTERN_TYPE_2E9,
    LAI_LOGICALCHANNEL_TEST_SIGNAL_PATTERN_PRBS_PATTERN_TYPE_2E15,
    LAI_LOGICALCHANNEL_TEST_SIGNAL_PATTERN_PRBS_PATTERN_TYPE_2E23,
    LAI_LOGICALCHANNEL_TEST_SIGNAL_PATTERN_PRBS_PATTERN_TYPE_2E31,
    LAI_LOGICALCHANNEL_TEST_SIGNAL_PATTERN_PRBS_PATTERN_TYPE_31Q,
    LAI_LOGICALCHANNEL_TEST_SIGNAL_PATTERN_PRBS_PATTERN_TYPE_13Q,
    LAI_LOGICALCHANNEL_TEST_SIGNAL_PATTERN_PRBS_PATTERN_TYPE_2E11,
    LAI_LOGICALCHANNEL_TEST_SIGNAL_PATTERN_PRBS_PATTERN_TYPE_2E13,
    LAI_LOGICALCHANNEL_TEST_SIGNAL_PATTERN_PRBS_PATTERN_TYPE_NONE,
} lai_logicalchannel_test_signal_pattern_t;

/**
 * @brief Logical channel attribute IDs
 */
typedef enum _lai_logicalchannel_attr_t
{
    /**
     * @brief Start of attributes
     */
    LAI_LOGICALCHANNEL_ATTR_START,

    /**
     * @brief Logical channel ID
     *
     * @type lai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_LOGICALCHANNEL_ATTR_CHANNEL_ID = LAI_LOGICALCHANNEL_ATTR_START,

    /**
     * @brief Logical channel type
     *
     * @type lai_logicalchannel_type_t
     * @flags CREATE_AND_SET
     */
    LAI_LOGICALCHANNEL_ATTR_LOGICAL_CHANNEL_TYPE,

    /**
     * @brief Loopback mode
     *
     * @type lai_logicalchannel_loopback_mode_t
     * @flags CREATE_AND_SET
     */
    LAI_LOGICALCHANNEL_ATTR_LOOPBACK_MODE,

    /**
     * @brief Rate class
     *
     * @type lai_logicalchannel_rate_class_t
     * @flags CREATE_AND_SET
     */
    LAI_LOGICALCHANNEL_ATTR_RATE_CLASS,

    /**
     * @brief Tributary protocol type
     *
     * @type lai_logicalchannel_trib_protocol_t
     * @flags CREATE_AND_SET
     */
    LAI_LOGICALCHANNEL_ATTR_TRIB_PROTOCOL,

    /**
     * @brief Test signal
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    LAI_LOGICALCHANNEL_ATTR_TEST_SIGNAL,

    /**
     * @brief Admin state
     *
     * @type lai_admin_state_t
     * @flags CREATE_AND_SET
     */
    LAI_LOGICALCHANNEL_ATTR_ADMIN_STATE,

    /**
     * @brief Link state
     *
     * @type lai_logicalchannel_link_state_t
     * @flags CREATE_AND_SET
     */
    LAI_LOGICALCHANNEL_ATTR_LINK_STATE,

    /**
     * @brief Link down delay mode
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    LAI_LOGICALCHANNEL_ATTR_LINK_DOWN_DELAY_MODE,

    /**
     * @brief Link down delay hold off
     *
     * @type lai_uint32_t
     * @flags CREATE_AND_SET
     */
    LAI_LOGICALCHANNEL_ATTR_LINK_DOWN_DELAY_HOLD_OFF,

    /**
     * @brief Test signal pattern
     *
     * @type lai_logicalchannel_test_signal_pattern_t
     * @flags CREATE_AND_SET
     */
    LAI_LOGICALCHANNEL_ATTR_TEST_SIGNAL_PATTERN,

    /**
     * @brief Tx test signal pattern
     *
     * @type lai_logicalchannel_test_signal_pattern_t
     * @flags CREATE_AND_SET
     */
    LAI_LOGICALCHANNEL_ATTR_TX_TEST_SIGNAL_PATTERN,

    /**
     * @brief Rx test signal pattern
     *
     * @type lai_logicalchannel_test_signal_pattern_t
     * @flags CREATE_AND_SET
     */
    LAI_LOGICALCHANNEL_ATTR_RX_TEST_SIGNAL_PATTERN,

    /**
     * @brief Link up delay mode
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    LAI_LOGICALCHANNEL_ATTR_LINK_UP_DELAY_MODE,

    /**
     * @brief Link up delay hold off
     *
     * @type lai_uint32_t
     * @flags CREATE_AND_SET
     */
    LAI_LOGICALCHANNEL_ATTR_LINK_UP_DELAY_HOLD_OFF,

    /**
     * @brief Link up delay active threshold
     *
     * @type lai_uint32_t
     * @flags CREATE_AND_SET
     */
    LAI_LOGICALCHANNEL_ATTR_LINK_UP_DELAY_ACTIVE_THRESHOLD,

    /**
     * @brief End of attributes
     */
    LAI_LOGICALCHANNEL_ATTR_END,

    /** Custom range base value */
    LAI_LOGICALCHANNEL_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    LAI_LOGICALCHANNEL_ATTR_CUSTOM_RANGE_END

} lai_logicalchannel_attr_t;

/**
 * @brief Logical channel counter IDs in lai_get_logicalchannel_stats() call
 *
 * @flags Contains flags
 */
typedef enum _lai_logicalchannel_stat_t
{
    /**
     * @brief Start of statistics
     */
    LAI_LOGICALCHANNEL_STAT_START,

    /**
     * @brief A placeholder
     *
     * @type lai_uint64_t
     */
    LAI_LOGICALCHANNEL_STAT_NOT_USE = LAI_LOGICALCHANNEL_STAT_START,

    /**
     * @brief End of statistics
     */
    LAI_LOGICALCHANNEL_STAT_END,

} lai_logicalchannel_stat_t;

/**
 * @brief Create logical channel.
 *
 * Allocates and initializes a logical channel.
 *
 * @param[out] logicalchannel_id Logical channel id
 * @param[in] linecard_id Linecard id on which the logical channel exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_create_logicalchannel_fn)(
        _Out_ lai_object_id_t *logicalchannel_id,
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Remove logical channel
 *
 * @param[in] logicalchannel_id Logical channel id
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_remove_logicalchannel_fn)(
        _In_ lai_object_id_t logicalchannel_id);

/**
 * @brief Set logical channel attribute
 *
 * @param[in] logicalchannel_id Logical channel id
 * @param[in] attr Attribute
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_set_logicalchannel_attribute_fn)(
        _In_ lai_object_id_t logicalchannel_id,
        _In_ const lai_attribute_t *attr);

/**
 * @brief Get logical channel attribute
 *
 * @param[in] logicalchannel_id Logical channel id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_logicalchannel_attribute_fn)(
        _In_ lai_object_id_t logicalchannel_id,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

/**
 * @brief Get logical channel counters. Deprecated for backward compatibility.
 *
 * @param[in] logicalchannel_id Logical channel id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_logicalchannel_stats_fn)(
        _In_ lai_object_id_t logicalchannel_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Get logical channel statistics counters extended.
 *
 * @param[in] logicalchannel_id Logical channel id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_logicalchannel_stats_ext_fn)(
        _In_ lai_object_id_t logicalchannel_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _In_ lai_stats_mode_t mode,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Clear logical channel statistics counters.
 *
 * @param[in] logicalchannel_id Logical channel id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_clear_logicalchannel_stats_fn)(
        _In_ lai_object_id_t logicalchannel_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids);

/**
 * @brief Logical channel methods table retrieved with lai_api_query()
 */
typedef struct _lai_logicalchannel_api_t
{
    lai_create_logicalchannel_fn          create_logicalchannel;
    lai_remove_logicalchannel_fn          remove_logicalchannel;
    lai_set_logicalchannel_attribute_fn   set_logicalchannel_attribute;
    lai_get_logicalchannel_attribute_fn   get_logicalchannel_attribute;
    lai_get_logicalchannel_stats_fn       get_logicalchannel_stats;
    lai_get_logicalchannel_stats_ext_fn   get_logicalchannel_stats_ext;
    lai_clear_logicalchannel_stats_fn     clear_logicalchannel_stats;
} lai_logicalchannel_api_t;

/**
 * @}
 */
#endif /** __LAILOGICALCHANNEL_H_ */
