begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: node.h,v 2.4 85/08/22 16:05:40 timo Exp $ */
end_comment

begin_comment
comment|/*  * B editor -- Parse tree and Focus stack.  */
end_comment

begin_comment
comment|/*  * Assertion macro.  *  * This one differs from the one in #include<assert.h> in that it  * is usable as an expression operand, e.g. up(ep) || Assert(No).  * The function asserr() must unconditionally terminate the program.  * If the accumulated __FILE__ data wastes too much of your data  * space, omit them and change the code in asserr() that uses them.  * You better trust your code then, because unless compiled with "-g"  * it's difficult to dig the line number information from the core dump.  *  * There is also a variant called Abort() which is equivalent to Assert(No).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NDEBUG
end_ifdef

begin_define
define|#
directive|define
name|Abort
parameter_list|()
value|abort()
end_define

begin_comment
comment|/* Always fail */
end_comment

begin_define
define|#
directive|define
name|Assert
parameter_list|(
name|cond
parameter_list|)
value|0
end_define

begin_comment
comment|/* Dummy expression */
end_comment

begin_else
else|#
directive|else
else|NDEBUG
end_else

begin_undef
undef|#
directive|undef
name|__FILE__
end_undef

begin_define
define|#
directive|define
name|__FILE__
value|rcsid
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__LINE__
end_ifndef

begin_define
define|#
directive|define
name|__LINE__
value|0
end_define

begin_endif
endif|#
directive|endif
endif|__LINE__
end_endif

begin_define
define|#
directive|define
name|Abort
parameter_list|()
value|asserr(__FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|Assert
parameter_list|(
name|cond
parameter_list|)
value|((cond) || Abort())
end_define

begin_endif
endif|#
directive|endif
endif|NDEBUG
end_endif

begin_typedef
typedef|typedef
name|struct
name|node
modifier|*
name|node
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|path
modifier|*
name|path
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|markbits
typedef|;
end_typedef

begin_struct
struct|struct
name|node
block|{
name|char
name|type
decl_stmt|;
name|char
name|_unused
decl_stmt|;
name|intlet
name|refcnt
decl_stmt|;
name|intlet
name|len
decl_stmt|;
name|markbits
name|n_marks
decl_stmt|;
name|intlet
name|n_width
decl_stmt|;
name|intlet
name|n_symbol
decl_stmt|;
name|node
name|n_child
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|path
block|{
name|char
name|type
decl_stmt|;
name|char
name|_unused
decl_stmt|;
name|intlet
name|refcnt
decl_stmt|;
name|intlet
name|len
decl_stmt|;
name|path
name|p_parent
decl_stmt|;
name|node
name|p_tree
decl_stmt|;
name|intlet
name|p_ichild
decl_stmt|;
name|intlet
name|p_ycoord
decl_stmt|;
name|intlet
name|p_xcoord
decl_stmt|;
name|intlet
name|p_level
decl_stmt|;
name|markbits
name|p_addmarks
decl_stmt|;
name|markbits
name|p_delmarks
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|Nnil
value|((node) NULL)
end_define

begin_function_decl
name|node
name|newnode
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_define
define|#
directive|define
name|symbol
parameter_list|(
name|n
parameter_list|)
value|(Assert(Type(n)==Nod), (n)->n_symbol)
end_define

begin_define
define|#
directive|define
name|nchildren
parameter_list|(
name|n
parameter_list|)
value|(Assert(Type(n)==Nod), Length(n))
end_define

begin_define
define|#
directive|define
name|marks
parameter_list|(
name|n
parameter_list|)
value|(Assert(Type(n)==Nod), (n)->n_marks)
end_define

begin_define
define|#
directive|define
name|child
parameter_list|(
name|n
parameter_list|,
name|i
parameter_list|)
define|\
value|(Assert(Type(n)==Nod&& (i)>0&& (i)<=Length(n)), (n)->n_child[(i)-1])
end_define

begin_define
define|#
directive|define
name|lastchild
parameter_list|(
name|n
parameter_list|)
define|\
value|(Assert(Type(n)==Nod&& Length(n)>0), (n)->n_child[Length(n)-1])
end_define

begin_define
define|#
directive|define
name|firstchild
parameter_list|(
name|n
parameter_list|)
define|\
value|(Assert(Type(n)==Nod&& Length(n)>0), (n)->n_child[0])
end_define

begin_else
else|#
directive|else
else|NDEBUG
end_else

begin_define
define|#
directive|define
name|symbol
parameter_list|(
name|n
parameter_list|)
value|((n)->n_symbol)
end_define

begin_define
define|#
directive|define
name|nchildren
parameter_list|(
name|n
parameter_list|)
value|(Length(n))
end_define

begin_define
define|#
directive|define
name|marks
parameter_list|(
name|n
parameter_list|)
value|((n)->n_marks)
end_define

begin_define
define|#
directive|define
name|child
parameter_list|(
name|n
parameter_list|,
name|i
parameter_list|)
value|((n)->n_child[(i)-1])
end_define

begin_define
define|#
directive|define
name|lastchild
parameter_list|(
name|n
parameter_list|)
value|((n)->n_child[Length(n)-1])
end_define

begin_define
define|#
directive|define
name|firstchild
parameter_list|(
name|n
parameter_list|)
value|((n)->n_child[0])
end_define

begin_endif
endif|#
directive|endif
endif|NDEBUG
end_endif

begin_define
define|#
directive|define
name|width
parameter_list|(
name|n
parameter_list|)
value|(Type(n)==Tex ? Length((value)(n)) : (n)->n_width)
end_define

begin_define
define|#
directive|define
name|marked
parameter_list|(
name|p
parameter_list|,
name|x
parameter_list|)
value|(marks(tree(p))&(x))
end_define

begin_define
define|#
directive|define
name|Pnil
value|((path) NULL)
end_define

begin_function_decl
name|path
name|newpath
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|parent
parameter_list|(
name|p
parameter_list|)
value|((p)->p_parent)
end_define

begin_define
define|#
directive|define
name|tree
parameter_list|(
name|p
parameter_list|)
value|((p)->p_tree)
end_define

begin_define
define|#
directive|define
name|ichild
parameter_list|(
name|p
parameter_list|)
value|((p)->p_ichild)
end_define

begin_define
define|#
directive|define
name|Ycoord
parameter_list|(
name|p
parameter_list|)
value|((p)->p_ycoord)
end_define

begin_define
define|#
directive|define
name|Xcoord
parameter_list|(
name|p
parameter_list|)
value|((p)->p_xcoord)
end_define

begin_define
define|#
directive|define
name|Level
parameter_list|(
name|p
parameter_list|)
value|((p)->p_level)
end_define

begin_comment
comment|/* Procedure markpath(); */
end_comment

begin_comment
comment|/* Procedure unmkpath(); */
end_comment

begin_comment
comment|/* Procedure replace(); */
end_comment

begin_function_decl
name|bool
name|up
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|downi
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|down
parameter_list|(
name|n
parameter_list|)
value|downi(n, 1)
end_define

begin_function_decl
name|bool
name|downrite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|left
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|rite
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure top(); */
end_comment

begin_function_decl
name|bool
name|nextnode
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure firstleaf(); */
end_comment

begin_function_decl
name|bool
name|nextleaf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|prevnode
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure lastleaf(); */
end_comment

begin_function_decl
name|bool
name|prevleaf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|nextmarked
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|prevmarked
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * The following are routines for lint, but macros for CC.  * This way lint can detect wrong arguments passed.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_function_decl
name|node
name|nodecopy
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|noderelease
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|nodeuniql
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|path
name|pathcopy
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|pathrelease
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pathuniql
argument_list|()
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|nodecopy
parameter_list|(
name|n
parameter_list|)
value|((node)copy(n))
end_define

begin_define
define|#
directive|define
name|noderelease
parameter_list|(
name|n
parameter_list|)
value|release(n)
end_define

begin_define
define|#
directive|define
name|nodeuniql
parameter_list|(
name|pn
parameter_list|)
value|uniql(pn)
end_define

begin_define
define|#
directive|define
name|pathcopy
parameter_list|(
name|p
parameter_list|)
value|((path)copy(p))
end_define

begin_define
define|#
directive|define
name|pathrelease
parameter_list|(
name|p
parameter_list|)
value|release(p)
end_define

begin_define
define|#
directive|define
name|pathuniql
parameter_list|(
name|pp
parameter_list|)
value|uniql(pp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|node
name|grab_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|path
name|grab_path
parameter_list|()
function_decl|;
end_function_decl

end_unit

