begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_ifdef
ifdef|#
directive|ifdef
name|RCSIDENT
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Header: gtime.c,v 1.7 85/01/18 15:12:21 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  * gettime(whenvec) struct when_f *whenvec; {}  *  *    fills in whenvec with the most uptodate time  *  *	Rob Kolstad Winter 1980  *	Modified to split getting and formatting time  *			Malcolm Slaney	March 1983  */
end_comment

begin_comment
comment|/*  *	4.2 Bsd moved the file!  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD42
end_ifndef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
endif|!BSD42
end_endif

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
name|time
argument_list|(
operator|&
name|tvec
argument_list|)
expr_stmt|;
comment|/* get the funky number */
return|return
operator|(
name|maketime
argument_list|(
name|whenvec
argument_list|,
name|tvec
argument_list|)
operator|)
return|;
block|}
end_block

begin_macro
name|maketime
argument_list|(
argument|whenvec
argument_list|,
argument|tvec
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|when_f
modifier|*
name|whenvec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|tvec
decl_stmt|;
end_decl_stmt

begin_block
block|{
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
name|whenvec
operator|->
name|w_gmttime
operator|=
name|tvec
expr_stmt|;
block|}
end_block

end_unit

