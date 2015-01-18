begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== StoreRef.h - Smart pointer for store objects ---------------*- C++ -*--==//
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
comment|//  This file defined the type StoreRef.
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
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_STOREREF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_STOREREF_H
end_define

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
comment|/// Store - This opaque type encapsulates an immutable mapping from
comment|///  locations to values.  At a high-level, it represents the symbolic
comment|///  memory model.  Different subclasses of StoreManager may choose
comment|///  different types to represent the locations and values.
typedef|typedef
specifier|const
name|void
modifier|*
name|Store
typedef|;
name|class
name|StoreManager
decl_stmt|;
name|class
name|StoreRef
block|{
name|Store
name|store
decl_stmt|;
name|StoreManager
modifier|&
name|mgr
decl_stmt|;
name|public
label|:
name|StoreRef
argument_list|(
name|Store
argument_list|,
name|StoreManager
operator|&
argument_list|)
expr_stmt|;
name|StoreRef
argument_list|(
specifier|const
name|StoreRef
operator|&
argument_list|)
expr_stmt|;
name|StoreRef
modifier|&
name|operator
init|=
operator|(
name|StoreRef
specifier|const
operator|&
operator|)
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|StoreRef
operator|&
name|x
operator|)
specifier|const
block|{
name|assert
argument_list|(
operator|&
name|mgr
operator|==
operator|&
name|x
operator|.
name|mgr
argument_list|)
block|;
return|return
name|x
operator|.
name|store
operator|==
name|store
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|StoreRef
operator|&
name|x
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|x
operator|)
return|;
block|}
operator|~
name|StoreRef
argument_list|()
expr_stmt|;
name|Store
name|getStore
argument_list|()
specifier|const
block|{
return|return
name|store
return|;
block|}
specifier|const
name|StoreManager
operator|&
name|getStoreManager
argument_list|()
specifier|const
block|{
return|return
name|mgr
return|;
block|}
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

