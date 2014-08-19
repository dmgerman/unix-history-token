begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_VERSION_H
end_ifndef

begin_define
define|#
directive|define
name|APR_VERSION_H
end_define

begin_comment
comment|/**  * @file apr_version.h  * @brief APR Versioning Interface  *   * APR's Version  *  * There are several different mechanisms for accessing the version. There  * is a string form, and a set of numbers; in addition, there are constants  * which can be compiled into your application, and you can query the library  * being used for its actual version.  *  * Note that it is possible for an application to detect that it has been  * compiled against a different version of APR by use of the compile-time  * constants and the use of the run-time query function.  *  * APR version numbering follows the guidelines specified in:  *  *     http://apr.apache.org/versioning.html  */
end_comment

begin_define
define|#
directive|define
name|APR_COPYRIGHT
value|"Copyright (c) 2000-2014 The Apache Software " \                       "Foundation or its licensors, as applicable."
end_define

begin_comment
comment|/* The numeric compile-time version constants. These constants are the  * authoritative version numbers for APR.   */
end_comment

begin_comment
comment|/** major version   * Major API changes that could cause compatibility problems for older  * programs such as structure size changes.  No binary compatibility is  * possible across a change in the major version.  */
end_comment

begin_define
define|#
directive|define
name|APR_MAJOR_VERSION
value|1
end_define

begin_comment
comment|/** minor version  * Minor API changes that do not cause binary compatibility problems.  * Reset to 0 when upgrading APR_MAJOR_VERSION  */
end_comment

begin_define
define|#
directive|define
name|APR_MINOR_VERSION
value|5
end_define

begin_comment
comment|/** patch level   * The Patch Level never includes API changes, simply bug fixes.  * Reset to 0 when upgrading APR_MINOR_VERSION  */
end_comment

begin_define
define|#
directive|define
name|APR_PATCH_VERSION
value|1
end_define

begin_comment
comment|/**   * The symbol APR_IS_DEV_VERSION is only defined for internal,  * "development" copies of APR.  It is undefined for released versions  * of APR.  */
end_comment

begin_comment
comment|/* #define APR_IS_DEV_VERSION */
end_comment

begin_comment
comment|/**  * Check at compile time if the APR version is at least a certain  * level.  * @param major The major version component of the version checked  * for (e.g., the "1" of "1.3.0").  * @param minor The minor version component of the version checked  * for (e.g., the "3" of "1.3.0").  * @param patch The patch level component of the version checked  * for (e.g., the "0" of "1.3.0").  * @remark This macro is available with APR versions starting with  * 1.3.0.  */
end_comment

begin_define
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
value|(((major)< APR_MAJOR_VERSION)                                     \  || ((major) == APR_MAJOR_VERSION&& (minor)< APR_MINOR_VERSION) \  || ((major) == APR_MAJOR_VERSION&& (minor) == APR_MINOR_VERSION&& (patch)<= APR_PATCH_VERSION))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|APR_IS_DEV_VERSION
argument_list|)
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
end_if

begin_comment
comment|/** Internal: string form of the "is dev" flag */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_IS_DEV_STRING
end_ifndef

begin_define
define|#
directive|define
name|APR_IS_DEV_STRING
value|"-dev"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|APR_IS_DEV_STRING
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_STRINGIFY is defined here, and also in apr_general.h, so wrap it */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_STRINGIFY
end_ifndef

begin_comment
comment|/** Properly quote a value as a string in the C preprocessor */
end_comment

begin_define
define|#
directive|define
name|APR_STRINGIFY
parameter_list|(
name|n
parameter_list|)
value|APR_STRINGIFY_HELPER(n)
end_define

begin_comment
comment|/** Helper macro for APR_STRINGIFY */
end_comment

begin_define
define|#
directive|define
name|APR_STRINGIFY_HELPER
parameter_list|(
name|n
parameter_list|)
value|#n
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** The formatted string of APR's version */
end_comment

begin_define
define|#
directive|define
name|APR_VERSION_STRING
define|\
value|APR_STRINGIFY(APR_MAJOR_VERSION) "." \      APR_STRINGIFY(APR_MINOR_VERSION) "." \      APR_STRINGIFY(APR_PATCH_VERSION) \      APR_IS_DEV_STRING
end_define

begin_comment
comment|/** An alternative formatted string of APR's version */
end_comment

begin_comment
comment|/* macro for Win32 .rc files using numeric csv representation */
end_comment

begin_define
define|#
directive|define
name|APR_VERSION_STRING_CSV
value|APR_MAJOR_VERSION ##, \                              ##APR_MINOR_VERSION ##, \                              ##APR_PATCH_VERSION
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|APR_VERSION_ONLY
end_ifndef

begin_comment
comment|/* The C language API to access the version at run time,   * as opposed to compile time.  APR_VERSION_ONLY may be defined   * externally when preprocessing apr_version.h to obtain strictly   * the C Preprocessor macro declarations.  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
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
comment|/**   * The numeric version information is broken out into fields within this   * structure.   */
typedef|typedef
struct|struct
block|{
name|int
name|major
decl_stmt|;
comment|/**< major number */
name|int
name|minor
decl_stmt|;
comment|/**< minor number */
name|int
name|patch
decl_stmt|;
comment|/**< patch number */
name|int
name|is_dev
decl_stmt|;
comment|/**< is development (1 or 0) */
block|}
name|apr_version_t
typedef|;
comment|/**  * Return APR's version information information in a numeric form.  *  *  @param pvsn Pointer to a version structure for returning the version  *              information.  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_version
argument_list|(
name|apr_version_t
operator|*
name|pvsn
argument_list|)
expr_stmt|;
comment|/** Return APR's version information as a string. */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_version_string
argument_list|(
name|void
argument_list|)
expr_stmt|;
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
comment|/* ndef APR_VERSION_ONLY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef APR_VERSION_H */
end_comment

end_unit

