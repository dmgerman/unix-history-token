begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stdarg/varargs support for the ARC */
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

begin_comment
comment|/* See arc_setup_incoming_varargs for reasons for the oddity in va_start.  */
end_comment

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
value|(AP = (__gnuc_va_list) ((int *) __builtin_next_arg (LASTARG) \ 			+ (__builtin_args_info (0)< 8 \ 			   ? (__builtin_args_info (0)& 1) \ 			   : 0)))
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
name|AP
parameter_list|)
define|\
value|(AP = (__gnuc_va_list) ((int *)&__builtin_va_alist \ 			+ (__builtin_args_info (0)< 8 \ 			   ? (__builtin_args_info (0)& 1) \ 			   : 0)))
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
name|AP
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
comment|/* All aggregates are passed by reference.  All scalar types larger than 8    bytes are passed by reference.  */
end_comment

begin_comment
comment|/* We cast to void * and then to TYPE * because this avoids    a warning about increasing the alignment requirement.    The casts to char * avoid warnings about invalid pointer arithmetic.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__big_endian__
end_ifdef

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
value|__extension__							\ (*({((__builtin_classify_type (*(TYPE*) 0)>= __record_type_class \       || __va_rounded_size (TYPE)> 8)				\      ? ((AP) = (char *)(AP) + __va_rounded_size (TYPE *),	\ 	*(TYPE **) (void *) ((char *)(AP) - __va_rounded_size (TYPE *))) \      : ((TYPE *) (void *)					\ 	(AP = (void *) ((__alignof__ (TYPE)> 4			\ 			 ? ((int) AP + 8 - 1)& -8		\ 			 : (int) AP)				\ 			 + __va_rounded_size (TYPE))) - 1));}))
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
name|AP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|__extension__							\ (*({((__builtin_classify_type (*(TYPE*) 0)>= __record_type_class \       || __va_rounded_size (TYPE)> 8)				\      ? ((AP) = (char *)(AP) + __va_rounded_size (TYPE *),	\ 	*(TYPE **) (void *) ((char *)(AP) - __va_rounded_size (TYPE *))) \      : ((AP = (void *) ((__alignof__ (TYPE)> 4			\ 			? ((int) AP + 8 - 1)& -8		\ 			: (int) AP)				\ 		       + __va_rounded_size (TYPE))),		\ 	(TYPE *) (void *) (AP - __va_rounded_size (TYPE))));}))
end_define

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

