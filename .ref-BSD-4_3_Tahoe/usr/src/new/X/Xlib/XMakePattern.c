begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: XMakePattern.c,v 1.1 86/04/22 15:15:16 jg Rel $ */
end_comment

begin_comment
comment|/*   * XMakePattern.c - Substitute for macro in the library  *   * Author:	Scott Nettles  * 		Digital Equipment Corporation  * 		Western Research Laboratory  * Date:	Sat Aug 24 1985  */
end_comment

begin_comment
comment|/* $Log:	XMakePattern.c,v $  * Revision 1.1  86/04/22  15:15:16  jg  * Changes to hide protocol better for BIGSHORTS  *   * Revision 1.1  85/12/05  13:34:57  nettles  * Initial revision  *  */
end_comment

begin_decl_stmt
specifier|static
name|char
name|rcs_ident
index|[]
init|=
literal|"$Header: XMakePattern.c,v 1.1 86/04/22 15:15:16 jg Rel $"
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|long
name|Pattern
typedef|;
end_typedef

begin_function
name|Pattern
name|XMakePattern
parameter_list|(
name|pattern
parameter_list|,
name|patlen
parameter_list|,
name|patmul
parameter_list|)
name|int
name|pattern
decl_stmt|,
name|patlen
decl_stmt|,
name|patmul
decl_stmt|;
block|{
return|return
operator|(
call|(
name|Pattern
call|)
argument_list|(
operator|(
operator|(
name|patmul
operator|)
operator|<<
literal|20
operator|)
operator||
operator|(
operator|(
operator|(
name|patlen
operator|)
operator|-
literal|1
operator|)
operator|<<
literal|16
operator|)
operator||
operator|(
name|pattern
operator|)
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

