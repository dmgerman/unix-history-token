begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"parms.h"
end_include

begin_include
include|#
directive|include
file|"structs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RCSIDENT
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Header: gdate.c,v 1.7.0.1 85/09/09 18:32:11 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  * this gdate routine reads a "search date" from the keyboard.  This date  * must be of the form mm/dd or mm/dd/yy (number of digits in each is  * irrelevant).  it sets the date parameter correctly to the input or  * returns -1 to indicate failure to complete a date (i.e., a return alone  * was entered on a line).  If the date is invalid, it must be retyped.  * I know it is unfortunate that we can't have a plato arrow type judging  * system here.  I just don't want to go to all the hassle of making one now.  * perhaps this is an area of improvement for this program.  RK  11/10/80.  *  *	Rewritten to use the parsetime() routine which understands  *	about converting ASCII time specifications into a UNIX  *	Internal time.    *		-- Ray Essick, March 1984  *  */
end_comment

begin_define
define|#
directive|define
name|TIMELEN
value|40
end_define

begin_comment
comment|/* longest time spec */
end_comment

begin_macro
name|gdate
argument_list|(
argument|date
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|when_f
modifier|*
name|date
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|datin
index|[
name|TIMELEN
operator|+
literal|1
index|]
decl_stmt|,
name|fmt
index|[
name|DATELEN
index|]
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|,
name|pass
decl_stmt|;
name|struct
name|when_f
name|tmpdate
decl_stmt|;
comment|/* hold it */
name|pass
operator|=
literal|0
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
name|sprdate
argument_list|(
name|date
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
comment|/* current setting */
name|at
argument_list|(
literal|0
argument_list|,
name|PROMPTMSGX
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Set to read notes since: %-*s"
argument_list|,
name|DATELEN
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|at
argument_list|(
operator|-
literal|1
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"New Date> %*s"
argument_list|,
name|TIMELEN
argument_list|,
literal|" "
argument_list|)
expr_stmt|;
name|at
argument_list|(
operator|-
literal|1
argument_list|,
literal|21
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|TIMELEN
condition|;
name|i
operator|++
control|)
name|datin
index|[
name|i
index|]
operator|=
literal|' '
expr_stmt|;
if|if
condition|(
name|gline
argument_list|(
name|datin
argument_list|,
name|TIMELEN
argument_list|)
operator|==
literal|1
condition|)
block|{
comment|/* empty line */
name|at
argument_list|(
operator|-
literal|1
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%*s"
argument_list|,
literal|23
operator|+
name|TIMELEN
argument_list|,
literal|" "
argument_list|)
expr_stmt|;
comment|/* space padding */
if|if
condition|(
name|pass
condition|)
return|return
literal|0
return|;
comment|/* ok */
else|else
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* 1st pass return */
block|}
switch|switch
condition|(
name|parsetime
argument_list|(
name|datin
argument_list|,
operator|&
name|tmpdate
argument_list|)
condition|)
comment|/* parsed? */
block|{
case|case
literal|0
case|:
comment|/* worked */
operator|*
name|date
operator|=
name|tmpdate
expr_stmt|;
comment|/* transfer it */
name|pass
operator|++
expr_stmt|;
comment|/* count passes */
break|break;
default|default:
comment|/* failures */
name|putc
argument_list|(
literal|'\07'
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
comment|/* bark at him */
break|break;
block|}
block|}
comment|/*	yes, we know about the fact that this statement is unreachable! */
return|return
literal|0
return|;
comment|/* never executed */
block|}
end_block

end_unit

