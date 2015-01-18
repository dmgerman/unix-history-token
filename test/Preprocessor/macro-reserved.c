begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -pedantic -verify %s
end_comment

begin_define
define|#
directive|define
name|for
value|0
end_define

begin_comment
comment|// expected-warning {{keyword is hidden by macro definition}}
end_comment

begin_define
define|#
directive|define
name|final
value|1
end_define

begin_define
define|#
directive|define
name|__HAVE_X
value|0
end_define

begin_define
define|#
directive|define
name|__cplusplus
end_define

begin_define
define|#
directive|define
name|_HAVE_X
value|0
end_define

begin_define
define|#
directive|define
name|X__Y
end_define

begin_undef
undef|#
directive|undef
name|for
end_undef

begin_undef
undef|#
directive|undef
name|final
end_undef

begin_undef
undef|#
directive|undef
name|__HAVE_X
end_undef

begin_undef
undef|#
directive|undef
name|__cplusplus
end_undef

begin_undef
undef|#
directive|undef
name|_HAVE_X
end_undef

begin_undef
undef|#
directive|undef
name|X__Y
end_undef

begin_comment
comment|// whitelisted definitions
end_comment

begin_define
define|#
directive|define
name|while
value|while
end_define

begin_define
define|#
directive|define
name|const
end_define

begin_define
define|#
directive|define
name|static
end_define

begin_define
define|#
directive|define
name|extern
end_define

begin_define
define|#
directive|define
name|inline
end_define

begin_undef
undef|#
directive|undef
name|while
end_undef

begin_undef
undef|#
directive|undef
name|const
end_undef

begin_undef
undef|#
directive|undef
name|static
end_undef

begin_undef
undef|#
directive|undef
name|extern
end_undef

begin_undef
undef|#
directive|undef
name|inline
end_undef

begin_define
define|#
directive|define
name|inline
value|__inline
end_define

begin_undef
undef|#
directive|undef
name|inline
end_undef

begin_define
define|#
directive|define
name|inline
value|__inline__
end_define

begin_undef
undef|#
directive|undef
name|inline
end_undef

begin_define
define|#
directive|define
name|inline
value|inline__
end_define

begin_comment
comment|// expected-warning {{keyword is hidden by macro definition}}
end_comment

begin_undef
undef|#
directive|undef
name|inline
end_undef

begin_define
define|#
directive|define
name|extern
value|__inline
end_define

begin_comment
comment|// expected-warning {{keyword is hidden by macro definition}}
end_comment

begin_undef
undef|#
directive|undef
name|extern
end_undef

begin_define
define|#
directive|define
name|extern
value|__extern
end_define

begin_comment
comment|// expected-warning {{keyword is hidden by macro definition}}
end_comment

begin_undef
undef|#
directive|undef
name|extern
end_undef

begin_define
define|#
directive|define
name|extern
value|__extern__
end_define

begin_comment
comment|// expected-warning {{keyword is hidden by macro definition}}
end_comment

begin_undef
undef|#
directive|undef
name|extern
end_undef

begin_define
define|#
directive|define
name|inline
value|_inline
end_define

begin_comment
comment|// expected-warning {{keyword is hidden by macro definition}}
end_comment

begin_undef
undef|#
directive|undef
name|inline
end_undef

begin_define
define|#
directive|define
name|volatile
end_define

begin_comment
comment|// expected-warning {{keyword is hidden by macro definition}}
end_comment

begin_undef
undef|#
directive|undef
name|volatile
end_undef

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|warning
literal|"-Wreserved-id-macro"
end_pragma

begin_define
define|#
directive|define
name|switch
value|if
end_define

begin_comment
comment|// expected-warning {{keyword is hidden by macro definition}}
end_comment

begin_define
define|#
directive|define
name|final
value|1
end_define

begin_define
define|#
directive|define
name|__clusplus
end_define

begin_comment
comment|// expected-warning {{macro name is a reserved identifier}}
end_comment

begin_define
define|#
directive|define
name|__HAVE_X
value|0
end_define

begin_comment
comment|// expected-warning {{macro name is a reserved identifier}}
end_comment

begin_define
define|#
directive|define
name|_HAVE_X
value|0
end_define

begin_comment
comment|// expected-warning {{macro name is a reserved identifier}}
end_comment

begin_define
define|#
directive|define
name|X__Y
end_define

begin_undef
undef|#
directive|undef
name|switch
end_undef

begin_undef
undef|#
directive|undef
name|final
end_undef

begin_undef
undef|#
directive|undef
name|__cplusplus
end_undef

begin_comment
comment|// expected-warning {{macro name is a reserved identifier}}
end_comment

begin_undef
undef|#
directive|undef
name|_HAVE_X
end_undef

begin_comment
comment|// expected-warning {{macro name is a reserved identifier}}
end_comment

begin_undef
undef|#
directive|undef
name|X__Y
end_undef

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

end_unit

