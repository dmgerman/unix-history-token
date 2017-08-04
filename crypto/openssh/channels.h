begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: channels.h,v 1.121 2017/02/01 02:59:09 dtucker Exp $ */
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1999, 2000, 2001, 2002 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CHANNEL_H
end_ifndef

begin_define
define|#
directive|define
name|CHANNEL_H
end_define

begin_comment
comment|/* Definitions for channel types. */
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
name|SSH_CHANNEL_ZOMBIE
value|14
end_define

begin_comment
comment|/* Almost dead. */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_MUX_LISTENER
value|15
end_define

begin_comment
comment|/* Listener for mux conn. */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_MUX_CLIENT
value|16
end_define

begin_comment
comment|/* Conn. to mux slave */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_ABANDONED
value|17
end_define

begin_comment
comment|/* Abandoned session, eg mux */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_UNIX_LISTENER
value|18
end_define

begin_comment
comment|/* Listening on a domain socket. */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_RUNIX_LISTENER
value|19
end_define

begin_comment
comment|/* Listening to a R-style domain socket. */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_MUX_PROXY
value|20
end_define

begin_comment
comment|/* proxy channel for mux-slave */
end_comment

begin_define
define|#
directive|define
name|SSH_CHANNEL_MAX_TYPE
value|21
end_define

begin_define
define|#
directive|define
name|CHANNEL_CANCEL_PORT_STATIC
value|-1
end_define

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
name|channel_open_fn
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|channel_callback_fn
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|channel_infilter_fn
parameter_list|(
name|struct
name|Channel
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|channel_filter_cleanup_fn
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|u_char
modifier|*
name|channel_outfilter_fn
parameter_list|(
name|struct
name|Channel
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Channel success/failure callbacks */
end_comment

begin_typedef
typedef|typedef
name|void
name|channel_confirm_cb
parameter_list|(
name|int
parameter_list|,
name|struct
name|Channel
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|channel_confirm_abandon_cb
parameter_list|(
name|struct
name|Channel
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|channel_confirm
block|{
name|TAILQ_ENTRY
argument_list|(
argument|channel_confirm
argument_list|)
name|entry
expr_stmt|;
name|channel_confirm_cb
modifier|*
name|cb
decl_stmt|;
name|channel_confirm_abandon_cb
modifier|*
name|abandon_cb
decl_stmt|;
name|void
modifier|*
name|ctx
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|channel_confirms
argument_list|,
name|channel_confirm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Context for non-blocking connects */
end_comment

begin_struct
struct|struct
name|channel_connect
block|{
name|char
modifier|*
name|host
decl_stmt|;
name|int
name|port
decl_stmt|;
name|struct
name|addrinfo
modifier|*
name|ai
decl_stmt|,
modifier|*
name|aitop
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Callbacks for mux channels back into client-specific code */
end_comment

begin_typedef
typedef|typedef
name|int
name|mux_callback_fn
parameter_list|(
name|struct
name|Channel
modifier|*
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
name|u_int
name|istate
decl_stmt|;
comment|/* input from channel (state of receive half) */
name|u_int
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
name|ctl_chan
decl_stmt|;
comment|/* control channel (multiplexed connections) */
name|int
name|isatty
decl_stmt|;
comment|/* rfd is a tty */
ifdef|#
directive|ifdef
name|_AIX
name|int
name|wfd_isatty
decl_stmt|;
comment|/* wfd is a tty */
endif|#
directive|endif
name|int
name|client_tty
decl_stmt|;
comment|/* (client) TTY has been requested */
name|int
name|force_drain
decl_stmt|;
comment|/* force close on iEOF */
name|time_t
name|notbefore
decl_stmt|;
comment|/* Pause IO until deadline (time_t) */
name|int
name|delayed
decl_stmt|;
comment|/* post-select handlers for newly created 				 * channels are delayed until the first call 				 * to a matching pre-select handler. 				 * this way post-select handlers are not 				 * accidentally called if a FD gets reused */
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
modifier|*
name|path
decl_stmt|;
comment|/* path for unix domain sockets, or host name for forwards */
name|int
name|listening_port
decl_stmt|;
comment|/* port being listened for forwards */
name|char
modifier|*
name|listening_addr
decl_stmt|;
comment|/* addr being listened for forwards */
name|int
name|host_port
decl_stmt|;
comment|/* remote port to connect for forwards */
name|char
modifier|*
name|remote_name
decl_stmt|;
comment|/* remote hostname */
name|u_int
name|remote_window
decl_stmt|;
name|u_int
name|remote_maxpacket
decl_stmt|;
name|u_int
name|local_window
decl_stmt|;
name|u_int
name|local_window_max
decl_stmt|;
name|u_int
name|local_consumed
decl_stmt|;
name|u_int
name|local_maxpacket
decl_stmt|;
name|int
name|extended_usage
decl_stmt|;
name|int
name|single_connection
decl_stmt|;
name|char
modifier|*
name|ctype
decl_stmt|;
comment|/* type */
comment|/* callback */
name|channel_open_fn
modifier|*
name|open_confirm
decl_stmt|;
name|void
modifier|*
name|open_confirm_ctx
decl_stmt|;
name|channel_callback_fn
modifier|*
name|detach_user
decl_stmt|;
name|int
name|detach_close
decl_stmt|;
name|struct
name|channel_confirms
name|status_confirms
decl_stmt|;
comment|/* filter */
name|channel_infilter_fn
modifier|*
name|input_filter
decl_stmt|;
name|channel_outfilter_fn
modifier|*
name|output_filter
decl_stmt|;
name|void
modifier|*
name|filter_ctx
decl_stmt|;
name|channel_filter_cleanup_fn
modifier|*
name|filter_cleanup
decl_stmt|;
comment|/* keep boundaries */
name|int
name|datagram
decl_stmt|;
comment|/* non-blocking connect */
name|struct
name|channel_connect
name|connect_ctx
decl_stmt|;
comment|/* multiplexing protocol hook, called for each packet received */
name|mux_callback_fn
modifier|*
name|mux_rcb
decl_stmt|;
name|void
modifier|*
name|mux_ctx
decl_stmt|;
name|int
name|mux_pause
decl_stmt|;
name|int
name|mux_downstream_id
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
name|CHAN_SES_PACKET_DEFAULT
value|(32*1024)
end_define

begin_define
define|#
directive|define
name|CHAN_SES_WINDOW_DEFAULT
value|(64*CHAN_SES_PACKET_DEFAULT)
end_define

begin_define
define|#
directive|define
name|CHAN_TCP_PACKET_DEFAULT
value|(32*1024)
end_define

begin_define
define|#
directive|define
name|CHAN_TCP_WINDOW_DEFAULT
value|(64*CHAN_TCP_PACKET_DEFAULT)
end_define

begin_define
define|#
directive|define
name|CHAN_X11_PACKET_DEFAULT
value|(16*1024)
end_define

begin_define
define|#
directive|define
name|CHAN_X11_WINDOW_DEFAULT
value|(4*CHAN_X11_PACKET_DEFAULT)
end_define

begin_comment
comment|/* possible input states */
end_comment

begin_define
define|#
directive|define
name|CHAN_INPUT_OPEN
value|0
end_define

begin_define
define|#
directive|define
name|CHAN_INPUT_WAIT_DRAIN
value|1
end_define

begin_define
define|#
directive|define
name|CHAN_INPUT_WAIT_OCLOSE
value|2
end_define

begin_define
define|#
directive|define
name|CHAN_INPUT_CLOSED
value|3
end_define

begin_comment
comment|/* possible output states */
end_comment

begin_define
define|#
directive|define
name|CHAN_OUTPUT_OPEN
value|0
end_define

begin_define
define|#
directive|define
name|CHAN_OUTPUT_WAIT_DRAIN
value|1
end_define

begin_define
define|#
directive|define
name|CHAN_OUTPUT_WAIT_IEOF
value|2
end_define

begin_define
define|#
directive|define
name|CHAN_OUTPUT_CLOSED
value|3
end_define

begin_define
define|#
directive|define
name|CHAN_CLOSE_SENT
value|0x01
end_define

begin_define
define|#
directive|define
name|CHAN_CLOSE_RCVD
value|0x02
end_define

begin_define
define|#
directive|define
name|CHAN_EOF_SENT
value|0x04
end_define

begin_define
define|#
directive|define
name|CHAN_EOF_RCVD
value|0x08
end_define

begin_define
define|#
directive|define
name|CHAN_LOCAL
value|0x10
end_define

begin_define
define|#
directive|define
name|CHAN_RBUF
value|16*1024
end_define

begin_comment
comment|/* check whether 'efd' is still in use */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_EFD_INPUT_ACTIVE
parameter_list|(
name|c
parameter_list|)
define|\
value|(compat20&& c->extended_usage == CHAN_EXTENDED_READ&& \ 	(c->efd != -1 || \ 	buffer_len(&c->extended)> 0))
end_define

begin_define
define|#
directive|define
name|CHANNEL_EFD_OUTPUT_ACTIVE
parameter_list|(
name|c
parameter_list|)
define|\
value|(compat20&& c->extended_usage == CHAN_EXTENDED_WRITE&& \ 	c->efd != -1&& (!(c->flags& (CHAN_EOF_RCVD|CHAN_CLOSE_RCVD)) || \ 	buffer_len(&c->extended)> 0))
end_define

begin_comment
comment|/* channel management */
end_comment

begin_function_decl
name|Channel
modifier|*
name|channel_by_id
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Channel
modifier|*
name|channel_by_remote_id
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Channel
modifier|*
name|channel_lookup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Channel
modifier|*
name|channel_new
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_set_fds
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_free
parameter_list|(
name|Channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_free_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_stop_listening
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_send_open
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_request_start
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_register_cleanup
parameter_list|(
name|int
parameter_list|,
name|channel_callback_fn
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_register_open_confirm
parameter_list|(
name|int
parameter_list|,
name|channel_open_fn
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_register_filter
parameter_list|(
name|int
parameter_list|,
name|channel_infilter_fn
modifier|*
parameter_list|,
name|channel_outfilter_fn
modifier|*
parameter_list|,
name|channel_filter_cleanup_fn
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_register_status_confirm
parameter_list|(
name|int
parameter_list|,
name|channel_confirm_cb
modifier|*
parameter_list|,
name|channel_confirm_abandon_cb
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_cancel_cleanup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_close_fd
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_send_window_changes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mux proxy support */
end_comment

begin_function_decl
name|int
name|channel_proxy_downstream
parameter_list|(
name|Channel
modifier|*
name|mc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_proxy_upstream
parameter_list|(
name|Channel
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* protocol handler */
end_comment

begin_function_decl
name|int
name|channel_input_close
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_input_close_confirmation
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_input_data
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_input_extended_data
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_input_ieof
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_input_oclose
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_input_open_confirmation
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_input_open_failure
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_input_port_open
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_input_window_adjust
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_input_status_confirm
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* file descriptor handling (read/write) */
end_comment

begin_function_decl
name|void
name|channel_prepare_select
parameter_list|(
name|fd_set
modifier|*
modifier|*
parameter_list|,
name|fd_set
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|,
name|time_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_after_select
parameter_list|(
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_output_poll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_not_very_much_buffered_data
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_close_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_still_open
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|channel_open_message
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

begin_comment
comment|/* tcp forwarding */
end_comment

begin_struct_decl
struct_decl|struct
name|Forward
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ForwardOptions
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|channel_set_af
parameter_list|(
name|int
name|af
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_permit_all_opens
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_add_permitted_opens
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_add_adm_permitted_opens
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_disable_adm_local_opens
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_update_permitted_opens
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_clear_permitted_opens
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_clear_adm_permitted_opens
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_print_adm_permitted_opens
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Channel
modifier|*
name|channel_connect_to_port
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_short
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Channel
modifier|*
name|channel_connect_to_path
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Channel
modifier|*
name|channel_connect_stdio_fwd
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_short
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Channel
modifier|*
name|channel_connect_by_listen_address
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_short
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Channel
modifier|*
name|channel_connect_by_listen_path
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_request_remote_forwarding
parameter_list|(
name|struct
name|Forward
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_setup_local_fwd_listener
parameter_list|(
name|struct
name|Forward
modifier|*
parameter_list|,
name|struct
name|ForwardOptions
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_request_rforward_cancel
parameter_list|(
name|struct
name|Forward
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_setup_remote_fwd_listener
parameter_list|(
name|struct
name|Forward
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|ForwardOptions
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_cancel_rport_listener
parameter_list|(
name|struct
name|Forward
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|channel_cancel_lport_listener
parameter_list|(
name|struct
name|Forward
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ForwardOptions
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|permitopen_port
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* x11 forwarding */
end_comment

begin_function_decl
name|void
name|channel_set_x11_refuse_time
parameter_list|(
name|u_int
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
name|x11_create_display_inet
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_int
modifier|*
parameter_list|,
name|int
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|x11_input_open
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|x11_request_forwarding_with_spoofing
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|deny_input_open
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* agent forwarding */
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
comment|/* channel close */
end_comment

begin_function_decl
name|int
name|chan_is_dead
parameter_list|(
name|Channel
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chan_mark_dead
parameter_list|(
name|Channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* channel events */
end_comment

begin_function_decl
name|void
name|chan_rcvd_oclose
parameter_list|(
name|Channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chan_rcvd_eow
parameter_list|(
name|Channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* SSH2-only */
end_comment

begin_function_decl
name|void
name|chan_read_failed
parameter_list|(
name|Channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chan_ibuf_empty
parameter_list|(
name|Channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chan_rcvd_ieof
parameter_list|(
name|Channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chan_write_failed
parameter_list|(
name|Channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chan_obuf_empty
parameter_list|(
name|Channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

