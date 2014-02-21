begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* IBM RS/6000 native-dependent macros for GDB, the GNU debugger.    Copyright 1986, 1987, 1989, 1991, 1992, 1994, 1996, 1999, 2000, 2001    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Do implement the attach and detach commands.  */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
end_define

begin_comment
comment|/* Override copies of {fetch,store}_inferior_registers in infptrace.c.  */
end_comment

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

begin_comment
comment|/* Override child_xfer_memory in infptrace.c. */
end_comment

begin_define
define|#
directive|define
name|CHILD_XFER_MEMORY
end_define

begin_comment
comment|/* When a child process is just starting, we sneak in and relocate    the symbol table (and other stuff) after the dynamic linker has    figured out where they go.  */
end_comment

begin_define
define|#
directive|define
name|SOLIB_CREATE_INFERIOR_HOOK
parameter_list|(
name|PID
parameter_list|)
define|\
value|do {					\     xcoff_relocate_symtab (PID);	\   } while (0)
end_define

begin_comment
comment|/* When a target process or core-file has been attached, we sneak in    and figure out where the shared libraries have got to.  */
end_comment

begin_define
define|#
directive|define
name|SOLIB_ADD
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
define|\
value|if (PIDGET (inferior_ptid))	\
comment|/* Attach to process.  */
value|\     xcoff_relocate_symtab (PIDGET (inferior_ptid)); \   else		\
comment|/* Core file.  */
value|\     xcoff_relocate_core (c);
end_define

begin_function_decl
specifier|extern
name|void
name|xcoff_relocate_symtab
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|target_ops
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|xcoff_relocate_core
parameter_list|(
name|struct
name|target_ops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If ADDR lies in a shared library, return its name.  */
end_comment

begin_define
define|#
directive|define
name|PC_SOLIB
parameter_list|(
name|PC
parameter_list|)
value|xcoff_solib_address(PC)
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|xcoff_solib_address
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return sizeof user struct to callers in less machine dependent routines */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_SIZE
value|kernel_u_size()
end_define

begin_function_decl
specifier|extern
name|int
name|kernel_u_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Flag for machine-specific stuff in shared files.  FIXME */
end_comment

begin_define
define|#
directive|define
name|DEPRECATED_IBM6000_TARGET
end_define

end_unit

