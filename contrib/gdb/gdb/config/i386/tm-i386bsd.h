begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for i386 running under BSD Unix.    Copyright 1986, 1987, 1989, 1991, 1992, 1993 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_I386BSD_H
end_ifndef

begin_define
define|#
directive|define
name|TM_I386BSD_H
value|1
end_define

begin_include
include|#
directive|include
file|"i386/tm-i386.h"
end_include

begin_comment
comment|/* 386BSD cannot handle the segment registers. */
end_comment

begin_comment
comment|/* BSDI can't handle them either.  */
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
value|10
end_define

begin_comment
comment|/* On 386 bsd, sigtramp is above the user stack and immediately below    the user area. Using constants here allows for cross debugging.    These are tested for BSDI but should work on 386BSD.  */
end_comment

begin_define
define|#
directive|define
name|SIGTRAMP_START
parameter_list|(
name|pc
parameter_list|)
value|0xfdbfdfc0
end_define

begin_define
define|#
directive|define
name|SIGTRAMP_END
parameter_list|(
name|pc
parameter_list|)
value|0xfdbfe000
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef TM_I386BSD_H */
end_comment

end_unit

