begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * RSA key generation, encryption and decryption.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/* RCSID("$OpenBSD: rsa.h,v 1.11 2001/03/26 23:23:24 markus Exp $"); */
end_comment

begin_comment
comment|/* RCSID("$FreeBSD$"); */
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
name|int
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

begin_decl_stmt
name|void
name|generate_additional_parameters
name|__P
argument_list|(
operator|(
name|RSA
operator|*
name|rsa
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

