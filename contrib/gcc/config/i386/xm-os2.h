begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU compiler    for an Intel i386 or later processor running OS/2 2.x.    Copyright (C) 1993, 1994, 1995, 1997, 1998, 1999 Free Software Foundation, Inc.    Contributed by Samuel Figueroa (figueroa@apple.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OS2
end_ifndef

begin_define
define|#
directive|define
name|OS2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__IBMC__
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* this defines alloca */
end_comment

begin_define
define|#
directive|define
name|USG
end_define

begin_define
define|#
directive|define
name|ONLY_INT_FIELDS
end_define

begin_define
define|#
directive|define
name|USE_PROTOTYPES
value|1
end_define

begin_define
define|#
directive|define
name|strcasecmp
value|stricmp
end_define

begin_define
define|#
directive|define
name|kill
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|raise(b)
end_define

begin_define
define|#
directive|define
name|mktemp
value|tmpnam
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__EMX__
end_ifdef

begin_define
define|#
directive|define
name|EMX
end_define

begin_define
define|#
directive|define
name|USG
end_define

begin_define
define|#
directive|define
name|BSTRING
end_define

begin_define
define|#
directive|define
name|HAVE_PUTENV
end_define

begin_define
define|#
directive|define
name|HAVE_VPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_STRERROR
end_define

begin_define
define|#
directive|define
name|strcasecmp
value|stricmp
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|____386BSD____
end_define

begin_function_decl
name|int
name|spawnv
parameter_list|(
name|int
name|modeflag
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|spawnvp
parameter_list|(
name|int
name|modeflag
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __EMX__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IBMC__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_SEPARATOR
end_ifndef

begin_define
define|#
directive|define
name|PATH_SEPARATOR
value|';'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DIR_SEPARATOR
end_ifndef

begin_define
define|#
directive|define
name|DIR_SEPARATOR
value|'\\'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DIR_SEPARATOR_2
end_ifndef

begin_define
define|#
directive|define
name|DIR_SEPARATOR_2
value|'/'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Allow handling of drive names. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DOS_BASED_FILE_SYSTEM
end_define

begin_define
define|#
directive|define
name|EXECUTABLE_SUFFIX
value|".exe"
end_define

begin_comment
comment|/* The EMX compiler uses regular .o files */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EMX__
end_ifndef

begin_define
define|#
directive|define
name|OBJECT_SUFFIX
value|".obj"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is required to make temporary file names unique on file    systems which severely restrict the length of file names. */
end_comment

begin_define
define|#
directive|define
name|MKTEMP_EACH_FILE
end_define

begin_include
include|#
directive|include
file|"i386/xm-i386.h"
end_include

end_unit

