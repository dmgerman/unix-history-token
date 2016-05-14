begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_dep_compat.h  * @brief Compatibility macros and functions.  * @since New in 1.5.0.  */
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
comment|/**  * We assume that 'int' and 'unsigned' are at least 32 bits wide.  * This also implies that long (rev numbers) is 32 bits or wider.  *  * @since New in 1.9.  */
if|#
directive|if
name|defined
argument_list|(
name|APR_HAVE_LIMITS_H
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|SVN_ALLOW_SHORT_INTS
argument_list|)
expr|\
operator|&&
operator|(
name|INT_MAX
operator|<
literal|0x7FFFFFFFl
operator|)
error|#
directive|error
error|int is shorter than 32 bits and may break Subversion. Define SVN_ALLOW_SHORT_INTS to skip this check.
endif|#
directive|endif
comment|/**  * We assume that 'char' is 8 bits wide.  The critical interfaces are  * our repository formats and RA encodings.  E.g. a 32 bit wide char may  * mess up UTF8 parsing, how we interpret size values etc.  *  * @since New in 1.9.  */
if|#
directive|if
name|defined
argument_list|(
name|CHAR_BIT
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|SVN_ALLOW_NON_8_BIT_CHARS
argument_list|)
expr|\
operator|&&
operator|(
name|CHAR_BIT
operator|!=
literal|8
operator|)
error|#
directive|error
error|char is not 8 bits and may break Subversion. Define SVN_ALLOW_NON_8_BIT_CHARS to skip this check.
endif|#
directive|endif
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
comment|/**  * APR keeps a few interesting defines hidden away in its private  * headers apr_arch_file_io.h, so we redefined them here.  *  * @since New in 1.9  */
ifndef|#
directive|ifndef
name|APR_FREADONLY
define|#
directive|define
name|APR_FREADONLY
value|0x10000000
endif|#
directive|endif
ifndef|#
directive|ifndef
name|APR_OPENINFO
define|#
directive|define
name|APR_OPENINFO
value|0x00100000
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

