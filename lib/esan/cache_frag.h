begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- cache_frag.h --------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of EfficiencySanitizer, a family of performance tuners.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Header for cache-fragmentation-specific code.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CACHE_FRAG_H
end_ifndef

begin_define
define|#
directive|define
name|CACHE_FRAG_H
end_define

begin_decl_stmt
name|namespace
name|__esan
block|{
name|void
name|processCacheFragCompilationUnitInit
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
function_decl|;
name|void
name|processCacheFragCompilationUnitExit
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
function_decl|;
name|void
name|initializeCacheFrag
parameter_list|()
function_decl|;
name|int
name|finalizeCacheFrag
parameter_list|()
function_decl|;
name|void
name|reportCacheFrag
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __esan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CACHE_FRAG_H
end_comment

end_unit

