begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  control_w.h  *  *  * Copyright (C) 1992,1993,1994  *                       W. Metzenthen, 22 Parker St, Ormond, Vic 3163,  *                       Australia.  E-mail   billm@vaxc.cc.monash.edu.au  * All rights reserved.  *  * This copyright notice covers the redistribution and use of the  * FPU emulator developed by W. Metzenthen. It covers only its use  * in the 386BSD, FreeBSD and NetBSD operating systems. Any other  * use is not permitted under this copyright.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must include information specifying  *    that source code for the emulator is freely available and include  *    either:  *      a) an offer to provide the source code for a nominal distribution  *         fee, or  *      b) list at least two alternative methods whereby the source  *         can be obtained, e.g. a publically accessible bulletin board  *         and an anonymous ftp site from which the software can be  *         downloaded.  * 3. All advertising materials specifically mentioning features or use of  *    this emulator must acknowledge that it was developed by W. Metzenthen.  * 4. The name of W. Metzenthen may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * W. METZENTHEN BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  * The purpose of this copyright, based upon the Berkeley copyright, is to  * ensure that the covered software remains freely available to everyone.  *  * The software (with necessary differences) is also available, but under  * the terms of the GNU copyleft, for the Linux operating system and for  * the djgpp ms-dos extender.  *  * W. Metzenthen   June 1994.  *  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONTROLW_H_
end_ifndef

begin_define
define|#
directive|define
name|_CONTROLW_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LOCORE
end_ifdef

begin_define
define|#
directive|define
name|_Const_
parameter_list|(
name|x
parameter_list|)
value|$
comment|/**/
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_Const_
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CW_RC
value|_Const_(0x0C00)
end_define

begin_comment
comment|/* rounding control */
end_comment

begin_define
define|#
directive|define
name|CW_PC
value|_Const_(0x0300)
end_define

begin_comment
comment|/* precision control */
end_comment

begin_define
define|#
directive|define
name|CW_Precision
value|Const_(0x0020)
end_define

begin_comment
comment|/* loss of precision mask */
end_comment

begin_define
define|#
directive|define
name|CW_Underflow
value|Const_(0x0010)
end_define

begin_comment
comment|/* underflow mask */
end_comment

begin_define
define|#
directive|define
name|CW_Overflow
value|Const_(0x0008)
end_define

begin_comment
comment|/* overflow mask */
end_comment

begin_define
define|#
directive|define
name|CW_ZeroDiv
value|Const_(0x0004)
end_define

begin_comment
comment|/* divide by zero mask */
end_comment

begin_define
define|#
directive|define
name|CW_Denormal
value|Const_(0x0002)
end_define

begin_comment
comment|/* denormalized operand mask */
end_comment

begin_define
define|#
directive|define
name|CW_Invalid
value|Const_(0x0001)
end_define

begin_comment
comment|/* invalid operation mask */
end_comment

begin_define
define|#
directive|define
name|CW_Exceptions
value|_Const_(0x003f)
end_define

begin_comment
comment|/* all masks */
end_comment

begin_define
define|#
directive|define
name|RC_RND
value|_Const_(0x0000)
end_define

begin_define
define|#
directive|define
name|RC_DOWN
value|_Const_(0x0400)
end_define

begin_define
define|#
directive|define
name|RC_UP
value|_Const_(0x0800)
end_define

begin_define
define|#
directive|define
name|RC_CHOP
value|_Const_(0x0C00)
end_define

begin_comment
comment|/* p 15-5: Precision control bits affect only the following:    ADD, SUB(R), MUL, DIV(R), and SQRT */
end_comment

begin_define
define|#
directive|define
name|PR_24_BITS
value|_Const_(0x000)
end_define

begin_define
define|#
directive|define
name|PR_53_BITS
value|_Const_(0x200)
end_define

begin_define
define|#
directive|define
name|PR_64_BITS
value|_Const_(0x300)
end_define

begin_comment
comment|/* FULL_PRECISION simulates all exceptions masked */
end_comment

begin_define
define|#
directive|define
name|FULL_PRECISION
value|(PR_64_BITS | RC_RND | 0x3f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CONTROLW_H_ */
end_comment

end_unit

