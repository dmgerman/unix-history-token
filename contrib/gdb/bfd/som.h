begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* HP PA-RISC SOM object file format:  definitions internal to BFD.    Copyright (C) 1990, 91, 92, 93, 94 Free Software Foundation, Inc.     Contributed by the Center for Software Science at the    University of Utah (pa-gdb-bugs@cs.utah.edu).     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SOM_H
end_ifndef

begin_define
define|#
directive|define
name|_SOM_H
end_define

begin_include
include|#
directive|include
file|"../bfd/sysdep.h"
end_include

begin_include
include|#
directive|include
file|"libhppa.h"
end_include

begin_include
include|#
directive|include
file|<a.out.h>
end_include

begin_include
include|#
directive|include
file|<lst.h>
end_include

begin_include
include|#
directive|include
file|<ar.h>
end_include

begin_comment
comment|/* The SOM BFD backend doesn't currently use anything from these    two include files, but it's likely to need them in the future.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|R_DLT_REL
end_ifdef

begin_include
include|#
directive|include
file|<shl.h>
end_include

begin_include
include|#
directive|include
file|<dl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HOST_HPPABSD
argument_list|)
operator|||
name|defined
argument_list|(
name|HOST_HPPAOSF
argument_list|)
end_if

begin_comment
comment|/* BSD uses a completely different scheme for object file identification.    so for now, define _PA_RISC_ID to accept any random value for a model    number.  */
end_comment

begin_undef
undef|#
directive|undef
name|_PA_RISC_ID
end_undef

begin_define
define|#
directive|define
name|_PA_RISC_ID
parameter_list|(
name|__m_num
parameter_list|)
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HOST_HPPABSD */
end_comment

begin_define
define|#
directive|define
name|FILE_HDR_SIZE
value|sizeof(struct header)
end_define

begin_define
define|#
directive|define
name|AUX_HDR_SIZE
value|sizeof(struct som_exec_auxhdr)
end_define

begin_typedef
typedef|typedef
struct|struct
name|som_symbol
block|{
name|asymbol
name|symbol
decl_stmt|;
name|unsigned
name|int
name|som_type
decl_stmt|;
comment|/* Structured like the ELF tc_data union.  Allows more code sharing        in GAS this way.  */
union|union
block|{
name|unsigned
name|int
name|hppa_arg_reloc
decl_stmt|;
name|PTR
name|any
decl_stmt|;
block|}
name|tc_data
union|;
comment|/* Index of this symbol in the symbol table.  Only used when        building relocation streams for incomplete objects.  */
name|int
name|index
decl_stmt|;
comment|/* How many times this symbol is used in a relocation.  By sorting        the symbols from most used to least used we can significantly        reduce the size of the relocation stream for incomplete objects.  */
name|int
name|reloc_count
decl_stmt|;
comment|/* During object file writing, the offset of the name of this symbol        in the SOM string table. */
name|int
name|stringtab_offset
decl_stmt|;
block|}
name|som_symbol_type
typedef|;
end_typedef

begin_comment
comment|/* A structure containing all the magic information stored in a BFD's    private data which needs to be copied during an objcopy/strip run.  */
end_comment

begin_struct
struct|struct
name|som_exec_data
block|{
comment|/* Sort-of a magic number.  BSD uses it to distinguish between        native executables and hpux executables.  */
name|short
name|system_id
decl_stmt|;
comment|/* Magic exec flags.  These control things like whether or not        null pointer dereferencing is allowed and the like.  */
name|long
name|exec_flags
decl_stmt|;
comment|/* Add more stuff here as needed.  Good examples of information        we might want to pass would be presumed_dp, entry_* and maybe        others from the file header.  */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|somdata
block|{
comment|/* All the magic information about an executable which lives        in the private BFD structure and needs to be copied from        the input bfd to the output bfd during a objcopy/strip.  */
name|struct
name|som_exec_data
modifier|*
name|exec_data
decl_stmt|;
comment|/* These three fields are only used when writing files and are        generated from scratch.  They need not be copied for objcopy        or strip to work.  */
name|struct
name|header
modifier|*
name|file_hdr
decl_stmt|;
name|struct
name|copyright_aux_hdr
modifier|*
name|copyright_aux_hdr
decl_stmt|;
name|struct
name|user_string_aux_hdr
modifier|*
name|version_aux_hdr
decl_stmt|;
name|struct
name|som_exec_auxhdr
modifier|*
name|exec_hdr
decl_stmt|;
comment|/* Pointers to a saved copy of the symbol and string tables.  These        need not be copied for objcopy or strip to work.  */
name|som_symbol_type
modifier|*
name|symtab
decl_stmt|;
name|char
modifier|*
name|stringtab
decl_stmt|;
name|asymbol
modifier|*
modifier|*
name|sorted_syms
decl_stmt|;
comment|/* We remember these offsets so that after check_file_format, we have        no dependencies on the particular format of the exec_hdr.        These offsets need not be copied for objcopy or strip to work.  */
name|file_ptr
name|sym_filepos
decl_stmt|;
name|file_ptr
name|str_filepos
decl_stmt|;
name|file_ptr
name|reloc_filepos
decl_stmt|;
name|unsigned
name|stringtab_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|som_data_struct
block|{
name|struct
name|somdata
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Substructure of som_section_data_struct used to hold information    which can't be represented by the generic BFD section structure,    but which must be copied during objcopy or strip.  */
end_comment

begin_struct
struct|struct
name|som_copyable_section_data_struct
block|{
comment|/* Various fields in space and subspace headers that we need        to pass around.  */
name|unsigned
name|int
name|sort_key
range|:
literal|8
decl_stmt|;
name|unsigned
name|int
name|access_control_bits
range|:
literal|7
decl_stmt|;
name|unsigned
name|int
name|is_defined
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_private
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|quadrant
range|:
literal|2
decl_stmt|;
comment|/* For subspaces, this points to the section which represents the        space in which the subspace is contained.  For spaces it points        back to the section for this space.  */
name|asection
modifier|*
name|container
decl_stmt|;
comment|/* The user-specified space number.  It is wrong to use this as        an index since duplicates and holes are allowed.  */
name|int
name|space_number
decl_stmt|;
comment|/* Add more stuff here as needed.  Good examples of information        we might want to pass would be initialization pointers,         and the many subspace flags we do not represent yet.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Used to keep extra SOM specific information for a given section.     reloc_size holds the size of the relocation stream, note this    is very different from the number of relocations as SOM relocations    are variable length.      reloc_stream is the actual stream of relocation entries.  */
end_comment

begin_struct
struct|struct
name|som_section_data_struct
block|{
name|struct
name|som_copyable_section_data_struct
modifier|*
name|copy_data
decl_stmt|;
name|unsigned
name|int
name|reloc_size
decl_stmt|;
name|char
modifier|*
name|reloc_stream
decl_stmt|;
name|struct
name|space_dictionary_record
modifier|*
name|space_dict
decl_stmt|;
name|struct
name|subspace_dictionary_record
modifier|*
name|subspace_dict
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|somdata
parameter_list|(
name|bfd
parameter_list|)
value|((bfd)->tdata.som_data->a)
end_define

begin_define
define|#
directive|define
name|obj_som_exec_data
parameter_list|(
name|bfd
parameter_list|)
value|(somdata(bfd).exec_data)
end_define

begin_define
define|#
directive|define
name|obj_som_file_hdr
parameter_list|(
name|bfd
parameter_list|)
value|(somdata(bfd).file_hdr)
end_define

begin_define
define|#
directive|define
name|obj_som_exec_hdr
parameter_list|(
name|bfd
parameter_list|)
value|(somdata(bfd).exec_hdr)
end_define

begin_define
define|#
directive|define
name|obj_som_copyright_hdr
parameter_list|(
name|bfd
parameter_list|)
value|(somdata(bfd).copyright_aux_hdr)
end_define

begin_define
define|#
directive|define
name|obj_som_version_hdr
parameter_list|(
name|bfd
parameter_list|)
value|(somdata(bfd).version_aux_hdr)
end_define

begin_define
define|#
directive|define
name|obj_som_symtab
parameter_list|(
name|bfd
parameter_list|)
value|(somdata(bfd).symtab)
end_define

begin_define
define|#
directive|define
name|obj_som_stringtab
parameter_list|(
name|bfd
parameter_list|)
value|(somdata(bfd).stringtab)
end_define

begin_define
define|#
directive|define
name|obj_som_sym_filepos
parameter_list|(
name|bfd
parameter_list|)
value|(somdata(bfd).sym_filepos)
end_define

begin_define
define|#
directive|define
name|obj_som_str_filepos
parameter_list|(
name|bfd
parameter_list|)
value|(somdata(bfd).str_filepos)
end_define

begin_define
define|#
directive|define
name|obj_som_stringtab_size
parameter_list|(
name|bfd
parameter_list|)
value|(somdata(bfd).stringtab_size)
end_define

begin_define
define|#
directive|define
name|obj_som_reloc_filepos
parameter_list|(
name|bfd
parameter_list|)
value|(somdata(bfd).reloc_filepos)
end_define

begin_define
define|#
directive|define
name|obj_som_sorted_syms
parameter_list|(
name|bfd
parameter_list|)
value|(somdata(bfd).sorted_syms)
end_define

begin_define
define|#
directive|define
name|som_section_data
parameter_list|(
name|sec
parameter_list|)
define|\
value|((struct som_section_data_struct *)sec->used_by_bfd)
end_define

begin_define
define|#
directive|define
name|som_symbol_data
parameter_list|(
name|symbol
parameter_list|)
value|((som_symbol_type *) symbol)
end_define

begin_comment
comment|/* Defines groups of basic relocations.  FIXME:  These should    be the only basic relocations created by GAS.  The rest    should be internal to the BFD backend.     The idea is both SOM and ELF define these basic relocation    types so they map into a SOM or ELF specific reloation as    appropriate.  This allows GAS to share much more code     between the two object formats.  */
end_comment

begin_define
define|#
directive|define
name|R_HPPA_NONE
value|R_NO_RELOCATION
end_define

begin_define
define|#
directive|define
name|R_HPPA
value|R_CODE_ONE_SYMBOL
end_define

begin_define
define|#
directive|define
name|R_HPPA_PCREL_CALL
value|R_PCREL_CALL
end_define

begin_define
define|#
directive|define
name|R_HPPA_ABS_CALL
value|R_ABS_CALL
end_define

begin_define
define|#
directive|define
name|R_HPPA_GOTOFF
value|R_DP_RELATIVE
end_define

begin_define
define|#
directive|define
name|R_HPPA_ENTRY
value|R_ENTRY
end_define

begin_define
define|#
directive|define
name|R_HPPA_EXIT
value|R_EXIT
end_define

begin_define
define|#
directive|define
name|R_HPPA_COMPLEX
value|R_COMP1
end_define

begin_define
define|#
directive|define
name|R_HPPA_BEGIN_BRTAB
value|R_BEGIN_BRTAB
end_define

begin_define
define|#
directive|define
name|R_HPPA_END_BRTAB
value|R_END_BRTAB
end_define

begin_comment
comment|/* Exported functions, mostly for use by GAS.  */
end_comment

begin_decl_stmt
name|boolean
name|bfd_som_set_section_attributes
name|PARAMS
argument_list|(
operator|(
name|asection
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|unsigned
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|bfd_som_set_subsection_attributes
name|PARAMS
argument_list|(
operator|(
name|asection
operator|*
operator|,
name|asection
operator|*
operator|,
name|int
operator|,
name|unsigned
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bfd_som_set_symbol_type
name|PARAMS
argument_list|(
operator|(
name|asymbol
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|bfd_som_attach_aux_hdr
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
modifier|*
name|hppa_som_gen_reloc_type
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|enum
name|hppa_reloc_field_selector_type_alt
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SOM_H */
end_comment

end_unit

