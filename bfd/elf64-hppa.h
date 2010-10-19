begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ELF64/HPPA support     Copyright 1999, 2000, 2002 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF64_HPPA_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF64_HPPA_H
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

begin_decl_stmt
name|elf_hppa_reloc_type
name|elf64_hppa_reloc_final_type
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|elf_hppa_reloc_type
operator|,
name|int
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|elf_hppa_reloc_type
modifier|*
modifier|*
name|_bfd_elf64_hppa_gen_reloc_type
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|elf_hppa_reloc_type
operator|,
name|int
operator|,
name|unsigned
name|int
operator|,
name|int
operator|,
name|asymbol
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define groups of basic relocations.  FIXME:  These should    be the only basic relocations created by GAS.  The rest    should be internal to the BFD backend.     The idea is both SOM and ELF define these basic relocation    types so they map into a SOM or ELF specific relocation    as appropriate.  This allows GAS to share much more code    between the two target object formats.  */
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
value|R_PARISC_DIR64
end_define

begin_define
define|#
directive|define
name|R_HPPA_GOTOFF
value|R_PARISC_DLTREL21L
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF64_HPPA_H */
end_comment

end_unit

