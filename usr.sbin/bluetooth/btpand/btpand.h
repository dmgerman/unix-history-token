begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: btpand.h,v 1.1 2008/08/17 13:20:57 plunky Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Iain Hibbert  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<bluetooth.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|"event.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__arraycount
end_ifndef

begin_define
define|#
directive|define
name|__arraycount
parameter_list|(
name|__x
parameter_list|)
value|(int)(sizeof((__x)) / sizeof((__x)[0]))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|L2CAP_PSM_INVALID
end_ifndef

begin_define
define|#
directive|define
name|L2CAP_PSM_INVALID
parameter_list|(
name|psm
parameter_list|)
value|(((psm)& 0x0101) != 0x0001)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|L2CAP_PSM_BNEP
end_ifndef

begin_define
define|#
directive|define
name|L2CAP_PSM_BNEP
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|channel
name|channel_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pfilter
name|pfilter_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mfilter
name|mfilter_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|packet
name|packet_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pkthdr
name|pkthdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pktlist
name|pktlist_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|exthdr
name|exthdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|extlist
name|extlist_t
typedef|;
end_typedef

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|chlist
argument_list|,
name|channel
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|extlist
argument_list|,
name|exthdr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|pktlist
argument_list|,
name|pkthdr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_enum
enum|enum
name|channel_state
block|{
name|CHANNEL_CLOSED
block|,
name|CHANNEL_WAIT_CONNECT_REQ
block|,
name|CHANNEL_WAIT_CONNECT_RSP
block|,
name|CHANNEL_OPEN
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|CHANNEL_MAXQLEN
value|128
end_define

begin_comment
comment|/* BNEP or tap channel */
end_comment

begin_struct
struct|struct
name|channel
block|{
name|enum
name|channel_state
name|state
decl_stmt|;
name|bool
name|oactive
decl_stmt|;
name|uint8_t
name|laddr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|raddr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|size_t
name|mru
decl_stmt|;
name|size_t
name|mtu
decl_stmt|;
name|int
name|npfilter
decl_stmt|;
name|pfilter_t
modifier|*
name|pfilter
decl_stmt|;
name|int
name|nmfilter
decl_stmt|;
name|mfilter_t
modifier|*
name|mfilter
decl_stmt|;
name|pktlist_t
name|pktlist
decl_stmt|;
name|int
name|qlen
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|struct
name|event
name|rd_ev
decl_stmt|;
name|struct
name|event
name|wr_ev
decl_stmt|;
name|uint8_t
modifier|*
name|sendbuf
decl_stmt|;
name|bool
function_decl|(
modifier|*
name|send
function_decl|)
parameter_list|(
name|channel_t
modifier|*
parameter_list|,
name|packet_t
modifier|*
parameter_list|)
function_decl|;
name|bool
function_decl|(
modifier|*
name|recv
function_decl|)
parameter_list|(
name|packet_t
modifier|*
parameter_list|)
function_decl|;
name|int
name|tick
decl_stmt|;
name|struct
name|pidfh
modifier|*
name|pfh
decl_stmt|;
name|int
name|refcnt
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|channel
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* network protocol type filter */
end_comment

begin_struct
struct|struct
name|pfilter
block|{
name|uint16_t
name|start
decl_stmt|;
name|uint16_t
name|end
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* multicast address filter */
end_comment

begin_struct
struct|struct
name|mfilter
block|{
name|uint8_t
name|start
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|end
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* packet data buffer */
end_comment

begin_struct
struct|struct
name|packet
block|{
name|channel_t
modifier|*
name|chan
decl_stmt|;
comment|/* source channel */
name|uint8_t
modifier|*
name|dst
decl_stmt|;
comment|/* dest address */
name|uint8_t
modifier|*
name|src
decl_stmt|;
comment|/* source address */
name|uint8_t
modifier|*
name|type
decl_stmt|;
comment|/* protocol type */
name|uint8_t
modifier|*
name|ptr
decl_stmt|;
comment|/* data pointer */
name|size_t
name|len
decl_stmt|;
comment|/* data length */
name|int
name|refcnt
decl_stmt|;
comment|/* reference count */
name|extlist_t
name|extlist
decl_stmt|;
comment|/* extension headers */
name|uint8_t
name|buf
index|[
literal|0
index|]
decl_stmt|;
comment|/* data starts here */
block|}
struct|;
end_struct

begin_comment
comment|/* extension header */
end_comment

begin_struct
struct|struct
name|exthdr
block|{
name|STAILQ_ENTRY
argument_list|(
argument|exthdr
argument_list|)
name|next
expr_stmt|;
name|uint8_t
modifier|*
name|ptr
decl_stmt|;
name|uint8_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* packet header */
end_comment

begin_struct
struct|struct
name|pkthdr
block|{
name|STAILQ_ENTRY
argument_list|(
argument|pkthdr
argument_list|)
name|next
expr_stmt|;
name|packet_t
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* global variables */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|control_path
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|service_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|interface_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bdaddr_t
name|local_bdaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bdaddr_t
name|remote_bdaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint16_t
name|l2cap_psm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|l2cap_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint16_t
name|service_class
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|server_limit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Bluetooth addresses are stored the other way around than  * Ethernet addresses even though they are of the same family  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|b2eaddr
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
name|bdaddr_t
modifier|*
name|src
parameter_list|)
block|{
name|uint8_t
modifier|*
name|d
init|=
name|dst
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ETHER_ADDR_LEN
condition|;
name|i
operator|++
control|)
name|d
index|[
name|i
index|]
operator|=
name|src
operator|->
name|b
index|[
name|ETHER_ADDR_LEN
operator|-
name|i
operator|-
literal|1
index|]
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|log_err
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|syslog(LOG_ERR, fmt , ##args)
end_define

begin_define
define|#
directive|define
name|log_info
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|syslog(LOG_INFO, fmt , ##args)
end_define

begin_define
define|#
directive|define
name|log_notice
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|syslog(LOG_NOTICE, fmt , ##args)
end_define

begin_define
define|#
directive|define
name|log_debug
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|syslog(LOG_DEBUG, "%s: " fmt, __func__ , ##args)
end_define

begin_comment
comment|/* bnep.c */
end_comment

begin_function_decl
name|bool
name|bnep_send
parameter_list|(
name|channel_t
modifier|*
parameter_list|,
name|packet_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bnep_recv
parameter_list|(
name|packet_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bnep_send_control
parameter_list|(
name|channel_t
modifier|*
parameter_list|,
name|uint8_t
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* channel.c */
end_comment

begin_function_decl
name|void
name|channel_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|channel_t
modifier|*
name|channel_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|channel_open
parameter_list|(
name|channel_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_close
parameter_list|(
name|channel_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_free
parameter_list|(
name|channel_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_timeout
parameter_list|(
name|channel_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|channel_put
parameter_list|(
name|channel_t
modifier|*
parameter_list|,
name|packet_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* client.c */
end_comment

begin_function_decl
name|void
name|client_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* packet.c */
end_comment

begin_function_decl
name|packet_t
modifier|*
name|packet_alloc
parameter_list|(
name|channel_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_free
parameter_list|(
name|packet_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_adj
parameter_list|(
name|packet_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pkthdr_t
modifier|*
name|pkthdr_alloc
parameter_list|(
name|packet_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pkthdr_free
parameter_list|(
name|pkthdr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* server.c */
end_comment

begin_function_decl
name|void
name|server_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|server_update
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* tap.c */
end_comment

begin_function_decl
name|void
name|tap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

