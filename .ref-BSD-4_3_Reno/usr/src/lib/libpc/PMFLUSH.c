begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)PMFLUSH.c	1.4 (Berkeley) 4/9/90"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_macro
name|PMFLUSH
argument_list|(
argument|cntrs
argument_list|,
argument|rtns
argument_list|,
argument|bufaddr
argument_list|)
end_macro

begin_decl_stmt
name|long
name|cntrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total number of counters (stmt + routine) */
end_comment

begin_decl_stmt
name|long
name|rtns
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of func and proc counters */
end_comment

begin_decl_stmt
name|long
modifier|*
name|bufaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* address of count buffers */
end_comment

begin_block
block|{
specifier|register
name|FILE
modifier|*
name|filep
decl_stmt|;
name|bufaddr
index|[
literal|0
index|]
operator|=
literal|0426
expr_stmt|;
name|time
argument_list|(
operator|&
name|bufaddr
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|bufaddr
index|[
literal|2
index|]
operator|=
name|cntrs
expr_stmt|;
name|bufaddr
index|[
literal|3
index|]
operator|=
name|rtns
expr_stmt|;
name|filep
operator|=
name|fopen
argument_list|(
name|PXPFILE
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
if|if
condition|(
name|filep
operator|==
name|NULL
condition|)
goto|goto
name|ioerr
goto|;
name|fwrite
argument_list|(
name|bufaddr
argument_list|,
call|(
name|int
call|)
argument_list|(
name|cntrs
operator|+
literal|1
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|long
argument_list|)
argument_list|,
name|filep
argument_list|)
expr_stmt|;
if|if
condition|(
name|ferror
argument_list|(
name|filep
argument_list|)
condition|)
goto|goto
name|ioerr
goto|;
name|fclose
argument_list|(
name|filep
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ferror
argument_list|(
name|filep
argument_list|)
condition|)
return|return;
name|ioerr
label|:
name|perror
argument_list|(
name|PXPFILE
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

