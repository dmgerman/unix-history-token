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
end_define

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
value|({  type __va_result; \         if ((pvar).__pnt>= 20) { \            __va_result = *( (type *) ((pvar).__stack + (pvar).__pnt - 20)); \ 	   (pvar).__pnt += (sizeof(type) + 7)& ~7; \ 	} \ 	else if ((pvar).__pnt + sizeof(type)> 20) { \ 	   __va_result = * (type *) (pvar).__stack; \ 	   (pvar).__pnt = 20 + ( (sizeof(type) + 7)& ~7); \ 	} \ 	else if (sizeof(type) == 8) { \ 	   union {double d; int i[2];} __u; \ 	   __u.i[0] = *(int *) ((pvar).__regs + (pvar).__pnt); \ 	   __u.i[1] = *(int *) ((pvar).__regs + (pvar).__pnt + 4); \ 	   __va_result = * (type *)&__u; \ 	   (pvar).__pnt += 8; \ 	} \ 	else { \ 	   __va_result = * (type *) ((pvar).__regs + (pvar).__pnt); \ 	   (pvar).__pnt += (sizeof(type) + 3)& ~3; \ 	} \ 	__va_result; })
end_define

end_unit

