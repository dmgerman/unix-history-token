begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: h_fsmacros.h,v 1.38 2013/06/26 19:29:24 reinoud Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Nicolas Joly.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__H_FSMACROS_H_
end_ifndef

begin_define
define|#
directive|define
name|__H_FSMACROS_H_
end_define

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<puffsdump.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<rump/rump.h>
end_include

begin_include
include|#
directive|include
file|"../../h_macros.h"
end_include

begin_define
define|#
directive|define
name|FSPROTOS
parameter_list|(
name|_fs_
parameter_list|)
define|\
value|int _fs_##_fstest_newfs(const atf_tc_t *, void **, const char *,	\ 			off_t, void *);					\ int _fs_##_fstest_delfs(const atf_tc_t *, void *);			\ int _fs_##_fstest_mount(const atf_tc_t *, void *, const char *, int);	\ int _fs_##_fstest_unmount(const atf_tc_t *, const char *, int);
end_define

begin_expr_stmt
name|FSPROTOS
argument_list|(
name|ext2fs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FSPROTOS
argument_list|(
name|ffs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FSPROTOS
argument_list|(
name|ffslog
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FSPROTOS
argument_list|(
name|lfs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FSPROTOS
argument_list|(
name|msdosfs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FSPROTOS
argument_list|(
name|nfs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FSPROTOS
argument_list|(
name|nfsro
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FSPROTOS
argument_list|(
name|p2k_ffs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FSPROTOS
argument_list|(
name|puffs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FSPROTOS
argument_list|(
name|rumpfs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FSPROTOS
argument_list|(
name|sysvbfs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FSPROTOS
argument_list|(
name|tmpfs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FSPROTOS
argument_list|(
name|udf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FSPROTOS
argument_list|(
name|v7fs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FSPROTOS
argument_list|(
name|zfs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|FSTEST_IMGNAME
end_ifndef

begin_define
define|#
directive|define
name|FSTEST_IMGNAME
value|"image.fs"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FSTEST_IMGSIZE
end_ifndef

begin_define
define|#
directive|define
name|FSTEST_IMGSIZE
value|(10000 * 512)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FSTEST_MNTNAME
end_ifndef

begin_define
define|#
directive|define
name|FSTEST_MNTNAME
value|"/mnt"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FSTEST_CONSTRUCTOR
parameter_list|(
name|_tc_
parameter_list|,
name|_fs_
parameter_list|,
name|_args_
parameter_list|)
define|\
value|do {									\ 	if (_fs_##_fstest_newfs(_tc_,&_args_,				\ 	    FSTEST_IMGNAME, FSTEST_IMGSIZE, NULL) != 0)			\ 		atf_tc_fail_errno("newfs failed");			\ 	if (_fs_##_fstest_mount(_tc_, _args_, FSTEST_MNTNAME, 0) != 0)	\ 		atf_tc_fail_errno("mount failed");			\ } while (
comment|/*CONSTCOND*/
value|0);
end_define

begin_define
define|#
directive|define
name|FSTEST_CONSTRUCTOR_FSPRIV
parameter_list|(
name|_tc_
parameter_list|,
name|_fs_
parameter_list|,
name|_args_
parameter_list|,
name|_privargs_
parameter_list|)
define|\
value|do {									\ 	if (_fs_##_fstest_newfs(_tc_,&_args_,				\ 	    FSTEST_IMGNAME, FSTEST_IMGSIZE, _privargs_) != 0)		\ 		atf_tc_fail_errno("newfs failed");			\ 	if (_fs_##_fstest_mount(_tc_, _args_, FSTEST_MNTNAME, 0) != 0)	\ 		atf_tc_fail_errno("mount failed");			\ } while (
comment|/*CONSTCOND*/
value|0);
end_define

begin_define
define|#
directive|define
name|FSTEST_DESTRUCTOR
parameter_list|(
name|_tc_
parameter_list|,
name|_fs_
parameter_list|,
name|_args_
parameter_list|)
define|\
value|do {									\ 	if (_fs_##_fstest_unmount(_tc_, FSTEST_MNTNAME, 0) != 0) {	\ 		rump_pub_vfs_mount_print(FSTEST_MNTNAME, 1);		\ 		atf_tc_fail_errno("unmount failed");			\ 	}								\ 	if (_fs_##_fstest_delfs(_tc_, _args_) != 0)			\ 		atf_tc_fail_errno("delfs failed");			\ } while (
comment|/*CONSTCOND*/
value|0);
end_define

begin_define
define|#
directive|define
name|ATF_TC_FSADD
parameter_list|(
name|fs
parameter_list|,
name|type
parameter_list|,
name|func
parameter_list|,
name|desc
parameter_list|)
define|\
value|ATF_TC(fs##_##func);						\ 	ATF_TC_HEAD(fs##_##func,tc)					\ 	{								\ 		atf_tc_set_md_var(tc, "descr", type " test for " desc);	\ 		atf_tc_set_md_var(tc, "X-fs.type", #fs);		\ 		atf_tc_set_md_var(tc, "X-fs.mntname", type);		\ 		if (strcmp(#fs, "zfs") == 0) {				\
comment|/* This should not be necessary. */
value|\ 			atf_tc_set_md_var(tc, "require.user", "root");	\ 		}							\ 	}								\ 	void *fs##func##tmp;						\ 									\ 	ATF_TC_BODY(fs##_##func,tc)					\ 	{								\ 		if (!atf_check_fstype(tc, #fs))				\ 			atf_tc_skip("filesystem not selected");		\ 		FSTEST_CONSTRUCTOR(tc,fs,fs##func##tmp);		\ 		func(tc,FSTEST_MNTNAME);				\ 		if (fs##_fstest_unmount(tc, FSTEST_MNTNAME, 0) != 0) {	\ 			rump_pub_vfs_mount_print(FSTEST_MNTNAME, 1);	\ 			atf_tc_fail_errno("unmount failed");		\ 		}							\ 	}
end_define

begin_define
define|#
directive|define
name|ATF_TC_FSADD_RO
parameter_list|(
name|_fs_
parameter_list|,
name|_type_
parameter_list|,
name|_func_
parameter_list|,
name|_desc_
parameter_list|,
name|_gen_
parameter_list|)
define|\
value|ATF_TC(_fs_##_##_func_);					\ 	ATF_TC_HEAD(_fs_##_##_func_,tc)					\ 	{								\ 		atf_tc_set_md_var(tc, "descr",_type_" test for "_desc_);\ 		atf_tc_set_md_var(tc, "X-fs.type", #_fs_);		\ 		atf_tc_set_md_var(tc, "X-fs.mntname", _type_);		\ 		if (strcmp(#_fs_, "zfs") == 0) {			\
comment|/* This should not be necessary. */
value|\ 			atf_tc_set_md_var(tc, "require.user", "root");	\ 		}							\ 	}								\ 	void *_fs_##_func_##tmp;					\ 									\ 	ATF_TC_BODY(_fs_##_##_func_,tc)					\ 	{								\ 		if (!atf_check_fstype(tc, #_fs_))			\ 			atf_tc_skip("filesystem not selected");		\ 		FSTEST_CONSTRUCTOR(tc,_fs_,_fs_##_func_##tmp);		\ 		_gen_(tc,FSTEST_MNTNAME);				\ 		if (_fs_##_fstest_unmount(tc, FSTEST_MNTNAME, 0) != 0)	\ 			atf_tc_fail_errno("unmount r/w failed");	\ 		if (_fs_##_fstest_mount(tc, _fs_##_func_##tmp,		\ 		    FSTEST_MNTNAME, MNT_RDONLY) != 0)			\ 		atf_tc_fail_errno("mount ro failed");			\ 		_func_(tc,FSTEST_MNTNAME);				\ 		if (_fs_##_fstest_unmount(tc, FSTEST_MNTNAME, 0) != 0) {\ 			rump_pub_vfs_mount_print(FSTEST_MNTNAME, 1);	\ 			atf_tc_fail_errno("unmount failed");		\ 		}							\ 	}
end_define

begin_define
define|#
directive|define
name|ATF_TP_FSADD
parameter_list|(
name|fs
parameter_list|,
name|func
parameter_list|)
define|\
value|ATF_TP_ADD_TC(tp,fs##_##func)
end_define

begin_define
define|#
directive|define
name|ATF_TC_FSAPPLY_NOZFS
parameter_list|(
name|func
parameter_list|,
name|desc
parameter_list|)
define|\
value|ATF_TC_FSADD(ext2fs,MOUNT_EXT2FS,func,desc)				\   ATF_TC_FSADD(ffs,MOUNT_FFS,func,desc)					\   ATF_TC_FSADD(ffslog,MOUNT_FFS,func,desc)				\   ATF_TC_FSADD(lfs,MOUNT_LFS,func,desc)					\   ATF_TC_FSADD(msdosfs,MOUNT_MSDOS,func,desc)				\   ATF_TC_FSADD(nfs,MOUNT_NFS,func,desc)					\   ATF_TC_FSADD(puffs,MOUNT_PUFFS,func,desc)				\   ATF_TC_FSADD(p2k_ffs,MOUNT_PUFFS,func,desc)				\   ATF_TC_FSADD(rumpfs,MOUNT_RUMPFS,func,desc)				\   ATF_TC_FSADD(sysvbfs,MOUNT_SYSVBFS,func,desc)				\   ATF_TC_FSADD(tmpfs,MOUNT_TMPFS,func,desc)				\   ATF_TC_FSADD(udf,MOUNT_UDF,func,desc)				\   ATF_TC_FSADD(v7fs,MOUNT_V7FS,func,desc)
end_define

begin_define
define|#
directive|define
name|ATF_TP_FSAPPLY_NOZFS
parameter_list|(
name|func
parameter_list|)
define|\
value|ATF_TP_FSADD(ext2fs,func);						\   ATF_TP_FSADD(ffs,func);						\   ATF_TP_FSADD(ffslog,func);						\   ATF_TP_FSADD(lfs,func);						\   ATF_TP_FSADD(msdosfs,func);						\   ATF_TP_FSADD(nfs,func);						\   ATF_TP_FSADD(puffs,func);						\   ATF_TP_FSADD(p2k_ffs,func);						\   ATF_TP_FSADD(rumpfs,func);						\   ATF_TP_FSADD(sysvbfs,func);						\   ATF_TP_FSADD(tmpfs,func);						\   ATF_TP_FSADD(udf,func);						\   ATF_TP_FSADD(v7fs,func);
end_define

begin_comment
comment|/* XXX: this will not scale */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WANT_ZFS_TESTS
end_ifdef

begin_define
define|#
directive|define
name|ATF_TC_FSAPPLY
parameter_list|(
name|func
parameter_list|,
name|desc
parameter_list|)
define|\
value|ATF_TC_FSAPPLY_NOZFS(func,desc)					\   ATF_TC_FSADD(zfs,MOUNT_ZFS,func,desc)
end_define

begin_define
define|#
directive|define
name|ATF_TP_FSAPPLY
parameter_list|(
name|func
parameter_list|)
define|\
value|ATF_TP_FSAPPLY_NOZFS(func)						\   ATF_TP_FSADD(zfs,func);
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !WANT_ZFS_TESTS */
end_comment

begin_define
define|#
directive|define
name|ATF_TC_FSAPPLY
parameter_list|(
name|func
parameter_list|,
name|desc
parameter_list|)
define|\
value|ATF_TC_FSAPPLY_NOZFS(func,desc)
end_define

begin_define
define|#
directive|define
name|ATF_TP_FSAPPLY
parameter_list|(
name|func
parameter_list|)
define|\
value|ATF_TP_FSAPPLY_NOZFS(func)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WANT_ZFS_TESTS */
end_comment

begin_comment
comment|/*  * Same as above, but generate a file system image first and perform  * tests for a r/o mount.  *  * Missing the following file systems:  *   + lfs (fstest_lfs routines cannot handle remount.  FIXME!)  *   + tmpfs (memory backend)  *   + rumpfs (memory backend)  *   + puffs (memory backend, but could be run in theory)  */
end_comment

begin_define
define|#
directive|define
name|ATF_TC_FSAPPLY_RO
parameter_list|(
name|func
parameter_list|,
name|desc
parameter_list|,
name|gen
parameter_list|)
define|\
value|ATF_TC_FSADD_RO(ext2fs,MOUNT_EXT2FS,func,desc,gen)			\   ATF_TC_FSADD_RO(ffs,MOUNT_FFS,func,desc,gen)				\   ATF_TC_FSADD_RO(ffslog,MOUNT_FFS,func,desc,gen)			\   ATF_TC_FSADD_RO(msdosfs,MOUNT_MSDOS,func,desc,gen)			\   ATF_TC_FSADD_RO(nfs,MOUNT_NFS,func,desc,gen)				\   ATF_TC_FSADD_RO(nfsro,MOUNT_NFS,func,desc,gen)			\   ATF_TC_FSADD_RO(sysvbfs,MOUNT_SYSVBFS,func,desc,gen)			\   ATF_TC_FSADD_RO(udf,MOUNT_UDF,func,desc,gen)			\   ATF_TC_FSADD_RO(v7fs,MOUNT_V7FS,func,desc,gen)
end_define

begin_define
define|#
directive|define
name|ATF_TP_FSAPPLY_RO
parameter_list|(
name|func
parameter_list|)
define|\
value|ATF_TP_FSADD(ext2fs,func);						\   ATF_TP_FSADD(ffs,func);						\   ATF_TP_FSADD(ffslog,func);						\   ATF_TP_FSADD(msdosfs,func);						\   ATF_TP_FSADD(nfs,func);						\   ATF_TP_FSADD(nfsro,func);						\   ATF_TP_FSADD(sysvbfs,func);						\   ATF_TP_FSADD(udf,func);						\   ATF_TP_FSADD(v7fs,func);
end_define

begin_define
define|#
directive|define
name|ATF_FSAPPLY
parameter_list|(
name|func
parameter_list|,
name|desc
parameter_list|)
define|\
value|ATF_TC_FSAPPLY(func,desc);					\ 	ATF_TP_ADD_TCS(tp)						\ 	{								\ 		ATF_TP_FSAPPLY(func);					\ 		return atf_no_error();					\ 	}
end_define

begin_function
specifier|static
name|__inline
name|bool
name|atf_check_fstype
parameter_list|(
specifier|const
name|atf_tc_t
modifier|*
name|tc
parameter_list|,
specifier|const
name|char
modifier|*
name|fs
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|fstype
decl_stmt|;
if|if
condition|(
operator|!
name|atf_tc_has_config_var
argument_list|(
name|tc
argument_list|,
literal|"fstype"
argument_list|)
condition|)
return|return
name|true
return|;
name|fstype
operator|=
name|atf_tc_get_config_var
argument_list|(
name|tc
argument_list|,
literal|"fstype"
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|fstype
argument_list|,
name|fs
argument_list|)
operator|==
literal|0
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
end_function

begin_define
define|#
directive|define
name|FSTYPE_EXT2FS
parameter_list|(
name|tc
parameter_list|)
define|\
value|(strcmp(atf_tc_get_md_var(tc, "X-fs.type"), "ext2fs") == 0)
end_define

begin_define
define|#
directive|define
name|FSTYPE_FFS
parameter_list|(
name|tc
parameter_list|)
define|\
value|(strcmp(atf_tc_get_md_var(tc, "X-fs.type"), "ffs") == 0)
end_define

begin_define
define|#
directive|define
name|FSTYPE_FFSLOG
parameter_list|(
name|tc
parameter_list|)
define|\
value|(strcmp(atf_tc_get_md_var(tc, "X-fs.type"), "ffslog") == 0)
end_define

begin_define
define|#
directive|define
name|FSTYPE_LFS
parameter_list|(
name|tc
parameter_list|)
define|\
value|(strcmp(atf_tc_get_md_var(tc, "X-fs.type"), "lfs") == 0)
end_define

begin_define
define|#
directive|define
name|FSTYPE_MSDOS
parameter_list|(
name|tc
parameter_list|)
define|\
value|(strcmp(atf_tc_get_md_var(tc, "X-fs.type"), "msdosfs") == 0)
end_define

begin_define
define|#
directive|define
name|FSTYPE_NFS
parameter_list|(
name|tc
parameter_list|)
define|\
value|(strcmp(atf_tc_get_md_var(tc, "X-fs.type"), "nfs") == 0)
end_define

begin_define
define|#
directive|define
name|FSTYPE_NFSRO
parameter_list|(
name|tc
parameter_list|)
define|\
value|(strcmp(atf_tc_get_md_var(tc, "X-fs.type"), "nfsro") == 0)
end_define

begin_define
define|#
directive|define
name|FSTYPE_P2K_FFS
parameter_list|(
name|tc
parameter_list|)
define|\
value|(strcmp(atf_tc_get_md_var(tc, "X-fs.type"), "p2k_ffs") == 0)
end_define

begin_define
define|#
directive|define
name|FSTYPE_PUFFS
parameter_list|(
name|tc
parameter_list|)
define|\
value|(strcmp(atf_tc_get_md_var(tc, "X-fs.type"), "puffs") == 0)
end_define

begin_define
define|#
directive|define
name|FSTYPE_RUMPFS
parameter_list|(
name|tc
parameter_list|)
define|\
value|(strcmp(atf_tc_get_md_var(tc, "X-fs.type"), "rumpfs") == 0)
end_define

begin_define
define|#
directive|define
name|FSTYPE_SYSVBFS
parameter_list|(
name|tc
parameter_list|)
define|\
value|(strcmp(atf_tc_get_md_var(tc, "X-fs.type"), "sysvbfs") == 0)
end_define

begin_define
define|#
directive|define
name|FSTYPE_TMPFS
parameter_list|(
name|tc
parameter_list|)
define|\
value|(strcmp(atf_tc_get_md_var(tc, "X-fs.type"), "tmpfs") == 0)
end_define

begin_define
define|#
directive|define
name|FSTYPE_UDF
parameter_list|(
name|tc
parameter_list|)
define|\
value|(strcmp(atf_tc_get_md_var(tc, "X-fs.type"), "udf") == 0)
end_define

begin_define
define|#
directive|define
name|FSTYPE_V7FS
parameter_list|(
name|tc
parameter_list|)
define|\
value|(strcmp(atf_tc_get_md_var(tc, "X-fs.type"), "v7fs") == 0)
end_define

begin_define
define|#
directive|define
name|FSTYPE_ZFS
parameter_list|(
name|tc
parameter_list|)
define|\
value|(strcmp(atf_tc_get_md_var(tc, "X-fs.type"), "zfs") == 0)
end_define

begin_define
define|#
directive|define
name|FSTEST_ENTER
parameter_list|()
define|\
value|if (rump_sys_chdir(FSTEST_MNTNAME) == -1)			\ 		atf_tc_fail_errno("failed to cd into test mount")
end_define

begin_define
define|#
directive|define
name|FSTEST_EXIT
parameter_list|()
define|\
value|if (rump_sys_chdir("/") == -1)					\ 		atf_tc_fail_errno("failed to cd out of test mount")
end_define

begin_comment
comment|/*  * file system args structures  */
end_comment

begin_struct
struct|struct
name|nfstestargs
block|{
name|pid_t
name|ta_childpid
decl_stmt|;
name|char
name|ta_ethername
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|puffstestargs
block|{
name|uint8_t
modifier|*
name|pta_pargs
decl_stmt|;
name|size_t
name|pta_pargslen
decl_stmt|;
name|int
name|pta_pflags
decl_stmt|;
name|pid_t
name|pta_childpid
decl_stmt|;
name|int
name|pta_rumpfd
decl_stmt|;
name|int
name|pta_servfd
decl_stmt|;
name|char
name|pta_dev
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
name|pta_dir
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|int
name|pta_mntflags
decl_stmt|;
name|int
name|pta_vfs_toserv_ops
index|[
name|PUFFS_VFS_MAX
index|]
decl_stmt|;
name|int
name|pta_vn_toserv_ops
index|[
name|PUFFS_VN_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __H_FSMACROS_H_ */
end_comment

end_unit

