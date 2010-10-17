begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* COFF information for the Intel i860.        Copyright 2001, 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file was hacked from i386.h   [dolan@ssd.intel.com] */
end_comment

begin_define
define|#
directive|define
name|L_LNNO_SIZE
value|2
end_define

begin_include
include|#
directive|include
file|"coff/external.h"
end_include

begin_comment
comment|/* Bits for f_flags:  	F_RELFLG	relocation info stripped from file  	F_EXEC		file is executable (no unresolved external references)  	F_LNNO		line numbers stripped from file  	F_LSYMS		local symbols stripped from file  	F_AR32WR	file has byte ordering of an AR32WR machine (e.g. vax).  */
end_comment

begin_define
define|#
directive|define
name|F_RELFLG
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|F_EXEC
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|F_LNNO
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|F_LSYMS
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|I860MAGIC
value|0x14d
end_define

begin_define
define|#
directive|define
name|I860BADMAG
parameter_list|(
name|x
parameter_list|)
value|((x).f_magic != I860MAGIC)
end_define

begin_undef
undef|#
directive|undef
name|AOUTSZ
end_undef

begin_define
define|#
directive|define
name|AOUTSZ
value|36
end_define

begin_comment
comment|/* FIXME: What are the a.out magic numbers?  */
end_comment

begin_define
define|#
directive|define
name|_ETEXT
value|"etext"
end_define

begin_comment
comment|/********************** RELOCATION DIRECTIVES **********************/
end_comment

begin_struct
struct|struct
name|external_reloc
block|{
name|char
name|r_vaddr
index|[
literal|4
index|]
decl_stmt|;
name|char
name|r_symndx
index|[
literal|4
index|]
decl_stmt|;
name|char
name|r_type
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RELOC
value|struct external_reloc
end_define

begin_define
define|#
directive|define
name|RELSZ
value|10
end_define

begin_comment
comment|/* The relocation directory entry types.      PAIR   : The low half that follows relates to the preceeding HIGH[ADJ].      HIGH   : The high half of a 32-bit constant.      LOWn   : The low half, insn bits 15..(n-1), 2^n-byte aligned.       SPLITn : The low half, insn bits 20..16 and 10..(n-1), 2^n-byte aligned.       HIGHADJ: Similar to HIGH, but with adjustment.      BRADDR : 26-bit branch displacement.     Note: The Intel assembler manual lists LOW4 as one of the    relocation types, but it appears to be useless for the i860.    We will recognize it anyway, just in case it actually appears in    any object files.  */
end_comment

begin_enum
enum|enum
block|{
name|COFF860_R_PAIR
init|=
literal|0x1c
block|,
name|COFF860_R_HIGH
init|=
literal|0x1e
block|,
name|COFF860_R_LOW0
init|=
literal|0x1f
block|,
name|COFF860_R_LOW1
init|=
literal|0x20
block|,
name|COFF860_R_LOW2
init|=
literal|0x21
block|,
name|COFF860_R_LOW3
init|=
literal|0x22
block|,
name|COFF860_R_LOW4
init|=
literal|0x23
block|,
name|COFF860_R_SPLIT0
init|=
literal|0x24
block|,
name|COFF860_R_SPLIT1
init|=
literal|0x25
block|,
name|COFF860_R_SPLIT2
init|=
literal|0x26
block|,
name|COFF860_R_HIGHADJ
init|=
literal|0x27
block|,
name|COFF860_R_BRADDR
init|=
literal|0x28
block|}
enum|;
end_enum

end_unit

