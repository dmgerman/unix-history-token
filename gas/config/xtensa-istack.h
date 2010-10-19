begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for stacks of tokenized Xtensa instructions.    Copyright (C) 2003, 2004 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XTENSA_ISTACK_H
end_ifndef

begin_define
define|#
directive|define
name|XTENSA_ISTACK_H
end_define

begin_include
include|#
directive|include
file|"xtensa-isa.h"
end_include

begin_define
define|#
directive|define
name|MAX_ISTACK
value|12
end_define

begin_define
define|#
directive|define
name|MAX_INSN_ARGS
value|10
end_define

begin_enum
enum|enum
name|itype_enum
block|{
name|ITYPE_INSN
block|,
name|ITYPE_LITERAL
block|,
name|ITYPE_LABEL
block|}
enum|;
end_enum

begin_comment
comment|/* Literals have 1 token and no opcode.    Labels have 1 token and no opcode.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tinsn_struct
block|{
name|enum
name|itype_enum
name|insn_type
decl_stmt|;
name|xtensa_opcode
name|opcode
decl_stmt|;
comment|/* Literals have an invalid opcode.  */
name|bfd_boolean
name|is_specific_opcode
decl_stmt|;
name|bfd_boolean
name|keep_wide
decl_stmt|;
name|int
name|ntok
decl_stmt|;
name|expressionS
name|tok
index|[
name|MAX_INSN_ARGS
index|]
decl_stmt|;
name|unsigned
name|linenum
decl_stmt|;
name|struct
name|fixP
modifier|*
name|fixup
decl_stmt|;
comment|/* Filled out by relaxation_requirements:  */
name|enum
name|xtensa_relax_statesE
name|subtype
decl_stmt|;
name|int
name|literal_space
decl_stmt|;
comment|/* Filled out by vinsn_to_insnbuf:  */
name|symbolS
modifier|*
name|symbol
decl_stmt|;
name|offsetT
name|offset
decl_stmt|;
name|fragS
modifier|*
name|literal_frag
decl_stmt|;
block|}
name|TInsn
typedef|;
end_typedef

begin_comment
comment|/* tinsn_stack:  This is a stack of instructions to  be placed.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tinsn_stack
block|{
name|int
name|ninsn
decl_stmt|;
name|TInsn
name|insn
index|[
name|MAX_ISTACK
index|]
decl_stmt|;
block|}
name|IStack
typedef|;
end_typedef

begin_function_decl
name|void
name|istack_init
parameter_list|(
name|IStack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|istack_empty
parameter_list|(
name|IStack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|istack_full
parameter_list|(
name|IStack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TInsn
modifier|*
name|istack_top
parameter_list|(
name|IStack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|istack_push
parameter_list|(
name|IStack
modifier|*
parameter_list|,
name|TInsn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TInsn
modifier|*
name|istack_push_space
parameter_list|(
name|IStack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|istack_pop
parameter_list|(
name|IStack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* TInsn utilities.  */
end_comment

begin_function_decl
name|void
name|tinsn_init
parameter_list|(
name|TInsn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|expressionS
modifier|*
name|tinsn_get_tok
parameter_list|(
name|TInsn
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* vliw_insn: bundles of TInsns.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vliw_insn
block|{
name|xtensa_format
name|format
decl_stmt|;
name|int
name|num_slots
decl_stmt|;
name|unsigned
name|int
name|inside_bundle
decl_stmt|;
name|TInsn
name|slots
index|[
name|MAX_SLOTS
index|]
decl_stmt|;
name|xtensa_insnbuf
name|insnbuf
decl_stmt|;
name|xtensa_insnbuf
name|slotbuf
index|[
name|MAX_SLOTS
index|]
decl_stmt|;
block|}
name|vliw_insn
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !XTENSA_ISTACK_H */
end_comment

end_unit

