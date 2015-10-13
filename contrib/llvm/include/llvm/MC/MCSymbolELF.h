begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSymbolELF.h -  -----------------------------------------*- C++ -*-===//
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
name|LLVM_MC_MCSYMBOLELF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSYMBOLELF_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCSymbol.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCSymbolELF
range|:
name|public
name|MCSymbol
block|{
comment|/// An expression describing how to calculate the size of a symbol. If a
comment|/// symbol has no size this field will be NULL.
specifier|const
name|MCExpr
operator|*
name|SymbolSize
operator|=
name|nullptr
block|;
name|public
operator|:
name|MCSymbolELF
argument_list|(
argument|const StringMapEntry<bool> *Name
argument_list|,
argument|bool isTemporary
argument_list|)
operator|:
name|MCSymbol
argument_list|(
argument|SymbolKindELF
argument_list|,
argument|Name
argument_list|,
argument|isTemporary
argument_list|)
block|{}
name|void
name|setSize
argument_list|(
argument|const MCExpr *SS
argument_list|)
block|{
name|SymbolSize
operator|=
name|SS
block|; }
specifier|const
name|MCExpr
operator|*
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|SymbolSize
return|;
block|}
name|void
name|setVisibility
argument_list|(
argument|unsigned Visibility
argument_list|)
block|;
name|unsigned
name|getVisibility
argument_list|()
specifier|const
block|;
name|void
name|setOther
argument_list|(
argument|unsigned Other
argument_list|)
block|;
name|unsigned
name|getOther
argument_list|()
specifier|const
block|;
name|void
name|setType
argument_list|(
argument|unsigned Type
argument_list|)
specifier|const
block|;
name|unsigned
name|getType
argument_list|()
specifier|const
block|;
name|void
name|setBinding
argument_list|(
argument|unsigned Binding
argument_list|)
specifier|const
block|;
name|unsigned
name|getBinding
argument_list|()
specifier|const
block|;
name|bool
name|isBindingSet
argument_list|()
specifier|const
block|;
name|void
name|setIsWeakrefUsedInReloc
argument_list|()
specifier|const
block|;
name|bool
name|isWeakrefUsedInReloc
argument_list|()
specifier|const
block|;
name|void
name|setIsSignature
argument_list|()
specifier|const
block|;
name|bool
name|isSignature
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCSymbol *S
argument_list|)
block|{
return|return
name|S
operator|->
name|isELF
argument_list|()
return|;
block|}
name|private
operator|:
name|void
name|setIsBindingSet
argument_list|()
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

