begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// PR3588
end_comment

begin_function_decl
name|void
name|g0
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g0
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_function
name|void
name|f0
parameter_list|()
block|{
name|g0
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// expected-error{{too many arguments to function call}}
block|}
end_function

begin_function_decl
name|void
name|g0
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{conflicting types for 'g0'}}
end_comment

begin_function_decl
name|int
name|g1
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
name|INT
typedef|;
end_typedef

begin_function
name|INT
name|g1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|{
return|return
name|x
operator|+
name|y
return|;
block|}
end_function

begin_function_decl
name|int
name|g2
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_function
name|INT
name|g2
parameter_list|(
name|x
parameter_list|)
comment|// expected-error{{conflicting types for 'g2'}}
name|int
name|x
decl_stmt|;
block|{
return|return
name|x
return|;
block|}
end_function

begin_function
name|void
name|test
parameter_list|()
block|{
name|int
name|f1
decl_stmt|;
block|{
name|void
name|f1
argument_list|(
name|double
argument_list|)
decl_stmt|;
block|{
name|void
name|f1
argument_list|(
name|double
argument_list|)
decl_stmt|;
comment|// expected-note{{previous declaration is here}}
block|{
name|int
name|f1
argument_list|(
name|int
argument_list|)
decl_stmt|;
comment|// expected-error{{conflicting types for 'f1'}}
block|}
block|}
block|}
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|g3
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_function
specifier|static
name|void
name|g3
parameter_list|(
name|int
name|x
parameter_list|)
block|{ }
end_function

begin_comment
comment|// expected-error{{static declaration of 'g3' follows non-static declaration}}
end_comment

begin_function
name|void
name|test2
parameter_list|()
block|{
specifier|extern
name|int
name|f2
decl_stmt|;
comment|// expected-note 2 {{previous definition is here}}
block|{
name|void
name|f2
argument_list|(
name|int
argument_list|)
decl_stmt|;
comment|// expected-error{{redefinition of 'f2' as different kind of symbol}}
block|}
block|{
name|int
name|f2
decl_stmt|;
block|{
name|void
name|f2
argument_list|(
name|int
argument_list|)
decl_stmt|;
comment|// expected-error{{redefinition of 'f2' as different kind of symbol}}
block|}
block|}
block|}
end_function

begin_comment
comment|//<rdar://problem/6127293>
end_comment

begin_function_decl
name|int
name|outer1
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_struct
struct|struct
name|outer3
block|{ }
struct|;
end_struct

begin_function_decl
name|int
name|outer4
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|outer5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

begin_function_decl
name|int
modifier|*
name|outer7
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|outer_test
parameter_list|()
block|{
name|int
name|outer1
argument_list|(
name|float
argument_list|)
decl_stmt|;
comment|// expected-error{{conflicting types for 'outer1'}}
name|int
name|outer2
argument_list|(
name|int
argument_list|)
decl_stmt|;
comment|// expected-note{{previous declaration is here}}
name|int
name|outer3
argument_list|(
name|int
argument_list|)
decl_stmt|;
comment|// expected-note{{previous declaration is here}}
name|int
name|outer4
argument_list|(
name|int
argument_list|)
decl_stmt|;
comment|// expected-note{{previous declaration is here}}
name|int
name|outer5
argument_list|(
name|int
argument_list|)
decl_stmt|;
comment|// expected-error{{redefinition of 'outer5' as different kind of symbol}}
name|int
modifier|*
name|outer6
argument_list|(
name|int
argument_list|)
decl_stmt|;
comment|// expected-note{{previous declaration is here}}
name|int
modifier|*
name|outer7
argument_list|(
name|int
argument_list|)
decl_stmt|;
name|int
name|outer8
argument_list|(
name|int
argument_list|)
decl_stmt|;
name|int
modifier|*
name|ip7
init|=
name|outer7
argument_list|(
literal|6
argument_list|)
decl_stmt|;
block|}
end_function

begin_function_decl
name|int
name|outer2
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{conflicting types for 'outer2'}}
end_comment

begin_function_decl
name|int
name|outer3
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{conflicting types for 'outer3'}}
end_comment

begin_function_decl
name|int
name|outer4
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{conflicting types for 'outer4'}}
end_comment

begin_function
name|void
name|outer_test2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
modifier|*
name|ip
init|=
name|outer6
argument_list|(
name|x
argument_list|)
decl_stmt|;
comment|// expected-warning{{use of out-of-scope declaration of 'outer6'}}
name|int
modifier|*
name|ip2
init|=
name|outer7
argument_list|(
name|x
argument_list|)
decl_stmt|;
block|}
end_function

begin_function
name|void
name|outer_test3
parameter_list|()
block|{
name|int
modifier|*
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
name|outer8
function_decl|;
comment|// expected-error{{use of undeclared identifier 'outer8'}}
block|}
end_function

begin_function_decl
specifier|static
name|float
name|outer8
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// okay
end_comment

begin_enum
enum|enum
name|e
block|{
name|e1
block|,
name|e2
block|}
enum|;
end_enum

begin_comment
comment|// GNU extension: prototypes and K&R function definitions
end_comment

begin_function_decl
name|int
name|isroot
parameter_list|(
name|short
name|x
parameter_list|,
comment|// expected-note{{previous declaration is here}}
name|enum
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|isroot
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
name|short
name|x
decl_stmt|;
comment|// expected-warning{{promoted type 'int' of K&R function parameter is not compatible with the parameter type 'short' declared in a previous prototype}}
name|unsigned
name|int
name|y
decl_stmt|;
block|{
return|return
name|x
operator|==
literal|1
return|;
block|}
end_function

begin_comment
comment|// PR3817
end_comment

begin_function_decl
name|void
modifier|*
name|h0
parameter_list|(
name|unsigned
name|a0
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern __typeof (h0
end_extern

begin_decl_stmt
unit|)
name|h1
name|__attribute__
argument_list|(
operator|(
name|__sentinel__
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern __typeof (h1
end_extern

begin_decl_stmt
unit|)
name|h1
name|__attribute__
argument_list|(
operator|(
name|__sentinel__
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR3840
end_comment

begin_function_decl
name|void
name|i0
parameter_list|(
name|unsigned
name|short
name|a0
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern __typeof (i0
end_extern

begin_expr_stmt
unit|)
name|i1
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern __typeof (i1
end_extern

begin_expr_stmt
unit|)
name|i1
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|int
name|a
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|a2
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|a
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|a2
name|x2
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_x
parameter_list|()
block|{
name|x
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|x2
argument_list|(
literal|5
argument_list|)
expr_stmt|;
comment|// expected-warning{{incompatible integer to pointer conversion passing 'int', expected 'int *'}}
block|}
end_function

end_unit

