begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2005, 2006 Free Software Foundation, Inc.    Contributed by Richard Henderson<rth@redhat.com>.     This file is part of the GNU OpenMP Library (libgomp).     Libgomp is free software; you can redistribute it and/or modify it    under the terms of the GNU Lesser General Public License as published by    the Free Software Foundation; either version 2.1 of the License, or    (at your option) any later version.     Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS    FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for    more details.     You should have received a copy of the GNU Lesser General Public License    along with libgomp; see the file COPYING.LIB.  If not, write to the    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files, some    of which are compiled with GCC, to produce an executable, this library    does not by itself cause the resulting executable to be covered by the    GNU General Public License.  This exception does not however invalidate    any other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_comment
comment|/* This is the default POSIX 1003.1b implementation of a semaphore    synchronization mechanism for libgomp.  This type is private to    the library.     This is a bit heavy weight for what we need, in that we're not    interested in sem_wait as a cancelation point, but it's not too    bad for a default.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOMP_SEM_H
end_ifndef

begin_define
define|#
directive|define
name|GOMP_SEM_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ATTRIBUTE_VISIBILITY
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|push
name|(
name|default
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<semaphore.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ATTRIBUTE_VISIBILITY
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|pop
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BROKEN_POSIX_SEMAPHORES
end_ifdef

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_struct
struct|struct
name|gomp_sem
block|{
name|pthread_mutex_t
name|mutex
decl_stmt|;
name|pthread_cond_t
name|cond
decl_stmt|;
name|int
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|gomp_sem
name|gomp_sem_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gomp_sem_init
parameter_list|(
name|gomp_sem_t
modifier|*
name|sem
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gomp_sem_wait
parameter_list|(
name|gomp_sem_t
modifier|*
name|sem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gomp_sem_post
parameter_list|(
name|gomp_sem_t
modifier|*
name|sem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gomp_sem_destroy
parameter_list|(
name|gomp_sem_t
modifier|*
name|sem
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HAVE_BROKEN_POSIX_SEMAPHORES  */
end_comment

begin_typedef
typedef|typedef
name|sem_t
name|gomp_sem_t
typedef|;
end_typedef

begin_function
specifier|static
specifier|inline
name|void
name|gomp_sem_init
parameter_list|(
name|gomp_sem_t
modifier|*
name|sem
parameter_list|,
name|int
name|value
parameter_list|)
block|{
name|sem_init
argument_list|(
name|sem
argument_list|,
literal|0
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|gomp_sem_wait
parameter_list|(
name|gomp_sem_t
modifier|*
name|sem
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|void
name|gomp_sem_post
parameter_list|(
name|gomp_sem_t
modifier|*
name|sem
parameter_list|)
block|{
name|sem_post
argument_list|(
name|sem
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|gomp_sem_destroy
parameter_list|(
name|gomp_sem_t
modifier|*
name|sem
parameter_list|)
block|{
name|sem_destroy
argument_list|(
name|sem
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* doesn't HAVE_BROKEN_POSIX_SEMAPHORES  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GOMP_SEM_H  */
end_comment

end_unit

