begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSymbolWasm.h -  ----------------------------------------*- C++ -*-===//
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
name|LLVM_MC_MCSYMBOLWASM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSYMBOLWASM_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Wasm.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCSymbolWasm
range|:
name|public
name|MCSymbol
block|{
name|private
operator|:
name|bool
name|IsFunction
operator|=
name|false
block|;
name|std
operator|::
name|string
name|ModuleName
block|;
name|SmallVector
operator|<
name|wasm
operator|::
name|ValType
block|,
literal|1
operator|>
name|Returns
block|;
name|SmallVector
operator|<
name|wasm
operator|::
name|ValType
block|,
literal|4
operator|>
name|Params
block|;
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
comment|// Use a module name of "env" for now, for compatibility with existing tools.
comment|// This is temporary, and may change, as the ABI is not yet stable.
name|MCSymbolWasm
argument_list|(
argument|const StringMapEntry<bool> *Name
argument_list|,
argument|bool isTemporary
argument_list|)
operator|:
name|MCSymbol
argument_list|(
name|SymbolKindWasm
argument_list|,
name|Name
argument_list|,
name|isTemporary
argument_list|)
block|,
name|ModuleName
argument_list|(
literal|"env"
argument_list|)
block|{}
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
name|isWasm
argument_list|()
return|;
block|}
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
name|setSize
argument_list|(
argument|const MCExpr *SS
argument_list|)
block|{
name|SymbolSize
operator|=
name|SS
block|; }
name|bool
name|isFunction
argument_list|()
specifier|const
block|{
return|return
name|IsFunction
return|;
block|}
name|void
name|setIsFunction
argument_list|(
argument|bool isFunc
argument_list|)
block|{
name|IsFunction
operator|=
name|isFunc
block|; }
specifier|const
name|StringRef
name|getModuleName
argument_list|()
specifier|const
block|{
return|return
name|ModuleName
return|;
block|}
specifier|const
name|SmallVector
operator|<
name|wasm
operator|::
name|ValType
block|,
literal|1
operator|>
operator|&
name|getReturns
argument_list|()
specifier|const
block|{
return|return
name|Returns
return|;
block|}
name|void
name|setReturns
argument_list|(
argument|SmallVectorImpl<wasm::ValType>&&Rets
argument_list|)
block|{
name|Returns
operator|=
name|std
operator|::
name|move
argument_list|(
name|Rets
argument_list|)
block|;   }
specifier|const
name|SmallVector
operator|<
name|wasm
operator|::
name|ValType
block|,
literal|4
operator|>
operator|&
name|getParams
argument_list|()
specifier|const
block|{
return|return
name|Params
return|;
block|}
name|void
name|setParams
argument_list|(
argument|SmallVectorImpl<wasm::ValType>&&Pars
argument_list|)
block|{
name|Params
operator|=
name|std
operator|::
name|move
argument_list|(
name|Pars
argument_list|)
block|;   }
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

