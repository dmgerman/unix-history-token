begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* acconfig.h: Extra commentary for Autoheader  %%% portions-copyright-cmetz-96 Portions of this software are Copyright 1996-1997 by Craig Metz, All Rights Reserved. The Inner Net License Version 2 applies to these portions of the software. You should have received a copy of the license with this software. If you didn't get a copy, you may request one from<license@inner.net>.  /* Define if the closedir function returns void instead of int.  */
end_comment

begin_undef
undef|#
directive|undef
name|CLOSEDIR_VOID
end_undef

begin_comment
comment|/* Define if you want the FTP daemon to support anonymous logins. */
end_comment

begin_undef
undef|#
directive|undef
name|DOANONYMOUS
end_undef

begin_comment
comment|/* The default value of the PATH environment variable */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_PATH
end_undef

begin_comment
comment|/* Defined if the file /etc/default/login exists     (and, presumably, should be looked at by login) */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ETC_DEFAULT_LOGIN
end_undef

begin_comment
comment|/* Defined to the name of a file that contains a list of files whose    permissions and ownerships should be changed on login. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_LOGIN_PERMFILE
end_undef

begin_comment
comment|/* Defined to the name of a file that contains a list of environment    values that should be set on login. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_LOGIN_ENVFILE
end_undef

begin_comment
comment|/* Defined if the file /etc/securetty exists    (and, presumably, should be looked at by login) */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SECURETTY
end_undef

begin_comment
comment|/* Defined if the file /etc/shadow exists    (and, presumably, should be looked at for shadow passwords) */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ETC_SHADOW
end_undef

begin_comment
comment|/* The path to the access file, if we're going to use it */
end_comment

begin_undef
undef|#
directive|undef
name|PATH_ACCESS_FILE
end_undef

begin_comment
comment|/* The path to the mail spool, if we know it */
end_comment

begin_undef
undef|#
directive|undef
name|PATH_MAIL
end_undef

begin_comment
comment|/* The path to the utmp file, if we know it */
end_comment

begin_undef
undef|#
directive|undef
name|PATH_UTMP_AC
end_undef

begin_comment
comment|/* The path to the utmpx file, if we know it */
end_comment

begin_undef
undef|#
directive|undef
name|PATH_UTMPX_AC
end_undef

begin_comment
comment|/* The path to the wtmp file, if we know it */
end_comment

begin_undef
undef|#
directive|undef
name|PATH_WTMP_AC
end_undef

begin_comment
comment|/* The path to the wtmpx file, if we know it */
end_comment

begin_undef
undef|#
directive|undef
name|PATH_WTMPX_AC
end_undef

begin_comment
comment|/* Defined if the system's profile (/etc/profile) displays    the motd file */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_MOTD_IN_PROFILE
end_undef

begin_comment
comment|/* Defined if the system's profile (/etc/profile) informs the    user of new mail */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_MAILCHECK_IN_PROFILE
end_undef

begin_comment
comment|/* Define if you have a nonstandard gettimeofday() that takes one argument    instead of two. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ONE_ARG_GETTIMEOFDAY
end_undef

begin_comment
comment|/* Define if the system has the getenv function */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GETENV
end_undef

begin_comment
comment|/* Define if the system has the setenv function */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SETENV
end_undef

begin_comment
comment|/* Define if the system has the /var/adm/sulog file */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SULOG
end_undef

begin_comment
comment|/* Define if the system has the unsetenv function */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_UNSETENV
end_undef

begin_comment
comment|/* Define if the compiler can handle ANSI-style argument lists */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ANSIDECL
end_undef

begin_comment
comment|/* Define if the compiler can handle ANSI-style prototypes */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ANSIPROTO
end_undef

begin_comment
comment|/* Define if the system has an ANSI-style printf (returns int instead of char *) */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ANSISPRINTF
end_undef

begin_comment
comment|/* Define if the compiler can handle ANSI-style variable argument lists */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ANSISTDARG
end_undef

begin_comment
comment|/* Define if the compiler can handle void argument lists to functions */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_VOIDARG
end_undef

begin_comment
comment|/* Define if the compiler can handle void return "values" from functions */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_VOIDRET
end_undef

begin_comment
comment|/* Define if the compiler can handle void pointers to our liking */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_VOIDPTR
end_undef

begin_comment
comment|/* Define if the /bin/ls command seems to support the -g flag */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_LS_G_FLAG
end_undef

begin_comment
comment|/* Define if there is a ut_pid field in struct utmp */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_UT_PID
end_undef

begin_comment
comment|/* Define if there is a ut_type field in struct utmp */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_UT_TYPE
end_undef

begin_comment
comment|/* Define if there is a ut_user field in struct utmp */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_UT_USER
end_undef

begin_comment
comment|/* Define if there is a ut_name field in struct utmp */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_UT_NAME
end_undef

begin_comment
comment|/* Define if there is a ut_host field in struct utmp */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_UT_HOST
end_undef

begin_comment
comment|/* Define if the system has getutline() */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GETUTLINE
end_undef

begin_comment
comment|/* Defined if the system has SunOS C2 security shadow passwords */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SUNOS_C2_SHADOW
end_undef

begin_comment
comment|/* Defined if you want to disable utmp support */
end_comment

begin_undef
undef|#
directive|undef
name|DISABLE_UTMP
end_undef

begin_comment
comment|/* Defined if you want to disable wtmp support */
end_comment

begin_undef
undef|#
directive|undef
name|DISABLE_WTMP
end_undef

begin_comment
comment|/* Defined if you want to allow users to override the insecure checks */
end_comment

begin_undef
undef|#
directive|undef
name|INSECURE_OVERRIDE
end_undef

begin_comment
comment|/* Defined to the default hash value, always defined */
end_comment

begin_undef
undef|#
directive|undef
name|MDX
end_undef

begin_comment
comment|/* Defined if new-style prompts are to be used */
end_comment

begin_undef
undef|#
directive|undef
name|NEW_PROMPTS
end_undef

begin_comment
comment|/* Defined to the path of the OPIE lock directory */
end_comment

begin_undef
undef|#
directive|undef
name|OPIE_LOCK_DIR
end_undef

begin_comment
comment|/* Defined if users are to be asked to re-type secret pass phrases */
end_comment

begin_undef
undef|#
directive|undef
name|RETYPE
end_undef

begin_comment
comment|/* Defined if su should not switch to disabled accounts */
end_comment

begin_undef
undef|#
directive|undef
name|SU_STAR_CHECK
end_undef

begin_comment
comment|/* Defined if user locking is to be used */
end_comment

begin_undef
undef|#
directive|undef
name|USER_LOCKING
end_undef

end_unit

