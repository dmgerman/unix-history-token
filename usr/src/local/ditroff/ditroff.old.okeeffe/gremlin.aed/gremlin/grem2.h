begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_escape
end_escape

begin_comment
comment|/* grem2.h -  *      This is an include file for database macros.  */
end_comment

begin_define
define|#
directive|define
name|DBNextElt
parameter_list|(
name|elt
parameter_list|)
value|elt->nextelt
end_define

begin_define
define|#
directive|define
name|DBNextofSet
parameter_list|(
name|elt
parameter_list|)
value|elt->setnext
end_define

begin_define
define|#
directive|define
name|DBNullelt
parameter_list|(
name|elt
parameter_list|)
value|( elt == NULL )
end_define

begin_define
define|#
directive|define
name|Nullpoint
parameter_list|(
name|pt
parameter_list|)
value|( pt->x == nullpt )
end_define

begin_define
define|#
directive|define
name|PTNextPoint
parameter_list|(
name|pt
parameter_list|)
value|pt->nextpt
end_define

end_unit

