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

begin_struct_decl
struct_decl|struct
name|cam_sim
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rpb
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

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_43
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|szosigcode
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_FREEBSD4
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|szfreebsd4_sigcode
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|long
name|Maxmem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|busdma_swi_pending
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rpb
modifier|*
name|hwrpb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|mc_expected
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|mc_received
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|XentArith
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|XentIF
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|XentInt
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|XentMM
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|XentRestart
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|XentSys
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|XentUna
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|alpha_fpstate_check
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|alpha_fpstate_drop
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|alpha_fpstate_save
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|write
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|alpha_fpstate_switch
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|alpha_init
parameter_list|(
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|alpha_pa_access
parameter_list|(
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|alpha_register_pci_scsi
parameter_list|(
name|int
name|bus
parameter_list|,
name|int
name|slot
parameter_list|,
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|badaddr
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|badaddr_read
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|busdma_swi
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|console_restart
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dumpconf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|exception_return
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|frametoreg
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|,
name|struct
name|reg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|fswintrberr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|u_int64_t
name|hwrpb_checksum
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hwrpb_restart_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_prom_interface
parameter_list|(
name|struct
name|rpb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|interrupt
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_physical_memory
parameter_list|(
name|vm_offset_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|machine_check
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|regdump
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|regtoframe
parameter_list|(
name|struct
name|reg
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_iointr
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|switch_exit
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|syscall
parameter_list|(
name|u_int64_t
parameter_list|,
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
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_BUS_H_
end_ifdef

begin_function_decl
name|struct
name|resource
modifier|*
name|alpha_platform_alloc_ide_intr
parameter_list|(
name|int
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|alpha_platform_release_ide_intr
parameter_list|(
name|int
name|chan
parameter_list|,
name|struct
name|resource
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|alpha_platform_setup_ide_intr
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|,
name|struct
name|resource
modifier|*
name|res
parameter_list|,
name|driver_intr_t
modifier|*
name|fn
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|alpha_platform_teardown_ide_intr
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|,
name|struct
name|resource
modifier|*
name|res
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|alpha_platform_pci_setup_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|struct
name|resource
modifier|*
name|irq
parameter_list|,
name|int
name|flags
parameter_list|,
name|driver_intr_t
modifier|*
name|intr
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|alpha_platform_pci_teardown_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|struct
name|resource
modifier|*
name|irq
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|alpha_pci_route_interrupt
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|,
name|int
name|pin
parameter_list|)
function_decl|;
end_function_decl

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

