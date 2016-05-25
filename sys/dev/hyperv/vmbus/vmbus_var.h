begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Microsoft Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMBUS_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMBUS_VAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus_dma.h>
end_include

begin_include
include|#
directive|include
file|<dev/hyperv/include/hyperv_busdma.h>
end_include

begin_struct
struct|struct
name|vmbus_pcpu_data
block|{
name|u_long
modifier|*
name|intr_cnt
decl_stmt|;
comment|/* Hyper-V interrupt counter */
name|struct
name|vmbus_message
modifier|*
name|message
decl_stmt|;
comment|/* shared messages */
name|uint32_t
name|vcpuid
decl_stmt|;
comment|/* virtual cpuid */
name|int
name|event_flag_cnt
decl_stmt|;
comment|/* # of event flags */
name|union
name|vmbus_event_flags
modifier|*
name|event_flag
decl_stmt|;
comment|/* shared event flags */
comment|/* Rarely used fields */
name|struct
name|hyperv_dma
name|message_dma
decl_stmt|;
comment|/* busdma glue */
name|struct
name|hyperv_dma
name|event_flag_dma
decl_stmt|;
comment|/* busdma glue */
name|struct
name|taskqueue
modifier|*
name|event_tq
decl_stmt|;
comment|/* event taskq */
name|struct
name|taskqueue
modifier|*
name|message_tq
decl_stmt|;
comment|/* message taskq */
name|struct
name|task
name|message_task
decl_stmt|;
comment|/* message task */
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|vmbus_softc
block|{
name|void
function_decl|(
modifier|*
name|vmbus_event_proc
function_decl|)
parameter_list|(
name|struct
name|vmbus_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|struct
name|vmbus_pcpu_data
name|vmbus_pcpu
index|[
name|MAXCPU
index|]
decl_stmt|;
comment|/* Rarely used fields */
name|device_t
name|vmbus_dev
decl_stmt|;
name|int
name|vmbus_idtvec
decl_stmt|;
name|uint32_t
name|vmbus_flags
decl_stmt|;
comment|/* see VMBUS_FLAG_ */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VMBUS_FLAG_ATTACHED
value|0x0001
end_define

begin_comment
comment|/* vmbus was attached */
end_comment

begin_define
define|#
directive|define
name|VMBUS_FLAG_SYNIC
value|0x0002
end_define

begin_comment
comment|/* SynIC was setup */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vmbus_softc
modifier|*
name|vmbus_sc
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|vmbus_softc
operator|*
name|vmbus_get_softc
argument_list|(
argument|void
argument_list|)
block|{
return|return
name|vmbus_sc
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|__inline
name|device_t
name|vmbus_get_device
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|vmbus_sc
operator|->
name|vmbus_dev
return|;
block|}
end_function

begin_define
define|#
directive|define
name|VMBUS_PCPU_GET
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|,
name|cpu
parameter_list|)
value|(sc)->vmbus_pcpu[(cpu)].field
end_define

begin_define
define|#
directive|define
name|VMBUS_PCPU_PTR
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|,
name|cpu
parameter_list|)
value|&(sc)->vmbus_pcpu[(cpu)].field
end_define

begin_function_decl
name|void
name|vmbus_on_channel_open
parameter_list|(
specifier|const
name|struct
name|hv_vmbus_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_event_proc
parameter_list|(
name|struct
name|vmbus_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_event_proc_compat
parameter_list|(
name|struct
name|vmbus_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VMBUS_VAR_H_ */
end_comment

end_unit

