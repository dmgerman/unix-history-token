begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: sensors.h,v 1.23 2007/03/22 16:55:31 deraadt Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2003, 2004 Alexander Yurchenko<grange@openbsd.org>  * Copyright (c) 2006 Constantine A. Murenin<cnst+openbsd@bugmail.mojo.ru>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SENSORS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SENSORS_H_
end_define

begin_comment
comment|/* Sensor types */
end_comment

begin_enum
enum|enum
name|sensor_type
block|{
name|SENSOR_TEMP
block|,
comment|/* temperature (muK) */
name|SENSOR_FANRPM
block|,
comment|/* fan revolution speed */
name|SENSOR_VOLTS_DC
block|,
comment|/* voltage (muV DC) */
name|SENSOR_VOLTS_AC
block|,
comment|/* voltage (muV AC) */
name|SENSOR_OHMS
block|,
comment|/* resistance */
name|SENSOR_WATTS
block|,
comment|/* power */
name|SENSOR_AMPS
block|,
comment|/* current (muA) */
name|SENSOR_WATTHOUR
block|,
comment|/* power capacity */
name|SENSOR_AMPHOUR
block|,
comment|/* power capacity */
name|SENSOR_INDICATOR
block|,
comment|/* boolean indicator */
name|SENSOR_INTEGER
block|,
comment|/* generic integer value */
name|SENSOR_PERCENT
block|,
comment|/* percent */
name|SENSOR_LUX
block|,
comment|/* illuminance (mulx) */
name|SENSOR_DRIVE
block|,
comment|/* disk */
name|SENSOR_TIMEDELTA
block|,
comment|/* system time error (nSec) */
name|SENSOR_MAX_TYPES
block|}
enum|;
end_enum

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|sensor_type_s
index|[
name|SENSOR_MAX_TYPES
operator|+
literal|1
index|]
init|=
block|{
literal|"temp"
block|,
literal|"fan"
block|,
literal|"volt"
block|,
literal|"acvolt"
block|,
literal|"resistance"
block|,
literal|"power"
block|,
literal|"current"
block|,
literal|"watthour"
block|,
literal|"amphour"
block|,
literal|"indicator"
block|,
literal|"raw"
block|,
literal|"percent"
block|,
literal|"illuminance"
block|,
literal|"drive"
block|,
literal|"timedelta"
block|,
literal|"undefined"
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SENSOR_DRIVE_EMPTY
value|1
end_define

begin_define
define|#
directive|define
name|SENSOR_DRIVE_READY
value|2
end_define

begin_define
define|#
directive|define
name|SENSOR_DRIVE_POWERUP
value|3
end_define

begin_define
define|#
directive|define
name|SENSOR_DRIVE_ONLINE
value|4
end_define

begin_define
define|#
directive|define
name|SENSOR_DRIVE_IDLE
value|5
end_define

begin_define
define|#
directive|define
name|SENSOR_DRIVE_ACTIVE
value|6
end_define

begin_define
define|#
directive|define
name|SENSOR_DRIVE_REBUILD
value|7
end_define

begin_define
define|#
directive|define
name|SENSOR_DRIVE_POWERDOWN
value|8
end_define

begin_define
define|#
directive|define
name|SENSOR_DRIVE_FAIL
value|9
end_define

begin_define
define|#
directive|define
name|SENSOR_DRIVE_PFAIL
value|10
end_define

begin_comment
comment|/* Sensor states */
end_comment

begin_enum
enum|enum
name|sensor_status
block|{
name|SENSOR_S_UNSPEC
block|,
comment|/* status is unspecified */
name|SENSOR_S_OK
block|,
comment|/* status is ok */
name|SENSOR_S_WARN
block|,
comment|/* status is warning */
name|SENSOR_S_CRIT
block|,
comment|/* status is critical */
name|SENSOR_S_UNKNOWN
comment|/* status is unknown */
block|}
enum|;
end_enum

begin_comment
comment|/* Sensor data:  * New fields should be added at the end to encourage backwards compat  */
end_comment

begin_struct
struct|struct
name|sensor
block|{
name|char
name|desc
index|[
literal|32
index|]
decl_stmt|;
comment|/* sensor description, may be empty */
name|struct
name|timeval
name|tv
decl_stmt|;
comment|/* sensor value last change time */
name|int64_t
name|value
decl_stmt|;
comment|/* current value */
name|enum
name|sensor_type
name|type
decl_stmt|;
comment|/* sensor type */
name|enum
name|sensor_status
name|status
decl_stmt|;
comment|/* sensor status */
name|int
name|numt
decl_stmt|;
comment|/* sensor number of .type type */
name|int
name|flags
decl_stmt|;
comment|/* sensor flags */
define|#
directive|define
name|SENSOR_FINVALID
value|0x0001
comment|/* sensor is invalid */
define|#
directive|define
name|SENSOR_FUNKNOWN
value|0x0002
comment|/* sensor value is unknown */
block|}
struct|;
end_struct

begin_comment
comment|/* Sensor device data:  * New fields should be added at the end to encourage backwards compat  */
end_comment

begin_struct
struct|struct
name|sensordev
block|{
name|int
name|num
decl_stmt|;
comment|/* sensordev number */
name|char
name|xname
index|[
literal|16
index|]
decl_stmt|;
comment|/* unix device name */
name|int
name|maxnumt
index|[
name|SENSOR_MAX_TYPES
index|]
decl_stmt|;
name|int
name|sensors_count
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXSENSORDEVICES
value|32
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NOSYSCTL8HACK
end_ifndef

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sensor data */
end_comment

begin_struct
struct|struct
name|ksensor
block|{
name|SLIST_ENTRY
argument_list|(
argument|ksensor
argument_list|)
name|list
expr_stmt|;
comment|/* device-scope list */
name|char
name|desc
index|[
literal|32
index|]
decl_stmt|;
comment|/* sensor description, may be empty */
name|struct
name|timeval
name|tv
decl_stmt|;
comment|/* sensor value last change time */
name|int64_t
name|value
decl_stmt|;
comment|/* current value */
name|enum
name|sensor_type
name|type
decl_stmt|;
comment|/* sensor type */
name|enum
name|sensor_status
name|status
decl_stmt|;
comment|/* sensor status */
name|int
name|numt
decl_stmt|;
comment|/* sensor number of .type type */
name|int
name|flags
decl_stmt|;
comment|/* sensor flags, ie. SENSOR_FINVALID */
block|}
struct|;
end_struct

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|ksensors_head
argument_list|,
name|ksensor
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Sensor device data */
end_comment

begin_struct
struct|struct
name|ksensordev
block|{
name|SLIST_ENTRY
argument_list|(
argument|ksensordev
argument_list|)
name|list
expr_stmt|;
name|int
name|num
decl_stmt|;
comment|/* sensordev number */
name|char
name|xname
index|[
literal|16
index|]
decl_stmt|;
comment|/* unix device name */
name|int
name|maxnumt
index|[
name|SENSOR_MAX_TYPES
index|]
decl_stmt|;
name|int
name|sensors_count
decl_stmt|;
name|struct
name|ksensors_head
name|sensors_list
decl_stmt|;
ifndef|#
directive|ifndef
name|NOSYSCTL8HACK
name|struct
name|sysctl_ctx_list
name|clist
decl_stmt|;
comment|/* XXX: sysctl(9) .oid_handler() for 					 * CTLTYPE_NODE type doesn't support 					 * the undocumented sysctl magic. 					 */
endif|#
directive|endif
comment|/* !NOSYSCTL8HACK */
block|}
struct|;
end_struct

begin_comment
comment|/* struct ksensordev */
end_comment

begin_function_decl
name|void
name|sensordev_install
parameter_list|(
name|struct
name|ksensordev
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sensordev_deinstall
parameter_list|(
name|struct
name|ksensordev
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* struct ksensor */
end_comment

begin_function_decl
name|void
name|sensor_attach
parameter_list|(
name|struct
name|ksensordev
modifier|*
parameter_list|,
name|struct
name|ksensor
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sensor_detach
parameter_list|(
name|struct
name|ksensordev
modifier|*
parameter_list|,
name|struct
name|ksensor
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* task scheduling */
end_comment

begin_function_decl
name|int
name|sensor_task_register
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sensor_task_unregister
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SENSORS_H_ */
end_comment

end_unit

