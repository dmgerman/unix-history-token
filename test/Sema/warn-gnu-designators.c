begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Wno-gnu-designator -verify %s
end_comment

begin_struct
struct|struct
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
index|[
literal|12
index|]
decl_stmt|;
block|}
name|value
init|=
block|{
name|x
operator|:
literal|17
block|,
operator|.
name|z
index|[
literal|3
operator|...
literal|5
index|]
operator|=
literal|7
block|}
struct|;
end_struct

end_unit

