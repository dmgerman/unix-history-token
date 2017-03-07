begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Support for the latest PCI standard.  Copyright (c) 2006 - 2014, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                                              **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCI_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCI_H_
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Pci30.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/PciExpress21.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/PciExpress30.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/PciCodeId.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

