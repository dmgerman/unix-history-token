begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native support for GNU/Linux x86.     Copyright 1986, 1987, 1989, 1992, 1993, 1994, 1995, 1996, 1997,    1998, 1999, 2000, 2001, 2002 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_LINUX_H
end_ifndef

begin_define
define|#
directive|define
name|NM_LINUX_H
end_define

begin_comment
comment|/* GNU/Linux supports the i386 hardware debugging registers.  */
end_comment

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

begin_include
include|#
directive|include
file|"nm-linux.h"
end_include

begin_comment
comment|/* Support for the user area.  */
end_comment

begin_comment
comment|/* Return the size of the user struct.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|kernel_u_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|KERNEL_U_SIZE
value|kernel_u_size()
end_define

begin_comment
comment|/* This is the amount to substract from u.u_ar0 to get the offset in    the core file of the register values.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|0
end_define

begin_comment
comment|/* Offset of the registers within the user area.  */
end_comment

begin_define
define|#
directive|define
name|U_REGS_OFFSET
value|0
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|register_u_addr
parameter_list|(
name|CORE_ADDR
name|blockend
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|REGISTER_U_ADDR
parameter_list|(
name|addr
parameter_list|,
name|blockend
parameter_list|,
name|regnum
parameter_list|)
define|\
value|(addr) = register_u_addr (blockend, regnum)
end_define

begin_escape
end_escape

begin_comment
comment|/* Provide access to the i386 hardware debugging registers.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i386_linux_dr_set_control
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
value|i386_linux_dr_set_control (control)
end_define

begin_function_decl
specifier|extern
name|void
name|i386_linux_dr_set_addr
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
value|i386_linux_dr_set_addr (regnum, addr)
end_define

begin_function_decl
specifier|extern
name|void
name|i386_linux_dr_reset_addr
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
value|i386_linux_dr_reset_addr (regnum)
end_define

begin_function_decl
specifier|extern
name|unsigned
name|long
name|i386_linux_dr_get_status
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
value|i386_linux_dr_get_status ()
end_define

begin_escape
end_escape

begin_comment
comment|/* Override copies of {fetch,store}_inferior_registers in `infptrace.c'.  */
end_comment

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

begin_comment
comment|/* Nevertheless, define CANNOT_{FETCH,STORE}_REGISTER, because we    might fall back on the code `infptrace.c' (well a copy of that code    in `i386-linux-nat.c' for now) and we can access only the    general-purpose registers in that way.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cannot_fetch_register
parameter_list|(
name|int
name|regno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cannot_store_register
parameter_list|(
name|int
name|regno
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CANNOT_FETCH_REGISTER
parameter_list|(
name|regno
parameter_list|)
value|cannot_fetch_register (regno)
end_define

begin_define
define|#
directive|define
name|CANNOT_STORE_REGISTER
parameter_list|(
name|regno
parameter_list|)
value|cannot_store_register (regno)
end_define

begin_comment
comment|/* Override child_resume in `infptrace.c'.  */
end_comment

begin_define
define|#
directive|define
name|CHILD_RESUME
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* nm-linux.h */
end_comment

end_unit

