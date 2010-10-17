begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* coff information for Renesas H8/300 and H8/300-H     Copyright 2001, 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|H8300MAGIC
value|0x8300
end_define

begin_define
define|#
directive|define
name|H8300HMAGIC
value|0x8301
end_define

begin_define
define|#
directive|define
name|H8300SMAGIC
value|0x8302
end_define

begin_define
define|#
directive|define
name|H8300HNMAGIC
value|0x8303
end_define

begin_define
define|#
directive|define
name|H8300SNMAGIC
value|0x8304
end_define

begin_define
define|#
directive|define
name|H8300BADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != H8300MAGIC))
end_define

begin_define
define|#
directive|define
name|H8300HBADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != H8300HMAGIC))
end_define

begin_define
define|#
directive|define
name|H8300SBADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != H8300SMAGIC))
end_define

begin_define
define|#
directive|define
name|H8300HNBADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != H8300HNMAGIC))
end_define

begin_define
define|#
directive|define
name|H8300SNBADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != H8300SNMAGIC))
end_define

begin_comment
comment|/* Relocation directives.  */
end_comment

begin_comment
comment|/* The external reloc has an offset field, because some of the reloc    types on the h8 don't have room in the instruction for the entire    offset - eg the strange jump and high page addressing modes.  */
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

