begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/md5/md5_locl.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<openssl/e_os2.h>
end_include

begin_include
include|#
directive|include
file|<openssl/md5.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MD5_LONG_LOG2
end_ifndef

begin_define
define|#
directive|define
name|MD5_LONG_LOG2
value|2
end_define

begin_comment
comment|/* default to 32 bits */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MD5_ASM
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_IX86
argument_list|)
operator|||
name|defined
argument_list|(
name|__INTEL__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__x86_64
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_AMD64
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_X64
argument_list|)
end_if

begin_define
define|#
directive|define
name|md5_block_data_order
value|md5_block_asm_data_order
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ia64
argument_list|)
operator|||
name|defined
argument_list|(
name|__ia64__
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_IA64
argument_list|)
end_elif

begin_define
define|#
directive|define
name|md5_block_data_order
value|md5_block_asm_data_order
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|md5_block_data_order
parameter_list|(
name|MD5_CTX
modifier|*
name|c
parameter_list|,
specifier|const
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DATA_ORDER_IS_LITTLE_ENDIAN
end_define

begin_define
define|#
directive|define
name|HASH_LONG
value|MD5_LONG
end_define

begin_define
define|#
directive|define
name|HASH_CTX
value|MD5_CTX
end_define

begin_define
define|#
directive|define
name|HASH_CBLOCK
value|MD5_CBLOCK
end_define

begin_define
define|#
directive|define
name|HASH_UPDATE
value|MD5_Update
end_define

begin_define
define|#
directive|define
name|HASH_TRANSFORM
value|MD5_Transform
end_define

begin_define
define|#
directive|define
name|HASH_FINAL
value|MD5_Final
end_define

begin_define
define|#
directive|define
name|HASH_MAKE_STRING
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|do {	\ 	unsigned long ll;		\ 	ll=(c)->A; (void)HOST_l2c(ll,(s));	\ 	ll=(c)->B; (void)HOST_l2c(ll,(s));	\ 	ll=(c)->C; (void)HOST_l2c(ll,(s));	\ 	ll=(c)->D; (void)HOST_l2c(ll,(s));	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|HASH_BLOCK_DATA_ORDER
value|md5_block_data_order
end_define

begin_include
include|#
directive|include
file|"md32_common.h"
end_include

begin_comment
comment|/* #define	F(x,y,z)	(((x)& (y))  |  ((~(x))& (z))) #define	G(x,y,z)	(((x)& (z))  |  ((y)& (~(z)))) */
end_comment

begin_comment
comment|/* As pointed out by Wei Dai<weidai@eskimo.com>, the above can be  * simplified to the code below.  Wei attributes these optimizations  * to Peter Gutmann's SHS code, and he attributes it to Rich Schroeppel.  */
end_comment

begin_define
define|#
directive|define
name|F
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((((c) ^ (d))& (b)) ^ (d))
end_define

begin_define
define|#
directive|define
name|G
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((((b) ^ (c))& (d)) ^ (c))
end_define

begin_define
define|#
directive|define
name|H
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((b) ^ (c) ^ (d))
end_define

begin_define
define|#
directive|define
name|I
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|(((~(d)) | (b)) ^ (c))
end_define

begin_define
define|#
directive|define
name|R0
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|k
parameter_list|,
name|s
parameter_list|,
name|t
parameter_list|)
value|{ \ 	a+=((k)+(t)+F((b),(c),(d))); \ 	a=ROTATE(a,s); \ 	a+=b; };\  #define R1(a,b,c,d,k,s,t) { \ 	a+=((k)+(t)+G((b),(c),(d))); \ 	a=ROTATE(a,s); \ 	a+=b; };
end_define

begin_define
define|#
directive|define
name|R2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|k
parameter_list|,
name|s
parameter_list|,
name|t
parameter_list|)
value|{ \ 	a+=((k)+(t)+H((b),(c),(d))); \ 	a=ROTATE(a,s); \ 	a+=b; };
end_define

begin_define
define|#
directive|define
name|R3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|k
parameter_list|,
name|s
parameter_list|,
name|t
parameter_list|)
value|{ \ 	a+=((k)+(t)+I((b),(c),(d))); \ 	a=ROTATE(a,s); \ 	a+=b; };
end_define

end_unit

