begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* XXX: Depend on our system headers protecting against multiple includes. */
end_comment

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_undef
undef|#
directive|undef
name|_PATH_FTPUSERS
end_undef

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_define
define|#
directive|define
name|LOGIN_NAME_MAX
value|MAXLOGNAME
end_define

begin_comment
comment|/*<sys/param.h> */
end_comment

begin_define
define|#
directive|define
name|_DIAGASSERT
parameter_list|(
name|x
parameter_list|)
end_define

end_unit

