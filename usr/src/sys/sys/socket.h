begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* socket.h 4.1 81/10/29 */
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
union|union
block|{
comment|/* protocol control block */
name|char
modifier|*
name|unull
decl_stmt|;
comment|/* general */
name|struct
name|tcb
modifier|*
name|utcb
decl_stmt|;
comment|/* for tcp */
block|}
name|U_cp
union|;
define|#
directive|define
name|uc_tcb
value|U_cp.utcb
name|struct
name|mbuf
modifier|*
name|uc_sbuf
decl_stmt|;
comment|/* user send buffer */
name|struct
name|mbuf
modifier|*
name|uc_rbuf
decl_stmt|;
comment|/* user receive buffer */
name|u_char
name|uc_lolink
decl_stmt|;
comment|/* lowest link no. in range (raw) */
name|u_char
name|uc_hilink
decl_stmt|;
comment|/* highest link no. in range (raw) */
name|u_char
name|uc_snd
decl_stmt|;
comment|/* # send bufs allocated */
name|u_char
name|uc_ssize
decl_stmt|;
comment|/* # bufs on send buffer */
define|#
directive|define
name|uc_timeo
value|uc_ssize
comment|/* user timeout parameter */
name|short
name|uc_rhiwat
decl_stmt|;
name|short
name|uc_rcc
decl_stmt|;
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
name|struct
name|th
modifier|*
name|uc_template
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|th
modifier|*
name|tcp_template
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* uc_flags field definitions */
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
comment|/* this is a TCP connection */
end_comment

begin_define
define|#
directive|define
name|UIP
value|00040
end_define

begin_comment
comment|/* this is a raw IP connection */
end_comment

begin_define
define|#
directive|define
name|URAW
value|00100
end_define

begin_comment
comment|/* this is a raw 1822 connection */
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
name|UCTL
value|00400
end_define

begin_comment
comment|/* this is a control port only */
end_comment

begin_define
define|#
directive|define
name|URMSK
value|00560
end_define

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

