begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: fstype.h,v 5.2 90/06/23 22:20:30 jsp Rel $  *  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)fstype.h	5.1 (Berkeley) 7/19/90  */
end_comment

begin_comment
comment|/*  * File system types  */
end_comment

begin_comment
comment|/*  * Automount File System  */
end_comment

begin_define
define|#
directive|define
name|HAS_AFS
end_define

begin_decl_stmt
specifier|extern
name|am_ops
name|afs_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Automount file system (this!) */
end_comment

begin_decl_stmt
specifier|extern
name|qelem
name|afs_srvr_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fserver
modifier|*
name|find_afs_srvr
name|P
argument_list|(
operator|(
name|mntfs
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Direct Automount File System  */
end_comment

begin_define
define|#
directive|define
name|HAS_DFS
end_define

begin_decl_stmt
specifier|extern
name|am_ops
name|dfs_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Direct Automount file system (this too) */
end_comment

begin_comment
comment|/*  * Error File System  */
end_comment

begin_define
define|#
directive|define
name|HAS_EFS
end_define

begin_decl_stmt
specifier|extern
name|am_ops
name|efs_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Error file system */
end_comment

begin_comment
comment|/*  * Inheritance File System  */
end_comment

begin_define
define|#
directive|define
name|HAS_IFS
end_define

begin_decl_stmt
specifier|extern
name|am_ops
name|ifs_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Inheritance file system */
end_comment

begin_comment
comment|/*  * Loopback File System  * LOFS is optional - you can compile without it.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OS_HAS_LOFS
end_ifdef

begin_comment
comment|/*  * Most systems can't support this, and in  * any case most of the functionality is  * available with Symlink FS.  In fact,  * lofs_ops is not yet available.  */
end_comment

begin_define
define|#
directive|define
name|HAS_LOFS
end_define

begin_decl_stmt
specifier|extern
name|am_ops
name|lofs_ops
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Netw*rk File System  * Good, slow, NFS.  * NFS host - a whole tree  */
end_comment

begin_define
define|#
directive|define
name|HAS_NFS
end_define

begin_define
define|#
directive|define
name|HAS_HOST
end_define

begin_decl_stmt
specifier|extern
name|am_ops
name|nfs_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NFS */
end_comment

begin_decl_stmt
specifier|extern
name|am_ops
name|host_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NFS host */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HOST_EXEC
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|host_helper
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "/usr/local/etc/amd-host" */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|qelem
name|nfs_srvr_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fserver
modifier|*
name|find_nfs_srvr
name|P
argument_list|(
operator|(
name|mntfs
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Program File System  * PFS is optional - you can compile without it.  * This is useful for things like RVD.  */
end_comment

begin_define
define|#
directive|define
name|HAS_PFS
end_define

begin_decl_stmt
specifier|extern
name|am_ops
name|pfs_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PFS */
end_comment

begin_comment
comment|/*  * Translucent File System  * TFS is optional - you can compile without it.  * This is just plain cute.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|tfs_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TFS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|HAS_TFS
end_undef

begin_comment
comment|/*  * Un*x File System  * Normal local disk file system.  */
end_comment

begin_define
define|#
directive|define
name|HAS_UFS
end_define

begin_decl_stmt
specifier|extern
name|am_ops
name|ufs_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Un*x file system */
end_comment

begin_comment
comment|/*  * Symbolic-link file system  * A "filesystem" which is just a symbol link.  */
end_comment

begin_define
define|#
directive|define
name|HAS_SFS
end_define

begin_decl_stmt
specifier|extern
name|am_ops
name|sfs_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Symlink FS */
end_comment

end_unit

