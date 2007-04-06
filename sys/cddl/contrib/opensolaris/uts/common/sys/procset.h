begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved  	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PROCSET_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PROCSET_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_comment
comment|/* SVr4.0 1.6 */
end_comment

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
file|<sys/feature_tests.h>
include|#
directive|include
file|<sys/types.h>
include|#
directive|include
file|<sys/signal.h>
comment|/*  *	This file defines the data needed to specify a set of  *	processes.  These types are used by the sigsend, sigsendset,  *	priocntl, priocntlset, waitid, evexit, and evexitset system  *	calls.  */
define|#
directive|define
name|P_INITPID
value|1
define|#
directive|define
name|P_INITUID
value|0
define|#
directive|define
name|P_INITPGID
value|0
comment|/*  *	The following defines the values for an identifier type.  It  *	specifies the interpretation of an id value.  An idtype and  *	id together define a simple set of processes.  */
typedef|typedef
enum|enum
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_XPG4_2
argument_list|)
operator|||
name|defined
argument_list|(
name|__EXTENSIONS__
argument_list|)
name|idtype
comment|/* pollutes XPG4.2 namespace */
endif|#
directive|endif
block|{
name|P_PID
block|,
comment|/* A process identifier.		*/
name|P_PPID
block|,
comment|/* A parent process identifier.		*/
name|P_PGID
block|,
comment|/* A process group (job control group)	*/
comment|/* identifier.				*/
name|P_SID
block|,
comment|/* A session identifier.		*/
name|P_CID
block|,
comment|/* A scheduling class identifier.	*/
name|P_UID
block|,
comment|/* A user identifier.			*/
name|P_GID
block|,
comment|/* A group identifier.			*/
name|P_ALL
block|,
comment|/* All processes.			*/
name|P_LWPID
block|,
comment|/* An LWP identifier.			*/
name|P_TASKID
block|,
comment|/* A task identifier.			*/
name|P_PROJID
block|,
comment|/* A project identifier.		*/
name|P_POOLID
block|,
comment|/* A pool identifier.			*/
name|P_ZONEID
block|,
comment|/* A zone identifier.			*/
name|P_CTID
block|,
comment|/* A (process) contract identifier.	*/
name|P_CPUID
block|,
comment|/* CPU identifier.			*/
name|P_PSETID
comment|/* Processor set identifier		*/
block|}
name|idtype_t
typedef|;
comment|/*  *	The following defines the operations which can be performed to  *	combine two simple sets of processes to form another set of  *	processes.  */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_XPG4_2
argument_list|)
operator|||
name|defined
argument_list|(
name|__EXTENSIONS__
argument_list|)
typedef|typedef
enum|enum
name|idop
block|{
name|POP_DIFF
block|,
comment|/* Set difference.  The processes which	*/
comment|/* are in the left operand set and not	*/
comment|/* in the right operand set.		*/
name|POP_AND
block|,
comment|/* Set disjunction.  The processes	*/
comment|/* which are in both the left and right	*/
comment|/* operand sets.			*/
name|POP_OR
block|,
comment|/* Set conjunction.  The processes	*/
comment|/* which are in either the left or the	*/
comment|/* right operand sets (or both).	*/
name|POP_XOR
comment|/* Set exclusive or.  The processes 	*/
comment|/* which are in either the left or	*/
comment|/* right operand sets but not in both.	*/
block|}
name|idop_t
typedef|;
comment|/*  *	The following structure is used to define a set of processes.  *	The set is defined in terms of two simple sets of processes  *	and an operator which operates on these two operand sets.  */
typedef|typedef
struct|struct
name|procset
block|{
name|idop_t
name|p_op
decl_stmt|;
comment|/* The operator connection the	*/
comment|/* following two operands each	*/
comment|/* of which is a simple set of	*/
comment|/* processes.			*/
name|idtype_t
name|p_lidtype
decl_stmt|;
comment|/* The type of the left operand	*/
comment|/* simple set.			*/
name|id_t
name|p_lid
decl_stmt|;
comment|/* The id of the left operand.	*/
name|idtype_t
name|p_ridtype
decl_stmt|;
comment|/* The type of the right	*/
comment|/* operand simple set.		*/
name|id_t
name|p_rid
decl_stmt|;
comment|/* The id of the right operand.	*/
block|}
name|procset_t
typedef|;
comment|/*  *	The following macro can be used to initialize a procset_t  *	structure.  */
define|#
directive|define
name|setprocset
parameter_list|(
name|psp
parameter_list|,
name|op
parameter_list|,
name|ltype
parameter_list|,
name|lid
parameter_list|,
name|rtype
parameter_list|,
name|rid
parameter_list|)
define|\
value|(psp)->p_op		= (op); \ 			(psp)->p_lidtype	= (ltype); \ 			(psp)->p_lid		= (lid); \ 			(psp)->p_ridtype	= (rtype); \ 			(psp)->p_rid		= (rid);
endif|#
directive|endif
comment|/* !defined(_XPG4_2) || defined(__EXTENSIONS__) */
ifdef|#
directive|ifdef
name|_KERNEL
struct_decl|struct
name|proc
struct_decl|;
specifier|extern
name|int
name|dotoprocs
parameter_list|(
name|procset_t
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|()
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dotolwp
parameter_list|(
name|procset_t
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|()
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|procinset
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|procset_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|sigsendproc
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|sigsend_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|sigsendset
parameter_list|(
name|procset_t
modifier|*
parameter_list|,
name|sigsend_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|boolean_t
name|cur_inset_only
parameter_list|(
name|procset_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|id_t
name|getmyid
parameter_list|(
name|idtype_t
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* _KERNEL */
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
comment|/* _SYS_PROCSET_H */
end_comment

end_unit

