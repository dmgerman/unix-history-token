begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: atomic.h,v 1.1 2002/10/19 12:22:34 bsh Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (C) 2003-2004 Olivier Houchard  * Copyright (C) 1994-1997 Mark Brinicombe  * Copyright (C) 1994 Brini  * All rights reserved.  *  * This code is derived from software written for Brini by Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Brini.  * 4. The name of Brini may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BRINI ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BRINI BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ATOMIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ATOMIC_H_
end_define

begin_include
include|#
directive|include
file|<machine/armreg.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<machine/sysarch.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_include
include|#
directive|include
file|<machine/atomic-v6.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*< armv6 */
end_comment

begin_include
include|#
directive|include
file|<machine/atomic-v4.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Arch>= v6 */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|atomic_load_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|v
parameter_list|)
block|{
return|return
operator|(
operator|*
name|v
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_store_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|dst
parameter_list|,
name|uint32_t
name|src
parameter_list|)
block|{
operator|*
name|dst
operator|=
name|src
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|atomic_load_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|v
parameter_list|)
block|{
return|return
operator|(
operator|*
name|v
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_store_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|dst
parameter_list|,
name|u_long
name|src
parameter_list|)
block|{
operator|*
name|dst
operator|=
name|src
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|atomic_clear_ptr
value|atomic_clear_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_ptr
value|atomic_clear_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_ptr
value|atomic_clear_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_set_ptr
value|atomic_set_32
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_ptr
value|atomic_set_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_ptr
value|atomic_set_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_ptr
value|atomic_fcmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_ptr
value|atomic_fcmpset_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_ptr
value|atomic_fcmpset_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_ptr
value|atomic_cmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_ptr
value|atomic_cmpset_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_ptr
value|atomic_cmpset_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_ptr
value|atomic_load_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_store_ptr
value|atomic_store_32
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_ptr
value|atomic_store_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_swap_ptr
value|atomic_swap_32
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_ptr
value|atomic_readandclear_32
end_define

begin_define
define|#
directive|define
name|atomic_add_int
value|atomic_add_32
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_int
value|atomic_add_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_int
value|atomic_add_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_int
value|atomic_subtract_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_int
value|atomic_subtract_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_int
value|atomic_subtract_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_int
value|atomic_clear_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_int
value|atomic_clear_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_int
value|atomic_clear_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_set_int
value|atomic_set_32
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_int
value|atomic_set_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_int
value|atomic_set_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_int
value|atomic_fcmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_int
value|atomic_fcmpset_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_int
value|atomic_fcmpset_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_int
value|atomic_cmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_int
value|atomic_cmpset_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_int
value|atomic_cmpset_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_fetchadd_int
value|atomic_fetchadd_32
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_int
value|atomic_readandclear_32
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_int
value|atomic_load_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_int
value|atomic_store_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_swap_int
value|atomic_swap_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_ATOMIC_H_ */
end_comment

end_unit

