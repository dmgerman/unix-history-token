begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: md5.h,v 1.4 2000/03/27 04:36:22 sumikawa Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_MD5_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_MD5_H_
end_define

begin_define
define|#
directive|define
name|MD5_BUFLEN
value|64
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
union|union
block|{
name|u_int32_t
name|md5_state32
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|md5_state8
index|[
literal|16
index|]
decl_stmt|;
block|}
name|md5_st
union|;
define|#
directive|define
name|md5_sta
value|md5_st.md5_state32[0]
define|#
directive|define
name|md5_stb
value|md5_st.md5_state32[1]
define|#
directive|define
name|md5_stc
value|md5_st.md5_state32[2]
define|#
directive|define
name|md5_std
value|md5_st.md5_state32[3]
define|#
directive|define
name|md5_st8
value|md5_st.md5_state8
union|union
block|{
name|u_int64_t
name|md5_count64
decl_stmt|;
name|u_int8_t
name|md5_count8
index|[
literal|8
index|]
decl_stmt|;
block|}
name|md5_count
union|;
define|#
directive|define
name|md5_n
value|md5_count.md5_count64
define|#
directive|define
name|md5_n8
value|md5_count.md5_count8
name|u_int
name|md5_i
decl_stmt|;
name|u_int8_t
name|md5_buf
index|[
name|MD5_BUFLEN
index|]
decl_stmt|;
block|}
name|md5_ctxt
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|md5_init
parameter_list|(
name|md5_ctxt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|md5_loop
parameter_list|(
name|md5_ctxt
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|md5_pad
parameter_list|(
name|md5_ctxt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|md5_result
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|,
name|md5_ctxt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* compatibility */
end_comment

begin_define
define|#
directive|define
name|MD5_CTX
value|md5_ctxt
end_define

begin_define
define|#
directive|define
name|MD5Init
parameter_list|(
name|x
parameter_list|)
value|md5_init((x))
end_define

begin_define
define|#
directive|define
name|MD5Update
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|md5_loop((x), (y), (z))
end_define

begin_define
define|#
directive|define
name|MD5Final
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|do {				\ 	md5_pad((y));		\ 	md5_result((x), (y));	\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _NETINET6_MD5_H_*/
end_comment

end_unit

