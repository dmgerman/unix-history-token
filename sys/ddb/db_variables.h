begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1991,1990 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * HISTORY  * $Log: db_variables.h,v $  * Revision 1.1  1992/03/25  21:45:35  pace  * Initial revision  *  * Revision 2.3  91/02/05  17:07:23  mrt  * 	Changed to new Mach copyright  * 	[91/01/31  16:19:54  mrt]  *   * Revision 2.2  90/08/27  21:53:40  dbg  * 	Modularized typedef name.  Documented the calling sequence of  * 	the (optional) access function of a variable.  Now the valuep  * 	field can be made opaque, eg be an offset that fcn() resolves.  * 	[90/08/20            af]  *   * 	Created.  * 	[90/07/25            dbg]  *   */
end_comment

begin_comment
comment|/*  * 	Author: David B. Golub, Carnegie Mellon University  *	Date:	7/90  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DB_VARIABLES_H_
end_ifndef

begin_define
define|#
directive|define
name|_DB_VARIABLES_H_
end_define

begin_comment
comment|/*  * Debugger variables.  */
end_comment

begin_struct
struct|struct
name|db_variable
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of variable */
name|int
modifier|*
name|valuep
decl_stmt|;
comment|/* value of variable */
comment|/* function to call when reading/writing */
name|int
function_decl|(
modifier|*
name|fcn
function_decl|)
parameter_list|(
comment|/* db_variable *vp, db_expr_t *valuep, int op */
parameter_list|)
function_decl|;
define|#
directive|define
name|DB_VAR_GET
value|0
define|#
directive|define
name|DB_VAR_SET
value|1
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FCN_NULL
value|((int (*)())0)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|db_variable
name|db_vars
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debugger variables */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|db_variable
modifier|*
name|db_evars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|db_variable
name|db_regs
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* machine registers */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|db_variable
modifier|*
name|db_eregs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DB_VARIABLES_H_ */
end_comment

end_unit

