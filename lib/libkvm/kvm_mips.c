begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2006 Bruce M. Simpson.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bruce M. Simpson.  * 4. The name of Bruce M. Simpson may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BRUCE M. SIMPSON ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BRUCE M. SIMPSON BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * MIPS machine dependent routines for kvm.  */
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
file|<sys/elf32.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/pmap.h>
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
name|kvm_t
modifier|*
name|kd
parameter_list|)
block|{
name|_kvm_err
argument_list|(
name|kd
argument_list|,
literal|0
argument_list|,
literal|"Unimplemented function"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|_kvm_initvtop
parameter_list|(
name|kvm_t
modifier|*
name|kd
parameter_list|)
block|{
name|_kvm_err
argument_list|(
name|kd
argument_list|,
literal|0
argument_list|,
literal|"Unimplemented function"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|_kvm_kvatop
parameter_list|(
name|kvm_t
modifier|*
name|kd
parameter_list|,
name|u_long
name|va
name|__unused
parameter_list|,
name|off_t
modifier|*
name|pa
name|__unused
parameter_list|)
block|{
name|_kvm_err
argument_list|(
name|kd
argument_list|,
literal|0
argument_list|,
literal|"Unimplemented function"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
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
name|_kvm_err
argument_list|(
name|kd
argument_list|,
literal|0
argument_list|,
literal|"Unimplemented function"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

