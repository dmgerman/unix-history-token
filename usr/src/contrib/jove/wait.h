begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD_WAIT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_define
define|#
directive|define
name|w_termsignum
parameter_list|(
name|w
parameter_list|)
value|((w).w_termsig)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WIFSTOPPED
parameter_list|(
name|w
parameter_list|)
value|(((w).w_status& 0377) == 0177)
end_define

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|w
parameter_list|)
value|(((w).w_status& 0377) == 0)
end_define

begin_define
define|#
directive|define
name|WIFSIGNALED
parameter_list|(
name|w
parameter_list|)
value|((((w).w_status>> 8)& 0377) == 0)
end_define

begin_define
define|#
directive|define
name|w_termsignum
parameter_list|(
name|w
parameter_list|)
value|((w).w_status& 0177)
end_define

begin_define
define|#
directive|define
name|wait2
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|)
value|wait(w)
end_define

begin_union
union|union
name|wait
block|{
name|int
name|w_status
decl_stmt|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|kill_off
name|proto
argument_list|(
operator|(
name|int
operator|,
expr|union
name|wait
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

