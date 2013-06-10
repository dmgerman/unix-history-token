begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple le32-unknown-nacl %s -fsyntax-only -verify
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|regparm
argument_list|(
literal|2
argument_list|)
operator|)
argument_list|)
name|fc_f1
argument_list|(
name|int
name|i
argument_list|,
name|int
name|j
argument_list|,
name|int
name|k
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|// expected-error{{'regparm' is not valid on this platform}}
end_comment

end_unit

