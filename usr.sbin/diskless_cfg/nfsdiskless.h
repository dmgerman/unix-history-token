begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsdiskless.h	7.1 (Berkeley) 3/4/91  */
end_comment

begin_comment
comment|/*  * Structure that must be initialized for a diskless nfs client.  * This structure is used by nfs_mountroot() to set up the root and swap  * vnodes plus do a partial ifconfig(8) and route(8) so that the critical net  * interface can communicate with the server.  * For now it is statically initialized in swapvmunix.c, but someday a primary  * bootstrap should fill it in.  */
end_comment

begin_define
define|#
directive|define
name|NFSMNAMELEN
value|64
end_define

begin_struct
struct|struct
name|nfs_diskless
block|{
name|struct
name|ifaliasreq
name|myif
decl_stmt|;
comment|/* Info. for partial ifconfig */
name|struct
name|sockaddr
name|mygateway
decl_stmt|;
comment|/* Default gateway for "route add" */
name|struct
name|nfs_args
name|swap_args
decl_stmt|;
comment|/* Mount args for swap file */
name|u_char
name|swap_fh
index|[
name|NFS_FHSIZE
index|]
decl_stmt|;
comment|/* Swap file's file handle */
name|struct
name|sockaddr
name|swap_saddr
decl_stmt|;
comment|/* Address of swap server */
name|char
name|swap_hostnam
index|[
name|NFSMNAMELEN
index|]
decl_stmt|;
comment|/* Host name for mount pt */
name|struct
name|nfs_args
name|root_args
decl_stmt|;
comment|/* Mount args for root fs */
name|u_char
name|root_fh
index|[
name|NFS_FHSIZE
index|]
decl_stmt|;
comment|/* File handle of root dir */
name|struct
name|sockaddr
name|root_saddr
decl_stmt|;
comment|/* Address of root server */
name|char
name|root_hostnam
index|[
name|NFSMNAMELEN
index|]
decl_stmt|;
comment|/* Host name for mount pt */
block|}
struct|;
end_struct

end_unit

