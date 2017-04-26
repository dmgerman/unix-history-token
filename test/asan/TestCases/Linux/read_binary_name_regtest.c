begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Regression test for https://crbug.com/502974, where ASan was unable to read
end_comment

begin_comment
comment|// the binary name because of sandbox restrictions.
end_comment

begin_comment
comment|// This test uses seccomp-BPF to restrict the readlink() system call and makes
end_comment

begin_comment
comment|// sure ASan is still able to
end_comment

begin_comment
comment|// RUN: not ls /usr/include/linux/seccomp.h || ( %clang_asan %s -o %t&& not %run %t 2>&1 | FileCheck %s )
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

begin_comment
comment|// UNSUPPORTED: android
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/prctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_include
include|#
directive|include
file|<linux/filter.h>
end_include

begin_include
include|#
directive|include
file|<linux/seccomp.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__NR_readlink
end_ifndef

begin_define
define|#
directive|define
name|__NR_readlink
value|__NR_readlinkat
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|syscall_nr
value|(offsetof(struct seccomp_data, nr))
end_define

begin_function
name|void
name|corrupt
parameter_list|()
block|{
name|void
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|10
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|prctl
argument_list|(
name|PR_SET_NO_NEW_PRIVS
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|struct
name|sock_filter
name|filter
index|[]
init|=
block|{
comment|/* Grab the system call number */
name|BPF_STMT
argument_list|(
name|BPF_LD
operator|+
name|BPF_W
operator|+
name|BPF_ABS
argument_list|,
name|syscall_nr
argument_list|)
block|,
comment|// If this is __NR_readlink,
name|BPF_JUMP
argument_list|(
name|BPF_JMP
operator|+
name|BPF_JEQ
operator|+
name|BPF_K
argument_list|,
name|__NR_readlink
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
block|,
comment|// return with EPERM,
name|BPF_STMT
argument_list|(
name|BPF_RET
operator|+
name|BPF_K
argument_list|,
name|SECCOMP_RET_ERRNO
operator||
name|EPERM
argument_list|)
block|,
comment|// otherwise allow the syscall.
name|BPF_STMT
argument_list|(
argument|BPF_RET + BPF_K
argument_list|,
argument|SECCOMP_RET_ALLOW
argument_list|)
block|}
decl_stmt|;
name|struct
name|sock_fprog
name|prog
decl_stmt|;
name|prog
operator|.
name|len
operator|=
call|(
name|unsigned
name|short
call|)
argument_list|(
sizeof|sizeof
argument_list|(
name|filter
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|filter
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|prog
operator|.
name|filter
operator|=
name|filter
expr_stmt|;
name|int
name|res
init|=
name|prctl
argument_list|(
name|PR_SET_SECCOMP
argument_list|,
name|SECCOMP_MODE_FILTER
argument_list|,
operator|&
name|prog
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|!=
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"PR_SET_SECCOMP unsupported!\n"
argument_list|)
expr_stmt|;
block|}
name|corrupt
argument_list|()
expr_stmt|;
comment|// CHECK: AddressSanitizer
comment|// CHECK-NOT: reading executable name failed
return|return
literal|0
return|;
block|}
end_function

end_unit

