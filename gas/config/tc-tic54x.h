begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-tic54x.h -- Header file for tc-tic54x.c    Copyright 1999, 2000, 2001 Free Software Foundation, Inc.    Contributed by Timothy Wall (twall@alum.mit.edu)     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TC_TIC54X_H_
end_ifndef

begin_define
define|#
directive|define
name|_TC_TIC54X_H_
end_define

begin_comment
comment|/* select the proper coff format (see obj-coff.h) */
end_comment

begin_define
define|#
directive|define
name|TC_TIC54X
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|OCTETS_PER_BYTE_POWER
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_tic54x
end_define

begin_define
define|#
directive|define
name|BFD_ARCH
value|TARGET_ARCH
end_define

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
value|1
end_define

begin_define
define|#
directive|define
name|MAX_OPERANDS
value|4
end_define

begin_define
define|#
directive|define
name|PARALLEL_SEPARATOR
value|'|'
end_define

begin_define
define|#
directive|define
name|LABELS_WITHOUT_COLONS
value|1
end_define

begin_comment
comment|/* accept 0FFFFh, 1010b, etc.  */
end_comment

begin_define
define|#
directive|define
name|NUMBERS_WITH_SUFFIX
value|1
end_define

begin_comment
comment|/* $ is section program counter */
end_comment

begin_define
define|#
directive|define
name|DOLLAR_DOT
value|1
end_define

begin_comment
comment|/* accept parallel lines like        add #1,a  ||  ld #1, b        (may also be split across lines) */
end_comment

begin_define
define|#
directive|define
name|DOUBLEBAR_PARALLEL
value|1
end_define

begin_comment
comment|/* affects preprocessor */
end_comment

begin_define
define|#
directive|define
name|KEEP_WHITE_AROUND_COLON
value|1
end_define

begin_comment
comment|/* We need the extra field in the fixup struct to put the relocation in.  */
end_comment

begin_define
define|#
directive|define
name|NEED_FX_R_TYPE
end_define

begin_struct
struct|struct
name|bit_info
block|{
name|segT
name|seg
decl_stmt|;
define|#
directive|define
name|TYPE_SPACE
value|0
define|#
directive|define
name|TYPE_BES
value|1
define|#
directive|define
name|TYPE_FIELD
value|2
name|int
name|type
decl_stmt|;
name|symbolS
modifier|*
name|sym
decl_stmt|;
name|valueT
name|value
decl_stmt|;
name|char
modifier|*
name|where
decl_stmt|;
name|int
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* We sometimes need to keep track of bit offsets within words */
end_comment

begin_define
define|#
directive|define
name|TC_FRAG_TYPE
value|int
end_define

begin_define
define|#
directive|define
name|TC_FRAG_INIT
parameter_list|(
name|FRAGP
parameter_list|)
value|do {(FRAGP)->tc_frag_data = 0;}while (0)
end_define

begin_comment
comment|/* tell GAS whether the given token is indeed a code label */
end_comment

begin_define
define|#
directive|define
name|TC_START_LABEL_WITHOUT_COLON
parameter_list|(
name|c
parameter_list|,
name|ptr
parameter_list|)
value|tic54x_start_label(c,ptr)
end_define

begin_decl_stmt
specifier|extern
name|int
name|tic54x_start_label
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* custom handling for relocations in cons expressions */
end_comment

begin_define
define|#
directive|define
name|TC_CONS_FIX_NEW
parameter_list|(
name|FRAG
parameter_list|,
name|OFF
parameter_list|,
name|LEN
parameter_list|,
name|EXP
parameter_list|)
value|tic54x_cons_fix_new(FRAG,OFF,LEN,EXP)
end_define

begin_decl_stmt
specifier|extern
name|void
name|tic54x_cons_fix_new
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define md_number_to_chars as the appropriate standard big endian or    little endian function.  Mostly littleendian, but longwords and floats are    stored MS word first. */
end_comment

begin_define
define|#
directive|define
name|md_number_to_chars
value|tic54x_number_to_chars
end_define

begin_function_decl
specifier|extern
name|void
name|tic54x_number_to_chars
parameter_list|(
name|char
modifier|*
parameter_list|,
name|valueT
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_adjust_symtab
parameter_list|()
value|tic54x_adjust_symtab()
end_define

begin_function_decl
specifier|extern
name|void
name|tic54x_adjust_symtab
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_unrecognized_line
parameter_list|(
name|ch
parameter_list|)
value|tic54x_unrecognized_line(ch)
end_define

begin_function_decl
specifier|extern
name|int
name|tic54x_unrecognized_line
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_parse_name
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|,
name|c
parameter_list|)
value|tic54x_parse_name(s,e)
end_define

begin_function_decl
specifier|extern
name|int
name|tic54x_parse_name
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|expressionS
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_undefined_symbol
parameter_list|(
name|s
parameter_list|)
value|tic54x_undefined_symbol(s)
end_define

begin_function_decl
specifier|extern
name|symbolS
modifier|*
name|tic54x_undefined_symbol
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_macro_start
parameter_list|()
value|tic54x_macro_start()
end_define

begin_function_decl
specifier|extern
name|void
name|tic54x_macro_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_macro_end
parameter_list|()
value|tic54x_macro_end()
end_define

begin_function_decl
specifier|extern
name|void
name|tic54x_macro_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_macro_info
parameter_list|(
name|args
parameter_list|)
value|tic54x_macro_info(args)
end_define

begin_decl_stmt
specifier|extern
name|void
name|tic54x_macro_info
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
name|macro
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_frob_label
parameter_list|(
name|sym
parameter_list|)
value|tic54x_define_label (sym)
end_define

begin_decl_stmt
specifier|extern
name|void
name|tic54x_define_label
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_start_line_hook
parameter_list|()
value|tic54x_start_line_hook()
end_define

begin_function_decl
specifier|extern
name|void
name|tic54x_start_line_hook
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_estimate_size_before_relax
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|)
define|\
value|tic54x_estimate_size_before_relax(f,s)
end_define

begin_function_decl
specifier|extern
name|int
name|tic54x_estimate_size_before_relax
parameter_list|(
name|fragS
modifier|*
parameter_list|,
name|segT
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_relax_frag
parameter_list|(
name|seg
parameter_list|,
name|f
parameter_list|,
name|s
parameter_list|)
value|tic54x_relax_frag(f,s)
end_define

begin_function_decl
specifier|extern
name|int
name|tic54x_relax_frag
parameter_list|(
name|fragS
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_convert_frag
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
value|tic54x_convert_frag(b,s,f)
end_define

begin_function_decl
specifier|extern
name|void
name|tic54x_convert_frag
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|segT
parameter_list|,
name|fragS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Other things we don't support...  */
end_comment

begin_comment
comment|/* Define away the call to md_operand in the expression parsing code.    This is called whenever the expression parser can't parse the input    and gives the assembler backend a chance to deal with it instead.  */
end_comment

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|X
parameter_list|)
end_define

begin_comment
comment|/* spruce up the listing output */
end_comment

begin_define
define|#
directive|define
name|LISTING_WORD_SIZE
value|2
end_define

begin_function_decl
specifier|extern
name|void
name|tic54x_global
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

