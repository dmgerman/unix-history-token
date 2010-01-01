begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -dump-tokens %s 2>&1 | grep "Spelling=.*dumptokens_phyloc.c:3:20"
end_comment

begin_define
define|#
directive|define
name|TESTPHYLOC
value|10
end_define

begin_macro
name|TESTPHYLOC
end_macro

end_unit

