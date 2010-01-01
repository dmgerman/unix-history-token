begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -parse-noop %s
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|int printf(const char *, ...); void _Block_byref_release(void*src){}  int main() {    __block  int X = 1234;    __block  const char * message = "HELLO";     X = X - 1234;     X += 1;     printf ("%s(%d)\n", message, X);    X -= 1;     return X; }
endif|#
directive|endif
end_endif

end_unit

