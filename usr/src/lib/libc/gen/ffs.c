begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)ffs.c	5.2 (Berkeley) 6/27/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_comment
comment|/*  * ffs -- vax ffs instruction  */
end_comment

begin_expr_stmt
name|ffs
argument_list|(
name|mask
argument_list|)
specifier|register
name|long
name|mask
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|cnt
decl_stmt|;
if|if
condition|(
name|mask
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
for|for
control|(
name|cnt
operator|=
literal|1
init|;
operator|!
operator|(
name|mask
operator|&
literal|1
operator|)
condition|;
name|cnt
operator|++
control|)
name|mask
operator|>>=
literal|1
expr_stmt|;
return|return
operator|(
name|cnt
operator|)
return|;
block|}
end_block

end_unit

