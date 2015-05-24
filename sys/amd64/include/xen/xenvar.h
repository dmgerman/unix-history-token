begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Kip Macy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XENVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|XENVAR_H_
end_define

begin_define
define|#
directive|define
name|XBOOTUP
value|0x1
end_define

begin_define
define|#
directive|define
name|XPMAP
value|0x2
end_define

begin_decl_stmt
specifier|extern
name|int
name|xendebug_flags
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOXENDEBUG
end_ifndef

begin_define
define|#
directive|define
name|XENPRINTF
value|printk
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XENPRINTF
value|printf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<xen/features.h>
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|TRACE_ENTER
value|XENPRINTF("(file=%s, line=%d) entered %s\n", __FILE__, __LINE__, __FUNCTION__)
end_define

begin_define
define|#
directive|define
name|TRACE_EXIT
value|XENPRINTF("(file=%s, line=%d) exiting %s\n", __FILE__, __LINE__, __FUNCTION__)
end_define

begin_define
define|#
directive|define
name|TRACE_DEBUG
parameter_list|(
name|argflags
parameter_list|,
name|_f
parameter_list|,
name|_a
modifier|...
parameter_list|)
define|\
value|if (xendebug_flags& argflags) XENPRINTF("(file=%s, line=%d) " _f "\n", __FILE__, __LINE__, ## _a);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TRACE_ENTER
end_define

begin_define
define|#
directive|define
name|TRACE_EXIT
end_define

begin_define
define|#
directive|define
name|TRACE_DEBUG
parameter_list|(
name|argflags
parameter_list|,
name|_f
parameter_list|,
name|_a
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|vtomach
parameter_list|(
name|va
parameter_list|)
value|pmap_kextract((vm_offset_t) (va))
end_define

begin_function_decl
name|void
name|xpq_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xen_create_contiguous_region
parameter_list|(
name|vm_page_t
name|pages
parameter_list|,
name|int
name|npages
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xen_destroy_contiguous_region
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|int
name|npages
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

