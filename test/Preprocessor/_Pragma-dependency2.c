begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s -verify
end_comment

begin_define
define|#
directive|define
name|DO_PRAGMA
value|_Pragma
end_define

begin_macro
name|DO_PRAGMA
argument_list|(
literal|"GCC dependency \"blahblabh\""
argument_list|)
end_macro

begin_comment
comment|// expected-error {{file not found}}
end_comment

end_unit

