begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)stdarg.h	5.2 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|va_list
typedef|;
end_typedef

begin_comment
comment|/*  * ANSI says: "If there is no actual next argument, or if type is not  * compatible with the type of the actual next argument (as promoted  * according to the default argument promotions), the behavior is  * undefined."  We read this to mean that we're not allowed to do the  * promotion for the user, so shorts and chars drop core.  */
end_comment

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
value|((type *)(ap += sizeof(type)< sizeof(int) ? \ 		abort() : sizeof(type)))[-1]
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
name|__va_promote
parameter_list|(
name|type
parameter_list|)
define|\
value|(((sizeof(type) + sizeof(int) - 1) / sizeof(int)) * sizeof(int))
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|,
name|last
parameter_list|)
define|\
value|(ap = ((char *)&(last) + __va_promote(last)))
end_define

end_unit

