begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* hash.h -- header file for gas hash table routines    Copyright 1987, 1992, 1993, 1995, 1999 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASH_H
end_ifndef

begin_define
define|#
directive|define
name|HASH_H
end_define

begin_struct_decl
struct_decl|struct
name|hash_control
struct_decl|;
end_struct_decl

begin_comment
comment|/* Create a hash table.  This return a control block.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|hash_control
modifier|*
name|hash_new
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Delete a hash table, freeing all allocated memory.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|hash_die
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_control
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Insert an entry into a hash table.  This returns NULL on success.    On error, it returns a printable string indicating the error.  It    is considered to be an error if the entry already exists in the    hash table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|hash_insert
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_control
operator|*
operator|,
specifier|const
name|char
operator|*
name|key
operator|,
name|PTR
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Insert or replace an entry in a hash table.  This returns NULL on    success.  On error, it returns a printable string indicating the    error.  If an entry already exists, its value is replaced.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|hash_jam
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_control
operator|*
operator|,
specifier|const
name|char
operator|*
name|key
operator|,
name|PTR
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Replace an existing entry in a hash table.  This returns the old    value stored for the entry.  If the entry is not found in the hash    table, this does nothing and returns NULL.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|hash_replace
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_control
operator|*
operator|,
specifier|const
name|char
operator|*
name|key
operator|,
name|PTR
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find an entry in a hash table, returning its value.  Returns NULL    if the entry is not found.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|hash_find
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_control
operator|*
operator|,
specifier|const
name|char
operator|*
name|key
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Delete an entry from a hash table.  This returns the value stored    for that entry, or NULL if there is no such entry.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|hash_delete
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_control
operator|*
operator|,
specifier|const
name|char
operator|*
name|key
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Traverse a hash table.  Call the function on every entry in the    hash table.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|hash_traverse
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_control
operator|*
operator|,
name|void
argument_list|(
argument|*pfn
argument_list|)
operator|(
specifier|const
name|char
operator|*
name|key
operator|,
name|PTR
name|value
operator|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print hash table statistics on the specified file.  NAME is the    name of the hash table, used for printing a header.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|hash_print_statistics
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
name|name
operator|,
expr|struct
name|hash_control
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
comment|/* HASH_H */
end_comment

end_unit

