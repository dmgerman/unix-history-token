begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Avoid preprocessor diag crash caused by a parser diag left in flight.
end_comment

begin_decl_stmt
name|int
name|foo
range|:
end_decl_stmt

begin_comment
comment|// expected-error {{expected ';' after top level declarator}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-error {{#endif without #if}}
end_comment

end_unit

