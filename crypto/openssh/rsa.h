begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * rsa.h  *  * Author: Tatu Ylonen<ylo@cs.hut.fi>  *  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * Created: Fri Mar  3 22:01:06 1995 ylo  *  * RSA key generation, encryption and decryption.  *  * $FreeBSD$ */
end_comment

begin_comment
comment|/* RCSID("$Id: rsa.h,v 1.6 2000/04/14 10:30:32 markus Exp $"); */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RSA_H
end_ifndef

begin_define
define|#
directive|define
name|RSA_H
end_define

begin_include
include|#
directive|include
file|<openssl/bn.h>
end_include

begin_include
include|#
directive|include
file|<openssl/rsa.h>
end_include

begin_comment
comment|/* Calls SSL RSA_generate_key, only copies to prv and pub */
end_comment

begin_function_decl
name|void
name|rsa_generate_key
parameter_list|(
name|RSA
modifier|*
name|prv
parameter_list|,
name|RSA
modifier|*
name|pub
parameter_list|,
name|unsigned
name|int
name|bits
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Indicates whether the rsa module is permitted to show messages on the  * terminal.  */
end_comment

begin_decl_stmt
name|void
name|rsa_set_verbose
name|__P
argument_list|(
operator|(
name|int
name|verbose
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rsa_alive
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rsa_public_encrypt
name|__P
argument_list|(
operator|(
name|BIGNUM
operator|*
name|out
operator|,
name|BIGNUM
operator|*
name|in
operator|,
name|RSA
operator|*
name|prv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rsa_private_decrypt
name|__P
argument_list|(
operator|(
name|BIGNUM
operator|*
name|out
operator|,
name|BIGNUM
operator|*
name|in
operator|,
name|RSA
operator|*
name|prv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RSA_H */
end_comment

end_unit

