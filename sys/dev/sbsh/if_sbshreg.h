begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Granch SBNI16 G.SHDSL Modem driver definitions  * Written by Denis I. Timofeev, 2002-2003.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* SBNI16 controller chip definitions */
end_comment

begin_comment
comment|/* CR bits */
end_comment

begin_define
define|#
directive|define
name|TXEN
value|0x01
end_define

begin_comment
comment|/* transmitter enable */
end_comment

begin_define
define|#
directive|define
name|RXEN
value|0x02
end_define

begin_comment
comment|/* receiver  enable */
end_comment

begin_define
define|#
directive|define
name|NCRC
value|0x04
end_define

begin_comment
comment|/* ignore received CRC */
end_comment

begin_define
define|#
directive|define
name|DLBK
value|0x08
end_define

begin_comment
comment|/* digital loopback */
end_comment

begin_define
define|#
directive|define
name|CMOD
value|0x10
end_define

begin_comment
comment|/* 0 - use CRC-32, 1 - CRC-16 */
end_comment

begin_define
define|#
directive|define
name|FMOD
value|0x20
end_define

begin_comment
comment|/* interframe fill: 0 - all ones, 1 - 0xfe */
end_comment

begin_define
define|#
directive|define
name|PMOD
value|0x40
end_define

begin_comment
comment|/* data polarity: 0 - normal, 1 - invert */
end_comment

begin_define
define|#
directive|define
name|XRST
value|0x80
end_define

begin_comment
comment|/* reset the transceiver */
end_comment

begin_comment
comment|/* CRB bits */
end_comment

begin_define
define|#
directive|define
name|RDBE
value|0x01
end_define

begin_comment
comment|/* read burst enable */
end_comment

begin_define
define|#
directive|define
name|WTBE
value|0x02
end_define

begin_comment
comment|/* write burst enable */
end_comment

begin_define
define|#
directive|define
name|RODD
value|0x04
end_define

begin_comment
comment|/* receive 2-byte alignment */
end_comment

begin_define
define|#
directive|define
name|RXDE
value|0x08
end_define

begin_comment
comment|/* receive data enable */
end_comment

begin_comment
comment|/* SR and IMR bits */
end_comment

begin_define
define|#
directive|define
name|TXS
value|0x01
end_define

begin_comment
comment|/* transmit success */
end_comment

begin_define
define|#
directive|define
name|RXS
value|0x02
end_define

begin_comment
comment|/* receive success */
end_comment

begin_comment
comment|/* SR only */
end_comment

begin_define
define|#
directive|define
name|CRC
value|0x04
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|OFL
value|0x08
end_define

begin_comment
comment|/* fifo overflow error */
end_comment

begin_define
define|#
directive|define
name|UFL
value|0x10
end_define

begin_comment
comment|/* fifo underflow error */
end_comment

begin_define
define|#
directive|define
name|EXT
value|0x20
end_define

begin_comment
comment|/* interrupt from sk70725 */
end_comment

begin_comment
comment|/* IMR only */
end_comment

begin_define
define|#
directive|define
name|TSI
value|0x80
end_define

begin_comment
comment|/* generate test interrupt */
end_comment

begin_define
define|#
directive|define
name|LAST_FRAG
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SBNI16_MAX_FRAME
value|(1536 + 16)
end_define

begin_comment
comment|/* We don't have official vendor id yet... */
end_comment

begin_define
define|#
directive|define
name|SBNI16_VENDOR
value|0x55
end_define

begin_define
define|#
directive|define
name|SBNI16_DEVICE
value|0x9d
end_define

begin_define
define|#
directive|define
name|SBNI16_SUBDEV
value|3
end_define

begin_comment
comment|/* transceiver chip set definitions */
end_comment

begin_enum
enum|enum
name|CX28975_API_commands
block|{
name|_DSL_RESET_SYSTEM
init|=
literal|0x00
block|,
name|_DSL_SYSTEM_ENABLE
init|=
literal|0x01
block|,
name|_DSL_AFE_CONFIG
init|=
literal|0x02
block|,
name|_DSL_TRAINING_MODE
init|=
literal|0x03
block|,
name|_DSL_CLOCK_CONFIG
init|=
literal|0x04
block|,
name|_DSL_PCM_MF_LEN
init|=
literal|0x05
block|,
name|_DSL_SYSTEM_CONFIG
init|=
literal|0x06
block|,
name|_DSL_LOOPBACK
init|=
literal|0x09
block|,
name|_DSL_ACTIVATION
init|=
literal|0x0b
block|,
name|_DSL_FORCE_DEACTIVATE
init|=
literal|0x0c
block|,
name|_DSL_TEST_MODE
init|=
literal|0x0d
block|,
name|_DSL_DATA_RATE
init|=
literal|0x0e
block|,
name|_DSL_PREACTIVATION_CFG
init|=
literal|0x0f
block|,
name|_DSL_FR_PCM_CONFIG
init|=
literal|0x10
block|,
name|_DSL_FR_HDSL_CONFIG
init|=
literal|0x11
block|,
name|_DSL_PCM_CLK_CONF
init|=
literal|0x12
block|,
name|_AFE_TX_GAIN
init|=
literal|0x13
block|,
name|_DSL_PREACT_USER_INFO
init|=
literal|0x14
block|,
name|_DSL_PREACT_RATE_LIST
init|=
literal|0x15
block|,
name|_DSL_TX_ISO_PULSE
init|=
literal|0x16
block|,
name|_BP_ERLE_TEST_MODE
init|=
literal|0x18
block|,
name|_DSL_MULTI_PAIR_CONFIG
init|=
literal|0x19
block|,
name|_DSL_NB_MULTI_RATE_CONFIG
init|=
literal|0x1a
block|,
name|_DSL_MULTI_RATE_CONFIG
init|=
literal|0x1b
block|,
name|_ATM_PHY_MODE
init|=
literal|0x1c
block|,
name|_ATM_PHY_UTOPIA_CONFIG
init|=
literal|0x1d
block|,
name|_ATM_PHY_IF_MODE
init|=
literal|0x1e
block|,
name|_ATM_PHY_INJECT_HEC_ERROR
init|=
literal|0x1f
block|,
name|_ATM_PHY_CONFIG
init|=
literal|0x20
block|,
name|_DSL_TNB_BER_STATE
init|=
literal|0x21
block|,
name|_DSL_RNB_BER_STATE
init|=
literal|0x22
block|,
name|_DSL_TP_BER_STATE
init|=
literal|0x23
block|,
name|_DSL_RP_BER_STATE
init|=
literal|0x24
block|,
name|_DSL_PRBS_CONFIGURE
init|=
literal|0x25
block|,
name|_DSL_CONST_FILL
init|=
literal|0x26
block|,
name|_DSL_DBANK
init|=
literal|0x27
block|,
name|_DSL_NB_CONFIG
init|=
literal|0x28
block|,
name|_DSL_TNB_FRM_OFST
init|=
literal|0x29
block|,
name|_DSL_RNB_FRM_OFST
init|=
literal|0x2a
block|,
name|_DSL_TP_FRM_OFST
init|=
literal|0x2e
block|,
name|_DSL_RP_FRM_OFST
init|=
literal|0x2f
block|,
name|_DSL_TP_MAPPER_VALUE
init|=
literal|0x30
block|,
name|_DSL_TP_MAPPER_WRITE
init|=
literal|0x31
block|,
name|_DSL_RP_MAPPER_VALUE
init|=
literal|0x32
block|,
name|_DSL_RP_MAPPER_WRITE
init|=
literal|0x33
block|,
name|_DSL_TH_MAPPER_VALUE
init|=
literal|0x34
block|,
name|_DSL_TH_MAPPER_WRITE
init|=
literal|0x35
block|,
name|_DSL_RH_MAPPER_VALUE
init|=
literal|0x36
block|,
name|_DSL_RH_MAPPER_WRITE
init|=
literal|0x37
block|,
name|_DSL_TNB_MAPPER_VALUE
init|=
literal|0x38
block|,
name|_DSL_TNB_MAPPER_WRITE
init|=
literal|0x39
block|,
name|_DSL_RNB_MAPPER_VALUE
init|=
literal|0x3a
block|,
name|_DSL_RNB_MAPPER_WRITE
init|=
literal|0x3b
block|,
name|_DSL_CLEAR_ERROR_CTRS
init|=
literal|0x40
block|,
name|_DSL_INJECT_CRC_ERROR
init|=
literal|0x41
block|,
name|_DSL_THRESHOLDS
init|=
literal|0x43
block|,
name|_DSL_FR_SET_STATE_MACHINE
init|=
literal|0x4a
block|,
name|_DSL_FR_TNB_RESET
init|=
literal|0x4b
block|,
name|_DSL_FR_RNB_RESET
init|=
literal|0x4c
block|,
name|_EOC_RESET
init|=
literal|0x4d
block|,
name|_DSL_FR_TX_RESET
init|=
literal|0x4e
block|,
name|_DSL_FR_RX_RESET
init|=
literal|0x4f
block|,
name|_DSL_INTR_HOST_MASK
init|=
literal|0x50
block|,
name|_DSL_INTR_API_SUBMASK
init|=
literal|0x51
block|,
name|_DSL_DOWNLOAD_START
init|=
literal|0x53
block|,
name|_DSL_DOWNLOAD_DATA
init|=
literal|0x54
block|,
name|_DSL_DOWNLOAD_END
init|=
literal|0x55
block|,
name|_DSL_DPLL_CLOCK_GEN
init|=
literal|0x58
block|,
name|_DSL_NB_DPLL_CLOCK_GEN
init|=
literal|0x59
block|,
name|_DSL_WRITE_REG
init|=
literal|0x75
block|,
name|_DSL_WRITE_AFE
init|=
literal|0x76
block|}
enum|;
end_enum

begin_enum
enum|enum
name|CX28975_status_commands
block|{
name|_DSL_READ_CONTROL
init|=
literal|0x80
block|,
name|_DSL_FAR_END_ATTEN
init|=
literal|0x82
block|,
name|_DSL_NOISE_MARGIN
init|=
literal|0x83
block|,
name|_DSL_STATUS
init|=
literal|0x85
block|,
name|_DSL_PREACT_GET_FE_CAPS
init|=
literal|0x88
block|,
name|_DSL_PREACT_GET_OPT_DATA_RATE
init|=
literal|0x89
block|,
name|_DSL_VERSIONS
init|=
literal|0x8a
block|,
name|_DSL_TP_BER_RESULTS
init|=
literal|0x8c
block|,
name|_DSL_RP_BER_RESULTS
init|=
literal|0x8d
block|,
name|_DSL_STAGE_NUMBER
init|=
literal|0x8f
block|,
name|_DSL_AFE_SETTING
init|=
literal|0x90
block|,
name|_DSL_TNB_BER_RESULTS
init|=
literal|0x91
block|,
name|_DSL_RNB_BER_RESULTS
init|=
literal|0x92
block|,
name|_BP_ERLE_RESULTS
init|=
literal|0x93
block|,
name|_DSL_POWER_BACK_OFF_RESULT
init|=
literal|0x94
block|,
name|_DSL_OPER_ERR_CTRS
init|=
literal|0x9c
block|,
name|_DSL_TIME
init|=
literal|0x9d
block|,
name|_DSL_HDSL_PERF_ERR_CTRS
init|=
literal|0x9e
block|,
name|_DSL_READ_REG
init|=
literal|0xa0
block|,
name|_DSL_READ_AFE
init|=
literal|0xa1
block|,
name|_DSL_SYSTEM_PERF_ERR_CTRS
init|=
literal|0xa2
block|,
name|_DSL_TP_MAPPER_READ
init|=
literal|0xa3
block|,
name|_DSL_RP_MAPPER_READ
init|=
literal|0xa4
block|,
name|_DSL_TH_MAPPER_READ
init|=
literal|0xa5
block|,
name|_DSL_RH_MAPPER_READ
init|=
literal|0xa6
block|,
name|_DSL_TNB_MAPPER_READ
init|=
literal|0xa7
block|,
name|_DSL_RNB_MAPPER_READ
init|=
literal|0xa8
block|,
name|_EOC_RX_GET_STATS
init|=
literal|0xae
block|,
name|_EOC_TX_SEND_COMMAND
init|=
literal|0xb0
block|,
name|_EOC_RX_GET_MSG
init|=
literal|0xb1
block|,
name|_EOC_TX_GET_MSG_STATUS
init|=
literal|0xb2
block|,
name|_EOC_TX_DELETE_MSG
init|=
literal|0xb3
block|,
name|_ATM_PHY_OPER_ERR_CTRS
init|=
literal|0xb8
block|,
name|_ATM_PHY_PERF_ERR_CTRS
init|=
literal|0xb9
block|,
name|_ATM_PHY_CELL_CTRS
init|=
literal|0xba
block|}
enum|;
end_enum

begin_enum
enum|enum
name|CX28975_acknoledge_status_codes
block|{
name|_ACK_NOT_COMPLETE
init|=
literal|0x00
block|,
name|_ACK_PASS
init|=
literal|0x01
block|,
name|_ACK_BUSY
init|=
literal|0x02
block|,
name|_ACK_NOT_APPLICABLE
init|=
literal|0x03
block|,
name|_ACK_INVALID_DEST
init|=
literal|0x04
block|,
name|_ACK_INVALID_OPCODE
init|=
literal|0x05
block|,
name|_ACK_INVALID_LENGTH
init|=
literal|0x06
block|,
name|_ACK_INVALID_DATA
init|=
literal|0x07
block|,
name|_ACK_INVALID_CHKSUM
init|=
literal|0x08
block|,
name|_ACK_NO_RESULT
init|=
literal|0x09
block|,
name|_ACK_NOT_AVAILABLE
init|=
literal|0x0a
block|,
name|_ACK_BOOT_WAKE_UP
init|=
literal|0x0d
block|,
name|_ACK_OPER_WAKE_UP
init|=
literal|0x0e
block|}
enum|;
end_enum

end_unit

