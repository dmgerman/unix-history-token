begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by Richard Henderson<rth@redhat.com>.     This file is part of the GNU OpenMP Library (libgomp).     Libgomp is free software; you can redistribute it and/or modify it    under the terms of the GNU Lesser General Public License as published by    the Free Software Foundation; either version 2.1 of the License, or    (at your option) any later version.     Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS    FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for    more details.     You should have received a copy of the GNU Lesser General Public License     along with libgomp; see the file COPYING.LIB.  If not, write to the    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files, some    of which are compiled with GCC, to produce an executable, this library    does not by itself cause the resulting executable to be covered by the    GNU General Public License.  This exception does not however invalidate    any other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_comment
comment|/* This file contains wrappers for the system allocation routines.  Most    places in the OpenMP API do not make any provision for failure, so in    general we cannot allow memory allocation to fail.  */
end_comment

begin_include
include|#
directive|include
file|"libgomp.h"
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function
name|void
modifier|*
name|gomp_malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
name|void
modifier|*
name|ret
init|=
name|malloc
argument_list|(
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|==
name|NULL
condition|)
name|gomp_fatal
argument_list|(
literal|"Out of memory allocating %lu bytes"
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|size
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|gomp_malloc_cleared
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
name|void
modifier|*
name|ret
init|=
name|calloc
argument_list|(
literal|1
argument_list|,
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|==
name|NULL
condition|)
name|gomp_fatal
argument_list|(
literal|"Out of memory allocating %lu bytes"
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|size
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|gomp_realloc
parameter_list|(
name|void
modifier|*
name|old
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|void
modifier|*
name|ret
init|=
name|realloc
argument_list|(
name|old
argument_list|,
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|==
name|NULL
condition|)
name|gomp_fatal
argument_list|(
literal|"Out of memory allocating %lu bytes"
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|size
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

end_unit

