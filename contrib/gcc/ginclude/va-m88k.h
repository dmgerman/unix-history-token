begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU C varargs support for the Motorola 88100  */
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
name|int
name|__va_arg
decl_stmt|;
comment|/* argument number */
name|int
modifier|*
name|__va_stk
decl_stmt|;
comment|/* start of args passed on stack */
name|int
modifier|*
name|__va_reg
decl_stmt|;
comment|/* start of args passed in regs */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_STDARG_H
end_ifdef

begin_comment
comment|/* stdarg.h support */
end_comment

begin_comment
comment|/* Call __builtin_next_arg even though we aren't using its value, so that    we can verify that LASTARG is correct.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|>
literal|1
end_if

begin_comment
comment|/* GCC 2.0 and beyond */
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
value|(__builtin_next_arg (LASTARG),				\   (AP) = *(__gnuc_va_list *)__builtin_saveregs())
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
value|( (AP).__va_reg = (int *) __builtin_saveregs2(0), \     (AP).__va_stk = (int *) __builtin_argptr(), \     (AP).__va_arg = (int) (__builtin_argsize() + 3) / 4 )
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
comment|/* varargs.h support */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|>
literal|1
end_if

begin_comment
comment|/* GCC 2.0 and beyond */
end_comment

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|)
value|((AP) = *(__gnuc_va_list *)__builtin_saveregs())
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
value|( (AP).__va_reg = (int *) __builtin_saveregs2(1), \     (AP).__va_stk = (int *) __builtin_argptr(), \     (AP).__va_arg = (int) (__builtin_argsize() - 4 + 3) / 4 )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|va_alist
value|__va_1st_arg
end_define

begin_define
define|#
directive|define
name|va_dcl
value|register int va_alist;...
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDARG_H */
end_comment

begin_comment
comment|/* Avoid trouble between this file and _int_varargs.h under DG/UX.  This file    can be included by<stdio.h> and others and provides definitions of    __va_size and __va_reg_p and  a va_list typedef.  Avoid defining va_list    again with _VA_LIST.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT_VARARGS_H
end_ifdef

begin_undef
undef|#
directive|undef
name|__va_size
end_undef

begin_undef
undef|#
directive|undef
name|__va_reg_p
end_undef

begin_define
define|#
directive|define
name|__gnuc_va_list
value|va_list
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Similarly, if this gets included first, do nothing in _int_varargs.h.  */
end_comment

begin_define
define|#
directive|define
name|__INT_VARARGS_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__va_reg_p
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(__builtin_classify_type(*(TYPE *)0)< 12 \    ? sizeof(TYPE)<= 8 : sizeof(TYPE) == 4&& __alignof__(TYPE) == 4)
end_define

begin_define
define|#
directive|define
name|__va_size
parameter_list|(
name|TYPE
parameter_list|)
value|((sizeof(TYPE) + 3)>> 2)
end_define

begin_comment
comment|/* We cast to void * and then to TYPE * because this avoids    a warning about increasing the alignment requirement.  */
end_comment

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
value|( (AP).__va_arg = (((AP).__va_arg + (1<< (__alignof__(TYPE)>> 3)) - 1) \& ~((1<< (__alignof__(TYPE)>> 3)) - 1))		   \     + __va_size(TYPE),							   \     *((TYPE *) (void *) ((__va_reg_p(TYPE)				   \&& (AP).__va_arg< 8 + __va_size(TYPE)	   \ 			  ? (AP).__va_reg : (AP).__va_stk)		   \ 			 + ((AP).__va_arg - __va_size(TYPE)))))
end_define

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

