begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-vax.h -- Header file for tc-vax.c.    Copyright 1987, 1991, 1992, 1993, 1995, 1996, 1997, 2000, 2002, 2005, 2006    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_VAX
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_AOUT
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TE_NetBSD
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"a.out-vax-netbsd"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_FORMAT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"a.out-vax-bsd"
end_define

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
name|OBJ_VMS
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"vms-vax"
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
value|"elf32-vax"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_vax
end_define

begin_define
define|#
directive|define
name|NO_RELOC
value|BFD_RELOC_NONE
end_define

begin_define
define|#
directive|define
name|NOP_OPCODE
value|0x01
end_define

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
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
comment|/* Values passed to md_apply_fix don't include symbol values.  */
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

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
define|\
value|((FIX)->fx_r_type != BFD_RELOC_VTABLE_INHERIT		\&& (FIX)->fx_r_type != BFD_RELOC_32_PLT_PCREL		\&& (FIX)->fx_r_type != BFD_RELOC_32_GOT_PCREL		\&& (FIX)->fx_r_type != BFD_RELOC_VTABLE_ENTRY		\&& ((FIX)->fx_pcrel					\ 	     || ((FIX)->fx_subsy != NULL			\&& (S_GET_SEGMENT ((FIX)->fx_subsy)		\ 		     == S_GET_SEGMENT ((FIX)->fx_addsy)))	\ 	     || S_IS_LOCAL ((FIX)->fx_addsy)))
end_define

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

end_unit

