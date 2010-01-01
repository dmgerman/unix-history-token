begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -Eonly -verify
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|poison
name|rindex
end_pragma

begin_expr_stmt
name|rindex
argument_list|(
name|some_string
argument_list|,
literal|'h'
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{attempt to use a poisoned identifier}}
end_comment

begin_define
define|#
directive|define
name|BAR
value|_Pragma ("GCC poison XYZW")  XYZW
end_define

begin_comment
comment|/*NO ERROR*/
end_comment

begin_decl_stmt
name|XYZW
comment|// ok
name|BAR
name|XYZW
comment|// expected-error {{attempt to use a poisoned identifier}}
comment|// Pragma poison shouldn't warn from macro expansions defined before the token
comment|// is poisoned.
define|#
directive|define
name|strrchr
value|rindex2
pragma|#
directive|pragma
name|GCC
name|poison
name|rindex2
comment|// Can poison multiple times.
pragma|#
directive|pragma
name|GCC
name|poison
name|rindex2
name|strrchr
argument_list|(
name|some_string
argument_list|,
literal|'h'
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ok.
end_comment

end_unit

