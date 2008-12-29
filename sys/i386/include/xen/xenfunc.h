begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 2004,2005 Kip Macy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XEN_XENFUNC_H_
end_ifndef

begin_define
define|#
directive|define
name|_XEN_XENFUNC_H_
end_define

begin_include
include|#
directive|include
file|<machine/xen/xen-os.h>
end_include

begin_include
include|#
directive|include
file|<xen/hypervisor.h>
end_include

begin_include
include|#
directive|include
file|<machine/xen/xenpmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/segments.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_define
define|#
directive|define
name|BKPT
value|__asm__("int3");
end_define

begin_define
define|#
directive|define
name|XPQ_CALL_DEPTH
value|5
end_define

begin_define
define|#
directive|define
name|XPQ_CALL_COUNT
value|2
end_define

begin_define
define|#
directive|define
name|PG_PRIV
value|PG_AVAIL3
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|pt_ref
decl_stmt|;
name|unsigned
name|long
name|pt_eip
index|[
name|XPQ_CALL_COUNT
index|]
index|[
name|XPQ_CALL_DEPTH
index|]
decl_stmt|;
block|}
name|pteinfo_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|pteinfo_t
modifier|*
name|pteinfo_list
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|XENDEBUG_LOW
end_ifdef

begin_define
define|#
directive|define
name|__PRINTK
parameter_list|(
name|x
parameter_list|)
value|printk x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__PRINTK
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|xen_setbootenv
parameter_list|(
name|char
modifier|*
name|cmd_line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xen_boothowto
parameter_list|(
name|char
modifier|*
name|envp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_xen_machphys_update
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|vm_paddr_t
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|xen_machphys_update
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|_xen_machphys_update((a), (b), __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xen_machphys_update
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|_xen_machphys_update((a), (b), NULL, 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|xen_update_descriptor
parameter_list|(
name|union
name|descriptor
modifier|*
parameter_list|,
name|union
name|descriptor
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|balloon_lock
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|balloon_lock
parameter_list|(
name|__flags
parameter_list|)
value|mtx_lock_irqsave(&balloon_lock, __flags)
end_define

begin_define
define|#
directive|define
name|balloon_unlock
parameter_list|(
name|__flags
parameter_list|)
value|mtx_unlock_irqrestore(&balloon_lock, __flags)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|balloon_lock
parameter_list|(
name|__flags
parameter_list|)
value|__flags = 1
end_define

begin_define
define|#
directive|define
name|balloon_unlock
parameter_list|(
name|__flags
parameter_list|)
value|__flags = 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XEN_XENFUNC_H_ */
end_comment

end_unit

