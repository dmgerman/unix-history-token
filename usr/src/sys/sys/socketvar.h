begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* socketvar.h 4.1 81/11/07 */
end_comment

begin_comment
comment|/*  * Kernel structure per socket.  * Contains send and receive buffer queues,  * handle on protocol and pointer to protocol  * private data and error information.  */
end_comment

begin_struct
struct|struct
name|socket
block|{
name|short
name|so_type
decl_stmt|;
comment|/* generic type, see socket.h */
name|short
name|so_options
decl_stmt|;
comment|/* from socket call, see socket.h */
name|caddr_t
name|so_pcb
decl_stmt|;
comment|/* protocol control block */
name|struct
name|protosw
modifier|*
name|so_proto
decl_stmt|;
comment|/* protocol handle */
struct|struct
name|sockbuf
block|{
name|short
name|sb_cc
decl_stmt|;
comment|/* characters in buffer */
name|short
name|sb_hiwat
decl_stmt|;
comment|/* max chars for buffer */
name|short
name|sb_mbcnt
decl_stmt|;
comment|/* # mbufs in use */
name|short
name|sb_mbmax
decl_stmt|;
comment|/* max # mbufs to use */
name|short
name|sb_lowat
decl_stmt|;
comment|/* low water mark (not used yet) */
name|short
name|sb_timeo
decl_stmt|;
comment|/* timeout (not used yet) */
name|struct
name|mbuf
modifier|*
name|sb_mb
decl_stmt|;
comment|/* the mbuf chain */
name|struct
name|proc
modifier|*
name|sb_sel
decl_stmt|;
comment|/* process selecting read/write */
name|short
name|sb_flags
decl_stmt|;
comment|/* flags, see below */
block|}
name|so_rcv
struct|,
name|so_snd
struct|;
define|#
directive|define
name|SB_LOCK
value|0x01
comment|/* lock on data queue (so_rcv only) */
define|#
directive|define
name|SB_WANT
value|0x02
comment|/* someone is waiting to lock */
define|#
directive|define
name|SB_WAIT
value|0x04
comment|/* someone is waiting for data/space */
define|#
directive|define
name|SB_SEL
value|0x08
comment|/* buffer is selected */
define|#
directive|define
name|SB_COLL
value|0x10
comment|/* collision selecting */
comment|/* need something for async wakeup */
name|short
name|so_timeo
decl_stmt|;
comment|/* connection timeout */
name|u_short
name|so_error
decl_stmt|;
comment|/* error indicator */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Option bits and socket types are defined in socket.h.  */
end_comment

end_unit

