begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)machdep.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Most machines require the value returned from malloc to be aligned  * in some way.  The following macro will get this right on many machines.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ALIGN
end_ifndef

begin_union
union|union
name|align
block|{
name|int
name|i
decl_stmt|;
name|char
modifier|*
name|cp
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|ALIGN
parameter_list|(
name|nbytes
parameter_list|)
value|((nbytes) + sizeof(union align) - 1&~ (sizeof(union align) - 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

