begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)kern_xxx.c	7.13 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"user.h"
end_include

begin_include
include|#
directive|include
file|"kernel.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"reboot.h"
end_include

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
name|void
modifier|*
name|uap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
modifier|*
name|retval
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
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

begin_struct
struct|struct
name|args
block|{
name|long
name|hostid
decl_stmt|;
block|}
modifier|*
name|uap
struct|;
end_struct

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

begin_struct
struct|struct
name|args
block|{
name|char
modifier|*
name|hostname
decl_stmt|;
name|u_int
name|len
decl_stmt|;
block|}
modifier|*
name|uap
struct|;
end_struct

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

begin_struct
specifier|register
struct|struct
name|args
block|{
name|char
modifier|*
name|hostname
decl_stmt|;
name|u_int
name|len
decl_stmt|;
block|}
modifier|*
name|uap
struct|;
end_struct

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
name|u
operator|.
name|u_cred
argument_list|,
operator|&
name|u
operator|.
name|u_acflag
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

begin_struct
struct|struct
name|args
block|{
name|int
name|opt
decl_stmt|;
block|}
modifier|*
name|uap
struct|;
end_struct

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

begin_macro
name|ovhangup
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
end_block

begin_macro
name|oldquota
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
end_block

end_unit

