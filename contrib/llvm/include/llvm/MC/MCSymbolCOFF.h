begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSymbolCOFF.h -  ----------------------------------------*- C++ -*-===//
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
name|LLVM_MC_MCSYMBOLCOFF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSYMBOLCOFF_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCSymbol.h"
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
name|class
name|MCSymbolCOFF
range|:
name|public
name|MCSymbol
block|{
comment|/// This corresponds to the e_type field of the COFF symbol.
name|mutable
name|uint16_t
name|Type
operator|=
literal|0
block|;    enum
name|SymbolFlags
operator|:
name|uint16_t
block|{
name|SF_ClassMask
operator|=
literal|0x00FF
block|,
name|SF_ClassShift
operator|=
literal|0
block|,
name|SF_WeakExternal
operator|=
literal|0x0100
block|,
name|SF_SafeSEH
operator|=
literal|0x0200
block|,   }
block|;
name|public
operator|:
name|MCSymbolCOFF
argument_list|(
argument|const StringMapEntry<bool> *Name
argument_list|,
argument|bool isTemporary
argument_list|)
operator|:
name|MCSymbol
argument_list|(
argument|SymbolKindCOFF
argument_list|,
argument|Name
argument_list|,
argument|isTemporary
argument_list|)
block|{}
name|uint16_t
name|getType
argument_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
name|void
name|setType
argument_list|(
argument|uint16_t Ty
argument_list|)
specifier|const
block|{
name|Type
operator|=
name|Ty
block|;   }
name|uint16_t
name|getClass
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getFlags
argument_list|()
operator|&
name|SF_ClassMask
operator|)
operator|>>
name|SF_ClassShift
return|;
block|}
name|void
name|setClass
argument_list|(
argument|uint16_t StorageClass
argument_list|)
specifier|const
block|{
name|modifyFlags
argument_list|(
name|StorageClass
operator|<<
name|SF_ClassShift
argument_list|,
name|SF_ClassMask
argument_list|)
block|;   }
name|bool
name|isWeakExternal
argument_list|()
specifier|const
block|{
return|return
name|getFlags
argument_list|()
operator|&
name|SF_WeakExternal
return|;
block|}
name|void
name|setIsWeakExternal
argument_list|()
specifier|const
block|{
name|modifyFlags
argument_list|(
name|SF_WeakExternal
argument_list|,
name|SF_WeakExternal
argument_list|)
block|;   }
name|bool
name|isSafeSEH
argument_list|()
specifier|const
block|{
return|return
name|getFlags
argument_list|()
operator|&
name|SF_SafeSEH
return|;
block|}
name|void
name|setIsSafeSEH
argument_list|()
specifier|const
block|{
name|modifyFlags
argument_list|(
name|SF_SafeSEH
argument_list|,
name|SF_SafeSEH
argument_list|)
block|;   }
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
name|isCOFF
argument_list|()
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_MC_MCSYMBOLCOFF_H
end_comment

end_unit

