begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU C varargs support for the Intel 80960.  */
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
comment|/* The first element is the address of the first argument.    The second element is the number of bytes skipped past so far.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|__gnuc_va_list
index|[
literal|2
index|]
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
comment|/* The stack size of the type t.  */
end_comment

begin_define
define|#
directive|define
name|__vsiz
parameter_list|(
name|T
parameter_list|)
value|(((sizeof (T) + 3) / 4) * 4)
end_define

begin_comment
comment|/* The stack alignment of the type t.  */
end_comment

begin_define
define|#
directive|define
name|__vali
parameter_list|(
name|T
parameter_list|)
value|(__alignof__ (T)>= 4 ? __alignof__ (T) : 4)
end_define

begin_comment
comment|/* The offset of the next stack argument after one of type t at offset i.  */
end_comment

begin_define
define|#
directive|define
name|__vpad
parameter_list|(
name|I
parameter_list|,
name|T
parameter_list|)
value|((((I) + __vali (T) - 1) / __vali (T)) \ 		       * __vali (T) + __vsiz (T))
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

begin_ifdef
ifdef|#
directive|ifdef
name|_STDARG_H
end_ifdef

begin_comment
comment|/* Call __builtin_next_arg even though we aren't using its value, so that    we can verify that firstarg is correct.  */
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
value|__extension__						\ ({ __builtin_next_arg (LASTARG);			\    __asm__ ("st	g14,%0" : "=m" (*(AP)));		\    (AP)[1] = (__builtin_args_info (0) + __builtin_args_info (1)) * 4; })
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
value|char *__builtin_va_alist; __va_ellipsis
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|)
define|\
value|__extension__						\ ({ __asm__ ("st	g14,%0" : "=m" (*(AP)));		\    (AP)[1] = (__builtin_args_info (0) + __builtin_args_info (1)) * 4; })
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
name|AP
parameter_list|,
name|T
parameter_list|)
define|\
value|(									\   (									\     ((AP)[1]<= 48&& (__vpad ((AP)[1], T)> 48 || __vsiz (T)> 16))	\       ? ((AP)[1] = 48 + __vsiz (T))					\       : ((AP)[1] = __vpad ((AP)[1], T))					\   ),									\ 									\   *((T *) (void *) ((char *) *(AP) + (AP)[1] - __vsiz (T)))		\ )
end_define

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
name|AP
parameter_list|)
value|((void) 0)
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

