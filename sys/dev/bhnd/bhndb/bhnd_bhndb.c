begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhnd_ids.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhnd.h>
end_include

begin_include
include|#
directive|include
file|"bhndbvar.h"
end_include

begin_comment
comment|/*  * bhnd(4) driver mix-in providing a shared common methods for  * bhnd devices attached via a bhndb bridge.  */
end_comment

begin_function
specifier|static
name|int
name|bhnd_bhndb_read_board_info
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|struct
name|bhnd_board_info
modifier|*
name|info
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
comment|/* Initialize with NVRAM-derived values */
if|if
condition|(
operator|(
name|error
operator|=
name|bhnd_bus_generic_read_board_info
argument_list|(
name|dev
argument_list|,
name|child
argument_list|,
name|info
argument_list|)
operator|)
condition|)
return|return
operator|(
name|error
operator|)
return|;
comment|/* Let the bridge fill in any additional data */
return|return
operator|(
name|BHNDB_POPULATE_BOARD_INFO
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|info
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|bhnd_attach_type
name|bhnd_bhndb_get_attach_type
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
block|{
comment|/* It's safe to assume that a bridged device is always an adapter */
return|return
operator|(
name|BHND_ATTACH_ADAPTER
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|bhnd_bhndb_methods
index|[]
init|=
block|{
comment|/* BHND interface */
name|DEVMETHOD
argument_list|(
name|bhnd_bus_get_attach_type
argument_list|,
name|bhnd_bhndb_get_attach_type
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bhnd_bus_read_board_info
argument_list|,
name|bhnd_bhndb_read_board_info
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DEFINE_CLASS_0
argument_list|(
name|bhnd
argument_list|,
name|bhnd_bhndb_driver
argument_list|,
name|bhnd_bhndb_methods
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

