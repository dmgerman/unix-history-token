begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*					-[Sat Jan 29 13:53:19 1983 by jkf]-  * 	chkrtab.h			$Locker:  $  * check if read table valid   *  * $Header: /na/franz/franz/h/chkrtab.h,v 1.1 83/01/29 14:05:24 jkf Exp $  *  * (c) copyright 1982, Regents of the University of California  */
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

