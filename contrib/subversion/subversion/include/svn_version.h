begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_version.h  * @brief Version information.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_VERSION_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_VERSION_H
end_define

begin_comment
comment|/* Hack to prevent the resource compiler from including    apr_general.h.  It doesn't resolve the include paths    correctly and blows up without this.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_STRINGIFY
end_ifndef

begin_include
include|#
directive|include
file|<apr_general.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<apr_tables.h>
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
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
comment|/* Symbols that define the version number. */
comment|/* Version numbers:<major>.<minor>.<micro>  *  * The version numbers in this file follow the rules established by:  *  *   http://apr.apache.org/versioning.html  */
comment|/** Major version number.  *  * Modify when incompatible changes are made to published interfaces.  */
define|#
directive|define
name|SVN_VER_MAJOR
value|1
comment|/** Minor version number.  *  * Modify when new functionality is added or new interfaces are  * defined, but all changes are backward compatible.  */
define|#
directive|define
name|SVN_VER_MINOR
value|8
comment|/**  * Patch number.  *  * Modify for every released patch.  *  * @since New in 1.1.  */
define|#
directive|define
name|SVN_VER_PATCH
value|10
comment|/** @deprecated Provided for backward compatibility with the 1.0 API. */
define|#
directive|define
name|SVN_VER_MICRO
value|SVN_VER_PATCH
comment|/** @deprecated Provided for backward compatibility with the 1.0 API. */
define|#
directive|define
name|SVN_VER_LIBRARY
value|SVN_VER_MAJOR
comment|/** Version tag: a string describing the version.  *  * This tag remains " (dev build)" in the repository so that we can  * always see from "svn --version" that the software has been built  * from the repository rather than a "blessed" distribution.  *  * When rolling a tarball, we automatically replace this text with " (r1234)"  * (where 1234 is the last revision on the branch prior to the release)  * for final releases; in prereleases, it becomes " (Alpha 1)",  * " (Beta 1)", etc., as appropriate.  *  * Always change this at the same time as SVN_VER_NUMTAG.  */
define|#
directive|define
name|SVN_VER_TAG
value|" (r1615264)"
comment|/** Number tag: a string describing the version.  *  * This tag is used to generate a version number string to identify  * the client and server in HTTP requests, for example. It must not  * contain any spaces. This value remains "-dev" in the repository.  *  * When rolling a tarball, we automatically replace this text with ""  * for final releases; in prereleases, it becomes "-alpha1, "-beta1",  * etc., as appropriate.  *  * Always change this at the same time as SVN_VER_TAG.  */
define|#
directive|define
name|SVN_VER_NUMTAG
value|""
comment|/** Revision number: The repository revision number of this release.  *  * This constant is used to generate the build number part of the Windows  * file version. Its value remains 0 in the repository.  *  * When rolling a tarball, we automatically replace it with what we  * guess to be the correct revision number.  */
define|#
directive|define
name|SVN_VER_REVISION
value|1615264
comment|/* Version strings composed from the above definitions. */
comment|/** Version number */
define|#
directive|define
name|SVN_VER_NUM
value|APR_STRINGIFY(SVN_VER_MAJOR) \                            "." APR_STRINGIFY(SVN_VER_MINOR) \                            "." APR_STRINGIFY(SVN_VER_PATCH)
comment|/** Version number with tag (contains no whitespace) */
define|#
directive|define
name|SVN_VER_NUMBER
value|SVN_VER_NUM SVN_VER_NUMTAG
comment|/** Complete version string */
define|#
directive|define
name|SVN_VERSION
value|SVN_VER_NUMBER SVN_VER_TAG
comment|/* Version queries and compatibility checks */
comment|/**  * Version information. Each library contains a function called  * svn_<i>libname</i>_version() that returns a pointer to a statically  * allocated object of this type.  *  * @since New in 1.1.  */
struct|struct
name|svn_version_t
block|{
name|int
name|major
decl_stmt|;
comment|/**< Major version number */
name|int
name|minor
decl_stmt|;
comment|/**< Minor version number */
name|int
name|patch
decl_stmt|;
comment|/**< Patch number */
comment|/**    * The version tag (#SVN_VER_NUMTAG). Must always point to a    * statically allocated string.    */
specifier|const
name|char
modifier|*
name|tag
decl_stmt|;
block|}
struct|;
comment|/**  * Define a static svn_version_t object.  *  * @since New in 1.1.  */
define|#
directive|define
name|SVN_VERSION_DEFINE
parameter_list|(
name|name
parameter_list|)
define|\
value|static const svn_version_t name = \     { \       SVN_VER_MAJOR, \       SVN_VER_MINOR, \       SVN_VER_PATCH, \       SVN_VER_NUMTAG \     }
block|\
comment|/**  * Generate the implementation of a version query function.  *  * @since New in 1.1.  */
define|#
directive|define
name|SVN_VERSION_BODY
define|\
value|SVN_VERSION_DEFINE(versioninfo);              \   return&versioninfo
comment|/**  * Check library version compatibility. Return #TRUE if the client's  * version, given in @a my_version, is compatible with the library  * version, provided in @a lib_version.  *  * This function checks for version compatibility as per our  * guarantees, but requires an exact match when linking to an  * unreleased library. A development client is always compatible with  * a previous released library.  *  * @since New in 1.1.  */
name|svn_boolean_t
name|svn_ver_compatible
parameter_list|(
specifier|const
name|svn_version_t
modifier|*
name|my_version
parameter_list|,
specifier|const
name|svn_version_t
modifier|*
name|lib_version
parameter_list|)
function_decl|;
comment|/**  * Check if @a my_version and @a lib_version encode the same version number.  *  * @since New in 1.2.  */
name|svn_boolean_t
name|svn_ver_equal
parameter_list|(
specifier|const
name|svn_version_t
modifier|*
name|my_version
parameter_list|,
specifier|const
name|svn_version_t
modifier|*
name|lib_version
parameter_list|)
function_decl|;
comment|/**  * An entry in the compatibility checklist.  * @see svn_ver_check_list()  *  * @since New in 1.1.  */
typedef|typedef
struct|struct
name|svn_version_checklist_t
block|{
specifier|const
name|char
modifier|*
name|label
decl_stmt|;
comment|/**< Entry label */
comment|/** Version query function for this entry */
specifier|const
name|svn_version_t
modifier|*
function_decl|(
modifier|*
name|version_query
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
name|svn_version_checklist_t
typedef|;
comment|/**  * Perform a series of version compatibility checks. Checks if @a  * my_version is compatible with each entry in @a checklist. @a  * checklist must end with an entry whose label is @c NULL.  *  * @see svn_ver_compatible()  *  * @since New in 1.1.  */
name|svn_error_t
modifier|*
name|svn_ver_check_list
parameter_list|(
specifier|const
name|svn_version_t
modifier|*
name|my_version
parameter_list|,
specifier|const
name|svn_version_checklist_t
modifier|*
name|checklist
parameter_list|)
function_decl|;
comment|/**  * Type of function returning library version.  *  * @since New in 1.6.  */
typedef|typedef
specifier|const
name|svn_version_t
modifier|*
function_decl|(
modifier|*
name|svn_version_func_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* libsvn_subr doesn't have an svn_subr header, so put the prototype here. */
comment|/**  * Get libsvn_subr version information.  *  * @since New in 1.1.  */
specifier|const
name|svn_version_t
modifier|*
name|svn_subr_version
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Extended version information, including info about the running system.  *  * @since New in 1.8.  */
typedef|typedef
name|struct
name|svn_version_extended_t
name|svn_version_extended_t
typedef|;
comment|/**  * Return version information for the running program.  If @a verbose  * is #TRUE, collect extra information that may be expensive to  * retrieve (for example, the OS release name, list of shared  * libraries, etc.).  Use @a pool for all allocations.  *  * @since New in 1.8.  */
specifier|const
name|svn_version_extended_t
modifier|*
name|svn_version_extended
parameter_list|(
name|svn_boolean_t
name|verbose
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Accessor for svn_version_extended_t.  *  * @return The date when the libsvn_subr library was compiled, in the  * format defined by the C standard macro @c __DATE__.  *  * @since New in 1.8.  */
specifier|const
name|char
modifier|*
name|svn_version_ext_build_date
parameter_list|(
specifier|const
name|svn_version_extended_t
modifier|*
name|ext_info
parameter_list|)
function_decl|;
comment|/**  * Accessor for svn_version_extended_t.  *  * @return The time when the libsvn_subr library was compiled, in the  * format defined by the C standard macro @c __TIME__.  *  * @since New in 1.8.  */
specifier|const
name|char
modifier|*
name|svn_version_ext_build_time
parameter_list|(
specifier|const
name|svn_version_extended_t
modifier|*
name|ext_info
parameter_list|)
function_decl|;
comment|/**  * Accessor for svn_version_extended_t.  *  * @return The canonical host triplet (arch-vendor-osname) of the  * system where libsvn_subr was compiled.  *  * @note On Unix-like systems (includng Mac OS X), this string is the  * same as the output of the config.guess script.  *  * @since New in 1.8.  */
specifier|const
name|char
modifier|*
name|svn_version_ext_build_host
parameter_list|(
specifier|const
name|svn_version_extended_t
modifier|*
name|ext_info
parameter_list|)
function_decl|;
comment|/**  * Accessor for svn_version_extended_t.  *  * @return The localized copyright notice.  *  * @since New in 1.8.  */
specifier|const
name|char
modifier|*
name|svn_version_ext_copyright
parameter_list|(
specifier|const
name|svn_version_extended_t
modifier|*
name|ext_info
parameter_list|)
function_decl|;
comment|/**  * Accessor for svn_version_extended_t.  *  * @return The canonical host triplet (arch-vendor-osname) of the  * system where the current process is running.  *  * @note This string may not be the same as the output of config.guess  * on the same system.  *  * @since New in 1.8.  */
specifier|const
name|char
modifier|*
name|svn_version_ext_runtime_host
parameter_list|(
specifier|const
name|svn_version_extended_t
modifier|*
name|ext_info
parameter_list|)
function_decl|;
comment|/**  * Accessor for svn_version_extended_t.  *  * @return The "commercial" release name of the running operating  * system, if available.  Not to be confused with, e.g., the output of  * "uname -v" or "uname -r".  The returned value may be @c NULL.  *  * @since New in 1.8.  */
specifier|const
name|char
modifier|*
name|svn_version_ext_runtime_osname
parameter_list|(
specifier|const
name|svn_version_extended_t
modifier|*
name|ext_info
parameter_list|)
function_decl|;
comment|/**  * Dependent library information.  * Describes the name and versions of known dependencies  * used by libsvn_subr.  *  * @since New in 1.8.  */
typedef|typedef
struct|struct
name|svn_version_ext_linked_lib_t
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/**< Library name */
specifier|const
name|char
modifier|*
name|compiled_version
decl_stmt|;
comment|/**< Compile-time version string */
specifier|const
name|char
modifier|*
name|runtime_version
decl_stmt|;
comment|/**< Run-time version string (optional) */
block|}
name|svn_version_ext_linked_lib_t
typedef|;
comment|/**  * Accessor for svn_version_extended_t.  *  * @return Array of svn_version_ext_linked_lib_t describing dependent  * libraries.  The returned value may be @c NULL.  *  * @since New in 1.8.  */
specifier|const
name|apr_array_header_t
modifier|*
name|svn_version_ext_linked_libs
parameter_list|(
specifier|const
name|svn_version_extended_t
modifier|*
name|ext_info
parameter_list|)
function_decl|;
comment|/**  * Loaded shared library information.  * Describes the name and, where available, version of the shared libraries  * loaded by the running program.  *  * @since New in 1.8.  */
typedef|typedef
struct|struct
name|svn_version_ext_loaded_lib_t
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/**< Library name */
specifier|const
name|char
modifier|*
name|version
decl_stmt|;
comment|/**< Library version (optional) */
block|}
name|svn_version_ext_loaded_lib_t
typedef|;
comment|/**  * Accessor for svn_version_extended_t.  *  * @return Array of svn_version_ext_loaded_lib_t describing loaded  * shared libraries.  The returned value may be @c NULL.  *  * @note On Mac OS X, the loaded frameworks, private frameworks and  * system libraries will not be listed.  *  * @since New in 1.8.  */
specifier|const
name|apr_array_header_t
modifier|*
name|svn_version_ext_loaded_libs
parameter_list|(
specifier|const
name|svn_version_extended_t
modifier|*
name|ext_info
parameter_list|)
function_decl|;
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
comment|/* SVN_VERSION_H */
end_comment

end_unit

