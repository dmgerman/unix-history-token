begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* RCSID("$OpenBSD: channels.h,v 1.31 2001/04/13 22:46:53 beck Exp $"); */
end_comment

begin_comment
comment|/* RCSID("$FreeBSD$"); */
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

begin_include
include|#
directive|include
file|"buffer.h"
end_include

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

begin_define
define|#
directive|define
name|SSH_CHANNEL_AUTH_SOCKET
value|6
end_define

begin_comment
comment|/* authentication socket */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_X11_OPEN
value|7
end_define

begin_comment
comment|/* reading first X11 packet */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_INPUT_DRAINING
value|8
end_define

begin_comment
comment|/* sending remaining data to conn */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_OUTPUT_DRAINING
value|9
end_define

begin_comment
comment|/* sending remaining data to app */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_LARVAL
value|10
end_define

begin_comment
comment|/* larval session */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_RPORT_LISTENER
value|11
end_define

begin_comment
comment|/* Listening to a R-style port  */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_CONNECTING
value|12
end_define

begin_define
define|#
directive|define
name|SSH_CHANNEL_DYNAMIC
value|13
end_define

begin_define
define|#
directive|define
name|SSH_CHANNEL_MAX_TYPE
value|14
end_define

begin_comment
comment|/*  * Data structure for channel data.  This is iniailized in channel_allocate  * and cleared in channel_free.  */
end_comment

begin_struct_decl
struct_decl|struct
name|Channel
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|Channel
name|Channel
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|channel_callback_fn
parameter_list|(
name|int
name|id
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|channel_filter_fn
parameter_list|(
name|struct
name|Channel
modifier|*
name|c
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_typedef

begin_struct
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
name|flags
decl_stmt|;
comment|/* close sent/rcvd */
name|int
name|rfd
decl_stmt|;
comment|/* read fd */
name|int
name|wfd
decl_stmt|;
comment|/* write fd */
name|int
name|efd
decl_stmt|;
comment|/* extended fd */
name|int
name|sock
decl_stmt|;
comment|/* sock fd */
name|int
name|isatty
decl_stmt|;
comment|/* rfd is a tty */
name|Buffer
name|input
decl_stmt|;
comment|/* data read from socket, to be sent over 				 * encrypted connection */
name|Buffer
name|output
decl_stmt|;
comment|/* data received over encrypted connection for 				 * send on socket */
name|Buffer
name|extended
decl_stmt|;
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
name|int
name|remote_window
decl_stmt|;
name|int
name|remote_maxpacket
decl_stmt|;
name|int
name|local_window
decl_stmt|;
name|int
name|local_window_max
decl_stmt|;
name|int
name|local_consumed
decl_stmt|;
name|int
name|local_maxpacket
decl_stmt|;
name|int
name|extended_usage
decl_stmt|;
name|char
modifier|*
name|ctype
decl_stmt|;
comment|/* type */
comment|/* callback */
name|channel_callback_fn
modifier|*
name|cb_fn
decl_stmt|;
name|void
modifier|*
name|cb_arg
decl_stmt|;
name|int
name|cb_event
decl_stmt|;
name|channel_callback_fn
modifier|*
name|dettach_user
decl_stmt|;
comment|/* filter */
name|channel_filter_fn
modifier|*
name|input_filter
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CHAN_EXTENDED_IGNORE
value|0
end_define

begin_define
define|#
directive|define
name|CHAN_EXTENDED_READ
value|1
end_define

begin_define
define|#
directive|define
name|CHAN_EXTENDED_WRITE
value|2
end_define

begin_comment
comment|/* default window/packet sizes for tcp/x11-fwd-channel */
end_comment

begin_define
define|#
directive|define
name|CHAN_SES_WINDOW_DEFAULT
value|(32*1024)
end_define

begin_define
define|#
directive|define
name|CHAN_SES_PACKET_DEFAULT
value|(CHAN_SES_WINDOW_DEFAULT/2)
end_define

begin_define
define|#
directive|define
name|CHAN_TCP_WINDOW_DEFAULT
value|(32*1024)
end_define

begin_define
define|#
directive|define
name|CHAN_TCP_PACKET_DEFAULT
value|(CHAN_TCP_WINDOW_DEFAULT/2)
end_define

begin_define
define|#
directive|define
name|CHAN_X11_WINDOW_DEFAULT
value|(4*1024)
end_define

begin_define
define|#
directive|define
name|CHAN_X11_PACKET_DEFAULT
value|(CHAN_X11_WINDOW_DEFAULT/2)
end_define

begin_function_decl
name|void
name|channel_open
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_request
parameter_list|(
name|int
name|id
parameter_list|,
name|char
modifier|*
name|service
parameter_list|,
name|int
name|wantconfirm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_request_start
parameter_list|(
name|int
name|id
parameter_list|,
name|char
modifier|*
name|service
parameter_list|,
name|int
name|wantconfirm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_register_callback
parameter_list|(
name|int
name|id
parameter_list|,
name|int
name|mtype
parameter_list|,
name|channel_callback_fn
modifier|*
name|fn
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_register_cleanup
parameter_list|(
name|int
name|id
parameter_list|,
name|channel_callback_fn
modifier|*
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_register_filter
parameter_list|(
name|int
name|id
parameter_list|,
name|channel_filter_fn
modifier|*
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_cancel_cleanup
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Channel
modifier|*
name|channel_lookup
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_new
parameter_list|(
name|char
modifier|*
name|ctype
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rfd
parameter_list|,
name|int
name|wfd
parameter_list|,
name|int
name|efd
parameter_list|,
name|int
name|window
parameter_list|,
name|int
name|maxpack
parameter_list|,
name|int
name|extended_usage
parameter_list|,
name|char
modifier|*
name|remote_name
parameter_list|,
name|int
name|nonblock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_set_fds
parameter_list|(
name|int
name|id
parameter_list|,
name|int
name|rfd
parameter_list|,
name|int
name|wfd
parameter_list|,
name|int
name|efd
parameter_list|,
name|int
name|extusage
parameter_list|,
name|int
name|nonblock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|deny_input_open
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|plen
parameter_list|,
name|void
modifier|*
name|ctxt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_input_channel_request
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|plen
parameter_list|,
name|void
modifier|*
name|ctxt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_input_close
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|plen
parameter_list|,
name|void
modifier|*
name|ctxt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_input_close_confirmation
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|plen
parameter_list|,
name|void
modifier|*
name|ctxt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_input_data
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|plen
parameter_list|,
name|void
modifier|*
name|ctxt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_input_extended_data
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|plen
parameter_list|,
name|void
modifier|*
name|ctxt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_input_ieof
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|plen
parameter_list|,
name|void
modifier|*
name|ctxt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_input_oclose
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|plen
parameter_list|,
name|void
modifier|*
name|ctxt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_input_open_confirmation
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|plen
parameter_list|,
name|void
modifier|*
name|ctxt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_input_open_failure
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|plen
parameter_list|,
name|void
modifier|*
name|ctxt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_input_port_open
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|plen
parameter_list|,
name|void
modifier|*
name|ctxt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_input_window_adjust
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|plen
parameter_list|,
name|void
modifier|*
name|ctxt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Sets specific protocol options. */
end_comment

begin_function_decl
name|void
name|channel_set_options
parameter_list|(
name|int
name|hostname_in_open
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocate a new channel object and set its type and socket.  Remote_name  * must have been allocated with xmalloc; this will free it when the channel  * is freed.  */
end_comment

begin_function_decl
name|int
name|channel_allocate
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|sock
parameter_list|,
name|char
modifier|*
name|remote_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free the channel and close its socket. */
end_comment

begin_function_decl
name|void
name|channel_free
parameter_list|(
name|int
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocate/update select bitmasks and add any bits relevant to channels in  * select bitmasks.  */
end_comment

begin_function_decl
name|void
name|channel_prepare_select
parameter_list|(
name|fd_set
modifier|*
modifier|*
name|readsetp
parameter_list|,
name|fd_set
modifier|*
modifier|*
name|writesetp
parameter_list|,
name|int
modifier|*
name|maxfdp
parameter_list|,
name|int
name|rekeying
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * After select, perform any appropriate operations for channels which have  * events pending.  */
end_comment

begin_function_decl
name|void
name|channel_after_select
parameter_list|(
name|fd_set
modifier|*
name|readset
parameter_list|,
name|fd_set
modifier|*
name|writeset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If there is data to send to the connection, send some of it now. */
end_comment

begin_function_decl
name|void
name|channel_output_poll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true if no channel has too much buffered data. */
end_comment

begin_function_decl
name|int
name|channel_not_very_much_buffered_data
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This closes any sockets that are listening for connections; this removes    any unix domain sockets. */
end_comment

begin_function_decl
name|void
name|channel_stop_listening
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Closes the sockets of all channels.  This is used to close extra file  * descriptors after a fork.  */
end_comment

begin_function_decl
name|void
name|channel_close_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true if there is still an open channel over the connection. */
end_comment

begin_function_decl
name|int
name|channel_still_open
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns a string containing a list of all open channels.  The list is  * suitable for displaying to the user.  It uses crlf instead of newlines.  * The caller should free the string with xfree.  */
end_comment

begin_function_decl
name|char
modifier|*
name|channel_open_message
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initiate forwarding of connections to local port "port" through the secure  * channel to host:port from remote side.  */
end_comment

begin_function_decl
name|int
name|channel_request_local_forwarding
parameter_list|(
name|u_short
name|listen_port
parameter_list|,
specifier|const
name|char
modifier|*
name|host_to_connect
parameter_list|,
name|u_short
name|port_to_connect
parameter_list|,
name|int
name|gateway_ports
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_request_forwarding
parameter_list|(
specifier|const
name|char
modifier|*
name|listen_address
parameter_list|,
name|u_short
name|listen_port
parameter_list|,
specifier|const
name|char
modifier|*
name|host_to_connect
parameter_list|,
name|u_short
name|port_to_connect
parameter_list|,
name|int
name|gateway_ports
parameter_list|,
name|int
name|remote_fwd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initiate forwarding of connections to port "port" on remote host through  * the secure channel to host:port from local side.  This never returns if  * there was an error.  This registers that open requests for that port are  * permitted.  */
end_comment

begin_function_decl
name|void
name|channel_request_remote_forwarding
parameter_list|(
name|u_short
name|port
parameter_list|,
specifier|const
name|char
modifier|*
name|host
parameter_list|,
name|u_short
name|remote_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Permits opening to any host/port if permitted_opens[] is empty.  This is  * usually called by the server, because the user could connect to any port  * anyway, and the server has no way to know but to trust the client anyway.  */
end_comment

begin_function_decl
name|void
name|channel_permit_all_opens
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add host/port to list of allowed targets for port forwarding */
end_comment

begin_function_decl
name|void
name|channel_add_permitted_opens
parameter_list|(
name|char
modifier|*
name|host
parameter_list|,
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Flush list */
end_comment

begin_function_decl
name|void
name|channel_clear_permitted_opens
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This is called after receiving CHANNEL_FORWARDING_REQUEST.  This initates  * listening for the port, and sends back a success reply (or disconnect  * message if there was an error).  This never returns if there was an error.  */
end_comment

begin_function_decl
name|void
name|channel_input_port_forward_request
parameter_list|(
name|int
name|is_root
parameter_list|,
name|int
name|gateway_ports
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Creates a port for X11 connections, and starts listening for it. Returns  * the display name, or NULL if an error was encountered.  */
end_comment

begin_function_decl
name|char
modifier|*
name|x11_create_display
parameter_list|(
name|int
name|screen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Creates an internet domain socket for listening for X11 connections.  * Returns a suitable value for the DISPLAY variable, or NULL if an error  * occurs.  */
end_comment

begin_function_decl
name|char
modifier|*
name|x11_create_display_inet
parameter_list|(
name|int
name|screen
parameter_list|,
name|int
name|x11_display_offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This is called when SSH_SMSG_X11_OPEN is received.  The packet contains  * the remote channel number.  We should do whatever we want, and respond  * with either SSH_MSG_OPEN_CONFIRMATION or SSH_MSG_OPEN_FAILURE.  */
end_comment

begin_function_decl
name|void
name|x11_input_open
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|plen
parameter_list|,
name|void
modifier|*
name|ctxt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Requests forwarding of X11 connections.  This should be called on the  * client only.  */
end_comment

begin_function_decl
name|void
name|x11_request_forwarding
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Requests forwarding for X11 connections, with authentication spoofing.  * This should be called in the client only.  */
end_comment

begin_function_decl
name|void
name|x11_request_forwarding_with_spoofing
parameter_list|(
name|int
name|client_session_id
parameter_list|,
specifier|const
name|char
modifier|*
name|proto
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Sends a message to the server to request authentication fd forwarding. */
end_comment

begin_function_decl
name|void
name|auth_request_forwarding
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the name of the forwarded authentication socket.  Returns NULL if  * there is no forwarded authentication socket.  The returned value points to  * a static buffer.  */
end_comment

begin_function_decl
name|char
modifier|*
name|auth_get_socket_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This is called to process SSH_CMSG_AGENT_REQUEST_FORWARDING on the server.  * This starts forwarding authentication requests.  */
end_comment

begin_function_decl
name|int
name|auth_input_request_forwarding
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This is called to process an SSH_SMSG_AGENT_OPEN message. */
end_comment

begin_function_decl
name|void
name|auth_input_open_request
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|plen
parameter_list|,
name|void
modifier|*
name|ctxt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX */
end_comment

begin_function_decl
name|void
name|auth_sock_cleanup_proc
parameter_list|(
name|void
modifier|*
name|pw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_connect_to
parameter_list|(
specifier|const
name|char
modifier|*
name|host
parameter_list|,
name|u_short
name|host_port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_connect_by_listen_adress
parameter_list|(
name|u_short
name|listen_port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|x11_connect_display
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_find_open
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

