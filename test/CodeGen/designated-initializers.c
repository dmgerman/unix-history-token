begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown %s -emit-llvm -o - | FileCheck %s
end_comment

begin_struct
struct|struct
name|foo
block|{
name|void
modifier|*
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: @u = global %union.anon zeroinitializer
end_comment

begin_union
union|union
block|{
name|int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
name|u
init|=
block|{ }
union|;
end_union

begin_comment
comment|// CHECK: @u2 = global { i32, [4 x i8] } { i32 0, [4 x i8] undef }
end_comment

begin_union
union|union
block|{
name|int
name|i
decl_stmt|;
name|double
name|f
decl_stmt|;
block|}
name|u2
init|=
block|{ }
union|;
end_union

begin_comment
comment|// CHECK: @u3 = global  %union.anon.1 zeroinitializer
end_comment

begin_union
union|union
block|{
name|double
name|f
decl_stmt|;
name|int
name|i
decl_stmt|;
block|}
name|u3
init|=
block|{ }
union|;
end_union

begin_comment
comment|// CHECK: @b = global [2 x i32] [i32 0, i32 22]
end_comment

begin_decl_stmt
name|int
name|b
index|[
literal|2
index|]
init|=
block|{
index|[
literal|1
index|]
operator|=
literal|22
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR6955
end_comment

begin_struct
struct|struct
name|ds
block|{
struct|struct
block|{
struct|struct
block|{
name|short
name|a
decl_stmt|;
block|}
struct|;
name|short
name|b
decl_stmt|;
struct|struct
block|{
name|short
name|c
decl_stmt|;
block|}
struct|;
block|}
struct|;
block|}
struct|;
end_struct

begin_comment
comment|// Traditional C anonymous member init
end_comment

begin_decl_stmt
name|struct
name|ds
name|ds0
init|=
block|{
block|{
block|{
operator|.
name|a
operator|=
literal|0
block|}
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// C1X lookup-based anonymous member init cases
end_comment

begin_decl_stmt
name|struct
name|ds
name|ds1
init|=
block|{
block|{
operator|.
name|a
operator|=
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ds
name|ds2
init|=
block|{
block|{
operator|.
name|b
operator|=
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ds
name|ds3
init|=
block|{
operator|.
name|a
operator|=
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @ds4 = global %struct.ds { %struct.anon.3 { %struct.anon zeroinitializer, i16 0, %struct.anon.2 { i16 1 } } }
end_comment

begin_decl_stmt
name|struct
name|ds
name|ds4
init|=
block|{
operator|.
name|c
operator|=
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ds
name|ds5
init|=
block|{
block|{
block|{
operator|.
name|a
operator|=
literal|0
block|}
block|}
block|,
operator|.
name|b
operator|=
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ds
name|ds6
init|=
block|{
block|{
operator|.
name|a
operator|=
literal|0
block|,
operator|.
name|b
operator|=
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @ds7 = global %struct.ds { %struct.anon.3 { %struct.anon { i16 2 }, i16 3, %struct.anon.2 zeroinitializer } }
end_comment

begin_decl_stmt
name|struct
name|ds
name|ds7
init|=
block|{
block|{
block|{
operator|.
name|a
operator|=
literal|1
block|}
block|}
block|,
operator|.
name|a
operator|=
literal|2
block|,
operator|.
name|b
operator|=
literal|3
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//<rdar://problem/10465114>
end_comment

begin_struct
struct|struct
name|overwrite_string_struct1
block|{
name|__typeof
argument_list|(
literal|L"foo"
argument|[
literal|0
argument|]
argument_list|)
name|L
index|[
literal|6
index|]
expr_stmt|;
name|int
name|M
decl_stmt|;
block|}
name|overwrite_string1
index|[]
init|=
block|{
block|{
block|{
literal|L"foo"
block|}
block|,
literal|1
block|}
block|,
index|[
literal|0
index|]
operator|.
name|L
index|[
literal|2
index|]
operator|=
literal|L'
expr|x'
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: [6 x i32] [i32 102, i32 111, i32 120, i32 0, i32 0, i32 0], i32 1
end_comment

begin_struct
struct|struct
name|overwrite_string_struct2
block|{
name|char
name|L
index|[
literal|6
index|]
decl_stmt|;
name|int
name|M
decl_stmt|;
block|}
name|overwrite_string2
index|[]
init|=
block|{
block|{
block|{
literal|"foo"
block|}
block|,
literal|1
block|}
block|,
index|[
literal|0
index|]
operator|.
name|L
index|[
literal|2
index|]
operator|=
literal|'x'
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: [6 x i8] c"fox\00\00\00", i32 1
end_comment

begin_struct
struct|struct
name|overwrite_string_struct3
block|{
name|char
name|L
index|[
literal|3
index|]
decl_stmt|;
name|int
name|M
decl_stmt|;
block|}
name|overwrite_string3
index|[]
init|=
block|{
block|{
block|{
literal|"foo"
block|}
block|,
literal|1
block|}
block|,
index|[
literal|0
index|]
operator|.
name|L
index|[
literal|2
index|]
operator|=
literal|'x'
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: [3 x i8] c"fox", i32 1
end_comment

begin_struct
struct|struct
name|overwrite_string_struct4
block|{
name|char
name|L
index|[
literal|3
index|]
decl_stmt|;
name|int
name|M
decl_stmt|;
block|}
name|overwrite_string4
index|[]
init|=
block|{
block|{
block|{
literal|"foobar"
block|}
block|,
literal|1
block|}
block|,
index|[
literal|0
index|]
operator|.
name|L
index|[
literal|2
index|]
operator|=
literal|'x'
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: [3 x i8] c"fox", i32 1
end_comment

begin_struct
struct|struct
name|overwrite_string_struct5
block|{
name|char
name|L
index|[
literal|6
index|]
decl_stmt|;
name|int
name|M
decl_stmt|;
block|}
name|overwrite_string5
index|[]
init|=
block|{
block|{
block|{
literal|"foo"
block|}
block|,
literal|1
block|}
block|,
index|[
literal|0
index|]
operator|.
name|L
index|[
literal|4
index|]
operator|=
literal|'y'
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: [6 x i8] c"foo\00y\00", i32 1
end_comment

begin_comment
comment|// CHECK: @u1 = {{.*}} { i32 65535 }
end_comment

begin_union
union|union
name|u_FFFF
block|{
name|char
name|c
decl_stmt|;
name|long
name|l
decl_stmt|;
block|}
name|u1
init|=
block|{
operator|.
name|l
operator|=
literal|0xFFFF
block|}
union|;
end_union

begin_comment
comment|/// PR16644
end_comment

begin_typedef
typedef|typedef
union|union
name|u_16644
block|{
struct|struct
name|s_16644
block|{
name|int
name|zero
decl_stmt|;
name|int
name|one
decl_stmt|;
name|int
name|two
decl_stmt|;
name|int
name|three
decl_stmt|;
block|}
name|a
struct|;
name|int
name|b
index|[
literal|4
index|]
decl_stmt|;
block|}
name|union_16644_t
typedef|;
end_typedef

begin_comment
comment|// CHECK: @union_16644_instance_0 = {{.*}} { i32 0, i32 0, i32 0, i32 3 } }
end_comment

begin_decl_stmt
name|union_16644_t
name|union_16644_instance_0
init|=
block|{
operator|.
name|b
index|[
literal|0
index|]
operator|=
literal|0
block|,
operator|.
name|a
operator|.
name|one
operator|=
literal|1
block|,
operator|.
name|b
index|[
literal|2
index|]
operator|=
literal|2
block|,
operator|.
name|a
operator|.
name|three
operator|=
literal|3
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @union_16644_instance_1 = {{.*}} [i32 10, i32 0, i32 0, i32 0]
end_comment

begin_decl_stmt
name|union_16644_t
name|union_16644_instance_1
init|=
block|{
operator|.
name|a
operator|.
name|three
operator|=
literal|13
block|,
operator|.
name|b
index|[
literal|2
index|]
operator|=
literal|12
block|,
operator|.
name|a
operator|.
name|one
operator|=
literal|11
block|,
operator|.
name|b
index|[
literal|0
index|]
operator|=
literal|10
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @union_16644_instance_2 = {{.*}} [i32 0, i32 20, i32 0, i32 0]
end_comment

begin_decl_stmt
name|union_16644_t
name|union_16644_instance_2
init|=
block|{
operator|.
name|a
operator|.
name|one
operator|=
literal|21
block|,
operator|.
name|b
index|[
literal|1
index|]
operator|=
literal|20
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @union_16644_instance_3 = {{.*}} { i32 0, i32 31, i32 0, i32 0 }
end_comment

begin_decl_stmt
name|union_16644_t
name|union_16644_instance_3
init|=
block|{
operator|.
name|b
index|[
literal|1
index|]
operator|=
literal|30
block|,
operator|.
name|a
operator|=
block|{
operator|.
name|one
operator|=
literal|31
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @union_16644_instance_4 = {{.*}} { i32 5, i32 2, i32 0, i32 0 } {{.*}} [i32 0, i32 4, i32 0, i32 0]
end_comment

begin_decl_stmt
name|union_16644_t
name|union_16644_instance_4
index|[
literal|2
index|]
init|=
block|{
index|[
literal|0
index|]
operator|.
name|a
operator|.
name|one
operator|=
literal|2
block|,
index|[
literal|1
index|]
operator|.
name|a
operator|.
name|zero
operator|=
literal|3
block|,
index|[
literal|0
index|]
operator|.
name|a
operator|.
name|zero
operator|=
literal|5
block|,
index|[
literal|1
index|]
operator|.
name|b
index|[
literal|1
index|]
operator|=
literal|4
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @lab = global { [4 x i8], i32 } { [4 x i8] undef, i32 123 }
end_comment

begin_struct
struct|struct
name|leading_anon_bitfield
block|{
name|int
label|:
literal|32
expr_stmt|;
name|int
name|n
decl_stmt|;
block|}
name|lab
init|=
block|{
operator|.
name|n
operator|=
literal|123
block|}
struct|;
end_struct

begin_function
name|void
name|test1
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
comment|// CHECK: internal global %struct.foo { i8* null, i32 1024 }
specifier|static
name|struct
name|foo
name|foo
init|=
block|{
operator|.
name|b
operator|=
literal|1024
block|,   }
decl_stmt|;
comment|// CHECK: bitcast %union.anon.4* %u2
comment|// CHECK: call void @llvm.memset
union|union
block|{
name|int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
name|u2
init|=
block|{ }
union|;
comment|// CHECK-NOT: call void @llvm.memset
union|union
block|{
name|int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
name|u3
union|;
comment|// CHECK: ret void
block|}
end_function

begin_comment
comment|// PR7151
end_comment

begin_struct
struct|struct
name|S
block|{
name|int
name|nkeys
decl_stmt|;
name|int
modifier|*
name|keys
decl_stmt|;
union|union
block|{
name|void
modifier|*
name|data
decl_stmt|;
block|}
union|;
block|}
struct|;
end_struct

begin_function
name|void
name|test2
parameter_list|()
block|{
name|struct
name|S
modifier|*
name|btkr
decl_stmt|;
operator|*
name|btkr
operator|=
operator|(
expr|struct
name|S
operator|)
block|{
operator|.
name|keys
operator|=
literal|0
block|,
block|{
operator|.
name|data
operator|=
literal|0
block|}
block|,   }
expr_stmt|;
block|}
end_function

end_unit

