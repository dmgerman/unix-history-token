begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU C-compiler for Vax.    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
comment|/* target machine dependencies.    tm.h is a symbolic link to the actual target specific file.   */
end_comment

begin_include
include|#
directive|include
file|"tm.h"
end_include

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

begin_define
define|#
directive|define
name|SUCCESS_EXIT_CODE
value|1
end_define

begin_define
define|#
directive|define
name|FATAL_EXIT_CODE
value|(44 | 0x10000000)
end_define

begin_comment
comment|/* Failure, and no DCL message.  */
end_comment

begin_comment
comment|/* A couple of conditionals for execution machine are controlled here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMS
end_ifndef

begin_define
define|#
directive|define
name|VMS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_comment
comment|/* not present, at least in VAX-11 C (VMS) v2.2 */
end_comment

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_define
define|#
directive|define
name|unlink
value|delete
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* global const variables don't work,    so turn off const-ness to prevent trouble with insn-output.c.  */
end_comment

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/* If compiled with GNU C, use the built-in alloca */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

