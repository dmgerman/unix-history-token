begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: cast128.h,v 1.6 2000/09/18 20:59:20 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * heavily modified by Tomomi Suzuki<suzuki@grelot.elec.ryukoku.ac.jp>  */
end_comment

begin_comment
comment|/*  * The CAST-128 Encryption Algorithm (RFC 2144)  *  * original implementation<Hideo "Sir MaNMOS" Morisita>  * 1997/08/21  */
end_comment

begin_comment
comment|/*  * Copyright (C) 1997 Hideo "Sir MANMOS" Morishita  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY Hideo "Sir MaNMOS" Morishita ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Hideo "Sir MaNMOS" Morishita BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RFC2144_CAST_128_H
end_ifndef

begin_define
define|#
directive|define
name|RFC2144_CAST_128_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_define
define|#
directive|define
name|CAST128_ENCRYPT
value|1
end_define

begin_define
define|#
directive|define
name|CAST128_DECRYPT
value|0
end_define

begin_decl_stmt
specifier|extern
name|void
name|set_cast128_subkey
name|__P
argument_list|(
operator|(
name|u_int32_t
operator|*
operator|,
name|u_int8_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cast128_encrypt_round16
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
name|u_int32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cast128_decrypt_round16
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
name|u_int32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cast128_encrypt_round12
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
name|u_int32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cast128_decrypt_round12
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
name|u_int32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

