begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Pawel Jakub Dawidek under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $P4: //depot/projects/trustedbsd/openbsm/bin/auditdistd/auditdistd.h#2 $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AUDITDISTD_H_
end_ifndef

begin_define
define|#
directive|define
name|_AUDITDISTD_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
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
file|<dirent.h>
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
file|<compat/compat.h>
end_include

begin_include
include|#
directive|include
file|"proto.h"
end_include

begin_comment
comment|/*  * Version history:  * 0 - initial version  */
end_comment

begin_define
define|#
directive|define
name|ADIST_VERSION
value|0
end_define

begin_define
define|#
directive|define
name|ADIST_ROLE_UNDEF
value|0
end_define

begin_define
define|#
directive|define
name|ADIST_ROLE_SENDER
value|1
end_define

begin_define
define|#
directive|define
name|ADIST_ROLE_RECEIVER
value|2
end_define

begin_define
define|#
directive|define
name|ADIST_USER
value|"auditdistd"
end_define

begin_define
define|#
directive|define
name|ADIST_TIMEOUT
value|20
end_define

begin_define
define|#
directive|define
name|ADIST_CONFIG
value|"/etc/security/auditdistd.conf"
end_define

begin_define
define|#
directive|define
name|ADIST_TCP_PORT
value|"7878"
end_define

begin_define
define|#
directive|define
name|ADIST_LISTEN_TLS_TCP4
value|"tls://0.0.0.0:" ADIST_TCP_PORT
end_define

begin_define
define|#
directive|define
name|ADIST_LISTEN_TLS_TCP6
value|"tls://[::]:" ADIST_TCP_PORT
end_define

begin_define
define|#
directive|define
name|ADIST_PIDFILE
value|"/var/run/auditdistd.pid"
end_define

begin_define
define|#
directive|define
name|ADIST_DIRECTORY_SENDER
value|"/var/audit/dist"
end_define

begin_define
define|#
directive|define
name|ADIST_DIRECTORY_RECEIVER
value|"/var/audit/remote"
end_define

begin_define
define|#
directive|define
name|ADIST_CERTFILE
value|"/etc/security/auditdistd.cert.pem"
end_define

begin_define
define|#
directive|define
name|ADIST_KEYFILE
value|"/etc/security/auditdistd.key.pem"
end_define

begin_define
define|#
directive|define
name|ADIST_ERROR_WRONG_ORDER
value|1
end_define

begin_define
define|#
directive|define
name|ADIST_ERROR_INVALID_NAME
value|2
end_define

begin_define
define|#
directive|define
name|ADIST_ERROR_OPEN_OLD
value|3
end_define

begin_define
define|#
directive|define
name|ADIST_ERROR_CREATE
value|4
end_define

begin_define
define|#
directive|define
name|ADIST_ERROR_OPEN
value|5
end_define

begin_define
define|#
directive|define
name|ADIST_ERROR_READ
value|6
end_define

begin_define
define|#
directive|define
name|ADIST_ERROR_WRITE
value|7
end_define

begin_define
define|#
directive|define
name|ADIST_ERROR_RENAME
value|8
end_define

begin_define
define|#
directive|define
name|ADIST_ADDRSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|ADIST_HOSTSIZE
value|256
end_define

begin_define
define|#
directive|define
name|ADIST_PATHSIZE
value|256
end_define

begin_define
define|#
directive|define
name|ADIST_PASSWORDSIZE
value|128
end_define

begin_define
define|#
directive|define
name|ADIST_FINGERPRINTSIZE
value|256
end_define

begin_comment
comment|/* Number of seconds to sleep between reconnect retries or keepalive packets. */
end_comment

begin_define
define|#
directive|define
name|ADIST_KEEPALIVE
value|10
end_define

begin_struct
struct|struct
name|adist_listen
block|{
comment|/* Address to listen on. */
name|char
name|adl_addr
index|[
name|ADIST_ADDRSIZE
index|]
decl_stmt|;
comment|/* Protocol-specific data. */
name|struct
name|proto_conn
modifier|*
name|adl_conn
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|adist_listen
argument_list|)
name|adl_next
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|adist_config
block|{
comment|/* Our name. */
name|char
name|adc_name
index|[
name|ADIST_HOSTSIZE
index|]
decl_stmt|;
comment|/* PID file path. */
name|char
name|adc_pidfile
index|[
name|PATH_MAX
index|]
decl_stmt|;
comment|/* Connection timeout. */
name|int
name|adc_timeout
decl_stmt|;
comment|/* Path to receiver's certificate file. */
name|char
name|adc_certfile
index|[
name|PATH_MAX
index|]
decl_stmt|;
comment|/* Path to receiver's private key file. */
name|char
name|adc_keyfile
index|[
name|PATH_MAX
index|]
decl_stmt|;
comment|/* List of addresses to listen on. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|adist_listen
argument_list|)
name|adc_listen
expr_stmt|;
comment|/* List of hosts. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|adist_host
argument_list|)
name|adc_hosts
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ADIST_COMPRESSION_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ADIST_COMPRESSION_LZF
value|1
end_define

begin_define
define|#
directive|define
name|ADIST_CHECKSUM_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ADIST_CHECKSUM_CRC32
value|1
end_define

begin_define
define|#
directive|define
name|ADIST_CHECKSUM_SHA256
value|2
end_define

begin_comment
comment|/*  * Structure that describes single host (either sender or receiver).  */
end_comment

begin_struct
struct|struct
name|adist_host
block|{
comment|/* Host name. */
name|char
name|adh_name
index|[
name|ADIST_HOSTSIZE
index|]
decl_stmt|;
comment|/* Host role: ADIST_ROLE_{SENDER,RECEIVER}. */
name|int
name|adh_role
decl_stmt|;
comment|/* Protocol version negotiated. */
name|int
name|adh_version
decl_stmt|;
comment|/* Local address to bind to. */
name|char
name|adh_localaddr
index|[
name|ADIST_ADDRSIZE
index|]
decl_stmt|;
comment|/* Address of the remote component. */
name|char
name|adh_remoteaddr
index|[
name|ADIST_ADDRSIZE
index|]
decl_stmt|;
comment|/* Connection with remote host. */
name|struct
name|proto_conn
modifier|*
name|adh_remote
decl_stmt|;
comment|/* Connection was reestablished, reset the state. */
name|bool
name|adh_reset
decl_stmt|;
comment|/* 	 * Directory from which audit trail files should be send in 	 * ADIST_ROLE_SENDER case or stored into in ADIST_ROLE_RECEIVER case. 	 */
name|char
name|adh_directory
index|[
name|PATH_MAX
index|]
decl_stmt|;
comment|/* Compression algorithm. Currently unused. */
name|int
name|adh_compression
decl_stmt|;
comment|/* Checksum algorithm. Currently unused. */
name|int
name|adh_checksum
decl_stmt|;
comment|/* Sender's password. */
name|char
name|adh_password
index|[
name|ADIST_PASSWORDSIZE
index|]
decl_stmt|;
comment|/* Fingerprint of receiver's public key. */
name|char
name|adh_fingerprint
index|[
name|ADIST_FINGERPRINTSIZE
index|]
decl_stmt|;
comment|/* PID of child worker process. 0 - no child. */
name|pid_t
name|adh_worker_pid
decl_stmt|;
comment|/* Connection requests from sender to main. */
name|struct
name|proto_conn
modifier|*
name|adh_conn
decl_stmt|;
comment|/* Receiver-specific fields. */
name|char
name|adh_trail_name
index|[
name|ADIST_PATHSIZE
index|]
decl_stmt|;
name|int
name|adh_trail_fd
decl_stmt|;
name|int
name|adh_trail_dirfd
decl_stmt|;
name|DIR
modifier|*
name|adh_trail_dirfp
decl_stmt|;
comment|/* Sender-specific fields. */
name|uint64_t
name|adh_trail_offset
decl_stmt|;
comment|/* Next resource. */
name|TAILQ_ENTRY
argument_list|(
argument|adist_host
argument_list|)
name|adh_next
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ADIST_BYTEORDER_UNDEFINED
value|0
end_define

begin_define
define|#
directive|define
name|ADIST_BYTEORDER_LITTLE_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|ADIST_BYTEORDER_BIG_ENDIAN
value|2
end_define

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|ADIST_BYTEORDER
value|ADIST_BYTEORDER_LITTLE_ENDIAN
end_define

begin_elif
elif|#
directive|elif
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
end_elif

begin_define
define|#
directive|define
name|ADIST_BYTEORDER
value|ADIST_BYTEORDER_BIG_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Unknown byte order.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|adpkt
block|{
name|uint8_t
name|adp_byteorder
decl_stmt|;
define|#
directive|define
name|ADIST_CMD_UNDEFINED
value|0
define|#
directive|define
name|ADIST_CMD_OPEN
value|1
define|#
directive|define
name|ADIST_CMD_APPEND
value|2
define|#
directive|define
name|ADIST_CMD_CLOSE
value|3
define|#
directive|define
name|ADIST_CMD_KEEPALIVE
value|4
define|#
directive|define
name|ADIST_CMD_ERROR
value|5
name|uint8_t
name|adp_cmd
decl_stmt|;
name|uint64_t
name|adp_seq
decl_stmt|;
name|uint32_t
name|adp_datasize
decl_stmt|;
name|unsigned
name|char
name|adp_data
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|adreq
block|{
name|int
name|adr_error
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|adreq
argument_list|)
name|adr_next
expr_stmt|;
name|struct
name|adpkt
name|adr_packet
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|adr_byteorder
value|adr_packet.adp_byteorder
end_define

begin_define
define|#
directive|define
name|adr_cmd
value|adr_packet.adp_cmd
end_define

begin_define
define|#
directive|define
name|adr_seq
value|adr_packet.adp_seq
end_define

begin_define
define|#
directive|define
name|adr_datasize
value|adr_packet.adp_datasize
end_define

begin_define
define|#
directive|define
name|adr_data
value|adr_packet.adp_data
end_define

begin_define
define|#
directive|define
name|ADPKT_SIZE
parameter_list|(
name|adreq
parameter_list|)
value|(sizeof((adreq)->adr_packet) + (adreq)->adr_datasize)
end_define

begin_struct
struct|struct
name|adrep
block|{
name|uint8_t
name|adrp_byteorder
decl_stmt|;
name|uint64_t
name|adrp_seq
decl_stmt|;
name|uint16_t
name|adrp_error
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|ADIST_QUEUE_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|ADIST_BUF_SIZE
value|65536
end_define

begin_define
define|#
directive|define
name|QUEUE_TAKE
parameter_list|(
name|adreq
parameter_list|,
name|list
parameter_list|,
name|timeout
parameter_list|)
value|do {			\ 	mtx_lock(list##_lock);						\ 	if ((timeout) == 0) {						\ 		while (((adreq) = TAILQ_FIRST(list)) == NULL)		\ 			cv_wait(list##_cond, list##_lock);		\ 	} else {							\ 		(adreq) = TAILQ_FIRST(list);				\ 		if ((adreq) == NULL) {					\ 			cv_timedwait(list##_cond, list##_lock,		\ 			    (timeout));					\ 			(adreq) = TAILQ_FIRST(list);			\ 		}							\ 	}								\ 	if ((adreq) != NULL)						\ 		TAILQ_REMOVE((list), (adreq), adr_next);		\ 	mtx_unlock(list##_lock);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|QUEUE_INSERT
parameter_list|(
name|adreq
parameter_list|,
name|list
parameter_list|)
value|do {				\ 	bool _wakeup;							\ 									\ 	mtx_lock(list##_lock);						\ 	_wakeup = TAILQ_EMPTY(list);					\ 	TAILQ_INSERT_TAIL((list), (adreq), adr_next);			\ 	mtx_unlock(list##_lock);					\ 	if (_wakeup)							\ 		cv_signal(list##_cond);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|QUEUE_WAIT
parameter_list|(
name|list
parameter_list|)
value|do {					\ 	mtx_lock(list##_lock);						\ 	while (TAILQ_EMPTY(list))					\ 		cv_wait(list##_cond, list##_lock);			\ 	mtx_unlock(list##_lock);					\ } while (0)
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|cfgpath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|sigexit_received
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pidfh
modifier|*
name|pfh
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|descriptors_cleanup
parameter_list|(
name|struct
name|adist_host
modifier|*
name|adhost
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|descriptors_assert
parameter_list|(
specifier|const
name|struct
name|adist_host
modifier|*
name|adhost
parameter_list|,
name|int
name|pjdlogmode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adist_sender
parameter_list|(
name|struct
name|adist_config
modifier|*
name|config
parameter_list|,
name|struct
name|adist_host
modifier|*
name|adhost
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adist_receiver
parameter_list|(
name|struct
name|adist_config
modifier|*
name|config
parameter_list|,
name|struct
name|adist_host
modifier|*
name|adhost
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|adist_config
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
name|adist_config
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|yyerror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yylex
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
comment|/* !_AUDITDISTD_H_ */
end_comment

end_unit

