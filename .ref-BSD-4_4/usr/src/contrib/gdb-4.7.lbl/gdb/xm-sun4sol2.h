begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for running gdb on a Sun 4 running Solaris 2.    Copyright 1989, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Most of what we know is generic to SPARC hosts.  */
end_comment

begin_include
include|#
directive|include
file|"xm-sparc.h"
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
comment|/* SVR4's can't seem to agree on what to call the type that contains the    general registers.  Kludge around it with a #define.  */
end_comment

begin_define
define|#
directive|define
name|gregset_t
value|prgregset_t
end_define

begin_define
define|#
directive|define
name|fpregset_t
value|prfpregset_t
end_define

begin_comment
comment|/* The native Sun compiler complains about using volatile    to indicate functions that never return.  So shut it up by simply    defining away "NORETURN", which is normally defined to "volatile". */
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
comment|/* Large alloca's fail because the attempt to increase the stack limit in    main() fails because shared libraries are allocated just below the initial    stack limit.  The SunOS kernel will not allow the stack to grow into    the area occupied by the shared libraries.  Sun knows about this bug    but has no obvious fix for it.  */
end_comment

begin_define
define|#
directive|define
name|BROKEN_LARGE_ALLOCA
end_define

begin_comment
comment|/* If you expect to use the mmalloc package to obtain mapped symbol files,    for now you have to specify some parameters that determine how gdb places    the mappings in it's address space.  See the comments in map_to_address()    for details.  This is expected to only be a short term solution.  Yes it    is a kludge.    FIXME:  Make this more automatic. */
end_comment

begin_define
define|#
directive|define
name|MMAP_BASE_ADDRESS
value|0xE0000000
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

begin_comment
comment|/* These are not currently used in SVR4 (but should be, FIXME!).  */
end_comment

begin_undef
undef|#
directive|undef
name|DO_DEFERRED_STORES
end_undef

begin_undef
undef|#
directive|undef
name|CLEAR_DEFERRED_STORES
end_undef

begin_comment
comment|/* May be needed, may be not?  From Pace Willisson's port.  FIXME.  */
end_comment

begin_define
define|#
directive|define
name|NEED_POSIX_SETPGID
end_define

begin_comment
comment|/* Solaris PSRVADDR support does not seem to include a place for nPC.  */
end_comment

begin_define
define|#
directive|define
name|PRSVADDR_BROKEN
end_define

end_unit

