begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -I. %s | grep BODY_OF_FILE | wc -l | grep 1
end_comment

begin_comment
comment|// This #import should have no effect, as we're importing the current file.
end_comment

begin_empty
empty|#import<import_self.c>
end_empty

begin_macro
name|BODY_OF_FILE
end_macro

end_unit

