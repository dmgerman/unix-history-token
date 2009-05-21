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

begin_if
if|#
directive|if
literal|0
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|LOCORE
end_ifdef

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

begin_comment
unit|rlwinm	r0, r10, 0, 17, 15;		\ 	mtmsr	r0;				\ 1:	li	r11, MTX_LOCK;			\
comment|/* MTX_LOCK offset */
end_comment

begin_comment
unit|lwarx	r0, r11, lck;			\
comment|/* load current lock value */
end_comment

begin_comment
unit|cmplwi	r0, r1, MTX_UNOWNED;		\
comment|/* compare with unowned */
end_comment

begin_comment
unit|beq	1;				\
comment|/* if owned, loop */
end_comment

begin_comment
unit|lwz	r0, PC_CURPROC(pcpup);		\
comment|/* load curproc */
end_comment

begin_comment
unit|stwcx.	r0, r11, lck;			\
comment|/* attempt to store */
end_comment

begin_comment
unit|beq	1;				\
comment|/* loop if failed */
end_comment

begin_comment
unit|sync;					\
comment|/* sync */
end_comment

begin_comment
unit|eieio;					\
comment|/* sync */
end_comment

begin_comment
unit|stw	r10, MTX_SAVEINTR(lck)
comment|/* save flags */
end_comment

begin_define
define|#
directive|define
name|MTX_EXIT
parameter_list|(
name|lck
parameter_list|)
define|\
value|sync;					\
end_define

begin_comment
comment|/* sync */
end_comment

begin_comment
unit|eieio;					\
comment|/* sync */
end_comment

begin_comment
unit|li	r0, MTX_UNOWNED;		\
comment|/* load in unowned */
end_comment

begin_comment
unit|stw	r0, MTX_LOCK(lck);		\
comment|/* store to lock */
end_comment

begin_comment
unit|lwz	r0, MTX_SAVEINTR(lck);		\
comment|/* load saved flags */
end_comment

begin_comment
unit|mtmsr	r0
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MACHINE_MUTEX_H */
end_comment

end_unit

