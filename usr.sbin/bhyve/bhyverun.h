begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FBSDRUN_H_
end_ifndef

begin_define
define|#
directive|define
name|_FBSDRUN_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CTASSERT
end_ifndef

begin_comment
comment|/* Allow lint to override */
end_comment

begin_define
define|#
directive|define
name|CTASSERT
parameter_list|(
name|x
parameter_list|)
value|_CTASSERT(x, __LINE__)
end_define

begin_define
define|#
directive|define
name|_CTASSERT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__CTASSERT(x, y)
end_define

begin_define
define|#
directive|define
name|__CTASSERT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|typedef char __assert ## y[(x) ? 1 : -1]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VMEXIT_CONTINUE
value|1
end_define

begin_comment
comment|/* continue from next instruction */
end_comment

begin_define
define|#
directive|define
name|VMEXIT_RESTART
value|2
end_define

begin_comment
comment|/* restart current instruction */
end_comment

begin_define
define|#
directive|define
name|VMEXIT_ABORT
value|3
end_define

begin_comment
comment|/* abort the vm run loop */
end_comment

begin_define
define|#
directive|define
name|VMEXIT_RESET
value|4
end_define

begin_comment
comment|/* guest machine has reset */
end_comment

begin_define
define|#
directive|define
name|VMEXIT_POWEROFF
value|5
end_define

begin_comment
comment|/* guest machine has powered off */
end_comment

begin_struct_decl
struct_decl|struct
name|vmctx
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|guest_ncpus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|guest_uuid_str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|vmname
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
modifier|*
name|paddr_guest2host
parameter_list|(
name|struct
name|vmctx
modifier|*
name|ctx
parameter_list|,
name|uintptr_t
name|addr
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fbsdrun_set_capabilities
parameter_list|(
name|struct
name|vmctx
modifier|*
name|ctx
parameter_list|,
name|int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fbsdrun_addcpu
parameter_list|(
name|struct
name|vmctx
modifier|*
name|ctx
parameter_list|,
name|int
name|fromcpu
parameter_list|,
name|int
name|newcpu
parameter_list|,
name|uint64_t
name|rip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fbsdrun_muxed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fbsdrun_vmexit_on_hlt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fbsdrun_vmexit_on_pause
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fbsdrun_disable_x2apic
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fbsdrun_virtio_msix
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

