begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: rsa.h,v 1.15 2002/03/04 17:27:39 stevesk Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * RSA key generation, encryption and decryption.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
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

begin_function_decl
name|void
name|rsa_public_encrypt
parameter_list|(
name|BIGNUM
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
name|RSA
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rsa_private_decrypt
parameter_list|(
name|BIGNUM
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
name|RSA
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rsa_generate_additional_parameters
parameter_list|(
name|RSA
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RSA_H */
end_comment

end_unit

