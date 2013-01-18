begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ubsan_handlers_cxx.h ------------------------------------*- C++ -*-===//
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
comment|// Entry points to the runtime library for Clang's undefined behavior sanitizer,
end_comment

begin_comment
comment|// for C++-specific checks. This code is not linked into C binaries.
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
name|UBSAN_HANDLERS_CXX_H
end_ifndef

begin_define
define|#
directive|define
name|UBSAN_HANDLERS_CXX_H
end_define

begin_include
include|#
directive|include
file|"ubsan_value.h"
end_include

begin_decl_stmt
name|namespace
name|__ubsan
block|{
struct|struct
name|DynamicTypeCacheMissData
block|{
name|SourceLocation
name|Loc
decl_stmt|;
specifier|const
name|TypeDescriptor
modifier|&
name|Type
decl_stmt|;
name|void
modifier|*
name|TypeInfo
decl_stmt|;
name|unsigned
name|char
name|TypeCheckKind
decl_stmt|;
block|}
struct|;
comment|/// \brief Handle a runtime type check failure, caused by an incorrect vptr.
comment|/// When this handler is called, all we know is that the type was not in the
comment|/// cache; this does not necessarily imply the existence of a bug.
extern|extern
literal|"C"
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__ubsan_handle_dynamic_type_cache_miss
parameter_list|(
name|DynamicTypeCacheMissData
modifier|*
name|Data
parameter_list|,
name|ValueHandle
name|Pointer
parameter_list|,
name|ValueHandle
name|Hash
parameter_list|)
function_decl|;
extern|extern
literal|"C"
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__ubsan_handle_dynamic_type_cache_miss_abort
parameter_list|(
name|DynamicTypeCacheMissData
modifier|*
name|Data
parameter_list|,
name|ValueHandle
name|Pointer
parameter_list|,
name|ValueHandle
name|Hash
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// UBSAN_HANDLERS_H
end_comment

end_unit

