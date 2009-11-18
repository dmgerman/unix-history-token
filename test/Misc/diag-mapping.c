begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This should warn by default.
end_comment

begin_comment
comment|// RUN: clang-cc %s 2>&1 | grep "warning:"
end_comment

begin_comment
comment|// This should not emit anything.
end_comment

begin_comment
comment|// RUN: clang-cc %s -Wno-extra-tokens 2>&1 | not grep diagnostic
end_comment

begin_comment
comment|// -Werror can map all warnings to error.
end_comment

begin_comment
comment|// RUN: clang-cc %s -Werror 2>&1 | grep "error:"
end_comment

begin_comment
comment|// -Werror can map this one warning to error.
end_comment

begin_comment
comment|// RUN: clang-cc %s -Werror=extra-tokens 2>&1 | grep "error:"
end_comment

begin_comment
comment|// Mapping unrelated diags to errors doesn't affect this one.
end_comment

begin_comment
comment|// RUN: clang-cc %s -Werror=trigraphs 2>&1 | grep "warning:"
end_comment

begin_comment
comment|// This should stay a warning with -pedantic.
end_comment

begin_comment
comment|// RUN: clang-cc %s -pedantic 2>&1 | grep "warning:"
end_comment

begin_comment
comment|// This should emit an error with -pedantic-errors.
end_comment

begin_comment
comment|// RUN: clang-cc %s -pedantic-errors 2>&1 | grep "error:"
end_comment

begin_comment
comment|// This should emit a warning, because -Wfoo overrides -pedantic*.
end_comment

begin_comment
comment|// RUN: clang-cc %s -pedantic-errors -Wextra-tokens 2>&1 | grep "warning:"
end_comment

begin_comment
comment|// This should emit nothing, because -Wno-extra-tokens overrides -pedantic*
end_comment

begin_comment
comment|// RUN: clang-cc %s -pedantic-errors -Wno-extra-tokens 2>&1 | not grep diagnostic
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|foo
end_ifdef

begin_endif
endif|#
directive|endif
endif|bad
end_endif

begin_comment
comment|// extension!
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

end_unit

