begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<pv.h>
end_include

begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<func.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)rupdate.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|short
name|tTdbu
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|rupdate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|null_fn
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|fn_def
name|RupdatFn
init|=
block|{
literal|"RUPDATE"
block|,
name|rupdate
block|,
name|null_fn
block|,
comment|/* initialization function */
name|null_fn
block|,
name|NULL
block|,
literal|0
block|,
name|tTdbu
block|,
literal|100
block|,
literal|'Z'
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  RUBOUT SETUP FOR DEFFERED UPDATE PROCESSOR ** **	These routines setup the special processing for the rubout **	signal for the deferred update processor.  The update **	processor is then called. */
end_comment

begin_macro
name|rupdate
argument_list|(
argument|pc
argument_list|,
argument|pv
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PARM
name|pv
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|rtval
decl_stmt|;
comment|/* set up special signal processing */
name|ruboff
argument_list|(
literal|"batch update"
argument_list|)
expr_stmt|;
comment|/* call update */
name|rtval
operator|=
name|update
argument_list|(
name|pc
argument_list|,
name|pv
argument_list|)
expr_stmt|;
comment|/* clean up signals */
name|rubon
argument_list|()
expr_stmt|;
return|return
operator|(
name|rtval
operator|)
return|;
block|}
end_block

end_unit

