begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)libpc.h	1.9 (Berkeley) 4/9/90  */
end_comment

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|ACTFILE
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
modifier|*
name|ADDT
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|ATAN
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|CARD
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
name|CHR
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|CLCK
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|COS
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
modifier|*
name|CTTOT
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|ERROR
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|EXCEPT
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|EXP
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|EXPO
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|FNIL
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|formalrtn
modifier|*
name|FSAV
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|iorec
modifier|*
name|GETNAME
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|IN
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|INCT
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|LN
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|MAX
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
modifier|*
name|MULT
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|NAM
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|NIL
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|PRED
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|iorec
modifier|*
name|PFCLOSE
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|RANDOM
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
name|READC
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|READ4
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|READE
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|READ8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|RELNE
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|RELEQ
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|RELSLT
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|RELSLE
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|RELSGT
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|RELSGE
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|RELTLT
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|RELTLE
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|RELTGT
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|RELTGE
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|ROUND
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|RANG4
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|RSNG4
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|SCLCK
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|SEED
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|SIN
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|SQRT
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|SUBSC
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|SUBSCZ
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
modifier|*
name|SUBT
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|SUCC
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|seekptr
name|TELL
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|TEOF
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|TEOLN
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|TRUNC
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|iorec
modifier|*
name|UNIT
parameter_list|()
function_decl|;
end_function_decl

end_unit

