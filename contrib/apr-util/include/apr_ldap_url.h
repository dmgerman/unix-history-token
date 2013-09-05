begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/**  * @file apr_ldap_url.h  * @brief  APR-UTIL LDAP ldap_init() functions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_LDAP_URL_H
end_ifndef

begin_define
define|#
directive|define
name|APR_LDAP_URL_H
end_define

begin_comment
comment|/**  * @addtogroup APR_Util_LDAP  * @{  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
end_if

begin_include
include|#
directive|include
file|"apr_ldap.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAS_LDAP
end_if

begin_include
include|#
directive|include
file|"apu.h"
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
comment|/** Structure to access an exploded LDAP URL */
typedef|typedef
struct|struct
name|apr_ldap_url_desc_t
block|{
name|struct
name|apr_ldap_url_desc_t
modifier|*
name|lud_next
decl_stmt|;
name|char
modifier|*
name|lud_scheme
decl_stmt|;
name|char
modifier|*
name|lud_host
decl_stmt|;
name|int
name|lud_port
decl_stmt|;
name|char
modifier|*
name|lud_dn
decl_stmt|;
name|char
modifier|*
modifier|*
name|lud_attrs
decl_stmt|;
name|int
name|lud_scope
decl_stmt|;
name|char
modifier|*
name|lud_filter
decl_stmt|;
name|char
modifier|*
modifier|*
name|lud_exts
decl_stmt|;
name|int
name|lud_crit_exts
decl_stmt|;
block|}
name|apr_ldap_url_desc_t
typedef|;
ifndef|#
directive|ifndef
name|APR_LDAP_URL_SUCCESS
define|#
directive|define
name|APR_LDAP_URL_SUCCESS
value|0x00
comment|/* Success */
define|#
directive|define
name|APR_LDAP_URL_ERR_MEM
value|0x01
comment|/* can't allocate memory space */
define|#
directive|define
name|APR_LDAP_URL_ERR_PARAM
value|0x02
comment|/* parameter is bad */
define|#
directive|define
name|APR_LDAP_URL_ERR_BADSCHEME
value|0x03
comment|/* URL doesn't begin with "ldap[si]://" */
define|#
directive|define
name|APR_LDAP_URL_ERR_BADENCLOSURE
value|0x04
comment|/* URL is missing trailing ">" */
define|#
directive|define
name|APR_LDAP_URL_ERR_BADURL
value|0x05
comment|/* URL is bad */
define|#
directive|define
name|APR_LDAP_URL_ERR_BADHOST
value|0x06
comment|/* host port is bad */
define|#
directive|define
name|APR_LDAP_URL_ERR_BADATTRS
value|0x07
comment|/* bad (or missing) attributes */
define|#
directive|define
name|APR_LDAP_URL_ERR_BADSCOPE
value|0x08
comment|/* scope string is invalid (or missing) */
define|#
directive|define
name|APR_LDAP_URL_ERR_BADFILTER
value|0x09
comment|/* bad or missing filter */
define|#
directive|define
name|APR_LDAP_URL_ERR_BADEXTS
value|0x0a
comment|/* bad or missing extensions */
endif|#
directive|endif
comment|/**  * Is this URL an ldap url? ldap://  * @param url The url to test  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_ldap_is_ldap_url
argument_list|(
specifier|const
name|char
operator|*
name|url
argument_list|)
expr_stmt|;
comment|/**  * Is this URL an SSL ldap url? ldaps://  * @param url The url to test  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_ldap_is_ldaps_url
argument_list|(
specifier|const
name|char
operator|*
name|url
argument_list|)
expr_stmt|;
comment|/**  * Is this URL an ldap socket url? ldapi://  * @param url The url to test  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_ldap_is_ldapi_url
argument_list|(
specifier|const
name|char
operator|*
name|url
argument_list|)
expr_stmt|;
comment|/**  * Parse an LDAP URL.  * @param pool The pool to use  * @param url_in The URL to parse  * @param ludpp The structure to return the exploded URL  * @param result_err The result structure of the operation  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_ldap_url_parse_ext
argument_list|(
name|apr_pool_t
operator|*
name|pool
argument_list|,
specifier|const
name|char
operator|*
name|url_in
argument_list|,
name|apr_ldap_url_desc_t
operator|*
operator|*
name|ludpp
argument_list|,
name|apr_ldap_err_t
operator|*
operator|*
name|result_err
argument_list|)
expr_stmt|;
comment|/**  * Parse an LDAP URL.  * @param pool The pool to use  * @param url_in The URL to parse  * @param ludpp The structure to return the exploded URL  * @param result_err The result structure of the operation  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_ldap_url_parse
argument_list|(
name|apr_pool_t
operator|*
name|pool
argument_list|,
specifier|const
name|char
operator|*
name|url_in
argument_list|,
name|apr_ldap_url_desc_t
operator|*
operator|*
name|ludpp
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

