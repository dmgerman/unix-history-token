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

begin_comment
comment|/*  * Debugging  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MUTEX_DEBUG
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERN_MUTEX_C_
end_ifdef

begin_decl_stmt
name|char
name|STR_IEN
index|[]
init|=
literal|"ps& IPL == IPL_0"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|STR_IDIS
index|[]
init|=
literal|"ps& IPL == IPL_HIGH"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|STR_SIEN
index|[]
init|=
literal|"mpp->mtx_saveintr == IPL_0"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _KERN_MUTEX_C_ */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|STR_IEN
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|STR_IDIS
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|STR_SIEN
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERN_MUTEX_C_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MUTEX_DEBUG */
end_comment

begin_define
define|#
directive|define
name|ASS_IEN
value|MPASS2((alpha_pal_rdps()& ALPHA_PSL_IPL_MASK)	\ 			       == ALPHA_PSL_IPL_0, STR_IEN)
end_define

begin_define
define|#
directive|define
name|ASS_IDIS
value|MPASS2((alpha_pal_rdps()& ALPHA_PSL_IPL_MASK)	\ 			       == ALPHA_PSL_IPL_HIGH, STR_IDIS)
end_define

begin_define
define|#
directive|define
name|ASS_SIEN
parameter_list|(
name|mpp
parameter_list|)
value|MPASS2((mpp)->mtx_saveintr \ 			       == ALPHA_PSL_IPL_0, STR_SIEN)
end_define

begin_define
define|#
directive|define
name|mtx_legal2block
parameter_list|()
define|\
value|((alpha_pal_rdps()& ALPHA_PSL_IPL_MASK) == ALPHA_PSL_IPL_0)
end_define

begin_comment
comment|/*  * Assembly macros (for internal use only)  *--------------------------------------------------------------------------  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERN_MUTEX_C_
end_ifdef

begin_define
define|#
directive|define
name|_V
parameter_list|(
name|x
parameter_list|)
value|__STRING(x)
end_define

begin_comment
comment|/*  * Get a spin lock, handle recusion inline (as the less common case)  */
end_comment

begin_define
define|#
directive|define
name|_getlock_spin_block
parameter_list|(
name|mp
parameter_list|,
name|tid
parameter_list|,
name|type
parameter_list|)
value|do {				\ 	u_int _ipl = alpha_pal_swpipl(ALPHA_PSL_IPL_HIGH);		\ 	if (!_obtain_lock(mp, tid))					\ 		mtx_enter_hard(mp, (type)& MTX_HARDOPTS, _ipl);	\ 	else {								\ 		alpha_mb();						\ 		(mp)->mtx_saveintr = _ipl;				\ 	}								\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|_V
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERN_MUTEX_C_ */
end_comment

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
value|ldiq	a0, ALPHA_PSL_IPL_HIGH;		\ 	call_pal PAL_OSF1_swpipl;		\ 1:	ldq_l	a0, lck+MTX_LOCK;		\ 	cmpeq	a0, MTX_UNOWNED, a1;		\ 	beq	a1, 1b;				\ 	ldq	a0, PC_CURPROC(globalp);	\ 	stq_c	a0, lck+MTX_LOCK;		\ 	beq	a0, 1b;				\ 	mb;					\ 	stl	v0, lck+MTX_SAVEINTR
end_define

begin_define
define|#
directive|define
name|MTX_EXIT
parameter_list|(
name|lck
parameter_list|)
define|\
value|mb;					\ 	ldiq	a0, MTX_UNOWNED;		\ 	stq	a0, lck+MTX_LOCK;		\ 	ldl	a0, lck+MTX_SAVEINTR;		\ 	call_pal PAL_OSF1_swpipl
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
comment|/* __MACHINE_MUTEX_H */
end_comment

end_unit

