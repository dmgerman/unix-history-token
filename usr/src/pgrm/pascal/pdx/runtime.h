begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)runtime.h	5.2 (Berkeley) 1/3/88  */
end_comment

begin_comment
comment|/*  * Definitions for the runtime environment.  *  * In general, runtime organization is language, machine, and  * even compiler dependent.  */
end_comment

begin_function_decl
name|BOOLEAN
name|isactive
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* tell if a symbol is currently active */
end_comment

begin_function_decl
name|ADDRESS
name|entry_addr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* entry address of current proc/func */
end_comment

begin_function_decl
name|ADDRESS
name|entry_point
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* point where environment is setup */
end_comment

begin_function_decl
name|ADDRESS
name|return_addr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return address of current proc/func */
end_comment

begin_function_decl
name|ADDRESS
name|caller_addr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* entry of caller of current proc/func */
end_comment

begin_function_decl
name|int
name|where
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print out currently active procedures */
end_comment

begin_function_decl
name|int
name|dump
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* dump the world */
end_comment

begin_function_decl
name|int
name|callproc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* call a procedure */
end_comment

begin_function_decl
name|int
name|procreturn
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return from a "call"-ed procedure */
end_comment

begin_function_decl
name|ADDRESS
name|address
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* address of a variable */
end_comment

begin_function_decl
name|ADDRESS
name|firstline
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* address of first line in a procedure */
end_comment

begin_function_decl
name|int
name|findbeginning
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find address of beginning of a procedure */
end_comment

begin_function_decl
name|int
name|runtofirst
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* step to first line in current procedure */
end_comment

begin_function_decl
name|ADDRESS
name|lastaddr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* address of last line in program */
end_comment

begin_function_decl
name|ADDRESS
name|fparamaddr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* entry address of a function parameter */
end_comment

end_unit

