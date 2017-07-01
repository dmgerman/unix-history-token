begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -test-print-linkage-source %s | FileCheck %s
end_comment

begin_enum
enum|enum
name|Baz
block|{
name|Qux
init|=
literal|0
block|}
enum|;
end_enum

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|int
name|w
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar
parameter_list|(
name|int
name|y
parameter_list|)
block|{
specifier|static
name|int
name|z
decl_stmt|;
name|int
name|k
decl_stmt|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|wibble
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ena
parameter_list|(
name|int
function_decl|(
modifier|*
name|dio
function_decl|)
parameter_list|(
name|int
name|tria
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|int
name|test2
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f16
parameter_list|(
name|void
parameter_list|)
block|{
specifier|extern
name|int
name|test2
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: EnumDecl=Baz:3:6 (Definition)linkage=External
end_comment

begin_comment
comment|// CHECK: EnumConstantDecl=Qux:3:12 (Definition)linkage=NoLinkage
end_comment

begin_comment
comment|// CHECK: VarDecl=x:4:5linkage=External
end_comment

begin_comment
comment|// CHECK: FunctionDecl=foo:5:6linkage=External
end_comment

begin_comment
comment|// CHECK: VarDecl=w:6:12linkage=Internal
end_comment

begin_comment
comment|// CHECK: FunctionDecl=bar:7:6 (Definition)linkage=External
end_comment

begin_comment
comment|// CHECK: ParmDecl=y:7:14 (Definition)linkage=NoLinkage
end_comment

begin_comment
comment|// CHECK: VarDecl=z:8:14 (Definition)linkage=NoLinkage
end_comment

begin_comment
comment|// CHECK: VarDecl=k:9:7 (Definition)linkage=NoLinkage
end_comment

begin_comment
comment|// CHECK: VarDecl=n:11:12linkage=External
end_comment

begin_comment
comment|// CHECK: FunctionDecl=wibble:12:12linkage=Internal
end_comment

begin_comment
comment|// CHECK: ParmDecl=:12:22 (Definition)linkage=NoLinkage
end_comment

begin_comment
comment|// CHECK: FunctionDecl=ena:14:6linkage=External
end_comment

begin_comment
comment|// CHECK: ParmDecl=dio:14:16 (Definition)linkage=NoLinkage
end_comment

begin_comment
comment|// CHECK: ParmDecl=tria:14:25 (Definition)linkage=NoLinkage
end_comment

begin_comment
comment|// CHECK: VarDecl=test2{{.*}}linkage=Internal
end_comment

begin_comment
comment|// CHECK: VarDecl=test2{{.*}}linkage=Internal
end_comment

end_unit

