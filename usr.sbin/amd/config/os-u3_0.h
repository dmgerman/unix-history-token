begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)os-u3_0.h	8.1 (Berkeley) 6/6/93  *  * $FreeBSD$  *  * Ultrix 3.0 definitions for Amd (automounter)  */
end_comment

begin_comment
comment|/*  * Does the compiler grok void *  */
end_comment

begin_undef
undef|#
directive|undef
name|VOIDP
end_undef

begin_comment
comment|/*  * Which version of the Sun RPC library we are using  * This is the implementation release number, not  * the protocol revision number.  */
end_comment

begin_define
define|#
directive|define
name|RPC_3
end_define

begin_comment
comment|/*  * Which version of the NFS interface are we using.  * This is the implementation release number, not  * the protocol revision number.  */
end_comment

begin_define
define|#
directive|define
name|NFS_3
end_define

begin_comment
comment|/*  * Byte ordering  */
end_comment

begin_undef
undef|#
directive|undef
name|ARCH_ENDIAN
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|mips
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARCH_ENDIAN
value|"little"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The mount table is obtained from the kernel  */
end_comment

begin_undef
undef|#
directive|undef
name|UPDATE_MTAB
end_undef

begin_comment
comment|/*  * No mntent info on Ultrix   */
end_comment

begin_undef
undef|#
directive|undef
name|MNTENT_HDR
end_undef

begin_comment
comment|/*  * No support for syslog()  */
end_comment

begin_undef
undef|#
directive|undef
name|HAS_SYSLOG
end_undef

begin_comment
comment|/*  * Name of filesystem types  */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_NFS
value|GT_NFS
end_define

begin_define
define|#
directive|define
name|MOUNT_TYPE_UFS
value|GT_ULTRIX
end_define

begin_undef
undef|#
directive|undef
name|MTAB_TYPE_UFS
end_undef

begin_define
define|#
directive|define
name|MTAB_TYPE_UFS
value|"ufs"
end_define

begin_comment
comment|/*  * Name of mount& unmount system calls  */
end_comment

begin_undef
undef|#
directive|undef
name|MOUNT_TRAP
end_undef

begin_define
define|#
directive|define
name|MOUNT_TRAP
parameter_list|(
name|type
parameter_list|,
name|mnt
parameter_list|,
name|flag
parameter_list|,
name|mnt_data
parameter_list|)
define|\
value|mount(mnt->mnt_fsname, mnt->mnt_dir, flag, type, mnt_data)
end_define

begin_undef
undef|#
directive|undef
name|UNMOUNT_TRAP
end_undef

begin_define
define|#
directive|define
name|UNMOUNT_TRAP
parameter_list|(
name|mnt
parameter_list|)
value|umount(mnt->mnt_passno)
end_define

begin_comment
comment|/*  * Miscellaneous Ultrix bits  */
end_comment

begin_define
define|#
directive|define
name|M_RDONLY
value|M_RONLY
end_define

begin_define
define|#
directive|define
name|MNTMAXSTR
value|128
end_define

begin_define
define|#
directive|define
name|MNTTYPE_UFS
value|"ufs"
end_define

begin_comment
comment|/* Un*x file system */
end_comment

begin_define
define|#
directive|define
name|MNTTYPE_NFS
value|"nfs"
end_define

begin_comment
comment|/* network file system */
end_comment

begin_define
define|#
directive|define
name|MNTTYPE_IGNORE
value|"ignore"
end_define

begin_comment
comment|/* No type specified, ignore this entry */
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
name|MNTOPT_QUOTA
value|"quota"
end_define

begin_comment
comment|/* quotas */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NOQUOTA
value|"noquota"
end_define

begin_comment
comment|/* no quotas */
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
name|MNTOPT_SOFT
value|"soft"
end_define

begin_comment
comment|/* soft mount */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_INTR
value|"intr"
end_define

begin_comment
comment|/* interrupts allowed */
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

begin_struct
struct|struct
name|mntent
block|{
name|char
modifier|*
name|mnt_fsname
decl_stmt|;
comment|/* name of mounted file system */
name|char
modifier|*
name|mnt_dir
decl_stmt|;
comment|/* file system path prefix */
name|char
modifier|*
name|mnt_type
decl_stmt|;
comment|/* MNTTYPE_* */
name|char
modifier|*
name|mnt_opts
decl_stmt|;
comment|/* MNTOPT* */
name|int
name|mnt_freq
decl_stmt|;
comment|/* dump frequency, in days */
name|int
name|mnt_passno
decl_stmt|;
comment|/* pass number on parallel fsck */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MOUNTED
value|"/etc/mtab"
end_define

begin_define
define|#
directive|define
name|NFS_HDR
value|"misc-ultrix.h"
end_define

begin_define
define|#
directive|define
name|UFS_HDR
value|"misc-ultrix.h"
end_define

begin_define
define|#
directive|define
name|NEED_XDR_POINTER
end_define

begin_define
define|#
directive|define
name|NEED_CLNT_SPERRNO
end_define

begin_define
define|#
directive|define
name|nfs_args
value|nfs_gfs_mount
end_define

begin_define
define|#
directive|define
name|ULTRIX_HACK
end_define

begin_comment
comment|/* Should be handled better than this !! */
end_comment

begin_define
define|#
directive|define
name|NEED_MNTOPT_PARSER
end_define

begin_comment
comment|/*  * How to get a mount list  */
end_comment

begin_undef
undef|#
directive|undef
name|READ_MTAB_FROM_FILE
end_undef

begin_define
define|#
directive|define
name|READ_MTAB_ULTRIX_STYLE
end_define

begin_comment
comment|/*  * Need precise length links  */
end_comment

begin_define
define|#
directive|define
name|PRECISE_SYMLINKS
end_define

end_unit

