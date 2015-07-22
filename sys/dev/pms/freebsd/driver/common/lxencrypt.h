begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * *******************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************* ** ** Version Control Information: ** **  $Revision: 114125 $ **  $Author: lindfors $ **  $Date: 2012-01-06 17:12:27 -0800 (Fri, 06 Jan 2012) $ **  $Id: lxencrypt.h 112360 2012-01-07 01:12:27Z mcleanda $ ** *******************************************************************************/
end_comment

begin_comment
comment|//#ifndef __LXENCRYPT_H__
end_comment

begin_comment
comment|//#define __LXENCRYPT_H__
end_comment

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/tiapi.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/ostiapi.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/tidefs.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/tiglobal.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/titypes.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/common/tdioctl.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/freebsd/driver/common/osenv.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/freebsd/driver/common/ostypes.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/freebsd/driver/common/osdebug.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|//zone allocation
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|//zone allocation
end_comment

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_comment
comment|//zone allocation
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LXENCRYPT_H__
end_ifndef

begin_define
define|#
directive|define
name|__LXENCRYPT_H__
end_define

begin_define
define|#
directive|define
name|IOERR_QUEUE_DEPTH_MAX
value|1024
end_define

begin_enum
enum|enum
block|{
name|E_SUCCESS
init|=
literal|0
block|,
name|E_DEK_INDEX
block|,
name|E_DEK_TABLE
block|,
name|E_KEK_INDEX
block|,
name|E_CHANNEL_INDEX
block|,
name|E_DEVICE_INDEX
block|,
name|E_LUN_INDEX
block|,
name|E_LBA_RANGE
block|,
name|E_MEMPOOL_ALLOC
block|,
name|E_FLAGS
block|,
name|E_ENCRYPTION_DISABLED
block|,
name|E_BAD_CIPHER_MODE
block|,
name|E_NO_TARGET_MAP
block|,
name|E_NO_LBA_MAP
block|,
name|E_NOT_FOUND
block|, }
name|encrypt_error_e
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|ag_encrypt_ioerr_s
block|{
name|struct
name|list_head
modifier|*
name|list
decl_stmt|;
block|}
name|ag_encrypt_ioerr_t
typedef|;
end_typedef

begin_decl_stmt
name|struct
name|agtiapi_softc
modifier|*
name|pCard
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ENCRYPT_ENHANCE
end_ifdef

begin_function_decl
name|ssize_t
name|set_dek_table_entry0
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|,
name|struct
name|device_attribute
modifier|*
name|attr
parameter_list|,
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|show_dek_table_entry0
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|,
name|struct
name|device_attribute
modifier|*
name|attr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|set_dek_table_entry1
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|,
name|struct
name|device_attribute
modifier|*
name|attr
parameter_list|,
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|show_dek_table_entry1
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|,
name|struct
name|device_attribute
modifier|*
name|attr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|show_kek_table
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|,
name|struct
name|device_attribute
modifier|*
name|attr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|show_dek_kek_map0
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|,
name|struct
name|device_attribute
modifier|*
name|attr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|show_dek_kek_map1
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|,
name|struct
name|device_attribute
modifier|*
name|attr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|show_target_dek_map
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|,
name|struct
name|device_attribute
modifier|*
name|attr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|agtiapi_SetupEncryption
parameter_list|(
name|struct
name|agtiapi_softc
modifier|*
name|pCard
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|agtiapi_SetupEncryptionPools
parameter_list|(
name|struct
name|agtiapi_softc
modifier|*
name|pCard
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|agtiapi_CleanupEncryption
parameter_list|(
name|struct
name|agtiapi_softc
modifier|*
name|pCard
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|agtiapi_CleanupEncryptionPools
parameter_list|(
name|struct
name|agtiapi_softc
modifier|*
name|pCard
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|agtiapi_SetupEncryptedIO
parameter_list|(
name|struct
name|agtiapi_softc
modifier|*
name|pCard
parameter_list|,
name|ccb_t
modifier|*
name|pccb
parameter_list|,
name|unsigned
name|long
name|long
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|agtiapi_CleanupEncryptedIO
parameter_list|(
name|struct
name|agtiapi_softc
modifier|*
name|pCard
parameter_list|,
name|ccb_t
modifier|*
name|pccb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|agtiapi_HandleEncryptedIOFailure
parameter_list|(
name|ag_device_t
modifier|*
name|pDev
parameter_list|,
name|ccb_t
modifier|*
name|pccb
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

