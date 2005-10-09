begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_comment
comment|/*  * This is defined by the version 1 interface.  */
end_comment

begin_define
define|#
directive|define
name|DEVINFO_STRLEN
value|32
end_define

begin_comment
comment|/*  * Devices.    *  * Internal structure contains string buffers and list linkage;  */
end_comment

begin_struct
struct|struct
name|devinfo_i_dev
block|{
name|struct
name|devinfo_dev
name|dd_dev
decl_stmt|;
name|char
name|dd_name
index|[
name|DEVINFO_STRLEN
index|]
decl_stmt|;
name|char
name|dd_desc
index|[
name|DEVINFO_STRLEN
index|]
decl_stmt|;
name|char
name|dd_drivername
index|[
name|DEVINFO_STRLEN
index|]
decl_stmt|;
name|char
name|dd_pnpinfo
index|[
name|DEVINFO_STRLEN
operator|*
literal|4
index|]
decl_stmt|;
name|char
name|dd_location
index|[
name|DEVINFO_STRLEN
operator|*
literal|4
index|]
decl_stmt|;
name|uint32_t
name|dd_devflags
decl_stmt|;
name|uint16_t
name|dd_flags
decl_stmt|;
name|device_state_t
name|dd_state
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|devinfo_i_dev
argument_list|)
name|dd_link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Resources.  *  * Internal structures contain string buffers and list linkage;  */
end_comment

begin_struct
struct|struct
name|devinfo_i_rman
block|{
name|struct
name|devinfo_rman
name|dm_rman
decl_stmt|;
name|char
name|dm_desc
index|[
literal|32
index|]
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|devinfo_i_rman
argument_list|)
name|dm_link
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|devinfo_i_res
block|{
name|struct
name|devinfo_res
name|dr_res
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|devinfo_i_res
argument_list|)
name|dr_link
expr_stmt|;
block|}
struct|;
end_struct

end_unit

