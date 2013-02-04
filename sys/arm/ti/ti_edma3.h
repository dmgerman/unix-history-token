begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Damjan Marion<dmarion@Freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TI_EDMA3_H_
end_ifndef

begin_define
define|#
directive|define
name|_TI_EDMA3_H_
end_define

begin_comment
comment|/* Direct Mapped EDMA3 Events */
end_comment

begin_define
define|#
directive|define
name|TI_EDMA3_EVENT_SDTXEVT1
value|2
end_define

begin_define
define|#
directive|define
name|TI_EDMA3_EVENT_SDRXEVT1
value|3
end_define

begin_define
define|#
directive|define
name|TI_EDMA3_EVENT_SDTXEVT0
value|24
end_define

begin_define
define|#
directive|define
name|TI_EDMA3_EVENT_SDRXEVT0
value|25
end_define

begin_struct
struct|struct
name|ti_edma3cc_param_set
block|{
struct|struct
block|{
name|uint32_t
name|sam
range|:
literal|1
decl_stmt|;
comment|/* Source address mode */
name|uint32_t
name|dam
range|:
literal|1
decl_stmt|;
comment|/* Destination address mode */
name|uint32_t
name|syncdim
range|:
literal|1
decl_stmt|;
comment|/* Transfer synchronization dimension */
name|uint32_t
name|static_set
range|:
literal|1
decl_stmt|;
comment|/* Static Set */
name|uint32_t
label|:
literal|4
expr_stmt|;
name|uint32_t
name|fwid
range|:
literal|3
decl_stmt|;
comment|/* FIFO Width */
name|uint32_t
name|tccmode
range|:
literal|1
decl_stmt|;
comment|/* Transfer complete code mode */
name|uint32_t
name|tcc
range|:
literal|6
decl_stmt|;
comment|/* Transfer complete code */
name|uint32_t
label|:
literal|2
expr_stmt|;
name|uint32_t
name|tcinten
range|:
literal|1
decl_stmt|;
comment|/* Transfer complete interrupt enable */
name|uint32_t
name|itcinten
range|:
literal|1
decl_stmt|;
comment|/* Intermediate xfer completion intr. ena */
name|uint32_t
name|tcchen
range|:
literal|1
decl_stmt|;
comment|/* Transfer complete chaining enable */
name|uint32_t
name|itcchen
range|:
literal|1
decl_stmt|;
comment|/* Intermediate xfer completion chaining ena */
name|uint32_t
name|privid
range|:
literal|4
decl_stmt|;
comment|/* Privilege identification */
name|uint32_t
label|:
literal|3
expr_stmt|;
name|uint32_t
name|priv
range|:
literal|1
decl_stmt|;
comment|/* Privilege level */
block|}
name|opt
struct|;
name|uint32_t
name|src
decl_stmt|;
comment|/* Channel Source Address */
name|uint16_t
name|acnt
decl_stmt|;
comment|/* Count for 1st Dimension */
name|uint16_t
name|bcnt
decl_stmt|;
comment|/* Count for 2nd Dimension */
name|uint32_t
name|dst
decl_stmt|;
comment|/* Channel Destination Address */
name|int16_t
name|srcbidx
decl_stmt|;
comment|/* Source B Index */
name|int16_t
name|dstbidx
decl_stmt|;
comment|/* Destination B Index */
name|uint16_t
name|link
decl_stmt|;
comment|/* Link Address */
name|uint16_t
name|bcntrld
decl_stmt|;
comment|/* BCNT Reload */
name|int16_t
name|srccidx
decl_stmt|;
comment|/* Source C Index */
name|int16_t
name|dstcidx
decl_stmt|;
comment|/* Destination C Index */
name|uint16_t
name|ccnt
decl_stmt|;
comment|/* Count for 3rd Dimension */
name|uint16_t
name|reserved
decl_stmt|;
comment|/* Reserved */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ti_edma3_init
parameter_list|(
name|unsigned
name|int
name|eqn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_edma3_request_dma_ch
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|,
name|unsigned
name|int
name|tccn
parameter_list|,
name|unsigned
name|int
name|eqn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_edma3_request_qdma_ch
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|,
name|unsigned
name|int
name|tccn
parameter_list|,
name|unsigned
name|int
name|eqn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_edma3_enable_transfer_manual
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_edma3_enable_transfer_qdma
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_edma3_enable_transfer_event
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ti_edma3_param_write
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|,
name|struct
name|ti_edma3cc_param_set
modifier|*
name|prs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ti_edma3_param_read
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|,
name|struct
name|ti_edma3cc_param_set
modifier|*
name|prs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TI_EDMA3_H_ */
end_comment

end_unit

