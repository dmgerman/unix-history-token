begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1996 Free Software Foundation, Inc. This file is part of GNU Fortran libU77 library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with GNU Fortran; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|"f2c.h"
end_include

begin_include
include|#
directive|include
file|"fio.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_decl_stmt
name|integer
name|G77_fputc_0
argument_list|(
name|lunit
argument_list|,
name|c
argument_list|,
name|Lc
argument_list|)
name|integer
modifier|*
name|lunit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ftnlen
name|Lc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* should be 1 */
end_comment

begin_decl_stmt
name|char
modifier|*
name|c
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|integer
name|G77_fputc_0
parameter_list|(
specifier|const
name|integer
modifier|*
name|lunit
parameter_list|,
specifier|const
name|char
modifier|*
name|c
parameter_list|,
specifier|const
name|ftnlen
name|Lc
parameter_list|)
endif|#
directive|endif
block|{
name|int
name|err
decl_stmt|;
name|FILE
modifier|*
name|f
init|=
name|f__units
index|[
operator|*
name|lunit
index|]
operator|.
name|ufd
decl_stmt|;
if|if
condition|(
operator|*
name|lunit
operator|>=
name|MXUNIT
operator|||
operator|*
name|lunit
operator|<
literal|0
condition|)
return|return
literal|101
return|;
comment|/* bad unit error */
name|err
operator|=
name|putc
argument_list|(
name|c
index|[
literal|0
index|]
argument_list|,
name|f
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|==
name|EOF
condition|)
block|{
if|if
condition|(
name|feof
argument_list|(
name|f
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
else|else
return|return
name|ferror
argument_list|(
name|f
argument_list|)
return|;
block|}
else|else
return|return
literal|0
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_decl_stmt
name|integer
name|G77_fput_0
argument_list|(
name|c
argument_list|,
name|Lc
argument_list|)
name|ftnlen
name|Lc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* should be 1 */
end_comment

begin_decl_stmt
name|char
modifier|*
name|c
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|integer
name|G77_fput_0
parameter_list|(
specifier|const
name|char
modifier|*
name|c
parameter_list|,
specifier|const
name|ftnlen
name|Lc
parameter_list|)
endif|#
directive|endif
block|{
name|integer
name|six
init|=
literal|6
decl_stmt|;
return|return
name|G77_fputc_0
argument_list|(
operator|&
name|six
argument_list|,
name|c
argument_list|,
name|Lc
argument_list|)
return|;
block|}
end_function

end_unit

