begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This code is derived from software copyrighted by the Free Software  * Foundation.  *  * Modified 1991 by Donn Seeley at UUNET Technologies, Inc.  * Modified 1990 by Van Jacobson at Lawrence Berkeley Laboratory.  *  *	@(#)symtab.h	6.3 (Berkeley) 5/8/91  */
end_comment

begin_comment
comment|/* Symbol table definitions for GDB.    Copyright (C) 1986, 1989 Free Software Foundation, Inc.  This file is part of GDB.  GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GDB; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|<obstack.h>
end_include

begin_comment
comment|/* An obstack to hold objects that should be freed    when we load a new symbol table.    This includes the symbols made by dbxread    and the types that are not permanent.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|obstack
modifier|*
name|symbol_obstack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|obstack
modifier|*
name|psymbol_obstack
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

begin_function_decl
specifier|extern
name|char
modifier|*
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* gdb can know one or several symbol tables at the same time;    the ultimate intent is to have one for each separately-compiled module.    Each such symbol table is recorded by a struct symtab, and they    are all chained together.  */
end_comment

begin_comment
comment|/* In addition, gdb can record any number of miscellaneous undebuggable    functions' addresses.  In a system that appends _ to function names,    the _'s are removed from the names stored in this table.  */
end_comment

begin_comment
comment|/* Actually, the misc function list is used to store *all* of the    global symbols (text, data, bss, and abs).  It is sometimes used    to figure out what symtabs to read in.  The "type" field appears    never to be used.  */
end_comment

begin_enum
enum|enum
name|misc_function_type
block|{
name|mf_unknown
init|=
literal|0
block|,
name|mf_text
block|,
name|mf_data
block|,
name|mf_bss
block|,
name|mf_abs
block|}
enum|;
end_enum

begin_struct
struct|struct
name|misc_function
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|CORE_ADDR
name|address
decl_stmt|;
name|int
name|next
decl_stmt|;
comment|/* index of next in this hash bucket */
name|unsigned
name|char
name|type
decl_stmt|;
comment|/* Really enum misc_function_type.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Address and length of the vector recording all misc function names/addresses.  */
end_comment

begin_decl_stmt
name|struct
name|misc_function
modifier|*
name|misc_function_vector
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|misc_function_count
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MISC_FUNC_HASH_SIZE
value|(2048)
end_define

begin_decl_stmt
name|int
name|misc_function_hash_tab
index|[
name|MISC_FUNC_HASH_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_include
include|#
directive|include
file|"symseg.h"
end_include

begin_comment
comment|/* Each source file is represented by a struct symtab.  */
end_comment

begin_comment
comment|/* These objects are chained through the `next' field.  */
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
comment|/* Table mapping core addresses to line numbers for this file.  */
name|struct
name|linetable
modifier|*
name|linetable
decl_stmt|;
comment|/* Vector containing all types defined for this symtab.  */
name|struct
name|typevector
modifier|*
name|typevector
decl_stmt|;
comment|/* Name of this source file.  */
name|char
modifier|*
name|filename
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
comment|/* String of compilation information.  May be zero.  */
name|char
modifier|*
name|compilation
decl_stmt|;
comment|/* Offset within loader symbol table        of first local symbol for this file.  */
name|int
name|ldsymoff
decl_stmt|;
comment|/* Full name of file as found by searching the source path.        0 if not yet known.  */
name|char
modifier|*
name|fullname
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Each source file that has not been fully read in is represented by  * a partial_symtab.  This contains the information on where in the  * executable the debugging symbols for a specific file are, and a  * list of names of global symbols which are located in this file.  */
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
comment|/* Offset within loader symbol table of first local symbol for this      file and length (in bytes) of the section of the symbol table      devoted to this file's symbols (actually, the section bracketed      may contain more than just this files symbols      If ldsymlen is 0, the only reason for this things existence is      the dependency list below.  Nothing else will happen when it is      read in.  */
name|int
name|ldsymoff
decl_stmt|,
name|ldsymlen
decl_stmt|;
comment|/* Range of text addresses covered by this file; texthigh is the      beginning of the next section. */
name|int
name|textlow
decl_stmt|,
name|texthigh
decl_stmt|;
comment|/* Non-zero if the symtab corresponding to this psymtab has been      readin */
name|unsigned
name|char
name|readin
decl_stmt|;
comment|/* Array of pointers to all of the partial_symtab s which this one      depends one.  Since this array can only be set to previous or      the current (?) psymtab, this dependency tree is guarranteed not      to have any loops. */
name|struct
name|partial_symtab
modifier|*
modifier|*
name|dependencies
decl_stmt|;
name|int
name|number_of_dependencies
decl_stmt|;
comment|/* Global symbol list.  This list will be sorted after readin to      improve access.  Binary search will be the usual method of      finding a symbol within it. globals_offset is an integer offset      within ps_globals */
name|int
name|globals_offset
decl_stmt|,
name|n_global_syms
decl_stmt|;
comment|/* Static symbol list.  This list will *not* be sorted after readin;      to find a symbol in it, exhaustive search must be used.  This is      reasonable because searches through this list will eventually      lead to either the read in of a files symbols for real (assumed      to take a *lot* of time; check) or an error (and we don't care      how long errors take). */
name|int
name|statics_offset
decl_stmt|,
name|n_static_syms
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This is the list of struct symtab's that gdb considers current.  */
end_comment

begin_decl_stmt
name|struct
name|symtab
modifier|*
name|symtab_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is the list of struct partial_symtab's that gdb may need to access */
end_comment

begin_decl_stmt
name|struct
name|partial_symtab
modifier|*
name|partial_symtab_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This symtab variable specifies the current file for printing source lines */
end_comment

begin_decl_stmt
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
name|int
name|current_source_line
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BLOCKLIST
parameter_list|(
name|symtab
parameter_list|)
value|(symtab)->blockvector
end_define

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
name|TYPEVECTOR
parameter_list|(
name|symtab
parameter_list|)
value|(symtab)->typevector
end_define

begin_define
define|#
directive|define
name|LINELIST
parameter_list|(
name|symtab
parameter_list|)
value|(symtab)->linetable
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
name|BLOCKLIST_NBLOCKS
parameter_list|(
name|blocklist
parameter_list|)
value|(blocklist)->nblocks
end_define

begin_define
define|#
directive|define
name|BLOCKLIST_BLOCK
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
name|TYPEVECTOR_NTYPES
parameter_list|(
name|typelist
parameter_list|)
value|(typelist)->length
end_define

begin_define
define|#
directive|define
name|TYPEVECTOR_TYPE
parameter_list|(
name|typelist
parameter_list|,
name|n
parameter_list|)
value|(typelist)->type[n]
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
name|SYMBOL_TYPE
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->type
end_define

begin_comment
comment|/* Some macros for bitfields.  */
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
value|(a[x>>5] |= (1<< (x&31)))
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
value|(a[x>>5]&= ~(1<< (x&31)))
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
value|(a[x>>5]& (1<< (x&31)))
end_define

begin_define
define|#
directive|define
name|TYPE_NAME
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->name
end_define

begin_define
define|#
directive|define
name|TYPE_TARGET_TYPE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->target_type
end_define

begin_define
define|#
directive|define
name|TYPE_POINTER_TYPE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->pointer_type
end_define

begin_define
define|#
directive|define
name|TYPE_REFERENCE_TYPE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->reference_type
end_define

begin_define
define|#
directive|define
name|TYPE_FUNCTION_TYPE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->function_type
end_define

begin_define
define|#
directive|define
name|TYPE_MAIN_VARIANT
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->main_variant
end_define

begin_define
define|#
directive|define
name|TYPE_NEXT_VARIANT
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->next_variant
end_define

begin_define
define|#
directive|define
name|TYPE_LENGTH
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->length
end_define

begin_define
define|#
directive|define
name|TYPE_FLAGS
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->flags
end_define

begin_define
define|#
directive|define
name|TYPE_UNSIGNED
parameter_list|(
name|thistype
parameter_list|)
value|((thistype)->flags& TYPE_FLAG_UNSIGNED)
end_define

begin_define
define|#
directive|define
name|TYPE_CODE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->code
end_define

begin_define
define|#
directive|define
name|TYPE_NFIELDS
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->nfields
end_define

begin_define
define|#
directive|define
name|TYPE_FIELDS
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->fields
end_define

begin_comment
comment|/* C++ */
end_comment

begin_define
define|#
directive|define
name|TYPE_VPTR_BASETYPE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->vptr_basetype
end_define

begin_define
define|#
directive|define
name|TYPE_DOMAIN_TYPE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->vptr_basetype
end_define

begin_define
define|#
directive|define
name|TYPE_VPTR_FIELDNO
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->vptr_fieldno
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELDS
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->fn_fields
end_define

begin_define
define|#
directive|define
name|TYPE_NFN_FIELDS
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->nfn_fields
end_define

begin_define
define|#
directive|define
name|TYPE_NFN_FIELDS_TOTAL
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->nfn_fields_total
end_define

begin_define
define|#
directive|define
name|TYPE_BASECLASSES
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->baseclasses
end_define

begin_define
define|#
directive|define
name|TYPE_ARG_TYPES
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->arg_types
end_define

begin_define
define|#
directive|define
name|TYPE_BASECLASS
parameter_list|(
name|thistype
parameter_list|,
name|index
parameter_list|)
value|(thistype)->baseclasses[index]
end_define

begin_define
define|#
directive|define
name|TYPE_N_BASECLASSES
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->n_baseclasses
end_define

begin_define
define|#
directive|define
name|TYPE_VIA_PUBLIC
parameter_list|(
name|thistype
parameter_list|)
value|((thistype)->flags& TYPE_FLAG_VIA_PUBLIC)
end_define

begin_define
define|#
directive|define
name|TYPE_VIA_VIRTUAL
parameter_list|(
name|thistype
parameter_list|)
value|((thistype)->flags& TYPE_FLAG_VIA_VIRTUAL)
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)->fields[n]
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_TYPE
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)->fields[n].type
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_NAME
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)->fields[n].name
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_VALUE
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(* (int*)&(thistype)->fields[n].type)
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_BITPOS
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)->fields[n].bitpos
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_BITSIZE
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)->fields[n].bitsize
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_PACKED
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)->fields[n].bitsize
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_PRIVATE_BITS
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->private_field_bits
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_PROTECTED_BITS
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->protected_field_bits
end_define

begin_define
define|#
directive|define
name|SET_TYPE_FIELD_PRIVATE
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|B_SET ((thistype)->private_field_bits, (n))
end_define

begin_define
define|#
directive|define
name|SET_TYPE_FIELD_PROTECTED
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|B_SET ((thistype)->protected_field_bits, (n))
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_PRIVATE
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|B_TST((thistype)->private_field_bits, (n))
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_PROTECTED
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|B_TST((thistype)->protected_field_bits, (n))
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_DESTRUCTOR
parameter_list|(
name|thistype
parameter_list|)
value|((thistype)->flags& TYPE_FLAG_HAS_DESTRUCTOR)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_CONSTRUCTOR
parameter_list|(
name|thistype
parameter_list|)
value|((thistype)->flags& TYPE_FLAG_HAS_CONSTRUCTOR)
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_STATIC
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|((thistype)->fields[n].bitpos == -1)
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_STATIC_PHYSNAME
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|((char *)(thistype)->fields[n].bitsize)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELDLISTS
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->fn_fieldlists
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELDLIST
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)->fn_fieldlists[n]
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELDLIST1
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)->fn_fieldlists[n].fn_fields
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELDLIST_NAME
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)->fn_fieldlists[n].name
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELDLIST_LENGTH
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)->fn_fieldlists[n].length
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)[n]
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_NAME
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)[n].name
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_TYPE
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)[n].type
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_ARGS
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)[n].args
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_PHYSNAME
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)[n].physname
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_VIRTUAL_P
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|((thistype)[n].voffset< 0)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_STATIC_P
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|((thistype)[n].voffset> 0)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_VOFFSET
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|((thistype)[n].voffset-1)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_PRIVATE_BITS
parameter_list|(
name|thistype
parameter_list|)
value|(thistype).private_fn_field_bits
end_define

begin_define
define|#
directive|define
name|TYPE_FN_PROTECTED_BITS
parameter_list|(
name|thistype
parameter_list|)
value|(thistype).protected_fn_field_bits
end_define

begin_define
define|#
directive|define
name|SET_TYPE_FN_PRIVATE
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|B_SET ((thistype).private_fn_field_bits, n)
end_define

begin_define
define|#
directive|define
name|SET_TYPE_FN_PROTECTED
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|B_SET ((thistype).protected_fn_field_bits, n)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_PRIVATE
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|B_TST ((thistype).private_fn_field_bits, n)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_PROTECTED
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|B_TST ((thistype).protected_fn_field_bits, n)
end_define

begin_escape
end_escape

begin_comment
comment|/* Functions that work on the objects described above */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symtab
modifier|*
name|lookup_symtab
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|lookup_symbol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|lookup_typename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|lookup_unsigned_typename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|lookup_struct
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|lookup_union
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|lookup_enum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|lookup_struct_elt_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|lookup_pointer_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|lookup_function_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|lookup_basetype_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|create_array_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|block_function
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|find_pc_function
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|find_pc_partial_function
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|partial_symtab
modifier|*
name|find_pc_psymtab
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symtab
modifier|*
name|find_pc_symtab
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|partial_symbol
modifier|*
name|find_pc_psymbol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|find_pc_misc_function
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* C++ stuff.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|lookup_reference_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|lookup_member_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|lookup_class
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* end of C++ stuff.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_void
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_short
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_int
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_long
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_unsigned_char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_unsigned_short
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_unsigned_int
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_unsigned_long
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_float
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_double
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|LONG_LONG
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_long_long
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_unsigned_long_long
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|BUILTIN_TYPE_LONGEST
end_ifndef

begin_define
define|#
directive|define
name|BUILTIN_TYPE_LONGEST
value|builtin_type_long_long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BUILTIN_TYPE_UNSIGNED_LONGEST
end_ifndef

begin_define
define|#
directive|define
name|BUILTIN_TYPE_UNSIGNED_LONGEST
value|builtin_type_unsigned_long_long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* LONG_LONG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUILTIN_TYPE_LONGEST
end_ifndef

begin_define
define|#
directive|define
name|BUILTIN_TYPE_LONGEST
value|builtin_type_long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BUILTIN_TYPE_UNSIGNED_LONGEST
end_ifndef

begin_define
define|#
directive|define
name|BUILTIN_TYPE_UNSIGNED_LONGEST
value|builtin_type_unsigned_long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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

begin_function_decl
name|struct
name|symtab_and_line
name|find_pc_line
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Given a string, return the line specified by it.    For commands like "list" and "breakpoint".  */
end_comment

begin_function_decl
name|struct
name|symtabs_and_lines
name|decode_line_spec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|symtabs_and_lines
name|decode_line_spec_1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|symtabs_and_lines
name|decode_line_1
parameter_list|()
function_decl|;
end_function_decl

end_unit

