begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* Define if on AIX 3.    System headers sometimes define this.    We just want to avoid a redefinition error message.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALL_SOURCE
end_ifndef

begin_comment
comment|/* #undef _ALL_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if the closedir function returns void instead of int.  */
end_comment

begin_comment
comment|/* #undef CLOSEDIR_VOID */
end_comment

begin_comment
comment|/* Define to empty if the keyword does not work.  */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef gid_t */
end_comment

begin_comment
comment|/* Define if you support file names longer than 14 characters.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_FILE_NAMES
value|1
end_define

begin_comment
comment|/* Define if your struct stat has st_blksize.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ST_BLKSIZE
value|1
end_define

begin_comment
comment|/* Define if you have<sys/wait.h> that is POSIX.1 compatible.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define if utime(file, NULL) sets file's timestamp to the present.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIME_NULL
value|1
end_define

begin_comment
comment|/* Define if you have<vfork.h>.  */
end_comment

begin_comment
comment|/* #undef HAVE_VFORK_H */
end_comment

begin_comment
comment|/* Define if on MINIX.  */
end_comment

begin_comment
comment|/* #undef _MINIX */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef mode_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define if the system does not provide POSIX.1 features except    with this defined.  */
end_comment

begin_comment
comment|/* #undef _POSIX_1_SOURCE */
end_comment

begin_comment
comment|/* Define if you need to in order for stat and other things to work.  */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

begin_comment
comment|/* Define as the return type of signal handlers (int or void).  */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_comment
comment|/* Define to `unsigned' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* Define if the `S_IS*' macros in<sys/stat.h> do not work properly.  */
end_comment

begin_comment
comment|/* #undef STAT_MACROS_BROKEN */
end_comment

begin_comment
comment|/* Define if you have the ANSI C header files.  */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define if you can safely include both<sys/time.h> and<time.h>.  */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef uid_t */
end_comment

begin_comment
comment|/* Define vfork as fork if vfork does not work.  */
end_comment

begin_comment
comment|/* #undef vfork */
end_comment

begin_comment
comment|/* Define if you have MIT Kerberos version 4 available.  */
end_comment

begin_comment
comment|/* #undef HAVE_KERBEROS */
end_comment

begin_comment
comment|/* Define if you have GSSAPI with MIT Kerberos version 5 available.  */
end_comment

begin_comment
comment|/* #undef HAVE_GSSAPI */
end_comment

begin_comment
comment|/* Define if you want CVS to be able to be a remote repository client.  */
end_comment

begin_define
define|#
directive|define
name|CLIENT_SUPPORT
value|1
end_define

begin_comment
comment|/* Define if you want CVS to be able to serve repositories to remote    clients.  */
end_comment

begin_define
define|#
directive|define
name|SERVER_SUPPORT
value|1
end_define

begin_comment
comment|/* Define if you want to use the password authenticated server.  */
end_comment

begin_define
define|#
directive|define
name|AUTH_SERVER_SUPPORT
value|1
end_define

begin_comment
comment|/* Define if you want encryption support.  */
end_comment

begin_comment
comment|/* #undef ENCRYPTION */
end_comment

begin_comment
comment|/* Define if you have the connect function.  */
end_comment

begin_comment
comment|/* #undef HAVE_CONNECT */
end_comment

begin_comment
comment|/* Define if this system supports chown(), link(), and friends.  */
end_comment

begin_define
define|#
directive|define
name|PRESERVE_PERMISSIONS_SUPPORT
value|1
end_define

begin_comment
comment|/* Define if you have memchr (always for CVS).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCHR
value|1
end_define

begin_comment
comment|/* Define if you have strchr (always for CVS).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_comment
comment|/* Define if utime requires write access to the file (true on Windows,    but not Unix).  */
end_comment

begin_comment
comment|/* #undef UTIME_EXPECTS_WRITABLE */
end_comment

begin_comment
comment|/* Define if setmode is required when writing binary data to stdout.  */
end_comment

begin_comment
comment|/* #undef USE_SETMODE_STDOUT */
end_comment

begin_comment
comment|/* Define if the diff library should use setmode for binary files.    FIXME: Why two different macros for setmode?  */
end_comment

begin_comment
comment|/* #undef HAVE_SETMODE */
end_comment

begin_comment
comment|/* Define if you have the crypt function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CRYPT
value|1
end_define

begin_comment
comment|/* Define if you have the fchdir function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCHDIR
value|1
end_define

begin_comment
comment|/* Define if you have the fchmod function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCHMOD
value|1
end_define

begin_comment
comment|/* Define if you have the fsync function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FSYNC
value|1
end_define

begin_comment
comment|/* Define if you have the ftime function.  */
end_comment

begin_comment
comment|/* #undef HAVE_FTIME */
end_comment

begin_comment
comment|/* Define if you have the ftruncate function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FTRUNCATE
value|1
end_define

begin_comment
comment|/* Define if you have the getpagesize function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPAGESIZE
value|1
end_define

begin_comment
comment|/* Define if you have the getspnam function.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETSPNAM */
end_comment

begin_comment
comment|/* Define if you have the initgroups function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_INITGROUPS
value|1
end_define

begin_comment
comment|/* Define if you have the krb_get_err_text function.  */
end_comment

begin_comment
comment|/* #undef HAVE_KRB_GET_ERR_TEXT */
end_comment

begin_comment
comment|/* Define if you have the mktemp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKTEMP
value|1
end_define

begin_comment
comment|/* Define if you have the putenv function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PUTENV
value|1
end_define

begin_comment
comment|/* Define if you have the readlink function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_READLINK
value|1
end_define

begin_comment
comment|/* Define if you have the sigaction function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|1
end_define

begin_comment
comment|/* Define if you have the sigblock function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGBLOCK
value|1
end_define

begin_comment
comment|/* Define if you have the sigprocmask function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGPROCMASK
value|1
end_define

begin_comment
comment|/* Define if you have the sigsetmask function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGSETMASK
value|1
end_define

begin_comment
comment|/* Define if you have the sigvec function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGVEC
value|1
end_define

begin_comment
comment|/* Define if you have the tempnam function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TEMPNAM
value|1
end_define

begin_comment
comment|/* Define if you have the timezone function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMEZONE
value|1
end_define

begin_comment
comment|/* Define if you have the tzset function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TZSET
value|1
end_define

begin_comment
comment|/* Define if you have the vprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the wait3 function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_WAIT3
value|1
end_define

begin_comment
comment|/* Define if you have the<direct.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_DIRECT_H */
end_comment

begin_comment
comment|/* Define if you have the<dirent.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<errno.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<fcntl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<io.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_IO_H */
end_comment

begin_comment
comment|/* Define if you have the<limits.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<memory.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define if you have the<ndbm.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NDBM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<ndir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NDIR_H */
end_comment

begin_comment
comment|/* Define if you have the<string.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/bsdtypes.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_BSDTYPES_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/dir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DIR_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/file.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ndir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_NDIR_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/param.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/resource.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_RESOURCE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/select.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SELECT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/time.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/timeb.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMEB_H
value|1
end_define

begin_comment
comment|/* Define if you have the<unistd.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define if you have the<utime.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the crypt library (-lcrypt).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBCRYPT
value|1
end_define

begin_comment
comment|/* Define if you have the gen library (-lgen).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBGEN */
end_comment

begin_comment
comment|/* Define if you have the inet library (-linet).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBINET */
end_comment

begin_comment
comment|/* Define if you have the nsl library (-lnsl).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBNSL */
end_comment

begin_comment
comment|/* Define if you have the nsl_s library (-lnsl_s).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBNSL_S */
end_comment

begin_comment
comment|/* Define if you have the sec library (-lsec).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSEC */
end_comment

begin_comment
comment|/* Define if you have the socket library (-lsocket).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSOCKET */
end_comment

end_unit

