begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for i386 running under BSD Unix.    Copyright 1986, 1987, 1989, 1991, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_comment
comment|/* 386BSD cannot handle the segment registers. */
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
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*	BSDI $Id: tm-i386bsd.h,v 1.1.1.1 1992/08/27 17:03:50 trent Exp $	*/
end_comment

begin_undef
undef|#
directive|undef
name|FRAME_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|FRAME_NUM_ARGS
parameter_list|(
name|val
parameter_list|,
name|fi
parameter_list|)
value|(val = -1)
end_define

begin_undef
undef|#
directive|undef
name|COFF_NO_LONG_FILE_NAMES
end_undef

begin_define
define|#
directive|define
name|NAMES_HAVE_UNDERSCORE
value|1
end_define

begin_define
define|#
directive|define
name|NEED_TEXT_START_END
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNELDEBUG
end_ifdef

begin_define
define|#
directive|define
name|MEM_DEVICE
value|2
end_define

begin_decl_stmt
specifier|extern
name|int
name|kernel_debugging
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|FRAME_CHAIN_VALID
end_undef

begin_define
define|#
directive|define
name|FRAME_CHAIN_VALID
parameter_list|(
name|chain
parameter_list|,
name|thisframe
parameter_list|)
define|\
value|(chain != 0&& \ 	 kernel_debugging ? inside_kernstack(chain) : \ 		(!inside_entry_file(FRAME_SAVED_PC(thisframe))))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

