begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, by Peter Wemm  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the developer may NOT be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: smpasm.h,v 1.8 1997/04/25 03:11:40 fsmp Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MACHINE_SMPASM_H__
end_ifndef

begin_define
define|#
directive|define
name|__MACHINE_SMPASM_H__
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SMP
argument_list|)
operator|||
name|defined
argument_list|(
name|APIC_IO
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/apic.h>
end_include

begin_comment
comment|/* Macro to retrieve the current CPU id from hardware */
end_comment

begin_define
define|#
directive|define
name|GETCPUID
parameter_list|(
name|reg
parameter_list|)
define|\
value|movl _apic_base, reg;			\ 	movl APIC_ID(reg), reg; 		\ 	andl $APIC_ID_MASK, reg;		\ 	shrl $24, reg;				\ 	movl _apic_id_to_logical(,reg,4), reg
end_define

begin_define
define|#
directive|define
name|SETCURPROC
parameter_list|(
name|val
parameter_list|,
name|reg
parameter_list|)
value|GETCPUID(reg); movl val, _SMPcurproc(,reg,4)
end_define

begin_define
define|#
directive|define
name|GETCURPROC
parameter_list|(
name|reg
parameter_list|)
value|GETCPUID(reg); movl _SMPcurproc(,reg,4), reg
end_define

begin_define
define|#
directive|define
name|SETCURPCB
parameter_list|(
name|val
parameter_list|,
name|reg
parameter_list|)
value|GETCPUID(reg); movl val, _SMPcurpcb(,reg,4)
end_define

begin_define
define|#
directive|define
name|GETCURPCB
parameter_list|(
name|reg
parameter_list|)
value|GETCPUID(reg); movl _SMPcurpcb(,reg,4), reg
end_define

begin_define
define|#
directive|define
name|SETNPXPROC
parameter_list|(
name|val
parameter_list|,
name|reg
parameter_list|)
value|GETCPUID(reg); movl val, _SMPnpxproc(,reg,4)
end_define

begin_define
define|#
directive|define
name|GETNPXPROC
parameter_list|(
name|reg
parameter_list|)
value|GETCPUID(reg); movl _SMPnpxproc(,reg,4), reg
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !SMP&& !APIC_IO */
end_comment

begin_define
define|#
directive|define
name|SETCURPROC
parameter_list|(
name|val
parameter_list|,
name|reg
parameter_list|)
value|movl val, _curproc
end_define

begin_define
define|#
directive|define
name|GETCURPROC
parameter_list|(
name|reg
parameter_list|)
value|movl _curproc, reg
end_define

begin_define
define|#
directive|define
name|SETCURPCB
parameter_list|(
name|val
parameter_list|,
name|reg
parameter_list|)
value|movl val, _curpcb
end_define

begin_define
define|#
directive|define
name|GETCURPCB
parameter_list|(
name|reg
parameter_list|)
value|movl _curpcb, reg
end_define

begin_define
define|#
directive|define
name|SETNPXPROC
parameter_list|(
name|val
parameter_list|,
name|reg
parameter_list|)
value|movl val, _npxproc
end_define

begin_define
define|#
directive|define
name|GETNPXPROC
parameter_list|(
name|reg
parameter_list|)
value|movl _npxproc, reg
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP || APIC_IO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MACHINE_SMPASM_H__ */
end_comment

end_unit

