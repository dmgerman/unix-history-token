begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * This is part of the Driver for Video Capture Cards (Frame grabbers)  * and TV Tuner cards using the Brooktree Bt848, Bt848A, Bt849A, Bt878, Bt879  * chipset.  * Copyright Roger Hardiman and Amancio Hasty.  *  * bktr_os : This has all the Operating System dependant code.  *  */
end_comment

begin_comment
comment|/*  * 1. Redistributions of source code must retain the   * Copyright (c) 1997 Amancio Hasty, 1999 Roger Hardiman  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Amancio Hasty and  *      Roger Hardiman  * 4. The name of the author may not be used to endorse or promote products   *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.	IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************/
end_comment

begin_comment
comment|/* *** Memory Allocation  *** */
end_comment

begin_comment
comment|/******************************/
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|)
end_if

begin_function_decl
name|vm_offset_t
name|get_bktr_mem
parameter_list|(
name|int
name|unit
parameter_list|,
name|unsigned
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|)
end_if

begin_function_decl
name|vm_offset_t
name|get_bktr_mem
parameter_list|(
name|bktr_ptr_t
parameter_list|,
name|bus_dmamap_t
modifier|*
parameter_list|,
name|unsigned
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_bktr_mem
parameter_list|(
name|bktr_ptr_t
parameter_list|,
name|bus_dmamap_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************************/
end_comment

begin_comment
comment|/* *** Interrupt Enable/Disable *** */
end_comment

begin_comment
comment|/************************************/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|DECLARE_INTR_MASK
parameter_list|(
name|s
parameter_list|)
value|intrmask_t s
end_define

begin_define
define|#
directive|define
name|DISABLE_INTR
parameter_list|(
name|s
parameter_list|)
value|s=spltty()
end_define

begin_define
define|#
directive|define
name|ENABLE_INTR
parameter_list|(
name|s
parameter_list|)
value|splx(s)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DECLARE_INTR_MASK
parameter_list|(
name|s
parameter_list|)
end_define

begin_comment
comment|/* no need to declare 's' */
end_comment

begin_define
define|#
directive|define
name|DISABLE_INTR
parameter_list|(
name|s
parameter_list|)
value|disable_intr()
end_define

begin_define
define|#
directive|define
name|ENABLE_INTR
parameter_list|(
name|s
parameter_list|)
value|enable_intr()
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

