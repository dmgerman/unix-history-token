begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent header for the MIPS architecture, for GDB, the GNU Debugger.     Copyright 2002, 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_TDEP_H
end_ifndef

begin_define
define|#
directive|define
name|MIPS_TDEP_H
end_define

begin_struct_decl
struct_decl|struct
name|gdbarch
struct_decl|;
end_struct_decl

begin_comment
comment|/* All the possible MIPS ABIs. */
end_comment

begin_enum
enum|enum
name|mips_abi
block|{
name|MIPS_ABI_UNKNOWN
init|=
literal|0
block|,
name|MIPS_ABI_N32
block|,
name|MIPS_ABI_O32
block|,
name|MIPS_ABI_N64
block|,
name|MIPS_ABI_O64
block|,
name|MIPS_ABI_EABI32
block|,
name|MIPS_ABI_EABI64
block|,
name|MIPS_ABI_LAST
block|}
enum|;
end_enum

begin_comment
comment|/* Return the MIPS ABI associated with GDBARCH.  */
end_comment

begin_function_decl
name|enum
name|mips_abi
name|mips_abi
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For wince :-(.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|mips_next_pc
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the "MIPS" register size.  Just a short cut to the BFD    architecture's word size.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|mips_regsize
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the current index for various MIPS registers.  */
end_comment

begin_struct
struct|struct
name|mips_regnum
block|{
name|int
name|pc
decl_stmt|;
name|int
name|fp0
decl_stmt|;
name|int
name|fp_implementation_revision
decl_stmt|;
name|int
name|fp_control_status
decl_stmt|;
name|int
name|badvaddr
decl_stmt|;
comment|/* Bad vaddr for addressing exception.  */
name|int
name|cause
decl_stmt|;
comment|/* Describes last exception.  */
name|int
name|hi
decl_stmt|;
comment|/* Multiply/divide temp.  */
name|int
name|lo
decl_stmt|;
comment|/* ...  */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
specifier|const
name|struct
name|mips_regnum
modifier|*
name|mips_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|MIPS_EMBED_LO_REGNUM
init|=
literal|33
block|,
name|MIPS_EMBED_HI_REGNUM
init|=
literal|34
block|,
name|MIPS_EMBED_BADVADDR_REGNUM
init|=
literal|35
block|,
name|MIPS_EMBED_CAUSE_REGNUM
init|=
literal|36
block|,
name|MIPS_EMBED_PC_REGNUM
init|=
literal|37
block|,
name|MIPS_EMBED_FP0_REGNUM
init|=
literal|38
block|}
enum|;
end_enum

begin_comment
comment|/* Defined in mips-tdep.c and used in remote-mips.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|deprecated_mips_set_processor_regs_hack
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MIPS_TDEP_H */
end_comment

end_unit

