begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* A -*- C -*- header file for the bfd library    Copyright 1990, 1991, 1992 Free Software Foundation, Inc.    Contributed by Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* bfd.h -- The only header file required by users of the bfd library   This file is generated from various .c files, if you change it, your bits may be lost.  All the prototypes and definitions following the comment "THE FOLLOWING IS EXTRACTED FROM THE SOURCE" are extracted from the source files for BFD.  If you change it, someone oneday will extract it from the source again, and your changes will be lost.  To save yourself from this bind, change the definitions in the source in the bfd directory.  Type "make docs" and then "make headers" in that directory, and magically this file will change to reflect your changes.  If you don't have the tools to perform the extraction, then you are safe from someone on your system trampling over your header files. You should still maintain the equivalence between the source and this file though; every change you make to the .c file should be reflected here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BFD_H_SEEN__
end_ifndef

begin_define
define|#
directive|define
name|__BFD_H_SEEN__
end_define

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"obstack.h"
end_include

begin_comment
comment|/* Make it easier to declare prototypes (puts conditional here) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROTO
end_ifndef

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|,
name|arglist
parameter_list|)
value|type name arglist
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|,
name|arglist
parameter_list|)
value|type name ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BFD_VERSION
value|"2.0"
end_define

begin_comment
comment|/* forward declaration */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_bfd
name|bfd
typedef|;
end_typedef

begin_comment
comment|/* General rules: functions which are boolean return true on success    and false on failure (unless they're a predicate).   -- bfd.doc */
end_comment

begin_comment
comment|/* I'm sure this is going to break something and someone is going to    force me to change it. */
end_comment

begin_comment
comment|/* typedef enum boolean {false, true} boolean; */
end_comment

begin_comment
comment|/* Yup, SVR4 has a "typedef enum boolean" in<sys/types.h>  -fnf */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|bfd_boolean
block|{
name|false
block|,
name|true
block|}
name|boolean
typedef|;
end_typedef

begin_comment
comment|/* A pointer to a position in a file.  */
end_comment

begin_comment
comment|/* FIXME:  This should be using off_t from<sys/types.h>.    For now, try to avoid breaking stuff by not including<sys/types.h> here.    This will break on systems with 64-bit file offsets (e.g. 4.4BSD).    Probably the best long-term answer is to avoid using file_ptr AND off_t     in this header file, and to handle this in the BFD implementation    rather than in its interface.  */
end_comment

begin_comment
comment|/* typedef off_t	file_ptr; */
end_comment

begin_typedef
typedef|typedef
name|long
name|int
name|file_ptr
typedef|;
end_typedef

begin_comment
comment|/* Support for different sizes of target format ints and addresses */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HOST_64_BIT
end_ifdef

begin_typedef
typedef|typedef
name|HOST_64_BIT
name|rawdata_offset
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|HOST_64_BIT
name|bfd_vma
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|HOST_64_BIT
name|bfd_word
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|HOST_64_BIT
name|bfd_offset
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|HOST_64_BIT
name|bfd_size_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|HOST_64_BIT
name|symvalue
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|HOST_64_BIT
name|bfd_64_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fprintf_vma
parameter_list|(
name|s
parameter_list|,
name|x
parameter_list|)
define|\
value|fprintf(s,"%08x%08x", uint64_typeHIGH(x), uint64_typeLOW(x))
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
name|bfd_64_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|rawdata_offset
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|bfd_vma
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|bfd_offset
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|bfd_word
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|bfd_size
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|symvalue
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|bfd_size_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fprintf_vma
parameter_list|(
name|s
parameter_list|,
name|x
parameter_list|)
value|fprintf(s, "%08lx", x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|printf_vma
parameter_list|(
name|x
parameter_list|)
value|fprintf_vma(stdout,x)
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|flagword
typedef|;
end_typedef

begin_comment
comment|/* 32 bits of flags */
end_comment

begin_escape
end_escape

begin_comment
comment|/** File formats */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|bfd_format
block|{
name|bfd_unknown
init|=
literal|0
block|,
comment|/* file format is unknown */
name|bfd_object
block|,
comment|/* linker/assember/compiler output */
name|bfd_archive
block|,
comment|/* object archive file */
name|bfd_core
block|,
comment|/* core dump */
name|bfd_type_end
block|}
comment|/* marks the end; don't use it! */
name|bfd_format
typedef|;
end_typedef

begin_comment
comment|/* Object file flag values */
end_comment

begin_define
define|#
directive|define
name|NO_FLAGS
value|0x00
end_define

begin_define
define|#
directive|define
name|HAS_RELOC
value|0x01
end_define

begin_define
define|#
directive|define
name|EXEC_P
value|0x02
end_define

begin_define
define|#
directive|define
name|HAS_LINENO
value|0x04
end_define

begin_define
define|#
directive|define
name|HAS_DEBUG
value|0x08
end_define

begin_define
define|#
directive|define
name|HAS_SYMS
value|0x10
end_define

begin_define
define|#
directive|define
name|HAS_LOCALS
value|0x20
end_define

begin_define
define|#
directive|define
name|DYNAMIC
value|0x40
end_define

begin_define
define|#
directive|define
name|WP_TEXT
value|0x80
end_define

begin_define
define|#
directive|define
name|D_PAGED
value|0x100
end_define

begin_define
define|#
directive|define
name|BFD_IS_RELAXABLE
value|0x200
end_define

begin_escape
end_escape

begin_comment
comment|/* symbols and relocation */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|symindex
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BFD_NO_MORE_SYMBOLS
value|((symindex) ~0)
end_define

begin_typedef
typedef|typedef
enum|enum
name|bfd_symclass
block|{
name|bfd_symclass_unknown
init|=
literal|0
block|,
name|bfd_symclass_fcommon
block|,
comment|/* fortran common symbols */
name|bfd_symclass_global
block|,
comment|/* global symbol, what a surprise */
name|bfd_symclass_debugger
block|,
comment|/* some debugger symbol */
name|bfd_symclass_undefined
comment|/* none known */
block|}
name|symclass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|symtype
typedef|;
end_typedef

begin_comment
comment|/* Who knows, yet? */
end_comment

begin_comment
comment|/* general purpose part of a symbol;    target specific parts will be found in libcoff.h, liba.out.h etc */
end_comment

begin_define
define|#
directive|define
name|bfd_get_section
parameter_list|(
name|x
parameter_list|)
value|((x)->section)
end_define

begin_define
define|#
directive|define
name|bfd_get_output_section
parameter_list|(
name|x
parameter_list|)
value|((x)->section->output_section)
end_define

begin_define
define|#
directive|define
name|bfd_set_section
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)->section) = (y)
end_define

begin_define
define|#
directive|define
name|bfd_asymbol_base
parameter_list|(
name|x
parameter_list|)
value|((x)->section?((x)->section->vma):0)
end_define

begin_define
define|#
directive|define
name|bfd_asymbol_value
parameter_list|(
name|x
parameter_list|)
value|(bfd_asymbol_base(x) + x->value)
end_define

begin_define
define|#
directive|define
name|bfd_asymbol_name
parameter_list|(
name|x
parameter_list|)
value|((x)->name)
end_define

begin_comment
comment|/* This is a type pun with struct ranlib on purpose! */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|carsym
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|file_ptr
name|file_offset
decl_stmt|;
comment|/* look here to find the file */
block|}
name|carsym
typedef|;
end_typedef

begin_comment
comment|/* to make these you call a carsymogen */
end_comment

begin_comment
comment|/* Used in generating armaps.  Perhaps just a forward definition would do? */
end_comment

begin_struct
struct|struct
name|orl
block|{
comment|/* output ranlib */
name|char
modifier|*
modifier|*
name|name
decl_stmt|;
comment|/* symbol name */
name|file_ptr
name|pos
decl_stmt|;
comment|/* bfd* or file position */
name|int
name|namidx
decl_stmt|;
comment|/* index into string table */
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Linenumber stuff */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|lineno_cache_entry
block|{
name|unsigned
name|int
name|line_number
decl_stmt|;
comment|/* Linenumber from start of function*/
union|union
block|{
name|struct
name|symbol_cache_entry
modifier|*
name|sym
decl_stmt|;
comment|/* Function name */
name|unsigned
name|long
name|offset
decl_stmt|;
comment|/* Offset into section */
block|}
name|u
union|;
block|}
name|alent
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* object and core file sections */
end_comment

begin_define
define|#
directive|define
name|align_power
parameter_list|(
name|addr
parameter_list|,
name|align
parameter_list|)
define|\
value|( ((addr) + ((1<<(align))-1))& (-1<< (align)))
end_define

begin_typedef
typedef|typedef
name|struct
name|sec
modifier|*
name|sec_ptr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|bfd_get_section_name
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|((ptr)->name + 0)
end_define

begin_define
define|#
directive|define
name|bfd_get_section_vma
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|((ptr)->vma + 0)
end_define

begin_define
define|#
directive|define
name|bfd_get_section_alignment
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|((ptr)->alignment_power + 0)
end_define

begin_define
define|#
directive|define
name|bfd_section_name
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|((ptr)->name)
end_define

begin_define
define|#
directive|define
name|bfd_section_size
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|(bfd_get_section_size_before_reloc(ptr))
end_define

begin_define
define|#
directive|define
name|bfd_section_vma
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|((ptr)->vma)
end_define

begin_define
define|#
directive|define
name|bfd_section_alignment
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|((ptr)->alignment_power)
end_define

begin_define
define|#
directive|define
name|bfd_get_section_flags
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|((ptr)->flags + 0)
end_define

begin_define
define|#
directive|define
name|bfd_get_section_userdata
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|((ptr)->userdata)
end_define

begin_define
define|#
directive|define
name|bfd_set_section_vma
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|)
value|(((ptr)->vma = (val)), ((ptr)->user_set_vma = true), true)
end_define

begin_define
define|#
directive|define
name|bfd_set_section_alignment
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|)
value|(((ptr)->alignment_power = (val)),true)
end_define

begin_define
define|#
directive|define
name|bfd_set_section_userdata
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|)
value|(((ptr)->userdata = (val)),true)
end_define

begin_typedef
typedef|typedef
name|struct
name|stat
name|stat_type
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/** Error handling */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|bfd_error
block|{
name|no_error
init|=
literal|0
block|,
name|system_call_error
block|,
name|invalid_target
block|,
name|wrong_format
block|,
name|invalid_operation
block|,
name|no_memory
block|,
name|no_symbols
block|,
name|no_relocation_info
block|,
name|no_more_archived_files
block|,
name|malformed_archive
block|,
name|symbol_not_found
block|,
name|file_not_recognized
block|,
name|file_ambiguously_recognized
block|,
name|no_contents
block|,
name|bfd_error_nonrepresentable_section
block|,
name|no_debug_section
block|,
name|bad_value
block|,
name|invalid_error_code
block|}
name|bfd_ec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|bfd_ec
name|bfd_error
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|reloc_cache_entry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bfd_seclet_struct
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|bfd_error_vector
block|{
name|PROTO
argument_list|(
name|void
argument_list|,
operator|(
operator|*
name|nonrepresentable_section
operator|)
argument_list|,
operator|(
name|CONST
name|bfd
operator|*
name|CONST
name|abfd
operator|,
name|CONST
name|char
operator|*
name|CONST
name|name
operator|)
argument_list|)
expr_stmt|;
name|PROTO
argument_list|(
name|void
argument_list|,
operator|(
operator|*
name|undefined_symbol
operator|)
argument_list|,
operator|(
name|CONST
expr|struct
name|reloc_cache_entry
operator|*
name|rel
operator|,
name|CONST
expr|struct
name|bfd_seclet_struct
operator|*
name|sec
operator|)
argument_list|)
expr_stmt|;
name|PROTO
argument_list|(
name|void
argument_list|,
operator|(
operator|*
name|reloc_value_truncated
operator|)
argument_list|,
operator|(
name|CONST
expr|struct
name|reloc_cache_entry
operator|*
name|rel
operator|,
expr|struct
name|bfd_seclet_struct
operator|*
name|sec
operator|)
argument_list|)
expr_stmt|;
name|PROTO
argument_list|(
name|void
argument_list|,
operator|(
operator|*
name|reloc_dangerous
operator|)
argument_list|,
operator|(
name|CONST
expr|struct
name|reloc_cache_entry
operator|*
name|rel
operator|,
name|CONST
expr|struct
name|bfd_seclet_struct
operator|*
name|sec
operator|)
argument_list|)
expr_stmt|;
block|}
name|bfd_error_vector_type
typedef|;
end_typedef

begin_macro
name|PROTO
argument_list|(
argument|CONST char *
argument_list|,
argument|bfd_errmsg
argument_list|,
argument|(bfd_ec error_tag)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|PROTO
argument_list|(
name|void
argument_list|,
name|bfd_perror
argument_list|,
operator|(
name|CONST
name|char
operator|*
name|message
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_escape
end_escape

begin_typedef
typedef|typedef
enum|enum
name|bfd_print_symbol
block|{
name|bfd_print_symbol_name
block|,
name|bfd_print_symbol_more
block|,
name|bfd_print_symbol_all
block|,
name|bfd_print_symbol_nm
comment|/* Pretty format suitable for nm program. */
block|}
name|bfd_print_symbol_type
typedef|;
end_typedef

begin_escape
end_escape

begin_escape
end_escape

begin_comment
comment|/* The code that implements targets can initialize a jump table with this    macro.  It must name all its routines the same way (a prefix plus    the standard routine suffix), or it must #define the routines that    are not so named, before calling JUMP_TABLE in the initializer.  */
end_comment

begin_comment
comment|/* Semi-portable string concatenation in cpp */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CAT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|CAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a##b
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a
comment|/**/
value|b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|JUMP_TABLE
parameter_list|(
name|NAME
parameter_list|)
define|\
value|CAT(NAME,_core_file_failing_command),\ CAT(NAME,_core_file_failing_signal),\ CAT(NAME,_core_file_matches_executable_p),\ CAT(NAME,_slurp_armap),\ CAT(NAME,_slurp_extended_name_table),\ CAT(NAME,_truncate_arname),\ CAT(NAME,_write_armap),\ CAT(NAME,_close_and_cleanup),	\ CAT(NAME,_set_section_contents),\ CAT(NAME,_get_section_contents),\ CAT(NAME,_new_section_hook),\ CAT(NAME,_get_symtab_upper_bound),\ CAT(NAME,_get_symtab),\ CAT(NAME,_get_reloc_upper_bound),\ CAT(NAME,_canonicalize_reloc),\ CAT(NAME,_make_empty_symbol),\ CAT(NAME,_print_symbol),\ CAT(NAME,_get_lineno),\ CAT(NAME,_set_arch_mach),\ CAT(NAME,_openr_next_archived_file),\ CAT(NAME,_find_nearest_line),\ CAT(NAME,_generic_stat_arch_elt),\ CAT(NAME,_sizeof_headers),\ CAT(NAME,_bfd_debug_info_start),\ CAT(NAME,_bfd_debug_info_end),\ CAT(NAME,_bfd_debug_info_accumulate),\ CAT(NAME,_bfd_get_relocated_section_contents),\ CAT(NAME,_bfd_relax_section)
end_define

begin_define
define|#
directive|define
name|COFF_SWAP_TABLE
define|\
value|coff_swap_aux_in, coff_swap_sym_in, coff_swap_lineno_in, \  coff_swap_aux_out, coff_swap_sym_out, \  coff_swap_lineno_out, coff_swap_reloc_out, \  coff_swap_filehdr_out, coff_swap_aouthdr_out, \  coff_swap_scnhdr_out
end_define

begin_escape
end_escape

begin_comment
comment|/* User program access to BFD facilities */
end_comment

begin_decl_stmt
specifier|extern
name|CONST
name|short
name|_bfd_host_big_endian
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER_BIG_P
value|(*(char *)&_bfd_host_big_endian)
end_define

begin_comment
comment|/* The bfd itself */
end_comment

begin_comment
comment|/* Cast from const char * to char * so that caller can assign to    a char * without a warning.  */
end_comment

begin_define
define|#
directive|define
name|bfd_get_filename
parameter_list|(
name|abfd
parameter_list|)
value|((char *) (abfd)->filename)
end_define

begin_define
define|#
directive|define
name|bfd_get_format
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->format)
end_define

begin_define
define|#
directive|define
name|bfd_get_target
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->xvec->name)
end_define

begin_define
define|#
directive|define
name|bfd_get_file_flags
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->flags)
end_define

begin_define
define|#
directive|define
name|bfd_applicable_file_flags
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->xvec->object_flags)
end_define

begin_define
define|#
directive|define
name|bfd_applicable_section_flags
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->xvec->section_flags)
end_define

begin_define
define|#
directive|define
name|bfd_my_archive
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->my_archive)
end_define

begin_define
define|#
directive|define
name|bfd_has_map
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->has_armap)
end_define

begin_define
define|#
directive|define
name|bfd_header_twiddle_required
parameter_list|(
name|abfd
parameter_list|)
define|\
value|((((abfd)->xvec->header_byteorder_big_p)		\ 	  != (boolean)HOST_BYTE_ORDER_BIG_P) ? true:false)
end_define

begin_define
define|#
directive|define
name|bfd_valid_reloc_types
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->xvec->valid_reloc_types)
end_define

begin_define
define|#
directive|define
name|bfd_usrdata
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->usrdata)
end_define

begin_define
define|#
directive|define
name|bfd_get_start_address
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->start_address)
end_define

begin_define
define|#
directive|define
name|bfd_get_symcount
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->symcount)
end_define

begin_define
define|#
directive|define
name|bfd_get_outsymbols
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->outsymbols)
end_define

begin_define
define|#
directive|define
name|bfd_count_sections
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->section_count)
end_define

begin_define
define|#
directive|define
name|bfd_get_architecture
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->obj_arch)
end_define

begin_define
define|#
directive|define
name|bfd_get_machine
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->obj_machine)
end_define

begin_define
define|#
directive|define
name|bfd_get_symbol_leading_char
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->xvec->symbol_leading_char)
end_define

begin_define
define|#
directive|define
name|BYTE_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|SHORT_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|LONG_SIZE
value|4
end_define

begin_comment
comment|/* And more from the source.  */
end_comment

end_unit

