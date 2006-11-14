begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_RPCSVC_MOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<rpcsvc/mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RPCSVC_MOUNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_MOUNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NFS_NFS_GFS_H
end_ifdef

begin_include
include|#
directive|include
file|<nfs/nfs_gfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NFS_NFS_GFS_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NFS_MOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<nfs/mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NFS_MOUNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FS_NFS_CLNT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fs/nfs_clnt.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FS_NFS_CLNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LINUX_NFS_MOUNT_H
end_ifdef

begin_define
define|#
directive|define
name|_LINUX_NFS_H
end_define

begin_define
define|#
directive|define
name|_LINUX_NFS2_H
end_define

begin_define
define|#
directive|define
name|_LINUX_NFS3_H
end_define

begin_define
define|#
directive|define
name|_LINUX_NFS_FS_H
end_define

begin_define
define|#
directive|define
name|_LINUX_IN_H
end_define

begin_include
include|#
directive|include
file|<linux/nfs_mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LINUX_NFS_MOUNT_H */
end_comment

end_unit

