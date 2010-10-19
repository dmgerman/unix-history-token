begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ELF32/HPPA support     This file contains ELF32/HPPA relocation support as specified    in the Stratus FTX/Golf Object File Format (SED-1762) dated    February 1994.     Copyright 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1998, 1999, 2000,    2002, 2003 Free Software Foundation, Inc.     Written by:     Center for Software Science    Department of Computer Science    University of Utah     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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

begin_function_decl
name|int
name|elf32_hppa_setup_section_lists
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|elf32_hppa_next_input_section
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|elf32_hppa_size_stubs
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|,
name|bfd_signed_vma
parameter_list|,
name|asection
modifier|*
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|elf32_hppa_set_gp
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|elf32_hppa_build_stubs
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|elf_hppa_reloc_type
name|elf32_hppa_reloc_final_type
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|elf_hppa_reloc_type
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|elf_hppa_reloc_type
modifier|*
modifier|*
name|_bfd_elf32_hppa_gen_reloc_type
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|elf_hppa_reloc_type
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|asymbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF32_HPPA_H */
end_comment

end_unit

