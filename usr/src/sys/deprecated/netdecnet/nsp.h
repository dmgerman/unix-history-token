begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	nsp.h	1.3	82/10/09	*/
end_comment

begin_comment
comment|/*  * DECnet Network Services Protocol definitions,  * per Network Services Protocol Functional Specification,  * Version 3.2.0, October 1980.  */
end_comment

begin_comment
comment|/*  * NSP message types  */
end_comment

begin_define
define|#
directive|define
name|NSP_DATA
value|0x00
end_define

begin_comment
comment|/* data segment message */
end_comment

begin_define
define|#
directive|define
name|NSP_LS
value|0x10
end_define

begin_comment
comment|/* link service message */
end_comment

begin_define
define|#
directive|define
name|NSP_INTR
value|0x30
end_define

begin_comment
comment|/* interrupt message */
end_comment

begin_define
define|#
directive|define
name|NSP_DATACK
value|0x04
end_define

begin_comment
comment|/* data segment ack */
end_comment

begin_define
define|#
directive|define
name|NSP_OTHACK
value|0x14
end_define

begin_comment
comment|/* other data ack */
end_comment

begin_define
define|#
directive|define
name|NSP_CONACK
value|0x24
end_define

begin_comment
comment|/* connect ack */
end_comment

begin_define
define|#
directive|define
name|NSP_NOP
value|0x08
end_define

begin_comment
comment|/* no op */
end_comment

begin_define
define|#
directive|define
name|NSP_CI
value|0x18
end_define

begin_comment
comment|/* connect initiate */
end_comment

begin_define
define|#
directive|define
name|NSP_CC
value|0x28
end_define

begin_comment
comment|/* connect confirm */
end_comment

begin_define
define|#
directive|define
name|NSP_DI
value|0x38
end_define

begin_comment
comment|/* disconnect initiate */
end_comment

begin_define
define|#
directive|define
name|NSP_DC
value|0x48
end_define

begin_comment
comment|/* disconnect confirm */
end_comment

begin_comment
comment|/* flags for data segment messages */
end_comment

begin_define
define|#
directive|define
name|NSP_BOM
value|0x20
end_define

begin_comment
comment|/* beginning-of-message segment */
end_comment

begin_define
define|#
directive|define
name|NSP_EOM
value|0x40
end_define

begin_comment
comment|/* end-of-message segment */
end_comment

begin_comment
comment|/*  * Data segment message  */
end_comment

begin_struct
struct|struct
name|nspd
block|{
name|char
name|nsp_msgflg
decl_stmt|;
comment|/* message type and flags */
name|d_short
name|nsp_dstaddr
decl_stmt|;
comment|/* destination address * 	d_short	nsp_srcaddr;		/* source address */
name|d_short
name|nsp_acknum
decl_stmt|;
comment|/* number of ack'ed message */
name|d_short
name|nsp_segnum
decl_stmt|;
comment|/* this message's segment number */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Interrupt message  */
end_comment

begin_struct
struct|struct
name|nspi
block|{
name|char
name|nsp_msgflg
decl_stmt|;
comment|/* message type and flags */
name|d_short
name|nsp_dstaddr
decl_stmt|;
comment|/* destination address * 	d_short	nsp_srcaddr;		/* source address */
name|d_short
name|nsp_acknum
decl_stmt|;
comment|/* number of ack'ed message */
name|d_short
name|nsp_segnum
decl_stmt|;
comment|/* this message's segment number */
comment|/* optional data follows */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Link Service message  */
end_comment

begin_struct
struct|struct
name|nspls
block|{
name|char
name|nsp_msgflg
decl_stmt|;
comment|/* message type and flags */
name|d_short
name|nsp_dstaddr
decl_stmt|;
comment|/* destination address * 	d_short	nsp_srcaddr;		/* source address */
name|d_short
name|nsp_acknum
decl_stmt|;
comment|/* number of ack'ed message */
name|d_short
name|nsp_segnum
decl_stmt|;
comment|/* this message's segment number */
name|char
name|nsp_lsflags
decl_stmt|;
comment|/* link service flags */
name|char
name|nsp_fcval
decl_stmt|;
comment|/* flow control change value */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NSPLS_FCVALINT
value|0x0c
end_define

begin_comment
comment|/* fcval field interpretation: */
end_comment

begin_define
define|#
directive|define
name|NSPLS_DATREQ
value|0x00
end_define

begin_comment
comment|/*   data segment request */
end_comment

begin_define
define|#
directive|define
name|NSPLS_INTREQ
value|0x04
end_define

begin_comment
comment|/*   interrupt request */
end_comment

begin_define
define|#
directive|define
name|NSPLS_FCMOD
value|0x03
end_define

begin_comment
comment|/* flow control modification: */
end_comment

begin_define
define|#
directive|define
name|NSPLS_NOCHANGE
value|0x00
end_define

begin_comment
comment|/*   no change */
end_comment

begin_define
define|#
directive|define
name|NSPLS_OFF
value|0x01
end_define

begin_comment
comment|/*   do not send data */
end_comment

begin_define
define|#
directive|define
name|NSPLS_ON
value|0x02
end_define

begin_comment
comment|/*   send data */
end_comment

begin_comment
comment|/*  * Data or Other Data Ack  */
end_comment

begin_struct
struct|struct
name|nspack
block|{
name|char
name|nsp_msgflg
decl_stmt|;
comment|/* message type and flags */
name|d_short
name|nsp_dstaddr
decl_stmt|;
comment|/* destination address * 	d_short	nsp_srcaddr;		/* source address */
name|d_short
name|nsp_acknum
decl_stmt|;
comment|/* number of ack'ed message */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NSPA_ACK
value|0x8000
end_define

begin_comment
comment|/* ack flag for acknum */
end_comment

begin_define
define|#
directive|define
name|NSPA_NAK
value|0x9000
end_define

begin_comment
comment|/* nak flag for acknum */
end_comment

begin_define
define|#
directive|define
name|NSPA_QUAL
value|0xf000
end_define

begin_comment
comment|/* qual field for acknum */
end_comment

begin_define
define|#
directive|define
name|NSPA_NUM
value|0x0fff
end_define

begin_comment
comment|/* num field for acknum */
end_comment

begin_comment
comment|/*  * Connect Ack  */
end_comment

begin_struct
struct|struct
name|nspcack
block|{
name|char
name|nsp_msgflg
decl_stmt|;
comment|/* message type and flags */
name|d_short
name|nsp_dstaddr
decl_stmt|;
comment|/* destination address * };  /*  * No Op message  */
struct|struct
name|nspnop
block|{
name|char
name|nsp_msgflg
decl_stmt|;
comment|/* message type and flags */
comment|/* tstdata follows */
block|}
struct|;
comment|/*  * Connect Initiate message  */
struct|struct
name|nspci
block|{
name|char
name|nsp_msgflg
decl_stmt|;
comment|/* message type and flags */
name|d_short
name|nsp_dstaddr
decl_stmt|;
comment|/* destination address * 	d_short	nsp_srcaddr;		/* source address */
name|char
name|nsp_services
decl_stmt|;
comment|/* flow control options */
name|char
name|nsp_info
decl_stmt|;
comment|/* NSP version info */
name|d_short
name|nsp_segsize
decl_stmt|;
comment|/* requested segment size */
comment|/* connect data follows */
block|}
struct|;
comment|/*  * Connect Confirm message  */
struct|struct
name|nspcc
block|{
name|char
name|nsp_msgflg
decl_stmt|;
comment|/* message type and flags */
name|d_short
name|nsp_dstaddr
decl_stmt|;
comment|/* destination address * 	d_short	nsp_srcaddr;		/* source address */
name|char
name|nsp_services
decl_stmt|;
comment|/* flow control options */
name|char
name|nsp_info
decl_stmt|;
comment|/* NSP version info */
name|d_short
name|nsp_segsize
decl_stmt|;
comment|/* requested segment size */
name|char
name|nsp_cnt
decl_stmt|;
comment|/* size of optional data field */
comment|/* optional connect data follows */
block|}
struct|;
comment|/*  * Disconnect Initiate message  */
struct|struct
name|nspdi
block|{
name|char
name|nsp_msgflg
decl_stmt|;
comment|/* message type and flags */
name|d_short
name|nsp_dstaddr
decl_stmt|;
comment|/* destination address * 	d_short	nsp_srcaddr;		/* source address */
name|d_short
name|nsp_reason
decl_stmt|;
comment|/* reason for disconnect */
name|char
name|nsp_dcnt
decl_stmt|;
comment|/* size of optional data field */
comment|/* optional disconnect data follows */
block|}
struct|;
comment|/*  * Disconnect Confirm message  */
struct|struct
name|nspdc
block|{
name|char
name|nsp_msgflg
decl_stmt|;
comment|/* message type and flags */
name|d_short
name|nsp_dstaddr
decl_stmt|;
comment|/* destination address * 	d_short	nsp_srcaddr;		/* source address */
name|d_short
name|nsp_reason
decl_stmt|;
comment|/* disconnect reason */
block|}
struct|;
end_struct

end_unit

