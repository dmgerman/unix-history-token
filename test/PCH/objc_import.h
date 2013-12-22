begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* For use with the objc_import.m test */
end_comment

begin_expr_stmt
unit|@
name|interface
name|TestPCH
operator|+
name|alloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|instMethod
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|class
name|NewID1
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|@
name|compatibility_alias
name|OldID1
name|NewID1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|class
name|OldID1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|class
name|OldID1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|class
name|NewID2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|compatibility_alias
name|OldID2
name|NewID2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|class
name|OldID2
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|@
name|interface
name|OldID2
operator|-
operator|(
name|void
operator|)
name|meth
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

