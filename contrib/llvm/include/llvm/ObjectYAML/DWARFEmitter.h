begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DWARFEmitter.h - ---------------------------------------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// \brief Common declarations for yaml2obj
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_OBJECTYAML_DWARFEMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECTYAML_DWARFEMITTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Host.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|namespace
name|DWARFYAML
block|{
struct_decl|struct
name|Data
struct_decl|;
struct_decl|struct
name|PubSection
struct_decl|;
name|void
name|EmitDebugAbbrev
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|Data
modifier|&
name|DI
parameter_list|)
function_decl|;
name|void
name|EmitDebugStr
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|Data
modifier|&
name|DI
parameter_list|)
function_decl|;
name|void
name|EmitDebugAranges
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|Data
modifier|&
name|DI
parameter_list|)
function_decl|;
name|void
name|EmitPubSection
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|PubSection
modifier|&
name|Sect
parameter_list|,
name|bool
name|IsLittleEndian
parameter_list|)
function_decl|;
name|void
name|EmitDebugInfo
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|Data
modifier|&
name|DI
parameter_list|)
function_decl|;
name|void
name|EmitDebugLine
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|Data
modifier|&
name|DI
parameter_list|)
function_decl|;
name|Expected
operator|<
name|StringMap
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>>>
name|EmitDebugSections
argument_list|(
argument|StringRef YAMLString
argument_list|,
argument|bool IsLittleEndian = sys::IsLittleEndianHost
argument_list|)
expr_stmt|;
block|}
comment|// end namespace DWARFYAML
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_OBJECTYAML_DWARFEMITTER_H
end_comment

end_unit

