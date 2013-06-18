begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_string.h  * @brief Counted-length strings for Subversion, plus some C string goodies.  *  * There are two string datatypes: @c svn_string_t and @c svn_stringbuf_t.  * The former is a simple pointer/length pair useful for passing around  * strings (or arbitrary bytes) with a counted length. @c svn_stringbuf_t is  * buffered to enable efficient appending of strings without an allocation  * and copy for each append operation.  *  * @c svn_string_t contains a<tt>const char *</tt> for its data, so it is  * most appropriate for constant data and for functions which expect constant,  * counted data. Functions should generally use<tt>const @c svn_string_t  * *</tt> as their parameter to indicate they are expecting a constant,  * counted string.  *  * @c svn_stringbuf_t uses a plain<tt>char *</tt> for its data, so it is  * most appropriate for modifiable data.  *  *<h3>Invariants</h3>  *  *   1. Null termination:  *  *      Both structures maintain a significant invariant:  *  *<tt>s->data[s->len] == '\\0'</tt>  *  *      The functions defined within this header file will maintain  *      the invariant (which does imply that memory is  *      allocated/defined as @c len+1 bytes).  If code outside of the  *      @c svn_string.h functions manually builds these structures,  *      then they must enforce this invariant.  *  *      Note that an @c svn_string(buf)_t may contain binary data,  *      which means that strlen(s->data) does not have to equal @c  *      s->len. The null terminator is provided to make it easier to  *      pass @c s->data to C string interfaces.  *  *  *   2. Non-NULL input:  *  *      All the functions assume their input data pointer is non-NULL,  *      unless otherwise documented, and may seg fault if passed  *      NULL.  The input data may *contain* null bytes, of course, just  *      the data pointer itself must not be NULL.  *  *<h3>Memory allocation</h3>  *  *   All the functions make a deep copy of all input data, and never store  *   a pointer to the original input data.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_STRING_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_STRING_H
end_define

begin_include
include|#
directive|include
file|<apr.h>
end_include

begin_comment
comment|/* for apr_size_t */
end_comment

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_comment
comment|/* for apr_pool_t */
end_comment

begin_include
include|#
directive|include
file|<apr_tables.h>
end_include

begin_comment
comment|/* for apr_array_header_t */
end_comment

begin_include
include|#
directive|include
file|"svn_types.h"
end_include

begin_comment
comment|/* for svn_boolean_t, svn_error_t */
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
comment|/* __cplusplus */
comment|/**  * @defgroup svn_string String handling  * @{  */
comment|/** A simple counted string. */
typedef|typedef
struct|struct
name|svn_string_t
block|{
specifier|const
name|char
modifier|*
name|data
decl_stmt|;
comment|/**< pointer to the bytestring */
name|apr_size_t
name|len
decl_stmt|;
comment|/**< length of bytestring */
block|}
name|svn_string_t
typedef|;
comment|/** A buffered string, capable of appending without an allocation and copy  * for each append. */
typedef|typedef
struct|struct
name|svn_stringbuf_t
block|{
comment|/** a pool from which this string was originally allocated, and is not    * necessarily specific to this string.  This is used only for allocating    * more memory from when the string needs to grow.    */
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
comment|/** pointer to the bytestring */
name|char
modifier|*
name|data
decl_stmt|;
comment|/** length of bytestring */
name|apr_size_t
name|len
decl_stmt|;
comment|/** total size of buffer allocated */
name|apr_size_t
name|blocksize
decl_stmt|;
block|}
name|svn_stringbuf_t
typedef|;
comment|/**  * @defgroup svn_string_svn_string_t svn_string_t functions  * @{  */
comment|/** Create a new string copied from the null-terminated C string @a cstring.  */
name|svn_string_t
modifier|*
name|svn_string_create
parameter_list|(
specifier|const
name|char
modifier|*
name|cstring
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Create a new, empty string.  *  * @since New in 1.8.  */
name|svn_string_t
modifier|*
name|svn_string_create_empty
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Create a new string copied from a generic string of bytes, @a bytes, of  * length @a size bytes.  @a bytes is NOT assumed to be null-terminated, but  * the new string will be.  */
name|svn_string_t
modifier|*
name|svn_string_ncreate
parameter_list|(
specifier|const
name|char
modifier|*
name|bytes
parameter_list|,
name|apr_size_t
name|size
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Create a new string copied from the stringbuf @a strbuf.  */
name|svn_string_t
modifier|*
name|svn_string_create_from_buf
parameter_list|(
specifier|const
name|svn_stringbuf_t
modifier|*
name|strbuf
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Create a new string by printf-style formatting using @a fmt and the  * variable arguments, which are as appropriate for apr_psprintf().  */
name|svn_string_t
modifier|*
name|svn_string_createf
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
block|)
end_extern

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/** Create a new string by printf-style formatting using @c fmt and @a ap.  * This is the same as svn_string_createf() except for the different  * way of passing the variable arguments.  */
end_comment

begin_function_decl
name|svn_string_t
modifier|*
name|svn_string_createv
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/** Return TRUE if @a str is empty (has length zero). */
end_comment

begin_function_decl
name|svn_boolean_t
name|svn_string_isempty
parameter_list|(
specifier|const
name|svn_string_t
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return a duplicate of @a original_string. */
end_comment

begin_function_decl
name|svn_string_t
modifier|*
name|svn_string_dup
parameter_list|(
specifier|const
name|svn_string_t
modifier|*
name|original_string
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return @c TRUE iff @a str1 and @a str2 have identical length and data. */
end_comment

begin_function_decl
name|svn_boolean_t
name|svn_string_compare
parameter_list|(
specifier|const
name|svn_string_t
modifier|*
name|str1
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
name|str2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return offset of first non-whitespace character in @a str, or return  * @a str->len if none.  */
end_comment

begin_function_decl
name|apr_size_t
name|svn_string_first_non_whitespace
parameter_list|(
specifier|const
name|svn_string_t
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return position of last occurrence of @a ch in @a str, or return  * @a str->len if no occurrence.  */
end_comment

begin_function_decl
name|apr_size_t
name|svn_string_find_char_backward
parameter_list|(
specifier|const
name|svn_string_t
modifier|*
name|str
parameter_list|,
name|char
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_escape
end_escape

begin_comment
comment|/**  * @defgroup svn_string_svn_stringbuf_t svn_stringbuf_t functions  * @{  */
end_comment

begin_comment
comment|/** Create a new stringbuf copied from the null-terminated C string  * @a cstring.  */
end_comment

begin_function_decl
name|svn_stringbuf_t
modifier|*
name|svn_stringbuf_create
parameter_list|(
specifier|const
name|char
modifier|*
name|cstring
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Create a new stringbuf copied from the generic string of bytes, @a bytes,  * of length @a size bytes.  @a bytes is NOT assumed to be null-terminated,  * but the new stringbuf will be.  */
end_comment

begin_function_decl
name|svn_stringbuf_t
modifier|*
name|svn_stringbuf_ncreate
parameter_list|(
specifier|const
name|char
modifier|*
name|bytes
parameter_list|,
name|apr_size_t
name|size
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Create a new, empty stringbuf.  *  * @since New in 1.8.  */
end_comment

begin_function_decl
name|svn_stringbuf_t
modifier|*
name|svn_stringbuf_create_empty
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Create a new, empty stringbuf with at least @a minimum_size bytes of  * space available in the memory block.  *  * The allocated string buffer will be at least one byte larger than  * @a minimum_size to account for a final '\\0'.  *  * @since New in 1.6.  */
end_comment

begin_function_decl
name|svn_stringbuf_t
modifier|*
name|svn_stringbuf_create_ensure
parameter_list|(
name|apr_size_t
name|minimum_size
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Create a new stringbuf copied from the string @a str.  */
end_comment

begin_function_decl
name|svn_stringbuf_t
modifier|*
name|svn_stringbuf_create_from_string
parameter_list|(
specifier|const
name|svn_string_t
modifier|*
name|str
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Create a new stringbuf by printf-style formatting using @a fmt and the  * variable arguments, which are as appropriate for apr_psprintf().  */
end_comment

begin_function_decl
name|svn_stringbuf_t
modifier|*
name|svn_stringbuf_createf
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/** Create a new stringbuf by printf-style formatting using @c fmt and @a ap.  * This is the same as svn_stringbuf_createf() except for the different  * way of passing the variable arguments.  */
end_comment

begin_function_decl
name|svn_stringbuf_t
modifier|*
name|svn_stringbuf_createv
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/** Make sure that @a str has at least @a minimum_size  * bytes of space available in the memory block.  *  * The allocated string buffer will be at least one byte larger than  * @a minimum_size to account for a final '\\0'.  *  * @note: Before Subversion 1.8 this function did not ensure space for  * one byte more than @a minimum_size.  If compatibility with pre-1.8  * behaviour is required callers must assume space for only  * @a minimum_size-1 data bytes plus a final '\\0'.  */
end_comment

begin_function_decl
name|void
name|svn_stringbuf_ensure
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|str
parameter_list|,
name|apr_size_t
name|minimum_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Set @a str to a copy of the null-terminated C string @a value. */
end_comment

begin_function_decl
name|void
name|svn_stringbuf_set
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Set @a str to empty (zero length). */
end_comment

begin_function_decl
name|void
name|svn_stringbuf_setempty
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return @c TRUE if @a str is empty (has length zero). */
end_comment

begin_function_decl
name|svn_boolean_t
name|svn_stringbuf_isempty
parameter_list|(
specifier|const
name|svn_stringbuf_t
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Chop @a nbytes bytes off end of @a str, but not more than @a str->len. */
end_comment

begin_function_decl
name|void
name|svn_stringbuf_chop
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|str
parameter_list|,
name|apr_size_t
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Fill @a str with character @a c. */
end_comment

begin_function_decl
name|void
name|svn_stringbuf_fillchar
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|str
parameter_list|,
name|unsigned
name|char
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Append the single character @a byte onto @a targetstr.  *  * This is an optimized version of svn_stringbuf_appendbytes()  * that is much faster to call and execute. Gains vary with the ABI.  * The advantages extend beyond the actual call because the reduced  * register pressure allows for more optimization within the caller.  *  * reallocs if necessary. @a targetstr is affected, nothing else is.  * @since New in 1.7.  */
end_comment

begin_function_decl
name|void
name|svn_stringbuf_appendbyte
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|targetstr
parameter_list|,
name|char
name|byte
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Append an array of bytes onto @a targetstr.  *  * reallocs if necessary. @a targetstr is affected, nothing else is.  */
end_comment

begin_function_decl
name|void
name|svn_stringbuf_appendbytes
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|targetstr
parameter_list|,
specifier|const
name|char
modifier|*
name|bytes
parameter_list|,
name|apr_size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Append the stringbuf @c appendstr onto @a targetstr.  *  * reallocs if necessary. @a targetstr is affected, nothing else is.  */
end_comment

begin_function_decl
name|void
name|svn_stringbuf_appendstr
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|targetstr
parameter_list|,
specifier|const
name|svn_stringbuf_t
modifier|*
name|appendstr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Append the C string @a cstr onto @a targetstr.  *  * reallocs if necessary. @a targetstr is affected, nothing else is.  */
end_comment

begin_function_decl
name|void
name|svn_stringbuf_appendcstr
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|targetstr
parameter_list|,
specifier|const
name|char
modifier|*
name|cstr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Read @a count bytes from @a bytes and insert them into @a str at  * position @a pos and following.  The resulting string will be  * @c count+str->len bytes long.  If @c pos is larger or equal to the  * number of bytes currently used in @a str,  simply append @a bytes.  *  * Reallocs if necessary. @a str is affected, nothing else is.  *  * @note The inserted string may be a sub-range if @a str.  *  * @since New in 1.8.  */
end_comment

begin_function_decl
name|void
name|svn_stringbuf_insert
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|str
parameter_list|,
name|apr_size_t
name|pos
parameter_list|,
specifier|const
name|char
modifier|*
name|bytes
parameter_list|,
name|apr_size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Removes @a count bytes from @a str, starting at position @a pos.  * If that range exceeds the current string data,  @a str gets truncated  * at @a pos.  If the latter is larger or equal to @c str->pos, this will  * be a no-op.  Otherwise, the resulting string will be @c str->len-count  * bytes long.  *  * @since New in 1.8.  */
end_comment

begin_function_decl
name|void
name|svn_stringbuf_remove
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|str
parameter_list|,
name|apr_size_t
name|pos
parameter_list|,
name|apr_size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Replace in @a str the substring which starts at @a pos and is @a  * old_count bytes long with a new substring @a bytes (which is @a  * new_count bytes long).  *  * This is faster but functionally equivalent to the following sequence:  * @code      svn_stringbuf_remove(str, pos, old_count);      svn_stringbuf_insert(str, pos, bytes, new_count);  * @endcode  *  * @since New in 1.8.  */
end_comment

begin_function_decl
name|void
name|svn_stringbuf_replace
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|str
parameter_list|,
name|apr_size_t
name|pos
parameter_list|,
name|apr_size_t
name|old_count
parameter_list|,
specifier|const
name|char
modifier|*
name|bytes
parameter_list|,
name|apr_size_t
name|new_count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return a duplicate of @a original_string. */
end_comment

begin_function_decl
name|svn_stringbuf_t
modifier|*
name|svn_stringbuf_dup
parameter_list|(
specifier|const
name|svn_stringbuf_t
modifier|*
name|original_string
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return @c TRUE iff @a str1 and @a str2 have identical length and data. */
end_comment

begin_function_decl
name|svn_boolean_t
name|svn_stringbuf_compare
parameter_list|(
specifier|const
name|svn_stringbuf_t
modifier|*
name|str1
parameter_list|,
specifier|const
name|svn_stringbuf_t
modifier|*
name|str2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return offset of first non-whitespace character in @a str, or return  * @a str->len if none.  */
end_comment

begin_function_decl
name|apr_size_t
name|svn_stringbuf_first_non_whitespace
parameter_list|(
specifier|const
name|svn_stringbuf_t
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Strip whitespace from both sides of @a str (modified in place). */
end_comment

begin_function_decl
name|void
name|svn_stringbuf_strip_whitespace
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return position of last occurrence of @a ch in @a str, or return  * @a str->len if no occurrence.  */
end_comment

begin_function_decl
name|apr_size_t
name|svn_stringbuf_find_char_backward
parameter_list|(
specifier|const
name|svn_stringbuf_t
modifier|*
name|str
parameter_list|,
name|char
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return @c TRUE iff @a str1 and @a str2 have identical length and data. */
end_comment

begin_function_decl
name|svn_boolean_t
name|svn_string_compare_stringbuf
parameter_list|(
specifier|const
name|svn_string_t
modifier|*
name|str1
parameter_list|,
specifier|const
name|svn_stringbuf_t
modifier|*
name|str2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_escape
end_escape

begin_comment
comment|/**  * @defgroup svn_string_cstrings C string functions  * @{  */
end_comment

begin_comment
comment|/** Divide @a input into substrings along @a sep_chars boundaries, return an  * array of copies of those substrings (plain const char*), allocating both  * the array and the copies in @a pool.  *  * None of the elements added to the array contain any of the  * characters in @a sep_chars, and none of the new elements are empty  * (thus, it is possible that the returned array will have length  * zero).  *  * If @a chop_whitespace is TRUE, then remove leading and trailing  * whitespace from the returned strings.  */
end_comment

begin_function_decl
name|apr_array_header_t
modifier|*
name|svn_cstring_split
parameter_list|(
specifier|const
name|char
modifier|*
name|input
parameter_list|,
specifier|const
name|char
modifier|*
name|sep_chars
parameter_list|,
name|svn_boolean_t
name|chop_whitespace
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Like svn_cstring_split(), but append to existing @a array instead of  * creating a new one.  Allocate the copied substrings in @a pool  * (i.e., caller decides whether or not to pass @a array->pool as @a pool).  */
end_comment

begin_function_decl
name|void
name|svn_cstring_split_append
parameter_list|(
name|apr_array_header_t
modifier|*
name|array
parameter_list|,
specifier|const
name|char
modifier|*
name|input
parameter_list|,
specifier|const
name|char
modifier|*
name|sep_chars
parameter_list|,
name|svn_boolean_t
name|chop_whitespace
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return @c TRUE iff @a str matches any of the elements of @a list, a list  * of zero or more glob patterns.  */
end_comment

begin_function_decl
name|svn_boolean_t
name|svn_cstring_match_glob_list
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return @c TRUE iff @a str exactly matches any of the elements of @a list.  *  * @since new in 1.7  */
end_comment

begin_function_decl
name|svn_boolean_t
name|svn_cstring_match_list
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get the next token from @a *str interpreting any char from @a sep as a  * token separator.  Separators at the beginning of @a str will be skipped.  * Returns a pointer to the beginning of the first token in @a *str or NULL  * if no token is left.  Modifies @a str such that the next call will return  * the next token.  *  * @note The content of @a *str may be modified by this function.  *  * @since New in 1.8.  */
end_comment

begin_function_decl
name|char
modifier|*
name|svn_cstring_tokenize
parameter_list|(
specifier|const
name|char
modifier|*
name|sep
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return the number of line breaks in @a msg, allowing any kind of newline  * termination (CR, LF, CRLF, or LFCR), even inconsistent.  *  * @since New in 1.2.  */
end_comment

begin_function_decl
name|int
name|svn_cstring_count_newlines
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return a cstring which is the concatenation of @a strings (an array  * of char *) each followed by @a separator (that is, @a separator  * will also end the resulting string).  Allocate the result in @a pool.  * If @a strings is empty, then return the empty string.  *  * @since New in 1.2.  */
end_comment

begin_function_decl
name|char
modifier|*
name|svn_cstring_join
parameter_list|(
specifier|const
name|apr_array_header_t
modifier|*
name|strings
parameter_list|,
specifier|const
name|char
modifier|*
name|separator
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Compare two strings @a atr1 and @a atr2, treating case-equivalent  * unaccented Latin (ASCII subset) letters as equal.  *  * Returns in integer greater than, equal to, or less than 0,  * according to whether @a str1 is considered greater than, equal to,  * or less than @a str2.  *  * @since New in 1.5.  */
end_comment

begin_function_decl
name|int
name|svn_cstring_casecmp
parameter_list|(
specifier|const
name|char
modifier|*
name|str1
parameter_list|,
specifier|const
name|char
modifier|*
name|str2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Parse the C string @a str into a 64 bit number, and return it in @a *n.  * Assume that the number is represented in base @a base.  * Raise an error if conversion fails (e.g. due to overflow), or if the  * converted number is smaller than @a minval or larger than @a maxval.  *  * @since New in 1.7.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cstring_strtoi64
parameter_list|(
name|apr_int64_t
modifier|*
name|n
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|apr_int64_t
name|minval
parameter_list|,
name|apr_int64_t
name|maxval
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Parse the C string @a str into a 64 bit number, and return it in @a *n.  * Assume that the number is represented in base 10.  * Raise an error if conversion fails (e.g. due to overflow).  *  * @since New in 1.7.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cstring_atoi64
parameter_list|(
name|apr_int64_t
modifier|*
name|n
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Parse the C string @a str into a 32 bit number, and return it in @a *n.  * Assume that the number is represented in base 10.  * Raise an error if conversion fails (e.g. due to overflow).  *  * @since New in 1.7.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cstring_atoi
parameter_list|(
name|int
modifier|*
name|n
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Parse the C string @a str into an unsigned 64 bit number, and return  * it in @a *n. Assume that the number is represented in base @a base.  * Raise an error if conversion fails (e.g. due to overflow), or if the  * converted number is smaller than @a minval or larger than @a maxval.  *  * @since New in 1.7.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cstring_strtoui64
parameter_list|(
name|apr_uint64_t
modifier|*
name|n
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|apr_uint64_t
name|minval
parameter_list|,
name|apr_uint64_t
name|maxval
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Parse the C string @a str into an unsigned 64 bit number, and return  * it in @a *n. Assume that the number is represented in base 10.  * Raise an error if conversion fails (e.g. due to overflow).  *  * @since New in 1.7.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cstring_atoui64
parameter_list|(
name|apr_uint64_t
modifier|*
name|n
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Parse the C string @a str into an unsigned 32 bit number, and return  * it in @a *n. Assume that the number is represented in base 10.  * Raise an error if conversion fails (e.g. due to overflow).  *  * @since New in 1.7.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cstring_atoui
parameter_list|(
name|unsigned
name|int
modifier|*
name|n
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_STRING_H */
end_comment

end_unit

