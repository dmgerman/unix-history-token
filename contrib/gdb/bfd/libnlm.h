begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end data structures for NLM (NetWare Loadable Modules) files.    Copyright (C) 1993 Free Software Foundation, Inc.    Written by Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBNLM_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBNLM_H_
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ARCH_SIZE
end_ifdef

begin_define
define|#
directive|define
name|NLM_ARCH_SIZE
value|ARCH_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"nlm/common.h"
end_include

begin_include
include|#
directive|include
file|"nlm/internal.h"
end_include

begin_include
include|#
directive|include
file|"nlm/external.h"
end_include

begin_comment
comment|/* A reloc for an imported NLM symbol.  Normal relocs are associated    with sections, and include a symbol.  These relocs are associated    with (undefined) symbols, and include a section.  */
end_comment

begin_struct
struct|struct
name|nlm_relent
block|{
comment|/* Section of reloc.  */
name|asection
modifier|*
name|section
decl_stmt|;
comment|/* Reloc info (sym_ptr_ptr field set only when canonicalized).  */
name|arelent
name|reloc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Information we keep for an NLM symbol.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* BFD symbol.  */
name|asymbol
name|symbol
decl_stmt|;
comment|/* Number of reloc entries for imported symbol.  */
name|bfd_size_type
name|rcnt
decl_stmt|;
comment|/* Array of reloc information for imported symbol.  */
name|struct
name|nlm_relent
modifier|*
name|relocs
decl_stmt|;
block|}
name|nlmNAME
typedef|(
name|symbol_type
typedef|);
end_typedef

begin_decl_stmt
specifier|extern
name|boolean
name|nlm_mkobject
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|nlm_set_arch_mach
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|enum
name|bfd_architecture
operator|,
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|nlmNAME
parameter_list|(
name|get_symbol_info
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|asymbol *
operator|,
function_decl|symbol_info *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|long
name|nlmNAME
parameter_list|(
name|get_symtab_upper_bound
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|long
name|nlmNAME
parameter_list|(
name|get_symtab
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|asymbol **
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|asymbol
modifier|*
name|nlmNAME
parameter_list|(
name|make_empty_symbol
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|nlmNAME
parameter_list|(
name|print_symbol
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|PTR
operator|,
function_decl|asymbol *
operator|,
function_decl|bfd_print_symbol_type
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|long
name|nlmNAME
parameter_list|(
name|get_reloc_upper_bound
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|asection *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|long
name|nlmNAME
parameter_list|(
name|canonicalize_reloc
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|asection *
operator|,
function_decl|arelent **
operator|,
function_decl|asymbol **
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
specifier|const
name|bfd_target
modifier|*
name|nlmNAME
parameter_list|(
name|object_p
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|boolean
name|nlmNAME
parameter_list|(
name|set_arch_mach
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|enum bfd_architecture
operator|,
function_decl|unsigned long
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|boolean
name|nlmNAME
parameter_list|(
name|set_section_contents
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|asection *
operator|,
function_decl|PTR
operator|,
function_decl|file_ptr
operator|,
function_decl|bfd_size_type
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|boolean
name|nlmNAME
parameter_list|(
name|write_object_contents
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Some private data is stashed away for future use using the tdata pointer    in the bfd structure.  */
end_comment

begin_struct
struct|struct
name|nlm_obj_tdata
block|{
comment|/* Actual data, but ref like ptr */
name|Nlm_Internal_Fixed_Header
name|nlm_fixed_hdr
index|[
literal|1
index|]
decl_stmt|;
name|Nlm_Internal_Variable_Header
name|nlm_variable_hdr
index|[
literal|1
index|]
decl_stmt|;
name|Nlm_Internal_Version_Header
name|nlm_version_hdr
index|[
literal|1
index|]
decl_stmt|;
name|Nlm_Internal_Copyright_Header
name|nlm_copyright_hdr
index|[
literal|1
index|]
decl_stmt|;
name|Nlm_Internal_Extended_Header
name|nlm_extended_hdr
index|[
literal|1
index|]
decl_stmt|;
name|Nlm_Internal_Custom_Header
name|nlm_custom_hdr
index|[
literal|1
index|]
decl_stmt|;
name|Nlm_Internal_Cygnus_Ext_Header
name|nlm_cygnus_ext_hdr
index|[
literal|1
index|]
decl_stmt|;
comment|/* BFD NLM symbols.  */
name|nlmNAME
argument_list|(
name|symbol_type
argument_list|)
operator|*
name|nlm_symbols
expr_stmt|;
comment|/* Lowest text and data VMA values.  */
name|bfd_vma
name|nlm_text_low
decl_stmt|;
name|bfd_vma
name|nlm_data_low
decl_stmt|;
comment|/* Caches for data read from object file.  */
name|arelent
modifier|*
name|nlm_reloc_fixups
decl_stmt|;
name|asection
modifier|*
modifier|*
name|nlm_reloc_fixup_secs
decl_stmt|;
comment|/* Backend specific information.  This should probably be a pointer,      but that would require yet another entry point to initialize the      structure.  */
union|union
block|{
struct|struct
comment|/* Alpha backend information.  */
block|{
name|bfd_vma
name|gp
decl_stmt|;
comment|/* GP value.  */
name|bfd_vma
name|lita_address
decl_stmt|;
comment|/* .lita section address.  */
name|bfd_size_type
name|lita_size
decl_stmt|;
comment|/* .lita section size.  */
block|}
name|alpha_backend_data
struct|;
block|}
name|backend_data
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nlm_tdata
parameter_list|(
name|bfd
parameter_list|)
value|((bfd) -> tdata.nlm_obj_data)
end_define

begin_define
define|#
directive|define
name|nlm_fixed_header
parameter_list|(
name|bfd
parameter_list|)
value|(nlm_tdata(bfd) -> nlm_fixed_hdr)
end_define

begin_define
define|#
directive|define
name|nlm_variable_header
parameter_list|(
name|bfd
parameter_list|)
value|(nlm_tdata(bfd) -> nlm_variable_hdr)
end_define

begin_define
define|#
directive|define
name|nlm_version_header
parameter_list|(
name|bfd
parameter_list|)
value|(nlm_tdata(bfd) -> nlm_version_hdr)
end_define

begin_define
define|#
directive|define
name|nlm_copyright_header
parameter_list|(
name|bfd
parameter_list|)
value|(nlm_tdata(bfd) -> nlm_copyright_hdr)
end_define

begin_define
define|#
directive|define
name|nlm_extended_header
parameter_list|(
name|bfd
parameter_list|)
value|(nlm_tdata(bfd) -> nlm_extended_hdr)
end_define

begin_define
define|#
directive|define
name|nlm_custom_header
parameter_list|(
name|bfd
parameter_list|)
value|(nlm_tdata(bfd) -> nlm_custom_hdr)
end_define

begin_define
define|#
directive|define
name|nlm_cygnus_ext_header
parameter_list|(
name|bfd
parameter_list|)
value|(nlm_tdata(bfd) -> nlm_cygnus_ext_hdr)
end_define

begin_define
define|#
directive|define
name|nlm_get_symbols
parameter_list|(
name|bfd
parameter_list|)
value|(nlm_tdata(bfd) -> nlm_symbols)
end_define

begin_define
define|#
directive|define
name|nlm_set_symbols
parameter_list|(
name|bfd
parameter_list|,
name|p
parameter_list|)
value|(nlm_tdata(bfd) -> nlm_symbols = (p))
end_define

begin_define
define|#
directive|define
name|nlm_set_text_low
parameter_list|(
name|bfd
parameter_list|,
name|i
parameter_list|)
value|(nlm_tdata(bfd) -> nlm_text_low = (i))
end_define

begin_define
define|#
directive|define
name|nlm_get_text_low
parameter_list|(
name|bfd
parameter_list|)
value|(nlm_tdata(bfd) -> nlm_text_low)
end_define

begin_define
define|#
directive|define
name|nlm_set_data_low
parameter_list|(
name|bfd
parameter_list|,
name|i
parameter_list|)
value|(nlm_tdata(bfd) -> nlm_data_low = (i))
end_define

begin_define
define|#
directive|define
name|nlm_get_data_low
parameter_list|(
name|bfd
parameter_list|)
value|(nlm_tdata(bfd) -> nlm_data_low)
end_define

begin_define
define|#
directive|define
name|nlm_relocation_fixups
parameter_list|(
name|bfd
parameter_list|)
value|(nlm_tdata(bfd) -> nlm_reloc_fixups)
end_define

begin_define
define|#
directive|define
name|nlm_relocation_fixup_secs
parameter_list|(
name|bfd
parameter_list|)
value|(nlm_tdata(bfd)->nlm_reloc_fixup_secs)
end_define

begin_define
define|#
directive|define
name|nlm_alpha_backend_data
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(&nlm_tdata (bfd)->backend_data.alpha_backend_data)
end_define

begin_comment
comment|/* This is used when writing out the external relocs. */
end_comment

begin_struct
struct|struct
name|reloc_and_sec
block|{
name|arelent
modifier|*
name|rel
decl_stmt|;
name|asection
modifier|*
name|sec
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* We store some function pointer in the backend structure.  This lets    different NLM targets share most of the same code, while providing    slightly different code where necessary.  */
end_comment

begin_struct
struct|struct
name|nlm_backend_data
block|{
comment|/* Signature for this backend.  */
name|char
name|signature
index|[
name|NLM_SIGNATURE_SIZE
index|]
decl_stmt|;
comment|/* Size of the fixed header.  */
name|bfd_size_type
name|fixed_header_size
decl_stmt|;
comment|/* Size of optional prefix for this backend.  Some backend may      require this to be a function, but so far a constant is OK.  This      is for a prefix which precedes the standard NLM fixed header.  */
name|bfd_size_type
name|optional_prefix_size
decl_stmt|;
comment|/* Architecture.  */
name|enum
name|bfd_architecture
name|arch
decl_stmt|;
comment|/* Machine.  */
name|long
name|mach
decl_stmt|;
comment|/* Some NLM formats do not use the uninitialized data section, so      all uninitialized data must be put into the regular data section      instead.  */
name|boolean
name|no_uninitialized_data
decl_stmt|;
comment|/* Some NLM formats have a prefix on the file.  If this function is      not NULL, it will be called by nlm_object_p.  It should return      true if this file could match this format, and it should leave      the BFD such that a bfd_read will pick up the fixed header.  */
name|boolean
argument_list|(
argument|*nlm_backend_object_p
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Write out the prefix.  This function may be NULL.  This must      write out the same number of bytes as is in the field      optional_prefix_size.  */
name|boolean
argument_list|(
argument|*nlm_write_prefix
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Read a relocation fixup from abfd.  The reloc information is      machine specific.  The second argument is the symbol if this is      an import, or NULL if this is a reloc fixup.  This function      should set the third argument to the section which the reloc      belongs in, and the fourth argument to the reloc itself; it does      not need to fill in the sym_ptr_ptr field for a reloc against an      import symbol.  */
name|boolean
argument_list|(
argument|*nlm_read_reloc
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|nlmNAME
argument_list|(
name|symbol_type
argument_list|)
operator|*
operator|,
name|asection
operator|*
operator|*
operator|,
name|arelent
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* To make objcopy to an i386 NLM work, the i386 backend needs a      chance to work over the relocs.  This is a bit icky.  */
name|boolean
argument_list|(
argument|*nlm_mangle_relocs
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|PTR
name|data
operator|,
name|bfd_vma
name|offset
operator|,
name|bfd_size_type
name|count
operator|)
argument_list|)
expr_stmt|;
comment|/* Read an import record from abfd.  It would be nice if this      were in a machine-dependent format, but it doesn't seem to be. */
name|boolean
argument_list|(
argument|*nlm_read_import
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|nlmNAME
argument_list|(
name|symbol_type
argument_list|)
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Write an import record to abfd. */
name|boolean
argument_list|(
argument|*nlm_write_import
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|arelent
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Set the section for a public symbol.  This may be NULL, in which      case a default method will be used.  */
name|boolean
argument_list|(
argument|*nlm_set_public_section
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|nlmNAME
argument_list|(
name|symbol_type
argument_list|)
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Get the offset to write out for a public symbol.  This may be      NULL, in which case a default method will be used.  */
name|bfd_vma
argument_list|(
argument|*nlm_get_public_offset
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asymbol
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Swap the fixed header in and out */
name|void
argument_list|(
argument|*nlm_swap_fhdr_in
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|Nlm_Internal_Fixed_Header
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*nlm_swap_fhdr_out
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|nlm_internal_fixed_header
operator|*
operator|,
name|PTR
operator|)
argument_list|)
expr_stmt|;
comment|/* Write out an external reference.  */
name|boolean
argument_list|(
argument|*nlm_write_external
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|bfd_size_type
operator|,
name|asymbol
operator|*
operator|,
expr|struct
name|reloc_and_sec
operator|*
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|*nlm_write_export
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asymbol
operator|*
operator|,
name|bfd_vma
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nlm_backend
parameter_list|(
name|bfd
parameter_list|)
define|\
value|((struct nlm_backend_data *)((bfd) -> xvec -> backend_data))
end_define

begin_define
define|#
directive|define
name|nlm_signature
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> signature)
end_define

begin_define
define|#
directive|define
name|nlm_fixed_header_size
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> fixed_header_size)
end_define

begin_define
define|#
directive|define
name|nlm_optional_prefix_size
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> optional_prefix_size)
end_define

begin_define
define|#
directive|define
name|nlm_architecture
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> arch)
end_define

begin_define
define|#
directive|define
name|nlm_machine
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> mach)
end_define

begin_define
define|#
directive|define
name|nlm_no_uninitialized_data
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> no_uninitialized_data)
end_define

begin_define
define|#
directive|define
name|nlm_backend_object_p_func
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> nlm_backend_object_p)
end_define

begin_define
define|#
directive|define
name|nlm_write_prefix_func
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> nlm_write_prefix)
end_define

begin_define
define|#
directive|define
name|nlm_read_reloc_func
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> nlm_read_reloc)
end_define

begin_define
define|#
directive|define
name|nlm_mangle_relocs_func
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> nlm_mangle_relocs)
end_define

begin_define
define|#
directive|define
name|nlm_read_import_func
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> nlm_read_import)
end_define

begin_define
define|#
directive|define
name|nlm_write_import_func
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> nlm_write_import)
end_define

begin_define
define|#
directive|define
name|nlm_set_public_section_func
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> nlm_set_public_section)
end_define

begin_define
define|#
directive|define
name|nlm_get_public_offset_func
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> nlm_get_public_offset)
end_define

begin_define
define|#
directive|define
name|nlm_swap_fixed_header_in_func
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> nlm_swap_fhdr_in)
end_define

begin_define
define|#
directive|define
name|nlm_swap_fixed_header_out_func
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> nlm_swap_fhdr_out)
end_define

begin_define
define|#
directive|define
name|nlm_write_external_func
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> nlm_write_external)
end_define

begin_define
define|#
directive|define
name|nlm_write_export_func
parameter_list|(
name|bfd
parameter_list|)
define|\
value|(nlm_backend(bfd) -> nlm_write_export)
end_define

begin_comment
comment|/* The NLM code, data, and uninitialized sections have no names defined    in the NLM, but bfd wants to give them names, so use the traditional    UNIX names.  */
end_comment

begin_define
define|#
directive|define
name|NLM_CODE_NAME
value|".text"
end_define

begin_define
define|#
directive|define
name|NLM_INITIALIZED_DATA_NAME
value|".data"
end_define

begin_define
define|#
directive|define
name|NLM_UNINITIALIZED_DATA_NAME
value|".bss"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBNLM_H_ */
end_comment

end_unit

