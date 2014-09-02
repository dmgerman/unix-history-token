begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_compat.h  * @brief Compatibility macros and functions.  * @since New in 1.5.0.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_DEP_COMPAT_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_DEP_COMPAT_H
end_define

begin_include
include|#
directive|include
file|<apr_version.h>
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
comment|/* __cplusplus */
comment|/**  * Check at compile time if the APR version is at least a certain  * level.  * @param major The major version component of the version checked  * for (e.g., the "1" of "1.3.0").  * @param minor The minor version component of the version checked  * for (e.g., the "3" of "1.3.0").  * @param patch The patch level component of the version checked  * for (e.g., the "0" of "1.3.0").  *  * @since New in 1.5.  */
ifndef|#
directive|ifndef
name|APR_VERSION_AT_LEAST
comment|/* Introduced in APR 1.3.0 */
define|#
directive|define
name|APR_VERSION_AT_LEAST
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|,
name|patch
parameter_list|)
define|\
value|(((major)< APR_MAJOR_VERSION)                                       \  || ((major) == APR_MAJOR_VERSION&& (minor)< APR_MINOR_VERSION)    \  || ((major) == APR_MAJOR_VERSION&& (minor) == APR_MINOR_VERSION&& \      (patch)<= APR_PATCH_VERSION))
endif|#
directive|endif
comment|/* APR_VERSION_AT_LEAST */
comment|/**  * If we don't have a recent enough APR, emulate the behavior of the  * apr_array_clear() API.  */
if|#
directive|if
operator|!
name|APR_VERSION_AT_LEAST
argument_list|(
literal|1
operator|,
literal|3
operator|,
literal|0
argument_list|)
define|#
directive|define
name|apr_array_clear
parameter_list|(
name|arr
parameter_list|)
value|(arr)->nelts = 0
endif|#
directive|endif
if|#
directive|if
operator|!
name|APR_VERSION_AT_LEAST
argument_list|(
literal|1
operator|,
literal|3
operator|,
literal|0
argument_list|)
comment|/* Equivalent to the apr_hash_clear() function in APR>= 1.3.0.  Used to  * implement the 'apr_hash_clear' macro if the version of APR that  * we build against does not provide the apr_hash_clear() function. */
name|void
name|svn_hash__clear
parameter_list|(
name|struct
name|apr_hash_t
modifier|*
name|ht
parameter_list|)
function_decl|;
comment|/**  * If we don't have a recent enough APR, emulate the behavior of the  * apr_hash_clear() API.  */
define|#
directive|define
name|apr_hash_clear
parameter_list|(
name|ht
parameter_list|)
value|svn_hash__clear(ht)
endif|#
directive|endif
if|#
directive|if
operator|!
name|APR_VERSION_AT_LEAST
argument_list|(
literal|1
operator|,
literal|0
operator|,
literal|0
argument_list|)
define|#
directive|define
name|APR_UINT64_C
parameter_list|(
name|val
parameter_list|)
value|UINT64_C(val)
define|#
directive|define
name|APR_FPROT_OS_DEFAULT
value|APR_OS_DEFAULT
define|#
directive|define
name|apr_hash_make_custom
parameter_list|(
name|pool
parameter_list|,
name|hash_func
parameter_list|)
value|apr_hash_make(pool)
endif|#
directive|endif
if|#
directive|if
operator|!
name|APR_VERSION_AT_LEAST
argument_list|(
literal|1
operator|,
literal|3
operator|,
literal|0
argument_list|)
define|#
directive|define
name|APR_UINT16_MAX
value|0xFFFFU
define|#
directive|define
name|APR_INT16_MAX
value|0x7FFF
define|#
directive|define
name|APR_INT16_MIN
value|(-APR_INT16_MAX-1)
define|#
directive|define
name|APR_UINT32_MAX
value|0xFFFFFFFFU
define|#
directive|define
name|APR_INT32_MAX
value|0x7FFFFFFF
define|#
directive|define
name|APR_INT32_MIN
value|(-APR_INT32_MAX-1)
define|#
directive|define
name|APR_UINT64_MAX
value|APR_UINT64_C(0xFFFFFFFFFFFFFFFF)
define|#
directive|define
name|APR_INT64_MAX
value|APR_INT64_C(0x7FFFFFFFFFFFFFFF)
define|#
directive|define
name|APR_INT64_MIN
value|(-APR_INT64_MAX-1)
define|#
directive|define
name|APR_SIZE_MAX
value|(~(apr_size_t)0)
if|#
directive|if
name|APR_SIZEOF_VOIDP
operator|==
literal|8
typedef|typedef
name|apr_uint64_t
name|apr_uintptr_t
typedef|;
else|#
directive|else
typedef|typedef
name|apr_uint32_t
name|apr_uintptr_t
typedef|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* !APR_VERSION_AT_LEAST(1,3,0) */
comment|/**  * Work around a platform dependency issue. apr_thread_rwlock_trywrlock()  * will make APR_STATUS_IS_EBUSY() return TRUE if the lock could not be  * acquired under Unix. Under Windows, this will not work. So, provide  * a more portable substitute.  *  * @since New in 1.8.  */
ifdef|#
directive|ifdef
name|WIN32
define|#
directive|define
name|SVN_LOCK_IS_BUSY
parameter_list|(
name|x
parameter_list|)
define|\
value|(APR_STATUS_IS_EBUSY(x) || (x) == APR_FROM_OS_ERROR(WAIT_TIMEOUT))
else|#
directive|else
define|#
directive|define
name|SVN_LOCK_IS_BUSY
parameter_list|(
name|x
parameter_list|)
value|APR_STATUS_IS_EBUSY(x)
endif|#
directive|endif
if|#
directive|if
operator|!
name|APR_VERSION_AT_LEAST
argument_list|(
literal|1
operator|,
literal|4
operator|,
literal|0
argument_list|)
ifndef|#
directive|ifndef
name|apr_time_from_msec
define|#
directive|define
name|apr_time_from_msec
parameter_list|(
name|msec
parameter_list|)
value|((apr_time_t)(msec) * 1000)
endif|#
directive|endif
endif|#
directive|endif
comment|/**  * Check at compile time if the Serf version is at least a certain  * level.  * @param major The major version component of the version checked  * for (e.g., the "1" of "1.3.0").  * @param minor The minor version component of the version checked  * for (e.g., the "3" of "1.3.0").  * @param patch The patch level component of the version checked  * for (e.g., the "0" of "1.3.0").  *  * @since New in 1.5.  */
ifndef|#
directive|ifndef
name|SERF_VERSION_AT_LEAST
comment|/* Introduced in Serf 0.1.1 */
define|#
directive|define
name|SERF_VERSION_AT_LEAST
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|,
name|patch
parameter_list|)
define|\
value|(((major)< SERF_MAJOR_VERSION)                                        \  || ((major) == SERF_MAJOR_VERSION&& (minor)< SERF_MINOR_VERSION)    \  || ((major) == SERF_MAJOR_VERSION&& (minor) == SERF_MINOR_VERSION&& \      (patch)<= SERF_PATCH_VERSION))
endif|#
directive|endif
comment|/* SERF_VERSION_AT_LEAST */
comment|/**  * By default, if libsvn is built against one version of SQLite  * and then run using an older version, svn will error out:  *  *     svn: Couldn't perform atomic initialization  *     svn: SQLite compiled for 3.7.4, but running with 3.7.3  *  * That can be annoying when building on a modern system in order  * to deploy on a less modern one.  So these constants allow one  * to specify how old the system being deployed on might be.  * For example,  *  *     EXTRA_CFLAGS += -DSVN_SQLITE_MIN_VERSION_NUMBER=3007003  *     EXTRA_CFLAGS += '-DSVN_SQLITE_MIN_VERSION="3.7.3"'  *  * turns on code that works around infelicities in older versions  * as far back as 3.7.3 and relaxes the check at initialization time  * to permit them.  *  * @since New in 1.8.  */
ifndef|#
directive|ifndef
name|SVN_SQLITE_MIN_VERSION_NUMBER
define|#
directive|define
name|SVN_SQLITE_MIN_VERSION_NUMBER
value|SQLITE_VERSION_NUMBER
define|#
directive|define
name|SVN_SQLITE_MIN_VERSION
value|SQLITE_VERSION
endif|#
directive|endif
comment|/* SVN_SQLITE_MIN_VERSION_NUMBER */
comment|/**  * Check at compile time if the SQLite version is at least a certain  * level.  * @param major The major version component of the version checked  * for (e.g., the "1" of "1.3.0").  * @param minor The minor version component of the version checked  * for (e.g., the "3" of "1.3.0").  * @param patch The patch level component of the version checked  * for (e.g., the "0" of "1.3.0").  *  * @since New in 1.6.  */
ifndef|#
directive|ifndef
name|SQLITE_VERSION_AT_LEAST
define|#
directive|define
name|SQLITE_VERSION_AT_LEAST
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|,
name|patch
parameter_list|)
define|\
value|((major*1000000 + minor*1000 + patch)<= SVN_SQLITE_MIN_VERSION_NUMBER)
endif|#
directive|endif
comment|/* SQLITE_VERSION_AT_LEAST */
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
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_DEP_COMPAT_H */
end_comment

end_unit

