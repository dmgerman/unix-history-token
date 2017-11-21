begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landonf@FreeBSD.org>  * Copyright (c) 2017 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by Landon Fuller  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_BHNDVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_BHNDVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|"bhnd.h"
end_include

begin_comment
comment|/*  * Definitions shared by bhnd(4) bus and bhndb(4) bridge driver implementations.  */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_BHND
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|bhnd_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|bhnd_generic_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_generic_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_generic_shutdown
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_generic_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_generic_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_generic_get_probe_order
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
name|bhnd_generic_alloc_pmu
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
name|bhnd_generic_release_pmu
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
name|bhnd_generic_request_clock
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|bhnd_clock
name|clock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_generic_enable_clocks
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|uint32_t
name|clocks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_generic_request_ext_rsrc
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|u_int
name|rsrc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_generic_release_ext_rsrc
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|u_int
name|rsrc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_generic_print_child
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
name|void
name|bhnd_generic_probe_nomatch
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
name|void
name|bhnd_generic_child_deleted
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
name|bhnd_generic_suspend_child
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
name|bhnd_generic_resume_child
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
name|bhnd_generic_setup_intr
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
name|int
name|bhnd_generic_get_nvram_var
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|,
name|bhnd_nvram_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * bhnd driver instance state. Must be first member of all subclass  * softc structures.  */
end_comment

begin_struct
struct|struct
name|bhnd_softc
block|{
name|device_t
name|dev
decl_stmt|;
comment|/**< bus device */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_BHNDVAR_H_ */
end_comment

end_unit

