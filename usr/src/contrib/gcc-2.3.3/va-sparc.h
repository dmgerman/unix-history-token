begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is just like the default gvarargs.h    except for differences described below.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|__svr4__
end_ifndef

begin_comment
comment|/* This has to be a char * to be compatible with Sun.    i.e., we have to pass a `va_list' to vsprintf.  */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|__gnuc_va_list
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* This has to be a void * to be compatible with Sun svr4.    i.e., we have to pass a `va_list' to vsprintf.  */
end_comment

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
value|(__builtin_saveregs (), AP = ((char *) __builtin_next_arg ()))
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
define|\
value|(__builtin_saveregs (), (AP) = ((char *)&__builtin_va_alist))
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
name|pvar
parameter_list|)
end_define

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

begin_comment
comment|/* Avoid errors if compiling GCC v2 with GCC v1.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|__extension__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RECORD_TYPE args passed using the C calling convention are    passed by invisible reference.  ??? RECORD_TYPE args passed    in the stack are made to be word-aligned; for an aggregate that is    not word-aligned, we advance the pointer to the first non-reg slot.  */
end_comment

begin_comment
comment|/* We don't declare the union member `d' to have type TYPE    because that would lose in C++ if TYPE has a constructor.  */
end_comment

begin_comment
comment|/* We cast to void * and then to TYPE * because this avoids    a warning about increasing the alignment requirement.  */
end_comment

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|pvar
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|__extension__							\ ({ TYPE __va_temp;						\    ((__builtin_classify_type (__va_temp)>= 12)			\     ? ((pvar) += __va_rounded_size (TYPE *),			\        **(TYPE **) (void *) ((pvar) - __va_rounded_size (TYPE *))) \     : __va_rounded_size (TYPE) == 8				\     ? ({ union {char __d[sizeof (TYPE)]; int __i[2];} __u;	\ 	 __u.__i[0] = ((int *) (void *) (pvar))[0];		\ 	 __u.__i[1] = ((int *) (void *) (pvar))[1];		\ 	 (pvar) += 8;						\ 	 *(TYPE *) (void *) __u.__d; })				\     : ((pvar) += __va_rounded_size (TYPE),			\        *((TYPE *) (void *) ((pvar) - __va_rounded_size (TYPE)))));})
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (_STDARG_H) || defined (_VARARGS_H) */
end_comment

end_unit

