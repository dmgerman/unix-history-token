begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPARC ELF support for BFD.    Copyright (C) 1996, 1997 Free Software Foundation, Inc.    By Doug Evans, Cygnus Support,<dje@cygnus.com>.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_define
define|#
directive|define
name|EF_SPARC_HAL_R1
value|0x000400
end_define

begin_comment
comment|/* HAL R1 extensions */
end_comment

begin_comment
comment|/* This name is used in the V9 ABI.  */
end_comment

begin_define
define|#
directive|define
name|EF_SPARC_EXT_MASK
value|0xffff00
end_define

begin_comment
comment|/* reserved for vendor extensions */
end_comment

begin_comment
comment|/* V9 memory models */
end_comment

begin_define
define|#
directive|define
name|EF_SPARCV9_MM
value|0x3
end_define

begin_comment
comment|/* memory model mask */
end_comment

begin_define
define|#
directive|define
name|EF_SPARCV9_TSO
value|0x0
end_define

begin_comment
comment|/* total store ordering */
end_comment

begin_define
define|#
directive|define
name|EF_SPARCV9_PSO
value|0x1
end_define

begin_comment
comment|/* partial store ordering */
end_comment

begin_define
define|#
directive|define
name|EF_SPARCV9_RMO
value|0x2
end_define

begin_comment
comment|/* relaxed store ordering */
end_comment

begin_comment
comment|/* Section indices.  */
end_comment

begin_define
define|#
directive|define
name|SHN_BEFORE
value|0xff00
end_define

begin_comment
comment|/* used with SHF_ORDERED */
end_comment

begin_define
define|#
directive|define
name|SHN_AFTER
value|0xff01
end_define

begin_comment
comment|/* used with SHF_ORDERED */
end_comment

begin_comment
comment|/* Section flags.  */
end_comment

begin_define
define|#
directive|define
name|SHF_EXCLUDE
value|0x80000000
end_define

begin_comment
comment|/* exclude from linking */
end_comment

begin_define
define|#
directive|define
name|SHF_ORDERED
value|0x40000000
end_define

begin_comment
comment|/* treat sh_link,sh_info specially */
end_comment

begin_comment
comment|/* Symbol types.  */
end_comment

begin_define
define|#
directive|define
name|STT_REGISTER
value|13
end_define

begin_comment
comment|/* global reg reserved to app. */
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
name|R_SPARC_UNUSED_42
block|,
name|R_SPARC_7
block|,
name|R_SPARC_5
block|,
name|R_SPARC_6
block|,
name|R_SPARC_DISP64
block|,
name|R_SPARC_PLT64
block|,
name|R_SPARC_HIX22
block|,
name|R_SPARC_LOX10
block|,
name|R_SPARC_H44
block|,
name|R_SPARC_M44
block|,
name|R_SPARC_L44
block|,
name|R_SPARC_REGISTER
block|,
name|R_SPARC_UA64
block|,
name|R_SPARC_UA16
block|,
name|R_SPARC_max
block|}
enum|;
end_enum

begin_comment
comment|/* Relocation macros.  */
end_comment

begin_define
define|#
directive|define
name|ELF64_R_TYPE_DATA
parameter_list|(
name|info
parameter_list|)
value|(((bfd_vma) (info)<< 32)>> 40)
end_define

begin_define
define|#
directive|define
name|ELF64_R_TYPE_ID
parameter_list|(
name|info
parameter_list|)
value|(((bfd_vma) (info)<< 56)>> 56)
end_define

begin_define
define|#
directive|define
name|ELF64_R_TYPE_INFO
parameter_list|(
name|data
parameter_list|,
name|type
parameter_list|)
value|(((bfd_vma) (data)<< 8) \ 					 + (bfd_vma) (type))
end_define

begin_define
define|#
directive|define
name|DT_SPARC_REGISTER
value|0x70000001
end_define

begin_comment
comment|/*  * FIXME: NOT ABI -- GET RID OF THIS  * Defines the format used by the .plt.  Currently defined values are  *   0 -- reserved to SI  *   1 -- absolute address in .got.plt  *   2 -- got-relative address in .got.plt  */
end_comment

begin_define
define|#
directive|define
name|DT_SPARC_PLTFMT
value|0x70000001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_SPARC_H */
end_comment

end_unit

