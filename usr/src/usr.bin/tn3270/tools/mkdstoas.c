begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1988 Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
literal|"@(#)mkdstoas.c	4.1 (Berkeley) 12/4/88"
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
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|unix
argument_list|)
end_if

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(unix) */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(unix) */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"../api/asc_ebc.h"
end_include

begin_include
include|#
directive|include
file|"../api/ebc_disp.h"
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
comment|/* For each display code, find the ascii code that matches */
name|printf
argument_list|(
literal|"unsigned char disp_asc[256] = {"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
name|disp_ebc
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|i
operator|%
literal|8
operator|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\t0x%02x,"
argument_list|,
name|ebc_asc
index|[
name|disp_ebc
index|[
name|i
index|]
index|]
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
sizeof|sizeof
name|disp_ebc
init|;
name|i
operator|<
literal|256
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|i
operator|%
literal|8
operator|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\t0x%02x,"
argument_list|,
literal|' '
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n};\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

