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
comment|/* These macros implement varargs for GNU C--either traditional or ANSI.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__mips64
end_ifdef

begin_define
define|#
directive|define
name|__va_rounded_size
parameter_list|(
name|__TYPE
parameter_list|)
define|\
value|(((sizeof (__TYPE) + 8 - 1) / 8) * 8)
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
name|__TYPE
parameter_list|)
define|\
value|(((sizeof (__TYPE) + sizeof (int) - 1) / sizeof (int)) * sizeof (int))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get definitions for _MIPS_SIM_ABI64 etc.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MIPS_SIM
end_ifdef

begin_include
include|#
directive|include
file|<sgidefs.h>
end_include

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
name|__AP
parameter_list|,
name|__LASTARG
parameter_list|)
define|\
value|(__AP = (__gnuc_va_list) __builtin_next_arg (__LASTARG))
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

begin_ifdef
ifdef|#
directive|ifdef
name|__mips64
end_ifdef

begin_comment
comment|/* This assumes that `long long int' is always a 64 bit type.  */
end_comment

begin_define
define|#
directive|define
name|va_dcl
value|long long int __builtin_va_alist; __va_ellipsis
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|va_dcl
value|int __builtin_va_alist; __va_ellipsis
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Need alternate code for _MIPS_SIM_ABI64.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_SIM
argument_list|)
operator|&&
operator|(
name|_MIPS_SIM
operator|==
name|_MIPS_SIM_ABI64
operator|)
end_if

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|__AP
parameter_list|)
define|\
value|(__AP = (__gnuc_va_list) __builtin_next_arg ()			\    + (__builtin_args_info (2)>= 8 ? -8 : 0))
end_define

begin_else
else|#
directive|else
end_else

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
value|((void)0)
end_define

begin_comment
comment|/* We cast to void * and then to TYPE * because this avoids    a warning about increasing the alignment requirement.  */
end_comment

begin_comment
comment|/* The __mips64 cases are reversed from the 32 bit cases, because the standard    32 bit calling convention left-aligns all parameters smaller than a word,    whereas the __mips64 calling convention does not (and hence they are    right aligned).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__mips64
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__MIPSEB__
end_ifdef

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
value|((__type *) (void *) (__AP = (char *) ((((__PTRDIFF_TYPE__)__AP + 8 - 1)& -8) \ 					 + __va_rounded_size (__type))))[-1]
end_define

begin_else
else|#
directive|else
end_else

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
value|((__AP = (char *) ((((__PTRDIFF_TYPE__)__AP + 8 - 1)& -8)	\ 		     + __va_rounded_size (__type))),		\    *(__type *) (void *) (__AP - __va_rounded_size (__type)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __mips64 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__MIPSEB__
end_ifdef

begin_comment
comment|/* For big-endian machines.  */
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
value|((__AP = (char *) ((__alignof__ (__type)> 4			\ 		      ? ((int)__AP + 8 - 1)& -8		\ 		      : ((int)__AP + 4 - 1)& -4)		\ 		     + __va_rounded_size (__type))),		\    *(__type *) (void *) (__AP - __va_rounded_size (__type)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* For little-endian machines.  */
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
value|((__type *) (void *) (__AP = (char *) ((__alignof__(__type)> 4	    \ 					  ? ((int)__AP + 8 - 1)& -8	    \ 					  : ((int)__AP + 4 - 1)& -4)	    \ 					 + __va_rounded_size(__type))))[-1]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (_STDARG_H) || defined (_VARARGS_H) */
end_comment

end_unit

