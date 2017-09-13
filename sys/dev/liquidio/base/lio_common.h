begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   BSD LICENSE  *  *   Copyright(c) 2017 Cavium, Inc.. All rights reserved.  *   All rights reserved.  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in  *       the documentation and/or other materials provided with the  *       distribution.  *     * Neither the name of Cavium, Inc. nor the names of its  *       contributors may be used to endorse or promote products derived  *       from this software without specific prior written permission.  *  *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *   OWNER(S) OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_comment
comment|/*   \file  lio_common.h  *   \brief Common: Structures and macros used in PCI-NIC package by core and  *   host driver.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIO_COMMON_H__
end_ifndef

begin_define
define|#
directive|define
name|__LIO_COMMON_H__
end_define

begin_include
include|#
directive|include
file|"lio_config.h"
end_include

begin_define
define|#
directive|define
name|LIO_STR_HELPER
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_define
define|#
directive|define
name|LIO_STR
parameter_list|(
name|x
parameter_list|)
value|LIO_STR_HELPER(x)
end_define

begin_define
define|#
directive|define
name|LIO_BASE_MAJOR_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|LIO_BASE_MINOR_VERSION
value|6
end_define

begin_define
define|#
directive|define
name|LIO_BASE_MICRO_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|LIO_BASE_VERSION
value|LIO_STR(LIO_BASE_MAJOR_VERSION) "."	\ 				LIO_STR(LIO_BASE_MINOR_VERSION)
end_define

begin_define
define|#
directive|define
name|LIO_VERSION
value|LIO_STR(LIO_BASE_MAJOR_VERSION) "."	\ 				LIO_STR(LIO_BASE_MINOR_VERSION)		\ 				"." LIO_STR(LIO_BASE_MICRO_VERSION)
end_define

begin_struct
struct|struct
name|lio_version
block|{
name|uint16_t
name|major
decl_stmt|;
name|uint16_t
name|minor
decl_stmt|;
name|uint16_t
name|micro
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Tag types used by Octeon cores in its work. */
end_comment

begin_enum
enum|enum
name|lio_tag_type
block|{
name|LIO_ORDERED_TAG
init|=
literal|0
block|,
name|LIO_ATOMIC_TAG
init|=
literal|1
block|,
name|LIO_NULL_TAG
init|=
literal|2
block|,
name|LIO_NULL_NULL_TAG
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/* pre-defined host->NIC tag values */
end_comment

begin_define
define|#
directive|define
name|LIO_CONTROL
value|(0x11111110)
end_define

begin_define
define|#
directive|define
name|LIO_DATA
parameter_list|(
name|i
parameter_list|)
value|(0x11111111 + (i))
end_define

begin_comment
comment|/*  * Opcodes used by host driver/apps to perform operations on the core.  * These are used to identify the major subsystem that the operation  * is for.  */
end_comment

begin_define
define|#
directive|define
name|LIO_OPCODE_NIC
value|1
end_define

begin_comment
comment|/* used for NIC operations */
end_comment

begin_comment
comment|/*  * Subcodes are used by host driver/apps to identify the sub-operation  * for the core. They only need to by unique for a given subsystem.  */
end_comment

begin_define
define|#
directive|define
name|LIO_OPCODE_SUBCODE
parameter_list|(
name|op
parameter_list|,
name|sub
parameter_list|)
value|((((op)& 0x0f)<< 8) | ((sub)& 0x7f))
end_define

begin_comment
comment|/* OPCODE_CORE subcodes. For future use. */
end_comment

begin_comment
comment|/* OPCODE_NIC subcodes */
end_comment

begin_comment
comment|/* This subcode is sent by core PCI driver to indicate cores are ready. */
end_comment

begin_define
define|#
directive|define
name|LIO_OPCODE_NIC_CORE_DRV_ACTIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|LIO_OPCODE_NIC_NW_DATA
value|0x02
end_define

begin_comment
comment|/* network packet data */
end_comment

begin_define
define|#
directive|define
name|LIO_OPCODE_NIC_CMD
value|0x03
end_define

begin_define
define|#
directive|define
name|LIO_OPCODE_NIC_INFO
value|0x04
end_define

begin_define
define|#
directive|define
name|LIO_OPCODE_NIC_PORT_STATS
value|0x05
end_define

begin_define
define|#
directive|define
name|LIO_OPCODE_NIC_INTRMOD_CFG
value|0x08
end_define

begin_define
define|#
directive|define
name|LIO_OPCODE_NIC_IF_CFG
value|0x09
end_define

begin_define
define|#
directive|define
name|LIO_OPCODE_NIC_INTRMOD_PARAMS
value|0x0B
end_define

begin_comment
comment|/* Application codes advertised by the core driver initialization packet. */
end_comment

begin_define
define|#
directive|define
name|LIO_DRV_APP_START
value|0x0
end_define

begin_define
define|#
directive|define
name|LIO_DRV_APP_COUNT
value|0x2
end_define

begin_define
define|#
directive|define
name|LIO_DRV_NIC_APP
value|(LIO_DRV_APP_START + 0x1)
end_define

begin_define
define|#
directive|define
name|LIO_DRV_INVALID_APP
value|(LIO_DRV_APP_START + 0x2)
end_define

begin_define
define|#
directive|define
name|LIO_DRV_APP_END
value|(LIO_DRV_INVALID_APP - 1)
end_define

begin_define
define|#
directive|define
name|BYTES_PER_DHLEN_UNIT
value|8
end_define

begin_define
define|#
directive|define
name|SCR2_BIT_FW_LOADED
value|63
end_define

begin_define
define|#
directive|define
name|SCR2_BIT_FW_RELOADED
value|62
end_define

begin_function
specifier|static
specifier|inline
name|uint32_t
name|lio_incr_index
parameter_list|(
name|uint32_t
name|index
parameter_list|,
name|uint32_t
name|count
parameter_list|,
name|uint32_t
name|max
parameter_list|)
block|{
if|if
condition|(
operator|(
name|index
operator|+
name|count
operator|)
operator|>=
name|max
condition|)
name|index
operator|=
name|index
operator|+
name|count
operator|-
name|max
expr_stmt|;
else|else
name|index
operator|+=
name|count
expr_stmt|;
return|return
operator|(
name|index
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|LIO_BOARD_NAME
value|32
end_define

begin_define
define|#
directive|define
name|LIO_SERIAL_NUM_LEN
value|64
end_define

begin_comment
comment|/*  * Structure used by core driver to send indication that the Octeon  * application is ready.  */
end_comment

begin_struct
struct|struct
name|lio_core_setup
block|{
name|uint64_t
name|corefreq
decl_stmt|;
name|char
name|boardname
index|[
name|LIO_BOARD_NAME
index|]
decl_stmt|;
name|char
name|board_serial_number
index|[
name|LIO_SERIAL_NUM_LEN
index|]
decl_stmt|;
name|uint64_t
name|board_rev_major
decl_stmt|;
name|uint64_t
name|board_rev_minor
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*---------------------------  SCATTER GATHER ENTRY  -----------------------*/
end_comment

begin_comment
comment|/*  * The Scatter-Gather List Entry. The scatter or gather component used with  * a Octeon input instruction has this format.  */
end_comment

begin_struct
struct|struct
name|lio_sg_entry
block|{
comment|/* The first 64 bit gives the size of data in each dptr. */
union|union
block|{
name|uint16_t
name|size
index|[
literal|4
index|]
decl_stmt|;
name|uint64_t
name|size64
decl_stmt|;
block|}
name|u
union|;
comment|/* The 4 dptr pointers for this entry. */
name|uint64_t
name|ptr
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LIO_SG_ENTRY_SIZE
value|(sizeof(struct lio_sg_entry))
end_define

begin_comment
comment|/*  * \brief Add size to gather list  * @param sg_entry scatter/gather entry  * @param size size to add  * @param pos position to add it.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|lio_add_sg_size
parameter_list|(
name|struct
name|lio_sg_entry
modifier|*
name|sg_entry
parameter_list|,
name|uint16_t
name|size
parameter_list|,
name|uint32_t
name|pos
parameter_list|)
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|sg_entry
operator|->
name|u
operator|.
name|size
index|[
name|pos
index|]
operator|=
name|size
expr_stmt|;
else|#
directive|else
comment|/* BYTE_ORDER != BIG_ENDIAN  */
name|sg_entry
operator|->
name|u
operator|.
name|size
index|[
literal|3
operator|-
name|pos
index|]
operator|=
name|size
expr_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN  */
block|}
end_function

begin_comment
comment|/*------------------------- End Scatter/Gather ---------------------------*/
end_comment

begin_define
define|#
directive|define
name|LIO_FRM_HEADER_SIZE
value|22
end_define

begin_comment
comment|/* VLAN + Ethernet */
end_comment

begin_define
define|#
directive|define
name|LIO_MAX_FRM_SIZE
value|(16000 + LIO_FRM_HEADER_SIZE)
end_define

begin_define
define|#
directive|define
name|LIO_DEFAULT_FRM_SIZE
value|(1500 + LIO_FRM_HEADER_SIZE)
end_define

begin_comment
comment|/* NIC Command types */
end_comment

begin_define
define|#
directive|define
name|LIO_CMD_CHANGE_MTU
value|0x1
end_define

begin_define
define|#
directive|define
name|LIO_CMD_CHANGE_MACADDR
value|0x2
end_define

begin_define
define|#
directive|define
name|LIO_CMD_CHANGE_DEVFLAGS
value|0x3
end_define

begin_define
define|#
directive|define
name|LIO_CMD_RX_CTL
value|0x4
end_define

begin_define
define|#
directive|define
name|LIO_CMD_SET_MULTI_LIST
value|0x5
end_define

begin_comment
comment|/* command for setting the speed, duplex& autoneg */
end_comment

begin_define
define|#
directive|define
name|LIO_CMD_SET_SETTINGS
value|0x7
end_define

begin_define
define|#
directive|define
name|LIO_CMD_SET_FLOW_CTL
value|0x8
end_define

begin_define
define|#
directive|define
name|LIO_CMD_GPIO_ACCESS
value|0xA
end_define

begin_define
define|#
directive|define
name|LIO_CMD_LRO_ENABLE
value|0xB
end_define

begin_define
define|#
directive|define
name|LIO_CMD_LRO_DISABLE
value|0xC
end_define

begin_define
define|#
directive|define
name|LIO_CMD_SET_RSS
value|0xD
end_define

begin_define
define|#
directive|define
name|LIO_CMD_TNL_RX_CSUM_CTL
value|0x10
end_define

begin_define
define|#
directive|define
name|LIO_CMD_TNL_TX_CSUM_CTL
value|0x11
end_define

begin_define
define|#
directive|define
name|LIO_CMD_VERBOSE_ENABLE
value|0x14
end_define

begin_define
define|#
directive|define
name|LIO_CMD_VERBOSE_DISABLE
value|0x15
end_define

begin_define
define|#
directive|define
name|LIO_CMD_VLAN_FILTER_CTL
value|0x16
end_define

begin_define
define|#
directive|define
name|LIO_CMD_ADD_VLAN_FILTER
value|0x17
end_define

begin_define
define|#
directive|define
name|LIO_CMD_DEL_VLAN_FILTER
value|0x18
end_define

begin_define
define|#
directive|define
name|LIO_CMD_VXLAN_PORT_CONFIG
value|0x19
end_define

begin_define
define|#
directive|define
name|LIO_CMD_ID_ACTIVE
value|0x1a
end_define

begin_define
define|#
directive|define
name|LIO_CMD_SET_FNV
value|0x1d
end_define

begin_define
define|#
directive|define
name|LIO_CMD_PKT_STEERING_CTL
value|0x1e
end_define

begin_define
define|#
directive|define
name|LIO_CMD_QUEUE_COUNT_CTL
value|0x1f
end_define

begin_define
define|#
directive|define
name|LIO_CMD_VXLAN_PORT_ADD
value|0x0
end_define

begin_define
define|#
directive|define
name|LIO_CMD_VXLAN_PORT_DEL
value|0x1
end_define

begin_define
define|#
directive|define
name|LIO_CMD_RXCSUM_ENABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|LIO_CMD_RXCSUM_DISABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|LIO_CMD_TXCSUM_ENABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|LIO_CMD_TXCSUM_DISABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|LIO_CMD_FNV_ENABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|LIO_CMD_FNV_DISABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|LIO_CMD_PKT_STEERING_ENABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|LIO_CMD_PKT_STEERING_DISABLE
value|0x1
end_define

begin_comment
comment|/* RX(packets coming from wire) Checksum verification flags */
end_comment

begin_comment
comment|/* TCP/UDP csum */
end_comment

begin_define
define|#
directive|define
name|LIO_L4SUM_VERIFIED
value|0x1
end_define

begin_define
define|#
directive|define
name|LIO_IPSUM_VERIFIED
value|0x2
end_define

begin_comment
comment|/*LROIPV4 and LROIPV6 Flags*/
end_comment

begin_define
define|#
directive|define
name|LIO_LROIPV4
value|0x1
end_define

begin_define
define|#
directive|define
name|LIO_LROIPV6
value|0x2
end_define

begin_comment
comment|/* Interface flags communicated between host driver and core app. */
end_comment

begin_enum
enum|enum
name|lio_ifflags
block|{
name|LIO_IFFLAG_PROMISC
init|=
literal|0x01
block|,
name|LIO_IFFLAG_ALLMULTI
init|=
literal|0x02
block|,
name|LIO_IFFLAG_MULTICAST
init|=
literal|0x04
block|,
name|LIO_IFFLAG_BROADCAST
init|=
literal|0x08
block|,
name|LIO_IFFLAG_UNICAST
init|=
literal|0x10
block|}
enum|;
end_enum

begin_comment
comment|/*  *   wqe  *  ---------------  0  * |  wqe  word0-3 |  *  ---------------  32  * |    PCI IH     |  *  ---------------  40  * |     RPTR      |  *  ---------------  48  * |    PCI IRH    |  *  ---------------  56  * |  OCT_NET_CMD  |  *  ---------------  64  * | Addtl 8-BData |  * |               |  *  ---------------  */
end_comment

begin_union
union|union
name|octeon_cmd
block|{
name|uint64_t
name|cmd64
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint64_t
name|cmd
range|:
literal|5
decl_stmt|;
name|uint64_t
name|more
range|:
literal|6
decl_stmt|;
comment|/* How many udd words follow the command */
name|uint64_t
name|reserved
range|:
literal|29
decl_stmt|;
name|uint64_t
name|param1
range|:
literal|16
decl_stmt|;
name|uint64_t
name|param2
range|:
literal|8
decl_stmt|;
else|#
directive|else
comment|/* BYTE_ORDER != BIG_ENDIAN */
name|uint64_t
name|param2
range|:
literal|8
decl_stmt|;
name|uint64_t
name|param1
range|:
literal|16
decl_stmt|;
name|uint64_t
name|reserved
range|:
literal|29
decl_stmt|;
name|uint64_t
name|more
range|:
literal|6
decl_stmt|;
name|uint64_t
name|cmd
range|:
literal|5
decl_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN */
block|}
name|s
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|OCTEON_CMD_SIZE
value|(sizeof(union octeon_cmd))
end_define

begin_comment
comment|/* pkiih3 + irh + ossp[0] + ossp[1] + rdp + rptr = 40 bytes */
end_comment

begin_define
define|#
directive|define
name|LIO_SOFTCMDRESP_IH3
value|(40 + 8)
end_define

begin_define
define|#
directive|define
name|LIO_PCICMD_O3
value|(24 + 8)
end_define

begin_comment
comment|/* Instruction Header(DPI) - for OCTEON-III models */
end_comment

begin_struct
struct|struct
name|octeon_instr_ih3
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
comment|/* Reserved3 */
name|uint64_t
name|reserved3
range|:
literal|1
decl_stmt|;
comment|/* Gather indicator 1=gather */
name|uint64_t
name|gather
range|:
literal|1
decl_stmt|;
comment|/* Data length OR no. of entries in gather list */
name|uint64_t
name|dlengsz
range|:
literal|14
decl_stmt|;
comment|/* Front Data size */
name|uint64_t
name|fsz
range|:
literal|6
decl_stmt|;
comment|/* Reserved2 */
name|uint64_t
name|reserved2
range|:
literal|4
decl_stmt|;
comment|/* PKI port kind - PKIND */
name|uint64_t
name|pkind
range|:
literal|6
decl_stmt|;
comment|/* Reserved1 */
name|uint64_t
name|reserved1
range|:
literal|32
decl_stmt|;
else|#
directive|else
comment|/* BYTE_ORDER != BIG_ENDIAN */
comment|/* Reserved1 */
name|uint64_t
name|reserved1
range|:
literal|32
decl_stmt|;
comment|/* PKI port kind - PKIND */
name|uint64_t
name|pkind
range|:
literal|6
decl_stmt|;
comment|/* Reserved2 */
name|uint64_t
name|reserved2
range|:
literal|4
decl_stmt|;
comment|/* Front Data size */
name|uint64_t
name|fsz
range|:
literal|6
decl_stmt|;
comment|/* Data length OR no. of entries in gather list */
name|uint64_t
name|dlengsz
range|:
literal|14
decl_stmt|;
comment|/* Gather indicator 1=gather */
name|uint64_t
name|gather
range|:
literal|1
decl_stmt|;
comment|/* Reserved3 */
name|uint64_t
name|reserved3
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN */
block|}
struct|;
end_struct

begin_comment
comment|/* Optional PKI Instruction Header(PKI IH) - for OCTEON-III models */
end_comment

begin_comment
comment|/* BIG ENDIAN format.   */
end_comment

begin_struct
struct|struct
name|octeon_instr_pki_ih3
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
comment|/* Wider bit */
name|uint64_t
name|w
range|:
literal|1
decl_stmt|;
comment|/* Raw mode indicator 1 = RAW */
name|uint64_t
name|raw
range|:
literal|1
decl_stmt|;
comment|/* Use Tag */
name|uint64_t
name|utag
range|:
literal|1
decl_stmt|;
comment|/* Use QPG */
name|uint64_t
name|uqpg
range|:
literal|1
decl_stmt|;
comment|/* Reserved2 */
name|uint64_t
name|reserved2
range|:
literal|1
decl_stmt|;
comment|/* Parse Mode */
name|uint64_t
name|pm
range|:
literal|3
decl_stmt|;
comment|/* Skip Length */
name|uint64_t
name|sl
range|:
literal|8
decl_stmt|;
comment|/* Use Tag Type */
name|uint64_t
name|utt
range|:
literal|1
decl_stmt|;
comment|/* Tag type */
name|uint64_t
name|tagtype
range|:
literal|2
decl_stmt|;
comment|/* Reserved1 */
name|uint64_t
name|reserved1
range|:
literal|2
decl_stmt|;
comment|/* QPG Value */
name|uint64_t
name|qpg
range|:
literal|11
decl_stmt|;
comment|/* Tag Value */
name|uint64_t
name|tag
range|:
literal|32
decl_stmt|;
else|#
directive|else
comment|/* BYTE_ORDER != BIG_ENDIAN */
comment|/* Tag Value */
name|uint64_t
name|tag
range|:
literal|32
decl_stmt|;
comment|/* QPG Value */
name|uint64_t
name|qpg
range|:
literal|11
decl_stmt|;
comment|/* Reserved1 */
name|uint64_t
name|reserved1
range|:
literal|2
decl_stmt|;
comment|/* Tag type */
name|uint64_t
name|tagtype
range|:
literal|2
decl_stmt|;
comment|/* Use Tag Type */
name|uint64_t
name|utt
range|:
literal|1
decl_stmt|;
comment|/* Skip Length */
name|uint64_t
name|sl
range|:
literal|8
decl_stmt|;
comment|/* Parse Mode */
name|uint64_t
name|pm
range|:
literal|3
decl_stmt|;
comment|/* Reserved2 */
name|uint64_t
name|reserved2
range|:
literal|1
decl_stmt|;
comment|/* Use QPG */
name|uint64_t
name|uqpg
range|:
literal|1
decl_stmt|;
comment|/* Use Tag */
name|uint64_t
name|utag
range|:
literal|1
decl_stmt|;
comment|/* Raw mode indicator 1 = RAW */
name|uint64_t
name|raw
range|:
literal|1
decl_stmt|;
comment|/* Wider bit */
name|uint64_t
name|w
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN */
block|}
struct|;
end_struct

begin_comment
comment|/* Input Request Header */
end_comment

begin_struct
struct|struct
name|octeon_instr_irh
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint64_t
name|opcode
range|:
literal|4
decl_stmt|;
name|uint64_t
name|rflag
range|:
literal|1
decl_stmt|;
name|uint64_t
name|subcode
range|:
literal|7
decl_stmt|;
name|uint64_t
name|vlan
range|:
literal|12
decl_stmt|;
name|uint64_t
name|priority
range|:
literal|3
decl_stmt|;
name|uint64_t
name|reserved
range|:
literal|5
decl_stmt|;
name|uint64_t
name|ossp
range|:
literal|32
decl_stmt|;
comment|/* opcode/subcode specific parameters */
else|#
directive|else
comment|/* BYTE_ORDER != BIG_ENDIAN */
name|uint64_t
name|ossp
range|:
literal|32
decl_stmt|;
comment|/* opcode/subcode specific parameters */
name|uint64_t
name|reserved
range|:
literal|5
decl_stmt|;
name|uint64_t
name|priority
range|:
literal|3
decl_stmt|;
name|uint64_t
name|vlan
range|:
literal|12
decl_stmt|;
name|uint64_t
name|subcode
range|:
literal|7
decl_stmt|;
name|uint64_t
name|rflag
range|:
literal|1
decl_stmt|;
name|uint64_t
name|opcode
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN */
block|}
struct|;
end_struct

begin_comment
comment|/* Return Data Parameters */
end_comment

begin_struct
struct|struct
name|octeon_instr_rdp
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint64_t
name|reserved
range|:
literal|49
decl_stmt|;
name|uint64_t
name|pcie_port
range|:
literal|3
decl_stmt|;
name|uint64_t
name|rlen
range|:
literal|12
decl_stmt|;
else|#
directive|else
comment|/* BYTE_ORDER != BIG_ENDIAN */
name|uint64_t
name|rlen
range|:
literal|12
decl_stmt|;
name|uint64_t
name|pcie_port
range|:
literal|3
decl_stmt|;
name|uint64_t
name|reserved
range|:
literal|49
decl_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN */
block|}
struct|;
end_struct

begin_comment
comment|/* Receive Header */
end_comment

begin_union
union|union
name|octeon_rh
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint64_t
name|rh64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|opcode
range|:
literal|4
decl_stmt|;
name|uint64_t
name|subcode
range|:
literal|8
decl_stmt|;
name|uint64_t
name|len
range|:
literal|3
decl_stmt|;
comment|/* additional 64-bit words */
name|uint64_t
name|reserved
range|:
literal|17
decl_stmt|;
name|uint64_t
name|ossp
range|:
literal|32
decl_stmt|;
comment|/* opcode/subcode specific parameters */
block|}
name|r
struct|;
struct|struct
block|{
name|uint64_t
name|opcode
range|:
literal|4
decl_stmt|;
name|uint64_t
name|subcode
range|:
literal|8
decl_stmt|;
name|uint64_t
name|len
range|:
literal|3
decl_stmt|;
comment|/* additional 64-bit words */
name|uint64_t
name|extra
range|:
literal|28
decl_stmt|;
name|uint64_t
name|vlan
range|:
literal|12
decl_stmt|;
name|uint64_t
name|priority
range|:
literal|3
decl_stmt|;
name|uint64_t
name|csum_verified
range|:
literal|3
decl_stmt|;
comment|/* checksum verified. */
name|uint64_t
name|has_hwtstamp
range|:
literal|1
decl_stmt|;
comment|/* Has hardware timestamp. 1 = yes. */
name|uint64_t
name|encap_on
range|:
literal|1
decl_stmt|;
name|uint64_t
name|has_hash
range|:
literal|1
decl_stmt|;
comment|/* Has hash (rth or rss). 1 = yes. */
block|}
name|r_dh
struct|;
struct|struct
block|{
name|uint64_t
name|opcode
range|:
literal|4
decl_stmt|;
name|uint64_t
name|subcode
range|:
literal|8
decl_stmt|;
name|uint64_t
name|len
range|:
literal|3
decl_stmt|;
comment|/* additional 64-bit words */
name|uint64_t
name|reserved
range|:
literal|11
decl_stmt|;
name|uint64_t
name|num_gmx_ports
range|:
literal|8
decl_stmt|;
name|uint64_t
name|max_nic_ports
range|:
literal|10
decl_stmt|;
name|uint64_t
name|app_cap_flags
range|:
literal|4
decl_stmt|;
name|uint64_t
name|app_mode
range|:
literal|8
decl_stmt|;
name|uint64_t
name|pkind
range|:
literal|8
decl_stmt|;
block|}
name|r_core_drv_init
struct|;
struct|struct
block|{
name|uint64_t
name|opcode
range|:
literal|4
decl_stmt|;
name|uint64_t
name|subcode
range|:
literal|8
decl_stmt|;
name|uint64_t
name|len
range|:
literal|3
decl_stmt|;
comment|/* additional 64-bit words */
name|uint64_t
name|reserved
range|:
literal|8
decl_stmt|;
name|uint64_t
name|extra
range|:
literal|25
decl_stmt|;
name|uint64_t
name|gmxport
range|:
literal|16
decl_stmt|;
block|}
name|r_nic_info
struct|;
else|#
directive|else
comment|/* BYTE_ORDER != BIG_ENDIAN */
name|uint64_t
name|rh64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|ossp
range|:
literal|32
decl_stmt|;
comment|/* opcode/subcode specific parameters */
name|uint64_t
name|reserved
range|:
literal|17
decl_stmt|;
name|uint64_t
name|len
range|:
literal|3
decl_stmt|;
comment|/* additional 64-bit words */
name|uint64_t
name|subcode
range|:
literal|8
decl_stmt|;
name|uint64_t
name|opcode
range|:
literal|4
decl_stmt|;
block|}
name|r
struct|;
struct|struct
block|{
name|uint64_t
name|has_hash
range|:
literal|1
decl_stmt|;
comment|/* Has hash (rth or rss). 1 = yes. */
name|uint64_t
name|encap_on
range|:
literal|1
decl_stmt|;
name|uint64_t
name|has_hwtstamp
range|:
literal|1
decl_stmt|;
comment|/* 1 = has hwtstamp */
name|uint64_t
name|csum_verified
range|:
literal|3
decl_stmt|;
comment|/* checksum verified. */
name|uint64_t
name|priority
range|:
literal|3
decl_stmt|;
name|uint64_t
name|vlan
range|:
literal|12
decl_stmt|;
name|uint64_t
name|extra
range|:
literal|28
decl_stmt|;
name|uint64_t
name|len
range|:
literal|3
decl_stmt|;
comment|/* additional 64-bit words */
name|uint64_t
name|subcode
range|:
literal|8
decl_stmt|;
name|uint64_t
name|opcode
range|:
literal|4
decl_stmt|;
block|}
name|r_dh
struct|;
struct|struct
block|{
name|uint64_t
name|pkind
range|:
literal|8
decl_stmt|;
name|uint64_t
name|app_mode
range|:
literal|8
decl_stmt|;
name|uint64_t
name|app_cap_flags
range|:
literal|4
decl_stmt|;
name|uint64_t
name|max_nic_ports
range|:
literal|10
decl_stmt|;
name|uint64_t
name|num_gmx_ports
range|:
literal|8
decl_stmt|;
name|uint64_t
name|reserved
range|:
literal|11
decl_stmt|;
name|uint64_t
name|len
range|:
literal|3
decl_stmt|;
comment|/* additional 64-bit words */
name|uint64_t
name|subcode
range|:
literal|8
decl_stmt|;
name|uint64_t
name|opcode
range|:
literal|4
decl_stmt|;
block|}
name|r_core_drv_init
struct|;
struct|struct
block|{
name|uint64_t
name|gmxport
range|:
literal|16
decl_stmt|;
name|uint64_t
name|extra
range|:
literal|25
decl_stmt|;
name|uint64_t
name|reserved
range|:
literal|8
decl_stmt|;
name|uint64_t
name|len
range|:
literal|3
decl_stmt|;
comment|/* additional 64-bit words */
name|uint64_t
name|subcode
range|:
literal|8
decl_stmt|;
name|uint64_t
name|opcode
range|:
literal|4
decl_stmt|;
block|}
name|r_nic_info
struct|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN */
block|}
union|;
end_union

begin_define
define|#
directive|define
name|OCTEON_RH_SIZE
value|(sizeof(union  octeon_rh))
end_define

begin_union
union|union
name|octeon_packet_params
block|{
name|uint32_t
name|pkt_params32
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint32_t
name|reserved
range|:
literal|24
decl_stmt|;
name|uint32_t
name|ip_csum
range|:
literal|1
decl_stmt|;
comment|/* Perform IP header checksum(s) */
comment|/* Perform Outer transport header checksum */
name|uint32_t
name|transport_csum
range|:
literal|1
decl_stmt|;
comment|/* Find tunnel, and perform transport csum. */
name|uint32_t
name|tnl_csum
range|:
literal|1
decl_stmt|;
name|uint32_t
name|tsflag
range|:
literal|1
decl_stmt|;
comment|/* Timestamp this packet */
name|uint32_t
name|ipsec_ops
range|:
literal|4
decl_stmt|;
comment|/* IPsec operation */
else|#
directive|else
comment|/* BYTE_ORDER != BIG_ENDIAN */
name|uint32_t
name|ipsec_ops
range|:
literal|4
decl_stmt|;
name|uint32_t
name|tsflag
range|:
literal|1
decl_stmt|;
name|uint32_t
name|tnl_csum
range|:
literal|1
decl_stmt|;
name|uint32_t
name|transport_csum
range|:
literal|1
decl_stmt|;
name|uint32_t
name|ip_csum
range|:
literal|1
decl_stmt|;
name|uint32_t
name|reserved
range|:
literal|24
decl_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN */
block|}
name|s
struct|;
block|}
union|;
end_union

begin_comment
comment|/* Status of a RGMII Link on Octeon as seen by core driver. */
end_comment

begin_union
union|union
name|octeon_link_status
block|{
name|uint64_t
name|link_status64
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint64_t
name|duplex
range|:
literal|8
decl_stmt|;
name|uint64_t
name|mtu
range|:
literal|16
decl_stmt|;
name|uint64_t
name|speed
range|:
literal|16
decl_stmt|;
name|uint64_t
name|link_up
range|:
literal|1
decl_stmt|;
name|uint64_t
name|autoneg
range|:
literal|1
decl_stmt|;
name|uint64_t
name|if_mode
range|:
literal|5
decl_stmt|;
name|uint64_t
name|pause
range|:
literal|1
decl_stmt|;
name|uint64_t
name|flashing
range|:
literal|1
decl_stmt|;
name|uint64_t
name|reserved
range|:
literal|15
decl_stmt|;
else|#
directive|else
comment|/* BYTE_ORDER != BIG_ENDIAN */
name|uint64_t
name|reserved
range|:
literal|15
decl_stmt|;
name|uint64_t
name|flashing
range|:
literal|1
decl_stmt|;
name|uint64_t
name|pause
range|:
literal|1
decl_stmt|;
name|uint64_t
name|if_mode
range|:
literal|5
decl_stmt|;
name|uint64_t
name|autoneg
range|:
literal|1
decl_stmt|;
name|uint64_t
name|link_up
range|:
literal|1
decl_stmt|;
name|uint64_t
name|speed
range|:
literal|16
decl_stmt|;
name|uint64_t
name|mtu
range|:
literal|16
decl_stmt|;
name|uint64_t
name|duplex
range|:
literal|8
decl_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN */
block|}
name|s
struct|;
block|}
union|;
end_union

begin_comment
comment|/* The txpciq info passed to host from the firmware */
end_comment

begin_union
union|union
name|octeon_txpciq
block|{
name|uint64_t
name|txpciq64
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint64_t
name|q_no
range|:
literal|8
decl_stmt|;
name|uint64_t
name|port
range|:
literal|8
decl_stmt|;
name|uint64_t
name|pkind
range|:
literal|6
decl_stmt|;
name|uint64_t
name|use_qpg
range|:
literal|1
decl_stmt|;
name|uint64_t
name|qpg
range|:
literal|11
decl_stmt|;
name|uint64_t
name|aura_num
range|:
literal|10
decl_stmt|;
name|uint64_t
name|reserved
range|:
literal|20
decl_stmt|;
else|#
directive|else
comment|/* BYTE_ORDER != BIG_ENDIAN */
name|uint64_t
name|reserved
range|:
literal|20
decl_stmt|;
name|uint64_t
name|aura_num
range|:
literal|10
decl_stmt|;
name|uint64_t
name|qpg
range|:
literal|11
decl_stmt|;
name|uint64_t
name|use_qpg
range|:
literal|1
decl_stmt|;
name|uint64_t
name|pkind
range|:
literal|6
decl_stmt|;
name|uint64_t
name|port
range|:
literal|8
decl_stmt|;
name|uint64_t
name|q_no
range|:
literal|8
decl_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN */
block|}
name|s
struct|;
block|}
union|;
end_union

begin_comment
comment|/* The rxpciq info passed to host from the firmware */
end_comment

begin_union
union|union
name|octeon_rxpciq
block|{
name|uint64_t
name|rxpciq64
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint64_t
name|q_no
range|:
literal|8
decl_stmt|;
name|uint64_t
name|reserved
range|:
literal|56
decl_stmt|;
else|#
directive|else
comment|/* BYTE_ORDER != BIG_ENDIAN */
name|uint64_t
name|reserved
range|:
literal|56
decl_stmt|;
name|uint64_t
name|q_no
range|:
literal|8
decl_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN */
block|}
name|s
struct|;
block|}
union|;
end_union

begin_comment
comment|/* Information for a OCTEON ethernet interface shared between core& host. */
end_comment

begin_struct
struct|struct
name|octeon_link_info
block|{
name|union
name|octeon_link_status
name|link
decl_stmt|;
name|uint64_t
name|hw_addr
decl_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint64_t
name|gmxport
range|:
literal|16
decl_stmt|;
name|uint64_t
name|macaddr_is_admin_asgnd
range|:
literal|1
decl_stmt|;
name|uint64_t
name|vlan_is_admin_assigned
range|:
literal|1
decl_stmt|;
name|uint64_t
name|rsvd
range|:
literal|30
decl_stmt|;
name|uint64_t
name|num_txpciq
range|:
literal|8
decl_stmt|;
name|uint64_t
name|num_rxpciq
range|:
literal|8
decl_stmt|;
else|#
directive|else
comment|/* BYTE_ORDER != BIG_ENDIAN */
name|uint64_t
name|num_rxpciq
range|:
literal|8
decl_stmt|;
name|uint64_t
name|num_txpciq
range|:
literal|8
decl_stmt|;
name|uint64_t
name|rsvd
range|:
literal|30
decl_stmt|;
name|uint64_t
name|vlan_is_admin_assigned
range|:
literal|1
decl_stmt|;
name|uint64_t
name|macaddr_is_admin_asgnd
range|:
literal|1
decl_stmt|;
name|uint64_t
name|gmxport
range|:
literal|16
decl_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN */
name|union
name|octeon_txpciq
name|txpciq
index|[
name|LIO_MAX_IOQS_PER_NICIF
index|]
decl_stmt|;
name|union
name|octeon_rxpciq
name|rxpciq
index|[
name|LIO_MAX_IOQS_PER_NICIF
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|octeon_if_cfg_info
block|{
name|uint64_t
name|iqmask
decl_stmt|;
comment|/* mask for IQs enabled for  the port */
name|uint64_t
name|oqmask
decl_stmt|;
comment|/* mask for OQs enabled for the port */
name|struct
name|octeon_link_info
name|linfo
decl_stmt|;
comment|/* initial link information */
name|char
name|lio_firmware_version
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Stats for each NIC port in RX direction. */
end_comment

begin_struct
struct|struct
name|octeon_rx_stats
block|{
comment|/* link-level stats */
name|uint64_t
name|total_rcvd
decl_stmt|;
name|uint64_t
name|bytes_rcvd
decl_stmt|;
name|uint64_t
name|total_bcst
decl_stmt|;
name|uint64_t
name|total_mcst
decl_stmt|;
name|uint64_t
name|runts
decl_stmt|;
name|uint64_t
name|ctl_rcvd
decl_stmt|;
name|uint64_t
name|fifo_err
decl_stmt|;
comment|/* Accounts for over/under-run of buffers */
name|uint64_t
name|dmac_drop
decl_stmt|;
name|uint64_t
name|fcs_err
decl_stmt|;
name|uint64_t
name|jabber_err
decl_stmt|;
name|uint64_t
name|l2_err
decl_stmt|;
name|uint64_t
name|frame_err
decl_stmt|;
comment|/* firmware stats */
name|uint64_t
name|fw_total_rcvd
decl_stmt|;
name|uint64_t
name|fw_total_fwd
decl_stmt|;
name|uint64_t
name|fw_total_fwd_bytes
decl_stmt|;
name|uint64_t
name|fw_err_pko
decl_stmt|;
name|uint64_t
name|fw_err_link
decl_stmt|;
name|uint64_t
name|fw_err_drop
decl_stmt|;
name|uint64_t
name|fw_rx_vxlan
decl_stmt|;
name|uint64_t
name|fw_rx_vxlan_err
decl_stmt|;
comment|/* LRO */
name|uint64_t
name|fw_lro_pkts
decl_stmt|;
comment|/* Number of packets that are LROed */
name|uint64_t
name|fw_lro_octs
decl_stmt|;
comment|/* Number of octets that are LROed */
name|uint64_t
name|fw_total_lro
decl_stmt|;
comment|/* Number of LRO packets formed */
name|uint64_t
name|fw_lro_aborts
decl_stmt|;
comment|/* Number of times lRO of packet aborted */
name|uint64_t
name|fw_lro_aborts_port
decl_stmt|;
name|uint64_t
name|fw_lro_aborts_seq
decl_stmt|;
name|uint64_t
name|fw_lro_aborts_tsval
decl_stmt|;
name|uint64_t
name|fw_lro_aborts_timer
decl_stmt|;
comment|/* intrmod: packet forward rate */
name|uint64_t
name|fwd_rate
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Stats for each NIC port in RX direction. */
end_comment

begin_struct
struct|struct
name|octeon_tx_stats
block|{
comment|/* link-level stats */
name|uint64_t
name|total_pkts_sent
decl_stmt|;
name|uint64_t
name|total_bytes_sent
decl_stmt|;
name|uint64_t
name|mcast_pkts_sent
decl_stmt|;
name|uint64_t
name|bcast_pkts_sent
decl_stmt|;
name|uint64_t
name|ctl_sent
decl_stmt|;
name|uint64_t
name|one_collision_sent
decl_stmt|;
comment|/* Packets sent after one collision */
name|uint64_t
name|multi_collision_sent
decl_stmt|;
comment|/* Packets sent after multiple collision */
name|uint64_t
name|max_collision_fail
decl_stmt|;
comment|/* Packets not sent due to max collisions */
name|uint64_t
name|max_deferral_fail
decl_stmt|;
comment|/* Packets not sent due to max deferrals */
name|uint64_t
name|fifo_err
decl_stmt|;
comment|/* Accounts for over/under-run of buffers */
name|uint64_t
name|runts
decl_stmt|;
name|uint64_t
name|total_collisions
decl_stmt|;
comment|/* Total number of collisions detected */
comment|/* firmware stats */
name|uint64_t
name|fw_total_sent
decl_stmt|;
name|uint64_t
name|fw_total_fwd
decl_stmt|;
name|uint64_t
name|fw_total_fwd_bytes
decl_stmt|;
name|uint64_t
name|fw_err_pko
decl_stmt|;
name|uint64_t
name|fw_err_link
decl_stmt|;
name|uint64_t
name|fw_err_drop
decl_stmt|;
name|uint64_t
name|fw_err_tso
decl_stmt|;
name|uint64_t
name|fw_tso
decl_stmt|;
comment|/* number of tso requests */
name|uint64_t
name|fw_tso_fwd
decl_stmt|;
comment|/* number of packets segmented in tso */
name|uint64_t
name|fw_tx_vxlan
decl_stmt|;
name|uint64_t
name|fw_err_pki
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|octeon_link_stats
block|{
name|struct
name|octeon_rx_stats
name|fromwire
decl_stmt|;
name|struct
name|octeon_tx_stats
name|fromhost
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|int
name|lio_opcode_slow_path
parameter_list|(
name|union
name|octeon_rh
modifier|*
name|rh
parameter_list|)
block|{
name|uint16_t
name|subcode1
decl_stmt|,
name|subcode2
decl_stmt|;
name|subcode1
operator|=
name|LIO_OPCODE_SUBCODE
argument_list|(
operator|(
name|rh
operator|)
operator|->
name|r
operator|.
name|opcode
argument_list|,
operator|(
name|rh
operator|)
operator|->
name|r
operator|.
name|subcode
argument_list|)
expr_stmt|;
name|subcode2
operator|=
name|LIO_OPCODE_SUBCODE
argument_list|(
name|LIO_OPCODE_NIC
argument_list|,
name|LIO_OPCODE_NIC_NW_DATA
argument_list|)
expr_stmt|;
return|return
operator|(
name|subcode2
operator|!=
name|subcode1
operator|)
return|;
block|}
end_function

begin_struct
struct|struct
name|octeon_mdio_cmd
block|{
name|uint64_t
name|op
decl_stmt|;
name|uint64_t
name|mdio_addr
decl_stmt|;
name|uint64_t
name|value1
decl_stmt|;
name|uint64_t
name|value2
decl_stmt|;
name|uint64_t
name|value3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|octeon_intrmod_cfg
block|{
name|uint64_t
name|rx_enable
decl_stmt|;
name|uint64_t
name|tx_enable
decl_stmt|;
name|uint64_t
name|check_intrvl
decl_stmt|;
name|uint64_t
name|maxpkt_ratethr
decl_stmt|;
name|uint64_t
name|minpkt_ratethr
decl_stmt|;
name|uint64_t
name|rx_maxcnt_trigger
decl_stmt|;
name|uint64_t
name|rx_mincnt_trigger
decl_stmt|;
name|uint64_t
name|rx_maxtmr_trigger
decl_stmt|;
name|uint64_t
name|rx_mintmr_trigger
decl_stmt|;
name|uint64_t
name|tx_mincnt_trigger
decl_stmt|;
name|uint64_t
name|tx_maxcnt_trigger
decl_stmt|;
name|uint64_t
name|rx_frames
decl_stmt|;
name|uint64_t
name|tx_frames
decl_stmt|;
name|uint64_t
name|rx_usecs
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LIO_BASE_QUEUE_NOT_REQUESTED
value|65535
end_define

begin_union
union|union
name|octeon_if_cfg
block|{
name|uint64_t
name|if_cfg64
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint64_t
name|base_queue
range|:
literal|16
decl_stmt|;
name|uint64_t
name|num_iqueues
range|:
literal|16
decl_stmt|;
name|uint64_t
name|num_oqueues
range|:
literal|16
decl_stmt|;
name|uint64_t
name|gmx_port_id
range|:
literal|8
decl_stmt|;
name|uint64_t
name|vf_id
range|:
literal|8
decl_stmt|;
else|#
directive|else
comment|/* BYTE_ORDER != BIG_ENDIAN */
name|uint64_t
name|vf_id
range|:
literal|8
decl_stmt|;
name|uint64_t
name|gmx_port_id
range|:
literal|8
decl_stmt|;
name|uint64_t
name|num_oqueues
range|:
literal|16
decl_stmt|;
name|uint64_t
name|num_iqueues
range|:
literal|16
decl_stmt|;
name|uint64_t
name|base_queue
range|:
literal|16
decl_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN */
block|}
name|s
struct|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LIO_COMMON_H__ */
end_comment

end_unit

