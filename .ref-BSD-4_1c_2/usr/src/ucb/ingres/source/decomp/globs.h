begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tree.h>
end_include

begin_include
include|#
directive|include
file|<func.h>
end_include

begin_include
include|#
directive|include
file|<access.h>
end_include

begin_include
include|#
directive|include
file|"../decomp/decomp.h"
end_include

begin_include
include|#
directive|include
file|"../ovqp/ovqp.h"
end_include

begin_comment
comment|/*	@(#)globs.h	7.3	3/7/81	*/
end_comment

begin_struct
struct|struct
name|agglist
block|{
name|QTREE
modifier|*
modifier|*
name|father
decl_stmt|;
comment|/* addr of pointer to you */
name|QTREE
modifier|*
name|agpoint
decl_stmt|;
comment|/* pointer to aghead */
name|QTREE
modifier|*
name|agfather
decl_stmt|;
comment|/* is your father an aggregate? */
name|short
name|agvarno
decl_stmt|;
comment|/* var # assigned to aggr fnct */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hitlist
block|{
name|QTREE
modifier|*
modifier|*
name|trepr
decl_stmt|;
comment|/* position in tree to be changed */
name|short
name|byno
decl_stmt|;
comment|/* by-list position */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rang_tab
block|{
name|int
name|relnum
decl_stmt|;
comment|/* internal decomp relation number */
name|int
name|rtspec
decl_stmt|;
comment|/* relspec of relation */
name|int
name|rtstat
decl_stmt|;
comment|/* relstat of relation */
name|int
name|rtwid
decl_stmt|;
comment|/* relwidth of relation */
name|long
name|rtcnt
decl_stmt|;
comment|/* tupcount of relation */
name|int
name|rtaltnum
decl_stmt|;
comment|/* reserved for distributed decomp */
name|char
modifier|*
name|rtattmap
decl_stmt|;
comment|/* reserved for distributed decomp */
name|long
name|rtdcnt
decl_stmt|;
comment|/* reserved for distributed decomp */
name|struct
name|d_range
modifier|*
name|rtsrange
decl_stmt|;
comment|/* reserved for distributed decomp */
block|}
struct|;
end_struct

begin_comment
comment|/* The following structure reserved for distributed decomp */
end_comment

begin_comment
comment|/* The order of this has been changed for proper alignment */
end_comment

begin_struct
struct|struct
name|d_range
block|{
name|int
name|relnum
decl_stmt|;
name|int
name|draltnum
decl_stmt|;
name|long
name|drtupcnt
decl_stmt|;
name|struct
name|d_range
modifier|*
name|drnext
decl_stmt|;
name|int
name|drstat
decl_stmt|;
name|char
name|drsite
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* structure used by reduction to maintain component pieces */
end_comment

begin_struct
struct|struct
name|complist
block|{
name|struct
name|complist
modifier|*
name|nextcomp
decl_stmt|;
comment|/* next comp piece */
name|struct
name|complist
modifier|*
name|linkcomp
decl_stmt|;
comment|/* next clause of this comp */
name|QTREE
modifier|*
name|clause
decl_stmt|;
comment|/* associated clause */
name|int
name|bitmap
decl_stmt|;
comment|/* map of all assoc clauses */
block|}
struct|;
end_struct

begin_decl_stmt
name|bool
name|Batchupd
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|desc_tab
block|{
name|int
name|relnum
decl_stmt|;
comment|/* relation number */
name|char
name|dtmode
decl_stmt|;
comment|/* status of descriptor */
name|char
name|dtpos
decl_stmt|;
comment|/* position of last access */
name|DESC
name|desc
decl_stmt|;
comment|/* descriptor */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|stacksym
block|{
name|char
name|s_type
decl_stmt|;
name|char
name|s_len
decl_stmt|;
name|long
name|s_value
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* stack for OVQP interpreter */
end_comment

begin_struct
struct|struct
name|simp
block|{
name|int
name|relop
decl_stmt|;
comment|/* value of relop in simp clause*/
name|int
name|att
decl_stmt|;
comment|/* attno of attribute */
name|SYMBOL
operator|*
specifier|const
expr_stmt|;
comment|/* pointer to constant value symbol */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|key
block|{
name|SYMBOL
modifier|*
name|keysym
decl_stmt|;
name|int
name|dnumber
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|Equel
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
block|{
comment|/* OVQP variables */
name|char
name|ov_outtup
index|[
name|MAXTUP
index|]
decl_stmt|;
name|char
name|ov_intup
index|[
name|MAXTUP
index|]
decl_stmt|;
name|char
modifier|*
name|ov_origtup
decl_stmt|;
name|char
modifier|*
name|ov_tend
decl_stmt|;
comment|/* pts to end of data in ov_outtup */
name|short
name|ov_bopen
decl_stmt|;
comment|/* TRUE if batch file is open */
name|short
name|ov_targvc
decl_stmt|;
comment|/* var count in Target list (flags constant Targ. list) */
name|short
name|ov_qualvc
decl_stmt|;
comment|/* var count in Qual list */
name|short
name|ov_userqry
decl_stmt|;
comment|/* flags a query on the users's result rel */
name|short
name|ov_retrieve
decl_stmt|;
comment|/* true is a retrieve, else false */
name|char
modifier|*
name|ov_ovqpbuf
decl_stmt|;
name|short
name|ov_diffrel
decl_stmt|;
comment|/* true is ov_source and ov_result are different */
name|short
name|ov_agcount
decl_stmt|;
comment|/* count of the # of aggregates in the query */
name|short
name|ov_qvpointer
decl_stmt|;
name|long
name|ov_intid
decl_stmt|;
name|long
name|ov_uptid
decl_stmt|;
name|long
modifier|*
name|ov_counter
decl_stmt|;
comment|/* cnts "gets" done in OVQP */
name|long
name|ov_lotid
decl_stmt|;
name|long
name|ov_hitid
decl_stmt|;
comment|/* lo& hi limits of scan in OVQP */
name|long
name|ov_tupsfound
decl_stmt|;
comment|/* counts # tuples which satified the query */
name|DESC
modifier|*
name|ov_scanr
decl_stmt|;
comment|/* pts to desc of reln to be scanned */
name|DESC
modifier|*
name|ov_source
decl_stmt|;
comment|/* 0 if no source for qry, else poshorts to ov_srcdesc */
name|DESC
modifier|*
name|ov_result
decl_stmt|;
comment|/* 0 if no result for qry, else poshorts to ov_reldesc */
name|SYMBOL
modifier|*
modifier|*
name|ov_tlist
decl_stmt|;
name|SYMBOL
modifier|*
modifier|*
name|ov_alist
decl_stmt|;
name|SYMBOL
modifier|*
modifier|*
name|ov_qlist
decl_stmt|;
name|SYMBOL
modifier|*
modifier|*
name|ov_bylist
decl_stmt|;
name|struct
name|stacksym
name|ov_stack
index|[
name|STACKSIZ
index|]
decl_stmt|;
name|char
name|ov_keyl
index|[
name|MAXTUP
index|]
decl_stmt|;
name|char
name|ov_keyh
index|[
name|MAXTUP
index|]
decl_stmt|;
name|int
name|ov_nsimp
decl_stmt|;
comment|/* Current no. entries in ov_simp vector */
name|int
name|ov_fmode
decl_stmt|;
comment|/* find-mode determined by strategy */
name|struct
name|simp
name|ov_simp
index|[
name|NSIMP
index|]
decl_stmt|;
name|struct
name|key
name|ov_lkey_struct
index|[
name|MAXDOM
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|key
name|ov_hkey_struct
index|[
name|MAXDOM
operator|+
literal|1
index|]
decl_stmt|;
comment|/* DECOMP/OVQP variables */
name|struct
name|agglist
modifier|*
name|de_aggnext
decl_stmt|;
comment|/* next in aggregate list */
name|struct
name|agglist
modifier|*
name|de_agglim
decl_stmt|;
comment|/* limit in aggregate list */
name|struct
name|hitlist
modifier|*
name|de_hnext
decl_stmt|;
name|struct
name|hitlist
modifier|*
name|de_hlimit
decl_stmt|;
name|char
name|de_d_dbu70
decl_stmt|;
name|char
name|de_d_ovqp70
decl_stmt|;
name|int
name|de_synconly
decl_stmt|;
name|int
name|de_error_flag
decl_stmt|;
name|int
name|de_qvptr
decl_stmt|;
comment|/* index into available de_qvect space in ovqpnod() */
name|SYMBOL
modifier|*
name|de_qvect
index|[
name|MAXNODES
index|]
decl_stmt|;
name|short
name|de_newq
decl_stmt|;
comment|/* OVPQ must devise new strategy */
name|short
name|de_newr
decl_stmt|;
comment|/* force OVQP to reopen result relation */
name|int
name|de_qmode
decl_stmt|;
comment|/* flag set to indicate mode of tuple disposition */
name|int
name|de_resultvar
decl_stmt|;
comment|/* if>= 0 result variable */
name|int
name|de_sourcevar
decl_stmt|;
comment|/* likewise for source variable */
name|char
modifier|*
name|de_qbuf
decl_stmt|;
comment|/* pointer to query buffer */
name|QTREE
modifier|*
name|de_qle
decl_stmt|;
comment|/* ptr to QLEND node */
name|QTREE
modifier|*
name|de_tr
decl_stmt|;
comment|/* ptr to TREE node */
name|int
name|de_dfiles
decl_stmt|;
name|int
name|de_dopnfiles
decl_stmt|;
name|struct
name|desc_tab
name|de_desc
index|[
name|MAXRELN
index|]
decl_stmt|;
comment|/* descriptors available for use */
name|struct
name|rang_tab
name|de_rangev
index|[
name|MAXRANGE
operator|+
literal|2
index|]
decl_stmt|;
comment|/* global range table with extra slot for FREEVAR and SECINDVAR */
name|int
name|de_qry_mode
decl_stmt|;
comment|/* mode of original query (not nec same as de_qmode) */
name|char
name|de_name_table
index|[
name|FIRSTNUM
operator|-
literal|1
index|]
index|[
name|MAXNAME
index|]
decl_stmt|;
name|char
name|de_num_used
index|[
name|LASTNUM
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|de_buflag
decl_stmt|;
block|}
name|De
struct|;
end_struct

begin_decl_stmt
name|short
name|tTdecomp
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|tTf
end_ifdef

begin_undef
undef|#
directive|undef
name|tTf
end_undef

begin_endif
endif|#
directive|endif
endif|tTf
end_endif

begin_define
define|#
directive|define
name|tTf
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((b< 0) ? tTdecomp[a] : (tTdecomp[a]& (1<< b)))
end_define

end_unit

