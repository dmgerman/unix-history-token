begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RNBServices.h -------------------------------------------*- C++ -*-===//
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
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Created by Christopher Friesen on 3/21/08.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RNBServices_h__
end_ifndef

begin_define
define|#
directive|define
name|__RNBServices_h__
end_define

begin_include
include|#
directive|include
file|"RNBDefs.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_define
define|#
directive|define
name|DTSERVICES_APP_FRONTMOST_KEY
value|CFSTR("isFrontApp")
end_define

begin_define
define|#
directive|define
name|DTSERVICES_APP_PATH_KEY
value|CFSTR("executablePath")
end_define

begin_define
define|#
directive|define
name|DTSERVICES_APP_ICON_PATH_KEY
value|CFSTR("iconPath")
end_define

begin_define
define|#
directive|define
name|DTSERVICES_APP_DISPLAY_NAME_KEY
value|CFSTR("displayName")
end_define

begin_define
define|#
directive|define
name|DTSERVICES_APP_PID_KEY
value|CFSTR("pid")
end_define

begin_decl_stmt
name|int
name|ListApplications
argument_list|(
name|std
operator|::
name|string
operator|&
name|plist
argument_list|,
name|bool
name|opt_runningApps
argument_list|,
name|bool
name|opt_debuggable
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __RNBServices_h__
end_comment

end_unit

