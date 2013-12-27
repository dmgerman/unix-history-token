begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2012 Microsoft Corp.  * Copyright (c) 2012 NetApp Inc.  * Copyright (c) 2012 Citrix Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KVP_H
end_ifndef

begin_define
define|#
directive|define
name|_KVP_H
end_define

begin_comment
comment|/*  * An implementation of HyperV key value pair (KVP) functionality for FreeBSD   *  */
end_comment

begin_comment
comment|/*  * Maximum value size - used for both key names and value data, and includes  * any applicable NULL terminators.  *  * Note:  This limit is somewhat arbitrary, but falls easily within what is  * supported for all native guests (back to Win 2000) and what is reasonable  * for the IC KVP exchange functionality.  Note that Windows Me/98/95 are  * limited to 255 character key names.  *  * MSDN recommends not storing data values larger than 2048 bytes in the  * registry.  *  * Note:  This value is used in defining the KVP exchange message - this value  * cannot be modified without affecting the message size and compatibility.  */
end_comment

begin_comment
comment|/*  * bytes, including any null terminators  */
end_comment

begin_define
define|#
directive|define
name|HV_KVP_EXCHANGE_MAX_VALUE_SIZE
value|(2048)
end_define

begin_comment
comment|/*  * Maximum key size - the registry limit for the length of an entry name  * is 256 characters, including the null terminator  */
end_comment

begin_define
define|#
directive|define
name|HV_KVP_EXCHANGE_MAX_KEY_SIZE
value|(512)
end_define

begin_comment
comment|/*  * In FreeBSD, we implement the KVP functionality in two components:  * 1) The kernel component which is packaged as part of the hv_utils driver  * is responsible for communicating with the host and responsible for  * implementing the host/guest protocol. 2) A user level daemon that is  * responsible for data gathering.  *  * Host/Guest Protocol: The host iterates over an index and expects the guest  * to assign a key name to the index and also return the value corresponding to  * the key. The host will have atmost one KVP transaction outstanding at any  * given point in time. The host side iteration stops when the guest returns  * an error. Microsoft has specified the following mapping of key names to  * host specified index:  *  *  Index		Key Name  *	0		FullyQualifiedDomainName  *	1		IntegrationServicesVersion  *	2		NetworkAddressIPv4  *	3		NetworkAddressIPv6  *	4		OSBuildNumber  *	5		OSName  *	6		OSMajorVersion  *	7		OSMinorVersion  *	8		OSVersion  *	9		ProcessorArchitecture  *  * The Windows host expects the Key Name and Key Value to be encoded in utf16.  *  * Guest Kernel/KVP Daemon Protocol: As noted earlier, we implement all of the  * data gathering functionality in a user mode daemon. The user level daemon  * is also responsible for binding the key name to the index as well. The  * kernel and user-level daemon communicate using a connector channel.  *  * The user mode component first registers with the  * the kernel component. Subsequently, the kernel component requests, data  * for the specified keys. In response to this message the user mode component  * fills in the value corresponding to the specified key. We overload the  * sequence field in the cn_msg header to define our KVP message types.  *  *  * The kernel component simply acts as a conduit for communication between the  * Windows host and the user-level daemon. The kernel component passes up the  * index received from the Host to the user-level daemon. If the index is  * valid (supported), the corresponding key as well as its  * value (both are strings) is returned. If the index is invalid  * (not supported), a NULL key string is returned.  */
end_comment

begin_comment
comment|/*  * Registry value types.  */
end_comment

begin_define
define|#
directive|define
name|HV_REG_SZ
value|1
end_define

begin_define
define|#
directive|define
name|HV_REG_U32
value|4
end_define

begin_define
define|#
directive|define
name|HV_REG_U64
value|8
end_define

begin_comment
comment|/*  * Daemon code not supporting IP injection (legacy daemon).  */
end_comment

begin_define
define|#
directive|define
name|HV_KVP_OP_REGISTER
value|4
end_define

begin_comment
comment|/*  * Daemon code supporting IP injection.  * The KVP opcode field is used to communicate the  * registration information; so define a namespace that  * will be distinct from the host defined KVP opcode.  */
end_comment

begin_define
define|#
directive|define
name|KVP_OP_REGISTER1
value|100
end_define

begin_enum
enum|enum
name|hv_kvp_exchg_op
block|{
name|HV_KVP_OP_GET
init|=
literal|0
block|,
name|HV_KVP_OP_SET
block|,
name|HV_KVP_OP_DELETE
block|,
name|HV_KVP_OP_ENUMERATE
block|,
name|HV_KVP_OP_GET_IP_INFO
block|,
name|HV_KVP_OP_SET_IP_INFO
block|,
name|HV_KVP_OP_COUNT
comment|/* Number of operations, must be last. */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|hv_kvp_exchg_pool
block|{
name|HV_KVP_POOL_EXTERNAL
init|=
literal|0
block|,
name|HV_KVP_POOL_GUEST
block|,
name|HV_KVP_POOL_AUTO
block|,
name|HV_KVP_POOL_AUTO_EXTERNAL
block|,
name|HV_KVP_POOL_AUTO_INTERNAL
block|,
name|HV_KVP_POOL_COUNT
comment|/* Number of pools, must be last. */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Some Hyper-V status codes.  */
end_comment

begin_define
define|#
directive|define
name|HV_KVP_S_OK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HV_KVP_E_FAIL
value|0x80004005
end_define

begin_define
define|#
directive|define
name|HV_KVP_S_CONT
value|0x80070103
end_define

begin_define
define|#
directive|define
name|HV_ERROR_NOT_SUPPORTED
value|0x80070032
end_define

begin_define
define|#
directive|define
name|HV_ERROR_MACHINE_LOCKED
value|0x800704F7
end_define

begin_define
define|#
directive|define
name|HV_ERROR_DEVICE_NOT_CONNECTED
value|0x8007048F
end_define

begin_define
define|#
directive|define
name|HV_INVALIDARG
value|0x80070057
end_define

begin_define
define|#
directive|define
name|HV_KVP_GUID_NOTFOUND
value|0x80041002
end_define

begin_define
define|#
directive|define
name|ADDR_FAMILY_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|ADDR_FAMILY_IPV4
value|0x01
end_define

begin_define
define|#
directive|define
name|ADDR_FAMILY_IPV6
value|0x02
end_define

begin_define
define|#
directive|define
name|MAX_ADAPTER_ID_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|MAX_IP_ADDR_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|MAX_GATEWAY_SIZE
value|512
end_define

begin_struct
struct|struct
name|hv_kvp_ipaddr_value
block|{
name|uint16_t
name|adapter_id
index|[
name|MAX_ADAPTER_ID_SIZE
index|]
decl_stmt|;
name|uint8_t
name|addr_family
decl_stmt|;
name|uint8_t
name|dhcp_enabled
decl_stmt|;
name|uint16_t
name|ip_addr
index|[
name|MAX_IP_ADDR_SIZE
index|]
decl_stmt|;
name|uint16_t
name|sub_net
index|[
name|MAX_IP_ADDR_SIZE
index|]
decl_stmt|;
name|uint16_t
name|gate_way
index|[
name|MAX_GATEWAY_SIZE
index|]
decl_stmt|;
name|uint16_t
name|dns_addr
index|[
name|MAX_IP_ADDR_SIZE
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|hv_kvp_hdr
block|{
name|uint8_t
name|operation
decl_stmt|;
name|uint8_t
name|pool
decl_stmt|;
name|uint16_t
name|pad
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|hv_kvp_exchg_msg_value
block|{
name|uint32_t
name|value_type
decl_stmt|;
name|uint32_t
name|key_size
decl_stmt|;
name|uint32_t
name|value_size
decl_stmt|;
name|uint8_t
name|key
index|[
name|HV_KVP_EXCHANGE_MAX_KEY_SIZE
index|]
decl_stmt|;
union|union
block|{
name|uint8_t
name|value
index|[
name|HV_KVP_EXCHANGE_MAX_VALUE_SIZE
index|]
decl_stmt|;
name|uint32_t
name|value_u32
decl_stmt|;
name|uint64_t
name|value_u64
decl_stmt|;
block|}
name|msg_value
union|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|hv_kvp_msg_enumerate
block|{
name|uint32_t
name|index
decl_stmt|;
name|struct
name|hv_kvp_exchg_msg_value
name|data
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|hv_kvp_msg_get
block|{
name|struct
name|hv_kvp_exchg_msg_value
name|data
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|hv_kvp_msg_set
block|{
name|struct
name|hv_kvp_exchg_msg_value
name|data
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|hv_kvp_msg_delete
block|{
name|uint32_t
name|key_size
decl_stmt|;
name|uint8_t
name|key
index|[
name|HV_KVP_EXCHANGE_MAX_KEY_SIZE
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|hv_kvp_register
block|{
name|uint8_t
name|version
index|[
name|HV_KVP_EXCHANGE_MAX_KEY_SIZE
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|hv_kvp_msg
block|{
union|union
block|{
name|struct
name|hv_kvp_hdr
name|kvp_hdr
decl_stmt|;
name|int
name|error
decl_stmt|;
block|}
name|hdr
union|;
union|union
block|{
name|struct
name|hv_kvp_msg_get
name|kvp_get
decl_stmt|;
name|struct
name|hv_kvp_msg_set
name|kvp_set
decl_stmt|;
name|struct
name|hv_kvp_msg_delete
name|kvp_delete
decl_stmt|;
name|struct
name|hv_kvp_msg_enumerate
name|kvp_enum_data
decl_stmt|;
name|struct
name|hv_kvp_ipaddr_value
name|kvp_ip_val
decl_stmt|;
name|struct
name|hv_kvp_register
name|kvp_register
decl_stmt|;
block|}
name|body
union|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|hv_kvp_ip_msg
block|{
name|uint8_t
name|operation
decl_stmt|;
name|uint8_t
name|pool
decl_stmt|;
name|struct
name|hv_kvp_ipaddr_value
name|kvp_ip_val
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|BSD_SOC_PATH
value|"/etc/hyperv/socket"
end_define

begin_define
define|#
directive|define
name|HV_SHUT_DOWN
value|0
end_define

begin_define
define|#
directive|define
name|HV_TIME_SYNCH
value|1
end_define

begin_define
define|#
directive|define
name|HV_HEART_BEAT
value|2
end_define

begin_define
define|#
directive|define
name|HV_KVP
value|3
end_define

begin_define
define|#
directive|define
name|HV_MAX_UTIL_SERVICES
value|4
end_define

begin_define
define|#
directive|define
name|HV_WLTIMEDELTA
value|116444736000000000L
end_define

begin_comment
comment|/* in 100ns unit */
end_comment

begin_define
define|#
directive|define
name|HV_ICTIMESYNCFLAG_PROBE
value|0
end_define

begin_define
define|#
directive|define
name|HV_ICTIMESYNCFLAG_SYNC
value|1
end_define

begin_define
define|#
directive|define
name|HV_ICTIMESYNCFLAG_SAMPLE
value|2
end_define

begin_define
define|#
directive|define
name|HV_NANO_SEC_PER_SEC
value|1000000000
end_define

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_service
block|{
name|hv_guid
name|guid
decl_stmt|;
comment|/* Hyper-V GUID */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of service */
name|boolean_t
name|enabled
decl_stmt|;
comment|/* service enabled */
name|hv_work_queue
modifier|*
name|work_queue
decl_stmt|;
comment|/* background work queue */
comment|//
comment|// function to initialize service
comment|//
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|hv_vmbus_service
modifier|*
parameter_list|)
function_decl|;
comment|//
comment|// function to process Hyper-V messages
comment|//
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
name|hv_vmbus_service
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|uint8_t
modifier|*
name|receive_buffer
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|hv_vmbus_service
name|service_table
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KVP_H */
end_comment

end_unit

