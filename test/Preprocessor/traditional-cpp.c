begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Clang supports a very limited subset of -traditional-cpp, basically we only  * intend to add support for things that people actually rely on when doing  * things like using /usr/bin/cpp to preprocess non-source files. */
end_comment

begin_comment
comment|/*  RUN: %clang_cc1 -traditional-cpp %s -E -o %t  RUN: FileCheck< %t %s */
end_comment

begin_comment
comment|/* CHECK: foo // bar  */
end_comment

begin_macro
name|foo
end_macro

begin_comment
comment|// bar
end_comment

end_unit

