begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -g< %s | grep DW_TAG_member
end_comment

begin_struct
struct|struct
name|A
block|{
name|int
name|x
decl_stmt|;
block|}
name|a
struct|;
end_struct

end_unit

