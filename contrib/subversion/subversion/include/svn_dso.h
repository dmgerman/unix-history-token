begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_dso.h  * @brief DSO loading routines  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_DSO_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_DSO_H
end_define

begin_include
include|#
directive|include
file|<apr_dso.h>
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
comment|/**  * Initialize the DSO loading routines.  *  * @note This should be called prior to the creation of any pool that  *       is passed to a function that comes from a DSO, otherwise you  *       risk having the DSO unloaded before all pool cleanup callbacks  *       that live in the DSO have been executed.  If it is not called  *       prior to @c svn_dso_load being used for the first time there  *       will be a best effort attempt made to initialize the subsystem,  *       but it will not be entirely thread safe and it risks running  *       into the previously mentioned problems with DSO unloading and  *       pool cleanup callbacks.  *  * Returns svn_error_t object with corresponding apr_err returned by  * underlying calls. In case of no error returns @c SVN_NO_ERROR.  *  * @since New in 1.6.  */
name|svn_error_t
modifier|*
name|svn_dso_initialize2
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/** The same as svn_dso_initialize2(), except that if there is an error this  * calls abort() instead of returning the error.  *  * @deprecated Provided for backwards compatibility with the 1.5 API.  *  * @since New in 1.4.  */
name|SVN_DEPRECATED
name|void
name|svn_dso_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
if|#
directive|if
name|APR_HAS_DSO
comment|/**  * Attempt to load @a libname, returning it in @a *dso.  *  * If @a libname cannot be loaded set @a *dso to NULL and return  * @c SVN_NO_ERROR.  *  * @note Due to pool lifetime issues DSOs are all loaded into a global  *       pool, so you must be certain that there is a bounded number of  *       them that will ever be loaded by the system, otherwise you will  *       leak memory.  *  * @since New in 1.4.  */
name|svn_error_t
modifier|*
name|svn_dso_load
parameter_list|(
name|apr_dso_handle_t
modifier|*
modifier|*
name|dso
parameter_list|,
specifier|const
name|char
modifier|*
name|libname
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* APR_HAS_DSO */
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
comment|/* SVN_DSO_H */
end_comment

end_unit

