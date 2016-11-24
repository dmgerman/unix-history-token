begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- scudo_flags.h -------------------------------------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// Header for scudo_flags.cpp.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCUDO_FLAGS_H_
end_ifndef

begin_define
define|#
directive|define
name|SCUDO_FLAGS_H_
end_define

begin_decl_stmt
name|namespace
name|__scudo
block|{
struct|struct
name|Flags
block|{
define|#
directive|define
name|SCUDO_FLAG
parameter_list|(
name|Type
parameter_list|,
name|Name
parameter_list|,
name|DefaultValue
parameter_list|,
name|Description
parameter_list|)
value|Type Name;
include|#
directive|include
file|"scudo_flags.inc"
undef|#
directive|undef
name|SCUDO_FLAG
name|void
name|setDefaults
parameter_list|()
function_decl|;
block|}
struct|;
name|Flags
modifier|*
name|getFlags
parameter_list|()
function_decl|;
name|void
name|initFlags
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __scudo
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SCUDO_FLAGS_H_
end_comment

end_unit

