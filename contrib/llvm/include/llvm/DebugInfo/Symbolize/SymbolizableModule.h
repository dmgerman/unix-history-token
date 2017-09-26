begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SymbolizableModule.h -------------------------------------*- C++ -*-===//
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
comment|// This file declares the SymbolizableModule interface.
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
name|LLVM_DEBUGINFO_SYMBOLIZE_SYMBOLIZABLEMODULE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_SYMBOLIZE_SYMBOLIZABLEMODULE_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DIContext.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|symbolize
block|{
name|using
name|FunctionNameKind
init|=
name|DILineInfoSpecifier
operator|::
name|FunctionNameKind
decl_stmt|;
name|class
name|SymbolizableModule
block|{
name|public
label|:
name|virtual
operator|~
name|SymbolizableModule
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
name|DILineInfo
name|symbolizeCode
argument_list|(
name|uint64_t
name|ModuleOffset
argument_list|,
name|FunctionNameKind
name|FNKind
argument_list|,
name|bool
name|UseSymbolTable
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|DIInliningInfo
name|symbolizeInlinedCode
argument_list|(
name|uint64_t
name|ModuleOffset
argument_list|,
name|FunctionNameKind
name|FNKind
argument_list|,
name|bool
name|UseSymbolTable
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|DIGlobal
name|symbolizeData
argument_list|(
name|uint64_t
name|ModuleOffset
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// Return true if this is a 32-bit x86 PE COFF module.
name|virtual
name|bool
name|isWin32Module
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Returns the preferred base of the module, i.e. where the loader would place
comment|// it in memory assuming there were no conflicts.
name|virtual
name|uint64_t
name|getModulePreferredBase
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace symbolize
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
comment|// LLVM_DEBUGINFO_SYMBOLIZE_SYMBOLIZABLEMODULE_H
end_comment

end_unit

