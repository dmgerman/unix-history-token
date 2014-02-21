begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* COFF information for AMD 64.    Copyright 2006, 2009 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.        Written by Kai Tietz, OneVision Software GmbH&CoKg.  */
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
name|COFF_PAGE_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|AMD64MAGIC
value|0x8664
end_define

begin_define
define|#
directive|define
name|AMD64BADMAG
parameter_list|(
name|x
parameter_list|)
value|((x).f_magic != AMD64MAGIC)
end_define

begin_define
define|#
directive|define
name|IMAGE_NT_OPTIONAL_HDR64_MAGIC
value|0x20b
end_define

begin_define
define|#
directive|define
name|OMAGIC
value|0404
end_define

begin_comment
comment|/* Object files, eg as output.  */
end_comment

begin_define
define|#
directive|define
name|ZMAGIC
value|IMAGE_NT_OPTIONAL_HDR64_MAGIC
end_define

begin_comment
comment|/* Demand load format, eg normal ld output 0x10b.  */
end_comment

begin_define
define|#
directive|define
name|STMAGIC
value|0401
end_define

begin_comment
comment|/* Target shlib.  */
end_comment

begin_define
define|#
directive|define
name|SHMAGIC
value|0443
end_define

begin_comment
comment|/* Host   shlib.  */
end_comment

begin_comment
comment|/* Define some NT default values.  */
end_comment

begin_comment
comment|/*  #define NT_IMAGE_BASE        0x400000 moved to internal.h.  */
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
comment|/* Relocation directives.  */
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

