begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc --emit-llvm -o %t %s&&
end_comment

begin_comment
comment|// RUN: grep "i8 52" %t | count 1
end_comment

begin_struct
struct|struct
name|et7
block|{
name|float
name|lv7
index|[
literal|0
index|]
decl_stmt|;
name|char
name|mv7
range|:
literal|6
decl_stmt|;
block|}
name|yv7
init|=
block|{
block|{}
block|,
literal|52
block|,  }
struct|;
end_struct

end_unit

