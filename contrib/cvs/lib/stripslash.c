begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stripslash.c -- remove trailing slashes from a string    Copyright (C) 1990 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.  */
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

begin_if
if|#
directive|if
name|STDC_HEADERS
operator|||
name|HAVE_STRING_H
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* An ANSI string.h and pre-ANSI memory.h might conflict. */
end_comment

begin_if
if|#
directive|if
operator|!
name|STDC_HEADERS
operator|&&
name|HAVE_MEMORY_H
end_if

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not STDC_HEADERS and HAVE_MEMORY_H */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not STDC_HJEADERS and not HAVE_STRING_H */
end_comment

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_comment
comment|/* memory.h and strings.h conflict on some systems. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not STDC_HEADERS and not HAVE_STRING_H */
end_comment

begin_comment
comment|/* Remove trailing slashes from PATH. */
end_comment

begin_function
name|void
name|strip_trailing_slashes
parameter_list|(
name|path
parameter_list|)
name|char
modifier|*
name|path
decl_stmt|;
block|{
name|int
name|last
decl_stmt|;
name|last
operator|=
name|strlen
argument_list|(
name|path
argument_list|)
operator|-
literal|1
expr_stmt|;
while|while
condition|(
name|last
operator|>
literal|0
operator|&&
name|path
index|[
name|last
index|]
operator|==
literal|'/'
condition|)
name|path
index|[
name|last
operator|--
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function

end_unit

