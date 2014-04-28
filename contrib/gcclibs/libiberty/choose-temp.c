begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Utility to pick a temporary filename prefix.    Copyright (C) 1996, 1997, 1998 Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* May get P_tmpdir.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
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

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_function_decl
specifier|extern
name|char
modifier|*
name|choose_tmpdir
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Name of temporary file.    mktemp requires 6 trailing X's.  */
end_comment

begin_define
define|#
directive|define
name|TEMP_FILE
value|"ccXXXXXX"
end_define

begin_define
define|#
directive|define
name|TEMP_FILE_LEN
value|(sizeof(TEMP_FILE) - 1)
end_define

begin_comment
comment|/*  @deftypefn Extension char* choose_temp_base (void)  Return a prefix for temporary file names or @code{NULL} if unable to find one.  The current directory is chosen if all else fails so the program is exited if a temporary directory can't be found (@code{mktemp} fails).  The buffer for the result is obtained with @code{xmalloc}.  This function is provided for backwards compatability only.  Its use is not recommended.  @end deftypefn  */
end_comment

begin_function
name|char
modifier|*
name|choose_temp_base
parameter_list|(
name|void
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|base
init|=
name|choose_tmpdir
argument_list|()
decl_stmt|;
name|char
modifier|*
name|temp_filename
decl_stmt|;
name|int
name|len
decl_stmt|;
name|len
operator|=
name|strlen
argument_list|(
name|base
argument_list|)
expr_stmt|;
name|temp_filename
operator|=
name|XNEWVEC
argument_list|(
name|char
argument_list|,
name|len
operator|+
name|TEMP_FILE_LEN
operator|+
literal|1
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|temp_filename
argument_list|,
name|base
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|temp_filename
operator|+
name|len
argument_list|,
name|TEMP_FILE
argument_list|)
expr_stmt|;
if|if
condition|(
name|mktemp
argument_list|(
name|temp_filename
argument_list|)
operator|==
literal|0
condition|)
name|abort
argument_list|()
expr_stmt|;
return|return
name|temp_filename
return|;
block|}
end_function

end_unit

