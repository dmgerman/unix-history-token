begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to target GDB to GNU/Linux on 386.     Copyright 1992, 1993, 1995, 1996, 1998, 1999, 2000, 2001, 2002 Free    Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_LINUX_H
end_ifndef

begin_define
define|#
directive|define
name|TM_LINUX_H
end_define

begin_define
define|#
directive|define
name|I386_GNULINUX_TARGET
end_define

begin_define
define|#
directive|define
name|HAVE_I387_REGS
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PTRACE_GETFPXREGS
end_ifdef

begin_define
define|#
directive|define
name|HAVE_SSE_REGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"i386/tm-i386.h"
end_include

begin_include
include|#
directive|include
file|"tm-linux.h"
end_include

begin_comment
comment|/* Register number for the "orig_eax" pseudo-register.  If this    pseudo-register contains a value>= 0 it is interpreted as the    system call number that the kernel is supposed to restart.  */
end_comment

begin_define
define|#
directive|define
name|I386_LINUX_ORIG_EAX_REGNUM
value|(NUM_GREGS + NUM_FREGS + NUM_SSE_REGS)
end_define

begin_comment
comment|/* Adjust a few macros to deal with this extra register.  */
end_comment

begin_undef
undef|#
directive|undef
name|NUM_REGS
end_undef

begin_define
define|#
directive|define
name|NUM_REGS
value|(NUM_GREGS + NUM_FREGS + NUM_SSE_REGS + 1)
end_define

begin_undef
undef|#
directive|undef
name|MAX_NUM_REGS
end_undef

begin_define
define|#
directive|define
name|MAX_NUM_REGS
value|(16 + 16 + 9 + 1)
end_define

begin_undef
undef|#
directive|undef
name|REGISTER_BYTES
end_undef

begin_define
define|#
directive|define
name|REGISTER_BYTES
define|\
value|(SIZEOF_GREGS + SIZEOF_FPU_REGS + SIZEOF_FPU_CTRL_REGS + SIZEOF_SSE_REGS + 4)
end_define

begin_undef
undef|#
directive|undef
name|REGISTER_NAME
end_undef

begin_define
define|#
directive|define
name|REGISTER_NAME
parameter_list|(
name|reg
parameter_list|)
value|i386_linux_register_name ((reg))
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|i386_linux_register_name
parameter_list|(
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|REGISTER_BYTE
end_undef

begin_define
define|#
directive|define
name|REGISTER_BYTE
parameter_list|(
name|reg
parameter_list|)
value|i386_linux_register_byte ((reg))
end_define

begin_function_decl
specifier|extern
name|int
name|i386_linux_register_byte
parameter_list|(
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|REGISTER_RAW_SIZE
end_undef

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|reg
parameter_list|)
value|i386_linux_register_raw_size ((reg))
end_define

begin_function_decl
specifier|extern
name|int
name|i386_linux_register_raw_size
parameter_list|(
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* GNU/Linux ELF uses stabs-in-ELF with the DWARF register numbering    scheme by default, so we must redefine STAB_REG_TO_REGNUM.  This    messes up the floating-point registers for a.out, but there is not    much we can do about that.  */
end_comment

begin_undef
undef|#
directive|undef
name|STAB_REG_TO_REGNUM
end_undef

begin_define
define|#
directive|define
name|STAB_REG_TO_REGNUM
parameter_list|(
name|reg
parameter_list|)
value|i386_dwarf_reg_to_regnum ((reg))
end_define

begin_comment
comment|/* Use target_specific function to define link map offsets.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|link_map_offsets
modifier|*
name|i386_linux_svr4_fetch_link_map_offsets
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SVR4_FETCH_LINK_MAP_OFFSETS
parameter_list|()
value|i386_linux_svr4_fetch_link_map_offsets ()
end_define

begin_comment
comment|/* The following works around a problem with /usr/include/sys/procfs.h  */
end_comment

begin_define
define|#
directive|define
name|sys_quotactl
value|1
end_define

begin_comment
comment|/* When the i386 Linux kernel calls a signal handler, the return    address points to a bit of code on the stack.  These definitions    are used to identify this bit of code as a signal trampoline in    order to support backtracing through calls to signal handlers.  */
end_comment

begin_define
define|#
directive|define
name|IN_SIGTRAMP
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|i386_linux_in_sigtramp (pc, name)
end_define

begin_function_decl
specifier|extern
name|int
name|i386_linux_in_sigtramp
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|FRAME_CHAIN
end_undef

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|frame
parameter_list|)
value|i386_linux_frame_chain (frame)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|i386_linux_frame_chain
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|FRAME_SAVED_PC
end_undef

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|frame
parameter_list|)
value|i386_linux_frame_saved_pc (frame)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|i386_linux_frame_saved_pc
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|SAVED_PC_AFTER_CALL
end_undef

begin_define
define|#
directive|define
name|SAVED_PC_AFTER_CALL
parameter_list|(
name|frame
parameter_list|)
value|i386_linux_saved_pc_after_call (frame)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|i386_linux_saved_pc_after_call
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TARGET_WRITE_PC
parameter_list|(
name|pc
parameter_list|,
name|ptid
parameter_list|)
value|i386_linux_write_pc (pc, ptid)
end_define

begin_function_decl
specifier|extern
name|void
name|i386_linux_write_pc
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* When we call a function in a shared library, and the PLT sends us    into the dynamic linker to find the function's real address, we    need to skip over the dynamic linker call.  This function decides    when to skip, and where to skip to.  See the comments for    SKIP_SOLIB_RESOLVER at the top of infrun.c.  */
end_comment

begin_define
define|#
directive|define
name|SKIP_SOLIB_RESOLVER
value|i386_linux_skip_solib_resolver
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|i386_linux_skip_solib_resolver
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* N_FUN symbols in shared libaries have 0 for their values and need    to be relocated. */
end_comment

begin_define
define|#
directive|define
name|SOFUN_ADDRESS_MAYBE_MISSING
end_define

begin_escape
end_escape

begin_comment
comment|/* Support for longjmp.  */
end_comment

begin_comment
comment|/* Details about jmp_buf.  It's supposed to be an array of integers.  */
end_comment

begin_define
define|#
directive|define
name|JB_ELEMENT_SIZE
value|4
end_define

begin_comment
comment|/* Size of elements in jmp_buf.  */
end_comment

begin_define
define|#
directive|define
name|JB_PC
value|5
end_define

begin_comment
comment|/* Array index of saved PC.  */
end_comment

begin_comment
comment|/* Figure out where the longjmp will land.  Slurp the args out of the    stack.  We expect the first arg to be a pointer to the jmp_buf    structure from which we extract the pc (JB_PC) that we will land    at.  The pc is copied into ADDR.  This routine returns true on    success.  */
end_comment

begin_define
define|#
directive|define
name|GET_LONGJMP_TARGET
parameter_list|(
name|addr
parameter_list|)
value|get_longjmp_target (addr)
end_define

begin_function_decl
specifier|extern
name|int
name|get_longjmp_target
parameter_list|(
name|CORE_ADDR
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef TM_LINUX_H */
end_comment

end_unit

