begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * %sccs.include.redist.c%  *  *	@(#)varargs.h	7.3 (Berkeley) %G%  *  * from: $Header: varargs.h,v 1.5 92/10/16 04:16:09 torek Exp $  */
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

begin_endif
endif|#
directive|endif
end_endif

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
name|ap
parameter_list|)
value|(__builtin_saveregs(), (ap) = (char *)&va_alist)
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
define|\
value|(sizeof(ty) == 8 ? __extension__ ({ \ 	union { ty __d; int __i[2]; } __u; \ 	__u.__i[0] = ((int *)(ap))[0]; \ 	__u.__i[1] = ((int *)(ap))[1]; \ 	(ap) += 8; \ 	__u.__d; }) : \     ((ty *)(ap += sizeof(ty)))[-1])
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_VARARGS_H_ */
end_comment

end_unit

