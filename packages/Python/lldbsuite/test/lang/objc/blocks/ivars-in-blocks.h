begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#import<Foundation/Foundation.h>
end_empty

begin_decl_stmt
unit|@
name|interface
name|IAmBlocky
range|:
name|NSObject
block|{   @
name|public
name|int
name|blocky_ivar
block|; }
operator|+
operator|(
name|void
operator|)
name|classMethod
decl_stmt|;
end_decl_stmt

begin_expr_stmt
operator|-
operator|(
name|IAmBlocky
operator|*
operator|)
name|init
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|int
operator|)
name|callABlock
operator|:
operator|(
name|int
operator|)
name|block_value
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

