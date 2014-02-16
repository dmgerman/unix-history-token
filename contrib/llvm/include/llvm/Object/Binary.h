begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Binary.h - A generic binary file -------------------------*- C++ -*-===//
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
comment|// This file declares the Binary class.
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
name|LLVM_OBJECT_BINARY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECT_BINARY_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/Error.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBuffer
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|namespace
name|object
block|{
name|class
name|Binary
block|{
name|private
label|:
name|Binary
argument_list|()
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|Binary
argument_list|(
argument|const Binary&other
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|unsigned
name|int
name|TypeID
decl_stmt|;
name|protected
label|:
name|MemoryBuffer
modifier|*
name|Data
decl_stmt|;
name|Binary
argument_list|(
argument|unsigned int Type
argument_list|,
argument|MemoryBuffer *Source
argument_list|)
empty_stmt|;
enum|enum
block|{
name|ID_Archive
block|,
name|ID_MachOUniversalBinary
block|,
comment|// Object and children.
name|ID_StartObjects
block|,
name|ID_COFF
block|,
name|ID_ELF32L
block|,
comment|// ELF 32-bit, little endian
name|ID_ELF32B
block|,
comment|// ELF 32-bit, big endian
name|ID_ELF64L
block|,
comment|// ELF 64-bit, little endian
name|ID_ELF64B
block|,
comment|// ELF 64-bit, big endian
name|ID_MachO32L
block|,
comment|// MachO 32-bit, little endian
name|ID_MachO32B
block|,
comment|// MachO 32-bit, big endian
name|ID_MachO64L
block|,
comment|// MachO 64-bit, little endian
name|ID_MachO64B
block|,
comment|// MachO 64-bit, big endian
name|ID_EndObjects
block|}
enum|;
specifier|static
specifier|inline
name|unsigned
name|int
name|getELFType
parameter_list|(
name|bool
name|isLE
parameter_list|,
name|bool
name|is64Bits
parameter_list|)
block|{
if|if
condition|(
name|isLE
condition|)
return|return
name|is64Bits
condition|?
name|ID_ELF64L
else|:
name|ID_ELF32L
return|;
else|else
return|return
name|is64Bits
condition|?
name|ID_ELF64B
else|:
name|ID_ELF32B
return|;
block|}
specifier|static
name|unsigned
name|int
name|getMachOType
parameter_list|(
name|bool
name|isLE
parameter_list|,
name|bool
name|is64Bits
parameter_list|)
block|{
if|if
condition|(
name|isLE
condition|)
return|return
name|is64Bits
condition|?
name|ID_MachO64L
else|:
name|ID_MachO32L
return|;
else|else
return|return
name|is64Bits
condition|?
name|ID_MachO64B
else|:
name|ID_MachO32B
return|;
block|}
name|public
label|:
name|virtual
operator|~
name|Binary
argument_list|()
expr_stmt|;
name|StringRef
name|getData
argument_list|()
specifier|const
expr_stmt|;
name|StringRef
name|getFileName
argument_list|()
specifier|const
expr_stmt|;
comment|// Cast methods.
name|unsigned
name|int
name|getType
argument_list|()
specifier|const
block|{
return|return
name|TypeID
return|;
block|}
comment|// Convenience methods
name|bool
name|isObject
argument_list|()
specifier|const
block|{
return|return
name|TypeID
operator|>
name|ID_StartObjects
operator|&&
name|TypeID
operator|<
name|ID_EndObjects
return|;
block|}
name|bool
name|isArchive
argument_list|()
specifier|const
block|{
return|return
name|TypeID
operator|==
name|ID_Archive
return|;
block|}
name|bool
name|isMachOUniversalBinary
argument_list|()
specifier|const
block|{
return|return
name|TypeID
operator|==
name|ID_MachOUniversalBinary
return|;
block|}
name|bool
name|isELF
argument_list|()
specifier|const
block|{
return|return
name|TypeID
operator|>=
name|ID_ELF32L
operator|&&
name|TypeID
operator|<=
name|ID_ELF64B
return|;
block|}
name|bool
name|isMachO
argument_list|()
specifier|const
block|{
return|return
name|TypeID
operator|>=
name|ID_MachO32L
operator|&&
name|TypeID
operator|<=
name|ID_MachO64B
return|;
block|}
name|bool
name|isCOFF
argument_list|()
specifier|const
block|{
return|return
name|TypeID
operator|==
name|ID_COFF
return|;
block|}
name|bool
name|isLittleEndian
argument_list|()
specifier|const
block|{
return|return
operator|!
operator|(
name|TypeID
operator|==
name|ID_ELF32B
operator|||
name|TypeID
operator|==
name|ID_ELF64B
operator|||
name|TypeID
operator|==
name|ID_MachO32B
operator|||
name|TypeID
operator|==
name|ID_MachO64B
operator|)
return|;
block|}
block|}
empty_stmt|;
comment|/// @brief Create a Binary from Source, autodetecting the file type.
comment|///
comment|/// @param Source The data to create the Binary from. Ownership is transferred
comment|///        to Result if successful. If an error is returned, Source is destroyed
comment|///        by createBinary before returning.
comment|/// @param Result A pointer to the resulting Binary if no error occured.
name|error_code
name|createBinary
argument_list|(
name|MemoryBuffer
operator|*
name|Source
argument_list|,
name|OwningPtr
operator|<
name|Binary
operator|>
operator|&
name|Result
argument_list|)
decl_stmt|;
name|error_code
name|createBinary
argument_list|(
name|StringRef
name|Path
argument_list|,
name|OwningPtr
operator|<
name|Binary
operator|>
operator|&
name|Result
argument_list|)
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

