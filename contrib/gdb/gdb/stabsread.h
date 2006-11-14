begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Include file for stabs debugging format support functions.    Copyright 1986, 1987, 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995,    1996, 1997, 1999, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_struct_decl
struct_decl|struct
name|objfile
struct_decl|;
end_struct_decl

begin_comment
comment|/* Definitions, prototypes, etc for stabs debugging format support    functions.     Variables declared in this file can be defined by #define-ing    the name EXTERN to null.  It is used to declare variables that    are normally extern, but which get defined in a single module    using this technique.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXTERN
end_ifndef

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Hash table of global symbols whose values are not known yet.    They are chained thru the SYMBOL_VALUE_CHAIN, since we don't    have the correct data for that slot yet.     The use of the LOC_BLOCK code in this chain is nonstandard--    it refers to a FORTRAN common block rather than the usual meaning, and    the such LOC_BLOCK symbols use their fields in nonstandard ways.  */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|symbol
modifier|*
name|global_sym_chain
index|[
name|HASHSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|common_block_start
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|common_block_end
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Kludge for xcoffread.c */
end_comment

begin_struct
struct|struct
name|pending_stabs
block|{
name|int
name|count
decl_stmt|;
name|int
name|length
decl_stmt|;
name|char
modifier|*
name|stab
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|EXTERN
name|struct
name|pending_stabs
modifier|*
name|global_stabs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The type code that process_one_symbol saw on its previous invocation.    Used to detect pairs of N_SO symbols. */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|previous_stab_code
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Support for Sun changes to dbx symbol format */
end_comment

begin_comment
comment|/* For each identified header file, we have a table of types defined    in that header file.     header_files maps header file names to their type tables.    It is a vector of n_header_files elements.    Each element describes one header file.    It contains a vector of types.     Sometimes it can happen that the same header file produces    different results when included in different places.    This can result from conditionals or from different    things done before including the file.    When this happens, there are multiple entries for the file in this table,    one entry for each distinct set of results.    The entries are distinguished by the INSTANCE field.    The INSTANCE field appears in the N_BINCL and N_EXCL symbol table and is    used to match header-file references to their corresponding data.  */
end_comment

begin_struct
struct|struct
name|header_file
block|{
comment|/* Name of header file */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Numeric code distinguishing instances of one header file that produced        different results when included.  It comes from the N_BINCL or N_EXCL. */
name|int
name|instance
decl_stmt|;
comment|/* Pointer to vector of types */
name|struct
name|type
modifier|*
modifier|*
name|vector
decl_stmt|;
comment|/* Allocated length (# elts) of that vector */
name|int
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The table of header_files of this OBJFILE. */
end_comment

begin_define
define|#
directive|define
name|HEADER_FILES
parameter_list|(
name|OBJFILE
parameter_list|)
value|(DBX_SYMFILE_INFO (OBJFILE)->header_files)
end_define

begin_comment
comment|/* The actual length of HEADER_FILES. */
end_comment

begin_define
define|#
directive|define
name|N_HEADER_FILES
parameter_list|(
name|OBJFILE
parameter_list|)
value|(DBX_SYMFILE_INFO (OBJFILE)->n_header_files)
end_define

begin_comment
comment|/* The allocated lengh of HEADER_FILES. */
end_comment

begin_define
define|#
directive|define
name|N_ALLOCATED_HEADER_FILES
parameter_list|(
name|OBJFILE
parameter_list|)
define|\
value|(DBX_SYMFILE_INFO (OBJFILE)->n_allocated_header_files)
end_define

begin_comment
comment|/* Within each object file, various header files are assigned numbers.    A type is defined or referred to with a pair of numbers    (FILENUM,TYPENUM) where FILENUM is the number of the header file    and TYPENUM is the number within that header file.    TYPENUM is the index within the vector of types for that header file.     FILENUM == 0 is special; it refers to the main source of the object file,    and not to any header file.  FILENUM != 1 is interpreted by looking it up    in the following table, which contains indices in header_files.  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
modifier|*
name|this_object_header_files
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|n_this_object_header_files
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|n_allocated_this_object_header_files
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|cleanup_undefined_types
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|read_number
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|define_symbol
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stabsread_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stabsread_new_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|start_stabs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|end_stabs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_global_stabs
parameter_list|(
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* COFF files can have multiple .stab sections, if they are linked    using --split-by-reloc.  This linked list is used to pass the    information into the functions in dbxread.c.  */
end_comment

begin_struct
struct|struct
name|stab_section_list
block|{
comment|/* Next in list.  */
name|struct
name|stab_section_list
modifier|*
name|next
decl_stmt|;
comment|/* Stab section.  */
name|asection
modifier|*
name|section
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Functions exported by dbxread.c.  These are not in stabsread.c because    they are only used by some stabs readers.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|partial_symtab
modifier|*
name|end_psymtab
parameter_list|(
name|struct
name|partial_symtab
modifier|*
name|pst
parameter_list|,
name|char
modifier|*
modifier|*
name|include_list
parameter_list|,
name|int
name|num_includes
parameter_list|,
name|int
name|capping_symbol_offset
parameter_list|,
name|CORE_ADDR
name|capping_text
parameter_list|,
name|struct
name|partial_symtab
modifier|*
modifier|*
name|dependency_list
parameter_list|,
name|int
name|number_dependencies
parameter_list|,
name|int
name|textlow_not_set
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|process_one_symbol
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|CORE_ADDR
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|section_offsets
modifier|*
parameter_list|,
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|elfstab_build_psymtabs
parameter_list|(
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|,
name|int
name|mainline
parameter_list|,
name|asection
modifier|*
name|stabsect
parameter_list|,
name|file_ptr
name|stabstroffset
parameter_list|,
name|unsigned
name|int
name|stabstrsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|coffstab_build_psymtabs
parameter_list|(
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|,
name|int
name|mainline
parameter_list|,
name|CORE_ADDR
name|textaddr
parameter_list|,
name|unsigned
name|int
name|textsize
parameter_list|,
name|struct
name|stab_section_list
modifier|*
name|stabs
parameter_list|,
name|file_ptr
name|stabstroffset
parameter_list|,
name|unsigned
name|int
name|stabstrsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stabsect_build_psymtabs
parameter_list|(
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|,
name|int
name|mainline
parameter_list|,
name|char
modifier|*
name|stab_name
parameter_list|,
name|char
modifier|*
name|stabstr_name
parameter_list|,
name|char
modifier|*
name|text_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|elfstab_offset_sections
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|,
name|struct
name|partial_symtab
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|symbol_reference_defined
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ref_add
parameter_list|(
name|int
parameter_list|,
name|struct
name|symbol
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|ref_search
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_header_files
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_header_files
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|EXTERN
end_undef

end_unit

