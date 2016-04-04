begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2016 Michal Meloun<mmel@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_EXTRES_REGULATOR_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_EXTRES_REGULATOR_H_
end_define

begin_include
include|#
directive|include
file|"opt_platform.h"
end_include

begin_include
include|#
directive|include
file|<sys/kobj.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"regnode_if.h"
end_include

begin_define
define|#
directive|define
name|REGULATOR_FLAGS_STATIC
value|0x00000001
end_define

begin_comment
comment|/* Static strings */
end_comment

begin_define
define|#
directive|define
name|REGULATOR_FLAGS_NOT_DISABLE
value|0x00000002
end_define

begin_comment
comment|/* Cannot be disabled */
end_comment

begin_define
define|#
directive|define
name|REGULATOR_STATUS_ENABLED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|REGULATOR_STATUS_OVERCURRENT
value|0x00000002
end_define

begin_typedef
typedef|typedef
name|struct
name|regulator
modifier|*
name|regulator_t
typedef|;
end_typedef

begin_comment
comment|/* Standard regulator parameters. */
end_comment

begin_struct
struct|struct
name|regnode_std_param
block|{
name|int
name|min_uvolt
decl_stmt|;
comment|/* In uV */
name|int
name|max_uvolt
decl_stmt|;
comment|/* In uV */
name|int
name|min_uamp
decl_stmt|;
comment|/* In uA */
name|int
name|max_uamp
decl_stmt|;
comment|/* In uA */
name|int
name|ramp_delay
decl_stmt|;
comment|/* In uV/usec */
name|int
name|enable_delay
decl_stmt|;
comment|/* In usec */
name|bool
name|boot_on
decl_stmt|;
comment|/* Is enabled on boot */
name|bool
name|always_on
decl_stmt|;
comment|/* Must be enabled */
name|int
name|enable_active_high
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Initialization parameters. */
end_comment

begin_struct
struct|struct
name|regnode_init_def
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Regulator name */
name|char
modifier|*
name|parent_name
decl_stmt|;
comment|/* Name of parent regulator */
name|struct
name|regnode_std_param
name|std_param
decl_stmt|;
comment|/* Standard parameters */
name|intptr_t
name|id
decl_stmt|;
comment|/* Regulator ID */
name|int
name|flags
decl_stmt|;
comment|/* Flags */
ifdef|#
directive|ifdef
name|FDT
name|phandle_t
name|ofw_node
decl_stmt|;
comment|/* OFW node of regulator */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Shorthands for constructing method tables.  */
end_comment

begin_define
define|#
directive|define
name|REGNODEMETHOD
value|KOBJMETHOD
end_define

begin_define
define|#
directive|define
name|REGNODEMETHOD_END
value|KOBJMETHOD_END
end_define

begin_define
define|#
directive|define
name|regnode_method_t
value|kobj_method_t
end_define

begin_define
define|#
directive|define
name|regnode_class_t
value|kobj_class_t
end_define

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|regnode_class
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Providers interface. */
end_comment

begin_function_decl
name|struct
name|regnode
modifier|*
name|regnode_create
parameter_list|(
name|device_t
name|pdev
parameter_list|,
name|regnode_class_t
name|regnode_class
parameter_list|,
name|struct
name|regnode_init_def
modifier|*
name|def
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|regnode
modifier|*
name|regnode_register
parameter_list|(
name|struct
name|regnode
modifier|*
name|regnode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|regnode_get_name
parameter_list|(
name|struct
name|regnode
modifier|*
name|regnode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|regnode_get_parent_name
parameter_list|(
name|struct
name|regnode
modifier|*
name|regnode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|regnode
modifier|*
name|regnode_get_parent
parameter_list|(
name|struct
name|regnode
modifier|*
name|regnode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regnode_get_flags
parameter_list|(
name|struct
name|regnode
modifier|*
name|regnode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|regnode_get_softc
parameter_list|(
name|struct
name|regnode
modifier|*
name|regnode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|regnode_get_device
parameter_list|(
name|struct
name|regnode
modifier|*
name|regnode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|regnode_std_param
modifier|*
name|regnode_get_stdparam
parameter_list|(
name|struct
name|regnode
modifier|*
name|regnode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|regnode_topo_unlock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|regnode_topo_xlock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|regnode_topo_slock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regnode_enable
parameter_list|(
name|struct
name|regnode
modifier|*
name|regnode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regnode_disable
parameter_list|(
name|struct
name|regnode
modifier|*
name|regnode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regnode_stop
parameter_list|(
name|struct
name|regnode
modifier|*
name|regnode
parameter_list|,
name|int
name|depth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regnode_status
parameter_list|(
name|struct
name|regnode
modifier|*
name|regnode
parameter_list|,
name|int
modifier|*
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regnode_get_voltage
parameter_list|(
name|struct
name|regnode
modifier|*
name|regnode
parameter_list|,
name|int
modifier|*
name|uvolt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regnode_set_voltage
parameter_list|(
name|struct
name|regnode
modifier|*
name|regnode
parameter_list|,
name|int
name|min_uvolt
parameter_list|,
name|int
name|max_uvolt
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_function_decl
name|phandle_t
name|regnode_get_ofw_node
parameter_list|(
name|struct
name|regnode
modifier|*
name|regnode
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Consumers interface. */
end_comment

begin_function_decl
name|int
name|regulator_get_by_name
parameter_list|(
name|device_t
name|cdev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|regulator_t
modifier|*
name|regulator
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regulator_get_by_id
parameter_list|(
name|device_t
name|cdev
parameter_list|,
name|device_t
name|pdev
parameter_list|,
name|intptr_t
name|id
parameter_list|,
name|regulator_t
modifier|*
name|regulator
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regulator_release
parameter_list|(
name|regulator_t
name|regulator
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|regulator_get_name
parameter_list|(
name|regulator_t
name|regulator
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regulator_enable
parameter_list|(
name|regulator_t
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regulator_disable
parameter_list|(
name|regulator_t
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regulator_stop
parameter_list|(
name|regulator_t
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regulator_status
parameter_list|(
name|regulator_t
name|reg
parameter_list|,
name|int
modifier|*
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regulator_get_voltage
parameter_list|(
name|regulator_t
name|reg
parameter_list|,
name|int
modifier|*
name|uvolt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regulator_set_voltage
parameter_list|(
name|regulator_t
name|reg
parameter_list|,
name|int
name|min_uvolt
parameter_list|,
name|int
name|max_uvolt
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_function_decl
name|int
name|regulator_get_by_ofw_property
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|regulator_t
modifier|*
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regulator_parse_ofw_stdparam
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|phandle_t
name|node
parameter_list|,
name|struct
name|regnode_init_def
modifier|*
name|def
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_EXTRES_REGULATOR_H_ */
end_comment

end_unit

