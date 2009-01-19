begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* coff information for Windows CE with MIPS VR4111        Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|L_LNNO_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|INCLUDE_COMDAT_FIELDS_IN_AUXENT
end_define

begin_include
include|#
directive|include
file|"coff/external.h"
end_include

begin_define
define|#
directive|define
name|MIPS_ARCH_MAGIC_WINCE
value|0x0166
end_define

begin_comment
comment|/* Windows CE - little endian */
end_comment

begin_define
define|#
directive|define
name|MIPS_PE_MAGIC
value|0x010b
end_define

begin_define
define|#
directive|define
name|MIPSBADMAG
parameter_list|(
name|x
parameter_list|)
value|((x).f_magic != MIPS_ARCH_MAGIC_WINCE)
end_define

begin_comment
comment|/* define some NT default values */
end_comment

begin_comment
comment|/*  #define NT_IMAGE_BASE        0x400000 moved to internal.h */
end_comment

begin_define
define|#
directive|define
name|NT_SECTION_ALIGNMENT
value|0x1000
end_define

begin_define
define|#
directive|define
name|NT_FILE_ALIGNMENT
value|0x200
end_define

begin_define
define|#
directive|define
name|NT_DEF_RESERVE
value|0x100000
end_define

begin_define
define|#
directive|define
name|NT_DEF_COMMIT
value|0x1000
end_define

begin_comment
comment|/********************** RELOCATION DIRECTIVES **********************/
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
comment|/* MIPS PE relocation types. */
end_comment

begin_define
define|#
directive|define
name|MIPS_R_ABSOLUTE
value|0
end_define

begin_comment
comment|/* ignored */
end_comment

begin_define
define|#
directive|define
name|MIPS_R_REFHALF
value|1
end_define

begin_define
define|#
directive|define
name|MIPS_R_REFWORD
value|2
end_define

begin_define
define|#
directive|define
name|MIPS_R_JMPADDR
value|3
end_define

begin_define
define|#
directive|define
name|MIPS_R_REFHI
value|4
end_define

begin_comment
comment|/* PAIR follows */
end_comment

begin_define
define|#
directive|define
name|MIPS_R_REFLO
value|5
end_define

begin_define
define|#
directive|define
name|MIPS_R_GPREL
value|6
end_define

begin_define
define|#
directive|define
name|MIPS_R_LITERAL
value|7
end_define

begin_comment
comment|/* same as GPREL */
end_comment

begin_define
define|#
directive|define
name|MIPS_R_SECTION
value|10
end_define

begin_define
define|#
directive|define
name|MIPS_R_SECREL
value|11
end_define

begin_define
define|#
directive|define
name|MIPS_R_SECRELLO
value|12
end_define

begin_define
define|#
directive|define
name|MIPS_R_SECRELHI
value|13
end_define

begin_comment
comment|/* PAIR follows */
end_comment

begin_define
define|#
directive|define
name|MIPS_R_RVA
value|34
end_define

begin_comment
comment|/* 0x22 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R_PAIR
value|37
end_define

begin_comment
comment|/* 0x25 - symndx is really a signed 16-bit addend */
end_comment

end_unit

