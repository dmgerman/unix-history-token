begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Long story short: aclocal.m4 depends on autoconf 2.13  * implementation details wrt "const"; newer versions  * have different implementation details so for now we  * put "const" here.  This may cause duplicate definitions  * in config.h but that should be OK since they're the same.  */
end_comment

begin_undef
undef|#
directive|undef
name|const
end_undef

end_unit

