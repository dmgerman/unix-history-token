begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/**  * The APR LDAP rebind functions provide an implementation of  * a rebind procedure that can be used to allow clients to chase referrals,  * using the same credentials used to log in originally.  *  * Use of this implementation is optional.  *  * @file apr_ldap_rebind.h  * @brief Apache LDAP library  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APU_LDAP_REBIND_H
end_ifndef

begin_define
define|#
directive|define
name|APU_LDAP_REBIND_H
end_define

begin_comment
comment|/**  * @addtogroup APR_Util_LDAP  * @{  **/
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

begin_comment
comment|/*  * Handle the case when LDAP is enabled  */
end_comment

begin_if
if|#
directive|if
name|APR_HAS_LDAP
end_if

begin_comment
comment|/**  * APR LDAP initialize rebind lock  *  * This function creates the lock for controlling access to the xref list..  * @param pool Pool to use when creating the xref_lock.  */
end_comment

begin_macro
name|APU_DECLARE_LDAP
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_expr_stmt
name|apr_ldap_rebind_init
argument_list|(
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * APR LDAP rebind_add function  *  * This function creates a cross reference entry for the specified ldap  * connection. The rebind callback function will look up this ldap   * connection so it can retrieve the bindDN and bindPW for use in any   * binds while referrals are being chased.  *  * This function will add the callback to the LDAP handle passed in.  *  * A cleanup is registered within the pool provided to remove this  * entry when the pool is removed. Alternatively apr_ldap_rebind_remove()  * can be called to explicitly remove the entry at will.  *  * @param pool The pool to use  * @param ld The LDAP connectionhandle  * @param bindDN The bind DN to be used for any binds while chasing   *               referrals on this ldap connection.  * @param bindPW The bind Password to be used for any binds while   *               chasing referrals on this ldap connection.  */
end_comment

begin_macro
name|APU_DECLARE_LDAP
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_expr_stmt
name|apr_ldap_rebind_add
argument_list|(
name|apr_pool_t
operator|*
name|pool
argument_list|,
name|LDAP
operator|*
name|ld
argument_list|,
specifier|const
name|char
operator|*
name|bindDN
argument_list|,
specifier|const
name|char
operator|*
name|bindPW
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * APR LDAP rebind_remove function  *  * This function removes the rebind cross reference entry for the  * specified ldap connection.  *  * If not explicitly removed, this function will be called automatically  * when the pool is cleaned up.  *  * @param ld The LDAP connectionhandle  */
end_comment

begin_macro
name|APU_DECLARE_LDAP
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_expr_stmt
name|apr_ldap_rebind_remove
argument_list|(
name|LDAP
operator|*
name|ld
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/* APU_LDAP_REBIND_H */
end_comment

end_unit

