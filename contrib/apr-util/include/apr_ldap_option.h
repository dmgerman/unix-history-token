begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/**  * @file apr_ldap_option.h  * @brief  APR-UTIL LDAP ldap_*_option() functions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_LDAP_OPTION_H
end_ifndef

begin_define
define|#
directive|define
name|APR_LDAP_OPTION_H
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
comment|/*  * The following defines handle the different TLS certificate  * options available. If these options are missing, APR will try and  * emulate support for this using the deprecated ldap_start_tls_s()  * function.  */
comment|/**  * Set SSL mode to one of APR_LDAP_NONE, APR_LDAP_SSL, APR_LDAP_STARTTLS  * or APR_LDAP_STOPTLS.  */
define|#
directive|define
name|APR_LDAP_OPT_TLS
value|0x6fff
comment|/**  * Set zero or more CA certificates, client certificates or private  * keys globally, or per connection (where supported).  */
define|#
directive|define
name|APR_LDAP_OPT_TLS_CERT
value|0x6ffe
comment|/**  * Set the LDAP library to no verify the server certificate.  This means  * all servers are considered trusted.  */
define|#
directive|define
name|APR_LDAP_OPT_VERIFY_CERT
value|0x6ffd
comment|/**  * Set the LDAP library to indicate if referrals should be chased during  * LDAP searches.  */
define|#
directive|define
name|APR_LDAP_OPT_REFERRALS
value|0x6ffc
comment|/**  * Set the LDAP library to indicate a maximum number of referral hops to  * chase before giving up on the search.  */
define|#
directive|define
name|APR_LDAP_OPT_REFHOPLIMIT
value|0x6ffb
comment|/**  * Structures for the apr_set_option() cases  */
comment|/**  * APR_LDAP_OPT_TLS_CERT  *  * This structure includes possible options to set certificates on  * system initialisation. Different SDKs have different certificate  * requirements, and to achieve this multiple certificates must be  * specified at once passed as an (apr_array_header_t *).  *  * Netscape:  * Needs the CA cert database (cert7.db), the client cert database (key3.db)  * and the security module file (secmod.db) set at the system initialisation  * time. Three types are supported: APR_LDAP_CERT7_DB, APR_LDAP_KEY3_DB and  * APR_LDAP_SECMOD.  *  * To specify a client cert connection, a certificate nickname needs to be  * provided with a type of APR_LDAP_CERT.  * int ldapssl_enable_clientauth( LDAP *ld, char *keynickname,  * char *keypasswd, char *certnickname );  * keynickname is currently not used, and should be set to ""  *  * Novell:  * Needs CA certificates and client certificates set at system initialisation  * time. Three types are supported: APR_LDAP_CA*, APR_LDAP_CERT* and  * APR_LDAP_KEY*.  *  * Certificates cannot be specified per connection.  *  * The functions used are:  * ldapssl_add_trusted_cert(serverTrustedRoot, serverTrustedRootEncoding);  * Clients certs and keys are set at system initialisation time with  * int ldapssl_set_client_cert (  *  void   *cert,  *  int     type  *  void   *password);   * type can be LDAPSSL_CERT_FILETYPE_B64 or LDAPSSL_CERT_FILETYPE_DER  *  ldapssl_set_client_private_key(clientPrivateKey,  *                                 clientPrivateKeyEncoding,  *                                 clientPrivateKeyPassword);  *  * OpenSSL:  * Needs one or more CA certificates to be set at system initialisation time  * with a type of APR_LDAP_CA*.  *  * May have one or more client certificates set per connection with a type of  * APR_LDAP_CERT*, and keys with APR_LDAP_KEY*.  */
comment|/** CA certificate type unknown */
define|#
directive|define
name|APR_LDAP_CA_TYPE_UNKNOWN
value|0
comment|/** binary DER encoded CA certificate */
define|#
directive|define
name|APR_LDAP_CA_TYPE_DER
value|1
comment|/** PEM encoded CA certificate */
define|#
directive|define
name|APR_LDAP_CA_TYPE_BASE64
value|2
comment|/** Netscape/Mozilla cert7.db CA certificate database */
define|#
directive|define
name|APR_LDAP_CA_TYPE_CERT7_DB
value|3
comment|/** Netscape/Mozilla secmod file */
define|#
directive|define
name|APR_LDAP_CA_TYPE_SECMOD
value|4
comment|/** Client certificate type unknown */
define|#
directive|define
name|APR_LDAP_CERT_TYPE_UNKNOWN
value|5
comment|/** binary DER encoded client certificate */
define|#
directive|define
name|APR_LDAP_CERT_TYPE_DER
value|6
comment|/** PEM encoded client certificate */
define|#
directive|define
name|APR_LDAP_CERT_TYPE_BASE64
value|7
comment|/** Netscape/Mozilla key3.db client certificate database */
define|#
directive|define
name|APR_LDAP_CERT_TYPE_KEY3_DB
value|8
comment|/** Netscape/Mozilla client certificate nickname */
define|#
directive|define
name|APR_LDAP_CERT_TYPE_NICKNAME
value|9
comment|/** Private key type unknown */
define|#
directive|define
name|APR_LDAP_KEY_TYPE_UNKNOWN
value|10
comment|/** binary DER encoded private key */
define|#
directive|define
name|APR_LDAP_KEY_TYPE_DER
value|11
comment|/** PEM encoded private key */
define|#
directive|define
name|APR_LDAP_KEY_TYPE_BASE64
value|12
comment|/** PKCS#12 encoded client certificate */
define|#
directive|define
name|APR_LDAP_CERT_TYPE_PFX
value|13
comment|/** PKCS#12 encoded private key */
define|#
directive|define
name|APR_LDAP_KEY_TYPE_PFX
value|14
comment|/** Openldap directory full of base64-encoded cert   * authorities with hashes in corresponding .0 directory  */
define|#
directive|define
name|APR_LDAP_CA_TYPE_CACERTDIR_BASE64
value|15
comment|/**  * Certificate structure.  *  * This structure is used to store certificate details. An array of  * these structures is passed to apr_ldap_set_option() to set CA  * and client certificates.  * @param type Type of certificate APR_LDAP_*_TYPE_*  * @param path Path, file or nickname of the certificate  * @param password Optional password, can be NULL  */
typedef|typedef
name|struct
name|apr_ldap_opt_tls_cert_t
name|apr_ldap_opt_tls_cert_t
typedef|;
struct|struct
name|apr_ldap_opt_tls_cert_t
block|{
name|int
name|type
decl_stmt|;
specifier|const
name|char
modifier|*
name|path
decl_stmt|;
specifier|const
name|char
modifier|*
name|password
decl_stmt|;
block|}
struct|;
comment|/**  * APR_LDAP_OPT_TLS  *  * This sets the SSL level on the LDAP handle.  *  * Netscape/Mozilla:  * Supports SSL, but not STARTTLS  * SSL is enabled by calling ldapssl_install_routines().  *  * Novell:  * Supports SSL and STARTTLS.  * SSL is enabled by calling ldapssl_install_routines(). Note that calling  * other ldap functions before ldapssl_install_routines() may cause this  * function to fail.  * STARTTLS is enabled by calling ldapssl_start_tls_s() after calling  * ldapssl_install_routines() (check this).  *  * OpenLDAP:  * Supports SSL and supports STARTTLS, but none of this is documented:  * http://www.openldap.org/lists/openldap-software/200409/msg00618.html  * Documentation for both SSL support and STARTTLS has been deleted from  * the OpenLDAP documentation and website.  */
comment|/** No encryption */
define|#
directive|define
name|APR_LDAP_NONE
value|0
comment|/** SSL encryption (ldaps://) */
define|#
directive|define
name|APR_LDAP_SSL
value|1
comment|/** TLS encryption (STARTTLS) */
define|#
directive|define
name|APR_LDAP_STARTTLS
value|2
comment|/** end TLS encryption (STOPTLS) */
define|#
directive|define
name|APR_LDAP_STOPTLS
value|3
comment|/**  * APR LDAP get option function  *  * This function gets option values from a given LDAP session if  * one was specified. It maps to the native ldap_get_option() function.  * @param pool The pool to use  * @param ldap The LDAP handle  * @param option The LDAP_OPT_* option to return  * @param outvalue The value returned (if any)  * @param result_err The apr_ldap_err_t structure contained detailed results  *        of the operation.  */
name|APU_DECLARE_LDAP
argument_list|(
argument|int
argument_list|)
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
empty_stmt|;
comment|/**  * APR LDAP set option function  *   * This function sets option values to a given LDAP session if  * one was specified. It maps to the native ldap_set_option() function.  *   * Where an option is not supported by an LDAP toolkit, this function  * will try and apply legacy functions to achieve the same effect,  * depending on the platform.  * @param pool The pool to use  * @param ldap The LDAP handle  * @param option The LDAP_OPT_* option to set  * @param invalue The value to set  * @param result_err The apr_ldap_err_t structure contained detailed results  *        of the operation.  */
name|APU_DECLARE_LDAP
argument_list|(
argument|int
argument_list|)
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
empty_stmt|;
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
comment|/* APR_LDAP_OPTION_H */
end_comment

end_unit

