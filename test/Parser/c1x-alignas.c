begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c1x -fsyntax-only -verify %s
end_comment

begin_decl_stmt
alignas|_Alignas
argument_list|(
literal|4
argument_list|)
name|char
name|c1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
alignas|_Alignas
argument_list|(
name|long
argument_list|)
name|char
name|c2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
alignas|_Alignas
argument_list|(
literal|16
argument_list|)
name|c3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|c4
decl|_Alignas
argument_list|(
literal|32
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{expected ';' after top level declarator}}
end_comment

end_unit

