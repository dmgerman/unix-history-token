begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetLibraryInfo.h - Library information ---*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TARGET_TARGETLIBRARYINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETLIBRARYINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Triple
decl_stmt|;
name|namespace
name|LibFunc
block|{
enum|enum
name|Func
block|{
comment|/// void *memset(void *b, int c, size_t len);
name|memset
block|,
comment|// void *memcpy(void *s1, const void *s2, size_t n);
name|memcpy
block|,
comment|// void *memmove(void *s1, const void *s2, size_t n);
name|memmove
block|,
comment|/// void memset_pattern16(void *b, const void *pattern16, size_t len);
name|memset_pattern16
block|,
comment|/// int iprintf(const char *format, ...);
name|iprintf
block|,
comment|/// int siprintf(char *str, const char *format, ...);
name|siprintf
block|,
comment|/// int fiprintf(FILE *stream, const char *format, ...);
name|fiprintf
block|,
name|NumLibFuncs
block|}
enum|;
block|}
comment|/// TargetLibraryInfo - This immutable pass captures information about what
comment|/// library functions are available for the current target, and allows a
comment|/// frontend to disable optimizations through -fno-builtin etc.
name|class
name|TargetLibraryInfo
range|:
name|public
name|ImmutablePass
block|{
name|unsigned
name|char
name|AvailableArray
index|[
operator|(
name|LibFunc
operator|::
name|NumLibFuncs
operator|+
literal|7
operator|)
operator|/
literal|8
index|]
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|TargetLibraryInfo
argument_list|()
block|;
name|TargetLibraryInfo
argument_list|(
specifier|const
name|Triple
operator|&
name|T
argument_list|)
block|;
comment|/// has - This function is used by optimizations that want to match on or form
comment|/// a given library function.
name|bool
name|has
argument_list|(
argument|LibFunc::Func F
argument_list|)
specifier|const
block|{
return|return
operator|(
name|AvailableArray
index|[
name|F
operator|/
literal|8
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|F
operator|&
literal|7
operator|)
operator|)
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// setUnavailable - this can be used by whatever sets up TargetLibraryInfo to
comment|/// ban use of specific library functions.
name|void
name|setUnavailable
argument_list|(
argument|LibFunc::Func F
argument_list|)
block|{
name|AvailableArray
index|[
name|F
operator|/
literal|8
index|]
operator|&=
operator|~
operator|(
literal|1
operator|<<
operator|(
name|F
operator|&
literal|7
operator|)
operator|)
block|;   }
name|void
name|setAvailable
argument_list|(
argument|LibFunc::Func F
argument_list|)
block|{
name|AvailableArray
index|[
name|F
operator|/
literal|8
index|]
operator||=
literal|1
operator|<<
operator|(
name|F
operator|&
literal|7
operator|)
block|;   }
comment|/// disableAllFunctions - This disables all builtins, which is used for
comment|/// options like -fno-builtin.
name|void
name|disableAllFunctions
argument_list|()
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

