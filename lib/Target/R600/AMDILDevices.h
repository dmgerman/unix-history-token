begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDILDevices.h - Consolidate AMDIL Device headers -----------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|//==-----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMDIL_DEVICES_H
end_ifndef

begin_define
define|#
directive|define
name|AMDIL_DEVICES_H
end_define

begin_comment
comment|// Include all of the device specific header files
end_comment

begin_include
include|#
directive|include
file|"AMDIL7XXDevice.h"
end_include

begin_include
include|#
directive|include
file|"AMDILDevice.h"
end_include

begin_include
include|#
directive|include
file|"AMDILEvergreenDevice.h"
end_include

begin_include
include|#
directive|include
file|"AMDILNIDevice.h"
end_include

begin_include
include|#
directive|include
file|"AMDILSIDevice.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// AMDIL_DEVICES_H
end_comment

end_unit

