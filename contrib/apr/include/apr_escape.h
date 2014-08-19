begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/**  * @file apr_escape.h  * @brief APR-UTIL Escaping  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_ESCAPE_H
end_ifndef

begin_define
define|#
directive|define
name|APR_ESCAPE_H
end_define

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_general.h"
end_include

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
comment|/**  * @defgroup APR_Util_Escaping Escape functions  * @ingroup APR  * @{  */
comment|/* Simple escape/unescape functions.  *  */
comment|/**  * When passing a string to one of the escape functions, this value can be  * passed to indicate a string-valued key, and have the length computed  * automatically.  */
define|#
directive|define
name|APR_ESCAPE_STRING
value|(-1)
comment|/**  * Perform shell escaping on the provided string.  *   * Shell escaping causes characters to be prefixed with a '\' character.  * @param escaped Optional buffer to write the encoded string, can be  * NULL  * @param str The original string  * @param slen The length of the original string, or APR_ESCAPE_STRING  * @param len If present, returns the length of the string  * @return APR_SUCCESS, or APR_NOTFOUND if no changes to the string were  * detected or the string was NULL  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_escape_shell
argument_list|(
argument|char *escaped
argument_list|,
argument|const char *str
argument_list|,
argument|apr_ssize_t slen
argument_list|,
argument|apr_size_t *len
argument_list|)
empty_stmt|;
comment|/**  * Perform shell escaping on the provided string, returning the result  * from the pool.  *  * Shell escaping causes characters to be prefixed with a '\' character.  *  * If no characters were escaped, the original string is returned.  * @param p Pool to allocate from  * @param str The original string  * @return the encoded string, allocated from the pool, or the original  * string if no escaping took place or the string was NULL.  */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_pescape_shell
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const char *str
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/**  * Unescapes a URL, leaving reserved characters intact.  * @param escaped Optional buffer to write the encoded string, can be  * NULL  * @param url String to be unescaped  * @param slen The length of the original url, or APR_ESCAPE_STRING  * @param forbid Optional list of forbidden characters, in addition to  * 0x00  * @param reserved Optional list of reserved characters that will be  * left unescaped  * @param plus If non zero, '+' is converted to ' ' as per  * application/x-www-form-urlencoded encoding  * @param len If set, the length of the escaped string will be returned  * @return APR_SUCCESS on success, APR_NOTFOUND if no characters are  * decoded or the string is NULL, APR_EINVAL if a bad escape sequence is  * found, APR_BADCH if a character on the forbid list is found.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_unescape_url
argument_list|(
argument|char *escaped
argument_list|,
argument|const char *url
argument_list|,
argument|apr_ssize_t slen
argument_list|,
argument|const char *forbid
argument_list|,
argument|const char *reserved
argument_list|,
argument|int plus
argument_list|,
argument|apr_size_t *len
argument_list|)
empty_stmt|;
comment|/**  * Unescapes a URL, leaving reserved characters intact, returning the  * result from a pool.  * @param p Pool to allocate from  * @param url String to be unescaped in place  * @param forbid Optional list of forbidden characters, in addition to  * 0x00  * @param reserved Optional list of reserved characters that will be  * left unescaped  * @param plus If non zero, '+' is converted to ' ' as per  * application/x-www-form-urlencoded encoding  * @return A string allocated from the pool on success, the original string  * if no characters are decoded, or NULL if a bad escape sequence is found  * or if a character on the forbid list is found, or if the original string  * was NULL.  */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_punescape_url
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const char *url
argument_list|,
argument|const char *forbid
argument_list|,
argument|const char *reserved
argument_list|,
argument|int plus
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/**  * Escape a path segment, as defined in RFC1808.  * @param escaped Optional buffer to write the encoded string, can be  * NULL  * @param str The original string  * @param slen The length of the original string, or APR_ESCAPE_STRING  * @param len If present, returns the length of the string  * @return APR_SUCCESS, or APR_NOTFOUND if no changes to the string were  * detected or the string was NULL  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_escape_path_segment
argument_list|(
argument|char *escaped
argument_list|,
argument|const char *str
argument_list|,
argument|apr_ssize_t slen
argument_list|,
argument|apr_size_t *len
argument_list|)
empty_stmt|;
comment|/**  * Escape a path segment, as defined in RFC1808, returning the result from a  * pool.  * @param p Pool to allocate from  * @param str String to be escaped  * @return A string allocated from the pool on success, the original string  * if no characters are encoded or the string is NULL.  */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_pescape_path_segment
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const char *str
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/**  * Converts an OS path to a URL, in an OS dependent way, as defined in RFC1808.  * In all cases if a ':' occurs before the first '/' in the URL, the URL should  * be prefixed with "./" (or the ':' escaped). In the case of Unix, this means  * leaving '/' alone, but otherwise doing what escape_path_segment() does. For  * efficiency reasons, we don't use escape_path_segment(), which is provided for  * reference. Again, RFC 1808 is where this stuff is defined.  *  * If partial is set, os_escape_path() assumes that the path will be appended to  * something with a '/' in it (and thus does not prefix "./").  * @param escaped Optional buffer to write the encoded string, can be  * NULL  * @param path The original string  * @param slen The length of the original string, or APR_ESCAPE_STRING  * @param partial If non zero, suppresses the prepending of "./"  * @param len If present, returns the length of the string  * @return APR_SUCCESS, or APR_NOTFOUND if no changes to the string were  * detected or if the string was NULL  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_escape_path
argument_list|(
argument|char *escaped
argument_list|,
argument|const char *path
argument_list|,
argument|apr_ssize_t slen
argument_list|,
argument|int partial
argument_list|,
argument|apr_size_t *len
argument_list|)
empty_stmt|;
comment|/**  * Converts an OS path to a URL, in an OS dependent way, as defined in RFC1808,  * returning the result from a pool.  *  * In all cases if a ':' occurs before the first '/' in the URL, the URL should  * be prefixed with "./" (or the ':' escaped). In the case of Unix, this means  * leaving '/' alone, but otherwise doing what escape_path_segment() does. For  * efficiency reasons, we don't use escape_path_segment(), which is provided for  * reference. Again, RFC 1808 is where this stuff is defined.  *  * If partial is set, os_escape_path() assumes that the path will be appended to  * something with a '/' in it (and thus does not prefix "./").  * @param p Pool to allocate from  * @param str The original string  * @param partial If non zero, suppresses the prepending of "./"  * @return A string allocated from the pool on success, the original string  * if no characters are encoded or if the string was NULL.  */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_pescape_path
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const char *str
argument_list|,
argument|int partial
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/**  * Urlencode a string, as defined in  * http://www.w3.org/TR/html401/interact/forms.html#h-17.13.4.1.  * @param escaped Optional buffer to write the encoded string, can be  * NULL  * @param str The original string  * @param slen The length of the original string, or APR_ESCAPE_STRING  * @param len If present, returns the length of the string  * @return APR_SUCCESS, or APR_NOTFOUND if no changes to the string were  * detected or if the stirng was NULL  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_escape_urlencoded
argument_list|(
argument|char *escaped
argument_list|,
argument|const char *str
argument_list|,
argument|apr_ssize_t slen
argument_list|,
argument|apr_size_t *len
argument_list|)
empty_stmt|;
comment|/**  * Urlencode a string, as defined in  * http://www.w3.org/TR/html401/interact/forms.html#h-17.13.4.1, returning  * the result from a pool.  * @param p Pool to allocate from  * @param str String to be escaped  * @return A string allocated from the pool on success, the original string  * if no characters are encoded or if the string was NULL.  */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_pescape_urlencoded
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const char *str
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/**  * Apply entity encoding to a string. Characters are replaced as follows:  * '<' becomes '&lt;', '>' becomes '&gt;', '&' becomes '&amp;', the  * double quote becomes '&quot;" and the single quote becomes '&apos;'.  *  * If toasc is not zero, any non ascii character will be encoded as  * '%\#ddd;', where ddd is the decimal code of the character.  * @param escaped Optional buffer to write the encoded string, can be  * NULL  * @param str The original string  * @param slen The length of the original string, or APR_ESCAPE_STRING  * @param toasc If non zero, encode non ascii characters  * @param len If present, returns the length of the string  * @return APR_SUCCESS, or APR_NOTFOUND if no changes to the string were  * detected or the string was NULL  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_escape_entity
argument_list|(
argument|char *escaped
argument_list|,
argument|const char *str
argument_list|,
argument|apr_ssize_t slen
argument_list|,
argument|int toasc
argument_list|,
argument|apr_size_t *len
argument_list|)
empty_stmt|;
comment|/**  * Apply entity encoding to a string, returning the result from a pool.  * Characters are replaced as follows: '<' becomes '&lt;', '>' becomes  * '&gt;', '&' becomes '&amp;', the double quote becomes '&quot;" and the  * single quote becomes '&apos;'.  * @param p Pool to allocate from  * @param str The original string  * @param toasc If non zero, encode non ascii characters  * @return A string allocated from the pool on success, the original string  * if no characters are encoded or the string is NULL.  */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_pescape_entity
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const char *str
argument_list|,
argument|int toasc
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/**  * Decodes html entities or numeric character references in a string. If  * the string to be unescaped is syntactically incorrect, then the  * following fixups will be made:  * unknown entities will be left undecoded;  * references to unused numeric characters will be deleted.  * In particular,&#00; will not be decoded, but will be deleted.  * @param unescaped Optional buffer to write the encoded string, can be  * NULL  * @param str The original string  * @param slen The length of the original string, or APR_ESCAPE_STRING  * @param len If present, returns the length of the string  * @return APR_SUCCESS, or APR_NOTFOUND if no changes to the string were  * detected or the string was NULL  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_unescape_entity
argument_list|(
argument|char *unescaped
argument_list|,
argument|const char *str
argument_list|,
argument|apr_ssize_t slen
argument_list|,
argument|apr_size_t *len
argument_list|)
empty_stmt|;
comment|/**  * Decodes html entities or numeric character references in a string. If  * the string to be unescaped is syntactically incorrect, then the  * following fixups will be made:  * unknown entities will be left undecoded;  * references to unused numeric characters will be deleted.  * In particular,&#00; will not be decoded, but will be deleted.  * @param p Pool to allocate from  * @param str The original string  * @return A string allocated from the pool on success, the original string  * if no characters are encoded or the string is NULL.  */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_punescape_entity
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const char *str
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/**  * Escape control characters in a string, as performed by the shell's  * 'echo' command. Characters are replaced as follows:  * \\a alert (bell), \\b backspace, \\f form feed, \\n new line, \\r carriage  * return, \\t horizontal tab, \\v vertical tab, \\ backslash.  *  * Any non ascii character will be encoded as '\\xHH', where HH is the hex  * code of the character.  *  * If quote is not zero, the double quote character will also be escaped.  * @param escaped Optional buffer to write the encoded string, can be  * NULL  * @param str The original string  * @param slen The length of the original string, or APR_ESCAPE_STRING  * @param quote If non zero, encode double quotes  * @param len If present, returns the length of the string  * @return APR_SUCCESS, or APR_NOTFOUND if no changes to the string were  * detected or the string was NULL  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_escape_echo
argument_list|(
argument|char *escaped
argument_list|,
argument|const char *str
argument_list|,
argument|apr_ssize_t slen
argument_list|,
argument|int quote
argument_list|,
argument|apr_size_t *len
argument_list|)
empty_stmt|;
comment|/**  * Escape control characters in a string, as performed by the shell's  * 'echo' command, and return the results from a pool. Characters are  * replaced as follows: \\a alert (bell), \\b backspace, \\f form feed,  * \\n new line, \\r carriage return, \\t horizontal tab, \\v vertical tab,  * \\ backslash.  *  * Any non ascii character will be encoded as '\\xHH', where HH is the hex  * code of the character.  *  * If quote is not zero, the double quote character will also be escaped.  * @param p Pool to allocate from  * @param str The original string  * @param quote If non zero, encode double quotes  * @return A string allocated from the pool on success, the original string  * if no characters are encoded or the string is NULL.  */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_pescape_echo
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const char *str
argument_list|,
argument|int quote
argument_list|)
empty_stmt|;
comment|/**  * Convert binary data to a hex encoding.  * @param dest The destination buffer, can be NULL  * @param src The original buffer  * @param srclen The length of the original buffer  * @param colon If not zero, insert colon characters between hex digits.  * @param len If present, returns the length of the string  * @return APR_SUCCESS, or APR_NOTFOUND if the string was NULL  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_escape_hex
argument_list|(
argument|char *dest
argument_list|,
argument|const void *src
argument_list|,
argument|apr_size_t srclen
argument_list|,
argument|int colon
argument_list|,
argument|apr_size_t *len
argument_list|)
empty_stmt|;
comment|/**  * Convert binary data to a hex encoding, and return the results from a  * pool.  * @param p Pool to allocate from  * @param src The original buffer  * @param slen The length of the original buffer  * @param colon If not zero, insert colon characters between hex digits.  * @return A zero padded buffer allocated from the pool on success, or  * NULL if src was NULL.  */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_pescape_hex
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const void *src
argument_list|,
argument|apr_size_t slen
argument_list|,
argument|int colon
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/**  * Convert hex encoded string to binary data.  * @param dest The destination buffer, can be NULL  * @param str The original buffer  * @param slen The length of the original buffer  * @param colon If not zero, ignore colon characters between hex digits.  * @param len If present, returns the length of the string  * @return APR_SUCCESS, or APR_NOTFOUND if the string was NULL, or APR_BADCH  * if a non hex character is present.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_unescape_hex
argument_list|(
argument|void *dest
argument_list|,
argument|const char *str
argument_list|,
argument|apr_ssize_t slen
argument_list|,
argument|int colon
argument_list|,
argument|apr_size_t *len
argument_list|)
empty_stmt|;
comment|/**  * Convert hex encoding to binary data, and return the results from a pool.  * If the colon character appears between pairs of hex digits, it will be  * ignored.  * @param p Pool to allocate from  * @param str The original string  * @param colon If not zero, ignore colon characters between hex digits.  * @param len If present, returns the length of the final buffer  * @return A buffer allocated from the pool on success, or NULL if src was  * NULL, or a bad character was present.  */
name|APR_DECLARE
argument_list|(
argument|const void *
argument_list|)
name|apr_punescape_hex
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const char *str
argument_list|,
argument|int colon
argument_list|,
argument|apr_size_t *len
argument_list|)
empty_stmt|;
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !APR_ESCAPE_H */
end_comment

end_unit

