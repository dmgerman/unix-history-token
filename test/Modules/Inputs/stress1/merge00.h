begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|STRESS1_MERGE00_H
end_ifndef

begin_define
define|#
directive|define
name|STRESS1_MERGE00_H
end_define

begin_comment
comment|// These don't match the imported declarations because we import them from
end_comment

begin_comment
comment|// modules which are built in isolation of the current header's pragma state
end_comment

begin_comment
comment|// much like they are built in isolation of the incoming macro state.
end_comment

begin_comment
comment|// FIXME: We should expect warnings here but we can't because verify doesn't
end_comment

begin_comment
comment|// work for modules.
end_comment

begin_comment
comment|//#pragma weak pragma_weak01 // expected-warning {{weak identifier 'pragma_weak01' never declared}}
end_comment

begin_comment
comment|//#pragma weak pragma_weak04 // expected-warning {{weak identifier 'pragma_waek04' never declared}}
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MERGE_NO_REEXPORT
end_ifdef

begin_include
include|#
directive|include
file|"merge_no_reexport.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"m00.h"
end_include

begin_include
include|#
directive|include
file|"m01.h"
end_include

begin_include
include|#
directive|include
file|"m02.h"
end_include

begin_include
include|#
directive|include
file|"m03.h"
end_include

begin_function
specifier|inline
name|int
name|g
parameter_list|()
block|{
return|return
name|N00
operator|::
name|S00
argument_list|(
literal|'a'
argument_list|)
operator|.
name|method00
argument_list|(
literal|'b'
argument_list|)
operator|+
operator|(
name|int
operator|)
name|S00
argument_list|(
literal|42
argument_list|)
operator|+
name|function00
argument_list|(
literal|42
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Use implicit special memebers again for S01 to ensure that we merge them in
end_comment

begin_comment
comment|// successfully from m01.
end_comment

begin_expr_stmt
specifier|inline
name|N00
operator|::
name|S01
name|h
argument_list|()
block|{
return|return
name|N00
operator|::
name|S01
argument_list|()
return|;
block|}
end_expr_stmt

begin_pragma
pragma|#
directive|pragma
name|weak
name|pragma_weak02
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pragma_weak05
end_pragma

begin_extern
extern|extern
literal|"C"
name|int
name|pragma_weak02
parameter_list|()
function_decl|;
end_extern

begin_decl_stmt
name|int
name|pragma_weak05
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

