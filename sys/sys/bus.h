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
file|<machine/_limits.h>
end_include

begin_include
include|#
directive|include
file|<machine/_bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/_bus_dma.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioccom.h>
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
init|=
literal|10
block|,
comment|/**< @brief not probed or probe failed */
name|DS_ALIVE
init|=
literal|20
block|,
comment|/**< @brief probe succeeded */
name|DS_ATTACHING
init|=
literal|25
block|,
comment|/**< @brief currently attaching */
name|DS_ATTACHED
init|=
literal|30
block|,
comment|/**< @brief attach method called */
name|DS_BUSY
init|=
literal|40
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
comment|/**< @brief flags for dev state */
name|device_state_t
name|dv_state
decl_stmt|;
comment|/**< @brief State of attachment */
comment|/* XXX more driver info? */
block|}
struct|;
end_struct

begin_comment
comment|/* Flags exported via dv_flags. */
end_comment

begin_define
define|#
directive|define
name|DF_ENABLED
value|0x01
end_define

begin_comment
comment|/* device should be probed/attached */
end_comment

begin_define
define|#
directive|define
name|DF_FIXEDCLASS
value|0x02
end_define

begin_comment
comment|/* devclass specified at create time */
end_comment

begin_define
define|#
directive|define
name|DF_WILDCARD
value|0x04
end_define

begin_comment
comment|/* unit was originally wildcard */
end_comment

begin_define
define|#
directive|define
name|DF_DESCMALLOCED
value|0x08
end_define

begin_comment
comment|/* description was malloced */
end_comment

begin_define
define|#
directive|define
name|DF_QUIET
value|0x10
end_define

begin_comment
comment|/* don't print verbose attach message */
end_comment

begin_define
define|#
directive|define
name|DF_DONENOMATCH
value|0x20
end_define

begin_comment
comment|/* don't execute DEVICE_NOMATCH again */
end_comment

begin_define
define|#
directive|define
name|DF_EXTERNALSOFTC
value|0x40
end_define

begin_comment
comment|/* softc not allocated by us */
end_comment

begin_define
define|#
directive|define
name|DF_REBID
value|0x80
end_define

begin_comment
comment|/* Can rebid after attach */
end_comment

begin_define
define|#
directive|define
name|DF_SUSPENDED
value|0x100
end_define

begin_comment
comment|/* Device is suspended. */
end_comment

begin_comment
comment|/**  * @brief Device request structure used for ioctl's.  *  * Used for ioctl's on /dev/devctl2.  All device ioctl's  * must have parameter definitions which begin with dr_name.  */
end_comment

begin_struct
struct|struct
name|devreq_buffer
block|{
name|void
modifier|*
name|buffer
decl_stmt|;
name|size_t
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|devreq
block|{
name|char
name|dr_name
index|[
literal|128
index|]
decl_stmt|;
name|int
name|dr_flags
decl_stmt|;
comment|/* request-specific flags */
union|union
block|{
name|struct
name|devreq_buffer
name|dru_buffer
decl_stmt|;
name|void
modifier|*
name|dru_data
decl_stmt|;
block|}
name|dr_dru
union|;
define|#
directive|define
name|dr_buffer
value|dr_dru.dru_buffer
comment|/* variable-sized buffer */
define|#
directive|define
name|dr_data
value|dr_dru.dru_data
comment|/* fixed-size buffer */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEV_ATTACH
value|_IOW('D', 1, struct devreq)
end_define

begin_define
define|#
directive|define
name|DEV_DETACH
value|_IOW('D', 2, struct devreq)
end_define

begin_define
define|#
directive|define
name|DEV_ENABLE
value|_IOW('D', 3, struct devreq)
end_define

begin_define
define|#
directive|define
name|DEV_DISABLE
value|_IOW('D', 4, struct devreq)
end_define

begin_define
define|#
directive|define
name|DEV_SUSPEND
value|_IOW('D', 5, struct devreq)
end_define

begin_define
define|#
directive|define
name|DEV_RESUME
value|_IOW('D', 6, struct devreq)
end_define

begin_define
define|#
directive|define
name|DEV_SET_DRIVER
value|_IOW('D', 7, struct devreq)
end_define

begin_define
define|#
directive|define
name|DEV_CLEAR_DRIVER
value|_IOW('D', 8, struct devreq)
end_define

begin_define
define|#
directive|define
name|DEV_RESCAN
value|_IOW('D', 9, struct devreq)
end_define

begin_define
define|#
directive|define
name|DEV_DELETE
value|_IOW('D', 10, struct devreq)
end_define

begin_comment
comment|/* Flags for DEV_DETACH and DEV_DISABLE. */
end_comment

begin_define
define|#
directive|define
name|DEVF_FORCE_DETACH
value|0x0000001
end_define

begin_comment
comment|/* Flags for DEV_SET_DRIVER. */
end_comment

begin_define
define|#
directive|define
name|DEVF_SET_DRIVER_DETACH
value|0x0000001
end_define

begin_comment
comment|/* Detach existing driver. */
end_comment

begin_comment
comment|/* Flags for DEV_CLEAR_DRIVER. */
end_comment

begin_define
define|#
directive|define
name|DEVF_CLEAR_DRIVER_DETACH
value|0x0000001
end_define

begin_comment
comment|/* Detach existing driver. */
end_comment

begin_comment
comment|/* Flags for DEV_DELETE. */
end_comment

begin_define
define|#
directive|define
name|DEVF_FORCE_DELETE
value|0x0000001
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
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
name|boolean_t
name|devctl_process_running
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devctl_notify_f
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
parameter_list|,
name|int
name|__flags
parameter_list|)
function_decl|;
end_function_decl

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
name|devctl_queue_data_f
parameter_list|(
name|char
modifier|*
name|__data
parameter_list|,
name|int
name|__flags
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

begin_function_decl
name|void
name|devctl_safe_quote
parameter_list|(
name|char
modifier|*
name|__dst
parameter_list|,
specifier|const
name|char
modifier|*
name|__src
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Device name parsers.  Hook to allow device enumerators to map  * scheme-specific names to a device.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dev_lookup_fn
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|device_t
modifier|*
name|result
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|dev_lookup
argument_list|,
name|dev_lookup_fn
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/**  * @brief A device method  */
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
comment|/**  * @brief Interrupt type bits.  *   * These flags are used both by newbus interrupt  * registration (nexus.c) and also in struct intrec, which defines  * interrupt properties.  *  * XXX We should probably revisit this and remove the vestiges of the  * spls implicit in names like INTR_TYPE_TTY. In the meantime, don't  * confuse things by renaming them (Grog, 18 July 2000).  *  * Buses which do interrupt remapping will want to change their type  * to reflect what sort of devices are underneath.  */
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
block|,
comment|/* this interrupt provides entropy */
name|INTR_MD1
init|=
literal|4096
block|,
comment|/* flag reserved for MD use */
name|INTR_MD2
init|=
literal|8192
block|,
comment|/* flag reserved for MD use */
name|INTR_MD3
init|=
literal|16384
block|,
comment|/* flag reserved for MD use */
name|INTR_MD4
init|=
literal|32768
comment|/* flag reserved for MD use */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|intr_trigger
block|{
name|INTR_TRIGGER_INVALID
init|=
operator|-
literal|1
block|,
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

begin_comment
comment|/**  * CPU sets supported by bus_get_cpus().  Note that not all sets may be  * supported for a given device.  If a request is not supported by a  * device (or its parents), then bus_get_cpus() will fail with EINVAL.  */
end_comment

begin_enum
enum|enum
name|cpu_sets
block|{
name|LOCAL_CPUS
init|=
literal|0
block|,
name|INTR_CPUS
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
comment|/**  * @brief A resource mapping.  */
end_comment

begin_struct
struct|struct
name|resource_map
block|{
name|bus_space_tag_t
name|r_bustag
decl_stmt|;
name|bus_space_handle_t
name|r_bushandle
decl_stmt|;
name|bus_size_t
name|r_size
decl_stmt|;
name|void
modifier|*
name|r_vaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief Optional properties of a resource mapping request.  */
end_comment

begin_struct
struct|struct
name|resource_map_request
block|{
name|size_t
name|size
decl_stmt|;
name|rman_res_t
name|offset
decl_stmt|;
name|rman_res_t
name|length
decl_stmt|;
name|vm_memattr_t
name|memattr
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|resource_init_map_request_impl
parameter_list|(
name|struct
name|resource_map_request
modifier|*
name|_args
parameter_list|,
name|size_t
name|_sz
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|resource_init_map_request
parameter_list|(
name|rmr
parameter_list|)
define|\
value|resource_init_map_request_impl((rmr), sizeof(*(rmr)))
end_define

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
name|int
name|flags
decl_stmt|;
comment|/**< @brief resource flags */
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
comment|/**< @brief the real resource when allocated */
name|rman_res_t
name|start
decl_stmt|;
comment|/**< @brief start of resource range */
name|rman_res_t
name|end
decl_stmt|;
comment|/**< @brief end of resource range */
name|rman_res_t
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

begin_define
define|#
directive|define
name|RLE_RESERVED
value|0x0001
end_define

begin_comment
comment|/* Reserved by the parent bus. */
end_comment

begin_define
define|#
directive|define
name|RLE_ALLOCATED
value|0x0002
end_define

begin_comment
comment|/* Reserved resource is allocated. */
end_comment

begin_define
define|#
directive|define
name|RLE_PREFETCH
value|0x0004
end_define

begin_comment
comment|/* Resource is a prefetch range. */
end_comment

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
name|rman_res_t
name|start
parameter_list|,
name|rman_res_t
name|end
parameter_list|,
name|rman_res_t
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
name|rman_res_t
name|start
parameter_list|,
name|rman_res_t
name|end
parameter_list|,
name|rman_res_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|resource_list_busy
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
name|int
name|resource_list_reserved
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
name|rman_res_t
name|start
parameter_list|,
name|rman_res_t
name|end
parameter_list|,
name|rman_res_t
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
name|int
name|resource_list_release_active
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|resource
modifier|*
name|resource_list_reserve
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
name|rman_res_t
name|start
parameter_list|,
name|rman_res_t
name|end
parameter_list|,
name|rman_res_t
name|count
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|resource_list_unreserve
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
name|u_int
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
name|int
name|bus_generic_adjust_resource
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
name|struct
name|resource
modifier|*
name|r
parameter_list|,
name|rman_res_t
name|start
parameter_list|,
name|rman_res_t
name|end
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
name|rman_res_t
name|start
parameter_list|,
name|rman_res_t
name|end
parameter_list|,
name|rman_res_t
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
name|bus_generic_bind_intr
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
name|cpu
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
name|bus_generic_describe_intr
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
parameter_list|,
specifier|const
name|char
modifier|*
name|descr
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
name|int
name|bus_generic_get_cpus
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|enum
name|cpu_sets
name|op
parameter_list|,
name|size_t
name|setsize
parameter_list|,
name|struct
name|_cpuset
modifier|*
name|cpuset
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
name|bus_space_tag_t
name|bus_generic_get_bus_tag
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
name|bus_generic_get_domain
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
modifier|*
name|domain
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
name|bus_generic_map_resource
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
name|struct
name|resource
modifier|*
name|r
parameter_list|,
name|struct
name|resource_map_request
modifier|*
name|args
parameter_list|,
name|struct
name|resource_map
modifier|*
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_generic_new_pass
parameter_list|(
name|device_t
name|dev
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
name|bus_print_child_domain
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
name|bus_generic_resume_child
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
name|rman_res_t
parameter_list|,
name|rman_res_t
parameter_list|,
name|rman_res_t
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
name|rman_res_t
modifier|*
parameter_list|,
name|rman_res_t
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
name|rman_res_t
parameter_list|,
name|rman_res_t
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
name|bus_generic_suspend_child
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
name|bus_generic_unmap_resource
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
name|struct
name|resource
modifier|*
name|r
parameter_list|,
name|struct
name|resource_map
modifier|*
name|map
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

begin_function_decl
name|int
name|bus_null_rescan
parameter_list|(
name|device_t
name|dev
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
name|int
name|bus_adjust_resource
parameter_list|(
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|,
name|rman_res_t
name|start
parameter_list|,
name|rman_res_t
name|end
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
name|rman_res_t
name|start
parameter_list|,
name|rman_res_t
name|end
parameter_list|,
name|rman_res_t
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
name|int
name|bus_map_resource
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
parameter_list|,
name|struct
name|resource_map_request
modifier|*
name|args
parameter_list|,
name|struct
name|resource_map
modifier|*
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_unmap_resource
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
parameter_list|,
name|struct
name|resource_map
modifier|*
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_get_cpus
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|enum
name|cpu_sets
name|op
parameter_list|,
name|size_t
name|setsize
parameter_list|,
name|struct
name|_cpuset
modifier|*
name|cpuset
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
name|bus_space_tag_t
name|bus_get_bus_tag
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_get_domain
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
modifier|*
name|domain
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
name|bus_bind_intr
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
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_describe_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|resource
modifier|*
name|irq
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|4
operator|,
function_decl|5
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

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
name|rman_res_t
name|start
parameter_list|,
name|rman_res_t
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
name|rman_res_t
modifier|*
name|startp
parameter_list|,
name|rman_res_t
modifier|*
name|countp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rman_res_t
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
name|rman_res_t
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
literal|0
argument_list|,
operator|~
literal|0
argument_list|,
literal|1
argument_list|,
name|flags
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|resource
operator|*
name|bus_alloc_resource_anywhere
argument_list|(
argument|device_t dev
argument_list|,
argument|int type
argument_list|,
argument|int *rid
argument_list|,
argument|rman_res_t count
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
literal|0
argument_list|,
operator|~
literal|0
argument_list|,
name|count
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
name|u_int
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
name|device_delete_children
parameter_list|(
name|device_t
name|dev
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
name|device_is_suspended
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
name|device_t
name|device_lookup_by_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
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
name|device_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

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
name|device_set_devclass_fixed
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
name|void
name|device_free_softc
parameter_list|(
name|void
modifier|*
name|softc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_claim_softc
parameter_list|(
name|device_t
name|dev
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
name|driver_t
modifier|*
name|driver
parameter_list|,
name|int
name|pass
parameter_list|,
name|devclass_t
modifier|*
name|dcp
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
name|int
name|devclass_delete_driver
parameter_list|(
name|devclass_t
name|busclass
parameter_list|,
name|driver_t
modifier|*
name|driver
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
name|resource_unset_value
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
comment|/**  * Some convenience defines for probe routines to return.  These are just  * suggested values, and there's nothing magical about them.  * BUS_PROBE_SPECIFIC is for devices that cannot be reprobed, and that no  * possible other driver may exist (typically legacy drivers who don't fallow  * all the rules, or special needs drivers).  BUS_PROBE_VENDOR is the  * suggested value that vendor supplied drivers use.  This is for source or  * binary drivers that are not yet integrated into the FreeBSD tree.  Its use  * in the base OS is prohibited.  BUS_PROBE_DEFAULT is the normal return value  * for drivers to use.  It is intended that nearly all of the drivers in the  * tree should return this value.  BUS_PROBE_LOW_PRIORITY are for drivers that  * have special requirements like when there are two drivers that support  * overlapping series of hardware devices.  In this case the one that supports  * the older part of the line would return this value, while the one that  * supports the newer ones would return BUS_PROBE_DEFAULT.  BUS_PROBE_GENERIC  * is for drivers that wish to have a generic form and a specialized form,  * like is done with the pci bus and the acpi pci bus.  BUS_PROBE_HOOVER is  * for those busses that implement a generic device place-holder for devices on  * the bus that have no more specific driver for them (aka ugen).  * BUS_PROBE_NOWILDCARD or lower means that the device isn't really bidding  * for a device node, but accepts only devices that its parent has told it  * use this driver.  */
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
value|(-1000000)
end_define

begin_comment
comment|/* Driver for any dev on bus */
end_comment

begin_define
define|#
directive|define
name|BUS_PROBE_NOWILDCARD
value|(-2000000000)
end_define

begin_comment
comment|/* No wildcard device matches */
end_comment

begin_comment
comment|/**  * During boot, the device tree is scanned multiple times.  Each scan,  * or pass, drivers may be attached to devices.  Each driver  * attachment is assigned a pass number.  Drivers may only probe and  * attach to devices if their pass number is less than or equal to the  * current system-wide pass number.  The default pass is the last pass  * and is used by most drivers.  Drivers needed by the scheduler are  * probed in earlier passes.  */
end_comment

begin_define
define|#
directive|define
name|BUS_PASS_ROOT
value|0
end_define

begin_comment
comment|/* Used to attach root0. */
end_comment

begin_define
define|#
directive|define
name|BUS_PASS_BUS
value|10
end_define

begin_comment
comment|/* Busses and bridges. */
end_comment

begin_define
define|#
directive|define
name|BUS_PASS_CPU
value|20
end_define

begin_comment
comment|/* CPU devices. */
end_comment

begin_define
define|#
directive|define
name|BUS_PASS_RESOURCE
value|30
end_define

begin_comment
comment|/* Resource discovery. */
end_comment

begin_define
define|#
directive|define
name|BUS_PASS_INTERRUPT
value|40
end_define

begin_comment
comment|/* Interrupt controllers. */
end_comment

begin_define
define|#
directive|define
name|BUS_PASS_TIMER
value|50
end_define

begin_comment
comment|/* Timers and clocks. */
end_comment

begin_define
define|#
directive|define
name|BUS_PASS_SCHEDULER
value|60
end_define

begin_comment
comment|/* Start scheduler. */
end_comment

begin_define
define|#
directive|define
name|BUS_PASS_DEFAULT
value|__INT_MAX
end_define

begin_comment
comment|/* Everything else. */
end_comment

begin_define
define|#
directive|define
name|BUS_PASS_ORDER_FIRST
value|0
end_define

begin_define
define|#
directive|define
name|BUS_PASS_ORDER_EARLY
value|2
end_define

begin_define
define|#
directive|define
name|BUS_PASS_ORDER_MIDDLE
value|5
end_define

begin_define
define|#
directive|define
name|BUS_PASS_ORDER_LATE
value|7
end_define

begin_define
define|#
directive|define
name|BUS_PASS_ORDER_LAST
value|9
end_define

begin_decl_stmt
specifier|extern
name|int
name|bus_current_pass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|bus_set_pass
parameter_list|(
name|int
name|pass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Shorthands for constructing method tables.  */
end_comment

begin_define
define|#
directive|define
name|DEVMETHOD
value|KOBJMETHOD
end_define

begin_define
define|#
directive|define
name|DEVMETHOD_END
value|KOBJMETHOD_END
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
name|int
name|dmd_pass
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EARLY_DRIVER_MODULE_ORDERED
parameter_list|(
name|name
parameter_list|,
name|busname
parameter_list|,
name|driver
parameter_list|,
name|devclass
parameter_list|,	\
name|evh
parameter_list|,
name|arg
parameter_list|,
name|order
parameter_list|,
name|pass
parameter_list|)
define|\ 									\
value|static struct driver_module_data name##_##busname##_driver_mod = {	\ 	evh, arg,							\ 	#busname,							\ 	(kobj_class_t)&driver,						\&devclass,							\ 	pass								\ };									\ 									\ static moduledata_t name##_##busname##_mod = {				\ 	#busname "/" #name,						\ 	driver_module_handler,						\&name##_##busname##_driver_mod					\ };									\ DECLARE_MODULE(name##_##busname, name##_##busname##_mod,		\ 	       SI_SUB_DRIVERS, order)
end_define

begin_define
define|#
directive|define
name|EARLY_DRIVER_MODULE
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
parameter_list|,
name|pass
parameter_list|)
define|\
value|EARLY_DRIVER_MODULE_ORDERED(name, busname, driver, devclass,	\ 	    evh, arg, SI_ORDER_MIDDLE, pass)
end_define

begin_define
define|#
directive|define
name|DRIVER_MODULE_ORDERED
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
parameter_list|,\
name|order
parameter_list|)
define|\
value|EARLY_DRIVER_MODULE_ORDERED(name, busname, driver, devclass,	\ 	    evh, arg, order, BUS_PASS_DEFAULT)
end_define

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
define|\
value|EARLY_DRIVER_MODULE(name, busname, driver, devclass, evh, arg,	\ 	    BUS_PASS_DEFAULT)
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

