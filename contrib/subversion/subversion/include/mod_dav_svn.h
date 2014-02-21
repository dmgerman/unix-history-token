begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file mod_dav_svn.h  * @brief Subversion's backend for Apache's mod_dav module  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|MOD_DAV_SVN_H
end_ifndef

begin_define
define|#
directive|define
name|MOD_DAV_SVN_H
end_define

begin_include
include|#
directive|include
file|<httpd.h>
end_include

begin_include
include|#
directive|include
file|<mod_dav.h>
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
comment|/**    Given an apache request @a r, a @a uri, and a @a root_path to the svn    location block, process @a uri and return many things, allocated in    @a r->pool:     - @a cleaned_uri:    The uri with duplicate and trailing slashes removed.     - @a trailing_slash: Whether the uri had a trailing slash on it.     Three special substrings of the uri are returned for convenience:     - @a repos_basename: The single path component that is the directory                       which contains the repository.  (Don't confuse                       this with the "repository name" as optionally                       defined via the SVNReposName directive!)     - @a relative_path:  The remaining imaginary path components.     - @a repos_path:     The actual path within the repository filesystem, or                       NULL if no part of the uri refers to a path in                       the repository (e.g. "!svn/vcc/default" or                       "!svn/bln/25").      For example, consider the uri         /svn/repos/proj1/!svn/blah/13//A/B/alpha     In the SVNPath case, this function would receive a @a root_path of    '/svn/repos/proj1', and in the SVNParentPath case would receive a    @a root_path of '/svn/repos'.  But either way, we would get back:       - @a cleaned_uri:    /svn/repos/proj1/!svn/blah/13/A/B/alpha      - @a repos_basename: proj1      - @a relative_path:  /!svn/blah/13/A/B/alpha      - @a repos_path:     A/B/alpha      - @a trailing_slash: FALSE */
name|AP_MODULE_DECLARE
argument_list|(
argument|dav_error *
argument_list|)
name|dav_svn_split_uri
argument_list|(
name|request_rec
operator|*
name|r
argument_list|,
specifier|const
name|char
operator|*
name|uri
argument_list|,
specifier|const
name|char
operator|*
name|root_path
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|cleaned_uri
argument_list|,
name|int
operator|*
name|trailing_slash
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|repos_basename
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|relative_path
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|repos_path
argument_list|)
expr_stmt|;
comment|/**  * Given an apache request @a r and a @a root_path to the svn location  * block, set @a *repos_path to the path of the repository on disk.  */
name|AP_MODULE_DECLARE
argument_list|(
argument|dav_error *
argument_list|)
name|dav_svn_get_repos_path
argument_list|(
name|request_rec
operator|*
name|r
argument_list|,
specifier|const
name|char
operator|*
name|root_path
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|repos_path
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

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MOD_DAV_SVN_H */
end_comment

end_unit

