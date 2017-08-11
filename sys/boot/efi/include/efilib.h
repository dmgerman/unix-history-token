begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Doug Rabson  * Copyright (c) 2006 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOADER_EFILIB_H
end_ifndef

begin_define
define|#
directive|define
name|_LOADER_EFILIB_H
end_define

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_decl_stmt
specifier|extern
name|EFI_HANDLE
name|IH
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_SYSTEM_TABLE
modifier|*
name|ST
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_BOOT_SERVICES
modifier|*
name|BS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_RUNTIME_SERVICES
modifier|*
name|RS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|devsw
name|efipart_fddev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|devsw
name|efipart_cddev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|devsw
name|efipart_hddev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|devsw
name|efinet_dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|netif_driver
name|efinetif
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EFI block device data, included here to help efi_zfs_probe() */
end_comment

begin_typedef
typedef|typedef
name|STAILQ_HEAD
argument_list|(
argument|pdinfo_list
argument_list|,
argument|pdinfo
argument_list|)
name|pdinfo_list_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pdinfo
block|{
name|STAILQ_ENTRY
argument_list|(
argument|pdinfo
argument_list|)
name|pd_link
expr_stmt|;
comment|/* link in device list */
name|pdinfo_list_t
name|pd_part
decl_stmt|;
comment|/* link of partitions */
name|EFI_HANDLE
name|pd_handle
decl_stmt|;
name|EFI_HANDLE
name|pd_alias
decl_stmt|;
name|EFI_DEVICE_PATH
modifier|*
name|pd_devpath
decl_stmt|;
name|EFI_BLOCK_IO
modifier|*
name|pd_blkio
decl_stmt|;
name|int
name|pd_unit
decl_stmt|;
comment|/* unit number */
name|int
name|pd_open
decl_stmt|;
comment|/* reference counter */
name|void
modifier|*
name|pd_bcache
decl_stmt|;
comment|/* buffer cache data */
block|}
name|pdinfo_t
typedef|;
end_typedef

begin_function_decl
name|pdinfo_list_t
modifier|*
name|efiblk_get_pdinfo_list
parameter_list|(
name|struct
name|devsw
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|efi_get_table
parameter_list|(
name|EFI_GUID
modifier|*
name|tbl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_getdev
parameter_list|(
name|void
modifier|*
modifier|*
name|vdev
parameter_list|,
specifier|const
name|char
modifier|*
name|devspec
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|efi_fmtdev
parameter_list|(
name|void
modifier|*
name|vdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_setcurrdev
parameter_list|(
name|struct
name|env_var
modifier|*
name|ev
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_register_handles
parameter_list|(
name|struct
name|devsw
modifier|*
parameter_list|,
name|EFI_HANDLE
modifier|*
parameter_list|,
name|EFI_HANDLE
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EFI_HANDLE
name|efi_find_handle
parameter_list|(
name|struct
name|devsw
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_handle_lookup
parameter_list|(
name|EFI_HANDLE
parameter_list|,
name|struct
name|devsw
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_handle_update_dev
parameter_list|(
name|EFI_HANDLE
parameter_list|,
name|struct
name|devsw
modifier|*
parameter_list|,
name|int
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EFI_DEVICE_PATH
modifier|*
name|efi_lookup_image_devpath
parameter_list|(
name|EFI_HANDLE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EFI_DEVICE_PATH
modifier|*
name|efi_lookup_devpath
parameter_list|(
name|EFI_HANDLE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EFI_HANDLE
name|efi_devpath_handle
parameter_list|(
name|EFI_DEVICE_PATH
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EFI_DEVICE_PATH
modifier|*
name|efi_devpath_last_node
parameter_list|(
name|EFI_DEVICE_PATH
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EFI_DEVICE_PATH
modifier|*
name|efi_devpath_trim
parameter_list|(
name|EFI_DEVICE_PATH
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_devpath_match
parameter_list|(
name|EFI_DEVICE_PATH
modifier|*
parameter_list|,
name|EFI_DEVICE_PATH
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CHAR16
modifier|*
name|efi_devpath_name
parameter_list|(
name|EFI_DEVICE_PATH
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|efi_free_devpath_name
parameter_list|(
name|CHAR16
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_status_to_errno
parameter_list|(
name|EFI_STATUS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EFI_STATUS
name|errno_to_efi_status
parameter_list|(
name|int
name|errno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|efi_time_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|efi_time_fini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EFI_STATUS
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|CHAR16
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|exit
parameter_list|(
name|EFI_STATUS
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delay
parameter_list|(
name|int
name|usecs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* EFI environment initialization. */
end_comment

begin_function_decl
name|void
name|efi_init_environment
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* CHAR16 utility functions. */
end_comment

begin_function_decl
name|int
name|wcscmp
parameter_list|(
name|CHAR16
modifier|*
parameter_list|,
name|CHAR16
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpy8to16
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|CHAR16
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpy16to8
parameter_list|(
specifier|const
name|CHAR16
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LOADER_EFILIB_H */
end_comment

end_unit

