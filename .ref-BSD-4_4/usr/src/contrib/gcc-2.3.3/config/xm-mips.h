begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU C-compiler for MIPS Rx000 family    Copyright (C) 1989, 1990, 1991 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MIPSEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__MIPSEL__
argument_list|)
end_if

begin_define
define|#
directive|define
name|HOST_WORDS_BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable host-conditionals for MIPS machines.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS
end_ifndef

begin_define
define|#
directive|define
name|MIPS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A code distinguishing the floating point format of the host    machine.  There are three defined values: IEEE_FLOAT_FORMAT,    VAX_FLOAT_FORMAT, and UNKNOWN_FLOAT_FORMAT.  */
end_comment

begin_define
define|#
directive|define
name|HOST_FLOAT_FORMAT
value|IEEE_FLOAT_FORMAT
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
name|FATAL_EXIT_CODE
value|33
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_comment
comment|/* The MIPS compiler gets it wrong, and treats enumerated bitfields    as signed quantities, making it impossible to use an 8-bit enum    for compiling GNU C++.  */
end_comment

begin_define
define|#
directive|define
name|ONLY_INT_FIELDS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_OVERRIDE_ALLOCA
end_ifndef

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

begin_function_decl
specifier|extern
name|char
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* for the emacs version of alloca */
end_comment

begin_define
define|#
directive|define
name|STACK_DIRECTION
value|-1
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
comment|/* not MIPS_OVERRIDE_ALLOCA */
end_comment

begin_comment
comment|/* Say if we have vprintf.  BSD Mips targets probably don't have vfprintf.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OSF1__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OSF__
argument_list|)
operator|||
name|defined
argument_list|(
name|__osf__
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_PUTENV
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NO_STAB_H
end_define

begin_comment
comment|/* mips doesn't typically have stab.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

