begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  *  * 	Varargs for PYR/GNU CC  *  * WARNING -- WARNING -- DANGER  *  * The code in this file implements varargs for gcc on a pyr in  * a way that is compatible with code compiled by the Pyramid Technology  * C compiler.  * As such, it depends strongly on the Pyramid conventions for  * parameter passing.ct and independent implementation.   * These (somewhat bizarre) parameter-passing conventions are described  * in the ``OSx Operating System Porting Guide''.  *   * A quick summary is useful:  * 12 of the 48 register-windowed regs available for  * parameter passing.  Parameters of a function call that are eligible  * to be passed in registers are assigned registers from TR0/PR0 onwards;  * all other arguments are passed on the stack.  * Structure and union parameters are *never* passed in registers,  * even if they are small enough to fit.  They are always passed on  * the stack.  *  * Double-sized parameters cannot be passed in TR11, because  * TR12 is not used for passing parameters.  If, in the absence of this  * rule, a double-sized param would have been passed in TR11,  * that parameter is passed on the stack and no parameters are  * passed in TR11.  *   * It is only known to work for passing 32-bit integer quantities  * (ie chars, shorts, ints/enums, longs), doubles, or pointers.   * Passing structures on a Pyramid via varargs is a loser.  * Passing an object larger than 8 bytes on a pyramid via varargs may  * also be a loser.  *   */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  *  pointer to next stack parameter in __va_buf[0]  *  pointer to next parameter register in __va_buf[1]  *  Count of registers seen at __va_buf[2]  *  saved pr0..pr11 in __va_buf[3..14]  *  # of calls to va_arg (debugging) at __va_buf[15]  */
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
name|__voidptr
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|1
end_if

begin_typedef
typedef|typedef
struct|struct
name|__va_regs
block|{
name|__voidptr
name|__stackp
decl_stmt|,
name|__regp
decl_stmt|,
name|__count
decl_stmt|;
name|__voidptr
name|__pr0
decl_stmt|,
name|__pr1
decl_stmt|,
name|__pr2
decl_stmt|,
name|__pr3
decl_stmt|,
name|__pr4
decl_stmt|,
name|__pr5
decl_stmt|,
name|__pr6
decl_stmt|,
name|__pr7
decl_stmt|,
name|__pr8
decl_stmt|,
name|__pr9
decl_stmt|,
name|__pr10
decl_stmt|,
name|__pr11
decl_stmt|;
block|}
name|__va_regs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__va_regs
name|__va_buf
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __va_buf[0] = address of next arg passed on the stack    __va_buf[1] = address of next arg passed in a register    __va_buf[2] = register-# of next arg passed in a register  */
end_comment

begin_typedef
typedef|typedef
name|__voidptr
argument_list|(
operator|*
name|__va_buf
argument_list|)
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__va_buf
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

begin_escape
end_escape

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

begin_define
define|#
directive|define
name|va_alist
define|\
value|__va0,__va1,__va2,__va3,__va4,__va5,__va6,__va7,__va8,__va9,__va10,__va11, \  __builtin_va_alist
end_define

begin_comment
comment|/* The ... causes current_function_varargs to be set in cc1.  */
end_comment

begin_define
define|#
directive|define
name|va_dcl
value|__voidptr va_alist; __va_ellipsis
end_define

begin_comment
comment|/* __asm ("rcsp %0" : "=r" ( _AP [0]));*/
end_comment

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|_AP
parameter_list|)
define|\
value|_AP =  ((struct __va_regs) {						\&(_AP.__pr0), (void*)&__builtin_va_alist, (void*)0,			\         __va0,__va1,__va2,__va3,__va4,__va5,				\ 	__va6,__va7,__va8,__va9,__va10,__va11})
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
comment|/* We cast to void * and then to TYPE * because this avoids    a warning about increasing the alignment requirement.  */
end_comment

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|_AP
parameter_list|,
name|_MODE
parameter_list|)
define|\
value|__extension__								\ (*({__voidptr *__ap = (__voidptr*)&_AP;					\   register int __size = sizeof (_MODE);					\   register int __onstack =						\ 	  (__size> 8 || ( (int)(__ap[2])> 11) ||			\ 	    (__size==8&& (int)(__ap[2])==11));				\   register int* __param_addr =  ((int*)((__ap) [__onstack]));		\ 									\   ((void *)__ap[__onstack])+=__size;					\     if (__onstack==0 || (int)(__ap[2])==11)				\       __ap[2]+= (__size>> 2);						\   (( _MODE *) (void *) __param_addr);					\ }))
end_define

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

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|_X
parameter_list|)
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (_STDARG_H) || defined (_VARARGS_H) */
end_comment

end_unit

