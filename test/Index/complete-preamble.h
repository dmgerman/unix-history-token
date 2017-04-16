begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|push
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Weverything"
end_pragma

begin_decl_stmt
name|namespace
name|std
block|{
name|void
name|wibble
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
end_pragma

begin_decl_stmt
name|namespace
name|std
block|{ }
end_decl_stmt

end_unit

