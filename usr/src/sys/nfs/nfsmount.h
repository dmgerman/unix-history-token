begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)nfsmount.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Mount structure.  * One allocated on every nfs mount.  * Holds nfs specific info for mount (sockets...)  */
end_comment

begin_struct
struct|struct
name|nfsmount
block|{
name|int
name|nm_flag
decl_stmt|;
comment|/* Flags for soft/hard... */
name|struct
name|mount
modifier|*
name|nm_mountp
decl_stmt|;
comment|/* vfs structure for this filesystem */
name|nfsv2fh_t
name|nm_fh
decl_stmt|;
comment|/* File handle of root dir */
name|struct
name|mbuf
modifier|*
name|nm_sockaddr
decl_stmt|;
comment|/* Address of server */
name|struct
name|socket
modifier|*
name|nm_so
decl_stmt|;
comment|/* rpc socket */
name|int
name|nm_timeo
decl_stmt|;
comment|/* Timeout interval */
name|int
name|nm_retrans
decl_stmt|;
comment|/* # of retransmits */
name|int
name|nm_rsize
decl_stmt|;
comment|/* Max size of read rpc */
name|int
name|nm_wsize
decl_stmt|;
comment|/* Max size of write rpc */
name|char
name|nm_path
index|[
name|MNAMELEN
index|]
decl_stmt|;
comment|/* Path mounted on */
name|char
name|nm_host
index|[
name|MNAMELEN
index|]
decl_stmt|;
comment|/* Remote host name */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|nfsmount
modifier|*
name|vfs_to_nfs
parameter_list|()
function_decl|;
end_function_decl

end_unit

