begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: b.h,v 1.1 84/06/28 00:48:39 timo Exp $ */
end_comment

begin_comment
comment|/* b.h: general */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_define
define|#
directive|define
name|Forward
end_define

begin_define
define|#
directive|define
name|Visible
end_define

begin_define
define|#
directive|define
name|Hidden
value|static
end_define

begin_define
define|#
directive|define
name|Procedure
end_define

begin_define
define|#
directive|define
name|EQ
value|==
end_define

begin_define
define|#
directive|define
name|NE
value|!=
end_define

begin_comment
comment|/* The following are not intended as pseudo-encapsulation, */
end_comment

begin_comment
comment|/* but to emphasize intention. */
end_comment

begin_typedef
typedef|typedef
name|char
name|literal
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|bool
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|txptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|string
typedef|;
end_typedef

begin_comment
comment|/* Strings are always terminated with a char '\0'. */
end_comment

begin_define
define|#
directive|define
name|Yes
value|((bool) 1)
end_define

begin_define
define|#
directive|define
name|No
value|((bool) 0)
end_define

begin_typedef
typedef|typedef
name|short
name|intlet
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|bool
name|bugs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* Values                                                               */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* There are different modules for values, however all agree that       */
end_comment

begin_comment
comment|/* the first field of a value is its type, and the second its reference */
end_comment

begin_comment
comment|/* count. All other fields depend on the module.                        */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|literal
name|type
decl_stmt|;
name|intlet
name|refcnt
decl_stmt|,
name|len
decl_stmt|;
name|string
modifier|*
name|cts
decl_stmt|;
block|}
typedef|*
name|value
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Dummy
value|0
end_define

begin_define
define|#
directive|define
name|Dumval
value|((value) Dummy)
end_define

begin_define
define|#
directive|define
name|Vnil
value|((value) 0)
end_define

begin_define
define|#
directive|define
name|Pnil
value|((value *) 0)
end_define

begin_comment
comment|/* Types: */
end_comment

begin_define
define|#
directive|define
name|Num
value|'0'
end_define

begin_define
define|#
directive|define
name|Tex
value|'"'
end_define

begin_define
define|#
directive|define
name|Com
value|','
end_define

begin_define
define|#
directive|define
name|Lis
value|'L'
end_define

begin_define
define|#
directive|define
name|Tab
value|'M'
end_define

begin_define
define|#
directive|define
name|ELT
value|'}'
end_define

begin_comment
comment|/* locations: */
end_comment

begin_define
define|#
directive|define
name|Sim
value|'S'
end_define

begin_define
define|#
directive|define
name|Tri
value|'@'
end_define

begin_define
define|#
directive|define
name|Tse
value|'['
end_define

begin_define
define|#
directive|define
name|Glo
value|'g'
end_define

begin_define
define|#
directive|define
name|Per
value|'p'
end_define

begin_comment
comment|/* units: */
end_comment

begin_define
define|#
directive|define
name|How
value|'h'
end_define

begin_define
define|#
directive|define
name|For
value|'f'
end_define

begin_define
define|#
directive|define
name|Ref
value|'r'
end_define

begin_define
define|#
directive|define
name|Fun
value|'+'
end_define

begin_define
define|#
directive|define
name|Prd
value|'i'
end_define

begin_define
define|#
directive|define
name|Type
parameter_list|(
name|v
parameter_list|)
value|((v)->type)
end_define

begin_define
define|#
directive|define
name|Length
parameter_list|(
name|v
parameter_list|)
value|((v)->len)
end_define

begin_define
define|#
directive|define
name|Refcnt
parameter_list|(
name|v
parameter_list|)
value|((v)->refcnt)
end_define

begin_define
define|#
directive|define
name|Unique
parameter_list|(
name|v
parameter_list|)
value|((v)->refcnt==1)
end_define

begin_define
define|#
directive|define
name|Overall
value|for (k= 0; k< len; k++)
end_define

begin_define
define|#
directive|define
name|k_Over_len
value|for (k= 0; k< len; k++)
end_define

begin_define
define|#
directive|define
name|Last
parameter_list|(
name|k
parameter_list|)
value|(k == len-1)
end_define

begin_define
define|#
directive|define
name|Ats
parameter_list|(
name|v
parameter_list|)
value|((value *)&((v)->cts))
end_define

begin_define
define|#
directive|define
name|Str
parameter_list|(
name|v
parameter_list|)
value|((string)&((v)->cts))
end_define

begin_comment
comment|/* only for use in part1 */
end_comment

begin_comment
comment|/* Environments and context */
end_comment

begin_typedef
typedef|typedef
name|value
name|envtab
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ec
block|{
name|envtab
name|tab
decl_stmt|;
name|struct
name|ec
modifier|*
name|inv_env
decl_stmt|;
block|}
name|envchain
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|envchain
modifier|*
name|env
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|env
name|curnv
decl_stmt|;
name|value
modifier|*
name|bndtgs
decl_stmt|;
name|literal
name|cntxt
decl_stmt|,
name|resexp
decl_stmt|;
name|value
name|uname
decl_stmt|;
name|literal
name|utype
decl_stmt|;
name|intlet
name|cur_ilev
decl_stmt|,
name|lino
decl_stmt|;
name|txptr
name|tx
decl_stmt|,
name|ceol
decl_stmt|;
block|}
name|context
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Enil
value|((env) 0)
end_define

begin_comment
comment|/* contexts: */
end_comment

begin_define
define|#
directive|define
name|In_command
value|'c'
end_define

begin_define
define|#
directive|define
name|In_read
value|'?'
end_define

begin_define
define|#
directive|define
name|In_unit
value|'u'
end_define

begin_define
define|#
directive|define
name|In_value
value|'v'
end_define

begin_define
define|#
directive|define
name|In_formal
value|'f'
end_define

begin_define
define|#
directive|define
name|In_prmnv
value|'p'
end_define

begin_comment
comment|/* results */
end_comment

begin_define
define|#
directive|define
name|Ret
value|'V'
end_define

begin_define
define|#
directive|define
name|Rep
value|'+'
end_define

begin_define
define|#
directive|define
name|Voi
value|' '
end_define

begin_comment
comment|/* adicity */
end_comment

begin_define
define|#
directive|define
name|Zer
value|'0'
end_define

begin_define
define|#
directive|define
name|Mon
value|'1'
end_define

begin_define
define|#
directive|define
name|Dya
value|'2'
end_define

begin_comment
comment|/* funprd.def */
end_comment

begin_define
define|#
directive|define
name|Pre
value|'P'
end_define

begin_define
define|#
directive|define
name|Use
value|'U'
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* A function or predicate is modelled as a compound consisting of      */
end_comment

begin_comment
comment|/* (i)   two short integers for (L, H) priority                         */
end_comment

begin_comment
comment|/*           (relevant only for functions);                             */
end_comment

begin_comment
comment|/* (ii)  Zer/Mon/Dya for zero-, mon- or dyadicity;                      */
end_comment

begin_comment
comment|/* (iii) Pre/Use for pre- or user-definedness;                          */
end_comment

begin_comment
comment|/* (iv)  if Pre, a literal to switch on;                                */
end_comment

begin_comment
comment|/*       if Use, a pointer to the yield/test-unit text.                 */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|envtab
name|reftab
decl_stmt|;
name|txptr
name|fux
decl_stmt|,
name|lux
decl_stmt|;
name|bool
name|filed
decl_stmt|;
block|}
name|how
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|envtab
name|reftab
decl_stmt|;
name|txptr
name|fux
decl_stmt|,
name|lux
decl_stmt|;
name|bool
name|filed
decl_stmt|;
name|intlet
name|L
decl_stmt|,
name|H
decl_stmt|;
name|literal
name|adic
decl_stmt|,
name|def
decl_stmt|;
block|}
name|funprd
typedef|;
end_typedef

begin_comment
comment|/* The first four fields should have the same structure as those of 'hows' */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|context
name|con
decl_stmt|;
name|txptr
name|ftx
decl_stmt|;
block|}
name|formal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|txptr
name|rp
decl_stmt|;
name|intlet
name|rlino
decl_stmt|;
block|}
name|ref
typedef|;
end_typedef

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* Locations                                                            */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* A simple location is modelled as a pair basic-identifier and         */
end_comment

begin_comment
comment|/*     environment, where a basic-identifier is modelled as a text      */
end_comment

begin_comment
comment|/*     and an environment as a pointer to a pair (T, E), where T is a   */
end_comment

begin_comment
comment|/*     table with basic-identifiers as keys and content values as       */
end_comment

begin_comment
comment|/*     associates, and E is the invoking environment or nil.            */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* A trimmed-text location is modelled as a triple (R, B, C).           */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* A compound location is modelled as a compound whose fields are       */
end_comment

begin_comment
comment|/*     locations, rather than values.                                   */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* A table-selection location is modelled as a pair (R, K).             */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|value
name|loc
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|value
name|basidf
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|basidf
name|i
decl_stmt|;
name|env
name|e
decl_stmt|;
block|}
name|simploc
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|loc
name|R
decl_stmt|;
name|intlet
name|B
decl_stmt|,
name|C
decl_stmt|;
block|}
name|trimloc
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|loc
name|R
decl_stmt|;
name|value
name|K
decl_stmt|;
block|}
name|tbseloc
typedef|;
end_typedef

begin_comment
comment|/* Functions and Predicates */
end_comment

begin_typedef
typedef|typedef
name|value
name|fun
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|value
name|prd
typedef|;
end_typedef

begin_decl_stmt
name|char
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|realloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

end_unit

