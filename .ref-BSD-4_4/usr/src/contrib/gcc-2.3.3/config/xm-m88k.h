begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU compiler.    Motorola m88100 in an 88open OCS/BCS environment.    Copyright (C) 1988, 1989, 1990, 1991 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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

begin_comment
comment|/* Use System V memory functions.  */
end_comment

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

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_comment
comment|/* The 88open BCS (and ABI) environment doesn't support BSD features    (vfork, getrusage), so use USG.  The Omron Luna/88k is BSD though.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|luna88k
end_ifndef

begin_define
define|#
directive|define
name|USG
end_define

begin_define
define|#
directive|define
name|NO_SYS_SIGLIST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define HAVE_VPRINTF if it is available on host system.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VPRINTF
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
comment|/* For DG/UX, the best size is different.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__DGUX__
end_ifdef

begin_define
define|#
directive|define
name|OBSTACK_CHUNK_SIZE
value|(8192-16)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* target machine dependencies.    tm.h is a symbolic link to the actual target specific file.   */
end_comment

begin_include
include|#
directive|include
file|"tm.h"
end_include

end_unit

