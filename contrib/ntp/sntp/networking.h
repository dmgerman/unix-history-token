begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|NETWORKING_H
end_ifndef

begin_define
define|#
directive|define
name|NETWORKING_H
end_define

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
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<ntp_rfc2553.h>
end_include

begin_include
include|#
directive|include
file|<ntp_stdlib.h>
end_include

begin_include
include|#
directive|include
file|<ntp_machine.h>
end_include

begin_include
include|#
directive|include
file|<ntp_unixtime.h>
end_include

begin_include
include|#
directive|include
file|<ntp_fp.h>
end_include

begin_include
include|#
directive|include
file|<ntp.h>
end_include

begin_include
include|#
directive|include
file|"crypto.h"
end_include

begin_include
include|#
directive|include
file|"log.h"
end_include

begin_include
include|#
directive|include
file|"sntp-opts.h"
end_include

begin_include
include|#
directive|include
file|"utilities.h"
end_include

begin_comment
comment|/* FIXME To be replaced by the constants in ntp.h */
end_comment

begin_define
define|#
directive|define
name|SERVER_UNUSEABLE
value|-1
end_define

begin_comment
comment|/* Skip server */
end_comment

begin_define
define|#
directive|define
name|PACKET_UNUSEABLE
value|-2
end_define

begin_comment
comment|/* Discard packet and try to get a useable packet again if not tried too often */
end_comment

begin_define
define|#
directive|define
name|SERVER_AUTH_FAIL
value|-3
end_define

begin_comment
comment|/* Authentication failed, act upon settings */
end_comment

begin_define
define|#
directive|define
name|KOD_DEMOBILIZE
value|-4
end_define

begin_comment
comment|/* KOD packet with code DENY or RSTR, stop all communication and save KOD information */
end_comment

begin_define
define|#
directive|define
name|KOD_RATE
value|-5
end_define

begin_comment
comment|/* KOD packet with code RATE, reduce poll intervall */
end_comment

begin_define
define|#
directive|define
name|BROADCAST_FAILED
value|-6
end_define

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
name|int
name|sendpkt
parameter_list|(
name|SOCKET
name|rsock
parameter_list|,
name|sockaddr_u
modifier|*
name|dest
parameter_list|,
name|struct
name|pkt
modifier|*
name|pkt
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|recvdata
parameter_list|(
name|SOCKET
name|rsock
parameter_list|,
name|sockaddr_u
modifier|*
name|sender
parameter_list|,
name|void
modifier|*
name|rdata
parameter_list|,
name|int
name|rdata_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|recvpkt
parameter_list|(
name|SOCKET
name|rsock
parameter_list|,
name|struct
name|pkt
modifier|*
name|rpkt
parameter_list|,
name|unsigned
name|int
name|rsize
parameter_list|,
name|struct
name|pkt
modifier|*
name|spkt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|process_pkt
parameter_list|(
name|struct
name|pkt
modifier|*
name|rpkt
parameter_list|,
name|sockaddr_u
modifier|*
name|sas
parameter_list|,
name|int
name|pkt_len
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|pkt
modifier|*
name|spkt
parameter_list|,
specifier|const
name|char
modifier|*
name|func_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Shortened peer structure. Not absolutely necessary yet */
end_comment

begin_struct
struct|struct
name|speer
block|{
name|struct
name|speer
modifier|*
name|next
decl_stmt|;
name|sockaddr_u
name|srcadr
decl_stmt|;
name|u_char
name|version
decl_stmt|;
name|u_char
name|hmode
decl_stmt|;
name|u_char
name|hpoll
decl_stmt|;
name|u_char
name|minpoll
decl_stmt|;
name|u_char
name|maxpoll
decl_stmt|;
name|u_int
name|flags
decl_stmt|;
name|u_char
name|num_events
decl_stmt|;
name|u_char
name|ttl
decl_stmt|;
name|u_char
name|leap
decl_stmt|;
name|u_char
name|pmode
decl_stmt|;
name|u_char
name|stratum
decl_stmt|;
name|u_char
name|ppoll
decl_stmt|;
name|u_char
name|precision
decl_stmt|;
comment|/* should be s_char */
name|u_int32
name|refid
decl_stmt|;
name|l_fp
name|reftime
decl_stmt|;
name|keyid_t
name|keyid
decl_stmt|;
ifdef|#
directive|ifdef
name|AUTOKEY
define|#
directive|define
name|clear_to_zero
value|opcode
name|u_int32
name|opcode
decl_stmt|;
comment|/* last request opcode */
name|associd_t
name|assoc
decl_stmt|;
comment|/* peer association ID */
name|u_int32
name|crypto
decl_stmt|;
comment|/* peer status word */
name|EVP_PKEY
modifier|*
name|pkey
decl_stmt|;
comment|/* public key */
specifier|const
name|EVP_MD
modifier|*
name|digest
decl_stmt|;
comment|/* message digest algorithm */
name|char
modifier|*
name|subject
decl_stmt|;
comment|/* certificate subject name */
name|char
modifier|*
name|issuer
decl_stmt|;
comment|/* certificate issuer name */
name|struct
name|cert_info
modifier|*
name|xinfo
decl_stmt|;
comment|/* issuer certificate */
name|keyid_t
name|pkeyid
decl_stmt|;
comment|/* previous key ID */
name|keyid_t
name|hcookie
decl_stmt|;
comment|/* host cookie */
name|keyid_t
name|pcookie
decl_stmt|;
comment|/* peer cookie */
specifier|const
name|struct
name|pkey_info
modifier|*
name|ident_pkey
decl_stmt|;
comment|/* identity key */
name|BIGNUM
modifier|*
name|iffval
decl_stmt|;
comment|/* identity challenge (IFF, GQ, MV) */
specifier|const
name|BIGNUM
modifier|*
name|grpkey
decl_stmt|;
comment|/* identity challenge key (GQ) */
name|struct
name|value
name|cookval
decl_stmt|;
comment|/* receive cookie values */
name|struct
name|value
name|recval
decl_stmt|;
comment|/* receive autokey values */
name|struct
name|exten
modifier|*
name|cmmd
decl_stmt|;
comment|/* extension pointer */
name|u_long
name|refresh
decl_stmt|;
comment|/* next refresh epoch */
comment|/* 	 * Variables used by authenticated server 	 */
name|keyid_t
modifier|*
name|keylist
decl_stmt|;
comment|/* session key ID list */
name|int
name|keynumber
decl_stmt|;
comment|/* current key number */
name|struct
name|value
name|encrypt
decl_stmt|;
comment|/* send encrypt values */
name|struct
name|value
name|sndval
decl_stmt|;
comment|/* send autokey values */
else|#
directive|else
comment|/* !AUTOKEY follows */
define|#
directive|define
name|clear_to_zero
value|status
endif|#
directive|endif
comment|/* !AUTOKEY */
name|l_fp
name|rec
decl_stmt|;
comment|/* receive time stamp */
name|l_fp
name|xmt
decl_stmt|;
comment|/* transmit time stamp */
name|l_fp
name|dst
decl_stmt|;
comment|/* destination timestamp */
name|l_fp
name|aorg
decl_stmt|;
comment|/* origin timestamp */
name|l_fp
name|borg
decl_stmt|;
comment|/* alternate origin timestamp */
name|double
name|offset
decl_stmt|;
comment|/* peer clock offset */
name|double
name|delay
decl_stmt|;
comment|/* peer roundtrip delay */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

