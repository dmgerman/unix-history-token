begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ARM COFF support for BFD.    Copyright 1998, 1999, 2000, 2002 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|COFFARM
value|1
end_define

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

begin_comment
comment|/* Bits for f_flags:  	F_RELFLG	relocation info stripped from file  	F_EXEC		file is executable (no unresolved external references)  	F_LNNO		line numbers stripped from file  	F_LSYMS		local symbols stripped from file         F_INTERWORK     file supports switching between ARM and Thumb instruction sets         F_INTERWORK_SET the F_INTERWORK bit is valid  	F_APCS_FLOAT	code passes float arguments in float registers  	F_PIC		code is reentrant/position-independent  	F_AR32WR	file has byte ordering of an AR32WR machine (e.g. vax)  	F_APCS_26	file uses 26 bit ARM Procedure Calling Standard  	F_APCS_SET	the F_APCS_26, F_APCS_FLOAT and F_PIC bits have been initialised  	F_SOFT_FLOAT	code does not use floating point instructions.  */
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
name|F_INTERWORK
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|F_INTERWORK_SET
value|(0x0020)
end_define

begin_define
define|#
directive|define
name|F_APCS_FLOAT
value|(0x0040)
end_define

begin_undef
undef|#
directive|undef
name|F_AR16WR
end_undef

begin_define
define|#
directive|define
name|F_PIC
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|F_AR32WR
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|F_APCS_26
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|F_APCS_SET
value|(0x0800)
end_define

begin_define
define|#
directive|define
name|F_SOFT_FLOAT
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|F_VFP_FLOAT
value|(0x4000)
end_define

begin_comment
comment|/* Bits stored in flags field of the internal_f structure */
end_comment

begin_define
define|#
directive|define
name|F_INTERWORK
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|F_APCS_FLOAT
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|F_PIC
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|F_APCS26
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|F_ARM_ARCHITECTURE_MASK
value|(0x4000+0x0800+0x0400)
end_define

begin_define
define|#
directive|define
name|F_ARM_2
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|F_ARM_2a
value|(0x0800)
end_define

begin_define
define|#
directive|define
name|F_ARM_3
value|(0x0c00)
end_define

begin_define
define|#
directive|define
name|F_ARM_3M
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|F_ARM_4
value|(0x4400)
end_define

begin_define
define|#
directive|define
name|F_ARM_4T
value|(0x4800)
end_define

begin_define
define|#
directive|define
name|F_ARM_5
value|(0x4c00)
end_define

begin_comment
comment|/*   ARMMAGIC ought to encoded the procesor type,   but it is too late to change it now, instead   the flags field of the internal_f structure   is used as shown above.     XXX - NC 5/6/97.  */
end_comment

begin_define
define|#
directive|define
name|ARMMAGIC
value|0xa00
end_define

begin_comment
comment|/* I just made this up */
end_comment

begin_define
define|#
directive|define
name|ARMBADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != ARMMAGIC))
end_define

begin_define
define|#
directive|define
name|ARMPEMAGIC
value|0x1c0
end_define

begin_define
define|#
directive|define
name|THUMBPEMAGIC
value|0x1c2
end_define

begin_undef
undef|#
directive|undef
name|ARMBADMAG
end_undef

begin_define
define|#
directive|define
name|ARMBADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != ARMMAGIC)&& ((x).f_magic != ARMPEMAGIC)&& ((x).f_magic != THUMBPEMAGIC))
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
comment|/* We use the .rdata section to hold read only data.  */
end_comment

begin_define
define|#
directive|define
name|_LIT
value|".rdata"
end_define

begin_comment
comment|/********************** RELOCATION DIRECTIVES **********************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ARM_WINCE
end_ifdef

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

begin_else
else|#
directive|else
end_else

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

begin_define
define|#
directive|define
name|ARM_NOTE_SECTION
value|".note"
end_define

end_unit

