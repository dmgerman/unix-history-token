begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | grep 'noexp: foo y'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s | grep 'expand: abc'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s | grep 'noexp2: foo nonexp'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s | grep 'expand2: abc'
end_comment

begin_define
define|#
directive|define
name|A
value|foo
end_define

begin_define
define|#
directive|define
name|foo
parameter_list|()
value|abc
end_define

begin_define
define|#
directive|define
name|X
value|A y
end_define

begin_comment
comment|// This should not expand to abc, because the foo macro isn't followed by (.
end_comment

begin_label
name|noexp
label|:
end_label

begin_decl_stmt
name|X
comment|// This should expand to abc.
undef|#
directive|undef
name|X
define|#
directive|define
name|X
value|A ()
name|expand
range|:
name|X
comment|// This should be 'foo nonexp'
name|noexp2
operator|:
name|A
name|nonexp
comment|// This should expand
name|expand2
operator|:
name|A
argument_list|( )
end_decl_stmt

end_unit

