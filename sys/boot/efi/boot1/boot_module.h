begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Eric McCorkle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BOOT_MODULE_H_
end_ifndef

begin_define
define|#
directive|define
name|_BOOT_MODULE_H_
end_define

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<efi.h>
end_include

begin_include
include|#
directive|include
file|<efilib.h>
end_include

begin_include
include|#
directive|include
file|<eficonsctl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|EFI_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printf(fmt, ##args)
end_define

begin_define
define|#
directive|define
name|DSTALL
parameter_list|(
name|d
parameter_list|)
value|bs->Stall(d)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|{}
end_define

begin_define
define|#
directive|define
name|DSTALL
parameter_list|(
name|d
parameter_list|)
value|{}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFI device info */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dev_info
block|{
name|EFI_BLOCK_IO
modifier|*
name|dev
decl_stmt|;
name|EFI_DEVICE_PATH
modifier|*
name|devpath
decl_stmt|;
name|EFI_HANDLE
modifier|*
name|devhandle
decl_stmt|;
name|void
modifier|*
name|devdata
decl_stmt|;
name|BOOLEAN
name|preferred
decl_stmt|;
name|struct
name|dev_info
modifier|*
name|next
decl_stmt|;
block|}
name|dev_info_t
typedef|;
end_typedef

begin_comment
comment|/*  * A boot loader module.  *  * This is a standard interface for filesystem modules in the EFI system.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|boot_module_t
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* init is the optional initialiser for the module. */
name|void
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* 	 * probe checks to see if the module can handle dev. 	 * 	 * Return codes: 	 * EFI_SUCCESS = The module can handle the device. 	 * EFI_NOT_FOUND = The module can not handle the device. 	 * Other = The module encountered an error. 	 */
name|EFI_STATUS
function_decl|(
modifier|*
name|probe
function_decl|)
parameter_list|(
name|dev_info_t
modifier|*
name|dev
parameter_list|)
function_decl|;
comment|/* 	 * load should select the best out of a set of devices that probe 	 * indicated were loadable and load the specified file. 	 * 	 * Return codes: 	 * EFI_SUCCESS = The module can handle the device. 	 * EFI_NOT_FOUND = The module can not handle the device. 	 * Other = The module encountered an error. 	 */
name|EFI_STATUS
function_decl|(
modifier|*
name|load
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|filepath
parameter_list|,
name|dev_info_t
modifier|*
name|devinfo
parameter_list|,
name|void
modifier|*
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|*
name|bufsize
parameter_list|)
function_decl|;
comment|/* status outputs information about the probed devices. */
name|void
function_decl|(
modifier|*
name|status
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* valid devices as found by probe. */
name|dev_info_t
modifier|*
function_decl|(
modifier|*
name|devices
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
name|boot_module_t
typedef|;
end_typedef

begin_comment
comment|/* Standard boot modules. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EFI_UFS_BOOT
end_ifdef

begin_decl_stmt
specifier|extern
specifier|const
name|boot_module_t
name|ufs_module
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EFI_ZFS_BOOT
end_ifdef

begin_decl_stmt
specifier|extern
specifier|const
name|boot_module_t
name|zfs_module
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Functions available to modules. */
end_comment

begin_function_decl
specifier|extern
name|void
name|add_device
parameter_list|(
name|dev_info_t
modifier|*
modifier|*
name|devinfop
parameter_list|,
name|dev_info_t
modifier|*
name|devinfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vsnprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|sz
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|EFI_SYSTEM_TABLE
modifier|*
name|systab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_BOOT_SERVICES
modifier|*
name|bs
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|devpath_strlcat
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|,
name|EFI_DEVICE_PATH
modifier|*
name|devpath
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|devpath_str
parameter_list|(
name|EFI_DEVICE_PATH
modifier|*
name|devpath
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

