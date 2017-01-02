begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- xray_defs.h ---------------------------------------------*- C++ -*-===//
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
comment|// Common definitions useful for XRay sources.
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
name|XRAY_XRAY_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|XRAY_XRAY_DEFS_H
end_define

begin_if
if|#
directive|if
name|XRAY_SUPPORTED
end_if

begin_define
define|#
directive|define
name|XRAY_NEVER_INSTRUMENT
value|__attribute__((xray_never_instrument))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XRAY_NEVER_INSTRUMENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// XRAY_XRAY_DEFS_H
end_comment

end_unit

