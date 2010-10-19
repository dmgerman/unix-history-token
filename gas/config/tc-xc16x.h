begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-xc16x.h    Copyright 2006 Free Software Foundation, Inc.    Contributed by KPIT Cummins Infosystems      This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_XC16X
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
name|TARGET_ARCH
value|bfd_arch_xc16x
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_comment
comment|/* Fixup debug sections since we will never relax them.  */
end_comment

begin_define
define|#
directive|define
name|TC_LINKRELAX_FIXUP
parameter_list|(
name|seg
parameter_list|)
value|(seg->flags& SEC_ALLOC)
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
name|TARGET_FORMAT
value|"elf32-xc16x"
end_define

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|'.'
end_define

begin_define
define|#
directive|define
name|LOCAL_LABEL
parameter_list|(
name|NAME
parameter_list|)
value|(NAME[0] == '.'&& NAME[1] == 'L')
end_define

begin_define
define|#
directive|define
name|FAKE_LABEL_NAME
value|".L0\001"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ANSI_PROTOTYPES
end_if

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|internal_reloc
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|BFD_ARCH
value|bfd_arch_xc16x
end_define

begin_define
define|#
directive|define
name|TC_COUNT_RELOC
parameter_list|(
name|x
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|IGNORE_NONSTANDARD_ESCAPES
end_define

begin_define
define|#
directive|define
name|TC_RELOC_MANGLE
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tc_reloc_mangle(a,b,c)
end_define

begin_function_decl
specifier|extern
name|void
name|tc_reloc_mangle
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|,
name|struct
name|internal_reloc
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* No shared lib support, so we don't need to ensure externally    visible symbols can be overridden.  */
end_comment

begin_define
define|#
directive|define
name|EXTERN_FORCE_RELOC
value|0
end_define

begin_comment
comment|/* Minimum instruction is of 16 bits.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|2
end_define

begin_define
define|#
directive|define
name|DO_NOT_STRIP
value|0
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"Infineon XC16X GAS "
end_define

begin_define
define|#
directive|define
name|NEED_FX_R_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|MD_PCREL_FROM_SECTION
parameter_list|(
name|FIX
parameter_list|,
name|SEC
parameter_list|)
value|md_pcrel_from_section (FIX, SEC)
end_define

begin_function_decl
specifier|extern
name|long
name|md_pcrel_from_section
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|,
name|segT
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

end_unit

