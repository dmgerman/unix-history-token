begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * %sccs.include.redist.c%  *  *	@(#)stdarg.h	7.2 (Berkeley) %G%  *  * from: $Header: stdarg.h,v 1.5 92/06/17 06:10:29 torek Exp $  */
end_comment

begin_comment
comment|/*  * SPARC stdarg.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_STDARG_H
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_STDARG_H
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|va_list
typedef|;
end_typedef

begin_comment
comment|/*  * va_start sets ap to point to the first variable argument.  * The `last fixed argument' parameter l is ignored (and should  * never have been included in the ANSI standard!).  *  * va_end cleans up after va_start.  There is nothing to do there.  */
end_comment

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|,
name|l
parameter_list|)
value|(__builtin_saveregs(), \ 			 ap = (char *)__builtin_next_arg())
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

begin_comment
comment|/*  * va_arg picks up the next argument of type `t'.  Appending an  * asterisk to t must produce a pointer to t (i.e., t may not be,  * e.g., `int (*)()').  In addition, t must not be any type which  * undergoes promotion to some other type (e.g., char): it must  * be the promoted type instead.  */
end_comment

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|ap
parameter_list|,
name|t
parameter_list|)
value|(((t *)(ap += sizeof(t)))[-1])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_STDARG_H */
end_comment

end_unit

