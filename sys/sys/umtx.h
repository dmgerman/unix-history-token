begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002, Jeffrey Roberson<jeff@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_UMTX_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_UMTX_H_
end_define

begin_comment
comment|/*   * See pthread_*  */
end_comment

begin_define
define|#
directive|define
name|UMTX_UNOWNED
value|NULL
end_define

begin_define
define|#
directive|define
name|UMTX_CONTESTED
value|0x1
end_define

begin_struct
struct|struct
name|umtx
block|{
name|thr_id_t
name|u_owner
decl_stmt|;
comment|/* Owner of the mutex. */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/*  * System calls for acquiring and releasing contested mutexes.  */
end_comment

begin_function_decl
name|int
name|_umtx_lock
parameter_list|(
name|struct
name|umtx
modifier|*
name|mtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_umtx_unlock
parameter_list|(
name|struct
name|umtx
modifier|*
name|mtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Standard api.  Try uncontested acquire/release and asks the  * kernel to resolve failures.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|umtx_lock
parameter_list|(
name|struct
name|umtx
modifier|*
name|umtx
parameter_list|,
name|thr_id_t
name|id
parameter_list|)
block|{
if|if
condition|(
name|atomic_cmpset_acq_ptr
argument_list|(
operator|&
name|umtx
operator|->
name|u_owner
argument_list|,
name|UMTX_UNOWNED
argument_list|,
name|id
argument_list|)
operator|==
literal|0
condition|)
if|if
condition|(
name|_umtx_lock
argument_list|(
name|umtx
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
name|errno
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|umtx_trylock
parameter_list|(
name|struct
name|umtx
modifier|*
name|umtx
parameter_list|,
name|thr_id_t
name|id
parameter_list|)
block|{
if|if
condition|(
name|atomic_cmpset_acq_ptr
argument_list|(
operator|&
name|umtx
operator|->
name|u_owner
argument_list|,
name|UMTX_UNOWNED
argument_list|,
name|id
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|EBUSY
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|umtx_unlock
parameter_list|(
name|struct
name|umtx
modifier|*
name|umtx
parameter_list|,
name|thr_id_t
name|id
parameter_list|)
block|{
if|if
condition|(
name|atomic_cmpset_rel_ptr
argument_list|(
operator|&
name|umtx
operator|->
name|u_owner
argument_list|,
name|id
argument_list|,
name|UMTX_UNOWNED
argument_list|)
operator|==
literal|0
condition|)
if|if
condition|(
name|_umtx_unlock
argument_list|(
name|umtx
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
name|errno
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_UMTX_H_ */
end_comment

end_unit

