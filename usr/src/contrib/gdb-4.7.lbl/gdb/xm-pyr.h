begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on a Pyramidax under OSx 4.0 (4.2bsd).    Copyright 1988, 1989, 1992  Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* Define PYRAMID_CONTROL_FRAME_DEBUGGING to get copious messages    about reading the control stack on standard output. This    makes gdb unusable as a debugger. */
end_comment

begin_comment
comment|/* #define PYRAMID_CONTROL_FRAME_DEBUGGING */
end_comment

begin_comment
comment|/* Define PYRAMID_FRAME_DEBUGGING for ? */
end_comment

begin_comment
comment|/* use Pyramid's slightly strange ptrace */
end_comment

begin_define
define|#
directive|define
name|PYRAMID_PTRACE
end_define

begin_comment
comment|/* Traditional Unix virtual address spaces have thre regions: text,    data and stack.  The text, initialised data, and uninitialised data    are represented in separate segments of the a.out file.    When a process dumps core, the data and stack regions are written    to a core file.  This gives a debugger enough information to    reconstruct (and debug) the virtual address space at the time of    the coredump.    Pyramids have an distinct fourth region of the virtual address    space, in which the contents of the windowed registers are stacked    in fixed-size frames.  Pyramid refer to this region as the control    stack.  Each call (or trap) automatically allocates a new register    frame; each return deallocates the current frame and restores the    windowed registers to their values before the call.     When dumping core, the control stack is written to a core files as    a third segment. The core-handling functions need to know to deal    with it. */
end_comment

begin_comment
comment|/* Tell dep.c what the extra segment is.  */
end_comment

begin_define
define|#
directive|define
name|PYRAMID_CORE
end_define

begin_define
define|#
directive|define
name|NO_SIGINTERRUPT
end_define

begin_define
define|#
directive|define
name|HAVE_WAIT_STRUCT
end_define

begin_comment
comment|/* Get rid of any system-imposed stack limit if possible.  */
end_comment

begin_define
define|#
directive|define
name|SET_STACK_LIMIT_HUGE
end_define

begin_comment
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|(0x80000000 - (UPAGES * NBPG))
end_define

begin_comment
comment|/* Define offsets of registers in the core file (or maybe u area) */
end_comment

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
value|{ struct user __u;					\   addr = blockend  + (regno - 16 ) * 4;			\   if (regno == 67) {   					\       printf("\\geting reg 67\\");			\       addr = (int)(&__u.u_pcb.pcb_csp) - (int)&__u;	\   } else if (regno == KSP_REGNUM) {			\       printf("\\geting KSP (reg %d)\\", KSP_REGNUM);	\       addr = (int)(&__u.u_pcb.pcb_ksp) - (int)&__u;	\   } else if (regno == CSP_REGNUM) {			\       printf("\\geting CSP (reg %d\\",CSP_REGNUM);	\       addr = (int)(&__u.u_pcb.pcb_csp) - (int)&__u;	\   } else if (regno == 64) {				\       printf("\\geting reg 64\\");			\       addr = (int)(&__u.u_pcb.pcb_csp) - (int)&__u;	\    } else if (regno == PS_REGNUM)			\       addr = blockend - 4;				\   else if (1&& ((16> regno)&& (regno> 11)))		\       addr = last_frame_offset + (4 *(regno+32));	\   else if (0&& (12> regno)) 				\       addr = global_reg_offset + (4 *regno);		\   else if (16> regno)	 				\       addr = global_reg_offset + (4 *regno);		\  else							\       addr = blockend  + (regno - 16 ) * 4;		\ }
end_define

begin_comment
comment|/* Override copies of {fetch,store}_inferior_registers in infptrace.c.  */
end_comment

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

end_unit

