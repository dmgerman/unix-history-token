begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * %sccs.include.redist.c%  *  *	@(#)nfsdiskless.h	8.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFSDISKLESS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NFSDISKLESS_H_
end_define

begin_comment
comment|/*  * Structure that must be initialized for a diskless nfs client.  * This structure is used by nfs_mountroot() to set up the root and swap  * vnodes plus do a partial ifconfig(8) and route(8) so that the critical net  * interface can communicate with the server.  * The primary bootstrap is expected to fill in the appropriate fields before  * starting the kernel. Whether or not the swap area is nfs mounted is  * determined by the value in swdevt[0]. (equal to NODEV --> swap over nfs)  * Currently only works for AF_INET protocols.  * NB: All fields are stored in net byte order to avoid hassles with  * client/server byte ordering differences.  */
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
name|swap_args
decl_stmt|;
comment|/* Mount args for swap file */
name|int
name|swap_fhsize
decl_stmt|;
comment|/* Size of file handle */
name|u_char
name|swap_fh
index|[
name|NFSX_V3FHMAX
index|]
decl_stmt|;
comment|/* Swap file's file handle */
name|struct
name|sockaddr_in
name|swap_saddr
decl_stmt|;
comment|/* Address of swap server */
name|char
name|swap_hostnam
index|[
name|MNAMELEN
index|]
decl_stmt|;
comment|/* Host name for mount pt */
name|int
name|swap_nblks
decl_stmt|;
comment|/* Size of server swap file */
name|struct
name|ucred
name|swap_ucred
decl_stmt|;
comment|/* Swap credentials */
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
name|nfs_args
name|swap_args
decl_stmt|;
comment|/* Mount args for swap file */
name|u_char
name|swap_fh
index|[
name|NFSX_V2FH
index|]
decl_stmt|;
comment|/* Swap file's file handle */
name|struct
name|sockaddr_in
name|swap_saddr
decl_stmt|;
comment|/* Address of swap server */
name|char
name|swap_hostnam
index|[
name|MNAMELEN
index|]
decl_stmt|;
comment|/* Host name for mount pt */
name|int
name|swap_nblks
decl_stmt|;
comment|/* Size of server swap file */
name|struct
name|ucred
name|swap_ucred
decl_stmt|;
comment|/* Swap credentials */
name|struct
name|nfs_args
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

