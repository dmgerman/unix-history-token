begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, by Steve Passe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the developer may NOT be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: smptests.h,v 1.4 1997/07/06 23:36:49 smp Exp smp $  */
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
comment|/*  * various 'tests in progress'  */
end_comment

begin_comment
comment|/*  * address of POST hardware port  * #define POST_ADDR		0x80  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|POST_ADDR
end_ifdef

begin_comment
comment|/*  * Overwrite the current_postcode low nibble .  */
end_comment

begin_define
define|#
directive|define
name|ASMPOSTCODE_LO
parameter_list|(
name|X
parameter_list|)
define|\
value|movl	_current_postcode, %eax ;	\ 	andl	$0xf0, %eax ;			\ 	orl	$X, %eax ;			\ 	outb	%al, $POST_ADDR
end_define

begin_comment
comment|/*  * Overwrite the current_postcode high nibble .  * Note: this does NOT shift the digit to the high position!  */
end_comment

begin_define
define|#
directive|define
name|ASMPOSTCODE_HI
parameter_list|(
name|X
parameter_list|)
define|\
value|movl	_current_postcode, %eax ;	\ 	andl	$0x0f, %eax ;			\ 	orl	$X, %eax ;			\ 	outb	%al, $POST_ADDR
end_define

begin_else
else|#
directive|else
end_else

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

begin_comment
comment|/*  * misc. counters  * #define COUNT_XINVLTLB_HITS #define COUNT_SPURIOUS_INTS  */
end_comment

begin_comment
comment|/*  * IPI for stop/restart of other CPUs  * #define TEST_CPUSTOP #define DEBUG_CPUSTOP  */
end_comment

begin_comment
comment|/*  * use 'lowest priority' for sending IRQs to CPUs  *  * i386/i386/mplock.s, i386/i386/mpapic.c, kern/init_main.c  *  */
end_comment

begin_define
define|#
directive|define
name|TEST_LOPRIO
end_define

begin_comment
comment|/*  * deal with broken smp_idleloop()  */
end_comment

begin_define
define|#
directive|define
name|IGNORE_IDLEPROCS
end_define

begin_comment
comment|/**  * hack to "fake-out" kernel into thinking it is running on a 'default config'  *  * value == default type #define TEST_DEFAULT_CONFIG	6  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_SMPTESTS_H_ */
end_comment

end_unit

