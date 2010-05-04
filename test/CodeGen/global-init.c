begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - -triple i386-linux-gnu %s | FileCheck %s
end_comment

begin_comment
comment|// This checks that the global won't be marked as common.
end_comment

begin_comment
comment|// (It shouldn't because it's being initialized).
end_comment

begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|a
init|=
literal|242
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @a = global i32 242
end_comment

begin_comment
comment|// This should get normal weak linkage.
end_comment

begin_decl_stmt
name|int
name|c
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @c = weak global i32 0
end_comment

begin_comment
comment|// Since this is marked const, it should get weak_odr linkage, since all
end_comment

begin_comment
comment|// definitions have to be the same.
end_comment

begin_comment
comment|// CHECK: @d = weak_odr constant i32 0
end_comment

begin_decl_stmt
specifier|const
name|int
name|d
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR6168 "too many undefs"
end_comment

begin_struct
struct|struct
name|ManyFields
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
name|int
name|c
decl_stmt|;
name|char
name|d
decl_stmt|;
name|int
name|e
decl_stmt|;
name|int
name|f
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: global %0 { i32 1, i32 2, i32 0, i8 0, i32 0, i32 0 }
end_comment

begin_decl_stmt
name|struct
name|ManyFields
name|FewInits
init|=
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR6766
end_comment

begin_comment
comment|// CHECK: @l = global %1 { [24 x i8] c"f\00\00\00o\00\00\00o\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00", i32 1 }
end_comment

begin_typedef
typedef|typedef
name|__WCHAR_TYPE__
name|wchar_t
typedef|;
end_typedef

begin_struct
struct|struct
name|K
block|{
name|wchar_t
name|L
index|[
literal|6
index|]
decl_stmt|;
name|int
name|M
decl_stmt|;
block|}
name|l
init|=
block|{
block|{
literal|L"foo"
block|}
block|,
literal|1
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: @yuv_types = global [4 x [6 x i8]] {{\[}}[6 x i8] c"4:0:0\00", [6 x i8] c"4:2:0\00", [6 x i8] c"4:2:2\00", [6 x i8] c"4:4:4\00"]
end_comment

begin_decl_stmt
name|char
name|yuv_types
index|[
literal|4
index|]
index|[
literal|6
index|]
init|=
block|{
literal|"4:0:0"
block|,
literal|"4:2:0"
block|,
literal|"4:2:2"
block|,
literal|"4:4:4"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// NOTE: tentative definitions are processed at the end of the translation unit.
end_comment

begin_comment
comment|// This shouldn't be emitted as common because it has an explicit section.
end_comment

begin_comment
comment|// rdar://7119244
end_comment

begin_comment
comment|// CHECK: @b = global i32 0, section "foo"
end_comment

begin_decl_stmt
name|int
name|b
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|"foo"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

