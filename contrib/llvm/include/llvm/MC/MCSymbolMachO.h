begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSymbolMachO.h -  ---------------------------------------*- C++ -*-===//
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
name|LLVM_MC_MCSYMBOLMACHO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSYMBOLMACHO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

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
name|MCSymbolMachO
range|:
name|public
name|MCSymbol
block|{
comment|/// \brief We store the value for the 'desc' symbol field in the
comment|/// lowest 16 bits of the implementation defined flags.
block|enum
name|MachOSymbolFlags
operator|:
name|uint16_t
block|{
comment|// See<mach-o/nlist.h>.
name|SF_DescFlagsMask
operator|=
literal|0xFFFF
block|,
comment|// Reference type flags.
name|SF_ReferenceTypeMask
operator|=
literal|0x0007
block|,
name|SF_ReferenceTypeUndefinedNonLazy
operator|=
literal|0x0000
block|,
name|SF_ReferenceTypeUndefinedLazy
operator|=
literal|0x0001
block|,
name|SF_ReferenceTypeDefined
operator|=
literal|0x0002
block|,
name|SF_ReferenceTypePrivateDefined
operator|=
literal|0x0003
block|,
name|SF_ReferenceTypePrivateUndefinedNonLazy
operator|=
literal|0x0004
block|,
name|SF_ReferenceTypePrivateUndefinedLazy
operator|=
literal|0x0005
block|,
comment|// Other 'desc' flags.
name|SF_ThumbFunc
operator|=
literal|0x0008
block|,
name|SF_NoDeadStrip
operator|=
literal|0x0020
block|,
name|SF_WeakReference
operator|=
literal|0x0040
block|,
name|SF_WeakDefinition
operator|=
literal|0x0080
block|,
name|SF_SymbolResolver
operator|=
literal|0x0100
block|,
name|SF_AltEntry
operator|=
literal|0x0200
block|,
comment|// Common alignment
name|SF_CommonAlignmentMask
operator|=
literal|0xF0FF
block|,
name|SF_CommonAlignmentShift
operator|=
literal|8
block|}
block|;
name|public
operator|:
name|MCSymbolMachO
argument_list|(
argument|const StringMapEntry<bool> *Name
argument_list|,
argument|bool isTemporary
argument_list|)
operator|:
name|MCSymbol
argument_list|(
argument|SymbolKindMachO
argument_list|,
argument|Name
argument_list|,
argument|isTemporary
argument_list|)
block|{}
comment|// Reference type methods.
name|void
name|clearReferenceType
argument_list|()
specifier|const
block|{
name|modifyFlags
argument_list|(
literal|0
argument_list|,
name|SF_ReferenceTypeMask
argument_list|)
block|;   }
name|void
name|setReferenceTypeUndefinedLazy
argument_list|(
argument|bool Value
argument_list|)
specifier|const
block|{
name|modifyFlags
argument_list|(
name|Value
operator|?
name|SF_ReferenceTypeUndefinedLazy
operator|:
literal|0
argument_list|,
name|SF_ReferenceTypeUndefinedLazy
argument_list|)
block|;   }
comment|// Other 'desc' methods.
name|void
name|setThumbFunc
argument_list|()
specifier|const
block|{
name|modifyFlags
argument_list|(
name|SF_ThumbFunc
argument_list|,
name|SF_ThumbFunc
argument_list|)
block|;   }
name|bool
name|isNoDeadStrip
argument_list|()
specifier|const
block|{
return|return
name|getFlags
argument_list|()
operator|&
name|SF_NoDeadStrip
return|;
block|}
name|void
name|setNoDeadStrip
argument_list|()
specifier|const
block|{
name|modifyFlags
argument_list|(
name|SF_NoDeadStrip
argument_list|,
name|SF_NoDeadStrip
argument_list|)
block|;   }
name|bool
name|isWeakReference
argument_list|()
specifier|const
block|{
return|return
name|getFlags
argument_list|()
operator|&
name|SF_WeakReference
return|;
block|}
name|void
name|setWeakReference
argument_list|()
specifier|const
block|{
name|modifyFlags
argument_list|(
name|SF_WeakReference
argument_list|,
name|SF_WeakReference
argument_list|)
block|;   }
name|bool
name|isWeakDefinition
argument_list|()
specifier|const
block|{
return|return
name|getFlags
argument_list|()
operator|&
name|SF_WeakDefinition
return|;
block|}
name|void
name|setWeakDefinition
argument_list|()
specifier|const
block|{
name|modifyFlags
argument_list|(
name|SF_WeakDefinition
argument_list|,
name|SF_WeakDefinition
argument_list|)
block|;   }
name|bool
name|isSymbolResolver
argument_list|()
specifier|const
block|{
return|return
name|getFlags
argument_list|()
operator|&
name|SF_SymbolResolver
return|;
block|}
name|void
name|setSymbolResolver
argument_list|()
specifier|const
block|{
name|modifyFlags
argument_list|(
name|SF_SymbolResolver
argument_list|,
name|SF_SymbolResolver
argument_list|)
block|;   }
name|void
name|setAltEntry
argument_list|()
specifier|const
block|{
name|modifyFlags
argument_list|(
name|SF_AltEntry
argument_list|,
name|SF_AltEntry
argument_list|)
block|;   }
name|bool
name|isAltEntry
argument_list|()
specifier|const
block|{
return|return
name|getFlags
argument_list|()
operator|&
name|SF_AltEntry
return|;
block|}
name|void
name|setDesc
argument_list|(
argument|unsigned Value
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Value
operator|==
operator|(
name|Value
operator|&
name|SF_DescFlagsMask
operator|)
operator|&&
literal|"Invalid .desc value!"
argument_list|)
block|;
name|setFlags
argument_list|(
name|Value
operator|&
name|SF_DescFlagsMask
argument_list|)
block|;   }
comment|/// \brief Get the encoded value of the flags as they will be emitted in to
comment|/// the MachO binary
name|uint16_t
name|getEncodedFlags
argument_list|(
argument|bool EncodeAsAltEntry
argument_list|)
specifier|const
block|{
name|uint16_t
name|Flags
operator|=
name|getFlags
argument_list|()
block|;
comment|// Common alignment is packed into the 'desc' bits.
if|if
condition|(
name|isCommon
argument_list|()
condition|)
block|{
if|if
condition|(
name|unsigned
name|Align
init|=
name|getCommonAlignment
argument_list|()
condition|)
block|{
name|unsigned
name|Log2Size
init|=
name|Log2_32
argument_list|(
name|Align
argument_list|)
decl_stmt|;
name|assert
argument_list|(
operator|(
literal|1U
operator|<<
name|Log2Size
operator|)
operator|==
name|Align
operator|&&
literal|"Invalid 'common' alignment!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|Log2Size
operator|>
literal|15
condition|)
name|report_fatal_error
argument_list|(
literal|"invalid 'common' alignment '"
operator|+
name|Twine
argument_list|(
name|Align
argument_list|)
operator|+
literal|"' for '"
operator|+
name|getName
argument_list|()
operator|+
literal|"'"
argument_list|,
name|false
argument_list|)
expr_stmt|;
name|Flags
operator|=
operator|(
name|Flags
operator|&
name|SF_CommonAlignmentMask
operator|)
operator||
operator|(
name|Log2Size
operator|<<
name|SF_CommonAlignmentShift
operator|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|EncodeAsAltEntry
condition|)
name|Flags
operator||=
name|SF_AltEntry
expr_stmt|;
return|return
name|Flags
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|S
parameter_list|)
block|{
return|return
name|S
operator|->
name|isMachO
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

