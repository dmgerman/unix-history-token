begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *  dgmreg.h $FreeBSD$  *  *  Digiboard driver.  *  *  Stage 1. "Better than nothing".  *  *  Based on sio driver by Bruce Evans and on Linux driver by Troy   *  De Jongh<troyd@digibd.com> or<troyd@skypoint.com>   *  which is under GNU General Public License version 2 so this driver   *  is forced to be under GPL 2 too.  *  *  Written by Serge Babkin,  *      Joint Stock Commercial Bank "Chelindbank"  *      (Chelyabinsk, Russia)  *      babkin@hq.icb.chel.su  */
end_comment

begin_define
define|#
directive|define
name|MAX_DGM_PORTS
value|64
end_define

begin_comment
comment|/* digi.h */
end_comment

begin_comment
comment|/*          Definitions for DigiBoard ditty(1) command.                 */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TIOCMODG
argument_list|)
end_if

begin_define
define|#
directive|define
name|TIOCMODG
value|('d'<<8) | 250
end_define

begin_comment
comment|/* get modem ctrl state	*/
end_comment

begin_define
define|#
directive|define
name|TIOCMODS
value|('d'<<8) | 251
end_define

begin_comment
comment|/* set modem ctrl state	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TIOCMSET
argument_list|)
end_if

begin_define
define|#
directive|define
name|TIOCMSET
value|('d'<<8) | 252
end_define

begin_comment
comment|/* set modem ctrl state	*/
end_comment

begin_define
define|#
directive|define
name|TIOCMGET
value|('d'<<8) | 253
end_define

begin_comment
comment|/* set modem ctrl state	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TIOCMBIC
argument_list|)
end_if

begin_define
define|#
directive|define
name|TIOCMBIC
value|('d'<<8) | 254
end_define

begin_comment
comment|/* set modem ctrl state */
end_comment

begin_define
define|#
directive|define
name|TIOCMBIS
value|('d'<<8) | 255
end_define

begin_comment
comment|/* set modem ctrl state */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TIOCSDTR
argument_list|)
end_if

begin_define
define|#
directive|define
name|TIOCSDTR
value|('e'<<8) | 0
end_define

begin_comment
comment|/* set DTR		*/
end_comment

begin_define
define|#
directive|define
name|TIOCCDTR
value|('e'<<8) | 1
end_define

begin_comment
comment|/* clear DTR		*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************************************************************  * Ioctl command arguments for DIGI parameters.  ************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DIGI_GETA
value|('e'<<8) | 94
end_define

begin_comment
comment|/* Read params		*/
end_comment

begin_define
define|#
directive|define
name|DIGI_SETA
value|('e'<<8) | 95
end_define

begin_comment
comment|/* Set params		*/
end_comment

begin_define
define|#
directive|define
name|DIGI_SETAW
value|('e'<<8) | 96
end_define

begin_comment
comment|/* Drain& set params	*/
end_comment

begin_define
define|#
directive|define
name|DIGI_SETAF
value|('e'<<8) | 97
end_define

begin_comment
comment|/* Drain, flush& set params */
end_comment

begin_define
define|#
directive|define
name|DIGI_GETFLOW
value|('e'<<8) | 99
end_define

begin_comment
comment|/* Get startc/stopc flow */
end_comment

begin_comment
comment|/* control characters 	 */
end_comment

begin_define
define|#
directive|define
name|DIGI_SETFLOW
value|('e'<<8) | 100
end_define

begin_comment
comment|/* Set startc/stopc flow */
end_comment

begin_comment
comment|/* control characters	 */
end_comment

begin_define
define|#
directive|define
name|DIGI_GETAFLOW
value|('e'<<8) | 101
end_define

begin_comment
comment|/* Get Aux. startc/stopc */
end_comment

begin_comment
comment|/* flow control chars 	 */
end_comment

begin_define
define|#
directive|define
name|DIGI_SETAFLOW
value|('e'<<8) | 102
end_define

begin_comment
comment|/* Set Aux. startc/stopc */
end_comment

begin_comment
comment|/* flow control chars	 */
end_comment

begin_struct
struct|struct
name|digiflow_struct
block|{
name|unsigned
name|char
name|startc
decl_stmt|;
comment|/* flow cntl start char	*/
name|unsigned
name|char
name|stopc
decl_stmt|;
comment|/* flow cntl stop char	*/
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|digiflow_struct
name|digiflow_t
typedef|;
end_typedef

begin_comment
comment|/************************************************************************  * Values for digi_flags   ************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DIGI_IXON
value|0x0001
end_define

begin_comment
comment|/* Handle IXON in the FEP	*/
end_comment

begin_define
define|#
directive|define
name|DIGI_FAST
value|0x0002
end_define

begin_comment
comment|/* Fast baud rates		*/
end_comment

begin_define
define|#
directive|define
name|RTSPACE
value|0x0004
end_define

begin_comment
comment|/* RTS input flow control	*/
end_comment

begin_define
define|#
directive|define
name|CTSPACE
value|0x0008
end_define

begin_comment
comment|/* CTS output flow control	*/
end_comment

begin_define
define|#
directive|define
name|DSRPACE
value|0x0010
end_define

begin_comment
comment|/* DSR output flow control	*/
end_comment

begin_define
define|#
directive|define
name|DCDPACE
value|0x0020
end_define

begin_comment
comment|/* DCD output flow control	*/
end_comment

begin_define
define|#
directive|define
name|DTRPACE
value|0x0040
end_define

begin_comment
comment|/* DTR input flow control	*/
end_comment

begin_define
define|#
directive|define
name|DIGI_FORCEDCD
value|0x0100
end_define

begin_comment
comment|/* Force carrier		*/
end_comment

begin_define
define|#
directive|define
name|DIGI_ALTPIN
value|0x0200
end_define

begin_comment
comment|/* Alternate RJ-45 pin config	*/
end_comment

begin_define
define|#
directive|define
name|DIGI_AIXON
value|0x0400
end_define

begin_comment
comment|/* Aux flow control in fep	*/
end_comment

begin_comment
comment|/************************************************************************  * Structure used with ioctl commands for DIGI parameters.  ************************************************************************/
end_comment

begin_struct
struct|struct
name|digi_struct
block|{
name|unsigned
name|short
name|digi_flags
decl_stmt|;
comment|/* Flags (see above)	*/
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|digi_struct
name|digi_t
typedef|;
end_typedef

begin_comment
comment|/* fep.h */
end_comment

begin_define
define|#
directive|define
name|FEP_CSTART
value|0x400L
end_define

begin_define
define|#
directive|define
name|FEP_CMAX
value|0x800L
end_define

begin_define
define|#
directive|define
name|FEP_ISTART
value|0x800L
end_define

begin_define
define|#
directive|define
name|FEP_IMAX
value|0xC00L
end_define

begin_define
define|#
directive|define
name|FEP_CIN
value|0xD10L
end_define

begin_define
define|#
directive|define
name|FEP_GLOBAL
value|0xD10L
end_define

begin_define
define|#
directive|define
name|FEP_EIN
value|0xD18L
end_define

begin_define
define|#
directive|define
name|FEPSTAT
value|0xD20L
end_define

begin_define
define|#
directive|define
name|CHANSTRUCT
value|0x1000L
end_define

begin_define
define|#
directive|define
name|RXTXBUF
value|0x4000L
end_define

begin_struct
struct|struct
name|global_data
block|{
specifier|volatile
name|ushort
name|cin
decl_stmt|;
specifier|volatile
name|ushort
name|cout
decl_stmt|;
specifier|volatile
name|ushort
name|cstart
decl_stmt|;
specifier|volatile
name|ushort
name|cmax
decl_stmt|;
specifier|volatile
name|ushort
name|ein
decl_stmt|;
specifier|volatile
name|ushort
name|eout
decl_stmt|;
specifier|volatile
name|ushort
name|istart
decl_stmt|;
specifier|volatile
name|ushort
name|imax
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|board_chan
block|{
name|int
name|filler1
decl_stmt|;
name|int
name|filler2
decl_stmt|;
specifier|volatile
name|ushort
name|tseg
decl_stmt|;
specifier|volatile
name|ushort
name|tin
decl_stmt|;
specifier|volatile
name|ushort
name|tout
decl_stmt|;
specifier|volatile
name|ushort
name|tmax
decl_stmt|;
specifier|volatile
name|ushort
name|rseg
decl_stmt|;
specifier|volatile
name|ushort
name|rin
decl_stmt|;
specifier|volatile
name|ushort
name|rout
decl_stmt|;
specifier|volatile
name|ushort
name|rmax
decl_stmt|;
specifier|volatile
name|ushort
name|tlow
decl_stmt|;
specifier|volatile
name|ushort
name|rlow
decl_stmt|;
specifier|volatile
name|ushort
name|rhigh
decl_stmt|;
specifier|volatile
name|ushort
name|incr
decl_stmt|;
specifier|volatile
name|ushort
name|etime
decl_stmt|;
specifier|volatile
name|ushort
name|edelay
decl_stmt|;
specifier|volatile
name|u_char
modifier|*
name|dev
decl_stmt|;
specifier|volatile
name|ushort
name|iflag
decl_stmt|;
specifier|volatile
name|ushort
name|oflag
decl_stmt|;
specifier|volatile
name|ushort
name|cflag
decl_stmt|;
specifier|volatile
name|ushort
name|gmask
decl_stmt|;
specifier|volatile
name|ushort
name|col
decl_stmt|;
specifier|volatile
name|ushort
name|delay
decl_stmt|;
specifier|volatile
name|ushort
name|imask
decl_stmt|;
specifier|volatile
name|ushort
name|tflush
decl_stmt|;
name|int
name|filler3
decl_stmt|;
name|int
name|filler4
decl_stmt|;
name|int
name|filler5
decl_stmt|;
name|int
name|filler6
decl_stmt|;
specifier|volatile
name|u_char
name|num
decl_stmt|;
specifier|volatile
name|u_char
name|ract
decl_stmt|;
specifier|volatile
name|u_char
name|bstat
decl_stmt|;
specifier|volatile
name|u_char
name|tbusy
decl_stmt|;
specifier|volatile
name|u_char
name|iempty
decl_stmt|;
specifier|volatile
name|u_char
name|ilow
decl_stmt|;
specifier|volatile
name|u_char
name|idata
decl_stmt|;
specifier|volatile
name|u_char
name|eflag
decl_stmt|;
specifier|volatile
name|u_char
name|tflag
decl_stmt|;
specifier|volatile
name|u_char
name|rflag
decl_stmt|;
specifier|volatile
name|u_char
name|xmask
decl_stmt|;
specifier|volatile
name|u_char
name|xval
decl_stmt|;
specifier|volatile
name|u_char
name|mstat
decl_stmt|;
specifier|volatile
name|u_char
name|mchange
decl_stmt|;
specifier|volatile
name|u_char
name|mint
decl_stmt|;
specifier|volatile
name|u_char
name|lstat
decl_stmt|;
specifier|volatile
name|u_char
name|mtran
decl_stmt|;
specifier|volatile
name|u_char
name|orun
decl_stmt|;
specifier|volatile
name|u_char
name|startca
decl_stmt|;
specifier|volatile
name|u_char
name|stopca
decl_stmt|;
specifier|volatile
name|u_char
name|startc
decl_stmt|;
specifier|volatile
name|u_char
name|stopc
decl_stmt|;
specifier|volatile
name|u_char
name|vnext
decl_stmt|;
specifier|volatile
name|u_char
name|hflow
decl_stmt|;
specifier|volatile
name|u_char
name|fillc
decl_stmt|;
specifier|volatile
name|u_char
name|ochar
decl_stmt|;
specifier|volatile
name|u_char
name|omask
decl_stmt|;
name|u_char
name|filler7
decl_stmt|;
name|u_char
name|filler8
index|[
literal|28
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SRXLWATER
value|0xE0
end_define

begin_define
define|#
directive|define
name|SRXHWATER
value|0xE1
end_define

begin_define
define|#
directive|define
name|STOUT
value|0xE2
end_define

begin_define
define|#
directive|define
name|PAUSETX
value|0xE3
end_define

begin_define
define|#
directive|define
name|RESUMETX
value|0xE4
end_define

begin_define
define|#
directive|define
name|SAUXONOFFC
value|0xE6
end_define

begin_define
define|#
directive|define
name|SENDBREAK
value|0xE8
end_define

begin_define
define|#
directive|define
name|SETMODEM
value|0xE9
end_define

begin_define
define|#
directive|define
name|SETIFLAGS
value|0xEA
end_define

begin_define
define|#
directive|define
name|SONOFFC
value|0xEB
end_define

begin_define
define|#
directive|define
name|STXLWATER
value|0xEC
end_define

begin_define
define|#
directive|define
name|PAUSERX
value|0xEE
end_define

begin_define
define|#
directive|define
name|RESUMERX
value|0xEF
end_define

begin_define
define|#
directive|define
name|SETBUFFER
value|0xF2
end_define

begin_define
define|#
directive|define
name|SETCOOKED
value|0xF3
end_define

begin_define
define|#
directive|define
name|SETHFLOW
value|0xF4
end_define

begin_define
define|#
directive|define
name|SETCTRLFLAGS
value|0xF5
end_define

begin_define
define|#
directive|define
name|SETVNEXT
value|0xF6
end_define

begin_define
define|#
directive|define
name|BREAK_IND
value|0x01
end_define

begin_define
define|#
directive|define
name|LOWTX_IND
value|0x02
end_define

begin_define
define|#
directive|define
name|EMPTYTX_IND
value|0x04
end_define

begin_define
define|#
directive|define
name|DATA_IND
value|0x08
end_define

begin_define
define|#
directive|define
name|MODEMCHG_IND
value|0x20
end_define

begin_define
define|#
directive|define
name|ALL_IND
value|(BREAK_IND|LOWTX_IND|EMPTYTX_IND|DATA_IND|MODEMCHG_IND)
end_define

begin_define
define|#
directive|define
name|CD
value|0x80
end_define

begin_define
define|#
directive|define
name|DSR
value|0x20
end_define

begin_define
define|#
directive|define
name|CTS
value|0x10
end_define

begin_define
define|#
directive|define
name|DTR
value|0x01
end_define

begin_define
define|#
directive|define
name|RTS
value|0x02
end_define

begin_define
define|#
directive|define
name|RI
value|0x40
end_define

begin_define
define|#
directive|define
name|FEPCODESEG
value|0x0200L
end_define

begin_define
define|#
directive|define
name|FEPCODE
value|0x2000L
end_define

begin_define
define|#
directive|define
name|BIOSCODE
value|0xf800L
end_define

begin_define
define|#
directive|define
name|BIOSOFFSET
value|0x1000L
end_define

begin_define
define|#
directive|define
name|MISCGLOBAL
value|0x0C00L
end_define

begin_define
define|#
directive|define
name|NPORT
value|0x0C02L
end_define

begin_define
define|#
directive|define
name|MBOX
value|0x0C40L
end_define

begin_define
define|#
directive|define
name|BOTWIN
value|0x100L
end_define

begin_define
define|#
directive|define
name|TOPWIN
value|0xFF00L
end_define

begin_define
define|#
directive|define
name|FEPCLR
value|0x00
end_define

begin_define
define|#
directive|define
name|FEPMEM
value|0x02
end_define

begin_define
define|#
directive|define
name|FEPRST
value|0x04
end_define

begin_define
define|#
directive|define
name|FEPINT
value|0x08
end_define

begin_define
define|#
directive|define
name|FEPMASK
value|0x0e
end_define

begin_define
define|#
directive|define
name|FEPWIN
value|0x80
end_define

begin_define
define|#
directive|define
name|PCXI
value|0
end_define

begin_define
define|#
directive|define
name|PCXE
value|1
end_define

begin_define
define|#
directive|define
name|PCXEVE
value|2
end_define

begin_define
define|#
directive|define
name|PCXEM
value|3
end_define

begin_decl_stmt
specifier|static
name|char
modifier|*
specifier|const
name|board_desc
index|[]
init|=
block|{
literal|"PC/Xi (64K)"
block|,
literal|"PC/Xe (64K)"
block|,
literal|"PC/Xe (8K) "
block|,
literal|"PC/Xem "
block|, }
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|STARTC
value|021
end_define

begin_define
define|#
directive|define
name|STOPC
value|023
end_define

begin_define
define|#
directive|define
name|IAIXON
value|0x2000
end_define

begin_struct
struct|struct
name|board_info
block|{
name|u_char
name|status
decl_stmt|;
name|u_char
name|type
decl_stmt|;
name|u_char
name|altpin
decl_stmt|;
name|ushort
name|numports
decl_stmt|;
name|ushort
name|port
decl_stmt|;
name|u_long
name|membase
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TXSTOPPED
value|0x1
end_define

begin_define
define|#
directive|define
name|LOWWAIT
value|0x2
end_define

begin_define
define|#
directive|define
name|EMPTYWAIT
value|0x4
end_define

begin_define
define|#
directive|define
name|DISABLED
value|0
end_define

begin_define
define|#
directive|define
name|ENABLED
value|1
end_define

begin_define
define|#
directive|define
name|OFF
value|0
end_define

begin_define
define|#
directive|define
name|ON
value|1
end_define

begin_define
define|#
directive|define
name|FEPTIMEOUT
value|200000
end_define

begin_define
define|#
directive|define
name|SERIAL_TYPE_NORMAL
value|1
end_define

begin_define
define|#
directive|define
name|SERIAL_TYPE_CALLOUT
value|2
end_define

begin_define
define|#
directive|define
name|PCXE_EVENT_HANGUP
value|1
end_define

begin_struct
struct|struct
name|channel
block|{
name|u_char
name|unit
decl_stmt|;
comment|/* board unit number */
name|u_char
name|omodem
decl_stmt|;
comment|/* FEP output modem status     */
name|u_char
name|imodem
decl_stmt|;
comment|/* FEP input modem status      */
name|u_char
name|modemfake
decl_stmt|;
comment|/* Modem values to be forced   */
name|u_char
name|modem
decl_stmt|;
comment|/* Force values                */
name|u_char
name|hflow
decl_stmt|;
name|u_char
name|dsr
decl_stmt|;
name|u_char
name|dcd
decl_stmt|;
name|u_char
name|stopc
decl_stmt|;
name|u_char
name|startc
decl_stmt|;
name|u_char
name|stopca
decl_stmt|;
name|u_char
name|startca
decl_stmt|;
name|u_char
name|fepstopc
decl_stmt|;
name|u_char
name|fepstartc
decl_stmt|;
name|u_char
name|fepstopca
decl_stmt|;
name|u_char
name|fepstartca
decl_stmt|;
name|u_char
name|txwin
decl_stmt|;
name|u_char
name|rxwin
decl_stmt|;
name|ushort
name|fepiflag
decl_stmt|;
name|ushort
name|fepcflag
decl_stmt|;
name|ushort
name|fepoflag
decl_stmt|;
name|ushort
name|txbufhead
decl_stmt|;
name|ushort
name|txbufsize
decl_stmt|;
name|ushort
name|rxbufhead
decl_stmt|;
name|ushort
name|rxbufsize
decl_stmt|;
name|int
name|close_delay
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|blocked_open
decl_stmt|;
name|int
name|event
decl_stmt|;
name|int
name|asyncflags
decl_stmt|;
name|uint
name|dev
decl_stmt|;
name|long
name|session
decl_stmt|;
name|long
name|pgrp
decl_stmt|;
name|u_long
name|statusflags
decl_stmt|;
name|u_long
name|c_iflag
decl_stmt|;
name|u_long
name|c_cflag
decl_stmt|;
name|u_long
name|c_lflag
decl_stmt|;
name|u_long
name|c_oflag
decl_stmt|;
name|u_char
modifier|*
name|txptr
decl_stmt|;
name|u_char
modifier|*
name|rxptr
decl_stmt|;
name|struct
name|board_info
modifier|*
name|board
decl_stmt|;
name|struct
name|board_chan
modifier|*
name|brdchan
decl_stmt|;
name|struct
name|digi_struct
name|digiext
decl_stmt|;
name|struct
name|tty
modifier|*
name|tty
decl_stmt|;
name|struct
name|termios
name|normal_termios
decl_stmt|;
name|struct
name|termios
name|callout_termios
decl_stmt|;
specifier|volatile
name|struct
name|global_data
modifier|*
name|mailbox
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* flags for configuring */
end_comment

begin_define
define|#
directive|define
name|DGBFLAG_ALTPIN
value|0x0001
end_define

begin_comment
comment|/* chande DCD and DCD */
end_comment

begin_define
define|#
directive|define
name|DGBFLAG_NOWIN
value|0x0002
end_define

begin_comment
comment|/* use windowed PC/Xe as non-windowed */
end_comment

begin_define
define|#
directive|define
name|DB_RD
value|0x0001
end_define

begin_define
define|#
directive|define
name|DB_WR
value|0x0002
end_define

begin_define
define|#
directive|define
name|DB_WIN
value|0x0004
end_define

begin_define
define|#
directive|define
name|DB_INFO
value|0x0008
end_define

begin_define
define|#
directive|define
name|DB_EXCEPT
value|0x0010
end_define

begin_define
define|#
directive|define
name|DB_OPEN
value|0x0100
end_define

begin_define
define|#
directive|define
name|DB_CLOSE
value|0x0200
end_define

begin_define
define|#
directive|define
name|DB_DATA
value|0x0400
end_define

begin_define
define|#
directive|define
name|DB_RXDATA
value|0x0401
end_define

begin_define
define|#
directive|define
name|DB_TXDATA
value|0x0402
end_define

begin_define
define|#
directive|define
name|DB_EVENT
value|0x0800
end_define

begin_define
define|#
directive|define
name|DB_MODEM
value|0x1000
end_define

begin_define
define|#
directive|define
name|DB_BREAK
value|0x2000
end_define

begin_define
define|#
directive|define
name|DB_PARAM
value|0x4000
end_define

begin_define
define|#
directive|define
name|DB_FEP
value|0x8000
end_define

begin_comment
comment|/* debugging printout */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DPRINT1
parameter_list|(
name|l
parameter_list|,
name|a1
parameter_list|)
value|(dgmdebug&l ? printf(a1) : 0)
end_define

begin_define
define|#
directive|define
name|DPRINT2
parameter_list|(
name|l
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|)
value|(dgmdebug&l ? printf(a1,a2) : 0)
end_define

begin_define
define|#
directive|define
name|DPRINT3
parameter_list|(
name|l
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
value|(dgmdebug&l ? printf(a1,a2,a3) : 0)
end_define

begin_define
define|#
directive|define
name|DPRINT4
parameter_list|(
name|l
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|)
value|(dgmdebug&l ? printf(a1,a2,a3,a4) : 0)
end_define

begin_define
define|#
directive|define
name|DPRINT5
parameter_list|(
name|l
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|)
value|(dgmdebug&l ? printf(a1,a2,a3,a4,a5) : 0)
end_define

begin_define
define|#
directive|define
name|DPRINT6
parameter_list|(
name|l
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|,
name|a6
parameter_list|)
value|(dgmdebug&l ? printf(a1,a2,a3,a4,a5,a6) : 0)
end_define

begin_define
define|#
directive|define
name|DPRINT7
parameter_list|(
name|l
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|,
name|a6
parameter_list|,
name|a7
parameter_list|)
value|(dgmdebug&l ? printf(a1,a2,a3,a4,a5,a6,a7) : 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINT1
parameter_list|(
name|l
parameter_list|,
name|a1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DPRINT2
parameter_list|(
name|l
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DPRINT3
parameter_list|(
name|l
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DPRINT4
parameter_list|(
name|l
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DPRINT5
parameter_list|(
name|l
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DPRINT6
parameter_list|(
name|l
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|,
name|a6
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DPRINT7
parameter_list|(
name|l
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|,
name|a6
parameter_list|,
name|a7
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These are termios bits as the FEP understands them */
end_comment

begin_comment
comment|/* c_cflag bits */
end_comment

begin_define
define|#
directive|define
name|FEP_CBAUD
value|0x00000f
end_define

begin_define
define|#
directive|define
name|FEP_B0
value|0x000000
end_define

begin_comment
comment|/* hang up */
end_comment

begin_define
define|#
directive|define
name|FEP_B50
value|0x000001
end_define

begin_define
define|#
directive|define
name|FEP_B75
value|0x000002
end_define

begin_define
define|#
directive|define
name|FEP_B110
value|0x000003
end_define

begin_define
define|#
directive|define
name|FEP_B134
value|0x000004
end_define

begin_define
define|#
directive|define
name|FEP_B150
value|0x000005
end_define

begin_define
define|#
directive|define
name|FEP_B200
value|0x000006
end_define

begin_define
define|#
directive|define
name|FEP_B300
value|0x000007
end_define

begin_define
define|#
directive|define
name|FEP_B600
value|0x000008
end_define

begin_define
define|#
directive|define
name|FEP_B1200
value|0x000009
end_define

begin_define
define|#
directive|define
name|FEP_B1800
value|0x00000a
end_define

begin_define
define|#
directive|define
name|FEP_B2400
value|0x00000b
end_define

begin_define
define|#
directive|define
name|FEP_B4800
value|0x00000c
end_define

begin_define
define|#
directive|define
name|FEP_B9600
value|0x00000d
end_define

begin_define
define|#
directive|define
name|FEP_B19200
value|0x00000e
end_define

begin_define
define|#
directive|define
name|FEP_B38400
value|0x00000f
end_define

begin_define
define|#
directive|define
name|FEP_EXTA
value|FEP_B19200
end_define

begin_define
define|#
directive|define
name|FEP_EXTB
value|FEP_B38400
end_define

begin_define
define|#
directive|define
name|FEP_CSIZE
value|0x000030
end_define

begin_define
define|#
directive|define
name|FEP_CS5
value|0x000000
end_define

begin_define
define|#
directive|define
name|FEP_CS6
value|0x000010
end_define

begin_define
define|#
directive|define
name|FEP_CS7
value|0x000020
end_define

begin_define
define|#
directive|define
name|FEP_CS8
value|0x000030
end_define

begin_define
define|#
directive|define
name|FEP_CSTOPB
value|0x000040
end_define

begin_define
define|#
directive|define
name|FEP_CREAD
value|0x000080
end_define

begin_define
define|#
directive|define
name|FEP_PARENB
value|0x000100
end_define

begin_define
define|#
directive|define
name|FEP_PARODD
value|0x000200
end_define

begin_define
define|#
directive|define
name|FEP_CLOCAL
value|0x000800
end_define

begin_define
define|#
directive|define
name|FEP_FASTBAUD
value|0x000400
end_define

begin_comment
comment|/* c_iflag bits */
end_comment

begin_define
define|#
directive|define
name|FEP_IGNBRK
value|0000001
end_define

begin_define
define|#
directive|define
name|FEP_BRKINT
value|0000002
end_define

begin_define
define|#
directive|define
name|FEP_IGNPAR
value|0000004
end_define

begin_define
define|#
directive|define
name|FEP_PARMRK
value|0000010
end_define

begin_define
define|#
directive|define
name|FEP_INPCK
value|0000020
end_define

begin_define
define|#
directive|define
name|FEP_ISTRIP
value|0000040
end_define

begin_define
define|#
directive|define
name|FEP_IXON
value|0002000
end_define

begin_define
define|#
directive|define
name|FEP_IXANY
value|0004000
end_define

begin_define
define|#
directive|define
name|FEP_IXOFF
value|0010000
end_define

end_unit

