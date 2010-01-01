begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown %s -emit-llvm -o %t
end_comment

begin_comment
comment|// RUN: grep "struct.object_entry = type { i8, \[2 x i8\], i8 }" %t
end_comment

begin_struct
struct|struct
name|object_entry
block|{
name|unsigned
name|int
name|type
range|:
literal|3
decl_stmt|,
name|pack_id
range|:
literal|16
decl_stmt|,
name|depth
range|:
literal|13
decl_stmt|;
block|}
name|entries
struct|;
end_struct

end_unit

