begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for x86 running under FreeBSD Unix.    Copyright 1996 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_FBSD_H
end_ifndef

begin_define
define|#
directive|define
name|TM_FBSD_H
value|1
end_define

begin_include
include|#
directive|include
file|"i386/tm-i386bsd.h"
end_include

begin_undef
undef|#
directive|undef
name|NUM_REGS
end_undef

begin_define
define|#
directive|define
name|NUM_REGS
value|14
end_define

begin_decl_stmt
specifier|extern
name|struct
name|frame_info
modifier|*
name|setup_arbitrary_frame
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|CORE_ADDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SETUP_ARBITRARY_FRAME
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
value|setup_arbitrary_frame (argc, argv)
end_define

begin_decl_stmt
specifier|extern
name|void
name|i386_float_info
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FLOAT_INFO
value|i386_float_info ()
end_define

begin_define
define|#
directive|define
name|IN_SOLIB_CALL_TRAMPOLINE
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|STREQ (name, "_DYNAMIC")
end_define

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address and produces the frame's    chain-pointer.    In the case of the i386, the frame's nominal address    is the address of a 4-byte word containing the calling frame's address.  */
end_comment

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
name|thisframe
parameter_list|)
define|\
value|(kernel_debugging ? fbsd_kern_frame_chain(thisframe) : \   ((thisframe)->signal_handler_caller \    ? (thisframe)->frame \    : (!inside_entry_file ((thisframe)->pc) \       ? read_memory_integer ((thisframe)->frame, 4) \       : 0)))
end_define

begin_comment
comment|/* Saved Pc.  Get it from sigcontext if within sigtramp.  */
end_comment

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
name|FRAME
parameter_list|)
define|\
value|(kernel_debugging ? fbsd_kern_frame_saved_pc(FRAME) : \   (((FRAME)->signal_handler_caller \     ? sigtramp_saved_pc (FRAME) \     : read_memory_integer ((FRAME)->frame + 4, 4)) \    ))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_FBSD_H */
end_comment

end_unit

