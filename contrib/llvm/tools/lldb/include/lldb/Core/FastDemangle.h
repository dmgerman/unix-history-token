begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FastDemangle.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_FastDemangle_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_FastDemangle_h_
end_define

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|char
modifier|*
name|FastDemangle
parameter_list|(
specifier|const
name|char
modifier|*
name|mangled_name
parameter_list|)
function_decl|;
name|char
modifier|*
name|FastDemangle
parameter_list|(
specifier|const
name|char
modifier|*
name|mangled_name
parameter_list|,
name|long
name|mangled_name_length
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

