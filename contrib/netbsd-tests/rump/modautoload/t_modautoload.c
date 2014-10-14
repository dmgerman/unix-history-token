begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_modautoload.c,v 1.2 2014/03/10 22:38:53 pooka Exp $	*/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/dirent.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<rump/rump.h>
end_include

begin_include
include|#
directive|include
file|<rump/rump_syscalls.h>
end_include

begin_include
include|#
directive|include
file|<miscfs/kernfs/kernfs.h>
end_include

begin_include
include|#
directive|include
file|"../../h_macros.h"
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|modautoload
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|modautoload
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"tests that kernel module "
literal|"autoload works in rump"
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
specifier|static
name|void
name|mountkernfs
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|rump_nativeabi_p
argument_list|()
condition|)
name|atf_tc_skip
argument_list|(
literal|"host kernel modules not supported"
argument_list|)
expr_stmt|;
name|rump_init
argument_list|()
expr_stmt|;
if|if
condition|(
name|rump_sys_mkdir
argument_list|(
literal|"/kern"
argument_list|,
literal|0777
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"mkdir /kern"
argument_list|)
expr_stmt|;
if|if
condition|(
name|rump_sys_mount
argument_list|(
name|MOUNT_KERNFS
argument_list|,
literal|"/kern"
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"could not mount kernfs"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Why use kernfs here?  It talks to plenty of other parts with the  * kernel (e.g. vfs_attach() in modcmd), but is still easy to verify  * it's working correctly.  */
end_comment

begin_define
define|#
directive|define
name|MAGICNUM
value|1323
end_define

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|modautoload
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
specifier|extern
name|int
name|rumpns_hz
decl_stmt|;
name|char
name|buf
index|[
literal|64
index|]
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|mountkernfs
argument_list|()
expr_stmt|;
name|rumpns_hz
operator|=
name|MAGICNUM
expr_stmt|;
if|if
condition|(
operator|(
name|fd
operator|=
name|rump_sys_open
argument_list|(
literal|"/kern/hz"
argument_list|,
name|O_RDONLY
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"open /kern/hz"
argument_list|)
expr_stmt|;
if|if
condition|(
name|rump_sys_read
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|)
operator|<=
literal|0
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"read"
argument_list|)
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|atoi
argument_list|(
name|buf
argument_list|)
operator|==
name|MAGICNUM
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TP_ADD_TCS
argument_list|(
argument|tp
argument_list|)
end_macro

begin_block
block|{
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|modautoload
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

