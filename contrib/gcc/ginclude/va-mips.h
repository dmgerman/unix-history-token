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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_eabi
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__mips_soft_float
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__mips_single_float
argument_list|)
end_if

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Pointer to FP regs.  */
name|char
modifier|*
name|__fp_regs
decl_stmt|;
comment|/* Number of FP regs remaining.  */
name|int
name|__fp_left
decl_stmt|;
comment|/* Pointer to GP regs followed by stack parameters.  */
name|char
modifier|*
name|__gp_regs
decl_stmt|;
block|}
name|__gnuc_va_list
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! (defined (__mips_eabi)&& ! defined (__mips_soft_float)&& ! defined (__mips_single_float)) */
end_comment

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
comment|/* ! (defined (__mips_eabi)&& ! defined (__mips_soft_float)&& ! defined (__mips_single_float)) */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_MIPS_H_ENUM
end_ifndef

begin_define
define|#
directive|define
name|_VA_MIPS_H_ENUM
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|__mips64
end_ifdef

begin_define
define|#
directive|define
name|__va_reg_size
value|8
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__va_reg_size
value|4
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_eabi
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__mips_soft_float
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__mips_single_float
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__mips64
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
value|(__AP.__gp_regs = ((char *) __builtin_next_arg (__LASTARG)		\ 		     - (__builtin_args_info (2)< 8			\ 			? (8 - __builtin_args_info (2)) * __va_reg_size	\ 			: 0)),						\    __AP.__fp_left = 8 - __builtin_args_info (3),			\    __AP.__fp_regs = __AP.__gp_regs - __AP.__fp_left * __va_reg_size)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (__mips64) */
end_comment

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
value|(__AP.__gp_regs = ((char *) __builtin_next_arg (__LASTARG)		\ 		     - (__builtin_args_info (2)< 8			\ 			? (8 - __builtin_args_info (2)) * __va_reg_size	\ 			: 0)),						\    __AP.__fp_left = (8 - __builtin_args_info (3)) / 2,			\    __AP.__fp_regs = __AP.__gp_regs - __AP.__fp_left * 8,		\    __AP.__fp_regs = (char *) ((int) __AP.__fp_regs& -8))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (__mips64) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! (! defined (__mips_soft_float)&& ! defined (__mips_single_float) ) */
end_comment

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
value|(__AP = ((__gnuc_va_list) __builtin_next_arg (__LASTARG)		\ 	   - (__builtin_args_info (2)>= 8 ? 0				\ 	      : (8 - __builtin_args_info (2)) * __va_reg_size)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! (! defined (__mips_soft_float)&& ! defined (__mips_single_float) ) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (__mips_eabi) */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! (defined (__mips_eabi)&& ! defined (__mips_soft_float)&& ! defined (__mips_single_float)) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! _STDARG_H */
end_comment

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_eabi
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__mips_soft_float
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__mips_single_float
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__mips64
end_ifdef

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|__AP
parameter_list|)
define|\
value|(__AP.__gp_regs = ((char *) __builtin_next_arg ()			\ 		     - (__builtin_args_info (2)< 8			\ 			? (8 - __builtin_args_info (2)) * __va_reg_size	\ 			: __va_reg_size)),				\    __AP.__fp_left = 8 - __builtin_args_info (3),			\    __AP.__fp_regs = __AP.__gp_regs - __AP.__fp_left * __va_reg_size)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (__mips64) */
end_comment

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|__AP
parameter_list|)
define|\
value|(__AP.__gp_regs = ((char *) __builtin_next_arg ()			\ 		     - (__builtin_args_info (2)< 8			\ 			? (8 - __builtin_args_info (2)) * __va_reg_size	\ 			: __va_reg_size)),				\    __AP.__fp_left = (8 - __builtin_args_info (3)) / 2,			\    __AP.__fp_regs = __AP.__gp_regs - __AP.__fp_left * 8,		\    __AP.__fp_regs = (char *) ((int) __AP.__fp_regs& -8))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (__mips64) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! (! defined (__mips_soft_float)&& ! defined (__mips_single_float)) */
end_comment

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|__AP
parameter_list|)
define|\
value|(__AP = ((__gnuc_va_list) __builtin_next_arg ()			\ 	   - (__builtin_args_info (2)>= 8 ? __va_reg_size		\ 	      : (8 - __builtin_args_info (2)) * __va_reg_size)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! (! defined (__mips_soft_float)&& ! defined (__mips_single_float)) */
end_comment

begin_comment
comment|/* Need alternate code for _MIPS_SIM_ABI64.  */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MIPS_SIM
argument_list|)
operator|&&
operator|(
name|_MIPS_SIM
operator|==
name|_MIPS_SIM_ABI64
operator|||
name|_MIPS_SIM
operator|==
name|_MIPS_SIM_NABI32
operator|)
end_elif

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

begin_comment
comment|/* ! _STDARG_H */
end_comment

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_eabi
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__mips_soft_float
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__mips_single_float
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__mips64
end_ifdef

begin_define
define|#
directive|define
name|__va_next_addr
parameter_list|(
name|__AP
parameter_list|,
name|__type
parameter_list|)
define|\
value|((__builtin_classify_type (*(__type *) 0) == __real_type_class	\&& __AP.__fp_left> 0)						\    ? (--__AP.__fp_left, (__AP.__fp_regs += 8) - 8)			\    : (__AP.__gp_regs += __va_reg_size) - __va_reg_size)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__va_next_addr
parameter_list|(
name|__AP
parameter_list|,
name|__type
parameter_list|)
define|\
value|((__builtin_classify_type (*(__type *) 0) == __real_type_class	\&& __AP.__fp_left> 0)						\    ? (--__AP.__fp_left, (__AP.__fp_regs += 8) - 8)			\    : (((__builtin_classify_type (* (__type *) 0)< __record_type_class	\&& __alignof__ (__type)> 4)					\        ? __AP.__gp_regs = (char *) (((int) __AP.__gp_regs + 8 - 1)& -8) \        : (char *) 0),							\       (__builtin_classify_type (* (__type *) 0)>= __record_type_class	\        ? (__AP.__gp_regs += __va_reg_size) - __va_reg_size		\        : ((__AP.__gp_regs += __va_rounded_size (__type))		\ 	  - __va_rounded_size (__type)))))
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
comment|/* ! (! defined (__mips_soft_float)&& ! defined (__mips_single_float)) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__mips64
end_ifdef

begin_define
define|#
directive|define
name|__va_next_addr
parameter_list|(
name|__AP
parameter_list|,
name|__type
parameter_list|)
define|\
value|((__AP += __va_reg_size) - __va_reg_size)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__va_next_addr
parameter_list|(
name|__AP
parameter_list|,
name|__type
parameter_list|)
define|\
value|(((__builtin_classify_type (* (__type *) 0)< __record_type_class	\&& __alignof__ (__type)> 4)					\     ? __AP = (char *) (((__PTRDIFF_TYPE__) __AP + 8 - 1)& -8)		\     : (char *) 0),							\    (__builtin_classify_type (* (__type *) 0)>= __record_type_class	\     ? (__AP += __va_reg_size) - __va_reg_size				\     : ((__AP += __va_rounded_size (__type))				\        - __va_rounded_size (__type))))
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
comment|/* ! (! defined (__mips_soft_float)&& ! defined (__mips_single_float)) */
end_comment

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
value|((__va_rounded_size (__type)<= __va_reg_size)			\    ? *(__type *) (void *) (__va_next_addr (__AP, __type)		\ 			   + __va_reg_size				\ 			   - sizeof (__type))				\    : (__builtin_classify_type (*(__type *) 0)>= __record_type_class	\       ? **(__type **) (void *) (__va_next_addr (__AP, __type)		\ 				+ __va_reg_size				\ 				- sizeof (char *))			\       : *(__type *) (void *) __va_next_addr (__AP, __type)))
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
value|((__va_rounded_size (__type)<= __va_reg_size)			\    ? *(__type *) (void *) __va_next_addr (__AP, __type)		\    : (__builtin_classify_type (* (__type *) 0)>= __record_type_class	\       ? **(__type **) (void *) __va_next_addr (__AP, __type)		\       : *(__type *) (void *) __va_next_addr (__AP, __type)))
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
comment|/* ! defined (__mips_eabi) */
end_comment

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
value|((__type *) (void *) (__AP = (char *)                         \                        ((((__PTRDIFF_TYPE__)__AP + 8 - 1)& -8) \ 			   + __va_rounded_size (__type))))[-1]
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
value|((__AP = (char *) ((__alignof__ (__type)> 4			\ 		      ? ((__PTRDIFF_TYPE__)__AP + 8 - 1)& -8	\ 		      : ((__PTRDIFF_TYPE__)__AP + 4 - 1)& -4)	\ 		     + __va_rounded_size (__type))),		\    *(__type *) (void *) (__AP - __va_rounded_size (__type)))
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
value|((__type *) (void *) (__AP = (char *) ((__alignof__(__type)> 4	    \ 				? ((__PTRDIFF_TYPE__)__AP + 8 - 1)& -8	    \ 				: ((__PTRDIFF_TYPE__)__AP + 4 - 1)& -4)    \ 					 + __va_rounded_size(__type))))[-1]
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
comment|/* ! defined (__mips_eabi)  */
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

