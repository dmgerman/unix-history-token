begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997,1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_BUS_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_BUS_PRIVATE_H_
end_define

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_comment
comment|/*  * Forward declarations  */
end_comment

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument|devclass_list
argument_list|,
argument|devclass
argument_list|)
name|devclass_list_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument|driver_list
argument_list|,
argument|driver
argument_list|)
name|driver_list_t
expr_stmt|;
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
name|devclass
block|{
name|TAILQ_ENTRY
argument_list|(
argument|devclass
argument_list|)
name|link
expr_stmt|;
name|driver_list_t
name|drivers
decl_stmt|;
comment|/* bus devclasses store drivers for bus */
name|char
modifier|*
name|name
decl_stmt|;
name|device_t
modifier|*
name|devices
decl_stmt|;
comment|/* array of devices indexed by unit */
name|int
name|maxunit
decl_stmt|;
comment|/* size of devices array */
name|int
name|nextunit
decl_stmt|;
comment|/* next unused unit number */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Resources from config(8).  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|RES_INT
block|,
name|RES_STRING
block|,
name|RES_LONG
block|}
name|resource_type
typedef|;
end_typedef

begin_struct
struct|struct
name|config_resource
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|resource_type
name|type
decl_stmt|;
union|union
block|{
name|long
name|longval
decl_stmt|;
name|int
name|intval
decl_stmt|;
name|char
modifier|*
name|stringval
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|config_device
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* e.g. "lpt", "wdc" etc */
name|int
name|unit
decl_stmt|;
name|int
name|resource_count
decl_stmt|;
name|struct
name|config_resource
modifier|*
name|resources
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Compiled device methods.  */
end_comment

begin_struct
struct|struct
name|device_ops
block|{
name|int
name|maxoffset
decl_stmt|;
name|devop_t
name|methods
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Helpers for device method wrappers.  */
end_comment

begin_define
define|#
directive|define
name|DEVOPDESC
parameter_list|(
name|OP
parameter_list|)
value|(&OP##_##desc)
end_define

begin_define
define|#
directive|define
name|DEVOPOFF
parameter_list|(
name|DEV
parameter_list|,
name|OP
parameter_list|)
define|\
value|((DEVOPDESC(OP)->offset>= DEV->ops->maxoffset	\ 	  || !DEV->ops->methods[DEVOPDESC(OP)->offset])	\ 	 ? 0 : DEVOPDESC(OP)->offset)
end_define

begin_define
define|#
directive|define
name|DEVOPMETH
parameter_list|(
name|DEV
parameter_list|,
name|OP
parameter_list|)
value|(DEV->ops->methods[DEVOPOFF(DEV, OP)])
end_define

begin_comment
comment|/*  * Implementation of device.  */
end_comment

begin_struct
struct|struct
name|device
block|{
comment|/*      * Device hierarchy.      */
name|TAILQ_ENTRY
argument_list|(
argument|device
argument_list|)
name|link
expr_stmt|;
comment|/* list of devices in parent */
name|device_t
name|parent
decl_stmt|;
name|device_list_t
name|children
decl_stmt|;
comment|/* list of subordinate devices */
comment|/*      * Details of this device.      */
name|device_ops_t
name|ops
decl_stmt|;
name|driver_t
modifier|*
name|driver
decl_stmt|;
name|devclass_t
name|devclass
decl_stmt|;
comment|/* device class which we are in */
name|int
name|unit
decl_stmt|;
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
comment|/* driver specific description */
name|int
name|busy
decl_stmt|;
comment|/* count of calls to device_busy() */
name|device_state_t
name|state
decl_stmt|;
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|DF_ENABLED
value|1
comment|/* device should be probed/attached */
define|#
directive|define
name|DF_FIXEDCLASS
value|2
comment|/* devclass specified at create time */
define|#
directive|define
name|DF_WILDCARD
value|4
comment|/* unit was originally wildcard */
name|void
modifier|*
name|ivars
decl_stmt|;
name|void
modifier|*
name|softc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|device_op_desc
block|{
name|unsigned
name|int
name|offset
decl_stmt|;
comment|/* offset in driver ops */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* unique name (for registration) */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_BUS_PRIVATE_H_ */
end_comment

end_unit

