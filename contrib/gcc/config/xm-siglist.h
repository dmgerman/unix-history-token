begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Some systems provide no sys_siglist, but do offer the same data under    another name.  */
end_comment

begin_define
define|#
directive|define
name|sys_siglist
value|_sys_siglist
end_define

begin_undef
undef|#
directive|undef
name|SYS_SIGLIST_DECLARED
end_undef

begin_define
define|#
directive|define
name|SYS_SIGLIST_DECLARED
end_define

end_unit

