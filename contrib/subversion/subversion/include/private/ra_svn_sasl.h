begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ra_svn_sasl.h :  SASL-related declarations shared between the  * ra_svn and svnserve module  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RA_SVN_SASL_H
end_ifndef

begin_define
define|#
directive|define
name|RA_SVN_SASL_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_comment
comment|/* This prevents sasl.h from redefining iovec, which is always defined by APR    on win32. */
end_comment

begin_define
define|#
directive|define
name|STRUCT_IOVEC_DEFINED
end_define

begin_include
include|#
directive|include
file|<sasl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sasl/sasl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<apr_errno.h>
end_include

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|"svn_error.h"
end_include

begin_include
include|#
directive|include
file|"svn_ra_svn.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_atomic.h"
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
comment|/** The application and service name used for sasl_client_new,  * sasl_server_init, and sasl_server_new. */
define|#
directive|define
name|SVN_RA_SVN_SASL_NAME
value|"svn"
specifier|extern
specifier|volatile
name|svn_atomic_t
name|svn_ra_svn__sasl_status
decl_stmt|;
comment|/* Initialize secprops with default values. */
name|void
name|svn_ra_svn__default_secprops
parameter_list|(
name|sasl_security_properties_t
modifier|*
name|secprops
parameter_list|)
function_decl|;
comment|/* This function is called by the client and the server before    calling sasl_{client, server}_init, pool is used for allocations. */
name|svn_error_t
modifier|*
name|svn_ra_svn__sasl_common_init
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Sets local_addrport and remote_addrport to a string containing the    remote and local IP address and port, formatted like this: a.b.c.d;port. */
name|svn_error_t
modifier|*
name|svn_ra_svn__get_addresses
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|local_addrport
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|remote_addrport
parameter_list|,
name|svn_ra_svn_conn_t
modifier|*
name|conn
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* If a security layer was negotiated during the authentication exchange,    create an encrypted stream for conn. */
name|svn_error_t
modifier|*
name|svn_ra_svn__enable_sasl_encryption
parameter_list|(
name|svn_ra_svn_conn_t
modifier|*
name|conn
parameter_list|,
name|sasl_conn_t
modifier|*
name|sasl_ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
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
comment|/* RA_SVN_SASL_H */
end_comment

end_unit

