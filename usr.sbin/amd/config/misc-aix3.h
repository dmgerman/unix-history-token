begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)misc-aix3.h	8.1 (Berkeley) 6/6/93  *  * $FreeBSD$  *  */
end_comment

begin_struct
struct|struct
name|ufs_args
block|{
name|char
modifier|*
name|fspec
decl_stmt|;
comment|/* Block device */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfs_args
block|{
name|struct
name|sockaddr_in
name|addr
decl_stmt|;
comment|/* file server address */
name|fhandle_t
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
comment|/* server's hostname */
name|int
name|acregmin
decl_stmt|;
comment|/* attr cache file min secs */
name|int
name|acregmax
decl_stmt|;
comment|/* attr cache file max secs */
name|int
name|acdirmin
decl_stmt|;
comment|/* attr cache dir min secs */
name|int
name|acdirmax
decl_stmt|;
comment|/* attr cache dir max secs */
name|char
modifier|*
name|netname
decl_stmt|;
comment|/* server's netname */
name|int
name|biods
decl_stmt|;
comment|/* number of BIODS */
block|}
struct|;
end_struct

begin_comment
comment|/*  * NFS mount option flags  */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_RO
value|"ro"
end_define

begin_comment
comment|/* read only */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_RW
value|"rw"
end_define

begin_comment
comment|/* read/write */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_SOFT
value|"soft"
end_define

begin_comment
comment|/* soft mount */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_HARD
value|"hard"
end_define

begin_comment
comment|/* hard mount */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NOSUID
value|"nosuid"
end_define

begin_comment
comment|/* no set uid allowed */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NOAUTO
value|"noauto"
end_define

begin_comment
comment|/* hide entry from mount -a */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_INTR
value|"intr"
end_define

begin_comment
comment|/* allow interrupts on hard mount */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_SECURE
value|"secure"
end_define

begin_comment
comment|/* use secure RPC for NFS */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_GRPID
value|"grpid"
end_define

begin_comment
comment|/* SysV-compatible group-id on create */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NOSUB
value|"nosub"
end_define

begin_comment
comment|/* disallow mounts beneath this one */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_MULTI
value|"multi"
end_define

begin_comment
comment|/* Do multi-component lookup */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NOAC
value|"noac"
end_define

begin_comment
comment|/* don't cache attributes */
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
comment|/* allow interrupts on hard mount */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NOAC
value|0x080
end_define

begin_comment
comment|/* don't cache attributes */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_ACREGMIN
value|0x0100
end_define

begin_comment
comment|/* set min secs for file attr cache */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_ACREGMAX
value|0x0200
end_define

begin_comment
comment|/* set max secs for file attr cache */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_ACDIRMIN
value|0x0400
end_define

begin_comment
comment|/* set min secs for dir attr cache */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_ACDIRMAX
value|0x0800
end_define

begin_comment
comment|/* set max secs for dir attr cache */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_SECURE
value|0x1000
end_define

begin_comment
comment|/* secure mount */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_BIODS
value|0x10000
end_define

begin_comment
comment|/* Number of biods for the file system */
end_comment

begin_define
define|#
directive|define
name|DEF_BIODS
value|6
end_define

end_unit

