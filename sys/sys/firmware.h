begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005, Sam Leffler<sam@errno.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_FIRMWARE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FIRMWARE_H_
end_define

begin_comment
comment|/*  * Loadable firmware support.  *  * The firmware abstraction provides an interface for loading firmware  * images into the kernel and making them available to clients.  *  * Firmware images are usually embedded in kernel loadable modules that can  * be loaded on-demand or pre-loaded as desired.  Modules may contain  * one or more firmware images that are stored as opaque data arrays  * and registered with a unique string name. Clients request  * firmware by name, and are returned a struct firmware * below on success.  * The kernel keeps track of references to firmware images to allow/prevent  * module/data unload.  *  * When multiple images are stored in one module, the first image is  * treated as the master with the other images holding references  * to it.  This means that to unload the module each dependent/subimage  * must first have its references removed.  * In order for automatic loading to work, the master image must have  * the same name as the module it is embedded into.  */
end_comment

begin_struct
struct|struct
name|firmware
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* system-wide name */
specifier|const
name|void
modifier|*
name|data
decl_stmt|;
comment|/* location of image */
name|size_t
name|datasize
decl_stmt|;
comment|/* size of image in bytes */
name|unsigned
name|int
name|version
decl_stmt|;
comment|/* version of the image */
block|}
struct|;
end_struct

begin_function_decl
specifier|const
name|struct
name|firmware
modifier|*
name|firmware_register
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|unsigned
name|int
parameter_list|,
specifier|const
name|struct
name|firmware
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|firmware_unregister
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|firmware
modifier|*
name|firmware_get
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FIRMWARE_UNLOAD
value|0x0001
end_define

begin_comment
comment|/* unload if unreferenced */
end_comment

begin_function_decl
name|void
name|firmware_put
parameter_list|(
specifier|const
name|struct
name|firmware
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_FIRMWARE_H_ */
end_comment

end_unit

