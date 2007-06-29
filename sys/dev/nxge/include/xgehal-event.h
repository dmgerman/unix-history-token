begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2007 Neterion, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  FileName :    xgehal-event.h  *  *  Description:  event types  *  *  Created:      7 June 2004  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XGE_HAL_EVENT_H
end_ifndef

begin_define
define|#
directive|define
name|XGE_HAL_EVENT_H
end_define

begin_include
include|#
directive|include
file|<dev/nxge/include/xge-os-pal.h>
end_include

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_define
define|#
directive|define
name|XGE_HAL_EVENT_BASE
value|0
end_define

begin_define
define|#
directive|define
name|XGE_LL_EVENT_BASE
value|100
end_define

begin_comment
comment|/**  * enum xge_hal_event_e - Enumerates slow-path HAL events.  * @XGE_HAL_EVENT_UNKNOWN: Unknown (and invalid) event.  * @XGE_HAL_EVENT_SERR: Serious hardware error event.  * @XGE_HAL_EVENT_LINK_IS_UP: The link state has changed from 'down' to  * 'up'; upper-layer driver (typically, link layer) is  * supposed to wake the queue, etc.  * @XGE_HAL_EVENT_LINK_IS_DOWN: Link-down event.  *                    The link state has changed from 'down' to 'up';  *                    upper-layer driver is supposed to stop traffic, etc.  * @XGE_HAL_EVENT_ECCERR: ECC error event.  * @XGE_HAL_EVENT_PARITYERR: Parity error event.  * @XGE_HAL_EVENT_TARGETABORT: Target abort event. Used when device  * aborts transmit operation with the corresponding transfer code  * (for T_CODE enum see xgehal-fifo.h and xgehal-ring.h)  * @XGE_HAL_EVENT_SLOT_FREEZE: Slot-freeze event. Driver tries to distinguish  * slot-freeze from the rest critical events (e.g. ECC) when it is  * impossible to PIO read "through" the bus, i.e. when getting all-foxes.  *  * xge_hal_event_e enumerates slow-path HAL eventis.  *  * See also: xge_hal_uld_cbs_t{}, xge_uld_link_up_f{},  * xge_uld_link_down_f{}.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|xge_hal_event_e
block|{
name|XGE_HAL_EVENT_UNKNOWN
init|=
literal|0
block|,
comment|/* HAL events */
name|XGE_HAL_EVENT_SERR
init|=
name|XGE_HAL_EVENT_BASE
operator|+
literal|1
block|,
name|XGE_HAL_EVENT_LINK_IS_UP
init|=
name|XGE_HAL_EVENT_BASE
operator|+
literal|2
block|,
name|XGE_HAL_EVENT_LINK_IS_DOWN
init|=
name|XGE_HAL_EVENT_BASE
operator|+
literal|3
block|,
name|XGE_HAL_EVENT_ECCERR
init|=
name|XGE_HAL_EVENT_BASE
operator|+
literal|4
block|,
name|XGE_HAL_EVENT_PARITYERR
init|=
name|XGE_HAL_EVENT_BASE
operator|+
literal|5
block|,
name|XGE_HAL_EVENT_TARGETABORT
init|=
name|XGE_HAL_EVENT_BASE
operator|+
literal|6
block|,
name|XGE_HAL_EVENT_SLOT_FREEZE
init|=
name|XGE_HAL_EVENT_BASE
operator|+
literal|7
block|, }
name|xge_hal_event_e
typedef|;
end_typedef

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XGE_HAL_EVENT_H */
end_comment

end_unit

