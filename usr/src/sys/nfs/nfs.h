begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)nfs.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Tunable constants for nfs  */
end_comment

begin_define
define|#
directive|define
name|MAX_IOVEC
value|10
end_define

begin_define
define|#
directive|define
name|NFS_TIMEO
value|10
end_define

begin_comment
comment|/* Timeout in .1 sec intervals */
end_comment

begin_define
define|#
directive|define
name|NFS_MAXTIMEO
value|600
end_define

begin_comment
comment|/* Max timeout to backoff too in .1 sec */
end_comment

begin_define
define|#
directive|define
name|NFS_ATTRTIMEO
value|5
end_define

begin_comment
comment|/* Attribute cache timeout in sec */
end_comment

begin_define
define|#
directive|define
name|NFS_RETRANS
value|10
end_define

begin_comment
comment|/* Num of retrans for soft mounts */
end_comment

begin_define
define|#
directive|define
name|NFS_WSIZE
value|8192
end_define

begin_comment
comment|/* Max. write data size<= 8192 */
end_comment

begin_define
define|#
directive|define
name|NFS_RSIZE
value|8192
end_define

begin_comment
comment|/* Max. read data size<= 8192 */
end_comment

begin_define
define|#
directive|define
name|MAX_READDIR
value|NFS_RSIZE
end_define

begin_comment
comment|/* Max. size of directory read */
end_comment

begin_comment
comment|/*  * Nfs outstanding request list element  */
end_comment

begin_struct
struct|struct
name|nfsreq
block|{
name|struct
name|nfsreq
modifier|*
name|r_next
decl_stmt|;
name|struct
name|nfsreq
modifier|*
name|r_prev
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|r_mreq
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|r_mrep
decl_stmt|;
name|struct
name|nfsmount
modifier|*
name|r_mntp
decl_stmt|;
name|struct
name|vnode
modifier|*
name|r_vp
decl_stmt|;
name|int
name|r_msiz
decl_stmt|;
name|u_long
name|r_xid
decl_stmt|;
name|u_long
name|r_retry
decl_stmt|;
name|u_long
name|r_timeout
decl_stmt|;
name|u_long
name|r_timer
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Silly rename structure that hangs off the nfsnode until the name  * can be removed by nfs_inactive()  */
end_comment

begin_struct
struct|struct
name|sillyrename
block|{
name|int
name|s_flag
decl_stmt|;
name|nfsv2fh_t
name|s_fh
decl_stmt|;
name|struct
name|nameidata
name|s_namei
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* And its flag values */
end_comment

begin_define
define|#
directive|define
name|REMOVE
value|0
end_define

begin_define
define|#
directive|define
name|RMDIR
value|1
end_define

begin_comment
comment|/*  * Stats structure  */
end_comment

begin_struct
struct|struct
name|nfsstats
block|{
name|int
name|attrcache_hits
decl_stmt|;
name|int
name|attrcache_misses
decl_stmt|;
name|int
name|lookupcache_hits
decl_stmt|;
name|int
name|lookupcache_misses
decl_stmt|;
name|int
name|rpccnt
index|[
name|NFS_NPROCS
index|]
decl_stmt|;
name|int
name|rpcretries
decl_stmt|;
name|int
name|srvrpccnt
index|[
name|NFS_NPROCS
index|]
decl_stmt|;
name|int
name|srvrpc_errs
decl_stmt|;
name|int
name|srv_errs
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|nfsstats
name|nfsstats
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

