begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* coff information for Texas Instruments TMS320C3X        Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|L_LNNO_SIZE
value|4
end_define

begin_include
include|#
directive|include
file|"coff/external.h"
end_include

begin_define
define|#
directive|define
name|TIC30MAGIC
value|0xC000
end_define

begin_define
define|#
directive|define
name|TIC30BADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != TIC30MAGIC))
end_define

begin_comment
comment|/********************** RELOCATION DIRECTIVES **********************/
end_comment

begin_comment
comment|/* The external reloc has an offset field, because some of the reloc    types on the z8k don't have room in the instruction for the entire    offset - eg with segments */
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
name|r_offset
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
name|char
name|r_stuff
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
value|16
end_define

begin_comment
comment|/* TMS320C30 relocation types.  */
end_comment

begin_define
define|#
directive|define
name|R_TIC30_ABS16
value|0x100
end_define

begin_comment
comment|/* 16 bit absolute. */
end_comment

begin_define
define|#
directive|define
name|R_TIC30_ABS24
value|0x101
end_define

begin_comment
comment|/* 24 bit absolute. */
end_comment

begin_define
define|#
directive|define
name|R_TIC30_ABS32
value|0x102
end_define

begin_comment
comment|/* 32 bit absolute. */
end_comment

begin_define
define|#
directive|define
name|R_TIC30_LDP
value|0x103
end_define

begin_comment
comment|/* LDP bits 23-16 to 7-0. */
end_comment

begin_define
define|#
directive|define
name|R_TIC30_PC16
value|0x104
end_define

begin_comment
comment|/* 16 bit pc relative. */
end_comment

end_unit

