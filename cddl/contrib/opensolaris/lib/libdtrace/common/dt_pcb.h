begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_PCB_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_PCB_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<dtrace.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<dt_parser.h>
include|#
directive|include
file|<dt_regset.h>
include|#
directive|include
file|<dt_inttab.h>
include|#
directive|include
file|<dt_strtab.h>
include|#
directive|include
file|<dt_decl.h>
include|#
directive|include
file|<dt_as.h>
typedef|typedef
struct|struct
name|dt_pcb
block|{
name|dtrace_hdl_t
modifier|*
name|pcb_hdl
decl_stmt|;
comment|/* pointer to library handle */
name|struct
name|dt_pcb
modifier|*
name|pcb_prev
decl_stmt|;
comment|/* pointer to previous pcb in stack */
name|FILE
modifier|*
name|pcb_fileptr
decl_stmt|;
comment|/* pointer to input file (or NULL) */
name|char
modifier|*
name|pcb_filetag
decl_stmt|;
comment|/* optional file name string (or NULL) */
specifier|const
name|char
modifier|*
name|pcb_string
decl_stmt|;
comment|/* pointer to input string (or NULL) */
specifier|const
name|char
modifier|*
name|pcb_strptr
decl_stmt|;
comment|/* pointer to input position */
name|size_t
name|pcb_strlen
decl_stmt|;
comment|/* length of pcb_string */
name|int
name|pcb_sargc
decl_stmt|;
comment|/* number of script arguments (if any) */
name|char
modifier|*
specifier|const
modifier|*
name|pcb_sargv
decl_stmt|;
comment|/* script argument strings (if any) */
name|ushort_t
modifier|*
name|pcb_sflagv
decl_stmt|;
comment|/* script argument flags (DT_IDFLG_* bits) */
name|dt_scope_t
name|pcb_dstack
decl_stmt|;
comment|/* declaration processing stack */
name|dt_node_t
modifier|*
name|pcb_list
decl_stmt|;
comment|/* list of allocated parse tree nodes */
name|dt_node_t
modifier|*
name|pcb_hold
decl_stmt|;
comment|/* parse tree nodes on hold until end of defn */
name|dt_node_t
modifier|*
name|pcb_root
decl_stmt|;
comment|/* root of current parse tree */
name|dt_idstack_t
name|pcb_globals
decl_stmt|;
comment|/* stack of global identifier hash tables */
name|dt_idhash_t
modifier|*
name|pcb_locals
decl_stmt|;
comment|/* current hash table of local identifiers */
name|dt_idhash_t
modifier|*
name|pcb_idents
decl_stmt|;
comment|/* current hash table of ambiguous idents */
name|dt_idhash_t
modifier|*
name|pcb_pragmas
decl_stmt|;
comment|/* current hash table of pending pragmas */
name|dt_inttab_t
modifier|*
name|pcb_inttab
decl_stmt|;
comment|/* integer table for constant references */
name|dt_strtab_t
modifier|*
name|pcb_strtab
decl_stmt|;
comment|/* string table for string references */
name|dt_regset_t
modifier|*
name|pcb_regs
decl_stmt|;
comment|/* register set for code generation */
name|dt_irlist_t
name|pcb_ir
decl_stmt|;
comment|/* list of unrelocated IR instructions */
name|uint_t
name|pcb_asvidx
decl_stmt|;
comment|/* assembler vartab index (see dt_as.c) */
name|ulong_t
modifier|*
modifier|*
name|pcb_asxrefs
decl_stmt|;
comment|/* assembler imported xlators (see dt_as.c) */
name|uint_t
name|pcb_asxreflen
decl_stmt|;
comment|/* assembler xlator map length (see dt_as.c) */
specifier|const
name|dtrace_probedesc_t
modifier|*
name|pcb_pdesc
decl_stmt|;
comment|/* probedesc for current context */
name|struct
name|dt_probe
modifier|*
name|pcb_probe
decl_stmt|;
comment|/* probe associated with current context */
name|dtrace_probeinfo_t
name|pcb_pinfo
decl_stmt|;
comment|/* info associated with current context */
name|dtrace_attribute_t
name|pcb_amin
decl_stmt|;
comment|/* stability minimum for compilation */
name|dt_node_t
modifier|*
name|pcb_dret
decl_stmt|;
comment|/* node containing return type for assembler */
name|dtrace_difo_t
modifier|*
name|pcb_difo
decl_stmt|;
comment|/* intermediate DIF object made by assembler */
name|dtrace_prog_t
modifier|*
name|pcb_prog
decl_stmt|;
comment|/* intermediate program made by compiler */
name|dtrace_stmtdesc_t
modifier|*
name|pcb_stmt
decl_stmt|;
comment|/* intermediate stmt made by compiler */
name|dtrace_ecbdesc_t
modifier|*
name|pcb_ecbdesc
decl_stmt|;
comment|/* intermediate ecbdesc made by cmplr */
name|jmp_buf
name|pcb_jmpbuf
decl_stmt|;
comment|/* setjmp(3C) buffer for error return */
specifier|const
name|char
modifier|*
name|pcb_region
decl_stmt|;
comment|/* optional region name for yyerror() suffix */
name|dtrace_probespec_t
name|pcb_pspec
decl_stmt|;
comment|/* probe description evaluation context */
name|uint_t
name|pcb_cflags
decl_stmt|;
comment|/* optional compilation flags (see dtrace.h) */
name|uint_t
name|pcb_idepth
decl_stmt|;
comment|/* preprocessor #include nesting depth */
name|yystate_t
name|pcb_yystate
decl_stmt|;
comment|/* lex/yacc parsing state (see yybegin()) */
name|int
name|pcb_context
decl_stmt|;
comment|/* yyparse() rules context (DT_CTX_* value) */
name|int
name|pcb_token
decl_stmt|;
comment|/* token to be returned by yylex() (if != 0) */
name|int
name|pcb_cstate
decl_stmt|;
comment|/* state to be restored by lexer at state end */
name|int
name|pcb_braces
decl_stmt|;
comment|/* number of open curly braces in lexer */
name|int
name|pcb_brackets
decl_stmt|;
comment|/* number of open square brackets in lexer */
name|int
name|pcb_parens
decl_stmt|;
comment|/* number of open parentheses in lexer */
block|}
name|dt_pcb_t
typedef|;
specifier|extern
name|void
name|dt_pcb_push
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dt_pcb_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_pcb_pop
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_PCB_H */
end_comment

end_unit

