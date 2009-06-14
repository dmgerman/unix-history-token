begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetELFWriterInfo.h - ELF Writer Info -----*- C++ -*-===//
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
comment|// This file defines the TargetELFWriterInfo class.
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
name|LLVM_TARGET_TARGETELFWRITERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETELFWRITERINFO_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|//                          TargetELFWriterInfo
comment|//===--------------------------------------------------------------------===//
name|class
name|TargetELFWriterInfo
block|{
name|protected
label|:
comment|// EMachine - This field is the target specific value to emit as the
comment|// e_machine member of the ELF header.
name|unsigned
name|short
name|EMachine
decl_stmt|;
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
name|bool
name|is64Bit
decl_stmt|,
name|isLittleEndian
decl_stmt|;
name|public
label|:
comment|// Machine architectures
enum|enum
name|MachineType
block|{
name|EM_NONE
init|=
literal|0
block|,
comment|// No machine
name|EM_M32
init|=
literal|1
block|,
comment|// AT&T WE 32100
name|EM_SPARC
init|=
literal|2
block|,
comment|// SPARC
name|EM_386
init|=
literal|3
block|,
comment|// Intel 386
name|EM_68K
init|=
literal|4
block|,
comment|// Motorola 68000
name|EM_88K
init|=
literal|5
block|,
comment|// Motorola 88000
name|EM_486
init|=
literal|6
block|,
comment|// Intel 486 (deprecated)
name|EM_860
init|=
literal|7
block|,
comment|// Intel 80860
name|EM_MIPS
init|=
literal|8
block|,
comment|// MIPS R3000
name|EM_PPC
init|=
literal|20
block|,
comment|// PowerPC
name|EM_ARM
init|=
literal|40
block|,
comment|// ARM
name|EM_ALPHA
init|=
literal|41
block|,
comment|// DEC Alpha
name|EM_SPARCV9
init|=
literal|43
block|,
comment|// SPARC V9
name|EM_X86_64
init|=
literal|62
comment|// AMD64
block|}
enum|;
comment|// ELF File classes
enum|enum
block|{
name|ELFCLASS32
init|=
literal|1
block|,
comment|// 32-bit object file
name|ELFCLASS64
init|=
literal|2
comment|// 64-bit object file
block|}
enum|;
comment|// ELF Endianess
enum|enum
block|{
name|ELFDATA2LSB
init|=
literal|1
block|,
comment|// Little-endian object file
name|ELFDATA2MSB
init|=
literal|2
comment|// Big-endian object file
block|}
enum|;
name|explicit
name|TargetELFWriterInfo
parameter_list|(
name|TargetMachine
modifier|&
name|tm
parameter_list|)
function_decl|;
name|virtual
operator|~
name|TargetELFWriterInfo
argument_list|()
expr_stmt|;
name|unsigned
name|short
name|getEMachine
argument_list|()
specifier|const
block|{
return|return
name|EMachine
return|;
block|}
name|unsigned
name|getEFlags
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|unsigned
name|getEIClass
argument_list|()
specifier|const
block|{
return|return
name|is64Bit
operator|?
name|ELFCLASS64
operator|:
name|ELFCLASS32
return|;
block|}
name|unsigned
name|getEIData
argument_list|()
specifier|const
block|{
return|return
name|isLittleEndian
operator|?
name|ELFDATA2LSB
operator|:
name|ELFDATA2MSB
return|;
block|}
comment|/// ELF Header and ELF Section Header Info
name|unsigned
name|getHdrSize
argument_list|()
specifier|const
block|{
return|return
name|is64Bit
operator|?
literal|64
operator|:
literal|52
return|;
block|}
name|unsigned
name|getSHdrSize
argument_list|()
specifier|const
block|{
return|return
name|is64Bit
operator|?
literal|64
operator|:
literal|40
return|;
block|}
comment|/// Symbol Table Info
name|unsigned
name|getSymTabEntrySize
argument_list|()
specifier|const
block|{
return|return
name|is64Bit
operator|?
literal|24
operator|:
literal|16
return|;
block|}
name|unsigned
name|getSymTabAlignment
argument_list|()
specifier|const
block|{
return|return
name|is64Bit
operator|?
literal|8
operator|:
literal|4
return|;
block|}
comment|/// getFunctionAlignment - Returns the alignment for function 'F', targets
comment|/// with different alignment constraints should overload this method
name|virtual
name|unsigned
name|getFunctionAlignment
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|)
decl|const
decl_stmt|;
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
comment|// LLVM_TARGET_TARGETELFWRITERINFO_H
end_comment

end_unit

