begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -ccc-print-phases -emit-ast %s 2> %t
end_comment

begin_comment
comment|// RUN: echo 'END'>> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix EMIT-AST-PHASES -input-file %t %s
end_comment

begin_comment
comment|// EMIT-AST-PHASES: 0: input,
end_comment

begin_comment
comment|// EMIT-AST-PHASES: , c
end_comment

begin_comment
comment|// EMIT-AST-PHASES: 1: preprocessor, {0}, cpp-output
end_comment

begin_comment
comment|// EMIT-AST-PHASES: 2: compiler, {1}, ast
end_comment

begin_comment
comment|// EMIT-AST-PHASES-NOT: 3:
end_comment

begin_comment
comment|// EMIT-AST-PHASES: END
end_comment

begin_comment
comment|// RUN: touch %t.ast
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -ccc-print-phases -c %t.ast 2> %t
end_comment

begin_comment
comment|// RUN: echo 'END'>> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix COMPILE-AST-PHASES -input-file %t %s
end_comment

begin_comment
comment|// COMPILE-AST-PHASES: 0: input,
end_comment

begin_comment
comment|// COMPILE-AST-PHASES: , ast
end_comment

begin_comment
comment|// COMPILE-AST-PHASES: 1: compiler, {0}, ir
end_comment

begin_comment
comment|// COMPILE-AST-PHASES: 2: backend, {1}, assembler
end_comment

begin_comment
comment|// COMPILE-AST-PHASES: 3: assembler, {2}, object
end_comment

begin_comment
comment|// COMPILE-AST-PHASES-NOT: 4:
end_comment

begin_comment
comment|// COMPILE-AST-PHASES: END
end_comment

begin_comment
comment|// FIXME: There is a problem with compiling AST's in that the input language is
end_comment

begin_comment
comment|// not available for use by other tools (for example, to automatically add
end_comment

begin_comment
comment|// -lstdc++). We may need -x [objective-]c++-ast and all that goodness. :(
end_comment

end_unit

