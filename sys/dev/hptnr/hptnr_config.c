begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 HighPoint Technologies, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<dev/hptnr/hptnr_config.h>
end_include

begin_comment
comment|/****************************************************************************  * config.c - auto-generated file  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<dev/hptnr/os_bsd.h>
end_include

begin_function_decl
specifier|extern
name|int
name|init_module_him_r750
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|init_module_him_dc7280
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|init_module_vdev_raw
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|init_config
parameter_list|(
name|void
parameter_list|)
block|{
name|init_module_him_r750
argument_list|()
expr_stmt|;
name|init_module_him_dc7280
argument_list|()
expr_stmt|;
name|init_module_vdev_raw
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|const
name|char
name|driver_name
index|[]
init|=
literal|"hptnr"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
name|driver_name_long
index|[]
init|=
literal|"R750/DC7280 controller driver"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
name|driver_ver
index|[]
init|=
literal|"v1.0.1"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|osm_max_targets
init|=
literal|0xff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|os_max_cache_size
init|=
literal|0x1000000
decl_stmt|;
end_decl_stmt

end_unit

