begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_USER_H
end_ifndef

begin_define
define|#
directive|define
name|APR_USER_H
end_define

begin_comment
comment|/**  * @file apr_user.h  * @brief APR User ID Services   */
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

begin_include
include|#
directive|include
file|"apr_pools.h"
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
comment|/**  * @defgroup apr_user User and Group ID Services  * @ingroup APR   * @{  */
comment|/**  * Structure for determining user ownership.  */
ifdef|#
directive|ifdef
name|WIN32
typedef|typedef
name|PSID
name|apr_uid_t
typedef|;
else|#
directive|else
typedef|typedef
name|uid_t
name|apr_uid_t
typedef|;
endif|#
directive|endif
comment|/**  * Structure for determining group ownership.  */
ifdef|#
directive|ifdef
name|WIN32
typedef|typedef
name|PSID
name|apr_gid_t
typedef|;
else|#
directive|else
typedef|typedef
name|gid_t
name|apr_gid_t
typedef|;
endif|#
directive|endif
if|#
directive|if
name|APR_HAS_USER
comment|/**  * Get the userid (and groupid) of the calling process  * @param userid   Returns the user id  * @param groupid  Returns the user's group id  * @param p The pool from which to allocate working space  * @remark This function is available only if APR_HAS_USER is defined.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_uid_current
argument_list|(
name|apr_uid_t
operator|*
name|userid
argument_list|,
name|apr_gid_t
operator|*
name|groupid
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/**  * Get the user name for a specified userid  * @param username Pointer to new string containing user name (on output)  * @param userid The userid  * @param p The pool from which to allocate the string  * @remark This function is available only if APR_HAS_USER is defined.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_uid_name_get
argument_list|(
argument|char **username
argument_list|,
argument|apr_uid_t userid
argument_list|,
argument|apr_pool_t *p
argument_list|)
empty_stmt|;
comment|/**  * Get the userid (and groupid) for the specified username  * @param userid   Returns the user id  * @param groupid  Returns the user's group id  * @param username The username to look up  * @param p The pool from which to allocate working space  * @remark This function is available only if APR_HAS_USER is defined.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_uid_get
argument_list|(
name|apr_uid_t
operator|*
name|userid
argument_list|,
name|apr_gid_t
operator|*
name|groupid
argument_list|,
specifier|const
name|char
operator|*
name|username
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/**  * Get the home directory for the named user  * @param dirname Pointer to new string containing directory name (on output)  * @param username The named user  * @param p The pool from which to allocate the string  * @remark This function is available only if APR_HAS_USER is defined.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_uid_homepath_get
argument_list|(
name|char
operator|*
operator|*
name|dirname
argument_list|,
specifier|const
name|char
operator|*
name|username
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/**  * Compare two user identifiers for equality.  * @param left One uid to test  * @param right Another uid to test  * @return APR_SUCCESS if the apr_uid_t structures identify the same user,  * APR_EMISMATCH if not, APR_BADARG if an apr_uid_t is invalid.  * @remark This function is available only if APR_HAS_USER is defined.  */
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_uid_compare
argument_list|(
argument|apr_uid_t left
argument_list|,
argument|apr_uid_t right
argument_list|)
empty_stmt|;
else|#
directive|else
define|#
directive|define
name|apr_uid_compare
parameter_list|(
name|left
parameter_list|,
name|right
parameter_list|)
value|(((left) == (right)) ? APR_SUCCESS : APR_EMISMATCH)
endif|#
directive|endif
comment|/**  * Get the group name for a specified groupid  * @param groupname Pointer to new string containing group name (on output)  * @param groupid The groupid  * @param p The pool from which to allocate the string  * @remark This function is available only if APR_HAS_USER is defined.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_gid_name_get
argument_list|(
argument|char **groupname
argument_list|,
argument|apr_gid_t groupid
argument_list|,
argument|apr_pool_t *p
argument_list|)
empty_stmt|;
comment|/**  * Get the groupid for a specified group name  * @param groupid Pointer to the group id (on output)  * @param groupname The group name to look up  * @param p The pool from which to allocate the string  * @remark This function is available only if APR_HAS_USER is defined.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_gid_get
argument_list|(
name|apr_gid_t
operator|*
name|groupid
argument_list|,
specifier|const
name|char
operator|*
name|groupname
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/**  * Compare two group identifiers for equality.  * @param left One gid to test  * @param right Another gid to test  * @return APR_SUCCESS if the apr_gid_t structures identify the same group,  * APR_EMISMATCH if not, APR_BADARG if an apr_gid_t is invalid.  * @remark This function is available only if APR_HAS_USER is defined.  */
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_gid_compare
argument_list|(
argument|apr_gid_t left
argument_list|,
argument|apr_gid_t right
argument_list|)
empty_stmt|;
else|#
directive|else
define|#
directive|define
name|apr_gid_compare
parameter_list|(
name|left
parameter_list|,
name|right
parameter_list|)
value|(((left) == (right)) ? APR_SUCCESS : APR_EMISMATCH)
endif|#
directive|endif
endif|#
directive|endif
comment|/* ! APR_HAS_USER */
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
comment|/* ! APR_USER_H */
end_comment

end_unit

