begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RCSID("$Id: channels.h,v 1.6 1999/11/24 19:53:45 markus Exp $"); */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CHANNELS_H
end_ifndef

begin_define
define|#
directive|define
name|CHANNELS_H
end_define

begin_comment
comment|/* Definitions for channel types. */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_FREE
value|0
end_define

begin_comment
comment|/* This channel is free (unused). */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_X11_LISTENER
value|1
end_define

begin_comment
comment|/* Listening for inet X11 conn. */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_PORT_LISTENER
value|2
end_define

begin_comment
comment|/* Listening on a port. */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_OPENING
value|3
end_define

begin_comment
comment|/* waiting for confirmation */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_OPEN
value|4
end_define

begin_comment
comment|/* normal open two-way channel */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_CLOSED
value|5
end_define

begin_comment
comment|/* waiting for close confirmation */
end_comment

begin_comment
comment|/*	SSH_CHANNEL_AUTH_FD		6    	   authentication fd */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_AUTH_SOCKET
value|7
end_define

begin_comment
comment|/* authentication socket */
end_comment

begin_comment
comment|/*	SSH_CHANNEL_AUTH_SOCKET_FD	8    	   connection to auth socket */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_X11_OPEN
value|9
end_define

begin_comment
comment|/* reading first X11 packet */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_INPUT_DRAINING
value|10
end_define

begin_comment
comment|/* sending remaining data to conn */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_OUTPUT_DRAINING
value|11
end_define

begin_comment
comment|/* sending remaining data to app */
end_comment

begin_comment
comment|/*  * Data structure for channel data.  This is iniailized in channel_allocate  * and cleared in channel_free.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Channel
block|{
name|int
name|type
decl_stmt|;
comment|/* channel type/state */
name|int
name|self
decl_stmt|;
comment|/* my own channel identifier */
name|int
name|remote_id
decl_stmt|;
comment|/* channel identifier for remote peer */
comment|/* peer can be reached over encrypted connection, via packet-sent */
name|int
name|istate
decl_stmt|;
comment|/* input from channel (state of receive half) */
name|int
name|ostate
decl_stmt|;
comment|/* output to channel  (state of transmit half) */
name|int
name|sock
decl_stmt|;
comment|/* data socket, linked to this channel */
name|Buffer
name|input
decl_stmt|;
comment|/* data read from socket, to be sent over 				 * encrypted connection */
name|Buffer
name|output
decl_stmt|;
comment|/* data received over encrypted connection for 				 * send on socket */
name|char
name|path
index|[
literal|200
index|]
decl_stmt|;
comment|/* path for unix domain sockets, or host name 				 * for forwards */
name|int
name|listening_port
decl_stmt|;
comment|/* port being listened for forwards */
name|int
name|host_port
decl_stmt|;
comment|/* remote port to connect for forwards */
name|char
modifier|*
name|remote_name
decl_stmt|;
comment|/* remote hostname */
block|}
name|Channel
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

