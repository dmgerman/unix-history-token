begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|"scanner.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)s_inout.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* TWO CHARACTER STACK FOR 'UNGETC' BACKUP */
end_comment

begin_decl_stmt
name|char
name|Pchar
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Pctr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ** GTCHAR ** If 'Lcase' is set, all upper-case alphabetics are  ** mapped into lower-case. ** The correct return is> 0; a return = 0 indicates end-of-file. */
end_comment

begin_macro
name|gtchar
argument_list|()
end_macro

begin_block
block|{
specifier|extern
name|int
name|yyline
decl_stmt|;
specifier|register
name|char
name|chr
decl_stmt|;
comment|/* USE STACKED CHARACTERS IF POSSIBLE */
if|if
condition|(
name|Pctr
condition|)
name|chr
operator|=
name|Pchar
index|[
operator|--
name|Pctr
index|]
expr_stmt|;
else|else
name|chr
operator|=
name|get_scan
argument_list|(
name|NORMAL
argument_list|)
expr_stmt|;
comment|/* UPDATE LINE COUNTER */
if|if
condition|(
name|chr
operator|==
literal|'\n'
condition|)
name|yyline
operator|++
expr_stmt|;
return|return
operator|(
operator|(
name|Lcase
operator|&&
name|chr
operator|>=
literal|'A'
operator|&&
name|chr
operator|<=
literal|'Z'
operator|)
condition|?
operator|(
name|chr
operator|+
operator|(
literal|'a'
operator|-
literal|'A'
operator|)
operator|)
else|:
name|chr
operator|)
return|;
block|}
end_block

begin_comment
comment|/* ** BACKUP ** saves the character argument in the global stack 'Pchar' **/
end_comment

begin_macro
name|backup
argument_list|(
argument|chr
argument_list|)
end_macro

begin_decl_stmt
name|char
name|chr
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|int
name|yyline
decl_stmt|;
if|if
condition|(
name|Pctr
operator|==
literal|2
condition|)
name|syserr
argument_list|(
literal|"overflow in backup()"
argument_list|)
expr_stmt|;
name|Pchar
index|[
name|Pctr
operator|++
index|]
operator|=
name|chr
expr_stmt|;
if|if
condition|(
name|chr
operator|==
literal|'\n'
condition|)
name|yyline
operator|--
expr_stmt|;
block|}
end_block

end_unit

