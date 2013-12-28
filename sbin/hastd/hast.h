begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2010 The FreeBSD Foundation  * Copyright (c) 2011 Pawel Jakub Dawidek<pawel@dawidek.net>  * All rights reserved.  *  * This software was developed by Pawel Jakub Dawidek under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HAST_H_
end_ifndef

begin_define
define|#
directive|define
name|_HAST_H_
end_define

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
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<activemap.h>
end_include

begin_include
include|#
directive|include
file|"proto.h"
end_include

begin_comment
comment|/*  * Version history:  * 0 - initial version  * 1 - HIO_KEEPALIVE added  * 2 - "memsync" and "received" attributes added for memsync mode  */
end_comment

begin_define
define|#
directive|define
name|HAST_PROTO_VERSION
value|2
end_define

begin_define
define|#
directive|define
name|EHAST_OK
value|0
end_define

begin_define
define|#
directive|define
name|EHAST_NOENTRY
value|1
end_define

begin_define
define|#
directive|define
name|EHAST_INVALID
value|2
end_define

begin_define
define|#
directive|define
name|EHAST_NOMEMORY
value|3
end_define

begin_define
define|#
directive|define
name|EHAST_UNIMPLEMENTED
value|4
end_define

begin_define
define|#
directive|define
name|HASTCTL_CMD_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|HASTCTL_CMD_SETROLE
value|1
end_define

begin_define
define|#
directive|define
name|HASTCTL_CMD_STATUS
value|2
end_define

begin_define
define|#
directive|define
name|HAST_ROLE_UNDEF
value|0
end_define

begin_define
define|#
directive|define
name|HAST_ROLE_INIT
value|1
end_define

begin_define
define|#
directive|define
name|HAST_ROLE_PRIMARY
value|2
end_define

begin_define
define|#
directive|define
name|HAST_ROLE_SECONDARY
value|3
end_define

begin_define
define|#
directive|define
name|HAST_SYNCSRC_UNDEF
value|0
end_define

begin_define
define|#
directive|define
name|HAST_SYNCSRC_PRIMARY
value|1
end_define

begin_define
define|#
directive|define
name|HAST_SYNCSRC_SECONDARY
value|2
end_define

begin_define
define|#
directive|define
name|HIO_UNDEF
value|0
end_define

begin_define
define|#
directive|define
name|HIO_READ
value|1
end_define

begin_define
define|#
directive|define
name|HIO_WRITE
value|2
end_define

begin_define
define|#
directive|define
name|HIO_DELETE
value|3
end_define

begin_define
define|#
directive|define
name|HIO_FLUSH
value|4
end_define

begin_define
define|#
directive|define
name|HIO_KEEPALIVE
value|5
end_define

begin_define
define|#
directive|define
name|HAST_USER
value|"hast"
end_define

begin_define
define|#
directive|define
name|HAST_TIMEOUT
value|20
end_define

begin_define
define|#
directive|define
name|HAST_CONFIG
value|"/etc/hast.conf"
end_define

begin_define
define|#
directive|define
name|HAST_CONTROL
value|"/var/run/hastctl"
end_define

begin_define
define|#
directive|define
name|HASTD_LISTEN_TCP4
value|"tcp4://0.0.0.0:8457"
end_define

begin_define
define|#
directive|define
name|HASTD_LISTEN_TCP6
value|"tcp6://[::]:8457"
end_define

begin_define
define|#
directive|define
name|HASTD_PIDFILE
value|"/var/run/hastd.pid"
end_define

begin_comment
comment|/* Default extent size. */
end_comment

begin_define
define|#
directive|define
name|HAST_EXTENTSIZE
value|2097152
end_define

begin_comment
comment|/* Default maximum number of extents that are kept dirty. */
end_comment

begin_define
define|#
directive|define
name|HAST_KEEPDIRTY
value|64
end_define

begin_define
define|#
directive|define
name|HAST_ADDRSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|HAST_TOKEN_SIZE
value|16
end_define

begin_comment
comment|/* Number of seconds to sleep between reconnect retries or keepalive packets. */
end_comment

begin_define
define|#
directive|define
name|HAST_KEEPALIVE
value|10
end_define

begin_struct
struct|struct
name|hastd_listen
block|{
comment|/* Address to listen on. */
name|char
name|hl_addr
index|[
name|HAST_ADDRSIZE
index|]
decl_stmt|;
comment|/* Protocol-specific data. */
name|struct
name|proto_conn
modifier|*
name|hl_conn
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|hastd_listen
argument_list|)
name|hl_next
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hastd_config
block|{
comment|/* Address to communicate with hastctl(8). */
name|char
name|hc_controladdr
index|[
name|HAST_ADDRSIZE
index|]
decl_stmt|;
comment|/* Protocol-specific data. */
name|struct
name|proto_conn
modifier|*
name|hc_controlconn
decl_stmt|;
comment|/* Incoming control connection. */
name|struct
name|proto_conn
modifier|*
name|hc_controlin
decl_stmt|;
comment|/* PID file path. */
name|char
name|hc_pidfile
index|[
name|PATH_MAX
index|]
decl_stmt|;
comment|/* List of addresses to listen on. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|hastd_listen
argument_list|)
name|hc_listen
expr_stmt|;
comment|/* List of resources. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|hast_resource
argument_list|)
name|hc_resources
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HAST_REPLICATION_FULLSYNC
value|0
end_define

begin_define
define|#
directive|define
name|HAST_REPLICATION_MEMSYNC
value|1
end_define

begin_define
define|#
directive|define
name|HAST_REPLICATION_ASYNC
value|2
end_define

begin_define
define|#
directive|define
name|HAST_COMPRESSION_NONE
value|0
end_define

begin_define
define|#
directive|define
name|HAST_COMPRESSION_HOLE
value|1
end_define

begin_define
define|#
directive|define
name|HAST_COMPRESSION_LZF
value|2
end_define

begin_define
define|#
directive|define
name|HAST_CHECKSUM_NONE
value|0
end_define

begin_define
define|#
directive|define
name|HAST_CHECKSUM_CRC32
value|1
end_define

begin_define
define|#
directive|define
name|HAST_CHECKSUM_SHA256
value|2
end_define

begin_struct_decl
struct_decl|struct
name|nv
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Structure that describes single resource.  */
end_comment

begin_struct
struct|struct
name|hast_resource
block|{
comment|/* Resource name. */
name|char
name|hr_name
index|[
name|NAME_MAX
index|]
decl_stmt|;
comment|/* Negotiated replication mode (HAST_REPLICATION_*). */
name|int
name|hr_replication
decl_stmt|;
comment|/* Configured replication mode (HAST_REPLICATION_*). */
name|int
name|hr_original_replication
decl_stmt|;
comment|/* Provider name that will appear in /dev/hast/. */
name|char
name|hr_provname
index|[
name|NAME_MAX
index|]
decl_stmt|;
comment|/* Synchronization extent size. */
name|int
name|hr_extentsize
decl_stmt|;
comment|/* Maximum number of extents that are kept dirty. */
name|int
name|hr_keepdirty
decl_stmt|;
comment|/* Path to a program to execute on various events. */
name|char
name|hr_exec
index|[
name|PATH_MAX
index|]
decl_stmt|;
comment|/* Compression algorithm. */
name|int
name|hr_compression
decl_stmt|;
comment|/* Checksum algorithm. */
name|int
name|hr_checksum
decl_stmt|;
comment|/* Protocol version. */
name|int
name|hr_version
decl_stmt|;
comment|/* Path to local component. */
name|char
name|hr_localpath
index|[
name|PATH_MAX
index|]
decl_stmt|;
comment|/* Descriptor to access local component. */
name|int
name|hr_localfd
decl_stmt|;
comment|/* Offset into local component. */
name|off_t
name|hr_localoff
decl_stmt|;
comment|/* Size of usable space. */
name|off_t
name|hr_datasize
decl_stmt|;
comment|/* Size of entire local provider. */
name|off_t
name|hr_local_mediasize
decl_stmt|;
comment|/* Sector size of local provider. */
name|unsigned
name|int
name|hr_local_sectorsize
decl_stmt|;
comment|/* Is flushing write cache supported by the local provider? */
name|bool
name|hr_localflush
decl_stmt|;
comment|/* Flush write cache on metadata updates? */
name|int
name|hr_metaflush
decl_stmt|;
comment|/* Descriptor for /dev/ggctl communication. */
name|int
name|hr_ggatefd
decl_stmt|;
comment|/* Unit number for ggate communication. */
name|int
name|hr_ggateunit
decl_stmt|;
comment|/* Address of the remote component. */
name|char
name|hr_remoteaddr
index|[
name|HAST_ADDRSIZE
index|]
decl_stmt|;
comment|/* Local address to bind to for outgoing connections. */
name|char
name|hr_sourceaddr
index|[
name|HAST_ADDRSIZE
index|]
decl_stmt|;
comment|/* Connection for incoming data. */
name|struct
name|proto_conn
modifier|*
name|hr_remotein
decl_stmt|;
comment|/* Connection for outgoing data. */
name|struct
name|proto_conn
modifier|*
name|hr_remoteout
decl_stmt|;
comment|/* Token to verify both in and out connection are coming from 	   the same node (not necessarily from the same address). */
name|unsigned
name|char
name|hr_token
index|[
name|HAST_TOKEN_SIZE
index|]
decl_stmt|;
comment|/* Connection timeout. */
name|int
name|hr_timeout
decl_stmt|;
comment|/* Resource unique identifier. */
name|uint64_t
name|hr_resuid
decl_stmt|;
comment|/* Primary's local modification count. */
name|uint64_t
name|hr_primary_localcnt
decl_stmt|;
comment|/* Primary's remote modification count. */
name|uint64_t
name|hr_primary_remotecnt
decl_stmt|;
comment|/* Secondary's local modification count. */
name|uint64_t
name|hr_secondary_localcnt
decl_stmt|;
comment|/* Secondary's remote modification count. */
name|uint64_t
name|hr_secondary_remotecnt
decl_stmt|;
comment|/* Synchronization source. */
name|uint8_t
name|hr_syncsrc
decl_stmt|;
comment|/* Resource role: HAST_ROLE_{INIT,PRIMARY,SECONDARY}. */
name|int
name|hr_role
decl_stmt|;
comment|/* Previous resource role: HAST_ROLE_{INIT,PRIMARY,SECONDARY}. */
name|int
name|hr_previous_role
decl_stmt|;
comment|/* PID of child worker process. 0 - no child. */
name|pid_t
name|hr_workerpid
decl_stmt|;
comment|/* Control commands from parent to child. */
name|struct
name|proto_conn
modifier|*
name|hr_ctrl
decl_stmt|;
comment|/* Events from child to parent. */
name|struct
name|proto_conn
modifier|*
name|hr_event
decl_stmt|;
comment|/* Connection requests from child to parent. */
name|struct
name|proto_conn
modifier|*
name|hr_conn
decl_stmt|;
comment|/* Activemap structure. */
name|struct
name|activemap
modifier|*
name|hr_amp
decl_stmt|;
comment|/* Lock used to synchronize access to hr_amp. */
name|pthread_mutex_t
name|hr_amp_lock
decl_stmt|;
comment|/* Lock used to synchronize access to hr_amp diskmap. */
name|pthread_mutex_t
name|hr_amp_diskmap_lock
decl_stmt|;
comment|/* Number of BIO_READ requests. */
name|uint64_t
name|hr_stat_read
decl_stmt|;
comment|/* Number of BIO_WRITE requests. */
name|uint64_t
name|hr_stat_write
decl_stmt|;
comment|/* Number of BIO_DELETE requests. */
name|uint64_t
name|hr_stat_delete
decl_stmt|;
comment|/* Number of BIO_FLUSH requests. */
name|uint64_t
name|hr_stat_flush
decl_stmt|;
comment|/* Number of activemap updates. */
name|uint64_t
name|hr_stat_activemap_update
decl_stmt|;
comment|/* Number of local read errors. */
name|uint64_t
name|hr_stat_read_error
decl_stmt|;
comment|/* Number of local write errors. */
name|uint64_t
name|hr_stat_write_error
decl_stmt|;
comment|/* Number of local delete errors. */
name|uint64_t
name|hr_stat_delete_error
decl_stmt|;
comment|/* Number of flush errors. */
name|uint64_t
name|hr_stat_flush_error
decl_stmt|;
comment|/* Number of activemap write errors. */
name|uint64_t
name|hr_stat_activemap_write_error
decl_stmt|;
comment|/* Number of activemap flush errors. */
name|uint64_t
name|hr_stat_activemap_flush_error
decl_stmt|;
comment|/* Function to output worker specific info on control status request. */
name|void
function_decl|(
modifier|*
name|output_status_aux
function_decl|)
parameter_list|(
name|struct
name|nv
modifier|*
parameter_list|)
function_decl|;
comment|/* Next resource. */
name|TAILQ_ENTRY
argument_list|(
argument|hast_resource
argument_list|)
name|hr_next
expr_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|hastd_config
modifier|*
name|yy_config_parse
parameter_list|(
specifier|const
name|char
modifier|*
name|config
parameter_list|,
name|bool
name|exitonerror
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|yy_config_free
parameter_list|(
name|struct
name|hastd_config
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_HAST_H_ */
end_comment

end_unit

