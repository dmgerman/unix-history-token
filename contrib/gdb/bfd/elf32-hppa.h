begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ELF32/HPPA support     This file contains ELF32/HPPA relocation support as specified    in the Stratus FTX/Golf Object File Format (SED-1762) dated    February 1994.     Copyright (C) 1990, 91, 92, 93, 94 Free Software Foundation, Inc.     Written by:     Center for Software Science    Department of Computer Science    University of Utah     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF32_HPPA_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF32_HPPA_H
end_define

begin_include
include|#
directive|include
file|"elf-bfd.h"
end_include

begin_include
include|#
directive|include
file|"libhppa.h"
end_include

begin_include
include|#
directive|include
file|"elf/hppa.h"
end_include

begin_comment
comment|/* ELF/HPPA relocation types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* Address relocation types        These relocation types do simple base + offset relocations.  */
name|R_PARISC_NONE
init|=
literal|0x00
block|,
name|R_PARISC_DIR32
init|=
literal|0x01
block|,
name|R_PARISC_DIR21L
init|=
literal|0x02
block|,
name|R_PARISC_DIR17R
init|=
literal|0x03
block|,
name|R_PARISC_DIR17F
init|=
literal|0x04
block|,
name|R_PARISC_DIR14R
init|=
literal|0x06
block|,
comment|/* PC-relative relocation types        Typically used for calls.        Note PCREL17C and PCREL17F differ only in overflow handling.        PCREL17C never reports a relocation error.         When supporting argument relocations, function calls must be        accompanied by parameter relocation information.  This information is         carried in the ten high-order bits of the addend field.  The remaining        22 bits of of the addend field are sign-extended to form the Addend.         Note the code to build argument relocations depends on the         addend being zero.  A consequence of this limitation is GAS        can not perform relocation reductions for function symbols.  */
name|R_PARISC_PCREL21L
init|=
literal|0x0a
block|,
name|R_PARISC_PCREL17R
init|=
literal|0x0b
block|,
name|R_PARISC_PCREL17F
init|=
literal|0x0c
block|,
name|R_PARISC_PCREL17C
init|=
literal|0x0d
block|,
name|R_PARISC_PCREL14R
init|=
literal|0x0e
block|,
name|R_PARISC_PCREL14F
init|=
literal|0x0f
block|,
comment|/* DP-relative relocation types.  */
name|R_PARISC_DPREL21L
init|=
literal|0x12
block|,
name|R_PARISC_DPREL14R
init|=
literal|0x16
block|,
name|R_PARISC_DPREL14F
init|=
literal|0x17
block|,
comment|/* Data linkage table (DLT) relocation types         SOM DLT_REL fixup requests are used to for static data references        from position-independent code within shared libraries.  They are        similar to the GOT relocation types in some SVR4 implementations.  */
name|R_PARISC_DLTREL21L
init|=
literal|0x1a
block|,
name|R_PARISC_DLTREL14R
init|=
literal|0x1e
block|,
name|R_PARISC_DLTREL14F
init|=
literal|0x1f
block|,
comment|/* DLT indirect relocation types  */
name|R_PARISC_DLTIND21L
init|=
literal|0x22
block|,
name|R_PARISC_DLTIND14R
init|=
literal|0x26
block|,
name|R_PARISC_DLTIND14F
init|=
literal|0x27
block|,
comment|/* Base relative relocation types.  Ugh.  These imply lots of state */
name|R_PARISC_SETBASE
init|=
literal|0x28
block|,
name|R_PARISC_BASEREL32
init|=
literal|0x29
block|,
name|R_PARISC_BASEREL21L
init|=
literal|0x2a
block|,
name|R_PARISC_BASEREL17R
init|=
literal|0x2b
block|,
name|R_PARISC_BASEREL17F
init|=
literal|0x2c
block|,
name|R_PARISC_BASEREL14R
init|=
literal|0x2e
block|,
name|R_PARISC_BASEREL14F
init|=
literal|0x2f
block|,
comment|/* Segment relative relocation types.  */
name|R_PARISC_TEXTREL32
init|=
literal|0x31
block|,
name|R_PARISC_DATAREL32
init|=
literal|0x39
block|,
comment|/* Plabel relocation types.  */
name|R_PARISC_PLABEL32
init|=
literal|0x41
block|,
name|R_PARISC_PLABEL21L
init|=
literal|0x42
block|,
name|R_PARISC_PLABEL14R
init|=
literal|0x46
block|,
comment|/* PLT relocations.  */
name|R_PARISC_PLTIND21L
init|=
literal|0x82
block|,
name|R_PARISC_PLTIND14R
init|=
literal|0x86
block|,
name|R_PARISC_PLTIND14F
init|=
literal|0x87
block|,
comment|/* Misc relocation types.  */
name|R_PARISC_COPY
init|=
literal|0x88
block|,
name|R_PARISC_GLOB_DAT
init|=
literal|0x89
block|,
name|R_PARISC_JMP_SLOT
init|=
literal|0x8a
block|,
name|R_PARISC_RELATIVE
init|=
literal|0x8b
block|,
name|R_PARISC_UNIMPLEMENTED
block|,   }
name|elf32_hppa_reloc_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ELF_HOWTO_TABLE_SIZE
value|R_PARISC_UNIMPLEMENTED + 1
end_define

begin_define
define|#
directive|define
name|N_PARISC_RELOCS
value|R_PARISC_UNIMPLEMENTED + 1
end_define

begin_comment
comment|/* Define groups of basic relocations.  FIXME:  These should    be the only basic relocations created by GAS.  The rest    should be internal to the BFD backend.       The idea is both SOM and ELF define these basic relocation    types so they map into a SOM or ELF specific relocation     as appropriate.  This allows GAS to share much more code    between the two target object formats.  */
end_comment

begin_define
define|#
directive|define
name|R_HPPA_NONE
value|R_PARISC_NONE
end_define

begin_define
define|#
directive|define
name|R_HPPA
value|R_PARISC_DIR32
end_define

begin_define
define|#
directive|define
name|R_HPPA_GOTOFF
value|R_PARISC_DPREL21L
end_define

begin_define
define|#
directive|define
name|R_HPPA_PCREL_CALL
value|R_PARISC_PCREL21L
end_define

begin_define
define|#
directive|define
name|R_HPPA_ABS_CALL
value|R_PARISC_DIR17F
end_define

begin_define
define|#
directive|define
name|R_HPPA_COMPLEX
value|R_PARISC_UNIMPLEMENTED
end_define

begin_decl_stmt
name|elf32_hppa_reloc_type
modifier|*
modifier|*
name|hppa_elf_gen_reloc_type
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|elf32_hppa_reloc_type
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|elf32_hppa_size_stubs
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|elf32_hppa_build_stubs
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF32_HPPA_H */
end_comment

end_unit

