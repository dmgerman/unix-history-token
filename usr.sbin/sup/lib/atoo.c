begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator   or   Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the rights  * to redistribute these changes.  */
end_comment

begin_comment
comment|/*  atoo  --  convert ascii to octal  *  *  Usge:  i = atoo (string);  *	unsigned int i;  *	char *string;  *  *  Atoo converts the value contained in "string" into an  *  unsigned integer, assuming that the value represents  *  an octal number.  *  *  HISTORY  * 20-Nov-79  Steven Shafer (sas) at Carnegie-Mellon University  *	Rewritten for VAX.  *  */
end_comment

begin_function
name|unsigned
name|int
name|atoo
parameter_list|(
name|ap
parameter_list|)
name|char
modifier|*
name|ap
decl_stmt|;
block|{
specifier|register
name|unsigned
name|int
name|n
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|ap
expr_stmt|;
name|n
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|*
name|p
operator|==
literal|' '
operator|||
operator|*
name|p
operator|==
literal|'	'
condition|)
name|p
operator|++
expr_stmt|;
while|while
condition|(
operator|*
name|p
operator|>=
literal|'0'
operator|&&
operator|*
name|p
operator|<=
literal|'7'
condition|)
name|n
operator|=
name|n
operator|*
literal|8
operator|+
operator|*
name|p
operator|++
operator|-
literal|'0'
expr_stmt|;
return|return
operator|(
name|n
operator|)
return|;
block|}
end_function

end_unit

