begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: rijndael.h,v 1.7 2001/03/01 03:38:33 deraadt Exp $	*/
end_comment

begin_comment
comment|/* This is an independent implementation of the encryption algorithm:   */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/*         RIJNDAEL by Joan Daemen and Vincent Rijmen                   */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* which is a candidate algorithm in the Advanced Encryption Standard   */
end_comment

begin_comment
comment|/* programme of the US National Institute of Standards and Technology.  */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* Copyright in this implementation is held by Dr B R Gladman but I     */
end_comment

begin_comment
comment|/* hereby give permission for its free direct or derivative use subject */
end_comment

begin_comment
comment|/* to acknowledgment of its origin and compliance with any conditions   */
end_comment

begin_comment
comment|/* that the originators of the algorithm place on its exploitation.     */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* Dr Brian Gladman (gladman@seven77.demon.co.uk) 14th January 1999     */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RIJNDAEL_H_
end_ifndef

begin_define
define|#
directive|define
name|_RIJNDAEL_H_
end_define

begin_comment
comment|/* 1. Standard types for AES cryptography source code               */
end_comment

begin_typedef
typedef|typedef
name|u_int8_t
name|u1byte
typedef|;
end_typedef

begin_comment
comment|/* an 8 bit unsigned character type */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|u2byte
typedef|;
end_typedef

begin_comment
comment|/* a 16 bit unsigned integer type   */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|u4byte
typedef|;
end_typedef

begin_comment
comment|/* a 32 bit unsigned integer type   */
end_comment

begin_typedef
typedef|typedef
name|int8_t
name|s1byte
typedef|;
end_typedef

begin_comment
comment|/* an 8 bit signed character type   */
end_comment

begin_typedef
typedef|typedef
name|int16_t
name|s2byte
typedef|;
end_typedef

begin_comment
comment|/* a 16 bit signed integer type     */
end_comment

begin_typedef
typedef|typedef
name|int32_t
name|s4byte
typedef|;
end_typedef

begin_comment
comment|/* a 32 bit signed integer type     */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_rijndael_ctx
block|{
name|u4byte
name|k_len
decl_stmt|;
name|int
name|decrypt
decl_stmt|;
name|u4byte
name|e_key
index|[
literal|64
index|]
decl_stmt|;
name|u4byte
name|d_key
index|[
literal|64
index|]
decl_stmt|;
block|}
name|rijndael_ctx
typedef|;
end_typedef

begin_comment
comment|/* 2. Standard interface for AES cryptographic routines             */
end_comment

begin_comment
comment|/* These are all based on 32 bit unsigned values and will therefore */
end_comment

begin_comment
comment|/* require endian conversions for big-endian architectures          */
end_comment

begin_decl_stmt
name|rijndael_ctx
modifier|*
name|rijndael_set_key
name|__P
argument_list|(
operator|(
name|rijndael_ctx
operator|*
operator|,
specifier|const
name|u4byte
operator|*
operator|,
name|u4byte
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rijndael_encrypt
name|__P
argument_list|(
operator|(
name|rijndael_ctx
operator|*
operator|,
specifier|const
name|u4byte
operator|*
operator|,
name|u4byte
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rijndael_decrypt
name|__P
argument_list|(
operator|(
name|rijndael_ctx
operator|*
operator|,
specifier|const
name|u4byte
operator|*
operator|,
name|u4byte
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RIJNDAEL_H_ */
end_comment

end_unit

