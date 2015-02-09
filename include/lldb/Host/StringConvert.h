begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StringConvert.h -----------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_StringConvert_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_StringConvert_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|StringConvert
block|{
comment|//----------------------------------------------------------------------
comment|/// @namespace StringConvert StringConvert.h "lldb/Host/StringConvert.h"
comment|/// @brief Utility classes for converting strings into Integers
comment|//----------------------------------------------------------------------
name|int32_t
name|ToSInt32
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int32_t
name|fail_value
init|=
literal|0
parameter_list|,
name|int
name|base
init|=
literal|0
parameter_list|,
name|bool
modifier|*
name|success_ptr
init|=
name|nullptr
parameter_list|)
function_decl|;
name|uint32_t
name|ToUInt32
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|uint32_t
name|fail_value
init|=
literal|0
parameter_list|,
name|int
name|base
init|=
literal|0
parameter_list|,
name|bool
modifier|*
name|success_ptr
init|=
name|nullptr
parameter_list|)
function_decl|;
name|int64_t
name|ToSInt64
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int64_t
name|fail_value
init|=
literal|0
parameter_list|,
name|int
name|base
init|=
literal|0
parameter_list|,
name|bool
modifier|*
name|success_ptr
init|=
name|nullptr
parameter_list|)
function_decl|;
name|uint64_t
name|ToUInt64
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|uint64_t
name|fail_value
init|=
literal|0
parameter_list|,
name|int
name|base
init|=
literal|0
parameter_list|,
name|bool
modifier|*
name|success_ptr
init|=
name|nullptr
parameter_list|)
function_decl|;
block|}
comment|// namespace StringConvert
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

