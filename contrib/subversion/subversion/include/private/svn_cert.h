begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_cert.h  * @brief Implementation of certificate validation functions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_CERT_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_CERT_H
end_define

begin_include
include|#
directive|include
file|<apr.h>
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
end_include

begin_include
include|#
directive|include
file|"svn_string.h"
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
comment|/* Return TRUE iff @a pattern matches @a hostname as defined  * by the matching rules of RFC 6125.  In the context of RFC  * 6125 the pattern is the domain name portion of the presented  * identifier (which comes from the Common Name or a DNSName  * portion of the subjectAltName of an X.509 certificate) and  * the hostname is the source domain (i.e. the host portion  * of the URI the user entered).  *  * @note With respect to wildcards we only support matching  * wildcards in the left-most label and as the only character  * in the left-most label (i.e. we support RFC 6125 Â§ 6.4.3  * Rule 1 and 2 but not the optional Rule 3).  This may change  * in the future.  *  * @note Subversion does not at current support internationalized  * domain names.  Both values are presumed to be in NR-LDH label  * or A-label form (see RFC 5890 for the definition).  *  * @since New in 1.9.  */
name|svn_boolean_t
name|svn_cert__match_dns_identity
parameter_list|(
name|svn_string_t
modifier|*
name|pattern
parameter_list|,
name|svn_string_t
modifier|*
name|hostname
parameter_list|)
function_decl|;
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
comment|/* SVN_CERT_H */
end_comment

end_unit

