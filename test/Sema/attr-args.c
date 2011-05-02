begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -DATTR=noreturn -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=always_inline -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=cdecl -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=const -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=fastcall -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=malloc -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=nothrow -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=stdcall -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=used -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=unused -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=weak -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_define
define|#
directive|define
name|ATTR_DECL
parameter_list|(
name|a
parameter_list|)
value|__attribute__((ATTR(a)))
end_define

begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|inline
name|ATTR_DECL
argument_list|(
argument|a
argument_list|)
name|void
operator|*
name|foo
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error{{attribute takes no arguments}}
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=noreturn -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=always_inline -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=cdecl -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=const -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=fastcall -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=malloc -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=nothrow -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=stdcall -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=used -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=unused -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DATTR=weak -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_define
define|#
directive|define
name|ATTR_DECL
parameter_list|(
name|a
parameter_list|)
value|__attribute__((ATTR(a)))
end_define

begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|inline
name|ATTR_DECL
argument_list|(
argument|a
argument_list|)
name|void
operator|*
name|foo
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error{{attribute takes no arguments}}
end_comment

end_unit

