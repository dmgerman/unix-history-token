begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 by Matthew Jacob  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Definitions for the MCBUS System Bus found on  * AlphaServer 4100 systems.  */
end_comment

begin_enum
enum|enum
name|mcbus_device_instvars
block|{
name|MCBUS_IVAR_MID
block|,
name|MCBUS_IVAR_GID
block|,
name|MCBUS_IVAR_TYPE
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|MCBUS_ACCESSOR
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|T
parameter_list|)
define|\ 									 \
value|static __inline T mcbus_get_ ## A(device_t dev)				 \ {									 \ 	u_long v;							 \ 	BUS_READ_IVAR(device_get_parent(dev), dev, MCBUS_IVAR_ ## B,&v); \ 	return v;							 \ }
end_define

begin_macro
name|MCBUS_ACCESSOR
argument_list|(
argument|mid
argument_list|,
argument|MID
argument_list|,
argument|u_int8_t
argument_list|)
end_macro

begin_macro
name|MCBUS_ACCESSOR
argument_list|(
argument|gid
argument_list|,
argument|GID
argument_list|,
argument|u_int8_t
argument_list|)
end_macro

begin_macro
name|MCBUS_ACCESSOR
argument_list|(
argument|type
argument_list|,
argument|TYPE
argument_list|,
argument|u_int8_t
argument_list|)
end_macro

begin_comment
comment|/*  * The structure used to attach devices to the MCBUS  */
end_comment

begin_struct
struct|struct
name|mcbus_device
block|{
name|u_int8_t
name|ma_gid
decl_stmt|;
comment|/* GID of MCBUS (MCBUS #) */
name|u_int8_t
name|ma_mid
decl_stmt|;
comment|/* Module ID on MCBUS */
name|u_int8_t
name|ma_type
decl_stmt|;
comment|/* Module "type" */
name|u_int8_t
name|ma_order
decl_stmt|;
comment|/* order of attachment */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MCBUS_GID_FROM_INSTANCE
parameter_list|(
name|unit
parameter_list|)
value|(7 - unit)
end_define

begin_comment
comment|/*  * "types"  */
end_comment

begin_define
define|#
directive|define
name|MCBUS_TYPE_RES
value|0
end_define

begin_define
define|#
directive|define
name|MCBUS_TYPE_UNK
value|1
end_define

begin_define
define|#
directive|define
name|MCBUS_TYPE_MEM
value|2
end_define

begin_define
define|#
directive|define
name|MCBUS_TYPE_CPU
value|3
end_define

begin_define
define|#
directive|define
name|MCBUS_TYPE_PCI
value|4
end_define

begin_define
define|#
directive|define
name|DEVTOMCBUS
parameter_list|(
name|dev
parameter_list|)
value|((struct mcbus_device *) device_get_ivars(dev))
end_define

end_unit

