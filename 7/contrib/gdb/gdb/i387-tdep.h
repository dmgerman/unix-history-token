begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for the i387.     Copyright 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|I387_TDEP_H
end_ifndef

begin_define
define|#
directive|define
name|I387_TDEP_H
end_define

begin_struct_decl
struct_decl|struct
name|gdbarch
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regcache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|type
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ui_file
struct_decl|;
end_struct_decl

begin_comment
comment|/* Because the number of general-purpose registers is different for    AMD64, the floating-point registers and SSE registers get shifted.    The following definitions are intended to help writing code that    needs the register numbers of floating-point registers and SSE    registers.  In order to use these, one should provide a definition    for I387_ST0_REGNUM, and possibly I387_NUM_XMM_REGS, preferably by    using a local "#define" in the body of the function that uses this.    Please "#undef" them before the end of the function.  */
end_comment

begin_define
define|#
directive|define
name|I387_FCTRL_REGNUM
value|(I387_ST0_REGNUM + 8)
end_define

begin_define
define|#
directive|define
name|I387_FSTAT_REGNUM
value|(I387_FCTRL_REGNUM + 1)
end_define

begin_define
define|#
directive|define
name|I387_FTAG_REGNUM
value|(I387_FCTRL_REGNUM + 2)
end_define

begin_define
define|#
directive|define
name|I387_FISEG_REGNUM
value|(I387_FCTRL_REGNUM + 3)
end_define

begin_define
define|#
directive|define
name|I387_FIOFF_REGNUM
value|(I387_FCTRL_REGNUM + 4)
end_define

begin_define
define|#
directive|define
name|I387_FOSEG_REGNUM
value|(I387_FCTRL_REGNUM + 5)
end_define

begin_define
define|#
directive|define
name|I387_FOOFF_REGNUM
value|(I387_FCTRL_REGNUM + 6)
end_define

begin_define
define|#
directive|define
name|I387_FOP_REGNUM
value|(I387_FCTRL_REGNUM + 7)
end_define

begin_define
define|#
directive|define
name|I387_XMM0_REGNUM
value|(I387_ST0_REGNUM + 16)
end_define

begin_define
define|#
directive|define
name|I387_MXCSR_REGNUM
value|(I387_XMM0_REGNUM + I387_NUM_XMM_REGS)
end_define

begin_escape
end_escape

begin_comment
comment|/* Print out the i387 floating point state.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i387_print_float_info
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|ui_file
modifier|*
name|file
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
specifier|const
name|char
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read a value of type TYPE from register REGNUM in frame FRAME, and    return its contents in TO.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i387_register_to_value
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|void
modifier|*
name|to
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write the contents FROM of a value of type TYPE into register    REGNUM in frame FRAME.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i387_value_to_register
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|from
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Size of the memory area use by the 'fsave' and 'fxsave'    instructions.  */
end_comment

begin_define
define|#
directive|define
name|I387_SIZEOF_FSAVE
value|108
end_define

begin_define
define|#
directive|define
name|I387_SIZEOF_FXSAVE
value|512
end_define

begin_comment
comment|/* Fill register REGNUM in REGCACHE with the appropriate value from    *FSAVE.  This function masks off any of the reserved bits in    *FSAVE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i387_supply_fsave
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
name|fsave
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fill register REGNUM (if it is a floating-point register) in *FSAVE    with the value in GDB's register cache.  If REGNUM is -1, do this    for all registers.  This function doesn't touch any of the reserved    bits in *FSAVE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i387_fill_fsave
parameter_list|(
name|void
modifier|*
name|fsave
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fill register REGNUM in REGCACHE with the appropriate    floating-point or SSE register value from *FXSAVE.  This function    masks off any of the reserved bits in *FXSAVE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i387_supply_fxsave
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
name|fxsave
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fill register REGNUM (if it is a floating-point or SSE register) in    *FXSAVE with the value from REGCACHE.  If REGNUM is -1, do this for    all registers.  This function doesn't touch any of the reserved    bits in *FXSAVE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i387_collect_fxsave
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
name|fxsave
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fill register REGNUM (if it is a floating-point or SSE register) in    *FXSAVE with the value in GDB's register cache.  If REGNUM is -1, do    this for all registers.  This function doesn't touch any of the    reserved bits in *FXSAVE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i387_fill_fxsave
parameter_list|(
name|void
modifier|*
name|fxsave
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Prepare the FPU stack in REGCACHE for a function return.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i387_return_value
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i387-tdep.h */
end_comment

end_unit

