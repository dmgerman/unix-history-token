begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for symbol file management in GDB.     Copyright 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000,    2001, 2002, 2003, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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

begin_include
include|#
directive|include
file|"gdb_obstack.h"
end_include

begin_comment
comment|/* For obstack internals.  */
end_comment

begin_include
include|#
directive|include
file|"symfile.h"
end_include

begin_comment
comment|/* For struct psymbol_allocation_list */
end_comment

begin_struct_decl
struct_decl|struct
name|bcache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|htab
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|symtab
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|objfile_data
struct_decl|;
end_struct_decl

begin_comment
comment|/* This structure maintains information on a per-objfile basis about the    "entry point" of the objfile, and the scope within which the entry point    exists.  It is possible that gdb will see more than one objfile that is    executable, each with its own entry point.     For example, for dynamically linked executables in SVR4, the dynamic linker    code is contained within the shared C library, which is actually executable    and is run by the kernel first when an exec is done of a user executable    that is dynamically linked.  The dynamic linker within the shared C library    then maps in the various program segments in the user executable and jumps    to the user executable's recorded entry point, as if the call had been made    directly by the kernel.     The traditional gdb method of using this info is to use the    recorded entry point to set the variables    deprecated_entry_file_lowpc and deprecated_entry_file_highpc from    the debugging information, where these values are the starting    address (inclusive) and ending address (exclusive) of the    instruction space in the executable which correspond to the    "startup file", I.E. crt0.o in most cases.  This file is assumed to    be a startup file and frames with pc's inside it are treated as    nonexistent.  Setting these variables is necessary so that    backtraces do not fly off the bottom of the stack.     NOTE: cagney/2003-09-09: It turns out that this "traditional"    method doesn't work.  Corinna writes: ``It turns out that the call    to deprecated_inside_entry_file destroys a meaningful backtrace    under some conditions.  E. g. the backtrace tests in the asm-source    testcase are broken for some targets.  In this test the functions    are all implemented as part of one file and the testcase is not    necessarily linked with a start file (depending on the target).    What happens is, that the first frame is printed normaly and    following frames are treated as being inside the enttry file then.    This way, only the #0 frame is printed in the backtrace output.''    Ref "frame.c" "NOTE: vinschen/2003-04-01".     Gdb also supports an alternate method to avoid running off the bottom    of the stack.     There are two frames that are "special", the frame for the function    containing the process entry point, since it has no predecessor frame,    and the frame for the function containing the user code entry point    (the main() function), since all the predecessor frames are for the    process startup code.  Since we have no guarantee that the linked    in startup modules have any debugging information that gdb can use,    we need to avoid following frame pointers back into frames that might    have been built in the startup code, as we might get hopelessly     confused.  However, we almost always have debugging information    available for main().     These variables are used to save the range of PC values which are    valid within the main() function and within the function containing    the process entry point.  If we always consider the frame for    main() as the outermost frame when debugging user code, and the    frame for the process entry point function as the outermost frame    when debugging startup code, then all we have to do is have    DEPRECATED_FRAME_CHAIN_VALID return false whenever a frame's    current PC is within the range specified by these variables.  In    essence, we set "ceilings" in the frame chain beyond which we will    not proceed when following the frame chain back up the stack.     A nice side effect is that we can still debug startup code without    running off the end of the frame chain, assuming that we have usable    debugging information in the startup modules, and if we choose to not    use the block at main, or can't find it for some reason, everything    still works as before.  And if we have no startup code debugging    information but we do have usable information for main(), backtraces    from user code don't go wandering off into the startup code.  */
end_comment

begin_struct
struct|struct
name|entry_info
block|{
comment|/* The value we should use for this objects entry point.        The illegal/unknown value needs to be something other than 0, ~0        for instance, which is much less likely than 0. */
name|CORE_ADDR
name|entry_point
decl_stmt|;
define|#
directive|define
name|INVALID_ENTRY_POINT
value|(~0)
comment|/* ~0 will not be in any file, we hope.  */
comment|/* Start (inclusive) and end (exclusive) of function containing the        entry point. */
name|CORE_ADDR
name|entry_func_lowpc
decl_stmt|;
name|CORE_ADDR
name|entry_func_highpc
decl_stmt|;
comment|/* Start (inclusive) and end (exclusive) of object file containing the        entry point. */
name|CORE_ADDR
name|deprecated_entry_file_lowpc
decl_stmt|;
name|CORE_ADDR
name|deprecated_entry_file_highpc
decl_stmt|;
comment|/* Start (inclusive) and end (exclusive) of the user code main() function. */
name|CORE_ADDR
name|main_func_lowpc
decl_stmt|;
name|CORE_ADDR
name|main_func_highpc
decl_stmt|;
comment|/* Use these values when any of the above ranges is invalid.  */
comment|/* We use these values because it guarantees that there is no number that is    both>= LOWPC&&< HIGHPC.  It is also highly unlikely that 3 is a valid    module or function start address (as opposed to 0).  */
define|#
directive|define
name|INVALID_ENTRY_LOWPC
value|(3)
define|#
directive|define
name|INVALID_ENTRY_HIGHPC
value|(1)
block|}
struct|;
end_struct

begin_comment
comment|/* Sections in an objfile.     It is strange that we have both this notion of "sections"    and the one used by section_offsets.  Section as used    here, (currently at least) means a BFD section, and the sections    are set up from the BFD sections in allocate_objfile.     The sections in section_offsets have their meaning determined by    the symbol format, and they are set up by the sym_offsets function    for that symbol file format.     I'm not sure this could or should be changed, however.  */
end_comment

begin_struct
struct|struct
name|obj_section
block|{
name|CORE_ADDR
name|addr
decl_stmt|;
comment|/* lowest address in section */
name|CORE_ADDR
name|endaddr
decl_stmt|;
comment|/* 1+highest address in section */
comment|/* This field is being used for nefarious purposes by syms_from_objfile.        It is said to be redundant with section_offsets; it's not really being        used that way, however, it's some sort of hack I don't understand        and am not going to try to eliminate (yet, anyway).  FIXME.         It was documented as "offset between (end)addr and actual memory        addresses", but that's not true; addr& endaddr are actual memory        addresses.  */
name|CORE_ADDR
name|offset
decl_stmt|;
name|struct
name|bfd_section
modifier|*
name|the_bfd_section
decl_stmt|;
comment|/* BFD section pointer */
comment|/* Objfile this section is part of.  */
name|struct
name|objfile
modifier|*
name|objfile
decl_stmt|;
comment|/* True if this "overlay section" is mapped into an "overlay region". */
name|int
name|ovly_mapped
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* An import entry contains information about a symbol that    is used in this objfile but not defined in it, and so needs    to be imported from some other objfile */
end_comment

begin_comment
comment|/* Currently we just store the name; no attributes. 1997-08-05 */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|ImportEntry
typedef|;
end_typedef

begin_comment
comment|/* An export entry contains information about a symbol that    is defined in this objfile and available for use in other    objfiles */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of exported symbol */
name|int
name|address
decl_stmt|;
comment|/* offset subject to relocation */
comment|/* Currently no other attributes 1997-08-05 */
block|}
name|ExportEntry
typedef|;
end_typedef

begin_comment
comment|/* The "objstats" structure provides a place for gdb to record some    interesting information about its internal state at runtime, on a    per objfile basis, such as information about the number of symbols    read, size of string table (if any), etc. */
end_comment

begin_struct
struct|struct
name|objstats
block|{
name|int
name|n_minsyms
decl_stmt|;
comment|/* Number of minimal symbols read */
name|int
name|n_psyms
decl_stmt|;
comment|/* Number of partial symbols read */
name|int
name|n_syms
decl_stmt|;
comment|/* Number of full symbols read */
name|int
name|n_stabs
decl_stmt|;
comment|/* Number of ".stabs" read (if applicable) */
name|int
name|n_types
decl_stmt|;
comment|/* Number of types */
name|int
name|sz_strtab
decl_stmt|;
comment|/* Size of stringtable, (if applicable) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OBJSTAT
parameter_list|(
name|objfile
parameter_list|,
name|expr
parameter_list|)
value|(objfile -> stats.expr)
end_define

begin_define
define|#
directive|define
name|OBJSTATS
value|struct objstats stats
end_define

begin_function_decl
specifier|extern
name|void
name|print_objfile_statistics
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_symbol_bcache_statistics
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Number of entries in the minimal symbol hash table.  */
end_comment

begin_define
define|#
directive|define
name|MINIMAL_SYMBOL_HASH_SIZE
value|2039
end_define

begin_comment
comment|/* Master structure for keeping track of each file from which    gdb reads symbols.  There are several ways these get allocated: 1.    The main symbol file, symfile_objfile, set by the symbol-file command,    2.  Additional symbol files added by the add-symbol-file command,    3.  Shared library objfiles, added by ADD_SOLIB,  4.  symbol files    for modules that were loaded when GDB attached to a remote system    (see remote-vx.c).  */
end_comment

begin_struct
struct|struct
name|objfile
block|{
comment|/* All struct objfile's are chained together by their next pointers.        The global variable "object_files" points to the first link in this        chain.         FIXME:  There is a problem here if the objfile is reusable, and if        multiple users are to be supported.  The problem is that the objfile        list is linked through a member of the objfile struct itself, which        is only valid for one gdb process.  The list implementation needs to        be changed to something like:         struct list {struct list *next; struct objfile *objfile};         where the list structure is completely maintained separately within        each gdb process. */
name|struct
name|objfile
modifier|*
name|next
decl_stmt|;
comment|/* The object file's name, tilde-expanded and absolute.        Malloc'd; free it if you free this struct.  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Some flag bits for this objfile. */
name|unsigned
name|short
name|flags
decl_stmt|;
comment|/* Each objfile points to a linked list of symtabs derived from this file,        one symtab structure for each compilation unit (source file).  Each link        in the symtab list contains a backpointer to this objfile. */
name|struct
name|symtab
modifier|*
name|symtabs
decl_stmt|;
comment|/* Each objfile points to a linked list of partial symtabs derived from        this file, one partial symtab structure for each compilation unit        (source file). */
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
comment|/* The object file's BFD.  Can be null if the objfile contains only        minimal symbols, e.g. the run time common symbols for SunOS4.  */
name|bfd
modifier|*
name|obfd
decl_stmt|;
comment|/* The modification timestamp of the object file, as of the last time        we read its symbols.  */
name|long
name|mtime
decl_stmt|;
comment|/* Obstack to hold objects that should be freed when we load a new symbol        table from this object file. */
name|struct
name|obstack
name|objfile_obstack
decl_stmt|;
comment|/* A byte cache where we can stash arbitrary "chunks" of bytes that        will not change. */
name|struct
name|bcache
modifier|*
name|psymbol_cache
decl_stmt|;
comment|/* Byte cache for partial syms */
name|struct
name|bcache
modifier|*
name|macro_cache
decl_stmt|;
comment|/* Byte cache for macros */
comment|/* Hash table for mapping symbol names to demangled names.  Each        entry in the hash table is actually two consecutive strings,        both null-terminated; the first one is a mangled or linkage        name, and the second is the demangled name or just a zero byte        if the name doesn't demangle.  */
name|struct
name|htab
modifier|*
name|demangled_names_hash
decl_stmt|;
comment|/* Vectors of all partial symbols read in from file.  The actual data        is stored in the objfile_obstack. */
name|struct
name|psymbol_allocation_list
name|global_psymbols
decl_stmt|;
name|struct
name|psymbol_allocation_list
name|static_psymbols
decl_stmt|;
comment|/* Each file contains a pointer to an array of minimal symbols for all        global symbols that are defined within the file.  The array is terminated        by a "null symbol", one that has a NULL pointer for the name and a zero        value for the address.  This makes it easy to walk through the array        when passed a pointer to somewhere in the middle of it.  There is also        a count of the number of symbols, which does not include the terminating        null symbol.  The array itself, as well as all the data that it points        to, should be allocated on the objfile_obstack for this file. */
name|struct
name|minimal_symbol
modifier|*
name|msymbols
decl_stmt|;
name|int
name|minimal_symbol_count
decl_stmt|;
comment|/* This is a hash table used to index the minimal symbols by name.  */
name|struct
name|minimal_symbol
modifier|*
name|msymbol_hash
index|[
name|MINIMAL_SYMBOL_HASH_SIZE
index|]
decl_stmt|;
comment|/* This hash table is used to index the minimal symbols by their        demangled names.  */
name|struct
name|minimal_symbol
modifier|*
name|msymbol_demangled_hash
index|[
name|MINIMAL_SYMBOL_HASH_SIZE
index|]
decl_stmt|;
comment|/* For object file formats which don't specify fundamental types, gdb        can create such types.  For now, it maintains a vector of pointers        to these internally created fundamental types on a per objfile basis,        however it really should ultimately keep them on a per-compilation-unit        basis, to account for linkage-units that consist of a number of        compilation units that may have different fundamental types, such as        linking C modules with ADA modules, or linking C modules that are        compiled with 32-bit ints with C modules that are compiled with 64-bit        ints (not inherently evil with a smarter linker). */
name|struct
name|type
modifier|*
modifier|*
name|fundamental_types
decl_stmt|;
comment|/* The mmalloc() malloc-descriptor for this objfile if we are using        the memory mapped malloc() package to manage storage for this objfile's        data.  NULL if we are not. */
name|void
modifier|*
name|md
decl_stmt|;
comment|/* The file descriptor that was used to obtain the mmalloc descriptor        for this objfile.  If we call mmalloc_detach with the malloc descriptor        we should then close this file descriptor. */
name|int
name|mmfd
decl_stmt|;
comment|/* Structure which keeps track of functions that manipulate objfile's        of the same type as this objfile.  I.E. the function to read partial        symbols for example.  Note that this structure is in statically        allocated memory, and is shared by all objfiles that use the        object module reader of this type. */
name|struct
name|sym_fns
modifier|*
name|sf
decl_stmt|;
comment|/* The per-objfile information about the entry point, the scope (file/func)        containing the entry point, and the scope of the user's main() func. */
name|struct
name|entry_info
name|ei
decl_stmt|;
comment|/* Information about stabs.  Will be filled in with a dbx_symfile_info        struct by those readers that need it. */
name|struct
name|dbx_symfile_info
modifier|*
name|sym_stab_info
decl_stmt|;
comment|/* Hook for information for use by the symbol reader (currently used        for information shared by sym_init and sym_read).  It is        typically a pointer to malloc'd memory.  The symbol reader's finish        function is responsible for freeing the memory thusly allocated.  */
name|void
modifier|*
name|sym_private
decl_stmt|;
comment|/* Hook for target-architecture-specific information.  This must        point to memory allocated on one of the obstacks in this objfile,        so that it gets freed automatically when reading a new object        file. */
name|void
modifier|*
name|obj_private
decl_stmt|;
comment|/* Per objfile data-pointers required by other GDB modules.  */
comment|/* FIXME: kettenis/20030711: This mechanism could replace        sym_stab_info, sym_private and obj_private entirely.  */
name|void
modifier|*
modifier|*
name|data
decl_stmt|;
name|unsigned
name|num_data
decl_stmt|;
comment|/* Set of relocation offsets to apply to each section.        Currently on the objfile_obstack (which makes no sense, but I'm        not sure it's harming anything).         These offsets indicate that all symbols (including partial and        minimal symbols) which have been read have been relocated by this        much.  Symbols which are yet to be read need to be relocated by        it.  */
name|struct
name|section_offsets
modifier|*
name|section_offsets
decl_stmt|;
name|int
name|num_sections
decl_stmt|;
comment|/* Indexes in the section_offsets array. These are initialized by the        *_symfile_offsets() family of functions (som_symfile_offsets,        xcoff_symfile_offsets, default_symfile_offsets). In theory they        should correspond to the section indexes used by bfd for the        current objfile. The exception to this for the time being is the        SOM version. */
name|int
name|sect_index_text
decl_stmt|;
name|int
name|sect_index_data
decl_stmt|;
name|int
name|sect_index_bss
decl_stmt|;
name|int
name|sect_index_rodata
decl_stmt|;
comment|/* These pointers are used to locate the section table, which        among other things, is used to map pc addresses into sections.        SECTIONS points to the first entry in the table, and        SECTIONS_END points to the first location past the last entry        in the table.  Currently the table is stored on the        objfile_obstack (which makes no sense, but I'm not sure it's        harming anything).  */
name|struct
name|obj_section
modifier|*
name|sections
decl_stmt|,
modifier|*
name|sections_end
decl_stmt|;
comment|/* Imported symbols */
comment|/* FIXME: ezannoni 2004-02-10: This is just SOM (HP) specific (see        somread.c). It should not pollute generic objfiles.  */
name|ImportEntry
modifier|*
name|import_list
decl_stmt|;
name|int
name|import_list_size
decl_stmt|;
comment|/* Exported symbols */
comment|/* FIXME: ezannoni 2004-02-10: This is just SOM (HP) specific (see        somread.c). It should not pollute generic objfiles.  */
name|ExportEntry
modifier|*
name|export_list
decl_stmt|;
name|int
name|export_list_size
decl_stmt|;
comment|/* Link to objfile that contains the debug symbols for this one.        One is loaded if this file has an debug link to an existing        debug file with the right checksum */
name|struct
name|objfile
modifier|*
name|separate_debug_objfile
decl_stmt|;
comment|/* If this is a separate debug object, this is used as a link to the        actual executable objfile. */
name|struct
name|objfile
modifier|*
name|separate_debug_objfile_backlink
decl_stmt|;
comment|/* Place to stash various statistics about this objfile */
name|OBJSTATS
expr_stmt|;
comment|/* A symtab that the C++ code uses to stash special symbols        associated to namespaces.  */
comment|/* FIXME/carlton-2003-06-27: Delete this in a few years once        "possible namespace symbols" go away.  */
name|struct
name|symtab
modifier|*
name|cp_namespace_symtab
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Defines for the objfile flag word. */
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
comment|/* When an object file has its functions reordered (currently Irix-5.2    shared libraries exhibit this behaviour), we will need an expensive    algorithm to locate a partial symtab or symtab via an address.    To avoid this penalty for normal object files, we use this flag,    whose setting is determined upon symbol table read in.  */
end_comment

begin_define
define|#
directive|define
name|OBJF_REORDERED
value|(1<< 2)
end_define

begin_comment
comment|/* Functions are reordered */
end_comment

begin_comment
comment|/* Distinguish between an objfile for a shared library and a "vanilla"    objfile. (If not set, the objfile may still actually be a solib.    This can happen if the user created the objfile by using the    add-symbol-file command.  GDB doesn't in that situation actually    check whether the file is a solib.  Rather, the target's    implementation of the solib interface is responsible for setting    this flag when noticing solibs used by an inferior.)  */
end_comment

begin_define
define|#
directive|define
name|OBJF_SHARED
value|(1<< 3)
end_define

begin_comment
comment|/* From a shared library */
end_comment

begin_comment
comment|/* User requested that this objfile be read in it's entirety. */
end_comment

begin_define
define|#
directive|define
name|OBJF_READNOW
value|(1<< 4)
end_define

begin_comment
comment|/* Immediate full read */
end_comment

begin_comment
comment|/* This objfile was created because the user explicitly caused it    (e.g., used the add-symbol-file command).  This bit offers a way    for run_command to remove old objfile entries which are no longer    valid (i.e., are associated with an old inferior), but to preserve    ones that the user explicitly loaded via the add-symbol-file    command. */
end_comment

begin_define
define|#
directive|define
name|OBJF_USERLOADED
value|(1<< 5)
end_define

begin_comment
comment|/* User loaded */
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
comment|/* The object file that contains the runtime common minimal symbols    for SunOS4. Note that this objfile has no associated BFD.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|objfile
modifier|*
name|rt_common_objfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When we need to allocate a new type, we need to know which objfile_obstack    to allocate the type on, since there is one for each objfile.  The places    where types are allocated are deeply buried in function call hierarchies    which know nothing about objfiles, so rather than trying to pass a    particular objfile down to them, we just do an end run around them and    set current_objfile to be whatever objfile we expect to be using at the    time types are being allocated.  For instance, when we start reading    symbols for a particular objfile, we set current_objfile to point to that    objfile, and when we are done, we set it back to NULL, to ensure that we    never put a type someplace other than where we are expecting to put it.    FIXME:  Maybe we should review the entire type handling system and    see if there is a better way to avoid this problem. */
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

begin_function_decl
specifier|extern
name|struct
name|objfile
modifier|*
name|allocate_objfile
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_entry_point_info
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|entry_point_address
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|build_objfile_section_table
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|terminate_minimal_symbol_table
parameter_list|(
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|put_objfile_before
parameter_list|(
name|struct
name|objfile
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
name|objfile_to_front
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unlink_objfile
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_objfile
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|cleanup
modifier|*
name|make_cleanup_free_objfile
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_all_objfiles
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objfile_relocate
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|,
name|struct
name|section_offsets
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|have_partial_symbols
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|have_full_symbols
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This operation deletes all objfile entries that represent solibs that    weren't explicitly loaded by the user, via e.g., the add-symbol-file    command.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|objfile_purge_solibs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions for dealing with the minimal symbol table, really a misc    address<->symbol mapping for things we don't have debug symbols for.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|have_minimal_symbols
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|obj_section
modifier|*
name|find_pc_section
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|obj_section
modifier|*
name|find_pc_sect_section
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|asection
modifier|*
name|section
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|in_plt_section
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_in_import_list
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

begin_comment
comment|/* Keep a registry of per-objfile data-pointers required by other GDB    modules.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|struct
name|objfile_data
modifier|*
name|register_objfile_data
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_objfile_data
parameter_list|(
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_objfile_data
parameter_list|(
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|,
specifier|const
name|struct
name|objfile_data
modifier|*
name|data
parameter_list|,
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|objfile_data
parameter_list|(
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|,
specifier|const
name|struct
name|objfile_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

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
value|for ((m) = (objfile) -> msymbols; DEPRECATED_SYMBOL_NAME(m) != NULL; (m)++)
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
value|ALL_OBJFILES (objfile)	 \     ALL_OBJFILE_MSYMBOLS (objfile, m)
end_define

begin_define
define|#
directive|define
name|ALL_OBJFILE_OSECTIONS
parameter_list|(
name|objfile
parameter_list|,
name|osect
parameter_list|)
define|\
value|for (osect = objfile->sections; osect< objfile->sections_end; osect++)
end_define

begin_define
define|#
directive|define
name|ALL_OBJSECTIONS
parameter_list|(
name|objfile
parameter_list|,
name|osect
parameter_list|)
define|\
value|ALL_OBJFILES (objfile)			\     ALL_OBJFILE_OSECTIONS (objfile, osect)
end_define

begin_define
define|#
directive|define
name|SECT_OFF_DATA
parameter_list|(
name|objfile
parameter_list|)
define|\
value|((objfile->sect_index_data == -1) \       ? (internal_error (__FILE__, __LINE__, "sect_index_data not initialized"), -1) \       : objfile->sect_index_data)
end_define

begin_define
define|#
directive|define
name|SECT_OFF_RODATA
parameter_list|(
name|objfile
parameter_list|)
define|\
value|((objfile->sect_index_rodata == -1) \       ? (internal_error (__FILE__, __LINE__, "sect_index_rodata not initialized"), -1) \       : objfile->sect_index_rodata)
end_define

begin_define
define|#
directive|define
name|SECT_OFF_TEXT
parameter_list|(
name|objfile
parameter_list|)
define|\
value|((objfile->sect_index_text == -1) \       ? (internal_error (__FILE__, __LINE__, "sect_index_text not initialized"), -1) \       : objfile->sect_index_text)
end_define

begin_comment
comment|/* Sometimes the .bss section is missing from the objfile, so we don't    want to die here. Let the users of SECT_OFF_BSS deal with an    uninitialized section index. */
end_comment

begin_define
define|#
directive|define
name|SECT_OFF_BSS
parameter_list|(
name|objfile
parameter_list|)
value|(objfile)->sect_index_bss
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (OBJFILES_H) */
end_comment

end_unit

