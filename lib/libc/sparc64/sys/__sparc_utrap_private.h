begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|___SPARC_UTRAP_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|___SPARC_UTRAP_PRIVATE_H_
end_define

begin_define
define|#
directive|define
name|UF_DONE
parameter_list|(
name|uf
parameter_list|)
value|do {						\ 	uf->uf_pc = uf->uf_npc;						\ 	uf->uf_npc = uf->uf_pc + 4;					\ } while (0)
end_define

begin_struct
struct|struct
name|utrapframe
block|{
name|u_long
name|uf_global
index|[
literal|8
index|]
decl_stmt|;
name|u_long
name|uf_out
index|[
literal|8
index|]
decl_stmt|;
name|u_long
name|uf_pc
decl_stmt|;
name|u_long
name|uf_npc
decl_stmt|;
name|u_long
name|uf_sfar
decl_stmt|;
name|u_long
name|uf_sfsr
decl_stmt|;
name|u_long
name|uf_tar
decl_stmt|;
name|u_long
name|uf_type
decl_stmt|;
name|u_long
name|uf_state
decl_stmt|;
name|u_long
name|uf_fsr
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
name|__sparc_utrap_fp_disabled
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|__sparc_utrap_gen
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|__sparc_utrap
parameter_list|(
name|struct
name|utrapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

