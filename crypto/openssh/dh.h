begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: dh.h,v 1.11 2013/10/08 11:42:13 dtucker Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 Niels Provos.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DH_H
end_ifndef

begin_define
define|#
directive|define
name|DH_H
end_define

begin_struct
struct|struct
name|dhgroup
block|{
name|int
name|size
decl_stmt|;
name|BIGNUM
modifier|*
name|g
decl_stmt|;
name|BIGNUM
modifier|*
name|p
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|DH
modifier|*
name|choose_dh
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DH
modifier|*
name|dh_new_group_asc
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DH
modifier|*
name|dh_new_group
parameter_list|(
name|BIGNUM
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DH
modifier|*
name|dh_new_group1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DH
modifier|*
name|dh_new_group14
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dh_gen_key
parameter_list|(
name|DH
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dh_pub_is_valid
parameter_list|(
name|DH
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dh_estimate
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Min and max values from RFC4419. */
end_comment

begin_define
define|#
directive|define
name|DH_GRP_MIN
value|1024
end_define

begin_define
define|#
directive|define
name|DH_GRP_MAX
value|8192
end_define

begin_comment
comment|/*  * Values for "type" field of moduli(5)  * Specifies the internal structure of the prime modulus.  */
end_comment

begin_define
define|#
directive|define
name|MODULI_TYPE_UNKNOWN
value|(0)
end_define

begin_define
define|#
directive|define
name|MODULI_TYPE_UNSTRUCTURED
value|(1)
end_define

begin_define
define|#
directive|define
name|MODULI_TYPE_SAFE
value|(2)
end_define

begin_define
define|#
directive|define
name|MODULI_TYPE_SCHNORR
value|(3)
end_define

begin_define
define|#
directive|define
name|MODULI_TYPE_SOPHIE_GERMAIN
value|(4)
end_define

begin_define
define|#
directive|define
name|MODULI_TYPE_STRONG
value|(5)
end_define

begin_comment
comment|/*  * Values for "tests" field of moduli(5)  * Specifies the methods used in checking for primality.  * Usually, more than one test is used.  */
end_comment

begin_define
define|#
directive|define
name|MODULI_TESTS_UNTESTED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MODULI_TESTS_COMPOSITE
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MODULI_TESTS_SIEVE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MODULI_TESTS_MILLER_RABIN
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MODULI_TESTS_JACOBI
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MODULI_TESTS_ELLIPTIC
value|(0x10)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

