begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_expr_stmt
operator|.
name|asciz
literal|"@(#)getdtablesize.c	5.2 (Berkeley) 4/12/91"
endif|#
directive|endif
comment|/* LIBC_SCCS and not lint */
include|#
directive|include
file|"SYS.h"
operator|.
name|data
name|dtablesize
operator|:
operator|.
name|long
literal|0
operator|.
name|text
name|ENTRY
argument_list|(
argument|getdtablesize
argument_list|)
name|movl
name|dtablesize
operator|,
name|r0
operator|#
name|check
name|cache
name|beql
name|doit
name|ret
name|doit
operator|:
name|chmk
name|$SYS_getdtablesize
name|jcs
name|err
name|movl
name|r0
operator|,
name|dtablesize
operator|#
name|set
name|cache
name|ret
operator|#
name|dtablesize
operator|=
name|dtablesize
argument_list|()
expr_stmt|;
end_expr_stmt

begin_label
name|err
label|:
end_label

begin_decl_stmt
name|jmp
name|cerror
decl_stmt|;
end_decl_stmt

end_unit

