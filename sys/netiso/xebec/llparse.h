begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/xebec/Attic/llparse.h,v $ */
end_comment

begin_comment
comment|/************************************************************ 		attributes stack garbage 	************************************************************/
end_comment

begin_define
define|#
directive|define
name|LLMAXATTR
value|512
end_define

begin_define
define|#
directive|define
name|LLMAXDESC
value|256
end_define

begin_define
define|#
directive|define
name|LLATTR
end_define

begin_comment
comment|/* build an attribute stack */
end_comment

begin_comment
comment|/* 	**	attribute stack 	** 	**	AttrStack =	stack of record 	**				values : array of values; 	**				ptr	: index; 	**	end; 	** 	*/
end_comment

begin_typedef
typedef|typedef
name|union
name|llattrib
name|LLattrib
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|LLattrib
name|llattributes
index|[
name|LLMAXATTR
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|llattrtop
decl_stmt|;
end_decl_stmt

begin_struct
specifier|extern
struct|struct
name|llattr
block|{
name|LLattrib
modifier|*
name|llabase
decl_stmt|;
comment|/* ptr into the attr stack (llattributes) */
name|int
name|llaindex
decl_stmt|;
comment|/* # attrs on the stack so far for this prod */
name|int
name|llacnt
decl_stmt|;
comment|/* total # ever to go on for this prod */
name|int
name|lloldtop
decl_stmt|;
comment|/* when popping this prod, restore stack to here ; 						 one attr will remain on the stack (for the lhs) */
block|}
name|llattrdesc
index|[
name|LLMAXDESC
index|]
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|lldescindex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/************************************************************ 		attributes stack garbage 	************************************************************/
end_comment

begin_struct
specifier|extern
struct|struct
name|lltoken
block|{
name|short
name|llterm
decl_stmt|;
comment|/* token number */
name|short
name|llstate
decl_stmt|;
comment|/* inserted deleted normal */
name|LLattrib
name|llattrib
decl_stmt|;
block|}
name|lltoken
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|lltoken
name|LLtoken
typedef|;
end_typedef

begin_comment
comment|/************************************************************ 	constants used in llparse.c ************************************************************/
end_comment

begin_define
define|#
directive|define
name|STACKSIZE
value|500
end_define

begin_define
define|#
directive|define
name|MAXCORR
value|16
end_define

begin_define
define|#
directive|define
name|NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|DELETE
value|1
end_define

begin_define
define|#
directive|define
name|INSERT
value|2
end_define

begin_comment
comment|/************************************************************ 	datatypes used to communicate with the parser ************************************************************/
end_comment

begin_struct
struct|struct
name|llinsert
block|{
name|short
name|llinscost
decl_stmt|;
name|short
name|llinslength
decl_stmt|;
name|short
name|llinsert
index|[
name|MAXCORR
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|llinsert
name|LLinsert
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|short
name|llparsestack
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|llstackptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|llinfinite
decl_stmt|;
end_decl_stmt

begin_comment
comment|/************************************************************ 	variables used to pass information 	specific to each grammer ************************************************************/
end_comment

begin_decl_stmt
specifier|extern
name|short
name|llnterms
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|llnsyms
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|llnprods
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|llefile
decl_stmt|;
end_decl_stmt

begin_struct
specifier|extern
struct|struct
name|llparsetable
block|{
name|short
name|llterm
decl_stmt|;
name|short
name|llprod
decl_stmt|;
block|}
name|llparsetable
index|[]
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|short
name|llparseindex
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|llepsilon
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|llproductions
index|[]
decl_stmt|;
end_decl_stmt

begin_struct
specifier|extern
struct|struct
name|llprodindex
block|{
name|short
name|llprodstart
decl_stmt|;
name|short
name|llprodlength
decl_stmt|;
name|short
name|llprodtlen
decl_stmt|;
block|}
name|llprodindex
index|[]
struct|;
end_struct

begin_struct
specifier|extern
struct|struct
name|llcosts
block|{
name|short
name|llinsert
decl_stmt|;
name|short
name|lldelete
decl_stmt|;
block|}
name|llcosts
index|[]
struct|;
end_struct

begin_struct
specifier|extern
struct|struct
name|llstable
block|{
name|short
name|llsstart
decl_stmt|;
name|short
name|llslength
decl_stmt|;
block|}
name|llstable
index|[]
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|short
name|llsspace
index|[]
decl_stmt|;
end_decl_stmt

begin_struct
specifier|extern
struct|struct
name|lletable
block|{
name|short
name|llecost
decl_stmt|;
name|short
name|llelength
decl_stmt|;
name|short
name|llestart
decl_stmt|;
block|}
name|lletable
index|[]
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|long
name|lleindex
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|llespace
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|llstrings
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/************************************************************ 	routines defined in llparse.c ************************************************************/
end_comment

begin_extern
extern|extern llparse(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern llcopye(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern llcopys(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern llcorrector(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern llepsilonok(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern llexpand(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|short
name|llfindaction
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern llgetprefix(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern llgettoken(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern llinsert(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern llinsertsym(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern llinserttokens(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern llparsererror(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern llpushprod(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern llreadetab(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

end_unit

