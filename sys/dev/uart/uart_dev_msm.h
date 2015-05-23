begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ganbold Tsagaankhuu<ganbold@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UART_DM_H_
end_ifndef

begin_define
define|#
directive|define
name|_UART_DM_H_
end_define

begin_define
define|#
directive|define
name|UART_DM_EXTR_BITS
parameter_list|(
name|value
parameter_list|,
name|start_pos
parameter_list|,
name|end_pos
parameter_list|)
define|\
value|((value<< (32 - end_pos))>> (32 - (end_pos - start_pos)))
end_define

begin_comment
comment|/* UART Parity Mode */
end_comment

begin_enum
enum|enum
name|UART_DM_PARITY_MODE
block|{
name|UART_DM_NO_PARITY
block|,
name|UART_DM_ODD_PARITY
block|,
name|UART_DM_EVEN_PARITY
block|,
name|UART_DM_SPACE_PARITY
block|}
enum|;
end_enum

begin_comment
comment|/* UART Stop Bit Length */
end_comment

begin_enum
enum|enum
name|UART_DM_STOP_BIT_LEN
block|{
name|UART_DM_SBL_9_16
block|,
name|UART_DM_SBL_1
block|,
name|UART_DM_SBL_1_9_16
block|,
name|UART_DM_SBL_2
block|}
enum|;
end_enum

begin_comment
comment|/* UART Bits per Char */
end_comment

begin_enum
enum|enum
name|UART_DM_BITS_PER_CHAR
block|{
name|UART_DM_5_BPS
block|,
name|UART_DM_6_BPS
block|,
name|UART_DM_7_BPS
block|,
name|UART_DM_8_BPS
block|}
enum|;
end_enum

begin_comment
comment|/* 8-N-1 Configuration */
end_comment

begin_define
define|#
directive|define
name|UART_DM_8_N_1_MODE
value|(UART_DM_NO_PARITY | \ 						(UART_DM_SBL_1<< 2) | \ 						(UART_DM_8_BPS<< 4))
end_define

begin_comment
comment|/* UART_DM Registers */
end_comment

begin_comment
comment|/* UART Operational Mode Registers (HSUART) */
end_comment

begin_define
define|#
directive|define
name|UART_DM_MR1
value|0x00
end_define

begin_define
define|#
directive|define
name|UART_DM_MR1_AUTO_RFR_LEVEL1_BMSK
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|UART_DM_MR1_AUTO_RFR_LEVEL0_BMSK
value|0x3f
end_define

begin_define
define|#
directive|define
name|UART_DM_MR1_CTS_CTL_BMSK
value|0x40
end_define

begin_define
define|#
directive|define
name|UART_DM_MR1_RX_RDY_CTL_BMSK
value|0x80
end_define

begin_define
define|#
directive|define
name|UART_DM_MR2
value|0x04
end_define

begin_define
define|#
directive|define
name|UART_DM_MR2_ERROR_MODE_BMSK
value|0x40
end_define

begin_define
define|#
directive|define
name|UART_DM_MR2_BITS_PER_CHAR_BMSK
value|0x30
end_define

begin_define
define|#
directive|define
name|UART_DM_MR2_STOP_BIT_LEN_BMSK
value|0x0c
end_define

begin_define
define|#
directive|define
name|UART_DM_MR2_PARITY_MODE_BMSK
value|0x03
end_define

begin_define
define|#
directive|define
name|UART_DM_RXBRK_ZERO_CHAR_OFF
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|UART_DM_LOOPBACK
value|(1<< 7)
end_define

begin_comment
comment|/* UART Clock Selection Register, write only */
end_comment

begin_define
define|#
directive|define
name|UART_DM_CSR
value|0x08
end_define

begin_define
define|#
directive|define
name|UART_DM_CSR_115200
value|0xff
end_define

begin_define
define|#
directive|define
name|UART_DM_CSR_57600
value|0xee
end_define

begin_define
define|#
directive|define
name|UART_DM_CSR_38400
value|0xdd
end_define

begin_define
define|#
directive|define
name|UART_DM_CSR_28800
value|0xcc
end_define

begin_define
define|#
directive|define
name|UART_DM_CSR_19200
value|0xbb
end_define

begin_define
define|#
directive|define
name|UART_DM_CSR_14400
value|0xaa
end_define

begin_define
define|#
directive|define
name|UART_DM_CSR_9600
value|0x99
end_define

begin_define
define|#
directive|define
name|UART_DM_CSR_7200
value|0x88
end_define

begin_define
define|#
directive|define
name|UART_DM_CSR_4800
value|0x77
end_define

begin_define
define|#
directive|define
name|UART_DM_CSR_3600
value|0x66
end_define

begin_define
define|#
directive|define
name|UART_DM_CSR_2400
value|0x55
end_define

begin_define
define|#
directive|define
name|UART_DM_CSR_1200
value|0x44
end_define

begin_define
define|#
directive|define
name|UART_DM_CSR_600
value|0x33
end_define

begin_define
define|#
directive|define
name|UART_DM_CSR_300
value|0x22
end_define

begin_define
define|#
directive|define
name|UART_DM_CSR_150
value|0x11
end_define

begin_define
define|#
directive|define
name|UART_DM_CSR_75
value|0x00
end_define

begin_comment
comment|/* UART DM TX FIFO Registers - 4, write only */
end_comment

begin_define
define|#
directive|define
name|UART_DM_TF
parameter_list|(
name|x
parameter_list|)
value|(0x70 + (4 * (x)))
end_define

begin_comment
comment|/* UART Command Register, write only */
end_comment

begin_define
define|#
directive|define
name|UART_DM_CR
value|0x10
end_define

begin_define
define|#
directive|define
name|UART_DM_CR_RX_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|UART_DM_CR_RX_DISABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|UART_DM_CR_TX_ENABLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|UART_DM_CR_TX_DISABLE
value|(1<< 3)
end_define

begin_comment
comment|/* UART_DM_CR channel command bit value (register field is bits 8:4) */
end_comment

begin_define
define|#
directive|define
name|UART_DM_RESET_RX
value|0x10
end_define

begin_define
define|#
directive|define
name|UART_DM_RESET_TX
value|0x20
end_define

begin_define
define|#
directive|define
name|UART_DM_RESET_ERROR_STATUS
value|0x30
end_define

begin_define
define|#
directive|define
name|UART_DM_RESET_BREAK_INT
value|0x40
end_define

begin_define
define|#
directive|define
name|UART_DM_START_BREAK
value|0x50
end_define

begin_define
define|#
directive|define
name|UART_DM_STOP_BREAK
value|0x60
end_define

begin_define
define|#
directive|define
name|UART_DM_RESET_CTS
value|0x70
end_define

begin_define
define|#
directive|define
name|UART_DM_RESET_STALE_INT
value|0x80
end_define

begin_define
define|#
directive|define
name|UART_DM_RFR_LOW
value|0xD0
end_define

begin_define
define|#
directive|define
name|UART_DM_RFR_HIGH
value|0xE0
end_define

begin_define
define|#
directive|define
name|UART_DM_CR_PROTECTION_EN
value|0x100
end_define

begin_define
define|#
directive|define
name|UART_DM_STALE_EVENT_ENABLE
value|0x500
end_define

begin_define
define|#
directive|define
name|UART_DM_STALE_EVENT_DISABLE
value|0x600
end_define

begin_define
define|#
directive|define
name|UART_DM_FORCE_STALE_EVENT
value|0x400
end_define

begin_define
define|#
directive|define
name|UART_DM_CLEAR_TX_READY
value|0x300
end_define

begin_define
define|#
directive|define
name|UART_DM_RESET_TX_ERROR
value|0x800
end_define

begin_define
define|#
directive|define
name|UART_DM_RESET_TX_DONE
value|0x810
end_define

begin_comment
comment|/* UART Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|UART_DM_IMR
value|0x14
end_define

begin_comment
comment|/* these can be used for both ISR and IMR registers */
end_comment

begin_define
define|#
directive|define
name|UART_DM_TXLEV
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|UART_DM_RXHUNT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|UART_DM_RXBRK_CHNG
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|UART_DM_RXSTALE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|UART_DM_RXLEV
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|UART_DM_DELTA_CTS
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|UART_DM_CURRENT_CTS
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|UART_DM_TX_READY
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|UART_DM_TX_ERROR
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|UART_DM_TX_DONE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|UART_DM_RXBREAK_START
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|UART_DM_RXBREAK_END
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|UART_DM_PAR_FRAME_ERR_IRQ
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|UART_DM_IMR_ENABLED
value|(UART_DM_TX_READY | \ 						UART_DM_TXLEV | \ 						UART_DM_RXLEV | \ 						UART_DM_RXSTALE)
end_define

begin_comment
comment|/* UART Interrupt Programming Register */
end_comment

begin_define
define|#
directive|define
name|UART_DM_IPR
value|0x18
end_define

begin_define
define|#
directive|define
name|UART_DM_STALE_TIMEOUT_LSB
value|0x0f
end_define

begin_define
define|#
directive|define
name|UART_DM_STALE_TIMEOUT_MSB
value|0x00
end_define

begin_define
define|#
directive|define
name|UART_DM_IPR_STALE_TIMEOUT_MSB_BMSK
value|0xffffff80
end_define

begin_define
define|#
directive|define
name|UART_DM_IPR_STALE_LSB_BMSK
value|0x1f
end_define

begin_comment
comment|/* UART Transmit/Receive FIFO Watermark Register */
end_comment

begin_define
define|#
directive|define
name|UART_DM_TFWR
value|0x1c
end_define

begin_comment
comment|/* Interrupt is generated when FIFO level is less than or equal to this value */
end_comment

begin_define
define|#
directive|define
name|UART_DM_TFW_VALUE
value|0
end_define

begin_define
define|#
directive|define
name|UART_DM_RFWR
value|0x20
end_define

begin_comment
comment|/* Interrupt generated when no of words in RX FIFO is greater than this value */
end_comment

begin_define
define|#
directive|define
name|UART_DM_RFW_VALUE
value|0
end_define

begin_comment
comment|/* UART Hunt Character Register */
end_comment

begin_define
define|#
directive|define
name|UART_DM_HCR
value|0x24
end_define

begin_comment
comment|/* Used for RX transfer initialization */
end_comment

begin_define
define|#
directive|define
name|UART_DM_DMRX
value|0x34
end_define

begin_comment
comment|/* Default DMRX value - any value bigger than FIFO size would be fine */
end_comment

begin_define
define|#
directive|define
name|UART_DM_DMRX_DEF_VALUE
value|0x220
end_define

begin_comment
comment|/* Register to enable IRDA function */
end_comment

begin_define
define|#
directive|define
name|UART_DM_IRDA
value|0x38
end_define

begin_comment
comment|/* UART Data Mover Enable Register */
end_comment

begin_define
define|#
directive|define
name|UART_DM_DMEN
value|0x3c
end_define

begin_comment
comment|/* Number of characters for Transmission */
end_comment

begin_define
define|#
directive|define
name|UART_DM_NO_CHARS_FOR_TX
value|0x40
end_define

begin_comment
comment|/* UART RX FIFO Base Address */
end_comment

begin_define
define|#
directive|define
name|UART_DM_BADR
value|0x44
end_define

begin_define
define|#
directive|define
name|UART_DM_SIM_CFG_ADDR
value|0x80
end_define

begin_comment
comment|/* Read only registers */
end_comment

begin_comment
comment|/* UART Status Register */
end_comment

begin_define
define|#
directive|define
name|UART_DM_SR
value|0x08
end_define

begin_comment
comment|/* register field mask mapping */
end_comment

begin_define
define|#
directive|define
name|UART_DM_SR_RXRDY
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|UART_DM_SR_RXFULL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|UART_DM_SR_TXRDY
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|UART_DM_SR_TXEMT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|UART_DM_SR_UART_OVERRUN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|UART_DM_SR_PAR_FRAME_ERR
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|UART_DM_RX_BREAK
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|UART_DM_HUNT_CHAR
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|UART_DM_RX_BRK_START_LAST
value|(1<< 8)
end_define

begin_comment
comment|/* UART Receive FIFO Registers - 4 in numbers */
end_comment

begin_define
define|#
directive|define
name|UART_DM_RF
parameter_list|(
name|x
parameter_list|)
value|(0x70 + (4 * (x)))
end_define

begin_comment
comment|/* UART Masked Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|UART_DM_MISR
value|0x10
end_define

begin_comment
comment|/* UART Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|UART_DM_ISR
value|0x14
end_define

begin_comment
comment|/* Number of characters received since the end of last RX transfer */
end_comment

begin_define
define|#
directive|define
name|UART_DM_RX_TOTAL_SNAP
value|0x38
end_define

begin_comment
comment|/* UART TX FIFO Status Register */
end_comment

begin_define
define|#
directive|define
name|UART_DM_TXFS
value|0x4c
end_define

begin_define
define|#
directive|define
name|UART_DM_TXFS_STATE_LSB
parameter_list|(
name|x
parameter_list|)
value|UART_DM_EXTR_BITS(x,0,6)
end_define

begin_define
define|#
directive|define
name|UART_DM_TXFS_STATE_MSB
parameter_list|(
name|x
parameter_list|)
value|UART_DM_EXTR_BITS(x,14,31)
end_define

begin_define
define|#
directive|define
name|UART_DM_TXFS_BUF_STATE
parameter_list|(
name|x
parameter_list|)
value|UART_DM_EXTR_BITS(x,7,9)
end_define

begin_define
define|#
directive|define
name|UART_DM_TXFS_ASYNC_STATE
parameter_list|(
name|x
parameter_list|)
value|UART_DM_EXTR_BITS(x,10,13)
end_define

begin_comment
comment|/* UART RX FIFO Status Register */
end_comment

begin_define
define|#
directive|define
name|UART_DM_RXFS
value|0x50
end_define

begin_define
define|#
directive|define
name|UART_DM_RXFS_STATE_LSB
parameter_list|(
name|x
parameter_list|)
value|UART_DM_EXTR_BITS(x,0,6)
end_define

begin_define
define|#
directive|define
name|UART_DM_RXFS_STATE_MSB
parameter_list|(
name|x
parameter_list|)
value|UART_DM_EXTR_BITS(x,14,31)
end_define

begin_define
define|#
directive|define
name|UART_DM_RXFS_BUF_STATE
parameter_list|(
name|x
parameter_list|)
value|UART_DM_EXTR_BITS(x,7,9)
end_define

begin_define
define|#
directive|define
name|UART_DM_RXFS_ASYNC_STATE
parameter_list|(
name|x
parameter_list|)
value|UART_DM_EXTR_BITS(x,10,13)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UART_DM_H_ */
end_comment

end_unit

