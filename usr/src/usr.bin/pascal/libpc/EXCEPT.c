begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)EXCEPT.c	8.1 (Berkeley) 6/6/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|/*  * catch runtime arithmetic errors  */
end_comment

begin_macro
name|EXCEPT
argument_list|(
argument|signum
argument_list|,
argument|type
argument_list|)
end_macro

begin_decl_stmt
name|int
name|signum
decl_stmt|,
name|type
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|EXCEPT
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|vax
name|ERROR
argument_list|(
literal|"Overflow, underflow, or division by zero in arithmetic operation\n"
argument_list|)
expr_stmt|;
return|return;
endif|#
directive|endif
endif|notvax
ifdef|#
directive|ifdef
name|vax
comment|/* 	 * The values for this switch statement come from page 12-5 of 	 * Volume 1 of the 1978 VAX 11/780 Architecture Handbook 	 */
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|FPE_INTOVF_TRAP
case|:
name|ERROR
argument_list|(
literal|"Integer overflow\n"
argument_list|)
expr_stmt|;
return|return;
case|case
name|FPE_INTDIV_TRAP
case|:
name|ERROR
argument_list|(
literal|"Integer division by zero\n"
argument_list|)
expr_stmt|;
return|return;
case|case
name|FPE_FLTOVF_TRAP
case|:
case|case
name|FPE_FLTOVF_FAULT
case|:
name|ERROR
argument_list|(
literal|"Real overflow\n"
argument_list|)
expr_stmt|;
return|return;
case|case
name|FPE_FLTDIV_TRAP
case|:
case|case
name|FPE_FLTDIV_FAULT
case|:
name|ERROR
argument_list|(
literal|"Real division by zero\n"
argument_list|)
expr_stmt|;
return|return;
case|case
name|FPE_FLTUND_TRAP
case|:
case|case
name|FPE_FLTUND_FAULT
case|:
name|ERROR
argument_list|(
literal|"Real underflow\n"
argument_list|)
expr_stmt|;
return|return;
case|case
name|FPE_DECOVF_TRAP
case|:
case|case
name|FPE_SUBRNG_TRAP
case|:
default|default:
name|ERROR
argument_list|(
literal|"Undefined arithmetic exception type (%d)\n"
argument_list|,
name|type
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
endif|vax
block|}
end_block

end_unit

