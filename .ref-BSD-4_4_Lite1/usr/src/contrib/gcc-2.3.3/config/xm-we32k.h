begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU C-compiler for AT&T we32000 Family.    Contributed by John Wehle (john@feith1.uucp)    Copyright (C) 1991-1992 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* #defines that need visibility everywhere.  */
end_comment

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_comment
comment|/* This describes the machine the compiler is hosted on.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BITS_PER_CHAR
value|8
end_define

begin_define
define|#
directive|define
name|HOST_BITS_PER_SHORT
value|16
end_define

begin_define
define|#
directive|define
name|HOST_BITS_PER_INT
value|32
end_define

begin_define
define|#
directive|define
name|HOST_BITS_PER_LONG
value|32
end_define

begin_comment
comment|/* Arguments to use with `exit'.  */
end_comment

begin_define
define|#
directive|define
name|SUCCESS_EXIT_CODE
value|0
end_define

begin_define
define|#
directive|define
name|FATAL_EXIT_CODE
value|33
end_define

begin_define
define|#
directive|define
name|USG
end_define

begin_comment
comment|/* Don't try to use sys_siglist.  */
end_comment

begin_define
define|#
directive|define
name|NO_SYS_SIGLIST
end_define

begin_comment
comment|/* Don't try including wait.h.  */
end_comment

begin_define
define|#
directive|define
name|NO_WAIT_H
end_define

begin_comment
comment|/* target machine dependencies.    tm.h is a symbolic link to the actual target specific file.   */
end_comment

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcpy (b,a,c)
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|memset (a,0,b)
end_define

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcmp (a,b,c)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|alloca
parameter_list|(
name|n
parameter_list|)
value|__builtin_alloca(n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

