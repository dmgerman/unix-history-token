begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native support for GNU/Linux x86-64.     Copyright 2001, 2002 Free Software Foundation, Inc.  Contributed by    Jiri Smid, SuSE Labs.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_X86_64_H
end_ifndef

begin_define
define|#
directive|define
name|NM_X86_64_H
end_define

begin_include
include|#
directive|include
file|"nm-linux.h"
end_include

begin_define
define|#
directive|define
name|I386_USE_GENERIC_WATCHPOINTS
end_define

begin_include
include|#
directive|include
file|"i386/nm-i386.h"
end_include

begin_comment
comment|/* Support for 8-byte wide hw watchpoints.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_HAS_DR_LEN_8
value|1
end_define

begin_comment
comment|/* Provide access to the i386 hardware debugging registers.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|x86_64_linux_dr_set_control
parameter_list|(
name|unsigned
name|long
name|control
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|I386_DR_LOW_SET_CONTROL
parameter_list|(
name|control
parameter_list|)
define|\
value|x86_64_linux_dr_set_control (control)
end_define

begin_function_decl
specifier|extern
name|void
name|x86_64_linux_dr_set_addr
parameter_list|(
name|int
name|regnum
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|I386_DR_LOW_SET_ADDR
parameter_list|(
name|regnum
parameter_list|,
name|addr
parameter_list|)
define|\
value|x86_64_linux_dr_set_addr (regnum, addr)
end_define

begin_function_decl
specifier|extern
name|void
name|x86_64_linux_dr_reset_addr
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|I386_DR_LOW_RESET_ADDR
parameter_list|(
name|regnum
parameter_list|)
define|\
value|x86_64_linux_dr_reset_addr (regnum)
end_define

begin_function_decl
specifier|extern
name|unsigned
name|long
name|x86_64_linux_dr_get_status
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|I386_DR_LOW_GET_STATUS
parameter_list|()
define|\
value|x86_64_linux_dr_get_status ()
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|REGISTER_U_ADDR
parameter_list|(
name|addr
parameter_list|,
name|blockend
parameter_list|,
name|regno
parameter_list|)
define|\
value|(addr) = x86_64_register_u_addr ((blockend),(regno));
end_define

begin_function_decl
name|CORE_ADDR
name|x86_64_register_u_addr
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the size of the user struct.  */
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
comment|/* Offset of the registers within the user area.  */
end_comment

begin_define
define|#
directive|define
name|U_REGS_OFFSET
value|0
end_define

begin_comment
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|0x0
end_define

begin_define
define|#
directive|define
name|PTRACE_ARG3_TYPE
value|void*
end_define

begin_define
define|#
directive|define
name|PTRACE_XFER_TYPE
value|unsigned long
end_define

begin_escape
end_escape

begin_comment
comment|/* We define this if link.h is available, because with ELF we use SVR4 style    shared libraries. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LINK_H
end_ifdef

begin_define
define|#
directive|define
name|SVR4_SHARED_LIBS
end_define

begin_include
include|#
directive|include
file|"solib.h"
end_include

begin_comment
comment|/* Support for shared libraries. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Override copies of {fetch,store}_inferior_registers in `infptrace.c'.  */
end_comment

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

begin_undef
undef|#
directive|undef
name|PREPARE_TO_PROCEED
end_undef

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_function_decl
specifier|extern
name|void
name|lin_thread_get_thread_signals
parameter_list|(
name|sigset_t
modifier|*
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GET_THREAD_SIGNALS
parameter_list|(
name|mask
parameter_list|)
value|lin_thread_get_thread_signals (mask)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NM_X86_64.h */
end_comment

end_unit

