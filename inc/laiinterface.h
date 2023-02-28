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
 * @file    laiinterface.h
 * @brief   This module defines the interface for the LAI
 */

#if !defined (__LAIINTERFACE_H_)
#define __LAIINTERFACE_H_

#include <laitypes.h>

/**
 * @defgroup LAIINTERFACE LAI - Interface specific API definitions
 *
 * @{
 */

/**
 * @brief The type of the interface
 */
typedef enum _lai_interface_type_t
{
    LAI_INTERFACE_TYPE_INVALID,
    LAI_INTERFACE_TYPE_CLIENT,
    LAI_INTERFACE_TYPE_OSC,
} lai_interface_type_t;

/**
 * @brief INTERFACE attribute IDs
 */
typedef enum _lai_interface_attr_t
{
    /**
     * @brief Start of attributes
     */
    LAI_INTERFACE_ATTR_START,

    /**
     * @brief Interface type
     *
     * @type lai_interface_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_INTERFACE_ATTR_INTERFACE_TYPE = LAI_INTERFACE_ATTR_START,

    /**
     * @brief Interface id
     *
     * @type lai_uint32_t
     * @flags CREATE_ONLY
     */
    LAI_INTERFACE_ATTR_INTERFACE_ID,

    /**
     * @brief Transceiver
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_INTERFACE_ATTR_TRANSCEIVER,

    /**
     * @brief Hardware port
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_INTERFACE_ATTR_HARDWARE_PORT,

    /**
     * @brief End of attributes
     */
    LAI_INTERFACE_ATTR_END,

    /** Custom range base value */
    LAI_INTERFACE_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    LAI_INTERFACE_ATTR_CUSTOM_RANGE_END

} lai_interface_attr_t;

/**
 * @brief INTERFACE stat IDs
 *
 * @flags Contains flags
 */
typedef enum _lai_interface_stat_t
{
    /**
     * @brief Start of statistics
     */
    LAI_INTERFACE_STAT_START,

    /**
     * @brief Out multicast pkts
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_OUT_MULTICAST_PKTS = LAI_INTERFACE_STAT_START,

    /**
     * @brief In octets
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_OCTETS,

    /**
     * @brief Out pkts
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_OUT_PKTS,

    /**
     * @brief Out broadcast pkts
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_OUT_BROADCAST_PKTS,

    /**
     * @brief Out octets
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_OUT_OCTETS,

    /**
     * @brief Last clear
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_LAST_CLEAR,

    /**
     * @brief In pkts
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_PKTS,

    /**
     * @brief In multicast pkts
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_MULTICAST_PKTS,

    /**
     * @brief In errors
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_ERRORS,

    /**
     * @brief In broadcast pkts
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_BROADCAST_PKTS,

    /**
     * @brief Out errors
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_OUT_ERRORS,

    /**
     * @brief In CRC errors
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_CRC_ERRORS,

    /**
     * @brief In under size frames
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_UNDERSIZE_FRAMES,

    /**
     * @brief In frames 1024 to 1518 octets
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_FRAMES_1024_1518_OCTETS,

    /**
     * @brief In frames 256 to 511 octets
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_FRAMES_256_511_OCTETS,

    /**
     * @brief In frames 65 to 127 octets
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_FRAMES_65_127_OCTETS,

    /**
     * @brief In frames 128 to 255 octets
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_FRAMES_128_255_OCTETS,

    /**
     * @brief In frames 512 to 1023 octets
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_FRAMES_512_1023_OCTETS,

    /**
     * @brief In frames 64 octets
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_FRAMES_64_OCTETS,

    /**
     * @brief In oversize frames
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_OVERSIZE_FRAMES,

    /**
     * @brief In jabber frames
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_JABBER_FRAMES,

    /**
     * @brief Carrier transitions
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_CARRIER_TRANSITIONS,

    /**
     * @brief In 8021q frames
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_8021Q_FRAMES,

    /**
     * @brief In block errors
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_BLOCK_ERRORS,

    /**
     * @brief In carrier errors
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_CARRIER_ERRORS,

    /**
     * @brief In discards
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_DISCARDS,

    /**
     * @brief In FCS errors
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_FCS_ERRORS,

    /**
     * @brief In fragment frames
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_FRAGMENT_FRAMES,

    /**
     * @brief In interrupted tx
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_INTERRUPTED_TX,

    /**
     * @brief In late collision
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_LATE_COLLISION,

    /**
     * @brief In MAC control frames
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_MAC_CONTROL_FRAMES,

    /**
     * @brief In MAC errors rx
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_MAC_ERRORS_RX,

    /**
     * @brief In MAC pause frames
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_MAC_PAUSE_FRAMES,

    /**
     * @brief In max size exceeded
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_MAXSIZE_EXCEEDED,

    /**
     * @brief In single collision
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_SINGLE_COLLISION,

    /**
     * @brief In symbol error
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_SYMBOL_ERROR,

    /**
     * @brief In unicast pkts
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_UNICAST_PKTS,

    /**
     * @brief In unknown protocol
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_IN_UNKNOWN_PROTOS,

    /**
     * @brief Out 8021q frames
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_OUT_8021Q_FRAMES,

    /**
     * @brief Out discards
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_OUT_DISCARDS,

    /**
     * @brief Out MAC control frames
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_OUT_MAC_CONTROL_FRAMES,

    /**
     * @brief Out MAC errors tx
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_OUT_MAC_ERRORS_TX,

    /**
     * @brief Out MAC pause frames
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_OUT_MAC_PAUSE_FRAMES,

    /**
     * @brief Out unicast pkts
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_INTERFACE_STAT_OUT_UNICAST_PKTS,

    /**
     * @brief End of statistics
     */
    LAI_INTERFACE_STAT_END,

} lai_interface_stat_t;

/**
 * @brief Create INTERFACE.
 *
 * Allocates and initializes a interface.
 *
 * @param[out] interface_id INTERFACE id
 * @param[in] linecard_id Linecard id on which the interface exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_create_interface_fn)(
        _Out_ lai_object_id_t *interface_id,
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Remove interface
 *
 * @param[in] interface_id INTERFACE id
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_remove_interface_fn)(
        _In_ lai_object_id_t interface_id);

/**
 * @brief Set interface attribute
 *
 * @param[in] interface_id INTERFACE id
 * @param[in] attr Attribute
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_set_interface_attribute_fn)(
        _In_ lai_object_id_t interface_id,
        _In_ const lai_attribute_t *attr);

/**
 * @brief Get interface attribute
 *
 * @param[in] interface_id INTERFACE id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_interface_attribute_fn)(
        _In_ lai_object_id_t interface_id,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

/**
 * @brief Get interface statistics.
 *
 * @param[in] interface_id INTERFACE id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_interface_stats_fn)(
        _In_ lai_object_id_t interface_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Get interface statistics extended.
 *
 * @param[in] interface_id INTERFACE id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_interface_stats_ext_fn)(
        _In_ lai_object_id_t interface_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _In_ lai_stats_mode_t mode,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Clear interface statistics counters.
 *
 * @param[in] interface_id INTERFACE id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_clear_interface_stats_fn)(
        _In_ lai_object_id_t interface_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with lai_api_query()
 */
typedef struct _lai_interface_api_t
{
    lai_create_interface_fn                create_interface;
    lai_remove_interface_fn                remove_interface;
    lai_set_interface_attribute_fn         set_interface_attribute;
    lai_get_interface_attribute_fn         get_interface_attribute;
    lai_get_interface_stats_fn             get_interface_stats;
    lai_get_interface_stats_ext_fn         get_interface_stats_ext;
    lai_clear_interface_stats_fn           clear_interface_stats;
} lai_interface_api_t;

/**
 * @}
 */
#endif /** __LAIINTERFACE_H_ */
