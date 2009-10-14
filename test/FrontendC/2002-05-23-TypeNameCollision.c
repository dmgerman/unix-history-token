begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|/* Testcase for when struct tag conflicts with typedef name... grr */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|foo
block|{
name|struct
name|foo
modifier|*
name|X
decl_stmt|;
name|int
name|Y
decl_stmt|;
block|}
typedef|*
name|foo
typedef|;
end_typedef

begin_decl_stmt
name|foo
name|F1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|foo
modifier|*
name|F2
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|bar
block|{
name|test1
block|,
name|test2
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|float
name|bar
typedef|;
end_typedef

begin_decl_stmt
name|enum
name|bar
name|B1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bar
name|B2
decl_stmt|;
end_decl_stmt

end_unit

