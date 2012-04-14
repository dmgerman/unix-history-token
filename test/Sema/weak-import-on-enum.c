begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1  -fsyntax-only -verify -triple x86_64-apple-darwin %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin9 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// rdar://10277579
end_comment

begin_decl_stmt
name|enum
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
name|A
block|{
name|a0
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

