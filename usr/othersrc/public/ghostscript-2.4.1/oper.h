begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* oper.h */
end_comment

begin_comment
comment|/* Definitions for Ghostscript operators */
end_comment

begin_include
include|#
directive|include
file|"ostack.h"
end_include

begin_include
include|#
directive|include
file|"opdef.h"
end_include

begin_include
include|#
directive|include
file|"gsutil.h"
end_include

begin_include
include|#
directive|include
file|"iutil.h"
end_include

begin_comment
comment|/* Structure for initializing variables that hold name constants. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
name|_ds
modifier|*
name|vname
decl_stmt|;
name|ref
name|_ds
modifier|*
name|pvref
decl_stmt|;
block|}
name|names_def
typedef|;
end_typedef

begin_define
define|#
directive|define
name|names_def_end
value|{(char _ds *)0, (ref _ds *)0}
end_define

begin_decl_stmt
specifier|extern
name|void
name|init_names
argument_list|(
name|P1
argument_list|(
argument|const names_def _ds *
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Operand stack manipulation */
end_comment

begin_comment
comment|/* The most efficient code is different depending on the compiler.... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__MSDOS__
end_ifdef

begin_comment
comment|/* stupid compilers */
end_comment

begin_define
define|#
directive|define
name|push
parameter_list|(
name|n
parameter_list|)
define|\
value|if ( (op += (n))> ostop ) return (e_stackoverflow); else osp += (n)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* reasonable compiler */
end_comment

begin_define
define|#
directive|define
name|push
parameter_list|(
name|n
parameter_list|)
define|\
value|if ( (osp = op += (n))> ostop ) return (osp -= (n), e_stackoverflow)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Note that the pop macro only decrements osp, not op.  For this reason,  *  *>>>	pop should only be used just before returning,<<<  *>>>	or else op must be decremented explicitly.<<<  */
end_comment

begin_define
define|#
directive|define
name|pop
parameter_list|(
name|n
parameter_list|)
value|(osp -= (n))
end_define

begin_comment
comment|/*  * Note that the interpreter does not check for operand stack underflow  * before calling the operator procedure.  There are "guard" entries  * with invalid types and attributes just below the bottom of the  * operand stack: if the operator returns with a typecheck error,  * the interpreter checks for underflow at that time.  * Operators that don't typecheck their arguments must check for  * operand stack underflow explicitly.  */
end_comment

begin_define
define|#
directive|define
name|os_max_nargs
value|6
end_define

begin_decl_stmt
specifier|extern
name|os_ptr
name|osp_nargs
index|[
name|os_max_nargs
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|op_nargs_check
parameter_list|(
name|nargs
parameter_list|)
value|osp_nargs[(nargs) - 1]
end_define

begin_define
define|#
directive|define
name|check_op
parameter_list|(
name|nargs
parameter_list|)
define|\
value|if ( op< op_nargs_check(nargs) ) return e_stackunderflow
end_define

begin_comment
comment|/* Check type */
end_comment

begin_define
define|#
directive|define
name|check_type
parameter_list|(
name|rf
parameter_list|,
name|typ
parameter_list|)
define|\
value|if ( !r_has_type(&rf,typ) ) return e_typecheck
end_define

begin_comment
comment|/* Check for array */
end_comment

begin_define
define|#
directive|define
name|check_array_else
parameter_list|(
name|rf
parameter_list|,
name|err
parameter_list|)
define|\
value|if ( !r_has_type(&rf, t_array) ) return err
end_define

begin_define
define|#
directive|define
name|check_array
parameter_list|(
name|rf
parameter_list|)
value|check_array_else(rf, e_typecheck)
end_define

begin_comment
comment|/* Check for procedure */
end_comment

begin_define
define|#
directive|define
name|check_proc
parameter_list|(
name|rf
parameter_list|)
define|\
value|switch ( r_type_xe(&rf) )\    { default:\ 	return(r_has_attrs(&rf, a_execute + a_executable) ? e_typecheck :\ 	       e_invalidaccess);\      case type_xe_value(t_array, a_execute + a_executable):\      case type_xe_value(t_mixedarray, a_execute + a_executable):\      case type_xe_value(t_shortarray, a_execute + a_executable): ;\    }
end_define

begin_comment
comment|/* Check for read, write, or execute access. */
end_comment

begin_define
define|#
directive|define
name|check_access
parameter_list|(
name|rf
parameter_list|,
name|acc1
parameter_list|)
define|\
value|if ( !r_has_attr(&rf,acc1) ) return e_invalidaccess
end_define

begin_define
define|#
directive|define
name|check_read
parameter_list|(
name|rf
parameter_list|)
value|check_access(rf,a_read)
end_define

begin_define
define|#
directive|define
name|check_type_access
parameter_list|(
name|rf
parameter_list|,
name|typ
parameter_list|,
name|acc1
parameter_list|)
define|\
value|if ( !r_has_type_attrs(&rf,typ,acc1) )\     return (r_has_attr(&rf,acc1) ? e_typecheck : e_invalidaccess)
end_define

begin_define
define|#
directive|define
name|check_read_type
parameter_list|(
name|rf
parameter_list|,
name|typ
parameter_list|)
value|check_type_access(rf,typ,a_read)
end_define

begin_define
define|#
directive|define
name|check_write
parameter_list|(
name|rf
parameter_list|)
value|check_access(rf,a_write)
end_define

begin_define
define|#
directive|define
name|check_write_type
parameter_list|(
name|rf
parameter_list|,
name|typ
parameter_list|)
value|check_type_access(rf,typ,a_write)
end_define

begin_define
define|#
directive|define
name|check_execute
parameter_list|(
name|rf
parameter_list|)
value|check_access(rf,a_execute)
end_define

begin_comment
comment|/* Macro for as yet unimplemented operators. */
end_comment

begin_comment
comment|/* The if ( 1 ) is to prevent the compiler from complaining about */
end_comment

begin_comment
comment|/* unreachable code. */
end_comment

begin_define
define|#
directive|define
name|NYI
parameter_list|(
name|msg
parameter_list|)
value|if ( 1 ) return e_undefined
end_define

begin_comment
comment|/*  * If an operator has popped or pushed something on the control stack,  * it must return o_pop_estack or o_push_estack respectively,  * rather than 0, to indicate success.  * It is OK to return o_pop_estack if nothing has been popped,  * but it is not OK to return o_push_estack if nothing has been pushed.  *  * If an operator has suspended the current context and wants the  * interpreter to call the scheduler, it must return o_reschedule.  * It may also have pushed or popped elements on the control stack.  * (This is only used when the Display PostScript option is included.)  *  * These values must be positive, and far enough apart from zero and  * from each other not to tempt a compiler into implementing a 'switch'  * on them using indexing rather than testing.  */
end_comment

begin_define
define|#
directive|define
name|o_push_estack
value|3
end_define

begin_define
define|#
directive|define
name|o_pop_estack
value|8
end_define

begin_define
define|#
directive|define
name|o_reschedule
value|14
end_define

end_unit

