begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Internal definitions for configurable Xtensa ISA support.    Copyright 2003, 2004, 2005 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XTENSA_ISA_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|XTENSA_ISA_INTERNAL_H
end_define

begin_comment
comment|/* Flags.  */
end_comment

begin_define
define|#
directive|define
name|XTENSA_OPERAND_IS_REGISTER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|XTENSA_OPERAND_IS_PCRELATIVE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|XTENSA_OPERAND_IS_INVISIBLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|XTENSA_OPERAND_IS_UNKNOWN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|XTENSA_OPCODE_IS_BRANCH
value|0x00000001
end_define

begin_define
define|#
directive|define
name|XTENSA_OPCODE_IS_JUMP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|XTENSA_OPCODE_IS_LOOP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|XTENSA_OPCODE_IS_CALL
value|0x00000008
end_define

begin_define
define|#
directive|define
name|XTENSA_STATE_IS_EXPORTED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|XTENSA_INTERFACE_HAS_SIDE_EFFECT
value|0x00000001
end_define

begin_comment
comment|/* Function pointer typedefs */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xtensa_format_encode_fn
function_decl|)
parameter_list|(
name|xtensa_insnbuf
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xtensa_get_slot_fn
function_decl|)
parameter_list|(
specifier|const
name|xtensa_insnbuf
parameter_list|,
name|xtensa_insnbuf
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xtensa_set_slot_fn
function_decl|)
parameter_list|(
name|xtensa_insnbuf
parameter_list|,
specifier|const
name|xtensa_insnbuf
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xtensa_opcode_decode_fn
function_decl|)
parameter_list|(
specifier|const
name|xtensa_insnbuf
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|uint32
function_decl|(
modifier|*
name|xtensa_get_field_fn
function_decl|)
parameter_list|(
specifier|const
name|xtensa_insnbuf
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xtensa_set_field_fn
function_decl|)
parameter_list|(
name|xtensa_insnbuf
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xtensa_immed_decode_fn
function_decl|)
parameter_list|(
name|uint32
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xtensa_immed_encode_fn
function_decl|)
parameter_list|(
name|uint32
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xtensa_do_reloc_fn
function_decl|)
parameter_list|(
name|uint32
modifier|*
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xtensa_undo_reloc_fn
function_decl|)
parameter_list|(
name|uint32
modifier|*
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xtensa_opcode_encode_fn
function_decl|)
parameter_list|(
name|xtensa_insnbuf
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xtensa_format_decode_fn
function_decl|)
parameter_list|(
specifier|const
name|xtensa_insnbuf
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xtensa_length_decode_fn
function_decl|)
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_format_internal_struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Instruction format name.  */
name|int
name|length
decl_stmt|;
comment|/* Instruction length in bytes.  */
name|xtensa_format_encode_fn
name|encode_fn
decl_stmt|;
name|int
name|num_slots
decl_stmt|;
name|int
modifier|*
name|slot_id
decl_stmt|;
comment|/* Array[num_slots] of slot IDs.  */
block|}
name|xtensa_format_internal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_slot_internal_struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Not necessarily unique.  */
specifier|const
name|char
modifier|*
name|format
decl_stmt|;
name|int
name|position
decl_stmt|;
name|xtensa_get_slot_fn
name|get_fn
decl_stmt|;
name|xtensa_set_slot_fn
name|set_fn
decl_stmt|;
name|xtensa_get_field_fn
modifier|*
name|get_field_fns
decl_stmt|;
comment|/* Array[field_id].  */
name|xtensa_set_field_fn
modifier|*
name|set_field_fns
decl_stmt|;
comment|/* Array[field_id].  */
name|xtensa_opcode_decode_fn
name|opcode_decode_fn
decl_stmt|;
specifier|const
name|char
modifier|*
name|nop_name
decl_stmt|;
block|}
name|xtensa_slot_internal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_operand_internal_struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|field_id
decl_stmt|;
name|xtensa_regfile
name|regfile
decl_stmt|;
comment|/* Register file.  */
name|int
name|num_regs
decl_stmt|;
comment|/* Usually 1; 2 for reg pairs, etc.  */
name|uint32
name|flags
decl_stmt|;
comment|/* See XTENSA_OPERAND_* flags.  */
name|xtensa_immed_encode_fn
name|encode
decl_stmt|;
comment|/* Encode the operand value.  */
name|xtensa_immed_decode_fn
name|decode
decl_stmt|;
comment|/* Decode the value from the field.  */
name|xtensa_do_reloc_fn
name|do_reloc
decl_stmt|;
comment|/* Perform a PC-relative reloc.  */
name|xtensa_undo_reloc_fn
name|undo_reloc
decl_stmt|;
comment|/* Undo a PC-relative relocation.  */
block|}
name|xtensa_operand_internal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_arg_internal_struct
block|{
union|union
block|{
name|int
name|operand_id
decl_stmt|;
comment|/* For normal operands.  */
name|xtensa_state
name|state
decl_stmt|;
comment|/* For stateOperands.  */
block|}
name|u
union|;
name|char
name|inout
decl_stmt|;
comment|/* Direction: 'i', 'o', or 'm'.  */
block|}
name|xtensa_arg_internal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_iclass_internal_struct
block|{
name|int
name|num_operands
decl_stmt|;
comment|/* Size of "operands" array.  */
name|xtensa_arg_internal
modifier|*
name|operands
decl_stmt|;
comment|/* Array[num_operands].  */
name|int
name|num_stateOperands
decl_stmt|;
comment|/* Size of "stateOperands" array.  */
name|xtensa_arg_internal
modifier|*
name|stateOperands
decl_stmt|;
comment|/* Array[num_stateOperands].  */
name|int
name|num_interfaceOperands
decl_stmt|;
comment|/* Size of "interfaceOperands".  */
name|xtensa_interface
modifier|*
name|interfaceOperands
decl_stmt|;
comment|/* Array[num_interfaceOperands].  */
block|}
name|xtensa_iclass_internal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_opcode_internal_struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Opcode mnemonic.  */
name|int
name|iclass_id
decl_stmt|;
comment|/* Iclass for this opcode.  */
name|uint32
name|flags
decl_stmt|;
comment|/* See XTENSA_OPCODE_* flags.  */
name|xtensa_opcode_encode_fn
modifier|*
name|encode_fns
decl_stmt|;
comment|/* Array[slot_id].  */
name|int
name|num_funcUnit_uses
decl_stmt|;
comment|/* Number of funcUnit_use entries.  */
name|xtensa_funcUnit_use
modifier|*
name|funcUnit_uses
decl_stmt|;
comment|/* Array[num_funcUnit_uses].  */
block|}
name|xtensa_opcode_internal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_regfile_internal_struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Full name of the regfile.  */
specifier|const
name|char
modifier|*
name|shortname
decl_stmt|;
comment|/* Abbreviated name.  */
name|xtensa_regfile
name|parent
decl_stmt|;
comment|/* View parent (or identity).  */
name|int
name|num_bits
decl_stmt|;
comment|/* Width of the registers.  */
name|int
name|num_entries
decl_stmt|;
comment|/* Number of registers.  */
block|}
name|xtensa_regfile_internal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_interface_internal_struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Interface name.  */
name|int
name|num_bits
decl_stmt|;
comment|/* Width of the interface.  */
name|uint32
name|flags
decl_stmt|;
comment|/* See XTENSA_INTERFACE_* flags.  */
name|int
name|class_id
decl_stmt|;
comment|/* Class of related interfaces.  */
name|char
name|inout
decl_stmt|;
comment|/* "i" or "o".  */
block|}
name|xtensa_interface_internal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_funcUnit_internal_struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Functional unit name.  */
name|int
name|num_copies
decl_stmt|;
comment|/* Number of instances.  */
block|}
name|xtensa_funcUnit_internal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_state_internal_struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* State name.  */
name|int
name|num_bits
decl_stmt|;
comment|/* Number of state bits.  */
name|uint32
name|flags
decl_stmt|;
comment|/* See XTENSA_STATE_* flags.  */
block|}
name|xtensa_state_internal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_sysreg_internal_struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Register name.  */
name|int
name|number
decl_stmt|;
comment|/* Register number.  */
name|int
name|is_user
decl_stmt|;
comment|/* Non-zero if a "user register".  */
block|}
name|xtensa_sysreg_internal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_lookup_entry_struct
block|{
specifier|const
name|char
modifier|*
name|key
decl_stmt|;
union|union
block|{
name|xtensa_opcode
name|opcode
decl_stmt|;
comment|/* Internal opcode number.  */
name|xtensa_sysreg
name|sysreg
decl_stmt|;
comment|/* Internal sysreg number.  */
name|xtensa_state
name|state
decl_stmt|;
comment|/* Internal state number.  */
name|xtensa_interface
name|intf
decl_stmt|;
comment|/* Internal interface number.  */
name|xtensa_funcUnit
name|fun
decl_stmt|;
comment|/* Internal funcUnit number.  */
block|}
name|u
union|;
block|}
name|xtensa_lookup_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_isa_internal_struct
block|{
name|int
name|is_big_endian
decl_stmt|;
comment|/* Endianness.  */
name|int
name|insn_size
decl_stmt|;
comment|/* Maximum length in bytes.  */
name|int
name|insnbuf_size
decl_stmt|;
comment|/* Number of insnbuf_words.  */
name|int
name|num_formats
decl_stmt|;
name|xtensa_format_internal
modifier|*
name|formats
decl_stmt|;
name|xtensa_format_decode_fn
name|format_decode_fn
decl_stmt|;
name|xtensa_length_decode_fn
name|length_decode_fn
decl_stmt|;
name|int
name|num_slots
decl_stmt|;
name|xtensa_slot_internal
modifier|*
name|slots
decl_stmt|;
name|int
name|num_fields
decl_stmt|;
name|int
name|num_operands
decl_stmt|;
name|xtensa_operand_internal
modifier|*
name|operands
decl_stmt|;
name|int
name|num_iclasses
decl_stmt|;
name|xtensa_iclass_internal
modifier|*
name|iclasses
decl_stmt|;
name|int
name|num_opcodes
decl_stmt|;
name|xtensa_opcode_internal
modifier|*
name|opcodes
decl_stmt|;
name|xtensa_lookup_entry
modifier|*
name|opname_lookup_table
decl_stmt|;
name|int
name|num_regfiles
decl_stmt|;
name|xtensa_regfile_internal
modifier|*
name|regfiles
decl_stmt|;
name|int
name|num_states
decl_stmt|;
name|xtensa_state_internal
modifier|*
name|states
decl_stmt|;
name|xtensa_lookup_entry
modifier|*
name|state_lookup_table
decl_stmt|;
name|int
name|num_sysregs
decl_stmt|;
name|xtensa_sysreg_internal
modifier|*
name|sysregs
decl_stmt|;
name|xtensa_lookup_entry
modifier|*
name|sysreg_lookup_table
decl_stmt|;
comment|/* The current Xtensa ISA only supports 256 of each kind of sysreg so      we can get away with implementing lookups with tables indexed by      the register numbers.  If we ever allow larger sysreg numbers, this      may have to be reimplemented.  The first entry in the following      arrays corresponds to "special" registers and the second to "user"      registers.  */
name|int
name|max_sysreg_num
index|[
literal|2
index|]
decl_stmt|;
name|xtensa_sysreg
modifier|*
name|sysreg_table
index|[
literal|2
index|]
decl_stmt|;
name|int
name|num_interfaces
decl_stmt|;
name|xtensa_interface_internal
modifier|*
name|interfaces
decl_stmt|;
name|xtensa_lookup_entry
modifier|*
name|interface_lookup_table
decl_stmt|;
name|int
name|num_funcUnits
decl_stmt|;
name|xtensa_funcUnit_internal
modifier|*
name|funcUnits
decl_stmt|;
name|xtensa_lookup_entry
modifier|*
name|funcUnit_lookup_table
decl_stmt|;
block|}
name|xtensa_isa_internal
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|xtensa_isa_name_compare
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|xtensa_isa_status
name|xtisa_errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|xtisa_error_msg
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !XTENSA_ISA_INTERNAL_H */
end_comment

end_unit

