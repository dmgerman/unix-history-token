begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|dprintf
value|if (Debug) fprintf
end_define

begin_define
define|#
directive|define
name|TIMEOUT
value|3600
end_define

begin_comment
comment|/* seconds to read timeout in sfgets */
end_comment

begin_comment
comment|/* in goodbye() wait (or not) for QUIT response */
end_comment

begin_define
define|#
directive|define
name|WAIT
value|1
end_define

begin_define
define|#
directive|define
name|DONT_WAIT
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FAIL
end_ifndef

begin_define
define|#
directive|define
name|FAIL
value|(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

