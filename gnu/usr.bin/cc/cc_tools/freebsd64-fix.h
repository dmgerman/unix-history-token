begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * config/i386/freebsd64.h neglects to override the default bogus mcount  * function name.  In order to avoid touching vendor source while gcc3.4  * is in progress, try a minimal workaround.  *  * $FreeBSD$  */
end_comment

begin_undef
undef|#
directive|undef
name|MCOUNT_NAME
end_undef

begin_define
define|#
directive|define
name|MCOUNT_NAME
value|".mcount"
end_define

end_unit

