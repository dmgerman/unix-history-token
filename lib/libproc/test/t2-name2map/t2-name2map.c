begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010 The FreeBSD Foundation   * All rights reserved.   *   * This software was developed by Rui Paulo under sponsorship from the  * FreeBSD Foundation.   *    * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<libproc.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|prmap_t
modifier|*
name|map
init|=
name|NULL
decl_stmt|;
name|struct
name|proc_handle
modifier|*
name|phdl
decl_stmt|;
name|proc_create
argument_list|(
literal|"./t2-name2map"
argument_list|,
name|argv
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
operator|&
name|phdl
argument_list|)
expr_stmt|;
name|map
operator|=
name|proc_name2map
argument_list|(
name|phdl
argument_list|,
literal|"ld-elf.so.1"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|map
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

