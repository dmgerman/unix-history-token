begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-hppa.h -- Header file for the PA    Copyright 1989, 1993, 1994, 1995, 1997, 1998, 1999, 2000, 2001, 2002,    2003 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 1, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_comment
comment|/* HP PA-RISC support was contributed by the Center for Software Science    at the University of Utah.  */
end_comment

begin_comment
comment|/* Please refrain from exposing the world to the internals of tc-hppa.c    when this file is included.  This means only declaring exported functions,    (please PARAMize them!) not exporting structures and data items which    are used solely within tc-hppa.c, etc.     Also refrain from adding any more object file dependent code, there is    already far too much object file format dependent code in this file.    In theory this file should contain only exported functions, structures    and data declarations common to all PA assemblers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TC_HPPA_H
end_ifndef

begin_define
define|#
directive|define
name|_TC_HPPA_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TC_HPPA
end_ifndef

begin_define
define|#
directive|define
name|TC_HPPA
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_hppa
end_define

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_if
if|#
directive|if
name|TARGET_ARCH_SIZE
operator|==
literal|64
end_if

begin_include
include|#
directive|include
file|"bfd/elf64-hppa.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TE_LINUX
argument_list|)
operator|||
name|defined
argument_list|(
name|TE_NetBSD
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf64-hppa-linux"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf64-hppa"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* TARGET_ARCH_SIZE == 32 */
end_comment

begin_include
include|#
directive|include
file|"bfd/elf32-hppa.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TE_LINUX
argument_list|)
operator|||
name|defined
argument_list|(
name|TE_NetBSD
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-hppa-linux"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-hppa"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_SOM
end_ifdef

begin_include
include|#
directive|include
file|"bfd/som.h"
end_include

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"som"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TE_LINUX
argument_list|)
operator|||
name|defined
argument_list|(
name|TE_NetBSD
argument_list|)
end_if

begin_comment
comment|/* Define to compile in an extra assembler option, -c, which enables a    warning (once per file) when a comment is encountered.    The hppa comment char is a `;' which tends to occur in random C asm    statements.  A semicolon is a line separator for most assemblers.    It's hard to find these lurking semicolons.  Thus...  */
end_comment

begin_define
define|#
directive|define
name|WARN_COMMENTS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FIXME.  Why oh why aren't these defined somewhere globally?  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_define
define|#
directive|define
name|TRUE
value|(!FALSE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASEC_NULL
value|(asection *)0
end_define

begin_comment
comment|/* pa_define_label gets used outside of tc-hppa.c via tc_frob_label.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|pa_define_label
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|parse_cons_expression_hppa
name|PARAMS
argument_list|(
operator|(
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cons_fix_new_hppa
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

begin_decl_stmt
specifier|extern
name|int
name|hppa_force_relocation
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This gets called before writing the object file to make sure    things like entry/exit and proc/procend pairs match.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|pa_check_eof
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_frob_file
value|pa_check_eof
end_define

begin_define
define|#
directive|define
name|tc_frob_label
parameter_list|(
name|sym
parameter_list|)
value|pa_define_label (sym)
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|hppa_symbol_chars
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_symbol_chars
value|hppa_symbol_chars
end_define

begin_comment
comment|/* The PA does not need support for either of these.  */
end_comment

begin_define
define|#
directive|define
name|tc_crawl_symbol_chain
parameter_list|(
name|headers
parameter_list|)
value|{;}
end_define

begin_define
define|#
directive|define
name|tc_headers_hook
parameter_list|(
name|headers
parameter_list|)
value|{;}
end_define

begin_define
define|#
directive|define
name|RELOC_EXPANSION_POSSIBLE
end_define

begin_define
define|#
directive|define
name|MAX_RELOC_EXPANSION
value|6
end_define

begin_comment
comment|/* The PA needs to parse field selectors in .byte, etc.  */
end_comment

begin_define
define|#
directive|define
name|TC_PARSE_CONS_EXPRESSION
parameter_list|(
name|EXP
parameter_list|,
name|NBYTES
parameter_list|)
define|\
value|parse_cons_expression_hppa (EXP)
end_define

begin_define
define|#
directive|define
name|TC_CONS_FIX_NEW
value|cons_fix_new_hppa
end_define

begin_comment
comment|/* On the PA, an equal sign often appears as a condition or nullification    completer in an instruction.  This can be detected by checking the    previous character, if the character is a comma, then the equal is    being used as part of an instruction.  */
end_comment

begin_define
define|#
directive|define
name|TC_EQUAL_IN_INSN
parameter_list|(
name|C
parameter_list|,
name|PTR
parameter_list|)
value|((C) == ',')
end_define

begin_comment
comment|/* Similarly for an exclamation point.  It is used in FP comparison    instructions and as an end of line marker.  When used in an instruction    it will always follow a comma.  */
end_comment

begin_define
define|#
directive|define
name|TC_EOL_IN_INSN
parameter_list|(
name|PTR
parameter_list|)
value|(*(PTR) == '!'&& (PTR)[-1] == ',')
end_define

begin_decl_stmt
name|int
name|hppa_fix_adjustable
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_fix_adjustable
value|hppa_fix_adjustable
end_define

begin_define
define|#
directive|define
name|EXTERN_FORCE_RELOC
value|1
end_define

begin_comment
comment|/* Because of the strange PA calling conventions, it is sometimes    necessary to emit a relocation for a call even though it would    normally appear safe to handle it completely within GAS.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|FIX
parameter_list|)
value|hppa_force_relocation (FIX)
end_define

begin_comment
comment|/* Values passed to md_apply_fix3 don't include the symbol value.  */
end_comment

begin_define
define|#
directive|define
name|MD_APPLY_SYM_VALUE
parameter_list|(
name|FIX
parameter_list|)
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_SOM
end_ifdef

begin_comment
comment|/* If a symbol is imported, but never used, then the symbol should    *not* end up in the symbol table.  Likewise for absolute symbols    with local scope.  */
end_comment

begin_define
define|#
directive|define
name|tc_frob_symbol
parameter_list|(
name|sym
parameter_list|,
name|punt
parameter_list|)
define|\
value|if ((S_GET_SEGMENT (sym) ==&bfd_und_section&& ! symbol_used_p (sym)) \ 	|| (S_GET_SEGMENT (sym) ==&bfd_abs_section \&& ! S_IS_EXTERNAL (sym))) \       punt = 1
end_define

begin_comment
comment|/* We need to be able to make relocations involving the difference of    two symbols.  This includes the difference of two symbols when    one of them is undefined (this comes up in PIC code generation).     We don't define DIFF_EXPR_OK because it does the wrong thing if    the add symbol is undefined and the sub symbol is a symbol in    the same section as the relocation.  We also need some way to    specialize some code in adjust_reloc_syms.  */
end_comment

begin_define
define|#
directive|define
name|UNDEFINED_DIFFERENCE_OK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
value|1
end_define

begin_comment
comment|/* Handle .type psuedo.  Given a type string of `millicode', set the    internal elf symbol type to STT_PARISC_MILLI, and return    BSF_FUNCTION for the BFD symbol type.  */
end_comment

begin_define
define|#
directive|define
name|md_elf_symbol_type
parameter_list|(
name|name
parameter_list|,
name|sym
parameter_list|,
name|elf
parameter_list|)
define|\
value|((strcmp ((name), "millicode") == 0					\     || strcmp ((name), "STT_PARISC_MILLI") == 0)			\    ? (((elf)->internal_elf_sym.st_info = ELF_ST_INFO			\        (ELF_ST_BIND ((elf)->internal_elf_sym.st_info), STT_PARISC_MILLI)\        ), BSF_FUNCTION)							\    : -1)
end_define

begin_define
define|#
directive|define
name|tc_frob_symbol
parameter_list|(
name|sym
parameter_list|,
name|punt
parameter_list|)
define|\
value|{ \     if ((S_GET_SEGMENT (sym) ==&bfd_und_section&& ! symbol_used_p (sym)&& \   	 ELF_ST_VISIBILITY (S_GET_OTHER (sym)) == STV_DEFAULT) \ 	|| (S_GET_SEGMENT (sym) ==&bfd_abs_section \&& ! S_IS_EXTERNAL (sym)) \ 	|| strcmp (S_GET_NAME (sym), "$global$") == 0 \ 	|| strcmp (S_GET_NAME (sym), "$PIC_pcrel$0") == 0) \       punt = 1; \   }
end_define

begin_define
define|#
directive|define
name|elf_tc_final_processing
value|elf_hppa_final_processing
end_define

begin_decl_stmt
name|void
name|elf_hppa_final_processing
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJ_ELF */
end_comment

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* Allow register expressions to be treated as absolute expressions.    A silly fudge required for backwards compatibility.  */
end_comment

begin_define
define|#
directive|define
name|md_optimize_expr
value|hppa_force_reg_syms_absolute
end_define

begin_decl_stmt
name|int
name|hppa_force_reg_syms_absolute
name|PARAMS
argument_list|(
operator|(
name|expressionS
operator|*
operator|,
name|operatorT
operator|,
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_FIX_TYPE
value|PTR
end_define

begin_define
define|#
directive|define
name|TC_INIT_FIX_DATA
parameter_list|(
name|FIX
parameter_list|)
value|((FIX)->tc_fix_data = NULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TC_HPPA_H */
end_comment

end_unit

