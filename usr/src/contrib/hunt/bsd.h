begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Hunt  *  Copyright (c) 1985 Conrad C. Huang, Gregory S. Couch, Kenneth C.R.C. Arnold  *  San Francisco, California  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD_RELEASE
argument_list|)
operator|&&
name|BSD_RELEASE
operator|>=
literal|43
end_if

begin_define
define|#
directive|define
name|BROADCAST
end_define

begin_define
define|#
directive|define
name|SYSLOG_43
end_define

begin_define
define|#
directive|define
name|TALK_43
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD_RELEASE
argument_list|)
operator|&&
name|BSD_RELEASE
operator|==
literal|42
end_if

begin_define
define|#
directive|define
name|SYSLOG_42
end_define

begin_define
define|#
directive|define
name|TALK_42
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

