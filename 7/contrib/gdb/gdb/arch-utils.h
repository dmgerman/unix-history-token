begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Dynamic architecture support for GDB, the GNU debugger.     Copyright 1998, 1999, 2000, 2002, 2003 Free Software Foundation,    Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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

begin_struct_decl
struct_decl|struct
name|gdbarch
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|minimal_symbol
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|type
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|gdbarch_info
struct_decl|;
end_struct_decl

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
comment|/* Implementation of extract return value that grubs around in the    register cache.  */
end_comment

begin_decl_stmt
specifier|extern
name|gdbarch_extract_return_value_ftype
name|legacy_extract_return_value
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Implementation of store return value that grubs the register cache.  */
end_comment

begin_decl_stmt
specifier|extern
name|gdbarch_store_return_value_ftype
name|legacy_store_return_value
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* To return any structure or union type by value, store it at the    address passed as an invisible first argument to the function.  */
end_comment

begin_decl_stmt
specifier|extern
name|gdbarch_use_struct_convention_ftype
name|always_use_struct_convention
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
comment|/* Identity functions on a CORE_ADDR.  Just return the "addr".  */
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

begin_decl_stmt
specifier|extern
name|gdbarch_convert_from_func_ptr_addr_ftype
name|convert_from_func_ptr_addr_identity
decl_stmt|;
end_decl_stmt

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
comment|/* Versions of init_frame_pc().  Do nothing; do the default. */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|deprecated_init_frame_pc_default
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
comment|/* Legacy version of target_virtual_frame_pointer().  Assumes that    there is an DEPRECATED_FP_REGNUM and that it is the same, cooked or    raw.  */
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
name|CORE_ADDR
name|generic_skip_solib_resolver
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
name|generic_in_solib_return_trampoline
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

begin_comment
comment|/* Assume that the world is sane, a registers raw and virtual size    both match its type.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|generic_register_size
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Assume that the world is sane, the registers are all adjacent.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|generic_register_byte
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Prop up old targets that use various IN_SIGTRAMP() macros.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|legacy_pc_in_sigtramp
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

begin_comment
comment|/* The orginal register_convert*() functions were overloaded.  They    were used to both: convert between virtual and raw register formats    (something that is discouraged); and to convert a register to the    type of a corresponding variable.  These legacy functions preserve    that overloaded behavour in existing targets.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|legacy_convert_register_p
parameter_list|(
name|int
name|regnum
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|legacy_register_to_value
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|void
modifier|*
name|to
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|legacy_value_to_register
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|from
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|default_stabs_argument_has_addr
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For compatibility with older architectures, returns    (LEGACY_SIM_REGNO_IGNORE) when the register doesn't have a valid    name.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|legacy_register_sim_regno
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the selected byte order, or BFD_ENDIAN_UNKNOWN if no byte    order was explicitly selected.  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|bfd_endian
name|selected_byte_order
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the selected architecture's name, or NULL if no architecture    was explicitly selected.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|selected_architecture_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize a ``struct info''.  Can't use memset(0) since some    default values are not zero.  "fill" takes all available    information and fills in any unspecified fields.  */
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

begin_function_decl
specifier|extern
name|void
name|gdbarch_info_fill
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|gdbarch_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Similar to init, but this time fill in the blanks.  Information is    obtained from the specified architecture, global "set ..." options,    and explicitly initialized INFO fields.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|gdbarch_info_fill
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|gdbarch_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the architecture for ABFD.  If no suitable architecture    could be find, return NULL.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|gdbarch
modifier|*
name|gdbarch_from_bfd
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

