begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Memory.h -------------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
comment|// This file defines arena allocators.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Almost all large objects, such as files, sections or symbols, are
end_comment

begin_comment
comment|// used for the entire lifetime of the linker once they are created.
end_comment

begin_comment
comment|// This usage characteristic makes arena allocator an attractive choice
end_comment

begin_comment
comment|// where the entire linker is one arena. With an arena, newly created
end_comment

begin_comment
comment|// objects belong to the arena and freed all at once when everything is done.
end_comment

begin_comment
comment|// Arena allocators are efficient and easy to understand.
end_comment

begin_comment
comment|// Most objects are allocated using the arena allocators defined by this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If you edit this file, please edit COFF/Memory.h too.
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
name|LLD_ELF_MEMORY_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_MEMORY_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/StringSaver.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
comment|// Use this arena if your object doesn't have a destructor.
extern|extern llvm::BumpPtrAllocator BAlloc;
extern|extern llvm::StringSaver Saver;
comment|// These two classes are hack to keep track of all
comment|// SpecificBumpPtrAllocator instances.
struct|struct
name|SpecificAllocBase
block|{
name|SpecificAllocBase
argument_list|()
block|{
name|Instances
operator|.
name|push_back
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
name|virtual
operator|~
name|SpecificAllocBase
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
name|void
name|reset
parameter_list|()
init|=
literal|0
function_decl|;
specifier|static
name|std
operator|::
name|vector
operator|<
name|SpecificAllocBase
operator|*
operator|>
name|Instances
expr_stmt|;
block|}
struct|;
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|SpecificAlloc
operator|:
name|public
name|SpecificAllocBase
block|{
name|void
name|reset
argument_list|()
name|override
block|{
name|Alloc
operator|.
name|DestroyAll
argument_list|()
block|; }
name|llvm
operator|::
name|SpecificBumpPtrAllocator
operator|<
name|T
operator|>
name|Alloc
block|; }
expr_stmt|;
comment|// Use this arena if your object has a destructor.
comment|// Your destructor will be invoked from freeArena().
name|template
operator|<
name|typename
name|T
operator|,
name|typename
operator|...
name|U
operator|>
name|T
operator|*
name|make
argument_list|(
argument|U&&... Args
argument_list|)
block|{
specifier|static
name|SpecificAlloc
operator|<
name|T
operator|>
name|Alloc
block|;
return|return
name|new
argument_list|(
argument|Alloc.Alloc.Allocate()
argument_list|)
name|T
argument_list|(
name|std
operator|::
name|forward
operator|<
name|U
operator|>
operator|(
name|Args
operator|)
operator|...
argument_list|)
return|;
block|}
specifier|inline
name|void
name|freeArena
parameter_list|()
block|{
for|for
control|(
name|SpecificAllocBase
modifier|*
name|Alloc
range|:
name|SpecificAllocBase
operator|::
name|Instances
control|)
name|Alloc
operator|->
name|reset
argument_list|()
expr_stmt|;
name|BAlloc
operator|.
name|Reset
argument_list|()
expr_stmt|;
block|}
block|}
comment|// namespace elf
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

