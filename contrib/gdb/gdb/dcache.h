begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for caching.  Typically used by remote back ends for    caching remote memory.     Copyright 1992, 1993, 1995, 1999, 2000, 2001    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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
name|struct
name|dcache_struct
name|DCACHE
typedef|;
end_typedef

begin_comment
comment|/* Invalidate DCACHE. */
end_comment

begin_function_decl
name|void
name|dcache_invalidate
parameter_list|(
name|DCACHE
modifier|*
name|dcache
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize DCACHE. */
end_comment

begin_function_decl
name|DCACHE
modifier|*
name|dcache_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free a DCACHE */
end_comment

begin_function_decl
name|void
name|dcache_free
parameter_list|(
name|DCACHE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Simple to call from<remote>_xfer_memory */
end_comment

begin_function_decl
name|int
name|dcache_xfer_memory
parameter_list|(
name|DCACHE
modifier|*
name|cache
parameter_list|,
name|CORE_ADDR
name|mem
parameter_list|,
name|char
modifier|*
name|my
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|should_write
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DCACHE_H */
end_comment

end_unit

