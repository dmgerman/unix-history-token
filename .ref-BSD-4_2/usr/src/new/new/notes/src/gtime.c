begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)gtime.c	1.1\t1/23/83"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"parms.h"
end_include

begin_include
include|#
directive|include
file|"structs.h"
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/*  * gettime(whenvec) struct when_f *whenvec; {}  *  *    fills in whenvec with the most uptodate time  *  *	Rob Kolstad Winter 1980  */
end_comment

begin_macro
name|gettime
argument_list|(
argument|whenvec
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|when_f
modifier|*
name|whenvec
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|long
name|tvec
decl_stmt|;
name|struct
name|tm
modifier|*
name|ovec
decl_stmt|;
name|struct
name|tm
modifier|*
name|localtime
parameter_list|()
function_decl|;
name|time
argument_list|(
operator|&
name|tvec
argument_list|)
expr_stmt|;
comment|/* get the funky number */
name|ovec
operator|=
name|localtime
argument_list|(
operator|&
name|tvec
argument_list|)
expr_stmt|;
comment|/* convert to local time */
name|whenvec
operator|->
name|w_mins
operator|=
name|ovec
operator|->
name|tm_min
expr_stmt|;
name|whenvec
operator|->
name|w_hours
operator|=
name|ovec
operator|->
name|tm_hour
expr_stmt|;
name|whenvec
operator|->
name|w_day
operator|=
name|ovec
operator|->
name|tm_mday
expr_stmt|;
name|whenvec
operator|->
name|w_month
operator|=
name|ovec
operator|->
name|tm_mon
operator|+
literal|1
expr_stmt|;
comment|/* jan= 0 as supplied, correct it */
name|whenvec
operator|->
name|w_year
operator|=
name|ovec
operator|->
name|tm_year
operator|+
literal|1900
expr_stmt|;
comment|/* all from CTIME (III) */
block|}
end_block

end_unit

