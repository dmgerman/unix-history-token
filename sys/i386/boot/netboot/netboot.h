begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************** NETBOOT -  BOOTP/TFTP Bootstrap Program  Author: Martin Renters   Date: Dec/93  **************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<a.out.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<nfs/nfsv2.h>
end_include

begin_include
include|#
directive|include
file|<nfs/rpcv2.h>
end_include

begin_include
include|#
directive|include
file|<nfs/nfs.h>
end_include

begin_include
include|#
directive|include
file|<nfs/nfsdiskless.h>
end_include

begin_include
include|#
directive|include
file|<machine/bootinfo.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_define
define|#
directive|define
name|ESC
value|0x1B
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_BOOTFILE
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_BOOTFILE
value|"/kernel"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_TFTP_RETRIES
end_ifndef

begin_define
define|#
directive|define
name|MAX_TFTP_RETRIES
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_BOOTP_RETRIES
end_ifndef

begin_define
define|#
directive|define
name|MAX_BOOTP_RETRIES
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_ARP_RETRIES
end_ifndef

begin_define
define|#
directive|define
name|MAX_ARP_RETRIES
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_RPC_RETRIES
end_ifndef

begin_define
define|#
directive|define
name|MAX_RPC_RETRIES
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TIMEOUT
end_ifndef

begin_comment
comment|/* Inter-packet retry in ticks 18/sec */
end_comment

begin_define
define|#
directive|define
name|TIMEOUT
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|((void *)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|VENDOR_NONE
value|0
end_define

begin_define
define|#
directive|define
name|VENDOR_WD
value|1
end_define

begin_define
define|#
directive|define
name|VENDOR_NOVELL
value|2
end_define

begin_define
define|#
directive|define
name|VENDOR_3COM
value|3
end_define

begin_define
define|#
directive|define
name|VENDOR_3C509
value|4
end_define

begin_define
define|#
directive|define
name|FLAG_PIO
value|0x01
end_define

begin_define
define|#
directive|define
name|FLAG_16BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|FLAG_790
value|0x04
end_define

begin_define
define|#
directive|define
name|ARP_CLIENT
value|0
end_define

begin_define
define|#
directive|define
name|ARP_SERVER
value|1
end_define

begin_define
define|#
directive|define
name|ARP_GATEWAY
value|2
end_define

begin_define
define|#
directive|define
name|ARP_NS
value|3
end_define

begin_define
define|#
directive|define
name|ARP_ROOTSERVER
value|4
end_define

begin_define
define|#
directive|define
name|ARP_SWAPSERVER
value|5
end_define

begin_define
define|#
directive|define
name|MAX_ARP
value|ARP_SWAPSERVER+1
end_define

begin_define
define|#
directive|define
name|IP
value|0x0800
end_define

begin_define
define|#
directive|define
name|ARP
value|0x0806
end_define

begin_define
define|#
directive|define
name|BOOTP_SERVER
value|67
end_define

begin_define
define|#
directive|define
name|BOOTP_CLIENT
value|68
end_define

begin_define
define|#
directive|define
name|TFTP
value|69
end_define

begin_define
define|#
directive|define
name|SUNRPC
value|111
end_define

begin_define
define|#
directive|define
name|RPC_SOCKET
value|620
end_define

begin_comment
comment|/* Arbitrary */
end_comment

begin_define
define|#
directive|define
name|IP_UDP
value|17
end_define

begin_define
define|#
directive|define
name|IP_BROADCAST
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|ARP_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|ARP_REPLY
value|2
end_define

begin_define
define|#
directive|define
name|BOOTP_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|BOOTP_REPLY
value|2
end_define

begin_define
define|#
directive|define
name|TAG_LEN
parameter_list|(
name|p
parameter_list|)
value|(*((p)+1))
end_define

begin_define
define|#
directive|define
name|RFC1048_COOKIE
value|{ 99, 130, 83, 99 }
end_define

begin_define
define|#
directive|define
name|RFC1048_PAD
value|0
end_define

begin_define
define|#
directive|define
name|RFC1048_NETMASK
value|1
end_define

begin_define
define|#
directive|define
name|RFC1048_TIME_OFFSET
value|2
end_define

begin_define
define|#
directive|define
name|RFC1048_GATEWAY
value|3
end_define

begin_define
define|#
directive|define
name|RFC1048_TIME_SERVER
value|4
end_define

begin_define
define|#
directive|define
name|RFC1048_NAME_SERVER
value|5
end_define

begin_define
define|#
directive|define
name|RFC1048_DOMAIN_SERVER
value|6
end_define

begin_define
define|#
directive|define
name|RFC1048_HOSTNAME
value|12
end_define

begin_define
define|#
directive|define
name|RFC1048_BOOT_SIZE
value|12
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|RFC1048_SWAP_SERVER
value|16
end_define

begin_define
define|#
directive|define
name|RFC1048_ROOT_PATH
value|17
end_define

begin_define
define|#
directive|define
name|RFC1048_SWAP_PATH
value|128
end_define

begin_comment
comment|/* T128 */
end_comment

begin_define
define|#
directive|define
name|RFC1048_SWAP_LEN
value|129
end_define

begin_comment
comment|/* T129 */
end_comment

begin_define
define|#
directive|define
name|RFC1048_END
value|255
end_define

begin_define
define|#
directive|define
name|BOOTP_VENDOR_LEN
value|256
end_define

begin_comment
comment|/* Extended vendor field */
end_comment

begin_define
define|#
directive|define
name|BOOTP_MIN_LEN
value|300
end_define

begin_comment
comment|/* Minimum size of bootp udp packet */
end_comment

begin_define
define|#
directive|define
name|TFTP_RRQ
value|1
end_define

begin_define
define|#
directive|define
name|TFTP_WRQ
value|2
end_define

begin_define
define|#
directive|define
name|TFTP_DATA
value|3
end_define

begin_define
define|#
directive|define
name|TFTP_ACK
value|4
end_define

begin_define
define|#
directive|define
name|TFTP_ERROR
value|5
end_define

begin_define
define|#
directive|define
name|TFTP_CODE_EOF
value|1
end_define

begin_define
define|#
directive|define
name|TFTP_CODE_MORE
value|2
end_define

begin_define
define|#
directive|define
name|TFTP_CODE_ERROR
value|3
end_define

begin_define
define|#
directive|define
name|TFTP_CODE_BOOT
value|4
end_define

begin_define
define|#
directive|define
name|TFTP_CODE_CFG
value|5
end_define

begin_define
define|#
directive|define
name|PROG_PORTMAP
value|100000
end_define

begin_define
define|#
directive|define
name|PROG_NFS
value|100003
end_define

begin_define
define|#
directive|define
name|PROG_MOUNT
value|100005
end_define

begin_define
define|#
directive|define
name|MSG_CALL
value|0
end_define

begin_define
define|#
directive|define
name|MSG_REPLY
value|1
end_define

begin_define
define|#
directive|define
name|PORTMAP_LOOKUP
value|3
end_define

begin_define
define|#
directive|define
name|MOUNT_ADDENTRY
value|1
end_define

begin_define
define|#
directive|define
name|NFS_LOOKUP
value|4
end_define

begin_define
define|#
directive|define
name|NFS_READ
value|6
end_define

begin_define
define|#
directive|define
name|NFS_READ_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|AWAIT_ARP
value|0
end_define

begin_define
define|#
directive|define
name|AWAIT_BOOTP
value|1
end_define

begin_define
define|#
directive|define
name|AWAIT_TFTP
value|2
end_define

begin_define
define|#
directive|define
name|AWAIT_RPC
value|3
end_define

begin_struct
struct|struct
name|arptable_t
block|{
name|unsigned
name|long
name|ipaddr
decl_stmt|;
name|unsigned
name|char
name|node
index|[
literal|6
index|]
decl_stmt|;
block|}
name|arptable
index|[
name|MAX_ARP
index|]
struct|;
end_struct

begin_struct
struct|struct
name|arprequest
block|{
name|unsigned
name|short
name|hwtype
decl_stmt|;
name|unsigned
name|short
name|protocol
decl_stmt|;
name|char
name|hwlen
decl_stmt|;
name|char
name|protolen
decl_stmt|;
name|unsigned
name|short
name|opcode
decl_stmt|;
name|char
name|shwaddr
index|[
literal|6
index|]
decl_stmt|;
name|char
name|sipaddr
index|[
literal|4
index|]
decl_stmt|;
name|char
name|thwaddr
index|[
literal|6
index|]
decl_stmt|;
name|char
name|tipaddr
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iphdr
block|{
name|char
name|verhdrlen
decl_stmt|;
name|char
name|service
decl_stmt|;
name|unsigned
name|short
name|len
decl_stmt|;
name|unsigned
name|short
name|ident
decl_stmt|;
name|unsigned
name|short
name|frags
decl_stmt|;
name|char
name|ttl
decl_stmt|;
name|char
name|protocol
decl_stmt|;
name|unsigned
name|short
name|chksum
decl_stmt|;
name|char
name|src
index|[
literal|4
index|]
decl_stmt|;
name|char
name|dest
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|udphdr
block|{
name|unsigned
name|short
name|src
decl_stmt|;
name|unsigned
name|short
name|dest
decl_stmt|;
name|unsigned
name|short
name|len
decl_stmt|;
name|unsigned
name|short
name|chksum
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bootp_t
block|{
name|struct
name|iphdr
name|ip
decl_stmt|;
name|struct
name|udphdr
name|udp
decl_stmt|;
name|char
name|bp_op
decl_stmt|;
name|char
name|bp_htype
decl_stmt|;
name|char
name|bp_hlen
decl_stmt|;
name|char
name|bp_hops
decl_stmt|;
name|unsigned
name|long
name|bp_xid
decl_stmt|;
name|unsigned
name|short
name|bp_secs
decl_stmt|;
name|unsigned
name|short
name|unused
decl_stmt|;
name|char
name|bp_ciaddr
index|[
literal|4
index|]
decl_stmt|;
name|char
name|bp_yiaddr
index|[
literal|4
index|]
decl_stmt|;
name|char
name|bp_siaddr
index|[
literal|4
index|]
decl_stmt|;
name|char
name|bp_giaddr
index|[
literal|4
index|]
decl_stmt|;
name|char
name|bp_hwaddr
index|[
literal|16
index|]
decl_stmt|;
name|char
name|bp_sname
index|[
literal|64
index|]
decl_stmt|;
name|char
name|bp_file
index|[
literal|128
index|]
decl_stmt|;
name|char
name|bp_vend
index|[
name|BOOTP_VENDOR_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tftp_t
block|{
name|struct
name|iphdr
name|ip
decl_stmt|;
name|struct
name|udphdr
name|udp
decl_stmt|;
name|unsigned
name|short
name|opcode
decl_stmt|;
union|union
block|{
name|char
name|rrq
index|[
literal|512
index|]
decl_stmt|;
struct|struct
block|{
name|unsigned
name|short
name|block
decl_stmt|;
name|char
name|download
index|[
literal|512
index|]
decl_stmt|;
block|}
name|data
struct|;
struct|struct
block|{
name|unsigned
name|short
name|block
decl_stmt|;
block|}
name|ack
struct|;
struct|struct
block|{
name|unsigned
name|short
name|errcode
decl_stmt|;
name|char
name|errmsg
index|[
literal|512
index|]
decl_stmt|;
block|}
name|err
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rpc_t
block|{
name|struct
name|iphdr
name|ip
decl_stmt|;
name|struct
name|udphdr
name|udp
decl_stmt|;
union|union
block|{
name|char
name|data
index|[
literal|1400
index|]
decl_stmt|;
struct|struct
block|{
name|long
name|id
decl_stmt|;
name|long
name|type
decl_stmt|;
name|long
name|rstatus
decl_stmt|;
name|long
name|verifier
decl_stmt|;
name|long
name|v2
decl_stmt|;
name|long
name|astatus
decl_stmt|;
name|long
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|reply
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TFTP_MIN_PACKET_SIZE
value|(sizeof(struct iphdr) + sizeof(struct udphdr) + 4)
end_define

begin_comment
comment|/*************************************************************************** RPC Functions ***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PUTLONG
parameter_list|(
name|val
parameter_list|)
value|{\ 	register int lval = val; \ 	*(rpcptr++) = ((lval)>> 24); \ 	*(rpcptr++) = ((lval)>> 16); \ 	*(rpcptr++) = ((lval)>> 8); \ 	*(rpcptr++) = (lval); \ 	rpclen+=4; }
end_define

begin_function_decl
name|char
modifier|*
name|sprintf
parameter_list|()
function_decl|;
end_function_decl

end_unit

