begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPARC ELF support for BFD.    Copyright (C) 1996 Free Software Foundation, Inc.     By Doug Evans, Cygnus Support,<dje@cygnus.com>.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_SPARC_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_SPARC_H
end_define

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_comment
comment|/* These are defined by Sun.  */
end_comment

begin_define
define|#
directive|define
name|EF_SPARC_32PLUS_MASK
value|0xffff00
end_define

begin_comment
comment|/* bits indicating V8+ type */
end_comment

begin_define
define|#
directive|define
name|EF_SPARC_32PLUS
value|0x000100
end_define

begin_comment
comment|/* generic V8+ features */
end_comment

begin_define
define|#
directive|define
name|EF_SPARC_SUN_US1
value|0x000200
end_define

begin_comment
comment|/* Sun UltraSPARC1 extensions */
end_comment

begin_comment
comment|/* Relocation types.  */
end_comment

begin_enum
enum|enum
name|elf_sparc_reloc_type
block|{
name|R_SPARC_NONE
init|=
literal|0
block|,
name|R_SPARC_8
block|,
name|R_SPARC_16
block|,
name|R_SPARC_32
block|,
name|R_SPARC_DISP8
block|,
name|R_SPARC_DISP16
block|,
name|R_SPARC_DISP32
block|,
name|R_SPARC_WDISP30
block|,
name|R_SPARC_WDISP22
block|,
name|R_SPARC_HI22
block|,
name|R_SPARC_22
block|,
name|R_SPARC_13
block|,
name|R_SPARC_LO10
block|,
name|R_SPARC_GOT10
block|,
name|R_SPARC_GOT13
block|,
name|R_SPARC_GOT22
block|,
name|R_SPARC_PC10
block|,
name|R_SPARC_PC22
block|,
name|R_SPARC_WPLT30
block|,
name|R_SPARC_COPY
block|,
name|R_SPARC_GLOB_DAT
block|,
name|R_SPARC_JMP_SLOT
block|,
name|R_SPARC_RELATIVE
block|,
name|R_SPARC_UA32
block|,
comment|/* ??? These 6 relocs are new but not currently used.  For binary        compatility in the sparc64-elf toolchain, we leave them out.        A non-binary upward compatible change is expected for sparc64-elf.  */
ifndef|#
directive|ifndef
name|SPARC64_OLD_RELOCS
comment|/* ??? New relocs on the UltraSPARC.  Not sure what they're for yet.  */
name|R_SPARC_PLT32
block|,
name|R_SPARC_HIPLT22
block|,
name|R_SPARC_LOPLT10
block|,
name|R_SPARC_PCPLT32
block|,
name|R_SPARC_PCPLT22
block|,
name|R_SPARC_PCPLT10
block|,
endif|#
directive|endif
comment|/* v9 relocs */
name|R_SPARC_10
block|,
name|R_SPARC_11
block|,
name|R_SPARC_64
block|,
name|R_SPARC_OLO10
block|,
name|R_SPARC_HH22
block|,
name|R_SPARC_HM10
block|,
name|R_SPARC_LM22
block|,
name|R_SPARC_PC_HH22
block|,
name|R_SPARC_PC_HM10
block|,
name|R_SPARC_PC_LM22
block|,
name|R_SPARC_WDISP16
block|,
name|R_SPARC_WDISP19
block|,
name|R_SPARC_GLOB_JMP
block|,
name|R_SPARC_7
block|,
ifndef|#
directive|ifndef
name|SPARC64_OLD_RELOCS
name|R_SPARC_5
block|,
name|R_SPARC_6
block|,
endif|#
directive|endif
name|R_SPARC_max
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_SPARC_H */
end_comment

end_unit

