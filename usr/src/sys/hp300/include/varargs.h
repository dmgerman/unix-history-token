begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)varargs.h	5.3 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VARARGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_VARARGS_H_
end_define

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_undef
undef|#
directive|undef
name|va_dcl
end_undef

begin_define
define|#
directive|define
name|va_dcl
value|int va_alist;
end_define

begin_undef
undef|#
directive|undef
name|va_start
end_undef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VARARGS_H_ */
end_comment

end_unit

