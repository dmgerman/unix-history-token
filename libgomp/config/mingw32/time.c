begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2006 Free Software Foundation, Inc.    Contributed by Francois-Xavier Coudert<coudert@clipper.ens.fr>     This file is part of the GNU OpenMP Library (libgomp).     Libgomp is free software; you can redistribute it and/or modify it    under the terms of the GNU Lesser General Public License as published by    the Free Software Foundation; either version 2.1 of the License, or    (at your option) any later version.     Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS    FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for    more details.     You should have received a copy of the GNU Lesser General Public License     along with libgomp; see the file COPYING.LIB.  If not, write to the    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files, some    of which are compiled with GCC, to produce an executable, this library    does not by itself cause the resulting executable to be covered by the    GNU General Public License.  This exception does not however invalidate    any other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_comment
comment|/* This file contains timer routines for mingw32.  */
end_comment

begin_include
include|#
directive|include
file|"libgomp.h"
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_function
name|double
name|omp_get_wtime
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|_timeb
name|timebuf
decl_stmt|;
name|_ftime
argument_list|(
operator|&
name|timebuf
argument_list|)
expr_stmt|;
return|return
operator|(
name|timebuf
operator|.
name|time
operator|+
call|(
name|long
call|)
argument_list|(
name|timebuf
operator|.
name|millitm
argument_list|)
operator|/
literal|1e3
operator|)
return|;
block|}
end_function

begin_function
name|double
name|omp_get_wtick
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|1e-3
return|;
block|}
end_function

begin_macro
name|ialias
argument_list|(
argument|omp_get_wtime
argument_list|)
end_macro

begin_macro
name|ialias
argument_list|(
argument|omp_get_wtick
argument_list|)
end_macro

end_unit

