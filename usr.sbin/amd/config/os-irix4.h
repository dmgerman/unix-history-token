begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)os-irix4.h	8.1 (Berkeley) 6/6/93  *  * $FreeBSD$  *  * IRIX 4.0.X definitions for Amd (automounter)  * Contributed by Scott R. Presnell<srp@cgl.ucsf.edu>  */
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

begin_define
define|#
directive|define
name|ARCH_ENDIAN
value|"big"
end_define

begin_comment
comment|/*  * Has support for syslog()  */
end_comment

begin_define
define|#
directive|define
name|HAS_SYSLOG
end_define

begin_define
define|#
directive|define
name|M_RDONLY
value|MS_RDONLY
end_define

begin_define
define|#
directive|define
name|M_GRPID
value|MS_GRPID
end_define

begin_define
define|#
directive|define
name|M_NOSUID
value|MS_NOSUID
end_define

begin_define
define|#
directive|define
name|M_NONDEV
value|MS_NODEV
end_define

begin_comment
comment|/*  * Support for ndbm  */
end_comment

begin_define
define|#
directive|define
name|OS_HAS_NDBM
end_define

begin_define
define|#
directive|define
name|UPDATE_MTAB
end_define

begin_undef
undef|#
directive|undef
name|MTAB_TYPE_NFS
end_undef

begin_define
define|#
directive|define
name|MTAB_TYPE_NFS
value|"nfs"
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
value|"efs"
end_define

begin_define
define|#
directive|define
name|NMOUNT
value|40
end_define

begin_comment
comment|/* The std sun value */
end_comment

begin_comment
comment|/*  * Name of filesystem types  */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_UFS
value|sysfs(GETFSIND, FSID_EFS)
end_define

begin_define
define|#
directive|define
name|MOUNT_TYPE_NFS
value|sysfs(GETFSIND, FSID_NFS)
end_define

begin_define
define|#
directive|define
name|SYS5_SIGNALS
end_define

begin_comment
comment|/*  * Use<fcntl.h> rather than<sys/file.h>  */
end_comment

begin_comment
comment|/*#define USE_FCNTL*/
end_comment

begin_comment
comment|/*  * Use fcntl() rather than flock()  */
end_comment

begin_comment
comment|/*#define LOCK_FCNTL*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|alloca
parameter_list|(
name|sz
parameter_list|)
value|__builtin_alloca(sz)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|ptr
parameter_list|,
name|len
parameter_list|)
value|memset(ptr, 0, len)
end_define

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|len
parameter_list|)
value|memcpy(to, from, len)
end_define

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
name|flags
parameter_list|,
name|mnt_data
parameter_list|)
define|\
value|irix_mount(mnt->mnt_fsname, mnt->mnt_dir,flags, type, mnt_data)
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
value|umount(mnt->mnt_dir)
end_define

begin_define
define|#
directive|define
name|NFDS
value|30
end_define

begin_comment
comment|/* conservative */
end_comment

begin_define
define|#
directive|define
name|NFS_HDR
value|"misc-irix.h"
end_define

begin_define
define|#
directive|define
name|UFS_HDR
value|"misc-irix.h"
end_define

begin_comment
comment|/* not included in sys/param.h */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|MOUNT_HELPER_SOURCE
value|"mount_irix.c"
end_define

begin_comment
comment|/*  * Under 4.0.X this information is in /usr/include/mntent.h  * Below is what is used to be for Irix 3.3.X.  */
end_comment

begin_comment
comment|/*#define	MNTINFO_DEV	"fsid"*/
end_comment

begin_comment
comment|/*#define	MNTINFO_PREF	"0x"*/
end_comment

begin_define
define|#
directive|define
name|MNTINFO_PREF
value|""
end_define

begin_comment
comment|/*  * Under Irix, mount type "auto" is probed by statfs() in df.  A statfs() of  * a direct mount causes that mount to fire.  So change the  mount type in  * /etc/mtab to "ignore" to stop that (this is what SGI does for their  * automounter.  Use the old FASCIST define for this.  */
end_comment

begin_define
define|#
directive|define
name|FASCIST_DF_COMMAND
value|MNTTYPE_IGNORE
end_define

end_unit

