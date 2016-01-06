begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
unit|@
name|interface
name|MyBase
range|:
name|NSObject
block|{
if|#
directive|if
operator|!
name|__OBJC2__
name|int
name|maybe_used
block|;
comment|// The 1.0 runtime needs to have backed properties...
endif|#
directive|endif
block|}
expr|@
name|property
name|int
name|propertyMovesThings
decl_stmt|;
end_decl_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

