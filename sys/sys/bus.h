begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997,1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: bus.h,v 1.1 1998/06/10 10:57:21 dfr Exp $  */
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
name|device_method
name|device_method_t
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
name|struct
name|device_ops
modifier|*
name|device_ops_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|device_op_desc
modifier|*
name|device_op_desc_t
typedef|;
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

begin_struct
struct|struct
name|device_method
block|{
name|device_op_desc_t
name|desc
decl_stmt|;
name|devop_t
name|func
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|driver
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* driver name */
name|device_method_t
modifier|*
name|methods
decl_stmt|;
comment|/* method table */
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
name|device_ops_t
name|ops
decl_stmt|;
comment|/* compiled method table */
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
comment|/*  * Access functions for busses.  */
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
parameter_list|,
name|void
modifier|*
name|ivars
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|device_add_child_after
parameter_list|(
name|device_t
name|dev
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

begin_comment
comment|/*  * Useful functions for implementing busses.  */
end_comment

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
name|bus_generic_detach
parameter_list|(
name|device_t
name|dev
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
name|void
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
name|u_long
modifier|*
name|result
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
name|u_long
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_map_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
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

begin_comment
comment|/*  * Access functions for device.  */
end_comment

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

begin_comment
comment|/*  * Shorthand for constructing method tables.  */
end_comment

begin_define
define|#
directive|define
name|DEVMETHOD
parameter_list|(
name|NAME
parameter_list|,
name|FUNC
parameter_list|)
value|{&NAME##_desc, (devop_t) FUNC }
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

begin_function_decl
name|int
name|driver_module_handler
parameter_list|(
name|module_t
parameter_list|,
name|modeventtype_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

