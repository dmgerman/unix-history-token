begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  status_w.h  *  *  * Copyright (C) 1992,1993,1994  *                       W. Metzenthen, 22 Parker St, Ormond, Vic 3163,  *                       Australia.  E-mail   billm@vaxc.cc.monash.edu.au  * All rights reserved.  *  * This copyright notice covers the redistribution and use of the  * FPU emulator developed by W. Metzenthen. It covers only its use  * in the 386BSD, FreeBSD and NetBSD operating systems. Any other  * use is not permitted under this copyright.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must include information specifying  *    that source code for the emulator is freely available and include  *    either:  *      a) an offer to provide the source code for a nominal distribution  *         fee, or  *      b) list at least two alternative methods whereby the source  *         can be obtained, e.g. a publically accessible bulletin board  *         and an anonymous ftp site from which the software can be  *         downloaded.  * 3. All advertising materials specifically mentioning features or use of  *    this emulator must acknowledge that it was developed by W. Metzenthen.  * 4. The name of W. Metzenthen may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * W. METZENTHEN BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  * The purpose of this copyright, based upon the Berkeley copyright, is to  * ensure that the covered software remains freely available to everyone.  *  * The software (with necessary differences) is also available, but under  * the terms of the GNU copyleft, for the Linux operating system and for  * the djgpp ms-dos extender.  *  * W. Metzenthen   June 1994.  *  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STATUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_STATUS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LOCORE
end_ifdef

begin_define
define|#
directive|define
name|Const__
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
name|Const__
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
name|SW_Backward
value|Const__(0x8000)
end_define

begin_comment
comment|/* backward compatibility */
end_comment

begin_define
define|#
directive|define
name|SW_C3
value|Const__(0x4000)
end_define

begin_comment
comment|/* condition bit 3 */
end_comment

begin_define
define|#
directive|define
name|SW_Top
value|Const__(0x3800)
end_define

begin_comment
comment|/* top of stack */
end_comment

begin_define
define|#
directive|define
name|SW_Top_Shift
value|Const__(11)
end_define

begin_comment
comment|/* shift for top of stack bits */
end_comment

begin_define
define|#
directive|define
name|SW_C2
value|Const__(0x0400)
end_define

begin_comment
comment|/* condition bit 2 */
end_comment

begin_define
define|#
directive|define
name|SW_C1
value|Const__(0x0200)
end_define

begin_comment
comment|/* condition bit 1 */
end_comment

begin_define
define|#
directive|define
name|SW_C0
value|Const__(0x0100)
end_define

begin_comment
comment|/* condition bit 0 */
end_comment

begin_define
define|#
directive|define
name|SW_Summary
value|Const__(0x0080)
end_define

begin_comment
comment|/* exception summary */
end_comment

begin_define
define|#
directive|define
name|SW_Stack_Fault
value|Const__(0x0040)
end_define

begin_comment
comment|/* stack fault */
end_comment

begin_define
define|#
directive|define
name|SW_Precision
value|Const__(0x0020)
end_define

begin_comment
comment|/* loss of precision */
end_comment

begin_define
define|#
directive|define
name|SW_Underflow
value|Const__(0x0010)
end_define

begin_comment
comment|/* underflow */
end_comment

begin_define
define|#
directive|define
name|SW_Overflow
value|Const__(0x0008)
end_define

begin_comment
comment|/* overflow */
end_comment

begin_define
define|#
directive|define
name|SW_Zero_Div
value|Const__(0x0004)
end_define

begin_comment
comment|/* divide by zero */
end_comment

begin_define
define|#
directive|define
name|SW_Denorm_Op
value|Const__(0x0002)
end_define

begin_comment
comment|/* denormalized operand */
end_comment

begin_define
define|#
directive|define
name|SW_Invalid
value|Const__(0x0001)
end_define

begin_comment
comment|/* invalid operation */
end_comment

begin_define
define|#
directive|define
name|SW_Exc_Mask
value|Const__(0x27f)
end_define

begin_comment
comment|/* Status word exception bit mask */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_define
define|#
directive|define
name|COMP_A_gt_B
value|1
end_define

begin_define
define|#
directive|define
name|COMP_A_eq_B
value|2
end_define

begin_define
define|#
directive|define
name|COMP_A_lt_B
value|3
end_define

begin_define
define|#
directive|define
name|COMP_No_Comp
value|4
end_define

begin_define
define|#
directive|define
name|COMP_Denormal
value|0x20
end_define

begin_define
define|#
directive|define
name|COMP_NaN
value|0x40
end_define

begin_define
define|#
directive|define
name|COMP_SNaN
value|0x80
end_define

begin_define
define|#
directive|define
name|setcc
parameter_list|(
name|cc
parameter_list|)
value|({ \   status_word&= ~(SW_C0|SW_C1|SW_C2|SW_C3); \   status_word |= (cc)& (SW_C0|SW_C1|SW_C2|SW_C3); })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STATUS_H_ */
end_comment

end_unit

