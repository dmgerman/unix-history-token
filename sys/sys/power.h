begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Mitsuru IWASAKI  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_POWER_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_POWER_H_
end_define

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_comment
comment|/* Power management system type */
end_comment

begin_define
define|#
directive|define
name|POWER_PM_TYPE_APM
value|0x00
end_define

begin_define
define|#
directive|define
name|POWER_PM_TYPE_ACPI
value|0x01
end_define

begin_define
define|#
directive|define
name|POWER_PM_TYPE_NONE
value|0xff
end_define

begin_comment
comment|/* Commands for Power management function */
end_comment

begin_define
define|#
directive|define
name|POWER_CMD_SUSPEND
value|0x00
end_define

begin_comment
comment|/* Sleep state */
end_comment

begin_define
define|#
directive|define
name|POWER_SLEEP_STATE_STANDBY
value|0x00
end_define

begin_define
define|#
directive|define
name|POWER_SLEEP_STATE_SUSPEND
value|0x01
end_define

begin_define
define|#
directive|define
name|POWER_SLEEP_STATE_HIBERNATE
value|0x02
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|power_pm_fn_t
function_decl|)
parameter_list|(
name|u_long
parameter_list|,
name|void
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|power_pm_register
parameter_list|(
name|u_int
parameter_list|,
name|power_pm_fn_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int
name|power_pm_get_type
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|power_pm_suspend
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * System power API.  */
end_comment

begin_define
define|#
directive|define
name|POWER_PROFILE_PERFORMANCE
value|0
end_define

begin_define
define|#
directive|define
name|POWER_PROFILE_ECONOMY
value|1
end_define

begin_function_decl
specifier|extern
name|int
name|power_profile_get_state
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|power_profile_set_state
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|power_profile_change_hook
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|power_profile_change
argument_list|,
name|power_profile_change_hook
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_POWER_H_ */
end_comment

end_unit

