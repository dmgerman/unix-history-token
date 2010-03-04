begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEVINFO_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_DEVINFO_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_typedef
typedef|typedef
name|__uintptr_t
name|devinfo_handle_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEVINFO_ROOT_DEVICE
value|((devinfo_handle_t)0)
end_define

begin_typedef
typedef|typedef
name|enum
name|device_state
name|devinfo_state_t
typedef|;
end_typedef

begin_struct
struct|struct
name|devinfo_dev
block|{
name|devinfo_handle_t
name|dd_handle
decl_stmt|;
comment|/* device handle */
name|devinfo_handle_t
name|dd_parent
decl_stmt|;
comment|/* parent handle */
name|char
modifier|*
name|dd_name
decl_stmt|;
comment|/* name of device */
name|char
modifier|*
name|dd_desc
decl_stmt|;
comment|/* device description */
name|char
modifier|*
name|dd_drivername
decl_stmt|;
comment|/* name of attached driver*/
name|char
modifier|*
name|dd_pnpinfo
decl_stmt|;
comment|/* pnp info from parent bus */
name|char
modifier|*
name|dd_location
decl_stmt|;
comment|/* Where bus thinks dev at */
name|uint32_t
name|dd_devflags
decl_stmt|;
comment|/* API flags */
name|uint16_t
name|dd_flags
decl_stmt|;
comment|/* internal dev flags */
name|devinfo_state_t
name|dd_state
decl_stmt|;
comment|/* attacement state of dev */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|devinfo_rman
block|{
name|devinfo_handle_t
name|dm_handle
decl_stmt|;
comment|/* resource manager handle */
name|unsigned
name|long
name|dm_start
decl_stmt|;
comment|/* resource start */
name|unsigned
name|long
name|dm_size
decl_stmt|;
comment|/* resource size */
name|char
modifier|*
name|dm_desc
decl_stmt|;
comment|/* resource description */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|devinfo_res
block|{
name|devinfo_handle_t
name|dr_handle
decl_stmt|;
comment|/* resource handle */
name|devinfo_handle_t
name|dr_rman
decl_stmt|;
comment|/* resource manager handle */
name|devinfo_handle_t
name|dr_device
decl_stmt|;
comment|/* owning device */
name|unsigned
name|long
name|dr_start
decl_stmt|;
comment|/* region start */
name|unsigned
name|long
name|dr_size
decl_stmt|;
comment|/* region size */
comment|/* XXX add flags */
block|}
struct|;
end_struct

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * Acquire a coherent copy of the kernel's device and resource tables.  * This must return success (zero) before any other interfaces will  * function.  Sets errno on failure.  */
specifier|extern
name|int
name|devinfo_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Release the storage associated with the internal copy of the device  * and resource tables. devinfo_init must be called before any attempt  * is made to use any other interfaces.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|devinfo_free
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find a device/resource/resource manager by its handle.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|devinfo_dev
modifier|*
name|devinfo_handle_to_device
parameter_list|(
name|devinfo_handle_t
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|devinfo_res
modifier|*
name|devinfo_handle_to_resource
parameter_list|(
name|devinfo_handle_t
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|devinfo_rman
modifier|*
name|devinfo_handle_to_rman
parameter_list|(
name|devinfo_handle_t
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Iterate over the children of a device, calling (fn) on each.  If  * (fn) returns nonzero, abort the scan and return.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|devinfo_foreach_device_child
parameter_list|(
name|struct
name|devinfo_dev
modifier|*
name|parent
parameter_list|,
name|int
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|struct
name|devinfo_dev
modifier|*
name|child
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

begin_comment
comment|/*  * Iterate over all the resources owned by a device, calling (fn) on each.  * If (fn) returns nonzero, abort the scan and return.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|devinfo_foreach_device_resource
parameter_list|(
name|struct
name|devinfo_dev
modifier|*
name|dev
parameter_list|,
name|int
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|struct
name|devinfo_dev
modifier|*
name|dev
parameter_list|,
name|struct
name|devinfo_res
modifier|*
name|res
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

begin_comment
comment|/*  * Iterate over all the resources owned by a resource manager, calling (fn)  * on each.  If (fn) returns nonzero, abort the scan and return.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|devinfo_foreach_rman_resource
parameter_list|(
name|struct
name|devinfo_rman
modifier|*
name|rman
parameter_list|,
name|int
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|struct
name|devinfo_res
modifier|*
name|res
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

begin_comment
comment|/*  * Iterate over all the resource managers, calling (fn) on each.  If (fn)  * returns nonzero, abort the scan and return.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|devinfo_foreach_rman
parameter_list|(
name|int
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|struct
name|devinfo_rman
modifier|*
name|rman
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

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _DEVINFO_H_INCLUDED */
end_comment

end_unit

