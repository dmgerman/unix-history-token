begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_typedef
typedef|typedef
name|__builtin_ms_va_list
name|__ms_va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__ms_va_start
parameter_list|(
name|ap
parameter_list|,
name|a
parameter_list|)
value|__builtin_ms_va_start(ap, a)
end_define

begin_define
define|#
directive|define
name|__ms_va_end
parameter_list|(
name|ap
parameter_list|)
value|__builtin_ms_va_end(ap)
end_define

end_unit

