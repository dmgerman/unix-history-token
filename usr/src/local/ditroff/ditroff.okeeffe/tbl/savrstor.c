begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)savrstor.c	1.3 (CWI) 86/11/10"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"ext.h"
end_include

begin_comment
comment|/*  * remembers various things: fill mode, vs, ps in mac 35(SF)  */
end_comment

begin_macro
name|savefill
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|".de %d\n"
argument_list|,
name|SF
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".ps \\n(.s\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".vs \\n(.vu\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".in \\n(.iu\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".if \\n(.u .fi\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".if \\n(.j .ad\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".if \\n(.j=0 .na\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"..\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".nf\n"
argument_list|)
expr_stmt|;
comment|/* #| and #~ give the offsets for hor. and vert. lines 	   (in hundredths of an n) */
switch|switch
condition|(
name|device
condition|)
block|{
case|case
name|HARRIS
case|:
name|printf
argument_list|(
literal|".nr #~ 24\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".nr #| 46\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".nr Tw 22.5c\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|CAT
case|:
case|case
name|DEVVER
case|:
default|default:
name|printf
argument_list|(
literal|".nr #~ 0\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".nr #| 0\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".nr Tw 7.65i\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|DEVPSC
case|:
name|printf
argument_list|(
literal|".nr #~ 0-5\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".nr #| 8\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".nr Tw 7.65i\n"
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* 	 * This is the offset for the T450 boxes see drawvert() 	 */
name|printf
argument_list|(
literal|".if \\n(.T .if n .nr #~ 60\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Call the macro SF (35) to restore collected data  */
end_comment

begin_macro
name|rstofill
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|".%d\n"
argument_list|,
name|SF
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Clean up at end of file?  */
end_comment

begin_macro
name|endoff
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
comment|/* 	 * make some registers to be 0 ... 	 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAXHEAD
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|linestop
index|[
name|i
index|]
condition|)
name|printf
argument_list|(
literal|".nr #%c 0\n"
argument_list|,
literal|'a'
operator|+
name|i
argument_list|)
expr_stmt|;
comment|/* 	 * and remove used macros, strings (and diversions?) 	 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|texct
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|".rm %c+\n"
argument_list|,
name|texstr
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|last
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Let's check wether we are in a diversion  */
end_comment

begin_macro
name|ifdivert
argument_list|()
end_macro

begin_block
block|{
comment|/* 	 * #d hold current vertical place if in a diversion 	 */
name|printf
argument_list|(
literal|".ds #d .d\n"
argument_list|)
expr_stmt|;
comment|/* 	 * if diversion doesn't exist, rememenber current vertical 	 * place (nl) in #d 	 */
name|printf
argument_list|(
literal|".if \\(ts\\n(.z\\(ts\\(ts .ds #d nl\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * save current input line number (of troff), since we are going to add a lot of  * lines  *  * Note that register b. is never set to be auto incremeted, so this  * garanteed to fail!!! (jna)  *  * (should be replaced with a request for new troff)  */
end_comment

begin_macro
name|saveline
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|".if \\n+(b.=1 .nr d. \\n(.c-\\n(c.-1\n"
argument_list|)
expr_stmt|;
name|linstart
operator|=
name|iline
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * rstore line count of troff  */
end_comment

begin_macro
name|restline
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|".if \\n-(b.=0 .nr c. \\n(.c-\\n(d.-%d\n"
argument_list|,
name|iline
operator|-
name|linstart
argument_list|)
expr_stmt|;
name|linstart
operator|=
literal|0
expr_stmt|;
comment|/* 	 * support for .lf request of troff (jna) 	 */
name|printf
argument_list|(
literal|".lf %d\n"
argument_list|,
name|iline
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Turn the field mechanism off  */
end_comment

begin_macro
name|cleanfc
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|".fc\n"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

