begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1984, 1986 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)libcpats.c	7.3 (Berkeley) 11/13/91"
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
file|"inline.h"
end_include

begin_comment
comment|/*  * Pattern table for the C library.  */
end_comment

begin_decl_stmt
name|struct
name|pats
name|libc_ptab
index|[]
init|=
block|{
if|#
directive|if
name|defined
argument_list|(
name|NOTDEF
argument_list|)
operator|&&
name|defined
argument_list|(
name|vax
argument_list|)
block|{
literal|1
block|,
literal|"_fgetc\n"
block|,
literal|"	sobgeq	*(sp),1f\n\ 	calls	$1,__filbuf\n\ 	jbr     2f\n\ 1:\n\ 	addl3	$4,(sp)+,r1\n\ 	movzbl	*(r1),r0\n\ 	incl	(r1)\n\ 2:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_fputc\n"
block|,
literal|"	sobgeq	*4(sp),1f\n\ 	calls	$2,__flsbuf\n\ 	jbr	2f\n\ 1:\n\ 	movq	(sp)+,r0\n\ 	movb	r0,*4(r1)\n\ 	incl	4(r1)\n\ 2:\n"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|mc68000
comment|/* someday... */
endif|#
directive|endif
endif|mc68000
block|{
literal|0
block|,
literal|""
block|,
literal|""
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pats
name|vaxsubset_libc_ptab
index|[]
init|=
block|{
block|{
literal|1
block|,
literal|"_strlen\n"
block|,
literal|"	movl	(sp)+,r5\n\ 	movl	r5,r1\n\ 1:\n\ 	tstb	(r1)+\n\ 	jneq	1b\n\ 	decl	r1\n\ 	subl3	r5,r1,r0\n"
block|}
block|,
block|{
literal|0
block|,
literal|""
block|,
literal|""
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pats
name|vax_libc_ptab
index|[]
init|=
block|{
block|{
literal|1
block|,
literal|"_strlen\n"
block|,
literal|"	movl	(sp)+,r5\n\ 	movl	r5,r1\n\ 1:\n\ 	locc	$0,$65535,(r1)\n\ 	jeql	1b\n\ 	subl3	r5,r1,r0\n"
block|}
block|,
block|{
literal|0
block|,
literal|""
block|,
literal|""
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

