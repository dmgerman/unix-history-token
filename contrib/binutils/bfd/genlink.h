begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* genlink.h -- interface to the BFD generic linker    Copyright 1993, 1994, 1996 Free Software Foundation, Inc.    Written by Ian Lance Taylor, Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GENLINK_H
end_ifndef

begin_define
define|#
directive|define
name|GENLINK_H
end_define

begin_comment
comment|/* This header file is internal to BFD.  It describes the internal    structures and functions used by the BFD generic linker, in case    any of the more specific linkers want to use or call them.  Note    that some functions, such as _bfd_generic_link_hash_table_create,    are declared in libbfd.h, because they are expected to be widely    used.  The functions and structures in this file will probably only    be used by a few files besides linker.c itself.  In fact, this file    is not particularly complete; I have only put in the interfaces I    actually needed.  */
end_comment

begin_comment
comment|/* The generic linker uses a hash table which is a derived class of    the standard linker hash table, just as the other backend specific    linkers do.  Do not confuse the generic linker hash table with the    standard BFD linker hash table it is built upon.  */
end_comment

begin_comment
comment|/* Generic linker hash table entries.  */
end_comment

begin_struct
struct|struct
name|generic_link_hash_entry
block|{
name|struct
name|bfd_link_hash_entry
name|root
decl_stmt|;
comment|/* Whether this symbol has been written out.  */
name|boolean
name|written
decl_stmt|;
comment|/* Symbol from input BFD.  */
name|asymbol
modifier|*
name|sym
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Generic linker hash table.  */
end_comment

begin_struct
struct|struct
name|generic_link_hash_table
block|{
name|struct
name|bfd_link_hash_table
name|root
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Look up an entry in an generic link hash table.  */
end_comment

begin_define
define|#
directive|define
name|_bfd_generic_link_hash_lookup
parameter_list|(
name|table
parameter_list|,
name|string
parameter_list|,
name|create
parameter_list|,
name|copy
parameter_list|,
name|follow
parameter_list|)
define|\
value|((struct generic_link_hash_entry *) \    bfd_link_hash_lookup (&(table)->root, (string), (create), (copy), (follow)))
end_define

begin_comment
comment|/* Traverse an generic link hash table.  */
end_comment

begin_define
define|#
directive|define
name|_bfd_generic_link_hash_traverse
parameter_list|(
name|table
parameter_list|,
name|func
parameter_list|,
name|info
parameter_list|)
define|\
value|(bfd_link_hash_traverse						\    (&(table)->root,							\     (boolean (*) PARAMS ((struct bfd_link_hash_entry *, PTR))) (func),	\     (info)))
end_define

begin_comment
comment|/* Get the generic link hash table from the info structure.  This is    just a cast.  */
end_comment

begin_define
define|#
directive|define
name|_bfd_generic_hash_table
parameter_list|(
name|p
parameter_list|)
define|\
value|((struct generic_link_hash_table *) ((p)->hash))
end_define

begin_comment
comment|/* The generic linker reads in the asymbol structures for an input BFD    and keeps them in the outsymbol and symcount fields.  */
end_comment

begin_define
define|#
directive|define
name|_bfd_generic_link_get_symbols
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->outsymbols)
end_define

begin_define
define|#
directive|define
name|_bfd_generic_link_get_symcount
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->symcount)
end_define

begin_comment
comment|/* Add the symbols of input_bfd to the symbols being built for    output_bfd.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_generic_link_output_symbols
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|output_bfd
operator|,
name|bfd
operator|*
name|input_bfd
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|,
name|size_t
operator|*
name|psymalloc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This structure is used to pass information to    _bfd_generic_link_write_global_symbol, which may be called via    _bfd_generic_link_hash_traverse.  */
end_comment

begin_struct
struct|struct
name|generic_write_global_symbol_info
block|{
name|struct
name|bfd_link_info
modifier|*
name|info
decl_stmt|;
name|bfd
modifier|*
name|output_bfd
decl_stmt|;
name|size_t
modifier|*
name|psymalloc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Write out a single global symbol.  This is expected to be called    via _bfd_generic_link_hash_traverse.  The second argument must    actually be a struct generic_write_global_symbol_info *.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_generic_link_write_global_symbol
name|PARAMS
argument_list|(
operator|(
expr|struct
name|generic_link_hash_entry
operator|*
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generic link hash table entry creation routine.  */
end_comment

begin_decl_stmt
name|struct
name|bfd_hash_entry
modifier|*
name|_bfd_generic_link_hash_newfunc
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_hash_entry
operator|*
operator|,
expr|struct
name|bfd_hash_table
operator|*
operator|,
specifier|const
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

end_unit

