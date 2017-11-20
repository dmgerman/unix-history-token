begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)unpcb.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_UNPCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_UNPCB_H_
end_define

begin_typedef
typedef|typedef
name|uint64_t
name|unp_gen_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_WANT_UNPCB
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_comment
comment|/*  * Protocol control block for an active  * instance of a UNIX internal protocol.  *  * A socket may be associated with a vnode in the  * filesystem.  If so, the unp_vnode pointer holds  * a reference count to this vnode, which should be irele'd  * when the socket goes away.  *  * A socket may be connected to another socket, in which  * case the control block of the socket to which it is connected  * is given by unp_conn.  *  * A socket may be referenced by a number of sockets (e.g. several  * sockets may be connected to a datagram socket.)  These sockets  * are in a linked list starting with unp_refs, linked through  * unp_nextref and null-terminated.  Note that a socket may be referenced  * by a number of other sockets and may also reference a socket (not  * necessarily one which is referencing it).  This generates  * the need for unp_refs and unp_nextref to be separate fields.  *  * Stream sockets keep copies of receive sockbuf sb_cc and sb_mbcnt  * so that changes in the sockbuf may be computed to modify  * back pressure on the sender accordingly.  */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|unp_head
argument_list|,
name|unpcb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|unpcb
block|{
name|LIST_ENTRY
argument_list|(
argument|unpcb
argument_list|)
name|unp_link
expr_stmt|;
comment|/* glue on list of all PCBs */
name|struct
name|socket
modifier|*
name|unp_socket
decl_stmt|;
comment|/* pointer back to socket */
name|struct
name|file
modifier|*
name|unp_file
decl_stmt|;
comment|/* back-pointer to file for gc. */
name|struct
name|vnode
modifier|*
name|unp_vnode
decl_stmt|;
comment|/* if associated with file */
name|ino_t
name|unp_ino
decl_stmt|;
comment|/* fake inode number */
name|struct
name|unpcb
modifier|*
name|unp_conn
decl_stmt|;
comment|/* control block of connected socket */
name|struct
name|unp_head
name|unp_refs
decl_stmt|;
comment|/* referencing socket linked list */
name|LIST_ENTRY
argument_list|(
argument|unpcb
argument_list|)
name|unp_reflink
expr_stmt|;
comment|/* link in unp_refs list */
name|struct
name|sockaddr_un
modifier|*
name|unp_addr
decl_stmt|;
comment|/* bound address of socket */
name|unp_gen_t
name|unp_gencnt
decl_stmt|;
comment|/* generation count of this instance */
name|short
name|unp_flags
decl_stmt|;
comment|/* flags */
name|short
name|unp_gcflag
decl_stmt|;
comment|/* Garbage collector flags. */
name|struct
name|xucred
name|unp_peercred
decl_stmt|;
comment|/* peer credentials, if applicable */
name|u_int
name|unp_refcount
decl_stmt|;
name|u_int
name|unp_msgcount
decl_stmt|;
comment|/* references from message queue */
name|struct
name|mtx
name|unp_mtx
decl_stmt|;
comment|/* mutex */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags in unp_flags.  *  * UNP_HAVEPC - indicates that the unp_peercred member is filled in  * and is really the credentials of the connected peer.  This is used  * to determine whether the contents should be sent to the user or  * not.  */
end_comment

begin_define
define|#
directive|define
name|UNP_HAVEPC
value|0x001
end_define

begin_define
define|#
directive|define
name|UNP_WANTCRED
value|0x004
end_define

begin_comment
comment|/* credentials wanted */
end_comment

begin_define
define|#
directive|define
name|UNP_CONNWAIT
value|0x008
end_define

begin_comment
comment|/* connect blocks until accepted */
end_comment

begin_comment
comment|/*  * These flags are used to handle non-atomicity in connect() and bind()  * operations on a socket: in particular, to avoid races between multiple  * threads or processes operating simultaneously on the same socket.  */
end_comment

begin_define
define|#
directive|define
name|UNP_CONNECTING
value|0x010
end_define

begin_comment
comment|/* Currently connecting. */
end_comment

begin_define
define|#
directive|define
name|UNP_BINDING
value|0x020
end_define

begin_comment
comment|/* Currently binding. */
end_comment

begin_define
define|#
directive|define
name|UNP_NASCENT
value|0x040
end_define

begin_comment
comment|/* Newborn child socket. */
end_comment

begin_comment
comment|/*  * Flags in unp_gcflag.  */
end_comment

begin_define
define|#
directive|define
name|UNPGC_REF
value|0x1
end_define

begin_comment
comment|/* unpcb has external ref. */
end_comment

begin_define
define|#
directive|define
name|UNPGC_DEAD
value|0x2
end_define

begin_comment
comment|/* unpcb might be dead. */
end_comment

begin_define
define|#
directive|define
name|UNPGC_SCANNED
value|0x4
end_define

begin_comment
comment|/* Has been scanned. */
end_comment

begin_define
define|#
directive|define
name|UNPGC_IGNORE_RIGHTS
value|0x8
end_define

begin_comment
comment|/* Attached rights are freed */
end_comment

begin_define
define|#
directive|define
name|sotounpcb
parameter_list|(
name|so
parameter_list|)
value|((struct unpcb *)((so)->so_pcb))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL || _WANT_UNPCB */
end_comment

begin_comment
comment|/*  * UNPCB structure exported to user-land via sysctl(3).  *  * Fields prefixed with "xu_" are unique to the export structure, and fields  * with "unp_" or other prefixes match corresponding fields of 'struct unpcb'.  *  * Legend:  * (s) - used by userland utilities in src  * (p) - used by utilities in ports  * (3) - is known to be used by third party software not in ports  * (n) - no known usage  *  * Evil hack: declare only if sys/socketvar.h have been included.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_SOCKETVAR_H_
end_ifdef

begin_struct
struct|struct
name|xunpcb
block|{
name|size_t
name|xu_len
decl_stmt|;
comment|/* length of this structure */
name|void
modifier|*
name|xu_unpp
decl_stmt|;
comment|/* to help netstat, fstat */
name|void
modifier|*
name|unp_vnode
decl_stmt|;
comment|/* (s) */
name|void
modifier|*
name|unp_conn
decl_stmt|;
comment|/* (s) */
name|void
modifier|*
name|xu_firstref
decl_stmt|;
comment|/* (s) */
name|void
modifier|*
name|xu_nextref
decl_stmt|;
comment|/* (s) */
name|unp_gen_t
name|unp_gencnt
decl_stmt|;
comment|/* (s) */
name|int64_t
name|xu_spare64
index|[
literal|8
index|]
decl_stmt|;
name|int32_t
name|xu_spare32
index|[
literal|8
index|]
decl_stmt|;
union|union
block|{
name|struct
name|sockaddr_un
name|xu_addr
decl_stmt|;
comment|/* our bound address */
name|char
name|xu_dummy1
index|[
literal|256
index|]
decl_stmt|;
block|}
union|;
union|union
block|{
name|struct
name|sockaddr_un
name|xu_caddr
decl_stmt|;
comment|/* their bound address */
name|char
name|xu_dummy2
index|[
literal|256
index|]
decl_stmt|;
block|}
union|;
name|struct
name|xsocket
name|xu_socket
decl_stmt|;
block|}
name|__aligned
argument_list|(
literal|8
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|xunpgen
block|{
name|size_t
name|xug_len
decl_stmt|;
name|u_int
name|xug_count
decl_stmt|;
name|unp_gen_t
name|xug_gen
decl_stmt|;
name|so_gen_t
name|xug_sogen
decl_stmt|;
block|}
name|__aligned
argument_list|(
literal|8
argument_list|)
struct|;
end_struct

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SOCKETVAR_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_UNPCB_H_ */
end_comment

end_unit

