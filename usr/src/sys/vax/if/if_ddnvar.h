begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)if_ddnvar.h	7.1 (Berkeley) 6/5/86 */
end_comment

begin_comment
comment|/************************************************************************\       ________________________________________________________     /                                                        \    |          AAA          CCCCCCCCCCCCCC    CCCCCCCCCCCCCC   |    |         AAAAA        CCCCCCCCCCCCCCCC  CCCCCCCCCCCCCCCC  |    |        AAAAAAA       CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |    |       AAAA AAAA      CCCC              CCCC              |    |      AAAA   AAAA     CCCC              CCCC              |    |     AAAA     AAAA    CCCC              CCCC              |    |    AAAA       AAAA   CCCC              CCCC              |    |   AAAA  AAAAAAAAAAA  CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |    |  AAAA    AAAAAAAAAAA CCCCCCCCCCCCCCCC  CCCCCCCCCCCCCCCC  |    | AAAA      AAAAAAAAA   CCCCCCCCCCCCCC    CCCCCCCCCCCCCC   |     \________________________________________________________/  	Copyright (c) 1985 by Advanced Computer Communications 	720 Santa Barbara Street, Santa Barbara, California  93101 	(805) 963-9431  	This software may be duplicated and used on systems 	which are licensed to run U.C. Berkeley versions of 	the UNIX operating system.  Any duplication of any 	part of this software must include a copy of ACC's 	copyright notice.   File: 		if_ddnvar.h  Author: 		Art Berggreen  Project: 		4.2 DDN X.25 network driver  Function: 		This file contains definitions used to control and 		track the status of the ACP625 (IF-11/X25).  Components:  Revision History: 		16-May-1985:	V1.0 - First release. 				Art Berggreen.  \************************************************************************/
end_comment

begin_escape
end_escape

begin_comment
comment|/*	if_ddnvar.h	 V1.0	5/16/85	*/
end_comment

begin_comment
comment|/* program parameters */
end_comment

begin_define
define|#
directive|define
name|DDNMTU
value|1006
end_define

begin_comment
comment|/* maximum IP msg length */
end_comment

begin_define
define|#
directive|define
name|DDN_OQMAX
value|8
end_define

begin_comment
comment|/* max IP msgs on LCN output q */
end_comment

begin_define
define|#
directive|define
name|NDDNCH
value|32
end_define

begin_comment
comment|/* number of X.25 channels */
end_comment

begin_define
define|#
directive|define
name|DELAY_CNT
value|50000
end_define

begin_define
define|#
directive|define
name|DDN_TIMEOUT
value|10
end_define

begin_define
define|#
directive|define
name|DC_OBUSY
value|0x01
end_define

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
comment|/* X25 LCN state definitions */
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
comment|/* Timeout definitions */
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
value|( 90/DDN_TIMEOUT)
end_define

begin_comment
comment|/* restart timeout	*/
end_comment

begin_define
define|#
directive|define
name|TMO_CALL_PENDING
value|(180/DDN_TIMEOUT)
end_define

begin_comment
comment|/* call timeout		*/
end_comment

begin_define
define|#
directive|define
name|TMO_DATA_IDLE
value|( 30/DDN_TIMEOUT)
end_define

begin_comment
comment|/* idle circuit timeout	*/
end_comment

begin_define
define|#
directive|define
name|TMO_CLR_PENDING
value|( 30/DDN_TIMEOUT)
end_define

begin_comment
comment|/* clear timeout	*/
end_comment

begin_comment
comment|/* Link status codes */
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

begin_comment
comment|/* Line control codes */
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
name|LOOP_OFF
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
name|PKT_SIZE
value|0x90
end_define

begin_comment
comment|/* Packet size			*/
end_comment

begin_define
define|#
directive|define
name|PKT_WINDOW
value|0x4f
end_define

begin_comment
comment|/* Packet window		*/
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

begin_comment
comment|/* X25 facilities */
end_comment

begin_define
define|#
directive|define
name|X25_FACIL_DDN
value|0x04
end_define

begin_comment
comment|/* DDN mode facility		*/
end_comment

begin_define
define|#
directive|define
name|FAC_DDNSTD
value|0x01
end_define

begin_comment
comment|/*   DDN standard mode		*/
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

end_unit

