begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: intr.h,v 1.1 1998/01/10 10:13:14 jb Exp $ */
end_comment

begin_comment
comment|/* From: NetBSD: intr.h,v 1.11 1997/11/10 18:23:50 mjacob Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997 Christopher G. Demetriou.  All rights reserved.  * Copyright (c) 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALPHA_INTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALPHA_INTR_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_define
define|#
directive|define
name|IPL_NONE
value|0
end_define

begin_comment
comment|/* disable only this interrupt */
end_comment

begin_define
define|#
directive|define
name|IPL_BIO
value|1
end_define

begin_comment
comment|/* disable block I/O interrupts */
end_comment

begin_define
define|#
directive|define
name|IPL_NET
value|2
end_define

begin_comment
comment|/* disable network interrupts */
end_comment

begin_define
define|#
directive|define
name|IPL_TTY
value|3
end_define

begin_comment
comment|/* disable terminal interrupts */
end_comment

begin_define
define|#
directive|define
name|IPL_CLOCK
value|4
end_define

begin_comment
comment|/* disable clock interrupts */
end_comment

begin_define
define|#
directive|define
name|IPL_HIGH
value|5
end_define

begin_comment
comment|/* disable all interrupts */
end_comment

begin_define
define|#
directive|define
name|IST_UNUSABLE
value|-1
end_define

begin_comment
comment|/* interrupt cannot be used */
end_comment

begin_define
define|#
directive|define
name|IST_NONE
value|0
end_define

begin_comment
comment|/* none (dummy) */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* IPL-lowering/restoring macros */
end_comment

begin_define
define|#
directive|define
name|splx
parameter_list|(
name|s
parameter_list|)
define|\
value|((s) == ALPHA_PSL_IPL_0 ? spl0() : alpha_pal_swpipl(s))
end_define

begin_define
define|#
directive|define
name|splsoft
parameter_list|()
value|alpha_pal_swpipl(ALPHA_PSL_IPL_SOFT)
end_define

begin_define
define|#
directive|define
name|splsoftclock
parameter_list|()
value|splsoft()
end_define

begin_define
define|#
directive|define
name|splsoftnet
parameter_list|()
value|splsoft()
end_define

begin_comment
comment|/* IPL-raising functions/macros */
end_comment

begin_decl_stmt
specifier|static
name|__inline
name|int
name|_splraise
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|int
name|_splraise
parameter_list|(
name|s
parameter_list|)
name|int
name|s
decl_stmt|;
block|{
name|int
name|cur
init|=
name|alpha_pal_rdps
argument_list|()
operator|&
name|ALPHA_PSL_IPL_MASK
decl_stmt|;
return|return
operator|(
name|s
operator|>
name|cur
condition|?
name|alpha_pal_swpipl
argument_list|(
name|s
argument_list|)
else|:
name|cur
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|splnet
parameter_list|()
value|_splraise(ALPHA_PSL_IPL_IO)
end_define

begin_define
define|#
directive|define
name|splbio
parameter_list|()
value|_splraise(ALPHA_PSL_IPL_IO)
end_define

begin_define
define|#
directive|define
name|splimp
parameter_list|()
value|_splraise(ALPHA_PSL_IPL_IO)
end_define

begin_define
define|#
directive|define
name|spltty
parameter_list|()
value|_splraise(ALPHA_PSL_IPL_IO)
end_define

begin_define
define|#
directive|define
name|splclock
parameter_list|()
value|_splraise(ALPHA_PSL_IPL_CLOCK)
end_define

begin_define
define|#
directive|define
name|splstatclock
parameter_list|()
value|_splraise(ALPHA_PSL_IPL_CLOCK)
end_define

begin_define
define|#
directive|define
name|splhigh
parameter_list|()
value|_splraise(ALPHA_PSL_IPL_HIGH)
end_define

begin_comment
comment|/*  * simulated software interrupt register  */
end_comment

begin_decl_stmt
specifier|extern
name|u_int64_t
name|ssir
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SIR_NET
value|0x1
end_define

begin_define
define|#
directive|define
name|SIR_CLOCK
value|0x2
end_define

begin_define
define|#
directive|define
name|setsoftnet
parameter_list|()
value|ssir |= SIR_NET
end_define

begin_define
define|#
directive|define
name|setsoftclock
parameter_list|()
value|ssir |= SIR_CLOCK
end_define

begin_comment
comment|/*  * Alpha shared-interrupt-line common code.  */
end_comment

begin_struct
struct|struct
name|alpha_shared_intrhand
block|{
name|TAILQ_ENTRY
argument_list|(
argument|alpha_shared_intrhand
argument_list|)
name|ih_q
expr_stmt|;
name|int
argument_list|(
argument|*ih_fn
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
modifier|*
name|ih_arg
decl_stmt|;
name|int
name|ih_level
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|alpha_shared_intr
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|alpha_shared_intrhand
argument_list|)
name|intr_q
expr_stmt|;
name|int
name|intr_sharetype
decl_stmt|;
name|int
name|intr_dfltsharetype
decl_stmt|;
name|int
name|intr_nstrays
decl_stmt|;
name|int
name|intr_maxstrays
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|alpha_shared_intr
modifier|*
name|alpha_shared_intr_alloc
name|__P
argument_list|(
operator|(
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|alpha_shared_intr_dispatch
name|__P
argument_list|(
operator|(
expr|struct
name|alpha_shared_intr
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|alpha_shared_intr_establish
name|__P
argument_list|(
operator|(
expr|struct
name|alpha_shared_intr
operator|*
operator|,
name|unsigned
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|alpha_shared_intr_get_sharetype
name|__P
argument_list|(
operator|(
expr|struct
name|alpha_shared_intr
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|alpha_shared_intr_isactive
name|__P
argument_list|(
operator|(
expr|struct
name|alpha_shared_intr
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alpha_shared_intr_set_dfltsharetype
name|__P
argument_list|(
operator|(
expr|struct
name|alpha_shared_intr
operator|*
operator|,
name|unsigned
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alpha_shared_intr_set_maxstrays
name|__P
argument_list|(
operator|(
expr|struct
name|alpha_shared_intr
operator|*
operator|,
name|unsigned
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alpha_shared_intr_stray
name|__P
argument_list|(
operator|(
expr|struct
name|alpha_shared_intr
operator|*
operator|,
name|unsigned
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

