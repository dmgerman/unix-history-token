begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)Areadable.c	7.1 (Berkeley) 12/6/90  */
end_comment

begin_include
include|#
directive|include
file|"align.h"
end_include

begin_function
name|long
name|readable
parameter_list|(
name|infop
parameter_list|,
name|address
parameter_list|,
name|length
parameter_list|)
name|process_info
modifier|*
name|infop
decl_stmt|;
name|long
name|address
decl_stmt|,
name|length
decl_stmt|;
comment|/*  *   Return TRUE (= -1) if the specified bytes can be read without an access  * control violation (limit and/or protection). Page faults are OK.  *   If problems, return the code that would be pushed by HW on the  * stack (see the architecture manual).  *   Assumption is that in most cases, access is OK, so a quick 'prober'  * will be enough. If not, we have to work harder to determine the exact  * cause and return the right code, without getting the fault here in  * the kernel !!.  *  * The address is assumed to be read for the user.!  */
block|{
specifier|register
name|long
name|Register_12
decl_stmt|;
comment|/* Has to be first reg ! */
specifier|register
name|long
name|Register_11
decl_stmt|;
specifier|register
name|long
name|Register_10
decl_stmt|;
specifier|register
name|long
name|Register_9
decl_stmt|;
specifier|register
name|long
name|Register_8
decl_stmt|;
specifier|register
name|long
name|subspace
decl_stmt|;
specifier|register
name|long
name|last_page
decl_stmt|;
name|Register_12
operator|=
name|address
expr_stmt|;
name|Register_11
operator|=
name|length
operator|-
literal|1
expr_stmt|;
asm|asm ("		prober	$1,(r12),$1	");
comment|/* Yeach ... */
asm|asm ("		beql	no_access	");
asm|asm ("		addl2	r11,r12		");
comment|/* last byte */
asm|asm ("		prober	$1,(r12),$1	");
asm|asm ("		beql	no_access	");
asm|asm ("		movl	$-1,r0		");
comment|/* TRUE */
asm|asm ("		ret#1			");
asm|asm ("no_access:			");
comment|/*  * Now the hard work. Have to check length violation first.  * If any byte (first or last) causes a length violation, report it as such.  */
asm|asm ("	mfpr	$3,r8	");
comment|/* Get length registers. P0LR */
asm|asm ("	mfpr	$5,r9	");
comment|/* P1LR */
asm|asm ("	mfpr	$7,r10	");
comment|/* P2LR */
asm|asm ("	mfpr	$1,r11	");
comment|/* SLR  */
name|subspace
operator|=
operator|(
name|address
operator|>>
literal|30
operator|)
operator|&
literal|3
expr_stmt|;
name|Register_12
operator|=
operator|(
name|address
operator|>>
literal|10
operator|)
operator|&
literal|0xfffff
expr_stmt|;
comment|/* 1'st byte page # */
name|last_page
operator|=
operator|(
operator|(
name|address
operator|+
name|length
operator|-
literal|1
operator|)
operator|>>
literal|10
operator|)
operator|&
literal|0xfffff
expr_stmt|;
switch|switch
condition|(
name|subspace
condition|)
block|{
case|case
literal|0
case|:
if|if
condition|(
operator|(
name|Register_12
operator|>=
name|Register_8
operator|)
operator|||
operator|(
name|last_page
operator|>=
name|Register_8
operator|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
break|break;
case|case
literal|1
case|:
if|if
condition|(
operator|(
name|Register_12
operator|>=
name|Register_9
operator|)
operator|||
operator|(
name|last_page
operator|>=
name|Register_9
operator|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
break|break;
case|case
literal|2
case|:
if|if
condition|(
operator|(
name|Register_12
operator|<
name|Register_10
operator|)
operator|||
operator|(
name|last_page
operator|<
name|Register_10
operator|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
break|break;
case|case
literal|3
case|:
if|if
condition|(
operator|(
name|Register_12
operator|>=
name|Register_11
operator|)
operator|||
operator|(
name|last_page
operator|>=
name|Register_11
operator|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
break|break;
block|}
comment|/*  * OK, it's not a length violation. Must have been an access problem  * (no read by user).  *  * NOTE : I definitely ignore the case of 'no PTE access' since I  *	assume that's not the case for user mode. Besides, the poor  *	guy will just get an access violation that will most probably  *	send him into hyperspace anyway, so no need to be too acurate here.  */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

