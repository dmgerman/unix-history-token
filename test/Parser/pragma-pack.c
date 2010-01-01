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

end_unit

