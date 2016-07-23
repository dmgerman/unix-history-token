begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|clang
name|system_header
end_pragma

begin_define
define|#
directive|define
name|nil
value|0
end_define

begin_define
define|#
directive|define
name|BOOL
value|int
end_define

begin_define
define|#
directive|define
name|NS_ASSUME_NONNULL_BEGIN
value|_Pragma("clang assume_nonnull begin")
end_define

begin_define
define|#
directive|define
name|NS_ASSUME_NONNULL_END
value|_Pragma("clang assume_nonnull end")
end_define

begin_macro
name|NS_ASSUME_NONNULL_BEGIN
end_macro

begin_typedef
typedef|typedef
name|struct
name|_NSZone
name|NSZone
typedef|;
end_typedef

begin_expr_stmt
unit|@
name|protocol
name|NSObject
operator|+
operator|(
name|instancetype
operator|)
name|alloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|instancetype
operator|)
name|init
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|instancetype
operator|)
name|autorelease
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|protocol
name|NSCopying
operator|-
operator|(
name|id
operator|)
name|copyWithZone
operator|:
operator|(
name|nullable
name|NSZone
operator|*
operator|)
name|zone
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|protocol
name|NSMutableCopying
operator|-
operator|(
name|id
operator|)
name|mutableCopyWithZone
operator|:
operator|(
name|nullable
name|NSZone
operator|*
operator|)
name|zone
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|@
name|end
name|__attribute__
argument_list|(
operator|(
name|objc_root_class
operator|)
argument_list|)
decl|@
name|interface
name|NSObject
decl|<
name|NSObject
decl|> @
name|end
decl|@
name|interface
name|NSString
range|:
name|NSObject
operator|<
name|NSCopying
operator|>
operator|-
operator|(
name|BOOL
operator|)
name|isEqualToString
operator|:
operator|(
name|NSString
operator|*
operator|)
name|aString
decl_stmt|;
end_decl_stmt

begin_expr_stmt
operator|-
operator|(
name|NSString
operator|*
operator|)
name|stringByAppendingString
operator|:
operator|(
name|NSString
operator|*
operator|)
name|aString
expr_stmt|;
end_expr_stmt

begin_function_decl
unit|@
name|end
name|void
name|NSSystemFunctionTakingNonnull
parameter_list|(
name|NSString
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
unit|@
name|interface
name|NSSystemClass
range|:
name|NSObject
operator|-
operator|(
name|void
operator|)
name|takesNonnull
operator|:
operator|(
name|NSString
operator|*
operator|)
name|s
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|@
name|end
name|NS_ASSUME_NONNULL_END
end_expr_stmt

end_unit

