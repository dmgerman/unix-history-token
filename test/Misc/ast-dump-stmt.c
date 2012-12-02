begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ast-dump -ast-dump-filter Test %s | FileCheck -strict-whitespace %s
end_comment

begin_decl_stmt
name|int
name|TestLocation
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:      Dumping TestLocation
end_comment

begin_comment
comment|// CHECK-NEXT:   IntegerLiteral 0x{{[^ ]*}}<{{.*}}:3:20> 'int' 0
end_comment

begin_decl_stmt
name|int
name|TestIndent
init|=
literal|1
operator|+
operator|(
literal|1
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:      Dumping TestIndent
end_comment

begin_comment
comment|// CHECK-NEXT: {{\(BinaryOperator[^()]*$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^  \(IntegerLiteral.*0[^()]*\)$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^  \(ParenExpr.*0[^()]*$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^    \(IntegerLiteral.*0[^()]*\)\)\)$}}
end_comment

begin_function
name|void
name|TestDeclStmt
parameter_list|()
block|{
name|int
name|x
init|=
literal|0
decl_stmt|;
name|int
name|y
decl_stmt|,
name|z
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK:      Dumping TestDeclStmt
end_comment

begin_comment
comment|// CHECK-NEXT: CompoundStmt
end_comment

begin_comment
comment|// CHECK-NEXT:   DeclStmt
end_comment

begin_comment
comment|// CHECK-NEXT:     int x =
end_comment

begin_comment
comment|// CHECK-NEXT:       IntegerLiteral
end_comment

begin_comment
comment|// CHECK-NEXT:   DeclStmt
end_comment

begin_comment
comment|// CHECK-NEXT:     int y
end_comment

begin_comment
comment|// CHECK-NEXT:     int z
end_comment

begin_decl_stmt
name|int
name|TestOpaqueValueExpr
init|=
literal|0
condition|?
else|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:      Dumping TestOpaqueValueExpr
end_comment

begin_comment
comment|// CHECK-NEXT: BinaryConditionalOperator
end_comment

begin_comment
comment|// CHECK-NEXT:   IntegerLiteral
end_comment

begin_comment
comment|// CHECK-NEXT:   OpaqueValueExpr
end_comment

begin_comment
comment|// CHECK-NEXT:     IntegerLiteral
end_comment

begin_comment
comment|// CHECK-NEXT:   OpaqueValueExpr
end_comment

begin_comment
comment|// CHECK-NEXT:     IntegerLiteral
end_comment

begin_comment
comment|// CHECK-NEXT:   IntegerLiteral
end_comment

end_unit

