begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: rc5.h,v 1.4 2000/06/14 10:41:17 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RFC2040_RC5_H_
end_ifndef

begin_define
define|#
directive|define
name|_RFC2040_RC5_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_comment
comment|/*  * if RC5_WORD change, W also may be changed.  */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|RC5_WORD
typedef|;
end_typedef

begin_define
define|#
directive|define
name|W
value|(32)
end_define

begin_define
define|#
directive|define
name|WW
value|(W / 8)
end_define

begin_define
define|#
directive|define
name|ROT_MASK
value|(W - 1)
end_define

begin_define
define|#
directive|define
name|BB
value|((2 * W) / 8)
end_define

begin_define
define|#
directive|define
name|SHLL
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|)
value|((RC5_WORD)((x)<< ((s)&ROT_MASK)))
end_define

begin_define
define|#
directive|define
name|SHLR
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|,
name|w
parameter_list|)
value|((RC5_WORD)((x)>> ((w)-((s)&ROT_MASK))))
end_define

begin_define
define|#
directive|define
name|SHRL
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|,
name|w
parameter_list|)
value|((RC5_WORD)((x)<< ((w)-((s)&ROT_MASK))))
end_define

begin_define
define|#
directive|define
name|SHRR
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|)
value|((RC5_WORD)((x)>> ((s)&ROT_MASK)))
end_define

begin_define
define|#
directive|define
name|ROTL
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|,
name|w
parameter_list|)
value|((RC5_WORD)(SHLL((x), (s))|SHLR((x), (s), (w))))
end_define

begin_define
define|#
directive|define
name|ROTR
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|,
name|w
parameter_list|)
value|((RC5_WORD)(SHRL((x), (s), (w))|SHRR((x), (s))))
end_define

begin_define
define|#
directive|define
name|P16
value|0xb7e1
end_define

begin_define
define|#
directive|define
name|Q16
value|0x9e37
end_define

begin_define
define|#
directive|define
name|P32
value|0xb7e15163
end_define

begin_define
define|#
directive|define
name|Q32
value|0x9e3779b9
end_define

begin_define
define|#
directive|define
name|P64
value|0xb7e151628aed2a6b
end_define

begin_define
define|#
directive|define
name|Q64
value|0x9e3779b97f4a7c15
end_define

begin_if
if|#
directive|if
name|W
operator|==
literal|16
end_if

begin_define
define|#
directive|define
name|Pw
value|P16
end_define

begin_define
define|#
directive|define
name|Qw
value|Q16
end_define

begin_elif
elif|#
directive|elif
name|W
operator|==
literal|32
end_elif

begin_define
define|#
directive|define
name|Pw
value|P32
end_define

begin_define
define|#
directive|define
name|Qw
value|Q32
end_define

begin_elif
elif|#
directive|elif
name|W
operator|==
literal|64
end_elif

begin_define
define|#
directive|define
name|Pw
value|P64
end_define

begin_define
define|#
directive|define
name|Qw
value|Q64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RC5_ENCRYPT
value|1
end_define

begin_define
define|#
directive|define
name|RC5_DECRYPT
value|0
end_define

begin_decl_stmt
specifier|extern
name|void
name|set_rc5_expandkey
name|__P
argument_list|(
operator|(
name|RC5_WORD
operator|*
operator|,
name|u_int8_t
operator|*
operator|,
name|size_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rc5_encrypt_round16
name|__P
argument_list|(
operator|(
name|u_int8_t
operator|*
operator|,
specifier|const
name|u_int8_t
operator|*
operator|,
specifier|const
name|RC5_WORD
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rc5_decrypt_round16
name|__P
argument_list|(
operator|(
name|u_int8_t
operator|*
operator|,
specifier|const
name|u_int8_t
operator|*
operator|,
specifier|const
name|RC5_WORD
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rc5_cbc_process
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|size_t
operator|,
name|size_t
operator|,
name|RC5_WORD
operator|*
operator|,
name|u_int8_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

