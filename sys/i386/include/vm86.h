begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Jonathan Lemon  * All rights reserved.  *  * Derived from register.h, which is  *     Copyright (c) 1996 Michael Smith.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: vm86.h,v 1.3 1997/08/28 14:36:56 jlemon Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_VM86_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_VM86_H_
value|1
end_define

begin_struct
struct|struct
name|vm86_kernel
block|{
name|caddr_t
name|vm86_intmap
decl_stmt|;
comment|/* interrupt map */
name|u_long
name|vm86_eflags
decl_stmt|;
comment|/* emulated flags */
name|int
name|vm86_has_vme
decl_stmt|;
comment|/* VME support */
name|int
name|vm86_inited
decl_stmt|;
comment|/* we were initialized */
name|int
name|vm86_debug
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i386_vm86_args
block|{
name|int
name|sub_op
decl_stmt|;
comment|/* sub-operation to perform */
name|char
modifier|*
name|sub_args
decl_stmt|;
comment|/* args */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VM86_INIT
value|1
end_define

begin_define
define|#
directive|define
name|VM86_SET_VME
value|2
end_define

begin_define
define|#
directive|define
name|VM86_GET_VME
value|3
end_define

begin_struct
struct|struct
name|vm86_init_args
block|{
name|int
name|debug
decl_stmt|;
comment|/* debug flag */
name|int
name|cpu_type
decl_stmt|;
comment|/* cpu type to emulate */
name|u_char
name|int_map
index|[
literal|32
index|]
decl_stmt|;
comment|/* interrupt map */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm86_vme_args
block|{
name|int
name|state
decl_stmt|;
comment|/* status */
block|}
struct|;
end_struct

begin_comment
comment|/* standard register representation */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|u_long
name|r_ex
decl_stmt|;
struct|struct
block|{
name|u_short
name|r_x
decl_stmt|;
name|u_short
label|:
literal|16
expr_stmt|;
block|}
name|r_w
struct|;
struct|struct
block|{
name|u_char
name|r_l
decl_stmt|;
name|u_char
name|r_h
decl_stmt|;
name|u_short
label|:
literal|16
expr_stmt|;
block|}
name|r_b
struct|;
block|}
name|reg86_t
typedef|;
end_typedef

begin_comment
comment|/* layout must match definition of struct trapframe_vm86 in<machine/frame.h> */
end_comment

begin_struct
struct|struct
name|vm86frame
block|{
name|int
label|:
literal|32
expr_stmt|;
comment|/* kernel ES */
name|int
label|:
literal|32
expr_stmt|;
comment|/* kernel DS */
name|reg86_t
name|edi
decl_stmt|;
name|reg86_t
name|esi
decl_stmt|;
name|reg86_t
name|ebp
decl_stmt|;
name|reg86_t
name|isp
decl_stmt|;
name|reg86_t
name|ebx
decl_stmt|;
name|reg86_t
name|edx
decl_stmt|;
name|reg86_t
name|ecx
decl_stmt|;
name|reg86_t
name|eax
decl_stmt|;
name|int
label|:
literal|32
expr_stmt|;
comment|/* trapno */
name|int
label|:
literal|32
expr_stmt|;
comment|/* err */
name|reg86_t
name|eip
decl_stmt|;
name|reg86_t
name|cs
decl_stmt|;
name|reg86_t
name|eflags
decl_stmt|;
name|reg86_t
name|esp
decl_stmt|;
name|reg86_t
name|ss
decl_stmt|;
name|reg86_t
name|es
decl_stmt|;
name|reg86_t
name|ds
decl_stmt|;
name|reg86_t
name|fs
decl_stmt|;
name|reg86_t
name|gs
decl_stmt|;
define|#
directive|define
name|vmf_cs
value|cs.r_w.r_x
define|#
directive|define
name|vmf_ss
value|ss.r_w.r_x
define|#
directive|define
name|vmf_sp
value|esp.r_w.r_x
define|#
directive|define
name|vmf_ip
value|eip.r_w.r_x
define|#
directive|define
name|vmf_flags
value|eflags.r_w.r_x
define|#
directive|define
name|vmf_eflags
value|eflags.r_ex
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|vm86_emulate
name|__P
argument_list|(
operator|(
expr|struct
name|vm86frame
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vm86_sysarch
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
name|char
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
comment|/* _MACHINE_VM86_H_ */
end_comment

end_unit

