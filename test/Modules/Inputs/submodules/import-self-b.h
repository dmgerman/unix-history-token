begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// FIXME: This import has no effect, because the submodule isn't built yet, and
end_comment

begin_comment
comment|// we don't map an @import to a #include in this case.
end_comment

begin_decl_stmt
unit|@
name|import
name|import_self
operator|.
name|c
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"import-self-d.h"
end_include

begin_comment
comment|// FIXME: This should not work; names from 'a' should not be visible here.
end_comment

begin_decl_stmt
name|MyTypeA
name|import_self_test_a
decl_stmt|;
end_decl_stmt

begin_comment
comment|// FIXME: This should work but does not; names from 'c' are not actually visible here.
end_comment

begin_comment
comment|//MyTypeC import_self_test_c;
end_comment

begin_decl_stmt
name|MyTypeD
name|import_self_test_d
decl_stmt|;
end_decl_stmt

end_unit

