begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Cache and manage the values of registers for GDB, the GNU debugger.     Copyright 1986, 1987, 1989, 1991, 1994, 1995, 1996, 1998, 2000,    2001, 2002 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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

begin_struct_decl
struct_decl|struct
name|regcache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|gdbarch
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|regcache
modifier|*
name|current_regcache
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|regcache_xfree
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cleanup
modifier|*
name|make_cleanup_regcache_xfree
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|regcache
modifier|*
name|regcache_xmalloc
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return REGCACHE's architecture.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|gdbarch
modifier|*
name|get_regcache_arch
parameter_list|(
specifier|const
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Transfer a raw register [0..NUM_REGS) between core-gdb and the    regcache. */
end_comment

begin_function_decl
name|void
name|regcache_raw_read
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|rawnum
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|regcache_raw_write
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|rawnum
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regcache_raw_read_signed
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|regnum
parameter_list|,
name|LONGEST
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regcache_raw_read_unsigned
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|regnum
parameter_list|,
name|ULONGEST
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regcache_raw_write_signed
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
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
name|regcache_raw_write_unsigned
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|regnum
parameter_list|,
name|ULONGEST
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Partial transfer of a raw registers.  These perform read, modify,    write style operations.  */
end_comment

begin_function_decl
name|void
name|regcache_raw_read_part
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|regnum
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|len
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|regcache_raw_write_part
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|regnum
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|len
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regcache_valid_p
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Transfer a cooked register [0..NUM_REGS+NUM_PSEUDO_REGS).  */
end_comment

begin_function_decl
name|void
name|regcache_cooked_read
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|rawnum
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|regcache_cooked_write
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|rawnum
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* NOTE: cagney/2002-08-13: At present GDB has no reliable mechanism    for indicating when a ``cooked'' register was constructed from    invalid or unavailable ``raw'' registers.  One fairly easy way of    adding such a mechanism would be for the cooked functions to return    a register valid indication.  Given the possibility of such a    change, the extract functions below use a reference parameter,    rather than a function result.  */
end_comment

begin_comment
comment|/* Read a register as a signed/unsigned quantity.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|regcache_cooked_read_signed
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|regnum
parameter_list|,
name|LONGEST
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regcache_cooked_read_unsigned
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|regnum
parameter_list|,
name|ULONGEST
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regcache_cooked_write_signed
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
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
name|regcache_cooked_write_unsigned
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|regnum
parameter_list|,
name|ULONGEST
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Partial transfer of a cooked register.  These perform read, modify,    write style operations.  */
end_comment

begin_function_decl
name|void
name|regcache_cooked_read_part
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|regnum
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|len
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|regcache_cooked_write_part
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|regnum
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|len
parameter_list|,
specifier|const
name|void
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
specifier|const
name|void
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

begin_function_decl
specifier|extern
name|void
name|regcache_raw_supply
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|regnum
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regcache_raw_collect
parameter_list|(
specifier|const
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
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
comment|/* The register's ``offset''.     FIXME: cagney/2002-11-07: The frame_register() function, when    specifying the real location of a register, does so using that    registers offset in the register cache.  That offset is then used    by valops.c to determine the location of the register.  The code    should instead use the register's number and a location expression    to describe a value spread across multiple registers or memory.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|register_offset_hack
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The type of a register.  This function is slightly more efficient    then its gdbarch vector counterpart since it returns a precomputed    value stored in a table.     NOTE: cagney/2002-08-17: The original macro was called    DEPRECATED_REGISTER_VIRTUAL_TYPE.  This was because the register    could have different raw and cooked (nee virtual) representations.    The CONVERTABLE methods being used to convert between the two    representations.  Current code does not do this.  Instead, the    first [0..NUM_REGS) registers are 1:1 raw:cooked, and the type    exactly describes the register's representation.  Consequently, the    ``virtual'' has been dropped.     FIXME: cagney/2002-08-17: A number of architectures, including the    MIPS, are currently broken in this regard.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|register_type
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the size of register REGNUM.  All registers should have only    one size.     FIXME: cagney/2003-02-28:     Unfortunately, thanks to some legacy architectures, this doesn't    hold.  A register's cooked (nee virtual) and raw size can differ    (see MIPS).  Such architectures should be using different register    numbers for the different sized views of identical registers.     Anyway, the up-shot is that, until that mess is fixed, core code    can end up being very confused - should the RAW or VIRTUAL size be    used?  As a rule of thumb, use DEPRECATED_REGISTER_VIRTUAL_SIZE in    cooked code, but with the comment:     OK: REGISTER_VIRTUAL_SIZE     or just     OK     appended to the end of the line.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|register_size
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Save/restore a register cache.  The set of registers saved /    restored into the DST regcache determined by the save_reggroup /    restore_reggroup respectively.  COOKED_READ returns zero iff the    register's value can't be returned.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|regcache_cooked_read_ftype
function_decl|)
parameter_list|(
name|void
modifier|*
name|src
parameter_list|,
name|int
name|regnum
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|regcache_save
parameter_list|(
name|struct
name|regcache
modifier|*
name|dst
parameter_list|,
name|regcache_cooked_read_ftype
modifier|*
name|cooked_read
parameter_list|,
name|void
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regcache_restore
parameter_list|(
name|struct
name|regcache
modifier|*
name|dst
parameter_list|,
name|regcache_cooked_read_ftype
modifier|*
name|cooked_read
parameter_list|,
name|void
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Copy/duplicate the contents of a register cache.  By default, the    operation is pass-through.  Writes to DST and reads from SRC will    go through to the target.     The ``cpy'' functions can not have overlapping SRC and DST buffers.     ``no passthrough'' versions do not go through to the target.  They    only transfer values already in the cache.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|regcache
modifier|*
name|regcache_dup
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|regcache
modifier|*
name|regcache_dup_no_passthrough
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regcache_cpy
parameter_list|(
name|struct
name|regcache
modifier|*
name|dest
parameter_list|,
name|struct
name|regcache
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regcache_cpy_no_passthrough
parameter_list|(
name|struct
name|regcache
modifier|*
name|dest
parameter_list|,
name|struct
name|regcache
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* NOTE: cagney/2002-11-02: The below have been superseded by the    regcache_cooked_*() functions found above, and the frame_*()    functions found in "frame.h".  Take care though, often more than a    simple substitution is required when updating the code.  The    change, as far as practical, should avoid adding references to    global variables (e.g., current_regcache, current_frame,    current_gdbarch or deprecated_selected_frame) and instead refer to    the FRAME or REGCACHE that has been passed into the containing    function as parameters.  Consequently, the change typically    involves modifying the containing function so that it takes a FRAME    or REGCACHE parameter.  In the case of an architecture vector    method, there should already be a non-deprecated variant that is    parameterized with FRAME or REGCACHE.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|deprecated_grub_regcache_for_registers
parameter_list|(
name|struct
name|regcache
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|deprecated_read_register_gen
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
name|deprecated_write_register_gen
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
name|deprecated_read_register_bytes
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
name|deprecated_write_register_bytes
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
comment|/* Character array containing the current state of each register    (unavailable<0, invalid=0, valid>0) for the most recently    referenced thread.  This global is often found in close proximity    to code that is directly manipulating the deprecated_registers[]    array.  In such cases, it should be possible to replace the lot    with a call to supply_register().  If you find yourself in dire    straits, still needing access to the cache status bit, the    regcache_valid_p() and set_register_cached() functions are    available.  */
end_comment

begin_decl_stmt
specifier|extern
name|signed
name|char
modifier|*
name|deprecated_register_valid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Character array containing an image of the inferior programs'    registers for the most recently referenced thread.     NOTE: cagney/2002-11-14: Target side code should be using    supply_register() and/or regcache_collect() while architecture side    code should use the more generic regcache methods.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|deprecated_registers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NOTE: cagney/2002-11-05: This function, and its co-conspirator    deprecated_registers[], have been superseeded by supply_register().  */
end_comment

begin_function_decl
specifier|extern
name|void
name|deprecated_registers_fetched
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
name|registers_changed
parameter_list|(
name|void
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

