begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Alexander Motin<mav@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * PCI registers  */
end_comment

begin_define
define|#
directive|define
name|PCI_SDHCI_IFPIO
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_SDHCI_IFDMA
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_SDHCI_IFVENDOR
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_SLOT_INFO
value|0x40
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_SLOT_INFO_SLOTS
parameter_list|(
name|x
parameter_list|)
value|(((x>> 4)& 7) + 1)
end_define

begin_define
define|#
directive|define
name|PCI_SLOT_INFO_FIRST_BAR
parameter_list|(
name|x
parameter_list|)
value|((x)& 7)
end_define

begin_comment
comment|/*  * Controller registers  */
end_comment

begin_define
define|#
directive|define
name|SDHCI_DMA_ADDRESS
value|0x00
end_define

begin_define
define|#
directive|define
name|SDHCI_BLOCK_SIZE
value|0x04
end_define

begin_define
define|#
directive|define
name|SDHCI_MAKE_BLKSZ
parameter_list|(
name|dma
parameter_list|,
name|blksz
parameter_list|)
value|(((dma& 0x7)<< 12) | (blksz& 0xFFF))
end_define

begin_define
define|#
directive|define
name|SDHCI_BLOCK_COUNT
value|0x06
end_define

begin_define
define|#
directive|define
name|SDHCI_ARGUMENT
value|0x08
end_define

begin_define
define|#
directive|define
name|SDHCI_TRANSFER_MODE
value|0x0C
end_define

begin_define
define|#
directive|define
name|SDHCI_TRNS_DMA
value|0x01
end_define

begin_define
define|#
directive|define
name|SDHCI_TRNS_BLK_CNT_EN
value|0x02
end_define

begin_define
define|#
directive|define
name|SDHCI_TRNS_ACMD12
value|0x04
end_define

begin_define
define|#
directive|define
name|SDHCI_TRNS_READ
value|0x10
end_define

begin_define
define|#
directive|define
name|SDHCI_TRNS_MULTI
value|0x20
end_define

begin_define
define|#
directive|define
name|SDHCI_COMMAND_FLAGS
value|0x0E
end_define

begin_define
define|#
directive|define
name|SDHCI_CMD_RESP_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|SDHCI_CMD_RESP_LONG
value|0x01
end_define

begin_define
define|#
directive|define
name|SDHCI_CMD_RESP_SHORT
value|0x02
end_define

begin_define
define|#
directive|define
name|SDHCI_CMD_RESP_SHORT_BUSY
value|0x03
end_define

begin_define
define|#
directive|define
name|SDHCI_CMD_RESP_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|SDHCI_CMD_CRC
value|0x08
end_define

begin_define
define|#
directive|define
name|SDHCI_CMD_INDEX
value|0x10
end_define

begin_define
define|#
directive|define
name|SDHCI_CMD_DATA
value|0x20
end_define

begin_define
define|#
directive|define
name|SDHCI_CMD_TYPE_NORMAL
value|0x00
end_define

begin_define
define|#
directive|define
name|SDHCI_CMD_TYPE_SUSPEND
value|0x40
end_define

begin_define
define|#
directive|define
name|SDHCI_CMD_TYPE_RESUME
value|0x80
end_define

begin_define
define|#
directive|define
name|SDHCI_CMD_TYPE_ABORT
value|0xc0
end_define

begin_define
define|#
directive|define
name|SDHCI_CMD_TYPE_MASK
value|0xc0
end_define

begin_define
define|#
directive|define
name|SDHCI_COMMAND
value|0x0F
end_define

begin_define
define|#
directive|define
name|SDHCI_RESPONSE
value|0x10
end_define

begin_define
define|#
directive|define
name|SDHCI_BUFFER
value|0x20
end_define

begin_define
define|#
directive|define
name|SDHCI_PRESENT_STATE
value|0x24
end_define

begin_define
define|#
directive|define
name|SDHCI_CMD_INHIBIT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SDHCI_DAT_INHIBIT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SDHCI_DAT_ACTIVE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SDHCI_DOING_WRITE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SDHCI_DOING_READ
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SDHCI_SPACE_AVAILABLE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SDHCI_DATA_AVAILABLE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SDHCI_CARD_PRESENT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SDHCI_CARD_STABLE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SDHCI_CARD_PIN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SDHCI_WRITE_PROTECT
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SDHCI_STATE_DAT
value|0x00700000
end_define

begin_define
define|#
directive|define
name|SDHCI_STATE_CMD
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SDHCI_HOST_CONTROL
value|0x28
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL_LED
value|0x01
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL_4BITBUS
value|0x02
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL_HISPD
value|0x04
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL_SDMA
value|0x08
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL_ADMA2
value|0x10
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL_ADMA264
value|0x18
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL_CARD_DET
value|0x40
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL_FORCE_CARD
value|0x80
end_define

begin_define
define|#
directive|define
name|SDHCI_POWER_CONTROL
value|0x29
end_define

begin_define
define|#
directive|define
name|SDHCI_POWER_ON
value|0x01
end_define

begin_define
define|#
directive|define
name|SDHCI_POWER_180
value|0x0A
end_define

begin_define
define|#
directive|define
name|SDHCI_POWER_300
value|0x0C
end_define

begin_define
define|#
directive|define
name|SDHCI_POWER_330
value|0x0E
end_define

begin_define
define|#
directive|define
name|SDHCI_BLOCK_GAP_CONTROL
value|0x2A
end_define

begin_define
define|#
directive|define
name|SDHCI_WAKE_UP_CONTROL
value|0x2B
end_define

begin_define
define|#
directive|define
name|SDHCI_CLOCK_CONTROL
value|0x2C
end_define

begin_define
define|#
directive|define
name|SDHCI_DIVIDER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SDHCI_CLOCK_CARD_EN
value|0x0004
end_define

begin_define
define|#
directive|define
name|SDHCI_CLOCK_INT_STABLE
value|0x0002
end_define

begin_define
define|#
directive|define
name|SDHCI_CLOCK_INT_EN
value|0x0001
end_define

begin_define
define|#
directive|define
name|SDHCI_TIMEOUT_CONTROL
value|0x2E
end_define

begin_define
define|#
directive|define
name|SDHCI_SOFTWARE_RESET
value|0x2F
end_define

begin_define
define|#
directive|define
name|SDHCI_RESET_ALL
value|0x01
end_define

begin_define
define|#
directive|define
name|SDHCI_RESET_CMD
value|0x02
end_define

begin_define
define|#
directive|define
name|SDHCI_RESET_DATA
value|0x04
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_STATUS
value|0x30
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_ENABLE
value|0x34
end_define

begin_define
define|#
directive|define
name|SDHCI_SIGNAL_ENABLE
value|0x38
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_RESPONSE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_DATA_END
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_BLOCK_GAP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_DMA_END
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_SPACE_AVAIL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_DATA_AVAIL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_CARD_INSERT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_CARD_REMOVE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_CARD_INT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_ERROR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_TIMEOUT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_CRC
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_END_BIT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_INDEX
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_DATA_TIMEOUT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_DATA_CRC
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_DATA_END_BIT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_BUS_POWER
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_ACMD12ERR
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_ADMAERR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_NORMAL_MASK
value|0x00007FFF
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_ERROR_MASK
value|0xFFFF8000
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_CMD_MASK
value|(SDHCI_INT_RESPONSE | SDHCI_INT_TIMEOUT | \ 		SDHCI_INT_CRC | SDHCI_INT_END_BIT | SDHCI_INT_INDEX)
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_DATA_MASK
value|(SDHCI_INT_DATA_END | SDHCI_INT_DMA_END | \ 		SDHCI_INT_DATA_AVAIL | SDHCI_INT_SPACE_AVAIL | \ 		SDHCI_INT_DATA_TIMEOUT | SDHCI_INT_DATA_CRC | \ 		SDHCI_INT_DATA_END_BIT)
end_define

begin_define
define|#
directive|define
name|SDHCI_ACMD12_ERR
value|0x3C
end_define

begin_define
define|#
directive|define
name|SDHCI_CAPABILITIES
value|0x40
end_define

begin_define
define|#
directive|define
name|SDHCI_TIMEOUT_CLK_MASK
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|SDHCI_TIMEOUT_CLK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SDHCI_TIMEOUT_CLK_UNIT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SDHCI_CLOCK_BASE_MASK
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|SDHCI_CLOCK_BASE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SDHCI_MAX_BLOCK_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|SDHCI_MAX_BLOCK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SDHCI_CAN_DO_ADMA2
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SDHCI_CAN_DO_HISPD
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SDHCI_CAN_DO_DMA
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SDHCI_CAN_DO_SUSPEND
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SDHCI_CAN_VDD_330
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SDHCI_CAN_VDD_300
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SDHCI_CAN_VDD_180
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SDHCI_CAN_DO_64BIT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SDHCI_MAX_CURRENT
value|0x48
end_define

begin_define
define|#
directive|define
name|SDHCI_SLOT_INT_STATUS
value|0xFC
end_define

begin_define
define|#
directive|define
name|SDHCI_HOST_VERSION
value|0xFE
end_define

begin_define
define|#
directive|define
name|SDHCI_VENDOR_VER_MASK
value|0xFF00
end_define

begin_define
define|#
directive|define
name|SDHCI_VENDOR_VER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SDHCI_SPEC_VER_MASK
value|0x00FF
end_define

begin_define
define|#
directive|define
name|SDHCI_SPEC_VER_SHIFT
value|0
end_define

end_unit

