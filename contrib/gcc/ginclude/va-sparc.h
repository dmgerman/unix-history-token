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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__arch64__
argument_list|)
end_if

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

begin_ifdef
ifdef|#
directive|ifdef
name|_STDARG_H
end_ifdef

begin_comment
comment|/* Call __builtin_next_arg even though we aren't using its value, so that    we can verify that LASTARG is correct.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GCC_NEW_VARARGS__
argument_list|)
operator|||
name|defined
argument_list|(
name|__arch64__
argument_list|)
end_if

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
value|(__builtin_next_arg (LASTARG), AP = (char *) __builtin_saveregs ())
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
name|AP
parameter_list|,
name|LASTARG
parameter_list|)
define|\
value|(__builtin_saveregs (), AP = ((char *) __builtin_next_arg (LASTARG)))
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|int __builtin_va_alist;...
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GCC_NEW_VARARGS__
argument_list|)
operator|||
name|defined
argument_list|(
name|__arch64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|)
value|((AP) = (char *) __builtin_saveregs ())
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
name|AP
parameter_list|)
define|\
value|(__builtin_saveregs (), (AP) = ((char *)&__builtin_va_alist))
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

begin_comment
comment|/* Values returned by __builtin_classify_type.  */
end_comment

begin_enum
enum|enum
name|__va_type_classes
block|{
name|__no_type_class
init|=
operator|-
literal|1
block|,
name|__void_type_class
block|,
name|__integer_type_class
block|,
name|__char_type_class
block|,
name|__enumeral_type_class
block|,
name|__boolean_type_class
block|,
name|__pointer_type_class
block|,
name|__reference_type_class
block|,
name|__offset_type_class
block|,
name|__real_type_class
block|,
name|__complex_type_class
block|,
name|__function_type_class
block|,
name|__method_type_class
block|,
name|__record_type_class
block|,
name|__union_type_class
block|,
name|__array_type_class
block|,
name|__string_type_class
block|,
name|__set_type_class
block|,
name|__file_type_class
block|,
name|__lang_type_class
block|}
enum|;
end_enum

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
value|((void)0)
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

begin_ifdef
ifdef|#
directive|ifdef
name|__arch64__
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|__ptrint
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__DI__
typedef|)));
end_typedef

begin_comment
comment|/* ??? TODO: little endian support */
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
value|__extension__							\ (*({int __type = __builtin_classify_type (* (TYPE *) 0);	\   char * __result;						\   if (__type == __real_type_class)
comment|/* float? */
value|\     {								\       if (__alignof__ (TYPE) == 16)				\ 	(pvar) = (void *) (((__ptrint) (pvar) + 15)& -16);	\       __result = (pvar);					\       (pvar) = (char *) (pvar) + sizeof (TYPE);			\     }								\   else if (__type< __record_type_class)
comment|/* integer? */
value|\     {								\       (pvar) = (char *) (pvar) + 8;				\       __result = (char *) (pvar) - sizeof (TYPE);		\     }								\   else
comment|/* aggregate object */
value|\     {								\       if (sizeof (TYPE)<= 8)					\ 	{							\ 	  __result = (pvar);					\ 	  (pvar) = (char *) (pvar) + 8;				\ 	}							\       else if (sizeof (TYPE)<= 16)				\ 	{							\ 	  if (__alignof__ (TYPE) == 16)				\ 	    (pvar) = (void *) (((__ptrint) (pvar) + 15)& -16);	\ 	  __result = (pvar);					\ 	  (pvar) = (char *) (pvar) + 16;			\ 	}							\       else							\ 	{							\ 	  __result = * (void **) (pvar);			\ 	  (pvar) = (char *) (pvar) + 8;				\ 	}							\     }								\   (TYPE *) __result;}))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __arch64__ */
end_comment

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
comment|/* We don't declare the union member `d' to have type TYPE    because that would lose in C++ if TYPE has a constructor.  */
end_comment

begin_comment
comment|/* We cast to void * and then to TYPE * because this avoids    a warning about increasing the alignment requirement.    The casts to char * avoid warnings about invalid pointer arithmetic.  */
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
value|__extension__							\ (*({((__builtin_classify_type (*(TYPE*) 0)>= __record_type_class \       || (__builtin_classify_type (*(TYPE*) 0) == __real_type_class \&& sizeof (TYPE) == 16))				\     ? ((pvar) = (char *)(pvar) + __va_rounded_size (TYPE *),	\        *(TYPE **) (void *) ((char *)(pvar) - __va_rounded_size (TYPE *))) \     : __va_rounded_size (TYPE) == 8				\     ? ({ union {char __d[sizeof (TYPE)]; int __i[2];} __u;	\ 	 __u.__i[0] = ((int *) (void *) (pvar))[0];		\ 	 __u.__i[1] = ((int *) (void *) (pvar))[1];		\ 	 (pvar) = (char *)(pvar) + 8;				\ 	 (TYPE *) (void *) __u.__d; })				\     : ((pvar) = (char *)(pvar) + __va_rounded_size (TYPE),	\        ((TYPE *) (void *) ((char *)(pvar) - __va_rounded_size (TYPE)))));}))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __arch64__ */
end_comment

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

