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
literal|"@(#)RANG4.c	1.6 (Berkeley) 4/9/90"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_decl_stmt
name|char
name|ERANG
index|[]
init|=
literal|"Value of %D is out of range\n"
decl_stmt|;
end_decl_stmt

begin_function
name|long
name|RANG4
parameter_list|(
name|value
parameter_list|,
name|lower
parameter_list|,
name|upper
parameter_list|)
name|long
name|value
decl_stmt|;
name|long
name|lower
decl_stmt|;
name|long
name|upper
decl_stmt|;
block|{
if|if
condition|(
name|value
operator|<
name|lower
operator|||
name|value
operator|>
name|upper
condition|)
block|{
name|ERROR
argument_list|(
name|ERANG
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
return|return
name|value
return|;
block|}
end_function

end_unit

