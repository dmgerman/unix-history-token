begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Takanori Watanabe<takawata@shidahara1.planet.sci.kobe-u.ac.jp>  * Copyright (c) 1999, 2000 Mitsuru IWASAKI<iwasaki@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ACPI_ACPI_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ACPI_ACPI_H_
end_define

begin_comment
comment|/* PowerResource control */
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
name|u_int8_t
name|state
decl_stmt|;
comment|/* D0 to D3 */
name|u_int8_t
name|next_state
decl_stmt|;
comment|/* initialized with D0 */
block|}
struct|;
end_struct

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
define|#
directive|define
name|ACPI_POWER_RESOURCE_ON
value|1
define|#
directive|define
name|ACPI_POWER_RESOURCE_OFF
value|0
name|u_int8_t
name|state
decl_stmt|;
comment|/* OFF or ON */
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
block|}
struct|;
end_struct

begin_comment
comment|/* softc */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_softc
block|{
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
block|}
name|acpi_softc_t
typedef|;
end_typedef

begin_comment
comment|/* Device State */
end_comment

begin_function_decl
name|u_int8_t
name|acpi_get_current_device_state
parameter_list|(
name|struct
name|aml_name
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acpi_set_device_state
parameter_list|(
name|acpi_softc_t
modifier|*
parameter_list|,
name|struct
name|aml_name
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* PowerResource State */
end_comment

begin_function_decl
name|void
name|acpi_powerres_init
parameter_list|(
name|acpi_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acpi_powerres_debug
parameter_list|(
name|acpi_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int8_t
name|acpi_get_current_powerres_state
parameter_list|(
name|struct
name|aml_name
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acpi_set_powerres_state
parameter_list|(
name|acpi_softc_t
modifier|*
parameter_list|,
name|struct
name|aml_name
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acpi_powerres_set_sleeping_state
parameter_list|(
name|acpi_softc_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DEV_ACPI_ACPI_H_ */
end_comment

end_unit

