begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	from: NetBSD: fpu_extern.h,v 1.4 2000/08/03 18:32:08 eeh Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPARC64_FPU_FPU_EXTERN_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPARC64_FPU_FPU_EXTERN_H_
end_define

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fpstate
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|utrapframe
struct_decl|;
end_struct_decl

begin_union_decl
union_decl|union
name|instr
union_decl|;
end_union_decl

begin_struct_decl
struct_decl|struct
name|fpemu
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fpn
struct_decl|;
end_struct_decl

begin_comment
comment|/* fpu.c */
end_comment

begin_decl_stmt
name|void
name|__fpu_exception
name|__P
argument_list|(
operator|(
expr|struct
name|utrapframe
operator|*
name|tf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__fpu_panic
name|__P
argument_list|(
operator|(
name|char
operator|*
name|msg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fpu_add.c */
end_comment

begin_decl_stmt
name|struct
name|fpn
modifier|*
name|__fpu_add
name|__P
argument_list|(
operator|(
expr|struct
name|fpemu
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fpu_compare.c */
end_comment

begin_decl_stmt
name|void
name|__fpu_compare
name|__P
argument_list|(
operator|(
expr|struct
name|fpemu
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fpu_div.c */
end_comment

begin_decl_stmt
name|struct
name|fpn
modifier|*
name|__fpu_div
name|__P
argument_list|(
operator|(
expr|struct
name|fpemu
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fpu_explode.c */
end_comment

begin_decl_stmt
name|int
name|__fpu_itof
name|__P
argument_list|(
operator|(
expr|struct
name|fpn
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__fpu_xtof
name|__P
argument_list|(
operator|(
expr|struct
name|fpn
operator|*
operator|,
name|u_int64_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__fpu_stof
name|__P
argument_list|(
operator|(
expr|struct
name|fpn
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__fpu_dtof
name|__P
argument_list|(
operator|(
expr|struct
name|fpn
operator|*
operator|,
name|u_int
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__fpu_qtof
name|__P
argument_list|(
operator|(
expr|struct
name|fpn
operator|*
operator|,
name|u_int
operator|,
name|u_int
operator|,
name|u_int
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__fpu_explode
name|__P
argument_list|(
operator|(
expr|struct
name|fpemu
operator|*
operator|,
expr|struct
name|fpn
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fpu_implode.c */
end_comment

begin_decl_stmt
name|u_int
name|__fpu_ftoi
name|__P
argument_list|(
operator|(
expr|struct
name|fpemu
operator|*
operator|,
expr|struct
name|fpn
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|__fpu_ftox
name|__P
argument_list|(
operator|(
expr|struct
name|fpemu
operator|*
operator|,
expr|struct
name|fpn
operator|*
operator|,
name|u_int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|__fpu_ftos
name|__P
argument_list|(
operator|(
expr|struct
name|fpemu
operator|*
operator|,
expr|struct
name|fpn
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|__fpu_ftod
name|__P
argument_list|(
operator|(
expr|struct
name|fpemu
operator|*
operator|,
expr|struct
name|fpn
operator|*
operator|,
name|u_int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|__fpu_ftoq
name|__P
argument_list|(
operator|(
expr|struct
name|fpemu
operator|*
operator|,
expr|struct
name|fpn
operator|*
operator|,
name|u_int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__fpu_implode
name|__P
argument_list|(
operator|(
expr|struct
name|fpemu
operator|*
operator|,
expr|struct
name|fpn
operator|*
operator|,
name|int
operator|,
name|u_int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fpu_mul.c */
end_comment

begin_decl_stmt
name|struct
name|fpn
modifier|*
name|__fpu_mul
name|__P
argument_list|(
operator|(
expr|struct
name|fpemu
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fpu_sqrt.c */
end_comment

begin_decl_stmt
name|struct
name|fpn
modifier|*
name|__fpu_sqrt
name|__P
argument_list|(
operator|(
expr|struct
name|fpemu
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fpu_subr.c */
end_comment

begin_comment
comment|/*  * Shift a number right some number of bits, taking care of round/sticky.  * Note that the result is probably not a well-formed number (it will lack  * the normal 1-bit mant[0]&FP_1).  */
end_comment

begin_decl_stmt
name|int
name|__fpu_shr
name|__P
argument_list|(
operator|(
specifier|register
expr|struct
name|fpn
operator|*
operator|,
specifier|register
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__fpu_norm
name|__P
argument_list|(
operator|(
specifier|register
expr|struct
name|fpn
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Build a new Quiet NaN (sign=0, frac=all 1's). */
end_comment

begin_decl_stmt
name|struct
name|fpn
modifier|*
name|__fpu_newnan
name|__P
argument_list|(
operator|(
specifier|register
expr|struct
name|fpemu
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SPARC64_FPU_FPU_EXTERN_H_ */
end_comment

end_unit

