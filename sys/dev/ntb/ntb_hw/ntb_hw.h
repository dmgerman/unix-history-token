begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2013 Intel Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NTB_HW_H_
end_ifndef

begin_define
define|#
directive|define
name|_NTB_HW_H_
end_define

begin_struct_decl
struct_decl|struct
name|ntb_softc
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|NTB_MAX_NUM_MW
value|2
end_define

begin_enum
enum|enum
name|ntb_link_event
block|{
name|NTB_LINK_DOWN
init|=
literal|0
block|,
name|NTB_LINK_UP
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|ntb_hw_event
block|{
name|NTB_EVENT_SW_EVENT0
init|=
literal|0
block|,
name|NTB_EVENT_SW_EVENT1
block|,
name|NTB_EVENT_SW_EVENT2
block|,
name|NTB_EVENT_HW_ERROR
block|,
name|NTB_EVENT_HW_LINK_UP
block|,
name|NTB_EVENT_HW_LINK_DOWN
block|, }
enum|;
end_enum

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw_ntb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|ntb_db_callback
function_decl|)
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|int
name|db_num
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ntb_event_callback
function_decl|)
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|enum
name|ntb_hw_event
name|event
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|ntb_register_event_callback
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|,
name|ntb_event_callback
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ntb_unregister_event_callback
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ntb_register_db_callback
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|,
name|unsigned
name|int
name|idx
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|ntb_db_callback
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ntb_unregister_db_callback
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|,
name|unsigned
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ntb_find_transport
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ntb_softc
modifier|*
name|ntb_register_transport
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|,
name|void
modifier|*
name|transport
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ntb_unregister_transport
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|ntb_get_max_cbs
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|ntb_get_max_mw
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|ntb_get_max_spads
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ntb_write_local_spad
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|,
name|unsigned
name|int
name|idx
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ntb_read_local_spad
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|,
name|unsigned
name|int
name|idx
parameter_list|,
name|uint32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ntb_write_remote_spad
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|,
name|unsigned
name|int
name|idx
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ntb_read_remote_spad
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|,
name|unsigned
name|int
name|idx
parameter_list|,
name|uint32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ntb_get_mw_vbase
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|,
name|unsigned
name|int
name|mw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_paddr_t
name|ntb_get_mw_pbase
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|,
name|unsigned
name|int
name|mw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|ntb_get_mw_size
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|,
name|unsigned
name|int
name|mw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ntb_set_mw_addr
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|,
name|unsigned
name|int
name|mw
parameter_list|,
name|uint64_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ntb_ring_doorbell
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|,
name|unsigned
name|int
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ntb_query_link_status
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|ntb_get_device
parameter_list|(
name|struct
name|ntb_softc
modifier|*
name|ntb
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NTB_BAR_SIZE_4K
value|(1<< 0)
end_define

begin_comment
comment|/* REGS_THRU_MW is the equivalent of Linux's NTB_HWERR_SDOORBELL_LOCKUP */
end_comment

begin_define
define|#
directive|define
name|NTB_REGS_THRU_MW
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|NTB_SB01BASE_LOCKUP
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|NTB_B2BDOORBELL_BIT14
value|(1<< 3)
end_define

begin_function_decl
name|bool
name|ntb_has_feature
parameter_list|(
name|struct
name|ntb_softc
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NTB_HW_H_ */
end_comment

end_unit

