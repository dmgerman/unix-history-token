begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993, 1995  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfs.h	8.4 (Berkeley) 5/1/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFSCLIENT_NFSARGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFSCLIENT_NFSARGS_H_
end_define

begin_comment
comment|/*  * Arguments to mount NFS  */
end_comment

begin_define
define|#
directive|define
name|NFS_ARGSVERSION
value|3
end_define

begin_comment
comment|/* change when nfs_args changes */
end_comment

begin_struct
struct|struct
name|nfs_args
block|{
name|int
name|version
decl_stmt|;
comment|/* args structure version number */
name|struct
name|sockaddr
modifier|*
name|addr
decl_stmt|;
comment|/* file server address */
name|int
name|addrlen
decl_stmt|;
comment|/* length of address */
name|int
name|sotype
decl_stmt|;
comment|/* Socket type */
name|int
name|proto
decl_stmt|;
comment|/* and Protocol */
name|u_char
modifier|*
name|fh
decl_stmt|;
comment|/* File handle to be mounted */
name|int
name|fhsize
decl_stmt|;
comment|/* Size, in bytes, of fh */
name|int
name|flags
decl_stmt|;
comment|/* flags */
name|int
name|wsize
decl_stmt|;
comment|/* write size in bytes */
name|int
name|rsize
decl_stmt|;
comment|/* read size in bytes */
name|int
name|readdirsize
decl_stmt|;
comment|/* readdir size in bytes */
name|int
name|timeo
decl_stmt|;
comment|/* initial timeout in .1 secs */
name|int
name|retrans
decl_stmt|;
comment|/* times to retry send */
name|int
name|maxgrouplist
decl_stmt|;
comment|/* Max. size of group list */
name|int
name|readahead
decl_stmt|;
comment|/* # of blocks to readahead */
name|int
name|wcommitsize
decl_stmt|;
comment|/* Max. write commit size in bytes */
name|int
name|deadthresh
decl_stmt|;
comment|/* Retrans threshold */
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/* server's name */
name|int
name|acregmin
decl_stmt|;
comment|/* cache attrs for reg files min time */
name|int
name|acregmax
decl_stmt|;
comment|/* cache attrs for reg files max time */
name|int
name|acdirmin
decl_stmt|;
comment|/* cache attrs for dirs min time */
name|int
name|acdirmax
decl_stmt|;
comment|/* cache attrs for dirs max time */
block|}
struct|;
end_struct

begin_comment
comment|/*  * NFS mount option flags  */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_SOFT
value|0x00000001
end_define

begin_comment
comment|/* soft mount (hard is default) */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WSIZE
value|0x00000002
end_define

begin_comment
comment|/* set write size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RSIZE
value|0x00000004
end_define

begin_comment
comment|/* set read size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_TIMEO
value|0x00000008
end_define

begin_comment
comment|/* set initial timeout */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RETRANS
value|0x00000010
end_define

begin_comment
comment|/* set number of request retries */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_MAXGRPS
value|0x00000020
end_define

begin_comment
comment|/* set maximum grouplist size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_INT
value|0x00000040
end_define

begin_comment
comment|/* allow interrupts on hard mount */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NOCONN
value|0x00000080
end_define

begin_comment
comment|/* Don't Connect the socket */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_ONEOPENOWN
value|0x00000100
end_define

begin_comment
comment|/* Use one OpenOwner for NFSv4.1 */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NFSV3
value|0x00000200
end_define

begin_comment
comment|/* Use NFS Version 3 protocol */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_KERB
value|0x00000400
end_define

begin_comment
comment|/* Use RPCSEC_GSS/Krb5 */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_DUMBTIMR
value|0x00000800
end_define

begin_comment
comment|/* Don't estimate rtt dynamically */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WCOMMITSIZE
value|0x00001000
end_define

begin_comment
comment|/* set max write commit size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_READAHEAD
value|0x00002000
end_define

begin_comment
comment|/* set read ahead */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_DEADTHRESH
value|0x00004000
end_define

begin_comment
comment|/* set dead server retry thresh */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RESVPORT
value|0x00008000
end_define

begin_comment
comment|/* Allocate a reserved port */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RDIRPLUS
value|0x00010000
end_define

begin_comment
comment|/* Use Readdirplus for V3 */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_READDIRSIZE
value|0x00020000
end_define

begin_comment
comment|/* Set readdir size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_ACREGMIN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|NFSMNT_ACREGMAX
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NFSMNT_ACDIRMIN
value|0x00100000
end_define

begin_define
define|#
directive|define
name|NFSMNT_ACDIRMAX
value|0x00200000
end_define

begin_define
define|#
directive|define
name|NFSMNT_NOLOCKD
value|0x00400000
end_define

begin_comment
comment|/* Locks are local */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NFSV4
value|0x00800000
end_define

begin_comment
comment|/* Use NFS Version 4 protocol */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_HASWRITEVERF
value|0x01000000
end_define

begin_comment
comment|/* NFSv4 Write verifier */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_INTEGRITY
value|0x02000000
end_define

begin_comment
comment|/* Use integrity with RPCSEC_GSS */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_PRIVACY
value|0x04000000
end_define

begin_comment
comment|/* Use privacy with RPCSEC_GSS */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_ALLGSSNAME
value|0x08000000
end_define

begin_comment
comment|/* Use principal for all accesses */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_STRICT3530
value|0x10000000
end_define

begin_comment
comment|/* Adhere strictly to RFC3530 */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NOCTO
value|0x20000000
end_define

begin_comment
comment|/* Don't flush attrcache on open */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_PNFS
value|0x40000000
end_define

begin_comment
comment|/* Enable pNFS support */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NONCONTIGWR
value|0x80000000
end_define

begin_comment
comment|/* Enable non-contiguous writes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

