begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_fspath.h  * @brief Implementation of path manipulation functions similar to  *        those in svn_dirent_uri.h (which see for details) but for  *        the private fspath class of paths.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_FSPATH_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_FSPATH_H
end_define

begin_include
include|#
directive|include
file|<apr.h>
end_include

begin_include
include|#
directive|include
file|<apr_pools.h>
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
comment|/** Return TRUE iff @a fspath is canonical.  * @a fspath need not be canonical, of course.  *  * @since New in 1.7.  */
name|svn_boolean_t
name|svn_fspath__is_canonical
parameter_list|(
specifier|const
name|char
modifier|*
name|fspath
parameter_list|)
function_decl|;
comment|/** This function is similar to svn_relpath_canonicalize(), except  * that it returns an fspath (which is essentially just a relpath  * tacked onto a leading forward slash).  *  * The returned fspath may be statically allocated or allocated from  * @a pool.  *  * This is similar to svn_fs__canonicalize_abspath() but also treats "."  * segments as special.  *  * @since New in 1.7.  */
specifier|const
name|char
modifier|*
name|svn_fspath__canonicalize
parameter_list|(
specifier|const
name|char
modifier|*
name|fspath
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Return the dirname of @a fspath, defined as the path with its basename  * removed.  If @a fspath is "/", return "/".  *  * Allocate the result in @a pool.  *  * @since New in 1.7.  */
specifier|const
name|char
modifier|*
name|svn_fspath__dirname
parameter_list|(
specifier|const
name|char
modifier|*
name|fspath
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Return the last component of @a fspath.  The returned value will have no  * slashes in it.  If @a fspath is "/", return "".  *  * If @a pool is NULL, return a pointer to within @a fspath, else allocate  * the result in @a pool.  *  * @since New in 1.7.  */
specifier|const
name|char
modifier|*
name|svn_fspath__basename
parameter_list|(
specifier|const
name|char
modifier|*
name|fspath
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Divide the canonical @a fspath into @a *dirpath and @a  * *base_name, allocated in @a pool.  *  * If @a dirpath or @a base_name is NULL, then don't set that one.  *  * Either @a dirpath or @a base_name may be @a fspath's own address, but they  * may not both be the same address, or the results are undefined.  *  * If @a fspath has two or more components, the separator between @a dirpath  * and @a base_name is not included in either of the new names.  *  * @since New in 1.7.  */
name|void
name|svn_fspath__split
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|dirpath
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|base_name
parameter_list|,
specifier|const
name|char
modifier|*
name|fspath
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/** Return the fspath composed of @a fspath with @a relpath appended.  * Allocate the result in @a result_pool.  *  * @since New in 1.7.  */
name|char
modifier|*
name|svn_fspath__join
parameter_list|(
specifier|const
name|char
modifier|*
name|fspath
parameter_list|,
specifier|const
name|char
modifier|*
name|relpath
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/** Return TRUE if @a fspath (with length @a len) is the root  * directory; return FALSE otherwise.  *  * @since New in 1.7.  */
name|svn_boolean_t
name|svn_fspath__is_root
parameter_list|(
specifier|const
name|char
modifier|*
name|fspath
parameter_list|,
name|apr_size_t
name|len
parameter_list|)
function_decl|;
comment|/** Return the relative path part of @a child_fspath that is below  * @a parent_fspath, or just "" if @a parent_fspath is equal to  * @a child_fspath. If @a child_fspath is not below @a parent_fspath  * or equal to it, return @c NULL.  *  * @since New in 1.7.  */
specifier|const
name|char
modifier|*
name|svn_fspath__skip_ancestor
parameter_list|(
specifier|const
name|char
modifier|*
name|parent_fspath
parameter_list|,
specifier|const
name|char
modifier|*
name|child_fspath
parameter_list|)
function_decl|;
comment|/** Return the longest common path shared by two fspaths, @a fspath1 and  * @a fspath2.  If there's no common ancestor, return "/".  *  * @since New in 1.7.  */
name|char
modifier|*
name|svn_fspath__get_longest_ancestor
parameter_list|(
specifier|const
name|char
modifier|*
name|fspath1
parameter_list|,
specifier|const
name|char
modifier|*
name|fspath2
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/** A faux fspath API used by the DAV modules to help us distinguish  * between real URI-decoded fspaths and URI-encoded URL path-portions.  */
define|#
directive|define
name|svn_urlpath__basename
value|svn_fspath__basename
define|#
directive|define
name|svn_urlpath__dirname
value|svn_fspath__dirname
define|#
directive|define
name|svn_urlpath__get_longest_ancestor
value|svn_fspath__get_longest_ancestor
define|#
directive|define
name|svn_urlpath__is_canonical
value|svn_fspath__is_canonical
define|#
directive|define
name|svn_urlpath__is_root
value|svn_fspath__is_root
define|#
directive|define
name|svn_urlpath__join
value|svn_fspath__join
define|#
directive|define
name|svn_urlpath__skip_ancestor
value|svn_fspath__skip_ancestor
define|#
directive|define
name|svn_urlpath__split
value|svn_fspath__split
comment|/* Like svn_fspath__canonicalize(), but this one accepts both full    URLs and URL path-portions. */
specifier|const
name|char
modifier|*
name|svn_urlpath__canonicalize
parameter_list|(
specifier|const
name|char
modifier|*
name|uri
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
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
comment|/* SVN_FSPATH_H */
end_comment

end_unit

