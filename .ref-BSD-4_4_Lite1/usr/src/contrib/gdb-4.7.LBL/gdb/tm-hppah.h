begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for execution on an HP PA-RISC machine, running HPUX, for GDB.    Copyright 1991, 1992 Free Software Foundation, Inc.      Contributed by the Center for Software Science at the    University of Utah (pa-gdb-bugs@cs.utah.edu).  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Mostly it's common to all HPPA's.  */
end_comment

begin_include
include|#
directive|include
file|"tm-hppa.h"
end_include

begin_comment
comment|/* Saved PC's are different, since there is millicode.  */
end_comment

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|millicode_start
decl_stmt|,
name|millicode_end
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Immediately after a function call, return the saved pc.    Can't go through the frames for this because on some machines    the new frame is not set up until the new function executes    some instructions.  */
end_comment

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
define|\
value|((get_frame_pc (frame)>= millicode_start     \&& get_frame_pc (frame)< millicode_end) ?  \    read_register (31)& ~3                      \    : read_register (RP_REGNUM)& ~3)
end_define

end_unit

