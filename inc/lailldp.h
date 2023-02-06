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
 * @file    lailldp.h
 * @brief   This module defines the lldp for the LAI
 */

#if !defined (__LAILLDP_H_)
#define __LAILLDP_H_

#include <laitypes.h>

/**
 * @defgroup LAILLDP LAI - LLDP specific API definitions
 *
 * @{
 */

/** @brief LLDP chassis id type */
typedef enum _lai_lldp_chassis_id_type_t
{
    LAI_LLDP_CHASSIS_ID_TYPE_CHASSIS_COMPONENT,
    LAI_LLDP_CHASSIS_ID_TYPE_INTERFACE_ALIAS,
    LAI_LLDP_CHASSIS_ID_TYPE_PORT_COMPONENT,
    LAI_LLDP_CHASSIS_ID_TYPE_MAC_ADDRESS,
    LAI_LLDP_CHASSIS_ID_TYPE_NETWORK_ADDRESS,
    LAI_LLDP_CHASSIS_ID_TYPE_INTERFACE_NAME,
    LAI_LLDP_CHASSIS_ID_TYPE_LOCAL,
} lai_lldp_chassis_id_type_t;

/** @brief LLDP port id type */
typedef enum _lai_lldp_port_id_type_t
{
    LAI_LLDP_PORT_ID_TYPE_INTERFACE_ALIAS,
    LAI_LLDP_PORT_ID_TYPE_PORT_COMPONENT,
    LAI_LLDP_PORT_ID_TYPE_MAC_ADDRESS,
    LAI_LLDP_PORT_ID_TYPE_NETWORK_ADDRESS,
    LAI_LLDP_PORT_ID_TYPE_INTERFACE_NAME,
    LAI_LLDP_PORT_ID_TYPE_AGENT_CIRCUIT_ID,
    LAI_LLDP_PORT_ID_TYPE_LOCAL,
} lai_lldp_port_id_type_t;

/**
 * @brief LLDP attribute IDs
 */
typedef enum _lai_lldp_attr_t
{
    /**
     * @brief Start of attributes
     */
    LAI_LLDP_ATTR_START,

    /**
     * @brief The logical channel which lldp belongs to
     *
     * @type lai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_LLDP_ATTR_CHANNEL_ID = LAI_LLDP_ATTR_START,

    /**
     * @brief Enabled
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    LAI_LLDP_ATTR_ENABLED,

    /**
     * @brief Snooping
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    LAI_LLDP_ATTR_SNOOPING,

    /**
     * @brief Neighbor system name
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LLDP_ATTR_NEIGHBOR_SYSTEM_NAME,

    /**
     * @brief Neighbor system description
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LLDP_ATTR_NEIGHBOR_SYSTEM_DESCRIPTION,

    /**
     * @brief Neighbor chassis ID
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LLDP_ATTR_NEIGHBOR_CHASSIS_ID,

    /**
     * @brief Neighbor chassis ID type
     *
     * @type lai_lldp_chassis_id_type_t
     * @flags READ_ONLY
     */
    LAI_LLDP_ATTR_NEIGHBOR_CHASSIS_ID_TYPE,

    /**
     * @brief Neighbor ID
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LLDP_ATTR_NEIGHBOR_ID,

    /**
     * @brief Neighbor last update
     *
     * @type lai_int64_t
     * @flags READ_ONLY
     */
    LAI_LLDP_ATTR_NEIGHBOR_LAST_UPDATE,

    /**
     * @brief Neighbor port ID
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LLDP_ATTR_NEIGHBOR_PORT_ID,

    /**
     * @brief Neighbor port ID type
     *
     * @type lai_lldp_port_id_type_t
     * @flags READ_ONLY
     */
    LAI_LLDP_ATTR_NEIGHBOR_PORT_ID_TYPE,

    /**
     * @brief Neighbor port description
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LLDP_ATTR_NEIGHBOR_PORT_DESCRIPTION,

    /**
     * @brief Neighbor management address
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LLDP_ATTR_NEIGHBOR_MANAGEMENT_ADDRESS,

    /**
     * @brief Neighbor management address type
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LLDP_ATTR_NEIGHBOR_MANAGEMENT_ADDRESS_TYPE,

    /**
     * @brief End of attributes
     */
    LAI_LLDP_ATTR_END,

    /** Custom range base value */
    LAI_LLDP_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    LAI_LLDP_ATTR_CUSTOM_RANGE_END

} lai_lldp_attr_t;

/**
 * @brief LLDP stat IDs
 *
 * @flags Contains flags
 */
typedef enum _lai_lldp_stat_t
{
    /**
     * @brief Start of statistics
     */
    LAI_LLDP_STAT_START,

    /**
     * @brief A placeholder
     *
     * @type lai_uint64_t
     */
    LAI_LLDP_STAT_NOT_USE = LAI_LLDP_STAT_START,

    /**
     * @brief End of statistics
     */
    LAI_LLDP_STAT_END,

} lai_lldp_stat_t;

/**
 * @brief Create LLDP.
 *
 * Allocates and initializes a lldp.
 *
 * @param[out] lldp_id LLDP id
 * @param[in] linecard_id Linecard id on which the lldp exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_create_lldp_fn)(
        _Out_ lai_object_id_t *lldp_id,
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Remove lldp
 *
 * @param[in] lldp_id LLDP id
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_remove_lldp_fn)(
        _In_ lai_object_id_t lldp_id);

/**
 * @brief Set lldp attribute
 *
 * @param[in] lldp_id LLDP id
 * @param[in] attr Attribute
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_set_lldp_attribute_fn)(
        _In_ lai_object_id_t lldp_id,
        _In_ const lai_attribute_t *attr);

/**
 * @brief Get lldp attribute
 *
 * @param[in] lldp_id LLDP id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_lldp_attribute_fn)(
        _In_ lai_object_id_t lldp_id,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

/**
 * @brief Get lldp statistics.
 *
 * @param[in] lldp_id LLDP id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_lldp_stats_fn)(
        _In_ lai_object_id_t lldp_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Get lldp statistics extended.
 *
 * @param[in] lldp_id LLDP id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_lldp_stats_ext_fn)(
        _In_ lai_object_id_t lldp_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _In_ lai_stats_mode_t mode,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Clear lldp statistics counters.
 *
 * @param[in] lldp_id LLDP id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_clear_lldp_stats_fn)(
        _In_ lai_object_id_t lldp_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with lai_api_query()
 */
typedef struct _lai_lldp_api_t
{
    lai_create_lldp_fn                create_lldp;
    lai_remove_lldp_fn                remove_lldp;
    lai_set_lldp_attribute_fn         set_lldp_attribute;
    lai_get_lldp_attribute_fn         get_lldp_attribute;
    lai_get_lldp_stats_fn             get_lldp_stats;
    lai_get_lldp_stats_ext_fn         get_lldp_stats_ext;
    lai_clear_lldp_stats_fn           clear_lldp_stats;
} lai_lldp_api_t;

/**
 * @}
 */
#endif /** __LAILLDP_H_ */
