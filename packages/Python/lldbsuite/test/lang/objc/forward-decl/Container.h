begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#import<Foundation/Foundation.h>
end_empty

begin_decl_stmt
unit|@
name|class
name|ForwardDeclaredClass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|interface
name|Container
range|:
name|NSObject
block|{ @
name|public
name|ForwardDeclaredClass
operator|*
name|member
block|; }
operator|-
operator|(
name|id
operator|)
name|init
decl_stmt|;
end_decl_stmt

begin_expr_stmt
operator|-
operator|(
name|ForwardDeclaredClass
operator|*
operator|)
name|getMember
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

