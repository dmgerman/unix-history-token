begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Mitsuru IWASAKI<iwasaki@jp.freebsd.org>  * Copyright (c) 2000 Michael Smith<msmith@freebsd.org>  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACPIVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_ACPIVAR_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"acpi_if.h"
end_include

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
file|<sys/ktr.h>
end_include

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

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

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

begin_struct
struct|struct
name|acpi_softc
block|{
name|device_t
name|acpi_dev
decl_stmt|;
name|struct
name|cdev
modifier|*
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
name|acpi_do_disable
decl_stmt|;
name|int
name|acpi_verbose
decl_stmt|;
name|int
name|acpi_handle_reboot
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
name|int
name|ad_flags
decl_stmt|;
comment|/* Resources */
name|struct
name|resource_list
name|ad_rl
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACPI_PRW_MAX_POWERRES
value|8
end_define

begin_struct
struct|struct
name|acpi_prw_data
block|{
name|ACPI_HANDLE
name|gpe_handle
decl_stmt|;
name|int
name|gpe_bit
decl_stmt|;
name|int
name|lowest_wake
decl_stmt|;
name|ACPI_OBJECT
name|power_res
index|[
name|ACPI_PRW_MAX_POWERRES
index|]
decl_stmt|;
name|int
name|power_res_count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Flags for each device defined in the AML namespace. */
end_comment

begin_define
define|#
directive|define
name|ACPI_FLAG_WAKE_ENABLED
value|0x1
end_define

begin_comment
comment|/* Macros for extracting parts of a PCI address from an _ADR value. */
end_comment

begin_define
define|#
directive|define
name|ACPI_ADR_PCI_SLOT
parameter_list|(
name|adr
parameter_list|)
value|(((adr)& 0xffff0000)>> 16)
end_define

begin_define
define|#
directive|define
name|ACPI_ADR_PCI_FUNC
parameter_list|(
name|adr
parameter_list|)
value|((adr)& 0xffff)
end_define

begin_comment
comment|/*  * Entry points to ACPI from above are global functions defined in this  * file, sysctls, and I/O on the control device.  Entry points from below  * are interrupts (the SCI), notifies, task queue threads, and the thermal  * zone polling thread.  *  * ACPI tables and global shared data are protected by a global lock  * (acpi_mutex).    *  * Each ACPI device can have its own driver-specific mutex for protecting  * shared access to local data.  The ACPI_LOCK macros handle mutexes.  *  * Drivers that need to serialize access to functions (e.g., to route  * interrupts, get/set control paths, etc.) should use the sx lock macros  * (ACPI_SERIAL).  *  * ACPI-CA handles its own locking and should not be called with locks held.  *  * The most complicated path is:  *     GPE -> EC runs _Qxx -> _Qxx reads EC space -> GPE  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|acpi_mutex
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ACPI_LOCK
parameter_list|(
name|sys
parameter_list|)
value|mtx_lock(&sys##_mutex)
end_define

begin_define
define|#
directive|define
name|ACPI_UNLOCK
parameter_list|(
name|sys
parameter_list|)
value|mtx_unlock(&sys##_mutex)
end_define

begin_define
define|#
directive|define
name|ACPI_LOCK_ASSERT
parameter_list|(
name|sys
parameter_list|)
value|mtx_assert(&sys##_mutex, MA_OWNED);
end_define

begin_define
define|#
directive|define
name|ACPI_LOCK_DECL
parameter_list|(
name|sys
parameter_list|,
name|name
parameter_list|)
define|\
value|static struct mtx sys##_mutex;				\ 	MTX_SYSINIT(sys##_mutex,&sys##_mutex, name, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|ACPI_SERIAL_BEGIN
parameter_list|(
name|sys
parameter_list|)
value|sx_xlock(&sys##_sxlock)
end_define

begin_define
define|#
directive|define
name|ACPI_SERIAL_END
parameter_list|(
name|sys
parameter_list|)
value|sx_xunlock(&sys##_sxlock)
end_define

begin_define
define|#
directive|define
name|ACPI_SERIAL_ASSERT
parameter_list|(
name|sys
parameter_list|)
value|sx_assert(&sys##_sxlock, SX_XLOCKED);
end_define

begin_define
define|#
directive|define
name|ACPI_SERIAL_DECL
parameter_list|(
name|sys
parameter_list|,
name|name
parameter_list|)
define|\
value|static struct sx sys##_sxlock;				\ 	SX_SYSINIT(sys##_sxlock,&sys##_sxlock, name)
end_define

begin_comment
comment|/*  * ACPI CA does not define layers for non-ACPI CA drivers.  * We define some here within the range provided.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_AC_ADAPTER
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ACPI_BATTERY
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ACPI_BUS
value|0x00040000
end_define

begin_define
define|#
directive|define
name|ACPI_BUTTON
value|0x00080000
end_define

begin_define
define|#
directive|define
name|ACPI_EC
value|0x00100000
end_define

begin_define
define|#
directive|define
name|ACPI_FAN
value|0x00200000
end_define

begin_define
define|#
directive|define
name|ACPI_POWERRES
value|0x00400000
end_define

begin_define
define|#
directive|define
name|ACPI_PROCESSOR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|ACPI_THERMAL
value|0x01000000
end_define

begin_define
define|#
directive|define
name|ACPI_TIMER
value|0x02000000
end_define

begin_define
define|#
directive|define
name|ACPI_OEM
value|0x04000000
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
comment|/*  * Various features and capabilities for the acpi_get_features() method.  * In particular, these are used for the ACPI 3.0 _PDC and _OSC methods.  * See the Intel document titled "Processor Driver Capabilities Bit  * Definitions", number 302223-002.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_CAP_PERF_MSRS
value|(1<< 0)
end_define

begin_comment
comment|/* Intel SpeedStep PERF_CTL MSRs */
end_comment

begin_define
define|#
directive|define
name|ACPI_CAP_C1_IO_HALT
value|(1<< 1)
end_define

begin_comment
comment|/* Intel C1 "IO then halt" sequence */
end_comment

begin_define
define|#
directive|define
name|ACPI_CAP_THR_MSRS
value|(1<< 2)
end_define

begin_comment
comment|/* Intel OnDemand throttling MSRs */
end_comment

begin_define
define|#
directive|define
name|ACPI_CAP_SMP_SAME
value|(1<< 3)
end_define

begin_comment
comment|/* MP C1, Px, and Tx (all the same) */
end_comment

begin_define
define|#
directive|define
name|ACPI_CAP_SMP_SAME_C3
value|(1<< 4)
end_define

begin_comment
comment|/* MP C2 and C3 (all the same) */
end_comment

begin_define
define|#
directive|define
name|ACPI_CAP_SMP_DIFF_PX
value|(1<< 5)
end_define

begin_comment
comment|/* MP Px (different, using _PSD) */
end_comment

begin_define
define|#
directive|define
name|ACPI_CAP_SMP_DIFF_CX
value|(1<< 6)
end_define

begin_comment
comment|/* MP Cx (different, using _CSD) */
end_comment

begin_define
define|#
directive|define
name|ACPI_CAP_SMP_DIFF_TX
value|(1<< 7)
end_define

begin_comment
comment|/* MP Tx (different, using _TSD) */
end_comment

begin_define
define|#
directive|define
name|ACPI_CAP_SMP_C1_NATIVE
value|(1<< 8)
end_define

begin_comment
comment|/* MP C1 support other than halt */
end_comment

begin_comment
comment|/*  * Quirk flags.  *  * ACPI_Q_BROKEN: Disables all ACPI support.  * ACPI_Q_TIMER: Disables support for the ACPI timer.  * ACPI_Q_MADT_IRQ0: Specifies that ISA IRQ 0 is wired up to pin 0 of the  *	first APIC and that the MADT should force that by ignoring the PC-AT  *	compatible flag and ignoring overrides that redirect IRQ 0 to pin 2.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|acpi_quirks
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ACPI_Q_OK
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_Q_BROKEN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ACPI_Q_TIMER
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ACPI_Q_MADT_IRQ0
value|(1<< 2)
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

begin_define
define|#
directive|define
name|ACPI_IVAR_FLAGS
value|0x103
end_define

begin_comment
comment|/*  * Accessor functions for our ivars.  Default value for BUS_READ_IVAR is  * (type) 0.  The<sys/bus.h> accessor functions don't check return values.  */
end_comment

begin_define
define|#
directive|define
name|__ACPI_BUS_ACCESSOR
parameter_list|(
name|varp
parameter_list|,
name|var
parameter_list|,
name|ivarp
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\ 								\
value|static __inline type varp ## _get_ ## var(device_t dev)		\ {								\     uintptr_t v = 0;						\     BUS_READ_IVAR(device_get_parent(dev), dev,			\ 	ivarp ## _IVAR_ ## ivar,&v);				\     return ((type) v);						\ }								\ 								\ static __inline void varp ## _set_ ## var(device_t dev, type t)	\ {								\     uintptr_t v = (uintptr_t) t;				\     BUS_WRITE_IVAR(device_get_parent(dev), dev,			\ 	ivarp ## _IVAR_ ## ivar, v);				\ }
end_define

begin_macro
name|__ACPI_BUS_ACCESSOR
argument_list|(
argument|acpi
argument_list|,
argument|handle
argument_list|,
argument|ACPI
argument_list|,
argument|HANDLE
argument_list|,
argument|ACPI_HANDLE
argument_list|)
end_macro

begin_macro
name|__ACPI_BUS_ACCESSOR
argument_list|(
argument|acpi
argument_list|,
argument|magic
argument_list|,
argument|ACPI
argument_list|,
argument|MAGIC
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|__ACPI_BUS_ACCESSOR
argument_list|(
argument|acpi
argument_list|,
argument|private
argument_list|,
argument|ACPI
argument_list|,
argument|PRIVATE
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|__ACPI_BUS_ACCESSOR
argument_list|(
argument|acpi
argument_list|,
argument|flags
argument_list|,
argument|ACPI
argument_list|,
argument|FLAGS
argument_list|,
argument|int
argument_list|)
end_macro

begin_function_decl
name|void
name|acpi_fake_objhandler
parameter_list|(
name|ACPI_HANDLE
name|h
parameter_list|,
name|UINT32
name|fn
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|device_t
name|acpi_get_device
parameter_list|(
name|ACPI_HANDLE
name|handle
parameter_list|)
block|{
name|void
modifier|*
name|dev
init|=
name|NULL
decl_stmt|;
name|AcpiGetData
argument_list|(
name|handle
argument_list|,
name|acpi_fake_objhandler
argument_list|,
operator|&
name|dev
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|device_t
operator|)
name|dev
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|ACPI_OBJECT_TYPE
name|acpi_get_type
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|ACPI_HANDLE
name|h
decl_stmt|;
name|ACPI_OBJECT_TYPE
name|t
decl_stmt|;
if|if
condition|(
operator|(
name|h
operator|=
name|acpi_get_handle
argument_list|(
name|dev
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|ACPI_TYPE_NOT_FOUND
operator|)
return|;
if|if
condition|(
name|AcpiGetType
argument_list|(
name|h
argument_list|,
operator|&
name|t
argument_list|)
operator|!=
name|AE_OK
condition|)
return|return
operator|(
name|ACPI_TYPE_NOT_FOUND
operator|)
return|;
return|return
operator|(
name|t
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUGGER
end_ifdef

begin_function_decl
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

begin_comment
comment|/* Values for the device _STA (status) method. */
end_comment

begin_define
define|#
directive|define
name|ACPI_STA_PRESENT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ACPI_STA_ENABLED
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ACPI_STA_SHOW_IN_UI
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ACPI_STA_FUNCTIONAL
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ACPI_STA_BATT_PRESENT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ACPI_DEVINFO_PRESENT
parameter_list|(
name|x
parameter_list|,
name|flags
parameter_list|)
define|\
value|(((x)& (flags)) == (flags))
end_define

begin_define
define|#
directive|define
name|ACPI_DEVICE_PRESENT
parameter_list|(
name|x
parameter_list|)
define|\
value|ACPI_DEVINFO_PRESENT(x, ACPI_STA_PRESENT | ACPI_STA_FUNCTIONAL)
end_define

begin_define
define|#
directive|define
name|ACPI_BATTERY_PRESENT
parameter_list|(
name|x
parameter_list|)
define|\
value|ACPI_DEVINFO_PRESENT(x, ACPI_STA_PRESENT | ACPI_STA_FUNCTIONAL | \ 	    ACPI_STA_BATT_PRESENT)
end_define

begin_function_decl
name|BOOLEAN
name|acpi_DeviceIsPresent
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|acpi_BatteryIsPresent
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|uint32_t
name|acpi_TimerDelta
parameter_list|(
name|uint32_t
name|end
parameter_list|,
name|uint32_t
name|start
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|ACPI_STATUS
name|acpi_ConvertBufferToInteger
parameter_list|(
name|ACPI_BUFFER
modifier|*
name|bufp
parameter_list|,
name|UINT32
modifier|*
name|number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|acpi_GetInteger
parameter_list|(
name|ACPI_HANDLE
name|handle
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|UINT32
modifier|*
name|number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|acpi_SetInteger
parameter_list|(
name|ACPI_HANDLE
name|handle
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|UINT32
name|number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|ACPI_STATUS
name|acpi_OverrideInterruptLevel
parameter_list|(
name|UINT32
name|InterruptNumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|acpi_SetIntrModel
parameter_list|(
name|int
name|model
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|int
name|acpi_wake_init
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpi_wake_set_enable
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpi_parse_prw
parameter_list|(
name|ACPI_HANDLE
name|h
parameter_list|,
name|struct
name|acpi_prw_data
modifier|*
name|prw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|acpi_Startup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acpi_UserNotify
parameter_list|(
specifier|const
name|char
modifier|*
name|subsystem
parameter_list|,
name|ACPI_HANDLE
name|h
parameter_list|,
name|uint8_t
name|notify
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpi_bus_alloc_gas
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
modifier|*
name|type
parameter_list|,
name|int
modifier|*
name|rid
parameter_list|,
name|ACPI_GENERIC_ADDRESS
modifier|*
name|gas
parameter_list|,
name|struct
name|resource
modifier|*
modifier|*
name|res
parameter_list|,
name|u_int
name|flags
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
name|arg
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
name|uint32_t
name|base
parameter_list|,
name|uint32_t
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
name|uint32_t
name|low
parameter_list|,
name|uint32_t
name|high
parameter_list|,
name|uint32_t
name|length
parameter_list|,
name|uint32_t
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
name|uint32_t
name|base
parameter_list|,
name|uint32_t
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
name|uint32_t
name|low
parameter_list|,
name|uint32_t
name|high
parameter_list|,
name|uint32_t
name|length
parameter_list|,
name|uint32_t
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
name|count
parameter_list|,
name|int
name|trig
parameter_list|,
name|int
name|pol
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
name|void
name|acpi_config_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|ACPI_RESOURCE
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|acpi_lookup_irq_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|resource
modifier|*
name|res
parameter_list|,
name|ACPI_RESOURCE
modifier|*
name|acpi_res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ACPI event handling */
end_comment

begin_function_decl
name|UINT32
name|acpi_event_power_button_sleep
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|acpi_event_power_button_wake
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|acpi_event_sleep_button_sleep
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|acpi_event_sleep_button_wake
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
name|ACPI_STATUS
name|acpi_pwr_wake_enable
parameter_list|(
name|ACPI_HANDLE
name|consumer
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|int
name|acpi_avoid
parameter_list|(
name|ACPI_HANDLE
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|int
name|acpi_machdep_init
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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

begin_function_decl
name|int
name|acpi_table_quirks
parameter_list|(
name|int
modifier|*
name|quirks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpi_machdep_quirks
parameter_list|(
name|int
modifier|*
name|quirks
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

begin_function_decl
name|int
name|acpi_battery_register
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpi_battery_remove
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpi_battery_get_units
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpi_battery_get_info_expire
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpi_battery_bst_valid
parameter_list|(
name|struct
name|acpi_bst
modifier|*
name|bst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpi_battery_bif_valid
parameter_list|(
name|struct
name|acpi_bif
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpi_battery_get_battinfo
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|acpi_battinfo
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Embedded controller. */
end_comment

begin_function_decl
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
name|int
name|acpi_acad_get_acline
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Package manipulation convenience functions. */
end_comment

begin_define
define|#
directive|define
name|ACPI_PKG_VALID
parameter_list|(
name|pkg
parameter_list|,
name|size
parameter_list|)
define|\
value|((pkg) != NULL&& (pkg)->Type == ACPI_TYPE_PACKAGE&&	\      (pkg)->Package.Count>= (size))
end_define

begin_function_decl
name|int
name|acpi_PkgInt
parameter_list|(
name|ACPI_OBJECT
modifier|*
name|res
parameter_list|,
name|int
name|idx
parameter_list|,
name|ACPI_INTEGER
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpi_PkgInt32
parameter_list|(
name|ACPI_OBJECT
modifier|*
name|res
parameter_list|,
name|int
name|idx
parameter_list|,
name|uint32_t
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpi_PkgStr
parameter_list|(
name|ACPI_OBJECT
modifier|*
name|res
parameter_list|,
name|int
name|idx
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpi_PkgGas
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|ACPI_OBJECT
modifier|*
name|res
parameter_list|,
name|int
name|idx
parameter_list|,
name|int
modifier|*
name|type
parameter_list|,
name|int
modifier|*
name|rid
parameter_list|,
name|struct
name|resource
modifier|*
modifier|*
name|dst
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_HANDLE
name|acpi_GetReference
parameter_list|(
name|ACPI_HANDLE
name|scope
parameter_list|,
name|ACPI_OBJECT
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Default number of task queue threads to start. */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_THREADS
value|3
end_define

begin_comment
comment|/* Use the device logging level for ktr(4). */
end_comment

begin_define
define|#
directive|define
name|KTR_ACPI
value|KTR_DEV
end_define

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
comment|/* !_ACPIVAR_H_ */
end_comment

end_unit

