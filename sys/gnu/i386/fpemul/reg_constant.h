begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  reg_constant.h  *  *  * Copyright (C) 1992,1993,1994  *                       W. Metzenthen, 22 Parker St, Ormond, Vic 3163,  *                       Australia.  E-mail   billm@vaxc.cc.monash.edu.au  * All rights reserved.  *  * This copyright notice covers the redistribution and use of the  * FPU emulator developed by W. Metzenthen. It covers only its use  * in the 386BSD, FreeBSD and NetBSD operating systems. Any other  * use is not permitted under this copyright.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must include information specifying  *    that source code for the emulator is freely available and include  *    either:  *      a) an offer to provide the source code for a nominal distribution  *         fee, or  *      b) list at least two alternative methods whereby the source  *         can be obtained, e.g. a publically accessible bulletin board  *         and an anonymous ftp site from which the software can be  *         downloaded.  * 3. All advertising materials specifically mentioning features or use of  *    this emulator must acknowledge that it was developed by W. Metzenthen.  * 4. The name of W. Metzenthen may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * W. METZENTHEN BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  * The purpose of this copyright, based upon the Berkeley copyright, is to  * ensure that the covered software remains freely available to everyone.  *  * The software (with necessary differences) is also available, but under  * the terms of the GNU copyleft, for the Linux operating system and for  * the djgpp ms-dos extender.  *  * W. Metzenthen   June 1994.  *  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_REG_CONSTANT_H_
end_ifndef

begin_define
define|#
directive|define
name|_REG_CONSTANT_H_
end_define

begin_include
include|#
directive|include
file|<gnu/i386/fpemul/fpu_emu.h>
end_include

begin_decl_stmt
specifier|extern
name|FPU_REG
name|CONST_1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FPU_REG
name|CONST_2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FPU_REG
name|CONST_HALF
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FPU_REG
name|CONST_L2T
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FPU_REG
name|CONST_L2E
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FPU_REG
name|CONST_PI
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FPU_REG
name|CONST_PI2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FPU_REG
name|CONST_PI4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FPU_REG
name|CONST_LG2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FPU_REG
name|CONST_LN2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FPU_REG
name|CONST_Z
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FPU_REG
name|CONST_PINF
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FPU_REG
name|CONST_INF
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FPU_REG
name|CONST_MINF
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FPU_REG
name|CONST_QNaN
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _REG_CONSTANT_H_ */
end_comment

end_unit

