begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sean Eric Fagan.  *  * %sccs.include.redist.c%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)ldexp.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_comment
comment|/*  * ldexp(value, exp): return value * (2 ** exp).  *  * Written by Sean Eric Fagan (sef@kithrup.COM)  * Sun Mar 11 20:27:09 PST 1990  */
end_comment

begin_comment
comment|/*  * We do the conversion in C to let gcc optimize it away, if possible.  * The "fxch ; fstp" stuff is because value is still on the stack  * (stupid 8087!).  */
end_comment

begin_function
name|double
name|ldexp
parameter_list|(
name|double
name|value
parameter_list|,
name|int
name|exp
parameter_list|)
block|{
name|double
name|temp
decl_stmt|,
name|texp
decl_stmt|,
name|temp2
decl_stmt|;
name|texp
operator|=
name|exp
expr_stmt|;
asm|asm ("fscale ; fxch %%st(1) ; fstp%L1 %1 " 		: "=f" (temp), "=0" (temp2) 		: "0" (texp), "f" (value));
return|return
operator|(
name|temp
operator|)
return|;
block|}
end_function

end_unit

