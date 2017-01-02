begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
name|int
modifier|*
name|_Nonnull
name|forceNullabilityWarnings
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arrayParameter
parameter_list|(
name|int
name|x
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{array parameter is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1 {{insert '_Nullable'}}
end_comment

begin_comment
comment|// expected-note@-2 {{insert '_Nonnull'}}
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}nullability.h":{[[@LINE-3]]:27-[[@LINE-3]]:27}:"_Nullable"
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}nullability.h":{[[@LINE-4]]:27-[[@LINE-4]]:27}:"_Nonnull"
end_comment

begin_function_decl
name|void
name|arrayParameterWithSize
parameter_list|(
name|int
name|x
index|[
literal|5
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{array parameter is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1 {{insert '_Nullable'}}
end_comment

begin_comment
comment|// expected-note@-2 {{insert '_Nonnull'}}
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}nullability.h":{[[@LINE-3]]:35-[[@LINE-3]]:35}:"_Nullable "
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}nullability.h":{[[@LINE-4]]:35-[[@LINE-4]]:35}:"_Nonnull "
end_comment

begin_function_decl
name|void
name|arrayParameterWithStar
parameter_list|(
name|int
name|x
index|[
operator|*
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{array parameter is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1 {{insert '_Nullable'}}
end_comment

begin_comment
comment|// expected-note@-2 {{insert '_Nonnull'}}
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}nullability.h":{[[@LINE-3]]:35-[[@LINE-3]]:35}:"_Nullable "
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}nullability.h":{[[@LINE-4]]:35-[[@LINE-4]]:35}:"_Nonnull "
end_comment

begin_comment
comment|// No fix-its on either the macro definition or instantiation.
end_comment

begin_comment
comment|// CHECK-NOT: fix-it:"{{.*}}nullability.h":{[[@LINE+2]]
end_comment

begin_comment
comment|// CHECK-NOT: fix-it:"{{.*}}nullability.h":{[[@LINE+2]]
end_comment

begin_define
define|#
directive|define
name|PTR
parameter_list|(
name|X
parameter_list|)
value|X *
end_define

begin_macro
name|PTR
argument_list|(
argument|int
argument_list|)
end_macro

begin_expr_stmt
name|a
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning{{pointer is missing a nullability type specifier}}
end_comment

begin_undef
undef|#
directive|undef
name|PTR
end_undef

end_unit

