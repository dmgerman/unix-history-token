begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Utility to pick a temporary filename prefix.    Copyright (C) 1996 Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file exports one function: choose_temp_base.  */
end_comment

begin_comment
comment|/* This file lives in at least two places: libiberty and gcc.    Don't change one without the other.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SYS_FILE_H
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_comment
comment|/* May get R_OK, etc. on some systems.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|R_OK
end_ifndef

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
name|IN_GCC
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"gansidecl.h"
end_include

begin_function_decl
specifier|extern
name|char
modifier|*
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

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
value|'/'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On MSDOS, write temp files in current dir    because there's no place else we can expect to use.  */
end_comment

begin_comment
comment|/* ??? Although the current directory is tried as a last resort,    this is left in so that on MSDOS it is prefered to /tmp on the    off chance that someone requires this, since that was the previous    behaviour.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__MSDOS__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|P_tmpdir
end_ifndef

begin_define
define|#
directive|define
name|P_tmpdir
value|"."
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
comment|/* Name of temporary file.    mktemp requires 6 trailing X's.  */
end_comment

begin_define
define|#
directive|define
name|TEMP_FILE
value|"ccXXXXXX"
end_define

begin_comment
comment|/* Subroutine of choose_temp_base.    If BASE is non-NULL, returh it.    Otherwise it checks if DIR is a usable directory.    If success, DIR is returned.    Otherwise NULL is returned.  */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|try
parameter_list|(
name|dir
parameter_list|,
name|base
parameter_list|)
name|char
modifier|*
name|dir
decl_stmt|,
decl|*
name|base
decl_stmt|;
end_function

begin_block
block|{
if|if
condition|(
name|base
operator|!=
literal|0
condition|)
return|return
name|base
return|;
if|if
condition|(
name|dir
operator|!=
literal|0
operator|&&
name|access
argument_list|(
name|dir
argument_list|,
name|R_OK
operator||
name|W_OK
argument_list|)
operator|==
literal|0
condition|)
return|return
name|dir
return|;
return|return
literal|0
return|;
block|}
end_block

begin_comment
comment|/* Return a prefix for temporary file names or NULL if unable to find one.    The current directory is chosen if all else fails so the program is    exited if a temporary directory can't be found (mktemp fails).    The buffer for the result is obtained with xmalloc.  */
end_comment

begin_function
name|char
modifier|*
name|choose_temp_base
parameter_list|()
block|{
name|char
modifier|*
name|base
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|temp_filename
decl_stmt|;
name|int
name|len
decl_stmt|;
specifier|static
name|char
name|tmp
index|[]
init|=
block|{
name|DIR_SEPARATOR
block|,
literal|'t'
block|,
literal|'m'
block|,
literal|'p'
block|,
literal|0
block|}
decl_stmt|;
specifier|static
name|char
name|usrtmp
index|[]
init|=
block|{
name|DIR_SEPARATOR
block|,
literal|'u'
block|,
literal|'s'
block|,
literal|'r'
block|,
name|DIR_SEPARATOR
block|,
literal|'t'
block|,
literal|'m'
block|,
literal|'p'
block|,
literal|0
block|}
decl_stmt|;
ifndef|#
directive|ifndef
name|MPW
name|base
operator|=
name|try
argument_list|(
name|getenv
argument_list|(
literal|"TMPDIR"
argument_list|)
argument_list|,
name|base
argument_list|)
expr_stmt|;
name|base
operator|=
name|try
argument_list|(
name|getenv
argument_list|(
literal|"TMP"
argument_list|)
argument_list|,
name|base
argument_list|)
expr_stmt|;
name|base
operator|=
name|try
argument_list|(
name|getenv
argument_list|(
literal|"TEMP"
argument_list|)
argument_list|,
name|base
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|P_tmpdir
name|base
operator|=
name|try
argument_list|(
name|P_tmpdir
argument_list|,
name|base
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Try /usr/tmp, then /tmp.  */
name|base
operator|=
name|try
argument_list|(
name|usrtmp
argument_list|,
name|base
argument_list|)
expr_stmt|;
name|base
operator|=
name|try
argument_list|(
name|tmp
argument_list|,
name|base
argument_list|)
expr_stmt|;
comment|/* If all else fails, use the current directory!  */
if|if
condition|(
name|base
operator|==
literal|0
condition|)
name|base
operator|=
literal|"."
expr_stmt|;
else|#
directive|else
comment|/* MPW */
name|base
operator|=
literal|":"
expr_stmt|;
endif|#
directive|endif
name|len
operator|=
name|strlen
argument_list|(
name|base
argument_list|)
expr_stmt|;
if|if
condition|(
name|len
operator|==
literal|0
condition|)
name|abort
argument_list|()
expr_stmt|;
name|temp_filename
operator|=
name|xmalloc
argument_list|(
name|len
operator|+
literal|1
comment|/*DIR_SEPARATOR*/
operator|+
name|strlen
argument_list|(
name|TEMP_FILE
argument_list|)
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
ifndef|#
directive|ifndef
name|MPW
if|if
condition|(
name|temp_filename
index|[
name|len
operator|-
literal|1
index|]
operator|!=
literal|'/'
operator|&&
name|temp_filename
index|[
name|len
operator|-
literal|1
index|]
operator|!=
name|DIR_SEPARATOR
condition|)
name|temp_filename
index|[
name|len
operator|++
index|]
operator|=
name|DIR_SEPARATOR
expr_stmt|;
else|#
directive|else
comment|/* MPW */
if|if
condition|(
name|temp_filename
index|[
name|len
operator|-
literal|1
index|]
operator|!=
literal|':'
condition|)
name|temp_filename
index|[
name|len
operator|++
index|]
operator|=
literal|':'
expr_stmt|;
endif|#
directive|endif
comment|/* MPW */
name|strcpy
argument_list|(
name|temp_filename
operator|+
name|len
argument_list|,
name|TEMP_FILE
argument_list|)
expr_stmt|;
name|mktemp
argument_list|(
name|temp_filename
argument_list|)
expr_stmt|;
if|if
condition|(
name|strlen
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

