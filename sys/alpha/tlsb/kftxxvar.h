begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Instance vars for children of a KFTIA or KFTHA node.  */
end_comment

begin_enum
enum|enum
name|kft_dev_ivars
block|{
name|KFT_IVAR_NAME
block|,
name|KFT_IVAR_NODE
block|,
name|KFT_IVAR_DTYPE
block|,
name|KFT_IVAR_HOSENUM
block|}
enum|;
end_enum

begin_comment
comment|/*  * Simplified accessors for kft devices  */
end_comment

begin_define
define|#
directive|define
name|KFT_ACCESSOR
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|T
parameter_list|)
define|\ 									 \
value|static __inline T kft_get_ ## A(device_t dev)				 \ {									 \ 	u_long v;							 \ 	BUS_READ_IVAR(device_get_parent(dev), dev, KFT_IVAR_ ## B,&v);  \ 	return (T) v;							 \ }
end_define

begin_macro
name|KFT_ACCESSOR
argument_list|(
argument|name
argument_list|,
argument|NAME
argument_list|,
argument|const char*
argument_list|)
end_macro

begin_macro
name|KFT_ACCESSOR
argument_list|(
argument|node
argument_list|,
argument|NODE
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|KFT_ACCESSOR
argument_list|(
argument|dtype
argument_list|,
argument|DTYPE
argument_list|,
argument|u_int16_t
argument_list|)
end_macro

begin_macro
name|KFT_ACCESSOR
argument_list|(
argument|hosenum
argument_list|,
argument|HOSENUM
argument_list|,
argument|u_int16_t
argument_list|)
end_macro

end_unit

