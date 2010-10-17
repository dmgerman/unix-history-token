begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Internal definitions for configurable Xtensa ISA support.    Copyright 2003 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Use the statically-linked version for the GNU tools.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_LIBISA
value|1
end_define

begin_define
define|#
directive|define
name|ISA_INTERFACE_VERSION
value|3
end_define

begin_struct
struct|struct
name|config_struct
block|{
name|char
modifier|*
name|param_name
decl_stmt|;
name|char
modifier|*
name|param_value
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Encode/decode function types for immediate operands.  */
end_comment

begin_typedef
typedef|typedef
name|uint32
function_decl|(
modifier|*
name|xtensa_immed_decode_fn
function_decl|)
parameter_list|(
name|uint32
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|xtensa_encode_result
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

begin_comment
comment|/* Field accessor function types.  */
end_comment

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

begin_comment
comment|/* PC-relative relocation function types.  */
end_comment

begin_typedef
typedef|typedef
name|uint32
function_decl|(
modifier|*
name|xtensa_do_reloc_fn
function_decl|)
parameter_list|(
name|uint32
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|uint32
function_decl|(
modifier|*
name|xtensa_undo_reloc_fn
function_decl|)
parameter_list|(
name|uint32
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Instruction decode function type.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xtensa_insn_decode_fn
function_decl|)
parameter_list|(
specifier|const
name|xtensa_insnbuf
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Instruction encoding template function type (each of these functions    returns a constant template; they exist only to make it easier for the    TIE compiler to generate endian-independent DLLs).  */
end_comment

begin_typedef
typedef|typedef
name|xtensa_insnbuf
function_decl|(
modifier|*
name|xtensa_encoding_template_fn
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_operand_internal_struct
block|{
name|char
modifier|*
name|operand_kind
decl_stmt|;
comment|/* e.g., "a", "f", "i", "l"....  */
name|char
name|inout
decl_stmt|;
comment|/* '<', '>', or '='.  */
name|char
name|isPCRelative
decl_stmt|;
comment|/* Is this a PC-relative offset?  */
name|xtensa_get_field_fn
name|get_field
decl_stmt|;
comment|/* Get encoded value of the field.  */
name|xtensa_set_field_fn
name|set_field
decl_stmt|;
comment|/* Set field with an encoded value.  */
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
comment|/* Perform a PC-relative relocation.  */
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
name|xtensa_iclass_internal_struct
block|{
name|int
name|num_operands
decl_stmt|;
comment|/* Size of "operands" array.  */
name|xtensa_operand_internal
modifier|*
modifier|*
name|operands
decl_stmt|;
comment|/* Array of operand structures.  */
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
name|length
decl_stmt|;
comment|/* Length in bytes of the insn.  */
name|xtensa_encoding_template_fn
name|template
decl_stmt|;
comment|/* Fn returning encoding template.  */
name|xtensa_iclass_internal
modifier|*
name|iclass
decl_stmt|;
comment|/* Iclass for this opcode.  */
block|}
name|xtensa_opcode_internal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|opname_lookup_entry_struct
block|{
specifier|const
name|char
modifier|*
name|key
decl_stmt|;
comment|/* Opcode mnemonic.  */
name|xtensa_opcode
name|opcode
decl_stmt|;
comment|/* Internal opcode number.  */
block|}
name|opname_lookup_entry
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
name|num_opcodes
decl_stmt|;
comment|/* Total number for all modules.  */
name|xtensa_opcode_internal
modifier|*
modifier|*
name|opcode_table
decl_stmt|;
comment|/* Indexed by internal opcode #.  */
name|int
name|num_modules
decl_stmt|;
comment|/* Number of modules (DLLs) loaded.  */
name|int
modifier|*
name|module_opcode_base
decl_stmt|;
comment|/* Starting opcode # for each module.  */
name|xtensa_insn_decode_fn
modifier|*
name|module_decode_fn
decl_stmt|;
comment|/* Decode fn for each module.  */
name|opname_lookup_entry
modifier|*
name|opname_lookup_table
decl_stmt|;
comment|/* Lookup table for each module.  */
name|struct
name|config_struct
modifier|*
name|config
decl_stmt|;
comment|/* Table of configuration parameters.  */
name|int
name|has_density
decl_stmt|;
comment|/* Is density option available?  */
block|}
name|xtensa_isa_internal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_isa_module_struct
block|{
name|int
function_decl|(
modifier|*
name|get_num_opcodes_fn
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|xtensa_opcode_internal
modifier|*
modifier|*
function_decl|(
modifier|*
name|get_opcodes_fn
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|decode_insn_fn
function_decl|)
parameter_list|(
specifier|const
name|xtensa_insnbuf
parameter_list|)
function_decl|;
name|struct
name|config_struct
modifier|*
function_decl|(
modifier|*
name|get_config_table_fn
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
name|xtensa_isa_module
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|xtensa_isa_module
name|xtensa_isa_modules
index|[]
decl_stmt|;
end_decl_stmt

end_unit

