begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Include file cached obstack implementation.    Written by Fred Fish<fnf@cygnus.com>    Rewritten by Jim Blandy<jimb@cygnus.com>    Copyright 1999, 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|BCACHE_H
value|1
end_define

begin_comment
comment|/* A bcache is a data structure for factoring out duplication in    read-only structures.  You give the bcache some string of bytes S.    If the bcache already contains a copy of S, it hands you back a    pointer to its copy.  Otherwise, it makes a fresh copy of S, and    hands you back a pointer to that.  In either case, you can throw    away your copy of S, and use the bcache's.     The "strings" in question are arbitrary strings of bytes --- they    can contain zero bytes.  You pass in the length explicitly when you    call the bcache function.     This means that you can put ordinary C objects in a bcache.    However, if you do this, remember that structs can contain `holes'    between members, added for alignment.  These bytes usually contain    garbage.  If you try to bcache two objects which are identical from    your code's point of view, but have different garbage values in the    structure's holes, then the bcache will treat them as separate    strings, and you won't get the nice elimination of duplicates you    were hoping for.  So, remember to memset your structures full of    zeros before bcaching them!     You shouldn't modify the strings you get from a bcache, because:     - You don't necessarily know who you're sharing space with.  If I      stick eight bytes of text in a bcache, and then stick an      eight-byte structure in the same bcache, there's no guarantee      those two objects don't actually comprise the same sequence of      bytes.  If they happen to, the bcache will use a single byte      string for both of them.  Then, modifying the structure will      change the string.  In bizarre ways.     - Even if you know for some other reason that all that's okay,      there's another problem.  A bcache stores all its strings in a      hash table.  If you modify a string's contents, you will probably      change its hash value.  This means that the modified string is      now in the wrong place in the hash table, and future bcache      probes will never find it.  So by mutating a string, you give up      any chance of sharing its space with future duplicates.  */
end_comment

begin_comment
comment|/* The type used to hold a single bcache string.  The user data is    stored in d.data.  Since it can be any type, it needs to have the    same alignment as the most strict alignment of any type on the host    machine.  I don't know of any really correct way to do this in    stock ANSI C, so just do it the same way obstack.h does.     It would be nicer to have this stuff hidden away in bcache.c, but    struct objstack contains a struct bcache directly --- not a pointer    to one --- and then the memory-mapped stuff makes this a real pain.    We don't strictly need to expose struct bstring, but it's better to    have it all in one place.  */
end_comment

begin_struct
struct|struct
name|bstring
block|{
name|struct
name|bstring
modifier|*
name|next
decl_stmt|;
name|size_t
name|length
decl_stmt|;
union|union
block|{
name|char
name|data
index|[
literal|1
index|]
decl_stmt|;
name|double
name|dummy
decl_stmt|;
block|}
name|d
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* The structure for a bcache itself.    To initialize a bcache, just fill it with zeros.  */
end_comment

begin_struct
struct|struct
name|bcache
block|{
comment|/* All the bstrings are allocated here.  */
name|struct
name|obstack
name|cache
decl_stmt|;
comment|/* How many hash buckets we're using.  */
name|unsigned
name|int
name|num_buckets
decl_stmt|;
comment|/* Hash buckets.  This table is allocated using malloc, so when we      grow the table we can return the old table to the system.  */
name|struct
name|bstring
modifier|*
modifier|*
name|bucket
decl_stmt|;
comment|/* Statistics.  */
name|unsigned
name|long
name|unique_count
decl_stmt|;
comment|/* number of unique strings */
name|long
name|total_count
decl_stmt|;
comment|/* total number of strings cached, including dups */
name|long
name|unique_size
decl_stmt|;
comment|/* size of unique strings, in bytes */
name|long
name|total_size
decl_stmt|;
comment|/* total number of bytes cached, including dups */
name|long
name|structure_size
decl_stmt|;
comment|/* total size of bcache, including infrastructure */
block|}
struct|;
end_struct

begin_comment
comment|/* Find a copy of the LENGTH bytes at ADDR in BCACHE.  If BCACHE has    never seen those bytes before, add a copy of them to BCACHE.  In    either case, return a pointer to BCACHE's copy of that string.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|bcache
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|,
name|int
name|length
parameter_list|,
name|struct
name|bcache
modifier|*
name|bcache
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free all the storage that BCACHE refers to.  The result is a valid,    but empty, bcache.  This does not free BCACHE itself, since that    might be part of some larger object.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|free_bcache
parameter_list|(
name|struct
name|bcache
modifier|*
name|bcache
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print statistics on BCACHE's memory usage and efficacity at    eliminating duplication.  TYPE should be a string describing the    kind of data BCACHE holds.  Statistics are printed using    `printf_filtered' and its ilk.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|print_bcache_statistics
parameter_list|(
name|struct
name|bcache
modifier|*
name|bcache
parameter_list|,
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The hash function */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|long
name|hash
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BCACHE_H */
end_comment

end_unit

