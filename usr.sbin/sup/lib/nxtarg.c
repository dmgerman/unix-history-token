begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator   or   Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the rights  * to redistribute these changes.  */
end_comment

begin_comment
comment|/*  *  nxtarg -- strip off arguments from a string  *  *  Usage:  p = nxtarg (&q,brk);  *	char *p,*q,*brk;  *	extern char _argbreak;  *  *	q is pointer to next argument in string  *	after call, p points to string containing argument,  *	q points to remainder of string  *  *  Leading blanks and tabs are skipped; the argument ends at the  *  first occurence of one of the characters in the string "brk".  *  When such a character is found, it is put into the external  *  variable "_argbreak", and replaced by a null character; if the  *  arg string ends before that, then the null character is  *  placed into _argbreak;  *  If "brk" is 0, then " " is substituted.  *  *  HISTORY  * 01-Jul-83  Steven Shafer (sas) at Carnegie-Mellon University  *	Bug fix: added check for "back>= front" in loop to chop trailing  *	white space.  *  * 20-Nov-79  Steven Shafer (sas) at Carnegie-Mellon University  *	Rewritten for VAX.  By popular demand, a table of break characters  *	has been added (implemented as a string passed into nxtarg).  *  *  Originally	from klg (Ken Greer); IUS/SUS UNIX.  */
end_comment

begin_decl_stmt
name|char
name|_argbreak
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|skipto
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|char
modifier|*
name|nxtarg
parameter_list|(
name|q
parameter_list|,
name|brk
parameter_list|)
name|char
modifier|*
modifier|*
name|q
decl_stmt|,
decl|*
name|brk
decl_stmt|;
end_function

begin_block
block|{
specifier|register
name|char
modifier|*
name|front
decl_stmt|,
modifier|*
name|back
decl_stmt|;
name|front
operator|=
operator|*
name|q
expr_stmt|;
comment|/* start of string */
comment|/* leading blanks and tabs */
while|while
condition|(
operator|*
name|front
operator|&&
operator|(
operator|*
name|front
operator|==
literal|' '
operator|||
operator|*
name|front
operator|==
literal|'\t'
operator|)
condition|)
name|front
operator|++
expr_stmt|;
comment|/* find break character at end */
if|if
condition|(
name|brk
operator|==
literal|0
condition|)
name|brk
operator|=
literal|" "
expr_stmt|;
name|back
operator|=
name|skipto
argument_list|(
name|front
argument_list|,
name|brk
argument_list|)
expr_stmt|;
name|_argbreak
operator|=
operator|*
name|back
expr_stmt|;
operator|*
name|q
operator|=
operator|(
operator|*
name|back
condition|?
name|back
operator|+
literal|1
else|:
name|back
operator|)
expr_stmt|;
comment|/* next arg start loc */
comment|/* elim trailing blanks and tabs */
name|back
operator|-=
literal|1
expr_stmt|;
while|while
condition|(
operator|(
name|back
operator|>=
name|front
operator|)
operator|&&
operator|(
operator|*
name|back
operator|==
literal|' '
operator|||
operator|*
name|back
operator|==
literal|'\t'
operator|)
condition|)
name|back
operator|--
expr_stmt|;
name|back
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|back
condition|)
operator|*
name|back
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|front
operator|)
return|;
block|}
end_block

end_unit

