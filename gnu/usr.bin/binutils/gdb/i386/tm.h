begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for i386 running under BSD Unix.    Copyright 1986, 1987, 1989, 1991, 1992, 1993 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FREEBSD_TM_H_
end_ifndef

begin_define
define|#
directive|define
name|_FREEBSD_TM_H_
end_define

begin_comment
comment|/* Override number of expected traps from sysv. */
end_comment

begin_define
define|#
directive|define
name|START_INFERIOR_TRAPS_EXPECTED
value|2
end_define

begin_comment
comment|/* Most definitions from sysv could be used. */
end_comment

begin_include
include|#
directive|include
file|"tm-i386v.h"
end_include

begin_comment
comment|/* 386BSD cannot handle the segment registers. */
end_comment

begin_comment
comment|/* BSDI can't handle them either.  */
end_comment

begin_comment
comment|/* FreeBSD cannot handle %fs or %gs.  */
end_comment

begin_undef
undef|#
directive|undef
name|NUM_REGS
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|NUM_REGS
value|14
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NUM_REGS
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On 386 bsd, sigtramp is above the user stack and immediately below    the user area. Using constants here allows for cross debugging.    These are tested for BSDI but should work on 386BSD.  */
end_comment

begin_define
define|#
directive|define
name|SIGTRAMP_START
value|0xfdbfdfc0
end_define

begin_define
define|#
directive|define
name|SIGTRAMP_END
value|0xfdbfe000
end_define

begin_comment
comment|/* The following redefines make backtracing through sigtramp work.    They manufacture a fake sigtramp frame and obtain the saved pc in sigtramp    from the sigcontext structure which is pushed by the kernel on the    user stack, along with a pointer to it.  */
end_comment

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address and produces the frame's    chain-pointer.    In the case of the i386, the frame's nominal address    is the address of a 4-byte word containing the calling frame's address.  */
end_comment

begin_undef
undef|#
directive|undef
name|FRAME_CHAIN
end_undef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|fbsd_kern_frame_chain
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
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
define|\
value|(kernel_debugging ? fbsd_kern_frame_chain(thisframe) : \   ((thisframe)->signal_handler_caller \    ? (thisframe)->frame \    : (!inside_entry_file ((thisframe)->pc) \       ? read_memory_integer ((thisframe)->frame, 4) \       : 0)))
end_define

begin_comment
comment|/* A macro that tells us whether the function invocation represented    by FI does not have a frame on the stack associated with it.  If it    does not, FRAMELESS is set to 1, else 0.  */
end_comment

begin_undef
undef|#
directive|undef
name|FRAMELESS_FUNCTION_INVOCATION
end_undef

begin_define
define|#
directive|define
name|FRAMELESS_FUNCTION_INVOCATION
parameter_list|(
name|FI
parameter_list|,
name|FRAMELESS
parameter_list|)
define|\
value|do { \     if ((FI)->signal_handler_caller) \       (FRAMELESS) = 0; \     else \       (FRAMELESS) = frameless_look_for_prologue(FI); \   } while (0)
end_define

begin_comment
comment|/* Saved Pc.  Get it from sigcontext if within sigtramp.  */
end_comment

begin_comment
comment|/* Offset to saved PC in sigcontext, from<sys/signal.h>.  */
end_comment

begin_define
define|#
directive|define
name|SIGCONTEXT_PC_OFFSET
value|20
end_define

begin_undef
undef|#
directive|undef
name|FRAME_SAVED_PC
end_undef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|fbsd_kern_frame_saved_pc
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
name|FRAME_SAVED_PC
parameter_list|(
name|FRAME
parameter_list|)
define|\
value|(kernel_debugging ? fbsd_kern_frame_saved_pc(FRAME) : \   (((FRAME)->signal_handler_caller \     ? sigtramp_saved_pc (FRAME) \     : read_memory_integer ((FRAME)->frame + 4, 4)) \    ))
end_define

begin_undef
undef|#
directive|undef
name|SETUP_ARBITRARY_FRAME
end_undef

begin_include
include|#
directive|include
file|"frame.h"
end_include

begin_function_decl
specifier|extern
name|FRAME
name|setup_arbitrary_frame
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SETUP_ARBITRARY_FRAME
value|setup_arbitrary_frame
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FREEBSD_TM_H_ */
end_comment

end_unit

