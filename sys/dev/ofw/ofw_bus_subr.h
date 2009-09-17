begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Marius Strobl<marius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_OFW_OFW_BUS_SUBR_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_OFW_OFW_BUS_SUBR_H_
end_define

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_include
include|#
directive|include
file|"ofw_bus_if.h"
end_include

begin_define
define|#
directive|define
name|ORIP_NOINT
value|-1
end_define

begin_define
define|#
directive|define
name|ORIR_NOTFOUND
value|0xffffffff
end_define

begin_struct
struct|struct
name|ofw_bus_iinfo
block|{
name|u_int8_t
modifier|*
name|opi_imap
decl_stmt|;
name|u_int8_t
modifier|*
name|opi_imapmsk
decl_stmt|;
name|int
name|opi_imapsz
decl_stmt|;
name|pcell_t
name|opi_addrc
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|ofw_bus_gen_setup_devinfo
parameter_list|(
name|struct
name|ofw_bus_devinfo
modifier|*
parameter_list|,
name|phandle_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ofw_bus_gen_destroy_devinfo
parameter_list|(
name|struct
name|ofw_bus_devinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Helper method to report interesting OF properties in pnpinfo */
end_comment

begin_function_decl
name|int
name|ofw_bus_gen_child_pnpinfo_str
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Routines for processing firmware interrupt maps */
end_comment

begin_function_decl
name|void
name|ofw_bus_setup_iinfo
parameter_list|(
name|phandle_t
parameter_list|,
name|struct
name|ofw_bus_iinfo
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ofw_bus_lookup_imap
parameter_list|(
name|phandle_t
parameter_list|,
name|struct
name|ofw_bus_iinfo
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ofw_bus_search_intrmap
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ofw_bus_get_compat_t
name|ofw_bus_gen_get_compat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ofw_bus_get_model_t
name|ofw_bus_gen_get_model
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ofw_bus_get_name_t
name|ofw_bus_gen_get_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ofw_bus_get_node_t
name|ofw_bus_gen_get_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ofw_bus_get_type_t
name|ofw_bus_gen_get_type
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DEV_OFW_OFW_BUS_SUBR_H_ */
end_comment

end_unit

