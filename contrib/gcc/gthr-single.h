begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Threads compatibily routines for libgcc2.  */
end_comment

begin_comment
comment|/* Compile this one with gcc.  */
end_comment

begin_comment
comment|/* Copyright (C) 1997 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files,    some of which are compiled with GCC, to produce an executable,    this library does not by itself cause the resulting executable    to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__gthr_single_h
end_ifndef

begin_define
define|#
directive|define
name|__gthr_single_h
end_define

begin_comment
comment|/* Just provide compatibility for mutex handling. */
end_comment

begin_typedef
typedef|typedef
name|int
name|__gthread_mutex_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__GTHREAD_MUTEX_INIT
value|0
end_define

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_active_p
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|inline
name|int
name|__gthread_mutex_lock
argument_list|(
name|__gthread_mutex_t
operator|*
name|mutex
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
argument_list|)
block|{
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|inline
name|int
name|__gthread_mutex_trylock
argument_list|(
name|__gthread_mutex_t
operator|*
name|mutex
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
argument_list|)
block|{
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|inline
name|int
name|__gthread_mutex_unlock
argument_list|(
name|__gthread_mutex_t
operator|*
name|mutex
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
argument_list|)
block|{
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __gthr_single_h */
end_comment

end_unit

