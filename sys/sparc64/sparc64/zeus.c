begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Marius Strobl<marius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/asi.h>
end_include

begin_include
include|#
directive|include
file|<machine/cache.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_comment
comment|/*  * Flush all lines from the level 1 caches.  */
end_comment

begin_function
name|void
name|zeus_cache_flush
parameter_list|(
name|void
parameter_list|)
block|{
name|stxa_sync
argument_list|(
literal|0
argument_list|,
name|ASI_FLUSH_L1I
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Flush a physical page from the data cache.  Data cache consistency is  * maintained by hardware.  */
end_comment

begin_function
name|void
name|zeus_dcache_page_inval
parameter_list|(
name|vm_paddr_t
name|spa
name|__unused
parameter_list|)
block|{  }
end_function

begin_comment
comment|/*  * Flush a physical page from the intsruction cache.  Instruction cache  * consistency is maintained by hardware.  */
end_comment

begin_function
name|void
name|zeus_icache_page_inval
parameter_list|(
name|vm_paddr_t
name|pa
name|__unused
parameter_list|)
block|{  }
end_function

end_unit

