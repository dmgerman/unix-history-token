begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU C-compiler for IBM RS/6000.    Copyright (C) 1990 Free Software Foundation, Inc.    Contributed by Richard Kenner (kenner@nyu.edu).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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

begin_define
define|#
directive|define
name|HOST_BITS_PER_LONGLONG
value|64
end_define

begin_define
define|#
directive|define
name|HOST_WORDS_BIG_ENDIAN
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
name|FAILURE_EXIT_CODE
value|2
end_define

begin_define
define|#
directive|define
name|FATAL_EXIT_CODE
value|3
end_define

begin_comment
comment|/* If compiled with GNU C, use the built-in alloca.  */
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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|USE_C_ALLOCA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If not compiled with GNU C, use only int bitfields.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|ONLY_INT_FIELDS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIX is a flavor of System V */
end_comment

begin_define
define|#
directive|define
name|USG
end_define

begin_comment
comment|/* This is the only version of nm that collect2 can work with.  */
end_comment

begin_define
define|#
directive|define
name|REAL_NM_FILE_NAME
value|"/usr/ucb/nm"
end_define

begin_comment
comment|/* Big buffers improve performance.  */
end_comment

begin_define
define|#
directive|define
name|IO_BUFFER_SIZE
value|(0x8000 - 4096)
end_define

end_unit

