begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* basename.c -- return the last element in a path    Copyright (C) 1990 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|||
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Return NAME with any leading path stripped off.  */
end_comment

begin_function
name|char
modifier|*
name|basename
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|char
modifier|*
name|base
decl_stmt|;
name|base
operator|=
name|rindex
argument_list|(
name|name
argument_list|,
literal|'/'
argument_list|)
expr_stmt|;
return|return
name|base
condition|?
name|base
operator|+
literal|1
else|:
name|name
return|;
block|}
end_function

end_unit

