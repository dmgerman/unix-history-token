begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_comment
comment|/* static 	char sccsid[] = "@(#)libpc.h 1.1 %G%"; */
end_comment

begin_function_decl
specifier|extern
name|double
name|LN
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
name|double
name|RANDOM
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
name|char
modifier|*
name|FNIL
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

begin_function_decl
specifier|extern
name|struct
name|formalrtn
modifier|*
name|FSAV
parameter_list|()
function_decl|;
end_function_decl

end_unit

