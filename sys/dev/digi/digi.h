begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Brian Somers<brian@Awfulhak.org>  *   based on work by Slawa Olhovchenkov  *                    John Prince<johnp@knight-trosoft.com>  *                    Eric Hernes  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|W
parameter_list|(
name|p
parameter_list|)
value|(*(u_int16_t *)(p))
end_define

begin_define
define|#
directive|define
name|vW
parameter_list|(
name|p
parameter_list|)
value|(*(u_int16_t volatile *)(p))
end_define

begin_define
define|#
directive|define
name|D
parameter_list|(
name|p
parameter_list|)
value|(*(u_int32_t *)(p))
end_define

begin_define
define|#
directive|define
name|vD
parameter_list|(
name|p
parameter_list|)
value|(*(u_int32_t volatile *)(p))
end_define

begin_define
define|#
directive|define
name|CE_OVERRUN
value|0
end_define

begin_define
define|#
directive|define
name|CE_INTERRUPT_BUF_OVERFLOW
value|1
end_define

begin_define
define|#
directive|define
name|CE_TTY_BUF_OVERFLOW
value|2
end_define

begin_define
define|#
directive|define
name|CE_NTYPES
value|3
end_define

begin_define
define|#
directive|define
name|CE_RECORD
parameter_list|(
name|com
parameter_list|,
name|errnum
parameter_list|)
value|(++(com)->delta_error_counts[errnum])
end_define

begin_comment
comment|/*#define DIGI_INTERRUPT*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG
end_ifndef

begin_define
define|#
directive|define
name|DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|unsigned
name|digi_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DLOG
parameter_list|(
name|level
parameter_list|,
name|args
parameter_list|)
value|if (digi_debug& (level)) device_printf args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DLOG
parameter_list|(
name|level
parameter_list|,
name|args
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|digi_softc
struct_decl|;
end_struct_decl

begin_comment
comment|/* digiboard port structure */
end_comment

begin_struct
struct|struct
name|digi_p
block|{
name|struct
name|digi_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|status
decl_stmt|;
define|#
directive|define
name|ENABLED
value|1
define|#
directive|define
name|DIGI_DTR_OFF
value|2
define|#
directive|define
name|PAUSE_TX
value|8
define|#
directive|define
name|PAUSE_RX
value|16
name|int
name|opencnt
decl_stmt|;
name|ushort
name|txbufsize
decl_stmt|;
name|ushort
name|rxbufsize
decl_stmt|;
specifier|volatile
name|struct
name|board_chan
modifier|*
name|bc
decl_stmt|;
name|struct
name|tty
modifier|*
name|tp
decl_stmt|;
name|dev_t
name|dev
index|[
literal|6
index|]
decl_stmt|;
name|u_char
modifier|*
name|txbuf
decl_stmt|;
name|u_char
modifier|*
name|rxbuf
decl_stmt|;
name|u_char
name|txwin
decl_stmt|;
name|u_char
name|rxwin
decl_stmt|;
name|u_char
name|pnum
decl_stmt|;
comment|/* port number */
name|u_char
name|modemfake
decl_stmt|;
comment|/* Modem values to be forced */
name|u_char
name|mstat
decl_stmt|;
name|u_char
name|modem
decl_stmt|;
comment|/* Force values */
name|int
name|active_out
decl_stmt|;
comment|/* nonzero if the callout device is open */
name|int
name|dtr_wait
decl_stmt|;
comment|/* time to hold DTR down on close (* 1/hz) */
name|u_int
name|wopeners
decl_stmt|;
comment|/* # processes waiting for DCD in open() */
comment|/* 	 * The high level of the driver never reads status registers directly 	 * because there would be too many side effects to handle conveniently. 	 * Instead, it reads copies of the registers stored here by the 	 * interrupt handler. 	 */
name|u_char
name|last_modem_status
decl_stmt|;
comment|/* last MSR read by intr handler */
name|u_char
name|prev_modem_status
decl_stmt|;
comment|/* last MSR handled by high level */
comment|/* Initial state. */
name|struct
name|termios
name|it_in
decl_stmt|;
comment|/* should be in struct tty */
name|struct
name|termios
name|it_out
decl_stmt|;
comment|/* Lock state. */
name|struct
name|termios
name|lt_in
decl_stmt|;
comment|/* should be in struct tty */
name|struct
name|termios
name|lt_out
decl_stmt|;
name|u_int
name|do_timestamp
decl_stmt|;
name|u_int
name|do_dcd_timestamp
decl_stmt|;
name|struct
name|timeval
name|dcd_timestamp
decl_stmt|;
name|u_long
name|bytes_in
decl_stmt|,
name|bytes_out
decl_stmt|;
name|u_int
name|delta_error_counts
index|[
name|CE_NTYPES
index|]
decl_stmt|;
name|u_long
name|error_counts
decl_stmt|;
name|tcflag_t
name|c_iflag
decl_stmt|;
comment|/* hold true IXON/IXOFF/IXANY */
name|int
name|lcc
decl_stmt|,
name|lostcc
decl_stmt|,
name|lbuf
decl_stmt|;
name|u_char
name|send_ring
decl_stmt|;
name|unsigned
name|laltpin
range|:
literal|1
decl_stmt|;
comment|/* Alternate pin settings locked */
name|unsigned
name|ialtpin
range|:
literal|1
decl_stmt|;
comment|/* Initial alternate pin settings */
name|int
name|cd
decl_stmt|;
comment|/* Depends on the altpin setting */
name|int
name|dsr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Map TIOCM_* values to digiboard values  */
end_comment

begin_struct
struct|struct
name|digi_control_signals
block|{
name|int
name|rts
decl_stmt|;
name|int
name|cd
decl_stmt|;
name|int
name|dsr
decl_stmt|;
name|int
name|cts
decl_stmt|;
name|int
name|ri
decl_stmt|;
name|int
name|dtr
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|digi_board_status
block|{
name|DIGI_STATUS_NOTINIT
block|,
name|DIGI_STATUS_ENABLED
block|,
name|DIGI_STATUS_DISABLED
block|}
enum|;
end_enum

begin_comment
comment|/* Digiboard per-board structure */
end_comment

begin_struct
struct|struct
name|digi_softc
block|{
comment|/* struct board_info */
name|device_t
name|dev
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|enum
name|digi_board_status
name|status
decl_stmt|;
name|ushort
name|numports
decl_stmt|;
comment|/* number of ports on card */
name|ushort
name|port
decl_stmt|;
comment|/* I/O port */
name|ushort
name|wport
decl_stmt|;
comment|/* window select I/O port */
struct|struct
block|{
name|struct
name|resource
modifier|*
name|mem
decl_stmt|;
name|int
name|mrid
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|int
name|irqrid
decl_stmt|;
name|struct
name|resource
modifier|*
name|io
decl_stmt|;
name|int
name|iorid
decl_stmt|;
name|void
modifier|*
name|irqHandler
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|dev_t
name|ctldev
decl_stmt|;
block|}
name|res
struct|;
name|u_char
modifier|*
name|vmem
decl_stmt|;
comment|/* virtual memory address */
name|u_char
modifier|*
name|memcmd
decl_stmt|;
specifier|volatile
name|u_char
modifier|*
name|memevent
decl_stmt|;
name|long
name|pmem
decl_stmt|;
comment|/* physical memory address */
struct|struct
block|{
name|u_char
modifier|*
name|data
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|}
name|bios
struct|,
name|fep
struct|,
name|link
struct|;
ifdef|#
directive|ifdef
name|DIGI_INTERRUPT
name|struct
name|timeval
name|intr_timestamp
decl_stmt|;
endif|#
directive|endif
name|struct
name|digi_p
modifier|*
name|ports
decl_stmt|;
comment|/* pointer to array of port descriptors */
name|struct
name|tty
modifier|*
name|ttys
decl_stmt|;
comment|/* pointer to array of TTY structures */
specifier|volatile
name|struct
name|global_data
modifier|*
name|gdata
decl_stmt|;
name|u_char
name|window
decl_stmt|;
comment|/* saved window */
name|int
name|win_size
decl_stmt|;
name|int
name|win_bits
decl_stmt|;
name|int
name|mem_size
decl_stmt|;
name|int
name|mem_seg
decl_stmt|;
name|enum
name|digi_model
name|model
decl_stmt|;
specifier|const
name|struct
name|digi_control_signals
modifier|*
name|csigs
decl_stmt|;
name|int
name|opencnt
decl_stmt|;
name|unsigned
name|pcibus
range|:
literal|1
decl_stmt|;
comment|/* On a PCI bus ? */
name|struct
name|callout_handle
name|callout
decl_stmt|;
comment|/* poll timeout handle */
name|struct
name|callout_handle
name|inttest
decl_stmt|;
comment|/* int test timeout handle */
specifier|const
name|char
modifier|*
name|module
decl_stmt|;
name|u_char
modifier|*
function_decl|(
modifier|*
name|setwin
function_decl|)
parameter_list|(
name|struct
name|digi_softc
modifier|*
name|_sc
parameter_list|,
name|unsigned
name|_addr
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|hidewin
function_decl|)
parameter_list|(
name|struct
name|digi_softc
modifier|*
name|_sc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|towin
function_decl|)
parameter_list|(
name|struct
name|digi_softc
modifier|*
name|_sc
parameter_list|,
name|int
name|_win
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|DEBUG
name|int
name|intr_count
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|devclass_t
name|digi_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|digi_control_signals
name|digi_xixe_signals
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|digi_control_signals
name|digi_normal_signals
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|const
name|char
modifier|*
name|digi_errortxt
parameter_list|(
name|int
name|_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|digi_attach
parameter_list|(
name|struct
name|digi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|digi_detach
parameter_list|(
name|device_t
name|_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|digi_shutdown
parameter_list|(
name|device_t
name|_dev
parameter_list|)
function_decl|;
end_function_decl

end_unit

