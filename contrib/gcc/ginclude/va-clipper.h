begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU C varargs and stdargs support for Clipper.  */
end_comment

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
struct|struct
block|{
name|int
name|__va_ap
decl_stmt|;
comment|/* pointer to stack args */
name|void
modifier|*
name|__va_reg
index|[
literal|4
index|]
decl_stmt|;
comment|/* pointer to r0,f0,r1,f1 */
name|int
name|__va_num
decl_stmt|;
comment|/* number of args processed */
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

begin_typedef
typedef|typedef
name|__gnuc_va_list
name|va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__va_list
value|__gnuc_va_list
end_define

begin_comment
comment|/* acc compatibility */
end_comment

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

begin_define
define|#
directive|define
name|_SYS_INT_STDARG_H
end_define

begin_comment
comment|/* acc compatibility */
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
value|(__builtin_next_arg (LASTARG),		\    (AP) = *(va_list *)__builtin_saveregs(),	\    (AP).__va_num = __builtin_args_info (0),	\    (AP).__va_ap += __builtin_args_info (1))
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

begin_comment
comment|/* The ... causes current_function_varargs to be set in cc1.  */
end_comment

begin_define
define|#
directive|define
name|va_dcl
value|va_list __builtin_va_alist; ...
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|)
define|\
value|((AP) = *(va_list *)__builtin_saveregs(),	\    (AP).__va_num = __builtin_args_info (0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDARG_H */
end_comment

begin_comment
comment|/* round to alignment of `type' but keep a least integer alignment */
end_comment

begin_define
define|#
directive|define
name|__va_round
parameter_list|(
name|AP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|((AP).__va_ap = ((AP).__va_ap + __alignof__ (TYPE) - 1 )&	\    ~(__alignof__ (TYPE) - 1),					\   ((AP).__va_ap = ((AP).__va_ap + sizeof (int) - 1)& ~(sizeof (int) - 1)))
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
value|(*((AP).__va_num< 2&& __builtin_classify_type (* (TYPE *)0)< 12	\    ? (__builtin_classify_type (* (TYPE *)0) == 8			\       ? ((TYPE *)(AP).__va_reg[2 * (AP).__va_num++ + 1])		\       : ((TYPE *)(AP).__va_reg[2 * (AP).__va_num++ ]))			\    : ((AP).__va_num++, __va_round (AP,TYPE), ((TYPE *)((AP).__va_ap))++)))
end_define

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

