begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)os-defaults.h	8.1 (Berkeley) 6/6/93  *  * $FreeBSD$  *  * Common OS definitions.  These may be overridden in  * the OS specific files ("os-foo.h").  */
end_comment

begin_comment
comment|/*  * What level of AMD are we backward compatible with?  * This only applies to externally visible characteristics.  * Rev.Minor.Branch.Patch (2 digits each)  */
end_comment

begin_define
define|#
directive|define
name|AMD_COMPAT
value|5000000
end_define

begin_comment
comment|/* 5.0 */
end_comment

begin_comment
comment|/*  * What type is free(void*) returning?  */
end_comment

begin_define
define|#
directive|define
name|FREE_RETURN_TYPE
value|void
end_define

begin_comment
comment|/*  * Is the mount table mirrored in software  */
end_comment

begin_define
define|#
directive|define
name|UPDATE_MTAB
end_define

begin_comment
comment|/*  * Where to get union wait  */
end_comment

begin_define
define|#
directive|define
name|WAIT
value|<sys/wait.h>
end_define

begin_comment
comment|/*  * Where to get mount entry info  */
end_comment

begin_define
define|#
directive|define
name|MNTENT_HDR
value|<mntent.h>
end_define

begin_comment
comment|/*  * Include support for syslog()  */
end_comment

begin_define
define|#
directive|define
name|HAS_SYSLOG
end_define

begin_comment
comment|/*  * Byte ordering  */
end_comment

begin_define
define|#
directive|define
name|ARCH_ENDIAN
value|"unknown"
end_define

begin_comment
comment|/*  * Name of filesystem types  */
end_comment

begin_define
define|#
directive|define
name|MTAB_TYPE_NFS
value|"nfs"
end_define

begin_define
define|#
directive|define
name|MTAB_TYPE_UFS
value|"4.2"
end_define

begin_comment
comment|/*  * Name of mount& unmount system calls  *  * NOTE:  *  UNMOUNT_TRAP takes a struct mntent *  */
end_comment

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
value|mount(type, mnt->mnt_dir, flags, mnt_data)
end_define

begin_define
define|#
directive|define
name|UNMOUNT_TRAP
parameter_list|(
name|mnt
parameter_list|)
value|unmount(mnt->mnt_dir)
end_define

begin_comment
comment|/*  * How to unmount filesystems.  * NEED_UMOUNT_FS includes code to scan the mount table  * to find the correct information for the unmount system  * call.  Some systems, such as 4.4bsd, do not require  * this - they can just do an unmount system call directly.  */
end_comment

begin_define
define|#
directive|define
name|NEED_UMOUNT_FS
end_define

begin_define
define|#
directive|define
name|UMOUNT_FS
parameter_list|(
name|dir
parameter_list|)
value|umount_fs(dir)
end_define

begin_comment
comment|/*  * Type of a file handle  */
end_comment

begin_define
define|#
directive|define
name|NFS_FH_TYPE
value|fhandle_t *
end_define

begin_define
define|#
directive|define
name|NFS_FH_DREF
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|{ (dst) = (src); }
end_define

begin_comment
comment|/*  * How to copy an address into an NFS filehandle  */
end_comment

begin_define
define|#
directive|define
name|NFS_SA_DREF
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|{ (dst).addr = (src); }
end_define

begin_comment
comment|/*  * Type of filesystem type  */
end_comment

begin_define
define|#
directive|define
name|MTYPE_TYPE
value|int
end_define

begin_comment
comment|/*  * How to get a mount list  */
end_comment

begin_define
define|#
directive|define
name|READ_MTAB_FROM_FILE
end_define

begin_comment
comment|/*  * Make Amd automount points appear  * to be zero sized.  undef this  * if the O/S has a divide by zero  * problem in df et al.  */
end_comment

begin_define
define|#
directive|define
name|HAS_EMPTY_AUTOMOUNTS
end_define

begin_comment
comment|/*  * For the RE matcher  */
end_comment

begin_define
define|#
directive|define
name|CHARBITS
value|0377
end_define

begin_define
define|#
directive|define
name|STRCSPN
end_define

begin_define
define|#
directive|define
name|RE_HDR
value|"re.h"
end_define

end_unit

