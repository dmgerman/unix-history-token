begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2012,2016 Microsoft Corp.  * Copyright (c) 2010-2012 Citrix Inc.  * Copyright (c) 2012 NetApp Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HV_RNDIS_FILTER_H__
end_ifndef

begin_define
define|#
directive|define
name|__HV_RNDIS_FILTER_H__
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<dev/hyperv/netvsc/if_hnvar.h>
end_include

begin_comment
comment|/*  * Externs  */
end_comment

begin_struct_decl
struct_decl|struct
name|hn_rx_ring
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|hv_rf_on_receive
parameter_list|(
name|struct
name|hn_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|hn_rx_ring
modifier|*
name|rxr
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|int
name|dlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_rf_channel_rollup
parameter_list|(
name|struct
name|hn_rx_ring
modifier|*
name|rxr
parameter_list|,
name|struct
name|hn_tx_ring
modifier|*
name|txr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_rf_on_device_add
parameter_list|(
name|struct
name|hn_softc
modifier|*
name|sc
parameter_list|,
name|void
modifier|*
name|additl_info
parameter_list|,
name|int
modifier|*
name|nchan
parameter_list|,
name|struct
name|hn_rx_ring
modifier|*
name|rxr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_rf_on_device_remove
parameter_list|(
name|struct
name|hn_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_rf_on_open
parameter_list|(
name|struct
name|hn_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_rf_on_close
parameter_list|(
name|struct
name|hn_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HV_RNDIS_FILTER_H__ */
end_comment

end_unit

