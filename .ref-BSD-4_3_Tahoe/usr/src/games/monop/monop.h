begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)monop.h	5.4 (Berkeley) 6/18/88  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|reg
value|register
end_define

begin_define
define|#
directive|define
name|shrt
value|char
end_define

begin_define
define|#
directive|define
name|bool
value|char
end_define

begin_define
define|#
directive|define
name|unsgn
value|unsigned
end_define

begin_define
define|#
directive|define
name|TRUE
value|(1)
end_define

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_define
define|#
directive|define
name|N_MON
value|8
end_define

begin_comment
comment|/* number of monopolies			*/
end_comment

begin_define
define|#
directive|define
name|N_PROP
value|22
end_define

begin_comment
comment|/* number of normal property squares	*/
end_comment

begin_define
define|#
directive|define
name|N_RR
value|4
end_define

begin_comment
comment|/* number of railroads			*/
end_comment

begin_define
define|#
directive|define
name|N_UTIL
value|2
end_define

begin_comment
comment|/* number of utilities			*/
end_comment

begin_define
define|#
directive|define
name|N_SQRS
value|40
end_define

begin_comment
comment|/* number of squares on board		*/
end_comment

begin_define
define|#
directive|define
name|MAX_PL
value|9
end_define

begin_comment
comment|/* maximum number of players		*/
end_comment

begin_define
define|#
directive|define
name|MAX_PRP
value|(N_PROP+N_RR+N_UTIL)
end_define

begin_comment
comment|/* max # ownable property	*/
end_comment

begin_comment
comment|/* square type numbers			*/
end_comment

begin_define
define|#
directive|define
name|PRPTY
value|0
end_define

begin_comment
comment|/* normal property			*/
end_comment

begin_define
define|#
directive|define
name|RR
value|1
end_define

begin_comment
comment|/* railroad				*/
end_comment

begin_define
define|#
directive|define
name|UTIL
value|2
end_define

begin_comment
comment|/* water works - electric co		*/
end_comment

begin_define
define|#
directive|define
name|SAFE
value|3
end_define

begin_comment
comment|/* safe spot				*/
end_comment

begin_define
define|#
directive|define
name|CC
value|4
end_define

begin_comment
comment|/* community chest			*/
end_comment

begin_define
define|#
directive|define
name|CHANCE
value|5
end_define

begin_comment
comment|/* chance (surprise!!!)			*/
end_comment

begin_define
define|#
directive|define
name|INC_TAX
value|6
end_define

begin_comment
comment|/* Income tax */
end_comment

begin_define
define|#
directive|define
name|GOTO_J
value|7
end_define

begin_comment
comment|/* Go To Jail! */
end_comment

begin_define
define|#
directive|define
name|LUX_TAX
value|8
end_define

begin_comment
comment|/* Luxury tax */
end_comment

begin_define
define|#
directive|define
name|IN_JAIL
value|9
end_define

begin_comment
comment|/* In jail */
end_comment

begin_define
define|#
directive|define
name|JAIL
value|40
end_define

begin_comment
comment|/* JAIL square number			*/
end_comment

begin_define
define|#
directive|define
name|lucky
parameter_list|(
name|str
parameter_list|)
value|printf("%s%s\n",str,lucky_mes[roll(1,num_luck)-1])
end_define

begin_define
define|#
directive|define
name|printline
parameter_list|()
value|printf("------------------------------\n")
end_define

begin_define
define|#
directive|define
name|sqnum
parameter_list|(
name|sqp
parameter_list|)
value|(sqp - board)
end_define

begin_define
define|#
directive|define
name|swap
parameter_list|(
name|A1
parameter_list|,
name|A2
parameter_list|)
value|if ((A1) != (A2)) { \ 					(A1) ^= (A2); \ 					(A2) ^= (A1); \ 					(A1) ^= (A2); \ 				}
end_define

begin_struct
struct|struct
name|sqr_st
block|{
comment|/* structure for square			*/
name|char
modifier|*
name|name
decl_stmt|;
comment|/* place name			*/
name|shrt
name|owner
decl_stmt|;
comment|/* owner number			*/
name|shrt
name|type
decl_stmt|;
comment|/* place type			*/
name|struct
name|prp_st
modifier|*
name|desc
decl_stmt|;
comment|/* description struct		*/
name|int
name|cost
decl_stmt|;
comment|/* cost				*/
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sqr_st
name|SQUARE
typedef|;
end_typedef

begin_struct
struct|struct
name|mon_st
block|{
comment|/* monopoly description structure	*/
name|char
modifier|*
name|name
decl_stmt|;
comment|/* monop. name (color)		*/
name|shrt
name|owner
decl_stmt|;
comment|/* owner of monopoly		*/
name|shrt
name|num_in
decl_stmt|;
comment|/* # in monopoly		*/
name|shrt
name|num_own
decl_stmt|;
comment|/* # owned (-1: not poss. monop)*/
name|shrt
name|h_cost
decl_stmt|;
comment|/* price of houses		*/
name|char
modifier|*
name|not_m
decl_stmt|;
comment|/* name if not monopoly		*/
name|char
modifier|*
name|mon_n
decl_stmt|;
comment|/* name if a monopoly		*/
name|char
name|sqnums
index|[
literal|3
index|]
decl_stmt|;
comment|/* Square numbers (used to init)*/
name|SQUARE
modifier|*
name|sq
index|[
literal|3
index|]
decl_stmt|;
comment|/* list of squares in monop	*/
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mon_st
name|MON
typedef|;
end_typedef

begin_comment
comment|/*  * This struct describes a property.  For railroads and utilities, only  * the "morg" member is used.  */
end_comment

begin_struct
struct|struct
name|prp_st
block|{
comment|/* property description structure	*/
name|bool
name|morg
decl_stmt|;
comment|/* set if mortgaged		*/
name|bool
name|monop
decl_stmt|;
comment|/* set if monopoly		*/
name|shrt
name|square
decl_stmt|;
comment|/* square description		*/
name|shrt
name|houses
decl_stmt|;
comment|/* number of houses		*/
name|MON
modifier|*
name|mon_desc
decl_stmt|;
comment|/* name of color		*/
name|int
name|rent
index|[
literal|6
index|]
decl_stmt|;
comment|/* rents			*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|own_st
block|{
comment|/* element in list owned things		*/
name|SQUARE
modifier|*
name|sqr
decl_stmt|;
comment|/* pointer to square		*/
name|struct
name|own_st
modifier|*
name|next
decl_stmt|;
comment|/* next in list			*/
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|own_st
name|OWN
typedef|;
end_typedef

begin_struct
struct|struct
name|plr_st
block|{
comment|/* player description structure		*/
name|char
modifier|*
name|name
decl_stmt|;
comment|/* owner name			*/
name|shrt
name|num_gojf
decl_stmt|;
comment|/* # of get-out-of-jail-free's	*/
name|shrt
name|num_rr
decl_stmt|;
comment|/* # of railroads owned		*/
name|shrt
name|num_util
decl_stmt|;
comment|/* # of water works/elec. co.	*/
name|shrt
name|loc
decl_stmt|;
comment|/* location on board		*/
name|shrt
name|in_jail
decl_stmt|;
comment|/* count of turns in jail	*/
name|int
name|money
decl_stmt|;
comment|/* amount of money		*/
name|OWN
modifier|*
name|own_list
decl_stmt|;
comment|/* start of propery list	*/
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|plr_st
name|PLAY
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|prp_st
name|PROP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|prp_st
name|RR_S
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|prp_st
name|UTIL_S
typedef|;
end_typedef

begin_decl_stmt
name|int
name|cc
argument_list|()
decl_stmt|,
name|chance
argument_list|()
decl_stmt|,
name|lux_tax
argument_list|()
decl_stmt|,
name|goto_jail
argument_list|()
decl_stmt|,
name|inc_tax
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

