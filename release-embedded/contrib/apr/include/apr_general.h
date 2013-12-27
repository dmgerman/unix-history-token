begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_GENERAL_H
end_ifndef

begin_define
define|#
directive|define
name|APR_GENERAL_H
end_define

begin_comment
comment|/**  * @file apr_general.h  * This is collection of oddballs that didn't fit anywhere else,  * and might move to more appropriate headers with the release  * of APR 1.0.  * @brief APR Miscellaneous library routines  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_if
if|#
directive|if
name|APR_HAVE_SIGNAL_H
end_if

begin_include
include|#
directive|include
file|<signal.h>
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
comment|/**  * @defgroup apr_general Miscellaneous library routines  * @ingroup APR   * This is collection of oddballs that didn't fit anywhere else,  * and might move to more appropriate headers with the release  * of APR 1.0.  * @{  */
comment|/** FALSE */
ifndef|#
directive|ifndef
name|FALSE
define|#
directive|define
name|FALSE
value|0
endif|#
directive|endif
comment|/** TRUE */
ifndef|#
directive|ifndef
name|TRUE
define|#
directive|define
name|TRUE
value|(!FALSE)
endif|#
directive|endif
comment|/** a space */
define|#
directive|define
name|APR_ASCII_BLANK
value|'\040'
comment|/** a carrige return */
define|#
directive|define
name|APR_ASCII_CR
value|'\015'
comment|/** a line feed */
define|#
directive|define
name|APR_ASCII_LF
value|'\012'
comment|/** a tab */
define|#
directive|define
name|APR_ASCII_TAB
value|'\011'
comment|/** signal numbers typedef */
typedef|typedef
name|int
name|apr_signum_t
typedef|;
comment|/**  * Finding offsets of elements within structures.  * Taken from the X code... they've sweated portability of this stuff  * so we don't have to.  Sigh...  * @param p_type pointer type name  * @param field  data field within the structure pointed to  * @return offset  */
if|#
directive|if
name|defined
argument_list|(
name|CRAY
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__arm
argument_list|)
operator|&&
operator|!
operator|(
name|defined
argument_list|(
name|LINUX
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|)
operator|)
ifdef|#
directive|ifdef
name|__STDC__
define|#
directive|define
name|APR_OFFSET
parameter_list|(
name|p_type
parameter_list|,
name|field
parameter_list|)
value|_Offsetof(p_type,field)
else|#
directive|else
ifdef|#
directive|ifdef
name|CRAY2
define|#
directive|define
name|APR_OFFSET
parameter_list|(
name|p_type
parameter_list|,
name|field
parameter_list|)
define|\
value|(sizeof(int)*((unsigned int)&(((p_type)NULL)->field)))
else|#
directive|else
comment|/* !CRAY2 */
define|#
directive|define
name|APR_OFFSET
parameter_list|(
name|p_type
parameter_list|,
name|field
parameter_list|)
value|((unsigned int)&(((p_type)NULL)->field))
endif|#
directive|endif
comment|/* !CRAY2 */
endif|#
directive|endif
comment|/* __STDC__ */
else|#
directive|else
comment|/* ! (CRAY || __arm) */
define|#
directive|define
name|APR_OFFSET
parameter_list|(
name|p_type
parameter_list|,
name|field
parameter_list|)
define|\
value|((long) (((char *) (&(((p_type)NULL)->field))) - ((char *) NULL)))
endif|#
directive|endif
comment|/* !CRAY */
comment|/**  * Finding offsets of elements within structures.  * @param s_type structure type name  * @param field  data field within the structure  * @return offset  */
if|#
directive|if
name|defined
argument_list|(
name|offsetof
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__cplusplus
argument_list|)
define|#
directive|define
name|APR_OFFSETOF
parameter_list|(
name|s_type
parameter_list|,
name|field
parameter_list|)
value|offsetof(s_type,field)
else|#
directive|else
define|#
directive|define
name|APR_OFFSETOF
parameter_list|(
name|s_type
parameter_list|,
name|field
parameter_list|)
value|APR_OFFSET(s_type*,field)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|DOXYGEN
comment|/* A couple of prototypes for functions in case some platform doesn't   * have it  */
if|#
directive|if
operator|(
operator|!
name|APR_HAVE_STRCASECMP
operator|)
operator|&&
operator|(
name|APR_HAVE_STRICMP
operator|)
define|#
directive|define
name|strcasecmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|stricmp(s1, s2)
elif|#
directive|elif
operator|(
operator|!
name|APR_HAVE_STRCASECMP
operator|)
name|int
name|strcasecmp
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
specifier|const
name|char
modifier|*
name|b
parameter_list|)
function_decl|;
endif|#
directive|endif
if|#
directive|if
operator|(
operator|!
name|APR_HAVE_STRNCASECMP
operator|)
operator|&&
operator|(
name|APR_HAVE_STRNICMP
operator|)
define|#
directive|define
name|strncasecmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|strnicmp(s1, s2, n)
elif|#
directive|elif
operator|(
operator|!
name|APR_HAVE_STRNCASECMP
operator|)
name|int
name|strncasecmp
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
specifier|const
name|char
modifier|*
name|b
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
endif|#
directive|endif
endif|#
directive|endif
comment|/**  * Alignment macros  */
comment|/* APR_ALIGN() is only to be used to align on a power of 2 boundary */
define|#
directive|define
name|APR_ALIGN
parameter_list|(
name|size
parameter_list|,
name|boundary
parameter_list|)
define|\
value|(((size) + ((boundary) - 1))& ~((boundary) - 1))
comment|/** Default alignment */
define|#
directive|define
name|APR_ALIGN_DEFAULT
parameter_list|(
name|size
parameter_list|)
value|APR_ALIGN(size, 8)
comment|/**  * String and memory functions  */
comment|/* APR_STRINGIFY is defined here, and also in apr_release.h, so wrap it */
ifndef|#
directive|ifndef
name|APR_STRINGIFY
comment|/** Properly quote a value as a string in the C preprocessor */
define|#
directive|define
name|APR_STRINGIFY
parameter_list|(
name|n
parameter_list|)
value|APR_STRINGIFY_HELPER(n)
comment|/** Helper macro for APR_STRINGIFY */
define|#
directive|define
name|APR_STRINGIFY_HELPER
parameter_list|(
name|n
parameter_list|)
value|#n
endif|#
directive|endif
if|#
directive|if
operator|(
operator|!
name|APR_HAVE_MEMMOVE
operator|)
define|#
directive|define
name|memmove
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|bcopy(b,a,c)
endif|#
directive|endif
if|#
directive|if
operator|(
operator|!
name|APR_HAVE_MEMCHR
operator|)
name|void
modifier|*
name|memchr
parameter_list|(
specifier|const
name|void
modifier|*
name|s
parameter_list|,
name|int
name|c
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/** @} */
comment|/**  * @defgroup apr_library Library initialization and termination  * @{  */
comment|/**  * Setup any APR internal data structures.  This MUST be the first function   * called for any APR library. It is safe to call apr_initialize several  * times as long as apr_terminate is called the same number of times.  * @remark See apr_app_initialize if this is an application, rather than  * a library consumer of apr.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_initialize
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/**  * Set up an application with normalized argc, argv (and optionally env) in  * order to deal with platform-specific oddities, such as Win32 services,  * code pages and signals.  This must be the first function called for any  * APR program.  * @param argc Pointer to the argc that may be corrected  * @param argv Pointer to the argv that may be corrected  * @param env Pointer to the env that may be corrected, may be NULL  * @remark See apr_initialize if this is a library consumer of apr.  * Otherwise, this call is identical to apr_initialize, and must be closed  * with a call to apr_terminate at the end of program execution.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_app_initialize
argument_list|(
name|int
operator|*
name|argc
argument_list|,
name|char
specifier|const
operator|*
specifier|const
operator|*
operator|*
name|argv
argument_list|,
name|char
specifier|const
operator|*
specifier|const
operator|*
operator|*
name|env
argument_list|)
expr_stmt|;
comment|/**  * Tear down any APR internal data structures which aren't torn down   * automatically. apr_terminate must be called once for every call to  * apr_initialize() or apr_app_initialize().  * @remark An APR program must call this function at termination once it   *         has stopped using APR services.  The APR developers suggest using  *         atexit to ensure this is called.  When using APR from a language  *         other than C that has problems with the calling convention, use  *         apr_terminate2() instead.  */
name|APR_DECLARE_NONSTD
argument_list|(
argument|void
argument_list|)
name|apr_terminate
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/**  * Tear down any APR internal data structures which aren't torn down   * automatically, same as apr_terminate  * @remark An APR program must call either the apr_terminate or apr_terminate2   *         function once it it has finished using APR services.  The APR   *         developers suggest using atexit(apr_terminate) to ensure this is done.  *         apr_terminate2 exists to allow non-c language apps to tear down apr,   *         while apr_terminate is recommended from c language applications.  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_terminate2
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/** @} */
comment|/**  * @defgroup apr_random Random Functions  * @{  */
if|#
directive|if
name|APR_HAS_RANDOM
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/* TODO: I'm not sure this is the best place to put this prototype...*/
comment|/**  * Generate random bytes.  * @param buf Buffer to fill with random bytes  * @param length Length of buffer in bytes  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_generate_random_bytes
argument_list|(
argument|unsigned char * buf
argument_list|,
argument|apr_size_t length
argument_list|)
empty_stmt|;
endif|#
directive|endif
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
comment|/* ! APR_GENERAL_H */
end_comment

end_unit

