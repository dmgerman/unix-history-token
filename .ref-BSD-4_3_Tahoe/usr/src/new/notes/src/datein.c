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
literal|"$Header: datein.c,v 1.7.0.1 85/07/31 14:12:38 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *	getdate - parses the date handed as a string. Format is assumed  *	to be that of CTIME(III).  *		Ray Essick		Feb 1982  *  *	Augmented to understand about lots of different formats -  *	and make use of the getdate(III) routine to parse an  *	almost arbitrary date.  *  *	If the routine is unable to parse a time, the current time  *	is returned.  If the parsed time is in the future, the  *	current time is returned.  *  *	Returns:		0	succesfully parsed past date  *				-1	unsucessful parse  *					returned current time  *				-2	unsuccessful parse  *					returned a future time  *  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mnames
index|[]
decl_stmt|;
end_decl_stmt

begin_macro
name|parsetime
argument_list|(
argument|line
argument_list|,
argument|date
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|line
decl_stmt|;
end_decl_stmt

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
name|month
index|[
literal|100
index|]
decl_stmt|;
name|char
name|weekday
index|[
literal|100
index|]
decl_stmt|;
comment|/* day of week */
name|char
name|zonename
index|[
literal|100
index|]
decl_stmt|;
comment|/* time zone */
name|int
name|day
decl_stmt|,
name|hour
decl_stmt|,
name|min
decl_stmt|,
name|sec
decl_stmt|,
name|year
decl_stmt|;
name|int
name|count
decl_stmt|;
name|long
name|timenow
decl_stmt|;
comment|/* current time */
name|long
name|xtime
decl_stmt|;
comment|/* parsed time */
name|struct
name|when_f
name|now
decl_stmt|;
comment|/* in structure */
name|gettime
argument_list|(
name|date
argument_list|)
expr_stmt|;
comment|/* load current */
name|gettime
argument_list|(
operator|&
name|now
argument_list|)
expr_stmt|;
comment|/* load current */
name|time
argument_list|(
operator|&
name|timenow
argument_list|)
expr_stmt|;
comment|/* seconds GMT */
ifdef|#
directive|ifdef
name|notdef
comment|/*       * apparently there are other formats close enough to ctime      * to fool the sscanf() call into thinking it has succeeded      * when in fact it hasn't.  So we just fall directly      * into the getdate() call.      */
comment|/*       *	First, let's see if the string is CTIME(III) format.      */
if|if
condition|(
name|sscanf
argument_list|(
name|line
argument_list|,
literal|"%s %s %hd %hd:%hd:%hd %hd"
argument_list|,
name|weekday
argument_list|,
name|month
argument_list|,
operator|&
name|day
argument_list|,
operator|&
name|hour
argument_list|,
operator|&
name|min
argument_list|,
operator|&
name|sec
argument_list|,
operator|&
name|year
argument_list|)
operator|==
literal|7
condition|)
block|{
comment|/* yay! */
for|for
control|(
name|count
operator|=
literal|12
init|;
name|count
operator|>
literal|0
condition|;
name|count
operator|--
control|)
if|if
condition|(
name|strcmp
argument_list|(
name|mnames
index|[
name|count
index|]
argument_list|,
name|month
argument_list|)
operator|==
literal|0
condition|)
break|break;
name|date
operator|->
name|w_month
operator|=
name|count
expr_stmt|;
comment|/* place what we got */
name|date
operator|->
name|w_day
operator|=
name|day
expr_stmt|;
name|date
operator|->
name|w_hours
operator|=
name|hour
expr_stmt|;
name|date
operator|->
name|w_mins
operator|=
name|min
expr_stmt|;
name|date
operator|->
name|w_year
operator|=
name|year
expr_stmt|;
name|date
operator|->
name|w_gmttime
operator|=
literal|0
expr_stmt|;
comment|/*  	 *	We should check that it isn't in the future here 	 */
return|return
literal|0
return|;
block|}
endif|#
directive|endif
comment|/*       *	Ok, now it's time to call in the big artillery -- GETDATE      */
name|xtime
operator|=
name|getdate
argument_list|(
name|line
argument_list|,
operator|(
expr|struct
name|timeb
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
comment|/* parse */
if|if
condition|(
name|xtime
operator|<
literal|0
condition|)
comment|/* success? */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* failure */
name|maketime
argument_list|(
name|date
argument_list|,
operator|(
name|long
operator|)
name|xtime
argument_list|)
expr_stmt|;
comment|/* encode */
if|if
condition|(
name|xtime
operator|>
name|timenow
condition|)
comment|/* future shock */
return|return
operator|(
operator|-
literal|2
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

