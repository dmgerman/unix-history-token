begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Demangle.h ---------------------------------------------*- C++ -*-===//
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

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// This is a llvm local version of __cxa_demangle. Other than the name and
comment|/// being in the llvm namespace it is identical.
comment|///
comment|/// The mangled_name is demangled into buf and returned. If the buffer is not
comment|/// large enough, realloc is used to expand it.
comment|///
comment|/// The *status will be set to
comment|///   unknown_error: -4
comment|///   invalid_args:  -3
comment|///   invalid_mangled_name: -2
comment|///   memory_alloc_failure: -1
comment|///   success: 0
name|char
modifier|*
name|itaniumDemangle
parameter_list|(
specifier|const
name|char
modifier|*
name|mangled_name
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|*
name|n
parameter_list|,
name|int
modifier|*
name|status
parameter_list|)
function_decl|;
block|}
end_decl_stmt

end_unit

