begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Monthadar Al Jaberi, TerraNet AB  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VISIBILITY_H_
end_ifndef

begin_define
define|#
directive|define
name|_VISIBILITY_H_
end_define

begin_include
include|#
directive|include
file|"wtap_plugin.h"
end_include

begin_include
include|#
directive|include
file|"visibility_ioctl.h"
end_include

begin_define
define|#
directive|define
name|CDEV_GET_SOFTC
parameter_list|(
name|x
parameter_list|)
value|(x)->si_drv1
end_define

begin_define
define|#
directive|define
name|ARRAY_SIZE
value|(32)
end_define

begin_comment
comment|//We support a maximum of 1024 nodes for now
end_comment

begin_struct
struct|struct
name|vis_map
block|{
name|uint32_t
name|map
index|[
name|ARRAY_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|visibility_plugin
block|{
name|struct
name|wtap_plugin
name|base
decl_stmt|;
name|struct
name|mtx
name|pl_mtx
decl_stmt|;
name|struct
name|vis_map
name|pl_node
index|[
name|MAX_NBR_WTAP
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|visibility_init
parameter_list|(
name|struct
name|wtap_plugin
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|visibility_deinit
parameter_list|(
name|struct
name|wtap_plugin
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|visibility_work
parameter_list|(
name|struct
name|wtap_plugin
modifier|*
parameter_list|,
name|struct
name|packet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

