begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Dynamic architecture support for GDB, the GNU debugger.    Copyright 1998, 1999, 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GDBARCH_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|GDBARCH_UTILS_H
end_define

begin_comment
comment|/* gdbarch trace variable */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gdbarch_debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fallback for register convertible. */
end_comment

begin_decl_stmt
specifier|extern
name|gdbarch_register_convertible_ftype
name|generic_register_convertible_not
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|CORE_ADDR
name|generic_cannot_extract_struct_value_address
parameter_list|(
name|char
modifier|*
name|dummy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Helper function for targets that don't know how my arguments are    being passed */
end_comment

begin_decl_stmt
specifier|extern
name|gdbarch_frame_num_args_ftype
name|frame_num_args_unknown
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Implementation of breakpoint from PC using any of the deprecated    macros BREAKPOINT, LITTLE_BREAKPOINT, BIG_BREAPOINT.  For legacy    targets that don't yet implement their own breakpoint_from_pc(). */
end_comment

begin_decl_stmt
specifier|extern
name|gdbarch_breakpoint_from_pc_ftype
name|legacy_breakpoint_from_pc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Frameless functions not identifable. */
end_comment

begin_decl_stmt
specifier|extern
name|gdbarch_frameless_function_invocation_ftype
name|generic_frameless_function_invocation_not
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Only structures, unions, and arrays are returned using the struct    convention.  Note that arrays are never passed by value in the C    language family, so that case is irrelevant for C.  */
end_comment

begin_decl_stmt
specifier|extern
name|gdbarch_return_value_on_stack_ftype
name|generic_return_value_on_stack_not
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Map onto old REGISTER_NAMES. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|legacy_register_name
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Accessor for old global function pointer for disassembly. */
end_comment

begin_function_decl
specifier|extern
name|int
name|legacy_print_insn
parameter_list|(
name|bfd_vma
name|vma
parameter_list|,
name|disassemble_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Backward compatible call_dummy_words. */
end_comment

begin_decl_stmt
specifier|extern
name|LONGEST
name|legacy_call_dummy_words
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|legacy_sizeof_call_dummy_words
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Typical remote_translate_xfer_address */
end_comment

begin_decl_stmt
specifier|extern
name|gdbarch_remote_translate_xfer_address_ftype
name|generic_remote_translate_xfer_address
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generic implementation of prologue_frameless_p.  Just calls    SKIP_PROLOG and checks the return value to see if it actually    changed. */
end_comment

begin_decl_stmt
specifier|extern
name|gdbarch_prologue_frameless_p_ftype
name|generic_prologue_frameless_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The only possible cases for inner_than. */
end_comment

begin_function_decl
specifier|extern
name|int
name|core_addr_lessthan
parameter_list|(
name|CORE_ADDR
name|lhs
parameter_list|,
name|CORE_ADDR
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|core_addr_greaterthan
parameter_list|(
name|CORE_ADDR
name|lhs
parameter_list|,
name|CORE_ADDR
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Floating point values. */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|struct
name|floatformat
modifier|*
name|default_float_format
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|struct
name|floatformat
modifier|*
name|default_double_format
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Helper function for targets that don't know how my arguments are    being passed */
end_comment

begin_function_decl
specifier|extern
name|int
name|frame_num_args_unknown
parameter_list|(
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The following DEPRECATED interfaces are for pre- multi-arch legacy    targets. */
end_comment

begin_comment
comment|/* DEPRECATED pre- multi-arch interface.  Explicitly set the dynamic    target-system-dependent parameters based on bfd_architecture and    machine.  This function is deprecated, use    set_gdbarch_from_arch_machine(). */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_architecture_from_arch_mach
parameter_list|(
name|enum
name|bfd_architecture
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DEPRECATED pre- multi-arch interface.  Notify the target dependent    backend of a change to the selected architecture. A zero return    status indicates that the target did not like the change. */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|target_architecture_hook
function_decl|)
parameter_list|(
specifier|const
name|struct
name|bfd_arch_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Default raw->sim register re-numbering - does nothing. */
end_comment

begin_function_decl
specifier|extern
name|int
name|default_register_sim_regno
parameter_list|(
name|int
name|reg_nr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Identity function on a CORE_ADDR.  Just returns its parameter.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|core_addr_identity
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* No-op conversion of reg to regnum. */
end_comment

begin_function_decl
specifier|extern
name|int
name|no_op_reg_to_regnum
parameter_list|(
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Default frame_args_address and frame_locals_address.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|default_frame_address
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Default prepare_to_procced. */
end_comment

begin_function_decl
specifier|extern
name|int
name|default_prepare_to_proceed
parameter_list|(
name|int
name|select_it
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|generic_prepare_to_proceed
parameter_list|(
name|int
name|select_it
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Versions of init_frame_pc().  Do nothing; do the default. */
end_comment

begin_function_decl
name|void
name|init_frame_pc_noop
parameter_list|(
name|int
name|fromleaf
parameter_list|,
name|struct
name|frame_info
modifier|*
name|prev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_frame_pc_default
parameter_list|(
name|int
name|fromleaf
parameter_list|,
name|struct
name|frame_info
modifier|*
name|prev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Do nothing version of elf_make_msymbol_special. */
end_comment

begin_function_decl
name|void
name|default_elf_make_msymbol_special
parameter_list|(
name|asymbol
modifier|*
name|sym
parameter_list|,
name|struct
name|minimal_symbol
modifier|*
name|msym
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Do nothing version of coff_make_msymbol_special. */
end_comment

begin_function_decl
name|void
name|default_coff_make_msymbol_special
parameter_list|(
name|int
name|val
parameter_list|,
name|struct
name|minimal_symbol
modifier|*
name|msym
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Version of cannot_fetch_register() / cannot_store_register() that    always fails. */
end_comment

begin_function_decl
name|int
name|cannot_register_not
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Legacy version of target_virtual_frame_pointer().  Assumes that    there is an FP_REGNUM and that it is the same, cooked or raw.  */
end_comment

begin_decl_stmt
specifier|extern
name|gdbarch_virtual_frame_pointer_ftype
name|legacy_virtual_frame_pointer
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|CORE_ADDR
name|generic_skip_trampoline_code
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|generic_in_solib_call_trampoline
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|generic_in_function_epilogue_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_print_float_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Assume all registers are the same size and a size identical to that    of the integer type.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|generic_register_raw_size
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Assume the virtual size of registers corresponds to the virtual type.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|generic_register_virtual_size
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize a ``struct info''.  Can't use memset(0) since some    default values are not zero.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|gdbarch_info_init
parameter_list|(
name|struct
name|gdbarch_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

