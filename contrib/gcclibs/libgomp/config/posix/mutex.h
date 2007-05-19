begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by Richard Henderson<rth@redhat.com>.     This file is part of the GNU OpenMP Library (libgomp).     Libgomp is free software; you can redistribute it and/or modify it    under the terms of the GNU Lesser General Public License as published by    the Free Software Foundation; either version 2.1 of the License, or    (at your option) any later version.     Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS    FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for    more details.     You should have received a copy of the GNU Lesser General Public License     along with libgomp; see the file COPYING.LIB.  If not, write to the    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files, some    of which are compiled with GCC, to produce an executable, this library    does not by itself cause the resulting executable to be covered by the    GNU General Public License.  This exception does not however invalidate    any other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_comment
comment|/* This is the default PTHREADS implementation of a mutex synchronization    mechanism for libgomp.  This type is private to the library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOMP_MUTEX_H
end_ifndef

begin_define
define|#
directive|define
name|GOMP_MUTEX_H
value|1
end_define

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_typedef
typedef|typedef
name|pthread_mutex_t
name|gomp_mutex_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GOMP_MUTEX_INIT_0
value|0
end_define

begin_function
specifier|static
specifier|inline
name|void
name|gomp_mutex_init
parameter_list|(
name|gomp_mutex_t
modifier|*
name|mutex
parameter_list|)
block|{
name|pthread_mutex_init
argument_list|(
name|mutex
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|gomp_mutex_lock
parameter_list|(
name|gomp_mutex_t
modifier|*
name|mutex
parameter_list|)
block|{
name|pthread_mutex_lock
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|gomp_mutex_unlock
parameter_list|(
name|gomp_mutex_t
modifier|*
name|mutex
parameter_list|)
block|{
name|pthread_mutex_unlock
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|gomp_mutex_destroy
parameter_list|(
name|gomp_mutex_t
modifier|*
name|mutex
parameter_list|)
block|{
name|pthread_mutex_destroy
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GOMP_MUTEX_H */
end_comment

end_unit

