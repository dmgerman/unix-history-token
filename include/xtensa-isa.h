begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface definition for configurable Xtensa ISA support.    Copyright 2003 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XTENSA_LIBISA_H
end_ifndef

begin_define
define|#
directive|define
name|XTENSA_LIBISA_H
end_define

begin_comment
comment|/* Use the statically-linked version for the GNU tools.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_LIBISA
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
ifndef|#
directive|ifndef
name|uint32
define|#
directive|define
name|uint32
value|unsigned int
endif|#
directive|endif
comment|/* This file defines the interface to the Xtensa ISA library.  This library    contains most of the ISA-specific information for a particular Xtensa    processor.  For example, the set of valid instructions, their opcode    encodings and operand fields are all included here.  To support Xtensa's    configurability and user-defined instruction extensions (i.e., TIE), the    library is initialized by loading one or more dynamic libraries; only a    small set of interface code is present in the statically-linked portion    of the library.     This interface basically defines four abstract data types.     . an instruction buffer - for holding the raw instruction bits    . ISA info - information about the ISA as a whole    . opcode info - information about individual instructions    . operand info - information about specific instruction operands     It would be nice to implement these as classes in C++, but the library is    implemented in C to match the expectations of the GNU tools.    Instead, the interface defines a set of functions to access each data    type.  With the exception of the instruction buffer, the internal    representations of the data structures are hidden.  All accesses must be    made through the functions defined here.  */
typedef|typedef
name|void
modifier|*
name|xtensa_isa
typedef|;
typedef|typedef
name|void
modifier|*
name|xtensa_operand
typedef|;
comment|/* Opcodes are represented here using sequential integers beginning with 0.    The specific value used for a particular opcode is only fixed for a    particular instantiation of an xtensa_isa structure, so these values    should only be used internally.  */
typedef|typedef
name|int
name|xtensa_opcode
typedef|;
comment|/* Define a unique value for undefined opcodes ("static const int" doesn't    seem to work for this because EGCS 1.0.3 on i686-Linux without -O won't    allow it to be used as an initializer).  */
define|#
directive|define
name|XTENSA_UNDEFINED
value|-1
typedef|typedef
name|int
name|libisa_module_specifier
typedef|;
specifier|extern
name|xtensa_isa
name|xtensa_isa_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Instruction buffers.  */
typedef|typedef
name|uint32
name|xtensa_insnbuf_word
typedef|;
typedef|typedef
name|xtensa_insnbuf_word
modifier|*
name|xtensa_insnbuf
typedef|;
comment|/* Get the size in words of the xtensa_insnbuf array.  */
specifier|extern
name|int
name|xtensa_insnbuf_size
parameter_list|(
name|xtensa_isa
parameter_list|)
function_decl|;
comment|/* Allocate (with malloc) an xtensa_insnbuf of the right size.  */
specifier|extern
name|xtensa_insnbuf
name|xtensa_insnbuf_alloc
parameter_list|(
name|xtensa_isa
parameter_list|)
function_decl|;
comment|/* Release (with free) an xtensa_insnbuf of the right size.  */
specifier|extern
name|void
name|xtensa_insnbuf_free
parameter_list|(
name|xtensa_insnbuf
parameter_list|)
function_decl|;
comment|/* Inward and outward conversion from memory images (byte streams) to our    internal instruction representation.  */
specifier|extern
name|void
name|xtensa_insnbuf_to_chars
parameter_list|(
name|xtensa_isa
parameter_list|,
specifier|const
name|xtensa_insnbuf
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|xtensa_insnbuf_from_chars
parameter_list|(
name|xtensa_isa
parameter_list|,
name|xtensa_insnbuf
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* ISA information.  */
comment|/* Load the ISA information from a shared library.  If successful, this returns    a value which identifies the ISA for use in subsequent calls to the ISA    library; otherwise, it returns NULL.  Multiple ISAs can be loaded to support    heterogeneous multiprocessor systems.  */
specifier|extern
name|xtensa_isa
name|xtensa_load_isa
parameter_list|(
name|libisa_module_specifier
parameter_list|)
function_decl|;
comment|/* Extend an existing set of ISA information by loading an additional shared    library of ISA information.  This is primarily intended for loading TIE    extensions.  If successful, the return value is non-zero.  */
specifier|extern
name|int
name|xtensa_extend_isa
parameter_list|(
name|xtensa_isa
parameter_list|,
name|libisa_module_specifier
parameter_list|)
function_decl|;
comment|/* The default ISA.  This variable is set automatically to the ISA most    recently loaded and is provided as a convenience.  An exception is the GNU    opcodes library, where there is a fixed interface that does not allow    passing the ISA as a parameter and the ISA must be taken from this global    variable.  (Note: Since this variable is just a convenience, it is not    exported when libisa is built as a DLL, due to the hassle of dealing with    declspecs.)  */
specifier|extern
name|xtensa_isa
name|xtensa_default_isa
decl_stmt|;
comment|/* Deallocate an xtensa_isa structure.  */
specifier|extern
name|void
name|xtensa_isa_free
parameter_list|(
name|xtensa_isa
parameter_list|)
function_decl|;
comment|/* Get the maximum instruction size in bytes.  */
specifier|extern
name|int
name|xtensa_insn_maxlength
parameter_list|(
name|xtensa_isa
parameter_list|)
function_decl|;
comment|/* Get the total number of opcodes for this processor.  */
specifier|extern
name|int
name|xtensa_num_opcodes
parameter_list|(
name|xtensa_isa
parameter_list|)
function_decl|;
comment|/* Translate a mnemonic name to an opcode.  Returns XTENSA_UNDEFINED if    the name is not a valid opcode mnemonic.  */
specifier|extern
name|xtensa_opcode
name|xtensa_opcode_lookup
parameter_list|(
name|xtensa_isa
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* Decode a binary instruction buffer.  Returns the opcode or    XTENSA_UNDEFINED if the instruction is illegal.  */
specifier|extern
name|xtensa_opcode
name|xtensa_decode_insn
parameter_list|(
name|xtensa_isa
parameter_list|,
specifier|const
name|xtensa_insnbuf
parameter_list|)
function_decl|;
comment|/* Opcode information.  */
comment|/* Set the opcode field(s) in a binary instruction buffer.  The operand    fields are set to zero.  */
specifier|extern
name|void
name|xtensa_encode_insn
parameter_list|(
name|xtensa_isa
parameter_list|,
name|xtensa_opcode
parameter_list|,
name|xtensa_insnbuf
parameter_list|)
function_decl|;
comment|/* Get the mnemonic name for an opcode.  */
specifier|extern
specifier|const
name|char
modifier|*
name|xtensa_opcode_name
parameter_list|(
name|xtensa_isa
parameter_list|,
name|xtensa_opcode
parameter_list|)
function_decl|;
comment|/* Find the length (in bytes) of an instruction.  */
specifier|extern
name|int
name|xtensa_insn_length
parameter_list|(
name|xtensa_isa
parameter_list|,
name|xtensa_opcode
parameter_list|)
function_decl|;
comment|/* Find the length of an instruction by looking only at the first byte.  */
specifier|extern
name|int
name|xtensa_insn_length_from_first_byte
parameter_list|(
name|xtensa_isa
parameter_list|,
name|char
parameter_list|)
function_decl|;
comment|/* Find the number of operands for an instruction.  */
specifier|extern
name|int
name|xtensa_num_operands
parameter_list|(
name|xtensa_isa
parameter_list|,
name|xtensa_opcode
parameter_list|)
function_decl|;
comment|/* Get the information about operand number "opnd" of a particular opcode.  */
specifier|extern
name|xtensa_operand
name|xtensa_get_operand
parameter_list|(
name|xtensa_isa
parameter_list|,
name|xtensa_opcode
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Operand information.  */
comment|/* Find the kind of operand.  There are three possibilities:    1) PC-relative immediates (e.g., "l", "L").  These can be identified with       the xtensa_operand_isPCRelative function.    2) non-PC-relative immediates ("i").    3) register-file short names (e.g., "a", "b", "m" and others defined       via TIE).  */
specifier|extern
name|char
modifier|*
name|xtensa_operand_kind
parameter_list|(
name|xtensa_operand
parameter_list|)
function_decl|;
comment|/* Check if an operand is an input ('<'), output ('>'), or inout ('=')    operand.  Note: The output operand of a conditional assignment    (e.g., movnez) appears here as an inout ('=') even if it is declared    in the TIE code as an output ('>'); this allows the compiler to    properly handle register allocation for conditional assignments.  */
specifier|extern
name|char
name|xtensa_operand_inout
parameter_list|(
name|xtensa_operand
parameter_list|)
function_decl|;
comment|/* Get and set the raw (encoded) value of the field for the specified    operand.  The "set" function does not check if the value fits in the    field; that is done by the "encode" function below.  */
specifier|extern
name|uint32
name|xtensa_operand_get_field
parameter_list|(
name|xtensa_operand
parameter_list|,
specifier|const
name|xtensa_insnbuf
parameter_list|)
function_decl|;
specifier|extern
name|void
name|xtensa_operand_set_field
parameter_list|(
name|xtensa_operand
parameter_list|,
name|xtensa_insnbuf
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
comment|/* Encode and decode operands.  The raw bits in the operand field    may be encoded in a variety of different ways.  These functions hide the    details of that encoding.  The encode function has a special return type    (xtensa_encode_result) to indicate success or the reason for failure; the    encoded value is returned through the argument pointer.  The decode function    has no possibility of failure and returns the decoded value.  */
typedef|typedef
enum|enum
block|{
name|xtensa_encode_result_ok
block|,
name|xtensa_encode_result_align
block|,
name|xtensa_encode_result_not_in_table
block|,
name|xtensa_encode_result_too_low
block|,
name|xtensa_encode_result_too_high
block|,
name|xtensa_encode_result_not_ok
block|,
name|xtensa_encode_result_max
init|=
name|xtensa_encode_result_not_ok
block|}
name|xtensa_encode_result
typedef|;
specifier|extern
name|xtensa_encode_result
name|xtensa_operand_encode
parameter_list|(
name|xtensa_operand
parameter_list|,
name|uint32
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|uint32
name|xtensa_operand_decode
parameter_list|(
name|xtensa_operand
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
comment|/* For PC-relative offset operands, the interpretation of the offset may vary    between opcodes, e.g., is it relative to the current PC or that of the next    instruction?  The following functions are defined to perform PC-relative    relocations and to undo them (as in the disassembler).  The first function    takes the desired address and the PC of the current instruction and returns    the unencoded value to be stored in the offset field.  The second function    takes the unencoded offset value and the current PC and returns the address.    Note that these functions do not replace the encode/decode functions; the    operands must be encoded/decoded separately.  */
specifier|extern
name|int
name|xtensa_operand_isPCRelative
parameter_list|(
name|xtensa_operand
parameter_list|)
function_decl|;
specifier|extern
name|uint32
name|xtensa_operand_do_reloc
parameter_list|(
name|xtensa_operand
parameter_list|,
name|uint32
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
specifier|extern
name|uint32
name|xtensa_operand_undo_reloc
parameter_list|(
name|xtensa_operand
parameter_list|,
name|uint32
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XTENSA_LIBISA_H */
end_comment

end_unit

