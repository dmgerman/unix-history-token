begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1984 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)langpats.c	1.8 (Berkeley) 5/8/91"
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
comment|/*  * Pattern table for kernel specific routines.  * These patterns are based on the old asm.sed script.  */
end_comment

begin_decl_stmt
name|struct
name|pats
name|language_ptab
index|[]
init|=
block|{
block|{
literal|0
block|,
literal|"_spl0\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_spl1\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x11,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_spl3\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x13,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_spl4\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x14,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_spl5\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x15,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_spl7\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x17,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_spl8\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_splimp\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_splsoftclock\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x8,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_splnet\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0xc,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_splbio\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_spltty\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_splclock\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_splhigh\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_splx\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	mfpr	$8,r0\n\ 	mtpr	r1,$8\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_mfpr\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	mfpr	r1,r0\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_mtpr\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r0\n\ 	mtpr	r0,r1\n"
block|}
block|,
ifdef|#
directive|ifdef
name|notdef
block|{
literal|1
block|,
literal|"_uncache\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	mtpr	r1,$0x1c\n"
block|}
block|,
endif|#
directive|endif
block|{
literal|0
block|,
literal|"_setsoftclock\n"
block|,
literal|"	mtpr	$0x8,$0x10\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_fuibyte\n"
block|,
literal|"	callf	$8,_fubyte\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_fuiword\n"
block|,
literal|"	callf	$8,_fuword\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_suibyte\n"
block|,
literal|"	callf	$12,_subyte\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_suiword\n"
block|,
literal|"	callf	$12,_suword\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_ffs\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	ffs	r1,r0\n\ 	bgeq	1f\n\ 	mnegl	$1,r0\n\ 1:\n\ 	incl	r0\n"
block|}
block|,
block|{
literal|2
block|,
literal|"__insque\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	insque	(r0),(r1)\n"
block|}
block|,
block|{
literal|1
block|,
literal|"__remque\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	remque	(r1)\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_imin\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	cmpl	r0,r1\n\ 	bleq	1f\n\ 	movl	r1,r0\n\ 1:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_imax\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	cmpl	r0,r1\n\ 	bgeq	1f\n\ 	movl	r1,r0\n\ 1:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_min\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	cmpl	r0,r1\n\ 	blequ	1f\n\ 	movl	r1,r0\n\ 1:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_max\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	cmpl	r0,r1\n\ 	bgequ	1f\n\ 	movl	r1,r0\n\ 1:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"__movow\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r0\n\ 	movow	r0,(r1)\n"
block|}
block|,
block|{
literal|2
block|,
literal|"__movob\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r0\n\ 	movob	r0,(r1)\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_movpsl\n"
block|,
literal|"	movpsl	r0\n"
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

