begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013-2016 Qlogic Corporation  * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * File: ql_hw.h  * Author : David C Somayajulu, Qlogic Corporation, Aliso Viejo, CA 92656.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QL_HW_H_
end_ifndef

begin_define
define|#
directive|define
name|_QL_HW_H_
end_define

begin_comment
comment|/*  * PCIe Registers; Direct Mapped; Offsets from BAR0  */
end_comment

begin_comment
comment|/*  * Register offsets for QLE8030  */
end_comment

begin_comment
comment|/*  * Firmware Mailbox Registers  *	0 thru 511; offsets 0x800 thru 0xFFC; 32bits each  */
end_comment

begin_define
define|#
directive|define
name|Q8_FW_MBOX0
value|0x00000800
end_define

begin_define
define|#
directive|define
name|Q8_FW_MBOX511
value|0x00000FFC
end_define

begin_comment
comment|/*  * Host Mailbox Registers  *	0 thru 511; offsets 0x000 thru 0x7FC; 32bits each  */
end_comment

begin_define
define|#
directive|define
name|Q8_HOST_MBOX0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|Q8_HOST_MBOX511
value|0x000007FC
end_define

begin_define
define|#
directive|define
name|Q8_MBOX_INT_ENABLE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|Q8_MBOX_INT_MASK_MSIX
value|0x00001200
end_define

begin_define
define|#
directive|define
name|Q8_MBOX_INT_LEGACY
value|0x00003010
end_define

begin_define
define|#
directive|define
name|Q8_HOST_MBOX_CNTRL
value|0x00003038
end_define

begin_define
define|#
directive|define
name|Q8_FW_MBOX_CNTRL
value|0x0000303C
end_define

begin_define
define|#
directive|define
name|Q8_PEG_HALT_STATUS1
value|0x000034A8
end_define

begin_define
define|#
directive|define
name|Q8_PEG_HALT_STATUS2
value|0x000034AC
end_define

begin_define
define|#
directive|define
name|Q8_FIRMWARE_HEARTBEAT
value|0x000034B0
end_define

begin_define
define|#
directive|define
name|Q8_FLASH_LOCK_ID
value|0x00003500
end_define

begin_define
define|#
directive|define
name|Q8_DRIVER_LOCK_ID
value|0x00003504
end_define

begin_define
define|#
directive|define
name|Q8_FW_CAPABILITIES
value|0x00003528
end_define

begin_define
define|#
directive|define
name|Q8_FW_VER_MAJOR
value|0x00003550
end_define

begin_define
define|#
directive|define
name|Q8_FW_VER_MINOR
value|0x00003554
end_define

begin_define
define|#
directive|define
name|Q8_FW_VER_SUB
value|0x00003558
end_define

begin_define
define|#
directive|define
name|Q8_BOOTLD_ADDR
value|0x0000355C
end_define

begin_define
define|#
directive|define
name|Q8_BOOTLD_SIZE
value|0x00003560
end_define

begin_define
define|#
directive|define
name|Q8_FW_IMAGE_ADDR
value|0x00003564
end_define

begin_define
define|#
directive|define
name|Q8_FW_BUILD_NUMBER
value|0x00003568
end_define

begin_define
define|#
directive|define
name|Q8_FW_IMAGE_VALID
value|0x000035FC
end_define

begin_define
define|#
directive|define
name|Q8_CMDPEG_STATE
value|0x00003650
end_define

begin_define
define|#
directive|define
name|Q8_LINK_STATE
value|0x00003698
end_define

begin_define
define|#
directive|define
name|Q8_LINK_STATE_2
value|0x0000369C
end_define

begin_define
define|#
directive|define
name|Q8_LINK_SPEED_0
value|0x000036E0
end_define

begin_define
define|#
directive|define
name|Q8_LINK_SPEED_1
value|0x000036E4
end_define

begin_define
define|#
directive|define
name|Q8_LINK_SPEED_2
value|0x000036E8
end_define

begin_define
define|#
directive|define
name|Q8_LINK_SPEED_3
value|0x000036EC
end_define

begin_define
define|#
directive|define
name|Q8_MAX_LINK_SPEED_0
value|0x000036F0
end_define

begin_define
define|#
directive|define
name|Q8_MAX_LINK_SPEED_1
value|0x000036F4
end_define

begin_define
define|#
directive|define
name|Q8_MAX_LINK_SPEED_2
value|0x000036F8
end_define

begin_define
define|#
directive|define
name|Q8_MAX_LINK_SPEED_3
value|0x000036FC
end_define

begin_define
define|#
directive|define
name|Q8_ASIC_TEMPERATURE
value|0x000037B4
end_define

begin_comment
comment|/*  * CRB Window Registers  *	0 thru 15; offsets 0x3800 thru 0x383C; 32bits each  */
end_comment

begin_define
define|#
directive|define
name|Q8_CRB_WINDOW_PF0
value|0x00003800
end_define

begin_define
define|#
directive|define
name|Q8_CRB_WINDOW_PF15
value|0x0000383C
end_define

begin_define
define|#
directive|define
name|Q8_FLASH_LOCK
value|0x00003850
end_define

begin_define
define|#
directive|define
name|Q8_FLASH_UNLOCK
value|0x00003854
end_define

begin_define
define|#
directive|define
name|Q8_DRIVER_LOCK
value|0x00003868
end_define

begin_define
define|#
directive|define
name|Q8_DRIVER_UNLOCK
value|0x0000386C
end_define

begin_define
define|#
directive|define
name|Q8_LEGACY_INT_PTR
value|0x000038C0
end_define

begin_define
define|#
directive|define
name|Q8_LEGACY_INT_TRIG
value|0x000038C4
end_define

begin_define
define|#
directive|define
name|Q8_LEGACY_INT_MASK
value|0x000038C8
end_define

begin_define
define|#
directive|define
name|Q8_WILD_CARD
value|0x000038F0
end_define

begin_define
define|#
directive|define
name|Q8_INFORMANT
value|0x000038FC
end_define

begin_comment
comment|/*  * Ethernet Interface Specific Registers  */
end_comment

begin_define
define|#
directive|define
name|Q8_DRIVER_OP_MODE
value|0x00003570
end_define

begin_define
define|#
directive|define
name|Q8_API_VERSION
value|0x0000356C
end_define

begin_define
define|#
directive|define
name|Q8_NPAR_STATE
value|0x0000359C
end_define

begin_comment
comment|/*  * End of PCIe Registers; Direct Mapped; Offsets from BAR0  */
end_comment

begin_comment
comment|/*  * Indirect Registers  */
end_comment

begin_define
define|#
directive|define
name|Q8_LED_DUAL_0
value|0x28084C80
end_define

begin_define
define|#
directive|define
name|Q8_LED_SINGLE_0
value|0x28084C90
end_define

begin_define
define|#
directive|define
name|Q8_LED_DUAL_1
value|0x28084CA0
end_define

begin_define
define|#
directive|define
name|Q8_LED_SINGLE_1
value|0x28084CB0
end_define

begin_define
define|#
directive|define
name|Q8_LED_DUAL_2
value|0x28084CC0
end_define

begin_define
define|#
directive|define
name|Q8_LED_SINGLE_2
value|0x28084CD0
end_define

begin_define
define|#
directive|define
name|Q8_LED_DUAL_3
value|0x28084CE0
end_define

begin_define
define|#
directive|define
name|Q8_LED_SINGLE_3
value|0x28084CF0
end_define

begin_define
define|#
directive|define
name|Q8_GPIO_1
value|0x28084D00
end_define

begin_define
define|#
directive|define
name|Q8_GPIO_2
value|0x28084D10
end_define

begin_define
define|#
directive|define
name|Q8_GPIO_3
value|0x28084D20
end_define

begin_define
define|#
directive|define
name|Q8_GPIO_4
value|0x28084D40
end_define

begin_define
define|#
directive|define
name|Q8_GPIO_5
value|0x28084D50
end_define

begin_define
define|#
directive|define
name|Q8_GPIO_6
value|0x28084D60
end_define

begin_define
define|#
directive|define
name|Q8_GPIO_7
value|0x42100060
end_define

begin_define
define|#
directive|define
name|Q8_GPIO_8
value|0x42100064
end_define

begin_define
define|#
directive|define
name|Q8_FLASH_SPI_STATUS
value|0x2808E010
end_define

begin_define
define|#
directive|define
name|Q8_FLASH_SPI_CONTROL
value|0x2808E014
end_define

begin_define
define|#
directive|define
name|Q8_FLASH_STATUS
value|0x42100004
end_define

begin_define
define|#
directive|define
name|Q8_FLASH_CONTROL
value|0x42110004
end_define

begin_define
define|#
directive|define
name|Q8_FLASH_ADDRESS
value|0x42110008
end_define

begin_define
define|#
directive|define
name|Q8_FLASH_WR_DATA
value|0x4211000C
end_define

begin_define
define|#
directive|define
name|Q8_FLASH_RD_DATA
value|0x42110018
end_define

begin_define
define|#
directive|define
name|Q8_FLASH_DIRECT_WINDOW
value|0x42110030
end_define

begin_define
define|#
directive|define
name|Q8_FLASH_DIRECT_DATA
value|0x42150000
end_define

begin_define
define|#
directive|define
name|Q8_MS_CNTRL
value|0x41000090
end_define

begin_define
define|#
directive|define
name|Q8_MS_ADDR_LO
value|0x41000094
end_define

begin_define
define|#
directive|define
name|Q8_MS_ADDR_HI
value|0x41000098
end_define

begin_define
define|#
directive|define
name|Q8_MS_WR_DATA_0_31
value|0x410000A0
end_define

begin_define
define|#
directive|define
name|Q8_MS_WR_DATA_32_63
value|0x410000A4
end_define

begin_define
define|#
directive|define
name|Q8_MS_WR_DATA_64_95
value|0x410000B0
end_define

begin_define
define|#
directive|define
name|Q8_MS_WR_DATA_96_127
value|0x410000B4
end_define

begin_define
define|#
directive|define
name|Q8_MS_RD_DATA_0_31
value|0x410000A8
end_define

begin_define
define|#
directive|define
name|Q8_MS_RD_DATA_32_63
value|0x410000AC
end_define

begin_define
define|#
directive|define
name|Q8_MS_RD_DATA_64_95
value|0x410000B8
end_define

begin_define
define|#
directive|define
name|Q8_MS_RD_DATA_96_127
value|0x410000BC
end_define

begin_define
define|#
directive|define
name|Q8_CRB_PEG_0
value|0x3400003c
end_define

begin_define
define|#
directive|define
name|Q8_CRB_PEG_1
value|0x3410003c
end_define

begin_define
define|#
directive|define
name|Q8_CRB_PEG_2
value|0x3420003c
end_define

begin_define
define|#
directive|define
name|Q8_CRB_PEG_3
value|0x3430003c
end_define

begin_define
define|#
directive|define
name|Q8_CRB_PEG_4
value|0x34B0003c
end_define

begin_comment
comment|/*  * Macros for reading and writing registers  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|Q8_MB
parameter_list|()
value|__asm volatile("mfence" ::: "memory")
end_define

begin_define
define|#
directive|define
name|Q8_WMB
parameter_list|()
value|__asm volatile("sfence" ::: "memory")
end_define

begin_define
define|#
directive|define
name|Q8_RMB
parameter_list|()
value|__asm volatile("lfence" ::: "memory")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Q8_MB
parameter_list|()
end_define

begin_define
define|#
directive|define
name|Q8_WMB
parameter_list|()
end_define

begin_define
define|#
directive|define
name|Q8_RMB
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|READ_REG32
parameter_list|(
name|ha
parameter_list|,
name|reg
parameter_list|)
value|bus_read_4((ha->pci_reg), reg)
end_define

begin_define
define|#
directive|define
name|WRITE_REG32
parameter_list|(
name|ha
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|{\ 		bus_write_4((ha->pci_reg), reg, val);\ 		bus_read_4((ha->pci_reg), reg);\ 	}
end_define

begin_define
define|#
directive|define
name|Q8_NUM_MBOX
value|512
end_define

begin_define
define|#
directive|define
name|Q8_MAX_NUM_MULTICAST_ADDRS
value|1022
end_define

begin_define
define|#
directive|define
name|Q8_MAC_ADDR_LEN
value|6
end_define

begin_comment
comment|/*  * Firmware Interface  */
end_comment

begin_comment
comment|/*  * Command Response Interface - Commands  */
end_comment

begin_define
define|#
directive|define
name|Q8_MBX_CONFIG_IP_ADDRESS
value|0x0001
end_define

begin_define
define|#
directive|define
name|Q8_MBX_CONFIG_INTR
value|0x0002
end_define

begin_define
define|#
directive|define
name|Q8_MBX_MAP_INTR_SRC
value|0x0003
end_define

begin_define
define|#
directive|define
name|Q8_MBX_MAP_SDS_TO_RDS
value|0x0006
end_define

begin_define
define|#
directive|define
name|Q8_MBX_CREATE_RX_CNTXT
value|0x0007
end_define

begin_define
define|#
directive|define
name|Q8_MBX_DESTROY_RX_CNTXT
value|0x0008
end_define

begin_define
define|#
directive|define
name|Q8_MBX_CREATE_TX_CNTXT
value|0x0009
end_define

begin_define
define|#
directive|define
name|Q8_MBX_DESTROY_TX_CNTXT
value|0x000A
end_define

begin_define
define|#
directive|define
name|Q8_MBX_ADD_RX_RINGS
value|0x000B
end_define

begin_define
define|#
directive|define
name|Q8_MBX_CONFIG_LRO_FLOW
value|0x000C
end_define

begin_define
define|#
directive|define
name|Q8_MBX_CONFIG_MAC_LEARNING
value|0x000D
end_define

begin_define
define|#
directive|define
name|Q8_MBX_GET_STATS
value|0x000F
end_define

begin_define
define|#
directive|define
name|Q8_MBX_GENERATE_INTR
value|0x0011
end_define

begin_define
define|#
directive|define
name|Q8_MBX_SET_MAX_MTU
value|0x0012
end_define

begin_define
define|#
directive|define
name|Q8_MBX_MAC_ADDR_CNTRL
value|0x001F
end_define

begin_define
define|#
directive|define
name|Q8_MBX_GET_PCI_CONFIG
value|0x0020
end_define

begin_define
define|#
directive|define
name|Q8_MBX_GET_NIC_PARTITION
value|0x0021
end_define

begin_define
define|#
directive|define
name|Q8_MBX_SET_NIC_PARTITION
value|0x0022
end_define

begin_define
define|#
directive|define
name|Q8_MBX_QUERY_WOL_CAP
value|0x002C
end_define

begin_define
define|#
directive|define
name|Q8_MBX_SET_WOL_CONFIG
value|0x002D
end_define

begin_define
define|#
directive|define
name|Q8_MBX_GET_MINIDUMP_TMPLT_SIZE
value|0x002F
end_define

begin_define
define|#
directive|define
name|Q8_MBX_GET_MINIDUMP_TMPLT
value|0x0030
end_define

begin_define
define|#
directive|define
name|Q8_MBX_GET_FW_DCBX_CAPS
value|0x0034
end_define

begin_define
define|#
directive|define
name|Q8_MBX_QUERY_DCBX_SETTINGS
value|0x0035
end_define

begin_define
define|#
directive|define
name|Q8_MBX_CONFIG_RSS
value|0x0041
end_define

begin_define
define|#
directive|define
name|Q8_MBX_CONFIG_RSS_TABLE
value|0x0042
end_define

begin_define
define|#
directive|define
name|Q8_MBX_CONFIG_INTR_COALESCE
value|0x0043
end_define

begin_define
define|#
directive|define
name|Q8_MBX_CONFIG_LED
value|0x0044
end_define

begin_define
define|#
directive|define
name|Q8_MBX_CONFIG_MAC_ADDR
value|0x0045
end_define

begin_define
define|#
directive|define
name|Q8_MBX_CONFIG_STATISTICS
value|0x0046
end_define

begin_define
define|#
directive|define
name|Q8_MBX_CONFIG_LOOPBACK
value|0x0047
end_define

begin_define
define|#
directive|define
name|Q8_MBX_LINK_EVENT_REQ
value|0x0048
end_define

begin_define
define|#
directive|define
name|Q8_MBX_CONFIG_MAC_RX_MODE
value|0x0049
end_define

begin_define
define|#
directive|define
name|Q8_MBX_CONFIG_FW_LRO
value|0x004A
end_define

begin_define
define|#
directive|define
name|Q8_MBX_HW_CONFIG
value|0x004C
end_define

begin_define
define|#
directive|define
name|Q8_MBX_INIT_NIC_FUNC
value|0x0060
end_define

begin_define
define|#
directive|define
name|Q8_MBX_STOP_NIC_FUNC
value|0x0061
end_define

begin_define
define|#
directive|define
name|Q8_MBX_IDC_REQ
value|0x0062
end_define

begin_define
define|#
directive|define
name|Q8_MBX_IDC_ACK
value|0x0063
end_define

begin_define
define|#
directive|define
name|Q8_MBX_SET_PORT_CONFIG
value|0x0066
end_define

begin_define
define|#
directive|define
name|Q8_MBX_GET_PORT_CONFIG
value|0x0067
end_define

begin_define
define|#
directive|define
name|Q8_MBX_GET_LINK_STATUS
value|0x0068
end_define

begin_comment
comment|/*  * Mailbox Command Response  */
end_comment

begin_define
define|#
directive|define
name|Q8_MBX_RSP_SUCCESS
value|0x0001
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_RESPONSE_FAILURE
value|0x0002
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_NO_CARD_CRB
value|0x0003
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_NO_CARD_MEM
value|0x0004
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_NO_CARD_RSRC
value|0x0005
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_INVALID_ARGS
value|0x0006
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_INVALID_ACTION
value|0x0007
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_INVALID_STATE
value|0x0008
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_NOT_SUPPORTED
value|0x0009
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_NOT_PERMITTED
value|0x000A
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_NOT_READY
value|0x000B
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_DOES_NOT_EXIST
value|0x000C
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_ALREADY_EXISTS
value|0x000D
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_BAD_SIGNATURE
value|0x000E
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_CMD_NOT_IMPLEMENTED
value|0x000F
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_CMD_INVALID
value|0x0010
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_TIMEOUT
value|0x0011
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_CMD_FAILED
value|0x0012
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_FATAL_TEMP
value|0x0013
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_MAX_EXCEEDED
value|0x0014
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_UNSPECIFIED
value|0x0015
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_INTR_CREATE_FAILED
value|0x0017
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_INTR_DELETE_FAILED
value|0x0018
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_INTR_INVALID_OP
value|0x0019
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_IDC_INTRMD_RSP
value|0x001A
end_define

begin_define
define|#
directive|define
name|Q8_MBX_CMD_VERSION
value|(0x2<< 13)
end_define

begin_define
define|#
directive|define
name|Q8_MBX_RSP_STATUS
parameter_list|(
name|x
parameter_list|)
value|(((!(x>> 9)) || ((x>> 9) == 1)) ? 0: (x>> 9))
end_define

begin_comment
comment|/*  * Configure IP Address  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_ip_addr
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint8_t
name|cmd
decl_stmt|;
define|#
directive|define
name|Q8_MBX_CONFIG_IP_ADD_IP
value|0x1
define|#
directive|define
name|Q8_MBX_CONFIG_IP_DEL_IP
value|0x2
name|uint8_t
name|ip_type
decl_stmt|;
define|#
directive|define
name|Q8_MBX_CONFIG_IP_V4
value|0x0
define|#
directive|define
name|Q8_MBX_CONFIG_IP_V6
value|0x1
name|uint16_t
name|rsrvd
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ipv4
struct|;
name|uint8_t
name|ipv6_addr
index|[
literal|16
index|]
decl_stmt|;
block|}
name|u
union|;
block|}
name|__packed
name|q80_config_ip_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_ip_addr_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
block|}
name|__packed
name|q80_config_ip_addr_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Configure Interrupt Command  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_intr
block|{
name|uint8_t
name|cmd_type
decl_stmt|;
define|#
directive|define
name|Q8_MBX_CONFIG_INTR_CREATE
value|0x1
define|#
directive|define
name|Q8_MBX_CONFIG_INTR_DELETE
value|0x2
define|#
directive|define
name|Q8_MBX_CONFIG_INTR_TYPE_LINE
value|(0x1<< 4)
define|#
directive|define
name|Q8_MBX_CONFIG_INTR_TYPE_MSI_X
value|(0x3<< 4)
name|uint8_t
name|rsrvd
decl_stmt|;
name|uint16_t
name|msix_index
decl_stmt|;
block|}
name|__packed
name|q80_intr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Q8_MAX_INTR_VECTORS
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_intr
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint8_t
name|nentries
decl_stmt|;
name|uint8_t
name|rsrvd
index|[
literal|3
index|]
decl_stmt|;
name|q80_intr_t
name|intr
index|[
name|Q8_MAX_INTR_VECTORS
index|]
decl_stmt|;
block|}
name|__packed
name|q80_config_intr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_intr_rsp
block|{
name|uint8_t
name|status
decl_stmt|;
name|uint8_t
name|cmd
decl_stmt|;
name|uint16_t
name|intr_id
decl_stmt|;
name|uint32_t
name|intr_src
decl_stmt|;
block|}
name|q80_intr_rsp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_intr_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
name|uint8_t
name|nentries
decl_stmt|;
name|uint8_t
name|rsrvd
index|[
literal|3
index|]
decl_stmt|;
name|q80_intr_rsp_t
name|intr
index|[
name|Q8_MAX_INTR_VECTORS
index|]
decl_stmt|;
block|}
name|__packed
name|q80_config_intr_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Configure LRO Flow Command  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_lro_flow
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint8_t
name|cmd
decl_stmt|;
define|#
directive|define
name|Q8_MBX_CONFIG_LRO_FLOW_ADD
value|0x01
define|#
directive|define
name|Q8_MBX_CONFIG_LRO_FLOW_DELETE
value|0x02
name|uint8_t
name|type_ts
decl_stmt|;
define|#
directive|define
name|Q8_MBX_CONFIG_LRO_FLOW_IPV4
value|0x00
define|#
directive|define
name|Q8_MBX_CONFIG_LRO_FLOW_IPV6
value|0x01
define|#
directive|define
name|Q8_MBX_CONFIG_LRO_FLOW_TS_ABSENT
value|0x00
define|#
directive|define
name|Q8_MBX_CONFIG_LRO_FLOW_TS_PRESENT
value|0x02
name|uint16_t
name|rsrvd
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ipv4
struct|;
name|uint8_t
name|ipv6_addr
index|[
literal|16
index|]
decl_stmt|;
block|}
name|dst
union|;
union|union
block|{
struct|struct
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ipv4
struct|;
name|uint8_t
name|ipv6_addr
index|[
literal|16
index|]
decl_stmt|;
block|}
name|src
union|;
name|uint16_t
name|dst_port
decl_stmt|;
name|uint16_t
name|src_port
decl_stmt|;
block|}
name|__packed
name|q80_config_lro_flow_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_lro_flow_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
block|}
name|__packed
name|q80_config_lro_flow_rsp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_set_max_mtu
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint32_t
name|cntxt_id
decl_stmt|;
name|uint32_t
name|mtu
decl_stmt|;
block|}
name|__packed
name|q80_set_max_mtu_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_set_max_mtu_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
block|}
name|__packed
name|q80_set_max_mtu_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Configure RSS   */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_rss
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint16_t
name|cntxt_id
decl_stmt|;
name|uint16_t
name|rsrvd
decl_stmt|;
name|uint8_t
name|hash_type
decl_stmt|;
define|#
directive|define
name|Q8_MBX_RSS_HASH_TYPE_IPV4_IP
value|(0x1<< 4)
define|#
directive|define
name|Q8_MBX_RSS_HASH_TYPE_IPV4_TCP
value|(0x2<< 4)
define|#
directive|define
name|Q8_MBX_RSS_HASH_TYPE_IPV4_TCP_IP
value|(0x3<< 4)
define|#
directive|define
name|Q8_MBX_RSS_HASH_TYPE_IPV6_IP
value|(0x1<< 6)
define|#
directive|define
name|Q8_MBX_RSS_HASH_TYPE_IPV6_TCP
value|(0x2<< 6)
define|#
directive|define
name|Q8_MBX_RSS_HASH_TYPE_IPV6_TCP_IP
value|(0x3<< 6)
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|Q8_MBX_RSS_FLAGS_ENABLE_RSS
value|(0x1)
define|#
directive|define
name|Q8_MBX_RSS_FLAGS_USE_IND_TABLE
value|(0x2)
define|#
directive|define
name|Q8_MBX_RSS_FLAGS_TYPE_CRSS
value|(0x4)
name|uint16_t
name|indtbl_mask
decl_stmt|;
define|#
directive|define
name|Q8_MBX_RSS_INDTBL_MASK
value|0x7F
define|#
directive|define
name|Q8_MBX_RSS_FLAGS_MULTI_RSS_VALID
value|0x8000
name|uint32_t
name|multi_rss
decl_stmt|;
define|#
directive|define
name|Q8_MBX_RSS_MULTI_RSS_ENGINE_ASSIGN
value|BIT_30
define|#
directive|define
name|Q8_MBX_RSS_USE_MULTI_RSS_ENGINES
value|BIT_31
name|uint64_t
name|rss_key
index|[
literal|5
index|]
decl_stmt|;
block|}
name|__packed
name|q80_config_rss_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_rss_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
block|}
name|__packed
name|q80_config_rss_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Configure RSS Indirection Table  */
end_comment

begin_define
define|#
directive|define
name|Q8_RSS_IND_TBL_SIZE
value|40
end_define

begin_define
define|#
directive|define
name|Q8_RSS_IND_TBL_MIN_IDX
value|0
end_define

begin_define
define|#
directive|define
name|Q8_RSS_IND_TBL_MAX_IDX
value|127
end_define

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_rss_ind_table
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint8_t
name|start_idx
decl_stmt|;
name|uint8_t
name|end_idx
decl_stmt|;
name|uint16_t
name|cntxt_id
decl_stmt|;
name|uint8_t
name|ind_table
index|[
name|Q8_RSS_IND_TBL_SIZE
index|]
decl_stmt|;
block|}
name|__packed
name|q80_config_rss_ind_table_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_rss_ind_table_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
block|}
name|__packed
name|q80_config_rss_ind_table_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Configure Interrupt Coalescing and Generation  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_intr_coalesc
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|Q8_MBX_INTRC_FLAGS_RCV
value|1
define|#
directive|define
name|Q8_MBX_INTRC_FLAGS_XMT
value|2
define|#
directive|define
name|Q8_MBX_INTRC_FLAGS_PERIODIC
value|(1<< 3)
name|uint16_t
name|cntxt_id
decl_stmt|;
name|uint16_t
name|max_pkts
decl_stmt|;
name|uint16_t
name|max_mswait
decl_stmt|;
name|uint8_t
name|timer_type
decl_stmt|;
define|#
directive|define
name|Q8_MBX_INTRC_TIMER_NONE
value|0
define|#
directive|define
name|Q8_MBX_INTRC_TIMER_SINGLE
value|1
define|#
directive|define
name|Q8_MBX_INTRC_TIMER_PERIODIC
value|2
name|uint16_t
name|sds_ring_mask
decl_stmt|;
name|uint8_t
name|rsrvd
decl_stmt|;
name|uint32_t
name|ms_timeout
decl_stmt|;
block|}
name|__packed
name|q80_config_intr_coalesc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_intr_coalesc_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
block|}
name|__packed
name|q80_config_intr_coalesc_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Configure MAC Address  */
end_comment

begin_define
define|#
directive|define
name|Q8_ETHER_ADDR_LEN
value|6
end_define

begin_typedef
typedef|typedef
struct|struct
name|_q80_mac_addr
block|{
name|uint8_t
name|addr
index|[
name|Q8_ETHER_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|vlan_tci
decl_stmt|;
block|}
name|__packed
name|q80_mac_addr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Q8_MAX_MAC_ADDRS
value|64
end_define

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_mac_addr
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint8_t
name|cmd
decl_stmt|;
define|#
directive|define
name|Q8_MBX_CMAC_CMD_ADD_MAC_ADDR
value|1
define|#
directive|define
name|Q8_MBX_CMAC_CMD_DEL_MAC_ADDR
value|2
define|#
directive|define
name|Q8_MBX_CMAC_CMD_CAM_BOTH
value|(0x0<< 6)
define|#
directive|define
name|Q8_MBX_CMAC_CMD_CAM_INGRESS
value|(0x1<< 6)
define|#
directive|define
name|Q8_MBX_CMAC_CMD_CAM_EGRESS
value|(0x2<< 6)
name|uint8_t
name|nmac_entries
decl_stmt|;
name|uint16_t
name|cntxt_id
decl_stmt|;
name|q80_mac_addr_t
name|mac_addr
index|[
name|Q8_MAX_MAC_ADDRS
index|]
decl_stmt|;
block|}
name|__packed
name|q80_config_mac_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_mac_addr_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
name|uint8_t
name|cmd
decl_stmt|;
name|uint8_t
name|nmac_entries
decl_stmt|;
name|uint16_t
name|cntxt_id
decl_stmt|;
name|uint32_t
name|status
index|[
name|Q8_MAX_MAC_ADDRS
index|]
decl_stmt|;
block|}
name|__packed
name|q80_config_mac_addr_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Configure MAC Receive Mode  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_mac_rcv_mode
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint8_t
name|mode
decl_stmt|;
define|#
directive|define
name|Q8_MBX_MAC_RCV_PROMISC_ENABLE
value|0x1
define|#
directive|define
name|Q8_MBX_MAC_ALL_MULTI_ENABLE
value|0x2
name|uint8_t
name|rsrvd
decl_stmt|;
name|uint16_t
name|cntxt_id
decl_stmt|;
block|}
name|__packed
name|q80_config_mac_rcv_mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_mac_rcv_mode_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
block|}
name|__packed
name|q80_config_mac_rcv_mode_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Configure Firmware Controlled LRO  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_fw_lro
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|Q8_MBX_FW_LRO_IPV4
value|0x1
define|#
directive|define
name|Q8_MBX_FW_LRO_IPV6
value|0x2
define|#
directive|define
name|Q8_MBX_FW_LRO_IPV4_WO_DST_IP_CHK
value|0x4
define|#
directive|define
name|Q8_MBX_FW_LRO_IPV6_WO_DST_IP_CHK
value|0x8
define|#
directive|define
name|Q8_MBX_FW_LRO_LOW_THRESHOLD
value|0x10
name|uint8_t
name|rsrvd
decl_stmt|;
name|uint16_t
name|cntxt_id
decl_stmt|;
name|uint16_t
name|low_threshold
decl_stmt|;
name|uint16_t
name|rsrvd0
decl_stmt|;
block|}
name|__packed
name|q80_config_fw_lro_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_fw_lro_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
block|}
name|__packed
name|q80_config_fw_lro_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Minidump mailbox commands  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_md_templ_size
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
block|}
name|__packed
name|q80_config_md_templ_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_md_templ_size_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
name|uint32_t
name|rsrvd
decl_stmt|;
name|uint32_t
name|templ_size
decl_stmt|;
name|uint32_t
name|templ_version
decl_stmt|;
block|}
name|__packed
name|q80_config_md_templ_size_rsp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_md_templ_cmd
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint64_t
name|buf_addr
decl_stmt|;
comment|/* physical address of buffer */
name|uint32_t
name|buff_size
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
block|}
name|__packed
name|q80_config_md_templ_cmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_config_md_templ_cmd_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
name|uint32_t
name|rsrvd
decl_stmt|;
name|uint32_t
name|templ_size
decl_stmt|;
name|uint32_t
name|buff_size
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
block|}
name|__packed
name|q80_config_md_templ_cmd_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Hardware Configuration Commands  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_hw_config
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
define|#
directive|define
name|Q8_HW_CONFIG_SET_MDIO_REG_COUNT
value|0x06
define|#
directive|define
name|Q8_HW_CONFIG_GET_MDIO_REG_COUNT
value|0x05
define|#
directive|define
name|Q8_HW_CONFIG_SET_CAM_SEARCH_MODE_COUNT
value|0x03
define|#
directive|define
name|Q8_HW_CONFIG_GET_CAM_SEARCH_MODE_COUNT
value|0x02
define|#
directive|define
name|Q8_HW_CONFIG_SET_TEMP_THRESHOLD_COUNT
value|0x03
define|#
directive|define
name|Q8_HW_CONFIG_GET_TEMP_THRESHOLD_COUNT
value|0x02
define|#
directive|define
name|Q8_HW_CONFIG_GET_ECC_COUNTS_COUNT
value|0x02
name|uint32_t
name|cmd
decl_stmt|;
define|#
directive|define
name|Q8_HW_CONFIG_SET_MDIO_REG
value|0x01
define|#
directive|define
name|Q8_HW_CONFIG_GET_MDIO_REG
value|0x02
define|#
directive|define
name|Q8_HW_CONFIG_SET_CAM_SEARCH_MODE
value|0x03
define|#
directive|define
name|Q8_HW_CONFIG_GET_CAM_SEARCH_MODE
value|0x04
define|#
directive|define
name|Q8_HW_CONFIG_SET_TEMP_THRESHOLD
value|0x07
define|#
directive|define
name|Q8_HW_CONFIG_GET_TEMP_THRESHOLD
value|0x08
define|#
directive|define
name|Q8_HW_CONFIG_GET_ECC_COUNTS
value|0x0A
union|union
block|{
struct|struct
block|{
name|uint32_t
name|phys_port_number
decl_stmt|;
name|uint32_t
name|phy_dev_addr
decl_stmt|;
name|uint32_t
name|reg_addr
decl_stmt|;
name|uint32_t
name|data
decl_stmt|;
block|}
name|set_mdio
struct|;
struct|struct
block|{
name|uint32_t
name|phys_port_number
decl_stmt|;
name|uint32_t
name|phy_dev_addr
decl_stmt|;
name|uint32_t
name|reg_addr
decl_stmt|;
block|}
name|get_mdio
struct|;
struct|struct
block|{
name|uint32_t
name|mode
decl_stmt|;
define|#
directive|define
name|Q8_HW_CONFIG_CAM_SEARCH_MODE_INTERNAL
value|0x1
define|#
directive|define
name|Q8_HW_CONFIG_CAM_SEARCH_MODE_AUTO
value|0x2
block|}
name|set_cam_search_mode
struct|;
struct|struct
block|{
name|uint32_t
name|value
decl_stmt|;
block|}
name|set_temp_threshold
struct|;
block|}
name|u
union|;
block|}
name|__packed
name|q80_hw_config_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_hw_config_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint32_t
name|value
decl_stmt|;
block|}
name|get_mdio
struct|;
struct|struct
block|{
name|uint32_t
name|mode
decl_stmt|;
block|}
name|get_cam_search_mode
struct|;
struct|struct
block|{
name|uint32_t
name|temp_warn
decl_stmt|;
name|uint32_t
name|curr_temp
decl_stmt|;
name|uint32_t
name|osc_ring_rate
decl_stmt|;
name|uint32_t
name|core_voltage
decl_stmt|;
block|}
name|get_temp_threshold
struct|;
struct|struct
block|{
name|uint32_t
name|ddr_ecc_error_count
decl_stmt|;
name|uint32_t
name|ocm_ecc_error_count
decl_stmt|;
name|uint32_t
name|l2_dcache_ecc_error_count
decl_stmt|;
name|uint32_t
name|l2_icache_ecc_error_count
decl_stmt|;
name|uint32_t
name|eport_ecc_error_count
decl_stmt|;
block|}
name|get_ecc_counts
struct|;
block|}
name|u
union|;
block|}
name|__packed
name|q80_hw_config_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Link Event Request Command  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_link_event
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint8_t
name|cmd
decl_stmt|;
define|#
directive|define
name|Q8_LINK_EVENT_CMD_STOP_PERIODIC
value|0
define|#
directive|define
name|Q8_LINK_EVENT_CMD_ENABLE_ASYNC
value|1
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|Q8_LINK_EVENT_FLAGS_SEND_RSP
value|1
name|uint16_t
name|cntxt_id
decl_stmt|;
block|}
name|__packed
name|q80_link_event_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_link_event_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
block|}
name|__packed
name|q80_link_event_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Get Statistics Command  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_rcv_stats
block|{
name|uint64_t
name|total_bytes
decl_stmt|;
name|uint64_t
name|total_pkts
decl_stmt|;
name|uint64_t
name|lro_pkt_count
decl_stmt|;
name|uint64_t
name|sw_pkt_count
decl_stmt|;
name|uint64_t
name|ip_chksum_err
decl_stmt|;
name|uint64_t
name|pkts_wo_acntxts
decl_stmt|;
name|uint64_t
name|pkts_dropped_no_sds_card
decl_stmt|;
name|uint64_t
name|pkts_dropped_no_sds_host
decl_stmt|;
name|uint64_t
name|oversized_pkts
decl_stmt|;
name|uint64_t
name|pkts_dropped_no_rds
decl_stmt|;
name|uint64_t
name|unxpctd_mcast_pkts
decl_stmt|;
name|uint64_t
name|re1_fbq_error
decl_stmt|;
name|uint64_t
name|invalid_mac_addr
decl_stmt|;
name|uint64_t
name|rds_prime_trys
decl_stmt|;
name|uint64_t
name|rds_prime_success
decl_stmt|;
name|uint64_t
name|lro_flows_added
decl_stmt|;
name|uint64_t
name|lro_flows_deleted
decl_stmt|;
name|uint64_t
name|lro_flows_active
decl_stmt|;
name|uint64_t
name|pkts_droped_unknown
decl_stmt|;
block|}
name|__packed
name|q80_rcv_stats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_xmt_stats
block|{
name|uint64_t
name|total_bytes
decl_stmt|;
name|uint64_t
name|total_pkts
decl_stmt|;
name|uint64_t
name|errors
decl_stmt|;
name|uint64_t
name|pkts_dropped
decl_stmt|;
name|uint64_t
name|switch_pkts
decl_stmt|;
name|uint64_t
name|num_buffers
decl_stmt|;
block|}
name|__packed
name|q80_xmt_stats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_mac_stats
block|{
name|uint64_t
name|xmt_frames
decl_stmt|;
name|uint64_t
name|xmt_bytes
decl_stmt|;
name|uint64_t
name|xmt_mcast_pkts
decl_stmt|;
name|uint64_t
name|xmt_bcast_pkts
decl_stmt|;
name|uint64_t
name|xmt_pause_frames
decl_stmt|;
name|uint64_t
name|xmt_cntrl_pkts
decl_stmt|;
name|uint64_t
name|xmt_pkt_lt_64bytes
decl_stmt|;
name|uint64_t
name|xmt_pkt_lt_127bytes
decl_stmt|;
name|uint64_t
name|xmt_pkt_lt_255bytes
decl_stmt|;
name|uint64_t
name|xmt_pkt_lt_511bytes
decl_stmt|;
name|uint64_t
name|xmt_pkt_lt_1023bytes
decl_stmt|;
name|uint64_t
name|xmt_pkt_lt_1518bytes
decl_stmt|;
name|uint64_t
name|xmt_pkt_gt_1518bytes
decl_stmt|;
name|uint64_t
name|rsrvd0
index|[
literal|3
index|]
decl_stmt|;
name|uint64_t
name|rcv_frames
decl_stmt|;
name|uint64_t
name|rcv_bytes
decl_stmt|;
name|uint64_t
name|rcv_mcast_pkts
decl_stmt|;
name|uint64_t
name|rcv_bcast_pkts
decl_stmt|;
name|uint64_t
name|rcv_pause_frames
decl_stmt|;
name|uint64_t
name|rcv_cntrl_pkts
decl_stmt|;
name|uint64_t
name|rcv_pkt_lt_64bytes
decl_stmt|;
name|uint64_t
name|rcv_pkt_lt_127bytes
decl_stmt|;
name|uint64_t
name|rcv_pkt_lt_255bytes
decl_stmt|;
name|uint64_t
name|rcv_pkt_lt_511bytes
decl_stmt|;
name|uint64_t
name|rcv_pkt_lt_1023bytes
decl_stmt|;
name|uint64_t
name|rcv_pkt_lt_1518bytes
decl_stmt|;
name|uint64_t
name|rcv_pkt_gt_1518bytes
decl_stmt|;
name|uint64_t
name|rsrvd1
index|[
literal|3
index|]
decl_stmt|;
name|uint64_t
name|rcv_len_error
decl_stmt|;
name|uint64_t
name|rcv_len_small
decl_stmt|;
name|uint64_t
name|rcv_len_large
decl_stmt|;
name|uint64_t
name|rcv_jabber
decl_stmt|;
name|uint64_t
name|rcv_dropped
decl_stmt|;
name|uint64_t
name|fcs_error
decl_stmt|;
name|uint64_t
name|align_error
decl_stmt|;
name|uint64_t
name|eswitched_frames
decl_stmt|;
name|uint64_t
name|eswitched_bytes
decl_stmt|;
name|uint64_t
name|eswitched_mcast_frames
decl_stmt|;
name|uint64_t
name|eswitched_bcast_frames
decl_stmt|;
name|uint64_t
name|eswitched_ucast_frames
decl_stmt|;
name|uint64_t
name|eswitched_err_free_frames
decl_stmt|;
name|uint64_t
name|eswitched_err_free_bytes
decl_stmt|;
block|}
name|__packed
name|q80_mac_stats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_get_stats
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint32_t
name|cmd
decl_stmt|;
define|#
directive|define
name|Q8_GET_STATS_CMD_CLEAR
value|0x01
define|#
directive|define
name|Q8_GET_STATS_CMD_RCV
value|0x00
define|#
directive|define
name|Q8_GET_STATS_CMD_XMT
value|0x02
define|#
directive|define
name|Q8_GET_STATS_CMD_TYPE_CNTXT
value|0x00
define|#
directive|define
name|Q8_GET_STATS_CMD_TYPE_MAC
value|0x04
define|#
directive|define
name|Q8_GET_STATS_CMD_TYPE_FUNC
value|0x08
define|#
directive|define
name|Q8_GET_STATS_CMD_TYPE_VPORT
value|0x0C
define|#
directive|define
name|Q8_GET_STATS_CMD_TYPE_ALL
value|(0x7<< 2)
block|}
name|__packed
name|q80_get_stats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_get_stats_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
name|uint32_t
name|cmd
decl_stmt|;
union|union
block|{
name|q80_rcv_stats_t
name|rcv
decl_stmt|;
name|q80_xmt_stats_t
name|xmt
decl_stmt|;
name|q80_mac_stats_t
name|mac
decl_stmt|;
block|}
name|u
union|;
block|}
name|__packed
name|q80_get_stats_rsp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_get_mac_rcv_xmt_stats_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
name|uint32_t
name|cmd
decl_stmt|;
name|q80_mac_stats_t
name|mac
decl_stmt|;
name|q80_rcv_stats_t
name|rcv
decl_stmt|;
name|q80_xmt_stats_t
name|xmt
decl_stmt|;
block|}
name|__packed
name|q80_get_mac_rcv_xmt_stats_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Init NIC Function  * Used to Register DCBX Configuration Change AEN  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_init_nic_func
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint32_t
name|options
decl_stmt|;
define|#
directive|define
name|Q8_INIT_NIC_REG_IDC_AEN
value|0x01
define|#
directive|define
name|Q8_INIT_NIC_REG_DCBX_CHNG_AEN
value|0x02
define|#
directive|define
name|Q8_INIT_NIC_REG_SFP_CHNG_AEN
value|0x04
block|}
name|__packed
name|q80_init_nic_func_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_init_nic_func_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
block|}
name|__packed
name|q80_init_nic_func_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Stop NIC Function  * Used to DeRegister DCBX Configuration Change AEN  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_stop_nic_func
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint32_t
name|options
decl_stmt|;
define|#
directive|define
name|Q8_STOP_NIC_DEREG_DCBX_CHNG_AEN
value|0x02
define|#
directive|define
name|Q8_STOP_NIC_DEREG_SFP_CHNG_AEN
value|0x04
block|}
name|__packed
name|q80_stop_nic_func_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_stop_nic_func_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
block|}
name|__packed
name|q80_stop_nic_func_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Query Firmware DCBX Capabilities  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_query_fw_dcbx_caps
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
block|}
name|__packed
name|q80_query_fw_dcbx_caps_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_query_fw_dcbx_caps_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
name|uint32_t
name|dcbx_caps
decl_stmt|;
define|#
directive|define
name|Q8_QUERY_FW_DCBX_CAPS_TSA
value|0x00000001
define|#
directive|define
name|Q8_QUERY_FW_DCBX_CAPS_ETS
value|0x00000002
define|#
directive|define
name|Q8_QUERY_FW_DCBX_CAPS_DCBX_CEE_1_01
value|0x00000004
define|#
directive|define
name|Q8_QUERY_FW_DCBX_CAPS_DCBX_IEEE_1_0
value|0x00000008
define|#
directive|define
name|Q8_QUERY_FW_DCBX_MAX_TC_MASK
value|0x00F00000
define|#
directive|define
name|Q8_QUERY_FW_DCBX_MAX_ETS_TC_MASK
value|0x0F000000
define|#
directive|define
name|Q8_QUERY_FW_DCBX_MAX_PFC_TC_MASK
value|0xF0000000
block|}
name|__packed
name|q80_query_fw_dcbx_caps_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * IDC Ack Cmd  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_idc_ack
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint32_t
name|aen_mb1
decl_stmt|;
name|uint32_t
name|aen_mb2
decl_stmt|;
name|uint32_t
name|aen_mb3
decl_stmt|;
name|uint32_t
name|aen_mb4
decl_stmt|;
block|}
name|__packed
name|q80_idc_ack_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_idc_ack_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
block|}
name|__packed
name|q80_idc_ack_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Set Port Configuration command  * Used to set Ethernet Standard Pause values  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_set_port_cfg
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint32_t
name|cfg_bits
decl_stmt|;
define|#
directive|define
name|Q8_PORT_CFG_BITS_LOOPBACK_MODE_MASK
value|(0x7<< 1)
define|#
directive|define
name|Q8_PORT_CFG_BITS_LOOPBACK_MODE_NONE
value|(0x0<< 1)
define|#
directive|define
name|Q8_PORT_CFG_BITS_LOOPBACK_MODE_HSS
value|(0x2<< 1)
define|#
directive|define
name|Q8_PORT_CFG_BITS_LOOPBACK_MODE_PHY
value|(0x3<< 1)
define|#
directive|define
name|Q8_PORT_CFG_BITS_LOOPBACK_MODE_EXT
value|(0x4<< 1)
define|#
directive|define
name|Q8_VALID_LOOPBACK_MODE
parameter_list|(
name|mode
parameter_list|)
define|\
value|(((mode) == Q8_PORT_CFG_BITS_LOOPBACK_MODE_NONE) || \ 		(((mode)>= Q8_PORT_CFG_BITS_LOOPBACK_MODE_HSS)&& \ 		 ((mode)<= Q8_PORT_CFG_BITS_LOOPBACK_MODE_EXT)))
define|#
directive|define
name|Q8_PORT_CFG_BITS_DCBX_ENABLE
value|BIT_4
define|#
directive|define
name|Q8_PORT_CFG_BITS_PAUSE_CFG_MASK
value|(0x3<< 5)
define|#
directive|define
name|Q8_PORT_CFG_BITS_PAUSE_DISABLED
value|(0x0<< 5)
define|#
directive|define
name|Q8_PORT_CFG_BITS_PAUSE_STD
value|(0x1<< 5)
define|#
directive|define
name|Q8_PORT_CFG_BITS_PAUSE_PPM
value|(0x2<< 5)
define|#
directive|define
name|Q8_PORT_CFG_BITS_LNKCAP_10MB
value|BIT_8
define|#
directive|define
name|Q8_PORT_CFG_BITS_LNKCAP_100MB
value|BIT_9
define|#
directive|define
name|Q8_PORT_CFG_BITS_LNKCAP_1GB
value|BIT_10
define|#
directive|define
name|Q8_PORT_CFG_BITS_LNKCAP_10GB
value|BIT_11
define|#
directive|define
name|Q8_PORT_CFG_BITS_AUTONEG
value|BIT_15
define|#
directive|define
name|Q8_PORT_CFG_BITS_XMT_DISABLE
value|BIT_17
define|#
directive|define
name|Q8_PORT_CFG_BITS_FEC_RQSTD
value|BIT_18
define|#
directive|define
name|Q8_PORT_CFG_BITS_EEE_RQSTD
value|BIT_19
define|#
directive|define
name|Q8_PORT_CFG_BITS_STDPAUSE_DIR_MASK
value|(0x3<< 20)
define|#
directive|define
name|Q8_PORT_CFG_BITS_STDPAUSE_XMT_RCV
value|(0x0<< 20)
define|#
directive|define
name|Q8_PORT_CFG_BITS_STDPAUSE_XMT
value|(0x1<< 20)
define|#
directive|define
name|Q8_PORT_CFG_BITS_STDPAUSE_RCV
value|(0x2<< 20)
block|}
name|__packed
name|q80_set_port_cfg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_set_port_cfg_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
block|}
name|__packed
name|q80_set_port_cfg_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Get Port Configuration Command  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_get_port_cfg
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
block|}
name|__packed
name|q80_get_port_cfg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_get_port_cfg_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
name|uint32_t
name|cfg_bits
decl_stmt|;
comment|/* same as in q80_set_port_cfg_t */
name|uint8_t
name|phys_port_type
decl_stmt|;
name|uint8_t
name|rsvd
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
name|q80_get_port_cfg_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Get Link Status Command  * Used to get current PAUSE values for the port  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_get_link_status
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
block|}
name|__packed
name|q80_get_link_status_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_get_link_status_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
name|uint32_t
name|cfg_bits
decl_stmt|;
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_LINK_UP
value|BIT_0
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_LINK_SPEED_MASK
value|(0x7<< 3)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_LINK_SPEED_UNKNOWN
value|(0x0<< 3)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_LINK_SPEED_10MB
value|(0x1<< 3)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_LINK_SPEED_100MB
value|(0x2<< 3)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_LINK_SPEED_1GB
value|(0x3<< 3)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_LINK_SPEED_10GB
value|(0x4<< 3)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_PAUSE_CFG_MASK
value|(0x3<< 6)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_PAUSE_CFG_DISABLE
value|(0x0<< 6)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_PAUSE_CFG_STD
value|(0x1<< 6)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_PAUSE_CFG_PPM
value|(0x2<< 6)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_LOOPBACK_MASK
value|(0x7<< 8)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_LOOPBACK_NONE
value|(0x0<< 6)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_LOOPBACK_HSS
value|(0x2<< 6)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_LOOPBACK_PHY
value|(0x3<< 6)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_FEC_ENABLED
value|BIT_12
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_EEE_ENABLED
value|BIT_13
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_STDPAUSE_DIR_MASK
value|(0x3<< 20)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_STDPAUSE_NONE
value|(0x0<< 20)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_STDPAUSE_XMT
value|(0x1<< 20)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_STDPAUSE_RCV
value|(0x2<< 20)
define|#
directive|define
name|Q8_GET_LINK_STAT_CFG_BITS_STDPAUSE_XMT_RCV
value|(0x3<< 20)
name|uint32_t
name|link_state
decl_stmt|;
define|#
directive|define
name|Q8_GET_LINK_STAT_LOSS_OF_SIGNAL
value|BIT_0
define|#
directive|define
name|Q8_GET_LINK_STAT_PORT_RST_DONE
value|BIT_3
define|#
directive|define
name|Q8_GET_LINK_STAT_PHY_LINK_DOWN
value|BIT_4
define|#
directive|define
name|Q8_GET_LINK_STAT_PCS_LINK_DOWN
value|BIT_5
define|#
directive|define
name|Q8_GET_LINK_STAT_MAC_LOCAL_FAULT
value|BIT_6
define|#
directive|define
name|Q8_GET_LINK_STAT_MAC_REMOTE_FAULT
value|BIT_7
define|#
directive|define
name|Q8_GET_LINK_STAT_XMT_DISABLED
value|BIT_9
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_XMT_FAULT
value|BIT_10
name|uint32_t
name|sfp_info
decl_stmt|;
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_TRNCVR_MASK
value|0x3
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_TRNCVR_NOT_EXPECTED
value|0x0
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_TRNCVR_NONE
value|0x1
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_TRNCVR_INVALID
value|0x2
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_TRNCVR_VALID
value|0x3
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_ADDTL_INFO_MASK
value|(0x3<< 2)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_ADDTL_INFO_UNREC_TRSVR
value|(0x0<< 2)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_ADDTL_INFO_NOT_QLOGIC
value|(0x1<< 2)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_ADDTL_INFO_SPEED_FAILED
value|(0x2<< 2)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_ADDTL_INFO_ACCESS_ERROR
value|(0x3<< 2)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_MOD_TYPE_MASK
value|(0x1F<< 4)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_MOD_NONE
value|(0x00<< 4)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_MOD_10GBLRM
value|(0x01<< 4)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_MOD_10GBLR
value|(0x02<< 4)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_MOD_10GBSR
value|(0x03<< 4)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_MOD_10GBC_P
value|(0x04<< 4)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_MOD_10GBC_AL
value|(0x05<< 4)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_MOD_10GBC_PL
value|(0x06<< 4)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_MOD_1GBSX
value|(0x07<< 4)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_MOD_1GBLX
value|(0x08<< 4)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_MOD_1GBCX
value|(0x09<< 4)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_MOD_1GBT
value|(0x0A<< 4)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_MOD_1GBC_PL
value|(0x0B<< 4)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_MOD_UNKNOWN
value|(0x0F<< 4)
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_MULTI_RATE_MOD
value|BIT_9
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_XMT_FAULT
value|BIT_10
define|#
directive|define
name|Q8_GET_LINK_STAT_SFP_COPPER_CBL_LENGTH_MASK
value|(0xFF<< 16)
block|}
name|__packed
name|q80_get_link_status_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Transmit Related Definitions  */
end_comment

begin_comment
comment|/* Max# of TX Rings per Tx Create Cntxt Mbx Cmd*/
end_comment

begin_define
define|#
directive|define
name|MAX_TCNTXT_RINGS
value|8
end_define

begin_comment
comment|/*  * Transmit Context - Q8_CMD_CREATE_TX_CNTXT Command Configuration Data  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_rq_tx_ring
block|{
name|uint64_t
name|paddr
decl_stmt|;
name|uint64_t
name|tx_consumer
decl_stmt|;
name|uint16_t
name|nentries
decl_stmt|;
name|uint16_t
name|intr_id
decl_stmt|;
name|uint8_t
name|intr_src_bit
decl_stmt|;
name|uint8_t
name|rsrvd
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
name|q80_rq_tx_ring_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_rq_tx_cntxt
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint32_t
name|cap0
decl_stmt|;
define|#
directive|define
name|Q8_TX_CNTXT_CAP0_BASEFW
value|(1<< 0)
define|#
directive|define
name|Q8_TX_CNTXT_CAP0_LSO
value|(1<< 6)
define|#
directive|define
name|Q8_TX_CNTXT_CAP0_TC
value|(1<< 25)
name|uint32_t
name|cap1
decl_stmt|;
name|uint32_t
name|cap2
decl_stmt|;
name|uint32_t
name|cap3
decl_stmt|;
name|uint8_t
name|ntx_rings
decl_stmt|;
name|uint8_t
name|traffic_class
decl_stmt|;
comment|/* bits 8-10; others reserved */
name|uint16_t
name|tx_vpid
decl_stmt|;
name|q80_rq_tx_ring_t
name|tx_ring
index|[
name|MAX_TCNTXT_RINGS
index|]
decl_stmt|;
block|}
name|__packed
name|q80_rq_tx_cntxt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_rsp_tx_ring
block|{
name|uint32_t
name|prod_index
decl_stmt|;
name|uint16_t
name|cntxt_id
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
name|uint8_t
name|rsrvd
decl_stmt|;
block|}
name|q80_rsp_tx_ring_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_rsp_tx_cntxt
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
name|uint8_t
name|ntx_rings
decl_stmt|;
name|uint8_t
name|phy_port
decl_stmt|;
name|uint8_t
name|virt_port
decl_stmt|;
name|uint8_t
name|rsrvd
decl_stmt|;
name|q80_rsp_tx_ring_t
name|tx_ring
index|[
name|MAX_TCNTXT_RINGS
index|]
decl_stmt|;
block|}
name|__packed
name|q80_rsp_tx_cntxt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_tx_cntxt_destroy
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint32_t
name|cntxt_id
decl_stmt|;
block|}
name|__packed
name|q80_tx_cntxt_destroy_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_tx_cntxt_destroy_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
block|}
name|__packed
name|q80_tx_cntxt_destroy_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Transmit Command Descriptor  * These commands are issued on the Transmit Ring associated with a Transmit  * context  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_tx_cmd
block|{
name|uint8_t
name|tcp_hdr_off
decl_stmt|;
comment|/* TCP Header Offset */
name|uint8_t
name|ip_hdr_off
decl_stmt|;
comment|/* IP Header Offset */
name|uint16_t
name|flags_opcode
decl_stmt|;
comment|/* Bits 0-6: flags; 7-12: opcode */
comment|/* flags field */
define|#
directive|define
name|Q8_TX_CMD_FLAGS_MULTICAST
value|0x01
define|#
directive|define
name|Q8_TX_CMD_FLAGS_LSO_TSO
value|0x02
define|#
directive|define
name|Q8_TX_CMD_FLAGS_VLAN_TAGGED
value|0x10
define|#
directive|define
name|Q8_TX_CMD_FLAGS_HW_VLAN_ID
value|0x40
comment|/* opcode field */
define|#
directive|define
name|Q8_TX_CMD_OP_XMT_UDP_CHKSUM_IPV6
value|(0xC<< 7)
define|#
directive|define
name|Q8_TX_CMD_OP_XMT_TCP_CHKSUM_IPV6
value|(0xB<< 7)
define|#
directive|define
name|Q8_TX_CMD_OP_XMT_TCP_LSO_IPV6
value|(0x6<< 7)
define|#
directive|define
name|Q8_TX_CMD_OP_XMT_TCP_LSO
value|(0x5<< 7)
define|#
directive|define
name|Q8_TX_CMD_OP_XMT_UDP_CHKSUM
value|(0x3<< 7)
define|#
directive|define
name|Q8_TX_CMD_OP_XMT_TCP_CHKSUM
value|(0x2<< 7)
define|#
directive|define
name|Q8_TX_CMD_OP_XMT_ETHER
value|(0x1<< 7)
name|uint8_t
name|n_bufs
decl_stmt|;
comment|/* # of data segs in data buffer */
name|uint8_t
name|data_len_lo
decl_stmt|;
comment|/* data length lower 8 bits */
name|uint16_t
name|data_len_hi
decl_stmt|;
comment|/* data length upper 16 bits */
name|uint64_t
name|buf2_addr
decl_stmt|;
comment|/* buffer 2 address */
name|uint16_t
name|rsrvd0
decl_stmt|;
name|uint16_t
name|mss
decl_stmt|;
comment|/* MSS for this packet */
name|uint8_t
name|cntxtid
decl_stmt|;
comment|/* Bits 7-4: ContextId; 3-0: reserved */
define|#
directive|define
name|Q8_TX_CMD_PORT_CNXTID
parameter_list|(
name|c_id
parameter_list|)
value|((c_id& 0xF)<< 4)
name|uint8_t
name|total_hdr_len
decl_stmt|;
comment|/* MAC+IP+TCP Header Length for LSO */
name|uint16_t
name|rsrvd1
decl_stmt|;
name|uint64_t
name|buf3_addr
decl_stmt|;
comment|/* buffer 3 address */
name|uint64_t
name|buf1_addr
decl_stmt|;
comment|/* buffer 1 address */
name|uint16_t
name|buf1_len
decl_stmt|;
comment|/* length of buffer 1 */
name|uint16_t
name|buf2_len
decl_stmt|;
comment|/* length of buffer 2 */
name|uint16_t
name|buf3_len
decl_stmt|;
comment|/* length of buffer 3 */
name|uint16_t
name|buf4_len
decl_stmt|;
comment|/* length of buffer 4 */
name|uint64_t
name|buf4_addr
decl_stmt|;
comment|/* buffer 4 address */
name|uint32_t
name|rsrvd2
decl_stmt|;
name|uint16_t
name|rsrvd3
decl_stmt|;
name|uint16_t
name|vlan_tci
decl_stmt|;
comment|/* VLAN TCI when hw tagging is enabled*/
block|}
name|__packed
name|q80_tx_cmd_t
typedef|;
end_typedef

begin_comment
comment|/* 64 bytes */
end_comment

begin_define
define|#
directive|define
name|Q8_TX_CMD_MAX_SEGMENTS
value|4
end_define

begin_define
define|#
directive|define
name|Q8_TX_CMD_TSO_ALIGN
value|2
end_define

begin_define
define|#
directive|define
name|Q8_TX_MAX_NON_TSO_SEGS
value|62
end_define

begin_comment
comment|/*  * Receive Related Definitions  */
end_comment

begin_define
define|#
directive|define
name|MAX_RDS_RING_SETS
value|8
end_define

begin_comment
comment|/* Max# of Receive Descriptor Rings */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|QL_ENABLE_ISCSI_TLV
end_ifdef

begin_define
define|#
directive|define
name|MAX_SDS_RINGS
value|32
end_define

begin_comment
comment|/* Max# of Status Descriptor Rings */
end_comment

begin_define
define|#
directive|define
name|NUM_TX_RINGS
value|(MAX_SDS_RINGS * 2)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAX_SDS_RINGS
value|4
end_define

begin_comment
comment|/* Max# of Status Descriptor Rings */
end_comment

begin_define
define|#
directive|define
name|NUM_TX_RINGS
value|MAX_SDS_RINGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifdef QL_ENABLE_ISCSI_TLV */
end_comment

begin_define
define|#
directive|define
name|MAX_RDS_RINGS
value|MAX_SDS_RINGS
end_define

begin_comment
comment|/* Max# of Rcv Descriptor Rings */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_rq_sds_ring
block|{
name|uint64_t
name|paddr
decl_stmt|;
comment|/* physical addr of status ring in system memory */
name|uint64_t
name|hdr_split1
decl_stmt|;
name|uint64_t
name|hdr_split2
decl_stmt|;
name|uint16_t
name|size
decl_stmt|;
comment|/* number of entries in status ring */
name|uint16_t
name|hdr_split1_size
decl_stmt|;
name|uint16_t
name|hdr_split2_size
decl_stmt|;
name|uint16_t
name|hdr_split_count
decl_stmt|;
name|uint16_t
name|intr_id
decl_stmt|;
name|uint8_t
name|intr_src_bit
decl_stmt|;
name|uint8_t
name|rsrvd
index|[
literal|5
index|]
decl_stmt|;
block|}
name|__packed
name|q80_rq_sds_ring_t
typedef|;
end_typedef

begin_comment
comment|/* 10 32bit words */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_rq_rds_ring
block|{
name|uint64_t
name|paddr_std
decl_stmt|;
comment|/* physical addr of rcv ring in system memory */
name|uint64_t
name|paddr_jumbo
decl_stmt|;
comment|/* physical addr of rcv ring in system memory */
name|uint16_t
name|std_bsize
decl_stmt|;
name|uint16_t
name|std_nentries
decl_stmt|;
name|uint16_t
name|jumbo_bsize
decl_stmt|;
name|uint16_t
name|jumbo_nentries
decl_stmt|;
block|}
name|__packed
name|q80_rq_rds_ring_t
typedef|;
end_typedef

begin_comment
comment|/* 6 32bit words */
end_comment

begin_define
define|#
directive|define
name|MAX_RCNTXT_SDS_RINGS
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
name|_q80_rq_rcv_cntxt
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint32_t
name|cap0
decl_stmt|;
define|#
directive|define
name|Q8_RCV_CNTXT_CAP0_BASEFW
value|(1<< 0)
define|#
directive|define
name|Q8_RCV_CNTXT_CAP0_MULTI_RDS
value|(1<< 1)
define|#
directive|define
name|Q8_RCV_CNTXT_CAP0_LRO
value|(1<< 5)
define|#
directive|define
name|Q8_RCV_CNTXT_CAP0_HW_LRO
value|(1<< 10)
define|#
directive|define
name|Q8_RCV_CNTXT_CAP0_VLAN_ALIGN
value|(1<< 14)
define|#
directive|define
name|Q8_RCV_CNTXT_CAP0_RSS
value|(1<< 15)
define|#
directive|define
name|Q8_RCV_CNTXT_CAP0_MSFT_RSS
value|(1<< 16)
define|#
directive|define
name|Q8_RCV_CNTXT_CAP0_SGL_JUMBO
value|(1<< 18)
define|#
directive|define
name|Q8_RCV_CNTXT_CAP0_SGL_LRO
value|(1<< 19)
define|#
directive|define
name|Q8_RCV_CNTXT_CAP0_SINGLE_JUMBO
value|(1<< 26)
name|uint32_t
name|cap1
decl_stmt|;
name|uint32_t
name|cap2
decl_stmt|;
name|uint32_t
name|cap3
decl_stmt|;
name|uint8_t
name|nrds_sets_rings
decl_stmt|;
name|uint8_t
name|nsds_rings
decl_stmt|;
name|uint16_t
name|rds_producer_mode
decl_stmt|;
define|#
directive|define
name|Q8_RCV_CNTXT_RDS_PROD_MODE_UNIQUE
value|0
define|#
directive|define
name|Q8_RCV_CNTXT_RDS_PROD_MODE_SHARED
value|1
name|uint16_t
name|rcv_vpid
decl_stmt|;
name|uint16_t
name|rsrvd0
decl_stmt|;
name|uint32_t
name|rsrvd1
decl_stmt|;
name|q80_rq_sds_ring_t
name|sds
index|[
name|MAX_RCNTXT_SDS_RINGS
index|]
decl_stmt|;
name|q80_rq_rds_ring_t
name|rds
index|[
name|MAX_RDS_RING_SETS
index|]
decl_stmt|;
block|}
name|__packed
name|q80_rq_rcv_cntxt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_rsp_rds_ring
block|{
name|uint32_t
name|prod_std
decl_stmt|;
name|uint32_t
name|prod_jumbo
decl_stmt|;
block|}
name|__packed
name|q80_rsp_rds_ring_t
typedef|;
end_typedef

begin_comment
comment|/* 8 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_rsp_rcv_cntxt
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
name|uint8_t
name|nrds_sets_rings
decl_stmt|;
name|uint8_t
name|nsds_rings
decl_stmt|;
name|uint16_t
name|cntxt_id
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
name|uint8_t
name|num_funcs
decl_stmt|;
name|uint8_t
name|phy_port
decl_stmt|;
name|uint8_t
name|virt_port
decl_stmt|;
name|uint32_t
name|sds_cons
index|[
name|MAX_RCNTXT_SDS_RINGS
index|]
decl_stmt|;
name|q80_rsp_rds_ring_t
name|rds
index|[
name|MAX_RDS_RING_SETS
index|]
decl_stmt|;
block|}
name|__packed
name|q80_rsp_rcv_cntxt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_rcv_cntxt_destroy
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint32_t
name|cntxt_id
decl_stmt|;
block|}
name|__packed
name|q80_rcv_cntxt_destroy_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_rcv_cntxt_destroy_rsp
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
block|}
name|__packed
name|q80_rcv_cntxt_destroy_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Add Receive Rings  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_rq_add_rcv_rings
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint8_t
name|nrds_sets_rings
decl_stmt|;
name|uint8_t
name|nsds_rings
decl_stmt|;
name|uint16_t
name|cntxt_id
decl_stmt|;
name|q80_rq_sds_ring_t
name|sds
index|[
name|MAX_RCNTXT_SDS_RINGS
index|]
decl_stmt|;
name|q80_rq_rds_ring_t
name|rds
index|[
name|MAX_RDS_RING_SETS
index|]
decl_stmt|;
block|}
name|__packed
name|q80_rq_add_rcv_rings_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_rsp_add_rcv_rings
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
name|uint8_t
name|nrds_sets_rings
decl_stmt|;
name|uint8_t
name|nsds_rings
decl_stmt|;
name|uint16_t
name|cntxt_id
decl_stmt|;
name|uint32_t
name|sds_cons
index|[
name|MAX_RCNTXT_SDS_RINGS
index|]
decl_stmt|;
name|q80_rsp_rds_ring_t
name|rds
index|[
name|MAX_RDS_RING_SETS
index|]
decl_stmt|;
block|}
name|__packed
name|q80_rsp_add_rcv_rings_t
typedef|;
end_typedef

begin_comment
comment|/*  * Map Status Ring to Receive Descriptor Set  */
end_comment

begin_define
define|#
directive|define
name|MAX_SDS_TO_RDS_MAP
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
name|_q80_sds_rds_map_e
block|{
name|uint8_t
name|sds_ring
decl_stmt|;
name|uint8_t
name|rsrvd0
decl_stmt|;
name|uint8_t
name|rds_ring
decl_stmt|;
name|uint8_t
name|rsrvd1
decl_stmt|;
block|}
name|__packed
name|q80_sds_rds_map_e_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_rq_map_sds_to_rds
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|count_version
decl_stmt|;
name|uint16_t
name|cntxt_id
decl_stmt|;
name|uint16_t
name|num_rings
decl_stmt|;
name|q80_sds_rds_map_e_t
name|sds_rds
index|[
name|MAX_SDS_TO_RDS_MAP
index|]
decl_stmt|;
block|}
name|__packed
name|q80_rq_map_sds_to_rds_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_rsp_map_sds_to_rds
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|regcnt_status
decl_stmt|;
name|uint16_t
name|cntxt_id
decl_stmt|;
name|uint16_t
name|num_rings
decl_stmt|;
name|q80_sds_rds_map_e_t
name|sds_rds
index|[
name|MAX_SDS_TO_RDS_MAP
index|]
decl_stmt|;
block|}
name|__packed
name|q80_rsp_map_sds_to_rds_t
typedef|;
end_typedef

begin_comment
comment|/*  * Receive Descriptor corresponding to each entry in the receive ring  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_rcv_desc
block|{
name|uint16_t
name|handle
decl_stmt|;
name|uint16_t
name|rsrvd
decl_stmt|;
name|uint32_t
name|buf_size
decl_stmt|;
comment|/* buffer size in bytes */
name|uint64_t
name|buf_addr
decl_stmt|;
comment|/* physical address of buffer */
block|}
name|__packed
name|q80_recv_desc_t
typedef|;
end_typedef

begin_comment
comment|/*  * Status Descriptor corresponding to each entry in the Status ring  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_stat_desc
block|{
name|uint64_t
name|data
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
name|q80_stat_desc_t
typedef|;
end_typedef

begin_comment
comment|/*  * definitions for data[0] field of Status Descriptor  */
end_comment

begin_define
define|#
directive|define
name|Q8_STAT_DESC_RSS_HASH
parameter_list|(
name|data
parameter_list|)
value|(data& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_TOTAL_LENGTH
parameter_list|(
name|data
parameter_list|)
value|((data>> 32)& 0x3FFF)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_TOTAL_LENGTH_SGL_RCV
parameter_list|(
name|data
parameter_list|)
value|((data>> 32)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_HANDLE
parameter_list|(
name|data
parameter_list|)
value|((data>> 48)& 0xFFFF)
end_define

begin_comment
comment|/*  * definitions for data[1] field of Status Descriptor  */
end_comment

begin_define
define|#
directive|define
name|Q8_STAT_DESC_OPCODE
parameter_list|(
name|data
parameter_list|)
value|((data>> 42)& 0xF)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_OPCODE_RCV_PKT
value|0x01
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_OPCODE_LRO_PKT
value|0x02
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_OPCODE_SGL_LRO
value|0x04
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_OPCODE_SGL_RCV
value|0x05
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_OPCODE_CONT
value|0x06
end_define

begin_comment
comment|/*  * definitions for data[1] field of Status Descriptor for standard frames  * status descriptor opcode equals 0x04  */
end_comment

begin_define
define|#
directive|define
name|Q8_STAT_DESC_STATUS
parameter_list|(
name|data
parameter_list|)
value|((data>> 39)& 0x0007)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_STATUS_CHKSUM_NOT_DONE
value|0x00
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_STATUS_NO_CHKSUM
value|0x01
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_STATUS_CHKSUM_OK
value|0x02
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_STATUS_CHKSUM_ERR
value|0x03
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_VLAN
parameter_list|(
name|data
parameter_list|)
value|((data>> 47)& 1)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_VLAN_ID
parameter_list|(
name|data
parameter_list|)
value|((data>> 48)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_PROTOCOL
parameter_list|(
name|data
parameter_list|)
value|((data>> 44)& 0x000F)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_L2_OFFSET
parameter_list|(
name|data
parameter_list|)
value|((data>> 48)& 0x001F)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_COUNT
parameter_list|(
name|data
parameter_list|)
value|((data>> 37)& 0x0007)
end_define

begin_comment
comment|/*  * definitions for data[0-1] fields of Status Descriptor for LRO  * status descriptor opcode equals 0x04  */
end_comment

begin_comment
comment|/* definitions for data[1] field */
end_comment

begin_define
define|#
directive|define
name|Q8_LRO_STAT_DESC_SEQ_NUM
parameter_list|(
name|data
parameter_list|)
value|(uint32_t)(data)
end_define

begin_comment
comment|/*  * definitions specific to opcode 0x04 data[1]  */
end_comment

begin_define
define|#
directive|define
name|Q8_STAT_DESC_COUNT_SGL_LRO
parameter_list|(
name|data
parameter_list|)
value|((data>> 13)& 0x0007)
end_define

begin_define
define|#
directive|define
name|Q8_SGL_LRO_STAT_L2_OFFSET
parameter_list|(
name|data
parameter_list|)
value|((data>> 16)& 0xFF)
end_define

begin_define
define|#
directive|define
name|Q8_SGL_LRO_STAT_L4_OFFSET
parameter_list|(
name|data
parameter_list|)
value|((data>> 24)& 0xFF)
end_define

begin_define
define|#
directive|define
name|Q8_SGL_LRO_STAT_TS
parameter_list|(
name|data
parameter_list|)
value|((data>> 40)& 0x1)
end_define

begin_define
define|#
directive|define
name|Q8_SGL_LRO_STAT_PUSH_BIT
parameter_list|(
name|data
parameter_list|)
value|((data>> 41)& 0x1)
end_define

begin_comment
comment|/*  * definitions specific to opcode 0x05 data[1]  */
end_comment

begin_define
define|#
directive|define
name|Q8_STAT_DESC_COUNT_SGL_RCV
parameter_list|(
name|data
parameter_list|)
value|((data>> 37)& 0x0003)
end_define

begin_comment
comment|/*  * definitions for opcode 0x06  */
end_comment

begin_comment
comment|/* definitions for data[0] field */
end_comment

begin_define
define|#
directive|define
name|Q8_SGL_STAT_DESC_HANDLE1
parameter_list|(
name|data
parameter_list|)
value|(data& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|Q8_SGL_STAT_DESC_HANDLE2
parameter_list|(
name|data
parameter_list|)
value|((data>> 16)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|Q8_SGL_STAT_DESC_HANDLE3
parameter_list|(
name|data
parameter_list|)
value|((data>> 32)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|Q8_SGL_STAT_DESC_HANDLE4
parameter_list|(
name|data
parameter_list|)
value|((data>> 48)& 0xFFFF)
end_define

begin_comment
comment|/* definitions for data[1] field */
end_comment

begin_define
define|#
directive|define
name|Q8_SGL_STAT_DESC_HANDLE5
parameter_list|(
name|data
parameter_list|)
value|(data& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|Q8_SGL_STAT_DESC_HANDLE6
parameter_list|(
name|data
parameter_list|)
value|((data>> 16)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|Q8_SGL_STAT_DESC_NUM_HANDLES
parameter_list|(
name|data
parameter_list|)
value|((data>> 32)& 0x7)
end_define

begin_define
define|#
directive|define
name|Q8_SGL_STAT_DESC_HANDLE7
parameter_list|(
name|data
parameter_list|)
value|((data>> 48)& 0xFFFF)
end_define

begin_comment
comment|/** Driver Related Definitions Begin **/
end_comment

begin_define
define|#
directive|define
name|TX_SMALL_PKT_SIZE
value|128
end_define

begin_comment
comment|/* size in bytes of small packets */
end_comment

begin_comment
comment|/* The number of descriptors should be a power of 2 */
end_comment

begin_define
define|#
directive|define
name|NUM_TX_DESCRIPTORS
value|1024
end_define

begin_define
define|#
directive|define
name|NUM_STATUS_DESCRIPTORS
value|1024
end_define

begin_define
define|#
directive|define
name|NUM_RX_DESCRIPTORS
value|2048
end_define

begin_comment
comment|/*  * structure describing various dma buffers  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|qla_dmabuf
block|{
specifier|volatile
struct|struct
block|{
name|uint32_t
name|tx_ring
range|:
literal|1
decl_stmt|,
name|rds_ring
range|:
literal|1
decl_stmt|,
name|sds_ring
range|:
literal|1
decl_stmt|,
name|minidump
range|:
literal|1
decl_stmt|;
block|}
name|flags
struct|;
name|qla_dma_t
name|tx_ring
decl_stmt|;
name|qla_dma_t
name|rds_ring
index|[
name|MAX_RDS_RINGS
index|]
decl_stmt|;
name|qla_dma_t
name|sds_ring
index|[
name|MAX_SDS_RINGS
index|]
decl_stmt|;
name|qla_dma_t
name|minidump
decl_stmt|;
block|}
name|qla_dmabuf_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_qla_sds
block|{
name|q80_stat_desc_t
modifier|*
name|sds_ring_base
decl_stmt|;
comment|/* start of sds ring */
name|uint32_t
name|sdsr_next
decl_stmt|;
comment|/* next entry in SDS ring to process */
name|struct
name|lro_ctrl
name|lro
decl_stmt|;
name|void
modifier|*
name|rxb_free
decl_stmt|;
name|uint32_t
name|rx_free
decl_stmt|;
specifier|volatile
name|uint32_t
name|rcv_active
decl_stmt|;
name|uint32_t
name|sds_consumer
decl_stmt|;
name|uint64_t
name|intr_count
decl_stmt|;
name|uint64_t
name|spurious_intr_count
decl_stmt|;
block|}
name|qla_sds_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Q8_MAX_LRO_CONT_DESC
value|7
end_define

begin_define
define|#
directive|define
name|Q8_MAX_HANDLES_LRO
value|(1 + (Q8_MAX_LRO_CONT_DESC * 7))
end_define

begin_define
define|#
directive|define
name|Q8_MAX_HANDLES_NON_LRO
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
name|_qla_sgl_rcv
block|{
name|uint16_t
name|pkt_length
decl_stmt|;
name|uint16_t
name|num_handles
decl_stmt|;
name|uint16_t
name|chksum_status
decl_stmt|;
name|uint32_t
name|rss_hash
decl_stmt|;
name|uint16_t
name|rss_hash_flags
decl_stmt|;
name|uint16_t
name|vlan_tag
decl_stmt|;
name|uint16_t
name|handle
index|[
name|Q8_MAX_HANDLES_NON_LRO
index|]
decl_stmt|;
block|}
name|qla_sgl_rcv_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_qla_sgl_lro
block|{
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|Q8_LRO_COMP_TS
value|0x1
define|#
directive|define
name|Q8_LRO_COMP_PUSH_BIT
value|0x2
name|uint16_t
name|l2_offset
decl_stmt|;
name|uint16_t
name|l4_offset
decl_stmt|;
name|uint16_t
name|payload_length
decl_stmt|;
name|uint16_t
name|num_handles
decl_stmt|;
name|uint32_t
name|rss_hash
decl_stmt|;
name|uint16_t
name|rss_hash_flags
decl_stmt|;
name|uint16_t
name|vlan_tag
decl_stmt|;
name|uint16_t
name|handle
index|[
name|Q8_MAX_HANDLES_LRO
index|]
decl_stmt|;
block|}
name|qla_sgl_lro_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|qla_sgl_rcv_t
name|rcv
decl_stmt|;
name|qla_sgl_lro_t
name|lro
decl_stmt|;
block|}
name|qla_sgl_comp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|QL_FRAME_HDR_SIZE
value|(ETHER_HDR_LEN + ETHER_VLAN_ENCAP_LEN +\ 		sizeof (struct ip6_hdr) + sizeof (struct tcphdr) + 16)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_qla_hw_tx_cntxt
block|{
name|q80_tx_cmd_t
modifier|*
name|tx_ring_base
decl_stmt|;
name|bus_addr_t
name|tx_ring_paddr
decl_stmt|;
specifier|volatile
name|uint32_t
modifier|*
name|tx_cons
decl_stmt|;
comment|/* tx consumer shadow reg */
name|bus_addr_t
name|tx_cons_paddr
decl_stmt|;
specifier|volatile
name|uint32_t
name|txr_free
decl_stmt|;
comment|/* # of free entries in tx ring */
specifier|volatile
name|uint32_t
name|txr_next
decl_stmt|;
comment|/* # next available tx ring entry */
specifier|volatile
name|uint32_t
name|txr_comp
decl_stmt|;
comment|/* index of last tx entry completed */
name|uint32_t
name|tx_prod_reg
decl_stmt|;
name|uint16_t
name|tx_cntxt_id
decl_stmt|;
block|}
name|qla_hw_tx_cntxt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_qla_mcast
block|{
name|uint16_t
name|rsrvd
decl_stmt|;
name|uint8_t
name|addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
block|}
name|__packed
name|qla_mcast_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_qla_rdesc
block|{
specifier|volatile
name|uint32_t
name|prod_std
decl_stmt|;
specifier|volatile
name|uint32_t
name|prod_jumbo
decl_stmt|;
specifier|volatile
name|uint32_t
name|rx_next
decl_stmt|;
comment|/* next standard rcv ring to arm fw */
specifier|volatile
name|int32_t
name|rx_in
decl_stmt|;
comment|/* next standard rcv ring to add mbufs */
specifier|volatile
name|uint64_t
name|count
decl_stmt|;
block|}
name|qla_rdesc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_qla_flash_desc_table
block|{
name|uint32_t
name|flash_valid
decl_stmt|;
name|uint16_t
name|flash_ver
decl_stmt|;
name|uint16_t
name|flash_len
decl_stmt|;
name|uint16_t
name|flash_cksum
decl_stmt|;
name|uint16_t
name|flash_unused
decl_stmt|;
name|uint8_t
name|flash_model
index|[
literal|16
index|]
decl_stmt|;
name|uint16_t
name|flash_manuf
decl_stmt|;
name|uint16_t
name|flash_id
decl_stmt|;
name|uint8_t
name|flash_flag
decl_stmt|;
name|uint8_t
name|erase_cmd
decl_stmt|;
name|uint8_t
name|alt_erase_cmd
decl_stmt|;
name|uint8_t
name|write_enable_cmd
decl_stmt|;
name|uint8_t
name|write_enable_bits
decl_stmt|;
name|uint8_t
name|write_statusreg_cmd
decl_stmt|;
name|uint8_t
name|unprotected_sec_cmd
decl_stmt|;
name|uint8_t
name|read_manuf_cmd
decl_stmt|;
name|uint32_t
name|block_size
decl_stmt|;
name|uint32_t
name|alt_block_size
decl_stmt|;
name|uint32_t
name|flash_size
decl_stmt|;
name|uint32_t
name|write_enable_data
decl_stmt|;
name|uint8_t
name|readid_addr_len
decl_stmt|;
name|uint8_t
name|write_disable_bits
decl_stmt|;
name|uint8_t
name|read_dev_id_len
decl_stmt|;
name|uint8_t
name|chip_erase_cmd
decl_stmt|;
name|uint16_t
name|read_timeo
decl_stmt|;
name|uint8_t
name|protected_sec_cmd
decl_stmt|;
name|uint8_t
name|resvd
index|[
literal|65
index|]
decl_stmt|;
block|}
name|__packed
name|qla_flash_desc_table_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct for storing hardware specific information for a given interface  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_hw
block|{
struct|struct
block|{
name|uint32_t
name|unicast_mac
range|:
literal|1
decl_stmt|,
name|bcast_mac
range|:
literal|1
decl_stmt|,
name|loopback_mode
range|:
literal|2
decl_stmt|,
name|init_tx_cnxt
range|:
literal|1
decl_stmt|,
name|init_rx_cnxt
range|:
literal|1
decl_stmt|,
name|init_intr_cnxt
range|:
literal|1
decl_stmt|,
name|fduplex
range|:
literal|1
decl_stmt|,
name|autoneg
range|:
literal|1
decl_stmt|,
name|fdt_valid
range|:
literal|1
decl_stmt|;
block|}
name|flags
struct|;
name|uint16_t
name|link_speed
decl_stmt|;
name|uint16_t
name|cable_length
decl_stmt|;
name|uint32_t
name|cable_oui
decl_stmt|;
name|uint8_t
name|link_up
decl_stmt|;
name|uint8_t
name|module_type
decl_stmt|;
name|uint8_t
name|link_faults
decl_stmt|;
name|uint8_t
name|mac_rcv_mode
decl_stmt|;
name|uint32_t
name|max_mtu
decl_stmt|;
name|uint8_t
name|mac_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|uint32_t
name|num_sds_rings
decl_stmt|;
name|uint32_t
name|num_rds_rings
decl_stmt|;
name|uint32_t
name|num_tx_rings
decl_stmt|;
name|qla_dmabuf_t
name|dma_buf
decl_stmt|;
comment|/* Transmit Side */
name|qla_hw_tx_cntxt_t
name|tx_cntxt
index|[
name|NUM_TX_RINGS
index|]
decl_stmt|;
comment|/* Receive Side */
name|uint16_t
name|rcv_cntxt_id
decl_stmt|;
name|uint32_t
name|mbx_intr_mask_offset
decl_stmt|;
name|uint16_t
name|intr_id
index|[
name|MAX_SDS_RINGS
index|]
decl_stmt|;
name|uint32_t
name|intr_src
index|[
name|MAX_SDS_RINGS
index|]
decl_stmt|;
name|qla_sds_t
name|sds
index|[
name|MAX_SDS_RINGS
index|]
decl_stmt|;
name|uint32_t
name|mbox
index|[
name|Q8_NUM_MBOX
index|]
decl_stmt|;
name|qla_rdesc_t
name|rds
index|[
name|MAX_RDS_RINGS
index|]
decl_stmt|;
name|uint32_t
name|rds_pidx_thres
decl_stmt|;
name|uint32_t
name|sds_cidx_thres
decl_stmt|;
name|uint32_t
name|rcv_intr_coalesce
decl_stmt|;
name|uint32_t
name|xmt_intr_coalesce
decl_stmt|;
comment|/* Immediate Completion */
specifier|volatile
name|uint32_t
name|imd_compl
decl_stmt|;
specifier|volatile
name|uint32_t
name|aen_mb0
decl_stmt|;
specifier|volatile
name|uint32_t
name|aen_mb1
decl_stmt|;
specifier|volatile
name|uint32_t
name|aen_mb2
decl_stmt|;
specifier|volatile
name|uint32_t
name|aen_mb3
decl_stmt|;
specifier|volatile
name|uint32_t
name|aen_mb4
decl_stmt|;
comment|/* multicast address list */
name|uint32_t
name|nmcast
decl_stmt|;
name|qla_mcast_t
name|mcast
index|[
name|Q8_MAX_NUM_MULTICAST_ADDRS
index|]
decl_stmt|;
name|uint8_t
name|mac_addr_arr
index|[
operator|(
name|Q8_MAX_MAC_ADDRS
operator|*
name|ETHER_ADDR_LEN
operator|)
index|]
decl_stmt|;
comment|/* reset sequence */
define|#
directive|define
name|Q8_MAX_RESET_SEQ_IDX
value|16
name|uint32_t
name|rst_seq
index|[
name|Q8_MAX_RESET_SEQ_IDX
index|]
decl_stmt|;
name|uint32_t
name|rst_seq_idx
decl_stmt|;
comment|/* heart beat register value */
name|uint32_t
name|hbeat_value
decl_stmt|;
name|uint32_t
name|health_count
decl_stmt|;
name|uint32_t
name|max_tx_segs
decl_stmt|;
name|uint32_t
name|min_lro_pkt_size
decl_stmt|;
name|uint32_t
name|enable_hw_lro
decl_stmt|;
name|uint32_t
name|enable_soft_lro
decl_stmt|;
name|uint32_t
name|enable_9kb
decl_stmt|;
name|uint32_t
name|user_pri_nic
decl_stmt|;
name|uint32_t
name|user_pri_iscsi
decl_stmt|;
name|uint64_t
name|iscsi_pkt_count
decl_stmt|;
comment|/* Flash Descriptor Table */
name|qla_flash_desc_table_t
name|fdt
decl_stmt|;
comment|/* Minidump Related */
name|uint32_t
name|mdump_init
decl_stmt|;
name|uint32_t
name|mdump_done
decl_stmt|;
name|uint32_t
name|mdump_active
decl_stmt|;
name|uint32_t
name|mdump_capture_mask
decl_stmt|;
name|uint32_t
name|mdump_start_seq_index
decl_stmt|;
name|void
modifier|*
name|mdump_buffer
decl_stmt|;
name|uint32_t
name|mdump_buffer_size
decl_stmt|;
name|void
modifier|*
name|mdump_template
decl_stmt|;
name|uint32_t
name|mdump_template_size
decl_stmt|;
block|}
name|qla_hw_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|QL_UPDATE_RDS_PRODUCER_INDEX
parameter_list|(
name|ha
parameter_list|,
name|prod_reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_4((ha->pci_reg), prod_reg, val);
end_define

begin_define
define|#
directive|define
name|QL_UPDATE_TX_PRODUCER_INDEX
parameter_list|(
name|ha
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
define|\
value|WRITE_REG32(ha, ha->hw.tx_cntxt[i].tx_prod_reg, val)
end_define

begin_define
define|#
directive|define
name|QL_UPDATE_SDS_CONSUMER_INDEX
parameter_list|(
name|ha
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_4((ha->pci_reg), (ha->hw.sds[i].sds_consumer), val);
end_define

begin_define
define|#
directive|define
name|QL_ENABLE_INTERRUPTS
parameter_list|(
name|ha
parameter_list|,
name|i
parameter_list|)
define|\
value|bus_write_4((ha->pci_reg), (ha->hw.intr_src[i]), 0);
end_define

begin_define
define|#
directive|define
name|QL_BUFFER_ALIGN
value|16
end_define

begin_comment
comment|/*  * Flash Configuration   */
end_comment

begin_define
define|#
directive|define
name|Q8_BOARD_CONFIG_OFFSET
value|0x370000
end_define

begin_define
define|#
directive|define
name|Q8_BOARD_CONFIG_LENGTH
value|0x2000
end_define

begin_define
define|#
directive|define
name|Q8_BOARD_CONFIG_MAC0_LO
value|0x400
end_define

begin_define
define|#
directive|define
name|Q8_FDT_LOCK_MAGIC_ID
value|0x00FD00FD
end_define

begin_define
define|#
directive|define
name|Q8_FDT_FLASH_ADDR_VAL
value|0xFD009F
end_define

begin_define
define|#
directive|define
name|Q8_FDT_FLASH_CTRL_VAL
value|0x3F
end_define

begin_define
define|#
directive|define
name|Q8_FDT_MASK_VAL
value|0xFF
end_define

begin_define
define|#
directive|define
name|Q8_WR_ENABLE_FL_ADDR
value|0xFD0100
end_define

begin_define
define|#
directive|define
name|Q8_WR_ENABLE_FL_CTRL
value|0x5
end_define

begin_define
define|#
directive|define
name|Q8_ERASE_LOCK_MAGIC_ID
value|0x00EF00EF
end_define

begin_define
define|#
directive|define
name|Q8_ERASE_FL_ADDR_MASK
value|0xFD0300
end_define

begin_define
define|#
directive|define
name|Q8_ERASE_FL_CTRL_MASK
value|0x3D
end_define

begin_define
define|#
directive|define
name|Q8_WR_FL_LOCK_MAGIC_ID
value|0xABCDABCD
end_define

begin_define
define|#
directive|define
name|Q8_WR_FL_ADDR_MASK
value|0x800000
end_define

begin_define
define|#
directive|define
name|Q8_WR_FL_CTRL_MASK
value|0x3D
end_define

begin_define
define|#
directive|define
name|QL_FDT_OFFSET
value|0x3F0000
end_define

begin_define
define|#
directive|define
name|Q8_FLASH_SECTOR_SIZE
value|0x10000
end_define

begin_comment
comment|/*  * Off Chip Memory Access  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_offchip_mem_val
block|{
name|uint32_t
name|data_lo
decl_stmt|;
name|uint32_t
name|data_hi
decl_stmt|;
name|uint32_t
name|data_ulo
decl_stmt|;
name|uint32_t
name|data_uhi
decl_stmt|;
block|}
name|q80_offchip_mem_val_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _QL_HW_H_ */
end_comment

end_unit

