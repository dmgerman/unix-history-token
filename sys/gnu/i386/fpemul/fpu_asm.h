begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  fpu_asm.h  *  *  * Copyright (C) 1992,1993,1994  *                       W. Metzenthen, 22 Parker St, Ormond, Vic 3163,  *                       Australia.  E-mail   billm@vaxc.cc.monash.edu.au  * All rights reserved.  *  * This copyright notice covers the redistribution and use of the  * FPU emulator developed by W. Metzenthen. It covers only its use  * in the 386BSD, FreeBSD and NetBSD operating systems. Any other  * use is not permitted under this copyright.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must include information specifying  *    that source code for the emulator is freely available and include  *    either:  *      a) an offer to provide the source code for a nominal distribution  *         fee, or  *      b) list at least two alternative methods whereby the source  *         can be obtained, e.g. a publically accessible bulletin board  *         and an anonymous ftp site from which the software can be  *         downloaded.  * 3. All advertising materials specifically mentioning features or use of  *    this emulator must acknowledge that it was developed by W. Metzenthen.  * 4. The name of W. Metzenthen may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * W. METZENTHEN BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  * The purpose of this copyright, based upon the Berkeley copyright, is to  * ensure that the covered software remains freely available to everyone.  *  * The software (with necessary differences) is also available, but under  * the terms of the GNU copyleft, for the Linux operating system and for  * the djgpp ms-dos extender.  *  * W. Metzenthen   June 1994.  *  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FPU_ASM_H_
end_ifndef

begin_define
define|#
directive|define
name|_FPU_ASM_H_
end_define

begin_include
include|#
directive|include
file|<machine/asmacros.h>
end_include

begin_include
include|#
directive|include
file|<gnu/i386/fpemul/fpu_emu.h>
end_include

begin_define
define|#
directive|define
name|EXCEPTION
value|_exception
end_define

begin_define
define|#
directive|define
name|PARAM1
value|8(%ebp)
end_define

begin_define
define|#
directive|define
name|PARAM2
value|12(%ebp)
end_define

begin_define
define|#
directive|define
name|PARAM3
value|16(%ebp)
end_define

begin_define
define|#
directive|define
name|PARAM4
value|20(%ebp)
end_define

begin_define
define|#
directive|define
name|SIGL_OFFSET
value|8
end_define

begin_define
define|#
directive|define
name|SIGN
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|TAG
parameter_list|(
name|x
parameter_list|)
value|1(x)
end_define

begin_define
define|#
directive|define
name|EXP
parameter_list|(
name|x
parameter_list|)
value|4(x)
end_define

begin_define
define|#
directive|define
name|SIG
parameter_list|(
name|x
parameter_list|)
value|SIGL_OFFSET
comment|/**/
value|(x)
end_define

begin_define
define|#
directive|define
name|SIGL
parameter_list|(
name|x
parameter_list|)
value|SIGL_OFFSET
comment|/**/
value|(x)
end_define

begin_define
define|#
directive|define
name|SIGH
parameter_list|(
name|x
parameter_list|)
value|12(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FPU_ASM_H_ */
end_comment

end_unit

