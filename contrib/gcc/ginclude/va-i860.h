begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
union|union
block|{
name|float
name|__freg
index|[
literal|8
index|]
decl_stmt|;
name|double
name|__dreg
index|[
literal|4
index|]
decl_stmt|;
block|}
name|__f_regs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
if|#
directive|if
name|defined
argument_list|(
name|__SVR4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__alliant__
argument_list|)
operator|||
name|defined
argument_list|(
name|__PARAGON__
argument_list|)
name|__f_regs
name|__float_regs
decl_stmt|;
name|long
name|__ireg
index|[
literal|12
index|]
decl_stmt|;
else|#
directive|else
comment|/* pre-SVR4 */
name|long
name|__ireg
index|[
literal|12
index|]
decl_stmt|;
name|__f_regs
name|__float_regs
decl_stmt|;
endif|#
directive|endif
block|}
name|__va_saved_regs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
if|#
directive|if
name|defined
argument_list|(
name|__SVR4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__alliant__
argument_list|)
operator|||
name|defined
argument_list|(
name|__PARAGON__
argument_list|)
name|unsigned
name|__ireg_used
decl_stmt|;
comment|/* How many int regs consumed 'til now? */
name|unsigned
name|__freg_used
decl_stmt|;
comment|/* How many flt regs consumed 'til now? */
name|long
modifier|*
name|__reg_base
decl_stmt|;
comment|/* Address of where we stored the regs. */
name|long
modifier|*
name|__mem_ptr
decl_stmt|;
comment|/* Address of memory overflow args area. */
else|#
directive|else
comment|/* pre-SVR4 */
name|long
modifier|*
name|__reg_base
decl_stmt|;
comment|/* Address of where we stored the regs. */
name|long
modifier|*
name|__mem_ptr
decl_stmt|;
comment|/* Address of memory overflow args area. */
name|unsigned
name|__ireg_used
decl_stmt|;
comment|/* How many int regs consumed 'til now? */
name|unsigned
name|__freg_used
decl_stmt|;
comment|/* How many flt regs consumed 'til now? */
endif|#
directive|endif
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__PARAGON__
argument_list|)
end_if

begin_define
define|#
directive|define
name|va_dcl
value|int va_alist;
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __PARAGON__ */
end_comment

begin_define
define|#
directive|define
name|va_dcl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PARAGON__ */
end_comment

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

begin_comment
comment|/* Note that CUMULATIVE_ARGS elements are measured in bytes on the i860,    so we divide by 4 to get # of registers.  */
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
value|((pvar) = *(__gnuc_va_list *) __builtin_saveregs (),			\   (pvar).__ireg_used = __builtin_args_info (0) / 4,		\   (pvar).__freg_used = __builtin_args_info (1) / 4,		\   (pvar).__mem_ptr = __builtin_next_arg (firstarg))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDARG_H */
end_comment

begin_comment
comment|/* Values returned by __builtin_classify_type.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|va_end
end_ifndef

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
name|__va
parameter_list|)
value|((void) 0)
end_define

begin_define
define|#
directive|define
name|__NUM_PARM_FREGS
value|8
end_define

begin_define
define|#
directive|define
name|__NUM_PARM_IREGS
value|12
end_define

begin_define
define|#
directive|define
name|__savereg
parameter_list|(
name|__va
parameter_list|)
value|((__va_saved_regs *) ((__va).__reg_base))
end_define

begin_comment
comment|/* This macro works both for SVR4 and pre-SVR4 environments.  */
end_comment

begin_comment
comment|/* Note that parameters are always aligned at least to a word boundary    (when passed) regardless of what GCC's __alignof__ operator says.  */
end_comment

begin_comment
comment|/* Make allowances here for adding 128-bit (long double) floats someday.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* What was this for? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNU_VA_LIST
end_ifndef

begin_define
define|#
directive|define
name|__ireg_used
value|ireg_used
end_define

begin_define
define|#
directive|define
name|__freg_used
value|freg_used
end_define

begin_define
define|#
directive|define
name|__mem_ptr
value|mem_ptr
end_define

begin_define
define|#
directive|define
name|__reg_base
value|reg_base
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
comment|/* 0 */
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
value|__extension__								\ (* (__type *)								\ ({									\   register void *__rv;
comment|/* result value */
value|\   register unsigned __align;						\   switch (__builtin_classify_type (* (__type *) 0))			\     {									\     case __real_type_class:						\       switch (sizeof (__type))						\ 	{								\ 	  case sizeof (float):						\ 	  case sizeof (double):						\ 	    if ((__va).__freg_used< __NUM_PARM_FREGS - 1)		\ 	      {								\ 	        if (((__va).__freg_used& 1) != 0)			\ 	          (__va).__freg_used++;
comment|/* skip odd */
value|\ 	        __rv =&__savereg((__va))->__float_regs.__freg[(__va).__freg_used];\ 		(__va).__freg_used += 2;				\ 	      }								\ 	    else							\ 	      {								\ 	        if ((((unsigned) (__va).__mem_ptr)& (sizeof(double)-1)) != 0) \ 	          (__va).__mem_ptr++;
comment|/* skip odd */
value|\ 	        __rv = (__va).__mem_ptr;				\ 	        (__va).__mem_ptr += 2;					\ 	      }								\ 	    if (sizeof (__type) == sizeof (float))			\ 	      {								\ 	        *((float *) __rv) = *((double *) __rv);			\ 		*(((long *) __rv) + 1) = 0xfff00001;			\ 	      }								\ 	    break;							\ 	  default:							\ 	    abort ();							\ 	}								\       break;								\     case __void_type_class:						\     case __integer_type_class:						\     case __char_type_class:						\     case __enumeral_type_class:						\     case __boolean_type_class:						\     case __pointer_type_class:						\     case __reference_type_class:					\     case __offset_type_class:						\       if (sizeof (__type)<= 4)						\ 	{								\           __rv = ((__va).__ireg_used< __NUM_PARM_IREGS			\ 	          ? (&__savereg((__va))->__ireg[(__va).__ireg_used++])	\ 	          : (__va).__mem_ptr++);				\ 	  break;							\ 	}								\       else if ((__va).__ireg_used + sizeof (__type) / 4<= __NUM_PARM_IREGS) \ 	{								\ 	  __rv =&__savereg((__va))->__ireg[(__va).__ireg_used];	\ 	  (__va).__ireg_used += sizeof (__type) / 4;			\           break;							\ 	}								\
comment|/* Fall through to fetch from memory.  */
value|\     case __record_type_class:						\     case __union_type_class:						\       __align = (__alignof__ (__type)< sizeof (long)			\ 		 ? sizeof (long)					\ 		 : __alignof__ (__type));				\       (__va).__mem_ptr							\ 	= (long *)							\ 	  ((((unsigned) (__va).__mem_ptr) + (__align-1))& ~(__align-1)); \       __rv = (__va).__mem_ptr;						\       (__va).__mem_ptr							\ 	+= ((sizeof (__type) + sizeof (long) - 1) / sizeof (long));	\       break;								\     case __complex_type_class:						\     case __function_type_class:						\     case __method_type_class:						\     case __array_type_class:						\     case __string_type_class:						\     case __set_type_class:						\     case __file_type_class:						\     case __lang_type_class:						\     case __no_type_class:						\     default:								\ 	abort ();							\     }									\   __rv;									\ }))
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

