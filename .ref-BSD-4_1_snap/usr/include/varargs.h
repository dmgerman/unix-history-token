begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
name|char
modifier|*
name|va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|va_dcl
value|int va_alist;
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|list
parameter_list|)
value|list = (char *)&va_alist
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|list
parameter_list|)
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|list
parameter_list|,
name|mode
parameter_list|)
value|((mode *)(list += sizeof(mode)))[-1]
end_define

end_unit

