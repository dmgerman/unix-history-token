begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* socket.h 4.3 81/11/07 */
end_comment

begin_comment
comment|/*  * User connection block  */
end_comment

begin_struct
struct|struct
name|ucb
block|{
name|struct
name|host
modifier|*
name|uc_host
decl_stmt|;
comment|/* foreign host table entry */
name|struct
name|proc
modifier|*
name|uc_proc
decl_stmt|;
comment|/* user proc */
name|caddr_t
name|uc_pcb
decl_stmt|;
comment|/* protocol control block */
name|struct
name|protosw
modifier|*
name|uc_proto
decl_stmt|;
comment|/* protocol handle */
comment|/* sbuf and rbuf should be uc_s and uc_r which are structures with */
comment|/* fields: s_buf, s_mbmax, s_mbcnt, s_cc, s_ccmax */
name|struct
name|mbuf
modifier|*
name|uc_sbuf
decl_stmt|;
comment|/* user send buffer */
name|u_char
name|uc_snd
decl_stmt|;
comment|/* # send bufs allocated */
name|u_char
name|uc_ssize
decl_stmt|;
comment|/* # bufs on send buffer */
name|short
name|uc_scc
decl_stmt|;
comment|/* not used yet */
name|short
name|uc_shiwat
decl_stmt|;
comment|/* not used yet */
name|struct
name|mbuf
modifier|*
name|uc_rbuf
decl_stmt|;
comment|/* user receive buffer */
name|u_char
name|uc_rcv
decl_stmt|;
comment|/* not used now */
name|u_char
name|uc_rsize
decl_stmt|;
comment|/* not used now */
name|short
name|uc_rcc
decl_stmt|;
name|short
name|uc_rhiwat
decl_stmt|;
name|short
name|uc_timeo
decl_stmt|;
comment|/* open timeout */
name|u_char
name|uc_state
decl_stmt|;
comment|/* state of this connection */
name|u_short
name|uc_flags
decl_stmt|;
comment|/* misc. flags (see below) */
name|struct
name|proc
modifier|*
name|uc_rsel
decl_stmt|;
comment|/* read selecting proc */
block|}
struct|;
end_struct

begin_comment
comment|/* uc_flags field definitions */
end_comment

begin_comment
comment|/* these belong within TCP */
end_comment

begin_define
define|#
directive|define
name|UEOL
value|00001
end_define

begin_comment
comment|/* EOL sent */
end_comment

begin_define
define|#
directive|define
name|UURG
value|00002
end_define

begin_comment
comment|/* urgent data sent */
end_comment

begin_comment
comment|/* end belong in TCP */
end_comment

begin_define
define|#
directive|define
name|UDEBUG
value|00004
end_define

begin_comment
comment|/* turn on debugging info recording */
end_comment

begin_define
define|#
directive|define
name|UTCP
value|00020
end_define

begin_comment
comment|/* SHOULD BE IMPLIED BY uc_proto */
end_comment

begin_define
define|#
directive|define
name|ULISTEN
value|00200
end_define

begin_comment
comment|/* awaiting a connection */
end_comment

begin_define
define|#
directive|define
name|URCOLL
value|01000
end_define

begin_comment
comment|/* someone collided on read select */
end_comment

begin_define
define|#
directive|define
name|URLOCK
value|02000
end_define

begin_comment
comment|/* for uc_rbuf */
end_comment

begin_define
define|#
directive|define
name|URWANT
value|04000
end_define

begin_comment
comment|/* connection state field */
end_comment

begin_define
define|#
directive|define
name|UCLOSED
value|0000
end_define

begin_comment
comment|/* connection closed */
end_comment

begin_define
define|#
directive|define
name|UCLSERR
value|0001
end_define

begin_comment
comment|/* error -- connection closing */
end_comment

begin_define
define|#
directive|define
name|UABORT
value|0002
end_define

begin_comment
comment|/* connection aborted */
end_comment

begin_define
define|#
directive|define
name|UINTIMO
value|0004
end_define

begin_comment
comment|/* open failed -- init timeout */
end_comment

begin_define
define|#
directive|define
name|URXTIMO
value|0010
end_define

begin_comment
comment|/* retransmit too long timeout */
end_comment

begin_define
define|#
directive|define
name|URESET
value|0020
end_define

begin_comment
comment|/* connection aborted due to reset */
end_comment

begin_define
define|#
directive|define
name|UOPERR
value|0040
end_define

begin_comment
comment|/* open failed -- not enough buffers */
end_comment

begin_define
define|#
directive|define
name|UURGENT
value|0100
end_define

begin_comment
comment|/* urgent data received */
end_comment

begin_define
define|#
directive|define
name|UNETDWN
value|0200
end_define

begin_comment
comment|/* connection aborted due to net */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|ucb
modifier|*
name|contab
decl_stmt|,
modifier|*
name|conNCON
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nnetcon
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

