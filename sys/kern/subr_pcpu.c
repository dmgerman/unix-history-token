begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Wind River Systems, Inc.  * All rights reserved.  * Written by: John Baldwin<jhb@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This module provides MI support for per-cpu data.  *  * Each architecture determines the mapping of logical CPU IDs to physical  * CPUs.  The requirements of this mapping are as follows:  *  - Logical CPU IDs must reside in the range 0 ... MAXCPU - 1.  *  - The mapping is not required to be dense.  That is, there may be  *    gaps in the mappings.  *  - The platform sets the value of MAXCPU in<machine/param.h>.  *  - It is suggested, but not required, that in the non-SMP case, the  *    platform define MAXCPU to be 1 and define the logical ID of the  *    sole CPU as 0.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_decl_stmt
specifier|static
name|struct
name|globaldata
modifier|*
name|cpuid_to_globaldata
index|[
name|MAXCPU
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cpuhead
name|cpuhead
init|=
name|SLIST_HEAD_INITIALIZER
argument_list|(
name|cpuhead
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Register a struct globaldata.  */
end_comment

begin_function
name|void
name|globaldata_register
parameter_list|(
name|struct
name|globaldata
modifier|*
name|globaldata
parameter_list|)
block|{
name|KASSERT
argument_list|(
name|globaldata
operator|->
name|gd_cpuid
operator|>=
literal|0
operator|&&
name|globaldata
operator|->
name|gd_cpuid
operator|<
name|MAXCPU
argument_list|,
operator|(
literal|"globaldata_register: invalid cpuid"
operator|)
argument_list|)
expr_stmt|;
name|cpuid_to_globaldata
index|[
name|globaldata
operator|->
name|gd_cpuid
index|]
operator|=
name|globaldata
expr_stmt|;
name|SLIST_INSERT_HEAD
argument_list|(
operator|&
name|cpuhead
argument_list|,
name|globaldata
argument_list|,
name|gd_allcpu
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Locate a struct globaldata by cpu id.  */
end_comment

begin_function
name|struct
name|globaldata
modifier|*
name|globaldata_find
parameter_list|(
name|u_int
name|cpuid
parameter_list|)
block|{
return|return
operator|(
name|cpuid_to_globaldata
index|[
name|cpuid
index|]
operator|)
return|;
block|}
end_function

end_unit

