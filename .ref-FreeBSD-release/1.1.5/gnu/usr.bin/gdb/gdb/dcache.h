begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for caching.  Typically used by remote back ends for    caching remote memory.     Copyright 1992, 1993 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|DCACHE_H
end_define

begin_comment
comment|/* The data cache leads to incorrect results because it doesn't know about    volatile variables, thus making it impossible to debug functions which    use hardware registers.  Therefore it is #if 0'd out.  Effect on    performance is some, for backtraces of functions with a few    arguments each.  For functions with many arguments, the stack    frames don't fit in the cache blocks, which makes the cache less    helpful.  Disabling the cache is a big performance win for fetching    large structures, because the cache code fetched data in 16-byte    chunks.  */
end_comment

begin_define
define|#
directive|define
name|LINE_SIZE_POWER
value|(4)
end_define

begin_comment
comment|/* eg 1<<3 == 8 */
end_comment

begin_define
define|#
directive|define
name|LINE_SIZE
value|(1<< LINE_SIZE_POWER)
end_define

begin_comment
comment|/* Number of cache blocks */
end_comment

begin_define
define|#
directive|define
name|DCACHE_SIZE
value|(64)
end_define

begin_struct
struct|struct
name|dcache_block
block|{
name|struct
name|dcache_block
modifier|*
name|next
decl_stmt|,
modifier|*
name|last
decl_stmt|;
name|unsigned
name|int
name|addr
decl_stmt|;
comment|/* Address for which data is recorded.  */
name|int
name|data
index|[
name|LINE_SIZE
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*memxferfunc
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
name|memaddr
operator|,
name|unsigned
name|char
operator|*
name|myaddr
operator|,
name|int
name|len
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Function to actually read the target memory. */
name|memxferfunc
name|read_memory
decl_stmt|;
comment|/* Function to actually write the target memory */
name|memxferfunc
name|write_memory
decl_stmt|;
comment|/* free list */
name|struct
name|dcache_block
name|dcache_free
decl_stmt|;
comment|/* in use list */
name|struct
name|dcache_block
name|dcache_valid
decl_stmt|;
comment|/* The cache itself. */
name|struct
name|dcache_block
modifier|*
name|the_cache
decl_stmt|;
block|}
name|DCACHE
typedef|;
end_typedef

begin_comment
comment|/* Using the data cache DCACHE return the contents of the word at    address ADDR in the remote machine.  */
end_comment

begin_decl_stmt
name|int
name|dcache_fetch
name|PARAMS
argument_list|(
operator|(
name|DCACHE
operator|*
name|dcache
operator|,
name|CORE_ADDR
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flush DCACHE. */
end_comment

begin_decl_stmt
name|void
name|dcache_flush
name|PARAMS
argument_list|(
operator|(
name|DCACHE
operator|*
name|dcache
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize DCACHE. */
end_comment

begin_decl_stmt
name|DCACHE
modifier|*
name|dcache_init
name|PARAMS
argument_list|(
operator|(
name|memxferfunc
name|reading
operator|,
name|memxferfunc
name|writing
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write the word at ADDR both in the data cache and in the remote machine.  */
end_comment

begin_decl_stmt
name|void
name|dcache_poke
name|PARAMS
argument_list|(
operator|(
name|DCACHE
operator|*
name|dcache
operator|,
name|CORE_ADDR
name|addr
operator|,
name|int
name|data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DCACHE_H */
end_comment

end_unit

