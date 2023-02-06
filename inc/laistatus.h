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
 * @file    laistatus.h
 * @brief   This module defines LAI Status codes LAI
 */

#if !defined (__LAISTATUS_H_)
#define __LAISTATUS_H_

/**
 * @defgroup LAISTATUS LAI - Status codes definitions
 *
 * @{
 */

#ifdef _WIN32

#define LAI_STATUS_CODE(_S_)    ((lai_status_t)(_S_))

#else

/**
 * @brief Any mapping schema from _S_ to error codes convenient on *nix can be used.
 */
#define LAI_STATUS_CODE(_S_)    (-(_S_))

#endif

/**
 * @brief Status success
 */
#define LAI_STATUS_SUCCESS                                          0x00000000L

/**
 * @brief General failure
 */
#define LAI_STATUS_FAILURE                          LAI_STATUS_CODE(0x00000001L)

/**
 * @brief The request is not supported
 */
#define LAI_STATUS_NOT_SUPPORTED                    LAI_STATUS_CODE(0x00000002L)

/**
 * @brief Not enough memory to complete the operation
 */
#define LAI_STATUS_NO_MEMORY                        LAI_STATUS_CODE(0x00000003L)

/**
 * @brief Insufficient system resources exist to complete the operation
 */
#define LAI_STATUS_INSUFFICIENT_RESOURCES           LAI_STATUS_CODE(0x00000004L)

/**
 * @brief An invalid parameter was passed to a function
 */
#define LAI_STATUS_INVALID_PARAMETER                LAI_STATUS_CODE(0x00000005L)

/**
 * @brief An item already exists. For example, create a route which already
 * exists.
 */
#define LAI_STATUS_ITEM_ALREADY_EXISTS              LAI_STATUS_CODE(0x00000006L)

/**
 * @brief An item was not found. For example, remove a route which does not
 * exist.
 */
#define LAI_STATUS_ITEM_NOT_FOUND                   LAI_STATUS_CODE(0x00000007L)

/**
 * @brief The data was too large to fit into the specified buffer.
 */
#define LAI_STATUS_BUFFER_OVERFLOW                  LAI_STATUS_CODE(0x00000008L)

/**
 * @brief Invalid port number
 */
#define LAI_STATUS_INVALID_PORT_NUMBER              LAI_STATUS_CODE(0x00000009L)

/**
 * @brief Invalid port member
 */
#define LAI_STATUS_INVALID_PORT_MEMBER              LAI_STATUS_CODE(0x0000000AL)

/**
 * @brief Object is uninitialized
 */
#define LAI_STATUS_UNINITIALIZED                    LAI_STATUS_CODE(0x0000000CL)

/**
 * @brief Table is full
 */
#define LAI_STATUS_TABLE_FULL                       LAI_STATUS_CODE(0x0000000DL)

/**
 * @brief Mandatory attribute is missing
 */
#define LAI_STATUS_MANDATORY_ATTRIBUTE_MISSING      LAI_STATUS_CODE(0x0000000EL)

/**
 * @brief Function is not implemented
 */
#define LAI_STATUS_NOT_IMPLEMENTED                  LAI_STATUS_CODE(0x0000000FL)

/**
 * @brief Address not found
 */
#define LAI_STATUS_ADDR_NOT_FOUND                   LAI_STATUS_CODE(0x00000010L)

/**
 * @brief LAI Object is in use
 */
#define LAI_STATUS_OBJECT_IN_USE                    LAI_STATUS_CODE(0x00000011L)

/**
 * @brief Invalid LAI Object type passed to a function.
 *
 * If the object id is passed as an attribute value in list, then
 * #LAI_STATUS_INVALID_ATTR_VALUE_0 status code should be used.
 */
#define LAI_STATUS_INVALID_OBJECT_TYPE              LAI_STATUS_CODE(0x00000012L)

/**
 * @brief Invalid LAI Object ID passed to a function.
 *
 * Return #LAI_STATUS_INVALID_OBJECT_TYPE when the object type is invalid,
 * otherwise return this #LAI_STATUS_INVALID_OBJECT_ID. This can happen if the
 * object id is already deleted.
 */
#define LAI_STATUS_INVALID_OBJECT_ID                LAI_STATUS_CODE(0x00000013L)

/**
 * @brief The NV storage used is either invalid or corrupt. (rv for
 *        initialize_module())
 */
#define LAI_STATUS_INVALID_NV_STORAGE               LAI_STATUS_CODE(0x00000014L)

/**
 * @brief The NV storage is full. (rv for shutdown_module())
 */
#define LAI_STATUS_NV_STORAGE_FULL                  LAI_STATUS_CODE(0x00000015L)

/**
 * @brief Version mismatch in case of Inservice upgrade (rv for
 *        initialize_module())
 */
#define LAI_STATUS_SW_UPGRADE_VERSION_MISMATCH      LAI_STATUS_CODE(0x00000016L)

/**
 * @brief Operation not executed
 */
#define LAI_STATUS_NOT_EXECUTED                     LAI_STATUS_CODE(0x00000017L)

/**
 * @brief When admin status is up, operation is forbidden.
 */
#define LAI_STATUS_ADMIN_IS_UP                      LAI_STATUS_CODE(0x00000018L)

/**
 * @brief The hardware state does not match expectations.
 */
#define LAI_STATUS_HARDWARE_STATE_MISMATCH          LAI_STATUS_CODE(0x00000019L)

/**
 * @brief LAI Object is not ready.
 */
#define LAI_STATUS_OBJECT_NOT_READY                 LAI_STATUS_CODE(0x0000001AL)

/**
 * @brief Attribute is invalid
 *
 * Range from 0x00010000L to 0x0001FFFFL.
 *
 * Return this when the property attached to the attribute does not match
 * the API call.
 *
 * For example:
 * - When a READ_ONLY attribute is passed set_attribute or create call
 * - When a CREATE_ONLY attribute is passed to set_attribute call
 *
 * The offset from #LAI_STATUS_INVALID_ATTRIBUTE_0 is the array index of
 * the attribute list passed to the LAI API call.
 */
#define LAI_STATUS_INVALID_ATTRIBUTE_0              LAI_STATUS_CODE(0x00010000L)

/**
 * @brief End of invalid attribute range
 */
#define LAI_STATUS_INVALID_ATTRIBUTE_MAX            LAI_STATUS_CODE(0x0001FFFFL)

/**
 * @brief Invalid attribute value
 *
 * Range from 0x00020000L to 0x0002FFFFL.
 */
#define LAI_STATUS_INVALID_ATTR_VALUE_0             LAI_STATUS_CODE(0x00020000L)

/**
 * @brief End of invalid attribute value range
 */
#define LAI_STATUS_INVALID_ATTR_VALUE_MAX           LAI_STATUS_CODE(0x0002FFFFL)

/**
 * @brief Attribute is not implemented
 *
 * Range from 0x00030000L to 0x003FFFFL.
 *
 * Return this when the attribute is supported but not implemented on
 * the platform.
 */
#define LAI_STATUS_ATTR_NOT_IMPLEMENTED_0           LAI_STATUS_CODE(0x00030000L)

/**
 * @brief End of not implemented range
 */
#define LAI_STATUS_ATTR_NOT_IMPLEMENTED_MAX         LAI_STATUS_CODE(0x0003FFFFL)

/**
 * @brief Attribute is unknown
 *
 * Range from 0x00040000L to 0x004FFFFL.
 *
 * Return this when the attribute is undefined, e.g., the attribute id
 * is out of range.
 */
#define LAI_STATUS_UNKNOWN_ATTRIBUTE_0              LAI_STATUS_CODE(0x00040000L)

/**
 * @brief End of unknown attribute range
 */
#define LAI_STATUS_UNKNOWN_ATTRIBUTE_MAX            LAI_STATUS_CODE(0x0004FFFFL)

/**
 * @brief Attribute is not supported
 *
 * Range from 0x00050000L to 0x005FFFFL.
 *
 * Return this when the platform does not have the capability to support
 * this attribute.
 */
#define LAI_STATUS_ATTR_NOT_SUPPORTED_0             LAI_STATUS_CODE(0x00050000L)

/**
 * @brief End of attribute not supported range
 */
#define LAI_STATUS_ATTR_NOT_SUPPORTED_MAX           LAI_STATUS_CODE(0x0005FFFFL)

/*
 * Macros to check if attribute related error is within the specified range
 */

/**
 * @brief Is invalid attribute helper
 */
#define LAI_STATUS_IS_INVALID_ATTRIBUTE(x)      (((x) & (~0xFFFF)) == LAI_STATUS_INVALID_ATTRIBUTE_0)

/**
 * @brief Is invalid attribute value helper
 */
#define LAI_STATUS_IS_INVALID_ATTR_VALUE(x)     (((x) & (~0xFFFF)) == LAI_STATUS_INVALID_ATTR_VALUE_0)

/**
 * @brief Is attribute not implemented helper
 */
#define LAI_STATUS_IS_ATTR_NOT_IMPLEMENTED(x)   (((x) & (~0xFFFF)) == LAI_STATUS_ATTR_NOT_IMPLEMENTED_0)

/**
 * @brief Is unknown attribute helper
 */
#define LAI_STATUS_IS_UNKNOWN_ATTRIBUTE(x)      (((x) & (~0xFFFF)) == LAI_STATUS_INVALID_ATTRIBUTE_0)

/**
 * @brief Is attribute not supported helper
 */
#define LAI_STATUS_IS_ATTR_NOT_SUPPORTED(x)     (((x) & (~0xFFFF)) == LAI_STATUS_ATTR_NOT_SUPPORTED_0)

/**
 * @}
 */
#endif /** __LAISTATUS_H_ */
