begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Cache and manage the values of registers for GDB, the GNU debugger.    Copyright 1986, 1987, 1989, 1991, 1994, 1995, 1996, 1998, 2000, 2001    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REGCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|REGCACHE_H
end_define

begin_comment
comment|/* Transfer a raw register [0..NUM_REGS) between core-gdb and the    regcache. */
end_comment

begin_function_decl
name|void
name|regcache_read
parameter_list|(
name|int
name|rawnum
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|regcache_write
parameter_list|(
name|int
name|rawnum
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Transfer a raw register [0..NUM_REGS) between the regcache and the    target.  These functions are called by the target in response to a    target_fetch_registers() or target_store_registers().  */
end_comment

begin_function_decl
specifier|extern
name|void
name|supply_register
parameter_list|(
name|int
name|regnum
parameter_list|,
name|char
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regcache_collect
parameter_list|(
name|int
name|regnum
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DEPRECATED: Character array containing an image of the inferior    programs' registers for the most recently referenced thread. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|registers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DEPRECATED: Character array containing the current state of each    register (unavailable<0, invalid=0, valid>0) for the most recently    referenced thread. */
end_comment

begin_decl_stmt
specifier|extern
name|signed
name|char
modifier|*
name|register_valid
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|register_cached
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_register_cached
parameter_list|(
name|int
name|regnum
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|register_changed
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|registers_changed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|registers_fetched
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|read_register_bytes
parameter_list|(
name|int
name|regbyte
parameter_list|,
name|char
modifier|*
name|myaddr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|read_register_gen
parameter_list|(
name|int
name|regnum
parameter_list|,
name|char
modifier|*
name|myaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_register_gen
parameter_list|(
name|int
name|regnum
parameter_list|,
name|char
modifier|*
name|myaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_register_bytes
parameter_list|(
name|int
name|regbyte
parameter_list|,
name|char
modifier|*
name|myaddr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Rename to read_unsigned_register()? */
end_comment

begin_function_decl
specifier|extern
name|ULONGEST
name|read_register
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Rename to read_unsigned_register_pid()? */
end_comment

begin_function_decl
specifier|extern
name|ULONGEST
name|read_register_pid
parameter_list|(
name|int
name|regnum
parameter_list|,
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LONGEST
name|read_signed_register
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LONGEST
name|read_signed_register_pid
parameter_list|(
name|int
name|regnum
parameter_list|,
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_register
parameter_list|(
name|int
name|regnum
parameter_list|,
name|LONGEST
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_register_pid
parameter_list|(
name|int
name|regnum
parameter_list|,
name|CORE_ADDR
name|val
parameter_list|,
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REGCACHE_H */
end_comment

end_unit

