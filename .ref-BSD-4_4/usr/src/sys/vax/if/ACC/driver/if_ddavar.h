begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************/
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	 ________________________________________________________	 */
end_comment

begin_comment
comment|/*	/							 \	 */
end_comment

begin_comment
comment|/*     |	  AAA	       CCCCCCCCCCCCCC	 CCCCCCCCCCCCCC	  |	 */
end_comment

begin_comment
comment|/*     |	 AAAAA	      CCCCCCCCCCCCCCCC	CCCCCCCCCCCCCCCC  |	 */
end_comment

begin_comment
comment|/*     |	AAAAAAA	      CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |	 */
end_comment

begin_comment
comment|/*     |       AAAA AAAA      CCCC		CCCC		  |	 */
end_comment

begin_comment
comment|/*     |      AAAA   AAAA     CCCC		CCCC		  |	 */
end_comment

begin_comment
comment|/*     |     AAAA     AAAA    CCCC		CCCC		  |	 */
end_comment

begin_comment
comment|/*     |    AAAA       AAAA   CCCC		CCCC		  |	 */
end_comment

begin_comment
comment|/*     |   AAAA	 AAAAAAAAAAA  CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |	 */
end_comment

begin_comment
comment|/*     |  AAAA	  AAAAAAAAAAA CCCCCCCCCCCCCCCC	CCCCCCCCCCCCCCCC  |	 */
end_comment

begin_comment
comment|/*     | AAAA	   AAAAAAAAA   CCCCCCCCCCCCCC	 CCCCCCCCCCCCCC	  |	 */
end_comment

begin_comment
comment|/*	\________________________________________________________/	 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	Copyright (c) 1986 by Advanced Computer Communications		 */
end_comment

begin_comment
comment|/*	720 Santa Barbara Street, Santa Barbara, California  93101	 */
end_comment

begin_comment
comment|/*	(805) 963-9431							 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  File:		ddavar.h					 */
end_comment

begin_comment
comment|/*			When this file is copied to the /sys/vaxif	 */
end_comment

begin_comment
comment|/*			directory, it is renamed 'if_ddavar.h'.		 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Project:		UNIX 4.n BSD DDA-X.25 Network Interface Driver	 */
end_comment

begin_comment
comment|/*			for ACP 5250 and ACP 6250			 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Function:		This file contains definitions used to control	 */
end_comment

begin_comment
comment|/*			and track the status of the ACP 5250/6250.	 */
end_comment

begin_comment
comment|/*			The values for the Set System Parameter Messages */
end_comment

begin_comment
comment|/*			are located here.  Note that the values are the	 */
end_comment

begin_comment
comment|/*			same as those for ACP 625 for compatibility.	 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Revision History at end of file					 */
end_comment

begin_comment
comment|/*************************************************************************/
end_comment

begin_escape
end_escape

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DDA_PADOPT
argument_list|)
operator|||
name|defined
argument_list|(
name|DDA_RAWOPT
argument_list|)
end_if

begin_define
define|#
directive|define
name|DDA_PAD_OR_RAW
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NDDACH
value|126
end_define

begin_comment
comment|/* maximum number of channels */
end_comment

begin_define
define|#
directive|define
name|NDDACH_DEFAULT
value|64
end_define

begin_comment
comment|/* default number of channels */
end_comment

begin_comment
comment|/* path numbers (also called logical channel numbers, or lcns) */
end_comment

begin_define
define|#
directive|define
name|DDA_SUPR
value|0x00
end_define

begin_comment
comment|/* supervisory path for control */
end_comment

begin_define
define|#
directive|define
name|ALL_CHANS
value|0xff
end_define

begin_comment
comment|/* denotes all LCNs */
end_comment

begin_comment
comment|/* the following 2 defines (MAXADDRLEN and MINADDRLEN) give the max and min  * length X25 addresses.  These numbers include 1 byte to hold the length  * of the address.  Thus the normal value of MAXADDRLEN is 15, for 14-digit  * X.25 addresses; MAXADDRLEN can never be greater than 16 (15-digit addr).  */
end_comment

begin_define
define|#
directive|define
name|MAXADDRLEN
value|16
end_define

begin_comment
comment|/* max length of an X.25 address */
end_comment

begin_define
define|#
directive|define
name|MINADDRLEN
value|1
end_define

begin_comment
comment|/* min length of an X.25 address */
end_comment

begin_define
define|#
directive|define
name|TRANSPAC
value|1
end_define

begin_comment
comment|/* network type for TRANSPAC (def=0) */
end_comment

begin_define
define|#
directive|define
name|DDAMTU
value|1006
end_define

begin_comment
comment|/* maximum IP msg length */
end_comment

begin_define
define|#
directive|define
name|DDA_OQMAX
value|8
end_define

begin_comment
comment|/* max IP msgs on LCN output q */
end_comment

begin_define
define|#
directive|define
name|DDA_TIMEOUT
value|10
end_define

begin_comment
comment|/* dda timer interval, in seconds */
end_comment

begin_comment
comment|/* definitions for the DC_FLAGS byte of the dda_cb structure */
end_comment

begin_comment
comment|/* bits in dc_flags */
end_comment

begin_define
define|#
directive|define
name|DC_OBUSY
value|0x01
end_define

begin_define
define|#
directive|define
name|DC_CLIENTS
value|0x0e
end_define

begin_define
define|#
directive|define
name|DC_IP
value|0x00
end_define

begin_comment
comment|/* this channel is being used for IP traffic */
end_comment

begin_define
define|#
directive|define
name|DC_X29
value|0x02
end_define

begin_comment
comment|/* this channel is being used for X29 traffic */
end_comment

begin_define
define|#
directive|define
name|DC_X29W
value|0x04
end_define

begin_comment
comment|/* this channel waiting for x29 connection */
end_comment

begin_define
define|#
directive|define
name|DC_RAW
value|0x08
end_define

begin_comment
comment|/* this is a raw X25 channel */
end_comment

begin_define
define|#
directive|define
name|DC_IPEND
value|0x10
end_define

begin_comment
comment|/* input pending */
end_comment

begin_comment
comment|/* bits in hc_sbfc (which is the wrong place) */
end_comment

begin_define
define|#
directive|define
name|INVALID_MBUF
value|0x01
end_define

begin_comment
comment|/* Used to clear outstanding I/O */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|byte
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|boolean
typedef|;
end_typedef

begin_comment
comment|/* X25 LCN state definitions (in dc_state) */
end_comment

begin_define
define|#
directive|define
name|LC_DOWN
value|0
end_define

begin_comment
comment|/* X25 circuit down		*/
end_comment

begin_define
define|#
directive|define
name|LC_RESTART
value|1
end_define

begin_comment
comment|/* X25 circuit restarting	*/
end_comment

begin_define
define|#
directive|define
name|LC_IDLE
value|2
end_define

begin_comment
comment|/* X25 circuit not in use	*/
end_comment

begin_define
define|#
directive|define
name|LC_CALL_PENDING
value|3
end_define

begin_comment
comment|/* X25 circuit call pending	*/
end_comment

begin_define
define|#
directive|define
name|LC_DATA_IDLE
value|4
end_define

begin_comment
comment|/* X25 circuit open		*/
end_comment

begin_define
define|#
directive|define
name|LC_CLR_PENDING
value|5
end_define

begin_comment
comment|/* X25 circuit clear pending	*/
end_comment

begin_comment
comment|/* Timeout definitions (in dc_timer and dc_out_t) */
end_comment

begin_define
define|#
directive|define
name|TMO_OFF
value|0
end_define

begin_comment
comment|/* timer off		*/
end_comment

begin_define
define|#
directive|define
name|TMO_RESTART
value|( 90/DDA_TIMEOUT)
end_define

begin_comment
comment|/* restart timeout	*/
end_comment

begin_define
define|#
directive|define
name|TMO_CALL_PENDING
value|(180/DDA_TIMEOUT)
end_define

begin_comment
comment|/* call timeout		*/
end_comment

begin_define
define|#
directive|define
name|TMO_DATA_IDLE
value|(600/DDA_TIMEOUT)
end_define

begin_comment
comment|/* idle circuit timeout */
end_comment

begin_define
define|#
directive|define
name|TMO_CLR_PENDING
value|(380/DDA_TIMEOUT)
end_define

begin_comment
comment|/* clear timeout	*/
end_comment

begin_comment
comment|/* Link status codes (third byte of LINE_STATUS message) */
end_comment

begin_define
define|#
directive|define
name|LINK_DOWN
value|0x00
end_define

begin_comment
comment|/* Link layer is down		*/
end_comment

begin_define
define|#
directive|define
name|LINK_UP
value|0x01
end_define

begin_comment
comment|/* Link layer is up		*/
end_comment

begin_define
define|#
directive|define
name|LINK_DISABLED
value|0x02
end_define

begin_comment
comment|/* Link layer is disabled	*/
end_comment

begin_comment
comment|/* The following parameter modification commands such as BAUD_CNTL,  */
end_comment

begin_comment
comment|/* or WATCHDOG, are one-byte values containing size and ID followed  */
end_comment

begin_comment
comment|/* by 0-2 bytes of parameter information.  The number of bytes of    */
end_comment

begin_comment
comment|/* parameter information is specified in the most significant 2 bits */
end_comment

begin_comment
comment|/* of the command, the other 6 bits are the ID.	 A 00, 01, or 10     */
end_comment

begin_comment
comment|/* specify respectively 0, 1, or 2 bytes of parameter information    */
end_comment

begin_comment
comment|/* follow.							     */
end_comment

begin_comment
comment|/* Line control codes (in body of LINE_CNTL message) */
end_comment

begin_define
define|#
directive|define
name|LINK_DISABLE
value|0x00
end_define

begin_comment
comment|/* Disable link layer		*/
end_comment

begin_define
define|#
directive|define
name|LINK_ENABLE
value|0x01
end_define

begin_comment
comment|/* Enable link layer		*/
end_comment

begin_define
define|#
directive|define
name|LINK_LOOPBACK
value|0x42
end_define

begin_comment
comment|/* Link layer loopback mode	*/
end_comment

begin_define
define|#
directive|define
name|LOOP_NONE
value|0x00
end_define

begin_comment
comment|/*   Loopback off		*/
end_comment

begin_define
define|#
directive|define
name|LOOP_EXTERNAL
value|0x01
end_define

begin_comment
comment|/*   Loopback external		*/
end_comment

begin_define
define|#
directive|define
name|LOOP_INTERNAL
value|0x03
end_define

begin_comment
comment|/*   Loopback internal		*/
end_comment

begin_define
define|#
directive|define
name|DTE_DCE_MODE
value|0x43
end_define

begin_comment
comment|/* DTE/DCE Mode Parameter	*/
end_comment

begin_define
define|#
directive|define
name|DTE
value|0x00
end_define

begin_comment
comment|/*   operate as DTE		*/
end_comment

begin_define
define|#
directive|define
name|DCE
value|0x01
end_define

begin_comment
comment|/*   operate as DCE		*/
end_comment

begin_define
define|#
directive|define
name|DTE_ADDRESS
value|0x44
end_define

begin_comment
comment|/* DTE Address Parameter	*/
end_comment

begin_define
define|#
directive|define
name|DTE_ADRVAL
value|0x03
end_define

begin_comment
comment|/*   DTE Address value		*/
end_comment

begin_define
define|#
directive|define
name|DCE_ADDRESS
value|0x45
end_define

begin_comment
comment|/* DCE Address Parameter	*/
end_comment

begin_define
define|#
directive|define
name|DCE_ADRVAL
value|0x01
end_define

begin_comment
comment|/*   DCE Address value		*/
end_comment

begin_define
define|#
directive|define
name|IFRAME_TIMEO
value|0x46
end_define

begin_comment
comment|/* I-Frame Timeout Parameter	*/
end_comment

begin_define
define|#
directive|define
name|IFRAME_TOVAL
value|0x03
end_define

begin_comment
comment|/*   I-Frame Timeout value 3s	*/
end_comment

begin_define
define|#
directive|define
name|POLL_TIMEO
value|0x47
end_define

begin_comment
comment|/* Poll Timeout Parameter	*/
end_comment

begin_define
define|#
directive|define
name|POLL_TOVAL
value|0x03
end_define

begin_comment
comment|/*   Poll Timeout value 3s	*/
end_comment

begin_define
define|#
directive|define
name|ADM_TIMEO
value|0x48
end_define

begin_comment
comment|/* ADM Timeout Parameter	*/
end_comment

begin_define
define|#
directive|define
name|ADM_TOVAL
value|0x03
end_define

begin_comment
comment|/*   ADM Timeout value 3s	*/
end_comment

begin_define
define|#
directive|define
name|RETRY_LIMIT
value|0x4a
end_define

begin_comment
comment|/* Retry Limit Parameter	*/
end_comment

begin_define
define|#
directive|define
name|RETRY_VAL
value|0x14
end_define

begin_comment
comment|/*   20 (decimal) retries	*/
end_comment

begin_define
define|#
directive|define
name|WATCHDOG
value|0x4b
end_define

begin_comment
comment|/* Watchdog Timeout Parameter	*/
end_comment

begin_define
define|#
directive|define
name|WATCHDG_VAL
value|0x03
end_define

begin_comment
comment|/*   Watchdog Timeout value 3s	*/
end_comment

begin_define
define|#
directive|define
name|BAUD_CNTL
value|0xa9
end_define

begin_comment
comment|/* Baud Rate Parameter		*/
end_comment

begin_define
define|#
directive|define
name|CLOCK_CNTL
value|0x6a
end_define

begin_comment
comment|/* Select Clock Source		*/
end_comment

begin_define
define|#
directive|define
name|EXTERNAL_CLOCK
value|0x00
end_define

begin_comment
comment|/* clock generated externally	*/
end_comment

begin_define
define|#
directive|define
name|INTERNAL_CLOCK
value|0x01
end_define

begin_comment
comment|/* clock generated internally	*/
end_comment

begin_define
define|#
directive|define
name|IDLE_POLL
value|0x4d
end_define

begin_comment
comment|/* Idle Poll Parameter		*/
end_comment

begin_define
define|#
directive|define
name|IDLE_POLL_ON
value|0x01
end_define

begin_comment
comment|/*   Idle Polling on		*/
end_comment

begin_define
define|#
directive|define
name|IDLE_POLL_OFF
value|0x00
end_define

begin_comment
comment|/*   Idle Polling off		*/
end_comment

begin_define
define|#
directive|define
name|FRAME_WINDOW
value|0x4e
end_define

begin_comment
comment|/* Frame Window Parameter	*/
end_comment

begin_define
define|#
directive|define
name|FWINDW_VAL
value|0x07
end_define

begin_comment
comment|/*   Frame Window value 7	*/
end_comment

begin_define
define|#
directive|define
name|PKT_WINDOW
value|0x4f
end_define

begin_comment
comment|/* Packet Window Parameter	*/
end_comment

begin_define
define|#
directive|define
name|PWINDW_VAL
value|0x02
end_define

begin_comment
comment|/*   Packet Window value 2	*/
end_comment

begin_define
define|#
directive|define
name|PKT_SIZE
value|0x90
end_define

begin_comment
comment|/* Packet Size Parameter	*/
end_comment

begin_define
define|#
directive|define
name|PVAL_BYTE1
value|0x08
end_define

begin_comment
comment|/*   least significant byte	*/
end_comment

begin_define
define|#
directive|define
name|PVAL_BYTE2
value|0x00
end_define

begin_comment
comment|/*   most significant byte	*/
end_comment

begin_define
define|#
directive|define
name|MAX_PKT_SZ
value|0xbe
end_define

begin_comment
comment|/* Max Packet Size		*/
end_comment

begin_define
define|#
directive|define
name|MAX_PKT_WN
value|0x7c
end_define

begin_comment
comment|/* Max Packet Window Size	*/
end_comment

begin_define
define|#
directive|define
name|PKT_OPTIONS
value|0x77
end_define

begin_comment
comment|/* Supported 1984 options	*/
end_comment

begin_define
define|#
directive|define
name|HIGH_THRESH
value|0x51
end_define

begin_comment
comment|/* High Buffer Threshold Param	*/
end_comment

begin_define
define|#
directive|define
name|HTRSH_VAL
value|0x08
end_define

begin_comment
comment|/*   High Threshold value	*/
end_comment

begin_define
define|#
directive|define
name|LOW_THRESH
value|0x52
end_define

begin_comment
comment|/* Low Buffer Threshold Param	*/
end_comment

begin_define
define|#
directive|define
name|LTRSH_VAL
value|0x08
end_define

begin_comment
comment|/*   Low Threshold value	*/
end_comment

begin_define
define|#
directive|define
name|QUEUED_BUFS
value|0x53
end_define

begin_comment
comment|/* Max Number of Queued Buffers */
end_comment

begin_define
define|#
directive|define
name|QBUF_VAL
value|0x08
end_define

begin_comment
comment|/*   Queued Buffer value	*/
end_comment

begin_define
define|#
directive|define
name|QUEUED_IFRAMES
value|0x54
end_define

begin_comment
comment|/* Max Number Queued I-Frames	*/
end_comment

begin_define
define|#
directive|define
name|QIFRAME_VAL
value|0x08
end_define

begin_comment
comment|/*   Queued I-Frame value	*/
end_comment

begin_define
define|#
directive|define
name|FRAME_SIZE
value|0x95
end_define

begin_comment
comment|/* Maximum Frames Size Parametr */
end_comment

begin_define
define|#
directive|define
name|FRAME_SIZE1
value|0x95
end_define

begin_comment
comment|/*   least significant byte	*/
end_comment

begin_define
define|#
directive|define
name|FRAME_SIZE2
value|0x01
end_define

begin_comment
comment|/*   most significant byte	*/
end_comment

begin_comment
comment|/*   for value of 405 (decimal) */
end_comment

begin_define
define|#
directive|define
name|LCGN
value|0x56
end_define

begin_comment
comment|/* Logical Channel Group Number */
end_comment

begin_define
define|#
directive|define
name|LCGN_VAL
value|0x00
end_define

begin_comment
comment|/*   lcgn value			*/
end_comment

begin_define
define|#
directive|define
name|SVC_LIMIT
value|0x57
end_define

begin_comment
comment|/* Switched Virtual Circuit	*/
end_comment

begin_define
define|#
directive|define
name|SVC_VAL
value|0x20
end_define

begin_comment
comment|/*   SVC value 32 (decimal)	*/
end_comment

begin_define
define|#
directive|define
name|DDAF_OK
value|0x0001
end_define

begin_comment
comment|/* ACP operation flag		*/
end_comment

begin_define
define|#
directive|define
name|DDASTAT_OK
value|0x00
end_define

begin_comment
comment|/* ACP system status returned	*/
end_comment

begin_comment
comment|/* on interrupt "b"		*/
end_comment

begin_define
define|#
directive|define
name|DDASTAT_ERR
value|0x80
end_define

begin_define
define|#
directive|define
name|DDASTAT_NMC
value|0x7F
end_define

begin_comment
comment|/* flag values for ds->dda_init */
end_comment

begin_define
define|#
directive|define
name|INIT_OK
value|0x10
end_define

begin_comment
comment|/* ok to call x25_init()	*/
end_comment

begin_define
define|#
directive|define
name|DDA_STANDARD
value|0x01
end_define

begin_comment
comment|/* DDN standard X.25 service	*/
end_comment

begin_define
define|#
directive|define
name|DDA_BASIC
value|0x02
end_define

begin_comment
comment|/* DDN basic X.25 service	*/
end_comment

begin_define
define|#
directive|define
name|DDA_PDN
value|0x04
end_define

begin_comment
comment|/* Public Data Network X.25	*/
end_comment

begin_define
define|#
directive|define
name|DDA_INTCLOCK
value|0x08
end_define

begin_comment
comment|/* internal clocking is set	*/
end_comment

begin_define
define|#
directive|define
name|DDA_CLASS_A_B
value|0x20
end_define

begin_comment
comment|/* Standard service/table lookup */
end_comment

begin_define
define|#
directive|define
name|DDA_PKTNEG
value|0x40
end_define

begin_comment
comment|/* Packet size negotiation flag */
end_comment

begin_define
define|#
directive|define
name|DDA_WNDNEG
value|0x80
end_define

begin_comment
comment|/* Window size negotiation flag */
end_comment

begin_comment
comment|/* the following offsets are for ddainit_msg, the set systems parameters */
end_comment

begin_comment
comment|/* message								 */
end_comment

begin_define
define|#
directive|define
name|LOOP_OFFSET
value|6
end_define

begin_comment
comment|/* set system parms, loopback	  */
end_comment

begin_define
define|#
directive|define
name|DTE_OFFSET
value|8
end_define

begin_comment
comment|/* set system parms, dte/dce mode */
end_comment

begin_define
define|#
directive|define
name|BAUD_OFFSET
value|10
end_define

begin_comment
comment|/* set system parms, dte/dce mode */
end_comment

begin_define
define|#
directive|define
name|CLOCK_OFFSET
value|18
end_define

begin_comment
comment|/* set system parms, dte/dce mode */
end_comment

begin_define
define|#
directive|define
name|DOWN_OFFSET
value|19
end_define

begin_comment
comment|/* set system parms, line down	  */
end_comment

begin_define
define|#
directive|define
name|MSG_LENGTH
value|3
end_define

begin_comment
comment|/* offset for message length	  */
end_comment

begin_define
define|#
directive|define
name|MSG_OFFSET
value|4
end_define

begin_comment
comment|/* offset for start of parameters */
end_comment

begin_define
define|#
directive|define
name|MSGS_BAUD
value|3
end_define

begin_comment
comment|/* msg size for baud rate parms	  */
end_comment

begin_comment
comment|/* X25 supervisor message codes */
end_comment

begin_define
define|#
directive|define
name|CALL
value|0x00
end_define

begin_comment
comment|/* outgoing call		*/
end_comment

begin_define
define|#
directive|define
name|RING
value|0x01
end_define

begin_comment
comment|/* incoming call		*/
end_comment

begin_define
define|#
directive|define
name|CLEARVC
value|0x02
end_define

begin_comment
comment|/* clear by VCN			*/
end_comment

begin_define
define|#
directive|define
name|ANSWER
value|0x03
end_define

begin_comment
comment|/* answer call			*/
end_comment

begin_define
define|#
directive|define
name|CLEARLC
value|0x04
end_define

begin_comment
comment|/* clear by LCN			*/
end_comment

begin_define
define|#
directive|define
name|RESET
value|0x20
end_define

begin_comment
comment|/* reset LCN			*/
end_comment

begin_define
define|#
directive|define
name|RESET_ACK
value|0x21
end_define

begin_comment
comment|/* reset ack			*/
end_comment

begin_define
define|#
directive|define
name|INTERRUPT
value|0x22
end_define

begin_comment
comment|/* X25 interrupt		*/
end_comment

begin_define
define|#
directive|define
name|READY
value|0x23
end_define

begin_comment
comment|/* flow control ready		*/
end_comment

begin_define
define|#
directive|define
name|INTR_ACK
value|0x24
end_define

begin_comment
comment|/* interrupt ack		*/
end_comment

begin_define
define|#
directive|define
name|RESTART
value|0x40
end_define

begin_comment
comment|/* X25 restart			*/
end_comment

begin_define
define|#
directive|define
name|RSTRT_ACK
value|0x41
end_define

begin_comment
comment|/* restart ack			*/
end_comment

begin_define
define|#
directive|define
name|SYS_STATUS
value|0x42
end_define

begin_comment
comment|/* system status msg		*/
end_comment

begin_define
define|#
directive|define
name|LINE_CNTL
value|0x60
end_define

begin_comment
comment|/* link control cmnd		*/
end_comment

begin_define
define|#
directive|define
name|LINE_STATUS
value|0x61
end_define

begin_comment
comment|/* link status resp		*/
end_comment

begin_define
define|#
directive|define
name|SET_BFR_SIZE
value|0x62
end_define

begin_comment
comment|/* set firmware buffer size	*/
end_comment

begin_define
define|#
directive|define
name|STATQUERY
value|0217
end_define

begin_comment
comment|/* statistics query	      */
end_comment

begin_define
define|#
directive|define
name|STATRESP
value|0216
end_define

begin_comment
comment|/* statistics response	      */
end_comment

begin_comment
comment|/* X25 facilities */
end_comment

begin_define
define|#
directive|define
name|X25_FACIL_PKTSIZE
value|0x42
end_define

begin_comment
comment|/* CCITT packet size negotiation*/
end_comment

begin_define
define|#
directive|define
name|X25_FACIL_WINSIZE
value|0x43
end_define

begin_comment
comment|/* CCITT window size negotiation*/
end_comment

begin_define
define|#
directive|define
name|DDN_FACIL_MARKER
value|0
end_define

begin_comment
comment|/* two of these mark DDN private*/
end_comment

begin_define
define|#
directive|define
name|X25_FACIL_DDA
value|0x04
end_define

begin_comment
comment|/* DDA mode facility		*/
end_comment

begin_define
define|#
directive|define
name|FAC_DDASTD
value|0x01
end_define

begin_comment
comment|/*   DDA standard mode		*/
end_comment

begin_define
define|#
directive|define
name|PKTSIZE_LARGE
value|12
end_define

begin_comment
comment|/* lg2 (4096) for calls		*/
end_comment

begin_define
define|#
directive|define
name|WINSIZE_LARGE
value|7
end_define

begin_comment
comment|/* Large (7) window for calls	*/
end_comment

begin_define
define|#
directive|define
name|PKTSIZE_DEF
value|7
end_define

begin_comment
comment|/* Default packet size		*/
end_comment

begin_define
define|#
directive|define
name|WINSIZE_DEF
value|2
end_define

begin_comment
comment|/* Default window size		*/
end_comment

begin_comment
comment|/* X25 protocols */
end_comment

begin_define
define|#
directive|define
name|X25_PROTO_IP
value|0xcc
end_define

begin_comment
comment|/* X25 IP protocol type code	*/
end_comment

begin_define
define|#
directive|define
name|X25_PROTO_X29
value|0x01
end_define

begin_comment
comment|/* X29 over X25 protocol type code */
end_comment

begin_comment
comment|/* DMESG(unit,value,statement) e.g. DMESG(0,27,printf("error message")) */
end_comment

begin_comment
comment|/* v should be a constant (no side effects)				*/
end_comment

begin_comment
comment|/* (v)>> 5 == (v) / 32	 - find which word the bit is in.		*/
end_comment

begin_comment
comment|/* (v)& 0x1f == (v) % 32 - find the number of the bit to check		*/
end_comment

begin_comment
comment|/* DMESGSET - set a msg bit to 1					*/
end_comment

begin_comment
comment|/* DMESGCLR - set a msg bit to 0					*/
end_comment

begin_comment
comment|/* DMESGTOG - toggle a msg bit						*/
end_comment

begin_comment
comment|/* DMESGVAL - the value of a message bit. 0 or non-zero			*/
end_comment

begin_define
define|#
directive|define
name|DMESGSET
parameter_list|(
name|u
parameter_list|,
name|v
parameter_list|)
value|(ddamsgs[(u)][(int)((v)>>5)] |=  (1<< ((v)& 0x1f)))
end_define

begin_define
define|#
directive|define
name|DMESGCLR
parameter_list|(
name|u
parameter_list|,
name|v
parameter_list|)
value|(ddamsgs[(u)][(int)((v)>>5)]&= ~(1<< ((v)& 0x1f)))
end_define

begin_define
define|#
directive|define
name|DMESGTOG
parameter_list|(
name|u
parameter_list|,
name|v
parameter_list|)
value|(ddamsgs[(u)][(int)((v)>>5)] ^=  (1<< ((v)& 0x1f)))
end_define

begin_define
define|#
directive|define
name|DMESGVAL
parameter_list|(
name|u
parameter_list|,
name|v
parameter_list|)
value|(ddamsgs[(u)][(int)((v)>>5)]&   (1<< ((v)& 0x1f)))
end_define

begin_define
define|#
directive|define
name|DMESG
parameter_list|(
name|u
parameter_list|,
name|v
parameter_list|,
name|s
parameter_list|)
value|(DMESGVAL(u,v) ? 0 : (s))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VAXVMS
end_ifdef

begin_comment
comment|/* always enable debugging under VMS */
end_comment

begin_define
define|#
directive|define
name|DDADEBUG
end_define

begin_endif
endif|#
directive|endif
endif|VAXVMS
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DDADEBUG
end_ifdef

begin_define
define|#
directive|define
name|DDADBCH
parameter_list|(
name|n
parameter_list|,
name|unit
parameter_list|)
value|(!DMESGVAL(unit, n + 128))
end_define

begin_comment
comment|/* first 128 are !debug*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   macros to test for call logging -- only use unit 0 space for now */
end_comment

begin_define
define|#
directive|define
name|LOG_BUSY
value|(!DMESGVAL(0, 256))
end_define

begin_comment
comment|/* "all circuits in use"  					     * and "no circuits available" */
end_comment

begin_define
define|#
directive|define
name|LOG_CALLS
value|(!DMESGVAL(0, 257))
end_define

begin_comment
comment|/* calls and clears */
end_comment

begin_define
define|#
directive|define
name|LOG_ABT
value|(!DMESGVAL(0, 258))
end_define

begin_comment
comment|/* I/O aborts */
end_comment

begin_comment
comment|/* values in dda_state */
end_comment

begin_define
define|#
directive|define
name|S_DISABLED
value|0
end_define

begin_comment
comment|/* link is disabled */
end_comment

begin_define
define|#
directive|define
name|S_COMING_UP
value|1
end_define

begin_comment
comment|/* enable issued, waiting for response */
end_comment

begin_define
define|#
directive|define
name|S_LINK_UP
value|2
end_define

begin_comment
comment|/* link operational */
end_comment

begin_define
define|#
directive|define
name|S_GOING_DOWN
value|3
end_define

begin_comment
comment|/* disable issued, waiting for response */
end_comment

begin_struct
struct|struct
name|trtab
comment|/* This stuff should ALSO be in ddareg.h */
block|{
comment|/* Address Translation Table IOCTL Data */
name|unsigned
name|char
name|func
decl_stmt|;
name|unsigned
name|char
name|x25addr
index|[
name|MAXADDRLEN
index|]
decl_stmt|;
name|unsigned
name|long
name|ipaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ddactl
comment|/* used for -m (message), -q (query), -n (svc_count) */
block|{
name|unsigned
name|char
name|func
decl_stmt|;
name|unsigned
name|char
name|nothing
index|[
literal|3
index|]
decl_stmt|;
name|int
name|drval
decl_stmt|;
name|char
name|msg
index|[
name|MLEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%									%%*/
end_comment

begin_comment
comment|/*%%	The download structure is the template for communication	%%*/
end_comment

begin_comment
comment|/*%%	with the ACP7000 when it is running diagnostic roms.  The	%%*/
end_comment

begin_comment
comment|/*%%	will initially place the SYSGEN_VALID entry in the BIIC GPR0	%%*/
end_comment

begin_comment
comment|/*%%	when in the probe routine.  The IOCTL mechanism has been	%%*/
end_comment

begin_comment
comment|/*%%	extended to support a *very* limited download feature which	%%*/
end_comment

begin_comment
comment|/*%%	enables us to load programs into the 7000 and then execute	%%*/
end_comment

begin_comment
comment|/*%%	them.  Versabug has been modified to examine GPR0 for the	%%*/
end_comment

begin_comment
comment|/*%%	SYSGEN_DLOAD value.  GPR1 will contain the physical address of  %%*/
end_comment

begin_comment
comment|/*%%	our standard sysgen block.  The driver will then place messages	%%*/
end_comment

begin_comment
comment|/*%%	in the request queue.  These messages will be read by the 7000	%%*/
end_comment

begin_comment
comment|/*%%	diagnostic firmware and placed into memory as needed.  After	%%*/
end_comment

begin_comment
comment|/*%%	all code has been loaded,  a final "EXEC" command may be sent	%%*/
end_comment

begin_comment
comment|/*%%	to the 7000 giving an execution start address.  The 7000 will	%%*/
end_comment

begin_comment
comment|/*%%	then execute the system code (which should wait for GPR0 to	%%*/
end_comment

begin_comment
comment|/*%%	contain the standard SYSGEN_VALID pattern before continuing.	%%*/
end_comment

begin_comment
comment|/*%%									%%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACP_BI
end_ifdef

begin_define
define|#
directive|define
name|SYSGEN_VALID
value|0x12345678
end_define

begin_comment
comment|/* normal operation mode */
end_comment

begin_define
define|#
directive|define
name|SYSGEN_DLOAD
value|0x31415927
end_define

begin_comment
comment|/* download operation mode */
end_comment

begin_define
define|#
directive|define
name|DN_LCMD_SETUP
value|0
end_define

begin_comment
comment|/* reset board, alloc buffers, setup shm */
end_comment

begin_define
define|#
directive|define
name|DN_LCMD_FEOP
value|1
end_define

begin_comment
comment|/* send command and data to front end */
end_comment

begin_define
define|#
directive|define
name|DN_LCMD_CLEANUP
value|2
end_define

begin_comment
comment|/* dealloc buffers and restore shm to norm */
end_comment

begin_define
define|#
directive|define
name|DN_TYPE_ID
value|1
end_define

begin_comment
comment|/* identification record */
end_comment

begin_define
define|#
directive|define
name|DN_TYPE_VER
value|2
end_define

begin_comment
comment|/* version record */
end_comment

begin_define
define|#
directive|define
name|DN_TYPE_COPY
value|3
end_define

begin_comment
comment|/* copyright record */
end_comment

begin_define
define|#
directive|define
name|DN_TYPE_DATA
value|4
end_define

begin_comment
comment|/* data record */
end_comment

begin_define
define|#
directive|define
name|DN_TYPE_XFR
value|5
end_define

begin_comment
comment|/* start address transfer record */
end_comment

begin_struct
struct|struct
name|dda_dnload
comment|/* code download structure */
block|{
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* ioctl function code (will be 'L') */
name|unsigned
name|char
name|lcommand
decl_stmt|;
comment|/* driver load command (setup/op/cleanup) */
name|unsigned
name|short
name|padding
decl_stmt|;
comment|/* null padding for dest addr */
name|unsigned
name|short
name|len
decl_stmt|;
comment|/* length of entire record */
name|unsigned
name|short
name|type
decl_stmt|;
comment|/* type of record passed */
name|unsigned
name|int
name|dest
decl_stmt|;
comment|/* destination address */
name|char
modifier|*
name|data
decl_stmt|;
comment|/* address of data record in user space */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
endif|ACP_BI
end_endif

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%% Histogram support declarations and defines.  Slots 0-NDDACH %%*/
end_comment

begin_comment
comment|/*%% record the amount of time n channels were being used.  The	 %%*/
end_comment

begin_comment
comment|/*%% following define uses of locations that come after the	 %%*/
end_comment

begin_comment
comment|/*%% first NDDACH entries.					 %%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_define
define|#
directive|define
name|H_LINK_UP
value|(NDDACH+1)
end_define

begin_comment
comment|/* entry that records the time link is*/
end_comment

begin_comment
comment|/* up 0-126 */
end_comment

begin_define
define|#
directive|define
name|H_START
value|(NDDACH+2)
end_define

begin_comment
comment|/* starting time */
end_comment

begin_define
define|#
directive|define
name|H_END
value|(NDDACH+3)
end_define

begin_comment
comment|/* ending time */
end_comment

begin_define
define|#
directive|define
name|H_TMO
value|(NDDACH+4)
end_define

begin_comment
comment|/* current value of idle timer */
end_comment

begin_define
define|#
directive|define
name|HISTSIZE
value|(H_TMO+1)
end_define

begin_comment
comment|/* size of the histogram table */
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%   Information for each device unit is maintained in an	 %%*/
end_comment

begin_comment
comment|/*%%   array of structures named dda_softc[].  The array is	 %%*/
end_comment

begin_comment
comment|/*%%   indexed by unit number.	Each entry includes the network	 %%*/
end_comment

begin_comment
comment|/*%%   interface structure (dda_if) used by the routing code to	 %%*/
end_comment

begin_comment
comment|/*%%   locate the interface,  an array of Logical Channel	 %%*/
end_comment

begin_comment
comment|/*%%   control blocks which maintain information about each of	 %%*/
end_comment

begin_comment
comment|/*%%   the Logical Channels (LCNs) through which X.25 virtual	 %%*/
end_comment

begin_comment
comment|/*%%   calls are established, a queue of I/O requests pending	 %%*/
end_comment

begin_comment
comment|/*%%   for the ACP, the UNIBUS interrupt vector for the unit	 %%*/
end_comment

begin_comment
comment|/*%%   and misc flags.	The Logical Channel Control blocks	 %%*/
end_comment

begin_comment
comment|/*%%   maintain information about the state of each LCN, a	 %%*/
end_comment

begin_comment
comment|/*%%   queue of outbound data, Half Duplex Channel (HDX) blocks	 %%*/
end_comment

begin_comment
comment|/*%%   used for queuing I/O requests to the ACP and an ifuba	 %%*/
end_comment

begin_comment
comment|/*%%   structure which records the UNIBUS resources being held	 %%*/
end_comment

begin_comment
comment|/*%%   by the LCN.						 %%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_struct
struct|struct
name|sioq
comment|/* Start I/O queue head */
block|{
name|struct
name|hdx_chan
modifier|*
name|sq_head
decl_stmt|;
comment|/* queue head */
name|struct
name|hdx_chan
modifier|*
name|sq_tail
decl_stmt|;
comment|/* queue tail */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hdx_chan
comment|/* HDX channel block */
block|{
name|struct
name|hdx_chan
modifier|*
name|hc_next
decl_stmt|;
comment|/* link to next HDX channel */
name|struct
name|mbuf
modifier|*
name|hc_mbuf
decl_stmt|;
comment|/* mbuf chain */
name|struct
name|mbuf
modifier|*
name|hc_curr
decl_stmt|;
comment|/* current mbuf in chain */
name|unsigned
name|char
modifier|*
name|hc_addr
decl_stmt|;
comment|/* address bits 15-00 */
name|unsigned
name|short
name|hc_cnt
decl_stmt|;
comment|/* byte count */
name|unsigned
name|char
name|hc_func
decl_stmt|;
comment|/* I/O function */
name|unsigned
name|char
name|hc_sbfc
decl_stmt|;
comment|/* I/O subfunction */
name|unsigned
name|char
name|hc_chan
decl_stmt|;
comment|/* HDX channel number */
name|unsigned
name|char
name|hc_inv
decl_stmt|;
comment|/* place to store various bits */
ifdef|#
directive|ifdef
name|vax11c
comment|/* VAX C compiler (and GCC running in VAXC native mode) does not pad 	structures to longword boundaries, so we must pad any structures 	that are passed between ACPCONFIG and the driver */
name|unsigned
name|char
name|_vaxcfill
index|[
literal|2
index|]
decl_stmt|;
comment|/* pad structure to longword boundary */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_union
union|union
name|dc_key
block|{
name|struct
name|in_addr
name|key_addr
decl_stmt|;
name|unsigned
name|long
name|key_val
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|dda_cb
comment|/* Logical Channel control block */
block|{
if|#
directive|if
name|defined
argument_list|(
name|DDA_PADOPT
argument_list|)
operator|&&
name|defined
argument_list|(
name|VAXVMS
argument_list|)
name|int
name|ptyucb
decl_stmt|;
comment|/* to store the np unit control blk addr */
name|int
name|ttyflags
decl_stmt|;
comment|/* flags for the VMS x29 driver */
endif|#
directive|endif
name|int
name|dc_line
decl_stmt|;
comment|/* index into tty structure / minor number */
name|struct
name|in_addr
name|dc_inaddr
decl_stmt|;
comment|/* remote Internet address */
name|union
name|dc_key
name|dc_key
decl_stmt|;
comment|/* circuit destination key */
name|unsigned
name|char
name|dc_lcn
decl_stmt|;
comment|/* LCN number */
name|unsigned
name|char
name|dc_state
decl_stmt|;
comment|/* LCN state */
name|unsigned
name|short
name|dc_timer
decl_stmt|;
comment|/* LCN timer */
name|struct
name|ifqueue
name|dc_oq
decl_stmt|;
comment|/* LCN output queue */
name|struct
name|hdx_chan
name|dc_rchan
decl_stmt|;
comment|/* LCN read HDX channel */
name|struct
name|hdx_chan
name|dc_wchan
decl_stmt|;
comment|/* LCN write HDX channel */
name|short
name|dc_next
decl_stmt|;
comment|/* LCN next index. Long so padding will work */
name|unsigned
name|char
name|dc_wsizeout
decl_stmt|;
comment|/* negotiated outgoing window size */
name|unsigned
name|char
name|dc_wsizein
decl_stmt|;
comment|/* negotiated ingoing window size */
name|unsigned
name|char
name|dc_pktsizeout
decl_stmt|;
comment|/* negotiated outgoing packet size */
name|unsigned
name|char
name|dc_pktsizein
decl_stmt|;
comment|/* negotiated ingoing packet size */
name|unsigned
name|short
name|dc_flags
decl_stmt|;
comment|/* misc flags, DC_OBUSY */
name|unsigned
name|short
name|dc_out_t
decl_stmt|;
comment|/* DEBUG output completion timer per lcn */
ifdef|#
directive|ifdef
name|vax11c
comment|/* VAX C compiler (and GCC running in VAXC native mode) does not pad 	structures to longword boundaries, so we must pad any structures 	that are passed between ACPCONFIG and the driver */
name|unsigned
name|char
name|_vaxcfill
index|[
literal|2
index|]
decl_stmt|;
comment|/* pad structure to longword boundary */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dda_softc
comment|/* device control structure */
block|{
name|struct
name|ifnet
name|dda_if
decl_stmt|;
comment|/* network-visible interface */
name|struct
name|dda_cb
name|dda_cb
index|[
name|NDDACH
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Logical Channel cntl blks */
name|struct
name|sioq
name|dda_sioq
decl_stmt|;
comment|/* start I/O queue */
name|int
name|dda_vector
decl_stmt|;
comment|/* UNIBUS interrupt vector */
name|int
name|dda_mapreg
decl_stmt|;
comment|/* UNIBUS mapping register */
name|unsigned
name|char
name|dda_flags
decl_stmt|;
comment|/* ACP operational flag (intr b) */
name|unsigned
name|char
name|dda_init
decl_stmt|;
comment|/* flag for init, X.25 service */
name|unsigned
name|char
name|dda_state
decl_stmt|;
comment|/* state of link (see below) */
name|unsigned
name|char
name|dda_firmrev
decl_stmt|;
comment|/* firmware revision level byte */
name|struct
name|in_addr
name|dda_ipaddr
decl_stmt|;
comment|/* local IP address */
name|int
name|dda_net_id
decl_stmt|;
comment|/* net type -- for TRANSPAC */
block|}
struct|;
end_struct

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%   The dc_flags field in the dda_cb structure is used to	 %%*/
end_comment

begin_comment
comment|/*%%   indicate that output is busy, DC_OBUSY.	In ddainit(),	 %%*/
end_comment

begin_comment
comment|/*%%   the flag is set to zero.	 In dda_start(), return if the	 %%*/
end_comment

begin_comment
comment|/*%%   flag is set DC_OBUSY; otherwise if output isn't active	 %%*/
end_comment

begin_comment
comment|/*%%   an attempt is made to send another packet.  The packet	 %%*/
end_comment

begin_comment
comment|/*%%   is dequeued, and the flag is set for DC_BUSY on.	 In	 %%*/
end_comment

begin_comment
comment|/*%%   both dda_data and dda_supr, if a write completion is	 %%*/
end_comment

begin_comment
comment|/*%%   indicated, DC_BUSY is turned off before firing up a write %%*/
end_comment

begin_comment
comment|/*%%   via a call to dda_start().				 %%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%   In order to modify packet level parameters like packet	 %%*/
end_comment

begin_comment
comment|/*%%   window, packet level must be restarted.	Doing this	 %%*/
end_comment

begin_comment
comment|/*%%   reliably requires the driver know four possible states	 %%*/
end_comment

begin_comment
comment|/*%%   for the FEP: DISABLED (down and not attempting to bring	 %%*/
end_comment

begin_comment
comment|/*%%   the link up); COMING UP (processed a "-u N" for N != 0,	 %%*/
end_comment

begin_comment
comment|/*%%   but have not exchanged restarts yet); UP (data transfer	 %%*/
end_comment

begin_comment
comment|/*%%   state); GOING DOWN (processed "-u 0", but the other end	 %%*/
end_comment

begin_comment
comment|/*%%   has not yet agreed).  The dda_state variable tracks these %%*/
end_comment

begin_comment
comment|/*%%   four states.  No other data structure provides this level %%*/
end_comment

begin_comment
comment|/*%%   of resolution.  In particular, IFF_UP is always on when	 %%*/
end_comment

begin_comment
comment|/*%%   dda_state is UP, but sometimes on when dda_state is	 %%*/
end_comment

begin_comment
comment|/*%%   COMING UP or GOING DOWN.					 %%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DDA_MSGQ
end_ifdef

begin_define
define|#
directive|define
name|MSGQSIZE
value|2048
end_define

begin_define
define|#
directive|define
name|MQHEX
value|1
end_define

begin_comment
comment|/* marks the start of a hex number */
end_comment

begin_define
define|#
directive|define
name|MQDEC
value|2
end_define

begin_comment
comment|/* marks the start of a decimal number */
end_comment

begin_define
define|#
directive|define
name|MQEND
value|0
end_define

begin_comment
comment|/* marks the end of message queue data */
end_comment

begin_define
define|#
directive|define
name|MSGQNAME
value|"_ddamsgq"
end_define

begin_comment
comment|/* the text name of the message q */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/*  Revision History:  26-Mar-1986: V1.0 - First generated. 		 Clare Russ. 05-Sep-1986: V1.1 - Add definitions for modified ACPCONFIG interface 		 Clare Russ. 27-Oct-1986: V1.2 - Change TMO_DATA_IDLE from 30 to 600 sec. 		 Lars Poulsen and Randy Graves. 30-Jan-1987: V1.3 - Added DDASTAT_NMC 		 Jeff Berkowitz and Stephanie Price 30-Mar-1987: V1.4 - Added new #defines for X.25 facilities 		 Jeff Berkowitz 09-Sep-1987: V2.1 - Moved all major structure and constant 		 declarations from the driver to this file. 		 Added new #defines for X.25 options and facilities 		 Note that you must now edit this file to turn on 		 debugging and logging. 		 Stephanie Price 18-Mar-1988: V3.0 Brad Engstrom 		 Added four fields to the dda_cb structure. These fields 		 are used to track the negotiated packet and window size 		 for both incoming and outgoing directions. This data 		 will be displayed by the -l option of acpconfig. 12-Apr-1988: V3.0 Brad Engstrom 		 Moved all initialized variables to if_dda.c.  This will 		 allow this file to work under BSD or ULTRIX because the 		 ULTRIX C compiler gags on variables declared in header 		 files. 15-Apr-1988: V3.0 Brad Engstrom 		 Added a key field for doing searches for a 		 matching destination.	This is used to see if there is 		 already an open circuit to a particular destination. 15-Apr-1988: V3.0 Brad Engstrom 		 Added a next pointer to the dda_cb structure.	This 		 will allow lcn structures to be linked into free and 		 active lists.	The pointer is actully just an offset to 		 the next element in the list.	This allows programs such 		 as acpconfig to traverse a copy of the structure in 		 memory. 15-Apr-1988: V3.0 Brad Engstrom 		 Got rid of conditional compilation of dc_out_t field 		 in the dda_cb structure.  This will always be included 		 in the structure, but will only be used if DDA_DEBUG is 		 on. This releaves problems of padding size when adding 		 new fields to the dda_cb structure. 22-Apr-1988: V3.0 Brad Engstrom 		 Added new macro DMESG.	 This is used to conditionally 		 print driver console messages. 22-Apr-1988: V3.0 Brad Engstrom 		 Added a new define DDAMAINT_BRD.  If this is defined 		 then it is assumed that the maintenance board is being 		 used so don't do checks for the board id in the probe 		 routine. 10-May-1988: V3.0 Brad Engstrom 		 Added the constant MAXADDRLEN which is the maximum lenth 		 of an X.25 address. Also added	 MINADDRLEN to specify 		 the minimum X25 address length. 26-Oct-1988: V3.1 Charles Carvalho 		Added documentation. 15-Aug-1988: V4.0 Brad Ensgtrom 		added support for X.29 and Programmers Interface 02-Sep-1988: V4.0 Brad Ensgtrom 		added new field hc_inv to the hc structure.  Someone used 		the hc_sbfc field to store the invalid bit.  Now that the 		PI will use the subfunction field the invalid bit must be 		stored someplace else. 09-Jan-1989: V4.1 SAJ -- Merge 4.0, 3.1 		relaxed MAXADDRLEN& MINADDRLEN to allow for transpac 		installed padding changes from TGV for vax11c 17-Feb-1989: Paul Traina 		Merged SAJ's changes for DDA_DEBUG 28-May-1989: Paul Traina 		Changed structure padding for TGV 20-Jun-1989: Paul Traina 		Eliminated old debug logic... call loging is next on the hit 		list.  New driver is not compatible with old acpconfig! 18-Jul-1989: Paul Traina 		Moved dc_key.ttyline out of union, creating dc_line.  This 		is to stop it from getting clobbered on restarts et al. 25-Oct-1989: Paul Traina 		Added download structure for ACP7000 downloading and code 		execution. */
end_comment

end_unit

