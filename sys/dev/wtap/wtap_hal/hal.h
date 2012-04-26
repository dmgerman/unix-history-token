begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2011 Monthadar Al Jaberi, TerraNet AB  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WTAP_HAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_WTAP_HAL_H_
end_define

begin_include
include|#
directive|include
file|"../if_wtapvar.h"
end_include

begin_include
include|#
directive|include
file|"../plugins/wtap_plugin.h"
end_include

begin_include
include|#
directive|include
file|"handler.h"
end_include

begin_struct
struct|struct
name|wtap_hal
block|{
name|struct
name|wtap_medium
modifier|*
name|hal_md
decl_stmt|;
name|struct
name|mtx
name|hal_mtx
decl_stmt|;
name|struct
name|wtap_plugin
modifier|*
name|plugin
decl_stmt|;
name|struct
name|wtap_softc
modifier|*
name|hal_devs
index|[
name|MAX_NBR_WTAP
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|init_hal
parameter_list|(
name|struct
name|wtap_hal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|deinit_hal
parameter_list|(
name|struct
name|wtap_hal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|register_plugin
parameter_list|(
name|struct
name|wtap_hal
modifier|*
parameter_list|,
name|struct
name|wtap_plugin
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|deregister_plugin
parameter_list|(
name|struct
name|wtap_hal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|new_wtap
parameter_list|(
name|struct
name|wtap_hal
modifier|*
parameter_list|,
name|int32_t
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|free_wtap
parameter_list|(
name|struct
name|wtap_hal
modifier|*
parameter_list|,
name|int32_t
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

