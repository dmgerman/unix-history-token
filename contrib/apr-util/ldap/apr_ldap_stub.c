begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apu_config.h"
end_include

begin_include
include|#
directive|include
file|"apr_ldap.h"
end_include

begin_include
include|#
directive|include
file|"apu_internal.h"
end_include

begin_include
include|#
directive|include
file|"apr_dso.h"
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

begin_include
include|#
directive|include
file|"apr_strings.h"
end_include

begin_include
include|#
directive|include
file|"apu_version.h"
end_include

begin_if
if|#
directive|if
name|APR_HAS_LDAP
end_if

begin_if
if|#
directive|if
name|APU_DSO_BUILD
end_if

begin_decl_stmt
specifier|static
name|struct
name|apr__ldap_dso_fntable
modifier|*
name|lfn
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|apr_status_t
name|load_ldap
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
name|char
modifier|*
name|modname
decl_stmt|;
name|apr_dso_handle_sym_t
name|symbol
decl_stmt|;
name|apr_status_t
name|rv
decl_stmt|;
comment|/* deprecate in 2.0 - permit implicit initialization */
name|apu_dso_init
argument_list|(
name|pool
argument_list|)
expr_stmt|;
name|rv
operator|=
name|apu_dso_mutex_lock
argument_list|()
expr_stmt|;
if|if
condition|(
name|rv
condition|)
block|{
return|return
name|rv
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
name|modname
operator|=
literal|"apr_ldap-"
name|APU_STRINGIFY
argument_list|(
name|APU_MAJOR_VERSION
argument_list|)
literal|".dll"
expr_stmt|;
else|#
directive|else
name|modname
operator|=
literal|"apr_ldap-"
name|APU_STRINGIFY
argument_list|(
name|APU_MAJOR_VERSION
argument_list|)
literal|".so"
expr_stmt|;
endif|#
directive|endif
name|rv
operator|=
name|apu_dso_load
argument_list|(
name|NULL
argument_list|,
operator|&
name|symbol
argument_list|,
name|modname
argument_list|,
literal|"apr__ldap_fns"
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|rv
operator|==
name|APR_SUCCESS
condition|)
block|{
name|lfn
operator|=
name|symbol
expr_stmt|;
block|}
name|apu_dso_mutex_unlock
argument_list|()
expr_stmt|;
return|return
name|rv
return|;
block|}
end_function

begin_define
define|#
directive|define
name|LOAD_LDAP_STUB
parameter_list|(
name|pool
parameter_list|,
name|failres
parameter_list|)
define|\
value|if (!lfn&& (load_ldap(pool) != APR_SUCCESS)) \         return failres;
end_define

begin_macro
name|APU_DECLARE_LDAP
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_ldap_info
argument_list|(
argument|apr_pool_t *pool
argument_list|,
argument|apr_ldap_err_t **result_err
argument_list|)
end_macro

begin_block
block|{
name|LOAD_LDAP_STUB
argument_list|(
name|pool
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
name|lfn
operator|->
name|info
argument_list|(
name|pool
argument_list|,
name|result_err
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE_LDAP
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_ldap_init
argument_list|(
argument|apr_pool_t *pool
argument_list|,
argument|LDAP **ldap
argument_list|,
argument|const char *hostname
argument_list|,
argument|int portno
argument_list|,
argument|int secure
argument_list|,
argument|apr_ldap_err_t **result_err
argument_list|)
end_macro

begin_block
block|{
name|LOAD_LDAP_STUB
argument_list|(
name|pool
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
name|lfn
operator|->
name|init
argument_list|(
name|pool
argument_list|,
name|ldap
argument_list|,
name|hostname
argument_list|,
name|portno
argument_list|,
name|secure
argument_list|,
name|result_err
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE_LDAP
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_ldap_ssl_init
argument_list|(
argument|apr_pool_t *pool
argument_list|,
argument|const char *cert_auth_file
argument_list|,
argument|int cert_file_type
argument_list|,
argument|apr_ldap_err_t **result_err
argument_list|)
end_macro

begin_block
block|{
name|LOAD_LDAP_STUB
argument_list|(
name|pool
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
name|lfn
operator|->
name|ssl_init
argument_list|(
name|pool
argument_list|,
name|cert_auth_file
argument_list|,
name|cert_file_type
argument_list|,
name|result_err
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE_LDAP
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_ldap_ssl_deinit
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
operator|!
name|lfn
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|lfn
operator|->
name|ssl_deinit
argument_list|()
return|;
block|}
end_block

begin_macro
name|APU_DECLARE_LDAP
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_ldap_get_option
argument_list|(
argument|apr_pool_t *pool
argument_list|,
argument|LDAP *ldap
argument_list|,
argument|int option
argument_list|,
argument|void *outvalue
argument_list|,
argument|apr_ldap_err_t **result_err
argument_list|)
end_macro

begin_block
block|{
name|LOAD_LDAP_STUB
argument_list|(
name|pool
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
name|lfn
operator|->
name|get_option
argument_list|(
name|pool
argument_list|,
name|ldap
argument_list|,
name|option
argument_list|,
name|outvalue
argument_list|,
name|result_err
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE_LDAP
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_ldap_set_option
argument_list|(
argument|apr_pool_t *pool
argument_list|,
argument|LDAP *ldap
argument_list|,
argument|int option
argument_list|,
argument|const void *invalue
argument_list|,
argument|apr_ldap_err_t **result_err
argument_list|)
end_macro

begin_block
block|{
name|LOAD_LDAP_STUB
argument_list|(
name|pool
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
name|lfn
operator|->
name|set_option
argument_list|(
name|pool
argument_list|,
name|ldap
argument_list|,
name|option
argument_list|,
name|invalue
argument_list|,
name|result_err
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE_LDAP
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_ldap_rebind_init
argument_list|(
argument|apr_pool_t *pool
argument_list|)
end_macro

begin_block
block|{
name|LOAD_LDAP_STUB
argument_list|(
name|pool
argument_list|,
name|APR_EGENERAL
argument_list|)
expr_stmt|;
return|return
name|lfn
operator|->
name|rebind_init
argument_list|(
name|pool
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE_LDAP
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_ldap_rebind_add
argument_list|(
argument|apr_pool_t *pool
argument_list|,
argument|LDAP *ld
argument_list|,
argument|const char *bindDN
argument_list|,
argument|const char *bindPW
argument_list|)
end_macro

begin_block
block|{
name|LOAD_LDAP_STUB
argument_list|(
name|pool
argument_list|,
name|APR_EGENERAL
argument_list|)
expr_stmt|;
return|return
name|lfn
operator|->
name|rebind_add
argument_list|(
name|pool
argument_list|,
name|ld
argument_list|,
name|bindDN
argument_list|,
name|bindPW
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE_LDAP
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_ldap_rebind_remove
argument_list|(
argument|LDAP *ld
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
operator|!
name|lfn
condition|)
return|return
name|APR_EGENERAL
return|;
return|return
name|lfn
operator|->
name|rebind_remove
argument_list|(
name|ld
argument_list|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APU_DSO_BUILD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_HAS_LDAP */
end_comment

end_unit

