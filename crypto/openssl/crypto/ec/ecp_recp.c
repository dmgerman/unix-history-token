begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/ec/ecp_recp.c */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1998-2001 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_include
include|#
directive|include
file|"ec_lcl.h"
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|const EC_METHOD *EC_GFp_recp_method(void) 	{ 	static const EC_METHOD ret = { 		ec_GFp_recp_group_init, 		ec_GFp_recp_group_finish, 		ec_GFp_recp_group_clear_finish, 		ec_GFp_recp_group_copy, 		ec_GFp_recp_group_set_curve_GFp, 		ec_GFp_simple_group_get_curve_GFp, 		ec_GFp_simple_group_set_generator, 		ec_GFp_simple_group_get0_generator, 		ec_GFp_simple_group_get_order, 		ec_GFp_simple_group_get_cofactor, 		ec_GFp_simple_point_init, 		ec_GFp_simple_point_finish, 		ec_GFp_simple_point_clear_finish, 		ec_GFp_simple_point_copy, 		ec_GFp_simple_point_set_to_infinity, 		ec_GFp_simple_set_Jprojective_coordinates_GFp, 		ec_GFp_simple_get_Jprojective_coordinates_GFp, 		ec_GFp_simple_point_set_affine_coordinates_GFp, 		ec_GFp_simple_point_get_affine_coordinates_GFp, 		ec_GFp_simple_set_compressed_coordinates_GFp, 		ec_GFp_simple_point2oct, 		ec_GFp_simple_oct2point, 		ec_GFp_simple_add, 		ec_GFp_simple_dbl, 		ec_GFp_simple_invert, 		ec_GFp_simple_is_at_infinity, 		ec_GFp_simple_is_on_curve, 		ec_GFp_simple_cmp, 		ec_GFp_simple_make_affine, 		ec_GFp_simple_points_make_affine, 		ec_GFp_recp_field_mul, 		ec_GFp_recp_field_sqr, 		0
comment|/* field_encode */
end_comment

begin_comment
unit|, 		0
comment|/* field_decode */
end_comment

begin_comment
unit|, 		0
comment|/* field_set_to_one */
end_comment

begin_endif
unit|};  	return&ret; 	}
endif|#
directive|endif
end_endif

begin_function
name|int
name|ec_GFp_recp_group_init
parameter_list|(
name|EC_GROUP
modifier|*
name|group
parameter_list|)
block|{
name|int
name|ok
decl_stmt|;
name|ok
operator|=
name|ec_GFp_simple_group_init
argument_list|(
name|group
argument_list|)
expr_stmt|;
name|group
operator|->
name|field_data1
operator|=
name|NULL
expr_stmt|;
return|return
name|ok
return|;
block|}
end_function

begin_function_decl
name|int
name|ec_GFp_recp_group_set_curve_GFp
parameter_list|(
name|EC_GROUP
modifier|*
name|group
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
name|p
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
name|a
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
name|b
parameter_list|,
name|BN_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* TODO */
end_comment

begin_function_decl
name|void
name|ec_GFp_recp_group_finish
parameter_list|(
name|EC_GROUP
modifier|*
name|group
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* TODO */
end_comment

begin_function_decl
name|void
name|ec_GFp_recp_group_clear_finish
parameter_list|(
name|EC_GROUP
modifier|*
name|group
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* TODO */
end_comment

begin_function_decl
name|int
name|ec_GFp_recp_group_copy
parameter_list|(
name|EC_GROUP
modifier|*
name|dest
parameter_list|,
specifier|const
name|EC_GROUP
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* TODO */
end_comment

begin_function_decl
name|int
name|ec_GFp_recp_field_mul
parameter_list|(
specifier|const
name|EC_GROUP
modifier|*
name|group
parameter_list|,
name|BIGNUM
modifier|*
name|r
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
name|a
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
name|b
parameter_list|,
name|BN_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* TODO */
end_comment

begin_function_decl
name|int
name|ec_GFp_recp_field_sqr
parameter_list|(
specifier|const
name|EC_GROUP
modifier|*
name|group
parameter_list|,
name|BIGNUM
modifier|*
name|r
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
name|a
parameter_list|,
name|BN_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* TODO */
end_comment

end_unit

