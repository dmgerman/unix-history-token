begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|void
modifier|*
name|FooToken
init|=
operator|&
name|FooToken
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
modifier|*
name|FooTable
index|[
literal|256
index|]
init|=
block|{
index|[
literal|0x3
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 1
index|[
literal|0x5b
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 2
index|[
literal|0x81
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 3
index|[
literal|0x42
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 4
index|[
literal|0xa2
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 5
index|[
literal|0xe
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 6
index|[
literal|0x20
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 7
index|[
literal|0xd7
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 8
index|[
literal|0x39
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 9
index|[
literal|0xf1
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 10
index|[
literal|0xa4
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 11
index|[
literal|0xa8
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 12
index|[
literal|0x21
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 13
index|[
literal|0x86
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 14
index|[
literal|0x1d
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 15
index|[
literal|0xdc
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 16
index|[
literal|0xa5
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 17
index|[
literal|0xef
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 18
index|[
literal|0x9
index|]
operator|=
operator|(
name|void
operator|*
index|[
literal|256
index|]
operator|)
block|{
comment|// 19
index|[
literal|0x34
index|]
operator|=
operator|&
name|FooToken
block|,                                                                             }
block|,                                                                         }
block|,                                                                     }
block|,                                                                 }
block|,                                                             }
block|,                                                         }
block|,                                                     }
block|,                                                 }
block|,                                             }
block|,                                         }
block|,                                     }
block|,                                 }
block|,                             }
block|,                         }
block|,                     }
block|,                 }
block|,             }
block|,         }
block|,     }
block|}
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|P1
block|{
struct|struct
name|Q1
block|{
name|char
name|a
index|[
literal|6
index|]
decl_stmt|;
name|char
name|b
index|[
literal|6
index|]
decl_stmt|;
block|}
name|q
struct|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|P1
name|l1
init|=
block|{
operator|(
expr|struct
name|Q1
operator|)
block|{
literal|"foo"
block|,
literal|"bar"
block|}
block|,
operator|.
name|q
operator|.
name|b
operator|=
block|{
literal|"boo"
block|}
block|,
operator|.
name|q
operator|.
name|b
operator|=
block|{
index|[
literal|1
index|]
operator|=
literal|'x'
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|Q1
modifier|*
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
name|struct
name|P1
name|test_foo
parameter_list|()
block|{
name|struct
name|P1
name|l
init|=
block|{
operator|*
name|foo
argument_list|()
block|,
operator|.
name|q
operator|.
name|b
operator|=
block|{
literal|"boo"
block|}
block|,
operator|.
name|q
operator|.
name|b
operator|=
block|{
index|[
literal|1
index|]
operator|=
literal|'x'
block|}
block|}
decl_stmt|;
return|return
name|l
return|;
block|}
end_function

end_unit

