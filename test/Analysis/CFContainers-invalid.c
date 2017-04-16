begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=osx.coreFoundation.containers.PointerSizedValues -triple x86_64-apple-darwin -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_typedef
typedef|typedef
specifier|const
name|struct
name|__CFAllocator
modifier|*
name|CFAllocatorRef
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|__CFArray
modifier|*
name|CFArrayRef
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|__CFDictionary
modifier|*
name|CFDictionaryRef
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|__CFSet
modifier|*
name|CFSetRef
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|CFAllocatorRef
name|kCFAllocatorDefault
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Unexpected declarations for these:
end_comment

begin_function_decl
name|CFArrayRef
name|CFArrayCreate
parameter_list|(
name|CFAllocatorRef
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CFDictionaryRef
name|CFDictionaryCreate
parameter_list|(
name|CFAllocatorRef
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CFSetRef
name|CFSetCreate
parameter_list|(
name|CFAllocatorRef
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|testNoCrash
parameter_list|()
block|{
operator|(
name|void
operator|)
name|CFArrayCreate
argument_list|(
name|kCFAllocatorDefault
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|CFDictionaryCreate
argument_list|(
name|kCFAllocatorDefault
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|CFSetCreate
argument_list|(
name|kCFAllocatorDefault
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

