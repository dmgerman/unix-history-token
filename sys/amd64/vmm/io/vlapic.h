begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VLAPIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_VLAPIC_H_
end_define

begin_struct_decl
struct_decl|struct
name|vm
struct_decl|;
end_struct_decl

begin_enum_decl
enum_decl|enum
name|x2apic_state
enum_decl|;
end_enum_decl

begin_function_decl
name|int
name|vlapic_write
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|int
name|mmio_access
parameter_list|,
name|uint64_t
name|offset
parameter_list|,
name|uint64_t
name|data
parameter_list|,
name|bool
modifier|*
name|retu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vlapic_read
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|int
name|mmio_access
parameter_list|,
name|uint64_t
name|offset
parameter_list|,
name|uint64_t
modifier|*
name|data
parameter_list|,
name|bool
modifier|*
name|retu
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns 0 if there is no eligible vector that can be delivered to the  * guest at this time and non-zero otherwise.  *  * If an eligible vector number is found and 'vecptr' is not NULL then it will  * be stored in the location pointed to by 'vecptr'.  *  * Note that the vector does not automatically transition to the ISR as a  * result of calling this function.  */
end_comment

begin_function_decl
name|int
name|vlapic_pending_intr
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|int
modifier|*
name|vecptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Transition 'vector' from IRR to ISR. This function is called with the  * vector returned by 'vlapic_pending_intr()' when the guest is able to  * accept this interrupt (i.e. RFLAGS.IF = 1 and no conditions exist that  * block interrupt delivery).  */
end_comment

begin_function_decl
name|void
name|vlapic_intr_accepted
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|int
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns 1 if the vcpu needs to be notified of the interrupt and 0 otherwise.  */
end_comment

begin_function_decl
name|int
name|vlapic_set_intr_ready
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|int
name|vector
parameter_list|,
name|bool
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Post an interrupt to the vcpu running on 'hostcpu'. This will use a  * hardware assist if available (e.g. Posted Interrupt) or fall back to  * sending an 'ipinum' to interrupt the 'hostcpu'.  */
end_comment

begin_function_decl
name|void
name|vlapic_post_intr
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|int
name|hostcpu
parameter_list|,
name|int
name|ipinum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vlapic_set_error
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|uint32_t
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vlapic_fire_cmci
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vlapic_trigger_lvt
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|int
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|vlapic_get_apicbase
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vlapic_set_apicbase
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|uint64_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vlapic_set_x2apic_state
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|,
name|int
name|vcpuid
parameter_list|,
name|enum
name|x2apic_state
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|vlapic_enabled
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vlapic_deliver_intr
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|,
name|bool
name|level
parameter_list|,
name|uint32_t
name|dest
parameter_list|,
name|bool
name|phys
parameter_list|,
name|int
name|delmode
parameter_list|,
name|int
name|vec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Reset the trigger-mode bits for all vectors to be edge-triggered */
end_comment

begin_function_decl
name|void
name|vlapic_reset_tmr
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the trigger-mode bit associated with 'vector' to level-triggered if  * the (dest,phys,delmode) tuple resolves to an interrupt being delivered to  * this 'vlapic'.  */
end_comment

begin_function_decl
name|void
name|vlapic_set_tmr_level
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|uint32_t
name|dest
parameter_list|,
name|bool
name|phys
parameter_list|,
name|int
name|delmode
parameter_list|,
name|int
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vlapic_set_cr8
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|uint64_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|vlapic_get_cr8
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* APIC write handlers */
end_comment

begin_function_decl
name|void
name|vlapic_id_write_handler
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vlapic_ldr_write_handler
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vlapic_dfr_write_handler
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vlapic_svr_write_handler
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vlapic_esr_write_handler
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vlapic_icrlo_write_handler
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|bool
modifier|*
name|retu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vlapic_icrtmr_write_handler
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vlapic_dcr_write_handler
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vlapic_lvt_write_handler
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|uint32_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vlapic_self_ipi_handler
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|uint64_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VLAPIC_H_ */
end_comment

end_unit

