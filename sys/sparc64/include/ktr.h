begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 Berkeley Software Design, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from BSDI $Id: ktr.h,v 1.10.2.7 2000/03/16 21:44:42 cp Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_KTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_KTR_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LOCORE
end_ifdef

begin_define
define|#
directive|define
name|AND
parameter_list|(
name|var
parameter_list|,
name|mask
parameter_list|,
name|r1
parameter_list|,
name|r2
parameter_list|,
name|r3
parameter_list|,
name|l1
parameter_list|)
define|\
value|setx	var, r2, r1 ; \ 	setx	mask, r3, r2 ; \ 	lduw	[r1], r3 ; \ 	and	r2, r3, r1
end_define

begin_define
define|#
directive|define
name|TEST
parameter_list|(
name|var
parameter_list|,
name|mask
parameter_list|,
name|r1
parameter_list|,
name|r2
parameter_list|,
name|r3
parameter_list|,
name|l1
parameter_list|)
define|\
value|AND(var, mask, r1, r2, r3, l1) ; \ 	brz	r1, l1 ## f ; \ 	 nop
end_define

begin_comment
comment|/*  * XXX doesn't do timestamp or ktr_cpu.  */
end_comment

begin_define
define|#
directive|define
name|ATR
parameter_list|(
name|desc
parameter_list|,
name|r1
parameter_list|,
name|r2
parameter_list|,
name|r3
parameter_list|,
name|l1
parameter_list|,
name|l2
parameter_list|)
define|\
value|.sect	.rodata ; \ l1 ## :	.asciz	desc ; \ 	.previous ; \ 	set	ktr_idx, r1 ; \ 	lduw	[r1], r2 ; \ l2 ## :	add	r2, 1, r3 ; \ 	casa	[r1] ASI_N, r2, r3 ; \ 	cmp	r2, r3 ; \ 	bne	%icc, l2 ## b ; \ 	 mov	r3, r2 ; \ 	set	ktr_buf, r1 ; \ 	mulx	r2, KTR_SIZEOF, r2 ; \ 	add	r1, r2, r1 ; \ 	set	l1 ## b, r2 ; \ 	stx	r2, [r1 + KTR_DESC]
end_define

begin_define
define|#
directive|define
name|CATR
parameter_list|(
name|mask
parameter_list|,
name|desc
parameter_list|,
name|r1
parameter_list|,
name|r2
parameter_list|,
name|r3
parameter_list|,
name|l1
parameter_list|,
name|l2
parameter_list|,
name|l3
parameter_list|)
define|\
value|TEST(ktr_mask, mask, r1, r2, r3, l3) ; \ 	ATR(desc, r1, r2, r3, l1, l2)
end_define

begin_comment
comment|/*  * XXX crude conditional breakpoint and sir  */
end_comment

begin_define
define|#
directive|define
name|CBPT
parameter_list|(
name|mask
parameter_list|,
name|r1
parameter_list|,
name|r2
parameter_list|,
name|r3
parameter_list|,
name|l1
parameter_list|)
define|\
value|TEST(ktr_mask, mask, r1, r2, r3, l1) ; \ 	DEBUGGER() ; \ l1 ## :
end_define

begin_define
define|#
directive|define
name|CSIR
parameter_list|(
name|mask
parameter_list|,
name|r1
parameter_list|,
name|r2
parameter_list|,
name|r3
parameter_list|,
name|l1
parameter_list|)
define|\
value|TEST(ktr_mask, mask, r1, r2, r3, l1) ; \ 	sir	42 ; \ l1 ## :
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
comment|/* !_MACHINE_KTR_H_ */
end_comment

end_unit

