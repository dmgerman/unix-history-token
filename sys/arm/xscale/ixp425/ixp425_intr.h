begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ixp425_intr.h,v 1.6 2005/12/24 20:06:52 perry Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2001, 2002 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXP425_INTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXP425_INTR_H_
end_define

begin_define
define|#
directive|define
name|ARM_IRQ_HANDLER
value|_C_LABEL(ixp425_intr_dispatch)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<machine/armreg.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/ixp425/ixp425reg.h>
end_include

begin_define
define|#
directive|define
name|IXPREG
parameter_list|(
name|reg
parameter_list|)
value|*((__volatile u_int32_t*) (reg))
end_define

begin_function_decl
name|void
name|ixp425_do_pending
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|__volatile
name|uint32_t
name|intr_enabled
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|intr_steer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|void
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
name|ixp425_set_intrmask
argument_list|(
name|void
argument_list|)
block|{
name|IXPREG
argument_list|(
name|IXP425_INT_ENABLE
argument_list|)
operator|=
name|intr_enabled
operator|&
name|IXP425_INT_HWMASK
expr_stmt|;
block|}
end_decl_stmt

begin_function
specifier|static
name|__inline
name|void
name|ixp425_set_intrsteer
parameter_list|(
name|void
parameter_list|)
block|{
name|IXPREG
argument_list|(
name|IXP425_INT_SELECT
argument_list|)
operator|=
name|intr_steer
operator|&
name|IXP425_INT_HWMASK
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|__volatile
name|uint32_t
name|intr_enabled2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|intr_steer2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|void
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
name|ixp435_set_intrmask
argument_list|(
name|void
argument_list|)
block|{
name|IXPREG
argument_list|(
name|IXP435_INT_ENABLE2
argument_list|)
operator|=
name|intr_enabled2
operator|&
name|IXP435_INT_HWMASK
expr_stmt|;
block|}
end_decl_stmt

begin_function
specifier|static
name|__inline
name|void
name|ixp435_set_intrsteer
parameter_list|(
name|void
parameter_list|)
block|{
name|IXPREG
argument_list|(
name|IXP435_INT_SELECT2
argument_list|)
operator|=
name|intr_steer2
operator|&
name|IXP435_INT_HWMASK
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXP425_INTR_H_ */
end_comment

end_unit

