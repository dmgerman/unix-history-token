begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU C-compiler for openVMS/Alpha.    Copyright (C) 1996, 1997 Free Software Foundation, Inc.    Contributed by Klaus Kaempf (kkaempf@progis.de).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* If compiling with DECC, need to fix problem with<stdio.h>    which defines a macro called FILE_TYPE that breaks "tree.h".    Fortunately it uses #ifndef to suppress multiple inclusions.    Three possible cases:         1)<stdio.h> has already been included -- ours will be no-op;         2)<stdio.h> will be included after us -- "theirs" will be no-op;         3)<stdio.h> isn't needed -- including it here shouldn't hurt.    In all three cases, the problem macro will be removed here.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__DECC
end_ifdef

begin_undef
undef|#
directive|undef
name|FILE_TYPE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|HOST_BITS_PER_LONG
end_undef

begin_define
define|#
directive|define
name|HOST_BITS_PER_LONG
value|32
end_define

begin_define
define|#
directive|define
name|HOST_WIDE_INT
value|long long
end_define

begin_define
define|#
directive|define
name|HOST_BITS_PER_WIDE_INT
value|64
end_define

begin_undef
undef|#
directive|undef
name|SUCCESS_EXIT_CODE
end_undef

begin_define
define|#
directive|define
name|SUCCESS_EXIT_CODE
value|1
end_define

begin_undef
undef|#
directive|undef
name|FATAL_EXIT_CODE
end_undef

begin_define
define|#
directive|define
name|FATAL_EXIT_CODE
value|(44 | 0x10000000)
end_define

begin_comment
comment|/* Abort, and no DCL message.  */
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

begin_define
define|#
directive|define
name|GCC_INCLUDE_DIR
value|""
end_define

begin_comment
comment|/* Specify the list of include file directories.  */
end_comment

begin_define
define|#
directive|define
name|INCLUDE_DEFAULTS
define|\
value|{					\   { "GNU_GXX_INCLUDE:", "G++", 1, 1 },	\   { "GNU_CC_INCLUDE:", "GCC", 0, 0 },	\   { ".", 0, 0, 1 },			\   { 0, 0, 0, 0 }			\ }
end_define

begin_comment
comment|/* Define a local equivalent (sort of) for unlink */
end_comment

begin_define
define|#
directive|define
name|unlink
value|remove
end_define

begin_define
define|#
directive|define
name|NEED_ATEXIT
end_define

begin_define
define|#
directive|define
name|HAVE_VPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_PUTENV
end_define

begin_define
define|#
directive|define
name|HAVE_STRERROR
end_define

begin_define
define|#
directive|define
name|HAVE_ATOLL
end_define

begin_define
define|#
directive|define
name|NO_SYS_PARAMS_H
end_define

begin_comment
comment|/* Don't have<sys/params.h> */
end_comment

begin_define
define|#
directive|define
name|USE_C_ALLOCA
end_define

begin_comment
comment|/* Using alloca.c */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDDEF_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TIME_H
value|1
end_define

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_CPP_STRINGIFY
value|1
end_define

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
specifier|extern
name|void
modifier|*
name|alloca
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|alloca
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OBJECT_SUFFIX
value|".obj"
end_define

begin_define
define|#
directive|define
name|EXECUTABLE_SUFFIX
value|".exe"
end_define

end_unit

