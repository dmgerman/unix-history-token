begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)os-hpux.h	5.4 (Berkeley) %G%  *  * $Id: os-hpux.h,v 5.2.2.1 1992/02/09 15:10:23 jsp beta $  *  * HP/9000 HP-UX definitions for Amd (automounter)  */
end_comment

begin_comment
comment|/*  * Does the compiler grok void *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|VOIDP
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|hp9000s200
argument_list|)
operator|||
name|defined
argument_list|(
name|hp9000s300
argument_list|)
operator|||
name|defined
argument_list|(
name|hp9000s800
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARCH_ENDIAN
value|"big"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__hpux
end_ifndef

begin_define
define|#
directive|define
name|HPUX_VERSION_6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * No support for syslog() prior to 7.0  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX_VERSION_6
end_ifdef

begin_undef
undef|#
directive|undef
name|HAS_SYSLOG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * No support for ndbm  */
end_comment

begin_undef
undef|#
directive|undef
name|OS_HAS_NDBM
end_undef

begin_comment
comment|/*  * Name of filesystem types  */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_UFS
value|MOUNT_UFS
end_define

begin_define
define|#
directive|define
name|MOUNT_TYPE_NFS
value|MOUNT_NFS
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
value|"hfs"
end_define

begin_comment
comment|/*  * Where to get NFS definitions  */
end_comment

begin_define
define|#
directive|define
name|NFS_HDR
value|"misc-hpux.h"
end_define

begin_comment
comment|/*  * Where to get union wait  */
end_comment

begin_undef
undef|#
directive|undef
name|WAIT
end_undef

begin_define
define|#
directive|define
name|WAIT
value|"uwait.h"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX_VERSION_6
end_ifdef

begin_define
define|#
directive|define
name|SIGCHLD
value|SIGCLD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SYS5_SIGNALS
end_define

begin_comment
comment|/*  * Miscellaneous HP-UX definitions  */
end_comment

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

begin_comment
comment|/*  * Use<fcntl.h> rather than<sys/file.h>  */
end_comment

begin_define
define|#
directive|define
name|USE_FCNTL
end_define

begin_comment
comment|/*  * Use fcntl() rather than flock()  */
end_comment

begin_define
define|#
directive|define
name|LOCK_FCNTL
end_define

begin_comment
comment|/*  * Additional fields in struct mntent  * are fixed up here  */
end_comment

begin_define
define|#
directive|define
name|FIXUP_MNTENT
parameter_list|(
name|mntp
parameter_list|)
value|{ \ 	(mntp)->mnt_time = clocktime(); \ }
end_define

begin_define
define|#
directive|define
name|FIXUP_MNTENT_DUP
parameter_list|(
name|mntp
parameter_list|,
name|mp
parameter_list|)
value|{ \ 	(mntp)->mnt_time = (mp)->mnt_time; \ }
end_define

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

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|(2048)
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
value|vfsmount(type, mnt->mnt_dir, flags, mnt_data)
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
name|MOUNTED
value|MNT_MNTTAB
end_define

end_unit

