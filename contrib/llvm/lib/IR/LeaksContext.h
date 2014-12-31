begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LeaksContext.h - LeadDetector Implementation ------------*- C++ -*--===//
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
comment|//  This file defines various helper methods and classes used by
end_comment

begin_comment
comment|// LLVMContextImpl for leaks detectors.
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
name|LLVM_IR_LEAKSCONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_LEAKSCONTEXT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|PrinterTrait
block|{
specifier|static
name|void
name|print
argument_list|(
argument|const T* P
argument_list|)
block|{
name|errs
argument_list|()
operator|<<
name|P
block|; }
block|}
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|PrinterTrait
operator|<
name|Value
operator|>
block|{
specifier|static
name|void
name|print
argument_list|(
argument|const Value* P
argument_list|)
block|{
name|errs
argument_list|()
operator|<<
operator|*
name|P
block|; }
block|}
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|LeakDetectorImpl
block|{
name|explicit
name|LeakDetectorImpl
argument_list|(
specifier|const
name|char
operator|*
specifier|const
name|name
operator|=
literal|""
argument_list|)
operator|:
name|Cache
argument_list|(
name|nullptr
argument_list|)
block|,
name|Name
argument_list|(
argument|name
argument_list|)
block|{ }
name|void
name|clear
argument_list|()
block|{
name|Cache
operator|=
name|nullptr
block|;
name|Ts
operator|.
name|clear
argument_list|()
block|;   }
name|void
name|setName
argument_list|(
argument|const char* n
argument_list|)
block|{
name|Name
operator|=
name|n
block|;   }
comment|// Because the most common usage pattern, by far, is to add a
comment|// garbage object, then remove it immediately, we optimize this
comment|// case.  When an object is added, it is not added to the set
comment|// immediately, it is added to the CachedValue Value.  If it is
comment|// immediately removed, no set search need be performed.
name|void
name|addGarbage
argument_list|(
argument|const T* o
argument_list|)
block|{
name|assert
argument_list|(
name|Ts
operator|.
name|count
argument_list|(
name|o
argument_list|)
operator|==
literal|0
operator|&&
literal|"Object already in set!"
argument_list|)
block|;
if|if
condition|(
name|Cache
condition|)
block|{
name|assert
argument_list|(
name|Cache
operator|!=
name|o
operator|&&
literal|"Object already in set!"
argument_list|)
expr_stmt|;
name|Ts
operator|.
name|insert
argument_list|(
name|Cache
argument_list|)
expr_stmt|;
block|}
name|Cache
operator|=
name|o
expr_stmt|;
block|}
name|void
name|removeGarbage
argument_list|(
argument|const T* o
argument_list|)
block|{
if|if
condition|(
name|o
operator|==
name|Cache
condition|)
name|Cache
operator|=
name|nullptr
expr_stmt|;
comment|// Cache hit
else|else
name|Ts
operator|.
name|erase
argument_list|(
name|o
argument_list|)
expr_stmt|;
block|}
name|bool
name|hasGarbage
argument_list|(
argument|const std::string& Message
argument_list|)
block|{
name|addGarbage
argument_list|(
name|nullptr
argument_list|)
block|;
comment|// Flush the Cache
name|assert
argument_list|(
operator|!
name|Cache
operator|&&
literal|"No value should be cached anymore!"
argument_list|)
block|;
if|if
condition|(
operator|!
name|Ts
operator|.
name|empty
argument_list|()
condition|)
block|{
name|errs
argument_list|()
operator|<<
literal|"Leaked "
operator|<<
name|Name
operator|<<
literal|" objects found: "
operator|<<
name|Message
operator|<<
literal|":\n"
expr_stmt|;
for|for
control|(
name|typename
name|SmallPtrSet
operator|<
specifier|const
name|T
operator|*
operator|,
literal|8
operator|>
operator|::
name|iterator
name|I
operator|=
name|Ts
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|Ts
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
name|errs
argument_list|()
operator|<<
literal|'\t'
expr_stmt|;
name|PrinterTrait
operator|<
name|T
operator|>
operator|::
name|print
argument_list|(
operator|*
name|I
argument_list|)
expr_stmt|;
name|errs
argument_list|()
operator|<<
literal|'\n'
expr_stmt|;
block|}
name|errs
argument_list|()
operator|<<
literal|'\n'
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|private
operator|:
name|SmallPtrSet
operator|<
specifier|const
name|T
operator|*
block|,
literal|8
operator|>
name|Ts
block|;
specifier|const
name|T
operator|*
name|Cache
block|;
specifier|const
name|char
operator|*
name|Name
block|; }
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_LEAKSCONTEXT_H
end_comment

end_unit

