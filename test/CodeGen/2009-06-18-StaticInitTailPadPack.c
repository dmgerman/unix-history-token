begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_comment
comment|// rdar://6983634
end_comment

begin_typedef
typedef|typedef
name|struct
name|A
modifier|*
name|Foo
typedef|;
end_typedef

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

begin_struct
struct|struct
name|Bar
block|{
name|Foo
name|f1
decl_stmt|;
name|unsigned
name|short
name|f2
decl_stmt|;
name|float
name|f3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Baz
block|{
name|struct
name|Bar
name|f1
decl_stmt|;
name|struct
name|Bar
name|f2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Qux
block|{
name|unsigned
name|long
name|f1
decl_stmt|;
name|struct
name|Baz
name|f2
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|Qux
name|Bork
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|struct
name|Qux
name|Bork
init|=
block|{
literal|0
block|,
block|{
block|{
literal|0
block|}
block|,
block|{
literal|0
block|}
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

