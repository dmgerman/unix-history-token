begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2002 Sendmail, Inc. and its suppliers.  *      All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  */
end_comment

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_macro
name|SM_RCSID
argument_list|(
literal|"@(#)$Id: t-event.c,v 1.9 2002/03/19 00:26:21 ca Exp $"
argument_list|)
end_macro

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_if
if|#
directive|if
name|SM_CONF_SETITIMER
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_SETITIMER */
end_comment

begin_include
include|#
directive|include
file|<sm/clock.h>
end_include

begin_include
include|#
directive|include
file|<sm/test.h>
end_include

begin_decl_stmt
name|int
name|check
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|evcheck
parameter_list|(
name|arg
parameter_list|)
name|int
name|arg
decl_stmt|;
block|{
name|SM_TEST
argument_list|(
name|arg
operator|==
literal|3
argument_list|)
expr_stmt|;
name|SM_TEST
argument_list|(
name|check
operator|==
literal|0
argument_list|)
expr_stmt|;
name|check
operator|++
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ev1
parameter_list|(
name|arg
parameter_list|)
name|int
name|arg
decl_stmt|;
block|{
name|SM_TEST
argument_list|(
name|arg
operator|==
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* define as x if you want debug output */
end_comment

begin_define
define|#
directive|define
name|DBG_OUT
parameter_list|(
name|x
parameter_list|)
end_define

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
name|SM_EVENT
modifier|*
name|ev
decl_stmt|;
name|sm_test_begin
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"test event handling"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"This test may hang. If there is no output within twelve seconds, abort it\nand recompile with -DSM_CONF_SETITIMER=%d\n"
argument_list|,
name|SM_CONF_SETITIMER
operator|==
literal|0
condition|?
literal|1
else|:
literal|0
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|SM_TEST
argument_list|(
literal|1
operator|==
literal|1
argument_list|)
expr_stmt|;
name|DBG_OUT
argument_list|(
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"We're back, test 1 seems to work.\n"
argument_list|)
argument_list|)
expr_stmt|;
name|ev
operator|=
name|sm_seteventm
argument_list|(
literal|1000
argument_list|,
name|ev1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|SM_TEST
argument_list|(
literal|2
operator|==
literal|2
argument_list|)
expr_stmt|;
name|DBG_OUT
argument_list|(
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"We're back, test 2 seems to work.\n"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* schedule an event in 9s */
name|ev
operator|=
name|sm_seteventm
argument_list|(
literal|9000
argument_list|,
name|ev1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* clear the event before it can fire */
name|sm_clrevent
argument_list|(
name|ev
argument_list|)
expr_stmt|;
name|SM_TEST
argument_list|(
literal|3
operator|==
literal|3
argument_list|)
expr_stmt|;
name|DBG_OUT
argument_list|(
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"We're back, test 3 seems to work.\n"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* schedule an event in 1s */
name|check
operator|=
literal|0
expr_stmt|;
name|ev
operator|=
name|sm_seteventm
argument_list|(
literal|1000
argument_list|,
name|evcheck
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|/* clear the event */
name|sm_clrevent
argument_list|(
name|ev
argument_list|)
expr_stmt|;
name|SM_TEST
argument_list|(
literal|4
operator|==
literal|4
argument_list|)
expr_stmt|;
name|SM_TEST
argument_list|(
name|check
operator|==
literal|1
argument_list|)
expr_stmt|;
name|DBG_OUT
argument_list|(
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"We're back, test 4 seems to work.\n"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|sm_test_end
argument_list|()
return|;
block|}
end_function

end_unit

