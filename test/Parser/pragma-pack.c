begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Note that this puts the expected lines before the directives to work around
end_comment

begin_comment
comment|// limitations in the -verify mode.
end_comment

begin_comment
comment|/* expected-warning {{missing '(' after '#pragma pack'}}*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|10
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|8
name|)
end_pragma

begin_comment
comment|/*expected-warning {{unknown action for '#pragma pack'}}*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|hello
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_comment
comment|/* expected-warning {{expected integer or identifier in '#pragma pack'}}*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|)
end_pragma

begin_comment
comment|/* expected-warning {{expected integer or identifier in '#pragma pack'}}*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|)
end_pragma

begin_comment
comment|/* expected-warning {{expected integer or identifier in '#pragma pack'}}*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|,
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|i
name|)
end_pragma

begin_comment
comment|/* expected-warning {{expected integer or identifier in '#pragma pack'}}*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|i
name|,
end_pragma

begin_comment
comment|/* expected-warning {{expected integer or identifier in '#pragma pack'}}*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|i
name|,
name|)
end_pragma

begin_comment
comment|/* expected-warning {{expected integer or identifier in '#pragma pack'}}*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|i
name|,
name|help
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|8
name|)
end_pragma

begin_comment
comment|/* expected-warning {{missing ')' after '#pragma pack'}}*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|8
name|,
end_pragma

begin_comment
comment|/* expected-warning {{missing ')' after '#pragma pack'}}*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|8
name|,
name|)
end_pragma

begin_comment
comment|/* expected-warning {{missing ')' after '#pragma pack'}}*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|i
name|,
name|8
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|i
name|,
name|8
name|)
end_pragma

begin_comment
comment|/* expected-warning {{missing ')' after '#pragma pack'}}*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
end_pragma

begin_macro
name|_Pragma
argument_list|(
literal|"pack(push)"
argument_list|)
end_macro

begin_comment
comment|/* expected-warning {{expected integer or identifier in '#pragma pack'}}*/
end_comment

begin_macro
name|_Pragma
argument_list|(
literal|"pack(push,)"
argument_list|)
end_macro

begin_comment
comment|// PR13580
end_comment

begin_struct
struct|struct
name|S
block|{
name|char
name|a
index|[
literal|3
index|]
decl_stmt|;
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
struct|struct
name|T
block|{
name|char
name|b
decl_stmt|;
name|int
name|c
decl_stmt|;
block|}
name|d
struct|;
pragma|#
directive|pragma
name|pack
name|(
name|)
name|int
name|e
decl_stmt|;
block|}
struct|;
end_struct

end_unit

