begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"monitor.h"
end_include

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
argument|@(#)print.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  PRINT QUERY BUFFER ** **	The logical query buffer is printed on the terminal regardless **	of the "Nodayfile" mode.  Autoclear is reset, so the query **	may be rerun. ** **	Uses trace flag 6 */
end_comment

begin_macro
name|print
argument_list|()
end_macro

begin_block
block|{
name|FILE
modifier|*
name|iop
decl_stmt|;
specifier|register
name|char
name|c
decl_stmt|;
comment|/* BACK UP FILE& UPDATE LAST PAGE */
name|Autoclear
operator|=
literal|0
expr_stmt|;
name|clrline
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|Qryiop
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|iop
operator|=
name|fopen
argument_list|(
name|Qbname
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|syserr
argument_list|(
literal|"print: open 1"
argument_list|)
expr_stmt|;
comment|/* list file on standard output */
name|Notnull
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|iop
argument_list|)
operator|)
operator|>
literal|0
condition|)
block|{
name|putchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|Notnull
operator|++
expr_stmt|;
block|}
name|fclose
argument_list|(
name|iop
argument_list|)
expr_stmt|;
name|cgprompt
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

