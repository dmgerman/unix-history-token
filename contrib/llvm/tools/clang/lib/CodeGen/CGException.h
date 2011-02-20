begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CGException.h - Classes for exceptions IR generation ----*- C++ -*-===//
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
comment|// These classes support the generation of LLVM IR for exceptions in
end_comment

begin_comment
comment|// C++ and Objective C.
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
name|CLANG_CODEGEN_CGEXCEPTION_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CGEXCEPTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|LangOptions
decl_stmt|;
name|namespace
name|CodeGen
block|{
comment|/// The exceptions personality for a function.  When
name|class
name|EHPersonality
block|{
name|llvm
operator|::
name|StringRef
name|PersonalityFn
expr_stmt|;
comment|// If this is non-null, this personality requires a non-standard
comment|// function for rethrowing an exception after a catchall cleanup.
comment|// This function must have prototype void(void*).
name|llvm
operator|::
name|StringRef
name|CatchallRethrowFn
expr_stmt|;
name|EHPersonality
argument_list|(
argument|llvm::StringRef PersonalityFn
argument_list|,
argument|llvm::StringRef CatchallRethrowFn = llvm::StringRef()
argument_list|)
block|:
name|PersonalityFn
argument_list|(
name|PersonalityFn
argument_list|)
operator|,
name|CatchallRethrowFn
argument_list|(
argument|CatchallRethrowFn
argument_list|)
block|{}
name|public
operator|:
specifier|static
specifier|const
name|EHPersonality
operator|&
name|get
argument_list|(
specifier|const
name|LangOptions
operator|&
name|Lang
argument_list|)
expr_stmt|;
specifier|static
specifier|const
name|EHPersonality
name|GNU_C
decl_stmt|;
specifier|static
specifier|const
name|EHPersonality
name|GNU_C_SJLJ
decl_stmt|;
specifier|static
specifier|const
name|EHPersonality
name|GNU_ObjC
decl_stmt|;
specifier|static
specifier|const
name|EHPersonality
name|NeXT_ObjC
decl_stmt|;
specifier|static
specifier|const
name|EHPersonality
name|GNU_CPlusPlus
decl_stmt|;
specifier|static
specifier|const
name|EHPersonality
name|GNU_CPlusPlus_SJLJ
decl_stmt|;
name|llvm
operator|::
name|StringRef
name|getPersonalityFnName
argument_list|()
specifier|const
block|{
return|return
name|PersonalityFn
return|;
block|}
name|llvm
operator|::
name|StringRef
name|getCatchallRethrowFnName
argument_list|()
specifier|const
block|{
return|return
name|CatchallRethrowFn
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

