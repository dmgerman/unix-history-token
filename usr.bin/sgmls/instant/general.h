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
comment|/* ________________________________________________________________________  *  *  Common definitions for "instant" program.  * ________________________________________________________________________  */
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
name|gen_h_RCSid
init|=
literal|"$Header: /usr/src/docbook-to-man/Instant/RCS/general.h,v 1.5 1996/06/11 20:25:03 fld Exp $"
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

begin_comment
comment|/* string/numeric/character definitions */
end_comment

begin_define
define|#
directive|define
name|EOS
value|'\0'
end_define

begin_define
define|#
directive|define
name|NL
value|'\n'
end_define

begin_define
define|#
directive|define
name|TAB
value|'\t'
end_define

begin_define
define|#
directive|define
name|CR
value|'\r'
end_define

begin_define
define|#
directive|define
name|ANCHOR
value|'^'
end_define

begin_comment
comment|/* bigmask/flags for the Split() function */
end_comment

begin_define
define|#
directive|define
name|S_STRDUP
value|0x01
end_define

begin_define
define|#
directive|define
name|S_ALVEC
value|0x02
end_define

begin_comment
comment|/*  Command codes (1st char of esis lines) from sgmls.  See its manpage. */
end_comment

begin_define
define|#
directive|define
name|CMD_DATA
value|'-'
end_define

begin_define
define|#
directive|define
name|CMD_OPEN
value|'('
end_define

begin_define
define|#
directive|define
name|CMD_CLOSE
value|')'
end_define

begin_define
define|#
directive|define
name|CMD_ATT
value|'A'
end_define

begin_define
define|#
directive|define
name|CMD_D_ATT
value|'D'
end_define

begin_define
define|#
directive|define
name|CMD_NOTATION
value|'N'
end_define

begin_define
define|#
directive|define
name|CMD_EXT_ENT
value|'E'
end_define

begin_define
define|#
directive|define
name|CMD_INT_ENT
value|'I'
end_define

begin_define
define|#
directive|define
name|CMD_SYSID
value|'s'
end_define

begin_define
define|#
directive|define
name|CMD_PUBID
value|'p'
end_define

begin_define
define|#
directive|define
name|CMD_FILENAME
value|'f'
end_define

begin_define
define|#
directive|define
name|CMD_LINE
value|'L'
end_define

begin_define
define|#
directive|define
name|CMD_PI
value|'?'
end_define

begin_define
define|#
directive|define
name|CMD_SUBDOC
value|'S'
end_define

begin_define
define|#
directive|define
name|CMD_SUBDOC_S
value|'{'
end_define

begin_define
define|#
directive|define
name|CMD_SUBDOC_E
value|'}'
end_define

begin_define
define|#
directive|define
name|CMD_EXT_REF
value|'&'
end_define

begin_define
define|#
directive|define
name|CMD_APPINFO
value|'#'
end_define

begin_define
define|#
directive|define
name|CMD_CONFORM
value|'C'
end_define

begin_comment
comment|/*  Some sizes */
end_comment

begin_define
define|#
directive|define
name|MAX_DEPTH
value|40
end_define

begin_define
define|#
directive|define
name|LINESIZE
value|60000
end_define

begin_comment
comment|/*  Name of library env variable, and default value. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TPT_LIB
end_ifndef

begin_define
define|#
directive|define
name|TPT_LIB
value|"TPT_LIB"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DEF_TPT_LIB
end_ifndef

begin_define
define|#
directive|define
name|DEF_TPT_LIB
value|"/usr/share/sgml/transpec"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  Relationships - for querying */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|REL_None
block|,
name|REL_Parent
block|,
name|REL_Child
block|,
name|REL_Ancestor
block|,
name|REL_Descendant
block|,
name|REL_Sibling
block|,
name|REL_Preceding
block|,
name|REL_ImmPreceding
block|,
name|REL_Following
block|,
name|REL_ImmFollowing
block|,
name|REL_Cousin
block|,
name|REL_Unknown
block|}
name|Relation_t
typedef|;
end_typedef

begin_comment
comment|/* Initial map sizes (IMS) */
end_comment

begin_define
define|#
directive|define
name|IMS_relations
value|3
end_define

begin_define
define|#
directive|define
name|IMS_setvar
value|3
end_define

begin_define
define|#
directive|define
name|IMS_incvar
value|3
end_define

begin_define
define|#
directive|define
name|IMS_sdata
value|50
end_define

begin_define
define|#
directive|define
name|IMS_sdatacache
value|30
end_define

begin_define
define|#
directive|define
name|IMS_variables
value|20
end_define

begin_define
define|#
directive|define
name|IMS_attnames
value|50
end_define

begin_define
define|#
directive|define
name|IMS_elemnames
value|50
end_define

begin_comment
comment|/* ----- typedef and other misc definitions ----- */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|(1 == 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|(1 == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|short
name|bool
typedef|;
end_typedef

begin_comment
comment|/* ----- structure definitions ----- */
end_comment

begin_comment
comment|/*  We use this for variables, attributes, etc., so the caller only needs an  *  opaque handle to the thing below, not worrying about array management.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of the thing */
name|char
modifier|*
name|sval
decl_stmt|;
comment|/* string value */
block|}
name|Mapping_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|n_alloc
decl_stmt|;
comment|/* number of elements allocated */
name|int
name|n_used
decl_stmt|;
comment|/* number of elements used */
name|int
name|slot_incr
decl_stmt|;
comment|/* increment for allocating slots */
name|int
name|flags
decl_stmt|;
comment|/* info about this set of mappings */
name|Mapping_t
modifier|*
name|maps
decl_stmt|;
comment|/* array of mappings */
block|}
name|Map_t
typedef|;
end_typedef

begin_comment
comment|/* ______________________________________________________________________ */
end_comment

begin_comment
comment|/*  Information about an entity reference.  Not all fields will be used  *  at once.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ent
block|{
name|char
modifier|*
name|type
decl_stmt|;
comment|/* entity type */
name|char
modifier|*
name|ename
decl_stmt|;
comment|/* entity name */
name|char
modifier|*
name|nname
decl_stmt|;
comment|/* notation name */
name|char
modifier|*
name|sysid
decl_stmt|;
comment|/* sys id */
name|char
modifier|*
name|pubid
decl_stmt|;
comment|/* pub id */
name|char
modifier|*
name|fname
decl_stmt|;
comment|/* filename */
name|struct
name|_ent
modifier|*
name|next
decl_stmt|;
comment|/* next in linked list */
block|}
name|Entity_t
typedef|;
end_typedef

begin_comment
comment|/*  Content (child nodes) of an element (node in the tree) -- both data  *  and other elements.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|type
decl_stmt|;
comment|/* element, data, or pi? */
union|union
block|{
name|struct
name|_elem
modifier|*
name|elem
decl_stmt|;
comment|/* direct children of this elem */
name|char
modifier|*
name|data
decl_stmt|;
comment|/* character data of this elem */
block|}
name|ch
union|;
block|}
name|Content_t
typedef|;
end_typedef

begin_comment
comment|/*  An element (node in the tree) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_elem
block|{
name|char
modifier|*
name|gi
decl_stmt|;
comment|/* element GI */
name|Content_t
modifier|*
name|cont
decl_stmt|;
comment|/* content - element& data children */
name|int
name|ncont
decl_stmt|;
comment|/* # of content/children */
name|struct
name|_elem
modifier|*
modifier|*
name|econt
decl_stmt|;
comment|/* element children */
name|int
name|necont
decl_stmt|;
comment|/* # of element children */
name|char
modifier|*
modifier|*
name|dcont
decl_stmt|;
comment|/* character data children */
name|int
name|ndcont
decl_stmt|;
comment|/* # of data children */
name|Mapping_t
modifier|*
name|atts
decl_stmt|;
comment|/* array of attributes */
name|int
name|natts
decl_stmt|;
comment|/* # of attributes */
name|Entity_t
modifier|*
name|entity
decl_stmt|;
comment|/* ext entity& notation info */
name|char
modifier|*
name|id
decl_stmt|;
comment|/* for linking */
name|int
name|index
decl_stmt|;
comment|/* an internal bookkeeping mechanism */
name|int
name|depth
decl_stmt|;
comment|/* how deep in tree */
name|int
name|lineno
decl_stmt|;
comment|/* line number */
name|char
modifier|*
name|infile
decl_stmt|;
comment|/* input filename */
name|int
name|my_eorder
decl_stmt|;
comment|/* order of this elem of its parent */
name|struct
name|_elem
modifier|*
name|parent
decl_stmt|;
comment|/* this elem's direct parent */
name|struct
name|_elem
modifier|*
name|next
decl_stmt|;
comment|/* kept in linked list */
name|void
modifier|*
name|trans
decl_stmt|;
comment|/* pointer to translation spec */
comment|/* I'm not crazy about this, but it works */
name|int
name|gen_trans
index|[
literal|2
index|]
decl_stmt|;
comment|/* refs to generated trans specs */
name|int
name|processed
decl_stmt|;
comment|/* was this node processed? */
block|}
name|Element_t
typedef|;
end_typedef

begin_comment
comment|/*  For mapping of element IDs to elements themselves.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|id_s
block|{
name|char
modifier|*
name|id
decl_stmt|;
comment|/* ID of the element */
name|Element_t
modifier|*
name|elem
decl_stmt|;
comment|/* pointer to it */
name|struct
name|id_s
modifier|*
name|next
decl_stmt|;
block|}
name|ID_t
typedef|;
end_typedef

begin_comment
comment|/* ----- global variable declarations ----- */
end_comment

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
name|Element_t
modifier|*
name|DocTree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* root of document tree */
end_comment

begin_decl_stmt
name|def
name|char
modifier|*
modifier|*
name|UsedElem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a unique list of used elem names */
end_comment

begin_decl_stmt
name|def
name|int
name|nUsedElem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of used elem names */
end_comment

begin_decl_stmt
name|def
name|char
modifier|*
modifier|*
name|UsedAtt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a unique list of used attrib names */
end_comment

begin_decl_stmt
name|def
name|int
name|nUsedAtt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of used attrib names */
end_comment

begin_decl_stmt
name|def
name|ID_t
modifier|*
name|IDList
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of IDs used in the doc */
end_comment

begin_decl_stmt
name|def
name|Map_t
modifier|*
name|Variables
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* general, global variables */
end_comment

begin_decl_stmt
name|def
name|Map_t
modifier|*
name|SDATAmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SDATA mappings */
end_comment

begin_decl_stmt
name|def
name|Map_t
modifier|*
name|PImap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Processing Instruction mappings */
end_comment

begin_decl_stmt
name|def
name|Entity_t
modifier|*
name|Entities
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of entities */
end_comment

begin_decl_stmt
name|def
name|FILE
modifier|*
name|outfp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where output is written */
end_comment

begin_decl_stmt
name|def
name|char
modifier|*
name|tpt_lib
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TPT library directory */
end_comment

begin_decl_stmt
name|def
name|int
name|verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag - verbose output? */
end_comment

begin_decl_stmt
name|def
name|int
name|warnings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag - show warnings? */
end_comment

begin_decl_stmt
name|def
name|int
name|interactive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag - interactive browsing? */
end_comment

begin_decl_stmt
name|def
name|int
name|slave
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* are we slave to another process? */
end_comment

begin_decl_stmt
name|def
name|int
name|fold_case
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag - fold case of GIs? */
end_comment

begin_comment
comment|/* ----- some macros for convenience and ease of code reading ----- */
end_comment

begin_define
define|#
directive|define
name|stripNL
parameter_list|(
name|s
parameter_list|)
value|{ char *_cp; if ((_cp=strchr(s, NL))) *_cp = EOS; }
end_define

begin_comment
comment|/*  Similar to calloc(), malloc(), and realloc(), but check for success.  *  Args to all:  *	(1) number of 'elements' to allocate  *	(2) variable to point at allocated space  *	(3) type of 'element'  *  Eg:	Calloc(5, e, Element_t) replaces  *	if (!(e = (Element_t *)calloc(5, sizeof(Element_t))) {  *		... handle error ... ;  *	}  */
end_comment

begin_define
define|#
directive|define
name|Calloc
parameter_list|(
name|N
parameter_list|,
name|V
parameter_list|,
name|T
parameter_list|)
define|\
value|{ if (!((V) = (T *)calloc((size_t)N, sizeof(T)))) { \ 	perror("Calloc failed -- out of memory.  Bailing out.");  exit(1); \     }; memset((void *) (V), 0, (size_t) sizeof(T)); }
end_define

begin_define
define|#
directive|define
name|Malloc
parameter_list|(
name|N
parameter_list|,
name|V
parameter_list|,
name|T
parameter_list|)
define|\
value|{ if (!((V) = (T *)malloc((size_t)N*sizeof(T)))) { \ 	perror("Malloc failed -- out of memory.  Bailing out.");  exit(1); \     }; memset((void *) (V), 0, (size_t) sizeof(T)); }
end_define

begin_define
define|#
directive|define
name|Realloc
parameter_list|(
name|N
parameter_list|,
name|V
parameter_list|,
name|T
parameter_list|)
define|\
value|{ if (!((V) = (T *)realloc(V,(size_t)N*sizeof(T)))) { \ 	perror("Realloc failed -- out of memory.  Bailing out.");  exit(1); \     } }
end_define

begin_comment
comment|/*  similar to strcmp(), but check first chars first, for efficiency */
end_comment

begin_define
define|#
directive|define
name|StrEq
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(s1[0] == s2[0]&& !strcmp(s1,s2))
end_define

begin_comment
comment|/*  similar to isspace(), but check for blank or tab - without overhead  *  of procedure call */
end_comment

begin_define
define|#
directive|define
name|IsWhite
parameter_list|(
name|c
parameter_list|)
value|(c == ' ' || c == TAB || c == NL)
end_define

begin_define
define|#
directive|define
name|ContType
parameter_list|(
name|e
parameter_list|,
name|i
parameter_list|)
value|(e->cont[i].type)
end_define

begin_define
define|#
directive|define
name|ContData
parameter_list|(
name|e
parameter_list|,
name|i
parameter_list|)
value|(e->cont[i].ch.data)
end_define

begin_define
define|#
directive|define
name|ContElem
parameter_list|(
name|e
parameter_list|,
name|i
parameter_list|)
value|(e->cont[i].ch.elem)
end_define

begin_define
define|#
directive|define
name|IsContData
parameter_list|(
name|e
parameter_list|,
name|i
parameter_list|)
value|(e->cont[i].type == CMD_DATA)
end_define

begin_define
define|#
directive|define
name|IsContElem
parameter_list|(
name|e
parameter_list|,
name|i
parameter_list|)
value|(e->cont[i].type == CMD_OPEN)
end_define

begin_define
define|#
directive|define
name|IsContPI
parameter_list|(
name|e
parameter_list|,
name|i
parameter_list|)
value|(e->cont[i].type == CMD_PI)
end_define

begin_comment
comment|/* ----- function prototypes ----- */
end_comment

begin_comment
comment|/* things defined in util.c */
end_comment

begin_function_decl
name|Element_t
modifier|*
name|QRelation
parameter_list|(
name|Element_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|Relation_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Relation_t
name|FindRelByName
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|FindAttValByName
parameter_list|(
name|Element_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|FindContext
parameter_list|(
name|Element_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|AddElemName
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|AddAttName
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ExpandString
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OutputString
parameter_list|(
name|char
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
name|char
modifier|*
name|LookupSDATA
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|OpenFile
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|FilePath
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|FindElementPath
parameter_list|(
name|Element_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|NearestOlderElem
parameter_list|(
name|Element_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrintLocation
parameter_list|(
name|Element_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|Split
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DescendTree
parameter_list|(
name|Element_t
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|()
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|()
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|()
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Map_t
modifier|*
name|NewMap
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Mapping_t
modifier|*
name|FindMapping
parameter_list|(
name|Map_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|FindMappingVal
parameter_list|(
name|Map_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetMapping
parameter_list|(
name|Map_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetMappingNV
parameter_list|(
name|Map_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddID
parameter_list|(
name|Element_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Element_t
modifier|*
name|FindElemByID
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* things defined in translate.c */
end_comment

begin_function_decl
name|void
name|DoTranslate
parameter_list|(
name|Element_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ExpandVariables
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|Element_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* things defined in traninit.c */
end_comment

begin_function_decl
name|void
name|ReadTransSpec
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* things defined in tranvar.c */
end_comment

begin_function_decl
name|char
modifier|*
name|Get_A_C_value
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* things defined in info.c */
end_comment

begin_function_decl
name|void
name|PrintContext
parameter_list|(
name|Element_t
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrintElemSummary
parameter_list|(
name|Element_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrintElemTree
parameter_list|(
name|Element_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrintStats
parameter_list|(
name|Element_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrintIDList
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* things defined in table.c */
end_comment

begin_function_decl
name|void
name|CALStable
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
comment|/* ----- other declarations ----- */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
end_ifdef

begin_define
define|#
directive|define
name|strdup
parameter_list|(
name|s
parameter_list|)
value|strcpy((char *)malloc(strlen(s)+1), s)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

