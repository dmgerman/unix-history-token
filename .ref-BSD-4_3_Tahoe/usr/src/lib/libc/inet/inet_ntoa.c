begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)inet_ntoa.c	5.4 (Berkeley) 6/27/88"
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
comment|/*  * Convert network-format internet address  * to base 256 d.d.d.d representation.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_function
name|char
modifier|*
name|inet_ntoa
parameter_list|(
name|in
parameter_list|)
name|struct
name|in_addr
name|in
decl_stmt|;
block|{
specifier|static
name|char
name|b
index|[
literal|18
index|]
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
name|p
operator|=
operator|(
name|char
operator|*
operator|)
operator|&
name|in
expr_stmt|;
define|#
directive|define
name|UC
parameter_list|(
name|b
parameter_list|)
value|(((int)b)&0xff)
name|sprintf
argument_list|(
name|b
argument_list|,
literal|"%d.%d.%d.%d"
argument_list|,
name|UC
argument_list|(
name|p
index|[
literal|0
index|]
argument_list|)
argument_list|,
name|UC
argument_list|(
name|p
index|[
literal|1
index|]
argument_list|)
argument_list|,
name|UC
argument_list|(
name|p
index|[
literal|2
index|]
argument_list|)
argument_list|,
name|UC
argument_list|(
name|p
index|[
literal|3
index|]
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|b
operator|)
return|;
block|}
end_function

end_unit

