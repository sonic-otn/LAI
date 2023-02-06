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
 * @file    laiserialize.c
 *
 * @brief   This file implements basic serialization functions for LAI attributes
 */

#include <arpa/inet.h>
#include <byteswap.h>
#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <lai.h>
#include "laimetadatautils.h"
#include "laimetadatalogger.h"
#include "laimetadata.h"
#include "laiserialize.h"

#define PRIMITIVE_BUFFER_SIZE 128
#define MAX_CHARS_PRINT 25

bool lai_serialize_is_char_allowed(
        _In_ char c)
{
    /*
     * When we will perform deserialize, we allow buffer string to be
     * terminated not only by zero, but also with json characters like:
     *
     * - end of quote
     * - comma, next item in array
     * - end of array
     *
     * This will be handy when performing deserialize.
     */

    return c == 0 || c == '"' || c == ',' || c == ']' || c == '}';
}

int lai_serialize_bool(
        _Out_ char *buffer,
        _In_ bool flag)
{
    return sprintf(buffer, "%s", flag ? "true" : "false");
}

#define LAI_TRUE_LENGTH 4
#define LAI_FALSE_LENGTH 5

int lai_deserialize_bool(
        _In_ const char *buffer,
        _Out_ bool *flag)
{
    if (strncmp(buffer, "true", LAI_TRUE_LENGTH) == 0 &&
            lai_serialize_is_char_allowed(buffer[LAI_TRUE_LENGTH]))
    {
        *flag = true;
        return LAI_TRUE_LENGTH;
    }

    if (strncmp(buffer, "false", LAI_FALSE_LENGTH) == 0 &&
            lai_serialize_is_char_allowed(buffer[LAI_FALSE_LENGTH]))
    {
        *flag = false;
        return LAI_FALSE_LENGTH;
    }

    /*
     * Limit printf to maximum "false" length + 1 if there is invalid character
     * after "false" string.
     */

    LAI_META_LOG_WARN("failed to deserialize '%.*s' as bool",
            LAI_FALSE_LENGTH + 1,
            buffer);

    return LAI_SERIALIZE_ERROR;
}

int lai_serialize_chardata(
        _Out_ char *buffer,
        _In_ const char data[LAI_CHARDATA_LENGTH])
{
    int idx;

    for (idx = 0; idx < LAI_CHARDATA_LENGTH; ++idx)
    {
        char c = data[idx];

        if (c == 0)
        {
            break;
        }

        if (isprint(c) && c != '\\' && c != '"')
        {
            buffer[idx] = c;
            continue;
        }

        LAI_META_LOG_WARN("invalid character 0x%x in chardata", c);
        return LAI_SERIALIZE_ERROR;
    }

    buffer[idx] = 0;

    return idx;
}

int lai_deserialize_chardata(
        _In_ const char *buffer,
        _Out_ char data[LAI_CHARDATA_LENGTH])
{
    int idx;

    memset(data, 0, LAI_CHARDATA_LENGTH);

    for (idx = 0; idx < LAI_CHARDATA_LENGTH; ++idx)
    {
        char c = buffer[idx];

        if (isprint(c) && c != '\\' && c != '"')
        {
            data[idx] = c;
            continue;
        }

        if (c == 0)
        {
            break;
        }

        if (c == '"')
        {
            /*
             * We allow quote as last char since chardata will be serialized in
             * quotes.
             */

            break;
        }

        LAI_META_LOG_WARN("invalid character 0x%x in chardata", c);
        return LAI_SERIALIZE_ERROR;
    }

    if (lai_serialize_is_char_allowed(buffer[idx]))
    {
        return idx;
    }

    LAI_META_LOG_WARN("invalid character 0x%x in chardata", buffer[idx]);
    return LAI_SERIALIZE_ERROR;
}

int lai_serialize_uint8(
        _Out_ char *buffer,
        _In_ uint8_t u8)
{
    return sprintf(buffer, "%u", u8);
}

int lai_deserialize_uint8(
        _In_ const char *buffer,
        _Out_ uint8_t *u8)
{
    uint64_t u64;

    int res = lai_deserialize_uint64(buffer, &u64);

    if (res > 0 && u64 <= UCHAR_MAX)
    {
        *u8 = (uint8_t)u64;
        return res;
    }

    LAI_META_LOG_WARN("failed to deserialize '%.*s' as uint8", MAX_CHARS_PRINT, buffer);
    return LAI_SERIALIZE_ERROR;
}

int lai_serialize_int8(
        _Out_ char *buffer,
        _In_ int8_t u8)
{
    return sprintf(buffer, "%d", u8);
}

int lai_deserialize_int8(
        _In_ const char *buffer,
        _Out_ int8_t *s8)
{
    int64_t s64;

    int res = lai_deserialize_int64(buffer, &s64);

    if (res > 0 && s64 >= CHAR_MIN && s64 <= CHAR_MAX)
    {
        *s8 = (int8_t)s64;
        return res;
    }

    LAI_META_LOG_WARN("failed to deserialize '%.*s' as int8", MAX_CHARS_PRINT, buffer);
    return LAI_SERIALIZE_ERROR;
}

int lai_serialize_uint16(
        _Out_ char *buffer,
        _In_ uint16_t u16)
{
    return sprintf(buffer, "%u", u16);
}

int lai_deserialize_uint16(
        _In_ const char *buffer,
        _Out_ uint16_t *u16)
{
    uint64_t u64;

    int res = lai_deserialize_uint64(buffer, &u64);

    if (res > 0 && u64 <= USHRT_MAX)
    {
        *u16 = (uint16_t)u64;
        return res;
    }

    LAI_META_LOG_WARN("failed to deserialize '%.*s' as uint16", MAX_CHARS_PRINT, buffer);
    return LAI_SERIALIZE_ERROR;
}

int lai_serialize_int16(
        _Out_ char *buffer,
        _In_ int16_t s16)
{
    return sprintf(buffer, "%d", s16);
}

int lai_deserialize_int16(
        _In_ const char *buffer,
        _Out_ int16_t *s16)
{
    int64_t s64;

    int res = lai_deserialize_int64(buffer, &s64);

    if (res > 0 && s64 >= SHRT_MIN && s64 <= SHRT_MAX)
    {
        *s16 = (int16_t)s64;
        return res;
    }

    LAI_META_LOG_WARN("failed to deserialize '%.*s' as int16", MAX_CHARS_PRINT, buffer);
    return LAI_SERIALIZE_ERROR;
}

int lai_serialize_uint32(
        _Out_ char *buffer,
        _In_ uint32_t u32)
{
    return sprintf(buffer, "%u", u32);
}

int lai_deserialize_uint32(
        _In_ const char *buffer,
        _Out_ uint32_t *u32)
{
    uint64_t u64;

    int res = lai_deserialize_uint64(buffer, &u64);

    if (res > 0 && u64 <= UINT_MAX)
    {
        *u32 = (uint32_t)u64;
        return res;
    }

    LAI_META_LOG_WARN("failed to deserialize '%.*s' as uint32", MAX_CHARS_PRINT, buffer);
    return LAI_SERIALIZE_ERROR;
}

int lai_serialize_int32(
        _Out_ char *buffer,
        _In_ int32_t s32)
{
    return sprintf(buffer, "%d", s32);
}

int lai_deserialize_int32(
        _In_ const char *buffer,
        _Out_ int32_t *s32)
{
    int64_t s64;

    int res = lai_deserialize_int64(buffer, &s64);

    if (res > 0 && s64 >= INT_MIN && s64 <= INT_MAX)
    {
        *s32 = (int32_t)s64;
        return res;
    }

    LAI_META_LOG_WARN("failed to deserialize '%.*s' as int32", MAX_CHARS_PRINT, buffer);
    return LAI_SERIALIZE_ERROR;
}

int lai_serialize_uint64(
        _Out_ char *buffer,
        _In_ uint64_t u64)
{
    return sprintf(buffer, "%" PRIu64, u64);
}

#define LAI_BASE_10 10

int lai_deserialize_uint64(
        _In_ const char *buffer,
        _Out_ uint64_t *u64)
{
    int idx = 0;
    uint64_t result = 0;

    while (isdigit(buffer[idx]))
    {
        char c = (char)(buffer[idx] - '0');

        /*
         * Base is 10 we can check, that if result is greater than (2^64-1)/10)
         * then next multiplication with 10 will cause overflow.
         */

        if (result > (ULONG_MAX/LAI_BASE_10) ||
            ((result == ULONG_MAX/LAI_BASE_10) && (c > (char)(ULONG_MAX % LAI_BASE_10))))
        {
            idx = 0;
            break;
        }

        result = result * 10 + (uint64_t)(c);

        idx++;
    }

    if (idx > 0 && lai_serialize_is_char_allowed(buffer[idx]))
    {
        *u64 = result;
        return idx;
    }

    LAI_META_LOG_WARN("failed to deserialize '%.*s...' as uint64", MAX_CHARS_PRINT, buffer);
    return LAI_SERIALIZE_ERROR;
}

int lai_serialize_int64(
        _Out_ char *buffer,
        _In_ int64_t s64)
{
    return sprintf(buffer, "%" PRId64, s64);
}

int lai_deserialize_int64(
        _In_ const char *buffer,
        _Out_ int64_t *s64)
{
    uint64_t result = 0;
    bool negative = 0;

    if (*buffer == '-')
    {
        buffer++;
        negative = true;
    }

    int res = lai_deserialize_uint64(buffer, &result);

    if (res > 0)
    {
        if (negative)
        {
            if (result <= (uint64_t)(LONG_MIN))
            {
                *s64 = -(int64_t)result;
                return res + 1;
            }
        }
        else
        {
            if (result <= LONG_MAX)
            {
                *s64 = (int64_t)result;
                return res;
            }
        }
    }

    LAI_META_LOG_WARN("failed to deserialize '%.*s' as int64", MAX_CHARS_PRINT, buffer);
    return LAI_SERIALIZE_ERROR;
}

int lai_deserialize_u32range(
        _In_ const char *buffer,
        _Out_ lai_u32_range_t *value)
{
    int ret = lai_deserialize_uint32(buffer, &value->min), ret2;
    if ( ret < 0 ) {
        return ret;
    }
    if ( buffer[ret++] != ',' ) {
        return -1;
    }
    ret2 = lai_deserialize_uint32(buffer+ret, &value->max);
    return ret + ret2;
}

int lai_deserialize_s32range(
        _In_ const char *buffer,
        _Out_ lai_s32_range_t *value)
{
    int ret = lai_deserialize_int32(buffer, &value->min), ret2;
    if ( ret < 0 ) {
        return ret;
    }
    if ( buffer[ret++] != ',' ) {
        return -1;
    }
    ret2 = lai_deserialize_int32(buffer+ret, &value->max);
    return ret + ret2;
}

int lai_serialize_size(
        _Out_ char *buffer,
        _In_ lai_size_t size)
{
    return sprintf(buffer, "%zu", size);
}

int lai_deserialize_size(
        _In_ const char *buffer,
        _Out_ lai_size_t *size)
{
    uint64_t u64;

    int res = lai_deserialize_uint64(buffer, &u64);

    if (res > 0)
    {
        *size = (lai_size_t)u64;
        return res;
    }

    LAI_META_LOG_WARN("failed to deserialize '%.*s...' as lai_size_t", MAX_CHARS_PRINT, buffer);
    return LAI_SERIALIZE_ERROR;
}

int lai_serialize_object_id(
        _Out_ char *buffer,
        _In_ lai_object_id_t oid)
{
    return sprintf(buffer, "oid:0x%" PRIx64, oid);
}

int lai_serialize_double(
        _Out_ char *buffer,
        _In_ lai_double_t d64)
{
    return sprintf(buffer, "%.2lf", d64);
}

int lai_deserialize_double(
        _In_ const char *buffer,
        _Out_ lai_double_t *d64)
{
    return sscanf(buffer, "%lf", d64);
}

int lai_serialize_pointer(
        _Out_ char *buffer,
        _In_ lai_pointer_t ptr)
{
    return sprintf(buffer, "%p", ptr);
}

int lai_deserialize_pointer(
        _In_ const char *buffer,
        _Out_ lai_pointer_t *pointer)
{
    int read;

    int n = sscanf(buffer, "ptr:%p%n", pointer, &read);

    if (n == 1 && lai_serialize_is_char_allowed(buffer[read]))
    {
        return read;
    }

    LAI_META_LOG_WARN("failed to deserialize '%.*s' as pointer", MAX_CHARS_PRINT, buffer);
    return LAI_SERIALIZE_ERROR;
}

int lai_deserialize_object_id(
        _In_ const char *buffer,
        _Out_ lai_object_id_t *oid)
{
    int read;

    int n = sscanf(buffer, "oid:0x%16" PRIx64 "%n", oid, &read);

    if (n == 1 && lai_serialize_is_char_allowed(buffer[read]))
    {
        return read;
    }

    LAI_META_LOG_WARN("failed to deserialize '%.*s' as oid", MAX_CHARS_PRINT, buffer);
    return LAI_SERIALIZE_ERROR;
}

int lai_serialize_enum(
        _Out_ char *buffer,
        _In_ const lai_enum_metadata_t* meta,
        _In_ int32_t value)
{
    if (meta == NULL)
    {
        return lai_serialize_int32(buffer, value);
    }

    size_t i = 0;

    for (; i < meta->valuescount; ++i)
    {
        if (meta->values[i] == value)
        {
            return sprintf(buffer, "%s", meta->valuesnames[i]);
        }
    }

    LAI_META_LOG_WARN("enum value %d not found in enum %s", value, meta->name);

    return lai_serialize_int32(buffer, value);
}

int lai_deserialize_enum(
        _In_ const char *buffer,
        _In_ const lai_enum_metadata_t* meta,
        _Out_ int32_t *value)
{
    if (meta == NULL)
    {
        return lai_deserialize_int32(buffer, value);
    }

    size_t idx = 0;

    for (; idx < meta->valuescount; ++idx)
    {
        size_t len = strlen(meta->valuesnames[idx]);

        if (strncmp(meta->valuesnames[idx], buffer, len) == 0 &&
            lai_serialize_is_char_allowed(buffer[len]))
        {
            *value = meta->values[idx];
            return (int)len;
        }
    }

    LAI_META_LOG_WARN("enum value '%.*s' not found in enum %s", MAX_CHARS_PRINT, buffer, meta->name);

    return lai_deserialize_int32(buffer, value);
}


int lai_serialize_attr_id(
        _Out_ char *buf,
        _In_ const lai_attr_metadata_t *meta,
        _In_ lai_attr_id_t attr_id)
{
    strcpy(buf, meta->attridname);

    return (int)strlen(buf);
}

int lai_deserialize_attr_id(
        _In_ const char *buffer,
        _Out_ lai_attr_id_t *attr_id)
{
    LAI_META_LOG_WARN("not implemented");
    return LAI_SERIALIZE_ERROR;
}

int lai_serialize_attribute(
        _Out_ char *buf,
        _In_ const lai_attr_metadata_t *meta,
        _In_ const lai_attribute_t *attribute)
{
    char *begin_buf = buf;
    int ret;

    /* can be auto generated */

    buf += sprintf(buf, "{");

    buf += sprintf(buf, "\"id\":");

    buf += sprintf(buf, "\"");

    ret = lai_serialize_attr_id(buf, meta, attribute->id);

    if (ret < 0)
    {
        LAI_META_LOG_WARN("failed to serialize attr id");
        return LAI_SERIALIZE_ERROR;
    }

    buf += ret;

    buf += sprintf(buf, "\",");

    buf += sprintf(buf, "\"value\":");

    ret = lai_serialize_attribute_value(buf, meta, &attribute->value);

    if (ret < 0)
    {
        LAI_META_LOG_WARN("failed to serialize attribute value");
        return LAI_SERIALIZE_ERROR;
    }

    buf += ret;

    buf += sprintf(buf, "}");

    return (int)(buf - begin_buf);
}

int lai_deserialize_attribute(
        _In_ const char *buffer,
        _Out_ lai_attribute_t *attribute)
{
    LAI_META_LOG_WARN("not implemented");
    return LAI_SERIALIZE_ERROR;
}

