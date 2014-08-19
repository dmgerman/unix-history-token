begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_LIB_H
end_ifndef

begin_define
define|#
directive|define
name|APR_LIB_H
end_define

begin_comment
comment|/**  * @file apr_lib.h  * This is collection of oddballs that didn't fit anywhere else,  * and might move to more appropriate headers with the release  * of APR 1.0.  * @brief APR general purpose library routines  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_if
if|#
directive|if
name|APR_HAVE_CTYPE_H
end_if

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_STDARG_H
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
comment|/**  * @defgroup apr_lib General Purpose Library Routines  * @ingroup APR   * This is collection of oddballs that didn't fit anywhere else,  * and might move to more appropriate headers with the release  * of APR 1.0.  * @{  */
comment|/** A constant representing a 'large' string. */
define|#
directive|define
name|HUGE_STRING_LEN
value|8192
comment|/*  * Define the structures used by the APR general-purpose library.  */
comment|/** @see apr_vformatter_buff_t */
typedef|typedef
name|struct
name|apr_vformatter_buff_t
name|apr_vformatter_buff_t
typedef|;
comment|/**  * Structure used by the variable-formatter routines.  */
struct|struct
name|apr_vformatter_buff_t
block|{
comment|/** The current position */
name|char
modifier|*
name|curpos
decl_stmt|;
comment|/** The end position of the format string */
name|char
modifier|*
name|endpos
decl_stmt|;
block|}
struct|;
comment|/**  * return the final element of the pathname  * @param pathname The path to get the final element of  * @return the final element of the path  * @remark  *<PRE>  * For example:  *                 "/foo/bar/gum"    -> "gum"  *                 "/foo/bar/gum/"   -> ""  *                 "gum"             -> "gum"  *                 "bs\\path\\stuff" -> "stuff"  *</PRE>  */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_filepath_name_get
argument_list|(
specifier|const
name|char
operator|*
name|pathname
argument_list|)
expr_stmt|;
comment|/**  * apr_killpg  * Small utility macros to make things easier to read.  Not usually a  * goal, to be sure..  */
ifdef|#
directive|ifdef
name|WIN32
define|#
directive|define
name|apr_killpg
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
else|#
directive|else
comment|/* WIN32 */
ifdef|#
directive|ifdef
name|NO_KILLPG
define|#
directive|define
name|apr_killpg
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(kill (-(x), (y)))
else|#
directive|else
comment|/* NO_KILLPG */
define|#
directive|define
name|apr_killpg
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(killpg ((x), (y)))
endif|#
directive|endif
comment|/* NO_KILLPG */
endif|#
directive|endif
comment|/* WIN32 */
comment|/**  * apr_vformatter() is a generic printf-style formatting routine  * with some extensions.  * @param flush_func The function to call when the buffer is full  * @param c The buffer to write to  * @param fmt The format string  * @param ap The arguments to use to fill out the format string.  *  * @remark  *<PRE>  * The extensions are:  *  * - %%pA takes a struct in_addr *, and prints it as a.b.c.d  * - %%pI takes an apr_sockaddr_t * and prints it as a.b.c.d:port or  * \[ipv6-address\]:port  * - %%pT takes an apr_os_thread_t * and prints it in decimal  * ('0' is printed if !APR_HAS_THREADS)  * - %%pt takes an apr_os_thread_t * and prints it in hexadecimal  * ('0' is printed if !APR_HAS_THREADS)  * - %%pm takes an apr_status_t * and prints the appropriate error  * string (from apr_strerror) corresponding to that error code.  * - %%pp takes a void * and outputs it in hex  * - %%pB takes a apr_uint32_t * as bytes and outputs it's apr_strfsize  * - %%pF same as above, but takes a apr_off_t *  * - %%pS same as above, but takes a apr_size_t *  *  * %%pA, %%pI, %%pT, %%pp are available from APR 1.0.0 onwards (and in 0.9.x).  * %%pt is only available from APR 1.2.0 onwards.  * %%pm, %%pB, %%pF and %%pS are only available from APR 1.3.0 onwards.  *  * The %%p hacks are to force gcc's printf warning code to skip  * over a pointer argument without complaining.  This does  * mean that the ANSI-style %%p (output a void * in hex format) won't  * work as expected at all, but that seems to be a fair trade-off  * for the increased robustness of having printf-warnings work.  *  * Additionally, apr_vformatter allows for arbitrary output methods  * using the apr_vformatter_buff and flush_func.  *  * The apr_vformatter_buff has two elements curpos and endpos.  * curpos is where apr_vformatter will write the next byte of output.  * It proceeds writing output to curpos, and updating curpos, until  * either the end of output is reached, or curpos == endpos (i.e. the  * buffer is full).  *  * If the end of output is reached, apr_vformatter returns the  * number of bytes written.  *  * When the buffer is full, the flush_func is called.  The flush_func  * can return -1 to indicate that no further output should be attempted,  * and apr_vformatter will return immediately with -1.  Otherwise  * the flush_func should flush the buffer in whatever manner is  * appropriate, re apr_pool_t nitialize curpos and endpos, and return 0.  *  * Note that flush_func is only invoked as a result of attempting to  * write another byte at curpos when curpos>= endpos.  So for  * example, it's possible when the output exactly matches the buffer  * space available that curpos == endpos will be true when  * apr_vformatter returns.  *  * apr_vformatter does not call out to any other code, it is entirely  * self-contained.  This allows the callers to do things which are  * otherwise "unsafe".  For example, apr_psprintf uses the "scratch"  * space at the unallocated end of a block, and doesn't actually  * complete the allocation until apr_vformatter returns.  apr_psprintf  * would be completely broken if apr_vformatter were to call anything  * that used this same pool.  Similarly http_bprintf() uses the "scratch"  * space at the end of its output buffer, and doesn't actually note  * that the space is in use until it either has to flush the buffer  * or until apr_vformatter returns.  *</PRE>  */
name|APR_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_vformatter
argument_list|(
argument|int (*flush_func)(apr_vformatter_buff_t *b)
argument_list|,
argument|apr_vformatter_buff_t *c
argument_list|,
argument|const char *fmt
argument_list|,
argument|va_list ap
argument_list|)
empty_stmt|;
comment|/**  * Display a prompt and read in the password from stdin.  * @param prompt The prompt to display  * @param pwbuf Buffer to store the password  * @param bufsize The length of the password buffer.  * @remark If the password entered must be truncated to fit in  * the provided buffer, APR_ENAMETOOLONG will be returned.  * Note that the bufsize paramater is passed by reference for no  * reason; its value will never be modified by the apr_password_get()  * function.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_password_get
argument_list|(
specifier|const
name|char
operator|*
name|prompt
argument_list|,
name|char
operator|*
name|pwbuf
argument_list|,
name|apr_size_t
operator|*
name|bufsize
argument_list|)
expr_stmt|;
comment|/** @} */
comment|/**  * @defgroup apr_ctype ctype functions  * These macros allow correct support of 8-bit characters on systems which  * support 8-bit characters.  Pretty dumb how the cast is required, but  * that's legacy libc for ya.  These new macros do not support EOF like  * the standard macros do.  Tough.  * @{  */
comment|/** @see isalnum */
define|#
directive|define
name|apr_isalnum
parameter_list|(
name|c
parameter_list|)
value|(isalnum(((unsigned char)(c))))
comment|/** @see isalpha */
define|#
directive|define
name|apr_isalpha
parameter_list|(
name|c
parameter_list|)
value|(isalpha(((unsigned char)(c))))
comment|/** @see iscntrl */
define|#
directive|define
name|apr_iscntrl
parameter_list|(
name|c
parameter_list|)
value|(iscntrl(((unsigned char)(c))))
comment|/** @see isdigit */
define|#
directive|define
name|apr_isdigit
parameter_list|(
name|c
parameter_list|)
value|(isdigit(((unsigned char)(c))))
comment|/** @see isgraph */
define|#
directive|define
name|apr_isgraph
parameter_list|(
name|c
parameter_list|)
value|(isgraph(((unsigned char)(c))))
comment|/** @see islower*/
define|#
directive|define
name|apr_islower
parameter_list|(
name|c
parameter_list|)
value|(islower(((unsigned char)(c))))
comment|/** @see isascii */
ifdef|#
directive|ifdef
name|isascii
define|#
directive|define
name|apr_isascii
parameter_list|(
name|c
parameter_list|)
value|(isascii(((unsigned char)(c))))
else|#
directive|else
define|#
directive|define
name|apr_isascii
parameter_list|(
name|c
parameter_list|)
value|(((c)& ~0x7f)==0)
endif|#
directive|endif
comment|/** @see isprint */
define|#
directive|define
name|apr_isprint
parameter_list|(
name|c
parameter_list|)
value|(isprint(((unsigned char)(c))))
comment|/** @see ispunct */
define|#
directive|define
name|apr_ispunct
parameter_list|(
name|c
parameter_list|)
value|(ispunct(((unsigned char)(c))))
comment|/** @see isspace */
define|#
directive|define
name|apr_isspace
parameter_list|(
name|c
parameter_list|)
value|(isspace(((unsigned char)(c))))
comment|/** @see isupper */
define|#
directive|define
name|apr_isupper
parameter_list|(
name|c
parameter_list|)
value|(isupper(((unsigned char)(c))))
comment|/** @see isxdigit */
define|#
directive|define
name|apr_isxdigit
parameter_list|(
name|c
parameter_list|)
value|(isxdigit(((unsigned char)(c))))
comment|/** @see tolower */
define|#
directive|define
name|apr_tolower
parameter_list|(
name|c
parameter_list|)
value|(tolower(((unsigned char)(c))))
comment|/** @see toupper */
define|#
directive|define
name|apr_toupper
parameter_list|(
name|c
parameter_list|)
value|(toupper(((unsigned char)(c))))
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
comment|/* ! APR_LIB_H */
end_comment

end_unit

