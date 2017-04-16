begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=debug.AnalysisOrder -analyzer-config debug.AnalysisOrder:PreStmtCastExpr=true,debug.AnalysisOrder:PostStmtCastExpr=true %s 2>&1 | FileCheck %s
end_comment

begin_function
name|void
name|test
parameter_list|(
name|char
name|c
parameter_list|)
block|{
name|int
name|i
init|=
operator|(
name|int
operator|)
name|c
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: PreStmt<CastExpr> (Kind : LValueToRValue)
end_comment

begin_comment
comment|// CHECK-NEXT: PostStmt<CastExpr> (Kind : LValueToRValue)
end_comment

begin_comment
comment|// CHECK-NEXT: PreStmt<CastExpr> (Kind : IntegralCast)
end_comment

begin_comment
comment|// CHECK-NEXT: PostStmt<CastExpr> (Kind : IntegralCast)
end_comment

end_unit

