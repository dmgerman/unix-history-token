begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Takanori Watanabe<takawata@shidahara1.planet.sci.kobe-u.ac.jp>  * Copyright (c) 1999, 2000 Mitsuru IWASAKI<iwasaki@FreeBSD.org>  * Copyright (c) 2000 Michael Smith<msmith@FreeBSD.org>  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*   * PowerResource control   */
end_comment

begin_struct
struct|struct
name|acpi_powerres_device
block|{
name|LIST_ENTRY
argument_list|(
argument|acpi_powerres_device
argument_list|)
name|links
expr_stmt|;
name|struct
name|aml_name
modifier|*
name|name
decl_stmt|;
comment|/* _PR[0-2] */
name|u_int8_t
name|state
decl_stmt|;
comment|/* D0 to D3 */
name|u_int8_t
name|next_state
decl_stmt|;
comment|/* initialized with D0 */
define|#
directive|define
name|ACPI_D_STATE_D0
value|0
define|#
directive|define
name|ACPI_D_STATE_D1
value|1
define|#
directive|define
name|ACPI_D_STATE_D2
value|2
define|#
directive|define
name|ACPI_D_STATE_D3
value|3
define|#
directive|define
name|ACPI_D_STATE_UNKNOWN
value|255
comment|/* _PRW */
name|u_int8_t
name|wake_cap
decl_stmt|;
comment|/* wake capability */
define|#
directive|define
name|ACPI_D_WAKECAP_DISABLE
value|0
define|#
directive|define
name|ACPI_D_WAKECAP_ENABLE
value|1
define|#
directive|define
name|ACPI_D_WAKECAP_UNKNOWN
value|255
define|#
directive|define
name|ACPI_D_WAKECAP_DEFAULT
value|1
comment|/* XXX default enable for testing */
name|boolean_t
name|gpe_enabled
decl_stmt|;
comment|/* GEPx_EN enabled/disabled */
name|union
name|aml_object
modifier|*
name|prw_val
index|[
literal|2
index|]
decl_stmt|;
comment|/* elements of _PRW package */
block|}
struct|;
end_struct

begin_comment
comment|/* Device Power Management Chained Object Type */
end_comment

begin_define
define|#
directive|define
name|ACPI_D_PM_TYPE_IRC
value|0
end_define

begin_comment
comment|/* _IRC */
end_comment

begin_define
define|#
directive|define
name|ACPI_D_PM_TYPE_PRW
value|1
end_define

begin_comment
comment|/* _PRW */
end_comment

begin_define
define|#
directive|define
name|ACPI_D_PM_TYPE_PRX
value|2
end_define

begin_comment
comment|/* _PR0 - _PR2 */
end_comment

begin_comment
comment|/* and more... */
end_comment

begin_struct
struct|struct
name|acpi_powerres_device_ref
block|{
name|LIST_ENTRY
argument_list|(
argument|acpi_powerres_device_ref
argument_list|)
name|links
expr_stmt|;
name|struct
name|acpi_powerres_device
modifier|*
name|device
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|acpi_powerres_info
block|{
name|LIST_ENTRY
argument_list|(
argument|acpi_powerres_info
argument_list|)
name|links
expr_stmt|;
name|struct
name|aml_name
modifier|*
name|name
decl_stmt|;
name|u_int8_t
name|state
decl_stmt|;
comment|/* OFF or ON */
define|#
directive|define
name|ACPI_POWER_RESOURCE_ON
value|1
define|#
directive|define
name|ACPI_POWER_RESOURCE_OFF
value|0
define|#
directive|define
name|ACPI_PR_MAX
value|3
comment|/* _PR[0-2] */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|acpi_powerres_device_ref
argument_list|)
name|reflist
index|[
name|ACPI_PR_MAX
index|]
expr_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|acpi_powerres_device_ref
argument_list|)
name|prwlist
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Event Structure   */
end_comment

begin_struct
struct|struct
name|acpi_event
block|{
name|STAILQ_ENTRY
argument_list|(
argument|acpi_event
argument_list|)
name|ae_q
expr_stmt|;
name|int
name|ae_type
decl_stmt|;
define|#
directive|define
name|ACPI_EVENT_TYPE_FIXEDREG
value|0
define|#
directive|define
name|ACPI_EVENT_TYPE_GPEREG
value|1
define|#
directive|define
name|ACPI_EVENT_TYPE_EC
value|2
name|int
name|ae_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * I/O resource structure  */
end_comment

begin_define
define|#
directive|define
name|ACPI_RES_SMI_CMD
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_RES_PM1A_EVT
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_RES_PM1B_EVT
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_RES_PM1A_CNT
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_RES_PM1B_CNT
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_RES_PM2_CNT
value|5
end_define

begin_define
define|#
directive|define
name|ACPI_RES_PM_TMR
value|6
end_define

begin_define
define|#
directive|define
name|ACPI_RES_GPE0
value|7
end_define

begin_define
define|#
directive|define
name|ACPI_RES_GPE1
value|8
end_define

begin_define
define|#
directive|define
name|ACPI_RES_FIRSTFREE
value|9
end_define

begin_define
define|#
directive|define
name|ACPI_RES_AUTO
value|-1
end_define

begin_define
define|#
directive|define
name|ACPI_RES_MAX
value|64
end_define

begin_struct
struct|struct
name|acpi_io_resource
block|{
name|struct
name|resource
modifier|*
name|rsc
decl_stmt|;
name|int
name|rid
decl_stmt|;
name|int
name|size
decl_stmt|;
name|bus_space_handle_t
name|bhandle
decl_stmt|;
name|bus_space_tag_t
name|btag
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*   * Softc   */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|dev_t
name|dev_t
decl_stmt|;
name|struct
name|acpi_io_resource
name|iores
index|[
name|ACPI_RES_MAX
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
name|void
modifier|*
name|irq_handle
decl_stmt|;
name|struct
name|ACPIsdt
modifier|*
name|rsdt
decl_stmt|;
name|struct
name|ACPIsdt
modifier|*
name|facp
decl_stmt|;
name|struct
name|FACPbody
modifier|*
name|facp_body
decl_stmt|;
name|struct
name|ACPIsdt
modifier|*
name|dsdt
decl_stmt|;
name|struct
name|FACS
modifier|*
name|facs
decl_stmt|;
name|int
name|system_state
decl_stmt|;
name|int
name|system_state_initialized
decl_stmt|;
name|int
name|broken_wakeuplogic
decl_stmt|;
name|u_int32_t
name|gpe0_mask
decl_stmt|;
name|u_int32_t
name|gpe1_mask
decl_stmt|;
name|int
name|enabled
decl_stmt|;
name|u_int32_t
name|ignore_events
decl_stmt|;
name|struct
name|acpi_system_state_package
name|system_state_package
decl_stmt|;
name|struct
name|proc
modifier|*
name|acpi_thread
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|acpi_powerres_info
argument_list|)
name|acpi_powerres_inflist
expr_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|acpi_powerres_device
argument_list|)
name|acpi_powerres_devlist
expr_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|acpi_event
argument_list|)
name|event
expr_stmt|;
block|}
name|acpi_softc_t
typedef|;
end_typedef

begin_comment
comment|/*   * ACPI register I/O   */
end_comment

begin_define
define|#
directive|define
name|ACPI_REGISTER_INPUT
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_REGISTER_OUTPUT
value|1
end_define

begin_function_decl
specifier|extern
name|void
name|acpi_enable_disable
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|boolean_t
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_io_pm1_status
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|boolean_t
name|io
parameter_list|,
name|u_int32_t
modifier|*
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_io_pm1_enable
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|boolean_t
name|io
parameter_list|,
name|u_int32_t
modifier|*
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_io_pm1_control
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|boolean_t
name|io
parameter_list|,
name|u_int32_t
modifier|*
name|val_a
parameter_list|,
name|u_int32_t
modifier|*
name|val_b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_io_pm2_control
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|boolean_t
name|io
parameter_list|,
name|u_int32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_io_pm_timer
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|boolean_t
name|io
parameter_list|,
name|u_int32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_io_gpe0_status
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|boolean_t
name|io
parameter_list|,
name|u_int32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_io_gpe0_enable
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|boolean_t
name|io
parameter_list|,
name|u_int32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_io_gpe1_status
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|boolean_t
name|io
parameter_list|,
name|u_int32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_io_gpe1_enable
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|boolean_t
name|io
parameter_list|,
name|u_int32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*   * Device State   */
end_comment

begin_function_decl
specifier|extern
name|u_int8_t
name|acpi_get_current_device_state
parameter_list|(
name|struct
name|aml_name
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_set_device_state
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|aml_name
modifier|*
name|name
parameter_list|,
name|u_int8_t
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_set_device_wakecap
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|aml_name
modifier|*
name|name
parameter_list|,
name|u_int8_t
name|cap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * System state  */
end_comment

begin_function_decl
specifier|extern
name|void
name|acpi_set_sleeping_state
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|u_int8_t
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*   * PowerResource State   */
end_comment

begin_function_decl
specifier|extern
name|void
name|acpi_powerres_init
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_powerres_debug
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int8_t
name|acpi_get_current_powerres_state
parameter_list|(
name|struct
name|aml_name
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_set_powerres_state
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|aml_name
modifier|*
name|name
parameter_list|,
name|u_int8_t
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_powerres_set_sleeping_state
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|u_int8_t
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*   * GPE enable bit manipulation   */
end_comment

begin_function_decl
specifier|extern
name|void
name|acpi_gpe_enable_bit
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|u_int32_t
name|bit
parameter_list|,
name|boolean_t
name|on_off
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Event management  */
end_comment

begin_function_decl
specifier|extern
name|void
name|acpi_intr
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_queue_event
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acpi_send_pm_event
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|u_int8_t
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_enable_events
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_clear_ignore_events
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_event_thread
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ACPI pmap subsystem  */
end_comment

begin_define
define|#
directive|define
name|ACPI_SMAP_MAX_SIZE
value|16
end_define

begin_struct
struct|struct
name|ACPIaddr
block|{
name|int
name|entries
decl_stmt|;
struct|struct
block|{
name|vm_offset_t
name|pa_base
decl_stmt|;
name|vm_offset_t
name|va_base
decl_stmt|;
name|vm_size_t
name|size
decl_stmt|;
name|u_int32_t
name|type
decl_stmt|;
block|}
name|t
index|[
name|ACPI_SMAP_MAX_SIZE
index|]
struct|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ACPIaddr
name|acpi_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ACPIrsdp
modifier|*
name|acpi_rsdp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ACPI Root System Description Table */
end_comment

begin_function_decl
specifier|extern
name|void
name|acpi_init_addr_range
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_register_addr_range
parameter_list|(
name|u_int64_t
name|base
parameter_list|,
name|u_int64_t
name|size
parameter_list|,
name|u_int32_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acpi_sdt_checksum
parameter_list|(
name|struct
name|ACPIsdt
modifier|*
name|sdt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vm_offset_t
name|acpi_pmap_ptv
parameter_list|(
name|vm_offset_t
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vm_offset_t
name|acpi_pmap_vtp
parameter_list|(
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Bus interface.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|acpi_attach_resource
parameter_list|(
name|acpi_softc_t
modifier|*
name|sc
parameter_list|,
name|int
name|type
parameter_list|,
name|int
modifier|*
name|wantidx
parameter_list|,
name|u_long
name|start
parameter_list|,
name|u_long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ACPIrsdp
modifier|*
name|acpi_find_rsdp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_mapmem
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Debugging, console output  *  * XXX this should really be using device_printf or similar.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|acpi_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ACPI_DEVPRINTF
parameter_list|(
name|args
modifier|...
parameter_list|)
value|printf("acpi0: " args)
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUGPRINT
parameter_list|(
name|args
modifier|...
parameter_list|)
value|do { if (acpi_debug) ACPI_DEVPRINTF(args);} while(0)
end_define

end_unit

