begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Bruce D. Evans.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: md_var.h,v 1.18 1997/09/13 16:12:11 joerg Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_MD_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_MD_VAR_H_
end_define

begin_comment
comment|/*  * Miscellaneous machine-dependent declarations.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Maxmem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|atdevbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset in virtual memory of ISA io mem */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|cpu_feature
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|cpu_high
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|cpu_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|cyrix_did
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|cpu_vendor
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|kstack
index|[]
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern	void	(*netisrs[32]
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfs_diskless_valid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|sigcode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|szsigcode
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
name|alias_for_inthand_t
name|__P
typedef|((
name|u_int
name|cs
typedef|,
name|u_int
name|ef
typedef|,
name|u_int
name|esp
typedef|,
name|u_int
name|ss
typedef|));
end_typedef

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reg
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|bcopyb
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
name|from
operator|,
name|void
operator|*
name|to
operator|,
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_reset
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_halt
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_power_down
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_switch_load_fs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
asm|__asm(__STRING(cpu_switch_load_fs));
name|void
name|cpu_switch_load_gs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
asm|__asm(__STRING(cpu_switch_load_gs));
name|void
name|doreti_iret
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
asm|__asm(__STRING(doreti_iret));
name|void
name|doreti_iret_fault
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
asm|__asm(__STRING(doreti_iret_fault));
name|void
name|doreti_popl_ds
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
asm|__asm(__STRING(doreti_popl_ds));
name|void
name|doreti_popl_ds_fault
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
asm|__asm(__STRING(doreti_popl_ds_fault));
name|void
name|doreti_popl_es
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
asm|__asm(__STRING(doreti_popl_es));
name|void
name|doreti_popl_es_fault
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
asm|__asm(__STRING(doreti_popl_es_fault));
name|int
name|fill_regs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
expr|struct
name|reg
operator|*
name|regs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fillw
name|__P
argument_list|(
operator|(
name|int
comment|/*u_short*/
name|pat
operator|,
name|void
operator|*
name|base
operator|,
name|size_t
name|cnt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|is_physical_memory
name|__P
argument_list|(
operator|(
name|vm_offset_t
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|kvtop
name|__P
argument_list|(
operator|(
name|void
operator|*
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setidt
name|__P
argument_list|(
operator|(
name|int
name|idx
operator|,
name|alias_for_inthand_t
operator|*
name|func
operator|,
name|int
name|typ
operator|,
name|int
name|dpl
operator|,
name|int
name|selec
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|userconfig
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_bounce_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_page_zero_idle
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|need_pre_dma_flush
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|need_post_dma_flush
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_MD_VAR_H_ */
end_comment

end_unit

