begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	JNPR: stdarg.h,v 1.3 2006/09/15 12:52:34 katta  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_STDARG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_STDARG_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|3
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_VA_LIST_DECLARED
end_define

begin_typedef
typedef|typedef
name|__va_list
name|va_list
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|v
parameter_list|,
name|l
parameter_list|)
value|__builtin_va_start((v),l)
end_define

begin_define
define|#
directive|define
name|va_end
value|__builtin_va_end
end_define

begin_define
define|#
directive|define
name|va_arg
value|__builtin_va_arg
end_define

begin_define
define|#
directive|define
name|va_copy
value|__builtin_va_copy
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_comment
comment|/* ---------------------------------------- */
end_comment

begin_comment
comment|/*	     VARARGS  for MIPS/GNU CC	    */
end_comment

begin_comment
comment|/* ---------------------------------------- */
end_comment

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

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

begin_typedef
typedef|typedef
name|__gnuc_va_list
name|va_list
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __GNUC_VA_LIST */
end_comment

begin_comment
comment|/* If this is for internal libc use, don't define anything but    __gnuc_va_list.  */
end_comment

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
comment|/* In GCC version 2, we want an ellipsis at the end of the declaration    of the argument list.  GCC version 1 can't parse it.	 */
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
name|va_start
parameter_list|(
name|__AP
parameter_list|,
name|__LASTARG
parameter_list|)
define|\
value|(__AP = (__gnuc_va_list) __builtin_next_arg (__LASTARG))
end_define

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

begin_define
define|#
directive|define
name|__va_rounded_size
parameter_list|(
name|__TYPE
parameter_list|)
value|(((sizeof (__TYPE) + 8 - 1) / 8) * 8)
end_define

begin_define
define|#
directive|define
name|__va_reg_size
value|8
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MIPSEB__
argument_list|)
operator|||
operator|(
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
operator|)
end_if

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
value|((__type *) (void *) (__AP = (char *)				\ 	    ((((__PTRDIFF_TYPE__)__AP + 8 - 1)& -8)			\ 	    + __va_rounded_size (__type))))[-1]
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! __MIPSEB__&& !BYTE_ORDER == BIG_ENDIAN */
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
value|((__AP = (char *) ((((__PTRDIFF_TYPE__)__AP + 8 - 1)& -8)	\ 	    + __va_rounded_size (__type))),				\ 	    *(__type *) (void *) (__AP - __va_rounded_size (__type)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __MIPSEB__&& !BYTE_ORDER == BIG_ENDIAN */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! __mips64 */
end_comment

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

begin_define
define|#
directive|define
name|__va_reg_size
value|4
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MIPSEB__
argument_list|)
operator|||
operator|(
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
operator|)
end_if

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
value|((__AP = (char *) ((__alignof__ (__type)> 4		\ 	    ? ((__PTRDIFF_TYPE__)__AP + 8 - 1)& -8		\ 	    : ((__PTRDIFF_TYPE__)__AP + 4 - 1)& -4)		\ 	    + __va_rounded_size (__type))),			\ 	*(__type *) (void *) (__AP - __va_rounded_size (__type)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! __MIPSEB__&& !BYTE_ORDER == BIG_ENDIAN */
end_comment

begin_comment
comment|/* For little-endian machines.	*/
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
value|((__type *) (void *) (__AP = (char *) ((__alignof__(__type)> 4	\ 	    ? ((__PTRDIFF_TYPE__)__AP + 8 - 1)& -8			\ 	    : ((__PTRDIFF_TYPE__)__AP + 4 - 1)& -4)			\ 	    + __va_rounded_size(__type))))[-1]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __MIPSEB__&& !BYTE_ORDER == BIG_ENDIAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __mips64 */
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

begin_define
define|#
directive|define
name|va_copy
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
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_STDARG_H_ */
end_comment

end_unit

