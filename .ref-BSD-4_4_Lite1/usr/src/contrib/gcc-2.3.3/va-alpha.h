begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU C varargs and stdargs support for the DEC Alpha.  */
end_comment

begin_comment
comment|/* Note:  We must use the name __builtin_savregs.  GCC attaches special    significance to that name.  In particular, regardless of where in a    function __builtin_saveregs is called, GCC moves the call up to the    very start of the function.  */
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
struct|struct
block|{
name|long
name|__va_arg
decl_stmt|;
comment|/* Current argument number. */
name|long
modifier|*
name|__va_stack
decl_stmt|;
comment|/* Start of arguments on stack */
name|long
modifier|*
name|__va_iregs
decl_stmt|;
comment|/* Integer parameter registers ($16-$21) */
name|long
modifier|*
name|__va_fregs
decl_stmt|;
comment|/* FP parameter registers ($f16-$f21) */
block|}
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

begin_define
define|#
directive|define
name|va_list
value|__gnuc_va_list
end_define

begin_define
define|#
directive|define
name|_VA_LIST
end_define

begin_define
define|#
directive|define
name|_VA_LIST_
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_STDARG_H
argument_list|)
end_if

begin_comment
comment|/* varargs support */
end_comment

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
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|pvar
parameter_list|)
value|((pvar) = * (__gnuc_va_list *) __builtin_saveregs ())
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* STDARG.H */
end_comment

begin_comment
comment|/* ANSI alternative.  */
end_comment

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|pvar
parameter_list|,
name|firstarg
parameter_list|)
define|\
value|((pvar) = *(__gnuc_va_list *) __builtin_saveregs ())
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDARG_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|va_end
end_ifndef

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|__va
parameter_list|)
end_define

begin_comment
comment|/* Values returned by __builtin_classify_type.  */
end_comment

begin_enum
enum|enum
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

begin_comment
comment|/* Note that parameters are always aligned at least to a word boundary    (when passed) regardless of what GCC's __alignof__ operator says.  */
end_comment

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
comment|/* Get the rounded number of words of a type.  */
end_comment

begin_define
define|#
directive|define
name|__va_nwords
parameter_list|(
name|__type
parameter_list|)
define|\
value|((sizeof (__type) + sizeof (long) - 1) / sizeof (long))
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|__va
parameter_list|,
name|__type
parameter_list|)
define|\
value|__extension__								\ (* (__type *)								\  ({									\   register void *__rv;
comment|/* result value */
value|\   switch (__builtin_classify_type (* (__type *) 0))			\     {			        					\     case __real_type_class:						\ 									\
comment|/* Get a pointer to the value.  If we want a float instead of	\ 	 a double, we have to make one and point to it instead.  */
value|\ 									\       __rv = (void *)& ((__va).__va_arg< 6				\ 			 ? (__va).__va_fregs[(__va).__va_arg]		\ 			 : (__va).__va_stack[(__va).__va_arg - 6]);	\ 									\       if (sizeof (__type) == sizeof (float))				\ 	{								\ 	  float __rf = * ((double *) __rv);				\ 									\ 	  __rv = (void *)&__rf;					\ 	}								\ 									\       break;								\ 	      								\     case __void_type_class:						\     case __integer_type_class:						\     case __char_type_class:						\     case __enumeral_type_class:						\     case __boolean_type_class:						\     case __pointer_type_class:						\     case __reference_type_class:					\     case __offset_type_class:						\     case __record_type_class:						\     case __union_type_class:						\ 									\
comment|/* Force this on the stack if it's alignment isn't right.  */
value|\ 									\       if ((__va).__va_arg< 6)						\ 	switch (sizeof (__type))					\ 	  {								\ 	  case sizeof (char):						\ 	    break;							\ 	  case sizeof (short):						\ 	    if (__alignof__ (__type)< sizeof (short))			\ 	      (__va).__va_arg = 6;					\ 	    break;							\ 	  case 3:							\ 	  case sizeof (int):						\ 	    if (__alignof__ (__type)< sizeof (int))			\ 	      (__va).__va_arg = 6;					\ 	    break;							\ 	  default:							\ 	    if (__alignof__ (__type)< sizeof (long))			\ 	      (__va).__va_arg = 6;					\ 	    break;							\ 	  }								\ 									\
comment|/* If this object is only one word long, just get it.  If it is   \ 	 longer, we need to worry about the possibility that it is	\ 	 passed both in registers and in memory.  */
value|\ 									\       if (sizeof (__type)<= sizeof (long)				\ 	  || (__va).__va_arg>= 6					\ 	  || (__va).__va_arg + __va_nwords (__type)< 6)		\ 	__rv = (void *)& ((__va).__va_arg< 6				\ 			   ? (__va).__va_iregs[(__va).__va_arg]		\ 			   : (__va).__va_stack[(__va).__va_arg - 6]);	\       else								\ 	{								\ 	  long __obj[__va_nwords (__type)];				\ 	  int __i;							\ 									\ 	  for (__i = 0; __i< __va_nwords (__type); __i++)		\ 	    __obj[__i] = ((__va).__va_arg + __i< 6			\ 			  ? (__va).__va_iregs[(__va).__va_arg + __i]	\ 			  : (__va).__va_stack[(__va).__va_arg + __i - 6]); \ 									\ 	  __rv = (void *)&__obj[0];					\ 	}								\       break;								\ 									\     case __complex_type_class:						\     case __function_type_class:						\     case __method_type_class:						\     case __array_type_class:						\     case __string_type_class:						\     case __set_type_class:						\     case __file_type_class:						\     case __lang_type_class:						\     case __no_type_class:						\     default:								\ 	abort ();							\     }									\ 									\   (__va).__va_arg += __va_nwords (__type);				\ 									\   __rv;									\ }))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (_STDARG_H) || defined (_VARARGS_H) */
end_comment

end_unit

