begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)name.h	1.1 */
end_comment

begin_comment
comment|/* Nodes can have all kinds of values */
end_comment

begin_union
union|union
name|Namval
block|{
name|char
modifier|*
name|cp
decl_stmt|;
name|int
modifier|*
name|ip
decl_stmt|;
name|char
name|c
decl_stmt|;
name|int
name|i
decl_stmt|;
name|unsigned
name|u
decl_stmt|;
name|long
modifier|*
name|lp
decl_stmt|;
name|double
modifier|*
name|dp
decl_stmt|;
comment|/* for floating point arithmetic */
name|struct
name|Namaray
modifier|*
name|aray
decl_stmt|;
comment|/* for array node */
name|union
name|Namval
modifier|*
name|up
decl_stmt|;
comment|/* for indirect node */
name|struct
name|Bfunction
modifier|*
name|fp
decl_stmt|;
comment|/* builtin-function like $RANDOM */
name|struct
name|Ufunction
modifier|*
name|rp
decl_stmt|;
comment|/* shell user defined functions */
block|}
union|;
end_union

begin_comment
comment|/* each Namnod and each array element has one of these */
end_comment

begin_struct
struct|struct
name|Nodval
block|{
name|unsigned
name|namflg
decl_stmt|;
comment|/* attributes */
name|union
name|Namval
name|namval
decl_stmt|;
comment|/* value field */
block|}
struct|;
end_struct

begin_comment
comment|/* This is an array template */
end_comment

begin_struct
struct|struct
name|Namaray
block|{
name|unsigned
name|short
name|adot
decl_stmt|;
comment|/* index of last reference */
name|unsigned
name|short
name|maxi
decl_stmt|;
comment|/* maximum index of array */
name|struct
name|Nodval
modifier|*
name|val
index|[
literal|1
index|]
decl_stmt|;
comment|/* array of value holders */
block|}
struct|;
end_struct

begin_comment
comment|/* This is a template for a storage tree */
end_comment

begin_struct
struct|struct
name|Amemory
block|{
name|struct
name|Amemory
modifier|*
name|nexttree
decl_stmt|;
comment|/* search trees can be chained */
name|short
name|memsize
decl_stmt|;
comment|/* number of listheads */
name|struct
name|Namnod
modifier|*
name|memhead
index|[
literal|1
index|]
decl_stmt|;
comment|/* listhead pointers   */
block|}
struct|;
end_struct

begin_comment
comment|/* This describes a named node */
end_comment

begin_struct
struct|struct
name|Namnod
block|{
name|struct
name|Nodval
name|value
decl_stmt|;
comment|/* determines value of the item */
name|struct
name|Namnod
modifier|*
name|namnxt
decl_stmt|;
comment|/* pointer to next Namnod  */
name|char
modifier|*
name|namid
decl_stmt|;
comment|/* pointer to name of item */
name|short
name|namsz
decl_stmt|;
comment|/* size of item */
block|}
struct|;
end_struct

begin_comment
comment|/* This describes a builtin function node */
end_comment

begin_struct
struct|struct
name|Bfunction
block|{
name|long
function_decl|(
modifier|*
name|f_vp
function_decl|)
parameter_list|()
function_decl|;
comment|/* value function */
name|int
function_decl|(
modifier|*
name|f_ap
function_decl|)
parameter_list|()
function_decl|;
comment|/* assignment function */
block|}
struct|;
end_struct

begin_comment
comment|/* This describes a user defined function node */
end_comment

begin_struct
struct|struct
name|Ufunction
block|{
name|long
name|hoffset
decl_stmt|;
comment|/* offset into history file */
name|int
modifier|*
modifier|*
name|ptree
decl_stmt|;
comment|/* address of parse tree */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MEMSIZE
value|32*sizeof(int)
end_define

begin_comment
comment|/* default memory size for shell. 						Must be a power of 2 */
end_comment

begin_define
define|#
directive|define
name|PSEPS
value|":"
end_define

begin_define
define|#
directive|define
name|ARRMAX
value|512
end_define

begin_comment
comment|/* maximum number of elements in an array */
end_comment

begin_define
define|#
directive|define
name|ARRINCR
value|16
end_define

begin_comment
comment|/* number of elements to grow when array bound exceeded  				 Must be a power of 2 */
end_comment

begin_define
define|#
directive|define
name|MAXTREES
value|20
end_define

begin_comment
comment|/* maximum number of mounted search trees */
end_comment

begin_define
define|#
directive|define
name|NO_SUBSCRIPT
value|ARRMAX
end_define

begin_comment
comment|/* subscript not defined */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* types of namenode items */
end_comment

begin_define
define|#
directive|define
name|N_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|INT_GER
value|I_FLAG
end_define

begin_comment
comment|/* integer type */
end_comment

begin_define
define|#
directive|define
name|CPOIN_TER
value|W_FLAG
end_define

begin_define
define|#
directive|define
name|N_AVAIL
value|B_FLAG
end_define

begin_comment
comment|/* node is logically non-existent, blocked */
end_comment

begin_define
define|#
directive|define
name|C_WRITE
value|C_FLAG
end_define

begin_comment
comment|/* make copy of node on assignment */
end_comment

begin_define
define|#
directive|define
name|ARRAY
value|F_FLAG
end_define

begin_comment
comment|/* node is an array */
end_comment

begin_define
define|#
directive|define
name|IN_DIR
value|P_FLAG
end_define

begin_comment
comment|/* value is a pointer to a value node */
end_comment

begin_define
define|#
directive|define
name|N_ALLOC
value|V_FLAG
end_define

begin_comment
comment|/* don't allocate space for the value */
end_comment

begin_define
define|#
directive|define
name|N_FREE
value|S_FLAG
end_define

begin_comment
comment|/* don't free the space when releasing value */
end_comment

begin_define
define|#
directive|define
name|T_FORM
value|T_FLAG
end_define

begin_comment
comment|/* program usable tflag */
end_comment

begin_define
define|#
directive|define
name|L_TO_U
value|U_FLAG
end_define

begin_comment
comment|/* convert to uppercase */
end_comment

begin_define
define|#
directive|define
name|U_TO_L
value|L_FLAG
end_define

begin_comment
comment|/* convert to lowercase */
end_comment

begin_define
define|#
directive|define
name|Z_FILL
value|Z_FLAG
end_define

begin_comment
comment|/* right justify and fill with leading zeros */
end_comment

begin_define
define|#
directive|define
name|R_JUST
value|W_FLAG
end_define

begin_comment
comment|/* right justify and blank fill */
end_comment

begin_define
define|#
directive|define
name|L_JUST
value|O_FLAG
end_define

begin_comment
comment|/* left justify and blank fill */
end_comment

begin_define
define|#
directive|define
name|HOST_N
value|M_FLAG
end_define

begin_comment
comment|/* convert to host file name in non-unix */
end_comment

begin_define
define|#
directive|define
name|N_EXPORT
value|X_FLAG
end_define

begin_comment
comment|/* export bit */
end_comment

begin_define
define|#
directive|define
name|N_RDONLY
value|R_FLAG
end_define

begin_comment
comment|/* readonly bit */
end_comment

begin_define
define|#
directive|define
name|N_IMPORT
value|N_FLAG
end_define

begin_comment
comment|/* imported from environment */
end_comment

begin_comment
comment|/* The following are used with INT_FLG */
end_comment

begin_define
define|#
directive|define
name|BLT_NOD
value|M_FLAG
end_define

begin_comment
comment|/* builtin function flag */
end_comment

begin_define
define|#
directive|define
name|OC_TAL
value|O_FLAG
end_define

begin_define
define|#
directive|define
name|UN_SIGN
value|U_FLAG
end_define

begin_define
define|#
directive|define
name|is_afunction
parameter_list|(
name|n
parameter_list|)
value|(((n)->value.namflg&(~(N_EXPORT|T_FLAG)))==(INT_GER|L_FLAG))
end_define

begin_define
define|#
directive|define
name|funtree
parameter_list|(
name|n
parameter_list|)
value|((n)->value.namval.rp->ptree)
end_define

begin_define
define|#
directive|define
name|NO_ALIAS
value|(L_TO_U|U_TO_L|N_FLAG)
end_define

begin_comment
comment|/* namenode states */
end_comment

begin_define
define|#
directive|define
name|NO_ERR_
value|0
end_define

begin_define
define|#
directive|define
name|SANERR
value|E_FLAG
end_define

begin_define
define|#
directive|define
name|ADD_NOD
value|1
end_define

begin_comment
comment|/* add node if not found */
end_comment

begin_define
define|#
directive|define
name|CHK_FOR
value|2
end_define

begin_comment
comment|/* look for only if valid name */
end_comment

begin_define
define|#
directive|define
name|RE_USE
value|4
end_define

begin_comment
comment|/* used for efficiency in multitree searches */
end_comment

begin_comment
comment|/* NAMNOD MACROS */
end_comment

begin_comment
comment|/* ...  for arrays */
end_comment

begin_define
define|#
directive|define
name|arayp
parameter_list|(
name|v
parameter_list|)
value|(v->value.namval.aray)
end_define

begin_define
define|#
directive|define
name|curdot
parameter_list|(
name|n
parameter_list|)
value|((arayp(n))->adot)
end_define

begin_define
define|#
directive|define
name|abound
parameter_list|(
name|n
parameter_list|)
value|((int)((n)->value.namval.aray->maxi))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KSHELL
end_ifdef

begin_define
define|#
directive|define
name|setdot
parameter_list|(
name|n
parameter_list|,
name|i
parameter_list|)
value|((n)->value.namval.aray->adot = i)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KSHELL */
end_comment

begin_comment
comment|/* ... for attributes */
end_comment

begin_define
define|#
directive|define
name|namflag
parameter_list|(
name|n
parameter_list|)
value|(n)->value.namflg
end_define

begin_define
define|#
directive|define
name|attest
parameter_list|(
name|n
parameter_list|,
name|f
parameter_list|)
value|(namflag(n)& (f))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KSHELL
end_ifdef

begin_define
define|#
directive|define
name|attrib
parameter_list|(
name|n
parameter_list|,
name|f
parameter_list|)
value|((n)->value.namflg |= f)
end_define

begin_define
define|#
directive|define
name|sattrib
parameter_list|(
name|n
parameter_list|,
name|f
parameter_list|)
value|((n)->value.namflg = f)
end_define

begin_define
define|#
directive|define
name|pattrib
parameter_list|(
name|n
parameter_list|,
name|f
parameter_list|)
value|((n)->value.namflg&= f)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|attrib
parameter_list|(
name|n
parameter_list|,
name|f
parameter_list|)
value|(chattrib (n, namflag(n)|(f)))
end_define

begin_define
define|#
directive|define
name|sattrib
parameter_list|(
name|n
parameter_list|,
name|f
parameter_list|)
value|(chattrib (n, f))
end_define

begin_define
define|#
directive|define
name|pattrib
parameter_list|(
name|n
parameter_list|,
name|f
parameter_list|)
value|(chattrib (n, namflag(n)&(f)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KSHELL */
end_comment

begin_comment
comment|/* ... etc */
end_comment

begin_define
define|#
directive|define
name|isnull
parameter_list|(
name|n
parameter_list|)
value|((n)->value.namval.cp == NULL)
end_define

begin_comment
comment|/* strings only */
end_comment

begin_define
define|#
directive|define
name|freeble
parameter_list|(
name|nv
parameter_list|)
value|(((int)(nv))& 01)
end_define

begin_define
define|#
directive|define
name|mrkfree
parameter_list|(
name|nv
parameter_list|)
value|((struct Nodval*)(((int)(nv)) | 01))
end_define

begin_define
define|#
directive|define
name|unmark
parameter_list|(
name|nv
parameter_list|)
value|((struct Nodval*)(((int)(nv))& ~01))
end_define

begin_define
define|#
directive|define
name|errorp
parameter_list|(
name|np
parameter_list|)
value|((np)->namerr)
end_define

begin_define
define|#
directive|define
name|asscadr
parameter_list|(
name|np
parameter_list|,
name|val
parameter_list|)
value|assiadr(np,((int*)(val)))
end_define

begin_decl_stmt
specifier|extern
name|char
name|synmsg
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|subscript
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|badnum
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|badparam
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|divzero
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|hdigits
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|wtfailed
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|notid
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Amemory
modifier|*
name|namep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lastbase
decl_stmt|;
end_decl_stmt

end_unit

