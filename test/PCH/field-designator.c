begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -include %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-pch -o %t.pch
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -include-pch %t.pch
end_comment

begin_comment
comment|// rdar://12239321 Make sure we don't emit a bogus
end_comment

begin_comment
comment|//     error: field designator 'e' does not refer to a non-static data member
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER
end_ifndef

begin_define
define|#
directive|define
name|HEADER
end_define

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_struct
struct|struct
name|U
block|{
union|union
block|{
struct|struct
block|{
name|int
name|e
decl_stmt|;
name|int
name|f
decl_stmt|;
block|}
struct|;
name|int
name|a
decl_stmt|;
block|}
union|;
block|}
struct|;
end_struct

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HEADER
argument_list|)
end_if

begin_error
error|#
directive|error
error|Header inclusion order messed up
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_function
name|void
name|bar
parameter_list|()
block|{
specifier|static
specifier|const
name|struct
name|U
name|plan
init|=
block|{
operator|.
name|e
operator|=
literal|1
block|}
decl_stmt|;
block|}
end_function

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

