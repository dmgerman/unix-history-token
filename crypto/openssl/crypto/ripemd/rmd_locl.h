begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/ripemd/rmd_locl.h */
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
file|<openssl/opensslconf.h>
end_include

begin_include
include|#
directive|include
file|<openssl/ripemd.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|RIPEMD160_LONG_LOG2
end_ifndef

begin_define
define|#
directive|define
name|RIPEMD160_LONG_LOG2
value|2
end_define

begin_comment
comment|/* default to 32 bits */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * DO EXAMINE COMMENTS IN crypto/md5/md5_locl.h& crypto/md5/md5_dgst.c  * FOR EXPLANATIONS ON FOLLOWING "CODE."  *<appro@fy.chalmers.se>  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RMD160_ASM
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
name|_M_IX86
argument_list|)
operator|||
name|defined
argument_list|(
name|__INTEL__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ripemd160_block_host_order
value|ripemd160_block_asm_host_order
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
name|ripemd160_block_host_order
parameter_list|(
name|RIPEMD160_CTX
modifier|*
name|c
parameter_list|,
specifier|const
name|void
modifier|*
name|p
parameter_list|,
name|int
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ripemd160_block_data_order
parameter_list|(
name|RIPEMD160_CTX
modifier|*
name|c
parameter_list|,
specifier|const
name|void
modifier|*
name|p
parameter_list|,
name|int
name|num
parameter_list|)
function_decl|;
end_function_decl

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
name|_M_IX86
argument_list|)
operator|||
name|defined
argument_list|(
name|__INTEL__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ripemd160_block_data_order
value|ripemd160_block_host_order
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DATA_ORDER_IS_LITTLE_ENDIAN
end_define

begin_define
define|#
directive|define
name|HASH_LONG
value|RIPEMD160_LONG
end_define

begin_define
define|#
directive|define
name|HASH_LONG_LOG2
value|RIPEMD160_LONG_LOG2
end_define

begin_define
define|#
directive|define
name|HASH_CTX
value|RIPEMD160_CTX
end_define

begin_define
define|#
directive|define
name|HASH_CBLOCK
value|RIPEMD160_CBLOCK
end_define

begin_define
define|#
directive|define
name|HASH_LBLOCK
value|RIPEMD160_LBLOCK
end_define

begin_define
define|#
directive|define
name|HASH_UPDATE
value|RIPEMD160_Update
end_define

begin_define
define|#
directive|define
name|HASH_TRANSFORM
value|RIPEMD160_Transform
end_define

begin_define
define|#
directive|define
name|HASH_FINAL
value|RIPEMD160_Final
end_define

begin_define
define|#
directive|define
name|HASH_BLOCK_HOST_ORDER
value|ripemd160_block_host_order
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
value|do {	\ 	unsigned long ll;		\ 	ll=(c)->A; HOST_l2c(ll,(s));	\ 	ll=(c)->B; HOST_l2c(ll,(s));	\ 	ll=(c)->C; HOST_l2c(ll,(s));	\ 	ll=(c)->D; HOST_l2c(ll,(s));	\ 	ll=(c)->E; HOST_l2c(ll,(s));	\ 	} while (0)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|L_ENDIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|ripemd160_block_data_order
argument_list|)
end_if

begin_define
define|#
directive|define
name|HASH_BLOCK_DATA_ORDER
value|ripemd160_block_data_order
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"md32_common.h"
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|F1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((x)^(y)^(z))
end_define

begin_define
define|#
directive|define
name|F2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(((x)&(y))|((~x)&z))
end_define

begin_define
define|#
directive|define
name|F3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(((x)|(~y))^(z))
end_define

begin_define
define|#
directive|define
name|F4
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(((x)&(z))|((y)&(~(z))))
end_define

begin_define
define|#
directive|define
name|F5
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((x)^((y)|(~(z))))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Transformed F2 and F4 are courtesy of Wei Dai<weidai@eskimo.com>  */
end_comment

begin_define
define|#
directive|define
name|F1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((x) ^ (y) ^ (z))
end_define

begin_define
define|#
directive|define
name|F2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((((y) ^ (z))& (x)) ^ (z))
end_define

begin_define
define|#
directive|define
name|F3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(((~(y)) | (x)) ^ (z))
end_define

begin_define
define|#
directive|define
name|F4
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((((x) ^ (y))& (z)) ^ (y))
end_define

begin_define
define|#
directive|define
name|F5
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(((~(z)) | (y)) ^ (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RIPEMD160_A
value|0x67452301L
end_define

begin_define
define|#
directive|define
name|RIPEMD160_B
value|0xEFCDAB89L
end_define

begin_define
define|#
directive|define
name|RIPEMD160_C
value|0x98BADCFEL
end_define

begin_define
define|#
directive|define
name|RIPEMD160_D
value|0x10325476L
end_define

begin_define
define|#
directive|define
name|RIPEMD160_E
value|0xC3D2E1F0L
end_define

begin_include
include|#
directive|include
file|"rmdconst.h"
end_include

begin_define
define|#
directive|define
name|RIP1
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|w
parameter_list|,
name|s
parameter_list|)
value|{ \ 	a+=F1(b,c,d)+X(w); \         a=ROTATE(a,s)+e; \         c=ROTATE(c,10); }
end_define

begin_define
define|#
directive|define
name|RIP2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|w
parameter_list|,
name|s
parameter_list|,
name|K
parameter_list|)
value|{ \ 	a+=F2(b,c,d)+X(w)+K; \         a=ROTATE(a,s)+e; \         c=ROTATE(c,10); }
end_define

begin_define
define|#
directive|define
name|RIP3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|w
parameter_list|,
name|s
parameter_list|,
name|K
parameter_list|)
value|{ \ 	a+=F3(b,c,d)+X(w)+K; \         a=ROTATE(a,s)+e; \         c=ROTATE(c,10); }
end_define

begin_define
define|#
directive|define
name|RIP4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|w
parameter_list|,
name|s
parameter_list|,
name|K
parameter_list|)
value|{ \ 	a+=F4(b,c,d)+X(w)+K; \         a=ROTATE(a,s)+e; \         c=ROTATE(c,10); }
end_define

begin_define
define|#
directive|define
name|RIP5
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|w
parameter_list|,
name|s
parameter_list|,
name|K
parameter_list|)
value|{ \ 	a+=F5(b,c,d)+X(w)+K; \         a=ROTATE(a,s)+e; \         c=ROTATE(c,10); }
end_define

end_unit

