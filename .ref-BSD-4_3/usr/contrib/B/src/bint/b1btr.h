begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b1btr.h,v 1.4 85/08/22 16:41:40 timo Exp $ */
end_comment

begin_comment
comment|/* Private definitions for the b-tree module */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INTEGRATION
end_ifndef

begin_decl_stmt
specifier|extern
name|bool
name|comp_ok
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|reqerr
parameter_list|(
name|s
parameter_list|)
value|error(s)
end_define

begin_comment
comment|/*********************************************************************/
end_comment

begin_comment
comment|/* items /*********************************************************************/
end_comment

begin_typedef
typedef|typedef
name|char
name|texitem
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|value
name|lisitem
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pair
block|{
name|value
name|k
decl_stmt|,
name|a
decl_stmt|;
block|}
name|tabitem
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|onpair
block|{
name|value
name|ka
decl_stmt|,
name|u
decl_stmt|;
block|}
name|keysitem
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|itm
block|{
name|texitem
name|c
decl_stmt|;
name|lisitem
name|l
decl_stmt|;
name|tabitem
name|t
decl_stmt|;
block|}
name|item
operator|,
typedef|*
name|itemarray
operator|,
typedef|*
name|itemptr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Charval
parameter_list|(
name|pitm
parameter_list|)
value|((pitm)->c)
end_define

begin_define
define|#
directive|define
name|Keyval
parameter_list|(
name|pitm
parameter_list|)
value|((pitm)->l)
end_define

begin_define
define|#
directive|define
name|Ascval
parameter_list|(
name|pitm
parameter_list|)
value|((pitm)->t.a)
end_define

begin_comment
comment|/* Xt = itemtype, do not change these, their order is used */
end_comment

begin_define
define|#
directive|define
name|Ct
value|(0)
end_define

begin_define
define|#
directive|define
name|Lt
value|(1)
end_define

begin_define
define|#
directive|define
name|Tt
value|(2)
end_define

begin_define
define|#
directive|define
name|Kt
value|(3)
end_define

begin_comment
comment|/* Itemwidth, used for offset in btreenodes */
end_comment

begin_typedef
typedef|typedef
name|char
name|width
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Itemwidth
parameter_list|(
name|it
parameter_list|)
value|(itemwidth[it])
end_define

begin_decl_stmt
specifier|extern
name|char
name|itemwidth
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  uses: */
end_comment

begin_define
define|#
directive|define
name|Cw
value|(sizeof(texitem))
end_define

begin_define
define|#
directive|define
name|Lw
value|(sizeof(lisitem))
end_define

begin_define
define|#
directive|define
name|Tw
value|(sizeof(tabitem))
end_define

begin_define
define|#
directive|define
name|Kw
value|(sizeof(keysitem))
end_define

begin_comment
comment|/*********************************************************************/
end_comment

begin_comment
comment|/* sizes of btrees /*********************************************************************/
end_comment

begin_define
define|#
directive|define
name|Bigsize
value|(-1)
end_define

begin_define
define|#
directive|define
name|Stail
parameter_list|(
name|r
parameter_list|,
name|s
parameter_list|)
value|((r)> Maxint - (s) ? Bigsize : (r)+(s))
end_define

begin_define
define|#
directive|define
name|Ssum
parameter_list|(
name|r
parameter_list|,
name|s
parameter_list|)
value|((r) EQ Bigsize || (s) EQ Bigsize ? Bigsize : Stail(r,s))
end_define

begin_define
define|#
directive|define
name|Sincr
parameter_list|(
name|r
parameter_list|)
value|((r) EQ Bigsize ? Bigsize : Stail(r,1))
end_define

begin_define
define|#
directive|define
name|Sadd2
parameter_list|(
name|r
parameter_list|)
value|((r) EQ Bigsize ? Bigsize : Stail(r,2))
end_define

begin_define
define|#
directive|define
name|Sdiff
parameter_list|(
name|r
parameter_list|,
name|s
parameter_list|)
value|((r) EQ Bigsize || (s) EQ Bigsize ? Bigsize : (r)-(s))
end_define

begin_define
define|#
directive|define
name|Sdecr
parameter_list|(
name|r
parameter_list|)
value|((r) EQ Bigsize ? Bigsize : (r)-(1))
end_define

begin_function_decl
name|value
name|treesize
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr pnode */
end_comment

begin_comment
comment|/*********************************************************************/
end_comment

begin_comment
comment|/* (A,B)-btrees /*********************************************************************/
end_comment

begin_comment
comment|/* innernodes: using A=6 B=12 */
end_comment

begin_define
define|#
directive|define
name|Mininner
value|5
end_define

begin_comment
comment|/* A - 1 */
end_comment

begin_define
define|#
directive|define
name|Maxinner
value|11
end_define

begin_comment
comment|/* B - 1 */
end_comment

begin_comment
comment|/* bottomnodes */
end_comment

begin_define
define|#
directive|define
name|Minbottom
value|11
end_define

begin_define
define|#
directive|define
name|Maxbottom
value|22
end_define

begin_comment
comment|/* rangenodes */
end_comment

begin_define
define|#
directive|define
name|Biglim
value|(Maxbottom+1)
end_define

begin_typedef
typedef|typedef
struct|struct
name|btrnode
block|{
name|HEADER
expr_stmt|;
name|int
name|size
decl_stmt|;
name|char
modifier|*
modifier|*
name|g
decl_stmt|;
block|}
name|btreenode
operator|,
typedef|*
name|btreeptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|innernode
block|{
name|HEADER
expr_stmt|;
name|int
name|size
decl_stmt|;
name|btreeptr
name|ptr
index|[
name|Maxinner
operator|+
literal|1
index|]
decl_stmt|;
name|itemarray
name|iitm
decl_stmt|;
block|}
name|innernode
operator|,
typedef|*
name|innerptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|itexnode
block|{
name|HEADER
expr_stmt|;
name|int
name|size
decl_stmt|;
name|btreeptr
name|ptr
index|[
name|Maxinner
operator|+
literal|1
index|]
decl_stmt|;
name|texitem
name|icitm
index|[
name|Maxinner
index|]
decl_stmt|;
block|}
name|itexnode
operator|,
typedef|*
name|itexptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ilisnode
block|{
name|HEADER
expr_stmt|;
name|int
name|size
decl_stmt|;
name|btreeptr
name|ptr
index|[
name|Maxinner
operator|+
literal|1
index|]
decl_stmt|;
name|lisitem
name|ilitm
index|[
name|Maxinner
index|]
decl_stmt|;
block|}
name|ilisnode
operator|,
typedef|*
name|ilisptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|itabnode
block|{
name|HEADER
expr_stmt|;
name|int
name|size
decl_stmt|;
name|btreeptr
name|ptr
index|[
name|Maxinner
operator|+
literal|1
index|]
decl_stmt|;
name|tabitem
name|ititm
index|[
name|Maxinner
index|]
decl_stmt|;
block|}
name|itabnode
operator|,
typedef|*
name|itabptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bottomnode
block|{
name|HEADER
expr_stmt|;
name|int
name|size
decl_stmt|;
name|itemarray
name|bitm
decl_stmt|;
block|}
name|bottomnode
operator|,
typedef|*
name|bottomptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|btexnode
block|{
name|HEADER
expr_stmt|;
name|int
name|size
decl_stmt|;
name|texitem
name|bcitm
index|[
name|Maxbottom
index|]
decl_stmt|;
block|}
name|btexnode
operator|,
typedef|*
name|btexptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|blisnode
block|{
name|HEADER
expr_stmt|;
name|int
name|size
decl_stmt|;
name|lisitem
name|blitm
index|[
name|Maxbottom
index|]
decl_stmt|;
block|}
name|blisnode
operator|,
typedef|*
name|blisptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|btabnode
block|{
name|HEADER
expr_stmt|;
name|int
name|size
decl_stmt|;
name|tabitem
name|btitm
index|[
name|Maxbottom
index|]
decl_stmt|;
block|}
name|btabnode
operator|,
typedef|*
name|btabptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rangenode
block|{
name|HEADER
expr_stmt|;
name|int
name|size
decl_stmt|;
name|lisitem
name|lwb
decl_stmt|,
name|upb
decl_stmt|;
block|}
name|rangenode
operator|,
typedef|*
name|rangeptr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Bnil
value|((btreeptr) 0)
end_define

begin_define
define|#
directive|define
name|Flag
parameter_list|(
name|pnode
parameter_list|)
value|((pnode)->type)
end_define

begin_define
define|#
directive|define
name|Inner
value|'i'
end_define

begin_define
define|#
directive|define
name|Bottom
value|'b'
end_define

begin_define
define|#
directive|define
name|Irange
value|'.'
end_define

begin_define
define|#
directive|define
name|Crange
value|'\''
end_define

begin_define
define|#
directive|define
name|Lim
parameter_list|(
name|pnode
parameter_list|)
value|((pnode)->len)
end_define

begin_define
define|#
directive|define
name|Minlim
parameter_list|(
name|pnode
parameter_list|)
value|(Flag(pnode) EQ Inner ? Mininner : Minbottom)
end_define

begin_define
define|#
directive|define
name|Maxlim
parameter_list|(
name|pnode
parameter_list|)
value|(Flag(pnode) EQ Inner ? Maxinner : Maxbottom)
end_define

begin_define
define|#
directive|define
name|SetRangeLim
parameter_list|(
name|pnode
parameter_list|)
value|(Size(pnode) EQ Bigsize || Size(pnode)> Maxbottom\ 			    ? Biglim : Size(pnode))
end_define

begin_define
define|#
directive|define
name|Size
parameter_list|(
name|pnode
parameter_list|)
value|((pnode)->size)
end_define

begin_define
define|#
directive|define
name|Ptr
parameter_list|(
name|pnode
parameter_list|,
name|l
parameter_list|)
value|(((innerptr) (pnode))->ptr[l])
end_define

begin_comment
comment|/* pointer to item in innernode: */
end_comment

begin_define
define|#
directive|define
name|Piitm
parameter_list|(
name|pnode
parameter_list|,
name|l
parameter_list|,
name|w
parameter_list|)
value|((itemptr) (((char*)&(((innerptr) (pnode))->iitm)) + ((l)*(w))))
end_define

begin_comment
comment|/* pointer to item in bottomnode: */
end_comment

begin_define
define|#
directive|define
name|Pbitm
parameter_list|(
name|pnode
parameter_list|,
name|l
parameter_list|,
name|w
parameter_list|)
value|((itemptr) (((char*)&(((bottomptr) (pnode))->bitm)) + ((l)*(w))))
end_define

begin_define
define|#
directive|define
name|Ichar
parameter_list|(
name|pnode
parameter_list|,
name|l
parameter_list|)
value|(((itexptr) (pnode))->icitm[l])
end_define

begin_define
define|#
directive|define
name|Bchar
parameter_list|(
name|pnode
parameter_list|,
name|l
parameter_list|)
value|(((btexptr) (pnode))->bcitm[l])
end_define

begin_define
define|#
directive|define
name|Lwbval
parameter_list|(
name|pnode
parameter_list|)
value|(((rangeptr) (pnode))->lwb)
end_define

begin_define
define|#
directive|define
name|Upbval
parameter_list|(
name|pnode
parameter_list|)
value|(((rangeptr) (pnode))->upb)
end_define

begin_define
define|#
directive|define
name|Lwbchar
parameter_list|(
name|pnode
parameter_list|)
value|(Bchar(Root(Lwbval(pnode)), 0))
end_define

begin_define
define|#
directive|define
name|Upbchar
parameter_list|(
name|pnode
parameter_list|)
value|(Bchar(Root(Upbval(pnode)), 0))
end_define

begin_define
define|#
directive|define
name|Maxheight
value|20
end_define

begin_comment
comment|/* should be some function of B */
end_comment

begin_comment
comment|/* Procedure merge(); */
end_comment

begin_comment
comment|/* btreeptr pleft; itemptr pitm; btreeptr pright; literal it; */
end_comment

begin_function_decl
name|bool
name|rebalance
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr *pptr1; itemptr pitm; btreeptr pptr2;        intlet minlim, maxlim; literal it; */
end_comment

begin_comment
comment|/* Procedure restore_child(); */
end_comment

begin_comment
comment|/* btreeptr pparent; intlet ichild, minl, maxl; literal it; */
end_comment

begin_function_decl
name|bool
name|inodeinsert
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr pnode, *pptr; itemptr pitm; intlet at; literal it; */
end_comment

begin_function_decl
name|bool
name|bnodeinsert
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr pnode, *pptr; itemptr pitm; intlet at; literal it; */
end_comment

begin_function_decl
name|bool
name|i_search
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr pnode; value key; intlet *pl; width iw; */
end_comment

begin_function_decl
name|bool
name|b_search
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr pnode; value key; intlet *pl; width iw; */
end_comment

begin_comment
comment|/*********************************************************************/
end_comment

begin_comment
comment|/* texts only (mbte.c) /*********************************************************************/
end_comment

begin_function_decl
name|btreeptr
name|trimbtextnode
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr pnode, intlet from,to */
end_comment

begin_function_decl
name|btreeptr
name|trimitextnode
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr pnode, intlet from,to */
end_comment

begin_function_decl
name|bool
name|join_itm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr pnode, *pptr; itemptr pitm; bool after */
end_comment

begin_comment
comment|/*********************************************************************/
end_comment

begin_comment
comment|/* lists only (mbli.c) /*********************************************************************/
end_comment

begin_function_decl
name|btreeptr
name|spawncrangenode
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* value lwb, upb */
end_comment

begin_comment
comment|/* Procedure set_size_and_lim(); */
end_comment

begin_comment
comment|/* btreeptr pnode */
end_comment

begin_comment
comment|/* PRrocedure ir_to_bottomnode(); */
end_comment

begin_comment
comment|/* btreeptr *pptr; */
end_comment

begin_function_decl
name|bool
name|ins_itm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr *pptr1; itemptr pitm; btreeptr *pptr2; literal it; */
end_comment

begin_comment
comment|/* Procedure rem_greatest(); */
end_comment

begin_comment
comment|/* btreeptr *pptr; itemptr prepl_itm; literal it; */
end_comment

begin_function_decl
name|bool
name|rem_itm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr *pptr1; itemptr pitm;        itemptr p_insitm; btreeptr *pptr2; bool *psplit;        literal it; */
end_comment

begin_comment
comment|/*********************************************************************/
end_comment

begin_comment
comment|/* tables only (mbla.c) /*********************************************************************/
end_comment

begin_function_decl
name|bool
name|rpl_itm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr *pptr1, *pptr2; itemptr pitm; bool *p_added */
end_comment

begin_function_decl
name|bool
name|del_itm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr *pptr1; itemptr pitm */
end_comment

begin_function_decl
name|value
name|assocval
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr pnode; value key; */
end_comment

begin_function_decl
name|bool
name|assocloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* value **ploc; btreeptr pnode; value key; */
end_comment

begin_function_decl
name|bool
name|u_assoc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr pnode; value key; */
end_comment

begin_comment
comment|/***************** Texts, lists and tables ********************/
end_comment

begin_comment
comment|/* Procedure move_itm(); */
end_comment

begin_comment
comment|/* itemptr pdes, psrc; literal it; */
end_comment

begin_function_decl
name|bool
name|get_th_item
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* itemptr pitm; value num, v; */
end_comment

begin_endif
endif|#
directive|endif
endif|!INTEGRATION
end_endif

end_unit

