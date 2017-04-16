begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir %t
end_comment

begin_comment
comment|// RUN: echo 'module X { header "x.h" }'> %t/map
end_comment

begin_comment
comment|// RUN: echo 'extern int n;'> %t/x.h
end_comment

begin_comment
comment|// RUN: cd %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -fmodules -fmodule-map-file=map -fmodules-cache-path=. -verify -I.
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_include
include|#
directive|include
file|"x.h"
end_include

begin_decl_stmt
name|int
modifier|*
name|m
init|=
operator|&
name|n
decl_stmt|;
end_decl_stmt

end_unit

