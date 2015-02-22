begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_suppressions.h --------------------------------*- C++ -*-===//
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
comment|// Suppression parsing/matching code.
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
name|SANITIZER_SUPPRESSIONS_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_SUPPRESSIONS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
struct|struct
name|Suppression
block|{
specifier|const
name|char
modifier|*
name|type
decl_stmt|;
name|char
modifier|*
name|templ
decl_stmt|;
name|unsigned
name|hit_count
decl_stmt|;
name|uptr
name|weight
decl_stmt|;
block|}
struct|;
name|class
name|SuppressionContext
block|{
name|public
label|:
comment|// Create new SuppressionContext capable of parsing given suppression types.
name|SuppressionContext
argument_list|(
argument|const char *supprression_types[]
argument_list|,
argument|int suppression_types_num
argument_list|)
empty_stmt|;
name|void
name|ParseFromFile
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
name|void
name|Parse
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
name|bool
name|Match
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
name|Suppression
modifier|*
modifier|*
name|s
parameter_list|)
function_decl|;
name|uptr
name|SuppressionCount
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|HasSuppressionType
argument_list|(
specifier|const
name|char
operator|*
name|type
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|Suppression
modifier|*
name|SuppressionAt
argument_list|(
name|uptr
name|i
argument_list|)
decl|const
decl_stmt|;
name|void
name|GetMatched
argument_list|(
name|InternalMmapVector
operator|<
name|Suppression
operator|*
operator|>
operator|*
name|matched
argument_list|)
decl_stmt|;
name|private
label|:
specifier|static
specifier|const
name|int
name|kMaxSuppressionTypes
init|=
literal|16
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
specifier|const
name|suppression_types_
decl_stmt|;
specifier|const
name|int
name|suppression_types_num_
decl_stmt|;
name|InternalMmapVector
operator|<
name|Suppression
operator|>
name|suppressions_
expr_stmt|;
name|bool
name|has_suppression_type_
index|[
name|kMaxSuppressionTypes
index|]
decl_stmt|;
name|bool
name|can_parse_
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_SUPPRESSIONS_H
end_comment

end_unit

