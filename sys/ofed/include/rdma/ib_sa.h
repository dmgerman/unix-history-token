begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Topspin Communications.  All rights reserved.  * Copyright (c) 2005 Voltaire, Inc.  All rights reserved.  * Copyright (c) 2006 Intel Corporation.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IB_SA_H
end_ifndef

begin_define
define|#
directive|define
name|IB_SA_H
end_define

begin_include
include|#
directive|include
file|<linux/completion.h>
end_include

begin_include
include|#
directive|include
file|<linux/compiler.h>
end_include

begin_include
include|#
directive|include
file|<linux/netdevice.h>
end_include

begin_include
include|#
directive|include
file|<rdma/ib_verbs.h>
end_include

begin_include
include|#
directive|include
file|<rdma/ib_mad.h>
end_include

begin_enum
enum|enum
block|{
name|IB_SA_CLASS_VERSION
init|=
literal|2
block|,
comment|/* IB spec version 1.1/1.2 */
name|IB_SA_METHOD_GET_TABLE
init|=
literal|0x12
block|,
name|IB_SA_METHOD_GET_TABLE_RESP
init|=
literal|0x92
block|,
name|IB_SA_METHOD_DELETE
init|=
literal|0x15
block|,
name|IB_SA_METHOD_DELETE_RESP
init|=
literal|0x95
block|,
name|IB_SA_METHOD_GET_MULTI
init|=
literal|0x14
block|,
name|IB_SA_METHOD_GET_MULTI_RESP
init|=
literal|0x94
block|,
name|IB_SA_METHOD_GET_TRACE_TBL
init|=
literal|0x13
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|IB_SA_ATTR_CLASS_PORTINFO
init|=
literal|0x01
block|,
name|IB_SA_ATTR_NOTICE
init|=
literal|0x02
block|,
name|IB_SA_ATTR_INFORM_INFO
init|=
literal|0x03
block|,
name|IB_SA_ATTR_NODE_REC
init|=
literal|0x11
block|,
name|IB_SA_ATTR_PORT_INFO_REC
init|=
literal|0x12
block|,
name|IB_SA_ATTR_SL2VL_REC
init|=
literal|0x13
block|,
name|IB_SA_ATTR_SWITCH_REC
init|=
literal|0x14
block|,
name|IB_SA_ATTR_LINEAR_FDB_REC
init|=
literal|0x15
block|,
name|IB_SA_ATTR_RANDOM_FDB_REC
init|=
literal|0x16
block|,
name|IB_SA_ATTR_MCAST_FDB_REC
init|=
literal|0x17
block|,
name|IB_SA_ATTR_SM_INFO_REC
init|=
literal|0x18
block|,
name|IB_SA_ATTR_LINK_REC
init|=
literal|0x20
block|,
name|IB_SA_ATTR_GUID_INFO_REC
init|=
literal|0x30
block|,
name|IB_SA_ATTR_SERVICE_REC
init|=
literal|0x31
block|,
name|IB_SA_ATTR_PARTITION_REC
init|=
literal|0x33
block|,
name|IB_SA_ATTR_PATH_REC
init|=
literal|0x35
block|,
name|IB_SA_ATTR_VL_ARB_REC
init|=
literal|0x36
block|,
name|IB_SA_ATTR_MC_MEMBER_REC
init|=
literal|0x38
block|,
name|IB_SA_ATTR_TRACE_REC
init|=
literal|0x39
block|,
name|IB_SA_ATTR_MULTI_PATH_REC
init|=
literal|0x3a
block|,
name|IB_SA_ATTR_SERVICE_ASSOC_REC
init|=
literal|0x3b
block|,
name|IB_SA_ATTR_INFORM_INFO_REC
init|=
literal|0xf3
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ib_sa_selector
block|{
name|IB_SA_GT
init|=
literal|0
block|,
name|IB_SA_LT
init|=
literal|1
block|,
name|IB_SA_EQ
init|=
literal|2
block|,
comment|/* 	 * The meaning of "best" depends on the attribute: for 	 * example, for MTU best will return the largest available 	 * MTU, while for packet life time, best will return the 	 * smallest available life time. 	 */
name|IB_SA_BEST
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/*  * There are 4 types of join states:  * FullMember, NonMember, SendOnlyNonMember, SendOnlyFullMember.  * The order corresponds to JoinState bits in MCMemberRecord.  */
end_comment

begin_enum
enum|enum
name|ib_sa_mc_join_states
block|{
name|FULLMEMBER_JOIN
block|,
name|NONMEMBER_JOIN
block|,
name|SENDONLY_NONMEBER_JOIN
block|,
name|SENDONLY_FULLMEMBER_JOIN
block|,
name|NUM_JOIN_MEMBERSHIP_TYPES
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|IB_SA_CAP_MASK2_SENDONLY_FULL_MEM_SUPPORT
value|BIT(12)
end_define

begin_comment
comment|/*  * Structures for SA records are named "struct ib_sa_xxx_rec."  No  * attempt is made to pack structures to match the physical layout of  * SA records in SA MADs; all packing and unpacking is handled by the  * SA query code.  *  * For a record with structure ib_sa_xxx_rec, the naming convention  * for the component mask value for field yyy is IB_SA_XXX_REC_YYY (we  * never use different abbreviations or otherwise change the spelling  * of xxx/yyy between ib_sa_xxx_rec.yyy and IB_SA_XXX_REC_YYY).  *  * Reserved rows are indicated with comments to help maintainability.  */
end_comment

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_SERVICE_ID
value|(IB_SA_COMP_MASK( 0) |\ 							IB_SA_COMP_MASK( 1))
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_DGID
value|IB_SA_COMP_MASK( 2)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_SGID
value|IB_SA_COMP_MASK( 3)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_DLID
value|IB_SA_COMP_MASK( 4)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_SLID
value|IB_SA_COMP_MASK( 5)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_RAW_TRAFFIC
value|IB_SA_COMP_MASK( 6)
end_define

begin_comment
comment|/* reserved:								 7 */
end_comment

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_FLOW_LABEL
value|IB_SA_COMP_MASK( 8)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_HOP_LIMIT
value|IB_SA_COMP_MASK( 9)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_TRAFFIC_CLASS
value|IB_SA_COMP_MASK(10)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_REVERSIBLE
value|IB_SA_COMP_MASK(11)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_NUMB_PATH
value|IB_SA_COMP_MASK(12)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_PKEY
value|IB_SA_COMP_MASK(13)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_QOS_CLASS
value|IB_SA_COMP_MASK(14)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_SL
value|IB_SA_COMP_MASK(15)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_MTU_SELECTOR
value|IB_SA_COMP_MASK(16)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_MTU
value|IB_SA_COMP_MASK(17)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_RATE_SELECTOR
value|IB_SA_COMP_MASK(18)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_RATE
value|IB_SA_COMP_MASK(19)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_PACKET_LIFE_TIME_SELECTOR
value|IB_SA_COMP_MASK(20)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_PACKET_LIFE_TIME
value|IB_SA_COMP_MASK(21)
end_define

begin_define
define|#
directive|define
name|IB_SA_PATH_REC_PREFERENCE
value|IB_SA_COMP_MASK(22)
end_define

begin_struct
struct|struct
name|ib_sa_path_rec
block|{
name|__be64
name|service_id
decl_stmt|;
name|union
name|ib_gid
name|dgid
decl_stmt|;
name|union
name|ib_gid
name|sgid
decl_stmt|;
name|__be16
name|dlid
decl_stmt|;
name|__be16
name|slid
decl_stmt|;
name|int
name|raw_traffic
decl_stmt|;
comment|/* reserved */
name|__be32
name|flow_label
decl_stmt|;
name|u8
name|hop_limit
decl_stmt|;
name|u8
name|traffic_class
decl_stmt|;
name|int
name|reversible
decl_stmt|;
name|u8
name|numb_path
decl_stmt|;
name|__be16
name|pkey
decl_stmt|;
name|__be16
name|qos_class
decl_stmt|;
name|u8
name|sl
decl_stmt|;
name|u8
name|mtu_selector
decl_stmt|;
name|u8
name|mtu
decl_stmt|;
name|u8
name|rate_selector
decl_stmt|;
name|u8
name|rate
decl_stmt|;
name|u8
name|packet_life_time_selector
decl_stmt|;
name|u8
name|packet_life_time
decl_stmt|;
name|u8
name|preference
decl_stmt|;
name|u8
name|dmac
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/* ignored in IB */
name|int
name|ifindex
decl_stmt|;
comment|/* ignored in IB */
name|struct
name|vnet
modifier|*
name|net
decl_stmt|;
name|enum
name|ib_gid_type
name|gid_type
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|struct
name|net_device
modifier|*
name|ib_get_ndev_from_path
parameter_list|(
name|struct
name|ib_sa_path_rec
modifier|*
name|rec
parameter_list|)
block|{
return|return
name|rec
operator|->
name|net
condition|?
name|dev_get_by_index
argument_list|(
name|rec
operator|->
name|net
argument_list|,
name|rec
operator|->
name|ifindex
argument_list|)
else|:
name|NULL
return|;
block|}
end_function

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_MGID
value|IB_SA_COMP_MASK( 0)
end_define

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_PORT_GID
value|IB_SA_COMP_MASK( 1)
end_define

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_QKEY
value|IB_SA_COMP_MASK( 2)
end_define

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_MLID
value|IB_SA_COMP_MASK( 3)
end_define

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_MTU_SELECTOR
value|IB_SA_COMP_MASK( 4)
end_define

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_MTU
value|IB_SA_COMP_MASK( 5)
end_define

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_TRAFFIC_CLASS
value|IB_SA_COMP_MASK( 6)
end_define

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_PKEY
value|IB_SA_COMP_MASK( 7)
end_define

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_RATE_SELECTOR
value|IB_SA_COMP_MASK( 8)
end_define

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_RATE
value|IB_SA_COMP_MASK( 9)
end_define

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_PACKET_LIFE_TIME_SELECTOR
value|IB_SA_COMP_MASK(10)
end_define

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_PACKET_LIFE_TIME
value|IB_SA_COMP_MASK(11)
end_define

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_SL
value|IB_SA_COMP_MASK(12)
end_define

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_FLOW_LABEL
value|IB_SA_COMP_MASK(13)
end_define

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_HOP_LIMIT
value|IB_SA_COMP_MASK(14)
end_define

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_SCOPE
value|IB_SA_COMP_MASK(15)
end_define

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_JOIN_STATE
value|IB_SA_COMP_MASK(16)
end_define

begin_define
define|#
directive|define
name|IB_SA_MCMEMBER_REC_PROXY_JOIN
value|IB_SA_COMP_MASK(17)
end_define

begin_struct
struct|struct
name|ib_sa_mcmember_rec
block|{
name|union
name|ib_gid
name|mgid
decl_stmt|;
name|union
name|ib_gid
name|port_gid
decl_stmt|;
name|__be32
name|qkey
decl_stmt|;
name|__be16
name|mlid
decl_stmt|;
name|u8
name|mtu_selector
decl_stmt|;
name|u8
name|mtu
decl_stmt|;
name|u8
name|traffic_class
decl_stmt|;
name|__be16
name|pkey
decl_stmt|;
name|u8
name|rate_selector
decl_stmt|;
name|u8
name|rate
decl_stmt|;
name|u8
name|packet_life_time_selector
decl_stmt|;
name|u8
name|packet_life_time
decl_stmt|;
name|u8
name|sl
decl_stmt|;
name|__be32
name|flow_label
decl_stmt|;
name|u8
name|hop_limit
decl_stmt|;
name|u8
name|scope
decl_stmt|;
name|u8
name|join_state
decl_stmt|;
name|int
name|proxy_join
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Service Record Component Mask Sec 15.2.5.14 Ver 1.1	*/
end_comment

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_ID
value|IB_SA_COMP_MASK( 0)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_GID
value|IB_SA_COMP_MASK( 1)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_PKEY
value|IB_SA_COMP_MASK( 2)
end_define

begin_comment
comment|/* reserved:								 3 */
end_comment

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_LEASE
value|IB_SA_COMP_MASK( 4)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_KEY
value|IB_SA_COMP_MASK( 5)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_NAME
value|IB_SA_COMP_MASK( 6)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA8_0
value|IB_SA_COMP_MASK( 7)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA8_1
value|IB_SA_COMP_MASK( 8)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA8_2
value|IB_SA_COMP_MASK( 9)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA8_3
value|IB_SA_COMP_MASK(10)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA8_4
value|IB_SA_COMP_MASK(11)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA8_5
value|IB_SA_COMP_MASK(12)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA8_6
value|IB_SA_COMP_MASK(13)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA8_7
value|IB_SA_COMP_MASK(14)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA8_8
value|IB_SA_COMP_MASK(15)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA8_9
value|IB_SA_COMP_MASK(16)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA8_10
value|IB_SA_COMP_MASK(17)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA8_11
value|IB_SA_COMP_MASK(18)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA8_12
value|IB_SA_COMP_MASK(19)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA8_13
value|IB_SA_COMP_MASK(20)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA8_14
value|IB_SA_COMP_MASK(21)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA8_15
value|IB_SA_COMP_MASK(22)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA16_0
value|IB_SA_COMP_MASK(23)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA16_1
value|IB_SA_COMP_MASK(24)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA16_2
value|IB_SA_COMP_MASK(25)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA16_3
value|IB_SA_COMP_MASK(26)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA16_4
value|IB_SA_COMP_MASK(27)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA16_5
value|IB_SA_COMP_MASK(28)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA16_6
value|IB_SA_COMP_MASK(29)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA16_7
value|IB_SA_COMP_MASK(30)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA32_0
value|IB_SA_COMP_MASK(31)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA32_1
value|IB_SA_COMP_MASK(32)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA32_2
value|IB_SA_COMP_MASK(33)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA32_3
value|IB_SA_COMP_MASK(34)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA64_0
value|IB_SA_COMP_MASK(35)
end_define

begin_define
define|#
directive|define
name|IB_SA_SERVICE_REC_SERVICE_DATA64_1
value|IB_SA_COMP_MASK(36)
end_define

begin_define
define|#
directive|define
name|IB_DEFAULT_SERVICE_LEASE
value|0xFFFFFFFF
end_define

begin_struct
struct|struct
name|ib_sa_service_rec
block|{
name|u64
name|id
decl_stmt|;
name|union
name|ib_gid
name|gid
decl_stmt|;
name|__be16
name|pkey
decl_stmt|;
comment|/* reserved */
name|u32
name|lease
decl_stmt|;
name|u8
name|key
index|[
literal|16
index|]
decl_stmt|;
name|u8
name|name
index|[
literal|64
index|]
decl_stmt|;
name|u8
name|data8
index|[
literal|16
index|]
decl_stmt|;
name|u16
name|data16
index|[
literal|8
index|]
decl_stmt|;
name|u32
name|data32
index|[
literal|4
index|]
decl_stmt|;
name|u64
name|data64
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IB_SA_GUIDINFO_REC_LID
value|IB_SA_COMP_MASK(0)
end_define

begin_define
define|#
directive|define
name|IB_SA_GUIDINFO_REC_BLOCK_NUM
value|IB_SA_COMP_MASK(1)
end_define

begin_define
define|#
directive|define
name|IB_SA_GUIDINFO_REC_RES1
value|IB_SA_COMP_MASK(2)
end_define

begin_define
define|#
directive|define
name|IB_SA_GUIDINFO_REC_RES2
value|IB_SA_COMP_MASK(3)
end_define

begin_define
define|#
directive|define
name|IB_SA_GUIDINFO_REC_GID0
value|IB_SA_COMP_MASK(4)
end_define

begin_define
define|#
directive|define
name|IB_SA_GUIDINFO_REC_GID1
value|IB_SA_COMP_MASK(5)
end_define

begin_define
define|#
directive|define
name|IB_SA_GUIDINFO_REC_GID2
value|IB_SA_COMP_MASK(6)
end_define

begin_define
define|#
directive|define
name|IB_SA_GUIDINFO_REC_GID3
value|IB_SA_COMP_MASK(7)
end_define

begin_define
define|#
directive|define
name|IB_SA_GUIDINFO_REC_GID4
value|IB_SA_COMP_MASK(8)
end_define

begin_define
define|#
directive|define
name|IB_SA_GUIDINFO_REC_GID5
value|IB_SA_COMP_MASK(9)
end_define

begin_define
define|#
directive|define
name|IB_SA_GUIDINFO_REC_GID6
value|IB_SA_COMP_MASK(10)
end_define

begin_define
define|#
directive|define
name|IB_SA_GUIDINFO_REC_GID7
value|IB_SA_COMP_MASK(11)
end_define

begin_struct
struct|struct
name|ib_sa_guidinfo_rec
block|{
name|__be16
name|lid
decl_stmt|;
name|u8
name|block_num
decl_stmt|;
comment|/* reserved */
name|u8
name|res1
decl_stmt|;
name|__be32
name|res2
decl_stmt|;
name|u8
name|guid_info_list
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ib_sa_client
block|{
name|atomic_t
name|users
decl_stmt|;
name|struct
name|completion
name|comp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * ib_sa_register_client - Register an SA client.  */
end_comment

begin_function_decl
name|void
name|ib_sa_register_client
parameter_list|(
name|struct
name|ib_sa_client
modifier|*
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_sa_unregister_client - Deregister an SA client.  * @client: Client object to deregister.  */
end_comment

begin_function_decl
name|void
name|ib_sa_unregister_client
parameter_list|(
name|struct
name|ib_sa_client
modifier|*
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ib_sa_query
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ib_sa_cancel_query
parameter_list|(
name|int
name|id
parameter_list|,
name|struct
name|ib_sa_query
modifier|*
name|query
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ib_sa_path_rec_get
parameter_list|(
name|struct
name|ib_sa_client
modifier|*
name|client
parameter_list|,
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|u8
name|port_num
parameter_list|,
name|struct
name|ib_sa_path_rec
modifier|*
name|rec
parameter_list|,
name|ib_sa_comp_mask
name|comp_mask
parameter_list|,
name|int
name|timeout_ms
parameter_list|,
name|gfp_t
name|gfp_mask
parameter_list|,
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|int
name|status
parameter_list|,
name|struct
name|ib_sa_path_rec
modifier|*
name|resp
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
name|struct
name|ib_sa_query
modifier|*
modifier|*
name|query
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ib_sa_service_rec_query
parameter_list|(
name|struct
name|ib_sa_client
modifier|*
name|client
parameter_list|,
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|u8
name|port_num
parameter_list|,
name|u8
name|method
parameter_list|,
name|struct
name|ib_sa_service_rec
modifier|*
name|rec
parameter_list|,
name|ib_sa_comp_mask
name|comp_mask
parameter_list|,
name|int
name|timeout_ms
parameter_list|,
name|gfp_t
name|gfp_mask
parameter_list|,
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|int
name|status
parameter_list|,
name|struct
name|ib_sa_service_rec
modifier|*
name|resp
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
name|struct
name|ib_sa_query
modifier|*
modifier|*
name|sa_query
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|ib_sa_multicast
block|{
name|struct
name|ib_sa_mcmember_rec
name|rec
decl_stmt|;
name|ib_sa_comp_mask
name|comp_mask
decl_stmt|;
name|int
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|int
name|status
parameter_list|,
name|struct
name|ib_sa_multicast
modifier|*
name|multicast
parameter_list|)
function_decl|;
name|void
modifier|*
name|context
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * ib_sa_join_multicast - Initiates a join request to the specified multicast  *   group.  * @client: SA client  * @device: Device associated with the multicast group.  * @port_num: Port on the specified device to associate with the multicast  *   group.  * @rec: SA multicast member record specifying group attributes.  * @comp_mask: Component mask indicating which group attributes of %rec are  *   valid.  * @gfp_mask: GFP mask for memory allocations.  * @callback: User callback invoked once the join operation completes.  * @context: User specified context stored with the ib_sa_multicast structure.  *  * This call initiates a multicast join request with the SA for the specified  * multicast group.  If the join operation is started successfully, it returns  * an ib_sa_multicast structure that is used to track the multicast operation.  * Users must free this structure by calling ib_free_multicast, even if the  * join operation later fails.  (The callback status is non-zero.)  *  * If the join operation fails; status will be non-zero, with the following  * failures possible:  * -ETIMEDOUT: The request timed out.  * -EIO: An error occurred sending the query.  * -EINVAL: The MCMemberRecord values differed from the existing group's.  * -ENETRESET: Indicates that an fatal error has occurred on the multicast  *   group, and the user must rejoin the group to continue using it.  */
end_comment

begin_function_decl
name|struct
name|ib_sa_multicast
modifier|*
name|ib_sa_join_multicast
parameter_list|(
name|struct
name|ib_sa_client
modifier|*
name|client
parameter_list|,
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|u8
name|port_num
parameter_list|,
name|struct
name|ib_sa_mcmember_rec
modifier|*
name|rec
parameter_list|,
name|ib_sa_comp_mask
name|comp_mask
parameter_list|,
name|gfp_t
name|gfp_mask
parameter_list|,
name|int
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|int
name|status
parameter_list|,
name|struct
name|ib_sa_multicast
modifier|*
name|multicast
parameter_list|)
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_free_multicast - Frees the multicast tracking structure, and releases  *    any reference on the multicast group.  * @multicast: Multicast tracking structure allocated by ib_join_multicast.  *  * This call blocks until the multicast identifier is destroyed.  It may  * not be called from within the multicast callback; however, returning a non-  * zero value from the callback will result in destroying the multicast  * tracking structure.  */
end_comment

begin_function_decl
name|void
name|ib_sa_free_multicast
parameter_list|(
name|struct
name|ib_sa_multicast
modifier|*
name|multicast
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_get_mcmember_rec - Looks up a multicast member record by its MGID and  *   returns it if found.  * @device: Device associated with the multicast group.  * @port_num: Port on the specified device to associate with the multicast  *   group.  * @mgid: MGID of multicast group.  * @rec: Location to copy SA multicast member record.  */
end_comment

begin_function_decl
name|int
name|ib_sa_get_mcmember_rec
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|u8
name|port_num
parameter_list|,
name|union
name|ib_gid
modifier|*
name|mgid
parameter_list|,
name|struct
name|ib_sa_mcmember_rec
modifier|*
name|rec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_init_ah_from_mcmember - Initialize address handle attributes based on  * an SA multicast member record.  */
end_comment

begin_function_decl
name|int
name|ib_init_ah_from_mcmember
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|u8
name|port_num
parameter_list|,
name|struct
name|ib_sa_mcmember_rec
modifier|*
name|rec
parameter_list|,
name|struct
name|net_device
modifier|*
name|ndev
parameter_list|,
name|enum
name|ib_gid_type
name|gid_type
parameter_list|,
name|struct
name|ib_ah_attr
modifier|*
name|ah_attr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_init_ah_from_path - Initialize address handle attributes based on an SA  *   path record.  */
end_comment

begin_function_decl
name|int
name|ib_init_ah_from_path
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|u8
name|port_num
parameter_list|,
name|struct
name|ib_sa_path_rec
modifier|*
name|rec
parameter_list|,
name|struct
name|ib_ah_attr
modifier|*
name|ah_attr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_sa_pack_path - Conert a path record from struct ib_sa_path_rec  * to IB MAD wire format.  */
end_comment

begin_function_decl
name|void
name|ib_sa_pack_path
parameter_list|(
name|struct
name|ib_sa_path_rec
modifier|*
name|rec
parameter_list|,
name|void
modifier|*
name|attribute
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_sa_unpack_path - Convert a path record from MAD format to struct  * ib_sa_path_rec.  */
end_comment

begin_function_decl
name|void
name|ib_sa_unpack_path
parameter_list|(
name|void
modifier|*
name|attribute
parameter_list|,
name|struct
name|ib_sa_path_rec
modifier|*
name|rec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Support GuidInfoRecord */
end_comment

begin_function_decl
name|int
name|ib_sa_guid_info_rec_query
parameter_list|(
name|struct
name|ib_sa_client
modifier|*
name|client
parameter_list|,
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|u8
name|port_num
parameter_list|,
name|struct
name|ib_sa_guidinfo_rec
modifier|*
name|rec
parameter_list|,
name|ib_sa_comp_mask
name|comp_mask
parameter_list|,
name|u8
name|method
parameter_list|,
name|int
name|timeout_ms
parameter_list|,
name|gfp_t
name|gfp_mask
parameter_list|,
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|int
name|status
parameter_list|,
name|struct
name|ib_sa_guidinfo_rec
modifier|*
name|resp
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
name|struct
name|ib_sa_query
modifier|*
modifier|*
name|sa_query
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Support get SA ClassPortInfo */
end_comment

begin_function_decl
name|int
name|ib_sa_classport_info_rec_query
parameter_list|(
name|struct
name|ib_sa_client
modifier|*
name|client
parameter_list|,
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|u8
name|port_num
parameter_list|,
name|int
name|timeout_ms
parameter_list|,
name|gfp_t
name|gfp_mask
parameter_list|,
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|int
name|status
parameter_list|,
name|struct
name|ib_class_port_info
modifier|*
name|resp
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
name|struct
name|ib_sa_query
modifier|*
modifier|*
name|sa_query
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IB_SA_H */
end_comment

end_unit

