begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNCP_NCP_CONN_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNCP_NCP_CONN_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IN_H_
end_ifndef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IPX
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPX_IPX_H_
end_ifndef

begin_include
include|#
directive|include
file|<netipx/ipx.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SOCKET_H_
end_ifndef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* type of transport we use */
end_comment

begin_comment
comment|/*#define	NCP_ON_IPX	0 #define	NCP_ON_TCP	1*/
end_comment

begin_comment
comment|/* flags field in conn structure */
end_comment

begin_define
define|#
directive|define
name|NCPFL_SOCONN
value|0x01
end_define

begin_comment
comment|/* socket layer is up */
end_comment

begin_define
define|#
directive|define
name|NCPFL_ATTACHED
value|0x02
end_define

begin_comment
comment|/* ncp layer is up */
end_comment

begin_define
define|#
directive|define
name|NCPFL_LOGGED
value|0x04
end_define

begin_comment
comment|/* logged in to server */
end_comment

begin_define
define|#
directive|define
name|NCPFL_INVALID
value|0x08
end_define

begin_comment
comment|/* last request was not completed */
end_comment

begin_define
define|#
directive|define
name|NCPFL_INTR
value|0x10
end_define

begin_comment
comment|/* interrupted call */
end_comment

begin_define
define|#
directive|define
name|NCPFL_RESTORING
value|0x20
end_define

begin_comment
comment|/* trying to reconnect */
end_comment

begin_define
define|#
directive|define
name|NCPFL_PERMANENT
value|0x40
end_define

begin_comment
comment|/* no way to kill conn, when this set */
end_comment

begin_define
define|#
directive|define
name|NCPFL_PRIMARY
value|0x80
end_define

begin_comment
comment|/* have meaning only for owner */
end_comment

begin_define
define|#
directive|define
name|NCPFL_SIGNACTIVE
value|0x1000
end_define

begin_comment
comment|/* packet signing active */
end_comment

begin_define
define|#
directive|define
name|NCPFL_SIGNWANTED
value|0x2000
end_define

begin_comment
comment|/* signing should start */
end_comment

begin_comment
comment|/* access mode for connection */
end_comment

begin_define
define|#
directive|define
name|NCPM_READ
value|0400
end_define

begin_comment
comment|/* able to fetch conn params */
end_comment

begin_define
define|#
directive|define
name|NCPM_WRITE
value|0200
end_define

begin_comment
comment|/* modify/close */
end_comment

begin_define
define|#
directive|define
name|NCPM_EXECUTE
value|0100
end_define

begin_comment
comment|/* run requests */
end_comment

begin_define
define|#
directive|define
name|NCP_DEFAULT_OWNER
value|((uid_t)-1)
end_define

begin_define
define|#
directive|define
name|NCP_DEFAULT_GROUP
value|((uid_t)-1)
end_define

begin_comment
comment|/* args used to create connection */
end_comment

begin_define
define|#
directive|define
name|ncp_conn_loginfo
value|ncp_conn_args
end_define

begin_struct
struct|struct
name|ncp_conn_args
block|{
name|int
name|opt
decl_stmt|;
define|#
directive|define
name|NCP_OPT_WDOG
value|1
comment|/* need watch dog socket */
define|#
directive|define
name|NCP_OPT_MSG
value|2
comment|/* need message socket */
define|#
directive|define
name|NCP_OPT_SIGN
value|4
comment|/* signatures wanted */
define|#
directive|define
name|NCP_OPT_BIND
value|8
comment|/* force bindery login */
define|#
directive|define
name|NCP_OPT_PERMANENT
value|0x10
comment|/* only for refernce, completly ignored */
define|#
directive|define
name|NCP_OPT_NOUPCASEPASS
value|0x20
comment|/* leave password as is */
name|int
name|sig_level
decl_stmt|;
comment|/* wanted signature level */
name|char
name|server
index|[
name|NCP_BINDERY_NAME_LEN
operator|+
literal|1
index|]
decl_stmt|;
name|char
modifier|*
name|user
decl_stmt|;
name|char
modifier|*
name|password
decl_stmt|;
name|u_int32_t
name|objtype
decl_stmt|;
union|union
block|{
name|struct
name|sockaddr
name|addr
decl_stmt|;
ifdef|#
directive|ifdef
name|IPX
name|struct
name|sockaddr_ipx
name|ipxaddr
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|INET
name|struct
name|sockaddr_in
name|inaddr
decl_stmt|;
endif|#
directive|endif
block|}
name|addr
union|;
name|int
name|timeout
decl_stmt|;
comment|/* ncp rq timeout */
name|int
name|retry_count
decl_stmt|;
comment|/* counts to give an error */
name|uid_t
name|owner
decl_stmt|;
comment|/* proposed owner of connection */
name|gid_t
name|group
decl_stmt|;
comment|/* proposed group of connection */
name|mode_t
name|access_mode
decl_stmt|;
comment|/* R/W - can do rq's, X - can see the conn */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ipxaddr
value|addr.ipxaddr
end_define

begin_define
define|#
directive|define
name|inaddr
value|addr.inaddr
end_define

begin_define
define|#
directive|define
name|saddr
value|addr.addr
end_define

begin_comment
comment|/* user side structure to issue ncp calls */
end_comment

begin_struct
struct|struct
name|ncp_buf
block|{
name|int
name|rqsize
decl_stmt|;
comment|/* request size without ncp header */
name|int
name|rpsize
decl_stmt|;
comment|/* reply size minus ncp header */
name|int
name|cc
decl_stmt|;
comment|/* completion code */
name|int
name|cs
decl_stmt|;
comment|/* connection state */
name|char
name|packet
index|[
name|NCP_MAX_PACKET_SIZE
index|]
decl_stmt|;
comment|/* Here we prepare requests and receive replies */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Connection status, returned via sysctl(vfs.nwfs.connstat)  */
end_comment

begin_struct
struct|struct
name|ncp_conn_stat
block|{
name|struct
name|ncp_conn_args
name|li
decl_stmt|;
name|int
name|connRef
decl_stmt|;
name|int
name|ref_cnt
decl_stmt|;
name|int
name|connid
decl_stmt|;
name|int
name|buffer_size
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|int
name|sign_active
decl_stmt|;
name|uid_t
name|owner
decl_stmt|;
name|gid_t
name|group
decl_stmt|;
name|char
name|user
index|[
name|NCP_MAXUSERNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|LK_SHARED
end_ifndef

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|u_cred
struct_decl|;
end_struct_decl

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|ncp_conn_head
argument_list|,
name|ncp_conn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|ncp_rq
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ncp_conn
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * External and internal processes can reference connection only by handle.  * This gives us a freedom in maintance of underlying connections.  */
end_comment

begin_struct
struct|struct
name|ncp_handle
block|{
name|SLIST_ENTRY
argument_list|(
argument|ncp_handle
argument_list|)
name|nh_next
expr_stmt|;
name|int
name|nh_id
decl_stmt|;
comment|/* handle id */
name|struct
name|ncp_conn
modifier|*
name|nh_conn
decl_stmt|;
comment|/* which conn we are refernce */
name|struct
name|proc
modifier|*
name|nh_proc
decl_stmt|;
comment|/* who owns the handle	*/
name|int
name|nh_ref
decl_stmt|;
comment|/* one process can asquire many handles, but we return the one */
block|}
struct|;
end_struct

begin_comment
comment|/*   * Describes any connection to server   */
end_comment

begin_struct
struct|struct
name|ncp_conn
block|{
name|SLIST_ENTRY
argument_list|(
argument|ncp_conn
argument_list|)
name|nc_next
expr_stmt|;
name|struct
name|ncp_conn_args
name|li
decl_stmt|;
name|struct
name|ucred
modifier|*
name|nc_owner
decl_stmt|;
name|gid_t
name|nc_group
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|int
name|nc_id
decl_stmt|;
name|struct
name|socket
modifier|*
name|ncp_so
decl_stmt|;
name|struct
name|socket
modifier|*
name|wdg_so
decl_stmt|;
name|struct
name|socket
modifier|*
name|msg_so
decl_stmt|;
name|struct
name|socket
modifier|*
name|bc_so
decl_stmt|;
name|int
name|ref_cnt
decl_stmt|;
comment|/* how many handles leased */
name|SLIST_HEAD
argument_list|(
argument|ncp_ref_hd
argument_list|,
argument|ncp_ref
argument_list|)
name|ref_list
expr_stmt|;
comment|/* list of handles */
name|struct
name|lock
name|nc_lock
decl_stmt|;
comment|/* excl locks */
name|int
name|nc_lwant
decl_stmt|;
comment|/* number of wanted locks */
name|struct
name|proc
modifier|*
name|procp
decl_stmt|;
comment|/* pid currently operates */
name|struct
name|ucred
modifier|*
name|ucred
decl_stmt|;
comment|/* usr currently operates */
name|struct
name|ncp_rq
modifier|*
name|nc_rq
decl_stmt|;
comment|/* current request */
comment|/* Fields used to process ncp requests */
name|int
name|connid
decl_stmt|;
comment|/* assigned by server */
name|u_int8_t
name|seq
decl_stmt|;
name|int
name|buffer_size
decl_stmt|;
comment|/* Negotiated bufsize */
comment|/* Fields used to make packet signatures */
name|u_int32_t
name|sign_root
index|[
literal|2
index|]
decl_stmt|;
name|u_int32_t
name|sign_state
index|[
literal|4
index|]
decl_stmt|;
comment|/* md4 state */
ifdef|#
directive|ifdef
name|NCPBURST
comment|/* Fields used for packet bursting */
name|u_long
name|bc_pktseq
decl_stmt|;
comment|/* raw packet sequence */
name|u_short
name|bc_seq
decl_stmt|;
comment|/* burst sequence */
name|u_long
name|bc_locid
decl_stmt|;
comment|/* local connection id */
name|u_long
name|bc_remid
decl_stmt|;
comment|/* remote connection id */
name|u_long
name|bc_pktsize
decl_stmt|;
comment|/* negotiated burst packet size */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ncp_conn_signwanted
parameter_list|(
name|conn
parameter_list|)
value|((conn)->flags& NCPFL_SIGNWANTED)
end_define

begin_define
define|#
directive|define
name|ncp_conn_valid
parameter_list|(
name|conn
parameter_list|)
value|((conn->flags& NCPFL_INVALID) == 0)
end_define

begin_define
define|#
directive|define
name|ncp_conn_invalidate
parameter_list|(
name|conn
parameter_list|)
value|{conn->flags |= NCPFL_INVALID;}
end_define

begin_function_decl
name|int
name|ncp_conn_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_conn_alloc
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|ncp_conn
modifier|*
modifier|*
name|connid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_conn_free
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_conn_access
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|mode_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_conn_lock
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncp_conn_unlock
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_conn_assert_locked
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|,
name|char
modifier|*
name|checker
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*int  ncp_conn_ref(struct ncp_conn *conn, pid_t pid); int  ncp_conn_rm_ref(struct ncp_conn *conn, pid_t pid, int force); void ncp_conn_list_rm_ref(pid_t pid);*/
end_comment

begin_function_decl
name|int
name|ncp_conn_getbyref
parameter_list|(
name|int
name|connRef
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|ncp_conn
modifier|*
modifier|*
name|connpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_conn_getbyli
parameter_list|(
name|struct
name|ncp_conn_loginfo
modifier|*
name|li
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|ncp_conn
modifier|*
modifier|*
name|connpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_conn_setprimary
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_conn_locklist
parameter_list|(
name|int
name|flags
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncp_conn_unlocklist
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_conn_gethandle
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|ncp_handle
modifier|*
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_conn_puthandle
parameter_list|(
name|struct
name|ncp_handle
modifier|*
name|handle
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_conn_findhandle
parameter_list|(
name|int
name|connHandle
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|ncp_handle
modifier|*
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_conn_getattached
parameter_list|(
name|struct
name|ncp_conn_args
modifier|*
name|li
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|ncp_conn
modifier|*
modifier|*
name|connpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_conn_putprochandles
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_conn_getinfo
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|ncp
parameter_list|,
name|struct
name|ncp_conn_stat
modifier|*
name|ncs
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|ncp_conn_head
name|conn_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ncp_burst_enabled
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NCPDATA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NCP_CONN_H_ */
end_comment

end_unit

