begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Takanori Watanabe<takawata@shidahara1.planet.sci.kobe-u.ac.jp>  * Copyright (c) 1999 Mitsuru IWASAKI<iwasaki@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * Core ACPI subsystem ioctls  */
end_comment

begin_define
define|#
directive|define
name|ACPIIO_ENABLE
value|_IO('P', 1)
end_define

begin_define
define|#
directive|define
name|ACPIIO_DISABLE
value|_IO('P', 2)
end_define

begin_define
define|#
directive|define
name|ACPIIO_SETSLPSTATE
value|_IOW('P', 3, int)
end_define

begin_struct
struct|struct
name|acpi_battdesc
block|{
name|int
name|type
decl_stmt|;
comment|/* battery type: e.g. CMBAT */
name|int
name|phys_unit
decl_stmt|;
comment|/* physical unit of devclass */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACPI_BATT_TYPE_CMBAT
value|0x0000
end_define

begin_define
define|#
directive|define
name|ACPI_BATT_TYPE_SMBAT
value|0x0001
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
comment|/* remianing time */
name|int
name|state
decl_stmt|;
comment|/* battery state */
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
name|u_int32_t
name|unit
decl_stmt|;
comment|/* 0 for mWh, 1 for mAh */
name|u_int32_t
name|dcap
decl_stmt|;
comment|/* Design Capacity */
name|u_int32_t
name|lfcap
decl_stmt|;
comment|/* Last Full capacity */
name|u_int32_t
name|btech
decl_stmt|;
comment|/* Battery Technorogy */
name|u_int32_t
name|dvol
decl_stmt|;
comment|/* Design voltage (mV) */
name|u_int32_t
name|wcap
decl_stmt|;
comment|/* WARN capacity */
name|u_int32_t
name|lcap
decl_stmt|;
comment|/* Low capacity */
name|u_int32_t
name|gra1
decl_stmt|;
comment|/* Granulity 1(Warn to Low) */
name|u_int32_t
name|gra2
decl_stmt|;
comment|/* Granulity 2(Full to Warn) */
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
name|u_int32_t
name|state
decl_stmt|;
comment|/* Battery State */
name|u_int32_t
name|rate
decl_stmt|;
comment|/* Present Rate */
name|u_int32_t
name|cap
decl_stmt|;
comment|/* Remaining Capacity */
name|u_int32_t
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
comment|/* argument: logical unit (-1 = overall) */
name|struct
name|acpi_battdesc
name|battdesc
decl_stmt|;
name|struct
name|acpi_battinfo
name|battinfo
decl_stmt|;
name|struct
name|acpi_bif
name|bif
decl_stmt|;
comment|/* for acpi_cmbat */
name|struct
name|acpi_bst
name|bst
decl_stmt|;
comment|/* for acpi_cmbat */
block|}
union|;
end_union

begin_comment
comment|/* Common battery ioctl */
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
name|ACPIIO_BATT_GET_TYPE
value|_IOR('B', 0x02, union acpi_battery_ioctl_arg)
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
name|ACPIIO_BATT_GET_BATTDESC
value|_IOWR('B', 0x04, union acpi_battery_ioctl_arg)
end_define

begin_comment
comment|/* Cotrol Method battery ioctl */
end_comment

begin_define
define|#
directive|define
name|ACPIIO_CMBAT_GET_BIF
value|_IOWR('B', 0x10, union acpi_battery_ioctl_arg)
end_define

begin_define
define|#
directive|define
name|ACPIIO_CMBAT_GET_BST
value|_IOWR('B', 0x11, union acpi_battery_ioctl_arg)
end_define

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

begin_function_decl
specifier|extern
name|int
name|acpi_register_ioctl
parameter_list|(
name|u_long
name|cmd
parameter_list|,
name|int
function_decl|(
modifier|*
name|fn
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
name|int
function_decl|(
modifier|*
name|fn
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
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

