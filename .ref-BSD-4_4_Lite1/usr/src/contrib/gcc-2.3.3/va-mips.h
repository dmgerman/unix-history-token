begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ---------------------------------------- */
end_comment

begin_comment
comment|/*           VARARGS  for MIPS/GNU CC       */
end_comment

begin_comment
comment|/*                                          */
end_comment

begin_comment
comment|/*                                          */
end_comment

begin_comment
comment|/*                                          */
end_comment

begin_comment
comment|/*                                          */
end_comment

begin_comment
comment|/* ---------------------------------------- */
end_comment

begin_comment
comment|/* These macros implement varargs for GNU C--either traditional or ANSU.  */
end_comment

begin_comment
comment|/* Define __gnuc_va_list.  */
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
name|char
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

begin_define
define|#
directive|define
name|__va_rounded_size
parameter_list|(
name|__TYPE
parameter_list|)
define|\
value|(((sizeof (__TYPE) + sizeof (int) - 1) / sizeof (int)) * sizeof (int))
end_define

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
name|__AP
parameter_list|,
name|__LASTARG
parameter_list|)
define|\
value|(__AP = ((char *)&(__LASTARG) + __va_rounded_size (__LASTARG)))
end_define

begin_else
else|#
directive|else
end_else

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
name|__AP
parameter_list|)
value|__AP = (char *)&__builtin_va_alist
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|va_end
end_ifndef

begin_function_decl
name|void
name|va_end
parameter_list|(
name|__gnuc_va_list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in libgcc.a */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|__AP
parameter_list|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_comment
comment|/* complains about constant in conditional context */
end_comment

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|list
parameter_list|,
name|mode
parameter_list|)
value|((mode *)(list += __va_rounded_size(mode)))[-1]
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !lint */
end_comment

begin_comment
comment|/* We cast to void * and then to TYPE * because this avoids    a warning about increasing the alignment requirement.  */
end_comment

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|__AP
parameter_list|,
name|__type
parameter_list|)
define|\
value|((__type *) (void *) (__AP = (char *) ((__alignof(__type)> 4		    \ 					  ? ((int)__AP + 8 - 1)& -8	    \ 					  : ((int)__AP + 4 - 1)& -4)	    \ 					 + __va_rounded_size(__type))))[-1]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (_STDARG_H) || defined (_VARARGS_H) */
end_comment

end_unit

