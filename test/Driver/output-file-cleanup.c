begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: touch %t.o
end_comment

begin_comment
comment|// RUN: not %clang -DCRASH -o %t.o -MMD -MF %t.d %s
end_comment

begin_comment
comment|// RUN: test ! -f %t.o
end_comment

begin_comment
comment|// RUN: test ! -f %t.d
end_comment

begin_comment
comment|// RUN: touch %t.o
end_comment

begin_comment
comment|// RUN: not %clang -DMISSING -o %t.o -MMD -MF %t.d %s
end_comment

begin_comment
comment|// RUN: test ! -f %t.o
end_comment

begin_comment
comment|// RUN: test ! -f %t.d
end_comment

begin_comment
comment|// RUN: touch %t.o
end_comment

begin_comment
comment|// RUN: not %clang -o %t.o -MMD -MF %t.d %s
end_comment

begin_comment
comment|// RUN: test ! -f %t.o
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

end_unit

