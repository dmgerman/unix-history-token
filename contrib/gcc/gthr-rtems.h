begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RTEMS threads compatibily routines for libgcc2 and libobjc.    by: Rosimildo da Silva( rdasilva@connecttel.com ) */
end_comment

begin_comment
comment|/* Compile this one with gcc.  */
end_comment

begin_comment
comment|/* Copyright (C) 1997, 1999, 2000 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files,    some of which are compiled with GCC, to produce an executable,    this library does not by itself cause the resulting executable    to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_GTHR_RTEMS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_GTHR_RTEMS_H
end_define

begin_define
define|#
directive|define
name|__GTHREADS
value|1
end_define

begin_define
define|#
directive|define
name|__GTHREAD_ONCE_INIT
value|0
end_define

begin_define
define|#
directive|define
name|__GTHREAD_MUTEX_INIT_FUNCTION
value|rtems_gxx_mutex_init
end_define

begin_comment
comment|/* avoid depedency on rtems specific headers */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|__gthread_key_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__gthread_once_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|__gthread_mutex_t
typedef|;
end_typedef

begin_comment
comment|/*  * External functions provided by RTEMS. They are very similar to their POSIX   * counterparts. A "Wrapper API" is being use to avoid dependency on any RTEMS  * header files.  */
end_comment

begin_comment
comment|/* generic per task variables */
end_comment

begin_function_decl
specifier|extern
name|int
name|rtems_gxx_once
parameter_list|(
name|__gthread_once_t
modifier|*
name|once
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rtems_gxx_key_create
parameter_list|(
name|__gthread_key_t
modifier|*
name|key
parameter_list|,
name|void
function_decl|(
modifier|*
name|dtor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rtems_gxx_key_dtor
parameter_list|(
name|__gthread_key_t
name|key
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rtems_gxx_key_delete
parameter_list|(
name|__gthread_key_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|rtems_gxx_getspecific
parameter_list|(
name|__gthread_key_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rtems_gxx_setspecific
parameter_list|(
name|__gthread_key_t
name|key
parameter_list|,
specifier|const
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mutex support */
end_comment

begin_function_decl
specifier|extern
name|void
name|rtems_gxx_mutex_init
parameter_list|(
name|__gthread_mutex_t
modifier|*
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rtems_gxx_mutex_lock
parameter_list|(
name|__gthread_mutex_t
modifier|*
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rtems_gxx_mutex_trylock
parameter_list|(
name|__gthread_mutex_t
modifier|*
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rtems_gxx_mutex_unlock
parameter_list|(
name|__gthread_mutex_t
modifier|*
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* RTEMS threading is always active */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_active_p
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Wrapper calls */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_once
parameter_list|(
name|__gthread_once_t
modifier|*
name|once
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
parameter_list|)
block|{
return|return
name|rtems_gxx_once
argument_list|(
name|once
argument_list|,
name|func
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_key_create
parameter_list|(
name|__gthread_key_t
modifier|*
name|key
parameter_list|,
name|void
function_decl|(
modifier|*
name|dtor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
block|{
return|return
name|rtems_gxx_key_create
argument_list|(
name|key
argument_list|,
name|dtor
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_key_dtor
parameter_list|(
name|__gthread_key_t
name|key
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|rtems_gxx_key_dtor
argument_list|(
name|key
argument_list|,
name|ptr
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_key_delete
parameter_list|(
name|__gthread_key_t
name|key
parameter_list|)
block|{
return|return
name|rtems_gxx_key_delete
argument_list|(
name|key
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|__gthread_getspecific
parameter_list|(
name|__gthread_key_t
name|key
parameter_list|)
block|{
return|return
name|rtems_gxx_getspecific
argument_list|(
name|key
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_setspecific
parameter_list|(
name|__gthread_key_t
name|key
parameter_list|,
specifier|const
name|void
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|rtems_gxx_setspecific
argument_list|(
name|key
argument_list|,
name|ptr
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_mutex_lock
parameter_list|(
name|__gthread_mutex_t
modifier|*
name|mutex
parameter_list|)
block|{
return|return
name|rtems_gxx_mutex_lock
argument_list|(
name|mutex
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_mutex_trylock
parameter_list|(
name|__gthread_mutex_t
modifier|*
name|mutex
parameter_list|)
block|{
return|return
name|rtems_gxx_mutex_trylock
argument_list|(
name|mutex
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_mutex_unlock
parameter_list|(
name|__gthread_mutex_t
modifier|*
name|mutex
parameter_list|)
block|{
return|return
name|rtems_gxx_mutex_unlock
argument_list|(
name|mutex
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_GTHR_RTEMS_H */
end_comment

end_unit

