begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for running gdb on a Sun 4 running sunos 4.    Copyright (C) 1989, Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"xm-sparc.h"
end_include

begin_define
define|#
directive|define
name|FPU
end_define

begin_comment
comment|/* Large alloca's fail because the attempt to increase the stack limit in    main() fails because shared libraries are allocated just below the initial    stack limit.  The SunOS kernel will not allow the stack to grow into    the area occupied by the shared libraries.  Sun knows about this bug    but has no obvious fix for it.  */
end_comment

begin_define
define|#
directive|define
name|BROKEN_LARGE_ALLOCA
end_define

begin_comment
comment|/* SunOS 4.x has memory mapped files.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP
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
comment|/* /usr/include/malloc.h defines these w/o prototypes (and uses    char * instead of void *).  */
end_comment

begin_define
define|#
directive|define
name|MALLOC_INCOMPATIBLE
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|malloc
name|PARAMS
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|realloc
name|PARAMS
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|free
name|PARAMS
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SunOS 4.x uses nonstandard "char *" as type of third argument to ptrace() */
end_comment

begin_define
define|#
directive|define
name|PTRACE_ARG3_TYPE
value|char*
end_define

end_unit

