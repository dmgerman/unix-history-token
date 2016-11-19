begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Alexander Kabaev<kan@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|JZ4780_CPUREGS_H
end_ifndef

begin_define
define|#
directive|define
name|JZ4780_CPUREGS_H
end_define

begin_comment
comment|/* Core control register */
end_comment

begin_define
define|#
directive|define
name|JZ_CORECTL_SLP1M_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|JZ_CORECTL_SLP1M
value|(1u<< JZ_CORECTL_SLP1M_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_CORECTL_SLP0M_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|JZ_CORECTL_SLP0M
value|(1u<< JZ_CORECTL_SLP0M_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_CORECTL_RPC1_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|JZ_CORECTL_RPC1
value|(1u<< JZ_CORECTL_RPC1_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_CORECTL_RPC0_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|JZ_CORECTL_RPC0
value|(1u<< JZ_CORECTL_RPC0_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_CORECTL_SWRST1_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|JZ_CORECTL_SWRST1
value|(1u<< JZ_CORECTL_SWRST1_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_CORECTL_SWRST0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|JZ_CORECTL_SWRST0
value|(1u<< JZ_CORECTL_SWRST0_SHIFT)
end_define

begin_comment
comment|/* Core status register */
end_comment

begin_define
define|#
directive|define
name|JZ_CORESTS_SLP1_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|JZ_CORESTS_SLP1
value|(1u<< JZ_CORESTS_SLP1_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_CORESTS_SLP0_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|JZ_CORESTS_SLP0
value|(1u<< JZ_CORESTS_SLP0_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_CORESTS_IRQ1P_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|JZ_CORESTS_IRQ1P
value|(1u<< JZ_CORESTS_IRQ1P_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_CORESTS_IRQ0P_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|JZ_CORESTS_IRQ0P
value|(1u<< JZ_CORESTS_IRQ0P_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_CORESTS_MIRQ1P_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|JZ_CORESTS_MIRQ1P
value|(1u<< JZ_CORESTS_MIRQ1P_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_CORESTS_MIRQ0P_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|JZ_CORESTS_MIRQ0P
value|(1u<< JZ_CORESTS_MIRQ0P_SHIFT)
end_define

begin_comment
comment|/* Reset entry and IRQ mask */
end_comment

begin_define
define|#
directive|define
name|JZ_REIM_ENTRY_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|JZ_REIM_ENTRY_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|JZ_REIM_ENTRY_MASK
value|(0xFFFFu<< JZ_REIM_ENTRY_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_REIM_IRQ1M_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|JZ_REIM_IRQ1M
value|(1u<< JZ_REIM_IRQ1M_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_REIM_IRQ0M_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|JZ_REIM_IRQ0M
value|(1u<< JZ_REIM_IRQ0M_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_REIM_MIRQ1M_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|JZ_REIM_MIRQ1M
value|(1u<< JZ_REIM_MIRQ1M_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_REIM_MIRQ0M_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|JZ_REIM_MIRQ0M
value|(1u<< JZ_REIM_MIRQ0M_SHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JZ4780_CPUREGS_H */
end_comment

end_unit

