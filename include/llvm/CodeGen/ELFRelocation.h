begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== ELFRelocation.h - ELF Relocation Info ---------------------*- C++ -*-===//
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
comment|// This file defines the ELFRelocation class.
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
name|LLVM_CODEGEN_ELF_RELOCATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_ELF_RELOCATION_H
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
comment|/// ELFRelocation - This class contains all the information necessary to
comment|/// to generate any 32-bit or 64-bit ELF relocation entry.
name|class
name|ELFRelocation
block|{
name|uint64_t
name|r_offset
decl_stmt|;
comment|// offset in the section of the object this applies to
name|uint32_t
name|r_symidx
decl_stmt|;
comment|// symbol table index of the symbol to use
name|uint32_t
name|r_type
decl_stmt|;
comment|// machine specific relocation type
name|int64_t
name|r_add
decl_stmt|;
comment|// explicit relocation addend
name|bool
name|r_rela
decl_stmt|;
comment|// if true then the addend is part of the entry
comment|// otherwise the addend is at the location specified
comment|// by r_offset
name|public
label|:
name|uint64_t
name|getInfo
argument_list|(
name|bool
name|is64Bit
operator|=
name|false
argument_list|)
decl|const
block|{
if|if
condition|(
name|is64Bit
condition|)
return|return
operator|(
operator|(
name|uint64_t
operator|)
name|r_symidx
operator|<<
literal|32
operator|)
operator|+
operator|(
operator|(
name|uint64_t
operator|)
name|r_type
operator|&
literal|0xFFFFFFFFL
operator|)
return|;
else|else
return|return
operator|(
name|r_symidx
operator|<<
literal|8
operator|)
operator|+
operator|(
name|r_type
operator|&
literal|0xFFL
operator|)
return|;
block|}
name|uint64_t
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|r_offset
return|;
block|}
name|uint64_t
name|getAddress
argument_list|()
specifier|const
block|{
return|return
name|r_add
return|;
block|}
name|ELFRelocation
argument_list|(
argument|uint64_t off
argument_list|,
argument|uint32_t sym
argument_list|,
argument|uint32_t type
argument_list|,
argument|bool rela = true
argument_list|,
argument|int64_t addend =
literal|0
argument_list|)
block|:
name|r_offset
argument_list|(
name|off
argument_list|)
operator|,
name|r_symidx
argument_list|(
name|sym
argument_list|)
operator|,
name|r_type
argument_list|(
name|type
argument_list|)
operator|,
name|r_add
argument_list|(
name|addend
argument_list|)
operator|,
name|r_rela
argument_list|(
argument|rela
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
comment|// LLVM_CODEGEN_ELF_RELOCATION_H
end_comment

end_unit

