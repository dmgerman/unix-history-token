begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple x86_64-apple-darwin10 -emit-llvm %s -o %t
end_comment

begin_comment
comment|// RUN: grep "struct._attrs = type<{ i32, i8 }>" %t
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_attrs
block|{
name|unsigned
name|file_attributes
decl_stmt|;
name|unsigned
name|char
name|filename_length
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|__packed__
typedef|))
name|attrs
typedef|;
end_typedef

begin_comment
comment|// RUN: grep "union._attr_union = type<{ i32, i8 }>" %t
end_comment

begin_typedef
typedef|typedef
union|union
name|_attr_union
block|{
name|attrs
name|file_attrs
decl_stmt|;
name|unsigned
name|owner_id
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|__packed__
typedef|))
name|attr_union
typedef|;
end_typedef

begin_decl_stmt
name|attr_union
name|u
decl_stmt|;
end_decl_stmt

end_unit

