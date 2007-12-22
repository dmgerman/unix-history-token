begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pcy_lib.c */
end_comment

begin_comment
comment|/* Written by Dr Stephen N Henson (shenson@bigfoot.com) for the OpenSSL  * project 2004.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2004 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    licensing@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_include
include|#
directive|include
file|"cryptlib.h"
end_include

begin_include
include|#
directive|include
file|<openssl/x509.h>
end_include

begin_include
include|#
directive|include
file|<openssl/x509v3.h>
end_include

begin_include
include|#
directive|include
file|"pcy_int.h"
end_include

begin_comment
comment|/* accessor functions */
end_comment

begin_comment
comment|/* X509_POLICY_TREE stuff */
end_comment

begin_function
name|int
name|X509_policy_tree_level_count
parameter_list|(
specifier|const
name|X509_POLICY_TREE
modifier|*
name|tree
parameter_list|)
block|{
if|if
condition|(
operator|!
name|tree
condition|)
return|return
literal|0
return|;
return|return
name|tree
operator|->
name|nlevel
return|;
block|}
end_function

begin_function
name|X509_POLICY_LEVEL
modifier|*
name|X509_policy_tree_get0_level
parameter_list|(
specifier|const
name|X509_POLICY_TREE
modifier|*
name|tree
parameter_list|,
name|int
name|i
parameter_list|)
block|{
if|if
condition|(
operator|!
name|tree
operator|||
operator|(
name|i
operator|<
literal|0
operator|)
operator|||
operator|(
name|i
operator|>=
name|tree
operator|->
name|nlevel
operator|)
condition|)
return|return
name|NULL
return|;
return|return
name|tree
operator|->
name|levels
operator|+
name|i
return|;
block|}
end_function

begin_expr_stmt
name|STACK_OF
argument_list|(
name|X509_POLICY_NODE
argument_list|)
operator|*
name|X509_policy_tree_get0_policies
argument_list|(
argument|const X509_POLICY_TREE *tree
argument_list|)
block|{
if|if
condition|(
operator|!
name|tree
condition|)
return|return
name|NULL
return|;
end_expr_stmt

begin_return
return|return
name|tree
operator|->
name|auth_policies
return|;
end_return

begin_expr_stmt
unit|}  STACK_OF
operator|(
name|X509_POLICY_NODE
operator|)
operator|*
name|X509_policy_tree_get0_user_policies
argument_list|(
argument|const X509_POLICY_TREE *tree
argument_list|)
block|{
if|if
condition|(
operator|!
name|tree
condition|)
return|return
name|NULL
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|tree
operator|->
name|flags
operator|&
name|POLICY_FLAG_ANY_POLICY
condition|)
return|return
name|tree
operator|->
name|auth_policies
return|;
else|else
return|return
name|tree
operator|->
name|user_policies
return|;
end_if

begin_comment
unit|}
comment|/* X509_POLICY_LEVEL stuff */
end_comment

begin_macro
unit|int
name|X509_policy_level_node_count
argument_list|(
argument|X509_POLICY_LEVEL *level
argument_list|)
end_macro

begin_block
block|{
name|int
name|n
decl_stmt|;
if|if
condition|(
operator|!
name|level
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|level
operator|->
name|anyPolicy
condition|)
name|n
operator|=
literal|1
expr_stmt|;
else|else
name|n
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|level
operator|->
name|nodes
condition|)
name|n
operator|+=
name|sk_X509_POLICY_NODE_num
argument_list|(
name|level
operator|->
name|nodes
argument_list|)
expr_stmt|;
return|return
name|n
return|;
block|}
end_block

begin_function
name|X509_POLICY_NODE
modifier|*
name|X509_policy_level_get0_node
parameter_list|(
name|X509_POLICY_LEVEL
modifier|*
name|level
parameter_list|,
name|int
name|i
parameter_list|)
block|{
if|if
condition|(
operator|!
name|level
condition|)
return|return
name|NULL
return|;
if|if
condition|(
name|level
operator|->
name|anyPolicy
condition|)
block|{
if|if
condition|(
name|i
operator|==
literal|0
condition|)
return|return
name|level
operator|->
name|anyPolicy
return|;
name|i
operator|--
expr_stmt|;
block|}
return|return
name|sk_X509_POLICY_NODE_value
argument_list|(
name|level
operator|->
name|nodes
argument_list|,
name|i
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* X509_POLICY_NODE stuff */
end_comment

begin_function
specifier|const
name|ASN1_OBJECT
modifier|*
name|X509_policy_node_get0_policy
parameter_list|(
specifier|const
name|X509_POLICY_NODE
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
operator|!
name|node
condition|)
return|return
name|NULL
return|;
return|return
name|node
operator|->
name|data
operator|->
name|valid_policy
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|int X509_policy_node_get_critical(const X509_POLICY_NODE *node) 	{ 	if (node_critical(node)) 		return 1; 	return 0; 	}
endif|#
directive|endif
end_endif

begin_expr_stmt
name|STACK_OF
argument_list|(
name|POLICYQUALINFO
argument_list|)
operator|*
name|X509_policy_node_get0_qualifiers
argument_list|(
argument|const X509_POLICY_NODE *node
argument_list|)
block|{
if|if
condition|(
operator|!
name|node
condition|)
return|return
name|NULL
return|;
end_expr_stmt

begin_return
return|return
name|node
operator|->
name|data
operator|->
name|qualifier_set
return|;
end_return

begin_function
unit|}  const
name|X509_POLICY_NODE
modifier|*
name|X509_policy_node_get0_parent
parameter_list|(
specifier|const
name|X509_POLICY_NODE
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
operator|!
name|node
condition|)
return|return
name|NULL
return|;
return|return
name|node
operator|->
name|parent
return|;
block|}
end_function

end_unit

