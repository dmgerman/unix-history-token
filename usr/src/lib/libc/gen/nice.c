begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)nice.c	5.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_comment
comment|/*  * Backwards compatible nice.  */
end_comment

begin_macro
name|nice
argument_list|(
argument|incr
argument_list|)
end_macro

begin_decl_stmt
name|int
name|incr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|prio
decl_stmt|;
specifier|extern
name|int
name|errno
decl_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
name|prio
operator|=
name|getpriority
argument_list|(
name|PRIO_PROCESS
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|prio
operator|==
operator|-
literal|1
operator|&&
name|errno
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
name|setpriority
argument_list|(
name|PRIO_PROCESS
argument_list|,
literal|0
argument_list|,
name|prio
operator|+
name|incr
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

