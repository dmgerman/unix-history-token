begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)varargs.h	5.1 (Berkeley) %G%  */
end_comment

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
name|__va_round
parameter_list|(
name|type
parameter_list|)
define|\
value|(((sizeof(type) + sizeof(int) - 1) / sizeof(int)) * sizeof(int))
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
define|\
value|((type *)(ap += __va_round(type)))[-1]
end_define

begin_define
define|#
directive|define
name|va_dcl
value|int va_alist;
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|ap
parameter_list|)
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|)
define|\
value|ap = (char *)&va_alist
end_define

end_unit

