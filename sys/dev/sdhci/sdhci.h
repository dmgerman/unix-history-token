begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Alexander Motin<mav@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SDHCI_H__
end_ifndef

begin_define
define|#
directive|define
name|__SDHCI_H__
end_define

begin_define
define|#
directive|define
name|DMA_BLOCK_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|DMA_BOUNDARY
value|0
end_define

begin_comment
comment|/* DMA reload every 4K */
end_comment

begin_comment
comment|/* Controller doesn't honor resets unless we touch the clock register */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_CLOCK_BEFORE_RESET
value|(1<< 0)
end_define

begin_comment
comment|/* Controller really supports DMA */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_FORCE_DMA
value|(1<< 1)
end_define

begin_comment
comment|/* Controller has unusable DMA engine */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_BROKEN_DMA
value|(1<< 2)
end_define

begin_comment
comment|/* Controller doesn't like to be reset when there is no card inserted. */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_NO_CARD_NO_RESET
value|(1<< 3)
end_define

begin_comment
comment|/* Controller has flaky internal state so reset it on each ios change */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_RESET_ON_IOS
value|(1<< 4)
end_define

begin_comment
comment|/* Controller can only DMA chunk sizes that are a multiple of 32 bits */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_32BIT_DMA_SIZE
value|(1<< 5)
end_define

begin_comment
comment|/* Controller needs to be reset after each request to stay stable */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_RESET_AFTER_REQUEST
value|(1<< 6)
end_define

begin_comment
comment|/* Controller has an off-by-one issue with timeout value */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_INCR_TIMEOUT_CONTROL
value|(1<< 7)
end_define

begin_comment
comment|/* Controller has broken read timings */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_BROKEN_TIMINGS
value|(1<< 8)
end_define

begin_comment
comment|/* Controller needs lowered frequency */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_LOWER_FREQUENCY
value|(1<< 9)
end_define

begin_comment
comment|/* Data timeout is invalid, should use SD clock */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_DATA_TIMEOUT_USES_SDCLK
value|(1<< 10)
end_define

begin_comment
comment|/* Timeout value is invalid, should be overriden */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_BROKEN_TIMEOUT_VAL
value|(1<< 11)
end_define

begin_comment
comment|/* SDHCI_CAPABILITIES is invalid */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_MISSING_CAPS
value|(1<< 12)
end_define

begin_comment
comment|/* Hardware shifts the 136-bit response, don't do it in software. */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_DONT_SHIFT_RESPONSE
value|(1<< 13)
end_define

begin_comment
comment|/* Wait to see reset bit asserted before waiting for de-asserted  */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_WAITFOR_RESET_ASSERTED
value|(1<< 14)
end_define

begin_comment
comment|/* Leave controller in standard mode when putting card in HS mode. */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_DONT_SET_HISPD_BIT
value|(1<< 15)
end_define

begin_comment
comment|/* Alternate clock source is required when supplying a 400 KHz clock. */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_BCM577XX_400KHZ_CLKSRC
value|(1<< 16)
end_define

begin_comment
comment|/* Card insert/remove interrupts don't work, polling required. */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_POLL_CARD_PRESENT
value|(1<< 17)
end_define

begin_comment
comment|/* All controller slots are non-removable. */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_ALL_SLOTS_NON_REMOVABLE
value|(1<< 18)
end_define

begin_comment
comment|/* Issue custom Intel controller reset sequence after power-up. */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_INTEL_POWER_UP_RESET
value|(1<< 19)
end_define

begin_comment
comment|/* Data timeout is invalid, use 1 MHz clock instead. */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_DATA_TIMEOUT_1MHZ
value|(1<< 20)
end_define

begin_comment
comment|/* Controller doesn't allow access boot partitions. */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_BOOT_NOACC
value|(1<< 21)
end_define

begin_comment
comment|/* Controller waits for busy responses. */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_WAIT_WHILE_BUSY
value|(1<< 22)
end_define

begin_comment
comment|/* Controller supports eMMC DDR52 mode. */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_MMC_DDR52
value|(1<< 23)
end_define

begin_comment
comment|/* Controller support for UHS DDR50 mode is broken. */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_BROKEN_UHS_DDR50
value|(1<< 24)
end_define

begin_comment
comment|/* Controller support for eMMC HS200 mode is broken. */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_BROKEN_MMC_HS200
value|(1<< 25)
end_define

begin_comment
comment|/* Controller reports support for eMMC HS400 mode as SDHCI_CAN_MMC_HS400. */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_CAPS_BIT63_FOR_MMC_HS400
value|(1<< 26)
end_define

begin_comment
comment|/* Controller support for SDHCI_CTRL2_PRESET_VALUE is broken. */
end_comment

begin_define
define|#
directive|define
name|SDHCI_QUIRK_PRESET_VALUE_BROKEN
value|(1<< 27)
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
name|SDHCI_RETUNE_REQUEST
value|0x00000008
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
name|SDHCI_STATE_DAT_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|SDHCI_STATE_CMD
value|0x01000000
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
name|SDHCI_CTRL_DMA_MASK
value|0x18
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL_8BITBUS
value|0x20
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
name|SDHCI_DIVIDER_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|SDHCI_DIVIDER_MASK_LEN
value|8
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
name|SDHCI_DIVIDER_HI_MASK
value|3
end_define

begin_define
define|#
directive|define
name|SDHCI_DIVIDER_HI_SHIFT
value|6
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
name|SDHCI_DIVIDERS_MASK
define|\
value|((SDHCI_DIVIDER_MASK<< SDHCI_DIVIDER_SHIFT) | \     (SDHCI_DIVIDER_HI_MASK<< SDHCI_DIVIDER_HI_SHIFT))
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
name|SDHCI_INT_INT_A
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_INT_B
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_INT_C
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_RETUNE
value|0x00001000
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
name|SDHCI_INT_TUNEERR
value|0x04000000
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
name|SDHCI_INT_CMD_ERROR_MASK
value|(SDHCI_INT_TIMEOUT | \ 		SDHCI_INT_CRC | SDHCI_INT_END_BIT | SDHCI_INT_INDEX)
end_define

begin_define
define|#
directive|define
name|SDHCI_INT_CMD_MASK
value|(SDHCI_INT_RESPONSE | SDHCI_INT_CMD_ERROR_MASK)
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
name|SDHCI_HOST_CONTROL2
value|0x3E
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL2_PRESET_VALUE
value|0x8000
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL2_ASYNC_INTR
value|0x4000
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL2_SAMPLING_CLOCK
value|0x0080
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL2_EXEC_TUNING
value|0x0040
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL2_DRIVER_TYPE_MASK
value|0x0030
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL2_DRIVER_TYPE_B
value|0x0000
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL2_DRIVER_TYPE_A
value|0x0010
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL2_DRIVER_TYPE_C
value|0x0020
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL2_DRIVER_TYPE_D
value|0x0030
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL2_S18_ENABLE
value|0x0008
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL2_UHS_MASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL2_UHS_SDR12
value|0x0000
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL2_UHS_SDR25
value|0x0001
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL2_UHS_SDR50
value|0x0002
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL2_UHS_SDR104
value|0x0003
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL2_UHS_DDR50
value|0x0004
end_define

begin_define
define|#
directive|define
name|SDHCI_CTRL2_MMC_HS400
value|0x0005
end_define

begin_comment
comment|/* non-standard */
end_comment

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
name|SDHCI_CLOCK_V3_BASE_MASK
value|0x0000FF00
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
name|SDHCI_CAN_DO_8BITBUS
value|0x00040000
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
name|SDHCI_CAN_ASYNC_INTR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SDHCI_SLOTTYPE_MASK
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|SDHCI_SLOTTYPE_REMOVABLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SDHCI_SLOTTYPE_EMBEDDED
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SDHCI_SLOTTYPE_SHARED
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SDHCI_CAPABILITIES2
value|0x44
end_define

begin_define
define|#
directive|define
name|SDHCI_CAN_SDR50
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SDHCI_CAN_SDR104
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SDHCI_CAN_DDR50
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SDHCI_CAN_DRIVE_TYPE_A
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SDHCI_CAN_DRIVE_TYPE_C
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SDHCI_CAN_DRIVE_TYPE_D
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SDHCI_RETUNE_CNT_MASK
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|SDHCI_RETUNE_CNT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SDHCI_TUNE_SDR50
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SDHCI_RETUNE_MODES_MASK
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|SDHCI_RETUNE_MODES_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|SDHCI_CLOCK_MULT_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|SDHCI_CLOCK_MULT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SDHCI_CAN_MMC_HS400
value|0x80000000
end_define

begin_comment
comment|/* non-standard */
end_comment

begin_define
define|#
directive|define
name|SDHCI_MAX_CURRENT
value|0x48
end_define

begin_define
define|#
directive|define
name|SDHCI_FORCE_AUTO_EVENT
value|0x50
end_define

begin_define
define|#
directive|define
name|SDHCI_FORCE_INTR_EVENT
value|0x52
end_define

begin_define
define|#
directive|define
name|SDHCI_ADMA_ERR
value|0x54
end_define

begin_define
define|#
directive|define
name|SDHCI_ADMA_ERR_LENGTH
value|0x04
end_define

begin_define
define|#
directive|define
name|SDHCI_ADMA_ERR_STATE_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|SDHCI_ADMA_ERR_STATE_STOP
value|0x00
end_define

begin_define
define|#
directive|define
name|SDHCI_ADMA_ERR_STATE_FDS
value|0x01
end_define

begin_define
define|#
directive|define
name|SDHCI_ADMA_ERR_STATE_TFR
value|0x03
end_define

begin_define
define|#
directive|define
name|SDHCI_ADMA_ADDRESS_LO
value|0x58
end_define

begin_define
define|#
directive|define
name|SDHCI_ADMA_ADDRESS_HI
value|0x5C
end_define

begin_define
define|#
directive|define
name|SDHCI_PRESET_VALUE
value|0x60
end_define

begin_define
define|#
directive|define
name|SDHCI_SHARED_BUS_CTRL
value|0xE0
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

begin_define
define|#
directive|define
name|SDHCI_SPEC_100
value|0
end_define

begin_define
define|#
directive|define
name|SDHCI_SPEC_200
value|1
end_define

begin_define
define|#
directive|define
name|SDHCI_SPEC_300
value|2
end_define

begin_define
define|#
directive|define
name|SDHCI_SPEC_400
value|3
end_define

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw_sdhci
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|sdhci_quirk_clear
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|sdhci_quirk_set
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|sdhci_slot
block|{
name|struct
name|mtx
name|mtx
decl_stmt|;
comment|/* Slot mutex */
name|u_int
name|quirks
decl_stmt|;
comment|/* Chip specific quirks */
name|u_int
name|caps
decl_stmt|;
comment|/* Override SDHCI_CAPABILITIES */
name|u_int
name|caps2
decl_stmt|;
comment|/* Override SDHCI_CAPABILITIES2 */
name|device_t
name|bus
decl_stmt|;
comment|/* Bus device */
name|device_t
name|dev
decl_stmt|;
comment|/* Slot device */
name|u_char
name|num
decl_stmt|;
comment|/* Slot number */
name|u_char
name|opt
decl_stmt|;
comment|/* Slot options */
define|#
directive|define
name|SDHCI_HAVE_DMA
value|0x01
define|#
directive|define
name|SDHCI_PLATFORM_TRANSFER
value|0x02
define|#
directive|define
name|SDHCI_NON_REMOVABLE
value|0x04
define|#
directive|define
name|SDHCI_TUNING_SUPPORTED
value|0x08
define|#
directive|define
name|SDHCI_TUNING_ENABLED
value|0x10
define|#
directive|define
name|SDHCI_SDR50_NEEDS_TUNING
value|0x20
name|u_char
name|version
decl_stmt|;
name|int
name|timeout
decl_stmt|;
comment|/* Transfer timeout */
name|uint32_t
name|max_clk
decl_stmt|;
comment|/* Max possible freq */
name|uint32_t
name|timeout_clk
decl_stmt|;
comment|/* Timeout freq */
name|bus_dma_tag_t
name|dmatag
decl_stmt|;
name|bus_dmamap_t
name|dmamap
decl_stmt|;
name|u_char
modifier|*
name|dmamem
decl_stmt|;
name|bus_addr_t
name|paddr
decl_stmt|;
comment|/* DMA buffer address */
name|struct
name|task
name|card_task
decl_stmt|;
comment|/* Card presence check task */
name|struct
name|timeout_task
name|card_delayed_task
decl_stmt|;
comment|/* Card insert delayed task */
name|struct
name|callout
name|card_poll_callout
decl_stmt|;
comment|/* Card present polling callout */
name|struct
name|callout
name|timeout_callout
decl_stmt|;
comment|/* Card command/data response timeout */
name|struct
name|callout
name|retune_callout
decl_stmt|;
comment|/* Re-tuning mode 1 callout */
name|struct
name|mmc_host
name|host
decl_stmt|;
comment|/* Host parameters */
name|struct
name|mmc_request
modifier|*
name|req
decl_stmt|;
comment|/* Current request */
name|struct
name|mmc_command
modifier|*
name|curcmd
decl_stmt|;
comment|/* Current command of current request */
name|struct
name|mmc_request
modifier|*
name|tune_req
decl_stmt|;
comment|/* Tuning request */
name|struct
name|mmc_command
modifier|*
name|tune_cmd
decl_stmt|;
comment|/* Tuning command of tuning request */
name|struct
name|mmc_data
modifier|*
name|tune_data
decl_stmt|;
comment|/* Tuning data of tuning command */
name|uint32_t
name|retune_ticks
decl_stmt|;
comment|/* Re-tuning callout ticks [hz] */
name|uint32_t
name|intmask
decl_stmt|;
comment|/* Current interrupt mask */
name|uint32_t
name|clock
decl_stmt|;
comment|/* Current clock freq. */
name|size_t
name|offset
decl_stmt|;
comment|/* Data buffer offset */
name|uint8_t
name|hostctrl
decl_stmt|;
comment|/* Current host control register */
name|uint8_t
name|retune_count
decl_stmt|;
comment|/* Controller re-tuning count [s] */
name|uint8_t
name|retune_mode
decl_stmt|;
comment|/* Controller re-tuning mode */
define|#
directive|define
name|SDHCI_RETUNE_MODE_1
value|0x00
define|#
directive|define
name|SDHCI_RETUNE_MODE_2
value|0x01
define|#
directive|define
name|SDHCI_RETUNE_MODE_3
value|0x02
name|uint8_t
name|retune_req
decl_stmt|;
comment|/* Re-tuning request status */
define|#
directive|define
name|SDHCI_RETUNE_REQ_NEEDED
value|0x01
comment|/* Re-tuning w/o circuit reset needed */
define|#
directive|define
name|SDHCI_RETUNE_REQ_RESET
value|0x02
comment|/* Re-tuning w/ circuit reset needed */
name|u_char
name|power
decl_stmt|;
comment|/* Current power */
name|u_char
name|bus_busy
decl_stmt|;
comment|/* Bus busy status */
name|u_char
name|cmd_done
decl_stmt|;
comment|/* CMD command part done flag */
name|u_char
name|data_done
decl_stmt|;
comment|/* DAT command part done flag */
name|u_char
name|flags
decl_stmt|;
comment|/* Request execution flags */
define|#
directive|define
name|CMD_STARTED
value|1
define|#
directive|define
name|STOP_STARTED
value|2
define|#
directive|define
name|SDHCI_USE_DMA
value|4
comment|/* Use DMA for this req. */
define|#
directive|define
name|PLATFORM_DATA_STARTED
value|8
comment|/* Data xfer is handled by platform */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|sdhci_generic_read_ivar
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|which
parameter_list|,
name|uintptr_t
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdhci_generic_write_ivar
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|which
parameter_list|,
name|uintptr_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdhci_init_slot
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|sdhci_slot
modifier|*
name|slot
parameter_list|,
name|int
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sdhci_start_slot
parameter_list|(
name|struct
name|sdhci_slot
modifier|*
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* performs generic clean-up for platform transfers */
end_comment

begin_function_decl
name|void
name|sdhci_finish_data
parameter_list|(
name|struct
name|sdhci_slot
modifier|*
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdhci_cleanup_slot
parameter_list|(
name|struct
name|sdhci_slot
modifier|*
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdhci_generic_suspend
parameter_list|(
name|struct
name|sdhci_slot
modifier|*
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdhci_generic_resume
parameter_list|(
name|struct
name|sdhci_slot
modifier|*
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdhci_generic_update_ios
parameter_list|(
name|device_t
name|brdev
parameter_list|,
name|device_t
name|reqdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdhci_generic_tune
parameter_list|(
name|device_t
name|brdev
parameter_list|,
name|device_t
name|reqdev
parameter_list|,
name|bool
name|hs400
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdhci_generic_switch_vccq
parameter_list|(
name|device_t
name|brdev
parameter_list|,
name|device_t
name|reqdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdhci_generic_retune
parameter_list|(
name|device_t
name|brdev
parameter_list|,
name|device_t
name|reqdev
parameter_list|,
name|bool
name|reset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdhci_generic_request
parameter_list|(
name|device_t
name|brdev
parameter_list|,
name|device_t
name|reqdev
parameter_list|,
name|struct
name|mmc_request
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdhci_generic_get_ro
parameter_list|(
name|device_t
name|brdev
parameter_list|,
name|device_t
name|reqdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdhci_generic_acquire_host
parameter_list|(
name|device_t
name|brdev
parameter_list|,
name|device_t
name|reqdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdhci_generic_release_host
parameter_list|(
name|device_t
name|brdev
parameter_list|,
name|device_t
name|reqdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sdhci_generic_intr
parameter_list|(
name|struct
name|sdhci_slot
modifier|*
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|sdhci_generic_min_freq
parameter_list|(
name|device_t
name|brdev
parameter_list|,
name|struct
name|sdhci_slot
modifier|*
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|sdhci_generic_get_card_present
parameter_list|(
name|device_t
name|brdev
parameter_list|,
name|struct
name|sdhci_slot
modifier|*
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sdhci_generic_set_uhs_timing
parameter_list|(
name|device_t
name|brdev
parameter_list|,
name|struct
name|sdhci_slot
modifier|*
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sdhci_handle_card_present
parameter_list|(
name|struct
name|sdhci_slot
modifier|*
name|slot
parameter_list|,
name|bool
name|is_present
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SDHCI_H__ */
end_comment

end_unit

