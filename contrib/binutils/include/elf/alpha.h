begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ALPHA ELF support for BFD.    Copyright 1996, 1998, 2000 Free Software Foundation, Inc.     By Eric Youngdale,<eric@aib.com>.  No processor supplement available    for this platform.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_comment
comment|/* All addresses must be below 2GB.  */
end_comment

begin_define
define|#
directive|define
name|EF_ALPHA_32BIT
value|0x00000001
end_define

begin_comment
comment|/* All relocations needed for relaxation with code movement are present.  */
end_comment

begin_define
define|#
directive|define
name|EF_ALPHA_CANRELAX
value|0x00000002
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
comment|/* Special values for the st_other field in the symbol table.  */
end_comment

begin_define
define|#
directive|define
name|STO_ALPHA_NOPV
value|0x80
end_define

begin_define
define|#
directive|define
name|STO_ALPHA_STD_GPLOAD
value|0x88
end_define

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_comment
comment|/* Alpha relocs.  */
end_comment

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_alpha_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* No reloc */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_REFLONG
argument_list|,
literal|1
argument_list|)
end_macro

begin_comment
comment|/* Direct 32 bit */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_REFQUAD
argument_list|,
literal|2
argument_list|)
end_macro

begin_comment
comment|/* Direct 64 bit */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_GPREL32
argument_list|,
literal|3
argument_list|)
end_macro

begin_comment
comment|/* GP relative 32 bit */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_LITERAL
argument_list|,
literal|4
argument_list|)
end_macro

begin_comment
comment|/* GP relative 16 bit w/optimization */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_LITUSE
argument_list|,
literal|5
argument_list|)
end_macro

begin_comment
comment|/* Optimization hint for LITERAL */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_GPDISP
argument_list|,
literal|6
argument_list|)
end_macro

begin_comment
comment|/* Add displacement to GP */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_BRADDR
argument_list|,
literal|7
argument_list|)
end_macro

begin_comment
comment|/* PC+4 relative 23 bit shifted */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_HINT
argument_list|,
literal|8
argument_list|)
end_macro

begin_comment
comment|/* PC+4 relative 16 bit shifted */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_SREL16
argument_list|,
literal|9
argument_list|)
end_macro

begin_comment
comment|/* PC relative 16 bit */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_SREL32
argument_list|,
literal|10
argument_list|)
end_macro

begin_comment
comment|/* PC relative 32 bit */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_SREL64
argument_list|,
literal|11
argument_list|)
end_macro

begin_comment
comment|/* PC relative 64 bit */
end_comment

begin_comment
comment|/* Skip 12 - 16; deprecated ECOFF relocs.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_GPRELHIGH
argument_list|,
literal|17
argument_list|)
end_macro

begin_comment
comment|/* GP relative 32 bit, high 16 bits */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_GPRELLOW
argument_list|,
literal|18
argument_list|)
end_macro

begin_comment
comment|/* GP relative 32 bit, low 16 bits */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_GPREL16
argument_list|,
literal|19
argument_list|)
end_macro

begin_comment
comment|/* GP relative 16 bit */
end_comment

begin_comment
comment|/* Skip 20 - 23; deprecated ECOFF relocs.  */
end_comment

begin_comment
comment|/* These relocations are specific to shared libraries.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_COPY
argument_list|,
literal|24
argument_list|)
end_macro

begin_comment
comment|/* Copy symbol at runtime */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_GLOB_DAT
argument_list|,
literal|25
argument_list|)
end_macro

begin_comment
comment|/* Create GOT entry */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_JMP_SLOT
argument_list|,
literal|26
argument_list|)
end_macro

begin_comment
comment|/* Create PLT entry */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_RELATIVE
argument_list|,
literal|27
argument_list|)
end_macro

begin_comment
comment|/* Adjust by program base */
end_comment

begin_comment
comment|/* Like BRADDR, but assert that the source and target object file      share the same GP value, and adjust the target address for       STO_ALPHA_STD_GPLOAD.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ALPHA_BRSGP
argument_list|,
literal|28
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_ALPHA_max
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_ALPHA_H */
end_comment

end_unit

