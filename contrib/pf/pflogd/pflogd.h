begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: pflogd.h,v 1.2 2004/01/15 20:15:14 canacar Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2003 Can Erkin Acar  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_include
include|#
directive|include
file|<pcap.h>
end_include

begin_define
define|#
directive|define
name|DEF_SNAPLEN
value|116
end_define

begin_comment
comment|/* default plus allow for larger header of pflog */
end_comment

begin_define
define|#
directive|define
name|PCAP_TO_MS
value|500
end_define

begin_comment
comment|/* pcap read timeout (ms) */
end_comment

begin_define
define|#
directive|define
name|PCAP_NUM_PKTS
value|1000
end_define

begin_comment
comment|/* max number of packets to process at each loop */
end_comment

begin_define
define|#
directive|define
name|PCAP_OPT_FIL
value|1
end_define

begin_comment
comment|/* filter optimization */
end_comment

begin_define
define|#
directive|define
name|FLUSH_DELAY
value|60
end_define

begin_comment
comment|/* flush delay */
end_comment

begin_define
define|#
directive|define
name|PFLOGD_LOG_FILE
value|"/var/log/pflog"
end_define

begin_define
define|#
directive|define
name|PFLOGD_DEFAULT_IF
value|"pflog0"
end_define

begin_define
define|#
directive|define
name|PFLOGD_MAXSNAPLEN
value|INT_MAX
end_define

begin_define
define|#
directive|define
name|PFLOGD_BUFSIZE
value|65536
end_define

begin_comment
comment|/* buffer size for incoming packets */
end_comment

begin_function_decl
name|void
name|logmsg
parameter_list|(
name|int
name|priority
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Privilege separation */
end_comment

begin_function_decl
name|int
name|priv_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|priv_set_snaplen
parameter_list|(
name|int
name|snaplen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|priv_open_log
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pcap_t
modifier|*
name|pcap_open_live_fd
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|snaplen
parameter_list|,
name|char
modifier|*
name|ebuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_pcap_filter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* File descriptor send/recv */
end_comment

begin_function_decl
name|void
name|send_fd
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|receive_fd
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|Debug
decl_stmt|;
end_decl_stmt

end_unit

