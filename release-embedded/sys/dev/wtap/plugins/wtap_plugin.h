begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Monthadar Al Jaberi, TerraNet AB  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WTAP_PLUGIN_H_
end_ifndef

begin_define
define|#
directive|define
name|_WTAP_PLUGIN_H_
end_define

begin_include
include|#
directive|include
file|"../if_wtapvar.h"
end_include

begin_include
include|#
directive|include
file|"../if_medium.h"
end_include

begin_include
include|#
directive|include
file|"../wtap_hal/hal.h"
end_include

begin_struct
struct|struct
name|wtap_plugin
block|{
name|struct
name|cdev
modifier|*
name|wp_sdev
decl_stmt|;
name|struct
name|wtap_hal
modifier|*
name|wp_hal
decl_stmt|;
name|void
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|wtap_plugin
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|deinit
function_decl|)
parameter_list|(
name|struct
name|wtap_plugin
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|work
function_decl|)
parameter_list|(
name|struct
name|wtap_plugin
modifier|*
parameter_list|,
name|struct
name|packet
modifier|*
name|p
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

