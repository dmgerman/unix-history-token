begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994 by Chris Provenzano, proven@mit.edu  * Copyright (c) 1995-1998 by John Birrell<jb@cimlogic.com.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  This product includes software developed by Chris Provenzano.  * 4. The name of Chris Provenzano may not be used to endorse or promote   *	  products derived from this software without specific prior written  *	  permission.  *  * THIS SOFTWARE IS PROVIDED BY CHRIS PROVENZANO ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL CHRIS PROVENZANO BE LIABLE FOR ANY   * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR   * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__PTHREADTYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS__PTHREADTYPES_H_
end_define

begin_comment
comment|/*  * Forward structure definitions.  *  * These are mostly opaque to the user.  */
end_comment

begin_struct_decl
struct_decl|struct
name|pthread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_attr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_cond
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_cond_attr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_mutex
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_mutex_attr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_once
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_rwlock
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_rwlockattr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_barrier
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_barrier_attr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_spinlock
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Primitive system data type definitions required by P1003.1c.  *  * Note that P1003.1c specifies that there are no defined comparison  * or assignment operators for the types pthread_attr_t, pthread_cond_t,  * pthread_condattr_t, pthread_mutex_t, pthread_mutexattr_t.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|pthread
modifier|*
name|pthread_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_attr
modifier|*
name|pthread_attr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_mutex
modifier|*
name|pthread_mutex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_mutex_attr
modifier|*
name|pthread_mutexattr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_cond
modifier|*
name|pthread_cond_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_cond_attr
modifier|*
name|pthread_condattr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|pthread_key_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_once
name|pthread_once_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_rwlock
modifier|*
name|pthread_rwlock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_rwlockattr
modifier|*
name|pthread_rwlockattr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_barrier
modifier|*
name|pthread_barrier_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_barrierattr
modifier|*
name|pthread_barrierattr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_spinlock
modifier|*
name|pthread_spinlock_t
typedef|;
end_typedef

begin_comment
comment|/*  * Additional type definitions:  *  * Note that P1003.1c reserves the prefixes pthread_ and PTHREAD_ for  * use in header symbols.  */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|pthread_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|pthread_startroutine_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Once definitions.  */
end_comment

begin_struct
struct|struct
name|pthread_once
block|{
name|int
name|state
decl_stmt|;
name|pthread_mutex_t
name|mutex
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _SYS__PTHREADTYPES_H_ */
end_comment

end_unit

