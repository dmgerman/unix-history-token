begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Mitsuru IWASAKI<iwasaki@jp.freebsd.org>  * Copyright (c) 2000 Michael Smith<msmith@freebsd.org>  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"bus_if.h"
end_include

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500000
end_if

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
end_if

begin_typedef
typedef|typedef
name|vm_offset_t
name|vm_paddr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|acpi_softc
block|{
name|device_t
name|acpi_dev
decl_stmt|;
name|dev_t
name|acpi_dev_t
decl_stmt|;
name|struct
name|resource
modifier|*
name|acpi_irq
decl_stmt|;
name|int
name|acpi_irq_rid
decl_stmt|;
name|void
modifier|*
name|acpi_irq_handle
decl_stmt|;
name|int
name|acpi_enabled
decl_stmt|;
name|int
name|acpi_sstate
decl_stmt|;
name|int
name|acpi_sleep_disabled
decl_stmt|;
name|struct
name|sysctl_ctx_list
name|acpi_sysctl_ctx
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|acpi_sysctl_tree
decl_stmt|;
define|#
directive|define
name|ACPI_POWER_BUTTON_DEFAULT_SX
value|ACPI_STATE_S5;
define|#
directive|define
name|ACPI_SLEEP_BUTTON_DEFAULT_SX
value|ACPI_STATE_S1;
define|#
directive|define
name|ACPI_LID_SWITCH_DEFAULT_SX
value|ACPI_STATE_S1;
name|int
name|acpi_power_button_sx
decl_stmt|;
name|int
name|acpi_sleep_button_sx
decl_stmt|;
name|int
name|acpi_lid_switch_sx
decl_stmt|;
name|int
name|acpi_standby_sx
decl_stmt|;
name|int
name|acpi_suspend_sx
decl_stmt|;
name|int
name|acpi_sleep_delay
decl_stmt|;
name|int
name|acpi_s4bios
decl_stmt|;
name|int
name|acpi_disable_on_poweroff
decl_stmt|;
name|int
name|acpi_verbose
decl_stmt|;
name|bus_dma_tag_t
name|acpi_waketag
decl_stmt|;
name|bus_dmamap_t
name|acpi_wakemap
decl_stmt|;
name|vm_offset_t
name|acpi_wakeaddr
decl_stmt|;
name|vm_paddr_t
name|acpi_wakephys
decl_stmt|;
name|struct
name|sysctl_ctx_list
name|acpi_battery_sysctl_ctx
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|acpi_battery_sysctl_tree
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|acpi_device
block|{
comment|/* ACPI ivars */
name|ACPI_HANDLE
name|ad_handle
decl_stmt|;
name|int
name|ad_magic
decl_stmt|;
name|void
modifier|*
name|ad_private
decl_stmt|;
comment|/* resources */
name|struct
name|resource_list
name|ad_rl
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
end_if

begin_comment
comment|/*  * In 4.x, ACPI is protected by splhigh().  */
end_comment

begin_define
define|#
directive|define
name|ACPI_LOCK
value|s = splhigh()
end_define

begin_define
define|#
directive|define
name|ACPI_UNLOCK
value|splx(s)
end_define

begin_define
define|#
directive|define
name|ACPI_ASSERTLOCK
end_define

begin_define
define|#
directive|define
name|ACPI_MSLEEP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|tsleep(a, c, d, e)
end_define

begin_define
define|#
directive|define
name|ACPI_LOCK_DECL
value|int s
end_define

begin_define
define|#
directive|define
name|kthread_create
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
value|kthread_create(a, b, c, f)
end_define

begin_define
define|#
directive|define
name|tc_init
parameter_list|(
name|a
parameter_list|)
value|init_timecounter(a)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_LOCK
end_define

begin_define
define|#
directive|define
name|ACPI_UNLOCK
end_define

begin_define
define|#
directive|define
name|ACPI_ASSERTLOCK
end_define

begin_define
define|#
directive|define
name|ACPI_LOCK_DECL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ACPI CA does not define layers for non-ACPI CA drivers.  * We define some here within the range provided.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_BUS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ACPI_SYSTEM
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ACPI_POWER
value|0x00040000
end_define

begin_define
define|#
directive|define
name|ACPI_EC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|ACPI_AC_ADAPTER
value|0x00100000
end_define

begin_define
define|#
directive|define
name|ACPI_BATTERY
value|0x00110000
end_define

begin_define
define|#
directive|define
name|ACPI_BUTTON
value|0x00120000
end_define

begin_define
define|#
directive|define
name|ACPI_PROCESSOR
value|0x00140000
end_define

begin_define
define|#
directive|define
name|ACPI_THERMAL
value|0x00180000
end_define

begin_define
define|#
directive|define
name|ACPI_FAN
value|0x00200000
end_define

begin_comment
comment|/*  * Constants for different interrupt models used with acpi_SetIntrModel().  */
end_comment

begin_define
define|#
directive|define
name|ACPI_INTR_PIC
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_INTR_APIC
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_INTR_SAPIC
value|2
end_define

begin_comment
comment|/*  * Note that the low ivar values are reserved to provide  * interface compatibility with ISA drivers which can also  * attach to ACPI.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_IVAR_HANDLE
value|0x100
end_define

begin_define
define|#
directive|define
name|ACPI_IVAR_MAGIC
value|0x101
end_define

begin_define
define|#
directive|define
name|ACPI_IVAR_PRIVATE
value|0x102
end_define

begin_function_decl
specifier|extern
name|ACPI_HANDLE
name|acpi_get_handle
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acpi_set_handle
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|ACPI_HANDLE
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acpi_get_magic
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acpi_set_magic
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|acpi_get_private
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acpi_set_private
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ACPI_OBJECT_TYPE
name|acpi_get_type
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUGGER
end_ifdef

begin_function_decl
specifier|extern
name|void
name|acpi_EnterDebugger
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG
end_ifdef

begin_include
include|#
directive|include
file|<sys/cons.h>
end_include

begin_define
define|#
directive|define
name|STEP
parameter_list|(
name|x
parameter_list|)
value|do {printf x, printf("\n"); cngetc();} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STEP
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ACPI_VPRINT
parameter_list|(
name|dev
parameter_list|,
name|acpi_sc
parameter_list|,
name|x
modifier|...
parameter_list|)
value|do {			\     if (acpi_get_verbose(acpi_sc))				\ 	device_printf(dev, x);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|ACPI_DEVINFO_PRESENT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x9) == 9)
end_define

begin_function_decl
specifier|extern
name|BOOLEAN
name|acpi_DeviceIsPresent
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOLEAN
name|acpi_BatteryIsPresent
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOLEAN
name|acpi_MatchHid
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|char
modifier|*
name|hid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ACPI_STATUS
name|acpi_GetHandleInScope
parameter_list|(
name|ACPI_HANDLE
name|parent
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|ACPI_HANDLE
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ACPI_BUFFER
modifier|*
name|acpi_AllocBuffer
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ACPI_STATUS
name|acpi_EvaluateInteger
parameter_list|(
name|ACPI_HANDLE
name|handle
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|int
modifier|*
name|number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ACPI_STATUS
name|acpi_ConvertBufferToInteger
parameter_list|(
name|ACPI_BUFFER
modifier|*
name|bufp
parameter_list|,
name|int
modifier|*
name|number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ACPI_STATUS
name|acpi_ForeachPackageObject
parameter_list|(
name|ACPI_OBJECT
modifier|*
name|obj
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|ACPI_OBJECT
modifier|*
name|comp
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
name|ACPI_STATUS
name|acpi_FindIndexedResource
parameter_list|(
name|ACPI_BUFFER
modifier|*
name|buf
parameter_list|,
name|int
name|index
parameter_list|,
name|ACPI_RESOURCE
modifier|*
modifier|*
name|resp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ACPI_STATUS
name|acpi_AppendBufferResource
parameter_list|(
name|ACPI_BUFFER
modifier|*
name|buf
parameter_list|,
name|ACPI_RESOURCE
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ACPI_STATUS
name|acpi_SetIntrModel
parameter_list|(
name|int
name|model
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ACPI_STATUS
name|acpi_SetSleepState
parameter_list|(
name|struct
name|acpi_softc
modifier|*
name|sc
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ACPI_STATUS
name|acpi_Enable
parameter_list|(
name|struct
name|acpi_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ACPI_STATUS
name|acpi_Disable
parameter_list|(
name|struct
name|acpi_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|acpi_parse_resource_set
block|{
name|void
function_decl|(
modifier|*
name|set_init
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
modifier|*
name|context
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_done
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_ioport
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
name|u_int32_t
name|base
parameter_list|,
name|u_int32_t
name|length
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_iorange
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
name|u_int32_t
name|low
parameter_list|,
name|u_int32_t
name|high
parameter_list|,
name|u_int32_t
name|length
parameter_list|,
name|u_int32_t
name|align
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_memory
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
name|u_int32_t
name|base
parameter_list|,
name|u_int32_t
name|length
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_memoryrange
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
name|u_int32_t
name|low
parameter_list|,
name|u_int32_t
name|high
parameter_list|,
name|u_int32_t
name|length
parameter_list|,
name|u_int32_t
name|align
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_irq
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
name|u_int32_t
modifier|*
name|irq
parameter_list|,
name|int
name|cout
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_drq
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
name|u_int32_t
modifier|*
name|drq
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_start_dependant
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
name|int
name|preference
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_end_dependant
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|acpi_parse_resource_set
name|acpi_res_parse_set
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|ACPI_STATUS
name|acpi_parse_resources
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|ACPI_HANDLE
name|handle
parameter_list|,
name|struct
name|acpi_parse_resource_set
modifier|*
name|set
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX until Intel fix this in their headers, based on NEXT_RESOURCE */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NEXT
parameter_list|(
name|Res
parameter_list|)
value|(ACPI_RESOURCE *)((UINT8 *)Res + Res->Length)
end_define

begin_comment
comment|/* ACPI event handling */
end_comment

begin_function_decl
specifier|extern
name|UINT32
name|acpi_eventhandler_power_button_for_sleep
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|UINT32
name|acpi_eventhandler_power_button_for_wakeup
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|UINT32
name|acpi_eventhandler_sleep_button_for_sleep
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|UINT32
name|acpi_eventhandler_sleep_button_for_wakeup
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ACPI_EVENT_PRI_FIRST
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_PRI_DEFAULT
value|10000
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_PRI_LAST
value|20000
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|acpi_event_handler_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|acpi_sleep_event
argument_list|,
name|acpi_event_handler_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|acpi_wakeup_event
argument_list|,
name|acpi_event_handler_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Device power control. */
end_comment

begin_function_decl
specifier|extern
name|ACPI_STATUS
name|acpi_pwr_switch_consumer
parameter_list|(
name|ACPI_HANDLE
name|consumer
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Misc. */
end_comment

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|acpi_softc
operator|*
name|acpi_device_get_parent_softc
argument_list|(
argument|device_t child
argument_list|)
block|{
name|device_t
name|parent
block|;
name|parent
operator|=
name|device_get_parent
argument_list|(
name|child
argument_list|)
block|;
if|if
condition|(
name|parent
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
end_expr_stmt

begin_return
return|return
operator|(
name|device_get_softc
argument_list|(
name|parent
argument_list|)
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|int
name|acpi_get_verbose
parameter_list|(
name|struct
name|acpi_softc
modifier|*
name|sc
parameter_list|)
block|{
if|if
condition|(
name|sc
condition|)
return|return
operator|(
name|sc
operator|->
name|acpi_verbose
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function_decl
specifier|extern
name|char
modifier|*
name|acpi_name
parameter_list|(
name|ACPI_HANDLE
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acpi_avoid
parameter_list|(
name|ACPI_HANDLE
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acpi_disabled
parameter_list|(
name|char
modifier|*
name|subsys
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_device_enable_wake_capability
parameter_list|(
name|ACPI_HANDLE
name|h
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_device_enable_wake_event
parameter_list|(
name|ACPI_HANDLE
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acpi_machdep_init
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|acpi_install_wakeup_handler
parameter_list|(
name|struct
name|acpi_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acpi_sleep_machdep
parameter_list|(
name|struct
name|acpi_softc
modifier|*
name|sc
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Battery Abstraction. */
end_comment

begin_struct_decl
struct_decl|struct
name|acpi_battinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|acpi_battdesc
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|acpi_battery_register
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acpi_battery_get_battinfo
parameter_list|(
name|int
parameter_list|,
name|struct
name|acpi_battinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acpi_battery_get_units
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acpi_battery_get_info_expire
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acpi_battery_get_battdesc
parameter_list|(
name|int
parameter_list|,
name|struct
name|acpi_battdesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acpi_cmbat_get_battinfo
parameter_list|(
name|int
parameter_list|,
name|struct
name|acpi_battinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Embedded controller. */
end_comment

begin_function_decl
specifier|extern
name|void
name|acpi_ec_ecdt_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* AC adapter interface. */
end_comment

begin_function_decl
specifier|extern
name|int
name|acpi_acad_get_acline
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500000
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_MAX_THREADS
end_ifndef

begin_define
define|#
directive|define
name|ACPI_MAX_THREADS
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ACPI_MAX_THREADS
operator|>
literal|0
end_if

begin_define
define|#
directive|define
name|ACPI_USE_THREADS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_USE_THREADS
end_ifdef

begin_comment
comment|/* ACPI task kernel thread initialization. */
end_comment

begin_function_decl
specifier|extern
name|int
name|acpi_task_thread_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

