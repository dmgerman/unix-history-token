begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dirname.c -- return all but the last element in a path    Copyright (C) 1990 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STDC_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_STRING_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|strrchr
end_ifndef

begin_define
define|#
directive|define
name|strrchr
value|rindex
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
comment|/* Return the leading directories part of PATH,    allocated with malloc.  If out of memory, return 0.    Assumes that trailing slashes have already been    removed.  */
end_comment

begin_function
name|char
modifier|*
name|dirname
parameter_list|(
name|path
parameter_list|)
name|char
modifier|*
name|path
decl_stmt|;
block|{
name|char
modifier|*
name|newpath
decl_stmt|;
name|char
modifier|*
name|slash
decl_stmt|;
name|int
name|length
decl_stmt|;
comment|/* Length of result, not including NUL.  */
name|slash
operator|=
name|strrchr
argument_list|(
name|path
argument_list|,
literal|'/'
argument_list|)
expr_stmt|;
if|if
condition|(
name|slash
operator|==
literal|0
condition|)
block|{
comment|/* File is in the current directory.  */
name|path
operator|=
literal|"."
expr_stmt|;
name|length
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
comment|/* Remove any trailing slashes from the result.  */
while|while
condition|(
name|slash
operator|>
name|path
operator|&&
operator|*
name|slash
operator|==
literal|'/'
condition|)
operator|--
name|slash
expr_stmt|;
name|length
operator|=
name|slash
operator|-
name|path
operator|+
literal|1
expr_stmt|;
block|}
name|newpath
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|length
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|newpath
operator|==
literal|0
condition|)
return|return
literal|0
return|;
name|strncpy
argument_list|(
name|newpath
argument_list|,
name|path
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|newpath
index|[
name|length
index|]
operator|=
literal|0
expr_stmt|;
return|return
name|newpath
return|;
block|}
end_function

end_unit

