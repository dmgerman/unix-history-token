begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-h8300.h    Copyright 1987, 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996,    1997, 1998, 2000, 2001, 2002, 2003, 2005    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_H8300
end_define

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
value|bfd_arch_h8300
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-h8300"
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

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|COFF_MAGIC
value|( Smode&& Nmode ? 0x8304 : Hmode&& Nmode ? 0x8303 : Smode ? 0x8302 : Hmode ? 0x8301 : 0x8300)
end_define

begin_define
define|#
directive|define
name|IGNORE_NONSTANDARD_ESCAPES
end_define

begin_define
define|#
directive|define
name|tc_coff_symbol_emit_hook
parameter_list|(
name|a
parameter_list|)
value|;
end_define

begin_comment
comment|/* not used */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_comment
comment|/* Provide mappings from the original H8 COFF relocation names to    their corresponding BFD relocation names.  This allows us to use    most of tc-h8300.c without modifications for both ELF and COFF    ports.  */
end_comment

begin_define
define|#
directive|define
name|R_MOV24B1
value|BFD_RELOC_H8_DIR24A8
end_define

begin_define
define|#
directive|define
name|R_MOVL1
value|BFD_RELOC_H8_DIR32A16
end_define

begin_define
define|#
directive|define
name|R_MOV24B1
value|BFD_RELOC_H8_DIR24A8
end_define

begin_define
define|#
directive|define
name|R_MOVL1
value|BFD_RELOC_H8_DIR32A16
end_define

begin_define
define|#
directive|define
name|R_RELLONG
value|BFD_RELOC_32
end_define

begin_define
define|#
directive|define
name|R_MOV16B1
value|BFD_RELOC_H8_DIR16A8
end_define

begin_define
define|#
directive|define
name|R_RELWORD
value|BFD_RELOC_16
end_define

begin_define
define|#
directive|define
name|R_RELBYTE
value|BFD_RELOC_8
end_define

begin_define
define|#
directive|define
name|R_PCRWORD
value|BFD_RELOC_16_PCREL
end_define

begin_define
define|#
directive|define
name|R_PCRBYTE
value|BFD_RELOC_8_PCREL
end_define

begin_define
define|#
directive|define
name|R_JMPL1
value|BFD_RELOC_H8_DIR24R8
end_define

begin_define
define|#
directive|define
name|R_MEM_INDIRECT
value|BFD_RELOC_8
end_define

begin_comment
comment|/* We do not want to adjust any relocations to make implementation of    linker relaxations easier.  */
end_comment

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"Renesas H8/300 GAS "
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|OBJ_ELF
end_ifndef

begin_define
define|#
directive|define
name|RELOC_32
value|1234
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|Hmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Smode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Nmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|SXmode
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

end_unit

