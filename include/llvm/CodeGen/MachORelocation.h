begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== MachORelocation.h - Mach-O Relocation Info ----------------*- C++ -*-===//
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
comment|// This file defines the MachORelocation class.
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
name|LLVM_CODEGEN_MACHO_RELOCATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHO_RELOCATION_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// MachORelocation - This struct contains information about each relocation
comment|/// that needs to be emitted to the file.
comment|/// see<mach-o/reloc.h>
name|class
name|MachORelocation
block|{
name|uint32_t
name|r_address
decl_stmt|;
comment|// offset in the section to what is being  relocated
name|uint32_t
name|r_symbolnum
decl_stmt|;
comment|// symbol index if r_extern == 1 else section index
name|bool
name|r_pcrel
decl_stmt|;
comment|// was relocated pc-relative already
name|uint8_t
name|r_length
decl_stmt|;
comment|// length = 2 ^ r_length
name|bool
name|r_extern
decl_stmt|;
comment|//
name|uint8_t
name|r_type
decl_stmt|;
comment|// if not 0, machine-specific relocation type.
name|bool
name|r_scattered
decl_stmt|;
comment|// 1 = scattered, 0 = non-scattered
name|int32_t
name|r_value
decl_stmt|;
comment|// the value the item to be relocated is referring
comment|// to.
name|public
label|:
name|uint32_t
name|getPackedFields
argument_list|()
specifier|const
block|{
if|if
condition|(
name|r_scattered
condition|)
return|return
operator|(
literal|1
operator|<<
literal|31
operator|)
operator||
operator|(
name|r_pcrel
operator|<<
literal|30
operator|)
operator||
operator|(
operator|(
name|r_length
operator|&
literal|3
operator|)
operator|<<
literal|28
operator|)
operator||
operator|(
operator|(
name|r_type
operator|&
literal|15
operator|)
operator|<<
literal|24
operator|)
operator||
operator|(
name|r_address
operator|&
literal|0x00FFFFFF
operator|)
return|;
else|else
return|return
operator|(
name|r_symbolnum
operator|<<
literal|8
operator|)
operator||
operator|(
name|r_pcrel
operator|<<
literal|7
operator|)
operator||
operator|(
operator|(
name|r_length
operator|&
literal|3
operator|)
operator|<<
literal|5
operator|)
operator||
operator|(
name|r_extern
operator|<<
literal|4
operator|)
operator||
operator|(
name|r_type
operator|&
literal|15
operator|)
return|;
block|}
name|uint32_t
name|getAddress
argument_list|()
specifier|const
block|{
return|return
name|r_scattered
operator|?
name|r_value
operator|:
name|r_address
return|;
block|}
name|uint32_t
name|getRawAddress
argument_list|()
specifier|const
block|{
return|return
name|r_address
return|;
block|}
name|MachORelocation
argument_list|(
argument|uint32_t addr
argument_list|,
argument|uint32_t index
argument_list|,
argument|bool pcrel
argument_list|,
argument|uint8_t len
argument_list|,
argument|bool ext
argument_list|,
argument|uint8_t type
argument_list|,
argument|bool scattered = false
argument_list|,
argument|int32_t value =
literal|0
argument_list|)
block|:
name|r_address
argument_list|(
name|addr
argument_list|)
operator|,
name|r_symbolnum
argument_list|(
name|index
argument_list|)
operator|,
name|r_pcrel
argument_list|(
name|pcrel
argument_list|)
operator|,
name|r_length
argument_list|(
name|len
argument_list|)
operator|,
name|r_extern
argument_list|(
name|ext
argument_list|)
operator|,
name|r_type
argument_list|(
name|type
argument_list|)
operator|,
name|r_scattered
argument_list|(
name|scattered
argument_list|)
operator|,
name|r_value
argument_list|(
argument|value
argument_list|)
block|{}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_MACHO_RELOCATION_H
end_comment

end_unit

