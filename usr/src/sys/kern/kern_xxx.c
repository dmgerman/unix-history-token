begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)kern_xxx.c	7.20 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_decl_stmt
name|char
name|hostname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hostnamelen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|hostid
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|gethostid_args
block|{
name|int
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|gethostid
argument_list|(
argument|p
argument_list|,
argument|uap
argument_list|,
argument|retval
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|gethostid_args
modifier|*
name|uap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|retval
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
operator|(
name|long
operator|*
operator|)
name|retval
operator|=
name|hostid
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_struct
struct|struct
name|sethostid_args
block|{
name|long
name|hostid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|sethostid
argument_list|(
argument|p
argument_list|,
argument|uap
argument_list|,
argument|retval
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sethostid_args
modifier|*
name|uap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|retval
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|error
decl_stmt|;
block|}
end_block

begin_struct
struct|struct
name|gethostname_args
block|{
name|char
modifier|*
name|hostname
decl_stmt|;
name|u_int
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|gethostname
argument_list|(
argument|p
argument_list|,
argument|uap
argument_list|,
argument|retval
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|gethostname_args
modifier|*
name|uap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|retval
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|uap
operator|->
name|len
operator|>
name|hostnamelen
operator|+
literal|1
condition|)
name|uap
operator|->
name|len
operator|=
name|hostnamelen
operator|+
literal|1
expr_stmt|;
return|return
operator|(
name|copyout
argument_list|(
operator|(
name|caddr_t
operator|)
name|hostname
argument_list|,
operator|(
name|caddr_t
operator|)
name|uap
operator|->
name|hostname
argument_list|,
name|uap
operator|->
name|len
argument_list|)
operator|)
return|;
block|}
end_block

begin_struct
struct|struct
name|sethostname_args
block|{
name|char
modifier|*
name|hostname
decl_stmt|;
name|u_int
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|sethostname
argument_list|(
argument|p
argument_list|,
argument|uap
argument_list|,
argument|retval
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|struct
name|sethostname_args
modifier|*
name|uap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|retval
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|error
decl_stmt|;
if|if
condition|(
name|error
operator|=
name|suser
argument_list|(
name|p
operator|->
name|p_ucred
argument_list|,
operator|&
name|p
operator|->
name|p_acflag
argument_list|)
condition|)
return|return
operator|(
name|error
operator|)
return|;
if|if
condition|(
name|uap
operator|->
name|len
operator|>
sizeof|sizeof
argument_list|(
name|hostname
argument_list|)
operator|-
literal|1
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
name|hostnamelen
operator|=
name|uap
operator|->
name|len
expr_stmt|;
name|error
operator|=
name|copyin
argument_list|(
operator|(
name|caddr_t
operator|)
name|uap
operator|->
name|hostname
argument_list|,
name|hostname
argument_list|,
name|uap
operator|->
name|len
argument_list|)
expr_stmt|;
name|hostname
index|[
name|hostnamelen
index|]
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_block

begin_struct
struct|struct
name|reboot_args
block|{
name|int
name|opt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|reboot
argument_list|(
argument|p
argument_list|,
argument|uap
argument_list|,
argument|retval
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|reboot_args
modifier|*
name|uap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|retval
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|error
decl_stmt|;
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_43
end_ifdef

begin_macro
name|oquota
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

