begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * What follows is an attempt to unify varargs.h and stdarg.h. I'd rather   * have this than #ifdefs all over the code.   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_define
define|#
directive|define
name|VARARGS
parameter_list|(
name|func
parameter_list|,
name|type
parameter_list|,
name|arg
parameter_list|)
value|func(type arg, ...)
end_define

begin_define
define|#
directive|define
name|VASTART
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|,
name|name
parameter_list|)
value|va_start(ap,name)
end_define

begin_define
define|#
directive|define
name|VAEND
parameter_list|(
name|ap
parameter_list|)
value|va_end(ap)
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_define
define|#
directive|define
name|VARARGS
parameter_list|(
name|func
parameter_list|,
name|type
parameter_list|,
name|arg
parameter_list|)
value|func(va_alist) va_dcl
end_define

begin_define
define|#
directive|define
name|VASTART
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|,
name|name
parameter_list|)
value|{type name; va_start(ap); name = va_arg(ap, type)
end_define

begin_define
define|#
directive|define
name|VAEND
parameter_list|(
name|ap
parameter_list|)
value|va_end(ap);}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|percent_m
parameter_list|()
function_decl|;
end_function_decl

end_unit

