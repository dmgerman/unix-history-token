begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Topspin Communications.  All rights reserved.  * Copyright (c) 2005 Voltaire, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IB_USER_MAD_H
end_ifndef

begin_define
define|#
directive|define
name|IB_USER_MAD_H
end_define

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<linux/ioctl.h>
end_include

begin_comment
comment|/*  * Increment this value if any changes that break userspace ABI  * compatibility are made.  */
end_comment

begin_define
define|#
directive|define
name|IB_USER_MAD_ABI_VERSION
value|5
end_define

begin_comment
comment|/*  * Make sure that all structs defined in this file remain laid out so  * that they pack the same way on 32-bit and 64-bit architectures (to  * avoid incompatibility between 32-bit userspace and 64-bit kernels).  */
end_comment

begin_comment
comment|/**  * ib_user_mad_hdr_old - Old version of MAD packet header without pkey_index  * @id - ID of agent MAD received with/to be sent with  * @status - 0 on successful receive, ETIMEDOUT if no response  *   received (transaction ID in data[] will be set to TID of original  *   request) (ignored on send)  * @timeout_ms - Milliseconds to wait for response (unset on receive)  * @retries - Number of automatic retries to attempt  * @qpn - Remote QP number received from/to be sent to  * @qkey - Remote Q_Key to be sent with (unset on receive)  * @lid - Remote lid received from/to be sent to  * @sl - Service level received with/to be sent with  * @path_bits - Local path bits received with/to be sent with  * @grh_present - If set, GRH was received/should be sent  * @gid_index - Local GID index to send with (unset on receive)  * @hop_limit - Hop limit in GRH  * @traffic_class - Traffic class in GRH  * @gid - Remote GID in GRH  * @flow_label - Flow label in GRH  */
end_comment

begin_struct
struct|struct
name|ib_user_mad_hdr_old
block|{
name|__u32
name|id
decl_stmt|;
name|__u32
name|status
decl_stmt|;
name|__u32
name|timeout_ms
decl_stmt|;
name|__u32
name|retries
decl_stmt|;
name|__u32
name|length
decl_stmt|;
name|__be32
name|qpn
decl_stmt|;
name|__be32
name|qkey
decl_stmt|;
name|__be16
name|lid
decl_stmt|;
name|__u8
name|sl
decl_stmt|;
name|__u8
name|path_bits
decl_stmt|;
name|__u8
name|grh_present
decl_stmt|;
name|__u8
name|gid_index
decl_stmt|;
name|__u8
name|hop_limit
decl_stmt|;
name|__u8
name|traffic_class
decl_stmt|;
name|__u8
name|gid
index|[
literal|16
index|]
decl_stmt|;
name|__be32
name|flow_label
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * ib_user_mad_hdr - MAD packet header  *   This layout allows specifying/receiving the P_Key index.  To use  *   this capability, an application must call the  *   IB_USER_MAD_ENABLE_PKEY ioctl on the user MAD file handle before  *   any other actions with the file handle.  * @id - ID of agent MAD received with/to be sent with  * @status - 0 on successful receive, ETIMEDOUT if no response  *   received (transaction ID in data[] will be set to TID of original  *   request) (ignored on send)  * @timeout_ms - Milliseconds to wait for response (unset on receive)  * @retries - Number of automatic retries to attempt  * @qpn - Remote QP number received from/to be sent to  * @qkey - Remote Q_Key to be sent with (unset on receive)  * @lid - Remote lid received from/to be sent to  * @sl - Service level received with/to be sent with  * @path_bits - Local path bits received with/to be sent with  * @grh_present - If set, GRH was received/should be sent  * @gid_index - Local GID index to send with (unset on receive)  * @hop_limit - Hop limit in GRH  * @traffic_class - Traffic class in GRH  * @gid - Remote GID in GRH  * @flow_label - Flow label in GRH  * @pkey_index - P_Key index  */
end_comment

begin_struct
struct|struct
name|ib_user_mad_hdr
block|{
name|__u32
name|id
decl_stmt|;
name|__u32
name|status
decl_stmt|;
name|__u32
name|timeout_ms
decl_stmt|;
name|__u32
name|retries
decl_stmt|;
name|__u32
name|length
decl_stmt|;
name|__be32
name|qpn
decl_stmt|;
name|__be32
name|qkey
decl_stmt|;
name|__be16
name|lid
decl_stmt|;
name|__u8
name|sl
decl_stmt|;
name|__u8
name|path_bits
decl_stmt|;
name|__u8
name|grh_present
decl_stmt|;
name|__u8
name|gid_index
decl_stmt|;
name|__u8
name|hop_limit
decl_stmt|;
name|__u8
name|traffic_class
decl_stmt|;
name|__u8
name|gid
index|[
literal|16
index|]
decl_stmt|;
name|__be32
name|flow_label
decl_stmt|;
name|__u16
name|pkey_index
decl_stmt|;
name|__u8
name|reserved
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * ib_user_mad - MAD packet  * @hdr - MAD packet header  * @data - Contents of MAD  *  */
end_comment

begin_struct
struct|struct
name|ib_user_mad
block|{
name|struct
name|ib_user_mad_hdr
name|hdr
decl_stmt|;
name|__u64
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Earlier versions of this interface definition declared the  * method_mask[] member as an array of __u32 but treated it as a  * bitmap made up of longs in the kernel.  This ambiguity meant that  * 32-bit big-endian applications that can run on both 32-bit and  * 64-bit kernels had no consistent ABI to rely on, and 64-bit  * big-endian applications that treated method_mask as being made up  * of 32-bit words would have their bitmap misinterpreted.  *  * To clear up this confusion, we change the declaration of  * method_mask[] to use unsigned long and handle the conversion from  * 32-bit userspace to 64-bit kernel for big-endian systems in the  * compat_ioctl method.  Unfortunately, to keep the structure layout  * the same, we need the method_mask[] array to be aligned only to 4  * bytes even when long is 64 bits, which forces us into this ugly  * typedef.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|__attribute__
typedef|((
name|aligned
typedef|(4)))
name|packed_ulong
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IB_USER_MAD_LONGS_PER_METHOD_MASK
value|(128 / (8 * sizeof (long)))
end_define

begin_comment
comment|/**  * ib_user_mad_reg_req - MAD registration request  * @id - Set by the kernel; used to identify agent in future requests.  * @qpn - Queue pair number; must be 0 or 1.  * @method_mask - The caller will receive unsolicited MADs for any method  *   where @method_mask = 1.  * @mgmt_class - Indicates which management class of MADs should be receive  *   by the caller.  This field is only required if the user wishes to  *   receive unsolicited MADs, otherwise it should be 0.  * @mgmt_class_version - Indicates which version of MADs for the given  *   management class to receive.  * @oui: Indicates IEEE OUI when mgmt_class is a vendor class  *   in the range from 0x30 to 0x4f. Otherwise not used.  * @rmpp_version: If set, indicates the RMPP version used.  *  */
end_comment

begin_struct
struct|struct
name|ib_user_mad_reg_req
block|{
name|__u32
name|id
decl_stmt|;
name|packed_ulong
name|method_mask
index|[
name|IB_USER_MAD_LONGS_PER_METHOD_MASK
index|]
decl_stmt|;
name|__u8
name|qpn
decl_stmt|;
name|__u8
name|mgmt_class
decl_stmt|;
name|__u8
name|mgmt_class_version
decl_stmt|;
name|__u8
name|oui
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|rmpp_version
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * ib_user_mad_reg_req2 - MAD registration request  *  * @id                 - Set by the _kernel_; used by userspace to identify the  *                       registered agent in future requests.  * @qpn                - Queue pair number; must be 0 or 1.  * @mgmt_class         - Indicates which management class of MADs should be  *                       receive by the caller.  This field is only required if  *                       the user wishes to receive unsolicited MADs, otherwise  *                       it should be 0.  * @mgmt_class_version - Indicates which version of MADs for the given  *                       management class to receive.  * @res                - Ignored.  * @flags              - additional registration flags; Must be in the set of  *                       flags defined in IB_USER_MAD_REG_FLAGS_CAP  * @method_mask        - The caller wishes to receive unsolicited MADs for the  *                       methods whose bit(s) is(are) set.  * @oui                - Indicates IEEE OUI to use when mgmt_class is a vendor  *                       class in the range from 0x30 to 0x4f. Otherwise not  *                       used.  * @rmpp_version       - If set, indicates the RMPP version to use.  */
end_comment

begin_enum
enum|enum
block|{
name|IB_USER_MAD_USER_RMPP
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|IB_USER_MAD_REG_FLAGS_CAP
value|(IB_USER_MAD_USER_RMPP)
end_define

begin_struct
struct|struct
name|ib_user_mad_reg_req2
block|{
name|__u32
name|id
decl_stmt|;
name|__u32
name|qpn
decl_stmt|;
name|__u8
name|mgmt_class
decl_stmt|;
name|__u8
name|mgmt_class_version
decl_stmt|;
name|__u16
name|res
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
name|__u64
name|method_mask
index|[
literal|2
index|]
decl_stmt|;
name|__u32
name|oui
decl_stmt|;
name|__u8
name|rmpp_version
decl_stmt|;
name|__u8
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

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
value|_IOW(IB_IOCTL_MAGIC, 2, __u32)
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IB_USER_MAD_H */
end_comment

end_unit

