begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sysentvec for native FreeBSD a.out executable format.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysproto.h>
end_include

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_decl_stmt
name|struct
name|sysentvec
name|aout_sysvec
init|=
block|{
name|SYS_MAXSYSCALL
block|,
name|sysent
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|sendsig
block|,
name|sigcode
block|,
operator|&
name|szsigcode
block|,
literal|0
block|,
literal|"FreeBSD a.out"
block|}
decl_stmt|;
end_decl_stmt

end_unit

