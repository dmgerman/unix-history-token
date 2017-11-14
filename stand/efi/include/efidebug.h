begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|_EFI_DEBUG_H
end_define

begin_comment
comment|/*++  Copyright (c)  1999 - 2002 Intel Corporation. All rights reserved This software and associated documentation (if any) is furnished under a license and may only be used or copied in accordance with the terms of the license. Except as permitted by such license, no part of this software or documentation may be reproduced, stored in a retrieval system, or transmitted in any form or by any means without the express written consent of Intel Corporation.  Module Name:      efidebug.h  Abstract:      EFI library debug functions    Revision History  --*/
end_comment

begin_decl_stmt
specifier|extern
name|UINTN
name|EFIDebug
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|EFI_DEBUG
end_if

begin_define
define|#
directive|define
name|DBGASSERT
parameter_list|(
name|a
parameter_list|)
value|DbgAssert(__FILE__, __LINE__, #a)
end_define

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|a
parameter_list|)
value|DbgPrint a
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBGASSERT
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|EFI_DEBUG_CLEAR_MEMORY
end_if

begin_define
define|#
directive|define
name|DBGSETMEM
parameter_list|(
name|a
parameter_list|,
name|l
parameter_list|)
value|SetMem(a,l,(CHAR8)BAD_POINTER)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBGSETMEM
parameter_list|(
name|a
parameter_list|,
name|l
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|D_INIT
value|0x00000001
end_define

begin_comment
comment|// Initialization style messages
end_comment

begin_define
define|#
directive|define
name|D_WARN
value|0x00000002
end_define

begin_comment
comment|// Warnings
end_comment

begin_define
define|#
directive|define
name|D_LOAD
value|0x00000004
end_define

begin_comment
comment|// Load events
end_comment

begin_define
define|#
directive|define
name|D_FS
value|0x00000008
end_define

begin_comment
comment|// EFI File system
end_comment

begin_define
define|#
directive|define
name|D_POOL
value|0x00000010
end_define

begin_comment
comment|// Alloc& Free's
end_comment

begin_define
define|#
directive|define
name|D_PAGE
value|0x00000020
end_define

begin_comment
comment|// Alloc& Free's
end_comment

begin_define
define|#
directive|define
name|D_INFO
value|0x00000040
end_define

begin_comment
comment|// Verbose
end_comment

begin_define
define|#
directive|define
name|D_VARIABLE
value|0x00000100
end_define

begin_comment
comment|// Variable
end_comment

begin_define
define|#
directive|define
name|D_VAR
value|0x00000100
end_define

begin_comment
comment|// Variable
end_comment

begin_define
define|#
directive|define
name|D_BM
value|0x00000400
end_define

begin_comment
comment|// Boot Manager
end_comment

begin_define
define|#
directive|define
name|D_BLKIO
value|0x00001000
end_define

begin_comment
comment|// BlkIo Driver
end_comment

begin_define
define|#
directive|define
name|D_BLKIO_ULTRA
value|0x00002000
end_define

begin_comment
comment|// BlkIo Driver
end_comment

begin_define
define|#
directive|define
name|D_NET
value|0x00004000
end_define

begin_comment
comment|// SNI Driver
end_comment

begin_define
define|#
directive|define
name|D_NET_ULTRA
value|0x00008000
end_define

begin_comment
comment|// SNI Driver
end_comment

begin_define
define|#
directive|define
name|D_UNDI
value|0x00010000
end_define

begin_comment
comment|// UNDI Driver
end_comment

begin_define
define|#
directive|define
name|D_LOADFILE
value|0x00020000
end_define

begin_comment
comment|// UNDI Driver
end_comment

begin_define
define|#
directive|define
name|D_EVENT
value|0x00080000
end_define

begin_comment
comment|// Event messages
end_comment

begin_define
define|#
directive|define
name|D_ERROR
value|0x80000000
end_define

begin_comment
comment|// Error
end_comment

begin_define
define|#
directive|define
name|D_RESERVED
value|0x7ff40A80
end_define

begin_comment
comment|// Bits not reserved above
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Current Debug level of the system, value of EFIDebug
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//#define EFI_DBUG_MASK   (D_ERROR | D_WARN | D_LOAD | D_BLKIO | D_INIT)
end_comment

begin_define
define|#
directive|define
name|EFI_DBUG_MASK
value|(D_ERROR)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_if
if|#
directive|if
name|EFI_DEBUG
end_if

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|a
parameter_list|)
value|if(!(a))       DBGASSERT(a)
end_define

begin_define
define|#
directive|define
name|ASSERT_LOCKED
parameter_list|(
name|l
parameter_list|)
value|if(!(l)->Lock) DBGASSERT(l not locked)
end_define

begin_define
define|#
directive|define
name|ASSERT_STRUCT
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
value|DBGASSERT(t not structure), p
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASSERT_LOCKED
parameter_list|(
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASSERT_STRUCT
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//
end_comment

begin_comment
comment|// Prototypes
end_comment

begin_comment
comment|//
end_comment

begin_function_decl
name|INTN
name|DbgAssert
parameter_list|(
name|CHAR8
modifier|*
name|file
parameter_list|,
name|INTN
name|lineno
parameter_list|,
name|CHAR8
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|INTN
name|DbgPrint
parameter_list|(
name|INTN
name|mask
parameter_list|,
name|CHAR8
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

