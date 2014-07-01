begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Rick Macklem, University of Guelph  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * These macros handle nfsvattr fields. They look a bit silly here, but  * are quite different for the Darwin port.  */
end_comment

begin_define
define|#
directive|define
name|NFSVNO_ATTRINIT
parameter_list|(
name|n
parameter_list|)
value|(VATTR_NULL(&((n)->na_vattr)))
end_define

begin_define
define|#
directive|define
name|NFSVNO_SETATTRVAL
parameter_list|(
name|n
parameter_list|,
name|f
parameter_list|,
name|v
parameter_list|)
value|((n)->na_##f = (v))
end_define

begin_define
define|#
directive|define
name|NFSVNO_SETACTIVE
parameter_list|(
name|n
parameter_list|,
name|f
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NFSVNO_UNSET
parameter_list|(
name|n
parameter_list|,
name|f
parameter_list|)
value|((n)->na_##f = VNOVAL)
end_define

begin_define
define|#
directive|define
name|NFSVNO_NOTSETMODE
parameter_list|(
name|n
parameter_list|)
value|((n)->na_mode == ((mode_t)VNOVAL))
end_define

begin_define
define|#
directive|define
name|NFSVNO_ISSETMODE
parameter_list|(
name|n
parameter_list|)
value|((n)->na_mode != ((mode_t)VNOVAL))
end_define

begin_define
define|#
directive|define
name|NFSVNO_NOTSETUID
parameter_list|(
name|n
parameter_list|)
value|((n)->na_uid == ((uid_t)VNOVAL))
end_define

begin_define
define|#
directive|define
name|NFSVNO_ISSETUID
parameter_list|(
name|n
parameter_list|)
value|((n)->na_uid != ((uid_t)VNOVAL))
end_define

begin_define
define|#
directive|define
name|NFSVNO_NOTSETGID
parameter_list|(
name|n
parameter_list|)
value|((n)->na_gid == ((gid_t)VNOVAL))
end_define

begin_define
define|#
directive|define
name|NFSVNO_ISSETGID
parameter_list|(
name|n
parameter_list|)
value|((n)->na_gid != ((gid_t)VNOVAL))
end_define

begin_define
define|#
directive|define
name|NFSVNO_NOTSETSIZE
parameter_list|(
name|n
parameter_list|)
value|((n)->na_size == VNOVAL)
end_define

begin_define
define|#
directive|define
name|NFSVNO_ISSETSIZE
parameter_list|(
name|n
parameter_list|)
value|((n)->na_size != VNOVAL)
end_define

begin_define
define|#
directive|define
name|NFSVNO_NOTSETATIME
parameter_list|(
name|n
parameter_list|)
value|((n)->na_atime.tv_sec == VNOVAL)
end_define

begin_define
define|#
directive|define
name|NFSVNO_ISSETATIME
parameter_list|(
name|n
parameter_list|)
value|((n)->na_atime.tv_sec != VNOVAL)
end_define

begin_define
define|#
directive|define
name|NFSVNO_NOTSETMTIME
parameter_list|(
name|n
parameter_list|)
value|((n)->na_mtime.tv_sec == VNOVAL)
end_define

begin_define
define|#
directive|define
name|NFSVNO_ISSETMTIME
parameter_list|(
name|n
parameter_list|)
value|((n)->na_mtime.tv_sec != VNOVAL)
end_define

begin_comment
comment|/*  * This structure acts as a "catch-all" for information that  * needs to be returned by nfsd_fhtovp().  */
end_comment

begin_struct
struct|struct
name|nfsexstuff
block|{
name|int
name|nes_exflag
decl_stmt|;
comment|/* export flags */
name|int
name|nes_numsecflavor
decl_stmt|;
comment|/* # of security flavors */
name|int
name|nes_secflavors
index|[
name|MAXSECFLAVORS
index|]
decl_stmt|;
comment|/* and the flavors */
block|}
struct|;
end_struct

begin_comment
comment|/*  * These are NO-OPS for BSD until Isilon upstreams EXITCODE support.  * EXITCODE is an in-memory ring buffer that holds the routines failing status.  * This is a valuable tool to use when debugging and analyzing issues.  * In addition to recording a routine's failing status, it offers  * logging of routines for call stack tracing.  * EXITCODE should be used only in routines that return a true errno value, as  * that value will be formatted to a displayable errno string.  Routines that   * return regular int status that are not true errno should not set EXITCODE.  * If you want to log routine tracing, you can add EXITCODE(0) to any routine.  * NFS extended the EXITCODE with EXITCODE2 to record either the routine's  * exit errno status or the nd_repstat.  */
end_comment

begin_define
define|#
directive|define
name|NFSEXITCODE
parameter_list|(
name|error
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NFSEXITCODE2
parameter_list|(
name|error
parameter_list|,
name|nd
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NFSVNO_EXINIT
parameter_list|(
name|e
parameter_list|)
value|((e)->nes_exflag = 0)
end_define

begin_define
define|#
directive|define
name|NFSVNO_EXPORTED
parameter_list|(
name|e
parameter_list|)
value|((e)->nes_exflag& MNT_EXPORTED)
end_define

begin_define
define|#
directive|define
name|NFSVNO_EXRDONLY
parameter_list|(
name|e
parameter_list|)
value|((e)->nes_exflag& MNT_EXRDONLY)
end_define

begin_define
define|#
directive|define
name|NFSVNO_EXPORTANON
parameter_list|(
name|e
parameter_list|)
value|((e)->nes_exflag& MNT_EXPORTANON)
end_define

begin_define
define|#
directive|define
name|NFSVNO_EXSTRICTACCESS
parameter_list|(
name|e
parameter_list|)
value|((e)->nes_exflag& MNT_EXSTRICTACCESS)
end_define

begin_define
define|#
directive|define
name|NFSVNO_EXV4ONLY
parameter_list|(
name|e
parameter_list|)
value|((e)->nes_exflag& MNT_EXV4ONLY)
end_define

begin_define
define|#
directive|define
name|NFSVNO_SETEXRDONLY
parameter_list|(
name|e
parameter_list|)
value|((e)->nes_exflag = (MNT_EXPORTED|MNT_EXRDONLY))
end_define

begin_define
define|#
directive|define
name|NFSVNO_CMPFH
parameter_list|(
name|f1
parameter_list|,
name|f2
parameter_list|)
define|\
value|((f1)->fh_fsid.val[0] == (f2)->fh_fsid.val[0]&&			\      (f1)->fh_fsid.val[1] == (f2)->fh_fsid.val[1]&&			\      bcmp(&(f1)->fh_fid,&(f2)->fh_fid, sizeof(struct fid)) == 0)
end_define

begin_define
define|#
directive|define
name|NFSLOCKHASH
parameter_list|(
name|f
parameter_list|)
define|\
value|(&nfslockhash[nfsrv_hashfh(f) % NFSLOCKHASHSIZE])
end_define

begin_define
define|#
directive|define
name|NFSFPVNODE
parameter_list|(
name|f
parameter_list|)
value|((struct vnode *)((f)->f_data))
end_define

begin_define
define|#
directive|define
name|NFSFPCRED
parameter_list|(
name|f
parameter_list|)
value|((f)->f_cred)
end_define

begin_define
define|#
directive|define
name|NFSFPFLAG
parameter_list|(
name|f
parameter_list|)
value|((f)->f_flag)
end_define

begin_define
define|#
directive|define
name|NFSNAMEICNDSET
parameter_list|(
name|n
parameter_list|,
name|c
parameter_list|,
name|o
parameter_list|,
name|f
parameter_list|)
value|do {				\ 	(n)->cn_cred = (c);						\ 	(n)->cn_nameiop = (o);						\ 	(n)->cn_flags = (f);						\     } while (0)
end_define

begin_comment
comment|/*  * A little bit of Darwin vfs kpi.  */
end_comment

begin_define
define|#
directive|define
name|vnode_mount
parameter_list|(
name|v
parameter_list|)
value|((v)->v_mount)
end_define

begin_define
define|#
directive|define
name|vfs_statfs
parameter_list|(
name|m
parameter_list|)
value|(&((m)->mnt_stat))
end_define

begin_define
define|#
directive|define
name|NFSPATHLEN_T
value|size_t
end_define

begin_comment
comment|/*  * These are set to the minimum and maximum size of a server file  * handle.  */
end_comment

begin_define
define|#
directive|define
name|NFSRV_MINFH
value|(sizeof (fhandle_t))
end_define

begin_define
define|#
directive|define
name|NFSRV_MAXFH
value|(sizeof (fhandle_t))
end_define

begin_comment
comment|/* Use this macro for debug printfs. */
end_comment

begin_define
define|#
directive|define
name|NFSD_DEBUG
parameter_list|(
name|level
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 		if (nfsd_debuglevel>= (level))				\ 			printf(__VA_ARGS__);				\ 	} while (0)
end_define

end_unit

