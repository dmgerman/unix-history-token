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
name|data_abort_handler
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prefetch_abort_handler
parameter_list|(
name|struct
name|trapframe
modifier|*
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
name|freebsd_parse_boot_param
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
name|linux_parse_boot_param
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
name|arm_generic_initclocks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialization functions called by the common initarm() function in  * arm/machdep.c (but not necessarily from the custom initarm() functions of  * older code).  *  *  - initarm_early_init() is called very early, after parsing the boot params  *    and after physical memory has been located and sized.  *  *  - platform_devmap_init() is called as one of the last steps of early virtual  *    memory initialization, shortly before the new page tables are installed.  *  *  - initarm_lastaddr() is called after platform_devmap_init(), and must return  *    the address of the first byte of unusable KVA space.  This allows a  *    platform to carve out of the top of the KVA space whatever reserves it  *    needs for things like static device mapping, and this is called to get the  *    value before calling pmap_bootstrap() which uses the value to size the  *    available KVA.  *  *  - initarm_gpio_init() is called after the static device mappings are  *    established and just before cninit().  The intention is that the routine  *    can do any hardware setup (such as gpio or pinmux) necessary to make the  *    console functional.  *  *  - initarm_late_init() is called just after cninit().  This is the first of  *    the init routines that can use printf() and expect the output to appear on  *    a standard console.  *  */
end_comment

begin_function_decl
name|void
name|initarm_early_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|initarm_devmap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|initarm_lastaddr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|initarm_gpio_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|initarm_late_init
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_MACHDEP_H_ */
end_comment

end_unit

