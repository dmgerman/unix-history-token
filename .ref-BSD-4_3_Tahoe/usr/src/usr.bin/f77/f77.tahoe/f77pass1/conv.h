begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|TARGET
operator|!=
name|TAHOE
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
comment|/*  manner.						   */
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
value|0x7fff
end_define

begin_define
define|#
directive|define
name|MINWORD
value|-0x8000
end_define

begin_struct
unit|typedef
struct|struct
name|Dreal
block|{
if|#
directive|if
name|HERE
operator|==
name|VAX
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
else|#
directive|else
if|#
directive|if
name|HERE
operator|==
name|TAHOE
name|unsigned
name|sign
range|:
literal|1
decl_stmt|;
name|unsigned
name|exp
range|:
literal|8
decl_stmt|;
name|unsigned
name|fract1
range|:
literal|7
decl_stmt|;
else|#
directive|else
block|}
end_struct

begin_expr_stmt
unit|}}}}
name|WRONG
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

begin_endif
endif|#
directive|endif
end_endif

begin_label
unit|unsigned
name|fract2
label|:
end_label

begin_expr_stmt
literal|16
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|unsigned
name|short
name|fract3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|short
name|fract4
decl_stmt|;
end_decl_stmt

begin_empty_stmt
unit|}   dreal
empty_stmt|;
end_empty_stmt

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

