begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997,1998,2003 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_BUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_BUS_H_
end_define

begin_include
include|#
directive|include
file|<sys/_bus_dma.h>
end_include

begin_comment
comment|/**  * @defgroup NEWBUS newbus - a generic framework for managing devices  * @{  */
end_comment

begin_comment
comment|/**  * @brief Interface information structure.  */
end_comment

begin_struct
struct|struct
name|u_businfo
block|{
name|int
name|ub_version
decl_stmt|;
comment|/**< @brief interface version */
define|#
directive|define
name|BUS_USER_VERSION
value|1
name|int
name|ub_generation
decl_stmt|;
comment|/**< @brief generation count */
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief State of the device.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|device_state
block|{
name|DS_NOTPRESENT
block|,
comment|/**< @brief not probed or probe failed */
name|DS_ALIVE
block|,
comment|/**< @brief probe succeeded */
name|DS_ATTACHED
block|,
comment|/**< @brief attach method called */
name|DS_BUSY
comment|/**< @brief device is open */
block|}
name|device_state_t
typedef|;
end_typedef

begin_comment
comment|/**  * @brief Device information exported to userspace.  */
end_comment

begin_struct
struct|struct
name|u_device
block|{
name|uintptr_t
name|dv_handle
decl_stmt|;
name|uintptr_t
name|dv_parent
decl_stmt|;
name|char
name|dv_name
index|[
literal|32
index|]
decl_stmt|;
comment|/**< @brief Name of device in tree. */
name|char
name|dv_desc
index|[
literal|32
index|]
decl_stmt|;
comment|/**< @brief Driver description */
name|char
name|dv_drivername
index|[
literal|32
index|]
decl_stmt|;
comment|/**< @brief Driver name */
name|char
name|dv_pnpinfo
index|[
literal|128
index|]
decl_stmt|;
comment|/**< @brief Plug and play info */
name|char
name|dv_location
index|[
literal|128
index|]
decl_stmt|;
comment|/**< @brief Where is the device? */
name|uint32_t
name|dv_devflags
decl_stmt|;
comment|/**< @brief API Flags for device */
name|uint16_t
name|dv_flags
decl_stmt|;
comment|/**< @brief flags for dev date */
name|device_state_t
name|dv_state
decl_stmt|;
comment|/**< @brief State of attachment */
comment|/* XXX more driver info? */
block|}
struct|;
end_struct

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

begin_include
include|#
directive|include
file|<sys/kobj.h>
end_include

begin_comment
comment|/**  * devctl hooks.  Typically one should use the devctl_notify  * hook to send the message.  However, devctl_queue_data is also  * included in case devctl_notify isn't sufficiently general.  */
end_comment

begin_function_decl
name|void
name|devctl_notify
parameter_list|(
specifier|const
name|char
modifier|*
name|__system
parameter_list|,
specifier|const
name|char
modifier|*
name|__subsystem
parameter_list|,
specifier|const
name|char
modifier|*
name|__type
parameter_list|,
specifier|const
name|char
modifier|*
name|__data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devctl_queue_data
parameter_list|(
name|char
modifier|*
name|__data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief A device driver (included mainly for compatibility with  * FreeBSD 4.x).  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|kobj_class
name|driver_t
typedef|;
end_typedef

begin_comment
comment|/**  * @brief A device class  *  * The devclass object has two main functions in the system. The first  * is to manage the allocation of unit numbers for device instances  * and the second is to hold the list of device drivers for a  * particular bus type. Each devclass has a name and there cannot be  * two devclasses with the same name. This ensures that unique unit  * numbers are allocated to device instances.  *  * Drivers that support several different bus attachments (e.g. isa,  * pci, pccard) should all use the same devclass to ensure that unit  * numbers do not conflict.  *  * Each devclass may also have a parent devclass. This is used when  * searching for device drivers to allow a form of inheritance. When  * matching drivers with devices, first the driver list of the parent  * device's devclass is searched. If no driver is found in that list,  * the search continues in the parent devclass (if any).  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|devclass
modifier|*
name|devclass_t
typedef|;
end_typedef

begin_comment
comment|/**  * @brief A device method (included mainly for compatibility with  * FreeBSD 4.x).  */
end_comment

begin_define
define|#
directive|define
name|device_method_t
value|kobj_method_t
end_define

begin_comment
comment|/**  * @brief Driver interrupt filter return values  *  * If a driver provides an interrupt filter routine it must return an  * integer consisting of oring together zero or more of the following  * flags:  *  *	FILTER_STRAY	- this device did not trigger the interrupt  *	FILTER_HANDLED	- the interrupt has been fully handled and can be EOId  *	FILTER_SCHEDULE_THREAD - the threaded interrupt handler should be  *			  scheduled to execute  *  * If the driver does not provide a filter, then the interrupt code will  * act is if the filter had returned FILTER_SCHEDULE_THREAD.  Note that it  * is illegal to specify any other flag with FILTER_STRAY and that it is  * illegal to not specify either of FILTER_HANDLED or FILTER_SCHEDULE_THREAD  * if FILTER_STRAY is not specified.  */
end_comment

begin_define
define|#
directive|define
name|FILTER_STRAY
value|0x01
end_define

begin_define
define|#
directive|define
name|FILTER_HANDLED
value|0x02
end_define

begin_define
define|#
directive|define
name|FILTER_SCHEDULE_THREAD
value|0x04
end_define

begin_comment
comment|/**  * @brief Driver interrupt service routines  *  * The filter routine is run in primary interrupt context and may not  * block or use regular mutexes.  It may only use spin mutexes for  * synchronization.  The filter may either completely handle the  * interrupt or it may perform some of the work and defer more  * expensive work to the regular interrupt handler.  If a filter  * routine is not registered by the driver, then the regular interrupt  * handler is always used to handle interrupts from this device.  *  * The regular interrupt handler executes in its own thread context  * and may use regular mutexes.  However, it is prohibited from  * sleeping on a sleep queue.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|driver_filter_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|driver_intr_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * @brief Interrupt type bits.  *   * These flags are used both by newbus interrupt  * registration (nexus.c) and also in struct intrec, which defines  * interrupt properties.  *  * XXX We should probably revisit this and remove the vestiges of the  * spls implicit in names like INTR_TYPE_TTY. In the meantime, don't  * confuse things by renaming them (Grog, 18 July 2000).  *  * We define this in terms of bits because some devices may belong  * to multiple classes (and therefore need to be included in  * multiple interrupt masks, which is what this really serves to  * indicate. Buses which do interrupt remapping will want to  * change their type to reflect what sort of devices are underneath.  */
end_comment

begin_enum
enum|enum
name|intr_type
block|{
name|INTR_TYPE_TTY
init|=
literal|1
block|,
name|INTR_TYPE_BIO
init|=
literal|2
block|,
name|INTR_TYPE_NET
init|=
literal|4
block|,
name|INTR_TYPE_CAM
init|=
literal|8
block|,
name|INTR_TYPE_MISC
init|=
literal|16
block|,
name|INTR_TYPE_CLK
init|=
literal|32
block|,
name|INTR_TYPE_AV
init|=
literal|64
block|,
name|INTR_FAST
init|=
literal|128
block|,
name|INTR_EXCL
init|=
literal|256
block|,
comment|/* exclusive interrupt */
name|INTR_MPSAFE
init|=
literal|512
block|,
comment|/* this interrupt is SMP safe */
name|INTR_ENTROPY
init|=
literal|1024
comment|/* this interrupt provides entropy */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|intr_trigger
block|{
name|INTR_TRIGGER_CONFORM
init|=
literal|0
block|,
name|INTR_TRIGGER_EDGE
init|=
literal|1
block|,
name|INTR_TRIGGER_LEVEL
init|=
literal|2
block|}
enum|;
end_enum

begin_enum
enum|enum
name|intr_polarity
block|{
name|INTR_POLARITY_CONFORM
init|=
literal|0
block|,
name|INTR_POLARITY_HIGH
init|=
literal|1
block|,
name|INTR_POLARITY_LOW
init|=
literal|2
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|devop_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * @brief This structure is deprecated.  *  * Use the kobj(9) macro DEFINE_CLASS to  * declare classes which implement device drivers.  */
end_comment

begin_struct
struct|struct
name|driver
block|{
name|KOBJ_CLASS_FIELDS
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Definitions for drivers which need to keep simple lists of resources  * for their child devices.  */
end_comment

begin_struct_decl
struct_decl|struct
name|resource
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * @brief An entry for a single resource in a resource list.  */
end_comment

begin_struct
struct|struct
name|resource_list_entry
block|{
name|STAILQ_ENTRY
argument_list|(
argument|resource_list_entry
argument_list|)
name|link
expr_stmt|;
name|int
name|type
decl_stmt|;
comment|/**< @brief type argument to alloc_resource */
name|int
name|rid
decl_stmt|;
comment|/**< @brief resource identifier */
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
comment|/**< @brief the real resource when allocated */
name|u_long
name|start
decl_stmt|;
comment|/**< @brief start of resource range */
name|u_long
name|end
decl_stmt|;
comment|/**< @brief end of resource range */
name|u_long
name|count
decl_stmt|;
comment|/**< @brief count within range */
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|resource_list
argument_list|,
name|resource_list_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|resource_list_init
parameter_list|(
name|struct
name|resource_list
modifier|*
name|rl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|resource_list_free
parameter_list|(
name|struct
name|resource_list
modifier|*
name|rl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|resource_list_entry
modifier|*
name|resource_list_add
parameter_list|(
name|struct
name|resource_list
modifier|*
name|rl
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|u_long
name|start
parameter_list|,
name|u_long
name|end
parameter_list|,
name|u_long
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|resource_list_add_next
parameter_list|(
name|struct
name|resource_list
modifier|*
name|rl
parameter_list|,
name|int
name|type
parameter_list|,
name|u_long
name|start
parameter_list|,
name|u_long
name|end
parameter_list|,
name|u_long
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|resource_list_entry
modifier|*
name|resource_list_find
parameter_list|(
name|struct
name|resource_list
modifier|*
name|rl
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|resource_list_delete
parameter_list|(
name|struct
name|resource_list
modifier|*
name|rl
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|resource
modifier|*
name|resource_list_alloc
parameter_list|(
name|struct
name|resource_list
modifier|*
name|rl
parameter_list|,
name|device_t
name|bus
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
modifier|*
name|rid
parameter_list|,
name|u_long
name|start
parameter_list|,
name|u_long
name|end
parameter_list|,
name|u_long
name|count
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|resource_list_release
parameter_list|(
name|struct
name|resource_list
modifier|*
name|rl
parameter_list|,
name|device_t
name|bus
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|resource
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|resource_list_purge
parameter_list|(
name|struct
name|resource_list
modifier|*
name|rl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|resource_list_print_type
parameter_list|(
name|struct
name|resource_list
modifier|*
name|rl
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The root bus, to which all top-level busses are attached.  */
end_comment

begin_decl_stmt
specifier|extern
name|device_t
name|root_bus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|root_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|root_bus_configure
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Useful functions for implementing busses.  */
end_comment

begin_function_decl
name|int
name|bus_generic_activate_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|bus_generic_add_child
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|order
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|resource
modifier|*
name|bus_generic_alloc_resource
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
modifier|*
name|rid
parameter_list|,
name|u_long
name|start
parameter_list|,
name|u_long
name|end
parameter_list|,
name|u_long
name|count
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_child_present
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_config_intr
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|enum
name|intr_trigger
parameter_list|,
name|enum
name|intr_polarity
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_deactivate_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_generic_driver_added
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|driver_t
modifier|*
name|driver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bus_dma_tag_t
name|bus_generic_get_dma_tag
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|resource_list
modifier|*
name|bus_generic_get_resource_list
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_print_child_header
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_print_child_footer
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_print_child
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_read_ivar
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|which
parameter_list|,
name|uintptr_t
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_release_resource
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_setup_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|struct
name|resource
modifier|*
name|irq
parameter_list|,
name|int
name|flags
parameter_list|,
name|driver_filter_t
modifier|*
name|filter
parameter_list|,
name|driver_intr_t
modifier|*
name|intr
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|resource
modifier|*
name|bus_generic_rl_alloc_resource
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_generic_rl_delete_resource
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_rl_get_resource
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_long
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_rl_set_resource
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_rl_release_resource
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|resource
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_shutdown
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_teardown_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|struct
name|resource
modifier|*
name|irq
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_write_ivar
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|which
parameter_list|,
name|uintptr_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Wrapper functions for the BUS_*_RESOURCE methods to make client code  * a little simpler.  */
end_comment

begin_struct
struct|struct
name|resource_spec
block|{
name|int
name|type
decl_stmt|;
name|int
name|rid
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|bus_alloc_resources
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|resource_spec
modifier|*
name|rs
parameter_list|,
name|struct
name|resource
modifier|*
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_release_resources
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|resource_spec
modifier|*
name|rs
parameter_list|,
name|struct
name|resource
modifier|*
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|resource
modifier|*
name|bus_alloc_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|int
modifier|*
name|rid
parameter_list|,
name|u_long
name|start
parameter_list|,
name|u_long
name|end
parameter_list|,
name|u_long
name|count
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_activate_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_deactivate_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bus_dma_tag_t
name|bus_get_dma_tag
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_release_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_free_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_setup_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|,
name|int
name|flags
parameter_list|,
name|driver_filter_t
name|filter
parameter_list|,
name|driver_intr_t
name|handler
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_teardown_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_set_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|u_long
name|start
parameter_list|,
name|u_long
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_get_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|u_long
modifier|*
name|startp
parameter_list|,
name|u_long
modifier|*
name|countp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|bus_get_resource_start
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|bus_get_resource_count
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_delete_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_child_present
parameter_list|(
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_child_pnpinfo_str
parameter_list|(
name|device_t
name|child
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_child_location_str
parameter_list|(
name|device_t
name|child
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_enumerate_hinted_children
parameter_list|(
name|device_t
name|bus
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|resource
operator|*
name|bus_alloc_resource_any
argument_list|(
argument|device_t dev
argument_list|,
argument|int type
argument_list|,
argument|int *rid
argument_list|,
argument|u_int flags
argument_list|)
block|{
return|return
operator|(
name|bus_alloc_resource
argument_list|(
name|dev
argument_list|,
name|type
argument_list|,
name|rid
argument_list|,
literal|0ul
argument_list|,
operator|~
literal|0ul
argument_list|,
literal|1
argument_list|,
name|flags
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/*  * Access functions for device.  */
end_comment

begin_function_decl
name|device_t
name|device_add_child
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|device_add_child_ordered
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|order
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_busy
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_delete_child
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_disable
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_enable
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|device_find_child
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|classname
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|device_get_desc
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|devclass_t
name|device_get_devclass
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|driver_t
modifier|*
name|device_get_driver
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|device_get_flags
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|device_get_parent
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_get_children
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
modifier|*
modifier|*
name|listp
parameter_list|,
name|int
modifier|*
name|countp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|device_get_ivars
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_set_ivars
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|ivars
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|device_get_name
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|device_get_nameunit
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|device_get_softc
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_state_t
name|device_get_state
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_get_unit
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sysctl_ctx_list
modifier|*
name|device_get_sysctl_ctx
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sysctl_oid
modifier|*
name|device_get_sysctl_tree
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_is_alive
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* did probe succeed? */
end_comment

begin_function_decl
name|int
name|device_is_attached
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* did attach succeed? */
end_comment

begin_function_decl
name|int
name|device_is_enabled
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_is_quiet
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_print_prettyname
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_printf
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|device_probe_and_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_probe_child
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_quiesce
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_quiet
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_set_desc
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_set_desc_copy
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_set_devclass
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|classname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_set_driver
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|driver_t
modifier|*
name|driver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_set_flags
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_set_softc
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|softc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_set_unit
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX DONT USE XXX */
end_comment

begin_function_decl
name|int
name|device_shutdown
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_unbusy
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_verbose
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Access functions for devclass.  */
end_comment

begin_function_decl
name|int
name|devclass_add_driver
parameter_list|(
name|devclass_t
name|dc
parameter_list|,
name|kobj_class_t
name|driver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devclass_delete_driver
parameter_list|(
name|devclass_t
name|dc
parameter_list|,
name|kobj_class_t
name|driver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|devclass_t
name|devclass_create
parameter_list|(
specifier|const
name|char
modifier|*
name|classname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|devclass_t
name|devclass_find
parameter_list|(
specifier|const
name|char
modifier|*
name|classname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|kobj_class_t
name|devclass_find_driver
parameter_list|(
name|devclass_t
name|dc
parameter_list|,
specifier|const
name|char
modifier|*
name|classname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|devclass_get_name
parameter_list|(
name|devclass_t
name|dc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|devclass_get_device
parameter_list|(
name|devclass_t
name|dc
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|devclass_get_softc
parameter_list|(
name|devclass_t
name|dc
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devclass_get_devices
parameter_list|(
name|devclass_t
name|dc
parameter_list|,
name|device_t
modifier|*
modifier|*
name|listp
parameter_list|,
name|int
modifier|*
name|countp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devclass_get_drivers
parameter_list|(
name|devclass_t
name|dc
parameter_list|,
name|driver_t
modifier|*
modifier|*
modifier|*
name|listp
parameter_list|,
name|int
modifier|*
name|countp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devclass_get_count
parameter_list|(
name|devclass_t
name|dc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devclass_get_maxunit
parameter_list|(
name|devclass_t
name|dc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devclass_find_free_unit
parameter_list|(
name|devclass_t
name|dc
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devclass_set_parent
parameter_list|(
name|devclass_t
name|dc
parameter_list|,
name|devclass_t
name|pdc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|devclass_t
name|devclass_get_parent
parameter_list|(
name|devclass_t
name|dc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sysctl_ctx_list
modifier|*
name|devclass_get_sysctl_ctx
parameter_list|(
name|devclass_t
name|dc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sysctl_oid
modifier|*
name|devclass_get_sysctl_tree
parameter_list|(
name|devclass_t
name|dc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devclass_quiesce_driver
parameter_list|(
name|devclass_t
name|dc
parameter_list|,
name|kobj_class_t
name|driver
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Access functions for device resources.  */
end_comment

begin_function_decl
name|int
name|resource_int_value
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|unit
parameter_list|,
specifier|const
name|char
modifier|*
name|resname
parameter_list|,
name|int
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|resource_long_value
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|unit
parameter_list|,
specifier|const
name|char
modifier|*
name|resname
parameter_list|,
name|long
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|resource_string_value
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|unit
parameter_list|,
specifier|const
name|char
modifier|*
name|resname
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|resource_disabled
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|resource_find_match
parameter_list|(
name|int
modifier|*
name|anchor
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|name
parameter_list|,
name|int
modifier|*
name|unit
parameter_list|,
specifier|const
name|char
modifier|*
name|resname
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|resource_find_dev
parameter_list|(
name|int
modifier|*
name|anchor
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
modifier|*
name|unit
parameter_list|,
specifier|const
name|char
modifier|*
name|resname
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|resource_set_int
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|unit
parameter_list|,
specifier|const
name|char
modifier|*
name|resname
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|resource_set_long
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|unit
parameter_list|,
specifier|const
name|char
modifier|*
name|resname
parameter_list|,
name|long
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|resource_set_string
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|unit
parameter_list|,
specifier|const
name|char
modifier|*
name|resname
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions for maintaining and checking consistency of  * bus information exported to userspace.  */
end_comment

begin_function_decl
name|int
name|bus_data_generation_check
parameter_list|(
name|int
name|generation
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_data_generation_update
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Some convenience defines for probe routines to return.  These are just  * suggested values, and there's nothing magical about them.  * BUS_PROBE_SPECIFIC is for devices that cannot be reprobed, and that no  * possible other driver may exist (typically legacy drivers who don't fallow  * all the rules, or special needs drivers).  BUS_PROBE_VENDOR is the  * suggested value that vendor supplied drivers use.  This is for source or  * binary drivers that are not yet integrated into the FreeBSD tree.  Its use  * in the base OS is prohibited.  BUS_PROBE_DEFAULT is the normal return value  * for drivers to use.  It is intended that nearly all of the drivers in the  * tree should return this value.  BUS_PROBE_LOW_PRIORITY are for drivers that  * have special requirements like when there are two drivers that support  * overlapping series of hardware devices.  In this case the one that supports  * the older part of the line would return this value, while the one that  * supports the newer ones would return BUS_PROBE_DEFAULT.  BUS_PROBE_GENERIC  * is for drivers that wish to have a generic form and a specialized form,  * like is done with the pci bus and the acpi pci bus.  BUS_PROBE_HOOVER is  * for those busses that implement a generic device place-holder for devices on  * the bus that have no more specific driver for them (aka ugen).  */
end_comment

begin_define
define|#
directive|define
name|BUS_PROBE_SPECIFIC
value|0
end_define

begin_comment
comment|/* Only I can use this device */
end_comment

begin_define
define|#
directive|define
name|BUS_PROBE_VENDOR
value|(-10)
end_define

begin_comment
comment|/* Vendor supplied driver */
end_comment

begin_define
define|#
directive|define
name|BUS_PROBE_DEFAULT
value|(-20)
end_define

begin_comment
comment|/* Base OS default driver */
end_comment

begin_define
define|#
directive|define
name|BUS_PROBE_LOW_PRIORITY
value|(-40)
end_define

begin_comment
comment|/* Older, less desirable drivers */
end_comment

begin_define
define|#
directive|define
name|BUS_PROBE_GENERIC
value|(-100)
end_define

begin_comment
comment|/* generic driver for dev */
end_comment

begin_define
define|#
directive|define
name|BUS_PROBE_HOOVER
value|(-500)
end_define

begin_comment
comment|/* Generic dev for all devs on bus */
end_comment

begin_comment
comment|/**  * Shorthand for constructing method tables.  */
end_comment

begin_define
define|#
directive|define
name|DEVMETHOD
value|KOBJMETHOD
end_define

begin_comment
comment|/*  * Some common device interfaces.  */
end_comment

begin_include
include|#
directive|include
file|"device_if.h"
end_include

begin_include
include|#
directive|include
file|"bus_if.h"
end_include

begin_struct_decl
struct_decl|struct
name|module
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|driver_module_handler
parameter_list|(
name|struct
name|module
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Module support for automatically adding drivers to busses.  */
end_comment

begin_struct
struct|struct
name|driver_module_data
block|{
name|int
function_decl|(
modifier|*
name|dmd_chainevh
function_decl|)
parameter_list|(
name|struct
name|module
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|dmd_chainarg
decl_stmt|;
specifier|const
name|char
modifier|*
name|dmd_busname
decl_stmt|;
name|kobj_class_t
name|dmd_driver
decl_stmt|;
name|devclass_t
modifier|*
name|dmd_devclass
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DRIVER_MODULE
parameter_list|(
name|name
parameter_list|,
name|busname
parameter_list|,
name|driver
parameter_list|,
name|devclass
parameter_list|,
name|evh
parameter_list|,
name|arg
parameter_list|)
define|\ 									\
value|static struct driver_module_data name##_##busname##_driver_mod = {	\ 	evh, arg,							\ 	#busname,							\ 	(kobj_class_t)&driver,						\&devclass							\ };									\ 									\ static moduledata_t name##_##busname##_mod = {				\ 	#busname "/" #name,						\ 	driver_module_handler,						\&name##_##busname##_driver_mod					\ };									\ DECLARE_MODULE(name##_##busname, name##_##busname##_mod,		\ 	       SI_SUB_DRIVERS, SI_ORDER_MIDDLE)
end_define

begin_comment
comment|/**  * Generic ivar accessor generation macros for bus drivers  */
end_comment

begin_define
define|#
directive|define
name|__BUS_ACCESSOR
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
define|\ 									\
value|static __inline type varp ## _get_ ## var(device_t dev)			\ {									\ 	uintptr_t v;							\ 	BUS_READ_IVAR(device_get_parent(dev), dev,			\ 	    ivarp ## _IVAR_ ## ivar,&v);				\ 	return ((type) v);						\ }									\ 									\ static __inline void varp ## _set_ ## var(device_t dev, type t)		\ {									\ 	uintptr_t v = (uintptr_t) t;					\ 	BUS_WRITE_IVAR(device_get_parent(dev), dev,			\ 	    ivarp ## _IVAR_ ## ivar, v);				\ }
end_define

begin_comment
comment|/**  * Shorthand macros, taking resource argument  * Generated with sys/tools/bus_macro.sh  */
end_comment

begin_define
define|#
directive|define
name|bus_barrier
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|l
parameter_list|,
name|f
parameter_list|)
define|\
value|bus_space_barrier((r)->r_bustag, (r)->r_bushandle, (o), (l), (f))
end_define

begin_define
define|#
directive|define
name|bus_read_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|)
define|\
value|bus_space_read_1((r)->r_bustag, (r)->r_bushandle, (o))
end_define

begin_define
define|#
directive|define
name|bus_read_multi_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_multi_1((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_read_region_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_region_1((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_set_multi_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_multi_1((r)->r_bustag, (r)->r_bushandle, (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_set_region_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_region_1((r)->r_bustag, (r)->r_bushandle, (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_write_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|bus_space_write_1((r)->r_bustag, (r)->r_bushandle, (o), (v))
end_define

begin_define
define|#
directive|define
name|bus_write_multi_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_multi_1((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_write_region_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_region_1((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_read_stream_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|)
define|\
value|bus_space_read_stream_1((r)->r_bustag, (r)->r_bushandle, (o))
end_define

begin_define
define|#
directive|define
name|bus_read_multi_stream_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_multi_stream_1((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_read_region_stream_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_region_stream_1((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_set_multi_stream_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_multi_stream_1((r)->r_bustag, (r)->r_bushandle, (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_set_region_stream_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_region_stream_1((r)->r_bustag, (r)->r_bushandle, (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_write_stream_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|bus_space_write_stream_1((r)->r_bustag, (r)->r_bushandle, (o), (v))
end_define

begin_define
define|#
directive|define
name|bus_write_multi_stream_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_multi_stream_1((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_write_region_stream_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_region_stream_1((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_read_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|)
define|\
value|bus_space_read_2((r)->r_bustag, (r)->r_bushandle, (o))
end_define

begin_define
define|#
directive|define
name|bus_read_multi_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_multi_2((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_read_region_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_region_2((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_set_multi_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_multi_2((r)->r_bustag, (r)->r_bushandle, (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_set_region_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_region_2((r)->r_bustag, (r)->r_bushandle, (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_write_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|bus_space_write_2((r)->r_bustag, (r)->r_bushandle, (o), (v))
end_define

begin_define
define|#
directive|define
name|bus_write_multi_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_multi_2((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_write_region_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_region_2((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_read_stream_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|)
define|\
value|bus_space_read_stream_2((r)->r_bustag, (r)->r_bushandle, (o))
end_define

begin_define
define|#
directive|define
name|bus_read_multi_stream_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_multi_stream_2((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_read_region_stream_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_region_stream_2((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_set_multi_stream_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_multi_stream_2((r)->r_bustag, (r)->r_bushandle, (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_set_region_stream_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_region_stream_2((r)->r_bustag, (r)->r_bushandle, (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_write_stream_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|bus_space_write_stream_2((r)->r_bustag, (r)->r_bushandle, (o), (v))
end_define

begin_define
define|#
directive|define
name|bus_write_multi_stream_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_multi_stream_2((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_write_region_stream_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_region_stream_2((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_read_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|)
define|\
value|bus_space_read_4((r)->r_bustag, (r)->r_bushandle, (o))
end_define

begin_define
define|#
directive|define
name|bus_read_multi_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_multi_4((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_read_region_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_region_4((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_set_multi_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_multi_4((r)->r_bustag, (r)->r_bushandle, (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_set_region_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_region_4((r)->r_bustag, (r)->r_bushandle, (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_write_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|bus_space_write_4((r)->r_bustag, (r)->r_bushandle, (o), (v))
end_define

begin_define
define|#
directive|define
name|bus_write_multi_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_multi_4((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_write_region_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_region_4((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_read_stream_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|)
define|\
value|bus_space_read_stream_4((r)->r_bustag, (r)->r_bushandle, (o))
end_define

begin_define
define|#
directive|define
name|bus_read_multi_stream_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_multi_stream_4((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_read_region_stream_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_region_stream_4((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_set_multi_stream_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_multi_stream_4((r)->r_bustag, (r)->r_bushandle, (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_set_region_stream_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_region_stream_4((r)->r_bustag, (r)->r_bushandle, (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_write_stream_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|bus_space_write_stream_4((r)->r_bustag, (r)->r_bushandle, (o), (v))
end_define

begin_define
define|#
directive|define
name|bus_write_multi_stream_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_multi_stream_4((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_write_region_stream_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_region_stream_4((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_read_8
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|)
define|\
value|bus_space_read_8((r)->r_bustag, (r)->r_bushandle, (o))
end_define

begin_define
define|#
directive|define
name|bus_read_multi_8
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_multi_8((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_read_region_8
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_region_8((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_set_multi_8
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_multi_8((r)->r_bustag, (r)->r_bushandle, (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_set_region_8
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_region_8((r)->r_bustag, (r)->r_bushandle, (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_write_8
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|bus_space_write_8((r)->r_bustag, (r)->r_bushandle, (o), (v))
end_define

begin_define
define|#
directive|define
name|bus_write_multi_8
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_multi_8((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_write_region_8
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_region_8((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_read_stream_8
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|)
define|\
value|bus_space_read_stream_8((r)->r_bustag, (r)->r_bushandle, (o))
end_define

begin_define
define|#
directive|define
name|bus_read_multi_stream_8
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_multi_stream_8((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_read_region_stream_8
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_region_stream_8((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_set_multi_stream_8
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_multi_stream_8((r)->r_bustag, (r)->r_bushandle, (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_set_region_stream_8
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_region_stream_8((r)->r_bustag, (r)->r_bushandle, (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_write_stream_8
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|bus_space_write_stream_8((r)->r_bustag, (r)->r_bushandle, (o), (v))
end_define

begin_define
define|#
directive|define
name|bus_write_multi_stream_8
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_multi_stream_8((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bus_write_region_stream_8
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_region_stream_8((r)->r_bustag, (r)->r_bushandle, (o), (d), (c))
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
comment|/* !_SYS_BUS_H_ */
end_comment

end_unit

