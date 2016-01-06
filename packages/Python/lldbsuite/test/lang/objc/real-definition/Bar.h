begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#import<Foundation/Foundation.h>
end_empty

begin_decl_stmt
unit|@
name|class
name|InternalClass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|interface
name|Bar
range|:
name|NSObject
block|{     @
name|private
name|InternalClass
operator|*
name|storage
block|; }
operator|-
operator|(
name|NSString
operator|*
operator|)
name|description
decl_stmt|;
end_decl_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

