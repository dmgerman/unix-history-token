begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tm2ut.c - tm to time string */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: /f/osi/psap/RCS/tm2ut.c,v 7.1 91/02/22 09:37:15 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/tm2ut.c,v 7.1 91/02/22 09:37:15 mrose Interim $  *  *  * $Log:	tm2ut.c,v $  * Revision 7.1  91/02/22  09:37:15  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:13:54  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"psap.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|OSX
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|YEAR
parameter_list|(
name|y
parameter_list|)
value|((y)>= 100 ? (y) : (y) + 1900)
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|void
name|tm2ut
parameter_list|(
name|tm
parameter_list|,
name|ut
parameter_list|)
specifier|register
name|struct
name|tm
modifier|*
name|tm
decl_stmt|;
specifier|register
name|UTC
name|ut
decl_stmt|;
block|{
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|ut
argument_list|,
sizeof|sizeof
expr|*
name|ut
argument_list|)
expr_stmt|;
name|ut
operator|->
name|ut_year
operator|=
name|YEAR
argument_list|(
name|tm
operator|->
name|tm_year
argument_list|)
expr_stmt|;
name|ut
operator|->
name|ut_mon
operator|=
name|tm
operator|->
name|tm_mon
operator|+
literal|1
expr_stmt|;
name|ut
operator|->
name|ut_mday
operator|=
name|tm
operator|->
name|tm_mday
expr_stmt|;
name|ut
operator|->
name|ut_hour
operator|=
name|tm
operator|->
name|tm_hour
expr_stmt|;
name|ut
operator|->
name|ut_min
operator|=
name|tm
operator|->
name|tm_min
expr_stmt|;
name|ut
operator|->
name|ut_sec
operator|=
name|tm
operator|->
name|tm_sec
expr_stmt|;
name|ut
operator|->
name|ut_zone
operator|=
literal|0
expr_stmt|;
name|ut
operator|->
name|ut_flags
operator|=
name|UT_ZONE
operator||
name|UT_SEC
expr_stmt|;
block|}
end_function

end_unit

