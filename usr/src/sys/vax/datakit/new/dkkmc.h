begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	kmc and cpu interface  *		@(#)dkkmc.h	1.2 Garage 84/03/27  */
end_comment

begin_comment
comment|/*  *  structure for each datakit channel  */
end_comment

begin_struct
struct|struct
name|dkchan
block|{
name|short
name|dk_state
decl_stmt|;
name|struct
name|ifqueue
name|dk_outq
decl_stmt|;
comment|/* Output queue */
name|struct
name|mpacket
modifier|*
name|dk_obuf
decl_stmt|;
comment|/* Active mbuf output chain */
name|struct
name|mbuf
modifier|*
name|dk_pending
decl_stmt|;
comment|/* Rest of current mbuf chain */
name|struct
name|ifuba
name|dk_uba
decl_stmt|;
name|int
function_decl|(
modifier|*
name|dk_endfcn
function_decl|)
parameter_list|()
function_decl|;
name|caddr_t
name|dk_endparm
decl_stmt|;
name|int
function_decl|(
modifier|*
name|dk_supfcn
function_decl|)
parameter_list|()
function_decl|;
name|unsigned
name|dk_rlen
decl_stmt|;
comment|/* length of receive buffer */
name|int
name|dk_ubmbase
decl_stmt|;
comment|/* ubm base register used for this receive transaction */
comment|/* only one receive pending at a time on a channel */
block|}
struct|;
end_struct

begin_comment
comment|/*  * structure for command to kmc from cpu and  * report to cpu from kmc  */
end_comment

begin_struct
struct|struct
name|dkkin
block|{
name|short
name|k_type
decl_stmt|;
comment|/* cmd type or report type */
name|short
name|k_chan
decl_stmt|;
comment|/* chan number */
name|short
name|k_len
decl_stmt|;
comment|/* # of char */
name|char
name|k_ctl
decl_stmt|;
comment|/* cntl/time */
name|char
name|k_mode
decl_stmt|;
comment|/* rcv mode */
name|long
name|k_addr
decl_stmt|;
comment|/* address */
block|}
struct|;
end_struct

begin_comment
comment|/*  * command type  */
end_comment

begin_define
define|#
directive|define
name|KC_INIT
value|0x01
end_define

begin_comment
comment|/* init: 0,0,0,0 */
end_comment

begin_define
define|#
directive|define
name|KC_SEND
value|0x02
end_define

begin_comment
comment|/* send: len, 0, 0, addr */
end_comment

begin_define
define|#
directive|define
name|KC_RCVB
value|0x03
end_define

begin_comment
comment|/* rcv: len, time, mode, addr */
end_comment

begin_define
define|#
directive|define
name|KC_CLOSE
value|0x04
end_define

begin_comment
comment|/* close: 0, 0, 0, 0 */
end_comment

begin_define
define|#
directive|define
name|KC_XINIT
value|0x05
end_define

begin_comment
comment|/* re-init xmitter: 0, 0, 0, 0 */
end_comment

begin_define
define|#
directive|define
name|KC_CMD
value|0x06
end_define

begin_comment
comment|/* cmd to kmc: cmd, 0, 0, 0 */
end_comment

begin_define
define|#
directive|define
name|KC_FLAG
value|0x07
end_define

begin_comment
comment|/* i/oflag: iflag, oflaghi, oflaglo, 0 */
end_comment

begin_define
define|#
directive|define
name|KC_SOI
value|0x08
end_define

begin_comment
comment|/* send express: (byte2<<8)|byte1, 0, 0, 0 */
end_comment

begin_define
define|#
directive|define
name|KC_SCTL
value|0x09
end_define

begin_comment
comment|/* send cntl: ctl, 0, 0, 0 */
end_comment

begin_comment
comment|/*  * report type  */
end_comment

begin_define
define|#
directive|define
name|KS_SEND
value|0x0014
end_define

begin_comment
comment|/* send: 0, 0, 0, 0 */
end_comment

begin_define
define|#
directive|define
name|KS_RDB
value|0x0015
end_define

begin_comment
comment|/* rcv: residue len, cntl, mode, 0 */
end_comment

begin_define
define|#
directive|define
name|KS_EOI
value|0x0016
end_define

begin_comment
comment|/* rcv express: (byte2<<8)|byte1, 0, 0, 0 */
end_comment

begin_define
define|#
directive|define
name|KS_CNTL
value|0x0017
end_define

begin_comment
comment|/* rcv tdk cntl: cntl, 0, 0, 0 */
end_comment

begin_define
define|#
directive|define
name|KS_ERR
value|0x0018
end_define

begin_comment
comment|/* error: code, 0, 0, 0 */
end_comment

begin_comment
comment|/*  * The circular buffer, cmdbuf, is used to pass command to kmc:  * while the circular buffer statbuf is used to report status.  * There are 8 control and status registers (csr) accessible to  * both cpu and kmc.  * Csr4-csr5 are iused to indicate the head and tail respectively  * of the cmdbuf.  Likewise, csr6-csr7 for statbuf.  * At initialization time, the cpu and kmc would agree on the beginning  * address of both buffers and their sizes.  */
end_comment

begin_comment
comment|/*  * sub command bits for KC_CMD  */
end_comment

begin_define
define|#
directive|define
name|OFLUSH
value|(1<<1)
end_define

begin_comment
comment|/* Flush output */
end_comment

begin_define
define|#
directive|define
name|OSPND
value|(1<<2)
end_define

begin_comment
comment|/* Suspend output */
end_comment

begin_define
define|#
directive|define
name|ORSME
value|(1<<3)
end_define

begin_comment
comment|/* Resume output */
end_comment

begin_comment
comment|/*  * KC_RCV mode  */
end_comment

begin_define
define|#
directive|define
name|RCBLOCK
value|(1<<5)
end_define

begin_comment
comment|/* return on block boundary */
end_comment

begin_define
define|#
directive|define
name|RCTIME
value|(1<<6)
end_define

begin_comment
comment|/* return on time expires */
end_comment

begin_comment
comment|/*  * KS_RDB mode  */
end_comment

begin_define
define|#
directive|define
name|SFULL
value|(1<<0)
end_define

begin_comment
comment|/* buffer full */
end_comment

begin_define
define|#
directive|define
name|SCNTL
value|(1<<1)
end_define

begin_comment
comment|/* cntl char rcv */
end_comment

begin_define
define|#
directive|define
name|SBLOCK
value|(1<<5)
end_define

begin_comment
comment|/* block boundary */
end_comment

begin_define
define|#
directive|define
name|STIME
value|(1<<6)
end_define

begin_comment
comment|/* time limit expired */
end_comment

begin_define
define|#
directive|define
name|SABORT
value|(1<<3)
end_define

begin_comment
comment|/* rcv aborted */
end_comment

begin_comment
comment|/*  * KC_SEND mode  */
end_comment

begin_define
define|#
directive|define
name|SBOT
value|0
end_define

begin_comment
comment|/* End blocks with BOT */
end_comment

begin_define
define|#
directive|define
name|SBOTM
value|0x80
end_define

begin_comment
comment|/* End blocks with BOTM */
end_comment

begin_comment
comment|/*  * KS_ERR codes */
end_comment

begin_define
define|#
directive|define
name|E_SW
value|0x00
end_define

begin_comment
comment|/* dispatcher switch */
end_comment

begin_define
define|#
directive|define
name|E_BUS
value|0x01
end_define

begin_comment
comment|/* Unibus error */
end_comment

begin_define
define|#
directive|define
name|E_IPANIC
value|0x02
end_define

begin_comment
comment|/* input routine panic */
end_comment

begin_define
define|#
directive|define
name|E_CMD
value|0x03
end_define

begin_comment
comment|/* command unknown */
end_comment

begin_define
define|#
directive|define
name|E_NOQB
value|0x04
end_define

begin_comment
comment|/* run out of queue or buffer */
end_comment

begin_define
define|#
directive|define
name|E_DUP
value|0x05
end_define

begin_comment
comment|/* duplicate SEND */
end_comment

begin_define
define|#
directive|define
name|E_ODKOVF
value|0x06
end_define

begin_comment
comment|/* output routine panic */
end_comment

begin_define
define|#
directive|define
name|E_UMETA
value|0x07
end_define

begin_comment
comment|/* un-recognized cntl char */
end_comment

begin_define
define|#
directive|define
name|E_SYS1
value|0x0021
end_define

begin_comment
comment|/* system error 1 (041) */
end_comment

begin_define
define|#
directive|define
name|E_SYS2
value|0x0022
end_define

begin_comment
comment|/* system error 2 (042) */
end_comment

end_unit

