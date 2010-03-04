begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Michael Smith<msmith@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_comment
comment|/*  * Obtain memory configuration information from the BIOS  */
end_comment

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|"libi386.h"
end_include

begin_include
include|#
directive|include
file|"btxv86.h"
end_include

begin_decl_stmt
name|vm_offset_t
name|memtop
decl_stmt|,
name|memtop_copyin
decl_stmt|,
name|high_heap_base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|bios_basemem
decl_stmt|,
name|bios_extmem
decl_stmt|,
name|high_heap_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The minimum amount of memory to reserve in bios_extmem for the heap.  */
end_comment

begin_define
define|#
directive|define
name|HEAP_MIN
value|(3 * 1024 * 1024)
end_define

begin_function
name|void
name|bios_getmem
parameter_list|(
name|void
parameter_list|)
block|{
name|bios_basemem
operator|=
operator|(
operator|(
operator|*
operator|(
name|u_char
operator|*
operator|)
name|PTOV
argument_list|(
literal|0xA1501
argument_list|)
operator|&
literal|0x07
operator|)
operator|+
literal|1
operator|)
operator|*
literal|128
operator|*
literal|1024
expr_stmt|;
name|bios_extmem
operator|=
operator|*
operator|(
name|u_char
operator|*
operator|)
name|PTOV
argument_list|(
literal|0xA1401
argument_list|)
operator|*
literal|128
operator|*
literal|1024
operator|+
operator|*
operator|(
name|u_int16_t
operator|*
operator|)
name|PTOV
argument_list|(
literal|0xA1594
argument_list|)
operator|*
literal|1024
operator|*
literal|1024
expr_stmt|;
comment|/* Set memtop to actual top of memory */
name|memtop
operator|=
name|memtop_copyin
operator|=
literal|0x100000
operator|+
name|bios_extmem
expr_stmt|;
comment|/*      * If we have extended memory, use the last 3MB of 'extended' memory      * as a high heap candidate.      */
if|if
condition|(
name|bios_extmem
operator|>=
name|HEAP_MIN
condition|)
block|{
name|high_heap_size
operator|=
name|HEAP_MIN
expr_stmt|;
name|high_heap_base
operator|=
name|memtop
operator|-
name|HEAP_MIN
expr_stmt|;
block|}
block|}
end_function

end_unit

