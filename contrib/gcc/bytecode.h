begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Bytecode definitions for GNU C-compiler.    Copyright (C) 1993, 1994 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|output_bytecode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|stack_depth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|max_stack_depth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Emit DI constant according to target machine word ordering */
end_comment

begin_define
define|#
directive|define
name|bc_emit_bytecode_DI_const
parameter_list|(
name|CST
parameter_list|)
define|\
value|{ int opcode;							\   opcode = (WORDS_BIG_ENDIAN					\ 	    ? TREE_INT_CST_HIGH (CST) 				\ 	    : TREE_INT_CST_LOW (CST));				\   bc_emit_bytecode_const ((char *)&opcode, sizeof opcode); 	\   opcode = (WORDS_BIG_ENDIAN					\ 	    ? TREE_INT_CST_LOW (CST) 				\ 	    : TREE_INT_CST_HIGH (CST));				\   bc_emit_bytecode_const ((char *)&opcode, sizeof opcode);	\ }
end_define

begin_function_decl
specifier|extern
name|void
name|bc_expand_expr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_output_data_constructor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_store_field
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_load_bit_field
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_store_bit_field
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_push_offset_and_size
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_init_mode_to_code_map
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* These are just stubs, so the compiler will compile for targets    that aren't yet supported by the bytecode generator. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_SUPPORTS_BYTECODE
end_ifndef

begin_define
define|#
directive|define
name|MACHINE_SEG_ALIGN
value|1
end_define

begin_define
define|#
directive|define
name|INT_ALIGN
value|1
end_define

begin_define
define|#
directive|define
name|PTR_ALIGN
value|1
end_define

begin_define
define|#
directive|define
name|NAMES_HAVE_UNDERSCORES
end_define

begin_define
define|#
directive|define
name|BC_NOP
value|(0)
end_define

begin_define
define|#
directive|define
name|BC_GLOBALIZE_LABEL
parameter_list|(
name|FP
parameter_list|,
name|NAME
parameter_list|)
value|BC_NOP
end_define

begin_define
define|#
directive|define
name|BC_OUTPUT_COMMON
parameter_list|(
name|FP
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
value|BC_NOP
end_define

begin_define
define|#
directive|define
name|BC_OUTPUT_LOCAL
parameter_list|(
name|FP
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
value|BC_NOP
end_define

begin_define
define|#
directive|define
name|BC_OUTPUT_ALIGN
parameter_list|(
name|FP
parameter_list|,
name|ALIGN
parameter_list|)
value|BC_NOP
end_define

begin_define
define|#
directive|define
name|BC_OUTPUT_LABEL
parameter_list|(
name|FP
parameter_list|,
name|NAME
parameter_list|)
value|BC_NOP
end_define

begin_define
define|#
directive|define
name|BC_OUTPUT_SKIP
parameter_list|(
name|FP
parameter_list|,
name|SIZE
parameter_list|)
value|BC_NOP
end_define

begin_define
define|#
directive|define
name|BC_OUTPUT_LABELREF
parameter_list|(
name|FP
parameter_list|,
name|NAME
parameter_list|)
value|BC_NOP
end_define

begin_define
define|#
directive|define
name|BC_OUTPUT_FLOAT
parameter_list|(
name|FP
parameter_list|,
name|VAL
parameter_list|)
value|BC_NOP
end_define

begin_define
define|#
directive|define
name|BC_OUTPUT_DOUBLE
parameter_list|(
name|FP
parameter_list|,
name|VAL
parameter_list|)
value|BC_NOP
end_define

begin_define
define|#
directive|define
name|BC_OUTPUT_BYTE
parameter_list|(
name|FP
parameter_list|,
name|VAL
parameter_list|)
value|BC_NOP
end_define

begin_define
define|#
directive|define
name|BC_OUTPUT_FILE
value|ASM_OUTPUT_FILE
end_define

begin_define
define|#
directive|define
name|BC_OUTPUT_ASCII
value|ASM_OUTPUT_ASCII
end_define

begin_define
define|#
directive|define
name|BC_OUTPUT_IDENT
value|ASM_OUTPUT_IDENT
end_define

begin_define
define|#
directive|define
name|BCXSTR
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->bc_label)
end_define

begin_define
define|#
directive|define
name|BC_WRITE_FILE
parameter_list|(
name|FP
parameter_list|)
value|BC_NOP
end_define

begin_define
define|#
directive|define
name|BC_WRITE_SEGSYM
parameter_list|(
name|SEGSYM
parameter_list|,
name|FP
parameter_list|)
value|BC_NOP
end_define

begin_define
define|#
directive|define
name|BC_WRITE_RELOC_ENTRY
parameter_list|(
name|SEGRELOC
parameter_list|,
name|FP
parameter_list|,
name|OFFSET
parameter_list|)
value|BC_NOP
end_define

begin_define
define|#
directive|define
name|BC_START_BYTECODE_LINE
parameter_list|(
name|FP
parameter_list|)
value|BC_NOP
end_define

begin_define
define|#
directive|define
name|BC_WRITE_BYTECODE
parameter_list|(
name|SEP
parameter_list|,
name|VAL
parameter_list|,
name|FP
parameter_list|)
value|BC_NOP
end_define

begin_define
define|#
directive|define
name|BC_WRITE_RTL
parameter_list|(
name|R
parameter_list|,
name|FP
parameter_list|)
value|BC_NOP
end_define

begin_define
define|#
directive|define
name|BC_EMIT_TRAMPOLINE
parameter_list|(
name|TRAMPSEG
parameter_list|,
name|CALLINFO
parameter_list|)
value|BC_NOP
end_define

begin_define
define|#
directive|define
name|VALIDATE_STACK
value|BC_NOP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !TARGET_SUPPORTS_BYTECODE */
end_comment

end_unit

