begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|XPX
end_ifdef

begin_comment
comment|/*  * proc(x,args) - convert x to a procedure if possible; use args to  *  resolve ambiguous string names.  */
end_comment

begin_macro
name|Xproc
argument_list|(
argument|nargs
argument_list|,
argument|arg2
argument_list|,
argument|arg1
argument_list|,
argument|arg0
argument_list|)
end_macro

begin_decl_stmt
name|int
name|nargs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|arg2
decl_stmt|,
name|arg1
decl_stmt|,
name|arg0
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/*     * If x is already a proc, just return it in arg0.     */
name|arg0
operator|=
name|arg1
expr_stmt|;
name|DeRef
argument_list|(
argument|arg0
argument_list|)
if|if
condition|(
operator|!
name|QUAL
argument_list|(
name|arg0
argument_list|)
operator|&&
name|TYPE
argument_list|(
name|arg0
argument_list|)
operator|==
name|T_PROC
condition|)
return|return;
comment|/*     * args defaults to 1.     */
name|defshort
argument_list|(
operator|&
name|arg2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/*     * Attempt to convert arg0 to a procedure descriptor using args to     *  discriminate between procedures with the same names.  Fail if     *  the conversion isn't successful.     */
if|if
condition|(
name|strprc
argument_list|(
operator|&
name|arg0
argument_list|,
name|INTVAL
argument_list|(
name|arg2
argument_list|)
argument_list|)
condition|)
return|return;
else|else
name|fail
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|Procblock
argument_list|(
argument|proc
argument_list|,
literal|2
argument_list|)
end_macro

begin_else
else|#
directive|else
else|XPX
end_else

begin_decl_stmt
name|char
name|junk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* prevent null object file */
end_comment

begin_endif
endif|#
directive|endif
endif|XPX
end_endif

end_unit

