begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vmsysent.h	4.4	81/03/03	*/
end_comment

begin_comment
comment|/*  * Externals for functions defined in vmsys.c.  */
end_comment

begin_function_decl
name|int
name|nosys
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nullsys
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfork
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* later, just fork? */
end_comment

begin_function_decl
name|int
name|vread
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* deprecated */
end_comment

begin_function_decl
name|int
name|vwrite
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* deprecated */
end_comment

begin_function_decl
name|int
name|vadvise
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* later, segadvise */
end_comment

begin_function_decl
name|int
name|vhangup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* should just do in exit() */
end_comment

begin_function_decl
name|int
name|vlimit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vswapon
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vtimes
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_function_decl
name|int
name|vtrace
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|segalloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* not in yet */
end_comment

begin_function_decl
name|int
name|segfree
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* not in yet */
end_comment

begin_function_decl
name|int
name|segsync
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* not in yet */
end_comment

begin_function_decl
name|int
name|resuba
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|futz
parameter_list|()
function_decl|;
end_function_decl

end_unit

