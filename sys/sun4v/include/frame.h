begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_FRAME_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_FRAME_H_
end_define

begin_define
define|#
directive|define
name|RW_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|SPOFF
value|2047
end_define

begin_define
define|#
directive|define
name|BIAS
value|SPOFF
end_define

begin_comment
comment|/* XXX - open/netbsd compat */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * NOTE: keep this structure in sync with struct reg and struct mcontext.  */
end_comment

begin_struct
struct|struct
name|trapframe
block|{
name|uint64_t
name|tf_global
index|[
literal|8
index|]
decl_stmt|;
name|uint64_t
name|tf_out
index|[
literal|8
index|]
decl_stmt|;
name|uint64_t
name|tf_fprs
decl_stmt|;
name|uint64_t
name|tf_fsr
decl_stmt|;
name|uint64_t
name|tf_gsr
decl_stmt|;
name|uint64_t
name|tf_pad0
index|[
literal|1
index|]
decl_stmt|;
name|uint64_t
name|tf_pil
decl_stmt|;
name|uint64_t
name|tf_pad1
index|[
literal|3
index|]
decl_stmt|;
name|uint64_t
name|tf_tnpc
decl_stmt|;
name|uint64_t
name|tf_tpc
decl_stmt|;
name|uint64_t
name|tf_tstate
decl_stmt|;
name|uint64_t
name|tf_pad2
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|tf_wstate
decl_stmt|;
name|uint64_t
name|tf_asi
decl_stmt|;
name|uint64_t
name|tf_pad3
index|[
literal|1
index|]
decl_stmt|;
block|}
name|__aligned
argument_list|(
literal|64
argument_list|)
struct|;
end_struct

begin_comment
comment|/* extra padding can go away once we re-shuffle user-land mcontext  */
end_comment

begin_define
define|#
directive|define
name|tf_sp
value|tf_out[6]
end_define

begin_define
define|#
directive|define
name|TF_DONE
parameter_list|(
name|tf
parameter_list|)
value|do { \ 	tf->tf_tpc = tf->tf_tnpc; \ 	tf->tf_tnpc += 4; \ } while (0)
end_define

begin_struct
struct|struct
name|frame
block|{
name|u_long
name|fr_local
index|[
literal|8
index|]
decl_stmt|;
name|u_long
name|fr_in
index|[
literal|8
index|]
decl_stmt|;
name|u_long
name|fr_pad
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|fr_arg
value|fr_in
end_define

begin_define
define|#
directive|define
name|fr_fp
value|fr_in[6]
end_define

begin_define
define|#
directive|define
name|fr_pc
value|fr_in[7]
end_define

begin_define
define|#
directive|define
name|v9next_frame
parameter_list|(
name|fp
parameter_list|)
value|((struct frame *)(fp->fr_fp + BIAS))
end_define

begin_comment
comment|/*  * Frame used for pcb_rw.  */
end_comment

begin_struct
struct|struct
name|rwindow
block|{
name|u_long
name|rw_local
index|[
literal|8
index|]
decl_stmt|;
name|u_long
name|rw_in
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|rwindow_save
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rwindow_load
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|trapframe
modifier|*
name|tf
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_FRAME_H_ */
end_comment

end_unit

