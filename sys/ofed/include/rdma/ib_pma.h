begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006, 2007, 2008, 2009, 2010 QLogic Corporation.  * All rights reserved.  * Copyright (c) 2005, 2006 PathScale, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IB_PMA_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|IB_PMA_H
end_define

begin_include
include|#
directive|include
file|<rdma/ib_mad.h>
end_include

begin_comment
comment|/*  * PMA class portinfo capability mask bits  */
end_comment

begin_define
define|#
directive|define
name|IB_PMA_CLASS_CAP_ALLPORTSELECT
value|cpu_to_be16(1<< 8)
end_define

begin_define
define|#
directive|define
name|IB_PMA_CLASS_CAP_EXT_WIDTH
value|cpu_to_be16(1<< 9)
end_define

begin_define
define|#
directive|define
name|IB_PMA_CLASS_CAP_EXT_WIDTH_NOIETF
value|cpu_to_be16(1<< 10)
end_define

begin_define
define|#
directive|define
name|IB_PMA_CLASS_CAP_XMIT_WAIT
value|cpu_to_be16(1<< 12)
end_define

begin_define
define|#
directive|define
name|IB_PMA_CLASS_PORT_INFO
value|cpu_to_be16(0x0001)
end_define

begin_define
define|#
directive|define
name|IB_PMA_PORT_SAMPLES_CONTROL
value|cpu_to_be16(0x0010)
end_define

begin_define
define|#
directive|define
name|IB_PMA_PORT_SAMPLES_RESULT
value|cpu_to_be16(0x0011)
end_define

begin_define
define|#
directive|define
name|IB_PMA_PORT_COUNTERS
value|cpu_to_be16(0x0012)
end_define

begin_define
define|#
directive|define
name|IB_PMA_PORT_COUNTERS_EXT
value|cpu_to_be16(0x001D)
end_define

begin_define
define|#
directive|define
name|IB_PMA_PORT_SAMPLES_RESULT_EXT
value|cpu_to_be16(0x001E)
end_define

begin_struct
struct|struct
name|ib_pma_mad
block|{
name|struct
name|ib_mad_hdr
name|mad_hdr
decl_stmt|;
name|u8
name|reserved
index|[
literal|40
index|]
decl_stmt|;
name|u8
name|data
index|[
literal|192
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ib_pma_portsamplescontrol
block|{
name|u8
name|opcode
decl_stmt|;
name|u8
name|port_select
decl_stmt|;
name|u8
name|tick
decl_stmt|;
name|u8
name|counter_width
decl_stmt|;
comment|/* resv: 7:3, counter width: 2:0 */
name|__be32
name|counter_mask0_9
decl_stmt|;
comment|/* 2, 10 3-bit fields */
name|__be16
name|counter_mask10_14
decl_stmt|;
comment|/* 1, 5 3-bit fields */
name|u8
name|sample_mechanisms
decl_stmt|;
name|u8
name|sample_status
decl_stmt|;
comment|/* only lower 2 bits */
name|__be64
name|option_mask
decl_stmt|;
name|__be64
name|vendor_mask
decl_stmt|;
name|__be32
name|sample_start
decl_stmt|;
name|__be32
name|sample_interval
decl_stmt|;
name|__be16
name|tag
decl_stmt|;
name|__be16
name|counter_select
index|[
literal|15
index|]
decl_stmt|;
name|__be32
name|reserved1
decl_stmt|;
name|__be64
name|samples_only_option_mask
decl_stmt|;
name|__be32
name|reserved2
index|[
literal|28
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ib_pma_portsamplesresult
block|{
name|__be16
name|tag
decl_stmt|;
name|__be16
name|sample_status
decl_stmt|;
comment|/* only lower 2 bits */
name|__be32
name|counter
index|[
literal|15
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ib_pma_portsamplesresult_ext
block|{
name|__be16
name|tag
decl_stmt|;
name|__be16
name|sample_status
decl_stmt|;
comment|/* only lower 2 bits */
name|__be32
name|extended_width
decl_stmt|;
comment|/* only upper 2 bits */
name|__be64
name|counter
index|[
literal|15
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ib_pma_portcounters
block|{
name|u8
name|reserved
decl_stmt|;
name|u8
name|port_select
decl_stmt|;
name|__be16
name|counter_select
decl_stmt|;
name|__be16
name|symbol_error_counter
decl_stmt|;
name|u8
name|link_error_recovery_counter
decl_stmt|;
name|u8
name|link_downed_counter
decl_stmt|;
name|__be16
name|port_rcv_errors
decl_stmt|;
name|__be16
name|port_rcv_remphys_errors
decl_stmt|;
name|__be16
name|port_rcv_switch_relay_errors
decl_stmt|;
name|__be16
name|port_xmit_discards
decl_stmt|;
name|u8
name|port_xmit_constraint_errors
decl_stmt|;
name|u8
name|port_rcv_constraint_errors
decl_stmt|;
name|u8
name|reserved1
decl_stmt|;
name|u8
name|link_overrun_errors
decl_stmt|;
comment|/* LocalLink: 7:4, BufferOverrun: 3:0 */
name|__be16
name|reserved2
decl_stmt|;
name|__be16
name|vl15_dropped
decl_stmt|;
name|__be32
name|port_xmit_data
decl_stmt|;
name|__be32
name|port_rcv_data
decl_stmt|;
name|__be32
name|port_xmit_packets
decl_stmt|;
name|__be32
name|port_rcv_packets
decl_stmt|;
name|__be32
name|port_xmit_wait
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IB_PMA_SEL_SYMBOL_ERROR
value|cpu_to_be16(0x0001)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SEL_LINK_ERROR_RECOVERY
value|cpu_to_be16(0x0002)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SEL_LINK_DOWNED
value|cpu_to_be16(0x0004)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SEL_PORT_RCV_ERRORS
value|cpu_to_be16(0x0008)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SEL_PORT_RCV_REMPHYS_ERRORS
value|cpu_to_be16(0x0010)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SEL_PORT_XMIT_DISCARDS
value|cpu_to_be16(0x0040)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SEL_LOCAL_LINK_INTEGRITY_ERRORS
value|cpu_to_be16(0x0200)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SEL_EXCESSIVE_BUFFER_OVERRUNS
value|cpu_to_be16(0x0400)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SEL_PORT_VL15_DROPPED
value|cpu_to_be16(0x0800)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SEL_PORT_XMIT_DATA
value|cpu_to_be16(0x1000)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SEL_PORT_RCV_DATA
value|cpu_to_be16(0x2000)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SEL_PORT_XMIT_PACKETS
value|cpu_to_be16(0x4000)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SEL_PORT_RCV_PACKETS
value|cpu_to_be16(0x8000)
end_define

begin_struct
struct|struct
name|ib_pma_portcounters_ext
block|{
name|u8
name|reserved
decl_stmt|;
name|u8
name|port_select
decl_stmt|;
name|__be16
name|counter_select
decl_stmt|;
name|__be32
name|reserved1
decl_stmt|;
name|__be64
name|port_xmit_data
decl_stmt|;
name|__be64
name|port_rcv_data
decl_stmt|;
name|__be64
name|port_xmit_packets
decl_stmt|;
name|__be64
name|port_rcv_packets
decl_stmt|;
name|__be64
name|port_unicast_xmit_packets
decl_stmt|;
name|__be64
name|port_unicast_rcv_packets
decl_stmt|;
name|__be64
name|port_multicast_xmit_packets
decl_stmt|;
name|__be64
name|port_multicast_rcv_packets
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IB_PMA_SELX_PORT_XMIT_DATA
value|cpu_to_be16(0x0001)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SELX_PORT_RCV_DATA
value|cpu_to_be16(0x0002)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SELX_PORT_XMIT_PACKETS
value|cpu_to_be16(0x0004)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SELX_PORT_RCV_PACKETS
value|cpu_to_be16(0x0008)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SELX_PORT_UNI_XMIT_PACKETS
value|cpu_to_be16(0x0010)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SELX_PORT_UNI_RCV_PACKETS
value|cpu_to_be16(0x0020)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SELX_PORT_MULTI_XMIT_PACKETS
value|cpu_to_be16(0x0040)
end_define

begin_define
define|#
directive|define
name|IB_PMA_SELX_PORT_MULTI_RCV_PACKETS
value|cpu_to_be16(0x0080)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IB_PMA_H */
end_comment

end_unit

