begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Build symbol tables in GDB's internal format.    Copyright 1986-1993, 1996-1999 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BUILDSYM_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|BUILDSYM_H
value|1
end_define

begin_comment
comment|/* This module provides definitions used for creating and adding to    the symbol table.  These routines are called from various symbol-    file-reading routines.     They originated in dbxread.c of gdb-4.2, and were split out to    make xcoffread.c more maintainable by sharing code.     Variables declared in this file can be defined by #define-ing the    name EXTERN to null.  It is used to declare variables that are    normally extern, but which get defined in a single module using    this technique.  */
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

begin_define
define|#
directive|define
name|HASHSIZE
value|127
end_define

begin_comment
comment|/* Size of things hashed via 				   hashname() */
end_comment

begin_comment
comment|/* Name of source file whose symbol data we are now processing.  This    comes from a symbol of type N_SO. */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|last_source_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Core address of start of text of current source file.  This too    comes from the N_SO symbol. */
end_comment

begin_decl_stmt
name|EXTERN
name|CORE_ADDR
name|last_source_start_addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The list of sub-source-files within the current individual    compilation.  Each file gets its own symtab with its own linetable    and associated info, but they all share one blockvector.  */
end_comment

begin_struct
struct|struct
name|subfile
block|{
name|struct
name|subfile
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|dirname
decl_stmt|;
name|struct
name|linetable
modifier|*
name|line_vector
decl_stmt|;
name|int
name|line_vector_length
decl_stmt|;
name|enum
name|language
name|language
decl_stmt|;
name|char
modifier|*
name|debugformat
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|EXTERN
name|struct
name|subfile
modifier|*
name|subfiles
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|struct
name|subfile
modifier|*
name|current_subfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global variable which, when set, indicates that we are processing a    .o file compiled with gcc */
end_comment

begin_decl_stmt
name|EXTERN
name|unsigned
name|char
name|processing_gcc_compilation
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When set, we are processing a .o file compiled by sun acc.  This is    misnamed; it refers to all stabs-in-elf implementations which use    N_UNDF the way Sun does, including Solaris gcc.  Hopefully all    stabs-in-elf implementations ever invented will choose to be    compatible.  */
end_comment

begin_decl_stmt
name|EXTERN
name|unsigned
name|char
name|processing_acc_compilation
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* elz: added this flag to know when a block is compiled with HP    compilers (cc, aCC). This is necessary because of the macro    COERCE_FLOAT_TO_DOUBLE defined in tm_hppa.h, which causes a    coercion of float to double to always occur in parameter passing    for a function called by gdb (see the function value_arg_coerce in    valops.c). This is necessary only if the target was compiled with    gcc, not with HP compilers or with g++ */
end_comment

begin_decl_stmt
name|EXTERN
name|unsigned
name|char
name|processing_hp_compilation
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Count symbols as they are processed, for error messages.  */
end_comment

begin_decl_stmt
name|EXTERN
name|unsigned
name|int
name|symnum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Record the symbols defined for each context in a list.  We don't    create a struct block for the context until we know how long to    make it.  */
end_comment

begin_define
define|#
directive|define
name|PENDINGSIZE
value|100
end_define

begin_struct
struct|struct
name|pending
block|{
name|struct
name|pending
modifier|*
name|next
decl_stmt|;
name|int
name|nsyms
decl_stmt|;
name|struct
name|symbol
modifier|*
name|symbol
index|[
name|PENDINGSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Here are the three lists that symbols are put on.  */
end_comment

begin_comment
comment|/* static at top level, and types */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|pending
modifier|*
name|file_symbols
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global functions and variables */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|pending
modifier|*
name|global_symbols
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* everything local to lexical context */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|pending
modifier|*
name|local_symbols
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* func params local to lexical  context */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|pending
modifier|*
name|param_symbols
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stack representing unclosed lexical contexts (that will become    blocks, eventually).  */
end_comment

begin_struct
struct|struct
name|context_stack
block|{
comment|/* Outer locals at the time we entered */
name|struct
name|pending
modifier|*
name|locals
decl_stmt|;
comment|/* Pending func params at the time we entered */
name|struct
name|pending
modifier|*
name|params
decl_stmt|;
comment|/* Pointer into blocklist as of entry */
name|struct
name|pending_block
modifier|*
name|old_blocks
decl_stmt|;
comment|/* Name of function, if any, defining context */
name|struct
name|symbol
modifier|*
name|name
decl_stmt|;
comment|/* PC where this context starts */
name|CORE_ADDR
name|start_addr
decl_stmt|;
comment|/* Temp slot for exception handling. */
name|CORE_ADDR
name|end_addr
decl_stmt|;
comment|/* For error-checking matching push/pop */
name|int
name|depth
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|EXTERN
name|struct
name|context_stack
modifier|*
name|context_stack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index of first unused entry in context stack.  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|context_stack_depth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Currently allocated size of context stack.  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|context_stack_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macro "function" for popping contexts from the stack.  Pushing is    done by a real function, push_context.  This returns a pointer to a    struct context_stack.  */
end_comment

begin_define
define|#
directive|define
name|pop_context
parameter_list|()
value|(&context_stack[--context_stack_depth]);
end_define

begin_comment
comment|/* Nonzero if within a function (so symbols should be local, if    nothing says specifically).  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|within_function
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of blocks already made (lexical contexts already closed).    This is used at the end to make the blockvector.  */
end_comment

begin_struct
struct|struct
name|pending_block
block|{
name|struct
name|pending_block
modifier|*
name|next
decl_stmt|;
name|struct
name|block
modifier|*
name|block
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Pointer to the head of a linked list of symbol blocks which have    already been finalized (lexical contexts already closed) and which    are just waiting to be built into a blockvector when finalizing the    associated symtab. */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|pending_block
modifier|*
name|pending_blocks
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_struct
struct|struct
name|subfile_stack
block|{
name|struct
name|subfile_stack
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|EXTERN
name|struct
name|subfile_stack
modifier|*
name|subfile_stack
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|next_symbol_text
parameter_list|(
name|objfile
parameter_list|)
value|(*next_symbol_text_func)(objfile)
end_define

begin_comment
comment|/* Function to invoke get the next symbol.  Return the symbol name. */
end_comment

begin_function_decl
name|EXTERN
name|char
modifier|*
function_decl|(
modifier|*
name|next_symbol_text_func
function_decl|)
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Vector of types defined so far, indexed by their type numbers.    Used for both stabs and coff.  (In newer sun systems, dbx uses a    pair of numbers in parens, as in "(SUBFILENUM,NUMWITHINSUBFILE)".    Then these numbers must be translated through the type_translations    hash table to get the index into the type vector.)  */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|type
modifier|*
modifier|*
name|type_vector
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of elements allocated for type_vector currently.  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|type_vector_length
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initial size of type vector.  Is realloc'd larger if needed, and    realloc'd down to the size actually used, when completed.  */
end_comment

begin_define
define|#
directive|define
name|INITIAL_TYPE_VECTOR_LENGTH
value|160
end_define

begin_function_decl
specifier|extern
name|void
name|add_symbol_to_list
parameter_list|(
name|struct
name|symbol
modifier|*
name|symbol
parameter_list|,
name|struct
name|pending
modifier|*
modifier|*
name|listhead
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|find_symbol_in_list
parameter_list|(
name|struct
name|pending
modifier|*
name|list
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_block
parameter_list|(
name|struct
name|symbol
modifier|*
name|symbol
parameter_list|,
name|struct
name|pending
modifier|*
modifier|*
name|listhead
parameter_list|,
name|struct
name|pending_block
modifier|*
name|old_blocks
parameter_list|,
name|CORE_ADDR
name|start
parameter_list|,
name|CORE_ADDR
name|end
parameter_list|,
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
name|really_free_pendings
parameter_list|(
name|int
name|foo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|start_subfile
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|dirname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|patch_subfile_names
parameter_list|(
name|struct
name|subfile
modifier|*
name|subfile
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_subfile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|pop_subfile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symtab
modifier|*
name|end_symtab
parameter_list|(
name|CORE_ADDR
name|end_addr
parameter_list|,
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|,
name|int
name|section
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in stabsread.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|scan_file_globals
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
name|buildsym_new_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|buildsym_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|context_stack
modifier|*
name|push_context
parameter_list|(
name|int
name|desc
parameter_list|,
name|CORE_ADDR
name|valu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_line
parameter_list|(
name|struct
name|subfile
modifier|*
name|subfile
parameter_list|,
name|int
name|line
parameter_list|,
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|start_symtab
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|dirname
parameter_list|,
name|CORE_ADDR
name|start_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hashname
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_pending_blocks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FIXME: Note that this is used only in buildsym.c and dstread.c,    which should be fixed to not need direct access to    make_blockvector. */
end_comment

begin_function_decl
specifier|extern
name|struct
name|blockvector
modifier|*
name|make_blockvector
parameter_list|(
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FIXME: Note that this is used only in buildsym.c and dstread.c,    which should be fixed to not need direct access to    record_pending_block. */
end_comment

begin_function_decl
specifier|extern
name|void
name|record_pending_block
parameter_list|(
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|,
name|struct
name|block
modifier|*
name|block
parameter_list|,
name|struct
name|pending_block
modifier|*
name|opblock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_debugformat
parameter_list|(
name|char
modifier|*
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|merge_symbol_lists
parameter_list|(
name|struct
name|pending
modifier|*
modifier|*
name|srclist
parameter_list|,
name|struct
name|pending
modifier|*
modifier|*
name|targetlist
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|EXTERN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (BUILDSYM_H) */
end_comment

end_unit

