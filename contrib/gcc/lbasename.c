begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Libiberty basename.  Like basename, but is not overridden by the    system C library.    Copyright (C) 2001, 2002 Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/*  @deftypefn Replacement {const char*} lbasename (const char *@var{name})  Given a pointer to a string containing a typical pathname (@samp{/usr/src/cmd/ls/ls.c} for example), returns a pointer to the last component of the pathname (@samp{ls.c} in this case).  The returned pointer is guaranteed to lie within the original string.  This latter fact is not true of many vendor C libraries, which return special strings or modify the passed strings for particular input.  In particular, the empty string returns the same empty string, and a path ending in @code{/} returns the empty string after it.  @end deftypefn  */
end_comment

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

begin_include
include|#
directive|include
file|"safe-ctype.h"
end_include

begin_include
include|#
directive|include
file|"filenames.h"
end_include

begin_function
specifier|const
name|char
modifier|*
name|lbasename
parameter_list|(
name|name
parameter_list|)
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|{
specifier|const
name|char
modifier|*
name|base
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DOS_BASED_FILE_SYSTEM
argument_list|)
comment|/* Skip over a possible disk name.  */
if|if
condition|(
name|ISALPHA
argument_list|(
name|name
index|[
literal|0
index|]
argument_list|)
operator|&&
name|name
index|[
literal|1
index|]
operator|==
literal|':'
condition|)
name|name
operator|+=
literal|2
expr_stmt|;
endif|#
directive|endif
for|for
control|(
name|base
operator|=
name|name
init|;
operator|*
name|name
condition|;
name|name
operator|++
control|)
if|if
condition|(
name|IS_DIR_SEPARATOR
argument_list|(
operator|*
name|name
argument_list|)
condition|)
name|base
operator|=
name|name
operator|+
literal|1
expr_stmt|;
return|return
name|base
return|;
block|}
end_function

end_unit

