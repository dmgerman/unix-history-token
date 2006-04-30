begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: kvm_powerpc.c,v 1.4 1998/02/03 06:50:07 mycroft Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1996 Wolfgang Solfrank.  * Copyright (C) 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * PowerPC machine dependent routines for kvm.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<kvm.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"kvm_private.h"
end_include

begin_function
name|void
name|_kvm_freevtop
parameter_list|(
name|kd
parameter_list|)
name|kvm_t
modifier|*
name|kd
decl_stmt|;
block|{
if|if
condition|(
name|kd
operator|->
name|vmst
operator|!=
literal|0
condition|)
name|free
argument_list|(
name|kd
operator|->
name|vmst
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|_kvm_initvtop
parameter_list|(
name|kd
parameter_list|)
name|kvm_t
modifier|*
name|kd
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|_kvm_kvatop
parameter_list|(
name|kd
parameter_list|,
name|va
parameter_list|,
name|pa
parameter_list|)
name|kvm_t
modifier|*
name|kd
decl_stmt|;
name|u_long
name|va
decl_stmt|;
name|off_t
modifier|*
name|pa
decl_stmt|;
block|{
name|_kvm_err
argument_list|(
name|kd
argument_list|,
literal|0
argument_list|,
literal|"vatop not yet implemented!"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|off_t
name|_kvm_pa2off
parameter_list|(
name|kd
parameter_list|,
name|pa
parameter_list|)
name|kvm_t
modifier|*
name|kd
decl_stmt|;
name|u_long
name|pa
decl_stmt|;
block|{
name|_kvm_err
argument_list|(
name|kd
argument_list|,
literal|0
argument_list|,
literal|"pa2off not yet implemented!"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Machine-dependent initialization for ALL open kvm descriptors,  * not just those for a kernel crash dump.  Some architectures  * have to deal with these NOT being constants!  (i.e. m68k)  */
end_comment

begin_function
name|int
name|_kvm_mdopen
parameter_list|(
name|kd
parameter_list|)
name|kvm_t
modifier|*
name|kd
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|FBSD_NOT_YET
name|kd
operator|->
name|usrstack
operator|=
name|USRSTACK
expr_stmt|;
name|kd
operator|->
name|min_uva
operator|=
name|VM_MIN_ADDRESS
expr_stmt|;
name|kd
operator|->
name|max_uva
operator|=
name|VM_MAXUSER_ADDRESS
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

