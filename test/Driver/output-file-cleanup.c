begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: touch %t.s
end_comment

begin_comment
comment|// RUN: not %clang -S -DCRASH -o %t.s -MMD -MF %t.d %s
end_comment

begin_comment
comment|// RUN: test ! -f %t.s
end_comment

begin_comment
comment|// RUN: test ! -f %t.d
end_comment

begin_comment
comment|// RUN: touch %t.s
end_comment

begin_comment
comment|// RUN: not %clang -S -DMISSING -o %t.s -MMD -MF %t.d %s
end_comment

begin_comment
comment|// RUN: test ! -f %t.s
end_comment

begin_comment
comment|// RUN: test ! -f %t.d
end_comment

begin_comment
comment|// RUN: touch %t.s
end_comment

begin_comment
comment|// RUN: not %clang -S -o %t.s -MMD -MF %t.d %s
end_comment

begin_comment
comment|// RUN: test ! -f %t.s
end_comment

begin_comment
comment|// RUN: test -f %t.d
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

begin_comment
comment|// REQUIRES: crash-recovery
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CRASH
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|clang
name|__debug
name|crash
end_pragma

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MISSING
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"nonexistent.h"
end_include

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|invalid
name|C
name|code
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// RUN: touch %t1.c
end_comment

begin_comment
comment|// RUN: echo "invalid C code"> %t2.c
end_comment

begin_comment
comment|// RUN: cd %T&& not %clang -S %t1.c %t2.c
end_comment

begin_comment
comment|// RUN: test -f %t1.s
end_comment

begin_comment
comment|// RUN: test ! -f %t2.s
end_comment

begin_comment
comment|// RUN: touch %t1.c
end_comment

begin_comment
comment|// RUN: touch %t2.c
end_comment

begin_comment
comment|// RUN: chmod -r %t2.c
end_comment

begin_comment
comment|// RUN: cd %T&& not %clang -S %t1.c %t2.c
end_comment

begin_comment
comment|// RUN: test -f %t1.s
end_comment

begin_comment
comment|// RUN: test ! -f %t2.s
end_comment

begin_comment
comment|// RUN: touch %t1.c
end_comment

begin_comment
comment|// RUN: echo "invalid C code"> %t2.c
end_comment

begin_comment
comment|// RUN: touch %t3.c
end_comment

begin_comment
comment|// RUN: echo "invalid C code"> %t4.c
end_comment

begin_comment
comment|// RUN: touch %t5.c
end_comment

begin_comment
comment|// RUN: cd %T&& not %clang -S %t1.c %t2.c %t3.c %t4.c %t5.c
end_comment

begin_comment
comment|// RUN: test -f %t1.s
end_comment

begin_comment
comment|// RUN: test ! -f %t2.s
end_comment

begin_comment
comment|// RUN: test -f %t3.s
end_comment

begin_comment
comment|// RUN: test ! -f %t4.s
end_comment

begin_comment
comment|// RUN: test -f %t5.s
end_comment

end_unit

