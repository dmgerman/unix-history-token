begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006,2007  *	Damien Bergamini<damien.bergamini@free.fr>  *	Benjamin Close<Benjamin.Close@clearchain.com>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
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
name|WPI_DEBUG_KEY
init|=
literal|0x00010000
block|,
comment|/* node key management */
name|WPI_DEBUG_EDCA
init|=
literal|0x00020000
block|,
comment|/* WME info */
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
comment|/* Notifications */
case|case
name|WPI_UC_READY
case|:
return|return
literal|"UC_READY"
return|;
case|case
name|WPI_RX_DONE
case|:
return|return
literal|"RX_DONE"
return|;
case|case
name|WPI_START_SCAN
case|:
return|return
literal|"START_SCAN"
return|;
case|case
name|WPI_SCAN_RESULTS
case|:
return|return
literal|"SCAN_RESULTS"
return|;
case|case
name|WPI_STOP_SCAN
case|:
return|return
literal|"STOP_SCAN"
return|;
case|case
name|WPI_BEACON_SENT
case|:
return|return
literal|"BEACON_SENT"
return|;
case|case
name|WPI_RX_STATISTICS
case|:
return|return
literal|"RX_STATS"
return|;
case|case
name|WPI_BEACON_STATISTICS
case|:
return|return
literal|"BEACON_STATS"
return|;
case|case
name|WPI_STATE_CHANGED
case|:
return|return
literal|"STATE_CHANGED"
return|;
case|case
name|WPI_BEACON_MISSED
case|:
return|return
literal|"BEACON_MISSED"
return|;
comment|/* Command notifications */
case|case
name|WPI_CMD_RXON
case|:
return|return
literal|"WPI_CMD_RXON"
return|;
case|case
name|WPI_CMD_RXON_ASSOC
case|:
return|return
literal|"WPI_CMD_RXON_ASSOC"
return|;
case|case
name|WPI_CMD_EDCA_PARAMS
case|:
return|return
literal|"WPI_CMD_EDCA_PARAMS"
return|;
case|case
name|WPI_CMD_TIMING
case|:
return|return
literal|"WPI_CMD_TIMING"
return|;
case|case
name|WPI_CMD_ADD_NODE
case|:
return|return
literal|"WPI_CMD_ADD_NODE"
return|;
case|case
name|WPI_CMD_DEL_NODE
case|:
return|return
literal|"WPI_CMD_DEL_NODE"
return|;
case|case
name|WPI_CMD_TX_DATA
case|:
return|return
literal|"WPI_CMD_TX_DATA"
return|;
case|case
name|WPI_CMD_MRR_SETUP
case|:
return|return
literal|"WPI_CMD_MRR_SETUP"
return|;
case|case
name|WPI_CMD_SET_LED
case|:
return|return
literal|"WPI_CMD_SET_LED"
return|;
case|case
name|WPI_CMD_SET_POWER_MODE
case|:
return|return
literal|"WPI_CMD_SET_POWER_MODE"
return|;
case|case
name|WPI_CMD_SCAN
case|:
return|return
literal|"WPI_CMD_SCAN"
return|;
case|case
name|WPI_CMD_SET_BEACON
case|:
return|return
literal|"WPI_CMD_SET_BEACON"
return|;
case|case
name|WPI_CMD_TXPOWER
case|:
return|return
literal|"WPI_CMD_TXPOWER"
return|;
case|case
name|WPI_CMD_BT_COEX
case|:
return|return
literal|"WPI_CMD_BT_COEX"
return|;
default|default:
name|KASSERT
argument_list|(
literal|1
argument_list|,
operator|(
literal|"Unknown Command: %d\n"
operator|,
name|cmd
operator|)
argument_list|)
expr_stmt|;
return|return
literal|"UNKNOWN CMD"
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

