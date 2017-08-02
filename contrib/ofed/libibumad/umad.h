begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire Inc.  All rights reserved.  * Copyright (c) 2014 Intel Corporation.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UMAD_H
end_ifndef

begin_define
define|#
directive|define
name|_UMAD_H
end_define

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_comment
comment|/* __be16, __be32 and __be64 */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<infiniband/endian.h>
end_include

begin_include
include|#
directive|include
file|<infiniband/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__cplusplus */
end_comment

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_macro
name|BEGIN_C_DECLS
end_macro

begin_typedef
typedef|typedef
name|__be16
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
name|be16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__be32
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
name|be32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__be64
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
name|be64_t
typedef|;
end_typedef

begin_comment
comment|/*  * A GID data structure that may be used in definitions of on-the-wire data  * structures. Do not cast umad_gid pointers to ibv_gid pointers because the  * alignment of these two data structures is different.  */
end_comment

begin_union
union|union
name|umad_gid
block|{
name|uint8_t
name|raw
index|[
literal|16
index|]
decl_stmt|;
name|__be16
name|raw_be16
index|[
literal|8
index|]
decl_stmt|;
struct|struct
block|{
name|__be64
name|subnet_prefix
decl_stmt|;
name|__be64
name|interface_id
decl_stmt|;
block|}
name|global
struct|;
block|}
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|4
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
union|;
end_union

begin_define
define|#
directive|define
name|UMAD_MAX_DEVICES
value|32
end_define

begin_define
define|#
directive|define
name|UMAD_ANY_PORT
value|0
end_define

begin_typedef
typedef|typedef
struct|struct
name|ib_mad_addr
block|{
name|__be32
name|qpn
decl_stmt|;
name|__be32
name|qkey
decl_stmt|;
name|__be16
name|lid
decl_stmt|;
name|uint8_t
name|sl
decl_stmt|;
name|uint8_t
name|path_bits
decl_stmt|;
name|uint8_t
name|grh_present
decl_stmt|;
name|uint8_t
name|gid_index
decl_stmt|;
name|uint8_t
name|hop_limit
decl_stmt|;
name|uint8_t
name|traffic_class
decl_stmt|;
union|union
block|{
name|uint8_t
name|gid
index|[
literal|16
index|]
decl_stmt|;
comment|/* network-byte order */
name|union
name|umad_gid
name|ib_gid
decl_stmt|;
block|}
union|;
name|__be32
name|flow_label
decl_stmt|;
name|uint16_t
name|pkey_index
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|6
index|]
decl_stmt|;
block|}
name|ib_mad_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ib_user_mad
block|{
name|uint32_t
name|agent_id
decl_stmt|;
name|uint32_t
name|status
decl_stmt|;
name|uint32_t
name|timeout_ms
decl_stmt|;
name|uint32_t
name|retries
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|ib_mad_addr_t
name|addr
decl_stmt|;
name|uint8_t
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
name|ib_user_mad_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IB_UMAD_ABI_VERSION
value|5
end_define

begin_define
define|#
directive|define
name|IB_UMAD_ABI_DIR
value|"/sys/class/infiniband_mad"
end_define

begin_define
define|#
directive|define
name|IB_UMAD_ABI_FILE
value|"abi_version"
end_define

begin_define
define|#
directive|define
name|IB_IOCTL_MAGIC
value|0x1b
end_define

begin_define
define|#
directive|define
name|IB_USER_MAD_REGISTER_AGENT
value|_IOWR(IB_IOCTL_MAGIC, 1, \ 					      struct ib_user_mad_reg_req)
end_define

begin_define
define|#
directive|define
name|IB_USER_MAD_UNREGISTER_AGENT
value|_IOW(IB_IOCTL_MAGIC, 2, uint32_t)
end_define

begin_define
define|#
directive|define
name|IB_USER_MAD_ENABLE_PKEY
value|_IO(IB_IOCTL_MAGIC, 3)
end_define

begin_define
define|#
directive|define
name|IB_USER_MAD_REGISTER_AGENT2
value|_IOWR(IB_IOCTL_MAGIC, 4, \ 					      struct ib_user_mad_reg_req2)
end_define

begin_define
define|#
directive|define
name|UMAD_CA_NAME_LEN
value|20
end_define

begin_define
define|#
directive|define
name|UMAD_CA_MAX_PORTS
value|10
end_define

begin_comment
comment|/* 0 - 9 */
end_comment

begin_define
define|#
directive|define
name|UMAD_CA_MAX_AGENTS
value|32
end_define

begin_define
define|#
directive|define
name|SYS_INFINIBAND
value|"/sys/class/infiniband"
end_define

begin_define
define|#
directive|define
name|SYS_INFINIBAND_MAD
value|"/sys/class/infiniband_mad"
end_define

begin_define
define|#
directive|define
name|SYS_IB_MAD_PORT
value|"port"
end_define

begin_define
define|#
directive|define
name|SYS_IB_MAD_DEV
value|"ibdev"
end_define

begin_define
define|#
directive|define
name|UMAD_MAX_PORTS
value|64
end_define

begin_define
define|#
directive|define
name|UMAD_DEV_DIR
value|"/dev"
end_define

begin_define
define|#
directive|define
name|SYS_CA_PORTS_DIR
value|"ports"
end_define

begin_define
define|#
directive|define
name|SYS_NODE_TYPE
value|"node_type"
end_define

begin_define
define|#
directive|define
name|SYS_CA_FW_VERS
value|"fw_ver"
end_define

begin_define
define|#
directive|define
name|SYS_CA_HW_VERS
value|"hw_rev"
end_define

begin_define
define|#
directive|define
name|SYS_CA_TYPE
value|"hca_type"
end_define

begin_define
define|#
directive|define
name|SYS_CA_NODE_GUID
value|"node_guid"
end_define

begin_define
define|#
directive|define
name|SYS_CA_SYS_GUID
value|"sys_image_guid"
end_define

begin_define
define|#
directive|define
name|SYS_PORT_LMC
value|"lid_mask_count"
end_define

begin_define
define|#
directive|define
name|SYS_PORT_SMLID
value|"sm_lid"
end_define

begin_define
define|#
directive|define
name|SYS_PORT_SMSL
value|"sm_sl"
end_define

begin_define
define|#
directive|define
name|SYS_PORT_LID
value|"lid"
end_define

begin_define
define|#
directive|define
name|SYS_PORT_STATE
value|"state"
end_define

begin_define
define|#
directive|define
name|SYS_PORT_PHY_STATE
value|"phys_state"
end_define

begin_define
define|#
directive|define
name|SYS_PORT_CAPMASK
value|"cap_mask"
end_define

begin_define
define|#
directive|define
name|SYS_PORT_RATE
value|"rate"
end_define

begin_define
define|#
directive|define
name|SYS_PORT_GUID
value|"port_guid"
end_define

begin_define
define|#
directive|define
name|SYS_PORT_GID
value|"gids/0"
end_define

begin_define
define|#
directive|define
name|SYS_PORT_LINK_LAYER
value|"link_layer"
end_define

begin_typedef
typedef|typedef
struct|struct
name|umad_port
block|{
name|char
name|ca_name
index|[
name|UMAD_CA_NAME_LEN
index|]
decl_stmt|;
name|int
name|portnum
decl_stmt|;
name|unsigned
name|base_lid
decl_stmt|;
name|unsigned
name|lmc
decl_stmt|;
name|unsigned
name|sm_lid
decl_stmt|;
name|unsigned
name|sm_sl
decl_stmt|;
name|unsigned
name|state
decl_stmt|;
name|unsigned
name|phys_state
decl_stmt|;
name|unsigned
name|rate
decl_stmt|;
name|__be32
name|capmask
decl_stmt|;
name|__be64
name|gid_prefix
decl_stmt|;
name|__be64
name|port_guid
decl_stmt|;
name|unsigned
name|pkeys_size
decl_stmt|;
name|uint16_t
modifier|*
name|pkeys
decl_stmt|;
name|char
name|link_layer
index|[
name|UMAD_CA_NAME_LEN
index|]
decl_stmt|;
block|}
name|umad_port_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|umad_ca
block|{
name|char
name|ca_name
index|[
name|UMAD_CA_NAME_LEN
index|]
decl_stmt|;
name|unsigned
name|node_type
decl_stmt|;
name|int
name|numports
decl_stmt|;
name|char
name|fw_ver
index|[
literal|20
index|]
decl_stmt|;
name|char
name|ca_type
index|[
literal|40
index|]
decl_stmt|;
name|char
name|hw_ver
index|[
literal|20
index|]
decl_stmt|;
name|__be64
name|node_guid
decl_stmt|;
name|__be64
name|system_guid
decl_stmt|;
name|umad_port_t
modifier|*
name|ports
index|[
name|UMAD_CA_MAX_PORTS
index|]
decl_stmt|;
block|}
name|umad_ca_t
typedef|;
end_typedef

begin_function_decl
name|int
name|umad_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_done
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_get_cas_names
parameter_list|(
name|char
name|cas
index|[]
index|[
name|UMAD_CA_NAME_LEN
index|]
parameter_list|,
name|int
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_get_ca_portguids
parameter_list|(
specifier|const
name|char
modifier|*
name|ca_name
parameter_list|,
name|__be64
modifier|*
name|portguids
parameter_list|,
name|int
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_get_ca
parameter_list|(
specifier|const
name|char
modifier|*
name|ca_name
parameter_list|,
name|umad_ca_t
modifier|*
name|ca
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_release_ca
parameter_list|(
name|umad_ca_t
modifier|*
name|ca
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_get_port
parameter_list|(
specifier|const
name|char
modifier|*
name|ca_name
parameter_list|,
name|int
name|portnum
parameter_list|,
name|umad_port_t
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_release_port
parameter_list|(
name|umad_port_t
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_get_issm_path
parameter_list|(
specifier|const
name|char
modifier|*
name|ca_name
parameter_list|,
name|int
name|portnum
parameter_list|,
name|char
name|path
index|[]
parameter_list|,
name|int
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_open_port
parameter_list|(
specifier|const
name|char
modifier|*
name|ca_name
parameter_list|,
name|int
name|portnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_close_port
parameter_list|(
name|int
name|portid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|umad_get_mad
parameter_list|(
name|void
modifier|*
name|umad
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|umad_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_status
parameter_list|(
name|void
modifier|*
name|umad
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ib_mad_addr_t
modifier|*
name|umad_get_mad_addr
parameter_list|(
name|void
modifier|*
name|umad
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_set_grh_net
parameter_list|(
name|void
modifier|*
name|umad
parameter_list|,
name|void
modifier|*
name|mad_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_set_grh
parameter_list|(
name|void
modifier|*
name|umad
parameter_list|,
name|void
modifier|*
name|mad_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_set_addr_net
parameter_list|(
name|void
modifier|*
name|umad
parameter_list|,
name|__be16
name|dlid
parameter_list|,
name|__be32
name|dqp
parameter_list|,
name|int
name|sl
parameter_list|,
name|__be32
name|qkey
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_set_addr
parameter_list|(
name|void
modifier|*
name|umad
parameter_list|,
name|int
name|dlid
parameter_list|,
name|int
name|dqp
parameter_list|,
name|int
name|sl
parameter_list|,
name|int
name|qkey
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_set_pkey
parameter_list|(
name|void
modifier|*
name|umad
parameter_list|,
name|int
name|pkey_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_get_pkey
parameter_list|(
name|void
modifier|*
name|umad
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_send
parameter_list|(
name|int
name|portid
parameter_list|,
name|int
name|agentid
parameter_list|,
name|void
modifier|*
name|umad
parameter_list|,
name|int
name|length
parameter_list|,
name|int
name|timeout_ms
parameter_list|,
name|int
name|retries
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_recv
parameter_list|(
name|int
name|portid
parameter_list|,
name|void
modifier|*
name|umad
parameter_list|,
name|int
modifier|*
name|length
parameter_list|,
name|int
name|timeout_ms
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_poll
parameter_list|(
name|int
name|portid
parameter_list|,
name|int
name|timeout_ms
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_get_fd
parameter_list|(
name|int
name|portid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_register
parameter_list|(
name|int
name|portid
parameter_list|,
name|int
name|mgmt_class
parameter_list|,
name|int
name|mgmt_version
parameter_list|,
name|uint8_t
name|rmpp_version
parameter_list|,
name|long
name|method_mask
index|[
literal|16
operator|/
sizeof|sizeof
argument_list|(
name|long
argument_list|)
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_register_oui
parameter_list|(
name|int
name|portid
parameter_list|,
name|int
name|mgmt_class
parameter_list|,
name|uint8_t
name|rmpp_version
parameter_list|,
name|uint8_t
name|oui
index|[
literal|3
index|]
parameter_list|,
name|long
name|method_mask
index|[
literal|16
operator|/
sizeof|sizeof
argument_list|(
name|long
argument_list|)
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_unregister
parameter_list|(
name|int
name|portid
parameter_list|,
name|int
name|agentid
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|UMAD_USER_RMPP
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|}
enum|;
end_enum

begin_struct
struct|struct
name|umad_reg_attr
block|{
name|uint8_t
name|mgmt_class
decl_stmt|;
name|uint8_t
name|mgmt_class_version
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint64_t
name|method_mask
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|oui
decl_stmt|;
name|uint8_t
name|rmpp_version
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|umad_register2
parameter_list|(
name|int
name|port_fd
parameter_list|,
name|struct
name|umad_reg_attr
modifier|*
name|attr
parameter_list|,
name|uint32_t
modifier|*
name|agent_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umad_debug
parameter_list|(
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|umad_addr_dump
parameter_list|(
name|ib_mad_addr_t
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|umad_dump
parameter_list|(
name|void
modifier|*
name|umad
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|umad_alloc
parameter_list|(
name|int
name|num
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
comment|/* alloc array of umad buffers */
return|return
name|calloc
argument_list|(
name|num
argument_list|,
name|size
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|umad_free
parameter_list|(
name|void
modifier|*
name|umad
parameter_list|)
block|{
name|free
argument_list|(
name|umad
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Users should use the glibc functions directly, not these wrappers */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ntohll
end_ifndef

begin_undef
undef|#
directive|undef
name|ntohll
end_undef

begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(deprecated)
argument_list|)
name|uint64_t
name|ntohll
argument_list|(
argument|uint64_t x
argument_list|)
block|{
return|return
name|be64toh
argument_list|(
name|x
argument_list|)
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|ntohll
value|ntohll
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|htonll
end_ifndef

begin_undef
undef|#
directive|undef
name|htonll
end_undef

begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(deprecated)
argument_list|)
name|uint64_t
name|htonll
argument_list|(
argument|uint64_t x
argument_list|)
block|{
return|return
name|htobe64
argument_list|(
name|x
argument_list|)
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|htonll
value|htonll
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UMAD_H */
end_comment

end_unit

