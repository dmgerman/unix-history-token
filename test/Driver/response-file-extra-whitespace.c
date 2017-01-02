begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that clang is able to process response files with extra whitespace.
end_comment

begin_comment
comment|// We generate a dos-style file with \r\n for line endings, and then split
end_comment

begin_comment
comment|// some joined arguments (like "-x c") across lines to ensure that regular
end_comment

begin_comment
comment|// clang (not clang-cl) can process it correctly.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: printf " -x\r\nc\r\n-DTEST\r\n"> %t.0.txt
end_comment

begin_comment
comment|// RUN: %clang -E @%t.0.txt %s -v 2>&1 | FileCheck %s -check-prefix=SHORT
end_comment

begin_comment
comment|// SHORT: extern int it_works;
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|it_works
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

