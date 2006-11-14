begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFISTDARG_H_
end_ifndef

begin_define
define|#
directive|define
name|_EFISTDARG_H_
end_define

begin_comment
comment|/*++  Copyright (c) 1998  Intel Corporation  Module Name:      devpath.h  Abstract:      Defines for parsing the EFI Device Path structures    Revision History  --*/
end_comment

begin_define
define|#
directive|define
name|_INTSIZEOF
parameter_list|(
name|n
parameter_list|)
value|( (sizeof(n) + sizeof(UINTN) - 1)& ~(sizeof(UINTN) - 1) )
end_define

begin_typedef
typedef|typedef
name|CHAR8
modifier|*
name|va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|,
name|v
parameter_list|)
value|( ap = (va_list)&v + _INTSIZEOF(v) )
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|ap
parameter_list|,
name|t
parameter_list|)
value|( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|ap
parameter_list|)
value|( ap = (va_list)0 )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _INC_STDARG */
end_comment

end_unit

