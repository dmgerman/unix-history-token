begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Get common system includes and various definitions and declarations    based on target macros.    Copyright (C) 2000, 2001 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_TSYSTEM_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_TSYSTEM_H
end_define

begin_comment
comment|/* System headers (e.g. stdio.h, stdlib.h, unistd.h) sometimes    indirectly include getopt.h.  Our -I flags will cause gcc's gnu    getopt.h to be included, not the platform's copy.  In the default    case, gnu getopt.h will provide us with a no-argument prototype    which will generate -Wstrict-prototypes warnings.  None of the    target files actually use getopt, so it is safe to tell gnu    getopt.h we never need this prototype.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DECL_GETOPT
end_ifndef

begin_define
define|#
directive|define
name|HAVE_DECL_GETOPT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC supplies this header.  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|inhibit_libc
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|malloc
end_ifndef

begin_function_decl
specifier|extern
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|free
end_ifndef

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|atexit
end_ifndef

begin_function_decl
specifier|extern
name|int
name|atexit
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! inhibit_libc */
end_comment

begin_comment
comment|/* We disable this when inhibit_libc, so that gcc can still be built without    needing header files first.  */
end_comment

begin_comment
comment|/* ??? This is not a good solution, since prototypes may be required in    some cases for correct code.  */
end_comment

begin_comment
comment|/* GCC supplies this header.  */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|/* All systems have this header.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* All systems have this header.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* All systems have this header.  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|errno
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC (fixproto) guarantees these system headers exist.  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/* GCC supplies this header.  */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* inhibit_libc */
end_comment

begin_comment
comment|/* Define a generic NULL if one hasn't already been defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_TSYSTEM_H */
end_comment

end_unit

