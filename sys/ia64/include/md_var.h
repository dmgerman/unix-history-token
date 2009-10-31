begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_struct
struct|struct
name|ia64_fdesc
block|{
name|uint64_t
name|func
decl_stmt|;
name|uint64_t
name|gp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FDESC_FUNC
parameter_list|(
name|fn
parameter_list|)
value|(((struct ia64_fdesc *) fn)->func)
end_define

begin_define
define|#
directive|define
name|FDESC_GP
parameter_list|(
name|fn
parameter_list|)
value|(((struct ia64_fdesc *) fn)->gp)
end_define

begin_comment
comment|/* Convenience macros to decompose CFM& ar.pfs. */
end_comment

begin_define
define|#
directive|define
name|IA64_CFM_SOF
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x7f)
end_define

begin_define
define|#
directive|define
name|IA64_CFM_SOL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 0x7f)
end_define

begin_define
define|#
directive|define
name|IA64_CFM_SOR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x0f)
end_define

begin_define
define|#
directive|define
name|IA64_CFM_RRB_GR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 0x7f)
end_define

begin_define
define|#
directive|define
name|IA64_CFM_RRB_FR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x7f)
end_define

begin_define
define|#
directive|define
name|IA64_CFM_RRB_PR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 32)& 0x3f)
end_define

begin_comment
comment|/* Concenience function (inline) to adjust backingstore pointers. */
end_comment

begin_function
specifier|static
name|__inline
name|uint64_t
name|ia64_bsp_adjust
parameter_list|(
name|uint64_t
name|bsp
parameter_list|,
name|int
name|nslots
parameter_list|)
block|{
name|int
name|bias
init|=
operator|(
operator|(
name|unsigned
name|int
operator|)
name|bsp
operator|&
literal|0x1f8
operator|)
operator|>>
literal|3
decl_stmt|;
name|nslots
operator|+=
operator|(
name|nslots
operator|+
name|bias
operator|+
literal|63
operator|*
literal|8
operator|)
operator|/
literal|63
operator|-
literal|8
expr_stmt|;
return|return
name|bsp
operator|+
operator|(
name|nslots
operator|<<
literal|3
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|char
name|sigcode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|esigcode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|szsigcode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|Maxmem
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|_special
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fpreg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ia64_init_return
block|{
name|uint64_t
name|bspstore
decl_stmt|;
name|uint64_t
name|sp
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|busdma_swi
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copyout_regstack
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_mp_add
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_ast
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ia32_trap
parameter_list|(
name|int
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_count_cpus
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_emulate
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_flush_dirty
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|_special
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|ia64_get_hcdp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_highfp_drop
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_highfp_enable
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_highfp_save
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_highfp_save_ipi
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ia64_init_return
name|ia64_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ia64_probe_sapics
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ia64_sync_icache
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|interrupt
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|map_gateway_page
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|map_pal_code
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|map_vhpt
parameter_list|(
name|uintptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|os_boot_rendez
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|os_mca
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syscall
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trap
parameter_list|(
name|int
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trap_panic
parameter_list|(
name|int
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unaligned_fixup
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_MD_VAR_H_ */
end_comment

end_unit

