begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Symbol table definitions for GDB.    Copyright (C) 1986, 1989, 1991, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SYMTAB_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYMTAB_H
value|1
end_define

begin_include
include|#
directive|include
file|"obstack.h"
end_include

begin_comment
comment|/* See the comment in symfile.c about how current_objfile is used. */
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
comment|/* Some definitions and declarations to go with use of obstacks.  */
end_comment

begin_define
define|#
directive|define
name|obstack_chunk_alloc
value|xmalloc
end_define

begin_define
define|#
directive|define
name|obstack_chunk_free
value|free
end_define

begin_comment
comment|/* Some macros for char-based bitfields.  */
end_comment

begin_define
define|#
directive|define
name|B_SET
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
value|((a)[(x)>>3] |= (1<< ((x)&7)))
end_define

begin_define
define|#
directive|define
name|B_CLR
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
value|((a)[(x)>>3]&= ~(1<< ((x)&7)))
end_define

begin_define
define|#
directive|define
name|B_TST
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
value|((a)[(x)>>3]& (1<< ((x)&7)))
end_define

begin_define
define|#
directive|define
name|B_TYPE
value|unsigned char
end_define

begin_define
define|#
directive|define
name|B_BYTES
parameter_list|(
name|x
parameter_list|)
value|( 1 + ((x)>>3) )
end_define

begin_define
define|#
directive|define
name|B_CLRALL
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
value|memset ((a), 0, B_BYTES(x))
end_define

begin_comment
comment|/* Define a simple structure used to hold some very basic information about    all defined global symbols (text, data, bss, abs, etc).  The only two    required pieces of information are the symbol's name and the address    associated with that symbol.  In many cases, even if a file was compiled    with no special options for debugging at all, as long as was not stripped    it will contain sufficient information to build a useful minimal symbol    table using this structure.  Even when a file contains enough debugging    information to build a full symbol table, these minimal symbols are still    useful for quickly mapping between names and addresses, and vice versa.    They are also sometimes used to figure out what full symbol table entries    need to be read in. */
end_comment

begin_struct
struct|struct
name|minimal_symbol
block|{
comment|/* Name of the symbol.  This is a required field.  Storage for the name is      allocated on the symbol_obstack for the associated objfile. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Address of the symbol.  This is a required field. */
name|CORE_ADDR
name|address
decl_stmt|;
comment|/* The info field is available for caching machine-specific information that      The AMD 29000 tdep.c uses it to remember things it has decoded from the      instructions in the function header, so it doesn't have to rederive the      info constantly (over a serial line).  It is initialized to zero and      stays that way until target-dependent code sets it.  Storage for any data      pointed to by this field should be allocated on the symbol_obstack for      the associated objfile.  The type would be "void *" except for reasons      of compatibility with older compilers.  This field is optional. */
name|char
modifier|*
name|info
decl_stmt|;
comment|/* Classification types for this symbol.  These should be taken as "advisory      only", since if gdb can't easily figure out a classification it simply      selects mst_unknown.  It may also have to guess when it can't figure out      which is a better match between two types (mst_data versus mst_bss) for      example.  Since the minimal symbol info is sometimes derived from the      BFD library's view of a file, we need to live with what information bfd      supplies. */
enum|enum
name|minimal_symbol_type
block|{
name|mst_unknown
init|=
literal|0
block|,
comment|/* Unknown type, the default */
name|mst_text
block|,
comment|/* Generally executable instructions */
name|mst_data
block|,
comment|/* Generally initialized data */
name|mst_bss
block|,
comment|/* Generally uninitialized data */
name|mst_abs
comment|/* Generally absolute (nonrelocatable) */
block|}
name|type
enum|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* All of the name-scope contours of the program    are represented by `struct block' objects.    All of these objects are pointed to by the blockvector.     Each block represents one name scope.    Each lexical context has its own block.     The first two blocks in the blockvector are special.    The first one contains all the symbols defined in this compilation    whose scope is the entire program linked together.    The second one contains all the symbols whose scope is the    entire compilation excluding other separate compilations.    In C, these correspond to global symbols and static symbols.     Each block records a range of core addresses for the code that    is in the scope of the block.  The first two special blocks    give, for the range of code, the entire range of code produced    by the compilation that the symbol segment belongs to.     The blocks appear in the blockvector    in order of increasing starting-address,    and, within that, in order of decreasing ending-address.     This implies that within the body of one function    the blocks appear in the order of a depth-first tree walk.  */
end_comment

begin_struct
struct|struct
name|blockvector
block|{
comment|/* Number of blocks in the list.  */
name|int
name|nblocks
decl_stmt|;
comment|/* The blocks themselves.  */
name|struct
name|block
modifier|*
name|block
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Special block numbers */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_BLOCK
value|0
end_define

begin_define
define|#
directive|define
name|STATIC_BLOCK
value|1
end_define

begin_define
define|#
directive|define
name|FIRST_LOCAL_BLOCK
value|2
end_define

begin_struct
struct|struct
name|block
block|{
comment|/* Addresses in the executable code that are in this block.      Note: in an unrelocated symbol segment in a file,      these are always zero.  They can be filled in from the      N_LBRAC and N_RBRAC symbols in the loader symbol table.  */
name|CORE_ADDR
name|startaddr
decl_stmt|,
name|endaddr
decl_stmt|;
comment|/* The symbol that names this block,      if the block is the body of a function;      otherwise, zero.      Note: In an unrelocated symbol segment in an object file,      this field may be zero even when the block has a name.      That is because the block is output before the name      (since the name resides in a higher block).      Since the symbol does point to the block (as its value),      it is possible to find the block and set its name properly.  */
name|struct
name|symbol
modifier|*
name|function
decl_stmt|;
comment|/* The `struct block' for the containing block, or 0 if none.  */
comment|/* Note that in an unrelocated symbol segment in an object file      this pointer may be zero when the correct value should be      the second special block (for symbols whose scope is one compilation).      This is because the compiler outputs the special blocks at the      very end, after the other blocks.   */
name|struct
name|block
modifier|*
name|superblock
decl_stmt|;
comment|/* A flag indicating whether or not the function corresponding      to this block was compiled with gcc or not.  If there is no      function corresponding to this block, this meaning of this flag      is undefined.  (In practice it will be 1 if the block was created      while processing a file compiled with gcc and 0 when not). */
name|unsigned
name|char
name|gcc_compile_flag
decl_stmt|;
comment|/* Number of local symbols.  */
name|int
name|nsyms
decl_stmt|;
comment|/* The symbols.  */
name|struct
name|symbol
modifier|*
name|sym
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Represent one symbol name; a variable, constant, function or typedef.  */
end_comment

begin_comment
comment|/* Different name spaces for symbols.  Looking up a symbol specifies    a namespace and ignores symbol definitions in other name spaces.     VAR_NAMESPACE is the usual namespace.    In C, this contains variables, function names, typedef names    and enum type values.     STRUCT_NAMESPACE is used in C to hold struct, union and enum type names.    Thus, if `struct foo' is used in a C program,    it produces a symbol named `foo' in the STRUCT_NAMESPACE.     LABEL_NAMESPACE may be used for names of labels (for gotos);    currently it is not used and labels are not recorded at all.  */
end_comment

begin_comment
comment|/* For a non-global symbol allocated statically,    the correct core address cannot be determined by the compiler.    The compiler puts an index number into the symbol's value field.    This index number can be matched with the "desc" field of    an entry in the loader symbol table.  */
end_comment

begin_enum
enum|enum
name|namespace
block|{
name|UNDEF_NAMESPACE
block|,
name|VAR_NAMESPACE
block|,
name|STRUCT_NAMESPACE
block|,
name|LABEL_NAMESPACE
block|}
enum|;
end_enum

begin_comment
comment|/* An address-class says where to find the value of a symbol.  */
end_comment

begin_enum
enum|enum
name|address_class
block|{
name|LOC_UNDEF
block|,
comment|/* Not used; catches errors */
name|LOC_CONST
block|,
comment|/* Value is constant int SYMBOL_VALUE, host byteorder */
name|LOC_STATIC
block|,
comment|/* Value is at fixed address SYMBOL_VALUE_ADDRESS */
name|LOC_REGISTER
block|,
comment|/* Value is in register */
name|LOC_ARG
block|,
comment|/* Value is at spec'd offset in arglist */
name|LOC_REF_ARG
block|,
comment|/* Value address is at spec'd offset in arglist. */
name|LOC_REGPARM
block|,
comment|/* Value is at spec'd offset in register window */
name|LOC_LOCAL
block|,
comment|/* Value is at spec'd offset in stack frame */
name|LOC_TYPEDEF
block|,
comment|/* Value not used; definition in SYMBOL_TYPE 			   Symbols in the namespace STRUCT_NAMESPACE 			   all have this class.  */
name|LOC_LABEL
block|,
comment|/* Value is address SYMBOL_VALUE_ADDRESS in the code */
name|LOC_BLOCK
block|,
comment|/* Value is address SYMBOL_VALUE_BLOCK of a 			   `struct block'.  Function names have this class. */
name|LOC_CONST_BYTES
block|,
comment|/* Value is a constant byte-sequence pointed to by 			   SYMBOL_VALUE_ADDRESS, in target byte order.  */
name|LOC_LOCAL_ARG
comment|/* Value is arg at spec'd offset in stack frame. 			   Differs from LOC_LOCAL in that symbol is an 			   argument; differs from LOC_ARG in that we find it 			   in the frame (FRAME_LOCALS_ADDRESS), not in the 			   arglist (FRAME_ARGS_ADDRESS).  Added for i960, 			   which passes args in regs then copies to frame.  */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|symbol
block|{
comment|/* Symbol name */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name space code.  */
name|enum
name|namespace
name|namespace
decl_stmt|;
comment|/* Address class */
name|enum
name|address_class
name|class
decl_stmt|;
comment|/* Data type of value */
name|struct
name|type
modifier|*
name|type
decl_stmt|;
comment|/* Line number of definition.  */
name|unsigned
name|short
name|line
decl_stmt|;
comment|/* constant value, or address if static, or register number,      or offset in arguments, or offset in stack frame.  All of      these are in host byte order (though what they point to might      be in target byte order, e.g. LOC_CONST_BYTES).  */
union|union
block|{
name|long
name|value
decl_stmt|;
comment|/* for LOC_CONST, LOC_REGISTER, LOC_ARG,  				   LOC_REF_ARG, LOC_REGPARM, LOC_LOCAL */
name|struct
name|block
modifier|*
name|block
decl_stmt|;
comment|/* for LOC_BLOCK */
name|char
modifier|*
name|bytes
decl_stmt|;
comment|/* for LOC_CONST_BYTES */
name|CORE_ADDR
name|address
decl_stmt|;
comment|/* for LOC_STATIC, LOC_LABEL */
name|struct
name|symbol
modifier|*
name|chain
decl_stmt|;
comment|/* for opaque typedef struct chain */
block|}
name|value
union|;
comment|/* Some symbols require an additional value to be recorded on a per-      symbol basis.  Stash those values here. */
union|union
block|{
struct|struct
comment|/* for OP_BASEREG in DWARF location specs */
block|{
name|short
name|regno_valid
decl_stmt|;
comment|/* 0 == regno invalid; !0 == regno valid */
name|short
name|regno
decl_stmt|;
comment|/* base register number {0, 1, 2, ...} */
block|}
name|basereg
struct|;
block|}
name|aux_value
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* A partial_symbol records the name, namespace, and address class of    symbols whose types we have not parsed yet.  For functions, it also    contains their memory address, so we can find them from a PC value.    Each partial_symbol sits in a partial_symtab, all of which are chained    on a  partial symtab list and which points to the corresponding     normal symtab once the partial_symtab has been referenced.  */
end_comment

begin_struct
struct|struct
name|partial_symbol
block|{
comment|/* Symbol name */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name space code.  */
name|enum
name|namespace
name|namespace
decl_stmt|;
comment|/* Address class (for info_symbols) */
name|enum
name|address_class
name|class
decl_stmt|;
comment|/* Value (only used for static functions currently).  Done this      way so that we can use the struct symbol macros.      Note that the address of a function is SYMBOL_VALUE_ADDRESS (pst)      in a partial symbol table, but BLOCK_START (SYMBOL_BLOCK_VALUE (st))      in a symbol table.  */
union|union
block|{
name|long
name|value
decl_stmt|;
name|CORE_ADDR
name|address
decl_stmt|;
block|}
name|value
union|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Source-file information.    This describes the relation between source files and line numbers    and addresses in the program text.  */
end_comment

begin_struct
struct|struct
name|sourcevector
block|{
name|int
name|length
decl_stmt|;
comment|/* Number of source files described */
name|struct
name|source
modifier|*
name|source
index|[
literal|1
index|]
decl_stmt|;
comment|/* Descriptions of the files */
block|}
struct|;
end_struct

begin_comment
comment|/* Each item represents a line-->pc (or the reverse) mapping.  This is    somewhat more wasteful of space than one might wish, but since only    the files which are actually debugged are read in to core, we don't    waste much space.     Each item used to be an int; either minus a line number, or a    program counter.  If it represents a line number, that is the line    described by the next program counter value.  If it is positive, it    is the program counter at which the code for the next line starts.  */
end_comment

begin_struct
struct|struct
name|linetable_entry
block|{
name|int
name|line
decl_stmt|;
name|CORE_ADDR
name|pc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linetable
block|{
name|int
name|nitems
decl_stmt|;
name|struct
name|linetable_entry
name|item
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* All the information on one source file.  */
end_comment

begin_struct
struct|struct
name|source
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of file */
name|struct
name|linetable
name|contents
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* How to relocate the symbols from each section in a symbol file.    Each struct contains an array of offsets.    The ordering and meaning of the offsets is file-type-dependent;    typically it is indexed by section numbers or symbol types or    something like that.     To give us flexibility in changing the internal representation    of these offsets, the ANOFFSET macro must be used to insert and    extract offset values in the struct.  */
end_comment

begin_struct
struct|struct
name|section_offsets
block|{
name|CORE_ADDR
name|offsets
index|[
literal|1
index|]
decl_stmt|;
comment|/* As many as needed. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ANOFFSET
parameter_list|(
name|secoff
parameter_list|,
name|whichone
parameter_list|)
value|(secoff->offsets[whichone])
end_define

begin_comment
comment|/* Each source file is represented by a struct symtab.     These objects are chained through the `next' field.  */
end_comment

begin_struct
struct|struct
name|symtab
block|{
comment|/* Chain of all existing symtabs.  */
name|struct
name|symtab
modifier|*
name|next
decl_stmt|;
comment|/* List of all symbol scope blocks for this symtab.  */
name|struct
name|blockvector
modifier|*
name|blockvector
decl_stmt|;
comment|/* Table mapping core addresses to line numbers for this file.        Can be NULL if none.  */
name|struct
name|linetable
modifier|*
name|linetable
decl_stmt|;
comment|/* Name of this source file.  */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* Directory in which it was compiled, or NULL if we don't know.  */
name|char
modifier|*
name|dirname
decl_stmt|;
comment|/* This component says how to free the data we point to:        free_contents => do a tree walk and free each object.        free_nothing => do nothing; some other symtab will free          the data this one uses.        free_linetable => free just the linetable.  */
enum|enum
name|free_code
block|{
name|free_nothing
block|,
name|free_contents
block|,
name|free_linetable
block|}
name|free_code
enum|;
comment|/* Pointer to one block of storage to be freed, if nonzero.  */
comment|/* This is IN ADDITION to the action indicated by free_code.  */
name|char
modifier|*
name|free_ptr
decl_stmt|;
comment|/* Total number of lines found in source file.  */
name|int
name|nlines
decl_stmt|;
comment|/* Array mapping line number to character position.  */
name|int
modifier|*
name|line_charpos
decl_stmt|;
comment|/* Language of this source file.  */
name|enum
name|language
name|language
decl_stmt|;
comment|/* String of version information.  May be zero.  */
name|char
modifier|*
name|version
decl_stmt|;
comment|/* Full name of file as found by searching the source path.        0 if not yet known.  */
name|char
modifier|*
name|fullname
decl_stmt|;
comment|/* Object file from which this symbol information was read.  */
name|struct
name|objfile
modifier|*
name|objfile
decl_stmt|;
comment|/* Anything extra for this symtab.  This is for target machines        with special debugging info of some sort (which cannot just        be represented in a normal symtab).  */
if|#
directive|if
name|defined
argument_list|(
name|EXTRA_SYMTAB_INFO
argument_list|)
name|EXTRA_SYMTAB_INFO
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* Each source file that has not been fully read in is represented by    a partial_symtab.  This contains the information on where in the    executable the debugging symbols for a specific file are, and a    list of names of global symbols which are located in this file.    They are all chained on partial symtab lists.     Even after the source file has been read into a symtab, the    partial_symtab remains around.  They are allocated on an obstack,    psymbol_obstack.  FIXME, this is bad for dynamic linking or VxWorks-    style execution of a bunch of .o's.  */
end_comment

begin_struct
struct|struct
name|partial_symtab
block|{
comment|/* Chain of all existing partial symtabs.  */
name|struct
name|partial_symtab
modifier|*
name|next
decl_stmt|;
comment|/* Name of the source file which this partial_symtab defines */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* Information about the object file from which symbols should be read.  */
name|struct
name|objfile
modifier|*
name|objfile
decl_stmt|;
comment|/* Set of relocation offsets to apply to each section.  */
name|struct
name|section_offsets
modifier|*
name|section_offsets
decl_stmt|;
comment|/* Range of text addresses covered by this file; texthigh is the      beginning of the next section. */
name|CORE_ADDR
name|textlow
decl_stmt|,
name|texthigh
decl_stmt|;
comment|/* Array of pointers to all of the partial_symtab's which this one      depends on.  Since this array can only be set to previous or      the current (?) psymtab, this dependency tree is guaranteed not      to have any loops. */
name|struct
name|partial_symtab
modifier|*
modifier|*
name|dependencies
decl_stmt|;
name|int
name|number_of_dependencies
decl_stmt|;
comment|/* Global symbol list.  This list will be sorted after readin to      improve access.  Binary search will be the usual method of      finding a symbol within it. globals_offset is an integer offset      within global_psymbols[].  */
name|int
name|globals_offset
decl_stmt|,
name|n_global_syms
decl_stmt|;
comment|/* Static symbol list.  This list will *not* be sorted after readin;      to find a symbol in it, exhaustive search must be used.  This is      reasonable because searches through this list will eventually      lead to either the read in of a files symbols for real (assumed      to take a *lot* of time; check) or an error (and we don't care      how long errors take).  This is an offset and size within      static_psymbols[].  */
name|int
name|statics_offset
decl_stmt|,
name|n_static_syms
decl_stmt|;
comment|/* Pointer to symtab eventually allocated for this source file, 0 if      !readin or if we haven't looked for the symtab after it was readin.  */
name|struct
name|symtab
modifier|*
name|symtab
decl_stmt|;
comment|/* Pointer to function which will read in the symtab corresponding to      this psymtab.  */
name|void
argument_list|(
argument|*read_symtab
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|partial_symtab
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Information that lets read_symtab() locate the part of the symbol table      that this psymtab corresponds to.  This information is private to the      format-dependent symbol reading routines.  For further detail examine      the various symbol reading modules.  Should really be (void *) but is      (char *) as with other such gdb variables.  (FIXME) */
name|char
modifier|*
name|read_symtab_private
decl_stmt|;
comment|/* Non-zero if the symtab corresponding to this psymtab has been      readin */
name|unsigned
name|char
name|readin
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A fast way to get from a psymtab to its symtab (after the first time).  */
end_comment

begin_define
define|#
directive|define
name|PSYMTAB_TO_SYMTAB
parameter_list|(
name|pst
parameter_list|)
value|((pst)->symtab? 		\ 				 (pst)->symtab: 		\ 				 psymtab_to_symtab (pst) )
end_define

begin_comment
comment|/* This symtab variable specifies the current file for printing source lines */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
name|current_source_symtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is the next line to print for listing source lines.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_source_line
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BLOCKVECTOR
parameter_list|(
name|symtab
parameter_list|)
value|(symtab)->blockvector
end_define

begin_define
define|#
directive|define
name|LINETABLE
parameter_list|(
name|symtab
parameter_list|)
value|(symtab)->linetable
end_define

begin_escape
end_escape

begin_comment
comment|/* Macros normally used to access components of symbol table structures.  */
end_comment

begin_define
define|#
directive|define
name|BLOCKVECTOR_NBLOCKS
parameter_list|(
name|blocklist
parameter_list|)
value|(blocklist)->nblocks
end_define

begin_define
define|#
directive|define
name|BLOCKVECTOR_BLOCK
parameter_list|(
name|blocklist
parameter_list|,
name|n
parameter_list|)
value|(blocklist)->block[n]
end_define

begin_define
define|#
directive|define
name|BLOCK_START
parameter_list|(
name|bl
parameter_list|)
value|(bl)->startaddr
end_define

begin_define
define|#
directive|define
name|BLOCK_END
parameter_list|(
name|bl
parameter_list|)
value|(bl)->endaddr
end_define

begin_define
define|#
directive|define
name|BLOCK_NSYMS
parameter_list|(
name|bl
parameter_list|)
value|(bl)->nsyms
end_define

begin_define
define|#
directive|define
name|BLOCK_SYM
parameter_list|(
name|bl
parameter_list|,
name|n
parameter_list|)
value|(bl)->sym[n]
end_define

begin_define
define|#
directive|define
name|BLOCK_FUNCTION
parameter_list|(
name|bl
parameter_list|)
value|(bl)->function
end_define

begin_define
define|#
directive|define
name|BLOCK_SUPERBLOCK
parameter_list|(
name|bl
parameter_list|)
value|(bl)->superblock
end_define

begin_define
define|#
directive|define
name|BLOCK_GCC_COMPILED
parameter_list|(
name|bl
parameter_list|)
value|(bl)->gcc_compile_flag
end_define

begin_comment
comment|/* Nonzero if symbols of block BL should be sorted alphabetically.  */
end_comment

begin_define
define|#
directive|define
name|BLOCK_SHOULD_SORT
parameter_list|(
name|bl
parameter_list|)
value|((bl)->nsyms>= 40)
end_define

begin_define
define|#
directive|define
name|SYMBOL_NAME
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->name
end_define

begin_define
define|#
directive|define
name|SYMBOL_NAMESPACE
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->namespace
end_define

begin_define
define|#
directive|define
name|SYMBOL_CLASS
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->class
end_define

begin_define
define|#
directive|define
name|SYMBOL_VALUE
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->value.value
end_define

begin_define
define|#
directive|define
name|SYMBOL_VALUE_ADDRESS
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->value.address
end_define

begin_define
define|#
directive|define
name|SYMBOL_VALUE_BYTES
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->value.bytes
end_define

begin_define
define|#
directive|define
name|SYMBOL_BLOCK_VALUE
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->value.block
end_define

begin_define
define|#
directive|define
name|SYMBOL_VALUE_CHAIN
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->value.chain
end_define

begin_define
define|#
directive|define
name|SYMBOL_TYPE
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->type
end_define

begin_define
define|#
directive|define
name|SYMBOL_LINE
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->line
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* This currently fails because some symbols are not being initialized    to zero on allocation, and no code is currently setting this value.    Basereg handling will probably change significantly in the next release.    FIXME -fnf */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_BASEREG_VALID
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->aux_value.basereg.regno_valid
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SYMBOL_BASEREG_VALID
parameter_list|(
name|symbol
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SYMBOL_BASEREG
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->aux_value.basereg.regno
end_define

begin_comment
comment|/* The virtual function table is now an array of structures    which have the form { int16 offset, delta; void *pfn; }.      In normal virtual function tables, OFFSET is unused.    DELTA is the amount which is added to the apparent object's base    address in order to point to the actual object to which the    virtual function should be applied.    PFN is a pointer to the virtual function.  */
end_comment

begin_define
define|#
directive|define
name|VTBL_FNADDR_OFFSET
value|2
end_define

begin_comment
comment|/* Macro that yields non-zero value iff NAME is the prefix    for C++ operator names.  If you leave out the parenthesis    here you will lose!     Currently 'o' 'p' CPLUS_MARKER is used for both the symbol in the    symbol-file and the names in gdb's symbol table.  */
end_comment

begin_define
define|#
directive|define
name|OPNAME_PREFIX_P
parameter_list|(
name|NAME
parameter_list|)
value|((NAME)[0] == 'o'&& (NAME)[1] == 'p' \&& (NAME)[2] == CPLUS_MARKER)
end_define

begin_define
define|#
directive|define
name|VTBL_PREFIX_P
parameter_list|(
name|NAME
parameter_list|)
value|((NAME)[3] == CPLUS_MARKER	\&& !strncmp ((NAME), "_vt", 3))
end_define

begin_escape
end_escape

begin_comment
comment|/* Functions that work on the objects described above */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
name|lookup_symtab
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
name|struct
name|symbol
modifier|*
name|lookup_symbol
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
expr|struct
name|block
operator|*
operator|,
specifier|const
expr|enum
name|namespace
operator|,
name|int
operator|*
operator|,
expr|struct
name|symtab
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symbol
modifier|*
name|lookup_block_symbol
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|block
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
expr|enum
name|namespace
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|lookup_struct
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|lookup_union
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|lookup_enum
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symbol
modifier|*
name|block_function
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
name|struct
name|symbol
modifier|*
name|find_pc_function
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|find_pc_partial_function
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|char
operator|*
operator|*
operator|,
name|CORE_ADDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear_pc_function_cache
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
name|lookup_partial_symtab
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
name|struct
name|partial_symtab
modifier|*
name|find_pc_psymtab
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
name|find_pc_symtab
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|partial_symbol
modifier|*
name|find_pc_psymbol
name|PARAMS
argument_list|(
operator|(
expr|struct
name|partial_symtab
operator|*
operator|,
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|find_pc_line_pc_range
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|CORE_ADDR
operator|*
operator|,
name|CORE_ADDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|contained_in
name|PARAMS
argument_list|(
operator|(
expr|struct
name|block
operator|*
operator|,
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
name|reread_symbols
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
name|void
name|prim_record_minimal_symbol
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|CORE_ADDR
operator|,
expr|enum
name|minimal_symbol_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|prim_record_minimal_symbol_and_info
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|CORE_ADDR
operator|,
expr|enum
name|minimal_symbol_type
operator|,
name|char
operator|*
name|info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|minimal_symbol
modifier|*
name|lookup_minimal_symbol
name|PARAMS
argument_list|(
operator|(
specifier|const
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
name|struct
name|minimal_symbol
modifier|*
name|lookup_minimal_symbol_by_pc
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_minimal_symbol_collection
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
name|void
name|discard_minimal_symbols
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|install_minimal_symbols
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

begin_struct
struct|struct
name|symtab_and_line
block|{
name|struct
name|symtab
modifier|*
name|symtab
decl_stmt|;
name|int
name|line
decl_stmt|;
name|CORE_ADDR
name|pc
decl_stmt|;
name|CORE_ADDR
name|end
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|symtabs_and_lines
block|{
name|struct
name|symtab_and_line
modifier|*
name|sals
decl_stmt|;
name|int
name|nelts
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Given a pc value, return line number it is in.    Second arg nonzero means if pc is on the boundary    use the previous statement's line number.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symtab_and_line
name|find_pc_line
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a symtab and line number, return the pc there.  */
end_comment

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|find_line_pc
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|find_line_pc_range
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab
operator|*
operator|,
name|int
operator|,
name|CORE_ADDR
operator|*
operator|,
name|CORE_ADDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|resolve_sal_pc
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab_and_line
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a string, return the line specified by it.    For commands like "list" and "breakpoint".  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symtabs_and_lines
name|decode_line_spec
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symtabs_and_lines
name|decode_line_spec_1
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symtabs_and_lines
name|decode_line_1
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|int
operator|,
expr|struct
name|symtab
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Symmisc.c */
end_comment

begin_if
if|#
directive|if
name|MAINTENANCE_CMDS
end_if

begin_decl_stmt
name|void
name|maintenance_print_symbols
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|maintenance_print_psymbols
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|maintenance_print_msymbols
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|maintenance_print_objfiles
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
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

begin_decl_stmt
specifier|extern
name|void
name|free_symtab
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
comment|/* Symbol-reading stuff in symfile.c and solib.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
name|psymtab_to_symtab
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
name|clear_solib
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
name|objfile
modifier|*
name|symbol_file_add
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|CORE_ADDR
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|identify_source_line
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab
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
name|void
name|print_source_lines
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab
operator|*
operator|,
name|int
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
name|forget_cached_source_info
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
name|void
name|select_source_symtab
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
name|char
modifier|*
modifier|*
name|make_symbol_completion_list
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
comment|/* symtab.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|clear_symtab_users_once
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
name|find_main_psymtab
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* blockframe.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|blockvector
modifier|*
name|blockvector_for_pc
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* symfile.c */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|language
name|deduce_language_from_filename
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
comment|/* !defined(SYMTAB_H) */
end_comment

end_unit

