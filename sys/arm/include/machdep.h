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
comment|/* Structs that need to be initialised by initarm */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|irqstack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|undstack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|abtstack
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_struct_decl
struct_decl|struct
name|pv_addr
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|pv_addr
name|irqstack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pv_addr
name|undstack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pv_addr
name|abtstack
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define various stack sizes in pages */
end_comment

begin_define
define|#
directive|define
name|IRQ_STACK_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|ABT_STACK_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|UND_STACK_SIZE
value|1
end_define

begin_comment
comment|/* misc prototypes used by the many arm machdeps */
end_comment

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|arm_lock_cache_line
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_proc0
parameter_list|(
name|vm_offset_t
name|kstack
parameter_list|)
function_decl|;
end_function_decl

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
name|abort_handler
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_stackptrs
parameter_list|(
name|int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|undefinedinstruction_bounce
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Early boot related helper functions */
end_comment

begin_struct_decl
struct_decl|struct
name|arm_boot_params
struct_decl|;
end_struct_decl

begin_function_decl
name|vm_offset_t
name|default_parse_boot_param
parameter_list|(
name|struct
name|arm_boot_params
modifier|*
name|abp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|fake_preload_metadata
parameter_list|(
name|struct
name|arm_boot_params
modifier|*
name|abp
parameter_list|,
name|void
modifier|*
name|dtb_ptr
parameter_list|,
name|size_t
name|dtb_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|parse_boot_param
parameter_list|(
name|struct
name|arm_boot_params
modifier|*
name|abp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm_parse_fdt_bootargs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm_print_kenv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm_generic_initclocks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Board-specific attributes */
end_comment

begin_function_decl
name|void
name|board_set_serial
parameter_list|(
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|board_set_revision
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|arm_predict_branch
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|register_t
parameter_list|,
name|register_t
modifier|*
parameter_list|,
name|u_int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|u_int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|u_int
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PLATFORM
end_ifdef

begin_typedef
typedef|typedef
name|void
name|delay_func
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|arm_set_delay
parameter_list|(
name|delay_func
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EFI
end_ifdef

begin_struct_decl
struct_decl|struct
name|efi_map_header
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mem_region
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|arm_add_efi_map_entries
parameter_list|(
name|struct
name|efi_map_header
modifier|*
name|efihdr
parameter_list|,
name|struct
name|mem_region
modifier|*
name|mr
parameter_list|,
name|int
modifier|*
name|mrcnt
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
comment|/* !_MACHINE_MACHDEP_H_ */
end_comment

end_unit

