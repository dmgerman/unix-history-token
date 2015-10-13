begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 M. Warner Losh<imp@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_OW_OWLL_H
end_ifndef

begin_define
define|#
directive|define
name|DEV_OW_OWLL_H
value|1
end_define

begin_comment
comment|/*  * Generalized parameters for the mode of operation in the bus. All units  * are in nanoseconds, and assume that all timings are< 4s.  * See owll_if.m for timings, and refer to AN937 for details.  */
end_comment

begin_struct
struct|struct
name|ow_timing
block|{
name|uint32_t
name|t_slot
decl_stmt|;
comment|/* Slot time */
name|uint32_t
name|t_low0
decl_stmt|;
comment|/* Time low for a 0 bit. */
name|uint32_t
name|t_low1
decl_stmt|;
comment|/* Time low for a 1 bit. */
name|uint32_t
name|t_lowr
decl_stmt|;
comment|/* Time slave holds line down per bit */
name|uint32_t
name|t_release
decl_stmt|;
comment|/* Time after t_rdv to float high */
name|uint32_t
name|t_rec
decl_stmt|;
comment|/* After sample before M low */
name|uint32_t
name|t_rdv
decl_stmt|;
comment|/* Time to poll the bit after M low */
name|uint32_t
name|t_rstl
decl_stmt|;
comment|/* Time M low on reset */
name|uint32_t
name|t_rsth
decl_stmt|;
comment|/* Time M high on reset */
name|uint32_t
name|t_pdl
decl_stmt|;
comment|/* Time S low on reset */
name|uint32_t
name|t_pdh
decl_stmt|;
comment|/* Time R high after M low on reset */
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|"owll_if.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_OW_OWLL_H */
end_comment

end_unit

