begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright 1993 Open Software Foundation, Inc., Cambridge, Massachusetts.  *  All rights reserved.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994    * Open Software Foundation, Inc.   *    * Permission is hereby granted to use, copy, modify and freely distribute   * the software in this file and its documentation for any purpose without   * fee, provided that the above copyright notice appears in all copies and   * that both the copyright notice and this permission notice appear in   * supporting documentation.  Further, provided that the name of Open   * Software Foundation, Inc. ("OSF") not be used in advertising or   * publicity pertaining to distribution of the software without prior   * written permission from OSF.  OSF makes no representations about the   * suitability of this software for any purpose.  It is provided "as is"   * without express or implied warranty.   */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 X Consortium  * Copyright (c) 1995, 1996 Dalrymple Consulting  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE  * X CONSORTIUM OR DALRYMPLE CONSULTING BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *   * Except as contained in this notice, the names of the X Consortium and  * Dalrymple Consulting shall not be used in advertising or otherwise to  * promote the sale, use or other dealings in this Software without prior  * written authorization.  */
end_comment

begin_comment
comment|/* ________________________________________________________________________  *  *  Program to manipulate SGML instances.  *  *  These are data definitions for the "translating" portion of the program.  *  * ________________________________________________________________________  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STORAGE
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|tr_h_RCSid
init|=
literal|"$Header: /usr/src/docbook-to-man/Instant/RCS/translate.h,v 1.3 1996/06/02 21:47:32 fld Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|L_CURLY
value|'{'
end_define

begin_define
define|#
directive|define
name|R_CURLY
value|'}'
end_define

begin_comment
comment|/* things to ignore when processing an element */
end_comment

begin_define
define|#
directive|define
name|IGN_NONE
value|0
end_define

begin_define
define|#
directive|define
name|IGN_ALL
value|1
end_define

begin_define
define|#
directive|define
name|IGN_DATA
value|2
end_define

begin_define
define|#
directive|define
name|IGN_CHILDREN
value|3
end_define

begin_comment
comment|/* for CheckRelation() */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|RA_Current
block|,
name|RA_Related
block|}
name|RelAction_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* attribute name string */
name|char
modifier|*
name|val
decl_stmt|;
comment|/* attribute value string */
name|regexp
modifier|*
name|rex
decl_stmt|;
comment|/* attribute value reg expr (compiled) */
block|}
name|AttPair_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_Trans
block|{
comment|/* criteria */
name|char
modifier|*
name|gi
decl_stmt|;
comment|/* element name of tag under consideration */
name|char
modifier|*
modifier|*
name|gilist
decl_stmt|;
comment|/* list of element names (multiple gi's) */
name|char
modifier|*
name|context
decl_stmt|;
comment|/* context in tree - looking depth levels up */
name|regexp
modifier|*
name|context_re
decl_stmt|;
comment|/* tree heirarchy looking depth levels up */
name|int
name|depth
decl_stmt|;
comment|/* number of levels to look up the tree */
name|AttPair_t
modifier|*
name|attpair
decl_stmt|;
comment|/* attr name-value pairs */
name|int
name|nattpairs
decl_stmt|;
comment|/* number of name-value pairs */
name|char
modifier|*
name|parent
decl_stmt|;
comment|/* GI has this element as parent */
name|int
name|nth_child
decl_stmt|;
comment|/* GI is Nth child of this of parent element */
name|char
modifier|*
name|content
decl_stmt|;
comment|/* element has this string in content */
name|regexp
modifier|*
name|content_re
decl_stmt|;
comment|/* content reg expr (compiled) */
name|char
modifier|*
name|pattrset
decl_stmt|;
comment|/* is this attr set (any value) in parent? */
name|char
modifier|*
name|var_name
decl_stmt|;
comment|/* variable name */
name|char
modifier|*
name|var_value
decl_stmt|;
comment|/* variable value */
name|char
modifier|*
name|var_RE_name
decl_stmt|;
comment|/* variable name (for VarREValue) */
name|regexp
modifier|*
name|var_RE_value
decl_stmt|;
comment|/* variable value (compiled, for VarREValue) */
name|Map_t
modifier|*
name|relations
decl_stmt|;
comment|/* various relations to check */
comment|/* actions */
name|char
modifier|*
name|starttext
decl_stmt|;
comment|/* string to output at the start tag */
name|char
modifier|*
name|endtext
decl_stmt|;
comment|/* string to output at the end tag */
name|char
modifier|*
name|replace
decl_stmt|;
comment|/* string to replace this subtree with */
name|char
modifier|*
name|message
decl_stmt|;
comment|/* message for stderr, if element encountered */
name|int
name|ignore
decl_stmt|;
comment|/* flag - ignore content or data of element? */
name|int
name|verbatim
decl_stmt|;
comment|/* flag - pass content verbatim or do cmap? */
name|char
modifier|*
name|var_reset
decl_stmt|;
name|char
modifier|*
name|increment
decl_stmt|;
comment|/* increment these variables */
name|Map_t
modifier|*
name|set_var
decl_stmt|;
comment|/* set these variables */
name|Map_t
modifier|*
name|incr_var
decl_stmt|;
comment|/* increment these variables */
name|char
modifier|*
name|quit
decl_stmt|;
comment|/* print message and exit */
comment|/* pointers and bookkeeping */
name|int
name|my_id
decl_stmt|;
comment|/* unique (hopefully) ID of this transpec */
name|int
name|use_id
decl_stmt|;
comment|/* use transpec whose ID is this */
name|struct
name|_Trans
modifier|*
name|use_trans
decl_stmt|;
comment|/* pointer to other transpec */
name|struct
name|_Trans
modifier|*
name|next
decl_stmt|;
comment|/* linked list */
name|int
name|lineno
decl_stmt|;
comment|/* line number of end of transpec */
block|}
name|Trans_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|def
end_ifdef

begin_undef
undef|#
directive|undef
name|def
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STORAGE
end_ifdef

begin_define
define|#
directive|define
name|def
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|def
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|def
name|Trans_t
modifier|*
name|TrSpecs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|def
name|Mapping_t
modifier|*
name|CharMap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|def
name|int
name|nCharMap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* prototypes for things defined in translate.c */
end_comment

begin_function_decl
name|int
name|CheckRelation
parameter_list|(
name|Element_t
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
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|RelAction_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Trans_t
modifier|*
name|FindTrans
parameter_list|(
name|Element_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Trans_t
modifier|*
name|FindTransByName
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Trans_t
modifier|*
name|FindTransByID
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrepTranspecs
parameter_list|(
name|Element_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ProcessOneSpec
parameter_list|(
name|char
modifier|*
parameter_list|,
name|Element_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|TransElement
parameter_list|(
name|Element_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|Trans_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|TranByAction
parameter_list|(
name|Element_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|TranTByAction
parameter_list|(
name|Element_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* prototypes for things defined in tranvar.c */
end_comment

begin_function_decl
name|void
name|ExpandSpecialVar
parameter_list|(
name|char
modifier|*
parameter_list|,
name|Element_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* prototypes for things defined in tables.c */
end_comment

begin_function_decl
name|void
name|OSFtable
parameter_list|(
name|Element_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ______________________________________________________________________ */
end_comment

end_unit

