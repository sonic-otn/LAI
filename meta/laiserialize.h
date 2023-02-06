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
 * @file    laiserialize.h
 *
 * @brief   This module defines LAI Serialize methods
 */

#ifndef __LAISERIALIZE_H_
#define __LAISERIALIZE_H_

/**
 * @defgroup LAISERIALIZE LAI - Serialize Definitions
 *
 * @{
 */

/**
 * @def LAI_SERIALIZE_ERROR
 *
 * Returned from serialize/deserialize methods on any error.
 * Meta log functions are used to produce specific error message.
 */
#define LAI_SERIALIZE_ERROR (-1)

/**
 * @def LAI_CHARDATA_LENGTH
 *
 * Defines size of char data inside lai_attribute_value_t union.
 */
#define LAI_CHARDATA_LENGTH 512

/**
 * @brief Is char allowed.
 *
 * Function checks if given char is one of the following:
 * - '\0', '"', ',', ']', '}'
 *
 * Since serialization is done to json format, after each value
 * there may be some characters specific to json format, like:
 *
 * * quote, if value was in quotes (string)
 * * comma, if value was without quotes but an item in array (number, bool)
 * * square bracket, if item was last item in array (number, bool)
 * * curly bracket, if item was last item in object (number, bool)
 *
 * This means that deserialize is "relaxed", so each item don't need to end
 * as zero '\0' but it can end on any of those characters. This allows us to
 * deserialize json string reading it directly without creating json object
 * tree and without any extra string copy. For example if we have item:
 * {"foo":true}, we can just read value "true}" and ignore last character and
 * still value will be deserialized correctly.
 *
 * This is not ideal solution, but in this case it will work just fine.
 *
 * NOTE: All auto generated methods will enforce to check extra characters at
 * the end of each value.
 */
bool lai_serialize_is_char_allowed(
        _In_ char c);

/**
 * @brief Serialize bool value.
 *
 * @param[out] buffer Output buffer for serialized value.
 * @param[in] flag Bool flag to be serialized.
 *
 * @return Number of characters written to buffer excluding '\0',
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_serialize_bool(
        _Out_ char *buffer,
        _In_ bool flag);

/**
 * @brief Deserialize bool value.
 *
 * @param[in] buffer Input buffer to be examined.
 * @param[out] flag Deserialized value.
 *
 * @return Number of characters consumed from the buffer,
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_deserialize_bool(
        _In_ const char *buffer,
        _Out_ bool *flag);

/**
 * @brief Serialize char data value.
 *
 * All printable characters (isprint) are allowed except '\' and '"'.
 *
 * @param[out] buffer Output buffer for serialized value.
 * @param[in] data Data to be serialized.
 *
 * @return Number of characters written to buffer excluding '\0',
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_serialize_chardata(
        _Out_ char *buffer,
        _In_ const char data[LAI_CHARDATA_LENGTH]);

/**
 * @brief Deserialize char data value.
 *
 * @param[in] buffer Input buffer to be examined.
 * @param[out] data Deserialized value.
 *
 * @return Number of characters consumed from the buffer,
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_deserialize_chardata(
        _In_ const char *buffer,
        _Out_ char data[LAI_CHARDATA_LENGTH]);

/**
 * @brief Serialize 8 bit unsigned integer.
 *
 * @param[out] buffer Output buffer for serialized value.
 * @param[in] u8 Deserialized value.
 *
 * @return Number of characters written to buffer excluding '\0',
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_serialize_uint8(
        _Out_ char *buffer,
        _In_ uint8_t u8);

/**
 * @brief Deserialize 8 bit unsigned integer.
 *
 * @param[in] buffer Input buffer to be examined.
 * @param[out] u8 Deserialized value.
 *
 * @return Number of characters consumed from the buffer,
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_deserialize_uint8(
        _In_ const char *buffer,
        _Out_ uint8_t *u8);

/**
 * @brief Serialize 8 bit signed integer.
 *
 * @param[out] buffer Output buffer for serialized value.
 * @param[in] u8 Integer to be serialized.
 *
 * @return Number of characters written to buffer excluding '\0',
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_serialize_int8(
        _Out_ char *buffer,
        _In_ int8_t u8);

/**
 * @brief Deserialize 8 bit signed integer.
 *
 * @param[in] buffer Input buffer to be examined.
 * @param[out] s8 Deserialized value.
 *
 * @return Number of characters consumed from the buffer,
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_deserialize_int8(
        _In_ const char *buffer,
        _Out_ int8_t *s8);

/**
 * @brief Serialize 16 bit unsigned integer.
 *
 * @param[out] buffer Output buffer for serialized value.
 * @param[in] u16 Integer to be serialized.
 *
 * @return Number of characters written to buffer excluding '\0',
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_serialize_uint16(
        _Out_ char *buffer,
        _In_ uint16_t u16);

/**
 * @brief Deserialize 16 bit unsigned integer.
 *
 * @param[in] buffer Input buffer to be examined.
 * @param[out] u16 Deserialized value.
 *
 * @return Number of characters consumed from the buffer,
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_deserialize_uint16(
        _In_ const char *buffer,
        _Out_ uint16_t *u16);

/**
 * @brief Serialize 16 bit signed integer.
 *
 * @param[out] buffer Output buffer for serialized value.
 * @param[in] s16 Integer to be serialized.
 *
 * @return Number of characters written to buffer excluding '\0',
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_serialize_int16(
        _Out_ char *buffer,
        _In_ int16_t s16);

/**
 * @brief Deserialize 16 bit signed integer.
 *
 * @param[in] buffer Input buffer to be examined.
 * @param[out] s16 Deserialized value.
 *
 * @return Number of characters consumed from the buffer,
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_deserialize_int16(
        _In_ const char *buffer,
        _Out_ int16_t *s16);

/**
 * @brief Serialize 32 bit unsigned integer.
 *
 * @param[out] buffer Output buffer for serialized value.
 * @param[in] u32 Integer to be serialized.
 *
 * @return Number of characters written to buffer excluding '\0',
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_serialize_uint32(
        _Out_ char *buffer,
        _In_ uint32_t u32);

/**
 * @brief Deserialize 32 bit unsigned integer.
 *
 * @param[in] buffer Input buffer to be examined.
 * @param[out] u32 Deserialized value.
 *
 * @return Number of characters consumed from the buffer,
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_deserialize_uint32(
        _In_ const char *buffer,
        _Out_ uint32_t *u32);

/**
 * @brief Serialize 32 bit signed integer.
 *
 * @param[out] buffer Output buffer for serialized value.
 * @param[in] s32 Integer to be serialized.
 *
 * @return Number of characters written to buffer excluding '\0',
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_serialize_int32(
        _Out_ char *buffer,
        _In_ int32_t s32);

/**
 * @brief Deserialize 32 bit signed integer.
 *
 * @param[in] buffer Input buffer to be examined.
 * @param[out] s32 Deserialized value.
 *
 * @return Number of characters consumed from the buffer,
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_deserialize_int32(
        _In_ const char *buffer,
        _Out_ int32_t *s32);

/**
 * @brief Serialize 64 bit unsigned integer.
 *
 * @param[out] buffer Output buffer for serialized value.
 * @param[in] u64 Integer to be serialized.
 *
 * @return Number of characters written to buffer excluding '\0',
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_serialize_uint64(
        _Out_ char *buffer,
        _In_ uint64_t u64);

/**
 * @brief Deserialize 64 bit unsigned integer.
 *
 * @param[in] buffer Input buffer to be examined.
 * @param[out] u64 Deserialized value.
 *
 * @return Number of characters consumed from the buffer,
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_deserialize_uint64(
        _In_ const char *buffer,
        _Out_ uint64_t *u64);

/**
 * @brief Serialize 64 bit signed integer.
 *
 * @param[out] buffer Output buffer for serialized value.
 * @param[in] s64 Integer to be serialized.
 *
 * @return Number of characters written to buffer excluding '\0',
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_serialize_int64(
        _Out_ char *buffer,
        _In_ int64_t s64);

/**
 * @brief Deserialize 64 bit signed integer.
 *
 * @param[in] buffer Input buffer to be examined.
 * @param[out] s64 Deserialized value.
 *
 * @return Number of characters consumed from the buffer,
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_deserialize_int64(
        _In_ const char *buffer,
        _Out_ int64_t *s64);

/**
 * @brief Serialize double.
 *
 * @param[out] buffer Output buffer for serialized value.
 * @param[in] d64 Double to be serialized.
 *
 * @return Number of characters written to buffer excluding '\0',
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_serialize_double(
        _Out_ char *buffer,
        _In_ lai_double_t d64);

/**
 * @brief Deserialize double.
 *
 * @param[in] buffer Input buffer to be examined.
 * @param[out] d64 Deserialized value.
 *
 * @return Number of characters consumed from the buffer,
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_deserialize_double(
        _In_ const char *buffer,
        _Out_ lai_double_t *d64);

/**
 * @brief Serialize pointer.
 *
 * @param[out] buffer Output buffer for serialized value.
 * @param[in] ptr Pointer to be serialized.
 *
 * @return Number of characters written to buffer excluding '\0',
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_serialize_pointer(
        _Out_ char *buffer,
        _In_ lai_pointer_t ptr);

/**
 * @brief Deserialize pointer.
 *
 * @param[in] buffer Input buffer to be examined.
 * @param[out] pointer Deserialized value.
 *
 * @return Number of characters consumed from the buffer,
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_deserialize_pointer(
        _In_ const char *buffer,
        _Out_ lai_pointer_t *pointer);

/**
 * @brief Serialize lai_size_t.
 *
 * @param[out] buffer Output buffer for serialized value.
 * @param[in] size Size to be serialized.
 *
 * @return Number of characters written to buffer excluding '\0',
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_serialize_size(
        _Out_ char *buffer,
        _In_ lai_size_t size);

/**
 * @brief Deserialize lai_size_t.
 *
 * @param[in] buffer Input buffer to be examined.
 * @param[out] size Deserialized value.
 *
 * @return Number of characters consumed from the buffer,
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_deserialize_size(
        _In_ const char *buffer,
        _Out_ lai_size_t *size);

/**
 * @brief Serialize object ID.
 *
 * @param[out] buffer Output buffer for serialized value.
 * @param[in] object_id Object ID to be serialized.
 *
 * @return Number of characters written to buffer excluding '\0',
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_serialize_object_id(
        _Out_ char *buffer,
        _In_ lai_object_id_t object_id);

/**
 * @brief Deserialize object Id.
 *
 * @param[in] buffer Input buffer to be examined.
 * @param[out] object_id Deserialized value.
 *
 * @return Number of characters consumed from the buffer,
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_deserialize_object_id(
        _In_ const char *buffer,
        _Out_ lai_object_id_t *object_id);

/**
 * @brief Serialize enum value.
 *
 * Buffer will contain actual enum name of number if enum
 * value was not found in specified enum metadata.
 *
 * @param[out] buffer Output buffer for serialized value.
 * @param[in] meta Enum metadata for serialization info.
 * @param[in] value Enum value to be serialized.
 *
 * @return Number of characters written to buffer excluding '\0',
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_serialize_enum(
        _Out_ char *buffer,
        _In_ const lai_enum_metadata_t *meta,
        _In_ int32_t value);

/**
 * @brief Deserialize enum value.
 *
 * If buffer will not contain valid enum name, function will attempt to
 * deserialize value as signed 32 bit integer.
 *
 * @param[in] buffer Input buffer to be examined.
 * @param[in] meta Enum metadata.
 * @param[out] value Deserialized value.
 *
 * @return Number of characters consumed from the buffer,
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_deserialize_enum(
        _In_ const char *buffer,
        _In_ const lai_enum_metadata_t *meta,
        _Out_ int32_t *value);

/**
 * @brief Serialize LAI attribute.
 *
 * @param[out] buffer Output buffer for serialized value.
 * @param[in] meta Attribute metadata.
 * @param[in] attribute Attribute to be serialized.
 *
 * @return Number of characters written to buffer excluding '\0',
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_serialize_attribute(
        _Out_ char *buffer,
        _In_ const lai_attr_metadata_t *meta,
        _In_ const lai_attribute_t *attribute);

/**
 * @brief Deserialize LAI attribute.
 *
 * @param[in] buffer Input buffer to be examined.
 * @param[out] attribute Deserialized value.
 *
 * @return Number of characters consumed from the buffer,
 * or #LAI_SERIALIZE_ERROR on error.
 */
int lai_deserialize_attribute(
        _In_ const char *buffer,
        _Out_ lai_attribute_t *attribute);

/**
 * @}
 */
#endif /** __LAISERIALIZE_H_ */
