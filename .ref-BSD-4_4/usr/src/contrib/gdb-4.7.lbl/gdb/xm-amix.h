begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for GDB on a Commodore Amiga running SVR4 (amix)    Copyright 1991, 1992 Free Software Foundation, Inc.    Written by Fred Fish at Cygnus Support (fnf@cygnus.com)  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Pick up most of what we need from the generic m68k host include file. */
end_comment

begin_include
include|#
directive|include
file|"xm-m68k.h"
end_include

begin_comment
comment|/* Pick up more stuff from the generic SVR4 host include file. */
end_comment

begin_include
include|#
directive|include
file|"xm-sysv4.h"
end_include

begin_comment
comment|/* The native AT&T compiler for m68k/SVR4 complains about using volatile    to indicate functions that never return.  So shut it up by simply    defining away "NORETURN", which is normally defined to "volatile". */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|NORETURN
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If you expect to use the mmalloc package to obtain mapped symbol files,    for now you have to specify some parameters that determine how gdb places    the mappings in it's address space.  See the comments in map_to_address()    for details.  This is expected to only be a short term solution.  Yes it    is a kludge.    FIXME:  Make this more automatic. */
end_comment

begin_define
define|#
directive|define
name|MMAP_BASE_ADDRESS
value|0xC2000000
end_define

begin_comment
comment|/* First mapping here */
end_comment

begin_define
define|#
directive|define
name|MMAP_INCREMENT
value|0x01000000
end_define

begin_comment
comment|/* Increment to next mapping */
end_comment

end_unit

