begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *	@(#)if_acpvar.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*************************************************************************/
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*       ________________________________________________________        */
end_comment

begin_comment
comment|/*      /                                                        \       */
end_comment

begin_comment
comment|/*     |          AAA          CCCCCCCCCCCCCC    CCCCCCCCCCCCCC   |      */
end_comment

begin_comment
comment|/*     |         AAAAA        CCCCCCCCCCCCCCCC  CCCCCCCCCCCCCCCC  |      */
end_comment

begin_comment
comment|/*     |        AAAAAAA       CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |      */
end_comment

begin_comment
comment|/*     |       AAAA AAAA      CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |      AAAA   AAAA     CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |     AAAA     AAAA    CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |    AAAA       AAAA   CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |   AAAA  AAAAAAAAAAA  CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |      */
end_comment

begin_comment
comment|/*     |  AAAA    AAAAAAAAAAA CCCCCCCCCCCCCCCC  CCCCCCCCCCCCCCCC  |      */
end_comment

begin_comment
comment|/*     | AAAA      AAAAAAAAA   CCCCCCCCCCCCCC    CCCCCCCCCCCCCC   |      */
end_comment

begin_comment
comment|/*      \________________________________________________________/       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  	Copyright (c) 1986 by Advanced Computer Communications           */
end_comment

begin_comment
comment|/*  	720 Santa Barbara Street, Santa Barbara, California  93101       */
end_comment

begin_comment
comment|/*  	(805) 963-9431                                                   */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  File:		if_acpvar.h                                      */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Author:		Arthur Berggreen                                 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Project:		ACP6100 (UPB with HDLC firmware)                 */
end_comment

begin_comment
comment|/*          		ACP5100 (QPB with HDLC firmware)                 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Revision History:                                                    */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*    21-NOV-1985  Clare Russ:  add fileheader and comments              */
end_comment

begin_comment
comment|/*         Add definitions for implementatin of new Command Interface    */
end_comment

begin_comment
comment|/*         (CIF) and Access Path Allocation Protocol (APAP).             */
end_comment

begin_comment
comment|/*         Note that values for LINK_DISABLE etc, have been updated.     */
end_comment

begin_comment
comment|/*    22-NOV-1985  Clare Russ:  Modify set system parameters values      */
end_comment

begin_comment
comment|/*    17-DEC-1985  Clare Russ:  NACPCH is 2 to include all channels:     */
end_comment

begin_comment
comment|/*         allocation channel, supervisor channel, and data channel.     */
end_comment

begin_comment
comment|/*    30-MAY-1985  Clare Russ:  Add MPCP host request initiation         */
end_comment

begin_comment
comment|/*         mailbox subfunction values (0 = data, c3 = supervisory msg)   */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*************************************************************************/
end_comment

begin_escape
end_escape

begin_define
define|#
directive|define
name|NACPCH
value|2
end_define

begin_comment
comment|/* one ACP data channel    */
end_comment

begin_define
define|#
directive|define
name|ACP_ALLOC
value|0
end_define

begin_comment
comment|/* path allocation channel */
end_comment

begin_define
define|#
directive|define
name|ACP_SUPR
value|1
end_define

begin_comment
comment|/* supervisor channel      */
end_comment

begin_define
define|#
directive|define
name|ACP_DATA
value|2
end_define

begin_comment
comment|/* data channel            */
end_comment

begin_define
define|#
directive|define
name|ACPMTU
value|4096
end_define

begin_comment
comment|/* 4096 byte frames! */
end_comment

begin_define
define|#
directive|define
name|ACP_OQMAX
value|8
end_define

begin_define
define|#
directive|define
name|DC_OBUSY
value|0x01
end_define

begin_comment
comment|/* Defines for the Set HDLC System Parameters Command which is used */
end_comment

begin_comment
comment|/* to modify several operating parameters within the ACP5100/6100   */
end_comment

begin_define
define|#
directive|define
name|LINK_DISABLE
value|0x22
end_define

begin_comment
comment|/* disable the HDLC line    */
end_comment

begin_define
define|#
directive|define
name|LINK_ENABLE
value|0x01
end_define

begin_comment
comment|/* enable the HDLC line     */
end_comment

begin_comment
comment|/* The LINK_LOOPBACK, BAUD_CNTL, IDLE_POLL, and CLOCK_CNTL parameter */
end_comment

begin_comment
comment|/* modification commands are one-byte values containing a size and   */
end_comment

begin_comment
comment|/* and ID followed by 0-2 bytes of parameter information.  The       */
end_comment

begin_comment
comment|/* number of bytes of parameter information is specified in the most */
end_comment

begin_comment
comment|/* significant 2 bits of the command, the other 6 bits are the ID.   */
end_comment

begin_comment
comment|/* A 00, 01, or 10 specify respectively 0, 1, or 2 bytes of          */
end_comment

begin_comment
comment|/* parameter information follow.                                     */
end_comment

begin_define
define|#
directive|define
name|LINK_LOOPBACK
value|0x42
end_define

begin_comment
comment|/* set loopback mode        */
end_comment

begin_define
define|#
directive|define
name|LOOP_NONE
value|0x00
end_define

begin_comment
comment|/*  none (normal operation) */
end_comment

begin_define
define|#
directive|define
name|LOOP_EXTERNAL
value|0x01
end_define

begin_comment
comment|/*  external loopback       */
end_comment

begin_define
define|#
directive|define
name|LOOP_INTERNAL
value|0x02
end_define

begin_comment
comment|/*  internal loopback       */
end_comment

begin_define
define|#
directive|define
name|BAUD_CNTL
value|0x8c
end_define

begin_comment
comment|/* baud rate divisor        */
end_comment

begin_define
define|#
directive|define
name|IDLE_POLL
value|0x4d
end_define

begin_comment
comment|/* poll inactive link       */
end_comment

begin_define
define|#
directive|define
name|CLOCK_CNTL
value|0x4e
end_define

begin_comment
comment|/* select clock source      */
end_comment

begin_define
define|#
directive|define
name|LINE_STATUS
value|0x61
end_define

begin_define
define|#
directive|define
name|LINK_UP
value|0x01
end_define

begin_comment
comment|/*  Host Request Mailbox Completion Status  */
end_comment

begin_define
define|#
directive|define
name|ACPIOCOK
value|0x01
end_define

begin_comment
comment|/* success        */
end_comment

begin_define
define|#
directive|define
name|ACPIOCABT
value|0xff
end_define

begin_comment
comment|/* aborted        */
end_comment

begin_define
define|#
directive|define
name|ACPIOCERR
value|0xfe
end_define

begin_comment
comment|/* error          */
end_comment

begin_define
define|#
directive|define
name|ACPIOCOVR
value|0xfd
end_define

begin_comment
comment|/* overrun        */
end_comment

begin_define
define|#
directive|define
name|ACPIOCUBE
value|0xfc
end_define

begin_comment
comment|/* xfer count = 0 */
end_comment

begin_comment
comment|/*  Host Request Mailbox Subfunction  */
end_comment

begin_define
define|#
directive|define
name|SBFCN_DATA
value|0x00
end_define

begin_comment
comment|/* data           */
end_comment

begin_define
define|#
directive|define
name|SBFCN_SUPR
value|0xc3
end_define

begin_comment
comment|/* supervisory    */
end_comment

begin_define
define|#
directive|define
name|ACPF_OK
value|0x0001
end_define

begin_comment
comment|/* ACP operation flag */
end_comment

begin_define
define|#
directive|define
name|ACPSTAT_OK
value|0x00
end_define

begin_comment
comment|/* offsets for CIM command/response pairs */
end_comment

begin_define
define|#
directive|define
name|CMD_OFFSET
value|3
end_define

begin_comment
comment|/* CIM header, offset for command */
end_comment

begin_define
define|#
directive|define
name|CID_OFFSET
value|7
end_define

begin_comment
comment|/* Command ID field, set by the   */
end_comment

begin_comment
comment|/* generator, is returned with no */
end_comment

begin_comment
comment|/* change in the response         */
end_comment

begin_define
define|#
directive|define
name|RSF_OFFSET
value|11
end_define

begin_comment
comment|/* CIM header, offset for RSF     */
end_comment

begin_define
define|#
directive|define
name|DPN_OFFSET
value|13
end_define

begin_comment
comment|/* alloc cmd offset for dpn       */
end_comment

begin_define
define|#
directive|define
name|TYPE_OFFSET
value|17
end_define

begin_comment
comment|/* alloc cmd offset for path type */
end_comment

begin_define
define|#
directive|define
name|LOOP_OFFSET
value|16
end_define

begin_comment
comment|/* set system parms, loopback     */
end_comment

begin_define
define|#
directive|define
name|DTE_OFFSET
value|18
end_define

begin_comment
comment|/* set system parms, dte/dce mode */
end_comment

begin_define
define|#
directive|define
name|BAUD_OFFSET
value|20
end_define

begin_comment
comment|/* set system parms, dte/dce mode */
end_comment

begin_define
define|#
directive|define
name|CLOCK_OFFSET
value|25
end_define

begin_comment
comment|/* set system parms, dte/dce mode */
end_comment

begin_define
define|#
directive|define
name|DOWN_OFFSET
value|26
end_define

begin_comment
comment|/* set system parms, line down    */
end_comment

begin_define
define|#
directive|define
name|INIT_OK
value|0x10
end_define

begin_comment
comment|/* send line up CIM to front end  */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Most of the following defines were extracted from front end software     */
end_comment

begin_comment
comment|/* source include files cim.h, cimdef.h, and params.h on 21-NOV-1985.  This */
end_comment

begin_comment
comment|/* will ensure that the host and front end are using the same definitions.  */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Parameter Modification Commands for Set HDLC System Paramters command */
end_comment

begin_define
define|#
directive|define
name|DCE_OR_DTE
value|0x43
end_define

begin_comment
comment|/* HDLC: select DCE/DTE mode	*/
end_comment

begin_define
define|#
directive|define
name|DTE_MODE
value|0x00
end_define

begin_comment
comment|/*   specify DTE mode       	*/
end_comment

begin_define
define|#
directive|define
name|DCE_MODE
value|0x01
end_define

begin_comment
comment|/*   specify DCE mode       	*/
end_comment

begin_define
define|#
directive|define
name|DTE_ADDR
value|0x04
end_define

begin_comment
comment|/* HDLC: DTE frame address	*/
end_comment

begin_define
define|#
directive|define
name|DCE_ADDR
value|0x05
end_define

begin_comment
comment|/* HDLC: DCE frame address	*/
end_comment

begin_define
define|#
directive|define
name|IFRAME_T_O
value|0x06
end_define

begin_comment
comment|/* HDLC: T1 after I-frame	*/
end_comment

begin_define
define|#
directive|define
name|POLL_T_O
value|0x07
end_define

begin_comment
comment|/* HDLC: T1 after poll cmd	*/
end_comment

begin_define
define|#
directive|define
name|ADM_T_O
value|0x08
end_define

begin_comment
comment|/* HDLC: T1 for down link	*/
end_comment

begin_define
define|#
directive|define
name|RETRY_LIMIT
value|0x0a
end_define

begin_comment
comment|/* HDLC: N2 counter		*/
end_comment

begin_define
define|#
directive|define
name|WATCHDOG_T_O
value|0x0b
end_define

begin_comment
comment|/* phys: max transmit time	*/
end_comment

begin_define
define|#
directive|define
name|PKT_SIZE
value|0x10
end_define

begin_comment
comment|/* X.25: packet size		*/
end_comment

begin_define
define|#
directive|define
name|PKT_WINDOW
value|0x11
end_define

begin_comment
comment|/* X.25: packet window		*/
end_comment

begin_define
define|#
directive|define
name|PKT_TIMEOUT
value|0x12
end_define

begin_comment
comment|/* X.25: packet timeout		*/
end_comment

begin_define
define|#
directive|define
name|UPPER_THRESH
value|0x13
end_define

begin_comment
comment|/* HDLC queue limits: upper	*/
end_comment

begin_define
define|#
directive|define
name|LOWER_THRESH
value|0x14
end_define

begin_comment
comment|/*		      lower	*/
end_comment

begin_define
define|#
directive|define
name|WHICH_PROTOCOL
value|0x15
end_define

begin_comment
comment|/* protocol above HDLC:		*/
end_comment

begin_define
define|#
directive|define
name|PRMVAL_HDH
value|0x01
end_define

begin_comment
comment|/* HDH				*/
end_comment

begin_define
define|#
directive|define
name|PRMVAL_HDLC
value|0x02
end_define

begin_comment
comment|/* none (bare HDLC)		*/
end_comment

begin_define
define|#
directive|define
name|PRMVAL_X25
value|0x03
end_define

begin_comment
comment|/* X.25 packet level		*/
end_comment

begin_define
define|#
directive|define
name|IMP_OR_HOST
value|0x16
end_define

begin_comment
comment|/* HDH: select IMP/host mode	*/
end_comment

begin_define
define|#
directive|define
name|PKT_OR_MSG
value|0x17
end_define

begin_comment
comment|/* HDH: select packet/msg mode	*/
end_comment

begin_define
define|#
directive|define
name|SEND_TIMER
value|0x18
end_define

begin_comment
comment|/* HDH send timer		*/
end_comment

begin_define
define|#
directive|define
name|RESPONSE_TIMER
value|0x19
end_define

begin_comment
comment|/* HDH response timer		*/
end_comment

begin_define
define|#
directive|define
name|HLD_TMR
value|0x1A
end_define

begin_comment
comment|/* HDH				*/
end_comment

begin_define
define|#
directive|define
name|MISSES
value|0x1B
end_define

begin_comment
comment|/* HDH				*/
end_comment

begin_define
define|#
directive|define
name|HITS
value|0x1C
end_define

begin_comment
comment|/* HDH				*/
end_comment

begin_define
define|#
directive|define
name|SEND_WINDOW
value|0x1D
end_define

begin_comment
comment|/* HDH				*/
end_comment

begin_define
define|#
directive|define
name|MAXIFRM_XMIT
value|0x1e
end_define

begin_comment
comment|/* HDLC: queue to transmitter	*/
end_comment

begin_define
define|#
directive|define
name|FRAME_SPACE
value|0x1f
end_define

begin_comment
comment|/* phys: interframe spacing	*/
end_comment

begin_define
define|#
directive|define
name|FRAME_SIZE
value|0x20
end_define

begin_comment
comment|/* HDLC: frame size		*/
end_comment

begin_define
define|#
directive|define
name|FRAME_WINDOW
value|0x21
end_define

begin_comment
comment|/* HDLC: transmit frame window	*/
end_comment

begin_define
define|#
directive|define
name|EXTERNAL_CLOCK
value|0x00
end_define

begin_comment
comment|/* clock generated externally   */
end_comment

begin_define
define|#
directive|define
name|INTERNAL_CLOCK
value|0x01
end_define

begin_comment
comment|/* clock generated internally 	*/
end_comment

begin_define
define|#
directive|define
name|SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|FAILURE
value|1
end_define

begin_comment
comment|/*   Path types    */
end_comment

begin_define
define|#
directive|define
name|TYPE_DATA
value|0x01
end_define

begin_comment
comment|/* Path type of DATA  */
end_comment

begin_define
define|#
directive|define
name|TYPE_CNTL
value|0x02
end_define

begin_comment
comment|/* Path type of CONTROL */
end_comment

begin_comment
comment|/*   Command Codes used in CIMs                */
end_comment

begin_comment
comment|/* Allocation Facility Commands */
end_comment

begin_define
define|#
directive|define
name|CMD_ALLOC
value|0x22
end_define

begin_comment
comment|/* Allocate Path */
end_comment

begin_define
define|#
directive|define
name|CMD_DEALLOC
value|0x24
end_define

begin_comment
comment|/* Deallocate Path */
end_comment

begin_comment
comment|/* Allocation Facility Responses */
end_comment

begin_comment
comment|/* Note that the response value  */
end_comment

begin_comment
comment|/* is the command value + 1      */
end_comment

begin_define
define|#
directive|define
name|RSP_ALLOC
value|0x23
end_define

begin_comment
comment|/* Allocate Path */
end_comment

begin_define
define|#
directive|define
name|RSP_DEALLOC
value|0x25
end_define

begin_comment
comment|/* Deallocate Path */
end_comment

begin_define
define|#
directive|define
name|RSP_SSP
value|0x63
end_define

begin_comment
comment|/* Set Sys Params  */
end_comment

begin_define
define|#
directive|define
name|RSP_FLUP
value|0x65
end_define

begin_comment
comment|/* Frame Level Up */
end_comment

begin_define
define|#
directive|define
name|RSP_FLDWN
value|0x67
end_define

begin_comment
comment|/* Frame Level Down */
end_comment

begin_comment
comment|/* System Facility Commands */
end_comment

begin_define
define|#
directive|define
name|CMD_BFINIT
value|0x42
end_define

begin_comment
comment|/* Buffer Initialization */
end_comment

begin_define
define|#
directive|define
name|CMD_BFQRY
value|0x44
end_define

begin_comment
comment|/* Buffer Query */
end_comment

begin_define
define|#
directive|define
name|CMD_FACQRY
value|0x46
end_define

begin_comment
comment|/* Facility Query */
end_comment

begin_define
define|#
directive|define
name|CMD_MEMRD
value|0x48
end_define

begin_comment
comment|/* Memory Read */
end_comment

begin_define
define|#
directive|define
name|CMD_MEMWRT
value|0x4A
end_define

begin_comment
comment|/* Memory Write */
end_comment

begin_comment
comment|/* HDLC Facility Commands */
end_comment

begin_define
define|#
directive|define
name|CMD_SSP
value|0x62
end_define

begin_comment
comment|/* Set HDLC Parameters */
end_comment

begin_define
define|#
directive|define
name|CMD_FLUP
value|0x64
end_define

begin_comment
comment|/* Frame Level Up */
end_comment

begin_define
define|#
directive|define
name|CMD_FLDWN
value|0x66
end_define

begin_comment
comment|/* Frame Level Down */
end_comment

begin_define
define|#
directive|define
name|CMD_STAQRY
value|0x68
end_define

begin_comment
comment|/* Statistics Query */
end_comment

begin_define
define|#
directive|define
name|CMD_FRMQRY
value|0x6A
end_define

begin_comment
comment|/* Frame Level Status Query */
end_comment

begin_comment
comment|/* DCP Driver Commands */
end_comment

begin_define
define|#
directive|define
name|CMD_ERST
value|0x02
end_define

begin_comment
comment|/* Reset Encryption */
end_comment

begin_define
define|#
directive|define
name|CMD_DRST
value|0x04
end_define

begin_comment
comment|/* Reset Decryption */
end_comment

begin_define
define|#
directive|define
name|CMD_ESTA
value|0x06
end_define

begin_comment
comment|/* Start Encryption */
end_comment

begin_define
define|#
directive|define
name|CMD_DSTA
value|0x08
end_define

begin_comment
comment|/* Start Decryption */
end_comment

begin_define
define|#
directive|define
name|CMD_ESET
value|0x0A
end_define

begin_comment
comment|/* Set Encryption */
end_comment

begin_define
define|#
directive|define
name|CMD_DSET
value|0x0C
end_define

begin_comment
comment|/* Set Decryption */
end_comment

begin_define
define|#
directive|define
name|CMD_ESTOP
value|0x0E
end_define

begin_comment
comment|/* Stop Encryption */
end_comment

begin_define
define|#
directive|define
name|CMD_DSTOP
value|0x10
end_define

begin_comment
comment|/* Stop Decryption */
end_comment

begin_define
define|#
directive|define
name|CMD_DCPERR
value|0x7E
end_define

begin_comment
comment|/* DCP Error Detected */
end_comment

begin_comment
comment|/*   Facility Codes used in CIMs  */
end_comment

begin_comment
comment|/*    Symbol        FAC Code     Facility       */
end_comment

begin_define
define|#
directive|define
name|FAC_NONE
value|0x00
end_define

begin_comment
comment|/* No Facility assigned   */
end_comment

begin_define
define|#
directive|define
name|FAC_ALLOC
value|0x01
end_define

begin_comment
comment|/* Allocation facility */
end_comment

begin_define
define|#
directive|define
name|FAC_SYS
value|0x02
end_define

begin_comment
comment|/* System query/response facility */
end_comment

begin_define
define|#
directive|define
name|FAC_HDLC
value|0x03
end_define

begin_comment
comment|/* HDLC facility */
end_comment

begin_define
define|#
directive|define
name|FAC_DCP
value|0x04
end_define

begin_comment
comment|/* Data Encryption Facility */
end_comment

begin_define
define|#
directive|define
name|MAX_FAC
value|4
end_define

begin_comment
comment|/* Maximum facility number  */
end_comment

begin_comment
comment|/* RSF Codes used in CIMs  */
end_comment

begin_comment
comment|/*   RSF Symbol    RSF Code    Response Description */
end_comment

begin_comment
comment|/*                 (decimal)                        */
end_comment

begin_define
define|#
directive|define
name|RSF_SUCC
value|0
end_define

begin_comment
comment|/* Success */
end_comment

begin_define
define|#
directive|define
name|RSF_LONG
value|1
end_define

begin_comment
comment|/* Command is too long */
end_comment

begin_define
define|#
directive|define
name|RSF_SHORT
value|2
end_define

begin_comment
comment|/* Command is too short */
end_comment

begin_define
define|#
directive|define
name|RSF_NOTSUPP
value|3
end_define

begin_comment
comment|/* Request not supported */
end_comment

begin_define
define|#
directive|define
name|RSF_DATA_NA
value|4
end_define

begin_comment
comment|/* Buffer contains data-Not allowed */
end_comment

begin_define
define|#
directive|define
name|RSF_NOCNTL
value|5
end_define

begin_comment
comment|/* Control Path must be allocated 1st */
end_comment

begin_define
define|#
directive|define
name|RSF_NOFAC
value|6
end_define

begin_comment
comment|/* Facility unavailable for allocation */
end_comment

begin_define
define|#
directive|define
name|RSF_FACPTH
value|7
end_define

begin_comment
comment|/* Path cannot be allocated for facility */
end_comment

begin_define
define|#
directive|define
name|RSF_NOBUF
value|8
end_define

begin_comment
comment|/* No buffers available    */
end_comment

begin_define
define|#
directive|define
name|RSF_INVDPN
value|10
end_define

begin_comment
comment|/* Invalid Data Path Number */
end_comment

begin_define
define|#
directive|define
name|RSF_INVCMD
value|11
end_define

begin_comment
comment|/* Invalid Command */
end_comment

begin_define
define|#
directive|define
name|RSF_INVTYP
value|12
end_define

begin_comment
comment|/* Invalid path type */
end_comment

begin_define
define|#
directive|define
name|RSF_INVFAC
value|13
end_define

begin_comment
comment|/* Invalid facility */
end_comment

begin_define
define|#
directive|define
name|RSF_DPNOOR
value|20
end_define

begin_comment
comment|/* DPN out of range */
end_comment

begin_define
define|#
directive|define
name|RSF_PTHEXC
value|21
end_define

begin_comment
comment|/* Maximum number of paths exceeded */
end_comment

begin_define
define|#
directive|define
name|RSF_NOTALLOC
value|23
end_define

begin_comment
comment|/* Path not allocated */
end_comment

begin_define
define|#
directive|define
name|RSF_BFROOR
value|30
end_define

begin_comment
comment|/* Buffer size out of range */
end_comment

begin_define
define|#
directive|define
name|RSF_SEGBFR
value|31
end_define

begin_comment
comment|/* Segmented Buffers implemented */
end_comment

begin_define
define|#
directive|define
name|RSF_BFQEXC
value|32
end_define

begin_comment
comment|/* Too many Buffer queues requested */
end_comment

begin_define
define|#
directive|define
name|RSF_INVADR
value|40
end_define

begin_comment
comment|/* Invalid ACP 6100 Address */
end_comment

begin_define
define|#
directive|define
name|RSF_INVCNT
value|41
end_define

begin_comment
comment|/* Byte count Invalid */
end_comment

begin_define
define|#
directive|define
name|RSF_INVPID
value|50
end_define

begin_comment
comment|/* Parameter ID Unknown */
end_comment

begin_define
define|#
directive|define
name|RSF_INVVAL
value|51
end_define

begin_comment
comment|/* Invalid Value */
end_comment

begin_define
define|#
directive|define
name|RSF_PTLVAL
value|52
end_define

begin_comment
comment|/* Partial Value */
end_comment

begin_define
define|#
directive|define
name|RSF_BDPRTY
value|61
end_define

begin_comment
comment|/* Bad parity for Key; one or more */
end_comment

begin_comment
comment|/* Key bytes had bad (even) parity */
end_comment

begin_define
define|#
directive|define
name|RSF_NOSET
value|62
end_define

begin_comment
comment|/* No Set Command given */
end_comment

begin_define
define|#
directive|define
name|RSF_INVMOD
value|63
end_define

begin_comment
comment|/* Invalid Mode in Set command */
end_comment

begin_define
define|#
directive|define
name|RSF_INACT
value|64
end_define

begin_comment
comment|/* Inactive-Stop issued for operation */
end_comment

begin_comment
comment|/* that's not Started */
end_comment

begin_define
define|#
directive|define
name|RSF_ACTIVE
value|66
end_define

begin_comment
comment|/* Active; operation was not Stopped */
end_comment

begin_define
define|#
directive|define
name|RSF_ERROR
value|67
end_define

begin_comment
comment|/* Error condition: send Reset(s) */
end_comment

begin_define
define|#
directive|define
name|RSF_DCPSTER
value|70
end_define

begin_comment
comment|/* DCP chip error, bad status after */
end_comment

begin_comment
comment|/* Start command */
end_comment

begin_define
define|#
directive|define
name|RSF_DCPMODE
value|71
end_define

begin_comment
comment|/* DCP chip error, bad status after */
end_comment

begin_comment
comment|/* mode set */
end_comment

begin_define
define|#
directive|define
name|RSF_DCPRESET
value|73
end_define

begin_comment
comment|/* DCP chip error, bad status */
end_comment

begin_comment
comment|/* after software reset */
end_comment

begin_define
define|#
directive|define
name|RSF_DCPTRN
value|74
end_define

begin_comment
comment|/* DMAC chip error detected; DMAC */
end_comment

begin_comment
comment|/* malfunction during data transfer */
end_comment

end_unit

