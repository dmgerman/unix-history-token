begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-v850.h -- Header file for tc-v850.c.    Copyright 1996, 1997, 1998, 2000 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_V850
end_define

begin_include
include|#
directive|include
file|<elf/v850.h>
end_include

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_error
error|#
directive|error
error|V850 support requires BFD_ASSEMBLER
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The target BFD architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_v850
end_define

begin_comment
comment|/* The target BFD format.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-v850"
end_define

begin_define
define|#
directive|define
name|MD_APPLY_FIX3
end_define

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|obj_fix_adjustable
parameter_list|(
name|fixP
parameter_list|)
value|v850_fix_adjustable(fixP)
end_define

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|fixp
parameter_list|)
value|v850_force_relocation(fixp)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_comment
comment|/* This arranges for gas/write.c to not apply a relocation if    obj_fix_adjustable() says it is not adjustable.  */
end_comment

begin_define
define|#
directive|define
name|TC_FIX_ADJUSTABLE
parameter_list|(
name|fixP
parameter_list|)
value|obj_fix_adjustable (fixP)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|v850_force_relocation
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
comment|/* Permit temporary numeric labels.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_comment
comment|/* foo-. gets turned into PC relative relocs */
end_comment

begin_comment
comment|/* We don't need to handle .word strangely.  */
end_comment

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|md_number_to_chars
value|number_to_chars_littleendian
end_define

begin_comment
comment|/* We need to handle lo(), hi(), etc etc in .hword, .word, etc    directives, so we have to parse "cons" expressions ourselves.  */
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
value|parse_cons_expression_v850 (EXP)
end_define

begin_define
define|#
directive|define
name|TC_CONS_FIX_NEW
value|cons_fix_new_v850
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|relax_type
name|md_relax_table
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_GENERIC_RELAX_TABLE
value|md_relax_table
end_define

begin_comment
comment|/* This section must be in the small data area (pointed to by GP).  */
end_comment

begin_define
define|#
directive|define
name|SHF_V850_GPREL
value|0x10000000
end_define

begin_comment
comment|/* This section must be in the tiny data area (pointed to by EP).  */
end_comment

begin_define
define|#
directive|define
name|SHF_V850_EPREL
value|0x20000000
end_define

begin_comment
comment|/* This section must be in the zero data area (pointed to by R0).  */
end_comment

begin_define
define|#
directive|define
name|SHF_V850_R0REL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|ELF_TC_SPECIAL_SECTIONS
define|\
value|{ ".sdata",	SHT_PROGBITS,		SHF_ALLOC + SHF_WRITE + SHF_V850_GPREL	}, \   { ".rosdata",	SHT_PROGBITS,		SHF_ALLOC +             SHF_V850_GPREL	}, \   { ".sbss",	SHT_NOBITS,		SHF_ALLOC + SHF_WRITE + SHF_V850_GPREL	}, \   { ".scommon",	SHT_V850_SCOMMON, 	SHF_ALLOC + SHF_WRITE + SHF_V850_GPREL	}, \   { ".tdata",	SHT_PROGBITS,		SHF_ALLOC + SHF_WRITE + SHF_V850_EPREL	}, \   { ".tbss",	SHT_NOBITS,		SHF_ALLOC + SHF_WRITE + SHF_V850_EPREL	}, \   { ".tcommon",	SHT_V850_TCOMMON,	SHF_ALLOC + SHF_WRITE + SHF_V850_R0REL	}, \   { ".zdata",	SHT_PROGBITS,		SHF_ALLOC + SHF_WRITE + SHF_V850_R0REL	}, \   { ".rozdata",	SHT_PROGBITS,		SHF_ALLOC +             SHF_V850_R0REL	}, \   { ".zbss",	SHT_NOBITS,	  	SHF_ALLOC + SHF_WRITE + SHF_V850_R0REL	}, \   { ".zcommon",	SHT_V850_ZCOMMON, 	SHF_ALLOC + SHF_WRITE + SHF_V850_R0REL	}, \   { ".call_table_data",	SHT_PROGBITS,	SHF_ALLOC + SHF_WRITE },	   \   { ".call_table_text",	SHT_PROGBITS,	SHF_ALLOC + SHF_WRITE + SHF_EXECINSTR },
end_define

begin_define
define|#
directive|define
name|MD_PCREL_FROM_SECTION
parameter_list|(
name|fixP
parameter_list|,
name|section
parameter_list|)
value|v850_pcrel_from_section (fixP, section)
end_define

begin_function_decl
specifier|extern
name|long
name|v850_pcrel_from_section
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|2
end_define

end_unit

