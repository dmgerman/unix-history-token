begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define if you have MIT Kerberos version 4 available.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_KERBEROS
end_undef

begin_comment
comment|/* Define if you want CVS to be able to be a remote repository client.  */
end_comment

begin_undef
undef|#
directive|undef
name|CLIENT_SUPPORT
end_undef

begin_comment
comment|/* Define if you want CVS to be able to serve repositories to remote    clients.  */
end_comment

begin_undef
undef|#
directive|undef
name|SERVER_SUPPORT
end_undef

begin_comment
comment|/* Define if you want to use the password authenticated server.  */
end_comment

begin_undef
undef|#
directive|undef
name|AUTH_SERVER_SUPPORT
end_undef

begin_comment
comment|/* Define if you want encryption support.  */
end_comment

begin_undef
undef|#
directive|undef
name|ENCRYPTION
end_undef

begin_comment
comment|/* Define if you have the connect function.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_CONNECT
end_undef

begin_comment
comment|/* Define if this system supports chown(), link(), and friends.  */
end_comment

begin_undef
undef|#
directive|undef
name|PRESERVE_PERMISSIONS_SUPPORT
end_undef

begin_comment
comment|/* Define if you have memchr (always for CVS).  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_MEMCHR
end_undef

begin_comment
comment|/* Define if you have strchr (always for CVS).  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_STRCHR
end_undef

begin_comment
comment|/* Define if utime requires write access to the file (true on Windows,    but not Unix).  */
end_comment

begin_undef
undef|#
directive|undef
name|UTIME_EXPECTS_WRITABLE
end_undef

begin_comment
comment|/* Define if setmode is required when writing binary data to stdout.  */
end_comment

begin_undef
undef|#
directive|undef
name|USE_SETMODE_STDOUT
end_undef

begin_comment
comment|/* Define if the diff library should use setmode for binary files.    FIXME: Why two different macros for setmode?  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SETMODE
end_undef

begin_comment
comment|/* Define if you have the crypt function.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_CRYPT
end_undef

begin_comment
comment|/* Define if you have the getspnam function.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GETSPNAM
end_undef

begin_comment
comment|/* Define to force lib/regex.c to use malloc instead of alloca.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGEX_MALLOC
end_undef

begin_comment
comment|/* Define to force lib/regex.c to define re_comp et al.  */
end_comment

begin_undef
undef|#
directive|undef
name|_REGEX_RE_COMP
end_undef

end_unit

