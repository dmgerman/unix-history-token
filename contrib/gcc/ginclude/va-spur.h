begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  varargs.h for SPUR */
end_comment

begin_comment
comment|/* NB.  This is NOT the definition needed for the new ANSI proposed    standard */
end_comment

begin_struct
struct|struct
name|__va_struct
block|{
name|char
name|__regs
index|[
literal|20
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|va_alist
value|__va_regs, __va_stack
end_define

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
comment|/* The ... causes current_function_varargs to be set in cc1.  */
end_comment

begin_define
define|#
directive|define
name|va_dcl
value|struct __va_struct __va_regs; int __va_stack;
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|__pnt
decl_stmt|;
name|char
modifier|*
name|__regs
decl_stmt|;
name|char
modifier|*
name|__stack
decl_stmt|;
block|}
name|va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|pvar
parameter_list|)
define|\
value|((pvar).__pnt = 0, (pvar).__regs = __va_regs.__regs, \       (pvar).__stack = (char *)&__va_stack)
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|pvar
parameter_list|)
value|((void)0)
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

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|pvar
parameter_list|,
name|type
parameter_list|)
define|\
value|__extension__ \     (*({  type *__va_result; \         if ((pvar).__pnt>= 20) { \            __va_result = ( (type *) ((pvar).__stack + (pvar).__pnt - 20)); \ 	   (pvar).__pnt += (sizeof(type) + 7)& ~7; \ 	} \ 	else if ((pvar).__pnt + sizeof(type)> 20) { \ 	   __va_result = (type *) (pvar).__stack; \ 	   (pvar).__pnt = 20 + ( (sizeof(type) + 7)& ~7); \ 	} \ 	else if (sizeof(type) == 8) { \ 	   union {double d; int i[2];} __u; \ 	   __u.i[0] = *(int *) ((pvar).__regs + (pvar).__pnt); \ 	   __u.i[1] = *(int *) ((pvar).__regs + (pvar).__pnt + 4); \ 	   __va_result = (type *)&__u; \ 	   (pvar).__pnt += 8; \ 	} \ 	else { \ 	   __va_result = (type *) ((pvar).__regs + (pvar).__pnt); \ 	   (pvar).__pnt += (sizeof(type) + 3)& ~3; \ 	} \ 	__va_result; }))
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

end_unit

