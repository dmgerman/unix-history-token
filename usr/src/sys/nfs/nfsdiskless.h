begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * %sccs.include.redist.c%  *  *	@(#)nfsdiskless.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Structure that must be initialized for a diskless nfs client.  * This structure is used by nfs_mountroot() to set up the root and swap  * vnodes plus do a partial ifconfig(8) and route(8) so that the critical net  * interface can communicate with the server.  * For now it is statically initialized in swapvmunix.c, but someday a primary  * bootstrap should fill it in.  */
end_comment

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
modifier|*
name|swap_hostnam
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
modifier|*
name|root_hostnam
decl_stmt|;
comment|/* Host name for mount pt */
block|}
struct|;
end_struct

end_unit

