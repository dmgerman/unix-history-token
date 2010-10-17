begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* coff information for we32k        Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|F_BM32B
value|(0020000)
end_define

begin_define
define|#
directive|define
name|F_BM32MAU
value|(0040000)
end_define

begin_define
define|#
directive|define
name|WE32KMAGIC
value|0x170
end_define

begin_comment
comment|/* we32k sans transfer vector */
end_comment

begin_define
define|#
directive|define
name|FBOMAGIC
value|0x170
end_define

begin_comment
comment|/* we32k sans transfer vector */
end_comment

begin_define
define|#
directive|define
name|MTVMAGIC
value|0x171
end_define

begin_comment
comment|/* we32k with transfer vector */
end_comment

begin_define
define|#
directive|define
name|RBOMAGIC
value|0x172
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|WE32KBADMAG
parameter_list|(
name|x
parameter_list|)
value|(   ((x).f_magic != WE32KMAGIC) \&& ((x).f_magic != FBOMAGIC) \&& ((x).f_magic != RBOMAGIC) \&& ((x).f_magic != MTVMAGIC))
end_define

begin_comment
comment|/* More names of "special" sections.  */
end_comment

begin_define
define|#
directive|define
name|_TV
value|".tv"
end_define

begin_define
define|#
directive|define
name|_INIT
value|".init"
end_define

begin_define
define|#
directive|define
name|_FINI
value|".fini"
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

end_unit

