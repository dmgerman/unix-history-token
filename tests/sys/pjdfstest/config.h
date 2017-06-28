begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* config.h.  Generated from config.h.in by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated from configure.ac by autoheader.  */
end_comment

begin_comment
comment|/* Define to 1 if NFSv4 ACL support is available */
end_comment

begin_define
define|#
directive|define
name|HAS_NFSV4_ACL_SUPPORT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `acl_create_entry_np' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ACL_CREATE_ENTRY_NP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `acl_from_text' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ACL_FROM_TEXT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `acl_get_entry' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ACL_GET_ENTRY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `acl_get_file' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ACL_GET_FILE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `acl_set_file' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ACL_SET_FILE
value|1
end_define

begin_comment
comment|/* Define if bindat exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_BINDAT
value|1
end_define

begin_comment
comment|/* Define if chflags exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_CHFLAGS
value|1
end_define

begin_comment
comment|/* Define if chflagsat exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_CHFLAGSAT
value|1
end_define

begin_comment
comment|/* Define if connectat exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_CONNECTAT
value|1
end_define

begin_comment
comment|/* Define if faccessat exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_FACCESSAT
value|1
end_define

begin_comment
comment|/* Define if fchflags exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCHFLAGS
value|1
end_define

begin_comment
comment|/* Define if fchmodat exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCHMODAT
value|1
end_define

begin_comment
comment|/* Define if fchownat exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCHOWNAT
value|1
end_define

begin_comment
comment|/* Define if fstatat exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_FSTATAT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<inttypes.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define if lchflags exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_LCHFLAGS
value|1
end_define

begin_comment
comment|/* Define if lchmod exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_LCHMOD
value|1
end_define

begin_comment
comment|/* Define if linkat exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_LINKAT
value|1
end_define

begin_comment
comment|/* Define if lpathconf exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_LPATHCONF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<memory.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define if mkdirat exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKDIRAT
value|1
end_define

begin_comment
comment|/* Define if mkfifoat exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKFIFOAT
value|1
end_define

begin_comment
comment|/* Define if mknodat exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKNODAT
value|1
end_define

begin_comment
comment|/* Define if openat exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENAT
value|1
end_define

begin_comment
comment|/* Define if posix_fallocate exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_POSIX_FALLOCATE
value|1
end_define

begin_comment
comment|/* Define if readlinkat exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_READLINKAT
value|1
end_define

begin_comment
comment|/* Define if renameat exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_RENAMEAT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdint.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<strings.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<string.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_atim' is a member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_ATIM
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_atimespec' is a member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_ATIMESPEC
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_birthtim' is a member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_BIRTHTIM
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_birthtime' is a member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_BIRTHTIME
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_birthtimespec' is a member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_BIRTHTIMESPEC
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_ctim' is a member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_CTIM
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_ctimespec' is a member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_CTIMESPEC
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_mtim' is a member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_MTIM
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_mtimespec' is a member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_MTIMESPEC
value|1
end_define

begin_comment
comment|/* Define if symlinkat exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYMLINKAT
value|1
end_define

begin_comment
comment|/* Define to 1 if sys/acl.h is available */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_ACL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/mkdev.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_MKDEV_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/stat.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<unistd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define if utimensat exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIMENSAT
value|1
end_define

begin_comment
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"pjdfstest"
end_define

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|""
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"pjdfstest"
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"pjdfstest 0.1"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"pjdfstest"
end_define

begin_comment
comment|/* Define to the home page for this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_URL
value|""
end_define

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|"0.1"
end_define

begin_comment
comment|/* Define to 1 if you have the ANSI C header files. */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Enable extensions on AIX 3, Interix.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALL_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_ALL_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable GNU extensions on systems that have them.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_GNU_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable threading extensions on Solaris.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_PTHREAD_SEMANTICS
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_PTHREAD_SEMANTICS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable extensions on HP NonStop.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TANDEM_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_TANDEM_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable general extensions on Solaris.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EXTENSIONS__
end_ifndef

begin_define
define|#
directive|define
name|__EXTENSIONS__
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"0.1"
end_define

begin_comment
comment|/* Define to 1 if on MINIX. */
end_comment

begin_comment
comment|/* #undef _MINIX */
end_comment

begin_comment
comment|/* Define to 2 if the system does not provide POSIX.1 features except with    this defined. */
end_comment

begin_comment
comment|/* #undef _POSIX_1_SOURCE */
end_comment

begin_comment
comment|/* Define to 1 if you need to in order for `stat' and other things to work. */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

end_unit

