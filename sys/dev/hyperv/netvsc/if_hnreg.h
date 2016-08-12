begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Microsoft Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_HNREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_HNREG_H_
end_define

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

begin_define
define|#
directive|define
name|HN_NVS_STATUS_OK
value|1
end_define

begin_define
define|#
directive|define
name|HN_NVS_TYPE_INIT
value|1
end_define

begin_define
define|#
directive|define
name|HN_NVS_TYPE_INIT_RESP
value|2
end_define

begin_define
define|#
directive|define
name|HN_NVS_TYPE_NDIS_CONF
value|125
end_define

begin_comment
comment|/*  * Any size less than this one will _not_ work, e.g. hn_nvs_init  * only has 12B valid data, however, if only 12B data were sent,  * Hypervisor would never reply.  */
end_comment

begin_define
define|#
directive|define
name|HN_NVS_REQSIZE_MIN
value|32
end_define

begin_struct
struct|struct
name|hn_nvs_init
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_INIT */
name|uint32_t
name|nvs_ver_min
decl_stmt|;
name|uint32_t
name|nvs_ver_max
decl_stmt|;
name|uint8_t
name|nvs_rsvd
index|[
literal|20
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|hn_nvs_init
argument_list|)
operator|>=
name|HN_NVS_REQSIZE_MIN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|hn_nvs_init_resp
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_INIT_RESP */
name|uint32_t
name|nvs_ver
decl_stmt|;
comment|/* deprecated */
name|uint32_t
name|nvs_rsvd
decl_stmt|;
name|uint32_t
name|nvs_status
decl_stmt|;
comment|/* HN_NVS_STATUS_ */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* No reponse */
end_comment

begin_struct
struct|struct
name|hn_nvs_ndis_conf
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_NDIS_CONF */
name|uint32_t
name|nvs_mtu
decl_stmt|;
name|uint32_t
name|nvs_rsvd
decl_stmt|;
name|uint64_t
name|nvs_caps
decl_stmt|;
comment|/* HN_NVS_NDIS_CONF_ */
name|uint8_t
name|nvs_rsvd1
index|[
literal|12
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|hn_nvs_ndis_conf
argument_list|)
operator|>=
name|HN_NVS_REQSIZE_MIN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|HN_NVS_NDIS_CONF_SRIOV
value|0x0004
end_define

begin_define
define|#
directive|define
name|HN_NVS_NDIS_CONF_VLAN
value|0x0008
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IF_HNREG_H_ */
end_comment

end_unit

