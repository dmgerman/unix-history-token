begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* AUTOMATICALLY GENERATED; DO NOT EDIT! */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_G_config_h
end_ifndef

begin_define
define|#
directive|define
name|_G_config_h
end_define

begin_define
define|#
directive|define
name|_G_LIB_VERSION
value|"2.4"
end_define

begin_define
define|#
directive|define
name|_G_NAMES_HAVE_UNDERSCORE
value|1
end_define

begin_define
define|#
directive|define
name|_G_DOLLAR_IN_LABEL
value|1
end_define

begin_define
define|#
directive|define
name|_G_HAVE_ST_BLKSIZE
value|1
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|_G_clock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|_G_dev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|_G_fpos_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|_G_gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|_G_ino_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|_G_mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|_G_nlink_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|_G_off_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|_G_pid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|_G_ptrdiff_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|_G_sigset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|_G_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|_G_time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|_G_uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|_G_wchar_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
comment|/* default */
name|_G_int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
comment|/* default */
name|_G_uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
comment|/* default */
name|_G_ssize_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
comment|/* default */
name|_G_va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_G_signal_return_type
value|void
end_define

begin_define
define|#
directive|define
name|_G_sprintf_return_type
value|int
end_define

begin_define
define|#
directive|define
name|_G_BUFSIZ
value|1024
end_define

begin_define
define|#
directive|define
name|_G_FOPEN_MAX
value|20
end_define

begin_define
define|#
directive|define
name|_G_FILENAME_MAX
value|1024
end_define

begin_define
define|#
directive|define
name|_G_NULL
value|0
end_define

begin_comment
comment|/* default */
end_comment

begin_define
define|#
directive|define
name|_G_USE_PROTOS
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_G_USE_PROTOS
end_ifdef

begin_define
define|#
directive|define
name|_G_ARGS
parameter_list|(
name|ARGLIST
parameter_list|)
value|ARGLIST
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_G_ARGS
parameter_list|(
name|ARGLIST
parameter_list|)
value|(...)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #define _G_SYSV */
end_comment

begin_define
define|#
directive|define
name|_G_HAVE_SYS_RESOURCE
value|1
end_define

begin_define
define|#
directive|define
name|_G_HAVE_SYS_SOCKET
value|1
end_define

begin_define
define|#
directive|define
name|_G_HAVE_SYS_WAIT
value|1
end_define

begin_define
define|#
directive|define
name|_G_HAVE_UNISTD
value|1
end_define

begin_define
define|#
directive|define
name|_G_HAVE_DIRENT
value|1
end_define

begin_define
define|#
directive|define
name|_G_HAVE_CURSES
value|1
end_define

begin_define
define|#
directive|define
name|_G_CURSES_FORMAT_ARG
value|const char *fmt,
end_define

begin_define
define|#
directive|define
name|_G_MATH_H_INLINES
value|0
end_define

begin_comment
comment|/* #define _G_BROKEN_SIGNED_CHAR */
end_comment

begin_comment
comment|/* #define _G_FRIEND_BUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_G_config_h */
end_comment

end_unit

