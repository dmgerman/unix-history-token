begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)misc-hpux.h	5.4 (Berkeley) %G%  *  * $Id: misc-hpux.h,v 5.2.2.1 1992/02/09 15:10:24 jsp beta $  *  */
end_comment

begin_comment
comment|/*  * These definitions are from<nfs/nfs.h>  * Unfortunately, that file cannot be included  * because it contains lots of structure definitions  * that are not wanted (they produce name clashes).  * Isn't HP-UX wonderful!  */
end_comment

begin_comment
comment|/*  * HP-UX specific definitions  */
end_comment

begin_struct
struct|struct
name|nfs_args
block|{
name|struct
name|sockaddr_in
modifier|*
name|addr
decl_stmt|;
comment|/* file server address */
name|fhandle_t
modifier|*
name|fh
decl_stmt|;
comment|/* File handle to be mounted */
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
name|timeo
decl_stmt|;
comment|/* initial timeout in .1 secs */
name|int
name|retrans
decl_stmt|;
comment|/* times to retry send */
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/* server's name */
ifdef|#
directive|ifdef
name|__hp9000s700
comment|/* XXX for HPUX 8.0 */
name|char
modifier|*
name|fsname
decl_stmt|;
comment|/* server's filesystem name */
endif|#
directive|endif
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
value|0x001
end_define

begin_comment
comment|/* soft mount (hard is default) */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WSIZE
value|0x002
end_define

begin_comment
comment|/* set write size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RSIZE
value|0x004
end_define

begin_comment
comment|/* set read size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_TIMEO
value|0x008
end_define

begin_comment
comment|/* set initial timeout */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RETRANS
value|0x010
end_define

begin_comment
comment|/* set number of request retrys */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_HOSTNAME
value|0x020
end_define

begin_comment
comment|/* set hostname for error printf */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_INT
value|0x040
end_define

begin_comment
comment|/* set option to have interruptable mounts */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NODEVS
value|0x080
end_define

begin_comment
comment|/* turn off device file access (default on) */
end_comment

end_unit

