begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wassign-enum %s
end_comment

begin_comment
comment|// rdar://11824807
end_comment

begin_typedef
typedef|typedef
enum|enum
name|CCTestEnum
block|{
name|One
block|,
name|Two
init|=
literal|4
block|,
name|Three
block|}
name|CCTestEnum
typedef|;
end_typedef

begin_decl_stmt
name|CCTestEnum
name|test
init|=
literal|50
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{integer constant not in range of enumerated type 'CCTestEnum'}}
end_comment

begin_decl_stmt
name|CCTestEnum
name|test1
init|=
operator|-
literal|50
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{integer constant not in range of enumerated type 'CCTestEnum'}}
end_comment

begin_comment
comment|// Explicit cast should silence the warning.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|CCTestEnum
name|SilenceWithCast1
init|=
literal|51
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{integer constant not in range of enumerated type 'CCTestEnum'}}
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|CCTestEnum
name|SilenceWithCast2
init|=
operator|(
name|CCTestEnum
operator|)
literal|51
decl_stmt|;
end_decl_stmt

begin_comment
comment|// no-warning
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|CCTestEnum
name|SilenceWithCast3
init|=
operator|(
specifier|const
name|CCTestEnum
operator|)
literal|51
decl_stmt|;
end_decl_stmt

begin_comment
comment|// no-warning
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|CCTestEnum
name|SilenceWithCast4
init|=
operator|(
specifier|const
specifier|volatile
name|CCTestEnum
operator|)
literal|51
decl_stmt|;
end_decl_stmt

begin_comment
comment|// no-warning
end_comment

begin_function
name|void
name|SilenceWithCastLocalVar
parameter_list|()
block|{
name|CCTestEnum
name|SilenceWithCast1
init|=
literal|51
decl_stmt|;
comment|// expected-warning {{integer constant not in range of enumerated type 'CCTestEnum'}}
name|CCTestEnum
name|SilenceWithCast2
init|=
operator|(
name|CCTestEnum
operator|)
literal|51
decl_stmt|;
comment|// no-warning
name|CCTestEnum
name|SilenceWithCast3
init|=
operator|(
specifier|const
name|CCTestEnum
operator|)
literal|51
decl_stmt|;
comment|// no-warning
name|CCTestEnum
name|SilenceWithCast4
init|=
operator|(
specifier|const
specifier|volatile
name|CCTestEnum
operator|)
literal|51
decl_stmt|;
comment|// no-warning
specifier|const
name|CCTestEnum
name|SilenceWithCast1c
init|=
literal|51
decl_stmt|;
comment|// expected-warning {{integer constant not in range of enumerated type 'CCTestEnum'}}
specifier|const
name|CCTestEnum
name|SilenceWithCast2c
init|=
operator|(
name|CCTestEnum
operator|)
literal|51
decl_stmt|;
comment|// no-warning
specifier|const
name|CCTestEnum
name|SilenceWithCast3c
init|=
operator|(
specifier|const
name|CCTestEnum
operator|)
literal|51
decl_stmt|;
comment|// no-warning
specifier|const
name|CCTestEnum
name|SilenceWithCast4c
init|=
operator|(
specifier|const
specifier|volatile
name|CCTestEnum
operator|)
literal|51
decl_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|CCTestEnum
name|foo
parameter_list|(
name|CCTestEnum
name|r
parameter_list|)
block|{
return|return
literal|20
return|;
comment|// expected-warning {{integer constant not in range of enumerated type 'CCTestEnum'}}
block|}
end_function

begin_enum
enum|enum
name|Test2
block|{
name|K_zero
block|,
name|K_one
block|}
enum|;
end_enum

begin_function
name|enum
name|Test2
name|test2
parameter_list|(
name|enum
name|Test2
modifier|*
name|t
parameter_list|)
block|{
operator|*
name|t
operator|=
literal|20
expr_stmt|;
comment|// expected-warning {{integer constant not in range of enumerated type 'enum Test2'}}
return|return
literal|10
return|;
comment|// expected-warning {{integer constant not in range of enumerated type 'enum Test2'}}
block|}
end_function

begin_comment
comment|// PR15069
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|a
init|=
literal|0
block|}
name|T
typedef|;
end_typedef

begin_function
name|void
name|f
parameter_list|()
block|{
name|T
name|x
init|=
name|a
decl_stmt|;
name|x
operator|+=
literal|1
expr_stmt|;
comment|// expected-warning {{integer constant not in range of enumerated type}}
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|CCTestEnum
name|test
init|=
literal|1
decl_stmt|;
comment|// expected-warning {{integer constant not in range of enumerated type 'CCTestEnum'}}
name|test
operator|=
literal|600
expr_stmt|;
comment|// expected-warning {{integer constant not in range of enumerated type 'CCTestEnum'}}
name|foo
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning {{integer constant not in range of enumerated type 'CCTestEnum'}}
name|foo
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning {{integer constant not in range of enumerated type 'CCTestEnum'}}
name|foo
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|foo
argument_list|(
name|Two
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

