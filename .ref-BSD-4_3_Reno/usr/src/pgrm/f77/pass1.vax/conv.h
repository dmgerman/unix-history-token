begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)conv.h	5.1 (Berkeley) 6/7/85  */
end_comment

begin_if
if|#
directive|if
operator|(
name|HERE
operator|!=
name|VAX
operator|||
name|TARGET
operator|!=
name|VAX
operator|)
end_if

begin_expr_stmt
unit|}}}}}	WRONG
name|MACHINE
operator|!
operator|!
operator|!
end_expr_stmt

begin_endif
unit|}}}}}
endif|#
directive|endif
end_endif

begin_comment
comment|/*  The code for converting the types of constants is not  */
end_comment

begin_comment
comment|/*  portable.  The problems involved in dealing with       */
end_comment

begin_comment
comment|/*  features such as reserved operands and byte orderings  */
end_comment

begin_comment
comment|/*  have proven very difficult to deal with in a portable  */
end_comment

begin_comment
comment|/*  manner.  Because of impending deadlines, I have put    */
end_comment

begin_comment
comment|/*  off trying to achieve portability.                     */
end_comment

begin_comment
comment|/*                                                         */
end_comment

begin_comment
comment|/*                             -Robert Paul Corbett        */
end_comment

begin_comment
comment|/*                              1983 May 1                 */
end_comment

begin_define
define|#
directive|define
name|BLANK
value|' '
end_define

begin_define
define|#
directive|define
name|MAXWORD
value|32767
end_define

begin_define
define|#
directive|define
name|MINWORD
value|-32768
end_define

begin_struct
unit|typedef
struct|struct
name|Dreal
block|{
name|unsigned
name|fract1
range|:
literal|7
decl_stmt|;
name|unsigned
name|exp
range|:
literal|8
decl_stmt|;
name|unsigned
name|sign
range|:
literal|1
decl_stmt|;
name|unsigned
name|fract2
range|:
literal|16
decl_stmt|;
name|unsigned
name|fract3
range|:
literal|16
decl_stmt|;
name|unsigned
name|fract4
range|:
literal|16
decl_stmt|;
block|}
name|dreal
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|Quad
block|{
name|long
name|word1
decl_stmt|;
name|long
name|word2
decl_stmt|;
block|}
name|quad
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|RealValue
block|{
name|double
name|d
decl_stmt|;
name|quad
name|q
decl_stmt|;
name|dreal
name|f
decl_stmt|;
block|}
name|realvalue
typedef|;
end_typedef

end_unit

