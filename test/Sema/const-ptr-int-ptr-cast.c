begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_decl_stmt
name|char
modifier|*
name|a
init|=
operator|(
name|void
operator|*
operator|)
call|(
name|uintptr_t
call|)
argument_list|(
name|void
operator|*
argument_list|)
operator|&
name|a
decl_stmt|;
end_decl_stmt

end_unit

