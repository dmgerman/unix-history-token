begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id$  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Forward declarations  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|bus
modifier|*
name|bus_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|device
modifier|*
name|device_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|driver
name|driver_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|devclass
modifier|*
name|devclass_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|driver_probe_t
parameter_list|(
name|bus_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|driver_attach_t
parameter_list|(
name|bus_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|driver_detach_t
parameter_list|(
name|bus_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|driver_shutdown_t
parameter_list|(
name|bus_t
name|bus
parameter_list|,
name|device_t
name|dev
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

begin_typedef
typedef|typedef
enum|enum
name|driver_type
block|{
name|DRIVER_TYPE_TTY
block|,
name|DRIVER_TYPE_BIO
block|,
name|DRIVER_TYPE_NET
block|,
name|DRIVER_TYPE_MISC
block|,
name|MAX_DRIVER_TYPE
block|}
name|driver_type_t
typedef|;
end_typedef

begin_struct
struct|struct
name|driver
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|driver_probe_t
modifier|*
name|probe
decl_stmt|;
name|driver_attach_t
modifier|*
name|attach
decl_stmt|;
name|driver_detach_t
modifier|*
name|detach
decl_stmt|;
name|driver_shutdown_t
modifier|*
name|shutdown
decl_stmt|;
name|driver_type_t
name|type
decl_stmt|;
name|size_t
name|softc
decl_stmt|;
comment|/* size of device softc struct */
name|TAILQ_ENTRY
argument_list|(
argument|driver
argument_list|)
name|link
expr_stmt|;
comment|/* list of devices on bus */
name|void
modifier|*
name|buspriv
decl_stmt|;
comment|/* private data for the owning bus */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|enum
name|device_state
name|device_state_t
typedef|;
end_typedef

begin_enum
enum|enum
name|device_state
block|{
name|DS_NOTPRESENT
block|,
comment|/* not probed or probe failed */
name|DS_ALIVE
block|,
comment|/* probe succeeded */
name|DS_ATTACHED
block|,
comment|/* attach method called */
name|DS_BUSY
comment|/* device is open */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Busses - containers of devices.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|bus_print_device_t
parameter_list|(
name|bus_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|bus_read_ivar_t
parameter_list|(
name|bus_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|,
name|int
name|index
parameter_list|,
name|u_long
modifier|*
name|result
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|bus_write_ivar_t
parameter_list|(
name|bus_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|,
name|int
name|index
parameter_list|,
name|u_long
name|value
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|bus_map_intr_t
parameter_list|(
name|bus_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|,
name|driver_intr_t
modifier|*
name|intr
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bus_ops
block|{
name|bus_print_device_t
modifier|*
name|print_device
decl_stmt|;
name|bus_read_ivar_t
modifier|*
name|read_ivar
decl_stmt|;
name|bus_write_ivar_t
modifier|*
name|write_ivar
decl_stmt|;
name|bus_map_intr_t
modifier|*
name|map_intr
decl_stmt|;
block|}
name|bus_ops_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument|device_list
argument_list|,
argument|device
argument_list|)
name|device_list_t
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|bus
block|{
name|bus_ops_t
modifier|*
name|ops
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
comment|/* device instance in parent bus */
name|device_list_t
name|devices
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bus priorities.  This determines the order in which busses are probed.  */
end_comment

begin_define
define|#
directive|define
name|BUS_PRIORITY_HIGH
value|1
end_define

begin_define
define|#
directive|define
name|BUS_PRIORITY_MEDIUM
value|2
end_define

begin_define
define|#
directive|define
name|BUS_PRIORITY_LOW
value|3
end_define

begin_comment
comment|/*  * The root bus, to which all top-level busses are attached.  */
end_comment

begin_decl_stmt
specifier|extern
name|bus_t
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
comment|/*  * Access functions for bus.  */
end_comment

begin_function_decl
name|device_t
name|bus_get_device
parameter_list|(
name|bus_t
name|bus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_print_device
parameter_list|(
name|bus_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_read_ivar
parameter_list|(
name|bus_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|,
name|int
name|index
parameter_list|,
name|u_long
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_write_ivar
parameter_list|(
name|bus_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|,
name|int
name|index
parameter_list|,
name|u_long
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_map_intr
parameter_list|(
name|bus_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|,
name|driver_intr_t
modifier|*
name|intr
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|bus_add_device
parameter_list|(
name|bus_t
name|bus
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|unit
parameter_list|,
name|void
modifier|*
name|ivars
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|bus_add_device_after
parameter_list|(
name|bus_t
name|bus
parameter_list|,
name|device_t
name|place
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|unit
parameter_list|,
name|void
modifier|*
name|ivars
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_delete_device
parameter_list|(
name|bus_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|bus_find_device
parameter_list|(
name|bus_t
name|bus
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

begin_comment
comment|/*  * Useful functions for implementing busses.  */
end_comment

begin_function_decl
name|void
name|bus_init
parameter_list|(
name|bus_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|,
name|bus_ops_t
modifier|*
name|ops
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|driver_attach_t
name|bus_generic_attach
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|driver_detach_t
name|bus_generic_detach
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|driver_shutdown_t
name|bus_generic_shutdown
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_print_device_t
name|null_print_device
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_read_ivar_t
name|null_read_ivar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_write_ivar_t
name|null_write_ivar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_map_intr_t
name|null_map_intr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bus_ops_t
name|null_bus_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Access functions for device.  */
end_comment

begin_function_decl
name|bus_t
name|device_get_parent
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
name|devclass_t
name|device_get_devclass
parameter_list|(
name|device_t
name|dev
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
name|int
name|device_get_unit
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
name|device_state_t
name|device_get_state
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
name|device_busy
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
name|device_probe_and_attach
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
name|int
name|device_shutdown
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
name|int
name|devclass_add_driver
parameter_list|(
name|devclass_t
name|dc
parameter_list|,
name|driver_t
modifier|*
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
name|driver_t
modifier|*
name|driver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|driver_t
modifier|*
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
name|devlistp
parameter_list|,
name|int
modifier|*
name|devcountp
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

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_MODULE_H_
end_ifdef

begin_comment
comment|/*  * Module support for automatically adding drivers to busses.  */
end_comment

begin_struct
struct|struct
name|driver_module_data
block|{
name|modeventhand_t
name|chainevh
decl_stmt|;
name|void
modifier|*
name|chainarg
decl_stmt|;
specifier|const
name|char
modifier|*
name|busname
decl_stmt|;
name|driver_t
modifier|*
name|driver
decl_stmt|;
name|devclass_t
modifier|*
name|devclass
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|driver_module_handler
name|__P
argument_list|(
operator|(
name|module_t
operator|,
name|modeventtype_t
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|static struct driver_module_data name##_driver_mod = {			\ 	evh, arg,							\ 	#busname,							\&driver,							\&devclass,							\ };									\ 									\ static moduledata_t name##_mod = {					\ 	#name,								\ 	driver_module_handler,						\&name##_driver_mod						\ };									\ DECLARE_MODULE(name, name##_mod, SI_SUB_DRIVERS, SI_ORDER_MIDDLE)
end_define

begin_define
define|#
directive|define
name|CDEV_DRIVER_MODULE
parameter_list|(
name|name
parameter_list|,
name|busname
parameter_list|,
name|driver
parameter_list|,
name|devclass
parameter_list|,	\
name|major
parameter_list|,
name|devsw
parameter_list|,
name|evh
parameter_list|,
name|arg
parameter_list|)
define|\ 								\
value|static struct cdevsw_module_data name##_cdevsw_mod = {		\     evh, arg, makedev(major, 0),&devsw				\ };								\ 								\ DRIVER_MODULE(name, busname, driver, devclass,			\ 	      cdevsw_module_handler,&name##_cdevsw_mod)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_BUS_H_ */
end_comment

end_unit

