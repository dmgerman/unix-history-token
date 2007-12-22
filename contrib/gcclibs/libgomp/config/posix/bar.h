begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by Richard Henderson<rth@redhat.com>.     This file is part of the GNU OpenMP Library (libgomp).     Libgomp is free software; you can redistribute it and/or modify it    under the terms of the GNU Lesser General Public License as published by    the Free Software Foundation; either version 2.1 of the License, or    (at your option) any later version.     Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS    FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for    more details.     You should have received a copy of the GNU Lesser General Public License     along with libgomp; see the file COPYING.LIB.  If not, write to the    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files, some    of which are compiled with GCC, to produce an executable, this library    does not by itself cause the resulting executable to be covered by the    GNU General Public License.  This exception does not however invalidate    any other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_comment
comment|/* This is the default implementation of a barrier synchronization mechanism    for libgomp.  This type is private to the library.  Note that we rely on    being able to adjust the barrier count while threads are blocked, so the    POSIX pthread_barrier_t won't work.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOMP_BARRIER_H
end_ifndef

begin_define
define|#
directive|define
name|GOMP_BARRIER_H
value|1
end_define

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|gomp_mutex_t
name|mutex1
decl_stmt|;
ifndef|#
directive|ifndef
name|HAVE_SYNC_BUILTINS
name|gomp_mutex_t
name|mutex2
decl_stmt|;
endif|#
directive|endif
name|gomp_sem_t
name|sem1
decl_stmt|;
name|gomp_sem_t
name|sem2
decl_stmt|;
name|unsigned
name|total
decl_stmt|;
name|unsigned
name|arrived
decl_stmt|;
block|}
name|gomp_barrier_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gomp_barrier_init
parameter_list|(
name|gomp_barrier_t
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gomp_barrier_reinit
parameter_list|(
name|gomp_barrier_t
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gomp_barrier_destroy
parameter_list|(
name|gomp_barrier_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gomp_barrier_wait
parameter_list|(
name|gomp_barrier_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gomp_barrier_wait_end
parameter_list|(
name|gomp_barrier_t
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|bool
name|gomp_barrier_wait_start
parameter_list|(
name|gomp_barrier_t
modifier|*
name|bar
parameter_list|)
block|{
name|gomp_mutex_lock
argument_list|(
operator|&
name|bar
operator|->
name|mutex1
argument_list|)
expr_stmt|;
return|return
operator|++
name|bar
operator|->
name|arrived
operator|==
name|bar
operator|->
name|total
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GOMP_BARRIER_H */
end_comment

end_unit

