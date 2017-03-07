begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file    Root include file for Mde Package SEC, PEIM, PEI_CORE type modules.    This is the include file for any module of type PEIM. PEIM   modules only use types defined via this include file and can   be ported easily to any environment.   Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PI_PEI_H__
end_ifndef

begin_define
define|#
directive|define
name|__PI_PEI_H__
end_define

begin_include
include|#
directive|include
file|<Uefi/UefiBaseType.h>
end_include

begin_include
include|#
directive|include
file|<Pi/PiPeiCis.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

