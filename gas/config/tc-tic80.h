begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-tic80.h    Copyright 1996, 1997, 2000 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_TIC80
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
value|bfd_arch_tic80
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-tic80"
end_define

begin_define
define|#
directive|define
name|BFD_ARCH
value|TARGET_ARCH
end_define

begin_comment
comment|/* We need the extra field in the fixup struct to put the relocation in.  */
end_comment

begin_define
define|#
directive|define
name|NEED_FX_R_TYPE
end_define

begin_comment
comment|/* Define md_number_to_chars as the appropriate standard big endian or    little endian function.  Should we someday support endianness as a    runtime decision, this will need to change.  */
end_comment

begin_define
define|#
directive|define
name|md_number_to_chars
value|number_to_chars_littleendian
end_define

begin_comment
comment|/* Define away the call to md_operand in the expression parsing code.    This is called whenever the expression parser can't parse the input    and gives the assembler backend a chance to deal with it instead.  */
end_comment

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_COFF
end_ifdef

begin_comment
comment|/* COFF specific definitions.  */
end_comment

begin_define
define|#
directive|define
name|COFF_MAGIC
value|TIC80_ARCH_MAGIC
end_define

begin_comment
comment|/* Whether a reloc should be output.  */
end_comment

begin_define
define|#
directive|define
name|TC_COUNT_RELOC
parameter_list|(
name|fixp
parameter_list|)
value|((fixp) -> fx_addsy != NULL)
end_define

begin_comment
comment|/* This macro translates between an internal fix and a coff reloc type. */
end_comment

begin_define
define|#
directive|define
name|TC_COFF_FIX2RTYPE
parameter_list|(
name|fixP
parameter_list|)
value|tc_coff_fix2rtype(fixP)
end_define

begin_decl_stmt
specifier|extern
name|short
name|tc_coff_fix2rtype
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJ_COFF */
end_comment

end_unit

