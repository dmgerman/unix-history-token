begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1995 Free Software Foundation, Inc. This file is part of GNU Fortran libU77 library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with GNU Fortran; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
name|HAVE_STRING_H
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

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_comment
comment|/* Subroutine */
end_comment

begin_decl_stmt
name|int
name|G77_perror_0
argument_list|(
name|str
argument_list|,
name|Lstr
argument_list|)
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ftnlen
name|Lstr
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Subroutine */
end_comment

begin_function
name|int
name|G77_perror_0
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|ftnlen
name|Lstr
parameter_list|)
endif|#
directive|endif
block|{
name|char
name|buff
index|[
literal|1000
index|]
decl_stmt|;
name|char
modifier|*
name|bp
decl_stmt|,
modifier|*
name|blast
decl_stmt|;
comment|/* same technique as `system' -- what's wrong with malloc? */
name|blast
operator|=
name|buff
operator|+
operator|(
name|Lstr
operator|<
literal|1000
condition|?
name|Lstr
else|:
literal|1000
operator|)
expr_stmt|;
for|for
control|(
name|bp
operator|=
name|buff
init|;
name|bp
operator|<
name|blast
operator|&&
operator|*
name|str
operator|!=
literal|'\0'
condition|;
control|)
operator|*
name|bp
operator|++
operator|=
operator|*
name|str
operator|++
expr_stmt|;
operator|*
name|bp
operator|=
literal|'\0'
expr_stmt|;
name|perror
argument_list|(
name|buff
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

