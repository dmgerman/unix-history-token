begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/*  * apr_ldap.h is generated from apr_ldap.h.in by configure -- do not edit apr_ldap.h  */
end_comment

begin_comment
comment|/**  * @file apr_ldap.h  * @brief  APR-UTIL LDAP   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APU_LDAP_H
end_ifndef

begin_define
define|#
directive|define
name|APU_LDAP_H
end_define

begin_comment
comment|/**  * @defgroup APR_Util_LDAP LDAP  * @ingroup APR_Util  * @{  */
end_comment

begin_comment
comment|/* this will be defined if LDAP support was compiled into apr-util */
end_comment

begin_define
define|#
directive|define
name|APR_HAS_LDAP
value|0
end_define

begin_comment
comment|/* identify the LDAP toolkit used */
end_comment

begin_define
define|#
directive|define
name|APR_HAS_NETSCAPE_LDAPSDK
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAS_SOLARIS_LDAPSDK
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAS_NOVELL_LDAPSDK
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAS_MOZILLA_LDAPSDK
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAS_OPENLDAP_LDAPSDK
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAS_MICROSOFT_LDAPSDK
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAS_TIVOLI_LDAPSDK
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAS_ZOS_LDAPSDK
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAS_OTHER_LDAPSDK
value|0
end_define

begin_comment
comment|/*  * Handle the case when LDAP is enabled  */
end_comment

begin_if
if|#
directive|if
name|APR_HAS_LDAP
end_if

begin_comment
comment|/*  * The following #defines are DEPRECATED and should not be used for  * anything. They remain to maintain binary compatibility.  * The original code defined the OPENLDAP SDK as present regardless  * of what really was there, which was way bogus. In addition, the  * apr_ldap_url_parse*() functions have been rewritten specifically for  * APR, so the APR_HAS_LDAP_URL_PARSE macro is forced to zero.  */
end_comment

begin_if
if|#
directive|if
name|APR_HAS_TIVOLI_LDAPSDK
end_if

begin_define
define|#
directive|define
name|APR_HAS_LDAP_SSL
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|APR_HAS_LDAP_SSL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|APR_HAS_LDAP_URL_PARSE
value|0
end_define

begin_if
if|#
directive|if
name|APR_HAS_OPENLDAP_LDAPSDK
operator|&&
operator|!
name|defined
argument_list|(
name|LDAP_DEPRECATED
argument_list|)
end_if

begin_comment
comment|/* Ensure that the "deprecated" interfaces are still exposed  * with OpenLDAP>= 2.3; these were exposed by default in earlier  * releases. */
end_comment

begin_define
define|#
directive|define
name|LDAP_DEPRECATED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Include the standard LDAP header files.  */
end_comment

begin_comment
comment|/*  * Detected standard functions  */
end_comment

begin_define
define|#
directive|define
name|APR_HAS_LDAPSSL_CLIENT_INIT
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAS_LDAPSSL_CLIENT_DEINIT
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAS_LDAPSSL_ADD_TRUSTED_CERT
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAS_LDAP_START_TLS_S
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAS_LDAP_SSLINIT
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAS_LDAPSSL_INIT
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAS_LDAPSSL_INSTALL_ROUTINES
value|0
end_define

begin_comment
comment|/*  * Make sure the secure LDAP port is defined  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDAPS_PORT
end_ifndef

begin_define
define|#
directive|define
name|LDAPS_PORT
value|636
end_define

begin_comment
comment|/* ldaps:/// default LDAP over TLS port */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * For ldap function calls that input a size limit on the number of returned elements  * Some SDKs do not have the define for LDAP_DEFAULT_LIMIT (-1) or LDAP_NO_LIMIT (0)  * LDAP_DEFAULT_LIMIT is preferred as it allows inheritance from whatever the SDK  * or process is configured for.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LDAP_DEFAULT_LIMIT
end_ifdef

begin_define
define|#
directive|define
name|APR_LDAP_SIZELIMIT
value|LDAP_DEFAULT_LIMIT
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|LDAP_NO_LIMIT
end_ifdef

begin_define
define|#
directive|define
name|APR_LDAP_SIZELIMIT
value|LDAP_NO_LIMIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|APR_LDAP_SIZELIMIT
end_ifndef

begin_define
define|#
directive|define
name|APR_LDAP_SIZELIMIT
value|0
end_define

begin_comment
comment|/* equivalent to LDAP_NO_LIMIT, and what goes on the wire */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * z/OS is missing some defines  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDAP_VERSION_MAX
end_ifndef

begin_define
define|#
directive|define
name|LDAP_VERSION_MAX
value|LDAP_VERSION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAS_ZOS_LDAPSDK
end_if

begin_define
define|#
directive|define
name|LDAP_VENDOR_NAME
value|"IBM z/OS"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Note: Macros defining const casting has been removed in APR v1.0,  * pending real support for LDAP v2.0 toolkits.  *  * In the mean time, please use an LDAP v3.0 toolkit.  */
end_comment

begin_if
if|#
directive|if
name|LDAP_VERSION_MAX
operator|<=
literal|2
end_if

begin_error
error|#
directive|error
error|Support for LDAP v2.0 toolkits has been removed from apr-util. Please use an LDAP v3.0 toolkit.
end_error

begin_endif
endif|#
directive|endif
end_endif

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
comment|/**  * This structure allows the C LDAP API error codes to be returned  * along with plain text error messages that explain to us mere mortals  * what really happened.  */
typedef|typedef
struct|struct
name|apr_ldap_err_t
block|{
specifier|const
name|char
modifier|*
name|reason
decl_stmt|;
specifier|const
name|char
modifier|*
name|msg
decl_stmt|;
name|int
name|rc
decl_stmt|;
block|}
name|apr_ldap_err_t
typedef|;
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
comment|/* The MS SDK returns LDAP_UNAVAILABLE when the backend has closed the connection  * between LDAP calls. Protect with APR_HAS_MICROSOFT_LDAPSDK in case someone   * manually chooses another SDK on Windows   */
end_comment

begin_if
if|#
directive|if
name|APR_HAS_MICROSOFT_LDAPSDK
end_if

begin_define
define|#
directive|define
name|APR_LDAP_IS_SERVER_DOWN
parameter_list|(
name|s
parameter_list|)
value|((s) == LDAP_SERVER_DOWN \                                     || (s) == LDAP_UNAVAILABLE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|APR_LDAP_IS_SERVER_DOWN
parameter_list|(
name|s
parameter_list|)
value|((s) == LDAP_SERVER_DOWN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These symbols are not actually exported in a DSO build, but mapped into  * a private exported function array for apr_ldap_stub to bind dynamically.  * Rename them appropriately to protect the global namespace.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|APU_DSO_LDAP_BUILD
end_ifdef

begin_define
define|#
directive|define
name|apr_ldap_info
value|apr__ldap_info
end_define

begin_define
define|#
directive|define
name|apr_ldap_init
value|apr__ldap_init
end_define

begin_define
define|#
directive|define
name|apr_ldap_ssl_init
value|apr__ldap_ssl_init
end_define

begin_define
define|#
directive|define
name|apr_ldap_ssl_deinit
value|apr__ldap_ssl_deinit
end_define

begin_define
define|#
directive|define
name|apr_ldap_get_option
value|apr__ldap_get_option
end_define

begin_define
define|#
directive|define
name|apr_ldap_set_option
value|apr__ldap_set_option
end_define

begin_define
define|#
directive|define
name|apr_ldap_rebind_init
value|apr__ldap_rebind_init
end_define

begin_define
define|#
directive|define
name|apr_ldap_rebind_add
value|apr__ldap_rebind_add
end_define

begin_define
define|#
directive|define
name|apr_ldap_rebind_remove
value|apr__ldap_rebind_remove
end_define

begin_define
define|#
directive|define
name|APU_DECLARE_LDAP
parameter_list|(
name|type
parameter_list|)
value|type
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|APU_DECLARE_LDAP
parameter_list|(
name|type
parameter_list|)
value|APU_DECLARE(type)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"apr_ldap_url.h"
end_include

begin_include
include|#
directive|include
file|"apr_ldap_init.h"
end_include

begin_include
include|#
directive|include
file|"apr_ldap_option.h"
end_include

begin_include
include|#
directive|include
file|"apr_ldap_rebind.h"
end_include

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
comment|/* APU_LDAP_H */
end_comment

end_unit

