begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/**  * @file apr_ldap_init.h  * @brief  APR-UTIL LDAP ldap_init() functions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_LDAP_INIT_H
end_ifndef

begin_define
define|#
directive|define
name|APR_LDAP_INIT_H
end_define

begin_comment
comment|/**  * @addtogroup APR_Util_LDAP  * @{  */
end_comment

begin_include
include|#
directive|include
file|"apr_ldap.h"
end_include

begin_if
if|#
directive|if
name|APR_HAS_LDAP
end_if

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
comment|/**  * Macro to detect security related return values.  */
if|#
directive|if
name|defined
argument_list|(
name|LDAP_INSUFFICIENT_ACCESS
argument_list|)
define|#
directive|define
name|APU_LDAP_INSUFFICIENT_ACCESS
value|LDAP_INSUFFICIENT_ACCESS
elif|#
directive|elif
name|defined
argument_list|(
name|LDAP_INSUFFICIENT_RIGHTS
argument_list|)
define|#
directive|define
name|APU_LDAP_INSUFFICIENT_ACCESS
value|LDAP_INSUFFICIENT_RIGHTS
elif|#
directive|elif
name|defined
argument_list|(
name|APR_HAS_MICROSOFT_LDAPSDK
argument_list|)
comment|/* The macros above fail to contemplate that LDAP_RETCODE values  * may be represented by an enum.  autoconf tests would be much  * more robust.  */
define|#
directive|define
name|APU_LDAP_INSUFFICIENT_ACCESS
value|LDAP_INSUFFICIENT_RIGHTS
else|#
directive|else
error|#
directive|error
error|The security return codes must be added to support this LDAP toolkit.
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|LDAP_SECURITY_ERROR
argument_list|)
define|#
directive|define
name|APU_LDAP_SECURITY_ERROR
value|LDAP_SECURITY_ERROR
else|#
directive|else
define|#
directive|define
name|APU_LDAP_SECURITY_ERROR
parameter_list|(
name|n
parameter_list|)
define|\
value|(LDAP_INAPPROPRIATE_AUTH == n) ? 1 \     : (LDAP_INVALID_CREDENTIALS == n) ? 1 \     : (APU_LDAP_INSUFFICIENT_ACCESS == n) ? 1 \     : 0
endif|#
directive|endif
comment|/**  * APR LDAP SSL Initialise function  *  * This function initialises SSL on the underlying LDAP toolkit  * if this is necessary.  *  * If a CA certificate is provided, this is set, however the setting  * of certificates via this method has been deprecated and will be removed in  * APR v2.0.  *  * The apr_ldap_set_option() function with the APR_LDAP_OPT_TLS_CERT option  * should be used instead to set certificates.  *  * If SSL support is not available on this platform, or a problem  * was encountered while trying to set the certificate, the function  * will return APR_EGENERAL. Further LDAP specific error information  * can be found in result_err.  * @param pool The pool to use  * @param cert_auth_file The name of the certificate to use, can be NULL  * @param cert_file_type The type of certificate specified. See the  * apr_ldap_set_option() APR_LDAP_OPT_TLS_CERT option for details.  * @param result_err The returned result  */
name|APU_DECLARE_LDAP
argument_list|(
argument|int
argument_list|)
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
empty_stmt|;
comment|/**  * APR LDAP SSL De-Initialise function  *  * This function tears down any SSL certificate setup previously  * set using apr_ldap_ssl_init(). It should be called to clean  * up if a graceful restart of a service is attempted.  * @todo currently we do not check whether apr_ldap_ssl_init()  * has been called first - we probably should.  */
name|APU_DECLARE_LDAP
argument_list|(
argument|int
argument_list|)
name|apr_ldap_ssl_deinit
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/**  * APR LDAP initialise function  *  * This function is responsible for initialising an LDAP  * connection in a toolkit independant way. It does the  * job of ldap_init() from the C api.  *  * It handles both the SSL and non-SSL case, and attempts  * to hide the complexity setup from the user. This function  * assumes that any certificate setup necessary has already  * been done.  *  * If SSL or STARTTLS needs to be enabled, and the underlying  * toolkit supports it, the following values are accepted for  * secure:  *  * APR_LDAP_NONE: No encryption  * APR_LDAP_SSL: SSL encryption (ldaps://)  * APR_LDAP_STARTTLS: Force STARTTLS on ldap://  * @remark The Novell toolkit is only able to set the SSL mode via this  * function. To work around this limitation, set the SSL mode here if no  * per connection client certificates are present, otherwise set secure  * APR_LDAP_NONE here, then set the per connection client certificates,  * followed by setting the SSL mode via apr_ldap_set_option(). As Novell  * does not support per connection client certificates, this problem is  * worked around while still being compatible with other LDAP toolkits.  * @param pool The pool to use  * @param ldap The LDAP handle  * @param hostname The name of the host to connect to. This can be either a  * DNS name, or an IP address.  * @param portno The port to connect to  * @param secure The security mode to set  * @param result_err The returned result  */
name|APU_DECLARE_LDAP
argument_list|(
argument|int
argument_list|)
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
empty_stmt|;
comment|/**  * APR LDAP info function  *  * This function returns a string describing the LDAP toolkit  * currently in use. The string is placed inside result_err->reason.  * @param pool The pool to use  * @param result_err The returned result  */
name|APU_DECLARE_LDAP
argument_list|(
argument|int
argument_list|)
name|apr_ldap_info
argument_list|(
name|apr_pool_t
operator|*
name|pool
argument_list|,
name|apr_ldap_err_t
operator|*
operator|*
name|result_err
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
comment|/* APR_HAS_LDAP */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_LDAP_URL_H */
end_comment

end_unit

