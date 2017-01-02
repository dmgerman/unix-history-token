begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X.h>
end_include

begin_macro
name|__attribute__
argument_list|(
argument|(availability(macosx,introduced=
literal|1066.0
argument|))
argument_list|)
end_macro

begin_expr_stmt
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|ios
argument_list|,
name|introduced
operator|=
literal|1066.0
argument_list|)
operator|)
argument_list|)
expr|@
name|interface
name|UnavailableObjCClass
operator|:
name|NSObject
operator|-
operator|(
name|void
operator|)
name|someMethod
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

