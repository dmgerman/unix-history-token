begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Netflix, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_EFIIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_EFIIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/uuid.h>
end_include

begin_include
include|#
directive|include
file|<sys/efi.h>
end_include

begin_struct
struct|struct
name|efi_get_table_ioc
block|{
name|struct
name|uuid
name|uuid
decl_stmt|;
comment|/* UUID to look up */
name|void
modifier|*
name|ptr
decl_stmt|;
comment|/* Pointer to table in KVA space */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|efi_var_ioc
block|{
name|efi_char
modifier|*
name|name
decl_stmt|;
comment|/* User pointer to name, in wide chars */
name|size_t
name|namesize
decl_stmt|;
comment|/* Number of wide characters in name */
name|struct
name|uuid
name|vendor
decl_stmt|;
comment|/* Vendor's UUID for variable */
name|uint32_t
name|attrib
decl_stmt|;
comment|/* Attributes */
name|void
modifier|*
name|data
decl_stmt|;
comment|/* User pointer to the data */
name|size_t
name|datasize
decl_stmt|;
comment|/* Number of *bytes* in the data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EFIIOC_GET_TABLE
value|_IOWR('E',  1, struct efi_get_table_ioc)
end_define

begin_define
define|#
directive|define
name|EFIIOC_GET_TIME
value|_IOR('E',   2, struct efi_tm)
end_define

begin_define
define|#
directive|define
name|EFIIOC_SET_TIME
value|_IOW('E',   3, struct efi_tm)
end_define

begin_define
define|#
directive|define
name|EFIIOC_VAR_GET
value|_IOWR('E',  4, struct efi_var_ioc)
end_define

begin_define
define|#
directive|define
name|EFIIOC_VAR_NEXT
value|_IOWR('E',  5, struct efi_var_ioc)
end_define

begin_define
define|#
directive|define
name|EFIIOC_VAR_SET
value|_IOWR('E',  6, struct efi_var_ioc)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_EFIIO_H_ */
end_comment

end_unit

