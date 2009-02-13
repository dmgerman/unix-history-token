begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Takanori Watanabe<takawata@jp.freebsd.org>  * Copyright (c) 1999 Mitsuru IWASAKI<iwasaki@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACPIIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_ACPIIO_H_
end_define

begin_comment
comment|/*  * Core ACPI subsystem ioctls  */
end_comment

begin_define
define|#
directive|define
name|ACPIIO_SETSLPSTATE
value|_IOW('P', 3, int)
end_define

begin_comment
comment|/* DEPRECATED */
end_comment

begin_comment
comment|/* Request S1-5 sleep state. User is notified and then sleep proceeds. */
end_comment

begin_define
define|#
directive|define
name|ACPIIO_REQSLPSTATE
value|_IOW('P', 4, int)
end_define

begin_comment
comment|/* Allow suspend to continue (0) or abort it (errno). */
end_comment

begin_define
define|#
directive|define
name|ACPIIO_ACKSLPSTATE
value|_IOW('P', 5, int)
end_define

begin_struct
struct|struct
name|acpi_battinfo
block|{
name|int
name|cap
decl_stmt|;
comment|/* percent */
name|int
name|min
decl_stmt|;
comment|/* remaining time (in minutes) */
name|int
name|state
decl_stmt|;
comment|/* battery state */
name|int
name|rate
decl_stmt|;
comment|/* emptying rate */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACPI_CMBAT_MAXSTRLEN
value|32
end_define

begin_struct
struct|struct
name|acpi_bif
block|{
name|uint32_t
name|units
decl_stmt|;
comment|/* Units (mW or mA). */
define|#
directive|define
name|ACPI_BIF_UNITS_MW
value|0
comment|/* Capacity in mWh, rate in mW. */
define|#
directive|define
name|ACPI_BIF_UNITS_MA
value|1
comment|/* Capacity in mAh, rate in mA. */
name|uint32_t
name|dcap
decl_stmt|;
comment|/* Design Capacity */
name|uint32_t
name|lfcap
decl_stmt|;
comment|/* Last Full capacity */
name|uint32_t
name|btech
decl_stmt|;
comment|/* Battery Technology */
name|uint32_t
name|dvol
decl_stmt|;
comment|/* Design voltage (mV) */
name|uint32_t
name|wcap
decl_stmt|;
comment|/* WARN capacity */
name|uint32_t
name|lcap
decl_stmt|;
comment|/* Low capacity */
name|uint32_t
name|gra1
decl_stmt|;
comment|/* Granularity 1 (Warn to Low) */
name|uint32_t
name|gra2
decl_stmt|;
comment|/* Granularity 2 (Full to Warn) */
name|char
name|model
index|[
name|ACPI_CMBAT_MAXSTRLEN
index|]
decl_stmt|;
comment|/* model identifier */
name|char
name|serial
index|[
name|ACPI_CMBAT_MAXSTRLEN
index|]
decl_stmt|;
comment|/* Serial number */
name|char
name|type
index|[
name|ACPI_CMBAT_MAXSTRLEN
index|]
decl_stmt|;
comment|/* Type */
name|char
name|oeminfo
index|[
name|ACPI_CMBAT_MAXSTRLEN
index|]
decl_stmt|;
comment|/* OEM infomation */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|acpi_bst
block|{
name|uint32_t
name|state
decl_stmt|;
comment|/* Battery State */
name|uint32_t
name|rate
decl_stmt|;
comment|/* Present Rate */
name|uint32_t
name|cap
decl_stmt|;
comment|/* Remaining Capacity */
name|uint32_t
name|volt
decl_stmt|;
comment|/* Present Voltage */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACPI_BATT_STAT_DISCHARG
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACPI_BATT_STAT_CHARGING
value|0x0002
end_define

begin_define
define|#
directive|define
name|ACPI_BATT_STAT_CRITICAL
value|0x0004
end_define

begin_define
define|#
directive|define
name|ACPI_BATT_STAT_NOT_PRESENT
value|0x0007
end_define

begin_define
define|#
directive|define
name|ACPI_BATT_STAT_MAX
value|0x0007
end_define

begin_union
union|union
name|acpi_battery_ioctl_arg
block|{
name|int
name|unit
decl_stmt|;
comment|/* Device unit or ACPI_BATTERY_ALL_UNITS. */
name|struct
name|acpi_battinfo
name|battinfo
decl_stmt|;
name|struct
name|acpi_bif
name|bif
decl_stmt|;
name|struct
name|acpi_bst
name|bst
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|ACPI_BATTERY_ALL_UNITS
value|(-1)
end_define

begin_define
define|#
directive|define
name|ACPI_BATT_UNKNOWN
value|0xffffffff
end_define

begin_comment
comment|/* _BST or _BIF value unknown. */
end_comment

begin_comment
comment|/* Common battery ioctls */
end_comment

begin_define
define|#
directive|define
name|ACPIIO_BATT_GET_UNITS
value|_IOR('B', 0x01, int)
end_define

begin_define
define|#
directive|define
name|ACPIIO_BATT_GET_BATTINFO
value|_IOWR('B', 0x03, union acpi_battery_ioctl_arg)
end_define

begin_define
define|#
directive|define
name|ACPIIO_BATT_GET_BIF
value|_IOWR('B', 0x10, union acpi_battery_ioctl_arg)
end_define

begin_define
define|#
directive|define
name|ACPIIO_BATT_GET_BST
value|_IOWR('B', 0x11, union acpi_battery_ioctl_arg)
end_define

begin_comment
comment|/* Control Method battery ioctls (deprecated) */
end_comment

begin_define
define|#
directive|define
name|ACPIIO_CMBAT_GET_BIF
value|ACPIIO_BATT_GET_BIF
end_define

begin_define
define|#
directive|define
name|ACPIIO_CMBAT_GET_BST
value|ACPIIO_BATT_GET_BST
end_define

begin_comment
comment|/* Get AC adapter status. */
end_comment

begin_define
define|#
directive|define
name|ACPIIO_ACAD_GET_STATUS
value|_IOR('A', 1, int)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|acpi_ioctl_fn
function_decl|)
parameter_list|(
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|addr
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|acpi_register_ioctl
parameter_list|(
name|u_long
name|cmd
parameter_list|,
name|acpi_ioctl_fn
name|fn
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_deregister_ioctl
parameter_list|(
name|u_long
name|cmd
parameter_list|,
name|acpi_ioctl_fn
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ACPIIO_H_ */
end_comment

end_unit

