begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|__attribute__
argument_list|(
operator|(
name|objc_root_class
operator|)
argument_list|)
expr|@
name|interface
name|NSError
expr|@
name|end
name|__attribute__
argument_list|(
operator|(
name|objc_root_class
operator|)
argument_list|)
expr|@
name|interface
name|A
expr|@
name|end
expr|struct
name|X
block|{ }
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|f1
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1{{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2{{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_typedef
typedef|typedef
name|struct
name|__attribute__
argument_list|(
operator|(
name|objc_bridge
argument_list|(
name|NSError
argument_list|)
operator|)
argument_list|)
name|__CFError
modifier|*
name|CFErrorRef
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|NSError
modifier|*
name|NSErrorPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|NSError
modifier|*
modifier|*
name|NSErrorPtrPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CFErrorRef
modifier|*
name|CFErrorRefPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
modifier|*
name|int_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|A
modifier|*
name|A_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|^
name|block_ptr
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|clang
name|assume_nonnull
name|begin
end_pragma

begin_function_decl
name|void
name|f2
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f3
parameter_list|(
name|A
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f4
parameter_list|(
name|int
function_decl|(
modifier|^
name|block
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f5
parameter_list|(
name|int_ptr
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f6
parameter_list|(
name|A_ptr
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f7
parameter_list|(
name|int
modifier|*
name|_Nullable
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f8
parameter_list|(
name|A
modifier|*
name|_Nullable
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|f9
argument_list|(
name|int
name|X
operator|::
operator|*
name|mem_ptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|f10
argument_list|(
name|int
argument_list|(
name|X
operator|::
operator|*
name|mem_func
argument_list|)
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|f11
argument_list|(
name|int
name|X
operator|::
operator|*
name|_Nullable
name|mem_ptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|f12
argument_list|(
name|int
argument_list|(
argument|X::* _Nullable mem_func
argument_list|)
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int_ptr
name|f13
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|A
modifier|*
name|f14
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
modifier|*
name|_Null_unspecified
name|f15
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|A
modifier|*
name|_Null_unspecified
name|f16
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f17
parameter_list|(
name|CFErrorRef
modifier|*
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{no known conversion from 'A * _Nonnull' to 'CFErrorRef  _Nullable * _Nullable' (aka '__CFError **') for 1st argument}}
end_comment

begin_function_decl
name|void
name|f18
parameter_list|(
name|A
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning 2{{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1 2 {{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2 2 {{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_function_decl
name|void
name|f19
parameter_list|(
name|CFErrorRefPtr
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1{{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2{{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_function_decl
name|void
name|g1
parameter_list|(
name|int
function_decl|(
modifier|^
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g2
parameter_list|(
name|int
function_decl|(
modifier|^
modifier|*
name|bp
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{block pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1{{insert '_Nullable' if the block pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2{{insert '_Nonnull' if the block pointer should never be null}}
end_comment

begin_comment
comment|// expected-warning@-3{{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-4{{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-5{{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_function_decl
name|void
name|g3
parameter_list|(
name|block_ptr
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{block pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1{{insert '_Nullable' if the block pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2{{insert '_Nonnull' if the block pointer should never be null}}
end_comment

begin_comment
comment|// expected-warning@-3{{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-4{{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-5{{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_function_decl
name|void
name|g4
parameter_list|(
name|int
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g5
parameter_list|(
name|int
function_decl|(
modifier|*
modifier|*
name|fp
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning 2{{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1 2 {{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2 2 {{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_decl_stmt
unit|@
name|interface
name|A
argument_list|(
name|Pragmas1
argument_list|)
decl|+
argument_list|(
name|instancetype
argument_list|)
name|aWithA
range|:
operator|(
name|A
operator|*
operator|)
name|a
decl_stmt|;
end_decl_stmt

begin_expr_stmt
operator|-
operator|(
name|A
operator|*
operator|)
name|method1
operator|:
operator|(
name|A_ptr
operator|)
name|ptr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|null_unspecified
name|A
operator|*
operator|)
name|method2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|method3
operator|:
operator|(
name|NSError
operator|*
operator|*
operator|)
name|error
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-note{{passing argument to parameter 'error' here}}
end_comment

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|method4
operator|:
operator|(
name|NSErrorPtr
operator|*
operator|)
name|error
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-note{{passing argument to parameter 'error' here}}
end_comment

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|method5
operator|:
operator|(
name|NSErrorPtrPtr
operator|)
name|error
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning@-1{{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-2{{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-3{{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_decl_stmt
unit|@
name|property
name|A
modifier|*
name|aProp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|property
name|NSError
modifier|*
modifier|*
name|anError
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning 2{{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1 2 {{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2 2 {{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_decl_stmt
unit|@
name|end
name|int
modifier|*
name|global_int_ptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|// typedefs not inferred _Nonnull
end_comment

begin_typedef
typedef|typedef
name|int
modifier|*
name|int_ptr_2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
modifier|*
comment|// expected-warning{{pointer is missing a nullability type specifier}}
comment|// expected-note@-1{{insert '_Nullable' if the pointer may be null}}
comment|// expected-note@-2{{insert '_Nonnull' if the pointer should never be null}}
modifier|*
name|int_ptr_ptr
typedef|;
end_typedef

begin_function
specifier|static
specifier|inline
name|void
name|f30
parameter_list|(
name|void
parameter_list|)
block|{
name|float
modifier|*
name|fp
init|=
name|global_int_ptr
decl_stmt|;
comment|// expected-error{{cannot initialize a variable of type 'float *' with an lvalue of type 'int * _Nonnull'}}
name|int_ptr_2
name|ip2
decl_stmt|;
name|float
modifier|*
name|fp2
init|=
name|ip2
decl_stmt|;
comment|// expected-error{{cannot initialize a variable of type 'float *' with an lvalue of type 'int_ptr_2' (aka 'int *')}}
name|int_ptr_ptr
name|ipp
decl_stmt|;
name|float
modifier|*
name|fp3
init|=
name|ipp
decl_stmt|;
comment|// expected-error{{lvalue of type 'int_ptr_ptr' (aka 'int **')}}
block|}
end_function

begin_decl_stmt
unit|@
name|interface
name|AA
range|:
name|A
block|{ @
name|public
name|id
name|ivar1
block|;
name|_Nonnull
name|id
name|ivar2
block|; }
expr|@
name|end
pragma|#
directive|pragma
name|clang
name|assume_nonnull
name|end
name|void
name|f20
argument_list|(
name|A
operator|*
name|a
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1{{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2{{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_function_decl
name|void
name|f21
parameter_list|(
name|int_ptr
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1{{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2{{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_function_decl
name|void
name|f22
parameter_list|(
name|A_ptr
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1{{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2{{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_function_decl
name|void
name|f23
parameter_list|(
name|int_ptr
name|_Nullable
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f24
parameter_list|(
name|A_ptr
name|_Nullable
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f25
parameter_list|(
name|int_ptr_2
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1{{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2{{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_decl_stmt
unit|@
name|interface
name|A
argument_list|(
name|OutsidePragmas1
argument_list|)
decl|+
argument_list|(
name|instancetype
argument_list|)
name|aWithInt
range|:
operator|(
name|int
operator|)
name|value
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1{{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2{{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_macro
unit|@
name|end
end_macro

end_unit

