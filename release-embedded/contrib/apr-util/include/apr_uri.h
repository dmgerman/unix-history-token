begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/*  * apr_uri.h: External Interface of apr_uri.c  */
end_comment

begin_comment
comment|/**  * @file apr_uri.h  * @brief APR-UTIL URI Routines  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_URI_H
end_ifndef

begin_define
define|#
directive|define
name|APR_URI_H
end_define

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apr_network_io.h"
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
comment|/**  * @defgroup APR_Util_URI URI  * @ingroup APR_Util  * @{  */
define|#
directive|define
name|APR_URI_FTP_DEFAULT_PORT
value|21
comment|/**< default FTP port */
define|#
directive|define
name|APR_URI_SSH_DEFAULT_PORT
value|22
comment|/**< default SSH port */
define|#
directive|define
name|APR_URI_TELNET_DEFAULT_PORT
value|23
comment|/**< default telnet port */
define|#
directive|define
name|APR_URI_GOPHER_DEFAULT_PORT
value|70
comment|/**< default Gopher port */
define|#
directive|define
name|APR_URI_HTTP_DEFAULT_PORT
value|80
comment|/**< default HTTP port */
define|#
directive|define
name|APR_URI_POP_DEFAULT_PORT
value|110
comment|/**< default POP port */
define|#
directive|define
name|APR_URI_NNTP_DEFAULT_PORT
value|119
comment|/**< default NNTP port */
define|#
directive|define
name|APR_URI_IMAP_DEFAULT_PORT
value|143
comment|/**< default IMAP port */
define|#
directive|define
name|APR_URI_PROSPERO_DEFAULT_PORT
value|191
comment|/**< default Prospero port */
define|#
directive|define
name|APR_URI_WAIS_DEFAULT_PORT
value|210
comment|/**< default WAIS port */
define|#
directive|define
name|APR_URI_LDAP_DEFAULT_PORT
value|389
comment|/**< default LDAP port */
define|#
directive|define
name|APR_URI_HTTPS_DEFAULT_PORT
value|443
comment|/**< default HTTPS port */
define|#
directive|define
name|APR_URI_RTSP_DEFAULT_PORT
value|554
comment|/**< default RTSP port */
define|#
directive|define
name|APR_URI_SNEWS_DEFAULT_PORT
value|563
comment|/**< default SNEWS port */
define|#
directive|define
name|APR_URI_ACAP_DEFAULT_PORT
value|674
comment|/**< default ACAP port */
define|#
directive|define
name|APR_URI_NFS_DEFAULT_PORT
value|2049
comment|/**< default NFS port */
define|#
directive|define
name|APR_URI_TIP_DEFAULT_PORT
value|3372
comment|/**< default TIP port */
define|#
directive|define
name|APR_URI_SIP_DEFAULT_PORT
value|5060
comment|/**< default SIP port */
comment|/** Flags passed to unparse_uri_components(): */
comment|/** suppress "scheme://user\@site:port" */
define|#
directive|define
name|APR_URI_UNP_OMITSITEPART
value|(1U<<0)
comment|/** Just omit user */
define|#
directive|define
name|APR_URI_UNP_OMITUSER
value|(1U<<1)
comment|/** Just omit password */
define|#
directive|define
name|APR_URI_UNP_OMITPASSWORD
value|(1U<<2)
comment|/** omit "user:password\@" part */
define|#
directive|define
name|APR_URI_UNP_OMITUSERINFO
value|(APR_URI_UNP_OMITUSER | \                                      APR_URI_UNP_OMITPASSWORD)
comment|/** Show plain text password (default: show XXXXXXXX) */
define|#
directive|define
name|APR_URI_UNP_REVEALPASSWORD
value|(1U<<3)
comment|/** Show "scheme://user\@site:port" only */
define|#
directive|define
name|APR_URI_UNP_OMITPATHINFO
value|(1U<<4)
comment|/** Omit the "?queryarg" from the path */
define|#
directive|define
name|APR_URI_UNP_OMITQUERY
value|(1U<<5)
comment|/** @see apr_uri_t */
typedef|typedef
name|struct
name|apr_uri_t
name|apr_uri_t
typedef|;
comment|/**  * A structure to encompass all of the fields in a uri  */
struct|struct
name|apr_uri_t
block|{
comment|/** scheme ("http"/"ftp"/...) */
name|char
modifier|*
name|scheme
decl_stmt|;
comment|/** combined [user[:password]\@]host[:port] */
name|char
modifier|*
name|hostinfo
decl_stmt|;
comment|/** user name, as in http://user:passwd\@host:port/ */
name|char
modifier|*
name|user
decl_stmt|;
comment|/** password, as in http://user:passwd\@host:port/ */
name|char
modifier|*
name|password
decl_stmt|;
comment|/** hostname from URI (or from Host: header) */
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/** port string (integer representation is in "port") */
name|char
modifier|*
name|port_str
decl_stmt|;
comment|/** the request path (or NULL if only scheme://host was given) */
name|char
modifier|*
name|path
decl_stmt|;
comment|/** Everything after a '?' in the path, if present */
name|char
modifier|*
name|query
decl_stmt|;
comment|/** Trailing "#fragment" string, if present */
name|char
modifier|*
name|fragment
decl_stmt|;
comment|/** structure returned from gethostbyname() */
name|struct
name|hostent
modifier|*
name|hostent
decl_stmt|;
comment|/** The port number, numeric, valid only if port_str != NULL */
name|apr_port_t
name|port
decl_stmt|;
comment|/** has the structure been initialized */
name|unsigned
name|is_initialized
range|:
literal|1
decl_stmt|;
comment|/** has the DNS been looked up yet */
name|unsigned
name|dns_looked_up
range|:
literal|1
decl_stmt|;
comment|/** has the dns been resolved yet */
name|unsigned
name|dns_resolved
range|:
literal|1
decl_stmt|;
block|}
struct|;
comment|/* apr_uri.c */
comment|/**  * Return the default port for a given scheme.  The schemes recognized are  * http, ftp, https, gopher, wais, nntp, snews, and prospero  * @param scheme_str The string that contains the current scheme  * @return The default port for this scheme  */
name|APU_DECLARE
argument_list|(
argument|apr_port_t
argument_list|)
name|apr_uri_port_of_scheme
argument_list|(
specifier|const
name|char
operator|*
name|scheme_str
argument_list|)
expr_stmt|;
comment|/**  * Unparse a apr_uri_t structure to an URI string.  Optionally   * suppress the password for security reasons.  * @param p The pool to allocate out of  * @param uptr All of the parts of the uri  * @param flags How to unparse the uri.  One of:  *<PRE>  *    APR_URI_UNP_OMITSITEPART        Suppress "scheme://user\@site:port"   *    APR_URI_UNP_OMITUSER            Just omit user   *    APR_URI_UNP_OMITPASSWORD        Just omit password   *    APR_URI_UNP_OMITUSERINFO        Omit "user:password\@" part  *    APR_URI_UNP_REVEALPASSWORD      Show plain text password (default: show XXXXXXXX)  *    APR_URI_UNP_OMITPATHINFO        Show "scheme://user\@site:port" only   *    APR_URI_UNP_OMITQUERY           Omit "?queryarg" or "#fragment"   *</PRE>  * @return The uri as a string  */
name|APU_DECLARE
argument_list|(
argument|char *
argument_list|)
name|apr_uri_unparse
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const apr_uri_t *uptr
argument_list|,
argument|unsigned flags
argument_list|)
empty_stmt|;
comment|/**  * Parse a given URI, fill in all supplied fields of a apr_uri_t  * structure. This eliminates the necessity of extracting host, port,  * path, query info repeatedly in the modules.  * @param p The pool to allocate out of  * @param uri The uri to parse  * @param uptr The apr_uri_t to fill out  * @return APR_SUCCESS for success or error code  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_uri_parse
argument_list|(
name|apr_pool_t
operator|*
name|p
argument_list|,
specifier|const
name|char
operator|*
name|uri
argument_list|,
name|apr_uri_t
operator|*
name|uptr
argument_list|)
expr_stmt|;
comment|/**  * Special case for CONNECT parsing: it comes with the hostinfo part only  * @param p The pool to allocate out of  * @param hostinfo The hostinfo string to parse  * @param uptr The apr_uri_t to fill out  * @return APR_SUCCESS for success or error code  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_uri_parse_hostinfo
argument_list|(
name|apr_pool_t
operator|*
name|p
argument_list|,
specifier|const
name|char
operator|*
name|hostinfo
argument_list|,
name|apr_uri_t
operator|*
name|uptr
argument_list|)
expr_stmt|;
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
comment|/* APR_URI_H */
end_comment

end_unit

