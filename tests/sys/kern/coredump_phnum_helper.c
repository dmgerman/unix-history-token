begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016, Conrad Meyer  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * 1. Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/*  * This program is intended to create a bunch of segment mappings, then dump  * core.  */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
name|__unused
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
name|__unused
parameter_list|)
block|{
name|void
modifier|*
name|v
decl_stmt|;
name|unsigned
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|UINT16_MAX
operator|+
literal|1000
condition|;
name|i
operator|++
control|)
block|{
comment|/* 		 * Alternate protections; otherwise the kernel will just extend 		 * the adjacent same-protection previous mapping. 		 */
name|v
operator|=
name|mmap
argument_list|(
name|NULL
argument_list|,
name|PAGE_SIZE
argument_list|,
operator|(
operator|(
operator|(
name|i
operator|%
literal|2
operator|)
operator|==
literal|0
operator|)
condition|?
name|PROT_READ
else|:
literal|0
operator|)
operator||
name|PROT_WRITE
argument_list|,
name|MAP_ANON
operator||
name|MAP_PRIVATE
argument_list|,
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|v
operator|==
name|MAP_FAILED
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"mmap"
argument_list|)
expr_stmt|;
block|}
comment|/* Dump core. */
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

