begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|RECVBUFF_H
end_ifndef

begin_define
define|#
directive|define
name|RECVBUFF_H
end_define

begin_include
include|#
directive|include
file|"ntp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_net.h"
end_include

begin_include
include|#
directive|include
file|"ntp_lists.h"
end_include

begin_include
include|#
directive|include
file|<isc/result.h>
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

begin_function_decl
specifier|extern
name|HANDLE
name|get_recv_buff_event
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
comment|/*  *  the maximum length NTP packet contains the NTP header, one Autokey  *  request, one Autokey response and the MAC. Assuming certificates don't  *  get too big, the maximum packet length is set arbitrarily at 1000.  */
end_comment

begin_define
define|#
directive|define
name|RX_BUFF_SIZE
value|1000
end_define

begin_comment
comment|/* hail Mary */
end_comment

begin_typedef
typedef|typedef
name|struct
name|recvbuf
name|recvbuf_t
typedef|;
end_typedef

begin_struct
struct|struct
name|recvbuf
block|{
name|recvbuf_t
modifier|*
name|link
decl_stmt|;
comment|/* next in list */
union|union
block|{
name|sockaddr_u
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
ifndef|#
directive|ifndef
name|HAVE_IO_COMPLETION_PORT
name|sockaddr_u
name|srcadr
decl_stmt|;
comment|/* where packet came from */
else|#
directive|else
name|int
name|recv_srcadr_len
decl_stmt|;
comment|/* filled in on completion */
endif|#
directive|endif
name|endpt
modifier|*
name|dstadr
decl_stmt|;
comment|/* address pkt arrived on */
name|SOCKET
name|fd
decl_stmt|;
comment|/* fd on which it was received */
name|int
name|msg_flags
decl_stmt|;
comment|/* Flags received about the packet */
name|l_fp
name|recv_time
decl_stmt|;
comment|/* time of arrival */
name|void
function_decl|(
modifier|*
name|receiver
function_decl|)
parameter_list|(
name|struct
name|recvbuf
modifier|*
parameter_list|)
function_decl|;
comment|/* callback */
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
name|int
name|used
decl_stmt|;
comment|/* reference count */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|init_recvbuff
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* freerecvbuf - make a single recvbuf available for reuse  */
end_comment

begin_function_decl
specifier|extern
name|void
name|freerecvbuf
parameter_list|(
name|struct
name|recvbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  Get a free buffer (typically used so an async  *  read can directly place data into the buffer  *  *  The buffer is removed from the free list. Make sure  *  you put it back with freerecvbuf() or   */
end_comment

begin_comment
comment|/* signal safe - no malloc */
end_comment

begin_function_decl
specifier|extern
name|struct
name|recvbuf
modifier|*
name|get_free_recv_buffer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* signal unsafe - may malloc */
end_comment

begin_function_decl
specifier|extern
name|struct
name|recvbuf
modifier|*
name|get_free_recv_buffer_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*   Add a buffer to the full list  */
end_comment

begin_function_decl
specifier|extern
name|void
name|add_full_recv_buffer
parameter_list|(
name|struct
name|recvbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* number of recvbufs on freelist */
end_comment

begin_function_decl
specifier|extern
name|u_long
name|free_recvbuffs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
name|full_recvbuffs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
name|total_recvbuffs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
name|lowater_additions
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  Returns the next buffer in the full list.  *  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|recvbuf
modifier|*
name|get_full_recv_buffer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * purge_recv_buffers_for_fd() - purges any previously-received input  *				 from a given file descriptor.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|purge_recv_buffers_for_fd
parameter_list|(
name|SOCKET
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Checks to see if there are buffers to process  */
end_comment

begin_function_decl
specifier|extern
name|isc_boolean_t
name|has_full_recv_buffer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RECVBUFF_H */
end_comment

end_unit

