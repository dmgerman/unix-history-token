begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for reading symbol files into GDB.    Copyright (C) 1990, 1991, 1992  Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
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

begin_struct
struct|struct
name|psymbol_allocation_list
block|{
name|struct
name|partial_symbol
modifier|*
name|list
decl_stmt|;
name|struct
name|partial_symbol
modifier|*
name|next
decl_stmt|;
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
comment|/* is the name, or name prefix, of the BFD "target type" that this      set of functions handles.  E.g. "a.out" or "sunOs" or "coff" or "elf".  */
name|char
modifier|*
name|sym_name
decl_stmt|;
comment|/* counts how many bytes of sym_name should be checked against the      BFD target type of the file being read.  If an exact match is      desired, specify the number of characters in sym_name plus 1 for the      NUL.  If a prefix match is desired, specify the number of characters in      sym_name.  */
name|int
name|sym_namelen
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

begin_define
define|#
directive|define
name|ADD_PSYMBOL_VT_TO_LIST
parameter_list|(
name|NAME
parameter_list|,
name|NAMELENGTH
parameter_list|,
name|NAMESPACE
parameter_list|,
name|CLASS
parameter_list|,
name|LIST
parameter_list|,
name|VALUE
parameter_list|,
name|VT
parameter_list|)
define|\
value|do {		        						\     register struct partial_symbol *psym;				\     if ((LIST).next>= (LIST).list + (LIST).size)			\ 	   extend_psymbol_list (&(LIST),objfile);				\     psym = (LIST).next++;						\ 									\     SYMBOL_NAME (psym) = (char *) obstack_alloc (&objfile->psymbol_obstack,	\ 						 (NAMELENGTH) + 1);	\     memcpy (SYMBOL_NAME (psym), (NAME), (NAMELENGTH));			\     SYMBOL_NAME (psym)[(NAMELENGTH)] = '\0';				\     SYMBOL_NAMESPACE (psym) = (NAMESPACE);				\     SYMBOL_CLASS (psym) = (CLASS);					\     VT (psym) = (VALUE); 						\   } while (0);
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_comment
comment|/* Since one arg is a struct, we have to pass in a ptr and deref it (sigh) */
end_comment

begin_define
define|#
directive|define
name|ADD_PSYMBOL_TO_LIST
parameter_list|(
name|name
parameter_list|,
name|namelength
parameter_list|,
name|namespace
parameter_list|,
name|class
parameter_list|,
name|list
parameter_list|,
name|value
parameter_list|)
define|\
value|add_psymbol_to_list (name, namelength, namespace, class,&list, value)
end_define

begin_define
define|#
directive|define
name|ADD_PSYMBOL_ADDR_TO_LIST
parameter_list|(
name|name
parameter_list|,
name|namelength
parameter_list|,
name|namespace
parameter_list|,
name|class
parameter_list|,
name|list
parameter_list|,
name|value
parameter_list|)
define|\
value|add_psymbol_addr_to_list (name, namelength, namespace, class,&list, value)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !DEBUG */
end_comment

begin_comment
comment|/* Add a symbol with an integer value to a psymtab. */
end_comment

begin_define
define|#
directive|define
name|ADD_PSYMBOL_TO_LIST
parameter_list|(
name|name
parameter_list|,
name|namelength
parameter_list|,
name|namespace
parameter_list|,
name|class
parameter_list|,
name|list
parameter_list|,
name|value
parameter_list|)
define|\
value|ADD_PSYMBOL_VT_TO_LIST (name, namelength, namespace, class, list, value, SYMBOL_VALUE)
end_define

begin_comment
comment|/* Add a symbol with a CORE_ADDR value to a psymtab. */
end_comment

begin_define
define|#
directive|define
name|ADD_PSYMBOL_ADDR_TO_LIST
parameter_list|(
name|name
parameter_list|,
name|namelength
parameter_list|,
name|namespace
parameter_list|,
name|class
parameter_list|,
name|list
parameter_list|,
name|value
parameter_list|)
define|\
value|ADD_PSYMBOL_VT_TO_LIST (name, namelength, namespace, class, list, value, SYMBOL_VALUE_ADDRESS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_comment
comment|/*   Functions   */
end_comment

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
operator|,
expr|struct
name|partial_symbol
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

begin_decl_stmt
specifier|extern
name|void
name|sort_all_symtab_syms
name|PARAMS
argument_list|(
operator|(
name|void
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
comment|/* Support for complaining about things in the symbol file that aren't    catastrophic.     Each such thing gets a counter.  The first time we have the problem,    during a symbol read, we report it.  At the end of symbol reading,    if verbose, we report how many of each problem we had.  */
end_comment

begin_struct
struct|struct
name|complaint
block|{
name|char
modifier|*
name|message
decl_stmt|;
name|unsigned
name|counter
decl_stmt|;
name|struct
name|complaint
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Root of the chain of complaints that have at some point been issued.     This is used to reset the counters, and/or report the total counts.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|complaint
name|complaint_root
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions that handle complaints.  (in symfile.c)  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|complain
name|PARAMS
argument_list|(
operator|(
expr|struct
name|complaint
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear_complaints
name|PARAMS
argument_list|(
operator|(
name|int
name|sym_reading
operator|,
name|int
name|noisy
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From symfile.c */
end_comment

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
comment|/* From dbxread.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|elfstab_build_psymtabs
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
name|objfile
operator|,
expr|struct
name|section_offsets
operator|*
name|section_offsets
operator|,
name|int
name|mainline
operator|,
name|file_ptr
name|staboff
operator|,
name|unsigned
name|int
name|stabsize
operator|,
name|file_ptr
name|stabstroffset
operator|,
name|unsigned
name|int
name|stabstrsize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From demangle.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|set_demangling_style
name|PARAMS
argument_list|(
operator|(
name|char
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

