begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* estack.h */
end_comment

begin_comment
comment|/* Definitions for Ghostscript execution stack */
end_comment

begin_comment
comment|/********************************  * NOTE: on MS-DOS systems, the execution stack is stored in the data segment.  * This leads to large performance gains, at the expense of having to swap  * the stack explicitly when switching contexts or handling segment under-  * or overflow (none of which are implemented yet!).  ********************************/
end_comment

begin_typedef
typedef|typedef
name|ref
name|_ds
modifier|*
name|es_ptr
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|es_ptr
name|esbot
decl_stmt|,
name|esp
decl_stmt|,
name|estop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * In the near future, we will cache the currentfile pointer  * (i.e., `shallow-bind' it in Lisp terminology).  The invariant is as  * follows: either esfile points to the currentfile slot on the estack  * (i.e., the topmost slot with an executable file), or it is 0.  * Note that the following algorithm suffices to maintain the invariant:  * whenever a routine pushes or pops anything on the estack, if the object  * *might* be an executable file, set esfile to 0.  ****** NOT IMPLEMENTED YET ******  */
end_comment

begin_decl_stmt
specifier|extern
name|es_ptr
name|esfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The execution stack is used for three purposes:  *	- Procedures being executed are held here.  They always have  * type = t_array, t_mixedarray, or t_shortarray, with a_executable set.  *	- if, ifelse, etc. push arguments to be executed here.  * They may be any kind of object whatever.  *	- for, repeat, loop, forall, pathforall, run, and stopped  * mark the stack by pushing an object with type = t_null,  * attrs = a_executable, and value.index = 0 for loops, 1 for run/stopped.  * (Executable null objects can't ever appear on the e-stack otherwise:  * if a control operator pushes one, it gets popped immediately.)  * The loop operators also push whatever state they need,  * followed by an operator object that handles continuing the loop.  */
end_comment

begin_comment
comment|/* Macro for marking the execution stack */
end_comment

begin_define
define|#
directive|define
name|make_mark_estack
parameter_list|(
name|ep
parameter_list|,
name|idx
parameter_list|)
define|\
value|make_tav(ep, t_null, a_executable, index, idx)
end_define

begin_define
define|#
directive|define
name|mark_estack
parameter_list|(
name|idx
parameter_list|)
define|\
value|(++esp, make_mark_estack(esp, idx))
end_define

begin_comment
comment|/* Macro for pushing an operator on the execution stack */
end_comment

begin_comment
comment|/* to represent a continuation procedure */
end_comment

begin_define
define|#
directive|define
name|make_op_estack
parameter_list|(
name|ep
parameter_list|,
name|proc
parameter_list|,
name|idx
parameter_list|)
define|\
value|make_oper(ep, idx, (dummy_op_proc_p)(proc))
end_define

begin_define
define|#
directive|define
name|push_op_estack
parameter_list|(
name|proc
parameter_list|,
name|idx
parameter_list|)
define|\
value|(++esp, make_op_estack(esp, proc, idx))
end_define

begin_comment
comment|/* Macro to ensure enough room on the execution stack */
end_comment

begin_define
define|#
directive|define
name|check_estack
parameter_list|(
name|n
parameter_list|)
define|\
value|if ( esp + (n)> estop ) return e_execstackoverflow
end_define

begin_comment
comment|/* Define the various kinds of execution stack marks. */
end_comment

begin_define
define|#
directive|define
name|es_other
value|0
end_define

begin_comment
comment|/* internal use */
end_comment

begin_define
define|#
directive|define
name|es_show
value|1
end_define

begin_comment
comment|/* show operators */
end_comment

begin_define
define|#
directive|define
name|es_for
value|2
end_define

begin_comment
comment|/* iteration operators */
end_comment

begin_define
define|#
directive|define
name|es_stopped
value|3
end_define

begin_comment
comment|/* stopped operator */
end_comment

end_unit

