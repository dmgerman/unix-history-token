begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: stime.c,v 1.6 1997/05/02 14:29:20 assar Exp $  *  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  */
end_comment

begin_include
include|#
directive|include
file|"krb_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: stime.c,v 1.6 1997/05/02 14:29:20 assar Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Given a pointer to a long containing the number of seconds  * since the beginning of time (midnight 1 Jan 1970 GMT), return  * a string containing the local time in the form:  *  * "25-Jan-1988 10:17:56"  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|krb_stime
parameter_list|(
name|time_t
modifier|*
name|t
parameter_list|)
block|{
specifier|static
name|char
name|st
index|[
literal|40
index|]
decl_stmt|;
name|struct
name|tm
modifier|*
name|tm
decl_stmt|;
name|tm
operator|=
name|localtime
argument_list|(
name|t
argument_list|)
expr_stmt|;
name|snprintf
argument_list|(
name|st
argument_list|,
sizeof|sizeof
argument_list|(
name|st
argument_list|)
argument_list|,
literal|"%2d-%s-%04d %02d:%02d:%02d"
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
operator|+
literal|1900
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

