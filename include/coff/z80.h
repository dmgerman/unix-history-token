begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* coff information for Zilog Z80    Copyright 2005 Free Software Foundation, Inc.    Contributed by Arnold Metselaar<arnold_m@operamail.com>     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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

begin_comment
comment|/* z80 backend does not use dots in section names.  */
end_comment

begin_undef
undef|#
directive|undef
name|_TEXT
end_undef

begin_define
define|#
directive|define
name|_TEXT
value|"text"
end_define

begin_undef
undef|#
directive|undef
name|_DATA
end_undef

begin_define
define|#
directive|define
name|_DATA
value|"data"
end_define

begin_undef
undef|#
directive|undef
name|_BSS
end_undef

begin_define
define|#
directive|define
name|_BSS
value|"bss"
end_define

begin_comment
comment|/* Type of cpu is stored in flags.  */
end_comment

begin_define
define|#
directive|define
name|F_MACHMASK
value|0xF000
end_define

begin_define
define|#
directive|define
name|Z80MAGIC
value|0x805A
end_define

begin_define
define|#
directive|define
name|Z80BADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != Z80MAGIC))
end_define

begin_comment
comment|/* Relocation directives.  */
end_comment

begin_comment
comment|/* This format actually has more bits than we need.  */
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

end_unit

