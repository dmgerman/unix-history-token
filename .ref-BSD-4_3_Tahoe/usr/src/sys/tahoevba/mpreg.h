begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)mpreg.h	7.2 (Berkeley) 7/15/88  */
end_comment

begin_comment
comment|/*  * MPCC Asynchronous Communications Interface.  */
end_comment

begin_define
define|#
directive|define
name|MPINTRBASE
value|0xa0
end_define

begin_comment
comment|/* base vector for interupts */
end_comment

begin_define
define|#
directive|define
name|MPMAGIC
value|1969
end_define

begin_comment
comment|/* magic number for mblok */
end_comment

begin_define
define|#
directive|define
name|MPMAXPORT
value|32
end_define

begin_comment
comment|/* maximum number of ports on an MPCC */
end_comment

begin_comment
comment|/*  * MPCC's are capable of supporting one of a  * the protocols listed below.  This driver  * supports only the async terminal protocol.  */
end_comment

begin_define
define|#
directive|define
name|MPPROTO_UNUSED
value|0
end_define

begin_comment
comment|/* port not in use */
end_comment

begin_define
define|#
directive|define
name|MPPROTO_ASYNC
value|1
end_define

begin_comment
comment|/* async protocol */
end_comment

begin_define
define|#
directive|define
name|MPPROTO_X25
value|2
end_define

begin_comment
comment|/* x25 protocol (unsupported) */
end_comment

begin_define
define|#
directive|define
name|MPPROTO_BISYNC
value|3
end_define

begin_comment
comment|/* bisync protocol (unsupported) */
end_comment

begin_define
define|#
directive|define
name|MPPROTO_SNA
value|4
end_define

begin_comment
comment|/* sna protocol (unsupported) */
end_comment

begin_define
define|#
directive|define
name|NMPPROTO
value|5
end_define

begin_comment
comment|/* max protocols supported by MPCC */
end_comment

begin_define
define|#
directive|define
name|MPINSET
value|8
end_define

begin_define
define|#
directive|define
name|MPOUTSET
value|8
end_define

begin_comment
comment|/*  * Host Interface Structure  */
end_comment

begin_struct
struct|struct
name|his
block|{
name|u_char
name|semaphore
decl_stmt|;
define|#
directive|define
name|MPSEMA_AVAILABLE
value|1
define|#
directive|define
name|MPSEMA_WORK
value|4
name|u_char
name|imok
decl_stmt|;
define|#
directive|define
name|MPIMOK_ALIVE
value|0x01
define|#
directive|define
name|MPIMOK_DEAD
value|0x80
name|u_char
name|brdnum
decl_stmt|;
comment|/* Virtual brd number for protocol */
name|u_char
name|unused
decl_stmt|;
struct|struct
block|{
name|u_char
name|inbdone
index|[
name|MPMAXPORT
index|]
decl_stmt|;
comment|/* Ports w/ inbound completed */
name|u_char
name|outbdone
index|[
name|MPMAXPORT
index|]
decl_stmt|;
comment|/* Ports w/outbound available */
name|u_int
name|fill
index|[
literal|2
index|]
decl_stmt|;
block|}
name|proto
index|[
name|NMPPROTO
index|]
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MPPORT_EOL
value|0xff
end_define

begin_comment
comment|/* end of port list */
end_comment

begin_comment
comment|/*  * Async host transmit list structure.  */
end_comment

begin_define
define|#
directive|define
name|MPXMIT
value|4
end_define

begin_comment
comment|/* # of transmit ptrs/MP_WRITE event */
end_comment

begin_struct
struct|struct
name|hxmtl
block|{
name|caddr_t
name|dblock
index|[
name|MPXMIT
index|]
decl_stmt|;
comment|/* ptrs to data blocks */
name|u_short
name|size
index|[
name|MPXMIT
index|]
decl_stmt|;
comment|/* size of each block */
block|}
struct|;
end_struct

begin_comment
comment|/*  * MPCC asynchronous protocol events.  */
end_comment

begin_struct
struct|struct
name|mpevent
block|{
name|u_char
name|ev_status
decl_stmt|;
comment|/* Go Status */
name|u_char
name|ev_cmd
decl_stmt|;
comment|/* Optional Op-code */
name|u_short
name|ev_opts
decl_stmt|;
comment|/* Optional flags */
name|u_short
name|ev_error
decl_stmt|;
comment|/* error status returned */
name|u_short
name|ev_flags
decl_stmt|;
comment|/* optional event flags field */
name|caddr_t
name|ev_params
decl_stmt|;
comment|/* pointer to event parameters */
union|union
block|{
name|struct
name|hxmtl
modifier|*
name|hxl
decl_stmt|;
comment|/* pointer to host xmit list */
name|u_char
modifier|*
name|rcvblk
decl_stmt|;
comment|/* pointer to receive block */
block|}
name|ev_un
union|;
name|u_short
name|ev_count
decl_stmt|;
comment|/* # ptrs in xmit list/# receive chars  */
name|u_short
name|ev_unused
decl_stmt|;
comment|/* round to longword */
name|u_int
name|ev_unused2
decl_stmt|;
comment|/* round to size of BSC struct. GROT!! */
block|}
struct|;
end_struct

begin_comment
comment|/* defines for ev_status */
end_comment

begin_define
define|#
directive|define
name|EVSTATUS_FREE
value|0
end_define

begin_define
define|#
directive|define
name|EVSTATUS_GO
value|1
end_define

begin_define
define|#
directive|define
name|EVSTATUS_BUSY
value|2
end_define

begin_define
define|#
directive|define
name|EVSTATUS_DONE
value|4
end_define

begin_comment
comment|/* defines for ev_cmd */
end_comment

begin_define
define|#
directive|define
name|EVCMD_OPEN
value|1
end_define

begin_define
define|#
directive|define
name|EVCMD_CLOSE
value|2
end_define

begin_define
define|#
directive|define
name|EVCMD_RESET
value|3
end_define

begin_define
define|#
directive|define
name|EVCMD_IOCTL
value|4
end_define

begin_define
define|#
directive|define
name|EVCMD_WRITE
value|5
end_define

begin_define
define|#
directive|define
name|EVCMD_READ
value|6
end_define

begin_define
define|#
directive|define
name|EVCMD_STATUS
value|7
end_define

begin_define
define|#
directive|define
name|EVCMD_EVENT
value|8
end_define

begin_comment
comment|/*  * Host-MPCC interface block.  */
end_comment

begin_struct
struct|struct
name|mblok
block|{
name|u_char
name|mb_status
decl_stmt|;
comment|/* mpcc status */
name|u_char
name|mb_ivec
decl_stmt|;
comment|/* host interrupt vector */
name|u_short
name|mb_magic
decl_stmt|;
name|u_char
name|mb_diagswitch
index|[
literal|2
index|]
decl_stmt|;
comment|/* run diagnostics/application */
name|u_char
name|mb_softerr
decl_stmt|;
comment|/* soft error code */
name|u_char
name|mb_harderr
decl_stmt|;
comment|/* hard error code */
struct|struct
name|mpdl
block|{
comment|/* download/config area */
name|u_char
name|mpdl_status
decl_stmt|;
comment|/* control/status */
name|u_char
name|mpdl_cmd
decl_stmt|;
comment|/* request type */
name|u_short
name|mpdl_count
decl_stmt|;
comment|/* size of parameter block */
name|caddr_t
name|mpdl_data
decl_stmt|;
comment|/* command parameters */
block|}
name|mb_dl
struct|;
name|u_char
name|mb_hiport
decl_stmt|,
name|mb_loport
decl_stmt|;
comment|/* high-low mpcc port numbers */
name|u_char
name|mb_unit
decl_stmt|;
comment|/* mpcc unit number */
name|u_char
name|mb_hndshk
decl_stmt|;
comment|/* handshaking timer */
name|caddr_t
name|mb_imokclk
decl_stmt|;
comment|/* handshaking clock */
name|u_char
name|mb_nointcnt
decl_stmt|;
comment|/* no interrupt from handshake */
name|u_char
name|mb_mpintcnt
decl_stmt|;
comment|/* # outstanding interupts to MPCC */
name|short
name|mb_unused
decl_stmt|;
name|caddr_t
name|mb_mpintclk
decl_stmt|;
comment|/* MPCC interrupt clock */
name|struct
name|his
name|mb_hostint
decl_stmt|;
comment|/* To Talk with Host */
name|u_char
name|mb_proto
index|[
name|MPMAXPORT
index|]
decl_stmt|;
comment|/* per-port protocols */
name|u_char
name|mb_intr
index|[
name|MPMAXPORT
index|]
decl_stmt|;
comment|/* per-port host->mpcc int flags */
struct|struct
name|mpport
block|{
comment|/* per-port structure */
name|u_short
name|mp_proto
decl_stmt|;
comment|/* protocol of port */
name|u_char
name|mp_on
decl_stmt|;
comment|/* Next available entry on Host */
name|u_char
name|mp_off
decl_stmt|;
comment|/* Next expected 'DONE' entry on Host */
name|struct
name|mpevent
name|mp_recvq
index|[
name|MPINSET
index|]
decl_stmt|;
comment|/* queue of events to host */
name|struct
name|mpevent
name|mp_sendq
index|[
name|MPOUTSET
index|]
decl_stmt|;
comment|/* queue of events to mpcc */
name|u_char
name|mp_nextrcv
decl_stmt|;
comment|/* next expected 'DONE' entry on Host */
name|u_char
name|mp_flags
decl_stmt|;
comment|/* host flags */
name|short
name|mp_unused
decl_stmt|;
name|caddr_t
name|mp_data
decl_stmt|;
comment|/* pointer to data for port */
block|}
name|mb_port
index|[
name|MPMAXPORT
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/* status defines for mblok.status */
end_comment

begin_define
define|#
directive|define
name|MP_DLPEND
value|1
end_define

begin_define
define|#
directive|define
name|MP_DLOPEN
value|2
end_define

begin_define
define|#
directive|define
name|MP_DLDONE
value|3
end_define

begin_define
define|#
directive|define
name|MP_OPCLOSE
value|4
end_define

begin_define
define|#
directive|define
name|MP_OPOPEN
value|5
end_define

begin_define
define|#
directive|define
name|MP_DLTIME
value|6
end_define

begin_define
define|#
directive|define
name|MP_DLERROR
value|(-1)
end_define

begin_comment
comment|/* hard error status values loaded into mblock.herr */
end_comment

begin_define
define|#
directive|define
name|NOHERR
value|0
end_define

begin_comment
comment|/* no error */
end_comment

begin_define
define|#
directive|define
name|MPBUSERR
value|1
end_define

begin_comment
comment|/* bus error */
end_comment

begin_define
define|#
directive|define
name|ADDRERR
value|2
end_define

begin_comment
comment|/* address error */
end_comment

begin_define
define|#
directive|define
name|UNDECC
value|3
end_define

begin_comment
comment|/* undefined ecc interrupt */
end_comment

begin_define
define|#
directive|define
name|UNDINT
value|4
end_define

begin_comment
comment|/* undefined interrupt */
end_comment

begin_define
define|#
directive|define
name|PWRFL
value|5
end_define

begin_comment
comment|/* power fail occurred */
end_comment

begin_define
define|#
directive|define
name|NOXENTRY
value|6
end_define

begin_comment
comment|/* xdone was enterred w/o xmit entry on queue */
end_comment

begin_define
define|#
directive|define
name|TWOFTMRS
value|7
end_define

begin_comment
comment|/* tried to start two fast timers on one port */
end_comment

begin_define
define|#
directive|define
name|INTQFULL
value|8
end_define

begin_comment
comment|/* interupt queue full */
end_comment

begin_define
define|#
directive|define
name|INTQERR
value|9
end_define

begin_comment
comment|/* interupt queue ack error */
end_comment

begin_define
define|#
directive|define
name|CBPERR
value|10
end_define

begin_comment
comment|/* uncorrectable DMA parity error */
end_comment

begin_define
define|#
directive|define
name|ACPDEAD
value|11
end_define

begin_comment
comment|/* acap has died */
end_comment

begin_comment
comment|/* additional panic codes not listed */
end_comment

begin_comment
comment|/* soft error status values loaded into mblock.serr */
end_comment

begin_define
define|#
directive|define
name|NOSERR
value|0
end_define

begin_comment
comment|/* no error */
end_comment

begin_define
define|#
directive|define
name|DMAPERR
value|1
end_define

begin_comment
comment|/* dma parity error */
end_comment

begin_define
define|#
directive|define
name|ECCERR
value|2
end_define

begin_comment
comment|/* local memory ecc error */
end_comment

begin_comment
comment|/* Defines for flags */
end_comment

begin_define
define|#
directive|define
name|MP_PROGRESS
value|1
end_define

begin_comment
comment|/* Open or Close is in progress */
end_comment

begin_define
define|#
directive|define
name|MP_PORTUP
value|2
end_define

begin_comment
comment|/* link is up for port */
end_comment

begin_define
define|#
directive|define
name|MP_REMBSY
value|4
end_define

begin_comment
comment|/* remote station busy */
end_comment

begin_comment
comment|/*  * Asynchronous Terminal Protocol Definitions.  */
end_comment

begin_define
define|#
directive|define
name|A_RCVTIM
value|2
end_define

begin_comment
comment|/* default max tix for receive event (~20ms) */
end_comment

begin_define
define|#
directive|define
name|ACPTMR
value|300
end_define

begin_comment
comment|/* approx. 5 secs to wait for acap     */
end_comment

begin_define
define|#
directive|define
name|A_MAXEVTP
value|3
end_define

begin_comment
comment|/* maximum # of L1 or Host Events to    */
end_comment

begin_comment
comment|/* process per port at one time	 */
end_comment

begin_define
define|#
directive|define
name|A_MAXRCV
value|128
end_define

begin_comment
comment|/* max # of chars in rcv event - enough */
end_comment

begin_comment
comment|/* to hold 20ms of chars at 19.2KB      */
end_comment

begin_define
define|#
directive|define
name|A_NUMRCV
value|32
end_define

begin_comment
comment|/* number of rcv buffers per port       */
end_comment

begin_define
define|#
directive|define
name|A_NUMXMT
value|2
end_define

begin_comment
comment|/* max number of concurrent xmits/port  */
end_comment

begin_define
define|#
directive|define
name|A_NUMEVT
value|32
end_define

begin_comment
comment|/* number of evt bufs for status evts   */
end_comment

begin_comment
comment|/* and L2 to L1 transmit evts	   */
end_comment

begin_define
define|#
directive|define
name|WR5
value|5
end_define

begin_comment
comment|/* SCC Write Reg 5		      */
end_comment

begin_define
define|#
directive|define
name|TXENBL
value|0x08
end_define

begin_comment
comment|/* mask to enable transmitter in WR 5   */
end_comment

begin_define
define|#
directive|define
name|RTSON
value|0x02
end_define

begin_comment
comment|/* mask to turn on RTS in wreg 5	*/
end_comment

begin_define
define|#
directive|define
name|CHR5MSK
value|0x1F
end_define

begin_comment
comment|/* mask for 5-bit transmit data	 */
end_comment

begin_comment
comment|/*  * macro to adjust a circular buffer ptr  *      x  = pointer or index  *      sz = size of circular buffer  */
end_comment

begin_define
define|#
directive|define
name|adjptr
parameter_list|(
name|x
parameter_list|,
name|sz
parameter_list|)
value|((x) = ((++(x) == (sz)) ? 0 : (x)))
end_define

begin_define
define|#
directive|define
name|adjptrbk
parameter_list|(
name|x
parameter_list|,
name|sz
parameter_list|)
value|((x) = ((x) == 0) ? (sz) : --(x))
end_define

begin_comment
comment|/*  * Events from ASYNC Level 1 to Level 2  */
end_comment

begin_define
define|#
directive|define
name|RCVDTA
value|10
end_define

begin_comment
comment|/* normal receive data available */
end_comment

begin_define
define|#
directive|define
name|PARERR
value|11
end_define

begin_comment
comment|/* receive data with parity error */
end_comment

begin_define
define|#
directive|define
name|OVRNERR
value|12
end_define

begin_comment
comment|/* receive data with overrun error */
end_comment

begin_define
define|#
directive|define
name|OVFERR
value|13
end_define

begin_comment
comment|/* receive data with overflow error */
end_comment

begin_define
define|#
directive|define
name|FRAMERR
value|14
end_define

begin_comment
comment|/* receive data with framing error */
end_comment

begin_define
define|#
directive|define
name|ACKXMT
value|15
end_define

begin_comment
comment|/* successful completion of transmit */
end_comment

begin_define
define|#
directive|define
name|NORBUF
value|16
end_define

begin_comment
comment|/* No Receive Buffers available	 */
end_comment

begin_define
define|#
directive|define
name|NOEBUF
value|17
end_define

begin_comment
comment|/* No Event Buffers available */
end_comment

begin_define
define|#
directive|define
name|BRKASRT
value|18
end_define

begin_comment
comment|/* Break condition detected */
end_comment

begin_comment
comment|/* defines for error conditions */
end_comment

begin_define
define|#
directive|define
name|A_OK
value|0
end_define

begin_comment
comment|/* No Errors */
end_comment

begin_define
define|#
directive|define
name|A_INVEVT
value|1
end_define

begin_comment
comment|/* Invalid Event Error */
end_comment

begin_define
define|#
directive|define
name|A_IOCERR
value|2
end_define

begin_comment
comment|/* Error while configuring port */
end_comment

begin_define
define|#
directive|define
name|A_SIZERR
value|3
end_define

begin_comment
comment|/* Error in count of data chars to xmt */
end_comment

begin_define
define|#
directive|define
name|A_NXBERR
value|4
end_define

begin_comment
comment|/* Transmit Incomplete due to lack of bufs */
end_comment

begin_comment
comment|/*  * Modem control signal control structure.  */
end_comment

begin_struct
struct|struct
name|mdmctl
block|{
name|u_char
name|mc_rngdsr
decl_stmt|;
comment|/* ring or dsr */
name|u_char
name|mc_rts
decl_stmt|;
comment|/* request to send */
name|u_char
name|mc_rate
decl_stmt|;
name|u_char
name|mc_dcd
decl_stmt|;
comment|/* data carrier detect */
name|u_char
name|mc_sectx
decl_stmt|;
comment|/* secondary transmit */
name|u_char
name|mc_cts
decl_stmt|;
comment|/* clear to send */
name|u_char
name|mc_secrx
decl_stmt|;
comment|/* secondary receive */
name|u_char
name|mc_dtr
decl_stmt|;
comment|/* data terminal ready */
block|}
struct|;
end_struct

begin_comment
comment|/* defines for modem control lines */
end_comment

begin_define
define|#
directive|define
name|ASSERT
value|1
end_define

begin_comment
comment|/* line asserted */
end_comment

begin_define
define|#
directive|define
name|DROP
value|2
end_define

begin_comment
comment|/* line dropped */
end_comment

begin_define
define|#
directive|define
name|AUTO
value|3
end_define

begin_comment
comment|/* auto mode enabled, rts only */
end_comment

begin_comment
comment|/*  * Async parameter structure.  */
end_comment

begin_struct
struct|struct
name|asyncparam
block|{
name|u_char
name|ap_xon
decl_stmt|,
name|ap_xoff
decl_stmt|;
comment|/* xon-xoff characters */
name|u_char
name|ap_xena
decl_stmt|;
comment|/* xon/xoff enabled */
name|u_char
name|ap_xany
decl_stmt|;
comment|/* any received char enables xmitter */
name|struct
name|mdmctl
name|ap_modem
decl_stmt|;
comment|/* port modem control lines */
name|struct
name|mdmctl
name|ap_intena
decl_stmt|;
comment|/* modem signals which generate */
comment|/* status change events */
name|u_char
name|ap_data
decl_stmt|;
comment|/* number of data bits */
name|u_char
name|ap_stop
decl_stmt|;
comment|/* number of stop bits */
name|u_char
name|ap_baud
decl_stmt|;
comment|/* baud rate */
name|u_char
name|ap_parity
decl_stmt|;
comment|/* even/odd/no parity */
name|u_char
name|ap_loop
decl_stmt|;
comment|/* enable for local loopback */
name|u_char
name|ap_rtimer
decl_stmt|;
comment|/* receive timer value (msec) */
name|short
name|ap_fill
decl_stmt|;
comment|/* round to longword */
block|}
struct|;
end_struct

begin_comment
comment|/* enable/disable signal codes */
end_comment

begin_define
define|#
directive|define
name|MPA_ENA
value|1
end_define

begin_comment
comment|/* condition enabled */
end_comment

begin_define
define|#
directive|define
name|MPA_DIS
value|2
end_define

begin_comment
comment|/* condition disabled */
end_comment

begin_comment
comment|/* defines for ap_data */
end_comment

begin_define
define|#
directive|define
name|MPCHAR_5
value|0
end_define

begin_comment
comment|/* 5 bits per character */
end_comment

begin_define
define|#
directive|define
name|MPCHAR_6
value|2
end_define

begin_comment
comment|/* 6 bits per character */
end_comment

begin_define
define|#
directive|define
name|MPCHAR_7
value|1
end_define

begin_comment
comment|/* 7 bits per character */
end_comment

begin_define
define|#
directive|define
name|MPCHAR_8
value|3
end_define

begin_comment
comment|/* 8 bits per character */
end_comment

begin_comment
comment|/* defines for ap_stop */
end_comment

begin_define
define|#
directive|define
name|MPSTOP_1
value|1
end_define

begin_comment
comment|/* 1 stop bit per character */
end_comment

begin_define
define|#
directive|define
name|MPSTOP_1_5
value|2
end_define

begin_comment
comment|/* 1 1/2 stop bits per character */
end_comment

begin_define
define|#
directive|define
name|MPSTOP_2
value|3
end_define

begin_comment
comment|/* 2 stop bits per character */
end_comment

begin_comment
comment|/* defines for ap_baud */
end_comment

begin_define
define|#
directive|define
name|MODEM
value|0
end_define

begin_define
define|#
directive|define
name|M0
value|0
end_define

begin_comment
comment|/* baud rate = 0 */
end_comment

begin_define
define|#
directive|define
name|M50
value|1
end_define

begin_comment
comment|/* baud rate = 50 */
end_comment

begin_define
define|#
directive|define
name|M75
value|2
end_define

begin_comment
comment|/* baud rate = 75 */
end_comment

begin_define
define|#
directive|define
name|M110
value|3
end_define

begin_comment
comment|/* baud rate = 110 */
end_comment

begin_define
define|#
directive|define
name|M134_5
value|4
end_define

begin_comment
comment|/* baud rate = 134.5 */
end_comment

begin_define
define|#
directive|define
name|M150
value|5
end_define

begin_comment
comment|/* baud rate = 150 */
end_comment

begin_define
define|#
directive|define
name|M200
value|6
end_define

begin_comment
comment|/* baud rate = 200 */
end_comment

begin_define
define|#
directive|define
name|M300
value|7
end_define

begin_comment
comment|/* baud rate = 300 */
end_comment

begin_define
define|#
directive|define
name|M600
value|8
end_define

begin_comment
comment|/* baud rate = 600 */
end_comment

begin_define
define|#
directive|define
name|M1200
value|9
end_define

begin_comment
comment|/* baud rate = 1200 */
end_comment

begin_define
define|#
directive|define
name|M1800
value|10
end_define

begin_comment
comment|/* baud rate = 1800 */
end_comment

begin_define
define|#
directive|define
name|M2400
value|11
end_define

begin_comment
comment|/* baud rate = 2400 */
end_comment

begin_define
define|#
directive|define
name|M4800
value|12
end_define

begin_comment
comment|/* baud rate = 4800 */
end_comment

begin_define
define|#
directive|define
name|M9600
value|13
end_define

begin_comment
comment|/* baud rate = 9600 */
end_comment

begin_define
define|#
directive|define
name|MEXTA
value|14
end_define

begin_comment
comment|/* baud rate = Ext A */
end_comment

begin_define
define|#
directive|define
name|MEXTB
value|15
end_define

begin_comment
comment|/* baud rate = Ext B */
end_comment

begin_define
define|#
directive|define
name|M2000
value|16
end_define

begin_comment
comment|/* baud rate = 2000 */
end_comment

begin_define
define|#
directive|define
name|M3600
value|17
end_define

begin_comment
comment|/* baud rate = 3600 */
end_comment

begin_define
define|#
directive|define
name|M7200
value|18
end_define

begin_comment
comment|/* baud rate = 7200 */
end_comment

begin_define
define|#
directive|define
name|M19200
value|19
end_define

begin_comment
comment|/* baud rate = 19,200 */
end_comment

begin_define
define|#
directive|define
name|M24000
value|20
end_define

begin_comment
comment|/* baud rate = 24,000 */
end_comment

begin_define
define|#
directive|define
name|M28400
value|21
end_define

begin_comment
comment|/* baud rate = 28,400 */
end_comment

begin_define
define|#
directive|define
name|M37800
value|22
end_define

begin_comment
comment|/* baud rate = 37,800 */
end_comment

begin_define
define|#
directive|define
name|M40300
value|23
end_define

begin_comment
comment|/* baud rate = 40,300 */
end_comment

begin_define
define|#
directive|define
name|M48000
value|24
end_define

begin_comment
comment|/* baud rate = 48,000 */
end_comment

begin_define
define|#
directive|define
name|M52000
value|25
end_define

begin_comment
comment|/* baud rate = 52,000 */
end_comment

begin_define
define|#
directive|define
name|M56800
value|26
end_define

begin_comment
comment|/* baud rate = 56,800 */
end_comment

begin_comment
comment|/* defines for ap_parity */
end_comment

begin_define
define|#
directive|define
name|MPPAR_NONE
value|0
end_define

begin_comment
comment|/* no parity */
end_comment

begin_define
define|#
directive|define
name|MPPAR_ODD
value|1
end_define

begin_comment
comment|/* odd parity */
end_comment

begin_define
define|#
directive|define
name|MPPAR_EVEN
value|3
end_define

begin_comment
comment|/* even parity */
end_comment

begin_comment
comment|/* possible flags for Host MP_IOCTL Events */
end_comment

begin_define
define|#
directive|define
name|A_CHGX
value|1
end_define

begin_comment
comment|/* IOCTL is only chging xonxoff params */
end_comment

begin_define
define|#
directive|define
name|A_MDMCHG
value|2
end_define

begin_comment
comment|/* change modem control lines */
end_comment

begin_define
define|#
directive|define
name|A_MDMGET
value|3
end_define

begin_comment
comment|/* get current state of modem ctl lines */
end_comment

begin_define
define|#
directive|define
name|A_CHGL1P
value|4
end_define

begin_comment
comment|/* IOCTL is changing changing L1 params */
end_comment

begin_define
define|#
directive|define
name|A_BRKON
value|5
end_define

begin_comment
comment|/* set port break bit */
end_comment

begin_define
define|#
directive|define
name|A_BRKOFF
value|6
end_define

begin_comment
comment|/* clear port break bit */
end_comment

begin_define
define|#
directive|define
name|A_CHGALL
value|7
end_define

begin_comment
comment|/* IOCTL is changing xonxoff params, */
end_comment

begin_comment
comment|/* pcnfg struct,& modem ctl structs */
end_comment

begin_define
define|#
directive|define
name|A_DISABX
value|8
end_define

begin_comment
comment|/* disable port transmitter (ctl-s) */
end_comment

begin_define
define|#
directive|define
name|A_ENABLX
value|9
end_define

begin_comment
comment|/* enable port transmitter (ctl-q) */
end_comment

begin_comment
comment|/* possible flags for Host MP_WRITE Events */
end_comment

begin_define
define|#
directive|define
name|A_FLUSH
value|1
end_define

begin_comment
comment|/* flush any queued transmit events */
end_comment

begin_define
define|#
directive|define
name|A_SSTOP
value|2
end_define

begin_comment
comment|/* transmit a port stop (xoff) char */
end_comment

begin_comment
comment|/* before sending rest of event xmts */
end_comment

begin_define
define|#
directive|define
name|A_SSTART
value|3
end_define

begin_comment
comment|/* transmit a port start (xon) char */
end_comment

begin_comment
comment|/* before sending rest of event xmts */
end_comment

begin_comment
comment|/* possible flags for Outbound MP_READ Events */
end_comment

begin_define
define|#
directive|define
name|A_XOFF
value|1
end_define

begin_comment
comment|/* transmitter stopped from by xoff char */
end_comment

begin_comment
comment|/* Perpos flags for modem control fields */
end_comment

begin_define
define|#
directive|define
name|A_RNGDSR
value|00001
end_define

begin_define
define|#
directive|define
name|A_RTS
value|00002
end_define

begin_define
define|#
directive|define
name|A_RATE
value|00004
end_define

begin_define
define|#
directive|define
name|A_DCD
value|00010
end_define

begin_define
define|#
directive|define
name|A_SECTX
value|00020
end_define

begin_define
define|#
directive|define
name|A_CTS
value|00040
end_define

begin_define
define|#
directive|define
name|A_SECRX
value|00100
end_define

begin_define
define|#
directive|define
name|A_DTR
value|00200
end_define

begin_comment
comment|/* error messages printed at console , board& port # filled in later */
end_comment

begin_define
define|#
directive|define
name|A_INVSTS
value|"\n#### Invalid Status Event "
end_define

begin_define
define|#
directive|define
name|A_INVCMD
value|"\n#### Invalid Event From the MPCC "
end_define

begin_define
define|#
directive|define
name|A_NORBUF
value|"\n#### No More Available Receive Buffers "
end_define

begin_define
define|#
directive|define
name|A_NOEBUF
value|"\n#### No More Available Event Buffers "
end_define

begin_define
define|#
directive|define
name|A_OVRN
value|"\n#### Overrun Error Detected "
end_define

begin_define
define|#
directive|define
name|A_OVRF
value|"\n#### Overflow Error Detected "
end_define

begin_define
define|#
directive|define
name|A_NOXBUF
value|"\n#### No More Available Transmit Event Buffers "
end_define

begin_define
define|#
directive|define
name|A_XSIZE
value|"\n#### Transmit Data Block Size Exceeds Event Data Buffer Size "
end_define

begin_define
define|#
directive|define
name|A_NOFREIN
value|"\n#### No Available Inbound Entries to Send Close Event "
end_define

begin_define
define|#
directive|define
name|DCDASRT
value|100
end_define

begin_comment
comment|/* data carrier detect asserted */
end_comment

begin_define
define|#
directive|define
name|DTRASRT
value|101
end_define

begin_comment
comment|/* data terminal ready asserted */
end_comment

begin_define
define|#
directive|define
name|RNGASRT
value|102
end_define

begin_comment
comment|/* ring indicator asserted */
end_comment

begin_define
define|#
directive|define
name|DSRASRT
value|102
end_define

begin_comment
comment|/* data set ready asserted */
end_comment

begin_define
define|#
directive|define
name|CTSASRT
value|103
end_define

begin_comment
comment|/* clear to send asserted */
end_comment

begin_define
define|#
directive|define
name|RTSASRT
value|104
end_define

begin_comment
comment|/* ready to send asserted */
end_comment

begin_define
define|#
directive|define
name|STXASRT
value|105
end_define

begin_comment
comment|/* secondary transmit asserted */
end_comment

begin_define
define|#
directive|define
name|SRXASRT
value|106
end_define

begin_comment
comment|/* secondary recieve asserted */
end_comment

begin_define
define|#
directive|define
name|RATEASRT
value|107
end_define

begin_comment
comment|/* rate signal asserted */
end_comment

begin_define
define|#
directive|define
name|DCDDROP
value|108
end_define

begin_comment
comment|/* data carrier detect dropped */
end_comment

begin_define
define|#
directive|define
name|DTRDROP
value|109
end_define

begin_comment
comment|/* data terminal ready dropped */
end_comment

begin_define
define|#
directive|define
name|RNGDROP
value|110
end_define

begin_comment
comment|/* ring indicator dropped */
end_comment

begin_define
define|#
directive|define
name|MPDSRDROP
value|110
end_define

begin_comment
comment|/* data set ready dropped */
end_comment

begin_define
define|#
directive|define
name|CTSDROP
value|111
end_define

begin_comment
comment|/* clear to send dropped */
end_comment

begin_define
define|#
directive|define
name|RTSDROP
value|112
end_define

begin_comment
comment|/* ready to send dropped */
end_comment

begin_define
define|#
directive|define
name|STXDROP
value|113
end_define

begin_comment
comment|/* secondary transmit dropped */
end_comment

begin_define
define|#
directive|define
name|SRXDROP
value|114
end_define

begin_comment
comment|/* secondary recieve dropped */
end_comment

begin_define
define|#
directive|define
name|RATEDROP
value|115
end_define

begin_comment
comment|/* rate signal dropped */
end_comment

begin_comment
comment|/* Defines for filters and intena in portstat */
end_comment

begin_define
define|#
directive|define
name|MDM_OFF
value|0
end_define

begin_define
define|#
directive|define
name|MDM_ON
value|1
end_define

begin_comment
comment|/* Modem on/off flags */
end_comment

begin_define
define|#
directive|define
name|MMOD_OFF
value|0
end_define

begin_define
define|#
directive|define
name|MMOD_ON
value|1
end_define

begin_comment
comment|/* defintions for DL interface */
end_comment

begin_define
define|#
directive|define
name|MPDLBUFSIZE
value|1024
end_define

begin_comment
comment|/*      mpdlioctl command defines       */
end_comment

begin_struct
struct|struct
name|protports
block|{
name|char
name|protoport
index|[
name|MPMAXPORT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|abdcf
block|{
name|short
name|xmtbsz
decl_stmt|;
comment|/* transmit buffer size - should */
comment|/* equal # of chars in a cblock  */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bdcf
block|{
name|char
name|loadname
index|[
name|NMPPROTO
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|protoports
index|[
name|MPMAXPORT
index|]
decl_stmt|;
name|char
name|fccstimer
decl_stmt|;
comment|/* powerfail timer */
name|char
name|fccsports
decl_stmt|;
comment|/* ports to affect */
name|char
name|fccssoc
decl_stmt|;
comment|/* ports which will 'switch on close' */
block|}
struct|;
end_struct

begin_comment
comment|/* These ioctls are for the dlmpcc command */
end_comment

begin_define
define|#
directive|define
name|MPIOPORTMAP
value|_IOW('m',1, struct protports)
end_define

begin_define
define|#
directive|define
name|MPIOHILO
value|_IOW('m',3, short)
end_define

begin_define
define|#
directive|define
name|MPIOENDCODE
value|_IO('m',4)
end_define

begin_define
define|#
directive|define
name|MPIOASYNCNF
value|_IOW('m',7, struct abdcf)
end_define

begin_define
define|#
directive|define
name|MPIOENDDL
value|_IO('m',10)
end_define

begin_define
define|#
directive|define
name|MPIOSTARTDL
value|_IO('m',11)
end_define

begin_define
define|#
directive|define
name|MPIORESETBOARD
value|_IO('m',12)
end_define

begin_comment
comment|/*      mpdlwrite opcode defines        */
end_comment

begin_define
define|#
directive|define
name|MPDLCMD_NORMAL
value|1
end_define

end_unit

