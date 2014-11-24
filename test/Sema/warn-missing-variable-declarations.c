begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Wmissing-variable-declarations -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|int
name|vbad1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{no previous extern declaration for non-static variable 'vbad1'}}
end_comment

begin_decl_stmt
name|int
name|vbad2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vbad2
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{no previous extern declaration for non-static variable 'vbad2'}}
end_comment

begin_struct
struct|struct
block|{
name|int
name|mgood1
decl_stmt|;
block|}
name|vbad3
struct|;
end_struct

begin_comment
comment|// expected-warning{{no previous extern declaration for non-static variable 'vbad3'}}
end_comment

begin_decl_stmt
name|int
name|vbad4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vbad4
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{no previous extern declaration for non-static variable 'vbad4'}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vbad4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vgood1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vgood1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vgood1
init|=
literal|10
decl_stmt|;
end_decl_stmt

end_unit

