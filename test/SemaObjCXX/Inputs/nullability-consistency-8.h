begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
name|int
modifier|*
name|_Nonnull
name|mynonnull
typedef|;
end_typedef

begin_expr_stmt
name|__attribute__
argument_list|(
operator|(
name|objc_root_class
operator|)
argument_list|)
expr|@
name|interface
name|typedefClass
operator|-
operator|(
name|void
operator|)
name|func1
operator|:
operator|(
name|mynonnull
operator|)
name|i
expr_stmt|;
end_expr_stmt

begin_function_decl
unit|@
name|end
name|void
name|func2
parameter_list|(
name|mynonnull
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|func3
parameter_list|(
name|int
modifier|*
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

begin_define
define|#
directive|define
name|CF_RETURNS_NOT_RETAINED
value|__attribute__((cf_returns_not_retained))
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|CFTypeRef
typedef|;
end_typedef

begin_function_decl
name|void
name|cf1
parameter_list|(
name|CFTypeRef
modifier|*
name|p
name|CF_RETURNS_NOT_RETAINED
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
name|cf2
parameter_list|(
name|CFTypeRef
modifier|*
name|_Nullable
name|p
name|CF_RETURNS_NOT_RETAINED
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cf3
parameter_list|(
name|CFTypeRef
modifier|*
name|_Nonnull
name|p
name|CF_RETURNS_NOT_RETAINED
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cf4
parameter_list|(
name|CFTypeRef
name|_Nullable
modifier|*
name|_Nullable
name|p
name|CF_RETURNS_NOT_RETAINED
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cf5
parameter_list|(
name|CFTypeRef
name|_Nonnull
modifier|*
name|_Nullable
name|p
name|CF_RETURNS_NOT_RETAINED
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cf6
parameter_list|(
name|CFTypeRef
modifier|*
name|_Nullable
name|CF_RETURNS_NOT_RETAINED
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cf7
parameter_list|(
name|CF_RETURNS_NOT_RETAINED
name|CFTypeRef
modifier|*
name|_Nonnull
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|CFTypeRef
name|_Nullable
modifier|*
name|CFTypeRefPtr
typedef|;
end_typedef

begin_function_decl
name|void
name|cfp1
parameter_list|(
name|CFTypeRefPtr
name|p
name|CF_RETURNS_NOT_RETAINED
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
name|cfp2
parameter_list|(
name|CFTypeRefPtr
name|_Nonnull
name|p
name|CF_RETURNS_NOT_RETAINED
parameter_list|)
function_decl|;
end_function_decl

end_unit

