begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsdiskless.h	8.2 (Berkeley) 3/30/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFSCLIENT_NFSDISKLESS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFSCLIENT_NFSDISKLESS_H_
end_define

begin_comment
comment|/*  * Structure that must be initialized for a diskless nfs client.  * This structure is used by nfs_mountroot() to set up the root vnode,  * and to do a partial ifconfig(8) and route(8) so that the critical net  * interface can communicate with the server.  * The primary bootstrap is expected to fill in the appropriate fields before  * starting the kernel.  * Currently only works for AF_INET protocols.  * NB: All fields are stored in net byte order to avoid hassles with  * client/server byte ordering differences.  */
end_comment

begin_comment
comment|/*  * I have defined a new structure that can handle an NFS Version 3 file handle  * but the kernel still expects the old Version 2 one to be provided. The  * changes required in nfs_vfsops.c for using the new are documented there in  * comments. (I felt that breaking network booting code by changing this  * structure would not be prudent at this time, since almost all servers are  * still Version 2 anyhow.)  */
end_comment

begin_struct
struct|struct
name|nfsv3_diskless
block|{
name|struct
name|ifaliasreq
name|myif
decl_stmt|;
comment|/* Default interface */
name|struct
name|sockaddr_in
name|mygateway
decl_stmt|;
comment|/* Default gateway */
name|struct
name|nfs_args
name|root_args
decl_stmt|;
comment|/* Mount args for root fs */
name|int
name|root_fhsize
decl_stmt|;
comment|/* Size of root file handle */
name|u_char
name|root_fh
index|[
name|NFSX_V3FHMAX
index|]
decl_stmt|;
comment|/* File handle of root dir */
name|struct
name|sockaddr_in
name|root_saddr
decl_stmt|;
comment|/* Address of root server */
name|char
name|root_hostnam
index|[
name|MNAMELEN
index|]
decl_stmt|;
comment|/* Host name for mount pt */
name|long
name|root_time
decl_stmt|;
comment|/* Timestamp of root fs */
name|char
name|my_hostnam
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
comment|/* Client host name */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Old arguments to mount NFS  */
end_comment

begin_struct
struct|struct
name|onfs_args
block|{
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
name|leaseterm
decl_stmt|;
comment|/* Term (sec) of lease */
name|int
name|deadthresh
decl_stmt|;
comment|/* Retrans threshold */
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/* server's name */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfs_diskless
block|{
name|struct
name|ifaliasreq
name|myif
decl_stmt|;
comment|/* Default interface */
name|struct
name|sockaddr_in
name|mygateway
decl_stmt|;
comment|/* Default gateway */
name|struct
name|onfs_args
name|root_args
decl_stmt|;
comment|/* Mount args for root fs */
name|u_char
name|root_fh
index|[
name|NFSX_V2FH
index|]
decl_stmt|;
comment|/* File handle of root dir */
name|struct
name|sockaddr_in
name|root_saddr
decl_stmt|;
comment|/* Address of root server */
name|char
name|root_hostnam
index|[
name|MNAMELEN
index|]
decl_stmt|;
comment|/* Host name for mount pt */
name|long
name|root_time
decl_stmt|;
comment|/* Timestamp of root fs */
name|char
name|my_hostnam
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
comment|/* Client host name */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|nfsv3_diskless
name|nfsv3_diskless
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|nfs_diskless
name|nfs_diskless
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfs_diskless_valid
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|bootpc_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs_setup_diskless
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs_parse_options
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|nfs_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

