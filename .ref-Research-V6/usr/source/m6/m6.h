begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
block|{
name|int
name|word
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
comment|/*"put stack", currently gathering args*/
name|int
name|prev
decl_stmt|;
comment|/*previous frame ptr, self-relative*/
name|int
name|pan
decl_stmt|;
comment|/*argument number of arg being collected*/
name|int
name|pa0
decl_stmt|;
comment|/*self-relative ptr oo arg0*/
define|#
directive|define
name|pend
value|6
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
comment|/*"get stack", currently expanding macros*/
name|int
name|prev
decl_stmt|;
comment|/* prev frame ptr, self-realtive*/
name|int
name|mframe
decl_stmt|;
comment|/* ptr to macro definition frame*/
name|int
name|mchar
decl_stmt|;
comment|/* next char relative to def. frame*/
name|int
name|marg
decl_stmt|;
comment|/* 0 or ptr to next arg char reltive to gf*/
name|int
name|ga0
decl_stmt|;
comment|/* arg0 ptr self-rel*/
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
comment|/*"definition stack"*/
name|int
name|prev
decl_stmt|;
comment|/* prev frame ptr, self-relative*/
name|int
name|dswitch
decl_stmt|;
comment|/* builtin func code, neg for dead definition*/
name|int
name|dtext
decl_stmt|;
comment|/* definition text prt rel to df*/
name|int
name|dident
decl_stmt|;
comment|/* first char of identifier naming def*/
define|#
directive|define
name|dend
value|6
block|}
struct|;
end_struct

begin_decl_stmt
name|char
name|metas
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|lquote
value|metas[0]
end_define

begin_define
define|#
directive|define
name|rquote
value|metas[1]
end_define

begin_define
define|#
directive|define
name|sharp
value|metas[2]
end_define

begin_define
define|#
directive|define
name|colon
value|metas[3]
end_define

begin_define
define|#
directive|define
name|semi
value|metas[4]
end_define

begin_define
define|#
directive|define
name|comma
value|metas[5]
end_define

begin_define
define|#
directive|define
name|dollar
value|metas[6]
end_define

begin_define
define|#
directive|define
name|NMETA
value|7
end_define

begin_decl_stmt
name|char
name|one
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rescan
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|traceflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|trashflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nonzero when dead def'n exist*/
end_comment

begin_decl_stmt
name|int
name|lp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* arg collection level (out level)*/
end_comment

begin_decl_stmt
name|int
name|lg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*input level (get level) */
end_comment

begin_decl_stmt
name|int
name|lq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*quote level*/
end_comment

begin_decl_stmt
name|int
name|l9
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*apparent call level within arg 9*/
end_comment

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current input character*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|pf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*put stack frame ptr*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|pe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*put stack end*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|pmax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*top of put stack*/
end_comment

begin_decl_stmt
name|char
name|p0
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*put stack*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|gf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*get stack frame ptr*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|ge
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*get stack end*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|gmax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*get stack limit*/
end_comment

begin_decl_stmt
name|char
name|g0
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*get stack*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|df
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*definition stack frame ptr*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|de
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*def stack end*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|dmax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*def stack limit*/
end_comment

begin_decl_stmt
name|char
name|d0
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*def stack*/
end_comment

begin_decl_stmt
name|char
name|dummy
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*dummy empty macro*/
end_comment

end_unit

