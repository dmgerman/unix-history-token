begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)fstab.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FSTAB_H_
end_ifndef

begin_define
define|#
directive|define
name|_FSTAB_H_
end_define

begin_comment
comment|/*  * File system table, see fstab(5).  *  * Used by dump, mount, umount, swapon, fsck, df, ...  *  * For ufs fs_spec field is the block special name.  Programs that want to  * use the character special name must create that name by prepending a 'r'  * after the right most slash.  Quota files are always named "quotas", so  * if type is "rq", then use concatenation of fs_file and "quotas" to locate  * quota file.  */
end_comment

begin_define
define|#
directive|define
name|_PATH_FSTAB
value|"/etc/fstab"
end_define

begin_define
define|#
directive|define
name|FSTAB
value|"/etc/fstab"
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|FSTAB_RW
value|"rw"
end_define

begin_comment
comment|/* read/write device */
end_comment

begin_define
define|#
directive|define
name|FSTAB_RQ
value|"rq"
end_define

begin_comment
comment|/* read/write with quotas */
end_comment

begin_define
define|#
directive|define
name|FSTAB_RO
value|"ro"
end_define

begin_comment
comment|/* read-only device */
end_comment

begin_define
define|#
directive|define
name|FSTAB_SW
value|"sw"
end_define

begin_comment
comment|/* swap device */
end_comment

begin_define
define|#
directive|define
name|FSTAB_XX
value|"xx"
end_define

begin_comment
comment|/* ignore totally */
end_comment

begin_struct
struct|struct
name|fstab
block|{
name|char
modifier|*
name|fs_spec
decl_stmt|;
comment|/* block special device name */
name|char
modifier|*
name|fs_file
decl_stmt|;
comment|/* file system path prefix */
name|char
modifier|*
name|fs_vfstype
decl_stmt|;
comment|/* File system type, ufs, nfs */
name|char
modifier|*
name|fs_mntops
decl_stmt|;
comment|/* Mount options ala -o */
name|char
modifier|*
name|fs_type
decl_stmt|;
comment|/* FSTAB_* from fs_mntops */
name|int
name|fs_freq
decl_stmt|;
comment|/* dump frequency, in days */
name|int
name|fs_passno
decl_stmt|;
comment|/* pass number on parallel dump */
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|struct
name|fstab
modifier|*
name|getfsent
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|fstab
modifier|*
name|getfsspec
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|fstab
modifier|*
name|getfsfile
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setfsent
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|endfsent
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FSTAB_H_ */
end_comment

end_unit

