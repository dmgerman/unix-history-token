begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: month_sname.c,v 4.4 88/11/15 16:39:32 jtkohl Exp $  * $FreeBSD$  */
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
unit|static char *rcsid = "$FreeBSD$";
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

begin_comment
comment|/*  * Given an integer 1-12, month_sname() returns a string  * containing the first three letters of the corresponding  * month.  Returns 0 if the argument is out of range.  */
end_comment

begin_function
name|char
modifier|*
name|month_sname
parameter_list|(
name|n
parameter_list|)
name|int
name|n
decl_stmt|;
block|{
specifier|static
name|char
modifier|*
name|name
index|[]
init|=
block|{
literal|"Jan"
block|,
literal|"Feb"
block|,
literal|"Mar"
block|,
literal|"Apr"
block|,
literal|"May"
block|,
literal|"Jun"
block|,
literal|"Jul"
block|,
literal|"Aug"
block|,
literal|"Sep"
block|,
literal|"Oct"
block|,
literal|"Nov"
block|,
literal|"Dec"
block|}
decl_stmt|;
return|return
operator|(
operator|(
name|n
operator|<
literal|1
operator|||
name|n
operator|>
literal|12
operator|)
condition|?
literal|0
else|:
name|name
index|[
name|n
operator|-
literal|1
index|]
operator|)
return|;
block|}
end_function

end_unit

