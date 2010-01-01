begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin9 %s -emit-llvm -o - | FileCheck -check-prefix X32 %s
end_comment

begin_comment
comment|// CHECK-X32: %struct.menu = type<{ i8*, i8, i8 }>
end_comment

begin_comment
comment|// CHECK-X32: %union.command = type<{ i8*, [2 x i8] }>
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin9 %s -emit-llvm -o - | FileCheck -check-prefix X64 %s
end_comment

begin_comment
comment|// CHECK-X64: %struct.menu = type<{ i8*, i8, i8 }>
end_comment

begin_comment
comment|// CHECK-X64: %union.command = type<{ i8*, [2 x i8] }>
end_comment

begin_comment
comment|//<rdar://problem/7184250>
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|2
name|)
end_pragma

begin_typedef
typedef|typedef
union|union
name|command
block|{
name|void
modifier|*
name|windowRef
decl_stmt|;
struct|struct
name|menu
block|{
name|void
modifier|*
name|menuRef
decl_stmt|;
name|unsigned
name|char
name|menuItemIndex
decl_stmt|;
block|}
name|menu
struct|;
block|}
name|command
typedef|;
end_typedef

begin_decl_stmt
name|command
name|c
decl_stmt|;
end_decl_stmt

end_unit

