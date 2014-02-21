begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP server/peer: EAP-pwd shared definitions  * Copyright (c) 2009, Dan Harkins<dharkins@lounge.org>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_PWD_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_PWD_COMMON_H
end_define

begin_include
include|#
directive|include
file|<openssl/bn.h>
end_include

begin_include
include|#
directive|include
file|<openssl/ec.h>
end_include

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_comment
comment|/*  * definition of a finite cyclic group  * TODO: support one based on a prime field  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|group_definition_
block|{
name|u16
name|group_num
decl_stmt|;
name|EC_GROUP
modifier|*
name|group
decl_stmt|;
name|EC_POINT
modifier|*
name|pwe
decl_stmt|;
name|BIGNUM
modifier|*
name|order
decl_stmt|;
name|BIGNUM
modifier|*
name|prime
decl_stmt|;
block|}
name|EAP_PWD_group
typedef|;
end_typedef

begin_comment
comment|/*  * EAP-pwd header, included on all payloads  * L(1 bit) | M(1 bit) | exch(6 bits) | total_length(if L is set)  */
end_comment

begin_define
define|#
directive|define
name|EAP_PWD_HDR_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|EAP_PWD_OPCODE_ID_EXCH
value|1
end_define

begin_define
define|#
directive|define
name|EAP_PWD_OPCODE_COMMIT_EXCH
value|2
end_define

begin_define
define|#
directive|define
name|EAP_PWD_OPCODE_CONFIRM_EXCH
value|3
end_define

begin_define
define|#
directive|define
name|EAP_PWD_GET_LENGTH_BIT
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x80)
end_define

begin_define
define|#
directive|define
name|EAP_PWD_SET_LENGTH_BIT
parameter_list|(
name|x
parameter_list|)
value|((x) |= 0x80)
end_define

begin_define
define|#
directive|define
name|EAP_PWD_GET_MORE_BIT
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x40)
end_define

begin_define
define|#
directive|define
name|EAP_PWD_SET_MORE_BIT
parameter_list|(
name|x
parameter_list|)
value|((x) |= 0x40)
end_define

begin_define
define|#
directive|define
name|EAP_PWD_GET_EXCHANGE
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x3f)
end_define

begin_define
define|#
directive|define
name|EAP_PWD_SET_EXCHANGE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) |= (y))
end_define

begin_comment
comment|/* EAP-pwd-ID payload */
end_comment

begin_struct
struct|struct
name|eap_pwd_id
block|{
name|be16
name|group_num
decl_stmt|;
name|u8
name|random_function
decl_stmt|;
define|#
directive|define
name|EAP_PWD_DEFAULT_RAND_FUNC
value|1
name|u8
name|prf
decl_stmt|;
define|#
directive|define
name|EAP_PWD_DEFAULT_PRF
value|1
name|u8
name|token
index|[
literal|4
index|]
decl_stmt|;
name|u8
name|prep
decl_stmt|;
define|#
directive|define
name|EAP_PWD_PREP_NONE
value|0
define|#
directive|define
name|EAP_PWD_PREP_MS
value|1
name|u8
name|identity
index|[
literal|0
index|]
decl_stmt|;
comment|/* length inferred from payload */
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_comment
comment|/* common routines */
end_comment

begin_function_decl
name|int
name|compute_password_element
parameter_list|(
name|EAP_PWD_group
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u8
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u8
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u8
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u8
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|compute_keys
parameter_list|(
name|EAP_PWD_group
modifier|*
parameter_list|,
name|BN_CTX
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
name|u8
modifier|*
parameter_list|,
name|u8
modifier|*
parameter_list|,
name|u32
modifier|*
parameter_list|,
name|u8
modifier|*
parameter_list|,
name|u8
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|crypto_hash
modifier|*
name|eap_pwd_h_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_pwd_h_update
parameter_list|(
name|struct
name|crypto_hash
modifier|*
name|hash
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_pwd_h_final
parameter_list|(
name|struct
name|crypto_hash
modifier|*
name|hash
parameter_list|,
name|u8
modifier|*
name|digest
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_PWD_COMMON_H */
end_comment

end_unit

