begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)stdarg.h	7.4 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STDARG_H_
end_ifndef

begin_define
define|#
directive|define
name|_STDARG_H_
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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
value|((type *)(ap += sizeof(type)))[-1]
end_define

begin_else
else|#
directive|else
end_else

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
value|((type *)(ap += sizeof(type)< sizeof(int) ? \ 		(abort(), 0) : sizeof(type)))[-1]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|ap
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_STDARG_H_ */
end_comment

end_unit

