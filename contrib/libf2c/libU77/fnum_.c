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
file|"f2c.h"
end_include

begin_include
include|#
directive|include
file|"fio.h"
end_include

begin_function
name|integer
name|G77_fnum_0
parameter_list|(
name|integer
modifier|*
name|lunit
parameter_list|)
block|{
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
name|err
argument_list|(
literal|1
argument_list|,
literal|101
argument_list|,
literal|"fnum"
argument_list|)
expr_stmt|;
comment|/* f__units is a table of descriptions for the unit numbers (defined      in io.h).  Use file descriptor (ufd) and fileno rather than udev      field since udev is unix specific */
return|return
name|fileno
argument_list|(
name|f__units
index|[
operator|*
name|lunit
index|]
operator|.
name|ufd
argument_list|)
return|;
block|}
end_function

end_unit

