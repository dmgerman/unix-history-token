begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Mach Operating System  * Copyright (c) 1991,1990 Carnegie Mellon University  * All Rights Reserved.  *  * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DDB_DB_SYM_H_
end_ifndef

begin_define
define|#
directive|define
name|_DDB_DB_SYM_H_
end_define

begin_comment
comment|/*  * 	Author: Alessandro Forin, Carnegie Mellon University  *	Date:	8/90  */
end_comment

begin_comment
comment|/*  * This module can handle multiple symbol tables  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* symtab name */
name|char
modifier|*
name|start
decl_stmt|;
comment|/* symtab location */
name|char
modifier|*
name|end
decl_stmt|;
name|char
modifier|*
name|private
decl_stmt|;
comment|/* optional machdep pointer */
block|}
name|db_symtab_t
typedef|;
end_typedef

begin_comment
comment|/*  * Symbol representation is specific to the symtab style:  * BSD compilers use dbx' nlist, other compilers might use  * a different one  */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|db_sym_t
typedef|;
end_typedef

begin_comment
comment|/* opaque handle on symbols */
end_comment

begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
name|c_db_sym_t
typedef|;
end_typedef

begin_comment
comment|/* opaque handle on symbols */
end_comment

begin_define
define|#
directive|define
name|DB_SYM_NULL
value|((db_sym_t)0)
end_define

begin_define
define|#
directive|define
name|C_DB_SYM_NULL
value|((c_db_sym_t)0)
end_define

begin_comment
comment|/*  * Non-stripped symbol tables will have duplicates, for instance  * the same string could match a parameter name, a local var, a  * global var, etc.  * We are most concern with the following matches.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|db_strategy_t
typedef|;
end_typedef

begin_comment
comment|/* search strategy */
end_comment

begin_define
define|#
directive|define
name|DB_STGY_ANY
value|0
end_define

begin_comment
comment|/* anything goes */
end_comment

begin_define
define|#
directive|define
name|DB_STGY_XTRN
value|1
end_define

begin_comment
comment|/* only external symbols */
end_comment

begin_define
define|#
directive|define
name|DB_STGY_PROC
value|2
end_define

begin_comment
comment|/* only procedures */
end_comment

begin_comment
comment|/*  * Functions exported by the symtable module  */
end_comment

begin_function_decl
name|void
name|db_add_symbol_table
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* extend the list of symbol tables */
end_comment

begin_function_decl
name|c_db_sym_t
name|db_search_symbol
parameter_list|(
name|db_addr_t
parameter_list|,
name|db_strategy_t
parameter_list|,
name|db_expr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* find symbol given value */
end_comment

begin_function_decl
name|void
name|db_symbol_values
parameter_list|(
name|c_db_sym_t
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|db_expr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return name and value of symbol */
end_comment

begin_define
define|#
directive|define
name|db_find_sym_and_offset
parameter_list|(
name|val
parameter_list|,
name|namep
parameter_list|,
name|offp
parameter_list|)
define|\
value|db_symbol_values(db_search_symbol(val,DB_STGY_ANY,offp),namep,0)
end_define

begin_comment
comment|/* find name&value given approx val */
end_comment

begin_define
define|#
directive|define
name|db_find_xtrn_sym_and_offset
parameter_list|(
name|val
parameter_list|,
name|namep
parameter_list|,
name|offp
parameter_list|)
define|\
value|db_symbol_values(db_search_symbol(val,DB_STGY_XTRN,offp),namep,0)
end_define

begin_comment
comment|/* ditto, but no locals */
end_comment

begin_function_decl
name|int
name|db_eqname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* strcmp, modulo leading char */
end_comment

begin_function_decl
name|void
name|db_printsym
parameter_list|(
name|db_expr_t
parameter_list|,
name|db_strategy_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* print closest symbol to a value */
end_comment

begin_function_decl
name|int
name|db_sym_numargs
parameter_list|(
name|c_db_sym_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|X_db_line_at_pc
parameter_list|(
name|db_symtab_t
modifier|*
name|symtab
parameter_list|,
name|c_db_sym_t
name|cursym
parameter_list|,
name|char
modifier|*
modifier|*
name|filename
parameter_list|,
name|int
modifier|*
name|linenum
parameter_list|,
name|db_expr_t
name|off
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|c_db_sym_t
name|X_db_lookup
parameter_list|(
name|db_symtab_t
modifier|*
name|stab
parameter_list|,
specifier|const
name|char
modifier|*
name|symstr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|c_db_sym_t
name|X_db_search_symbol
parameter_list|(
name|db_symtab_t
modifier|*
name|symtab
parameter_list|,
name|db_addr_t
name|off
parameter_list|,
name|db_strategy_t
name|strategy
parameter_list|,
name|db_expr_t
modifier|*
name|diffp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|X_db_sym_numargs
parameter_list|(
name|db_symtab_t
modifier|*
parameter_list|,
name|c_db_sym_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|X_db_symbol_values
parameter_list|(
name|db_symtab_t
modifier|*
name|symtab
parameter_list|,
name|c_db_sym_t
name|sym
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|namep
parameter_list|,
name|db_expr_t
modifier|*
name|valuep
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DDB_DB_SYM_H_ */
end_comment

end_unit

