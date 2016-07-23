begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 "-triple" "x86_64-apple-darwin9.0.0" -fsyntax-only -verify %s
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_feature
argument_list|(
name|attribute_availability_with_strict
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Missing __has_feature"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|f0
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.4
parameter_list|,
name|deprecated
init|=
literal|10.6
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f1
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.5
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f2
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.4
parameter_list|,
name|deprecated
init|=
literal|10.5
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{'f2' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
name|void
name|f3
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.6
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f4
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.1
parameter_list|,
name|deprecated
init|=
literal|10.3
parameter_list|,
name|obsoleted
init|=
literal|10.5
parameter_list|)
operator|,
function_decl|availability
parameter_list|(
name|ios
parameter_list|,
name|introduced
init|=
literal|2.0
parameter_list|,
name|deprecated
init|=
literal|3.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note{{explicitly marked unavailable}}
end_comment

begin_function_decl
name|void
name|f5
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|introduced
init|=
literal|3.2
parameter_list|)
operator|,
function_decl|availability
parameter_list|(
name|macosx
parameter_list|,
name|unavailable
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note{{'f5' has been explicitly marked unavailable here}}
end_comment

begin_function_decl
name|void
name|f6
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|strict
parameter_list|,
name|introduced
init|=
literal|10.6
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-note{{'f6' has been explicitly marked unavailable here}}
end_comment

begin_function
name|void
name|test
parameter_list|()
block|{
name|f0
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|f1
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|f2
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{'f2' is deprecated: first deprecated in macOS 10.5}}
name|f3
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|f4
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error{{f4' is unavailable: obsoleted in macOS 10.5}}
name|f5
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error{{'f5' is unavailable: not available on macOS}}
name|f6
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error{{'f6' is unavailable: introduced in macOS 10.6}}
block|}
end_function

begin_decl_stmt
name|struct
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|macosx
argument_list|,
name|strict
argument_list|,
name|introduced
operator|=
literal|10.6
argument_list|)
operator|)
argument_list|)
name|not_yet_introduced_struct
decl_stmt|;
end_decl_stmt

begin_comment
comment|// \
end_comment

begin_expr_stmt
name|expected
operator|-
name|note
block|{
block|{
literal|'not_yet_introduced_struct'
name|has
name|been
name|explicitly
name|marked
name|unavailable
name|here
block|}
block|}
name|void
name|uses_not_introduced_struct
argument_list|(
expr|struct
name|not_yet_introduced_struct
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// \
end_comment

begin_expr_stmt
name|expected
operator|-
name|error
block|{
block|{
literal|'not_yet_introduced_struct'
name|is
name|unavailable
operator|:
name|introduced
name|in
name|macOS
literal|10.6
block|}
block|}
name|__attribute__
argument_list|(
argument|(availability(macosx,strict,introduced=
literal|10.6
argument|))
argument_list|)
name|void
name|uses_not_introduced_struct_same_availability
argument_list|(
expr|struct
name|not_yet_introduced_struct
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// rdar://10535640
end_comment

begin_enum
enum|enum
block|{
name|foo
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|macosx
argument_list|,
name|introduced
operator|=
literal|8.0
argument_list|,
name|deprecated
operator|=
literal|9.0
argument_list|)
operator|)
argument_list|)
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|bar
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|macosx
argument_list|,
name|introduced
operator|=
literal|8.0
argument_list|,
name|deprecated
operator|=
literal|9.0
argument_list|)
operator|)
argument_list|)
init|=
name|foo
block|}
enum|;
end_enum

begin_decl_stmt
name|enum
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|macosx
argument_list|,
name|introduced
operator|=
literal|8.0
argument_list|,
name|deprecated
operator|=
literal|9.0
argument_list|)
operator|)
argument_list|)
block|{
name|bar1
operator|=
name|foo
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Make sure the note is on the declaration with the actual availability attributes.
end_comment

begin_decl_stmt
name|struct
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|macosx
argument_list|,
name|strict
argument_list|,
name|introduced
operator|=
literal|10.9
argument_list|)
operator|)
argument_list|)
name|type_info
comment|// \
name|expected
decl|-
name|note
block|{
block|{
literal|'type_info'
name|has
name|been
name|explicitly
name|marked
name|unavailable
name|here
block|}
block|}
end_decl_stmt

begin_block
block|{ }
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_struct_decl
struct_decl|struct
name|type_info
struct_decl|;
end_struct_decl

begin_function
name|int
name|test2
parameter_list|()
block|{
name|struct
name|type_info
modifier|*
name|t
decl_stmt|;
comment|// expected-error{{'type_info' is unavailable: introduced in macOS 10.9}}
return|return
literal|0
return|;
block|}
end_function

end_unit

