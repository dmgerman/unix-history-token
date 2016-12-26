begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DebugInfoOptions.h - Debug Info Emission Types ---------*- C++ -*-===//
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
name|LLVM_CLANG_BASIC_DEBUGINFOOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_DEBUGINFOOPTIONS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|codegenoptions
block|{
enum|enum
name|DebugInfoKind
block|{
name|NoDebugInfo
block|,
comment|/// Don't generate debug info.
name|LocTrackingOnly
block|,
comment|/// Emit location information but do not generate
comment|/// debug info in the output. This is useful in
comment|/// cases where the backend wants to track source
comment|/// locations for instructions without actually
comment|/// emitting debug info for them (e.g., when -Rpass
comment|/// is used).
name|DebugLineTablesOnly
block|,
comment|/// Emit only debug info necessary for generating
comment|/// line number tables (-gline-tables-only).
name|LimitedDebugInfo
block|,
comment|/// Limit generated debug info to reduce size
comment|/// (-fno-standalone-debug). This emits
comment|/// forward decls for types that could be
comment|/// replaced with forward decls in the source
comment|/// code. For dynamic C++ classes type info
comment|/// is only emitted int the module that
comment|/// contains the classe's vtable.
name|FullDebugInfo
comment|/// Generate complete debug info.
block|}
enum|;
block|}
comment|// end namespace codegenoptions
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

