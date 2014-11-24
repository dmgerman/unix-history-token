begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wthread-safety -verify %s
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|capability
argument_list|(
literal|"role"
argument_list|)
operator|)
argument_list|)
name|ThreadRole
typedef|;
end_typedef

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(shared_capability(
literal|"mutex"
argument|))
argument_list|)
name|Mutex
block|{}
struct|;
end_struct

begin_struct
struct|struct
name|NotACapability
block|{}
struct|;
end_struct

begin_comment
comment|// Test an invalid capability name
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(capability(
literal|"wrong"
argument|))
argument_list|)
name|IncorrectName
block|{}
struct|;
end_struct

begin_comment
comment|// expected-warning {{invalid capability name 'wrong'; capability name must be 'mutex' or 'role'}}
end_comment

begin_decl_stmt
name|int
name|Test1
name|__attribute__
argument_list|(
operator|(
name|capability
argument_list|(
literal|"test1"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'capability' attribute only applies to structs or typedefs}}
end_comment

begin_decl_stmt
name|int
name|Test2
name|__attribute__
argument_list|(
operator|(
name|shared_capability
argument_list|(
literal|"test2"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'shared_capability' attribute only applies to structs or typedefs}}
end_comment

begin_decl_stmt
name|int
name|Test3
name|__attribute__
argument_list|(
operator|(
name|acquire_capability
argument_list|(
literal|"test3"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'acquire_capability' attribute only applies to functions}}
end_comment

begin_decl_stmt
name|int
name|Test4
name|__attribute__
argument_list|(
operator|(
name|try_acquire_capability
argument_list|(
literal|"test4"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'try_acquire_capability' attribute only applies to functions}}
end_comment

begin_decl_stmt
name|int
name|Test5
name|__attribute__
argument_list|(
operator|(
name|release_capability
argument_list|(
literal|"test5"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'release_capability' attribute only applies to functions}}
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(capability(
literal|12
argument|))
argument_list|)
name|Test3
block|{}
struct|;
end_struct

begin_comment
comment|// expected-error {{'capability' attribute requires a string}}
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(shared_capability(Test2))
argument_list|)
name|Test4
block|{}
struct|;
end_struct

begin_comment
comment|// expected-error {{'shared_capability' attribute requires a string}}
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(capability)
argument_list|)
name|Test5
block|{}
struct|;
end_struct

begin_comment
comment|// expected-error {{'capability' attribute takes one argument}}
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(shared_capability(
literal|"test1"
argument|,
literal|12
argument|))
argument_list|)
name|Test6
block|{}
struct|;
end_struct

begin_comment
comment|// expected-error {{'shared_capability' attribute takes one argument}}
end_comment

begin_decl_stmt
name|struct
name|NotACapability
name|BadCapability
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ThreadRole
name|GUI
decl_stmt|,
name|Worker
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|Func1
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(requires_capability
parameter_list|(
name|GUI
parameter_list|)
end_function

begin_block
unit|))
block|{}
end_block

begin_function
name|void
name|Func2
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(requires_shared_capability
parameter_list|(
name|Worker
parameter_list|)
end_function

begin_block
unit|))
block|{}
end_block

begin_function
name|void
name|Func3
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(requires_capability
end_function

begin_block
unit|))
block|{}
end_block

begin_comment
comment|// expected-error {{'requires_capability' attribute takes at least 1 argument}}
end_comment

begin_function
name|void
name|Func4
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(requires_shared_capability
end_function

begin_block
unit|))
block|{}
end_block

begin_comment
comment|// expected-error {{'requires_shared_capability' attribute takes at least 1 argument}}
end_comment

begin_function
name|void
name|Func5
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(requires_capability
parameter_list|(
function|1
end_function

begin_block
unit|)))
block|{}
end_block

begin_comment
comment|// expected-warning {{'requires_capability' attribute requires arguments whose type is annotated with 'capability' attribute; type here is 'int'}}
end_comment

begin_function
name|void
name|Func6
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(requires_shared_capability
parameter_list|(
name|BadCapability
parameter_list|)
end_function

begin_block
unit|))
block|{}
end_block

begin_comment
comment|// expected-warning {{'requires_shared_capability' attribute requires arguments whose type is annotated with 'capability' attribute; type here is 'struct NotACapability'}}
end_comment

begin_function
name|void
name|Func7
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(assert_capability
parameter_list|(
name|GUI
parameter_list|)
end_function

begin_block
unit|))
block|{}
end_block

begin_function
name|void
name|Func8
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(assert_shared_capability
parameter_list|(
name|GUI
parameter_list|)
end_function

begin_block
unit|))
block|{}
end_block

begin_function
name|void
name|Func9
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(assert_capability
parameter_list|()
end_function

begin_block
unit|))
block|{}
end_block

begin_comment
comment|// expected-error {{'assert_capability' attribute takes one argument}}
end_comment

begin_function
name|void
name|Func10
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(assert_shared_capability
parameter_list|()
end_function

begin_block
unit|))
block|{}
end_block

begin_comment
comment|// expected-error {{'assert_shared_capability' attribute takes one argument}}
end_comment

begin_function
name|void
name|Func11
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(acquire_capability
parameter_list|(
name|GUI
parameter_list|)
end_function

begin_block
unit|))
block|{}
end_block

begin_function
name|void
name|Func12
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(acquire_shared_capability
parameter_list|(
name|GUI
parameter_list|)
end_function

begin_block
unit|))
block|{}
end_block

begin_function
name|void
name|Func15
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(release_capability
parameter_list|(
name|GUI
parameter_list|)
end_function

begin_block
unit|))
block|{}
end_block

begin_function
name|void
name|Func16
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(release_shared_capability
parameter_list|(
name|GUI
parameter_list|)
end_function

begin_block
unit|))
block|{}
end_block

begin_function
name|void
name|Func17
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(release_generic_capability
parameter_list|(
name|GUI
parameter_list|)
end_function

begin_block
unit|))
block|{}
end_block

begin_function
name|void
name|Func21
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(try_acquire_capability
parameter_list|(
function|1
end_function

begin_block
unit|)))
block|{}
end_block

begin_function
name|void
name|Func22
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(try_acquire_shared_capability
parameter_list|(
function|1
end_function

begin_block
unit|)))
block|{}
end_block

begin_function
name|void
name|Func23
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(try_acquire_capability
parameter_list|(
function|1
operator|,
function|GUI
end_function

begin_block
unit|)))
block|{}
end_block

begin_function
name|void
name|Func24
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(try_acquire_shared_capability
parameter_list|(
function|1
operator|,
function|GUI
end_function

begin_block
unit|)))
block|{}
end_block

begin_function
name|void
name|Func25
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(try_acquire_capability
parameter_list|()
end_function

begin_block
unit|))
block|{}
end_block

begin_comment
comment|// expected-error {{'try_acquire_capability' attribute takes at least 1 argument}}
end_comment

begin_function
name|void
name|Func26
parameter_list|(
name|void
parameter_list|)
function|__attribute__
parameter_list|(
function|(try_acquire_shared_capability
parameter_list|()
end_function

begin_block
unit|))
block|{}
end_block

begin_comment
comment|// expected-error {{'try_acquire_shared_capability' attribute takes at least 1 argument}}
end_comment

begin_comment
comment|// Test that boolean logic works with capability attributes
end_comment

begin_function_decl
name|void
name|Func27
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(requires_capability
parameter_list|(
function_decl|!GUI
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|Func28
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(requires_capability
parameter_list|(
function_decl|GUI&& Worker
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|Func29
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(requires_capability
parameter_list|(
function_decl|GUI || Worker
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|Func30
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(requires_capability
parameter_list|(
function_decl|(Worker || Worker
end_function_decl

begin_expr_stmt
unit|)
operator|&&
operator|!
name|GUI
end_expr_stmt

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|int
name|AlsoNotACapability
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|Func31
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(requires_capability
parameter_list|(
function_decl|GUI&& AlsoNotACapability
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{'requires_capability' attribute requires arguments whose type is annotated with 'capability' attribute; type here is 'int'}}
end_comment

end_unit

