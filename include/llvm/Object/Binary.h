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
expr_stmt|;
comment|// = delete
name|Binary
argument_list|(
specifier|const
name|Binary
operator|&
name|other
argument_list|)
expr_stmt|;
comment|// = delete
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
name|isArchive
block|,
comment|// Object and children.
name|isObject
block|,
name|isCOFF
block|,
name|isELF
block|,
name|isMachO
block|,
name|lastObject
block|}
enum|;
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
specifier|static
specifier|inline
name|bool
name|classof
parameter_list|(
specifier|const
name|Binary
modifier|*
name|v
parameter_list|)
block|{
return|return
name|true
return|;
block|}
block|}
empty_stmt|;
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

