begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU C varargs support for the TMS320C[34]x  */
end_comment

begin_comment
comment|/* C[34]x arguments grow in weird ways (downwards) that the standard    varargs stuff can't handle. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC_VA_LIST
end_ifndef

begin_define
define|#
directive|define
name|__GNUC_VA_LIST
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|__gnuc_va_list
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __GNUC_VA_LIST */
end_comment

begin_comment
comment|/* If this is for internal libc use, don't define anything but    __gnuc_va_list.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_STDARG_H
argument_list|)
operator|||
name|defined
argument_list|(
name|_VARARGS_H
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|_STDARG_H
end_ifdef

begin_comment
comment|/* stdarg.h support */
end_comment

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|,
name|LASTARG
parameter_list|)
value|AP=(__gnuc_va_list) __builtin_next_arg (LASTARG)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* varargs.h support */
end_comment

begin_define
define|#
directive|define
name|__va_ellipsis
value|...
end_define

begin_define
define|#
directive|define
name|va_alist
value|__builtin_va_alist
end_define

begin_define
define|#
directive|define
name|va_dcl
value|int __builtin_va_alist; __va_ellipsis
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|)
value|AP=(__gnuc_va_list) ((int *)&__builtin_va_alist +  1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDARG_H */
end_comment

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|AP
parameter_list|)
value|((void) 0)
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|AP
parameter_list|,
name|TYPE
parameter_list|)
value|(AP = (__gnuc_va_list) ((char *) (AP) - sizeof(TYPE)), \ 			 *((TYPE *) ((char *) (AP))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (_STDARG_H) || defined (_VARARGS_H) */
end_comment

end_unit

