begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"gprof.h"
end_include

begin_comment
comment|/*  * gprof -c isn't currently supported...  */
end_comment

begin_macro
name|findcall
argument_list|(
argument|parentp
argument_list|,
argument|p_lowpc
argument_list|,
argument|p_highpc
argument_list|)
end_macro

begin_decl_stmt
name|nltype
modifier|*
name|parentp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|p_lowpc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|p_highpc
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

end_unit

