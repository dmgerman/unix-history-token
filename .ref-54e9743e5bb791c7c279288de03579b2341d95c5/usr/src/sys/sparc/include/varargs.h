begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)varargs.h	8.3 (Berkeley) %G%  *  * from: $Header: varargs.h,v 1.8 93/09/27 00:53:20 torek Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_VARARGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_VARARGS_H_
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|va_list
typedef|;
end_typedef

begin_comment
comment|/* See<machine/stdarg.h> for comments. */
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

begin_define
define|#
directive|define
name|va_dcl
value|int va_alist;
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* gcc2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GCC_NEW_VARARGS__
end_ifdef

begin_comment
comment|/* gcc 2.4.5 */
end_comment

begin_define
define|#
directive|define
name|va_alist
value|__builtin_va_alist
end_define

begin_define
define|#
directive|define
name|va_dcl
value|int __builtin_va_alist;
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* gcc 2.3.3 */
end_comment

begin_define
define|#
directive|define
name|va_dcl
value|int va_alist; ...
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__GCC_NEW_VARARGS__
end_ifdef

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|)
value|((ap) = (char *)__builtin_saveregs())
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|)
value|(__builtin_saveregs(), (ap) = (char *)&va_alist)
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

begin_comment
comment|/* empty */
end_comment

begin_comment
comment|/* Note, we can assume C code here; C++ does not use<varargs.h>. */
end_comment

begin_define
define|#
directive|define
name|__va_8byte
parameter_list|(
name|ap
parameter_list|,
name|ty
parameter_list|)
value|({ \ 	union { ty __d; int __i[2]; } __va_u; \ 	__va_u.__i[0] = ((int *)(void *)(ap))[0]; \ 	__va_u.__i[1] = ((int *)(void *)(ap))[1]; \ 	(ap) += 8; __va_u.__d; })
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|ap
parameter_list|,
name|ty
parameter_list|)
value|__extension__ ({ \     ty __va_temp; \     __builtin_classify_type(__va_temp)>= 12 ? \ 	((ty **)(void *)((ap) += sizeof(ty *)))[-1][0] : \     sizeof(ty) == 8 ? __va_8byte(ap, ty) : \ 	((ty *)(void *)(ap += sizeof(ty)))[-1]; })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_VARARGS_H_ */
end_comment

end_unit

