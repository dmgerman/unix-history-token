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

begin_decl_stmt
name|void
name|db_add_symbol_table
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extend the list of symbol tables */
end_comment

begin_decl_stmt
name|c_db_sym_t
name|db_search_symbol
name|__P
argument_list|(
operator|(
name|db_addr_t
operator|,
name|db_strategy_t
operator|,
name|db_expr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* find symbol given value */
end_comment

begin_decl_stmt
name|void
name|db_symbol_values
name|__P
argument_list|(
operator|(
name|c_db_sym_t
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
name|db_expr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|int
name|db_eqname
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* strcmp, modulo leading char */
end_comment

begin_decl_stmt
name|void
name|db_printsym
name|__P
argument_list|(
operator|(
name|db_expr_t
operator|,
name|db_strategy_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print closest symbol to a value */
end_comment

begin_decl_stmt
name|int
name|db_sym_numargs
name|__P
argument_list|(
operator|(
name|c_db_sym_t
operator|,
name|int
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|X_db_line_at_pc
name|__P
argument_list|(
operator|(
name|db_symtab_t
operator|*
name|symtab
operator|,
name|c_db_sym_t
name|cursym
operator|,
name|char
operator|*
operator|*
name|filename
operator|,
name|int
operator|*
name|linenum
operator|,
name|db_expr_t
name|off
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|c_db_sym_t
name|X_db_lookup
name|__P
argument_list|(
operator|(
name|db_symtab_t
operator|*
name|stab
operator|,
specifier|const
name|char
operator|*
name|symstr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|c_db_sym_t
name|X_db_search_symbol
name|__P
argument_list|(
operator|(
name|db_symtab_t
operator|*
name|symtab
operator|,
name|db_addr_t
name|off
operator|,
name|db_strategy_t
name|strategy
operator|,
name|db_expr_t
operator|*
name|diffp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|X_db_sym_numargs
name|__P
argument_list|(
operator|(
name|db_symtab_t
operator|*
operator|,
name|c_db_sym_t
operator|,
name|int
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|X_db_symbol_values
name|__P
argument_list|(
operator|(
name|db_symtab_t
operator|*
name|symtab
operator|,
name|c_db_sym_t
name|sym
operator|,
specifier|const
name|char
operator|*
operator|*
name|namep
operator|,
name|db_expr_t
operator|*
name|valuep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DDB_DB_SYM_H_ */
end_comment

end_unit

