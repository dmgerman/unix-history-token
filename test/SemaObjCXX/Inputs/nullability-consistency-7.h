begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|SOMEKIT_H
end_ifndef

begin_define
define|#
directive|define
name|SOMEKIT_H
end_define

begin_macro
name|__attribute__
argument_list|(
argument|(objc_root_class)
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|NS_ASSUME_NONNULL_BEGIN
end_ifndef

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|assume_nonnull
argument_list|)
end_if

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NS_ASSUME_NONNULL_BEGIN
end_define

begin_define
define|#
directive|define
name|NS_ASSUME_NONNULL_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|NS_ASSUME_NONNULL_BEGIN
expr|@
name|interface
name|A
operator|-
operator|(
name|null_unspecified
name|A
operator|*
operator|)
name|transform
operator|:
operator|(
name|null_unspecified
name|A
operator|*
operator|)
name|input
name|__attribute__
argument_list|(
operator|(
name|unavailable
argument_list|(
literal|"anything but this"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|A
operator|*
operator|)
name|transform
operator|:
operator|(
name|A
operator|*
operator|)
name|input
name|integer
operator|:
operator|(
name|int
operator|)
name|integer
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|property
argument_list|(
argument|null_unspecified
argument_list|,
argument|nonatomic
argument_list|,
argument|readonly
argument_list|,
argument|retain
argument_list|)
end_macro

begin_decl_stmt
name|A
modifier|*
name|someA
decl_stmt|;
end_decl_stmt

begin_macro
unit|@
name|property
argument_list|(
argument|null_unspecified
argument_list|,
argument|nonatomic
argument_list|,
argument|retain
argument_list|)
end_macro

begin_decl_stmt
name|A
modifier|*
name|someOtherA
decl_stmt|;
end_decl_stmt

begin_macro
unit|@
name|property
argument_list|(
argument|nonatomic
argument_list|)
end_macro

begin_decl_stmt
name|int
name|intValue
name|__attribute__
argument_list|(
operator|(
name|unavailable
argument_list|(
literal|"wouldn't work anyway"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|end
name|NS_ASSUME_NONNULL_END
name|__attribute__
argument_list|(
operator|(
name|unavailable
argument_list|(
literal|"just don't"
argument_list|)
operator|)
argument_list|)
decl|@
name|interface
name|B
range|:
name|A
expr|@
name|end
expr|@
name|interface
name|C
operator|:
name|A
operator|-
operator|(
name|instancetype
operator|)
name|init
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

begin_expr_stmt
operator|-
operator|(
name|instancetype
operator|)
name|initWithA
operator|:
operator|(
name|A
operator|*
operator|)
name|a
name|__attribute__
argument_list|(
operator|(
name|objc_designated_initializer
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning 2{{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1 2{{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2 2{{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_macro
unit|@
name|end
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

