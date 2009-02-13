begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for reading symbol files into GDB.     Copyright 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SYMFILE_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYMFILE_H
end_define

begin_comment
comment|/* This file requires that you first include "bfd.h".  */
end_comment

begin_comment
comment|/* Opaque declarations.  */
end_comment

begin_struct_decl
struct_decl|struct
name|section_table
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|objfile
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|obstack
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|block
struct_decl|;
end_struct_decl

begin_comment
comment|/* Partial symbols are stored in the psymbol_cache and pointers to    them are kept in a dynamically grown array that is obtained from    malloc and grown as necessary via realloc.  Each objfile typically    has two of these, one for global symbols and one for static    symbols.  Although this adds a level of indirection for storing or    accessing the partial symbols, it allows us to throw away duplicate    psymbols and set all pointers to the single saved instance.  */
end_comment

begin_struct
struct|struct
name|psymbol_allocation_list
block|{
comment|/* Pointer to beginning of dynamically allocated array of pointers      to partial symbols.  The array is dynamically expanded as      necessary to accommodate more pointers.  */
name|struct
name|partial_symbol
modifier|*
modifier|*
name|list
decl_stmt|;
comment|/* Pointer to next available slot in which to store a pointer to a      partial symbol.  */
name|struct
name|partial_symbol
modifier|*
modifier|*
name|next
decl_stmt|;
comment|/* Number of allocated pointer slots in current dynamic array (not      the number of bytes of storage).  The "next" pointer will always      point somewhere between list[0] and list[size], and when at      list[size] the array will be expanded on the next attempt to      store a pointer.  */
name|int
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Define an array of addresses to accommodate non-contiguous dynamic    loading of modules.  This is for use when entering commands, so we    can keep track of the section names until we read the file and can    map them to bfd sections.  This structure is also used by solib.c    to communicate the section addresses in shared objects to    symbol_file_add ().  */
end_comment

begin_struct
struct|struct
name|section_addr_info
block|{
comment|/* The number of sections for which address information is      available.  */
name|size_t
name|num_sections
decl_stmt|;
comment|/* Sections whose names are file format dependent. */
struct|struct
name|other_sections
block|{
name|CORE_ADDR
name|addr
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|sectindex
decl_stmt|;
block|}
name|other
index|[
literal|1
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure to keep track of symbol reading functions for various    object file types.  */
end_comment

begin_struct
struct|struct
name|sym_fns
block|{
comment|/* BFD flavour that we handle, or (as a special kludge, see      xcoffread.c, (enum bfd_flavour)-1 for xcoff).  */
name|enum
name|bfd_flavour
name|sym_flavour
decl_stmt|;
comment|/* Initializes anything that is global to the entire symbol table.      It is called during symbol_file_add, when we begin debugging an      entirely new program.  */
name|void
function_decl|(
modifier|*
name|sym_new_init
function_decl|)
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
comment|/* Reads any initial information from a symbol file, and initializes      the struct sym_fns SF in preparation for sym_read().  It is      called every time we read a symbol file for any reason.  */
name|void
function_decl|(
modifier|*
name|sym_init
function_decl|)
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
comment|/* sym_read (objfile, mainline) Reads a symbol file into a psymtab      (or possibly a symtab).  OBJFILE is the objfile struct for the      file we are reading.  MAINLINE is 1 if this is the main symbol      table being read, and 0 if a secondary symbol file (e.g. shared      library or dynamically loaded file) is being read.  */
name|void
function_decl|(
modifier|*
name|sym_read
function_decl|)
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Called when we are finished with an objfile.  Should do all      cleanup that is specific to the object file format for the      particular objfile.  */
name|void
function_decl|(
modifier|*
name|sym_finish
function_decl|)
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
comment|/* This function produces a file-dependent section_offsets      structure, allocated in the objfile's storage, and based on the      parameter.  The parameter is currently a CORE_ADDR (FIXME!) for      backward compatibility with the higher levels of GDB.  It should      probably be changed to a string, where NULL means the default,      and others are parsed in a file dependent way.  */
name|void
function_decl|(
modifier|*
name|sym_offsets
function_decl|)
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|,
name|struct
name|section_addr_info
modifier|*
parameter_list|)
function_decl|;
comment|/* Finds the next struct sym_fns.  They are allocated and      initialized in whatever module implements the functions pointed      to; an initializer calls add_symtab_fns to add them to the global      chain.  */
name|struct
name|sym_fns
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The default version of sym_fns.sym_offsets for readers that don't    do anything special.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|default_symfile_offsets
parameter_list|(
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|,
name|struct
name|section_addr_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|extend_psymbol_list
parameter_list|(
name|struct
name|psymbol_allocation_list
modifier|*
parameter_list|,
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add any kind of symbol to a psymbol_allocation_list.  */
end_comment

begin_comment
comment|/* #include "demangle.h" */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|struct
name|partial_symbol
modifier|*
name|add_psymbol_to_list
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|domain_enum
parameter_list|,
name|enum
name|address_class
parameter_list|,
name|struct
name|psymbol_allocation_list
modifier|*
parameter_list|,
name|long
parameter_list|,
name|CORE_ADDR
parameter_list|,
name|enum
name|language
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
name|add_psymbol_with_dem_name_to_list
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|domain_enum
parameter_list|,
name|enum
name|address_class
parameter_list|,
name|struct
name|psymbol_allocation_list
modifier|*
parameter_list|,
name|long
parameter_list|,
name|CORE_ADDR
parameter_list|,
name|enum
name|language
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
name|init_psymbol_list
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sort_pst_symbols
parameter_list|(
name|struct
name|partial_symtab
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symtab
modifier|*
name|allocate_symtab
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
name|int
name|free_named_symtabs
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fill_in_vptr_fieldno
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_symtab_fns
parameter_list|(
name|struct
name|sym_fns
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|syms_from_objfile
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|,
name|struct
name|section_addr_info
modifier|*
parameter_list|,
name|struct
name|section_offsets
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|new_symfile_objfile
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|objfile
modifier|*
name|symbol_file_add
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|section_addr_info
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create a new section_addr_info, with room for NUM_SECTIONS.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|section_addr_info
modifier|*
name|alloc_section_addr_info
parameter_list|(
name|size_t
name|num_sections
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Build (allocate and populate) a section_addr_info struct from an    existing section table.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|section_addr_info
modifier|*
name|build_section_addr_info_from_section_table
parameter_list|(
specifier|const
name|struct
name|section_table
modifier|*
name|start
parameter_list|,
specifier|const
name|struct
name|section_table
modifier|*
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free all memory allocated by    build_section_addr_info_from_section_table.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|free_section_addr_info
parameter_list|(
name|struct
name|section_addr_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|partial_symtab
modifier|*
name|start_psymtab_common
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|,
name|struct
name|section_offsets
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|CORE_ADDR
parameter_list|,
name|struct
name|partial_symbol
modifier|*
modifier|*
parameter_list|,
name|struct
name|partial_symbol
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Make a copy of the string at PTR with SIZE characters in the symbol    obstack (and add a null character at the end in the copy).  Returns    the address of the copy.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|obsavestring
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|obstack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Concatenate strings S1, S2 and S3; return the new string.  Space is    found in the OBSTACKP  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|obconcat
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstackp
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*   Variables   */
end_comment

begin_comment
comment|/* If non-zero, shared library symbols will be added automatically    when the inferior is created, new libraries are loaded, or when    attaching to the inferior.  This is almost always what users will    want to have happen; but for very large programs, the startup time    will be excessive, and so if this is a problem, the user can clear    this flag and then add the shared library symbols as needed.  Note    that there is a potential for confusion, since if the shared    library symbols are not loaded, commands like "info fun" will *not*    report all the functions that are actually present.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|auto_solib_add
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For systems that support it, a threshold size in megabytes.  If    automatically adding a new library's symbol table to those already    known to the debugger would cause the total shared library symbol    size to exceed this threshhold, then the shlib's symbols are not    added.  The threshold is ignored if the user explicitly asks for a    shlib to be added, such as when using the "sharedlibrary" command.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|auto_solib_limit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From symfile.c */
end_comment

begin_function_decl
specifier|extern
name|struct
name|partial_symtab
modifier|*
name|allocate_psymtab
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
name|discard_psymtab
parameter_list|(
name|struct
name|partial_symtab
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|find_lowest_section
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd
modifier|*
name|symfile_bfd_open
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|get_section_index
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Utility functions for overlay sections: */
end_comment

begin_enum
specifier|extern
enum|enum
name|overlay_debugging_state
block|{
name|ovly_off
block|,
name|ovly_on
block|,
name|ovly_auto
block|}
name|overlay_debugging
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|int
name|overlay_cache_invalid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the "mapped" overlay section containing the PC.  */
end_comment

begin_function_decl
specifier|extern
name|asection
modifier|*
name|find_pc_mapped_section
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return any overlay section containing the PC (even in its LMA    region).  */
end_comment

begin_function_decl
specifier|extern
name|asection
modifier|*
name|find_pc_overlay
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if the section is an overlay.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|section_is_overlay
parameter_list|(
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if the overlay section is currently "mapped".  */
end_comment

begin_function_decl
specifier|extern
name|int
name|section_is_mapped
parameter_list|(
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if pc belongs to section's VMA.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|pc_in_mapped_range
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if pc belongs to section's LMA.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|pc_in_unmapped_range
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Map an address from a section's LMA to its VMA.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|overlay_mapped_address
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Map an address from a section's VMA to its LMA.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|overlay_unmapped_address
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert an address in an overlay section (force into VMA range).  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|symbol_overlayed_address
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Load symbols from a file.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|symbol_file_add_main
parameter_list|(
name|char
modifier|*
name|args
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Clear GDB symbol tables.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|symbol_file_clear
parameter_list|(
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_byte
modifier|*
name|symfile_relocate_debug_section
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|asection
modifier|*
name|sectp
parameter_list|,
name|bfd_byte
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From dwarfread.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|dwarf_build_psymtabs
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|,
name|int
parameter_list|,
name|file_ptr
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|file_ptr
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From dwarf2read.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|dwarf2_has_info
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dwarf2_build_psymtabs
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dwarf2_build_frame_info
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From mdebugread.c */
end_comment

begin_comment
comment|/* Hack to force structures to exist before use in parameter list.  */
end_comment

begin_struct
struct|struct
name|ecoff_debug_hack
block|{
name|struct
name|ecoff_debug_swap
modifier|*
name|a
decl_stmt|;
name|struct
name|ecoff_debug_info
modifier|*
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|mdebug_build_psymtabs
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|,
specifier|const
name|struct
name|ecoff_debug_swap
modifier|*
parameter_list|,
name|struct
name|ecoff_debug_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|elfmdebug_build_psymtabs
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|,
specifier|const
name|struct
name|ecoff_debug_swap
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(SYMFILE_H) */
end_comment

end_unit

