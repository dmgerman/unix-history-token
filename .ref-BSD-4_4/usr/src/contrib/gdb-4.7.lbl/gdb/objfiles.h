begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for symbol file management in GDB.    Copyright (C) 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|OBJFILES_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|OBJFILES_H
end_define

begin_comment
comment|/* This structure maintains information on a per-objfile basis about the    "entry point" of the objfile, and the scope within which the entry point    exists.  It is possible that gdb will see more than one objfile that is    executable, each with it's own entry point.     For example, for dynamically linked executables in SVR4, the dynamic linker    code is contained within the shared C library, which is actually executable    and is run by the kernel first when an exec is done of a user executable    that is dynamically linked.  The dynamic linker within the shared C library    then maps in the various program segments in the user executable and jumps    to the user executable's recorded entry point, as if the call had been made    directly by the kernel.     The traditional gdb method of using this info is to use the recorded entry    point to set the variables entry_file_lowpc and entry_file_highpc from    the debugging information, where these values are the starting address    (inclusive) and ending address (exclusive) of the instruction space in the    executable which correspond to the "startup file", I.E. crt0.o in most    cases.  This file is assumed to be a startup file and frames with pc's    inside it are treated as nonexistent.  Setting these variables is necessary    so that backtraces do not fly off the bottom of the stack (or top, depending    upon your stack orientation).     Gdb also supports an alternate method to avoid running off the top/bottom    of the stack.     There are two frames that are "special", the frame for the function    containing the process entry point, since it has no predecessor frame,    and the frame for the function containing the user code entry point    (the main() function), since all the predecessor frames are for the    process startup code.  Since we have no guarantee that the linked    in startup modules have any debugging information that gdb can use,    we need to avoid following frame pointers back into frames that might    have been built in the startup code, as we might get hopelessly     confused.  However, we almost always have debugging information    available for main().     These variables are used to save the range of PC values which are valid    within the main() function and within the function containing the process    entry point.  If we always consider the frame for main() as the outermost    frame when debugging user code, and the frame for the process entry    point function as the outermost frame when debugging startup code, then    all we have to do is have FRAME_CHAIN_VALID return false whenever a    frame's current PC is within the range specified by these variables.    In essence, we set "ceilings" in the frame chain beyond which we will    not proceed when following the frame chain back up the stack.     A nice side effect is that we can still debug startup code without    running off the end of the frame chain, assuming that we have usable    debugging information in the startup modules, and if we choose to not    use the block at main, or can't find it for some reason, everything    still works as before.  And if we have no startup code debugging    information but we do have usable information for main(), backtraces    from user code don't go wandering off into the startup code.     To use this method, define your FRAME_CHAIN_VALID macro like:  	#define FRAME_CHAIN_VALID(chain, thisframe)     \ 	  (chain != 0                                   \&& !(inside_main_func ((thisframe)->pc))     \&& !(inside_entry_func ((thisframe)->pc)))     and add initializations of the four scope controlling variables inside    the object file / debugging information processing modules.  */
end_comment

begin_struct
struct|struct
name|entry_info
block|{
comment|/* The value we should use for this objects entry point.      The illegal/unknown value needs to be something other than 0, ~0      for instance, which is much less likely than 0. */
name|CORE_ADDR
name|entry_point
decl_stmt|;
comment|/* Start (inclusive) and end (exclusive) of function containing the      entry point. */
name|CORE_ADDR
name|entry_func_lowpc
decl_stmt|;
name|CORE_ADDR
name|entry_func_highpc
decl_stmt|;
comment|/* Start (inclusive) and end (exclusive) of object file containing the      entry point. */
name|CORE_ADDR
name|entry_file_lowpc
decl_stmt|;
name|CORE_ADDR
name|entry_file_highpc
decl_stmt|;
comment|/* Start (inclusive) and end (exclusive) of the user code main() function. */
name|CORE_ADDR
name|main_func_lowpc
decl_stmt|;
name|CORE_ADDR
name|main_func_highpc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Master structure for keeping track of each input file from which    gdb reads symbols.  One of these is allocated for each such file we    access, e.g. the exec_file, symbol_file, and any shared library object    files. */
end_comment

begin_struct
struct|struct
name|objfile
block|{
comment|/* All struct objfile's are chained together by their next pointers.      The global variable "object_files" points to the first link in this      chain.       FIXME:  There is a problem here if the objfile is reusable, and if      multiple users are to be supported.  The problem is that the objfile      list is linked through a member of the objfile struct itself, which      is only valid for one gdb process.  The list implementation needs to      be changed to something like:       struct list {struct list *next; struct objfile *objfile};       where the list structure is completely maintained separately within      each gdb process. */
name|struct
name|objfile
modifier|*
name|next
decl_stmt|;
comment|/* The object file's name.  Malloc'd; free it if you free this struct.  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Some flag bits for this objfile. */
name|unsigned
name|short
name|flags
decl_stmt|;
comment|/* Each objfile points to a linked list of symtabs derived from this file,      one symtab structure for each compilation unit (source file).  Each link      in the symtab list contains a backpointer to this objfile. */
name|struct
name|symtab
modifier|*
name|symtabs
decl_stmt|;
comment|/* Each objfile points to a linked list of partial symtabs derived from      this file, one partial symtab structure for each compilation unit      (source file). */
name|struct
name|partial_symtab
modifier|*
name|psymtabs
decl_stmt|;
comment|/* List of freed partial symtabs, available for re-use */
name|struct
name|partial_symtab
modifier|*
name|free_psymtabs
decl_stmt|;
comment|/* The object file's BFD.  Can be null, in which case bfd_open (name) and      put the result here.  */
name|bfd
modifier|*
name|obfd
decl_stmt|;
comment|/* The modification timestamp of the object file, as of the last time      we read its symbols.  */
name|long
name|mtime
decl_stmt|;
comment|/* Obstacks to hold objects that should be freed when we load a new symbol      table from this object file. */
name|struct
name|obstack
name|psymbol_obstack
decl_stmt|;
comment|/* Partial symbols */
name|struct
name|obstack
name|symbol_obstack
decl_stmt|;
comment|/* Full symbols */
name|struct
name|obstack
name|type_obstack
decl_stmt|;
comment|/* Types */
comment|/* Vectors of all partial symbols read in from file.  The actual data      is stored in the psymbol_obstack. */
name|struct
name|psymbol_allocation_list
name|global_psymbols
decl_stmt|;
name|struct
name|psymbol_allocation_list
name|static_psymbols
decl_stmt|;
comment|/* Each file contains a pointer to an array of minimal symbols for all      global symbols that are defined within the file.  The array is terminated      by a "null symbol", one that has a NULL pointer for the name and a zero      value for the address.  This makes it easy to walk through the array      when passed a pointer to somewhere in the middle of it.  There is also      a count of the number of symbols, which does include the terminating      null symbol.  The array itself, as well as all the data that it points      to, should be allocated on the symbol_obstack for this file. */
name|struct
name|minimal_symbol
modifier|*
name|msymbols
decl_stmt|;
name|int
name|minimal_symbol_count
decl_stmt|;
comment|/* For object file formats which don't specify fundamental types, gdb      can create such types.  For now, it maintains a vector of pointers      to these internally created fundamental types on a per objfile basis,      however it really should ultimately keep them on a per-compilation-unit      basis, to account for linkage-units that consist of a number of      compilation units that may have different fundamental types, such as      linking C modules with ADA modules, or linking C modules that are      compiled with 32-bit ints with C modules that are compiled with 64-bit      ints (not inherently evil with a smarter linker). */
name|struct
name|type
modifier|*
modifier|*
name|fundamental_types
decl_stmt|;
comment|/* The mmalloc() malloc-descriptor for this objfile if we are using      the memory mapped malloc() package to manage storage for this objfile's      data.  NULL if we are not. */
name|PTR
name|md
decl_stmt|;
comment|/* The file descriptor that was used to obtain the mmalloc descriptor      for this objfile.  If we call mmalloc_detach with the malloc descriptor      we should then close this file descriptor. */
name|int
name|mmfd
decl_stmt|;
comment|/* Structure which keeps track of functions that manipulate objfile's      of the same type as this objfile.  I.E. the function to read partial      symbols for example.  Note that this structure is in statically      allocated memory, and is shared by all objfiles that use the      object module reader of this type. */
name|struct
name|sym_fns
modifier|*
name|sf
decl_stmt|;
comment|/* The per-objfile information about the entry point, the scope (file/func)      containing the entry point, and the scope of the user's main() func. */
name|struct
name|entry_info
name|ei
decl_stmt|;
comment|/* Hook for information which is shared by sym_init and sym_read for      this objfile.  It is typically a pointer to malloc'd memory.  */
name|PTR
name|sym_private
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Defines for the objfile flag word. */
end_comment

begin_comment
comment|/* Gdb can arrange to allocate storage for all objects related to a    particular objfile in a designated section of it's address space,    managed at a low level by mmap() and using a special version of    malloc that handles malloc/free/realloc on top of the mmap() interface.    This allows the "internal gdb state" for a particular objfile to be    dumped to a gdb state file and subsequently reloaded at a later time. */
end_comment

begin_define
define|#
directive|define
name|OBJF_MAPPED
value|(1<< 0)
end_define

begin_comment
comment|/* Objfile data is mmap'd */
end_comment

begin_comment
comment|/* When using mapped/remapped predigested gdb symbol information, we need    a flag that indicates that we have previously done an initial symbol    table read from this particular objfile.  We can't just look for the    absence of any of the three symbol tables (msymbols, psymtab, symtab)    because if the file has no symbols for example, none of these will    exist. */
end_comment

begin_define
define|#
directive|define
name|OBJF_SYMS
value|(1<< 1)
end_define

begin_comment
comment|/* Have tried to read symbols */
end_comment

begin_comment
comment|/* The object file that the main symbol table was loaded from (e.g. the    argument to the "symbol-file" or "file" command).  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|objfile
modifier|*
name|symfile_objfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When we need to allocate a new type, we need to know which type_obstack    to allocate the type on, since there is one for each objfile.  The places    where types are allocated are deeply buried in function call hierarchies    which know nothing about objfiles, so rather than trying to pass a    particular objfile down to them, we just do an end run around them and    set current_objfile to be whatever objfile we expect to be using at the    time types are being allocated.  For instance, when we start reading    symbols for a particular objfile, we set current_objfile to point to that    objfile, and when we are done, we set it back to NULL, to ensure that we    never put a type someplace other than where we are expecting to put it.    FIXME:  Maybe we should review the entire type handling system and    see if there is a better way to avoid this problem. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|objfile
modifier|*
name|current_objfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* All known objfiles are kept in a linked list.  This points to the    root of this list. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|objfile
modifier|*
name|object_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declarations for functions defined in objfiles.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|objfile
modifier|*
name|allocate_objfile
name|PARAMS
argument_list|(
operator|(
name|bfd
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
name|unlink_objfile
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
name|free_objfile
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
name|free_all_objfiles
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
name|int
name|have_partial_symbols
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
name|int
name|have_full_symbols
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions for dealing with the minimal symbol table, really a misc    address<->symbol mapping for things we don't have debug symbols for.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|have_minimal_symbols
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Traverse all object files.  ALL_OBJFILES_SAFE works even if you delete    the objfile during the traversal.  */
end_comment

begin_define
define|#
directive|define
name|ALL_OBJFILES
parameter_list|(
name|obj
parameter_list|)
define|\
value|for ((obj) = object_files; (obj) != NULL; (obj) = (obj)->next)
end_define

begin_define
define|#
directive|define
name|ALL_OBJFILES_SAFE
parameter_list|(
name|obj
parameter_list|,
name|nxt
parameter_list|)
define|\
value|for ((obj) = object_files; 	   \        (obj) != NULL? ((nxt)=(obj)->next,1) :0;	\        (obj) = (nxt))
end_define

begin_comment
comment|/* Traverse all symtabs in one objfile.  */
end_comment

begin_define
define|#
directive|define
name|ALL_OBJFILE_SYMTABS
parameter_list|(
name|objfile
parameter_list|,
name|s
parameter_list|)
define|\
value|for ((s) = (objfile) -> symtabs; (s) != NULL; (s) = (s) -> next)
end_define

begin_comment
comment|/* Traverse all psymtabs in one objfile.  */
end_comment

begin_define
define|#
directive|define
name|ALL_OBJFILE_PSYMTABS
parameter_list|(
name|objfile
parameter_list|,
name|p
parameter_list|)
define|\
value|for ((p) = (objfile) -> psymtabs; (p) != NULL; (p) = (p) -> next)
end_define

begin_comment
comment|/* Traverse all minimal symbols in one objfile.  */
end_comment

begin_define
define|#
directive|define
name|ALL_OBJFILE_MSYMBOLS
parameter_list|(
name|objfile
parameter_list|,
name|m
parameter_list|)
define|\
value|for ((m) = (objfile) -> msymbols; (m)->name != NULL; (m)++)
end_define

begin_comment
comment|/* Traverse all symtabs in all objfiles.  */
end_comment

begin_define
define|#
directive|define
name|ALL_SYMTABS
parameter_list|(
name|objfile
parameter_list|,
name|s
parameter_list|)
define|\
value|ALL_OBJFILES (objfile)	 \     ALL_OBJFILE_SYMTABS (objfile, s)
end_define

begin_comment
comment|/* Traverse all psymtabs in all objfiles.  */
end_comment

begin_define
define|#
directive|define
name|ALL_PSYMTABS
parameter_list|(
name|objfile
parameter_list|,
name|p
parameter_list|)
define|\
value|ALL_OBJFILES (objfile)	 \     ALL_OBJFILE_PSYMTABS (objfile, p)
end_define

begin_comment
comment|/* Traverse all minimal symbols in all objfiles.  */
end_comment

begin_define
define|#
directive|define
name|ALL_MSYMBOLS
parameter_list|(
name|objfile
parameter_list|,
name|m
parameter_list|)
define|\
value|ALL_OBJFILES (objfile)	 \     if ((objfile)->msymbols)	 \       ALL_OBJFILE_MSYMBOLS (objfile, m)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (OBJFILES_H) */
end_comment

end_unit

