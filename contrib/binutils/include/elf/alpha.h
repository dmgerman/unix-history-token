begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ALPHA ELF support for BFD.    Copyright (C) 1996 Free Software Foundation, Inc.     By Eric Youngdale,<eric@aib.com>.  No processor supplement available    for this platform.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file holds definitions specific to the ALPHA ELF ABI.  Note    that most of this is not actually implemented by BFD.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_ALPHA_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_ALPHA_H
end_define

begin_comment
comment|/* Processor specific section flags.  */
end_comment

begin_comment
comment|/* This section must be in the global data area.  */
end_comment

begin_define
define|#
directive|define
name|SHF_ALPHA_GPREL
value|0x10000000
end_define

begin_comment
comment|/* Section contains some sort of debugging information.  The exact    format is unspecified.  It's probably ECOFF symbols.  */
end_comment

begin_define
define|#
directive|define
name|SHT_ALPHA_DEBUG
value|0x70000001
end_define

begin_comment
comment|/* Section contains register usage information.  */
end_comment

begin_define
define|#
directive|define
name|SHT_ALPHA_REGINFO
value|0x70000002
end_define

begin_comment
comment|/* A section of type SHT_MIPS_REGINFO contains the following    structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Mask of general purpose registers used.  */
name|unsigned
name|long
name|ri_gprmask
decl_stmt|;
comment|/* Mask of co-processor registers used.  */
name|unsigned
name|long
name|ri_cprmask
index|[
literal|4
index|]
decl_stmt|;
comment|/* GP register value for this object file.  */
name|long
name|ri_gp_value
decl_stmt|;
block|}
name|Elf64_RegInfo
typedef|;
end_typedef

begin_comment
comment|/* Alpha relocs.  */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_NONE
value|0
end_define

begin_comment
comment|/* No reloc */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_REFLONG
value|1
end_define

begin_comment
comment|/* Direct 32 bit */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_REFQUAD
value|2
end_define

begin_comment
comment|/* Direct 64 bit */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_GPREL32
value|3
end_define

begin_comment
comment|/* GP relative 32 bit */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_LITERAL
value|4
end_define

begin_comment
comment|/* GP relative 16 bit w/optimization */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_LITUSE
value|5
end_define

begin_comment
comment|/* Optimization hint for LITERAL */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_GPDISP
value|6
end_define

begin_comment
comment|/* Add displacement to GP */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_BRADDR
value|7
end_define

begin_comment
comment|/* PC+4 relative 23 bit shifted */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_HINT
value|8
end_define

begin_comment
comment|/* PC+4 relative 16 bit shifted */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_SREL16
value|9
end_define

begin_comment
comment|/* PC relative 16 bit */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_SREL32
value|10
end_define

begin_comment
comment|/* PC relative 32 bit */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_SREL64
value|11
end_define

begin_comment
comment|/* PC relative 64 bit */
end_comment

begin_comment
comment|/* Inherited these from ECOFF, but they are not particularly useful    and are depreciated.  And not implemented in the BFD, btw.  */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_OP_PUSH
value|12
end_define

begin_comment
comment|/* OP stack push */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_OP_STORE
value|13
end_define

begin_comment
comment|/* OP stack pop and store */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_OP_PSUB
value|14
end_define

begin_comment
comment|/* OP stack subtract */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_OP_PRSHIFT
value|15
end_define

begin_comment
comment|/* OP stack right shift */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_GPVALUE
value|16
end_define

begin_define
define|#
directive|define
name|R_ALPHA_GPRELHIGH
value|17
end_define

begin_define
define|#
directive|define
name|R_ALPHA_GPRELLOW
value|18
end_define

begin_define
define|#
directive|define
name|R_ALPHA_IMMED_GP_16
value|19
end_define

begin_define
define|#
directive|define
name|R_ALPHA_IMMED_GP_HI32
value|20
end_define

begin_define
define|#
directive|define
name|R_ALPHA_IMMED_SCN_HI32
value|21
end_define

begin_define
define|#
directive|define
name|R_ALPHA_IMMED_BR_HI32
value|22
end_define

begin_define
define|#
directive|define
name|R_ALPHA_IMMED_LO32
value|23
end_define

begin_comment
comment|/* These relocations are specific to shared libraries.  */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_COPY
value|24
end_define

begin_comment
comment|/* Copy symbol at runtime */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_GLOB_DAT
value|25
end_define

begin_comment
comment|/* Create GOT entry */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_JMP_SLOT
value|26
end_define

begin_comment
comment|/* Create PLT entry */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_RELATIVE
value|27
end_define

begin_comment
comment|/* Adjust by program base */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_max
value|28
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_ALPHA_H */
end_comment

end_unit

