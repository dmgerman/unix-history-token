begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: os-aux.h,v 5.2 90/06/23 22:20:37 jsp Rel $ */
end_comment

begin_comment
comment|/*  * A/UX macII definitions for Amd (automounter)  * Contributed by Julian Onions<jpo@cs.nott.ac.uk>  *  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)os-aux.h	5.1 (Berkeley) %G%  */
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
value|"5.2"
end_define

begin_define
define|#
directive|define
name|SIGCHLD
value|SIGCLD
end_define

begin_define
define|#
directive|define
name|SYS5_SIGNALS
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
value|fsmount(type, mnt->mnt_dir, flags, mnt_data)
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
value|unmount(mnt->mnt_dir)
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

begin_comment
comment|/* not included in sys/param.h */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* not part of sys/time.h */
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|/* for NMOUNT */
end_comment

begin_include
include|#
directive|include
file|<sys/config.h>
end_include

end_unit

