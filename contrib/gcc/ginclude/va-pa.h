begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define __gnuc_va_list. */
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

begin_define
define|#
directive|define
name|__gnuc_va_start
parameter_list|(
name|AP
parameter_list|)
value|((AP) = (va_list)__builtin_saveregs())
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|va_alist
value|__va_a__, __va_b__, __va_c__, __va_d__
end_define

begin_define
define|#
directive|define
name|__va_ellipsis
end_define

begin_define
define|#
directive|define
name|__gnuc_va_start
parameter_list|(
name|AP
parameter_list|)
define|\
value|(AP) = (double *)&__va_a__,&__va_b__,&__va_c__,&__va_d__, \   (AP) = (double *)((char *)(AP) + 4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__> 1 */
end_comment

begin_comment
comment|/* Call __builtin_next_arg even though we aren't using its value, so that    we can verify that LASTARG is correct.  */
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
value|(__builtin_next_arg (LASTARG), __gnuc_va_start (AP))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* The ... causes current_function_varargs to be set in cc1.  */
end_comment

begin_define
define|#
directive|define
name|va_dcl
value|long va_alist; __va_ellipsis
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|)
value|__gnuc_va_start (AP)
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
name|AP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(*(sizeof(TYPE)> 8 ?						\    ((AP = (__gnuc_va_list) ((char *)AP - sizeof (int))),	\     (((TYPE *) (void *) (*((int *) (AP))))))			\    :((AP =							\       (__gnuc_va_list) ((long)((char *)AP - sizeof (TYPE))	\& (sizeof(TYPE)> 4 ? ~0x7 : ~0x3))),	\      (((TYPE *) (void *) ((char *)AP + ((8 - sizeof(TYPE)) % 4)))))))
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

