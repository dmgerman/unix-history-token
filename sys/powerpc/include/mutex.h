begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Berkeley Software Design, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from BSDI $Id: mutex.h,v 2.7.2.35 2000/04/27 03:10:26 cp Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_MUTEX_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_MUTEX_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|mtx_intr_enable
parameter_list|(
name|mutex
parameter_list|)
value|do (mutex)->mtx_savecrit |= PSL_EE; while (0)
end_define

begin_comment
comment|/*  * Assembly macros (for internal use only)  *--------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|_V
parameter_list|(
name|x
parameter_list|)
value|__STRING(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !LOCORE */
end_comment

begin_comment
comment|/*  * Simple assembly macros to get and release non-recursive spin locks  */
end_comment

begin_define
define|#
directive|define
name|MTX_ENTER
parameter_list|(
name|lck
parameter_list|)
define|\
value|mfmsr	r10;				\
end_define

begin_comment
comment|/* disable interrupts */
end_comment

begin_decl_stmt
name|rlwinm
name|r0
decl_stmt|,
name|r10
decl_stmt|, 0, 17, 15;
end_decl_stmt

begin_decl_stmt
unit|\
name|mtmsr
name|r0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|\
literal|1
operator|:
name|li
name|r11
operator|,
name|MTX_LOCK
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|\
comment|/* MTX_LOCK offset */
name|lwarx
name|r0
operator|,
name|r11
operator|,
name|lck
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|\
comment|/* load current lock value */
name|cmplwi
name|r0
operator|,
name|r1
operator|,
name|MTX_UNOWNED
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|\
comment|/* compare with unowned */
name|beq
literal|1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|\
comment|/* if owned, loop */
name|lwz
name|r0
operator|,
name|PC_CURPROC
argument_list|(
name|pcpup
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|\
comment|/* load curproc */
name|stwcx
operator|.
name|r0
operator|,
name|r11
operator|,
name|lck
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|\
comment|/* attempt to store */
name|beq
literal|1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|\
comment|/* loop if failed */
name|sync
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|\
comment|/* sync */
name|eieio
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|\
comment|/* sync */
name|stw
name|r10
operator|,
name|MTX_SAVEINTR
argument_list|(
argument|lck
argument_list|)
comment|/* save flags */
define|#
directive|define
name|MTX_EXIT
parameter_list|(
name|lck
parameter_list|)
define|\
value|sync;					\
comment|/* sync */
name|eieio
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|\
comment|/* sync */
name|li
name|r0
operator|,
name|MTX_UNOWNED
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|\
comment|/* load in unowned */
name|stw
name|r0
operator|,
name|MTX_LOCK
argument_list|(
name|lck
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|\
comment|/* store to lock */
name|lwz
name|r0
operator|,
name|MTX_SAVEINTR
argument_list|(
name|lck
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|\
comment|/* load saved flags */
name|mtmsr
name|r0
end_expr_stmt

begin_comment
comment|/* enable interrupts */
end_comment

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
comment|/* __MACHINE_MUTEX_H */
end_comment

end_unit

