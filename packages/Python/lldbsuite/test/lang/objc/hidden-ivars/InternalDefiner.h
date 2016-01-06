begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#import<Foundation/Foundation.h>
end_empty

begin_empty
empty|#import<stdint.h>
end_empty

begin_decl_stmt
unit|@
name|interface
name|InternalDefiner
range|:
name|NSObject
block|{ @
name|public
name|uintptr_t
name|foo
block|; }
operator|-
operator|(
name|id
operator|)
name|initWithFoo
operator|:
operator|(
name|uintptr_t
operator|)
name|f
name|andBar
operator|:
operator|(
name|uintptr_t
operator|)
name|b
decl_stmt|;
end_decl_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

