begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1987, 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: fgetst.c,v 4.0 89/01/23 10:08:31 jtkohl Exp $  * $FreeBSD$  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_endif
unit|static char rcsid[] = "$FreeBSD$";
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  * fgetst takes a file descriptor, a character pointer, and a count.  * It reads from the file it has either read "count" characters, or  * until it reads a null byte.  When finished, what has been read exists  * in "s". If "count" characters were actually read, the last is changed  * to a null, so the returned string is always null-terminated.  fgetst  * returns the number of characters read, including the null terminator.  */
end_comment

begin_function
name|int
name|fgetst
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
name|FILE
modifier|*
name|f
decl_stmt|;
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|n
decl_stmt|;
block|{
specifier|register
name|int
name|count
init|=
name|n
decl_stmt|;
name|int
name|ch
decl_stmt|;
comment|/* NOT char; otherwise you don't see EOF */
while|while
condition|(
operator|(
name|ch
operator|=
name|getc
argument_list|(
name|f
argument_list|)
operator|)
operator|!=
name|EOF
operator|&&
name|ch
operator|&&
operator|--
name|count
condition|)
block|{
operator|*
name|s
operator|++
operator|=
name|ch
expr_stmt|;
block|}
operator|*
name|s
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|n
operator|-
name|count
operator|)
return|;
block|}
end_function

end_unit

