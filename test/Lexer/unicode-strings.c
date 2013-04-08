begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -x c -std=c11 -Werror %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=c++11 -Werror %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c -std=c11 -Wc99-compat -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=c++11 -Wc++98-compat -verify %s
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_typedef
typedef|typedef
name|__CHAR16_TYPE__
name|char16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__CHAR32_TYPE__
name|char32_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|// expected-warning@17 {{'char16_t' type specifier is incompatible with C++98}}
end_comment

begin_comment
comment|// expected-warning@18 {{'char32_t' type specifier is incompatible with C++98}}
end_comment

begin_comment
comment|// expected-warning@20 {{'char16_t' type specifier is incompatible with C++98}}
end_comment

begin_comment
comment|// expected-warning@21 {{'char32_t' type specifier is incompatible with C++98}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|const
name|char
modifier|*
name|a
init|=
literal|u8"abcd"
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{unicode literals are incompatible with}}
end_comment

begin_decl_stmt
specifier|const
name|char16_t
modifier|*
name|b
init|=
literal|u"abcd"
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{unicode literals are incompatible with}}
end_comment

begin_decl_stmt
specifier|const
name|char32_t
modifier|*
name|c
init|=
literal|U"abcd"
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{unicode literals are incompatible with}}
end_comment

begin_decl_stmt
name|char16_t
name|d
init|=
literal|u'
expr|a'
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{unicode literals are incompatible with}}
end_comment

begin_decl_stmt
name|char32_t
name|e
init|=
literal|U'
expr|a'
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{unicode literals are incompatible with}}
end_comment

end_unit

