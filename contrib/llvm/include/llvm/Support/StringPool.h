begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- StringPool.h - Interned string pool ----------------------*- C++ -*-===//
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
comment|// This file declares an interned string pool, which helps reduce the cost of
end_comment

begin_comment
comment|// strings by using the same storage for identical strings.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To intern a string:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   StringPool Pool;
end_comment

begin_comment
comment|//   PooledStringPtr Str = Pool.intern("wakka wakka");
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To use the value of an interned string, use operator bool and operator*:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   if (Str)
end_comment

begin_comment
comment|//     cerr<< "the string is"<< *Str<< "\n";
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Pooled strings are immutable, but you can change a PooledStringPtr to point
end_comment

begin_comment
comment|// to another instance. So that interned strings can eventually be freed,
end_comment

begin_comment
comment|// strings in the string pool are reference-counted (automatically).
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
name|LLVM_SUPPORT_STRINGPOOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_STRINGPOOL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PooledStringPtr
decl_stmt|;
comment|/// StringPool - An interned string pool. Use the intern method to add a
comment|/// string. Strings are removed automatically as PooledStringPtrs are
comment|/// destroyed.
name|class
name|StringPool
block|{
comment|/// PooledString - This is the value of an entry in the pool's interning
comment|/// table.
struct|struct
name|PooledString
block|{
name|StringPool
modifier|*
name|Pool
init|=
name|nullptr
decl_stmt|;
comment|///< So the string can remove itself.
name|unsigned
name|Refcount
init|=
literal|0
decl_stmt|;
comment|///< Number of referencing PooledStringPtrs.
name|public
label|:
name|PooledString
argument_list|()
operator|=
expr|default
expr_stmt|;
block|}
struct|;
name|friend
name|class
name|PooledStringPtr
decl_stmt|;
name|using
name|table_t
init|=
name|StringMap
operator|<
name|PooledString
operator|>
decl_stmt|;
name|using
name|entry_t
init|=
name|StringMapEntry
operator|<
name|PooledString
operator|>
decl_stmt|;
name|table_t
name|InternTable
decl_stmt|;
name|public
label|:
name|StringPool
argument_list|()
expr_stmt|;
operator|~
name|StringPool
argument_list|()
expr_stmt|;
comment|/// intern - Adds a string to the pool and returns a reference-counted
comment|/// pointer to it. No additional memory is allocated if the string already
comment|/// exists in the pool.
name|PooledStringPtr
name|intern
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
comment|/// empty - Checks whether the pool is empty. Returns true if so.
comment|///
specifier|inline
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|InternTable
operator|.
name|empty
argument_list|()
return|;
block|}
block|}
empty_stmt|;
comment|/// PooledStringPtr - A pointer to an interned string. Use operator bool to
comment|/// test whether the pointer is valid, and operator * to get the string if so.
comment|/// This is a lightweight value class with storage requirements equivalent to
comment|/// a single pointer, but it does have reference-counting overhead when
comment|/// copied.
name|class
name|PooledStringPtr
block|{
name|using
name|entry_t
init|=
name|StringPool
operator|::
name|entry_t
decl_stmt|;
name|entry_t
modifier|*
name|S
init|=
name|nullptr
decl_stmt|;
name|public
label|:
name|PooledStringPtr
argument_list|()
operator|=
expr|default
expr_stmt|;
name|explicit
name|PooledStringPtr
argument_list|(
name|entry_t
operator|*
name|E
argument_list|)
operator|:
name|S
argument_list|(
argument|E
argument_list|)
block|{
if|if
condition|(
name|S
condition|)
operator|++
name|S
operator|->
name|getValue
argument_list|()
operator|.
name|Refcount
expr_stmt|;
block|}
name|PooledStringPtr
argument_list|(
specifier|const
name|PooledStringPtr
operator|&
name|That
argument_list|)
operator|:
name|S
argument_list|(
argument|That.S
argument_list|)
block|{
if|if
condition|(
name|S
condition|)
operator|++
name|S
operator|->
name|getValue
argument_list|()
operator|.
name|Refcount
expr_stmt|;
block|}
name|PooledStringPtr
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PooledStringPtr
operator|&
name|That
operator|)
block|{
if|if
condition|(
name|S
operator|!=
name|That
operator|.
name|S
condition|)
block|{
name|clear
argument_list|()
expr_stmt|;
name|S
operator|=
name|That
operator|.
name|S
expr_stmt|;
if|if
condition|(
name|S
condition|)
operator|++
name|S
operator|->
name|getValue
argument_list|()
operator|.
name|Refcount
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
name|void
name|clear
parameter_list|()
block|{
if|if
condition|(
operator|!
name|S
condition|)
return|return;
if|if
condition|(
operator|--
name|S
operator|->
name|getValue
argument_list|()
operator|.
name|Refcount
operator|==
literal|0
condition|)
block|{
name|S
operator|->
name|getValue
argument_list|()
operator|.
name|Pool
operator|->
name|InternTable
operator|.
name|remove
argument_list|(
name|S
argument_list|)
expr_stmt|;
name|S
operator|->
name|Destroy
argument_list|()
expr_stmt|;
block|}
name|S
operator|=
name|nullptr
expr_stmt|;
block|}
operator|~
name|PooledStringPtr
argument_list|()
block|{
name|clear
argument_list|()
block|; }
specifier|inline
specifier|const
name|char
operator|*
name|begin
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|*
name|this
operator|&&
literal|"Attempt to dereference empty PooledStringPtr!"
argument_list|)
block|;
return|return
name|S
operator|->
name|getKeyData
argument_list|()
return|;
block|}
specifier|inline
specifier|const
name|char
operator|*
name|end
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|*
name|this
operator|&&
literal|"Attempt to dereference empty PooledStringPtr!"
argument_list|)
block|;
return|return
name|S
operator|->
name|getKeyData
argument_list|()
operator|+
name|S
operator|->
name|getKeyLength
argument_list|()
return|;
block|}
specifier|inline
name|unsigned
name|size
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|*
name|this
operator|&&
literal|"Attempt to dereference empty PooledStringPtr!"
argument_list|)
block|;
return|return
name|S
operator|->
name|getKeyLength
argument_list|()
return|;
block|}
specifier|inline
specifier|const
name|char
operator|*
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|S
operator|!=
name|nullptr
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|PooledStringPtr
operator|&
name|That
operator|)
specifier|const
block|{
return|return
name|S
operator|==
name|That
operator|.
name|S
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|PooledStringPtr
operator|&
name|That
operator|)
specifier|const
block|{
return|return
name|S
operator|!=
name|That
operator|.
name|S
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_STRINGPOOL_H
end_comment

end_unit

