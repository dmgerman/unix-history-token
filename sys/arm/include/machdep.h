begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: machdep.h,v 1.7 2002/02/21 02:52:21 thorpej Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHDEP_BOOT_MACHDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHDEP_BOOT_MACHDEP_H_
end_define

begin_comment
comment|/* misc prototypes used by the many arm machdeps */
end_comment

begin_function_decl
name|void
name|halt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|data_abort_handler
parameter_list|(
name|trapframe_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prefetch_abort_handler
parameter_list|(
name|trapframe_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|undefinedinstruction_bounce
parameter_list|(
name|trapframe_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm_lock_cache_line
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_MACHDEP_H_ */
end_comment

end_unit

