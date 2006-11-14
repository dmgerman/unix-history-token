begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Charles M. Hannum.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: intr.h,v 1.6 2000/02/11 13:15:44 tsubai Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACPPC_INTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACPPC_INTR_H_
end_define

begin_comment
comment|/* Interrupt priority `levels'. */
end_comment

begin_define
define|#
directive|define
name|IPL_NONE
value|9
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|IPL_SOFTCLOCK
value|8
end_define

begin_comment
comment|/* timeouts */
end_comment

begin_define
define|#
directive|define
name|IPL_SOFTNET
value|7
end_define

begin_comment
comment|/* protocol stacks */
end_comment

begin_define
define|#
directive|define
name|IPL_BIO
value|6
end_define

begin_comment
comment|/* block I/O */
end_comment

begin_define
define|#
directive|define
name|IPL_NET
value|5
end_define

begin_comment
comment|/* network */
end_comment

begin_define
define|#
directive|define
name|IPL_SOFTSERIAL
value|4
end_define

begin_comment
comment|/* serial */
end_comment

begin_define
define|#
directive|define
name|IPL_TTY
value|3
end_define

begin_comment
comment|/* terminal */
end_comment

begin_define
define|#
directive|define
name|IPL_IMP
value|3
end_define

begin_comment
comment|/* memory allocation */
end_comment

begin_define
define|#
directive|define
name|IPL_AUDIO
value|2
end_define

begin_comment
comment|/* audio */
end_comment

begin_define
define|#
directive|define
name|IPL_CLOCK
value|1
end_define

begin_comment
comment|/* clock */
end_comment

begin_define
define|#
directive|define
name|IPL_HIGH
value|1
end_define

begin_comment
comment|/* everything */
end_comment

begin_define
define|#
directive|define
name|IPL_SERIAL
value|0
end_define

begin_comment
comment|/* serial */
end_comment

begin_define
define|#
directive|define
name|NIPL
value|10
end_define

begin_comment
comment|/* Interrupt sharing types. */
end_comment

begin_define
define|#
directive|define
name|IST_NONE
value|0
end_define

begin_comment
comment|/* none */
end_comment

begin_define
define|#
directive|define
name|IST_PULSE
value|1
end_define

begin_comment
comment|/* pulsed */
end_comment

begin_define
define|#
directive|define
name|IST_EDGE
value|2
end_define

begin_comment
comment|/* edge-triggered */
end_comment

begin_define
define|#
directive|define
name|IST_LEVEL
value|3
end_define

begin_comment
comment|/* level-triggered */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * Interrupt handler chains.  intr_establish() inserts a handler into  * the list.  The handler is called with its (single) argument.  */
end_comment

begin_endif
unit|struct intrhand { 	int	(*ih_fun)(void *); 	void	*ih_arg; 	u_long	ih_count; 	struct	intrhand *ih_next; 	int	ih_level; 	int	ih_irq; };
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|setsoftclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clearsoftclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setsoftnet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clearsoftnet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_pending_int
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|softintr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|u_int
name|cpl
decl_stmt|,
name|ipending
decl_stmt|,
name|tickspending
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|imask
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Following code should be implemented with lwarx/stwcx to avoid  * the disable/enable. i need to read the manual once more.... */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|softintr
parameter_list|(
name|int
name|ipl
parameter_list|)
block|{
name|unsigned
name|int
name|msrsave
decl_stmt|;
name|msrsave
operator|=
name|mfmsr
argument_list|()
expr_stmt|;
name|mtmsr
argument_list|(
name|msrsave
operator|&
operator|~
name|PSL_EE
argument_list|)
expr_stmt|;
name|ipending
operator||=
literal|1
operator|<<
name|ipl
expr_stmt|;
name|mtmsr
argument_list|(
name|msrsave
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|ICU_LEN
value|64
end_define

begin_comment
comment|/* Soft interrupt masks. */
end_comment

begin_define
define|#
directive|define
name|SIR_CLOCK
value|28
end_define

begin_define
define|#
directive|define
name|SIR_NET
value|29
end_define

begin_define
define|#
directive|define
name|SIR_SERIAL
value|30
end_define

begin_define
define|#
directive|define
name|SPL_CLOCK
value|31
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * Hardware interrupt masks  */
end_comment

begin_define
define|#
directive|define
name|splbio
parameter_list|()
value|splraise(imask[IPL_BIO])
end_define

begin_define
define|#
directive|define
name|splnet
parameter_list|()
value|splraise(imask[IPL_NET])
end_define

begin_define
define|#
directive|define
name|spltty
parameter_list|()
value|splraise(imask[IPL_TTY])
end_define

begin_define
define|#
directive|define
name|splaudio
parameter_list|()
value|splraise(imask[IPL_AUDIO])
end_define

begin_define
define|#
directive|define
name|splclock
parameter_list|()
value|splraise(imask[IPL_CLOCK])
end_define

begin_define
define|#
directive|define
name|splstatclock
parameter_list|()
value|splclock()
end_define

begin_define
define|#
directive|define
name|splserial
parameter_list|()
value|splraise(imask[IPL_SERIAL])
end_define

begin_define
define|#
directive|define
name|spllpt
parameter_list|()
value|spltty()
end_define

begin_comment
comment|/*  * Software interrupt masks  *  * NOTE: splsoftclock() is used by hardclock() to lower the priority from  * clock to softclock before it calls softclock().  */
end_comment

begin_define
define|#
directive|define
name|spllowersoftclock
parameter_list|()
value|spllower(imask[IPL_SOFTCLOCK])
end_define

begin_define
define|#
directive|define
name|splsoftclock
parameter_list|()
value|splraise(imask[IPL_SOFTCLOCK])
end_define

begin_define
define|#
directive|define
name|splsoftnet
parameter_list|()
value|splraise(imask[IPL_SOFTNET])
end_define

begin_define
define|#
directive|define
name|splsoftserial
parameter_list|()
value|splraise(imask[IPL_SOFTSERIAL])
end_define

begin_comment
comment|/*  * Miscellaneous  */
end_comment

begin_define
define|#
directive|define
name|splimp
parameter_list|()
value|splraise(imask[IPL_IMP])
end_define

begin_define
define|#
directive|define
name|splhigh
parameter_list|()
value|splraise(imask[IPL_HIGH])
end_define

begin_define
define|#
directive|define
name|spl0
parameter_list|()
value|spllower(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|setsoftclock
parameter_list|()
value|softintr(SIR_CLOCK)
end_define

begin_define
define|#
directive|define
name|setsoftnet
parameter_list|()
value|softintr(SIR_NET)
end_define

begin_define
define|#
directive|define
name|setsoftserial
parameter_list|()
value|softintr(SIR_SERIAL)
end_define

begin_define
define|#
directive|define
name|CNT_IRQ0
value|0
end_define

begin_define
define|#
directive|define
name|CNT_CLOCK
value|64
end_define

begin_define
define|#
directive|define
name|CNT_SOFTCLOCK
value|65
end_define

begin_define
define|#
directive|define
name|CNT_SOFTNET
value|66
end_define

begin_define
define|#
directive|define
name|CNT_SOFTSERIAL
value|67
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACPPC_INTR_H_ */
end_comment

end_unit

