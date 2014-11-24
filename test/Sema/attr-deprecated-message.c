begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_comment
comment|// rdar: // 6734520
end_comment

begin_typedef
typedef|typedef
name|int
name|INT1
name|__attribute__
typedef|((
name|deprecated
typedef|("Please avoid INT1")));
end_typedef

begin_comment
comment|// expected-note 3 {{'INT1' has been explicitly marked deprecated here}}
end_comment

begin_typedef
typedef|typedef
name|INT1
name|INT2
name|__attribute__
typedef|((
name|__deprecated__
typedef|("Please avoid INT2")));
end_typedef

begin_typedef
typedef|typedef
name|INT1
name|INT1a
typedef|;
end_typedef

begin_comment
comment|// expected-warning {{'INT1' is deprecated: Please avoid INT1}}
end_comment

begin_typedef
typedef|typedef
name|INT1
name|INT1b
name|__attribute__
typedef|((
name|deprecated
typedef|("Please avoid INT1b")));
end_typedef

begin_decl_stmt
name|INT1
name|should_be_unavailable
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'INT1' is deprecated: Please avoid INT1}}
end_comment

begin_decl_stmt
name|INT1a
name|should_not_be_deprecated
decl_stmt|;
end_decl_stmt

begin_function_decl
name|INT1
name|f1
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
parameter_list|(
function_decl|"Please avoid f1"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{'f1' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
name|INT1
name|f2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{'INT1' is deprecated: Please avoid INT1}}
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|red
block|,
name|green
block|,
name|blue
block|}
name|Color
name|__attribute__
typedef|((
name|deprecated
typedef|("Please avoid Color")));
end_typedef

begin_comment
comment|// expected-note {{'Color' has been explicitly marked deprecated here}}
end_comment

begin_decl_stmt
name|Color
name|c1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'Color' is deprecated: Please avoid Color}}
end_comment

begin_decl_stmt
name|int
name|g1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|g2
name|__attribute__
argument_list|(
operator|(
name|deprecated
argument_list|(
literal|"Please avoid g2"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{'g2' has been explicitly marked deprecated here}}
end_comment

begin_function
name|int
name|func1
parameter_list|()
block|{
name|int
function_decl|(
modifier|*
name|pf
function_decl|)
parameter_list|()
init|=
name|f1
function_decl|;
comment|// expected-warning {{'f1' is deprecated: Please avoid f1}}
name|int
name|i
init|=
name|f2
argument_list|()
decl_stmt|;
return|return
name|g1
operator|+
name|g2
return|;
comment|// expected-warning {{'g2' is deprecated: Please avoid g2}}
block|}
end_function

end_unit

