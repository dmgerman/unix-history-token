begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for reading symbol files into GDB.    Copyright (C) 1990, 1991, 1992, 1993, 1994, 1996    Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* Partial symbols are stored in the psymbol_cache and pointers to them    are kept in a dynamically grown array that is obtained from malloc and    grown as necessary via realloc.  Each objfile typically has two of these,    one for global symbols and one for static symbols.  Although this adds    a level of indirection for storing or accessing the partial symbols,    it allows us to throw away duplicate psymbols and set all pointers    to the single saved instance. */
end_comment

begin_struct
struct|struct
name|psymbol_allocation_list
block|{
comment|/* Pointer to beginning of dynamically allocated array of pointers to    partial symbols.  The array is dynamically expanded as necessary to    accommodate more pointers. */
name|struct
name|partial_symbol
modifier|*
modifier|*
name|list
decl_stmt|;
comment|/* Pointer to next available slot in which to store a pointer to a partial      symbol. */
name|struct
name|partial_symbol
modifier|*
modifier|*
name|next
decl_stmt|;
comment|/* Number of allocated pointer slots in current dynamic array (not the      number of bytes of storage).  The "next" pointer will always point      somewhere between list[0] and list[size], and when at list[size] the      array will be expanded on the next attempt to store a pointer. */
name|int
name|size
decl_stmt|;
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
comment|/* BFD flavour that we handle, or (as a special kludge, see xcoffread.c,      (enum bfd_flavour)-1 for xcoff).  */
name|enum
name|bfd_flavour
name|sym_flavour
decl_stmt|;
comment|/* Initializes anything that is global to the entire symbol table.  It is      called during symbol_file_add, when we begin debugging an entirely new      program. */
name|void
argument_list|(
argument|*sym_new_init
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Reads any initial information from a symbol file, and initializes the      struct sym_fns SF in preparation for sym_read().  It is called every      time we read a symbol file for any reason. */
name|void
argument_list|(
argument|*sym_init
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* sym_read (objfile, addr, mainline)      Reads a symbol file into a psymtab (or possibly a symtab).      OBJFILE is the objfile struct for the file we are reading.      SECTION_OFFSETS      are the offset between the file's specified section addresses and      their true addresses in memory.      MAINLINE is 1 if this is the      main symbol table being read, and 0 if a secondary      symbol file (e.g. shared library or dynamically loaded file)      is being read.  */
name|void
argument_list|(
argument|*sym_read
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
operator|,
expr|struct
name|section_offsets
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Called when we are finished with an objfile.  Should do all cleanup      that is specific to the object file format for the particular objfile. */
name|void
argument_list|(
argument|*sym_finish
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* This function produces a file-dependent section_offsets structure,      allocated in the objfile's storage, and based on the parameter.      The parameter is currently a CORE_ADDR (FIXME!) for backward compatibility      with the higher levels of GDB.  It should probably be changed to      a string, where NULL means the default, and others are parsed in a file      dependent way.  The result of this function is handed in to sym_read.  */
name|struct
name|section_offsets
modifier|*
argument_list|(
operator|*
name|sym_offsets
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
operator|,
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
comment|/* Finds the next struct sym_fns.  They are allocated and initialized      in whatever module implements the functions pointed to; an       initializer calls add_symtab_fns to add them to the global chain.  */
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

begin_decl_stmt
specifier|extern
name|struct
name|section_offsets
modifier|*
name|default_symfile_offsets
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
name|objfile
operator|,
name|CORE_ADDR
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|extend_psymbol_list
name|PARAMS
argument_list|(
operator|(
expr|struct
name|psymbol_allocation_list
operator|*
operator|,
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add any kind of symbol to a psymbol_allocation_list. */
end_comment

begin_comment
comment|/* #include "demangle.h" */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|add_psymbol_to_list
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|namespace_enum
operator|,
expr|enum
name|address_class
operator|,
expr|struct
name|psymbol_allocation_list
operator|*
operator|,
name|long
operator|,
name|CORE_ADDR
operator|,
expr|enum
name|language
operator|,
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_psymbol_with_dem_name_to_list
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|namespace_enum
operator|,
expr|enum
name|address_class
operator|,
expr|struct
name|psymbol_allocation_list
operator|*
operator|,
name|long
operator|,
name|CORE_ADDR
operator|,
expr|enum
name|language
operator|,
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_psymbol_list
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sort_pst_symbols
name|PARAMS
argument_list|(
operator|(
expr|struct
name|partial_symtab
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
name|allocate_symtab
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|free_named_symtabs
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fill_in_vptr_fieldno
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_symtab_fns
name|PARAMS
argument_list|(
operator|(
expr|struct
name|sym_fns
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_entry_point_info
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|syms_from_objfile
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
operator|,
name|CORE_ADDR
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|new_symfile_objfile
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|partial_symtab
modifier|*
name|start_psymtab_common
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
operator|,
expr|struct
name|section_offsets
operator|*
operator|,
name|char
operator|*
operator|,
name|CORE_ADDR
operator|,
expr|struct
name|partial_symbol
operator|*
operator|*
operator|,
expr|struct
name|partial_symbol
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sorting your symbols for fast lookup or alphabetical printing.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|sort_block_syms
name|PARAMS
argument_list|(
operator|(
expr|struct
name|block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sort_symtab_syms
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a copy of the string at PTR with SIZE characters in the symbol obstack    (and add a null character at the end in the copy).    Returns the address of the copy.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|obsavestring
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
expr|struct
name|obstack
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Concatenate strings S1, S2 and S3; return the new string.    Space is found in the symbol_obstack.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|obconcat
name|PARAMS
argument_list|(
operator|(
expr|struct
name|obstack
operator|*
name|obstackp
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   Variables   */
end_comment

begin_comment
comment|/* whether to auto load solibs at startup time:  0/1.      On all platforms, 0 means "don't auto load".     On HP-UX,> 0 means a threshhold, in megabytes, of symbol table which will    be auto loaded.  When the cumulative size of solib symbol table exceeds    this threshhold, solibs' symbol tables will not be loaded.     On other platforms,> 0 means, "always auto load".    */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|auto_solib_add
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From symfile.c */
end_comment

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|entry_point_address
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|partial_symtab
modifier|*
name|allocate_psymtab
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|discard_psymtab
name|PARAMS
argument_list|(
operator|(
expr|struct
name|partial_symtab
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|find_lowest_section
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd
modifier|*
name|symfile_bfd_open
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Remote targets may wish to use this as their load function.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|generic_load
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|int
name|from_tty
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Utility functions for overlay sections: */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|overlay_debugging
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|overlay_cache_invalid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return the "mapped" overlay section  containing the PC */
end_comment

begin_decl_stmt
specifier|extern
name|asection
modifier|*
name|find_pc_mapped_section
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return any overlay section containing the PC (even in its LMA region) */
end_comment

begin_decl_stmt
specifier|extern
name|asection
modifier|*
name|find_pc_overlay
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return true if the section is an overlay */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|section_is_overlay
name|PARAMS
argument_list|(
operator|(
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return true if the overlay section is currently "mapped" */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|section_is_mapped
name|PARAMS
argument_list|(
operator|(
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return true if pc belongs to section's VMA */
end_comment

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|pc_in_mapped_range
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return true if pc belongs to section's LMA */
end_comment

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|pc_in_unmapped_range
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* map an address from a section's LMA to its VMA */
end_comment

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|overlay_mapped_address
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* map an address from a section's VMA to its LMA */
end_comment

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|overlay_unmapped_address
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* convert an address in an overlay section (force into VMA range) */
end_comment

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|symbol_overlayed_address
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From dwarfread.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dwarf_build_psymtabs
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
operator|,
expr|struct
name|section_offsets
operator|*
operator|,
name|int
operator|,
name|file_ptr
operator|,
name|unsigned
name|int
operator|,
name|file_ptr
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From dwarf2read.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dwarf2_has_info
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dwarf2_build_psymtabs
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
operator|,
expr|struct
name|section_offsets
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|void
name|mdebug_build_psymtabs
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
operator|,
specifier|const
expr|struct
name|ecoff_debug_swap
operator|*
operator|,
expr|struct
name|ecoff_debug_info
operator|*
operator|,
expr|struct
name|section_offsets
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|elfmdebug_build_psymtabs
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
operator|,
specifier|const
expr|struct
name|ecoff_debug_swap
operator|*
operator|,
name|asection
operator|*
operator|,
expr|struct
name|section_offsets
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
comment|/* !defined(SYMFILE_H) */
end_comment

end_unit

