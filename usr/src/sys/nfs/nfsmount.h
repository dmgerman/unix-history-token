begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)nfsmount.h	7.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Mount structure.  * One allocated on every NFS mount.  * Holds NFS specific information for mount.  */
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
comment|/* Vfs structure for this filesystem */
name|nfsv2fh_t
name|nm_fh
decl_stmt|;
comment|/* File handle of root dir */
name|struct
name|socket
modifier|*
name|nm_so
decl_stmt|;
comment|/* Rpc socket */
name|struct
name|nfshost
modifier|*
name|nm_hostinfo
decl_stmt|;
comment|/* Host and congestion information */
name|short
name|nm_retry
decl_stmt|;
comment|/* Max retry count */
name|short
name|nm_rexmit
decl_stmt|;
comment|/* Rexmit on previous request */
name|short
name|nm_rtt
decl_stmt|;
comment|/* Round trip timer ticks @ NFS_HZ */
name|short
name|nm_rto
decl_stmt|;
comment|/* Current timeout */
name|short
name|nm_srtt
decl_stmt|;
comment|/* Smoothed round trip time */
name|short
name|nm_rttvar
decl_stmt|;
comment|/* RTT variance */
name|int
name|nm_rsize
decl_stmt|;
comment|/* Max size of read rpc */
name|int
name|nm_wsize
decl_stmt|;
comment|/* Max size of write rpc */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Hostinfo/congestion structure.  * One allocated per NFS server.  * Holds host address, congestion limits, request count, etc.  * Reference count is of nfsmounts which point to it.  */
end_comment

begin_struct
struct|struct
name|nfshost
block|{
name|struct
name|nfshost
modifier|*
name|nh_next
decl_stmt|,
modifier|*
name|nh_prev
decl_stmt|;
name|short
name|nh_refcnt
decl_stmt|;
comment|/* Reference count */
name|short
name|nh_currto
decl_stmt|;
comment|/* Current rto of any nfsmount */
name|short
name|nh_currexmit
decl_stmt|;
comment|/* Max rexmit count of nfsmounts */
name|short
name|nh_sent
decl_stmt|;
comment|/* Request send count */
name|short
name|nh_window
decl_stmt|;
comment|/* Request send window (max) */
name|short
name|nh_winext
decl_stmt|;
comment|/* Window incremental value */
name|short
name|nh_ssthresh
decl_stmt|;
comment|/* Slowstart threshold */
name|short
name|nh_salen
decl_stmt|;
comment|/* Actual length of nh_sockaddr */
name|struct
name|mbuf
modifier|*
name|nh_sockaddr
decl_stmt|;
comment|/* Address of server */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Convert mount ptr to nfsmount ptr.  */
end_comment

begin_define
define|#
directive|define
name|VFSTONFS
parameter_list|(
name|mp
parameter_list|)
value|((struct nfsmount *)((mp)->mnt_data))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

