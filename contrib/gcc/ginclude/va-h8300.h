begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stdarg/vararg support for the Hitachi h8/300 and h8/300h */
end_comment

begin_comment
comment|/* Define __gnuc_va_list. */
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

begin_comment
comment|/* In GCC version 2, we want an ellipsis at the end of the declaration    of the argument list.  GCC version 1 can't parse it.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|>
literal|1
end_if

begin_define
define|#
directive|define
name|__va_ellipsis
value|...
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__va_ellipsis
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__H8300__
end_ifdef

begin_define
define|#
directive|define
name|__va_rounded_size
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(((sizeof (TYPE) + sizeof (int) - 1) / sizeof (int)) * sizeof (int))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__va_rounded_size
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(((sizeof (TYPE) + sizeof (long) - 1) / sizeof (long)) * sizeof (long))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_STDARG_H
end_ifdef

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|,
name|LASTARG
parameter_list|)
define|\
value|(AP = ((__gnuc_va_list) __builtin_next_arg (LASTARG)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _VARARGS_H */
end_comment

begin_define
define|#
directive|define
name|va_alist
value|__builtin_va_alist
end_define

begin_comment
comment|/* The ... causes current_function_varargs to be set in cc1.  */
end_comment

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
value|AP = (void *)&__builtin_va_alist
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VARARGS_H */
end_comment

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|AP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(AP = (__gnuc_va_list) ((char *) (AP) + __va_rounded_size (TYPE)),	\   *((TYPE *) (void *) ((char *) (AP)					\ 		       - ((sizeof (TYPE)< __va_rounded_size (int)	\ 			  ? sizeof (TYPE) : __va_rounded_size (TYPE))))))
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|AP
parameter_list|)
value|((void) 0)
end_define

begin_comment
comment|/* Copy __gnuc_va_list into another variable of this type.  */
end_comment

begin_define
define|#
directive|define
name|__va_copy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
value|(dest) = (src)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (_STDARG_H) || defined (_VARARGS_H) */
end_comment

end_unit

