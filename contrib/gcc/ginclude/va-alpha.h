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

begin_comment
comment|/* In VMS, __gnuc_va_list is simply char *; on OSF, it's a structure.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__VMS__
end_ifdef

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

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|__base
decl_stmt|;
comment|/* Pointer to first integer register. */
name|int
name|__offset
decl_stmt|;
comment|/* Byte offset of args so far. */
block|}
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
comment|/* __GNUC_VA_LIST */
end_comment

begin_comment
comment|/* If this is for internal libc use, don't define anything but    __gnuc_va_list.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC_VA_LIST_1
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|_STDARG_H
argument_list|)
operator|||
name|defined
argument_list|(
name|_VARARGS_H
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|__GNUC_VA_LIST_1
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

begin_typedef
typedef|typedef
name|__gnuc_va_list
name|va_list
typedef|;
end_typedef

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
value|int __builtin_va_alist;...
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__VMS__
end_ifdef

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|pvar
parameter_list|)
value|((pvar) = __builtin_saveregs ())
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
name|pvar
parameter_list|)
value|((pvar) = * (__gnuc_va_list *) __builtin_saveregs ())
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
comment|/* STDARG.H */
end_comment

begin_comment
comment|/* ANSI alternative.  */
end_comment

begin_comment
comment|/* Call __builtin_next_arg even though we aren't using its value, so that    we can verify that firstarg is correct.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__VMS__
end_ifdef

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
value|(__builtin_next_arg (firstarg),				\    (pvar) = __builtin_saveregs ())
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
name|pvar
parameter_list|,
name|firstarg
parameter_list|)
define|\
value|(__builtin_next_arg (firstarg),				\    (pvar) = *(__gnuc_va_list *) __builtin_saveregs ())
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
comment|/* _STDARG_H */
end_comment

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|__va
parameter_list|)
value|((void) 0)
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
comment|/* Get the size of a type in bytes, rounded up to an integral number    of words.  */
end_comment

begin_define
define|#
directive|define
name|__va_tsize
parameter_list|(
name|__type
parameter_list|)
define|\
value|(((sizeof (__type) + __extension__ sizeof (long long) - 1)   \     / __extension__ sizeof (long long)) * __extension__ sizeof (long long))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__VMS__
end_ifdef

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
value|(*(((__va) += __va_tsize (__type)),					\    (__type *)(void *)((__va) - __va_tsize (__type))))
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
name|__va
parameter_list|,
name|__type
parameter_list|)
define|\
value|(*(((__va).__offset += __va_tsize (__type)),				\    (__type *)(void *)((__va).__base + (__va).__offset			\ 	      - (((__builtin_classify_type (* (__type *) 0)		\ 		   == __real_type_class)&& (__va).__offset<= (6 * 8))	\ 		 ? (6 * 8) + 8 : __va_tsize (__type)))))
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* __GNUC_VA_LIST_1 */
end_comment

end_unit

