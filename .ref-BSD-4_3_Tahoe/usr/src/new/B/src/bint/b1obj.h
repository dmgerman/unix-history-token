begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b1obj.h,v 1.4 85/08/22 16:42:02 timo Exp $ */
end_comment

begin_comment
comment|/* B values, locations, environments: the B abstract machine */
end_comment

begin_comment
comment|/****************************** general ******************************/
end_comment

begin_typedef
typedef|typedef
name|int
name|relation
typedef|;
end_typedef

begin_comment
comment|/*< 0, == 0,> 0 */
end_comment

begin_function_decl
name|relation
name|compare
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|Is_text
parameter_list|(
name|v
parameter_list|)
value|(Type(v) == Tex)
end_define

begin_define
define|#
directive|define
name|Is_number
parameter_list|(
name|v
parameter_list|)
value|(Type(v) == Num)
end_define

begin_define
define|#
directive|define
name|Is_compound
parameter_list|(
name|v
parameter_list|)
value|(Type(v) == Com)
end_define

begin_define
define|#
directive|define
name|Is_list
parameter_list|(
name|v
parameter_list|)
value|(Type(v) == Lis || Type(v) == ELT)
end_define

begin_define
define|#
directive|define
name|Is_table
parameter_list|(
name|v
parameter_list|)
value|(Type(v) == Tab || Type(v) == ELT)
end_define

begin_define
define|#
directive|define
name|Is_tlt
parameter_list|(
name|v
parameter_list|)
value|(Type(v)==Tex || Type(v)==Lis || Type(v)==Tab || Type(v)==ELT)
end_define

begin_define
define|#
directive|define
name|Is_ELT
parameter_list|(
name|v
parameter_list|)
value|(Type(v) == ELT)
end_define

begin_define
define|#
directive|define
name|Is_parsetree
parameter_list|(
name|v
parameter_list|)
value|(Type(v) == Ptn)
end_define

begin_define
define|#
directive|define
name|Is_locloc
parameter_list|(
name|v
parameter_list|)
value|IsSmallInt(v)
end_define

begin_define
define|#
directive|define
name|Is_simploc
parameter_list|(
name|v
parameter_list|)
value|(Type(v) == Sim)
end_define

begin_define
define|#
directive|define
name|Is_tbseloc
parameter_list|(
name|v
parameter_list|)
value|(Type(v) == Tse)
end_define

begin_define
define|#
directive|define
name|Is_trimloc
parameter_list|(
name|v
parameter_list|)
value|(Type(v) == Tri)
end_define

begin_define
define|#
directive|define
name|Is_refinement
parameter_list|(
name|v
parameter_list|)
value|(Type(v) == Ref)
end_define

begin_define
define|#
directive|define
name|Is_formal
parameter_list|(
name|v
parameter_list|)
value|(Type(v) == For)
end_define

begin_define
define|#
directive|define
name|Is_filed
parameter_list|(
name|v
parameter_list|)
value|(Type(v) == Per)
end_define

begin_define
define|#
directive|define
name|Is_function
parameter_list|(
name|v
parameter_list|)
value|(Type(v) == Fun)
end_define

begin_define
define|#
directive|define
name|Is_predicate
parameter_list|(
name|v
parameter_list|)
value|(Type(v) == Prd)
end_define

begin_define
define|#
directive|define
name|Is_howto
parameter_list|(
name|v
parameter_list|)
value|(Type(v) == How)
end_define

begin_function_decl
name|value
name|grab_num
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|regrab_num
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|grab_rat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|grab_tex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|grab_com
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|grab_elt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|grab_lis
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|grab_tab
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|grab_ptn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|grab_sim
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|grab_tri
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|grab_tse
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|grab_how
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|grab_for
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|grab_per
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|grab_fun
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|grab_prd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|grab_ref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|copy
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure release(); */
end_comment

begin_comment
comment|/* Procedure uniql(); */
end_comment

begin_comment
comment|/* Procedure uniq_assoc(); */
end_comment

begin_function_decl
name|double
name|hash
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/****************************** Texts ******************************/
end_comment

begin_decl_stmt
name|string
name|strcpy
argument_list|()
decl_stmt|,
name|strncpy
argument_list|()
decl_stmt|,
name|strcat
argument_list|()
decl_stmt|,
name|sprintf
argument_list|()
decl_stmt|,
name|index
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|character
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|mk_text
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|charval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|string
name|strval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|concat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|behead
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|curtail
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|INTEGRATION
end_ifdef

begin_function_decl
name|value
name|trim
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|value
name|repeat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|adjleft
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|centre
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|adjright
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|convert
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/****************************** Numbers ******************************/
end_comment

begin_comment
comment|/* Predicates */
end_comment

begin_function_decl
name|bool
name|integral
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* is the value an integer? */
end_comment

begin_function_decl
name|bool
name|large
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* can a number be represented by a C int? */
end_comment

begin_comment
comment|/* Constants */
end_comment

begin_define
define|#
directive|define
name|zero
value|MkSmallInt(0)
end_define

begin_define
define|#
directive|define
name|one
value|MkSmallInt(1)
end_define

begin_comment
comment|/* Conversion of abstract values to concrete objects */
end_comment

begin_function_decl
name|double
name|numval
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* numeric value of any number */
end_comment

begin_function_decl
name|int
name|intval
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* numeric value of integral number */
end_comment

begin_function_decl
name|intlet
name|propintlet
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* converts int to intlet */
end_comment

begin_function_decl
name|string
name|convnum
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* character string approximation of any number */
end_comment

begin_function_decl
name|relation
name|numcomp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* comparison of two numbers: yields -1, 0 or 1 */
end_comment

begin_function_decl
name|double
name|numhash
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* hashes any abstract number to a 'double' */
end_comment

begin_comment
comment|/* Conversion of concrete objects to abstract numbers */
end_comment

begin_function_decl
name|value
name|numconst
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* string argument */
end_comment

begin_function_decl
name|value
name|mk_integer
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* int argument */
end_comment

begin_comment
comment|/* Functions on numbers */
end_comment

begin_function_decl
name|value
name|sum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|diff
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|negated
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|prod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|quot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|modulo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|floorf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|ceilf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|round1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|round2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|mod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|power
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|absval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|signum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|numerator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|denominator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|approximate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|random
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|root1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|sin1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|cos1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|tan1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|atn1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|exp1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|log1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|root2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|atn2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|log2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|pi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|e
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/****************************** Compounds ******************************/
end_comment

begin_define
define|#
directive|define
name|Nfields
parameter_list|(
name|c
parameter_list|)
value|Length(c)
end_define

begin_define
define|#
directive|define
name|Field
parameter_list|(
name|c
parameter_list|,
name|i
parameter_list|)
value|((Ats(c)+(i)))
end_define

begin_define
define|#
directive|define
name|k_Overfields
value|for (k= 0; k< len; k++)
end_define

begin_define
define|#
directive|define
name|Lastfield
parameter_list|(
name|k
parameter_list|)
value|((k) == len-1)
end_define

begin_define
define|#
directive|define
name|mk_compound
parameter_list|(
name|len
parameter_list|)
value|grab_com(len)
end_define

begin_comment
comment|/****************************** Lists ******************************/
end_comment

begin_function_decl
name|value
name|mk_numrange
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|mk_charrange
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure insert(); */
end_comment

begin_comment
comment|/* Procedure remove(); */
end_comment

begin_comment
comment|/****************************** Tables ******************************/
end_comment

begin_function_decl
name|value
name|keys
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|in_keys
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|associate
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure replace(); */
end_comment

begin_comment
comment|/* Procedure delete(); */
end_comment

begin_function_decl
name|value
modifier|*
name|adrassoc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
modifier|*
name|key
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
modifier|*
name|assoc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/****************************** Texts, Lists, and Tables *******************/
end_comment

begin_function_decl
name|value
name|mk_elt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|in
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|size
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|size2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|min1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|min2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|max1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|max2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|th_of
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|thof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|length
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The same as size, temporary until part2 is written in B */
end_comment

begin_function_decl
name|bool
name|empty
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* whether #v=0: also temporary */
end_comment

begin_comment
comment|/****************************** Other kinds of value ************************/
end_comment

begin_define
define|#
directive|define
name|Simploc
parameter_list|(
name|l
parameter_list|)
value|((simploc *)Ats(l))
end_define

begin_define
define|#
directive|define
name|Tbseloc
parameter_list|(
name|l
parameter_list|)
value|((tbseloc *)Ats(l))
end_define

begin_define
define|#
directive|define
name|Trimloc
parameter_list|(
name|l
parameter_list|)
value|((trimloc *)Ats(l))
end_define

begin_define
define|#
directive|define
name|Funprd
parameter_list|(
name|f
parameter_list|)
value|((funprd *)Ats(f))
end_define

begin_define
define|#
directive|define
name|How_to
parameter_list|(
name|u
parameter_list|)
value|((how *)Ats(u))
end_define

begin_define
define|#
directive|define
name|Formal
parameter_list|(
name|f
parameter_list|)
value|((formal *)Ats(f))
end_define

begin_define
define|#
directive|define
name|Refinement
parameter_list|(
name|r
parameter_list|)
value|((ref *)Ats(r))
end_define

begin_define
define|#
directive|define
name|Perm
parameter_list|(
name|p
parameter_list|)
value|((per *)Ats(p))
end_define

begin_function_decl
name|loc
name|mk_simploc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|loc
name|mk_trimloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|loc
name|mk_tbseloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|mk_per
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|fun
name|mk_fun
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|prd
name|mk_prd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|mk_how
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|mk_ref
parameter_list|()
function_decl|;
end_function_decl

end_unit

