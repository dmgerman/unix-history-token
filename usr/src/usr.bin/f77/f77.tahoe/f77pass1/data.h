begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)data.h	5.1 (Berkeley) 6/7/85  */
end_comment

begin_comment
comment|/*  Forms of data list elements  */
end_comment

begin_define
define|#
directive|define
name|SIMPLE
value|1
end_define

begin_define
define|#
directive|define
name|NESTED
value|2
end_define

begin_comment
comment|/*  data expression block types  */
end_comment

begin_define
define|#
directive|define
name|DVALUE
value|1
end_define

begin_define
define|#
directive|define
name|DVAR
value|2
end_define

begin_define
define|#
directive|define
name|DNAME
value|3
end_define

begin_define
define|#
directive|define
name|DEXPR
value|4
end_define

begin_define
define|#
directive|define
name|DERROR
value|5
end_define

begin_comment
comment|/*  status codes for integer values  */
end_comment

begin_define
define|#
directive|define
name|NORMAL
value|1
end_define

begin_define
define|#
directive|define
name|MAXPLUS1
value|2
end_define

begin_define
define|#
directive|define
name|MINLESS1
value|3
end_define

begin_define
define|#
directive|define
name|ERRVAL
value|4
end_define

begin_escape
end_escape

begin_comment
comment|/*  data types for data statements  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Dvalue
block|{
name|char
name|tag
decl_stmt|;
name|char
name|status
decl_stmt|;
name|ftnint
name|value
decl_stmt|;
block|}
name|dvalue
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Dvar
block|{
name|char
name|tag
decl_stmt|;
name|struct
name|Dvalue
modifier|*
name|valp
decl_stmt|;
block|}
name|dvar
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Dname
block|{
name|char
name|tag
decl_stmt|;
name|int
name|len
decl_stmt|;
name|char
modifier|*
name|repr
decl_stmt|;
block|}
name|dname
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Dexpr
block|{
name|char
name|tag
decl_stmt|;
name|char
name|opcode
decl_stmt|;
name|union
name|Vexpr
modifier|*
name|left
decl_stmt|;
name|union
name|Vexpr
modifier|*
name|right
decl_stmt|;
block|}
name|dexpr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Derror
block|{
name|char
name|tag
decl_stmt|;
block|}
name|derror
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|Vexpr
block|{
name|char
name|tag
decl_stmt|;
name|struct
name|Dvalue
name|dvalue
decl_stmt|;
name|struct
name|Dvar
name|dvar
decl_stmt|;
name|struct
name|Dname
name|dname
decl_stmt|;
name|struct
name|Dexpr
name|dexpr
decl_stmt|;
name|struct
name|Derror
name|derror
decl_stmt|;
block|}
name|vexpr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Elist
block|{
name|struct
name|Elist
modifier|*
name|next
decl_stmt|;
name|union
name|Delt
modifier|*
name|elt
decl_stmt|;
block|}
name|elist
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Aelt
block|{
name|char
name|tag
decl_stmt|;
name|Namep
name|var
decl_stmt|;
name|struct
name|Vlist
modifier|*
name|subs
decl_stmt|;
name|struct
name|Rpair
modifier|*
name|range
decl_stmt|;
block|}
name|aelt
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|DoList
block|{
name|char
name|tag
decl_stmt|;
name|struct
name|Elist
modifier|*
name|elts
decl_stmt|;
name|union
name|Vexpr
modifier|*
name|dovar
decl_stmt|;
name|union
name|Vexpr
modifier|*
name|init
decl_stmt|;
name|union
name|Vexpr
modifier|*
name|limit
decl_stmt|;
name|union
name|Vexpr
modifier|*
name|step
decl_stmt|;
block|}
name|dolist
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|Delt
block|{
name|char
name|tag
decl_stmt|;
name|struct
name|Aelt
name|simple
decl_stmt|;
name|struct
name|DoList
name|nested
decl_stmt|;
block|}
name|delt
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Rpair
block|{
name|union
name|Vexpr
modifier|*
name|low
decl_stmt|;
name|union
name|Vexpr
modifier|*
name|high
decl_stmt|;
block|}
name|rpair
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ValList
block|{
name|struct
name|ValList
modifier|*
name|next
decl_stmt|;
name|char
name|status
decl_stmt|;
name|int
name|repl
decl_stmt|;
name|Constp
name|value
decl_stmt|;
block|}
name|vallist
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Vlist
block|{
name|struct
name|Vlist
modifier|*
name|next
decl_stmt|;
name|union
name|Vexpr
modifier|*
name|val
decl_stmt|;
block|}
name|vlist
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|DoVars
block|{
name|struct
name|DoVars
modifier|*
name|next
decl_stmt|;
name|int
name|len
decl_stmt|;
name|char
modifier|*
name|repr
decl_stmt|;
name|dvalue
modifier|*
name|valp
decl_stmt|;
block|}
name|dovars
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/*  Global variables  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|badvalue
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|flag
name|overlapflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  Global procedures  */
end_comment

begin_extern
extern|extern frvexpr(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern frvlist(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|elist
modifier|*
name|revelist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vlist
modifier|*
name|revvlist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vlist
modifier|*
name|prepvexpr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|elist
modifier|*
name|preplval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|delt
modifier|*
name|mkdlval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|delt
modifier|*
name|mkdatado
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rpair
modifier|*
name|mkdrange
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vallist
modifier|*
name|mkdrval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vexpr
modifier|*
name|evicon
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vexpr
modifier|*
name|mkdname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|expptr
name|ivaltoicon
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|expptr
name|evparam
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vexpr
modifier|*
name|evaldname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vexpr
modifier|*
name|mkdexpr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vexpr
modifier|*
name|addivals
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vexpr
modifier|*
name|subivals
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vexpr
modifier|*
name|mulivals
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vexpr
modifier|*
name|divivals
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vexpr
modifier|*
name|powivals
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vexpr
modifier|*
name|negival
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|expptr
name|convconst
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern savedata(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

end_unit

