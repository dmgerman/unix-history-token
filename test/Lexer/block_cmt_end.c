begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   RUN: clang-cc -E -trigraphs %s | grep bar&&   RUN: clang-cc -E -trigraphs %s | grep foo&&   RUN: clang-cc -E -trigraphs %s | not grep abc&&   RUN: clang-cc -E -trigraphs %s | not grep xyz&&   RUN: clang-cc -fsyntax-only -trigraphs -verify %s   */
end_comment

begin_comment
comment|// This is a simple comment, /*/ does not end a comment, the trailing */ does.
end_comment

begin_decl_stmt
name|int
name|i
init|=
comment|/*/ */
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* abc  next comment ends with normal escaped newline: */
end_comment

begin_comment
comment|/* expected-warning {{escaped newline}} expected-warning {{backslash and newline}}  *\   /  int bar /* expected-error {{invalid token after top level declarator}} */
end_comment

begin_comment
comment|/* xyz  next comment ends with a trigraph escaped newline: */
end_comment

begin_comment
comment|/* expected-warning {{escaped newline between}}   expected-warning {{backslash and newline separated by space}}    expected-warning {{trigraph ends block comment}}   *??/     /  foo   // rdar://6060752 - We should not get warnings about trigraphs in comments: // '????' /* ???? */
end_comment

end_unit

