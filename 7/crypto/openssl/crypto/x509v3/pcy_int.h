begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pcy_int.h */
end_comment

begin_comment
comment|/* Written by Dr Stephen N Henson (shenson@bigfoot.com) for the OpenSSL  * project 2004.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2004 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    licensing@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_macro
name|DECLARE_STACK_OF
argument_list|(
argument|X509_POLICY_DATA
argument_list|)
end_macro

begin_macro
name|DECLARE_STACK_OF
argument_list|(
argument|X509_POLICY_REF
argument_list|)
end_macro

begin_macro
name|DECLARE_STACK_OF
argument_list|(
argument|X509_POLICY_NODE
argument_list|)
end_macro

begin_typedef
typedef|typedef
name|struct
name|X509_POLICY_DATA_st
name|X509_POLICY_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|X509_POLICY_REF_st
name|X509_POLICY_REF
typedef|;
end_typedef

begin_comment
comment|/* Internal structures */
end_comment

begin_comment
comment|/* This structure and the field names correspond to the Policy 'node' of  * RFC3280. NB this structure contains no pointers to parent or child  * data: X509_POLICY_NODE contains that. This means that the main policy data  * can be kept static and cached with the certificate.  */
end_comment

begin_struct
struct|struct
name|X509_POLICY_DATA_st
block|{
name|unsigned
name|int
name|flags
decl_stmt|;
comment|/* Policy OID and qualifiers for this data */
name|ASN1_OBJECT
modifier|*
name|valid_policy
decl_stmt|;
name|STACK_OF
argument_list|(
name|POLICYQUALINFO
argument_list|)
operator|*
name|qualifier_set
expr_stmt|;
name|STACK_OF
argument_list|(
name|ASN1_OBJECT
argument_list|)
operator|*
name|expected_policy_set
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* X509_POLICY_DATA flags values */
end_comment

begin_comment
comment|/* This flag indicates the structure has been mapped using a policy mapping  * extension. If policy mapping is not active its references get deleted.   */
end_comment

begin_define
define|#
directive|define
name|POLICY_DATA_FLAG_MAPPED
value|0x1
end_define

begin_comment
comment|/* This flag indicates the data doesn't correspond to a policy in Certificate  * Policies: it has been mapped to any policy.  */
end_comment

begin_define
define|#
directive|define
name|POLICY_DATA_FLAG_MAPPED_ANY
value|0x2
end_define

begin_comment
comment|/* AND with flags to see if any mapping has occurred */
end_comment

begin_define
define|#
directive|define
name|POLICY_DATA_FLAG_MAP_MASK
value|0x3
end_define

begin_comment
comment|/* qualifiers are shared and shouldn't be freed */
end_comment

begin_define
define|#
directive|define
name|POLICY_DATA_FLAG_SHARED_QUALIFIERS
value|0x4
end_define

begin_comment
comment|/* Parent node is an extra node and should be freed */
end_comment

begin_define
define|#
directive|define
name|POLICY_DATA_FLAG_EXTRA_NODE
value|0x8
end_define

begin_comment
comment|/* Corresponding CertificatePolicies is critical */
end_comment

begin_define
define|#
directive|define
name|POLICY_DATA_FLAG_CRITICAL
value|0x10
end_define

begin_comment
comment|/* This structure is an entry from a table of mapped policies which  * cross reference the policy it refers to.  */
end_comment

begin_struct
struct|struct
name|X509_POLICY_REF_st
block|{
name|ASN1_OBJECT
modifier|*
name|subjectDomainPolicy
decl_stmt|;
specifier|const
name|X509_POLICY_DATA
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure is cached with a certificate */
end_comment

begin_struct
struct|struct
name|X509_POLICY_CACHE_st
block|{
comment|/* anyPolicy data or NULL if no anyPolicy */
name|X509_POLICY_DATA
modifier|*
name|anyPolicy
decl_stmt|;
comment|/* other policy data */
name|STACK_OF
argument_list|(
name|X509_POLICY_DATA
argument_list|)
operator|*
name|data
expr_stmt|;
comment|/* If policyMappings extension present a table of mapped policies */
name|STACK_OF
argument_list|(
name|X509_POLICY_REF
argument_list|)
operator|*
name|maps
expr_stmt|;
comment|/* If InhibitAnyPolicy present this is its value or -1 if absent. */
name|long
name|any_skip
decl_stmt|;
comment|/* If policyConstraints and requireExplicitPolicy present this is its 	 * value or -1 if absent. 	 */
name|long
name|explicit_skip
decl_stmt|;
comment|/* If policyConstraints and policyMapping present this is its 	 * value or -1 if absent.          */
name|long
name|map_skip
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*#define POLICY_CACHE_FLAG_CRITICAL		POLICY_DATA_FLAG_CRITICAL*/
end_comment

begin_comment
comment|/* This structure represents the relationship between nodes */
end_comment

begin_struct
struct|struct
name|X509_POLICY_NODE_st
block|{
comment|/* node data this refers to */
specifier|const
name|X509_POLICY_DATA
modifier|*
name|data
decl_stmt|;
comment|/* Parent node */
name|X509_POLICY_NODE
modifier|*
name|parent
decl_stmt|;
comment|/* Number of child nodes */
name|int
name|nchild
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|X509_POLICY_LEVEL_st
block|{
comment|/* Cert for this level */
name|X509
modifier|*
name|cert
decl_stmt|;
comment|/* nodes at this level */
name|STACK_OF
argument_list|(
name|X509_POLICY_NODE
argument_list|)
operator|*
name|nodes
expr_stmt|;
comment|/* anyPolicy node */
name|X509_POLICY_NODE
modifier|*
name|anyPolicy
decl_stmt|;
comment|/* Extra data */
comment|/*STACK_OF(X509_POLICY_DATA) *extra_data;*/
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|X509_POLICY_TREE_st
block|{
comment|/* This is the tree 'level' data */
name|X509_POLICY_LEVEL
modifier|*
name|levels
decl_stmt|;
name|int
name|nlevel
decl_stmt|;
comment|/* Extra policy data when additional nodes (not from the certificate) 	 * are required. 	 */
name|STACK_OF
argument_list|(
name|X509_POLICY_DATA
argument_list|)
operator|*
name|extra_data
expr_stmt|;
comment|/* This is the authority constained policy set */
name|STACK_OF
argument_list|(
name|X509_POLICY_NODE
argument_list|)
operator|*
name|auth_policies
expr_stmt|;
name|STACK_OF
argument_list|(
name|X509_POLICY_NODE
argument_list|)
operator|*
name|user_policies
expr_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Set if anyPolicy present in user policies */
end_comment

begin_define
define|#
directive|define
name|POLICY_FLAG_ANY_POLICY
value|0x2
end_define

begin_comment
comment|/* Useful macros */
end_comment

begin_define
define|#
directive|define
name|node_data_critical
parameter_list|(
name|data
parameter_list|)
value|(data->flags& POLICY_DATA_FLAG_CRITICAL)
end_define

begin_define
define|#
directive|define
name|node_critical
parameter_list|(
name|node
parameter_list|)
value|node_data_critical(node->data)
end_define

begin_comment
comment|/* Internal functions */
end_comment

begin_function_decl
name|X509_POLICY_DATA
modifier|*
name|policy_data_new
parameter_list|(
name|POLICYINFO
modifier|*
name|policy
parameter_list|,
name|ASN1_OBJECT
modifier|*
name|id
parameter_list|,
name|int
name|crit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|policy_data_free
parameter_list|(
name|X509_POLICY_DATA
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|X509_POLICY_DATA
modifier|*
name|policy_cache_find_data
parameter_list|(
specifier|const
name|X509_POLICY_CACHE
modifier|*
name|cache
parameter_list|,
specifier|const
name|ASN1_OBJECT
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|policy_cache_set_mapping
parameter_list|(
name|X509
modifier|*
name|x
parameter_list|,
name|POLICY_MAPPINGS
modifier|*
name|maps
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|STACK_OF
argument_list|(
name|X509_POLICY_NODE
argument_list|)
operator|*
name|policy_node_cmp_new
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|policy_cache_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|policy_cache_free
parameter_list|(
name|X509_POLICY_CACHE
modifier|*
name|cache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|X509_POLICY_NODE
modifier|*
name|level_find_node
parameter_list|(
specifier|const
name|X509_POLICY_LEVEL
modifier|*
name|level
parameter_list|,
specifier|const
name|ASN1_OBJECT
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|X509_POLICY_NODE
modifier|*
name|tree_find_sk
argument_list|(
name|STACK_OF
argument_list|(
name|X509_POLICY_NODE
argument_list|)
operator|*
name|sk
argument_list|,
specifier|const
name|ASN1_OBJECT
operator|*
name|id
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|X509_POLICY_NODE
modifier|*
name|level_add_node
parameter_list|(
name|X509_POLICY_LEVEL
modifier|*
name|level
parameter_list|,
name|X509_POLICY_DATA
modifier|*
name|data
parameter_list|,
name|X509_POLICY_NODE
modifier|*
name|parent
parameter_list|,
name|X509_POLICY_TREE
modifier|*
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|policy_node_free
parameter_list|(
name|X509_POLICY_NODE
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|X509_POLICY_CACHE
modifier|*
name|policy_cache_set
parameter_list|(
name|X509
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

end_unit

