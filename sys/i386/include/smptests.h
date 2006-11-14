begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996, by Steve Passe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the developer may NOT be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SMPTESTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SMPTESTS_H_
end_define

begin_comment
comment|/*  * Various 'tests in progress' and configuration parameters.  */
end_comment

begin_comment
comment|/*  * Send CPUSTOP IPI for stop/restart of other CPUs on DDB break. #define VERBOSE_CPUSTOP_ON_DDBBREAK  */
end_comment

begin_define
define|#
directive|define
name|CPUSTOP_ON_DDBBREAK
end_define

begin_comment
comment|/*  * TLB counters.  * #define COUNT_XINVLTLB_HITS  */
end_comment

begin_comment
comment|/*  * Per-CPU IPI interrupt counters.  * #define	COUNT_IPIS  */
end_comment

begin_comment
comment|/*  * Address of POST hardware port.  * Defining this enables POSTCODE macros.  * #define POST_ADDR		0x80  */
end_comment

begin_comment
comment|/*  * POST hardware macros.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|POST_ADDR
end_ifdef

begin_define
define|#
directive|define
name|ASMPOSTCODE_INC
define|\
value|pushl	%eax ;				\ 	movl	_current_postcode, %eax ;	\ 	incl	%eax ;				\ 	andl	$0xff, %eax ;			\ 	movl	%eax, _current_postcode ;	\ 	outb	%al, $POST_ADDR ;		\ 	popl	%eax
end_define

begin_comment
comment|/*  * Overwrite the current_postcode value.  */
end_comment

begin_define
define|#
directive|define
name|ASMPOSTCODE
parameter_list|(
name|X
parameter_list|)
define|\
value|pushl	%eax ;				\ 	movl	$X, %eax ;			\ 	movl	%eax, _current_postcode ;	\ 	outb	%al, $POST_ADDR ;		\ 	popl	%eax
end_define

begin_comment
comment|/*  * Overwrite the current_postcode low nibble.  */
end_comment

begin_define
define|#
directive|define
name|ASMPOSTCODE_LO
parameter_list|(
name|X
parameter_list|)
define|\
value|pushl	%eax ;				\ 	movl	_current_postcode, %eax ;	\ 	andl	$0xf0, %eax ;			\ 	orl	$X, %eax ;			\ 	movl	%eax, _current_postcode ;	\ 	outb	%al, $POST_ADDR ;		\ 	popl	%eax
end_define

begin_comment
comment|/*  * Overwrite the current_postcode high nibble.  */
end_comment

begin_define
define|#
directive|define
name|ASMPOSTCODE_HI
parameter_list|(
name|X
parameter_list|)
define|\
value|pushl	%eax ;				\ 	movl	_current_postcode, %eax ;	\ 	andl	$0x0f, %eax ;			\ 	orl	$(X<<4), %eax ;			\ 	movl	%eax, _current_postcode ;	\ 	outb	%al, $POST_ADDR ;		\ 	popl	%eax
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASMPOSTCODE_INC
end_define

begin_define
define|#
directive|define
name|ASMPOSTCODE
parameter_list|(
name|X
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASMPOSTCODE_LO
parameter_list|(
name|X
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASMPOSTCODE_HI
parameter_list|(
name|X
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POST_ADDR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_SMPTESTS_H_ */
end_comment

end_unit

