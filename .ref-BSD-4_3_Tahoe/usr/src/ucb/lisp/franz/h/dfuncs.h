begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*					-[Sat Jan 29 13:54:30 1983 by jkf]-  * 	dfuncs.h			$Locker:  $  * external function declaration  *  * $Header: dfuncs.h,v 1.2 84/02/29 17:09:10 sklower Exp $  *  * (c) copyright 1982, Regents of the University of California  */
end_comment

begin_function_decl
name|char
modifier|*
name|brk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getsp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|pinewstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|inewstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mkmsg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|newstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rstore
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|sbrk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xsbrk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ysbrk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|csizeof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|finterp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Iget
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Imkrtab
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Iputprop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfuncal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lnegp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lsub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|copval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|csegment
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|errorh
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|errorh1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|errorh2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|eval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|gc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|getatom
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|inewval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|linterp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|matom
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|mfun
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|mstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|newarray
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|newdot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|newdoub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|newfunct
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|newint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|newsdot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|newval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|newhunk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|pnewdot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|pnewdb
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|pnewhunk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|pnewint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|pnewsdot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|pnewval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|popnames
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|r
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|ratomr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|readr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|readrx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|readry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|typred
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|unprot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|verify
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|atom
modifier|*
name|newatom
parameter_list|()
function_decl|;
end_function_decl

end_unit

