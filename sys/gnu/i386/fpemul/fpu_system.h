begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  fpu_system.h  *  *  * Copyright (C) 1992,1993,1994  *                       W. Metzenthen, 22 Parker St, Ormond, Vic 3163,  *                       Australia.  E-mail   billm@vaxc.cc.monash.edu.au  * All rights reserved.  *  * This copyright notice covers the redistribution and use of the  * FPU emulator developed by W. Metzenthen. It covers only its use  * in the 386BSD, FreeBSD and NetBSD operating systems. Any other  * use is not permitted under this copyright.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must include information specifying  *    that source code for the emulator is freely available and include  *    either:  *      a) an offer to provide the source code for a nominal distribution  *         fee, or  *      b) list at least two alternative methods whereby the source  *         can be obtained, e.g. a publically accessible bulletin board  *         and an anonymous ftp site from which the software can be  *         downloaded.  * 3. All advertising materials specifically mentioning features or use of  *    this emulator must acknowledge that it was developed by W. Metzenthen.  * 4. The name of W. Metzenthen may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * W. METZENTHEN BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  * The purpose of this copyright, based upon the Berkeley copyright, is to  * ensure that the covered software remains freely available to everyone.  *  * The software (with necessary differences) is also available, but under  * the terms of the GNU copyleft, for the Linux operating system and for  * the djgpp ms-dos extender.  *  * W. Metzenthen   June 1994.  *  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FPU_SYSTEM_H
end_ifndef

begin_define
define|#
directive|define
name|_FPU_SYSTEM_H
end_define

begin_comment
comment|/* system dependent definitions */
end_comment

begin_comment
comment|/* #include<linux/sched.h> #include<linux/kernel.h> */
end_comment

begin_define
define|#
directive|define
name|I387
value|(*(union i387_union *)&(((struct pcb *)curproc->p_addr)->pcb_save.sv_87))
end_define

begin_define
define|#
directive|define
name|FPU_info
value|(I387.soft.frame)
end_define

begin_define
define|#
directive|define
name|FPU_CS
value|(*(unsigned short *)&(FPU_info->tf_cs))
end_define

begin_define
define|#
directive|define
name|FPU_DS
value|(*(unsigned short *)&(FPU_info->tf_ds))
end_define

begin_define
define|#
directive|define
name|FPU_EAX
value|(FPU_info->tf_eax)
end_define

begin_define
define|#
directive|define
name|FPU_EFLAGS
value|(FPU_info->tf_eflags)
end_define

begin_define
define|#
directive|define
name|FPU_EIP
value|(FPU_info->tf_eip)
end_define

begin_comment
comment|/*#define FPU_ORIG_EIP		(FPU_info->___orig_eip) */
end_comment

begin_comment
comment|/*#define FPU_ORIG_EIP		(FPU_info->tf_isp)*/
end_comment

begin_define
define|#
directive|define
name|FPU_ORIG_EIP
value|(I387.soft.orig_eip)
end_define

begin_define
define|#
directive|define
name|FPU_lookahead
value|(I387.soft.lookahead)
end_define

begin_define
define|#
directive|define
name|FPU_entry_eip
value|(I387.soft.entry_eip)
end_define

begin_define
define|#
directive|define
name|status_word
value|(I387.soft.swd)
end_define

begin_define
define|#
directive|define
name|control_word
value|(I387.soft.cwd)
end_define

begin_define
define|#
directive|define
name|regs
value|(I387.soft.regs)
end_define

begin_define
define|#
directive|define
name|top
value|(I387.soft.top)
end_define

begin_define
define|#
directive|define
name|ip_offset
value|(I387.soft.fip)
end_define

begin_define
define|#
directive|define
name|cs_selector
value|(I387.soft.fcs)
end_define

begin_define
define|#
directive|define
name|data_operand_offset
value|(I387.soft.foo)
end_define

begin_define
define|#
directive|define
name|operand_selector
value|(I387.soft.fos)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

