begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2012,2016 Microsoft Corp.  * Copyright (c) 2012 NetApp Inc.  * Copyright (c) 2012 Citrix Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMBUS_ICVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMBUS_ICVAR_H_
end_define

begin_include
include|#
directive|include
file|<dev/hyperv/include/hyperv.h>
end_include

begin_include
include|#
directive|include
file|<dev/hyperv/include/vmbus.h>
end_include

begin_struct
struct|struct
name|vmbus_ic_softc
block|{
name|device_t
name|ic_dev
decl_stmt|;
name|uint8_t
modifier|*
name|ic_buf
decl_stmt|;
name|int
name|ic_buflen
decl_stmt|;
name|uint32_t
name|ic_fwver
decl_stmt|;
comment|/* framework version */
name|uint32_t
name|ic_msgver
decl_stmt|;
comment|/* message version */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vmbus_ic_desc
block|{
specifier|const
name|struct
name|hyperv_guid
name|ic_guid
decl_stmt|;
specifier|const
name|char
modifier|*
name|ic_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VMBUS_IC_DESC_END
value|{ .ic_desc = NULL }
end_define

begin_function_decl
name|int
name|vmbus_ic_attach
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|vmbus_chan_callback_t
name|cb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_ic_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_ic_probe
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|vmbus_ic_desc
name|descs
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_ic_negomsg
parameter_list|(
name|struct
name|vmbus_ic_softc
modifier|*
name|sc
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
modifier|*
name|dlen
parameter_list|,
name|uint32_t
name|fw_ver
parameter_list|,
name|uint32_t
name|msg_ver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_ic_sendresp
parameter_list|(
name|struct
name|vmbus_ic_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|dlen
parameter_list|,
name|uint64_t
name|xactid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VMBUS_ICVAR_H_ */
end_comment

end_unit

