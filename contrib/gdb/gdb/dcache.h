begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for caching.  Typically used by remote back ends for    caching remote memory.     Copyright 1992, 1993 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|struct
name|dcache_struct
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
name|int
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

begin_comment
comment|/* Simple to call from<remote>_xfer_memory */
end_comment

begin_decl_stmt
name|int
name|dcache_xfer_memory
name|PARAMS
argument_list|(
operator|(
name|DCACHE
operator|*
name|cache
operator|,
name|CORE_ADDR
name|mem
operator|,
name|char
operator|*
name|my
operator|,
name|int
name|len
operator|,
name|int
name|should_write
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write the bytes at ADDR into the data cache and the remote machine. */
end_comment

begin_decl_stmt
name|int
name|dcache_poke_block
name|PARAMS
argument_list|(
operator|(
name|DCACHE
operator|*
name|cache
operator|,
name|CORE_ADDR
name|mem
operator|,
name|char
operator|*
name|my
operator|,
name|int
name|len
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

