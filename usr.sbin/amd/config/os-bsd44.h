begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)os-bsd44.h	8.1 (Berkeley) 6/6/93  *  * $FreeBSD$  *  * 4.4 BSD definitions for Amd (automounter)  */
end_comment

begin_comment
comment|/*  * Does the compiler grok void *  */
end_comment

begin_define
define|#
directive|define
name|VOIDP
end_define

begin_comment
comment|/*  * Which version of the Sun RPC library we are using  * This is the implementation release number, not  * the protocol revision number.  */
end_comment

begin_define
define|#
directive|define
name|RPC_4
end_define

begin_comment
comment|/*  * Which version of the NFS interface are we using.  * This is the implementation release number, not  * the protocol revision number.  */
end_comment

begin_define
define|#
directive|define
name|NFS_44
end_define

begin_define
define|#
directive|define
name|HAS_TCP_NFS
end_define

begin_comment
comment|/*  * Does this OS have NDBM support?  */
end_comment

begin_define
define|#
directive|define
name|OS_HAS_NDBM
end_define

begin_comment
comment|/*  * 4.4 doesn't provide NIS, but FreeBSD does.  */
end_comment

begin_define
define|#
directive|define
name|HAS_NIS_MAPS
end_define

begin_comment
comment|/*  * OS provides strerror()  */
end_comment

begin_define
define|#
directive|define
name|HAS_STRERROR
end_define

begin_comment
comment|/*  * The mount table is obtained from the kernel  */
end_comment

begin_undef
undef|#
directive|undef
name|UPDATE_MTAB
end_undef

begin_comment
comment|/*  * No mntent info on 4.4 BSD  */
end_comment

begin_undef
undef|#
directive|undef
name|MNTENT_HDR
end_undef

begin_comment
comment|/*  * Name of filesystem types  */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_NFS
value|MOUNT_NFS
end_define

begin_define
define|#
directive|define
name|MOUNT_TYPE_UFS
value|MOUNT_UFS
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

begin_define
define|#
directive|define
name|MTAB_TYPE_MFS
value|"mfs"
end_define

begin_comment
comment|/*  * How to unmount filesystems  */
end_comment

begin_undef
undef|#
directive|undef
name|UNMOUNT_TRAP
end_undef

begin_undef
undef|#
directive|undef
name|NEED_UMOUNT_FS
end_undef

begin_define
define|#
directive|define
name|NEED_UMOUNT_BSD
end_define

begin_comment
comment|/*  * How to copy an address into an NFS filehandle  */
end_comment

begin_undef
undef|#
directive|undef
name|NFS_SA_DREF
end_undef

begin_define
define|#
directive|define
name|NFS_SA_DREF
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|{ \ 		(dst).addr = (struct sockaddr *) (src); \ 		(dst).addrlen = sizeof(*src); \ 		(dst).sotype = SOCK_DGRAM; \ 		(dst).proto = 0; \ 	}
end_define

begin_comment
comment|/*  * Byte ordering  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BYTE_ORDER
end_ifndef

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BYTE_ORDER */
end_comment

begin_undef
undef|#
directive|undef
name|ARCH_ENDIAN
end_undef

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|ARCH_ENDIAN
value|"little"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|ARCH_ENDIAN
value|"big"
end_define

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|XXX
operator|-
name|Probably
name|no
name|hope
name|of
name|running
name|Amd
name|on
name|this
name|machine
operator|!
endif|#
directive|endif
comment|/* BIG */
endif|#
directive|endif
comment|/* LITTLE */
comment|/*  * Miscellaneous 4.4 BSD bits  */
define|#
directive|define
name|NEED_MNTOPT_PARSER
define|#
directive|define
name|SHORT_MOUNT_NAME
define|#
directive|define
name|MNTMAXSTR
value|128
define|#
directive|define
name|MNTTYPE_UFS
value|"ufs"
comment|/* Un*x file system */
define|#
directive|define
name|MNTTYPE_NFS
value|"nfs"
comment|/* network file system */
define|#
directive|define
name|MNTTYPE_MFS
value|"mfs"
comment|/* memory file system */
define|#
directive|define
name|MNTTYPE_IGNORE
value|"ignore"
comment|/* No type specified, ignore this entry */
define|#
directive|define
name|M_RDONLY
value|MNT_RDONLY
define|#
directive|define
name|M_SYNC
value|MNT_SYNCHRONOUS
define|#
directive|define
name|M_NOEXEC
value|MNT_NOEXEC
define|#
directive|define
name|M_NOSUID
value|MNT_NOSUID
define|#
directive|define
name|M_NODEV
value|MNT_NODEV
define|#
directive|define
name|MNTOPT_SOFT
value|"soft"
comment|/* soft mount */
define|#
directive|define
name|MNTOPT_INTR
value|"intr"
comment|/* interrupts allowed */
define|#
directive|define
name|MNTOPT_NOCONN
value|"noconn"
comment|/* no connection option allowed */
define|#
directive|define
name|NFSMNT_HOSTNAME
value|0
comment|/* hostname on 4.4 is not optional */
expr|struct
name|mntent
block|{
name|char
operator|*
name|mnt_fsname
block|;
comment|/* name of mounted file system */
name|char
operator|*
name|mnt_dir
block|;
comment|/* file system path prefix */
name|char
operator|*
name|mnt_type
block|;
comment|/* MNTTYPE_* */
name|char
operator|*
name|mnt_opts
block|;
comment|/* MNTOPT* */
name|int
name|mnt_freq
block|;
comment|/* dump frequency, in days */
name|int
name|mnt_passno
block|;
comment|/* pass number on parallel fsck */
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Type of a file handle  */
end_comment

begin_undef
undef|#
directive|undef
name|NFS_FH_TYPE
end_undef

begin_define
define|#
directive|define
name|NFS_FH_TYPE
value|nfsv2fh_t *
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
name|READ_MTAB_BSD_STYLE
end_define

begin_comment
comment|/*  * The data for the mount syscall needs the path in addition to the  * host name since that is the only source of information about the  * mounted filesystem.  */
end_comment

begin_define
define|#
directive|define
name|NFS_ARGS_NEEDS_PATH
end_define

begin_comment
comment|/*  * 4.4 has RE support built in  */
end_comment

begin_undef
undef|#
directive|undef
name|RE_HDR
end_undef

begin_define
define|#
directive|define
name|RE_HDR
value|<regexp.h>
end_define

end_unit

