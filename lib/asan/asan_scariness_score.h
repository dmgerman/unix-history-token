begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_scariness_score.h ----------------------------------*- C++ -*-===//
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
comment|// This file is a part of AddressSanitizer, an address sanity checker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Compute the level of scariness of the error message.
end_comment

begin_comment
comment|// Don't expect any deep science here, just a set of heuristics that suggest
end_comment

begin_comment
comment|// that e.g. 1-byte-read-global-buffer-overflow is less scary than
end_comment

begin_comment
comment|// 8-byte-write-stack-use-after-return.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Every error report has one or more features, such as memory access size,
end_comment

begin_comment
comment|// type (read or write), type of accessed memory (e.g. free-d heap, or a global
end_comment

begin_comment
comment|// redzone), etc. Every such feature has an int score and a string description.
end_comment

begin_comment
comment|// The overall score is the sum of all feature scores and the description
end_comment

begin_comment
comment|// is a concatenation of feature descriptions.
end_comment

begin_comment
comment|// Examples:
end_comment

begin_comment
comment|//  17 (4-byte-read-heap-buffer-overflow)
end_comment

begin_comment
comment|//  65 (multi-byte-write-stack-use-after-return)
end_comment

begin_comment
comment|//  10 (null-deref)
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
name|ASAN_SCARINESS_SCORE_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_SCARINESS_SCORE_H
end_define

begin_include
include|#
directive|include
file|"asan_flags.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_libc.h"
end_include

begin_decl_stmt
name|namespace
name|__asan
block|{
struct|struct
name|ScarinessScoreBase
block|{
name|void
name|Clear
parameter_list|()
block|{
name|descr
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|score
operator|=
literal|0
expr_stmt|;
block|}
name|void
name|Scare
parameter_list|(
name|int
name|add_to_score
parameter_list|,
specifier|const
name|char
modifier|*
name|reason
parameter_list|)
block|{
if|if
condition|(
name|descr
index|[
literal|0
index|]
condition|)
name|internal_strlcat
argument_list|(
name|descr
argument_list|,
literal|"-"
argument_list|,
sizeof|sizeof
argument_list|(
name|descr
argument_list|)
argument_list|)
expr_stmt|;
name|internal_strlcat
argument_list|(
name|descr
argument_list|,
name|reason
argument_list|,
sizeof|sizeof
argument_list|(
name|descr
argument_list|)
argument_list|)
expr_stmt|;
name|score
operator|+=
name|add_to_score
expr_stmt|;
block|}
empty_stmt|;
name|int
name|GetScore
argument_list|()
specifier|const
block|{
return|return
name|score
return|;
block|}
specifier|const
name|char
operator|*
name|GetDescription
argument_list|()
specifier|const
block|{
return|return
name|descr
return|;
block|}
name|void
name|Print
parameter_list|()
block|{
if|if
condition|(
name|score
operator|&&
name|flags
argument_list|()
operator|->
name|print_scariness
condition|)
name|Printf
argument_list|(
literal|"SCARINESS: %d (%s)\n"
argument_list|,
name|score
argument_list|,
name|descr
argument_list|)
expr_stmt|;
block|}
specifier|static
name|void
name|PrintSimple
parameter_list|(
name|int
name|score
parameter_list|,
specifier|const
name|char
modifier|*
name|descr
parameter_list|)
block|{
name|ScarinessScoreBase
name|SSB
decl_stmt|;
name|SSB
operator|.
name|Clear
argument_list|()
expr_stmt|;
name|SSB
operator|.
name|Scare
argument_list|(
name|score
argument_list|,
name|descr
argument_list|)
expr_stmt|;
name|SSB
operator|.
name|Print
argument_list|()
expr_stmt|;
block|}
name|private
label|:
name|int
name|score
decl_stmt|;
name|char
name|descr
index|[
literal|1024
index|]
decl_stmt|;
block|}
struct|;
name|struct
name|ScarinessScore
range|:
name|ScarinessScoreBase
block|{
name|ScarinessScore
argument_list|()
block|{
name|Clear
argument_list|()
block|;   }
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __asan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_SCARINESS_SCORE_H
end_comment

end_unit

