begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/*  * apr_ldap_init.c: LDAP v2/v3 common initialise  *   * Original code from auth_ldap module for Apache v1.3:  * Copyright 1998, 1999 Enbridge Pipelines Inc.   * Copyright 1999-2001 Dave Carrigan  */
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

begin_if
if|#
directive|if
name|APU_DSO_BUILD
end_if

begin_define
define|#
directive|define
name|APU_DSO_LDAP_BUILD
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|APR_HAS_LDAP
end_if

begin_comment
comment|/**  * APR LDAP SSL Initialise function  *  * This function initialises SSL on the underlying LDAP toolkit  * if this is necessary.  *  * If a CA certificate is provided, this is set, however the setting  * of certificates via this method has been deprecated and will be removed in  * APR v2.0.  *  * The apr_ldap_set_option() function with the APR_LDAP_OPT_TLS_CERT option  * should be used instead to set certificates.  *  * If SSL support is not available on this platform, or a problem  * was encountered while trying to set the certificate, the function  * will return APR_EGENERAL. Further LDAP specific error information  * can be found in result_err.  */
end_comment

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
name|apr_ldap_err_t
modifier|*
name|result
init|=
operator|(
name|apr_ldap_err_t
operator|*
operator|)
name|apr_pcalloc
argument_list|(
name|pool
argument_list|,
sizeof|sizeof
argument_list|(
name|apr_ldap_err_t
argument_list|)
argument_list|)
decl_stmt|;
operator|*
name|result_err
operator|=
name|result
expr_stmt|;
if|#
directive|if
name|APR_HAS_LDAP_SSL
comment|/* compiled with ssl support */
comment|/* Novell */
if|#
directive|if
name|APR_HAS_NOVELL_LDAPSDK
name|ldapssl_client_init
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* if a certificate was specified, set it */
if|if
condition|(
name|cert_auth_file
condition|)
block|{
name|apr_ldap_opt_tls_cert_t
modifier|*
name|cert
init|=
operator|(
name|apr_ldap_opt_tls_cert_t
operator|*
operator|)
name|apr_pcalloc
argument_list|(
name|pool
argument_list|,
sizeof|sizeof
argument_list|(
name|apr_ldap_opt_tls_cert_t
argument_list|)
argument_list|)
decl_stmt|;
name|cert
operator|->
name|type
operator|=
name|cert_file_type
expr_stmt|;
name|cert
operator|->
name|path
operator|=
name|cert_auth_file
expr_stmt|;
return|return
name|apr_ldap_set_option
argument_list|(
name|pool
argument_list|,
name|NULL
argument_list|,
name|APR_LDAP_OPT_TLS_CERT
argument_list|,
operator|(
name|void
operator|*
operator|)
name|cert
argument_list|,
name|result_err
argument_list|)
return|;
block|}
else|#
directive|else
comment|/* not compiled with SSL Support */
if|if
condition|(
name|cert_auth_file
condition|)
block|{
name|result
operator|->
name|reason
operator|=
literal|"LDAP: Attempt to set certificate store failed. "
literal|"Not built with SSL support"
expr_stmt|;
name|result
operator|->
name|rc
operator|=
operator|-
literal|1
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* APR_HAS_LDAP_SSL */
if|if
condition|(
name|result
operator|->
name|rc
operator|!=
operator|-
literal|1
condition|)
block|{
name|result
operator|->
name|msg
operator|=
name|ldap_err2string
argument_list|(
name|result
operator|->
name|rc
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|LDAP_SUCCESS
operator|!=
name|result
operator|->
name|rc
condition|)
block|{
return|return
name|APR_EGENERAL
return|;
block|}
return|return
name|APR_SUCCESS
return|;
block|}
end_block

begin_comment
comment|/**  * APR LDAP SSL De-Initialise function  *  * This function tears down any SSL certificate setup previously  * set using apr_ldap_ssl_init(). It should be called to clean  * up if a graceful restart of a service is attempted.  *  * This function only does anything on Netware.  *  * @todo currently we do not check whether apr_ldap_ssl_init()  * has been called first - should we?  */
end_comment

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
if|#
directive|if
name|APR_HAS_LDAP_SSL
operator|&&
name|APR_HAS_LDAPSSL_CLIENT_DEINIT
name|ldapssl_client_deinit
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
name|APR_SUCCESS
return|;
block|}
end_block

begin_comment
comment|/**  * APR LDAP initialise function  *  * This function is responsible for initialising an LDAP  * connection in a toolkit independant way. It does the  * job of ldap_init() from the C api.  *  * It handles both the SSL and non-SSL case, and attempts  * to hide the complexity setup from the user. This function  * assumes that any certificate setup necessary has already  * been done.  *  * If SSL or STARTTLS needs to be enabled, and the underlying  * toolkit supports it, the following values are accepted for  * secure:  *  * APR_LDAP_NONE: No encryption  * APR_LDAP_SSL: SSL encryption (ldaps://)  * APR_LDAP_STARTTLS: Force STARTTLS on ldap://  */
end_comment

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
name|apr_ldap_err_t
modifier|*
name|result
init|=
operator|(
name|apr_ldap_err_t
operator|*
operator|)
name|apr_pcalloc
argument_list|(
name|pool
argument_list|,
sizeof|sizeof
argument_list|(
name|apr_ldap_err_t
argument_list|)
argument_list|)
decl_stmt|;
operator|*
name|result_err
operator|=
name|result
expr_stmt|;
if|#
directive|if
name|APR_HAS_LDAPSSL_INIT
if|#
directive|if
name|APR_HAS_SOLARIS_LDAPSDK
comment|/*      * Using the secure argument should aways be possible.  But as LDAP SDKs      * tend to have different quirks and bugs, this needs to be tested for      * for each of them, first. For Solaris LDAP it works, and the method      * with ldap_set_option doesn't.      */
operator|*
name|ldap
operator|=
name|ldapssl_init
argument_list|(
name|hostname
argument_list|,
name|portno
argument_list|,
name|secure
operator|==
name|APR_LDAP_SSL
argument_list|)
expr_stmt|;
else|#
directive|else
operator|*
name|ldap
operator|=
name|ldapssl_init
argument_list|(
name|hostname
argument_list|,
name|portno
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
elif|#
directive|elif
name|APR_HAS_LDAP_SSLINIT
operator|*
name|ldap
operator|=
name|ldap_sslinit
argument_list|(
operator|(
name|char
operator|*
operator|)
name|hostname
argument_list|,
name|portno
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
operator|*
name|ldap
operator|=
name|ldap_init
argument_list|(
operator|(
name|char
operator|*
operator|)
name|hostname
argument_list|,
name|portno
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|*
name|ldap
operator|!=
name|NULL
condition|)
block|{
if|#
directive|if
name|APR_HAS_SOLARIS_LDAPSDK
if|if
condition|(
name|secure
operator|==
name|APR_LDAP_SSL
condition|)
return|return
name|APR_SUCCESS
return|;
else|else
endif|#
directive|endif
return|return
name|apr_ldap_set_option
argument_list|(
name|pool
argument_list|,
operator|*
name|ldap
argument_list|,
name|APR_LDAP_OPT_TLS
argument_list|,
operator|&
name|secure
argument_list|,
name|result_err
argument_list|)
return|;
block|}
else|else
block|{
comment|/* handle the error case */
name|apr_ldap_err_t
modifier|*
name|result
init|=
operator|(
name|apr_ldap_err_t
operator|*
operator|)
name|apr_pcalloc
argument_list|(
name|pool
argument_list|,
sizeof|sizeof
argument_list|(
name|apr_ldap_err_t
argument_list|)
argument_list|)
decl_stmt|;
operator|*
name|result_err
operator|=
name|result
expr_stmt|;
name|result
operator|->
name|reason
operator|=
literal|"APR LDAP: Unable to initialize the LDAP connection"
expr_stmt|;
name|result
operator|->
name|rc
operator|=
operator|-
literal|1
expr_stmt|;
return|return
name|APR_EGENERAL
return|;
block|}
block|}
end_block

begin_comment
comment|/**  * APR LDAP info function  *  * This function returns a string describing the LDAP toolkit  * currently in use. The string is placed inside result_err->reason.  */
end_comment

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
name|apr_ldap_err_t
modifier|*
name|result
init|=
operator|(
name|apr_ldap_err_t
operator|*
operator|)
name|apr_pcalloc
argument_list|(
name|pool
argument_list|,
sizeof|sizeof
argument_list|(
name|apr_ldap_err_t
argument_list|)
argument_list|)
decl_stmt|;
operator|*
name|result_err
operator|=
name|result
expr_stmt|;
name|result
operator|->
name|reason
operator|=
literal|"APR LDAP: Built with "
name|LDAP_VENDOR_NAME
literal|" LDAP SDK"
expr_stmt|;
return|return
name|APR_SUCCESS
return|;
block|}
end_block

begin_if
if|#
directive|if
name|APU_DSO_BUILD
end_if

begin_comment
comment|/* For DSO builds, export the table of entry points into the apr_ldap DSO  * See include/private/apu_internal.h for the corresponding declarations  */
end_comment

begin_decl_stmt
name|APU_MODULE_DECLARE_DATA
name|struct
name|apr__ldap_dso_fntable
name|apr__ldap_fns
init|=
block|{
name|apr_ldap_info
block|,
name|apr_ldap_init
block|,
name|apr_ldap_ssl_init
block|,
name|apr_ldap_ssl_deinit
block|,
name|apr_ldap_get_option
block|,
name|apr_ldap_set_option
block|,
name|apr_ldap_rebind_init
block|,
name|apr_ldap_rebind_add
block|,
name|apr_ldap_rebind_remove
block|}
decl_stmt|;
end_decl_stmt

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

