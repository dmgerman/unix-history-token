begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
operator|!
name|defined
name|__recvbuff_h
end_if

begin_define
define|#
directive|define
name|__recvbuff_h
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ntp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_comment
comment|/*  * recvbuf memory management  */
end_comment

begin_define
define|#
directive|define
name|RECV_INIT
value|10
end_define

begin_comment
comment|/* 10 buffers initially */
end_comment

begin_define
define|#
directive|define
name|RECV_LOWAT
value|3
end_define

begin_comment
comment|/* when we're down to three buffers get more */
end_comment

begin_define
define|#
directive|define
name|RECV_INC
value|5
end_define

begin_comment
comment|/* get 5 more at a time */
end_comment

begin_define
define|#
directive|define
name|RECV_TOOMANY
value|40
end_define

begin_comment
comment|/* this is way too many buffers */
end_comment

begin_if
if|#
directive|if
name|defined
name|HAVE_IO_COMPLETION_PORT
end_if

begin_include
include|#
directive|include
file|"ntp_iocompletionport.h"
end_include

begin_include
include|#
directive|include
file|"ntp_timer.h"
end_include

begin_define
define|#
directive|define
name|RECV_BLOCK_IO
parameter_list|()
value|EnterCriticalSection(&RecvCritSection)
end_define

begin_define
define|#
directive|define
name|RECV_UNBLOCK_IO
parameter_list|()
value|LeaveCriticalSection(&RecvCritSection)
end_define

begin_comment
comment|/*  Return the event which is set when items are added to the full list  */
end_comment

begin_decl_stmt
specifier|extern
name|HANDLE
name|get_recv_buff_event
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RECV_BLOCK_IO
parameter_list|()
end_define

begin_define
define|#
directive|define
name|RECV_UNBLOCK_IO
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Format of a recvbuf.  These are used by the asynchronous receive  * routine to store incoming packets and related information.  */
end_comment

begin_comment
comment|/*  *  the maximum length NTP packet is a full length NTP control message with  *  the maximum length message authenticator.  I hate to hard-code 468 and 12,  *  but only a few modules include ntp_control.h...  */
end_comment

begin_define
define|#
directive|define
name|RX_BUFF_SIZE
value|(468+12+MAX_MAC_LEN)
end_define

begin_struct
struct|struct
name|recvbuf
block|{
name|struct
name|recvbuf
modifier|*
name|next
decl_stmt|;
comment|/* next buffer in chain */
union|union
block|{
name|struct
name|sockaddr_in
name|X_recv_srcadr
decl_stmt|;
name|caddr_t
name|X_recv_srcclock
decl_stmt|;
name|struct
name|peer
modifier|*
name|X_recv_peer
decl_stmt|;
block|}
name|X_from_where
union|;
define|#
directive|define
name|recv_srcadr
value|X_from_where.X_recv_srcadr
define|#
directive|define
name|recv_srcclock
value|X_from_where.X_recv_srcclock
define|#
directive|define
name|recv_peer
value|X_from_where.X_recv_peer
if|#
directive|if
name|defined
name|HAVE_IO_COMPLETION_PORT
name|IoCompletionInfo
name|iocompletioninfo
decl_stmt|;
name|WSABUF
name|wsabuff
decl_stmt|;
name|DWORD
name|AddressLength
decl_stmt|;
else|#
directive|else
name|struct
name|sockaddr_in
name|srcadr
decl_stmt|;
comment|/* where packet came from */
endif|#
directive|endif
name|struct
name|interface
modifier|*
name|dstadr
decl_stmt|;
comment|/* interface datagram arrived thru */
name|int
name|fd
decl_stmt|;
comment|/* fd on which it was received */
name|l_fp
name|recv_time
decl_stmt|;
comment|/* time of arrival */
name|void
argument_list|(
argument|*receiver
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|recvbuf
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* routine to receive buffer */
name|int
name|recv_length
decl_stmt|;
comment|/* number of octets received */
union|union
block|{
name|struct
name|pkt
name|X_recv_pkt
decl_stmt|;
name|u_char
name|X_recv_buffer
index|[
name|RX_BUFF_SIZE
index|]
decl_stmt|;
block|}
name|recv_space
union|;
define|#
directive|define
name|recv_pkt
value|recv_space.X_recv_pkt
define|#
directive|define
name|recv_buffer
value|recv_space.X_recv_buffer
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|void
name|init_recvbuff
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* freerecvbuf - make a single recvbuf available for reuse  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|freerecvbuf
name|P
argument_list|(
operator|(
expr|struct
name|recvbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|recvbuf
modifier|*
name|getrecvbufs
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  Get a free buffer (typically used so an async  *  read can directly place data into the buffer  *  *  The buffer is removed from the free list. Make sure  *  you put it back with freerecvbuf() or   */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|recvbuf
modifier|*
name|get_free_recv_buffer
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   Add a buffer to the full list  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|add_full_recv_buffer
name|P
argument_list|(
operator|(
expr|struct
name|recvbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*extern	void	process_recv_buffers	 P((void)); */
end_comment

begin_comment
comment|/* number of recvbufs on freelist */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|free_recvbuffs
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|full_recvbuffs
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|total_recvbuffs
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|lowater_additions
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  Returns the next buffer in the full list.  *  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|recvbuf
modifier|*
name|get_full_recv_buffer
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined __recvbuff_h */
end_comment

end_unit

