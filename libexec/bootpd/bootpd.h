begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************           Copyright 1988, 1991 by Carnegie Mellon University                            All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of Carnegie Mellon University not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  CARNEGIE MELLON UNIVERSITY DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL CMU BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. ************************************************************************/
end_comment

begin_comment
comment|/*  * bootpd.h -- common header file for all the modules of the bootpd program.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"bptypes.h"
end_include

begin_include
include|#
directive|include
file|"hash.h"
end_include

begin_include
include|#
directive|include
file|"hwaddr.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIVATE
end_ifndef

begin_define
define|#
directive|define
name|PRIVATE
value|static
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIGUSR1
end_ifndef

begin_define
define|#
directive|define
name|SIGUSR1
value|30
end_define

begin_comment
comment|/* From 4.3<signal.h> */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAXSTRINGLEN
value|80
end_define

begin_comment
comment|/* Max string length */
end_comment

begin_comment
comment|/* Local definitions: */
end_comment

begin_define
define|#
directive|define
name|MAX_MSG_SIZE
value|(3*512)
end_define

begin_comment
comment|/* Maximum packet size */
end_comment

begin_comment
comment|/*  * Return pointer to static string which gives full network error message.  */
end_comment

begin_define
define|#
directive|define
name|get_network_errmsg
value|get_errmsg
end_define

begin_comment
comment|/*  * Data structure used to hold an arbitrary-lengthed list of IP addresses.  * The list may be shared among multiple hosts by setting the linkcount  * appropriately.  */
end_comment

begin_struct
struct|struct
name|in_addr_list
block|{
name|unsigned
name|int
name|linkcount
decl_stmt|,
name|addrcount
decl_stmt|;
name|struct
name|in_addr
name|addr
index|[
literal|1
index|]
decl_stmt|;
comment|/* Dynamically extended */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Data structures used to hold shared strings and shared binary data.  * The linkcount must be set appropriately.  */
end_comment

begin_struct
struct|struct
name|shared_string
block|{
name|unsigned
name|int
name|linkcount
decl_stmt|;
name|char
name|string
index|[
literal|1
index|]
decl_stmt|;
comment|/* Dynamically extended */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|shared_bindata
block|{
name|unsigned
name|int
name|linkcount
decl_stmt|,
name|length
decl_stmt|;
name|byte
name|data
index|[
literal|1
index|]
decl_stmt|;
comment|/* Dynamically extended */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flag structure which indicates which symbols have been defined for a  * given host.  This information is used to determine which data should or  * should not be reported in the bootp packet vendor info field.  */
end_comment

begin_struct
struct|struct
name|flag
block|{
name|unsigned
name|bootfile
range|:
literal|1
decl_stmt|,
name|bootserver
range|:
literal|1
decl_stmt|,
name|bootsize
range|:
literal|1
decl_stmt|,
name|bootsize_auto
range|:
literal|1
decl_stmt|,
name|cookie_server
range|:
literal|1
decl_stmt|,
name|domain_server
range|:
literal|1
decl_stmt|,
name|gateway
range|:
literal|1
decl_stmt|,
name|generic
range|:
literal|1
decl_stmt|,
name|haddr
range|:
literal|1
decl_stmt|,
name|homedir
range|:
literal|1
decl_stmt|,
name|htype
range|:
literal|1
decl_stmt|,
name|impress_server
range|:
literal|1
decl_stmt|,
name|iaddr
range|:
literal|1
decl_stmt|,
name|log_server
range|:
literal|1
decl_stmt|,
name|lpr_server
range|:
literal|1
decl_stmt|,
name|name_server
range|:
literal|1
decl_stmt|,
name|name_switch
range|:
literal|1
decl_stmt|,
name|rlp_server
range|:
literal|1
decl_stmt|,
name|send_name
range|:
literal|1
decl_stmt|,
name|subnet_mask
range|:
literal|1
decl_stmt|,
name|tftpdir
range|:
literal|1
decl_stmt|,
name|time_offset
range|:
literal|1
decl_stmt|,
name|time_server
range|:
literal|1
decl_stmt|,
name|dump_file
range|:
literal|1
decl_stmt|,
name|domain_name
range|:
literal|1
decl_stmt|,
name|swap_server
range|:
literal|1
decl_stmt|,
name|root_path
range|:
literal|1
decl_stmt|,
name|exten_file
range|:
literal|1
decl_stmt|,
name|reply_addr
range|:
literal|1
decl_stmt|,
name|nis_domain
range|:
literal|1
decl_stmt|,
name|nis_server
range|:
literal|1
decl_stmt|,
name|ntp_server
range|:
literal|1
decl_stmt|,
name|exec_file
range|:
literal|1
decl_stmt|,
name|msg_size
range|:
literal|1
decl_stmt|,
name|min_wait
range|:
literal|1
decl_stmt|,
comment|/* XXX - Add new tags here */
name|vm_cookie
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/*  * The flags structure contains TRUE flags for all the fields which  * are considered valid, regardless of whether they were explicitly  * specified or indirectly inferred from another entry.  *  * The gateway and the various server fields all point to a shared list of  * IP addresses.  *  * The hostname, home directory, and bootfile are all shared strings.  *  * The generic data field is a shared binary data structure.  It is used to  * hold future RFC1048 vendor data until bootpd is updated to understand it.  *  * The vm_cookie field specifies the four-octet vendor magic cookie to use  * if it is desired to always send the same response to a given host.  *  * Hopefully, the rest is self-explanatory.  */
end_comment

begin_struct
struct|struct
name|host
block|{
name|unsigned
name|linkcount
decl_stmt|;
comment|/* hash list inserts */
name|struct
name|flag
name|flags
decl_stmt|;
comment|/* ALL valid fields */
name|struct
name|in_addr_list
modifier|*
name|cookie_server
decl_stmt|,
modifier|*
name|domain_server
decl_stmt|,
modifier|*
name|gateway
decl_stmt|,
modifier|*
name|impress_server
decl_stmt|,
modifier|*
name|log_server
decl_stmt|,
modifier|*
name|lpr_server
decl_stmt|,
modifier|*
name|name_server
decl_stmt|,
modifier|*
name|rlp_server
decl_stmt|,
modifier|*
name|time_server
decl_stmt|,
modifier|*
name|nis_server
decl_stmt|,
modifier|*
name|ntp_server
decl_stmt|;
name|struct
name|shared_string
modifier|*
name|bootfile
decl_stmt|,
modifier|*
name|hostname
decl_stmt|,
modifier|*
name|domain_name
decl_stmt|,
modifier|*
name|homedir
decl_stmt|,
modifier|*
name|tftpdir
decl_stmt|,
modifier|*
name|dump_file
decl_stmt|,
modifier|*
name|exten_file
decl_stmt|,
modifier|*
name|root_path
decl_stmt|,
modifier|*
name|nis_domain
decl_stmt|,
modifier|*
name|exec_file
decl_stmt|;
name|struct
name|shared_bindata
modifier|*
name|generic
decl_stmt|;
name|byte
name|vm_cookie
index|[
literal|4
index|]
decl_stmt|,
name|htype
decl_stmt|,
comment|/* RFC826 says this should be 16-bits but 				       RFC951 only allocates 1 byte. . . */
name|haddr
index|[
name|MAXHADDRLEN
index|]
decl_stmt|;
name|int32
name|time_offset
decl_stmt|;
name|u_int32
name|bootsize
decl_stmt|,
name|msg_size
decl_stmt|,
name|min_wait
decl_stmt|;
name|struct
name|in_addr
name|bootserver
decl_stmt|,
name|iaddr
decl_stmt|,
name|swap_server
decl_stmt|,
name|reply_addr
decl_stmt|,
name|subnet_mask
decl_stmt|;
comment|/* XXX - Add new tags here (or above as appropriate) */
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/*  * Variables shared among modules.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|bootptab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|vm_cmu
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|vm_rfc1048
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|hash_tbl
modifier|*
name|hwhashtable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|hash_tbl
modifier|*
name|iphashtable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|hash_tbl
modifier|*
name|nmhashtable
decl_stmt|;
end_decl_stmt

end_unit

