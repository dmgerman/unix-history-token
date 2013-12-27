begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by Richard Henderson<rth@redhat.com>.     This file is part of the GNU OpenMP Library (libgomp).     Libgomp is free software; you can redistribute it and/or modify it    under the terms of the GNU Lesser General Public License as published by    the Free Software Foundation; either version 2.1 of the License, or    (at your option) any later version.     Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS    FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for    more details.     You should have received a copy of the GNU Lesser General Public License     along with libgomp; see the file COPYING.LIB.  If not, write to the    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files, some    of which are compiled with GCC, to produce an executable, this library    does not by itself cause the resulting executable to be covered by the    GNU General Public License.  This exception does not however invalidate    any other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_comment
comment|/* This file contains routines used to signal errors.  Most places in the    OpenMP API do not make any provision for failure, so we can't just    defer the decision on reporting the problem to the user; we must do it    ourselves or not at all.  */
end_comment

begin_comment
comment|/* ??? Is this about what other implementations do?  Assume stderr hasn't    been pointed somewhere unsafe?  */
end_comment

begin_include
include|#
directive|include
file|"libgomp.h"
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function
specifier|static
name|void
name|gomp_verror
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|list
parameter_list|)
block|{
name|fputs
argument_list|(
literal|"\nlibgomp: "
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|fmt
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|gomp_error
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|list
decl_stmt|;
name|va_start
argument_list|(
name|list
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|gomp_verror
argument_list|(
name|fmt
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|list
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|gomp_fatal
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|list
decl_stmt|;
name|va_start
argument_list|(
name|list
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|gomp_verror
argument_list|(
name|fmt
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|list
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

