begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by Richard Henderson<rth@redhat.com>.     This file is part of the GNU OpenMP Library (libgomp).     Libgomp is free software; you can redistribute it and/or modify it    under the terms of the GNU Lesser General Public License as published by    the Free Software Foundation; either version 2.1 of the License, or    (at your option) any later version.     Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS    FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for    more details.     You should have received a copy of the GNU Lesser General Public License     along with libgomp; see the file COPYING.LIB.  If not, write to the    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files, some    of which are compiled with GCC, to produce an executable, this library    does not by itself cause the resulting executable to be covered by the    GNU General Public License.  This exception does not however invalidate    any other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_comment
comment|/* This file handles the BARRIER construct.  */
end_comment

begin_include
include|#
directive|include
file|"libgomp.h"
end_include

begin_function
name|void
name|GOMP_barrier
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|gomp_thread
modifier|*
name|thr
init|=
name|gomp_thread
argument_list|()
decl_stmt|;
name|struct
name|gomp_team
modifier|*
name|team
init|=
name|thr
operator|->
name|ts
operator|.
name|team
decl_stmt|;
comment|/* It is legal to have orphaned barriers.  */
if|if
condition|(
name|team
operator|==
name|NULL
condition|)
return|return;
name|gomp_barrier_wait
argument_list|(
operator|&
name|team
operator|->
name|barrier
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

