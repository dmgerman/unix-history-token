begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: stime.c,v 4.5 88/11/15 16:58:05 jtkohl Exp $  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* for sprintf() */
end_comment

begin_comment
comment|/*  * Given a pointer to a long containing the number of seconds  * since the beginning of time (midnight 1 Jan 1970 GMT), return  * a string containing the local time in the form:  *  * "25-Jan-88 10:17:56"  */
end_comment

begin_function
name|char
modifier|*
name|stime
parameter_list|(
name|t
parameter_list|)
name|long
modifier|*
name|t
decl_stmt|;
block|{
specifier|static
name|char
name|st_data
index|[
literal|40
index|]
decl_stmt|;
specifier|static
name|char
modifier|*
name|st
init|=
name|st_data
decl_stmt|;
name|struct
name|tm
modifier|*
name|tm
decl_stmt|;
name|char
modifier|*
name|month_sname
parameter_list|()
function_decl|;
name|tm
operator|=
name|localtime
argument_list|(
name|t
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|st
argument_list|,
literal|"%2d-%s-%02d %02d:%02d:%02d"
argument_list|,
name|tm
operator|->
name|tm_mday
argument_list|,
name|month_sname
argument_list|(
name|tm
operator|->
name|tm_mon
operator|+
literal|1
argument_list|)
argument_list|,
name|tm
operator|->
name|tm_year
argument_list|,
name|tm
operator|->
name|tm_hour
argument_list|,
name|tm
operator|->
name|tm_min
argument_list|,
name|tm
operator|->
name|tm_sec
argument_list|)
expr_stmt|;
return|return
name|st
return|;
block|}
end_function

end_unit

