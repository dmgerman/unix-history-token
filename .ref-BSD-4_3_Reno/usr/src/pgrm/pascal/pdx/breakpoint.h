begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)breakpoint.h	5.2 (Berkeley) 1/3/88  */
end_comment

begin_comment
comment|/*  * Breakpoint module definitions.  *  * This module contains routines that manage breakpoints at a high level.  * This includes adding and deleting breakpoints, handling the various  * types of breakpoints when they happen, management of conditions for  * breakpoints, and display information after single stepping.  */
end_comment

begin_decl_stmt
name|unsigned
name|short
name|tracing
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|short
name|var_tracing
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|short
name|inst_tracing
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BOOLEAN
name|isstopped
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ss_lines
value|(tracing != 0)
end_define

begin_define
define|#
directive|define
name|ss_variables
value|(var_tracing != 0)
end_define

begin_define
define|#
directive|define
name|ss_instructions
value|(inst_tracing != 0)
end_define

begin_define
define|#
directive|define
name|single_stepping
value|(ss_lines || ss_variables || ss_instructions)
end_define

begin_comment
comment|/*  * types of breakpoints  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ALL_ON
block|,
comment|/* turn TRACE on */
name|ALL_OFF
block|,
comment|/* turn TRACE off */
name|INST
block|,
comment|/* trace instruction (source line) */
name|CALL
block|,
name|RETURN
block|,
comment|/* trace procedure/function */
name|BLOCK_ON
block|,
comment|/* set CALL breakpoint */
name|BLOCK_OFF
block|,
comment|/* clear CALL breakpoint */
name|TERM_ON
block|,
comment|/* turn TRACEVAR on */
name|TERM_OFF
block|,
comment|/* turn TRACEVAR off */
name|AT_BP
block|,
comment|/* print expression at a line */
name|STOP_BP
block|,
comment|/* stop execution */
name|CALLPROC
block|,
comment|/* return from a "call"-ed procedure */
name|END_BP
block|,
comment|/* return from program */
name|STOP_ON
block|,
comment|/* start looking for stop condition */
name|STOP_OFF
block|,
comment|/* stop looking for stop condition */
block|}
name|BPTYPE
typedef|;
end_typedef

begin_comment
comment|/*  * Things that are on the tracing or condition list are either  * associated with the trace (implying printing) or stop commands.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TRPRINT
block|,
name|TRSTOP
block|}
name|TRTYPE
typedef|;
end_typedef

begin_comment
comment|/*  * routines available from this module  */
end_comment

begin_function_decl
name|int
name|addvar
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add a variable to the trace list */
end_comment

begin_function_decl
name|int
name|delvar
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* delete a variable from the trace list */
end_comment

begin_function_decl
name|int
name|printvarnews
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print out variables that have changed */
end_comment

begin_function_decl
name|int
name|trfree
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* free the entire trace list */
end_comment

begin_function_decl
name|int
name|addcond
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add a condition to the list */
end_comment

begin_function_decl
name|int
name|delcond
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* delete a condition from the list */
end_comment

begin_function_decl
name|BOOLEAN
name|trcond
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* determine if any trace condition is true */
end_comment

begin_function_decl
name|BOOLEAN
name|stopcond
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* determine if any stop condition is true */
end_comment

begin_function_decl
name|int
name|addbp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add a breakpoint */
end_comment

begin_function_decl
name|int
name|delbp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* delete a breakpoint, return FALSE if unsuccessful */
end_comment

begin_function_decl
name|int
name|bpfree
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* free all breakpoint information */
end_comment

begin_function_decl
name|int
name|setallbps
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* set traps for all breakpoints */
end_comment

begin_function_decl
name|int
name|unsetallbps
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove traps at all breakpoints */
end_comment

begin_function_decl
name|BOOLEAN
name|bpact
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* handle a breakpoint */
end_comment

begin_function_decl
name|int
name|fixbps
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* destroy temporary breakpoints left after a fault */
end_comment

begin_function_decl
name|int
name|status
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* list items being traced */
end_comment

end_unit

