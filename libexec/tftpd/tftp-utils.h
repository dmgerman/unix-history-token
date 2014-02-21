begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2008 Edwin Groothuis. All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|TIMEOUT
value|5
end_define

begin_define
define|#
directive|define
name|MAX_TIMEOUTS
value|5
end_define

begin_comment
comment|/* Generic values */
end_comment

begin_define
define|#
directive|define
name|MAXSEGSIZE
value|65464
end_define

begin_comment
comment|/* Maximum size of the data segment */
end_comment

begin_define
define|#
directive|define
name|MAXPKTSIZE
value|(MAXSEGSIZE + 4)
end_define

begin_comment
comment|/* Maximum size of the packet */
end_comment

begin_comment
comment|/* For the blksize option */
end_comment

begin_define
define|#
directive|define
name|BLKSIZE_MIN
value|8
end_define

begin_comment
comment|/* Minimum size of the data segment */
end_comment

begin_define
define|#
directive|define
name|BLKSIZE_MAX
value|MAXSEGSIZE
end_define

begin_comment
comment|/* Maximum size of the data segment */
end_comment

begin_comment
comment|/* For the timeout option */
end_comment

begin_define
define|#
directive|define
name|TIMEOUT_MIN
value|0
end_define

begin_comment
comment|/* Minimum timeout value */
end_comment

begin_define
define|#
directive|define
name|TIMEOUT_MAX
value|255
end_define

begin_comment
comment|/* Maximum timeout value */
end_comment

begin_define
define|#
directive|define
name|MIN_TIMEOUTS
value|3
end_define

begin_decl_stmt
specifier|extern
name|int
name|timeoutpacket
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|timeoutnetwork
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxtimeouts
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|settimeouts
parameter_list|(
name|int
name|timeoutpacket
parameter_list|,
name|int
name|timeoutnetwork
parameter_list|,
name|int
name|maxtimeouts
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|uint16_t
name|segsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint16_t
name|pktsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|acting_as_client
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  */
end_comment

begin_function_decl
name|void
name|unmappedaddr
parameter_list|(
name|struct
name|sockaddr_in6
modifier|*
name|sin6
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|get_field
parameter_list|(
name|int
name|peer
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|,
name|ssize_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Packet types  */
end_comment

begin_struct
struct|struct
name|packettypes
block|{
name|int
name|value
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|packettypes
name|packettypes
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|const
name|char
modifier|*
name|packettype
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * RP_  */
end_comment

begin_struct
struct|struct
name|rp_errors
block|{
name|int
name|error
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|desc
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|rp_errors
name|rp_errors
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|rp_strerror
parameter_list|(
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Debug features  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|DEBUG_PACKETS
value|0x0001
end_define

begin_define
define|#
directive|define
name|DEBUG_SIMPLE
value|0x0002
end_define

begin_define
define|#
directive|define
name|DEBUG_OPTIONS
value|0x0004
end_define

begin_define
define|#
directive|define
name|DEBUG_ACCESS
value|0x0008
end_define

begin_struct
struct|struct
name|debugs
block|{
name|int
name|value
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|desc
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|debugs
name|debugs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|packetdroppercentage
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|debug_find
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|debug_finds
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|debug_show
parameter_list|(
name|int
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Log routines  */
end_comment

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|s
parameter_list|)
value|tftp_log(LOG_DEBUG, "%s", s)
end_define

begin_decl_stmt
specifier|extern
name|int
name|tftp_logtostdout
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|tftp_openlog
parameter_list|(
specifier|const
name|char
modifier|*
name|ident
parameter_list|,
name|int
name|logopt
parameter_list|,
name|int
name|facility
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tftp_closelog
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tftp_log
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
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Performance figures  */
end_comment

begin_struct
struct|struct
name|tftp_stats
block|{
name|size_t
name|amount
decl_stmt|;
name|int
name|rollovers
decl_stmt|;
name|uint32_t
name|blocks
decl_stmt|;
name|int
name|retries
decl_stmt|;
name|struct
name|timeval
name|tstart
decl_stmt|;
name|struct
name|timeval
name|tstop
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|stats_init
parameter_list|(
name|struct
name|tftp_stats
modifier|*
name|ts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printstats
parameter_list|(
specifier|const
name|char
modifier|*
name|direction
parameter_list|,
name|int
name|verbose
parameter_list|,
name|struct
name|tftp_stats
modifier|*
name|ts
parameter_list|)
function_decl|;
end_function_decl

end_unit

