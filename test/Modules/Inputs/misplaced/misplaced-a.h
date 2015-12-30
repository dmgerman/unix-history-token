begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|namespace
name|A
block|{
name|namespace
name|B
block|{
comment|// expected-note{{namespace 'A::B' begins here}}
include|#
directive|include
file|"misplaced-b.h"
comment|// expected-error{{import of module 'Misplaced.Sub_B' appears within namespace 'A::B'}}
block|}
block|}
end_decl_stmt

end_unit

