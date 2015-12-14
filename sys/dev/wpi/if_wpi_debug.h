begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006,2007  *	Damien Bergamini<damien.bergamini@free.fr>  *	Benjamin Close<Benjamin.Close@clearchain.com>  * Copyright (c) 2015 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_WPI_DEBUG_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_WPI_DEBUG_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WPI_DEBUG
end_ifdef

begin_enum
enum|enum
block|{
name|WPI_DEBUG_XMIT
init|=
literal|0x00000001
block|,
comment|/* basic xmit operation */
name|WPI_DEBUG_RECV
init|=
literal|0x00000002
block|,
comment|/* basic recv operation */
name|WPI_DEBUG_STATE
init|=
literal|0x00000004
block|,
comment|/* 802.11 state transitions */
name|WPI_DEBUG_HW
init|=
literal|0x00000008
block|,
comment|/* Stage 1 (eeprom) debugging */
name|WPI_DEBUG_RESET
init|=
literal|0x00000010
block|,
comment|/* reset processing */
name|WPI_DEBUG_FIRMWARE
init|=
literal|0x00000020
block|,
comment|/* firmware(9) loading debug */
name|WPI_DEBUG_BEACON
init|=
literal|0x00000040
block|,
comment|/* beacon handling */
name|WPI_DEBUG_WATCHDOG
init|=
literal|0x00000080
block|,
comment|/* watchdog timeout */
name|WPI_DEBUG_INTR
init|=
literal|0x00000100
block|,
comment|/* ISR */
name|WPI_DEBUG_SCAN
init|=
literal|0x00000200
block|,
comment|/* Scan related operations */
name|WPI_DEBUG_NOTIFY
init|=
literal|0x00000400
block|,
comment|/* State 2 Notif intr debug */
name|WPI_DEBUG_TEMP
init|=
literal|0x00000800
block|,
comment|/* TXPower/Temp Calibration */
name|WPI_DEBUG_CMD
init|=
literal|0x00001000
block|,
comment|/* cmd submission */
name|WPI_DEBUG_TRACE
init|=
literal|0x00002000
block|,
comment|/* Print begin and start driver function */
name|WPI_DEBUG_PWRSAVE
init|=
literal|0x00004000
block|,
comment|/* Power save operations */
name|WPI_DEBUG_EEPROM
init|=
literal|0x00008000
block|,
comment|/* EEPROM info */
name|WPI_DEBUG_NODE
init|=
literal|0x00010000
block|,
comment|/* node addition/removal */
name|WPI_DEBUG_KEY
init|=
literal|0x00020000
block|,
comment|/* node key management */
name|WPI_DEBUG_EDCA
init|=
literal|0x00040000
block|,
comment|/* WME info */
name|WPI_DEBUG_REGISTER
init|=
literal|0x00080000
block|,
comment|/* print chipset register */
name|WPI_DEBUG_BMISS
init|=
literal|0x00100000
block|,
comment|/* print number of missed beacons */
name|WPI_DEBUG_ANY
init|=
literal|0xffffffff
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|sc
parameter_list|,
name|m
parameter_list|,
modifier|...
parameter_list|)
value|do {		\ 	if (sc->sc_debug& (m))			\ 		printf(__VA_ARGS__);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|TRACE_STR_BEGIN
value|"->%s: begin\n"
end_define

begin_define
define|#
directive|define
name|TRACE_STR_DOING
value|"->Doing %s\n"
end_define

begin_define
define|#
directive|define
name|TRACE_STR_END
value|"->%s: end\n"
end_define

begin_define
define|#
directive|define
name|TRACE_STR_END_ERR
value|"->%s: end in error\n"
end_define

begin_define
define|#
directive|define
name|WPI_DESC
parameter_list|(
name|x
parameter_list|)
value|case x:	return #x
end_define

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|wpi_cmd_str
parameter_list|(
name|int
name|cmd
parameter_list|)
block|{
switch|switch
condition|(
name|cmd
condition|)
block|{
comment|/* Notifications. */
name|WPI_DESC
argument_list|(
name|WPI_UC_READY
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_RX_DONE
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_START_SCAN
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_SCAN_RESULTS
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_STOP_SCAN
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_BEACON_SENT
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_RX_STATISTICS
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_BEACON_STATISTICS
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_STATE_CHANGED
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_BEACON_MISSED
argument_list|)
expr_stmt|;
comment|/* Command notifications. */
name|WPI_DESC
argument_list|(
name|WPI_CMD_RXON
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_CMD_RXON_ASSOC
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_CMD_EDCA_PARAMS
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_CMD_TIMING
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_CMD_ADD_NODE
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_CMD_DEL_NODE
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_CMD_TX_DATA
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_CMD_MRR_SETUP
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_CMD_SET_LED
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_CMD_SET_POWER_MODE
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_CMD_SCAN
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_CMD_SCAN_ABORT
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_CMD_SET_BEACON
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_CMD_TXPOWER
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_CMD_BT_COEX
argument_list|)
expr_stmt|;
default|default:
return|return
literal|"UNKNOWN CMD"
return|;
block|}
block|}
end_function

begin_comment
comment|/*  * Translate CSR code to string  */
end_comment

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|wpi_get_csr_string
parameter_list|(
name|size_t
name|csr
parameter_list|)
block|{
switch|switch
condition|(
name|csr
condition|)
block|{
name|WPI_DESC
argument_list|(
name|WPI_HW_IF_CONFIG
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_INT
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_INT_MASK
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_FH_INT
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_GPIO_IN
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_RESET
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_GP_CNTRL
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_EEPROM
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_EEPROM_GP
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_GIO
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_UCODE_GP1
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_UCODE_GP2
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_GIO_CHICKEN
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_ANA_PLL
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_DBG_HPET_MEM
argument_list|)
expr_stmt|;
default|default:
name|KASSERT
argument_list|(
literal|0
argument_list|,
operator|(
literal|"Unknown CSR: %d\n"
operator|,
name|csr
operator|)
argument_list|)
expr_stmt|;
return|return
literal|"UNKNOWN CSR"
return|;
block|}
block|}
end_function

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|wpi_get_prph_string
parameter_list|(
name|size_t
name|prph
parameter_list|)
block|{
switch|switch
condition|(
name|prph
condition|)
block|{
name|WPI_DESC
argument_list|(
name|WPI_APMG_CLK_CTRL
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_APMG_PS
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_APMG_PCI_STT
argument_list|)
expr_stmt|;
name|WPI_DESC
argument_list|(
name|WPI_APMG_RFKILL
argument_list|)
expr_stmt|;
default|default:
name|KASSERT
argument_list|(
literal|0
argument_list|,
operator|(
literal|"Unknown register: %d\n"
operator|,
name|prph
operator|)
argument_list|)
expr_stmt|;
return|return
literal|"UNKNOWN PRPH"
return|;
block|}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|sc
parameter_list|,
name|m
parameter_list|,
modifier|...
parameter_list|)
value|do { (void) sc; } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_WPI_DEBUG_H__ */
end_comment

end_unit

