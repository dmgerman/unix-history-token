begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* XXX _G_VTABLE_LABLE_PREFIX is different between ELF and a.out */
end_comment

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
value|"2.7.2"
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
name|_G_VTABLE_LABEL_HAS_LENGTH
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__ELF__
end_ifdef

begin_define
define|#
directive|define
name|_G_VTABLE_LABEL_PREFIX
value|"_vt."
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_G_VTABLE_LABEL_PREFIX
value|"__vt$"
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|unsigned
name|int
name|_G_dev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|_G_fpos_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|_G_gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
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
name|long
name|_G_off_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|_G_pid_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|__PTRDIFF_TYPE__
end_ifndef

begin_define
define|#
directive|define
name|__PTRDIFF_TYPE__
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__PTRDIFF_TYPE__
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

begin_ifndef
ifndef|#
directive|ifndef
name|__SIZE_TYPE__
end_ifndef

begin_define
define|#
directive|define
name|__SIZE_TYPE__
value|unsigned int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
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
name|int
name|_G_uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|_G_wchar_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|_G_ssize_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
comment|/* default */
name|_G_wint_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
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

begin_if
if|#
directive|if
name|__GNUC__
operator|>
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|7
operator|)
end_if

begin_typedef
typedef|typedef
name|int
name|_G_int8_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__QI__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|_G_uint8_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__QI__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|_G_int16_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__HI__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|_G_uint16_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__HI__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|_G_int32_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__SI__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|_G_uint32_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__SI__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|_G_int64_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__DI__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|_G_uint64_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__DI__
typedef|)));
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|short
name|_G_int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|_G_uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|_G_int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|_G_uint32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

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
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUG__
argument_list|)
operator|||
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_G_NO_NRV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUG__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_G_NO_EXTERN_TEMPLATES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_G_HAVE_ATEXIT
value|1
end_define

begin_define
define|#
directive|define
name|_G_HAVE_SYS_RESOURCE
value|1
end_define

begin_define
define|#
directive|define
name|_G_HAVE_SYS_TIMES
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
name|_G_HAVE_SYS_CDEFS
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
name|_G_MATH_H_INLINES
value|0
end_define

begin_define
define|#
directive|define
name|_G_HAVE_BOOL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_G_config_h */
end_comment

end_unit

