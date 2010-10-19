begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Motorola MCore support for BFD.    Copyright 1999, 2000 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* This file holds definitions specific to the MCore COFF/PE ABI. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COFF_MORE_H
end_ifndef

begin_define
define|#
directive|define
name|_COFF_MORE_H
end_define

begin_define
define|#
directive|define
name|INCLUDE_COMDAT_FIELDS_IN_AUXENT
end_define

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

begin_define
define|#
directive|define
name|MCOREMAGIC
value|0xb00
end_define

begin_comment
comment|/* I just made this up */
end_comment

begin_define
define|#
directive|define
name|MCOREBADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != MCOREMAGIC))
end_define

begin_define
define|#
directive|define
name|E_DIMNUM
value|4
end_define

begin_comment
comment|/* # array dimensions in auxiliary entry */
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_MCORE_ABSOLUTE
value|0x0000
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_MCORE_ADDR32
value|0x0001
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_MCORE_PCREL_IMM8BY4
value|0x0002
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_MCORE_PCREL_IMM11BY2
value|0x0003
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_MCORE_PCREL_IMM4BY2
value|0x0004
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_MCORE_PCREL_32
value|0x0005
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_MCORE_PCREL_JSR_IMM11BY2
value|0x0006
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_MCORE_RVA
value|0x0007
end_define

begin_define
define|#
directive|define
name|PEMCORE
end_define

begin_define
define|#
directive|define
name|OMAGIC
value|0404
end_define

begin_comment
comment|/* object files, eg as output */
end_comment

begin_define
define|#
directive|define
name|ZMAGIC
value|0413
end_define

begin_comment
comment|/* demand load format, eg normal ld output */
end_comment

begin_define
define|#
directive|define
name|STMAGIC
value|0401
end_define

begin_comment
comment|/* target shlib */
end_comment

begin_define
define|#
directive|define
name|SHMAGIC
value|0443
end_define

begin_comment
comment|/* host   shlib */
end_comment

begin_comment
comment|/* From winnt.h */
end_comment

begin_define
define|#
directive|define
name|IMAGE_NT_OPTIONAL_HDR_MAGIC
value|0x10b
end_define

begin_comment
comment|/* Define some NT default values. */
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
name|char
name|r_offset
index|[
literal|4
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
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __COFF_MCORE_H */
end_comment

end_unit

