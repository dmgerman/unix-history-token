begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2013, Vsevolod Stakhov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *       * Redistributions of source code must retain the above copyright  *         notice, this list of conditions and the following disclaimer.  *       * Redistributions in binary form must reproduce the above copyright  *         notice, this list of conditions and the following disclaimer in the  *         documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED ''AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL AUTHOR BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UCL_H_
end_ifndef

begin_define
define|#
directive|define
name|UCL_H_
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_define
define|#
directive|define
name|UCL_EXTERN
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UCL_EXTERN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * @mainpage  * This is a reference manual for UCL API. You may find the description of UCL format by following this  * [github repository](https://github.com/vstakhov/libucl).  *  * This manual has several main sections:  *  - @ref structures  *  - @ref utils  *  - @ref parser  *  - @ref emitter  */
end_comment

begin_comment
comment|/**  * @file ucl.h  * @brief UCL parsing and emitting functions  *  * UCL is universal configuration language, which is a form of  * JSON with less strict rules that make it more comfortable for  * using as a configuration language  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  * Memory allocation utilities  * UCL_ALLOC(size) - allocate memory for UCL  * UCL_FREE(size, ptr) - free memory of specified size at ptr  * Default: malloc and free  */
ifndef|#
directive|ifndef
name|UCL_ALLOC
define|#
directive|define
name|UCL_ALLOC
parameter_list|(
name|size
parameter_list|)
value|malloc(size)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|UCL_FREE
define|#
directive|define
name|UCL_FREE
parameter_list|(
name|size
parameter_list|,
name|ptr
parameter_list|)
value|free(ptr)
endif|#
directive|endif
if|#
directive|if
name|__GNUC__
operator|>
literal|3
operator|||
operator|(
name|__GNUC__
operator|==
literal|3
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|4
operator|)
define|#
directive|define
name|UCL_WARN_UNUSED_RESULT
define|\
value|__attribute__((warn_unused_result))
else|#
directive|else
define|#
directive|define
name|UCL_WARN_UNUSED_RESULT
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__GNUC__
define|#
directive|define
name|UCL_DEPRECATED
parameter_list|(
name|func
parameter_list|)
value|func __attribute__ ((deprecated))
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
define|#
directive|define
name|UCL_DEPRECATED
parameter_list|(
name|func
parameter_list|)
value|__declspec(deprecated) func
else|#
directive|else
define|#
directive|define
name|UCL_DEPRECATED
parameter_list|(
name|func
parameter_list|)
value|func
endif|#
directive|endif
comment|/**  * @defgroup structures Structures and types  * UCL defines several enumeration types used for error reporting or specifying flags and attributes.  *  * @{  */
comment|/**  * The common error codes returned by ucl parser  */
typedef|typedef
enum|enum
name|ucl_error
block|{
name|UCL_EOK
init|=
literal|0
block|,
comment|/**< No error */
name|UCL_ESYNTAX
block|,
comment|/**< Syntax error occurred during parsing */
name|UCL_EIO
block|,
comment|/**< IO error occurred during parsing */
name|UCL_ESTATE
block|,
comment|/**< Invalid state machine state */
name|UCL_ENESTED
block|,
comment|/**< Input has too many recursion levels */
name|UCL_EMACRO
block|,
comment|/**< Error processing a macro */
name|UCL_EINTERNAL
block|,
comment|/**< Internal unclassified error */
name|UCL_ESSL
comment|/**< SSL error */
block|}
name|ucl_error_t
typedef|;
comment|/**  * #ucl_object_t may have one of specified types, some types are compatible with each other and some are not.  * For example, you can always convert #UCL_TIME to #UCL_FLOAT. Also you can convert #UCL_FLOAT to #UCL_INTEGER  * by loosing floating point. Every object may be converted to a string by #ucl_object_tostring_forced() function.  *  */
typedef|typedef
enum|enum
name|ucl_type
block|{
name|UCL_OBJECT
init|=
literal|0
block|,
comment|/**< UCL object - key/value pairs */
name|UCL_ARRAY
block|,
comment|/**< UCL array */
name|UCL_INT
block|,
comment|/**< Integer number */
name|UCL_FLOAT
block|,
comment|/**< Floating point number */
name|UCL_STRING
block|,
comment|/**< Null terminated string */
name|UCL_BOOLEAN
block|,
comment|/**< Boolean value */
name|UCL_TIME
block|,
comment|/**< Time value (floating point number of seconds) */
name|UCL_USERDATA
block|,
comment|/**< Opaque userdata pointer (may be used in macros) */
name|UCL_NULL
comment|/**< Null value */
block|}
name|ucl_type_t
typedef|;
comment|/**  * You can use one of these types to serialise #ucl_object_t by using ucl_object_emit().  */
typedef|typedef
enum|enum
name|ucl_emitter
block|{
name|UCL_EMIT_JSON
init|=
literal|0
block|,
comment|/**< Emit fine formatted JSON */
name|UCL_EMIT_JSON_COMPACT
block|,
comment|/**< Emit compacted JSON */
name|UCL_EMIT_CONFIG
block|,
comment|/**< Emit human readable config format */
name|UCL_EMIT_YAML
comment|/**< Emit embedded YAML format */
block|}
name|ucl_emitter_t
typedef|;
comment|/**  * These flags defines parser behaviour. If you specify #UCL_PARSER_ZEROCOPY you must ensure  * that the input memory is not freed if an object is in use. Moreover, if you want to use  * zero-terminated keys and string values then you should not use zero-copy mode, as in this case  * UCL still has to perform copying implicitly.  */
typedef|typedef
enum|enum
name|ucl_parser_flags
block|{
name|UCL_PARSER_KEY_LOWERCASE
init|=
literal|0x1
block|,
comment|/**< Convert all keys to lower case */
name|UCL_PARSER_ZEROCOPY
init|=
literal|0x2
block|,
comment|/**< Parse input in zero-copy mode if possible */
name|UCL_PARSER_NO_TIME
init|=
literal|0x4
comment|/**< Do not parse time and treat time values as strings */
block|}
name|ucl_parser_flags_t
typedef|;
comment|/**  * String conversion flags, that are used in #ucl_object_fromstring_common function.  */
typedef|typedef
enum|enum
name|ucl_string_flags
block|{
name|UCL_STRING_ESCAPE
init|=
literal|0x1
block|,
comment|/**< Perform JSON escape */
name|UCL_STRING_TRIM
init|=
literal|0x2
block|,
comment|/**< Trim leading and trailing whitespaces */
name|UCL_STRING_PARSE_BOOLEAN
init|=
literal|0x4
block|,
comment|/**< Parse passed string and detect boolean */
name|UCL_STRING_PARSE_INT
init|=
literal|0x8
block|,
comment|/**< Parse passed string and detect integer number */
name|UCL_STRING_PARSE_DOUBLE
init|=
literal|0x10
block|,
comment|/**< Parse passed string and detect integer or float number */
name|UCL_STRING_PARSE_TIME
init|=
literal|0x20
block|,
comment|/**< Parse time strings */
name|UCL_STRING_PARSE_NUMBER
init|=
name|UCL_STRING_PARSE_INT
operator||
name|UCL_STRING_PARSE_DOUBLE
operator||
name|UCL_STRING_PARSE_TIME
block|,
comment|/**< 									Parse passed string and detect number */
name|UCL_STRING_PARSE
init|=
name|UCL_STRING_PARSE_BOOLEAN
operator||
name|UCL_STRING_PARSE_NUMBER
block|,
comment|/**< 									Parse passed string (and detect booleans and numbers) */
name|UCL_STRING_PARSE_BYTES
init|=
literal|0x40
comment|/**< Treat numbers as bytes */
block|}
name|ucl_string_flags_t
typedef|;
comment|/**  * Basic flags for an object  */
typedef|typedef
enum|enum
name|ucl_object_flags
block|{
name|UCL_OBJECT_ALLOCATED_KEY
init|=
literal|1
block|,
comment|/**< An object has key allocated internally */
name|UCL_OBJECT_ALLOCATED_VALUE
init|=
literal|2
block|,
comment|/**< An object has a string value allocated internally */
name|UCL_OBJECT_NEED_KEY_ESCAPE
init|=
literal|4
comment|/**< The key of an object need to be escaped on output */
block|}
name|ucl_object_flags_t
typedef|;
comment|/**  * UCL object structure. Please mention that the most of fields should not be touched by  * UCL users. In future, this structure may be converted to private one.  */
typedef|typedef
struct|struct
name|ucl_object_s
block|{
comment|/** 	 * Variant value type 	 */
union|union
block|{
name|int64_t
name|iv
decl_stmt|;
comment|/**< Int value of an object */
specifier|const
name|char
modifier|*
name|sv
decl_stmt|;
comment|/**< String value of an object */
name|double
name|dv
decl_stmt|;
comment|/**< Double value of an object */
name|struct
name|ucl_object_s
modifier|*
name|av
decl_stmt|;
comment|/**< Array					*/
name|void
modifier|*
name|ov
decl_stmt|;
comment|/**< Object					*/
name|void
modifier|*
name|ud
decl_stmt|;
comment|/**< Opaque user data		*/
block|}
name|value
union|;
specifier|const
name|char
modifier|*
name|key
decl_stmt|;
comment|/**< Key of an object		*/
name|struct
name|ucl_object_s
modifier|*
name|next
decl_stmt|;
comment|/**< Array handle			*/
name|struct
name|ucl_object_s
modifier|*
name|prev
decl_stmt|;
comment|/**< Array handle			*/
name|unsigned
name|char
modifier|*
name|trash_stack
index|[
literal|2
index|]
decl_stmt|;
comment|/**< Pointer to allocated chunks */
name|unsigned
name|keylen
decl_stmt|;
comment|/**< Lenght of a key		*/
name|unsigned
name|len
decl_stmt|;
comment|/**< Size of an object		*/
name|enum
name|ucl_type
name|type
decl_stmt|;
comment|/**< Real type				*/
name|uint16_t
name|ref
decl_stmt|;
comment|/**< Reference count		*/
name|uint16_t
name|flags
decl_stmt|;
comment|/**< Object flags			*/
block|}
name|ucl_object_t
typedef|;
comment|/** @} */
comment|/**  * @defgroup utils Utility functions  * A number of utility functions simplify handling of UCL objects  *  * @{  */
comment|/**  * Copy and return a key of an object, returned key is zero-terminated  * @param obj CL object  * @return zero terminated key  */
name|UCL_EXTERN
name|char
modifier|*
name|ucl_copy_key_trash
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|)
function_decl|;
comment|/**  * Copy and return a string value of an object, returned key is zero-terminated  * @param obj CL object  * @return zero terminated string representation of object value  */
name|UCL_EXTERN
name|char
modifier|*
name|ucl_copy_value_trash
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|)
function_decl|;
comment|/**  * Creates a new object  * @return new object  */
name|UCL_EXTERN
name|ucl_object_t
modifier|*
name|ucl_object_new
argument_list|(
name|void
argument_list|)
name|UCL_WARN_UNUSED_RESULT
decl_stmt|;
comment|/**  * Create new object with type specified  * @param type type of a new object  * @return new object  */
name|UCL_EXTERN
name|ucl_object_t
modifier|*
name|ucl_object_typed_new
argument_list|(
name|ucl_type_t
name|type
argument_list|)
name|UCL_WARN_UNUSED_RESULT
decl_stmt|;
comment|/**  * Return the type of an object  * @return the object type  */
name|UCL_EXTERN
name|ucl_type_t
name|ucl_object_type
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|)
function_decl|;
comment|/**  * Convert any string to an ucl object making the specified transformations  * @param str fixed size or NULL terminated string  * @param len length (if len is zero, than str is treated as NULL terminated)  * @param flags conversion flags  * @return new object  */
name|UCL_EXTERN
name|ucl_object_t
modifier|*
name|ucl_object_fromstring_common
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|,
name|size_t
name|len
argument_list|,
expr|enum
name|ucl_string_flags
name|flags
argument_list|)
name|UCL_WARN_UNUSED_RESULT
decl_stmt|;
comment|/**  * Create a UCL object from the specified string  * @param str NULL terminated string, will be json escaped  * @return new object  */
name|UCL_EXTERN
name|ucl_object_t
modifier|*
name|ucl_object_fromstring
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|)
name|UCL_WARN_UNUSED_RESULT
decl_stmt|;
comment|/**  * Create a UCL object from the specified string  * @param str fixed size string, will be json escaped  * @param len length of a string  * @return new object  */
name|UCL_EXTERN
name|ucl_object_t
modifier|*
name|ucl_object_fromlstring
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|,
name|size_t
name|len
argument_list|)
name|UCL_WARN_UNUSED_RESULT
decl_stmt|;
comment|/**  * Create an object from an integer number  * @param iv number  * @return new object  */
name|UCL_EXTERN
name|ucl_object_t
modifier|*
name|ucl_object_fromint
argument_list|(
name|int64_t
name|iv
argument_list|)
name|UCL_WARN_UNUSED_RESULT
decl_stmt|;
comment|/**  * Create an object from a float number  * @param dv number  * @return new object  */
name|UCL_EXTERN
name|ucl_object_t
modifier|*
name|ucl_object_fromdouble
argument_list|(
name|double
name|dv
argument_list|)
name|UCL_WARN_UNUSED_RESULT
decl_stmt|;
comment|/**  * Create an object from a boolean  * @param bv bool value  * @return new object  */
name|UCL_EXTERN
name|ucl_object_t
modifier|*
name|ucl_object_frombool
argument_list|(
name|bool
name|bv
argument_list|)
name|UCL_WARN_UNUSED_RESULT
decl_stmt|;
comment|/**  * Insert a object 'elt' to the hash 'top' and associate it with key 'key'  * @param top destination object (will be created automatically if top is NULL)  * @param elt element to insert (must NOT be NULL)  * @param key key to associate with this object (either const or preallocated)  * @param keylen length of the key (or 0 for NULL terminated keys)  * @param copy_key make an internal copy of key  * @return true if key has been inserted  */
name|UCL_EXTERN
name|bool
name|ucl_object_insert_key
parameter_list|(
name|ucl_object_t
modifier|*
name|top
parameter_list|,
name|ucl_object_t
modifier|*
name|elt
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|size_t
name|keylen
parameter_list|,
name|bool
name|copy_key
parameter_list|)
function_decl|;
comment|/**  * Replace a object 'elt' to the hash 'top' and associate it with key 'key', old object will be unrefed,  * if no object has been found this function works like ucl_object_insert_key()  * @param top destination object (will be created automatically if top is NULL)  * @param elt element to insert (must NOT be NULL)  * @param key key to associate with this object (either const or preallocated)  * @param keylen length of the key (or 0 for NULL terminated keys)  * @param copy_key make an internal copy of key  * @return true if key has been inserted  */
name|UCL_EXTERN
name|bool
name|ucl_object_replace_key
parameter_list|(
name|ucl_object_t
modifier|*
name|top
parameter_list|,
name|ucl_object_t
modifier|*
name|elt
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|size_t
name|keylen
parameter_list|,
name|bool
name|copy_key
parameter_list|)
function_decl|;
comment|/**  * Delete a object associated with key 'key', old object will be unrefered,  * @param top object  * @param key key associated to the object to remove  * @param keylen length of the key (or 0 for NULL terminated keys)  */
name|UCL_EXTERN
name|bool
name|ucl_object_delete_keyl
parameter_list|(
name|ucl_object_t
modifier|*
name|top
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|size_t
name|keylen
parameter_list|)
function_decl|;
comment|/**  * Delete a object associated with key 'key', old object will be unrefered,  * @param top object  * @param key key associated to the object to remove  */
name|UCL_EXTERN
name|bool
name|ucl_object_delete_key
parameter_list|(
name|ucl_object_t
modifier|*
name|top
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|)
function_decl|;
comment|/**  * Delete key from `top` object returning the object deleted. This object is not  * released  * @param top object  * @param key key to remove  * @param keylen length of the key (or 0 for NULL terminated keys)  * @return removed object or NULL if object has not been found  */
name|UCL_EXTERN
name|ucl_object_t
modifier|*
name|ucl_object_pop_keyl
argument_list|(
name|ucl_object_t
operator|*
name|top
argument_list|,
specifier|const
name|char
operator|*
name|key
argument_list|,
name|size_t
name|keylen
argument_list|)
name|UCL_WARN_UNUSED_RESULT
decl_stmt|;
comment|/**  * Delete key from `top` object returning the object deleted. This object is not  * released  * @param top object  * @param key key to remove  * @return removed object or NULL if object has not been found  */
name|UCL_EXTERN
name|ucl_object_t
modifier|*
name|ucl_object_pop_key
argument_list|(
name|ucl_object_t
operator|*
name|top
argument_list|,
specifier|const
name|char
operator|*
name|key
argument_list|)
name|UCL_WARN_UNUSED_RESULT
decl_stmt|;
comment|/**  * Insert a object 'elt' to the hash 'top' and associate it with key 'key', if the specified key exist,  * try to merge its content  * @param top destination object (will be created automatically if top is NULL)  * @param elt element to insert (must NOT be NULL)  * @param key key to associate with this object (either const or preallocated)  * @param keylen length of the key (or 0 for NULL terminated keys)  * @param copy_key make an internal copy of key  * @return true if key has been inserted  */
name|UCL_EXTERN
name|bool
name|ucl_object_insert_key_merged
parameter_list|(
name|ucl_object_t
modifier|*
name|top
parameter_list|,
name|ucl_object_t
modifier|*
name|elt
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|size_t
name|keylen
parameter_list|,
name|bool
name|copy_key
parameter_list|)
function_decl|;
comment|/**  * Append an element to the front of array object  * @param top destination object (will be created automatically if top is NULL)  * @param elt element to append (must NOT be NULL)  * @return true if value has been inserted  */
name|UCL_EXTERN
name|bool
name|ucl_array_append
parameter_list|(
name|ucl_object_t
modifier|*
name|top
parameter_list|,
name|ucl_object_t
modifier|*
name|elt
parameter_list|)
function_decl|;
comment|/**  * Append an element to the start of array object  * @param top destination object (will be created automatically if top is NULL)  * @param elt element to append (must NOT be NULL)  * @return true if value has been inserted  */
name|UCL_EXTERN
name|bool
name|ucl_array_prepend
parameter_list|(
name|ucl_object_t
modifier|*
name|top
parameter_list|,
name|ucl_object_t
modifier|*
name|elt
parameter_list|)
function_decl|;
comment|/**  * Removes an element `elt` from the array `top`. Caller must unref the returned object when it is not  * needed.  * @param top array ucl object  * @param elt element to remove  * @return removed element or NULL if `top` is NULL or not an array  */
name|UCL_EXTERN
name|ucl_object_t
modifier|*
name|ucl_array_delete
parameter_list|(
name|ucl_object_t
modifier|*
name|top
parameter_list|,
name|ucl_object_t
modifier|*
name|elt
parameter_list|)
function_decl|;
comment|/**  * Returns the first element of the array `top`  * @param top array ucl object  * @return element or NULL if `top` is NULL or not an array  */
name|UCL_EXTERN
specifier|const
name|ucl_object_t
modifier|*
name|ucl_array_head
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|top
parameter_list|)
function_decl|;
comment|/**  * Returns the last element of the array `top`  * @param top array ucl object  * @return element or NULL if `top` is NULL or not an array  */
name|UCL_EXTERN
specifier|const
name|ucl_object_t
modifier|*
name|ucl_array_tail
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|top
parameter_list|)
function_decl|;
comment|/**  * Removes the last element from the array `top`. Caller must unref the returned object when it is not  * needed.  * @param top array ucl object  * @return removed element or NULL if `top` is NULL or not an array  */
name|UCL_EXTERN
name|ucl_object_t
modifier|*
name|ucl_array_pop_last
parameter_list|(
name|ucl_object_t
modifier|*
name|top
parameter_list|)
function_decl|;
comment|/**  * Return object identified by an index of the array `top`  * @param obj object to get a key from (must be of type UCL_ARRAY)  * @param index index to return  * @return object at the specified index or NULL if index is not found  */
name|UCL_EXTERN
specifier|const
name|ucl_object_t
modifier|*
name|ucl_array_find_index
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|top
parameter_list|,
name|unsigned
name|int
name|index
parameter_list|)
function_decl|;
comment|/**  * Removes the first element from the array `top`. Caller must unref the returned object when it is not  * needed.  * @param top array ucl object  * @return removed element or NULL if `top` is NULL or not an array  */
name|UCL_EXTERN
name|ucl_object_t
modifier|*
name|ucl_array_pop_first
parameter_list|(
name|ucl_object_t
modifier|*
name|top
parameter_list|)
function_decl|;
comment|/**  * Append a element to another element forming an implicit array  * @param head head to append (may be NULL)  * @param elt new element  * @return true if element has been inserted  */
name|UCL_EXTERN
name|ucl_object_t
modifier|*
name|ucl_elt_append
parameter_list|(
name|ucl_object_t
modifier|*
name|head
parameter_list|,
name|ucl_object_t
modifier|*
name|elt
parameter_list|)
function_decl|;
comment|/**  * Converts an object to double value  * @param obj CL object  * @param target target double variable  * @return true if conversion was successful  */
name|UCL_EXTERN
name|bool
name|ucl_object_todouble_safe
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|,
name|double
modifier|*
name|target
parameter_list|)
function_decl|;
comment|/**  * Unsafe version of \ref ucl_obj_todouble_safe  * @param obj CL object  * @return double value  */
name|UCL_EXTERN
name|double
name|ucl_object_todouble
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|)
function_decl|;
comment|/**  * Converts an object to integer value  * @param obj CL object  * @param target target integer variable  * @return true if conversion was successful  */
name|UCL_EXTERN
name|bool
name|ucl_object_toint_safe
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|,
name|int64_t
modifier|*
name|target
parameter_list|)
function_decl|;
comment|/**  * Unsafe version of \ref ucl_obj_toint_safe  * @param obj CL object  * @return int value  */
name|UCL_EXTERN
name|int64_t
name|ucl_object_toint
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|)
function_decl|;
comment|/**  * Converts an object to boolean value  * @param obj CL object  * @param target target boolean variable  * @return true if conversion was successful  */
name|UCL_EXTERN
name|bool
name|ucl_object_toboolean_safe
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|,
name|bool
modifier|*
name|target
parameter_list|)
function_decl|;
comment|/**  * Unsafe version of \ref ucl_obj_toboolean_safe  * @param obj CL object  * @return boolean value  */
name|UCL_EXTERN
name|bool
name|ucl_object_toboolean
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|)
function_decl|;
comment|/**  * Converts an object to string value  * @param obj CL object  * @param target target string variable, no need to free value  * @return true if conversion was successful  */
name|UCL_EXTERN
name|bool
name|ucl_object_tostring_safe
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
comment|/**  * Unsafe version of \ref ucl_obj_tostring_safe  * @param obj CL object  * @return string value  */
name|UCL_EXTERN
specifier|const
name|char
modifier|*
name|ucl_object_tostring
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|)
function_decl|;
comment|/**  * Convert any object to a string in JSON notation if needed  * @param obj CL object  * @return string value  */
name|UCL_EXTERN
specifier|const
name|char
modifier|*
name|ucl_object_tostring_forced
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|)
function_decl|;
comment|/**  * Return string as char * and len, string may be not zero terminated, more efficient that \ref ucl_obj_tostring as it  * allows zero-copy (if #UCL_PARSER_ZEROCOPY has been used during parsing)  * @param obj CL object  * @param target target string variable, no need to free value  * @param tlen target length  * @return true if conversion was successful  */
name|UCL_EXTERN
name|bool
name|ucl_object_tolstring_safe
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|target
parameter_list|,
name|size_t
modifier|*
name|tlen
parameter_list|)
function_decl|;
comment|/**  * Unsafe version of \ref ucl_obj_tolstring_safe  * @param obj CL object  * @return string value  */
name|UCL_EXTERN
specifier|const
name|char
modifier|*
name|ucl_object_tolstring
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|,
name|size_t
modifier|*
name|tlen
parameter_list|)
function_decl|;
comment|/**  * Return object identified by a key in the specified object  * @param obj object to get a key from (must be of type UCL_OBJECT)  * @param key key to search  * @return object matched the specified key or NULL if key is not found  */
name|UCL_EXTERN
specifier|const
name|ucl_object_t
modifier|*
name|ucl_object_find_key
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|)
function_decl|;
comment|/**  * Return object identified by a fixed size key in the specified object  * @param obj object to get a key from (must be of type UCL_OBJECT)  * @param key key to search  * @param klen length of a key  * @return object matched the specified key or NULL if key is not found  */
name|UCL_EXTERN
specifier|const
name|ucl_object_t
modifier|*
name|ucl_object_find_keyl
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|size_t
name|klen
parameter_list|)
function_decl|;
comment|/**  * Return object identified by dot notation string  * @param obj object to search in  * @param path dot.notation.path to the path to lookup. May use numeric .index on arrays  * @return object matched the specified path or NULL if path is not found  */
name|UCL_EXTERN
specifier|const
name|ucl_object_t
modifier|*
name|ucl_lookup_path
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
comment|/**  * Returns a key of an object as a NULL terminated string  * @param obj CL object  * @return key or NULL if there is no key  */
name|UCL_EXTERN
specifier|const
name|char
modifier|*
name|ucl_object_key
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|)
function_decl|;
comment|/**  * Returns a key of an object as a fixed size string (may be more efficient)  * @param obj CL object  * @param len target key length  * @return key pointer  */
name|UCL_EXTERN
specifier|const
name|char
modifier|*
name|ucl_object_keyl
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
comment|/**  * Increase reference count for an object  * @param obj object to ref  */
name|UCL_EXTERN
name|ucl_object_t
modifier|*
name|ucl_object_ref
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|)
function_decl|;
comment|/**  * Free ucl object  * @param obj ucl object to free  */
name|UCL_DEPRECATED
argument_list|(
argument|UCL_EXTERN void ucl_object_free (ucl_object_t *obj)
argument_list|)
empty_stmt|;
comment|/**  * Decrease reference count for an object  * @param obj object to unref  */
name|UCL_EXTERN
name|void
name|ucl_object_unref
parameter_list|(
name|ucl_object_t
modifier|*
name|obj
parameter_list|)
function_decl|;
comment|/**  * Compare objects `o1` and `o2`  * @param o1 the first object  * @param o2 the second object  * @return values>0, 0 and<0 if `o1` is more than, equal and less than `o2`.  * The order of comparison:  * 1) Type of objects  * 2) Size of objects  * 3) Content of objects  */
name|UCL_EXTERN
name|int
name|ucl_object_compare
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|o1
parameter_list|,
specifier|const
name|ucl_object_t
modifier|*
name|o2
parameter_list|)
function_decl|;
comment|/**  * Sort UCL array using `cmp` compare function  * @param ar  * @param cmp  */
name|UCL_EXTERN
name|void
name|ucl_object_array_sort
parameter_list|(
name|ucl_object_t
modifier|*
name|ar
parameter_list|,
name|int
function_decl|(
modifier|*
name|cmp
function_decl|)
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|o1
parameter_list|,
specifier|const
name|ucl_object_t
modifier|*
name|o2
parameter_list|)
parameter_list|)
function_decl|;
comment|/**  * Opaque iterator object  */
typedef|typedef
name|void
modifier|*
name|ucl_object_iter_t
typedef|;
comment|/**  * Get next key from an object  * @param obj object to iterate  * @param iter opaque iterator, must be set to NULL on the first call:  * ucl_object_iter_t it = NULL;  * while ((cur = ucl_iterate_object (obj,&it)) != NULL) ...  * @return the next object or NULL  */
name|UCL_EXTERN
specifier|const
name|ucl_object_t
modifier|*
name|ucl_iterate_object
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|,
name|ucl_object_iter_t
modifier|*
name|iter
parameter_list|,
name|bool
name|expand_values
parameter_list|)
function_decl|;
comment|/** @} */
comment|/**  * @defgroup parser Parsing functions  * These functions are used to parse UCL objects  *  * @{  */
comment|/**  * Macro handler for a parser  * @param data the content of macro  * @param len the length of content  * @param ud opaque user data  * @param err error pointer  * @return true if macro has been parsed  */
typedef|typedef
name|bool
function_decl|(
modifier|*
name|ucl_macro_handler
function_decl|)
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|,
name|void
modifier|*
name|ud
parameter_list|)
function_decl|;
comment|/* Opaque parser */
struct_decl|struct
name|ucl_parser
struct_decl|;
comment|/**  * Creates new parser object  * @param pool pool to allocate memory from  * @return new parser object  */
name|UCL_EXTERN
name|struct
name|ucl_parser
modifier|*
name|ucl_parser_new
parameter_list|(
name|int
name|flags
parameter_list|)
function_decl|;
comment|/**  * Register new handler for a macro  * @param parser parser object  * @param macro macro name (without leading dot)  * @param handler handler (it is called immediately after macro is parsed)  * @param ud opaque user data for a handler  */
name|UCL_EXTERN
name|void
name|ucl_parser_register_macro
parameter_list|(
name|struct
name|ucl_parser
modifier|*
name|parser
parameter_list|,
specifier|const
name|char
modifier|*
name|macro
parameter_list|,
name|ucl_macro_handler
name|handler
parameter_list|,
name|void
modifier|*
name|ud
parameter_list|)
function_decl|;
comment|/**  * Handler to detect unregistered variables  * @param data variable data  * @param len length of variable  * @param replace (out) replace value for variable  * @param replace_len (out) replace length for variable  * @param need_free (out) UCL will free `dest` after usage  * @param ud opaque userdata  * @return true if variable  */
typedef|typedef
name|bool
function_decl|(
modifier|*
name|ucl_variable_handler
function_decl|)
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|*
name|replace
parameter_list|,
name|size_t
modifier|*
name|replace_len
parameter_list|,
name|bool
modifier|*
name|need_free
parameter_list|,
name|void
modifier|*
name|ud
parameter_list|)
function_decl|;
comment|/**  * Register new parser variable  * @param parser parser object  * @param var variable name  * @param value variable value  */
name|UCL_EXTERN
name|void
name|ucl_parser_register_variable
parameter_list|(
name|struct
name|ucl_parser
modifier|*
name|parser
parameter_list|,
specifier|const
name|char
modifier|*
name|var
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
comment|/**  * Set handler for unknown variables  * @param parser parser structure  * @param handler desired handler  * @param ud opaque data for the handler  */
name|UCL_EXTERN
name|void
name|ucl_parser_set_variables_handler
parameter_list|(
name|struct
name|ucl_parser
modifier|*
name|parser
parameter_list|,
name|ucl_variable_handler
name|handler
parameter_list|,
name|void
modifier|*
name|ud
parameter_list|)
function_decl|;
comment|/**  * Load new chunk to a parser  * @param parser parser structure  * @param data the pointer to the beginning of a chunk  * @param len the length of a chunk  * @param err if *err is NULL it is set to parser error  * @return true if chunk has been added and false in case of error  */
name|UCL_EXTERN
name|bool
name|ucl_parser_add_chunk
parameter_list|(
name|struct
name|ucl_parser
modifier|*
name|parser
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
comment|/**  * Load ucl object from a string  * @param parser parser structure  * @param data the pointer to the string  * @param len the length of the string, if `len` is 0 then `data` must be zero-terminated string  * @return true if string has been added and false in case of error  */
name|UCL_EXTERN
name|bool
name|ucl_parser_add_string
parameter_list|(
name|struct
name|ucl_parser
modifier|*
name|parser
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
comment|/**  * Load and add data from a file  * @param parser parser structure  * @param filename the name of file  * @param err if *err is NULL it is set to parser error  * @return true if chunk has been added and false in case of error  */
name|UCL_EXTERN
name|bool
name|ucl_parser_add_file
parameter_list|(
name|struct
name|ucl_parser
modifier|*
name|parser
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
comment|/**  * Load and add data from a file descriptor  * @param parser parser structure  * @param filename the name of file  * @param err if *err is NULL it is set to parser error  * @return true if chunk has been added and false in case of error  */
name|UCL_EXTERN
name|bool
name|ucl_parser_add_fd
parameter_list|(
name|struct
name|ucl_parser
modifier|*
name|parser
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
comment|/**  * Get a top object for a parser (refcount is increased)  * @param parser parser structure  * @param err if *err is NULL it is set to parser error  * @return top parser object or NULL  */
name|UCL_EXTERN
name|ucl_object_t
modifier|*
name|ucl_parser_get_object
parameter_list|(
name|struct
name|ucl_parser
modifier|*
name|parser
parameter_list|)
function_decl|;
comment|/**  * Get the error string if failing  * @param parser parser object  */
name|UCL_EXTERN
specifier|const
name|char
modifier|*
name|ucl_parser_get_error
parameter_list|(
name|struct
name|ucl_parser
modifier|*
name|parser
parameter_list|)
function_decl|;
comment|/**  * Free ucl parser object  * @param parser parser object  */
name|UCL_EXTERN
name|void
name|ucl_parser_free
parameter_list|(
name|struct
name|ucl_parser
modifier|*
name|parser
parameter_list|)
function_decl|;
comment|/**  * Add new public key to parser for signatures check  * @param parser parser object  * @param key PEM representation of a key  * @param len length of the key  * @param err if *err is NULL it is set to parser error  * @return true if a key has been successfully added  */
name|UCL_EXTERN
name|bool
name|ucl_pubkey_add
parameter_list|(
name|struct
name|ucl_parser
modifier|*
name|parser
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
comment|/**  * Set FILENAME and CURDIR variables in parser  * @param parser parser object  * @param filename filename to set or NULL to set FILENAME to "undef" and CURDIR to getcwd()  * @param need_expand perform realpath() if this variable is true and filename is not NULL  * @return true if variables has been set  */
name|UCL_EXTERN
name|bool
name|ucl_parser_set_filevars
parameter_list|(
name|struct
name|ucl_parser
modifier|*
name|parser
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|bool
name|need_expand
parameter_list|)
function_decl|;
comment|/** @} */
comment|/**  * @defgroup emitter Emitting functions  * These functions are used to serialise UCL objects to some string representation.  *  * @{  */
comment|/**  * Structure using for emitter callbacks  */
struct|struct
name|ucl_emitter_functions
block|{
comment|/** Append a single character */
name|int
function_decl|(
modifier|*
name|ucl_emitter_append_character
function_decl|)
parameter_list|(
name|unsigned
name|char
name|c
parameter_list|,
name|size_t
name|nchars
parameter_list|,
name|void
modifier|*
name|ud
parameter_list|)
function_decl|;
comment|/** Append a string of a specified length */
name|int
function_decl|(
modifier|*
name|ucl_emitter_append_len
function_decl|)
parameter_list|(
name|unsigned
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|len
parameter_list|,
name|void
modifier|*
name|ud
parameter_list|)
function_decl|;
comment|/** Append a 64 bit integer */
name|int
function_decl|(
modifier|*
name|ucl_emitter_append_int
function_decl|)
parameter_list|(
name|int64_t
name|elt
parameter_list|,
name|void
modifier|*
name|ud
parameter_list|)
function_decl|;
comment|/** Append floating point element */
name|int
function_decl|(
modifier|*
name|ucl_emitter_append_double
function_decl|)
parameter_list|(
name|double
name|elt
parameter_list|,
name|void
modifier|*
name|ud
parameter_list|)
function_decl|;
comment|/** Opaque userdata pointer */
name|void
modifier|*
name|ud
decl_stmt|;
block|}
struct|;
comment|/**  * Emit object to a string  * @param obj object  * @param emit_type if type is #UCL_EMIT_JSON then emit json, if type is  * #UCL_EMIT_CONFIG then emit config like object  * @return dump of an object (must be freed after using) or NULL in case of error  */
name|UCL_EXTERN
name|unsigned
name|char
modifier|*
name|ucl_object_emit
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|,
name|enum
name|ucl_emitter
name|emit_type
parameter_list|)
function_decl|;
comment|/**  * Emit object to a string  * @param obj object  * @param emit_type if type is #UCL_EMIT_JSON then emit json, if type is  * #UCL_EMIT_CONFIG then emit config like object  * @return dump of an object (must be freed after using) or NULL in case of error  */
name|UCL_EXTERN
name|bool
name|ucl_object_emit_full
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|,
name|enum
name|ucl_emitter
name|emit_type
parameter_list|,
name|struct
name|ucl_emitter_functions
modifier|*
name|emitter
parameter_list|)
function_decl|;
comment|/** @} */
comment|/**  * @defgroup schema Schema functions  * These functions are used to validate UCL objects using json schema format  *  * @{  */
comment|/**  * Used to define UCL schema error  */
enum|enum
name|ucl_schema_error_code
block|{
name|UCL_SCHEMA_OK
init|=
literal|0
block|,
comment|/**< no error */
name|UCL_SCHEMA_TYPE_MISMATCH
block|,
comment|/**< type of object is incorrect */
name|UCL_SCHEMA_INVALID_SCHEMA
block|,
comment|/**< schema is invalid */
name|UCL_SCHEMA_MISSING_PROPERTY
block|,
comment|/**< one or more missing properties */
name|UCL_SCHEMA_CONSTRAINT
block|,
comment|/**< constraint found */
name|UCL_SCHEMA_MISSING_DEPENDENCY
block|,
comment|/**< missing dependency */
name|UCL_SCHEMA_UNKNOWN
comment|/**< generic error */
block|}
enum|;
comment|/**  * Generic ucl schema error  */
struct|struct
name|ucl_schema_error
block|{
name|enum
name|ucl_schema_error_code
name|code
decl_stmt|;
comment|/**< error code */
name|char
name|msg
index|[
literal|128
index|]
decl_stmt|;
comment|/**< error message */
specifier|const
name|ucl_object_t
modifier|*
name|obj
decl_stmt|;
comment|/**< object where error occured */
block|}
struct|;
comment|/**  * Validate object `obj` using schema object `schema`.  * @param schema schema object  * @param obj object to validate  * @param err error pointer, if this parameter is not NULL and error has been  * occured, then `err` is filled with the exact error definition.  * @return true if `obj` is valid using `schema`  */
name|UCL_EXTERN
name|bool
name|ucl_object_validate
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|schema
parameter_list|,
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|,
name|struct
name|ucl_schema_error
modifier|*
name|err
parameter_list|)
function_decl|;
comment|/** @} */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX: Poorly named API functions, need to replace them with the appropriate  * named function. All API functions *must* use naming ucl_object_*. Usage of  * ucl_obj* should be avoided.  */
end_comment

begin_define
define|#
directive|define
name|ucl_obj_todouble_safe
value|ucl_object_todouble_safe
end_define

begin_define
define|#
directive|define
name|ucl_obj_todouble
value|ucl_object_todouble
end_define

begin_define
define|#
directive|define
name|ucl_obj_tostring
value|ucl_object_tostring
end_define

begin_define
define|#
directive|define
name|ucl_obj_tostring_safe
value|ucl_object_tostring_safe
end_define

begin_define
define|#
directive|define
name|ucl_obj_tolstring
value|ucl_object_tolstring
end_define

begin_define
define|#
directive|define
name|ucl_obj_tolstring_safe
value|ucl_object_tolstring_safe
end_define

begin_define
define|#
directive|define
name|ucl_obj_toint
value|ucl_object_toint
end_define

begin_define
define|#
directive|define
name|ucl_obj_toint_safe
value|ucl_object_toint_safe
end_define

begin_define
define|#
directive|define
name|ucl_obj_toboolean
value|ucl_object_toboolean
end_define

begin_define
define|#
directive|define
name|ucl_obj_toboolean_safe
value|ucl_object_toboolean_safe
end_define

begin_define
define|#
directive|define
name|ucl_obj_get_key
value|ucl_object_find_key
end_define

begin_define
define|#
directive|define
name|ucl_obj_get_keyl
value|ucl_object_find_keyl
end_define

begin_define
define|#
directive|define
name|ucl_obj_unref
value|ucl_object_unref
end_define

begin_define
define|#
directive|define
name|ucl_obj_ref
value|ucl_object_ref
end_define

begin_define
define|#
directive|define
name|ucl_obj_free
value|ucl_object_free
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UCL_H_ */
end_comment

end_unit

