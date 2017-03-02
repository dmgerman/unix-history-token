begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RuntimeDyldELFMips.h ---- ELF/Mips specific code. -------*- C++ -*-===//
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
name|LLVM_LIB_EXECUTIONENGINE_RUNTIMEDYLD_TARGETS_RUNTIMEDYLDELFMIPS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_EXECUTIONENGINE_RUNTIMEDYLD_TARGETS_RUNTIMEDYLDELFMIPS_H
end_define

begin_include
include|#
directive|include
file|"../RuntimeDyldELF.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_define
define|#
directive|define
name|DEBUG_TYPE
value|"dyld"
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|RuntimeDyldELFMips
range|:
name|public
name|RuntimeDyldELF
block|{
name|public
operator|:
typedef|typedef
name|uint64_t
name|TargetPtrT
typedef|;
name|RuntimeDyldELFMips
argument_list|(
name|RuntimeDyld
operator|::
name|MemoryManager
operator|&
name|MM
argument_list|,
name|JITSymbolResolver
operator|&
name|Resolver
argument_list|)
operator|:
name|RuntimeDyldELF
argument_list|(
argument|MM
argument_list|,
argument|Resolver
argument_list|)
block|{}
name|void
name|resolveRelocation
argument_list|(
argument|const RelocationEntry&RE
argument_list|,
argument|uint64_t Value
argument_list|)
name|override
decl_stmt|;
name|protected
label|:
name|void
name|resolveMIPSO32Relocation
parameter_list|(
specifier|const
name|SectionEntry
modifier|&
name|Section
parameter_list|,
name|uint64_t
name|Offset
parameter_list|,
name|uint32_t
name|Value
parameter_list|,
name|uint32_t
name|Type
parameter_list|,
name|int32_t
name|Addend
parameter_list|)
function_decl|;
name|void
name|resolveMIPSN32Relocation
parameter_list|(
specifier|const
name|SectionEntry
modifier|&
name|Section
parameter_list|,
name|uint64_t
name|Offset
parameter_list|,
name|uint64_t
name|Value
parameter_list|,
name|uint32_t
name|Type
parameter_list|,
name|int64_t
name|Addend
parameter_list|,
name|uint64_t
name|SymOffset
parameter_list|,
name|SID
name|SectionID
parameter_list|)
function_decl|;
name|void
name|resolveMIPSN64Relocation
parameter_list|(
specifier|const
name|SectionEntry
modifier|&
name|Section
parameter_list|,
name|uint64_t
name|Offset
parameter_list|,
name|uint64_t
name|Value
parameter_list|,
name|uint32_t
name|Type
parameter_list|,
name|int64_t
name|Addend
parameter_list|,
name|uint64_t
name|SymOffset
parameter_list|,
name|SID
name|SectionID
parameter_list|)
function_decl|;
name|private
label|:
comment|/// \brief A object file specific relocation resolver
comment|/// \param RE The relocation to be resolved
comment|/// \param Value Target symbol address to apply the relocation action
name|uint64_t
name|evaluateRelocation
parameter_list|(
specifier|const
name|RelocationEntry
modifier|&
name|RE
parameter_list|,
name|uint64_t
name|Value
parameter_list|,
name|uint64_t
name|Addend
parameter_list|)
function_decl|;
comment|/// \brief A object file specific relocation resolver
comment|/// \param RE The relocation to be resolved
comment|/// \param Value Target symbol address to apply the relocation action
name|void
name|applyRelocation
parameter_list|(
specifier|const
name|RelocationEntry
modifier|&
name|RE
parameter_list|,
name|uint64_t
name|Value
parameter_list|)
function_decl|;
name|int64_t
name|evaluateMIPS32Relocation
parameter_list|(
specifier|const
name|SectionEntry
modifier|&
name|Section
parameter_list|,
name|uint64_t
name|Offset
parameter_list|,
name|uint64_t
name|Value
parameter_list|,
name|uint32_t
name|Type
parameter_list|)
function_decl|;
name|int64_t
name|evaluateMIPS64Relocation
parameter_list|(
specifier|const
name|SectionEntry
modifier|&
name|Section
parameter_list|,
name|uint64_t
name|Offset
parameter_list|,
name|uint64_t
name|Value
parameter_list|,
name|uint32_t
name|Type
parameter_list|,
name|int64_t
name|Addend
parameter_list|,
name|uint64_t
name|SymOffset
parameter_list|,
name|SID
name|SectionID
parameter_list|)
function_decl|;
name|void
name|applyMIPSRelocation
parameter_list|(
name|uint8_t
modifier|*
name|TargetPtr
parameter_list|,
name|int64_t
name|CalculatedValue
parameter_list|,
name|uint32_t
name|Type
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_undef
unit|}
undef|#
directive|undef
name|DEBUG_TYPE
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

