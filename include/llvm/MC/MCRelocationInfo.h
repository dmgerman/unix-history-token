begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- llvm/MC/MCRelocationInfo.h --------------------------------*- C++ -*-==//
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
comment|// This file declares the MCRelocationInfo class, which provides methods to
end_comment

begin_comment
comment|// create MCExprs from relocations, either found in an object::ObjectFile
end_comment

begin_comment
comment|// (object::RelocationRef), or provided through the C API.
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
name|LLVM_MC_MCRELOCATIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCRELOCATIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
name|class
name|RelocationRef
decl_stmt|;
block|}
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
comment|/// \brief Create MCExprs from relocations found in an object file.
name|class
name|MCRelocationInfo
block|{
name|MCRelocationInfo
argument_list|(
argument|const MCRelocationInfo&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|MCRelocationInfo
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|protected
label|:
name|MCContext
modifier|&
name|Ctx
decl_stmt|;
name|public
label|:
name|MCRelocationInfo
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|MCRelocationInfo
argument_list|()
expr_stmt|;
comment|/// \brief Create an MCExpr for the relocation \p Rel.
comment|/// \returns If possible, an MCExpr corresponding to Rel, else 0.
name|virtual
specifier|const
name|MCExpr
modifier|*
name|createExprForRelocation
argument_list|(
name|object
operator|::
name|RelocationRef
name|Rel
argument_list|)
decl_stmt|;
comment|/// \brief Create an MCExpr for the target-specific \p VariantKind.
comment|/// The VariantKinds are defined in llvm-c/Disassembler.h.
comment|/// Used by MCExternalSymbolizer.
comment|/// \returns If possible, an MCExpr corresponding to VariantKind, else 0.
name|virtual
specifier|const
name|MCExpr
modifier|*
name|createExprForCAPIVariantKind
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|SubExpr
parameter_list|,
name|unsigned
name|VariantKind
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

