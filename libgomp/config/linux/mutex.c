begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by Richard Henderson<rth@redhat.com>.     This file is part of the GNU OpenMP Library (libgomp).     Libgomp is free software; you can redistribute it and/or modify it    under the terms of the GNU Lesser General Public License as published by    the Free Software Foundation; either version 2.1 of the License, or    (at your option) any later version.     Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS    FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for    more details.     You should have received a copy of the GNU Lesser General Public License     along with libgomp; see the file COPYING.LIB.  If not, write to the    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files, some    of which are compiled with GCC, to produce an executable, this library    does not by itself cause the resulting executable to be covered by the    GNU General Public License.  This exception does not however invalidate    any other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_comment
comment|/* This is a Linux specific implementation of a mutex synchronization    mechanism for libgomp.  This type is private to the library.  This    implementation uses atomic instructions and the futex syscall.  */
end_comment

begin_include
include|#
directive|include
file|"libgomp.h"
end_include

begin_include
include|#
directive|include
file|"futex.h"
end_include

begin_function
name|void
name|gomp_mutex_lock_slow
parameter_list|(
name|gomp_mutex_t
modifier|*
name|mutex
parameter_list|)
block|{
do|do
block|{
name|int
name|oldval
init|=
name|__sync_val_compare_and_swap
argument_list|(
name|mutex
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
if|if
condition|(
name|oldval
operator|!=
literal|0
condition|)
name|futex_wait
argument_list|(
name|mutex
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|!
name|__sync_bool_compare_and_swap
argument_list|(
name|mutex
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|)
condition|)
do|;
block|}
end_function

begin_function
name|void
name|gomp_mutex_unlock_slow
parameter_list|(
name|gomp_mutex_t
modifier|*
name|mutex
parameter_list|)
block|{
name|futex_wake
argument_list|(
name|mutex
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

