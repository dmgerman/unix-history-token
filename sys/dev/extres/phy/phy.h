begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2016 Michal Meloun<mmel@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_EXTRES_PHY_H
end_ifndef

begin_define
define|#
directive|define
name|DEV_EXTRES_PHY_H
end_define

begin_include
include|#
directive|include
file|"opt_platform.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
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

begin_typedef
typedef|typedef
name|struct
name|phy
modifier|*
name|phy_t
typedef|;
end_typedef

begin_comment
comment|/*  * Provider interface  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_function_decl
name|void
name|phy_register_provider
parameter_list|(
name|device_t
name|provider
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|phy_unregister_provider
parameter_list|(
name|device_t
name|provider
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Consumer interface  */
end_comment

begin_function_decl
name|int
name|phy_get_by_id
parameter_list|(
name|device_t
name|consumer_dev
parameter_list|,
name|device_t
name|provider_dev
parameter_list|,
name|intptr_t
name|id
parameter_list|,
name|phy_t
modifier|*
name|phy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|phy_release
parameter_list|(
name|phy_t
name|phy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|phy_get_by_ofw_name
parameter_list|(
name|device_t
name|consumer
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|phy_t
modifier|*
name|phy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|phy_get_by_ofw_idx
parameter_list|(
name|device_t
name|consumer
parameter_list|,
name|int
name|idx
parameter_list|,
name|phy_t
modifier|*
name|phy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|phy_get_by_ofw_property
parameter_list|(
name|device_t
name|consumer
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|phy_t
modifier|*
name|phy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|phy_init
parameter_list|(
name|device_t
name|consumer
parameter_list|,
name|phy_t
name|phy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|phy_deinit
parameter_list|(
name|device_t
name|consumer
parameter_list|,
name|phy_t
name|phy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|phy_enable
parameter_list|(
name|device_t
name|consumer
parameter_list|,
name|phy_t
name|phy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|phy_disable
parameter_list|(
name|device_t
name|consumer
parameter_list|,
name|phy_t
name|phy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|phy_status
parameter_list|(
name|device_t
name|consumer
parameter_list|,
name|phy_t
name|phy
parameter_list|,
name|int
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_EXTRES_PHY_H */
end_comment

end_unit

