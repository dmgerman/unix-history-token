begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<aux.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)out_arg.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  OUTPUT ARGUMENTS GLOBAL INITIALIZATION */
end_comment

begin_decl_stmt
name|struct
name|out_arg
name|Out_arg
init|=
comment|/* output arguments */
block|{
literal|6
block|,
comment|/* c0width */
literal|6
block|,
comment|/* i1width */
literal|6
block|,
comment|/* i2width */
literal|13
block|,
comment|/* i4width */
literal|10
block|,
comment|/* f4width */
literal|10
block|,
comment|/* f8width */
literal|3
block|,
comment|/* f4prec */
literal|3
block|,
comment|/* f8prec */
literal|'n'
block|,
comment|/* f4style */
literal|'n'
block|,
comment|/* f8style */
literal|66
block|,
comment|/* linesperpage */
literal|'|'
block|,
comment|/* coldelim */
block|}
decl_stmt|;
end_decl_stmt

end_unit

