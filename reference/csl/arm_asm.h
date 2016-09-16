begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2009 ARM Ltd  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the company may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY ARM LTD ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL ARM LTD BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_ASM__H
end_ifndef

begin_define
define|#
directive|define
name|ARM_ASM__H
end_define

begin_comment
comment|/* First define some macros that keep everything else sane.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7R__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_ISA_ARM_7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_ISA_ARM_7
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_6J__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6T2__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_6K__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6ZK__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_6Z__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_ISA_ARM_6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_ISA_ARM_6
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_5__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_5T__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_5TE__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_5TEJ__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_ISA_ARM_5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_ISA_ARM_5
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_4T__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_ISA_ARM_4T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_7M__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_7EM__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_ISA_THUMB_2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_ISA_THUMB_2
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6M__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_ISA_THUMB_1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Now some macros for common instruction sequences.  */
end_comment

begin_asm
asm|asm(".macro  RETURN	cond=\n\t"
if|#
directive|if
name|defined
argument_list|(
name|_ISA_ARM_4T
argument_list|)
operator|||
name|defined
argument_list|(
name|_ISA_THUMB_1
argument_list|)
asm|"bx\\cond	lr\n\t"
else|#
directive|else
asm|"mov\\cond	pc, lr\n\t"
endif|#
directive|endif
asm|".endm"     );
end_asm

begin_asm
asm|asm(".macro optpld	base, offset=#0\n\t"
if|#
directive|if
name|defined
argument_list|(
name|_ISA_ARM_7
argument_list|)
asm|"pld	[\\base, \\offset]\n\t"
endif|#
directive|endif
asm|".endm"     );
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_ASM__H */
end_comment

end_unit

