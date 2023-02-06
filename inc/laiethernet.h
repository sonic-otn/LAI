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
 * @file    laiethernet.h
 * @brief   This module defines the Ethernet logical channel for the LAI
 */

#if !defined (__LAIETHERNET_H_)
#define __LAIETHERNET_H_

#include <laitypes.h>

/**
 * @defgroup LAIETHERNET LAI - Ethernet specific API definitions
 *
 * @{
 */

/** @brief The client ALS mode */
typedef enum _lai_ethernet_client_als_t
{
    /**
     * @brief None
     *
     * The client port will do nothing when a failure is
     * detected on the line port or the remote client port.
     */
    LAI_ETHERNET_CLIENT_ALS_NONE,

    /**
     * @brief Laser shutdown
     *
     * The client port will shut down the laser to notify the
     * subtending Ethernet equipment of the failure detected on
     * the line port or the remote client port.
     */
    LAI_ETHERNET_CLIENT_ALS_LASER_SHUTDOWN,

    /**
     * @brief Ethernet
     *
     * The client port will propagate the local fault or remote
     * fault signal to the subtending Ethernet equipment.
     */
    LAI_ETHERNET_CLIENT_ALS_ETHERNET,
} lai_ethernet_client_als_t;

/** @brief Maintenance */
typedef enum _lai_ethernet_maintenance_t
{
    LAI_ETHERNET_MAINTENANCE_LF,
    LAI_ETHERNET_MAINTENANCE_RF,
    LAI_ETHERNET_MAINTENANCE_IDLE,
    LAI_ETHERNET_MAINTENANCE_NONE,
} lai_ethernet_maintenance_t;

/**
 * @brief Ethernet attribute IDs
 */
typedef enum _lai_ethernet_attr_t
{
    /**
     * @brief Start of attributes
     */
    LAI_ETHERNET_ATTR_START,

    /**
     * @brief The logical channel ID
     *
     * @type lai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_ETHERNET_ATTR_CHANNEL_ID = LAI_ETHERNET_ATTR_START,

    /**
     * @brief Client ALS mode
     *
     * @type lai_ethernet_client_als_t
     * @flags CREATE_AND_SET
     */
    LAI_ETHERNET_ATTR_CLIENT_ALS,

    /**
     * @brief ALS delay
     *
     * @type lai_uint64_t
     * @flags CREATE_AND_SET
     */
    LAI_ETHERNET_ATTR_ALS_DELAY,

    /**
     * @brief Maintenance
     *
     * @type lai_ethernet_maintenance_t
     * @flags CREATE_AND_SET
     */
    LAI_ETHERNET_ATTR_MAINTENANCE,

    /**
     * @brief Client rx ALS
     *
     * @type lai_ethernet_client_als_t
     * @flags CREATE_AND_SET
     */
    LAI_ETHERNET_ATTR_CLIENT_RX_ALS,

    /**
     * @brief Client rx ALS delay
     *
     * @type lai_uint64_t
     * @flags CREATE_AND_SET
     */
    LAI_ETHERNET_ATTR_CLIENT_RX_ALS_DELAY,

    /**
     * @brief Clear RMON
     *
     * @type bool
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_ETHERNET_ATTR_CLEAR_RMON,

    /**
     * @brief End of attributes
     */
    LAI_ETHERNET_ATTR_END,

    /** Custom range base value */
    LAI_ETHERNET_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    LAI_ETHERNET_ATTR_CUSTOM_RANGE_END

} lai_ethernet_attr_t;

/**
 * @brief Ethernet counter IDs in lai_get_ethernet_stats() call
 *
 * @flags Contains flags
 */
typedef enum _lai_ethernet_stat_t
{
    /**
     * @brief Start of statistics
     */
    LAI_ETHERNET_STAT_START,

    /**
     * @brief In MAC control frames
     *
     * MAC layer control frames received on the interface
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_IN_MAC_CONTROL_FRAMES = LAI_ETHERNET_STAT_START,

    /**
     * @brief In MAC pause frames
     *
     * MAC layer PAUSE frames received on the interface
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_IN_MAC_PAUSE_FRAMES,

    /**
     * @brief In oversize frames
     *
     * The total number of frames received that were
     * longer than 1518 octets (excluding framing bits,
     * but including FCS octets) and were otherwise
     * well formed.
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_IN_OVERSIZE_FRAMES,

    /**
     * @brief In under size frames
     *
     * The total number of frames received that were
     * less than 64 octets long (excluding framing bits,
     * but including FCS octets) and were otherwise well
     * formed.
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_IN_UNDERSIZE_FRAMES,

    /**
     * @brief In jabber frames
     *
     * Number of jabber frames received on the interface.
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_IN_JABBER_FRAMES,

    /**
     * @brief In fragment frames
     *
     * The total number of frames received that were less than
     * 64 octets in length (excluding framing bits but including
     * FCS octets) and had either a bad Frame Check Sequence
     * (FCS) with an integral number of octets (FCS Error) or a
     * bad FCS with a non-integral number of octets (Alignment
     * Error).
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_IN_FRAGMENT_FRAMES,

    /**
     * @brief In 802.1q frames
     *
     * Number of 802.1q tagged frames received on the interface
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_IN_8021Q_FRAMES,

    /**
     * @brief In CRC errors
     *
     * The total number of frames received that
     * had a length (excluding framing bits, but
     * including FCS octets) of between 64 and 1518
     * octets, inclusive, but had either a bad
     * Frame Check Sequence (FCS) with an integral
     * number of octets (FCS Error) or a bad FCS with
     * a non-integral number of octets (Alignment Error)
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_IN_CRC_ERRORS,

    /**
     * @brief In block errors
     *
     * The number of received error-ed blocks.
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_IN_BLOCK_ERRORS,

    /**
     * @brief Out MAC control frames
     *
     * MAC layer control frames sent on the interface
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_OUT_MAC_CONTROL_FRAMES,

    /**
     * @brief Out MAC pause frames
     *
     * MAC layer PAUSE frames sent on the interface
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_OUT_MAC_PAUSE_FRAMES,

    /**
     * @brief Out 802.1q frames
     *
     * Number of 802.1q tagged frames sent on the interface
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_OUT_8021Q_FRAMES,

    /**
     * @brief In PCS BIP errors
     *
     * The number of received bit interleaved parity (BIP) errors
     * at the physical coding sublayer (PCS). If the interface
     * consists of multiple lanes, this will be the sum of all
     * errors on the lane
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_IN_PCS_BIP_ERRORS,

    /**
     * @brief In PCS error-ed seconds
     *
     * The number of seconds that physical coding sublayer (PCS)
     * errors have crossed a system defined threshold indicating the
     * link is error
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_IN_PCS_ERRORED_SECONDS,

    /**
     * @brief In PCS severely error-ed seconds
     *
     * The number of seconds that physical coding sublayer (PCS)
     * errors have crossed a system defined threshold indicating the
     * link is severely error
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_IN_PCS_SEVERELY_ERRORED_SECONDS,

    /**
     * @brief In PCS unavailable seconds
     *
     * The number of seconds that physical coding sublayer (PCS)
     * errors have crossed a system defined threshold indicating the
     * link is unavailable
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_IN_PCS_UNAVAILABLE_SECONDS,

    /**
     * @brief Out PCS BIP errors
     *
     * The number of transmitted bit interleaved parity (BIP) errors
     * at the physical coding sublayer (PCS). If the interface
     * consists of multiple lanes, this will be the sum of all
     * errors on the lane
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_OUT_PCS_BIP_ERRORS,

    /**
     * @brief Out CRC errors
     *
     * Number of FCS/CRC error check failures sent on the interface
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_OUT_CRC_ERRORS,

    /**
     * @brief Out block errors
     *
     * The number of transmitted error-ed blocks.
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_OUT_BLOCK_ERRORS,

    /**
     * @brief Tx good frame
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_GOOD_FRAME,

    /**
     * @brief Tx good octets
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_GOOD_OCTETS,

    /**
     * @brief Tx good multicast
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_GOOD_MULTICAST,

    /**
     * @brief Tx good broadcast
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_GOOD_BROADCAST,

    /**
     * @brief Tx good 64b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_GOOD_64B,

    /**
     * @brief Tx good 65b 127b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_GOOD_65B_127B,

    /**
     * @brief Tx good 128b 255b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_GOOD_128B_255B,

    /**
     * @brief Tx good 256b 511b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_GOOD_256B_511B,

    /**
     * @brief Tx good 512b 1023b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_GOOD_512B_1023B,

    /**
     * @brief Tx good 1024b 1518b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_GOOD_1024B_1518B,

    /**
     * @brief Tx good 1519b LTJ
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_GOOD_1519B_LTJ,

    /**
     * @brief Tx good jumbo
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_GOOD_JUMBO,

    /**
     * @brief Tx bad frame
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_BAD_FRAME,

    /**
     * @brief Tx bad octets
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_BAD_OCTETS,

    /**
     * @brief Tx bad multicast
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_BAD_MULTICAST,

    /**
     * @brief Tx bad broadcast
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_BAD_BROADCAST,

    /**
     * @brief Tx bad LT 64b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_BAD_LT_64B,

    /**
     * @brief Tx bad 64b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_BAD_64B,

    /**
     * @brief Tx bad 65b 127b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_BAD_65B_127B,

    /**
     * @brief Tx bad 128b 255b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_BAD_128B_255B,

    /**
     * @brief Tx bad 256b 511b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_BAD_256B_511B,

    /**
     * @brief Tx bad 512b 1023b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_BAD_512B_1023B,

    /**
     * @brief Tx bad 1024b 1518b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_BAD_1024B_1518B,

    /**
     * @brief Tx bad 1519b LTJ
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_BAD_1519B_LTJ,

    /**
     * @brief Tx bad jumbo
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_BAD_JUMBO,

    /**
     * @brief Tx octets
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_OCTETS,

    /**
     * @brief Tx frame
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_FRAME,

    /**
     * @brief Tx broadcast
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_BROADCAST,

    /**
     * @brief Tx multicast
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_MULTICAST,

    /**
     * @brief Tx CRC align
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_CRC_ALIGN,

    /**
     * @brief Tx under size
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_UNDER_SIZE,

    /**
     * @brief Tx over size
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_OVER_SIZE,

    /**
     * @brief Tx fragment
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_FRAGMENT,

    /**
     * @brief Tx jabber
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_JABBER,

    /**
     * @brief Tx 64b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_64B,

    /**
     * @brief Tx 65b 127b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_65B_127B,

    /**
     * @brief Tx 128b 255b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_128B_255B,

    /**
     * @brief Tx 256b 511b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_256B_511B,

    /**
     * @brief Tx 512b 1023b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_512B_1023B,

    /**
     * @brief Tx 1024b 1518b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_1024B_1518B,

    /**
     * @brief Tx 1519b max
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_TX_1519B_MAX,

    /**
     * @brief Rx good frame
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_GOOD_FRAME,

    /**
     * @brief Rx good octets
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_GOOD_OCTETS,

    /**
     * @brief Rx good multicast
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_GOOD_MULTICAST,

    /**
     * @brief Rx good broadcast
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_GOOD_BROADCAST,

    /**
     * @brief Rx good 64b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_GOOD_64B,

    /**
     * @brief Rx good 65b 127b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_GOOD_65B_127B,

    /**
     * @brief Rx good 128b 255b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_GOOD_128B_255B,

    /**
     * @brief Rx good 256b 511b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_GOOD_256B_511B,

    /**
     * @brief Rx good 512b 1023b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_GOOD_512B_1023B,

    /**
     * @brief Rx good 1024b 1518b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_GOOD_1024B_1518B,

    /**
     * @brief Rx good 1519b LTJ
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_GOOD_1519B_LTJ,

    /**
     * @brief Rx good jumbo
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_GOOD_JUMBO,

    /**
     * @brief Rx bad frame
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_BAD_FRAME,

    /**
     * @brief Rx bad octets
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_BAD_OCTETS,

    /**
     * @brief Rx bad multicast
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_BAD_MULTICAST,

    /**
     * @brief Rx bad broadcast
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_BAD_BROADCAST,

    /**
     * @brief Rx bad LT 64b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_BAD_LT_64B,

    /**
     * @brief Rx bad 64b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_BAD_64B,

    /**
     * @brief Rx bad 65b 127b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_BAD_65B_127B,

    /**
     * @brief Rx bad 128b 255b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_BAD_128B_255B,

    /**
     * @brief Rx bad 256b 511b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_BAD_256B_511B,

    /**
     * @brief Rx bad 512b 1023b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_BAD_512B_1023B,

    /**
     * @brief Rx bad 1024b 1518b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_BAD_1024B_1518B,

    /**
     * @brief Rx bad 1519b LTJ
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_BAD_1519B_LTJ,

    /**
     * @brief Rx bad jumbo
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_BAD_JUMBO,

    /**
     * @brief Rx octets
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_OCTETS,

    /**
     * @brief Rx frame
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_FRAME,

    /**
     * @brief Rx broadcast
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_BROADCAST,

    /**
     * @brief Rx multicast
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_MULTICAST,

    /**
     * @brief Rx CRC align
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_CRC_ALIGN,

    /**
     * @brief Rx 64b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_64B,

    /**
     * @brief Rx 65b 127b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_65B_127B,

    /**
     * @brief Rx 128b 255b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_128B_255B,

    /**
     * @brief Rx 256b 511b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_256B_511B,

    /**
     * @brief Rx 512b 1023b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_512B_1023B,

    /**
     * @brief Rx 1024b 1518b
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_1024B_1518B,

    /**
     * @brief Rx 1519b max
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_RX_1519B_MAX,

    /**
     * @brief Last clean up
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_ETHERNET_STAT_LAST_CLEAN_UP,

    /**
     * @brief End of statistics
     */
    LAI_ETHERNET_STAT_END,

} lai_ethernet_stat_t;

/**
 * @brief Create Ethernet.
 *
 * Allocates and initializes a Ethernet.
 *
 * @param[out] ethernet_id Ethernet id
 * @param[in] linecard_id Linecard id on which the Ethernet exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_create_ethernet_fn)(
        _Out_ lai_object_id_t *ethernet_id,
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Remove Ethernet
 *
 * @param[in] ethernet_id Ethernet id
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_remove_ethernet_fn)(
        _In_ lai_object_id_t ethernet_id);

/**
 * @brief Set Ethernet attribute
 *
 * @param[in] ethernet_id Ethernet id
 * @param[in] attr Attribute
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_set_ethernet_attribute_fn)(
        _In_ lai_object_id_t ethernet_id,
        _In_ const lai_attribute_t *attr);

/**
 * @brief Get Ethernet attribute
 *
 * @param[in] ethernet_id Ethernet id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_ethernet_attribute_fn)(
        _In_ lai_object_id_t ethernet_id,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

/**
 * @brief Get Ethernet counters. Deprecated for backward compatibility.
 *
 * @param[in] ethernet_id Ethernet id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_ethernet_stats_fn)(
        _In_ lai_object_id_t ethernet_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Get Ethernet statistics counters extended.
 *
 * @param[in] ethernet_id Ethernet id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_ethernet_stats_ext_fn)(
        _In_ lai_object_id_t ethernet_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _In_ lai_stats_mode_t mode,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Clear Ethernet statistics counters.
 *
 * @param[in] ethernet_id Ethernet id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_clear_ethernet_stats_fn)(
        _In_ lai_object_id_t ethernet_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids);

/**
 * @brief Ethernet methods table retrieved with lai_api_query()
 */
typedef struct _lai_ethernet_api_t
{
    lai_create_ethernet_fn                create_ethernet;
    lai_remove_ethernet_fn                remove_ethernet;
    lai_set_ethernet_attribute_fn         set_ethernet_attribute;
    lai_get_ethernet_attribute_fn         get_ethernet_attribute;
    lai_get_ethernet_stats_fn             get_ethernet_stats;
    lai_get_ethernet_stats_ext_fn         get_ethernet_stats_ext;
    lai_clear_ethernet_stats_fn           clear_ethernet_stats;
} lai_ethernet_api_t;

/**
 * @}
 */
#endif /** __LAIETHERNET_H_ */
