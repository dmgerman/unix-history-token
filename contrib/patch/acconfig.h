begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Local acconfig.h for autoheader.    Descriptive text for the C preprocessor macros that    the patch configure.in can define.    autoheader copies the comments into config.hin.  */
end_comment

begin_comment
comment|/* Define if there is a member named d_ino in the struct describing    directory headers.  */
end_comment

begin_undef
undef|#
directive|undef
name|D_INO_IN_DIRENT
end_undef

begin_comment
comment|/* Define if memchr works.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_MEMCHR
end_undef

begin_comment
comment|/* Define if `struct utimbuf' is declared -- usually in<utime.h>.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_STRUCT_UTIMBUF
end_undef

end_unit

