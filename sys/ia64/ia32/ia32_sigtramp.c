begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_decl_stmt
name|char
name|ia32_sigcode
index|[]
init|=
block|{
literal|0xff
block|,
literal|0x54
block|,
literal|0x24
block|,
literal|0x10
block|,
comment|/* call *SIGF_HANDLER(%esp) */
literal|0x8d
block|,
literal|0x44
block|,
literal|0x24
block|,
literal|0x14
block|,
comment|/* lea SIGF_UC(%esp),%eax */
literal|0x50
block|,
comment|/* pushl %eax */
literal|0xf7
block|,
literal|0x40
block|,
literal|0x54
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x02
block|,
literal|0x02
block|,
comment|/* testl $PSL_VM,UC_EFLAGS(%eax) */
literal|0x75
block|,
literal|0x03
block|,
comment|/* jne 9f */
literal|0x8e
block|,
literal|0x68
block|,
literal|0x14
block|,
comment|/* movl UC_GS(%eax),%gs */
literal|0xb8
block|,
literal|0x57
block|,
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 9: movl $SYS_sigreturn,%eax */
literal|0x50
block|,
comment|/* pushl %eax */
literal|0xcd
block|,
literal|0x80
block|,
comment|/* int $0x80 */
literal|0xeb
block|,
literal|0xfe
block|,
comment|/* 0: jmp 0b */
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sz_ia32_sigcode
init|=
sizeof|sizeof
argument_list|(
name|ia32_sigcode
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

