begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU C stdarg/varargs support for the M32R */
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
comment|/* Common code for va_start for both varargs and stdarg.  */
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
name|_STDARG_H
end_ifdef

begin_comment
comment|/* stdarg.h support */
end_comment

begin_comment
comment|/* Calling __builtin_next_arg gives the proper error message if LASTARG is    not indeed the last argument.  */
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
define|\
value|(AP = ((__gnuc_va_list) __builtin_next_arg (LASTARG)))
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
value|int __builtin_va_alist; ...
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|)
value|AP=(char *)&__builtin_va_alist
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDARG_H */
end_comment

begin_comment
comment|/* Nothing needs to be done to end varargs/stdarg processing */
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

begin_comment
comment|/* Values returned by __builtin_classify_type.  */
end_comment

begin_enum
enum|enum
name|__type_class
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

begin_comment
comment|/* Return whether a type is passed by reference.  */
end_comment

begin_define
define|#
directive|define
name|__va_by_reference_p
parameter_list|(
name|TYPE
parameter_list|)
value|(sizeof (TYPE)> 8)
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
define|\
value|__extension__ (*({							\   register TYPE *__ptr;							\ 									\   if (__va_by_reference_p (TYPE))					\     {									\       __ptr = *(TYPE **)(void *) (AP);					\       (AP) = (__gnuc_va_list) ((char *) (AP) + sizeof (void *));	\     }									\   else									\     {									\       __ptr = (TYPE *)(void *)						\         ((char *) (AP) + (sizeof (TYPE)< __va_rounded_size (char)	\ 			  ? __va_rounded_size (TYPE) - sizeof (TYPE)	\ 			  : 0));					\       (AP) = (__gnuc_va_list) ((char *) (AP) + __va_rounded_size (TYPE)); \     }									\ 									\   __ptr;								\ }))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (_STDARG_H) || defined (_VARARGS_H) */
end_comment

end_unit

