begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o %t
end_comment

begin_struct
struct|struct
name|test
block|{
name|unsigned
name|a
range|:
literal|1
decl_stmt|;
name|unsigned
name|b
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|test
modifier|*
name|t
decl_stmt|;
end_decl_stmt

end_unit

