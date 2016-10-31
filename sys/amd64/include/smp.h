begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SMP_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<x86/x86_smp.h>
end_include

begin_comment
comment|/* global symbols in mpboot.S */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|mptramp_start
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|mptramp_end
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|mptramp_pagetables
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IPI handlers */
end_comment

begin_decl_stmt
name|inthand_t
name|IDTVEC
argument_list|(
name|invltlb_pcid
argument_list|)
decl_stmt|,
comment|/* TLB shootdowns - global, pcid */
name|IDTVEC
argument_list|(
name|invltlb_invpcid
argument_list|)
decl_stmt|,
comment|/* TLB shootdowns - global, invpcid */
name|IDTVEC
argument_list|(
name|justreturn
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interrupt CPU with minimum overhead */
end_comment

begin_function_decl
name|void
name|invltlb_pcid_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|invltlb_invpcid_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|native_start_all_aps
parameter_list|(
name|void
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
comment|/* SMP */
end_comment

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
comment|/* _MACHINE_SMP_H_ */
end_comment

end_unit

