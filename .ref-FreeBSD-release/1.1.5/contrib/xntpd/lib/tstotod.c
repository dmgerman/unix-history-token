begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|ELIMINATE
end_ifdef

begin_comment
comment|/* tstotod.c,v 3.1 1993/07/06 01:08:48 jbj Exp  * tstotod - compute calendar time given an NTP timestamp  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_calendar.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_function
name|void
name|tstotod
parameter_list|(
name|ts
parameter_list|,
name|tod
parameter_list|)
name|l_fp
modifier|*
name|ts
decl_stmt|;
name|struct
name|calendar
modifier|*
name|tod
decl_stmt|;
block|{
specifier|register
name|U_LONG
name|cyclesecs
decl_stmt|;
name|cyclesecs
operator|=
name|ts
operator|.
name|l_ui
operator|-
name|MAR_1900
expr_stmt|;
comment|/* bump forward to March 1900 */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ELIMINATE */
end_comment

end_unit

