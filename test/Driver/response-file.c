begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that clang is able to process short response files
end_comment

begin_comment
comment|// Since this is a short response file, clang must not use a response file
end_comment

begin_comment
comment|// to pass its parameters to other tools. This is only necessary for a large
end_comment

begin_comment
comment|// number of parameters.
end_comment

begin_comment
comment|// RUN: echo "-DTEST"> %t.0.txt
end_comment

begin_comment
comment|// RUN: %clang -E @%t.0.txt %s -v 2>&1 | FileCheck %s -check-prefix=SHORT
end_comment

begin_comment
comment|// SHORT-NOT: Arguments passed via response file
end_comment

begin_comment
comment|// SHORT: extern int it_works;
end_comment

begin_comment
comment|// Check that clang is able to process long response files, routing a long
end_comment

begin_comment
comment|// sequence of arguments to other tools by using response files as well.
end_comment

begin_comment
comment|// We generate a 2MB response file to attempt to surpass any system limit.
end_comment

begin_comment
comment|// But there's no guarantee that we actually will (the system limit could be
end_comment

begin_comment
comment|// *huge*), so just check that invoking cc1 succeeds under these conditions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -E %S/Inputs/gen-response.c | grep DTEST> %t.1.txt
end_comment

begin_comment
comment|// RUN: %clang -E @%t.1.txt %s -v 2>&1 | FileCheck %s -check-prefix=LONG
end_comment

begin_comment
comment|// LONG: extern int it_works;
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

