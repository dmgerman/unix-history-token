begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sccs id  @(#)chkrtab.h	35.2  6/17/81  */
end_comment

begin_define
define|#
directive|define
name|chkrtab
parameter_list|(
name|p
parameter_list|)
value|;	\ 	if(p!=lastrtab){ if(TYPE(p)!=ARRAY&& TYPE(p->ar.data)!=INT) rtaberr();\ 			else {lastrtab=p;ctable=(unsigned char*)p->ar.data;}}
end_define

begin_decl_stmt
specifier|extern
name|lispval
name|lastrtab
decl_stmt|;
end_decl_stmt

end_unit

