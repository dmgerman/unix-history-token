begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  PV.H -- definitions for parameter vectors ** **	Version: **		@(#)pv.h	7.1	2/5/81 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PV_MAXPC
end_ifndef

begin_comment
comment|/* setable constants */
end_comment

begin_define
define|#
directive|define
name|PV_MAXPC
value|125
end_define

begin_comment
comment|/* maximum number of parameters */
end_comment

begin_comment
comment|/* the parameter vector type */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|pv_type
decl_stmt|;
comment|/* the type, see below */
name|short
name|pv_len
decl_stmt|;
comment|/* the length of the value */
union|union
block|{
name|short
name|pv_int
decl_stmt|;
comment|/* PV_INT */
name|struct
name|querytree
modifier|*
name|pv_qtree
decl_stmt|;
comment|/* PV_QTREE */
name|char
modifier|*
name|pv_str
decl_stmt|;
comment|/* PV_STR */
name|char
modifier|*
name|pv_tuple
decl_stmt|;
comment|/* PV_TUPLE */
block|}
name|pv_val
union|;
block|}
name|PARM
typedef|;
end_typedef

begin_comment
comment|/* pv_type values */
end_comment

begin_define
define|#
directive|define
name|PV_EOF
value|0
end_define

begin_comment
comment|/* end of list */
end_comment

begin_define
define|#
directive|define
name|PV_INT
value|1
end_define

begin_comment
comment|/* integer */
end_comment

begin_define
define|#
directive|define
name|PV_STR
value|2
end_define

begin_comment
comment|/* string */
end_comment

begin_define
define|#
directive|define
name|PV_QTREE
value|3
end_define

begin_comment
comment|/* query tree */
end_comment

begin_define
define|#
directive|define
name|PV_TUPLE
value|4
end_define

begin_comment
comment|/* tuple */
end_comment

begin_endif
endif|#
directive|endif
endif|PV_MAXPC
end_endif

end_unit

