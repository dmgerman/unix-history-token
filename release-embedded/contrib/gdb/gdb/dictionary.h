begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Routines for name->symbol lookups in GDB.        Copyright 2003 Free Software Foundation, Inc.     Contributed by David Carlton<carlton@bactrian.org> and by Kealia,    Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or (at    your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DICTIONARY_H
end_ifndef

begin_define
define|#
directive|define
name|DICTIONARY_H
end_define

begin_comment
comment|/* An opaque type for dictionaries; only dictionary.c should know    about its innards.  */
end_comment

begin_struct_decl
struct_decl|struct
name|dictionary
struct_decl|;
end_struct_decl

begin_comment
comment|/* Other types needed for declarations.  */
end_comment

begin_struct_decl
struct_decl|struct
name|symbol
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|obstack
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pending
struct_decl|;
end_struct_decl

begin_comment
comment|/* The creation functions for various implementations of    dictionaries.  */
end_comment

begin_comment
comment|/* Create a dictionary implemented via a fixed-size hashtable.  All    memory it uses is allocated on OBSTACK; the environment is    initialized from SYMBOL_LIST.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|dictionary
modifier|*
name|dict_create_hashed
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|,
specifier|const
name|struct
name|pending
modifier|*
name|symbol_list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create a dictionary implemented via a hashtable that grows as    necessary.  The dictionary is initially empty; to add symbols to    it, call dict_add_symbol().  Call dict_free() when you're done with    it.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|dictionary
modifier|*
name|dict_create_hashed_expandable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create a dictionary implemented via a fixed-size array.  All memory    it uses is allocated on OBSTACK; the environment is initialized    from the SYMBOL_LIST.  The symbols are ordered in the same order    that they're found in SYMBOL_LIST.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|dictionary
modifier|*
name|dict_create_linear
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|,
specifier|const
name|struct
name|pending
modifier|*
name|symbol_list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create a dictionary implemented via an array that grows as    necessary.  The dictionary is initially empty; to add symbols to    it, call dict_add_symbol().  Call dict_free() when you're done with    it.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|dictionary
modifier|*
name|dict_create_linear_expandable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The functions providing the interface to dictionaries.  Note that    the most common parts of the interface, namely symbol lookup, are    only provided via iterator functions.  */
end_comment

begin_comment
comment|/* Free the memory used by a dictionary that's not on an obstack.  (If    any.)  */
end_comment

begin_function_decl
specifier|extern
name|void
name|dict_free
parameter_list|(
name|struct
name|dictionary
modifier|*
name|dict
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add a symbol to an expandable dictionary.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|dict_add_symbol
parameter_list|(
name|struct
name|dictionary
modifier|*
name|dict
parameter_list|,
name|struct
name|symbol
modifier|*
name|sym
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Is the dictionary empty?  */
end_comment

begin_function_decl
specifier|extern
name|int
name|dict_empty
parameter_list|(
name|struct
name|dictionary
modifier|*
name|dict
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* A type containing data that is used when iterating over all symbols    in a dictionary.  Don't ever look at its innards; this type would    be opaque if we didn't need to be able to allocate it on the    stack.  */
end_comment

begin_struct
struct|struct
name|dict_iterator
block|{
comment|/* The dictionary that this iterator is associated to.  */
specifier|const
name|struct
name|dictionary
modifier|*
name|dict
decl_stmt|;
comment|/* The next two members are data that is used in a way that depends      on DICT's implementation type.  */
name|int
name|index
decl_stmt|;
name|struct
name|symbol
modifier|*
name|current
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Initialize ITERATOR to point at the first symbol in DICT, and    return that first symbol, or NULL if DICT is empty.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|dict_iterator_first
parameter_list|(
specifier|const
name|struct
name|dictionary
modifier|*
name|dict
parameter_list|,
name|struct
name|dict_iterator
modifier|*
name|iterator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Advance ITERATOR, and return the next symbol, or NULL if there are    no more symbols.  Don't call this if you've previously received    NULL from dict_iterator_first or dict_iterator_next on this    iteration.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|dict_iterator_next
parameter_list|(
name|struct
name|dict_iterator
modifier|*
name|iterator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize ITERATOR to point at the first symbol in DICT whose    SYMBOL_BEST_NAME is NAME (as tested using strcmp_iw), and return    that first symbol, or NULL if there are no such symbols.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|dict_iter_name_first
parameter_list|(
specifier|const
name|struct
name|dictionary
modifier|*
name|dict
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|dict_iterator
modifier|*
name|iterator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Advance ITERATOR to point at the next symbol in DICT whose    SYMBOL_BEST_NAME is NAME (as tested using strcmp_iw), or NULL if    there are no more such symbols.  Don't call this if you've    previously received NULL from dict_iterator_first or    dict_iterator_next on this iteration.  And don't call it unless    ITERATOR was created by a previous call to dict_iter_name_first    with the same NAME.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|dict_iter_name_next
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|dict_iterator
modifier|*
name|iterator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return some notion of the size of the dictionary: the number of    symbols if we have that, the number of hash buckets otherwise.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|dict_size
parameter_list|(
specifier|const
name|struct
name|dictionary
modifier|*
name|dict
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Macro to loop through all symbols in a dictionary DICT, in no    particular order.  ITER is a struct dict_iterator (NOTE: __not__ a    struct dict_iterator *), and SYM points to the current symbol.     It's implemented as a single loop, so you can terminate the loop    early by a break if you desire.  */
end_comment

begin_define
define|#
directive|define
name|ALL_DICT_SYMBOLS
parameter_list|(
name|dict
parameter_list|,
name|iter
parameter_list|,
name|sym
parameter_list|)
define|\
value|for ((sym) = dict_iterator_first ((dict),&(iter));	\ 	     (sym);						\ 	     (sym) = dict_iterator_next (&(iter)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DICTIONARY_H */
end_comment

end_unit

