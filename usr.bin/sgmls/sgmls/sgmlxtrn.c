begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    Standard Generalized Markup Language Users' Group (SGMLUG)                  SGML Parser Materials (ARCSGML 1.0)  (C) 1983-1988 Charles F. Goldfarb (assigned to IBM Corporation) (C) 1988-1991 IBM Corporation  Licensed to the SGML Users' Group for distribution under the terms of the following license:                                                       */
end_comment

begin_decl_stmt
name|char
name|license
index|[]
init|=
literal|"SGMLUG hereby grants to any user: (1) an irrevocable royalty-free,\n\ worldwide, non-exclusive license to use, execute, reproduce, display,\n\ perform and distribute copies of, and to prepare derivative works\n\ based upon these materials; and (2) the right to authorize others to\n\ do any of the foregoing.\n"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"sgmlincl.h"
end_include

begin_comment
comment|/* SGMLXTRN: Storage allocation and initialization for all public variables.              Exceptions: Constants lex????? and del????? are defined in              LEX?????.C modules; constants pcb????? are defined in PCB?????.c. */
end_comment

begin_decl_stmt
name|int
name|badresw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=REF_ out of context; 0=valid. */
end_comment

begin_decl_stmt
name|int
name|charmode
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*>0=in #CHARS; 0=not. */
end_comment

begin_decl_stmt
name|int
name|conactsw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=return saved content action 0=get new one.*/
end_comment

begin_decl_stmt
name|int
name|conrefsw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=content reference att specified; 0=no. */
end_comment

begin_decl_stmt
name|int
name|contersv
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save contersw while processing pending REF. */
end_comment

begin_decl_stmt
name|int
name|contersw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=element or #CHARS out of context; 0=valid. */
end_comment

begin_decl_stmt
name|int
name|datarc
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return code for data: DAF_ or REF_. */
end_comment

begin_decl_stmt
name|int
name|delmscsw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=DELMSC must be read on return to es==0. */
end_comment

begin_decl_stmt
name|int
name|didreq
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=required implied tag processed; 0=no. */
end_comment

begin_decl_stmt
name|int
name|docelsw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=had document element; 0=no */
end_comment

begin_decl_stmt
name|int
name|dostag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=retry newetd instead of parsing; 0=parse. */
end_comment

begin_decl_stmt
name|int
name|dtdsw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DOCTYPE declaration found: 1=yes; 0=no. */
end_comment

begin_decl_stmt
name|int
name|entdatsw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 2=CDATA entity; 4=SDATA; 8=NDATA; 0=none. */
end_comment

begin_decl_stmt
name|int
name|entpisw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4=PI entity occurred; 0=not. */
end_comment

begin_decl_stmt
name|int
name|eodsw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=eod found in error; 0=not yet. */
end_comment

begin_decl_stmt
name|int
name|eofsw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=eof found in body of document; 0=not yet. */
end_comment

begin_decl_stmt
name|int
name|es
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index of current source in stack. */
end_comment

begin_decl_stmt
name|int
name|etagimct
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Implicitly ended elements left on stack. */
end_comment

begin_decl_stmt
name|int
name|etagimsw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=end-tag implied by other end-tag; 0=not. */
end_comment

begin_decl_stmt
name|int
name|etagmin
init|=
name|MINNONE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Minim: NONE NULL NET DATA; implied by S/ETAG*/
end_comment

begin_decl_stmt
name|int
name|etictr
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of "NET enabled" tags on stack. */
end_comment

begin_decl_stmt
name|int
name|etisw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=tag ended with eti; 0=did not. */
end_comment

begin_decl_stmt
name|int
name|indtdsw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we in the DTD? 1=yes; 0=no. */
end_comment

begin_decl_stmt
name|int
name|mslevel
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nesting level of marked sections. */
end_comment

begin_decl_stmt
name|int
name|msplevel
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nested MS levels subject to special parse. */
end_comment

begin_decl_stmt
name|int
name|prologsw
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=in prolog; 0=not. */
end_comment

begin_decl_stmt
name|int
name|pss
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SGMLACT: scbsgml stack level. */
end_comment

begin_decl_stmt
name|int
name|sgmlsw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SGML declaration found: 1=yes; 0=no. */
end_comment

begin_decl_stmt
name|int
name|stagmin
init|=
name|MINNONE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Minimization: NONE, NULL tag, implied by STAG*/
end_comment

begin_decl_stmt
name|int
name|tagctr
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tag source chars read. */
end_comment

begin_decl_stmt
name|int
name|tages
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ES level at start of tag. */
end_comment

begin_decl_stmt
name|int
name|ts
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index of current tag in stack. */
end_comment

begin_decl_stmt
name|struct
name|parse
modifier|*
name|propcb
init|=
operator|&
name|pcbpro
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current PCB for prolog parse. */
end_comment

begin_decl_stmt
name|int
name|aentctr
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of ENTITY tokens in this att list. */
end_comment

begin_decl_stmt
name|int
name|conact
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return code from content parse. */
end_comment

begin_decl_stmt
name|int
name|conrefsv
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save conrefsw when doing implied start-tag.*/
end_comment

begin_decl_stmt
name|int
name|dtdrefsw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* External DTD? 1=yes; 0=no. */
end_comment

begin_decl_stmt
name|int
name|etiswsv
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save etisw when processing implied start-tag.*/
end_comment

begin_decl_stmt
name|int
name|grplvl
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current level of nested grps in model. */
end_comment

begin_decl_stmt
name|int
name|idrctr
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of IDREF tokens in this att list. */
end_comment

begin_decl_stmt
name|int
name|mdessv
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ES level at start of markup declaration. */
end_comment

begin_decl_stmt
name|int
name|notadn
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Position of NOTATION attribute in list. */
end_comment

begin_decl_stmt
name|int
name|parmno
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current markup declaration parameter number. */
end_comment

begin_decl_stmt
name|int
name|pexsw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=tag valid solely because of plus exception.*/
end_comment

begin_decl_stmt
name|int
name|rcessv
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ES level at start of RCDATA content. */
end_comment

begin_decl_stmt
name|int
name|tagdelsw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=tag ended with delimiter; 0=no delimiter. */
end_comment

begin_decl_stmt
name|int
name|tokencnt
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of tokens found in attribute value. */
end_comment

begin_decl_stmt
name|struct
name|entity
modifier|*
name|ecbdeflt
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* #DEFAULT ecb (NULL if no default entity). */
end_comment

begin_decl_stmt
name|struct
name|etd
modifier|*
name|docetd
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The etd for the document as a whole. */
end_comment

begin_decl_stmt
name|struct
name|etd
modifier|*
name|etagreal
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Actual or dummy etd that implied this tag. */
end_comment

begin_decl_stmt
name|struct
name|etd
modifier|*
name|newetd
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The etd for a start- or end-tag recognized. */
end_comment

begin_decl_stmt
name|struct
name|etd
modifier|*
name|nextetd
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ETD that must come next (only one choice). */
end_comment

begin_decl_stmt
name|struct
name|etd
modifier|*
name|lastetd
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* most recently ended ETD. */
end_comment

begin_decl_stmt
name|struct
name|etd
modifier|*
name|stagreal
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Actual or dummy etd that implied this tag. */
end_comment

begin_decl_stmt
name|struct
name|parse
modifier|*
name|conpcb
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current PCB for content parse. */
end_comment

begin_decl_stmt
name|UNCH
modifier|*
name|data
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to returned data in buffer. */
end_comment

begin_decl_stmt
name|UNCH
modifier|*
name|mdname
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of current markup declaration. */
end_comment

begin_decl_stmt
name|UNCH
modifier|*
name|ptcon
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current pointer into tbuf. */
end_comment

begin_decl_stmt
name|UNCH
modifier|*
name|ptpro
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current pointer into tbuf. */
end_comment

begin_decl_stmt
name|UNCH
modifier|*
name|rbufs
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DOS file read area: start position for read. */
end_comment

begin_decl_stmt
name|UNCH
modifier|*
name|subdcl
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Subject of markup declaration (e.g., GI). */
end_comment

begin_decl_stmt
name|UNS
name|conradn
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=CONREF attribute in list (0=no). */
end_comment

begin_decl_stmt
name|UNS
name|datalen
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Length of returned data in buffer. */
end_comment

begin_decl_stmt
name|UNS
name|entlen
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Length of TAG or EXTERNAL entity text. */
end_comment

begin_decl_stmt
name|UNS
name|idadn
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of ID attribute (0 if none). */
end_comment

begin_decl_stmt
name|UNS
name|noteadn
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of NOTATION attribute (0 if none). */
end_comment

begin_decl_stmt
name|UNS
name|reqadn
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Num of atts with REQUIRED default (0=none). */
end_comment

begin_decl_stmt
name|int
name|grplongs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of longs for GRPCNT bitvector. */
end_comment

begin_comment
comment|/* Variable arrays and structures. */
end_comment

begin_decl_stmt
name|struct
name|ad
modifier|*
name|al
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current attribute list work area. */
end_comment

begin_decl_stmt
name|struct
name|dcncb
modifier|*
name|dcntab
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of data content notation names. */
end_comment

begin_decl_stmt
name|struct
name|entity
modifier|*
name|etab
index|[
name|ENTHASH
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Entity hash table. */
end_comment

begin_decl_stmt
name|struct
name|etd
modifier|*
name|etdtab
index|[
name|ETDHASH
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Element type definition hash table. */
end_comment

begin_decl_stmt
name|struct
name|fpi
name|fpidf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fpi for #DEFAULT entity. */
end_comment

begin_decl_stmt
name|struct
name|id
modifier|*
name|itab
index|[
name|IDHASH
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Unique identifier hash table. */
end_comment

begin_decl_stmt
name|struct
name|etd
modifier|*
modifier|*
name|nmgrp
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Element name group */
end_comment

begin_decl_stmt
name|PDCB
modifier|*
name|nnmgrp
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Notation name group */
end_comment

begin_decl_stmt
name|struct
name|restate
modifier|*
name|scbsgml
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SGMLACT: return action state stack. */
end_comment

begin_decl_stmt
name|struct
name|source
modifier|*
name|scbs
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stack of open sources ("SCB stack"). */
end_comment

begin_decl_stmt
name|struct
name|srh
modifier|*
name|srhtab
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of SHORTREF table headers. */
end_comment

begin_decl_stmt
name|struct
name|sgmlstat
name|ds
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Document statistics. */
end_comment

begin_decl_stmt
name|struct
name|switches
name|sw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parser control switches set by text proc. */
end_comment

begin_decl_stmt
name|struct
name|tag
modifier|*
name|tags
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stack of open elements ("tag stack"). */
end_comment

begin_decl_stmt
name|struct
name|thdr
modifier|*
name|gbuf
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer for creating group. */
end_comment

begin_decl_stmt
name|struct
name|thdr
name|prcon
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0-2: Model for *DOC content. */
end_comment

begin_decl_stmt
name|struct
name|thdr
name|undechdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0:Default model hdr for undeclared content.*/
end_comment

begin_decl_stmt
name|UNCH
modifier|*
name|dtype
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Document type name. */
end_comment

begin_decl_stmt
name|UNCH
modifier|*
name|entbuf
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer for entity reference name. */
end_comment

begin_decl_stmt
name|UNCH
name|fce
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* String form of FCE char.                                  (fce[1] must be EOS).*/
end_comment

begin_comment
comment|/* Buffer for non-SGML character reference.*/
end_comment

begin_decl_stmt
name|UNCH
name|nonchbuf
index|[
literal|2
index|]
init|=
block|{
name|DELNONCH
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|UNCH
modifier|*
name|tbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Work area for tokenization. */
end_comment

begin_decl_stmt
name|UNCH
modifier|*
name|lbuf
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In tbuf: Literal parse area.*/
end_comment

begin_decl_stmt
name|UNCH
modifier|*
name|sysibuf
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer for system identifiers. */
end_comment

begin_decl_stmt
name|UNCH
modifier|*
name|pubibuf
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer for public identifiers. */
end_comment

begin_decl_stmt
name|UNCH
modifier|*
name|nmbuf
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name buffer used by mdentity. */
end_comment

begin_decl_stmt
name|struct
name|mpos
modifier|*
name|savedpos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Constants. */
end_comment

begin_decl_stmt
name|struct
name|map
name|dctab
index|[]
init|=
block|{
comment|/* Keywords for declared content parameter.*/
block|{
name|key
index|[
name|KRCDATA
index|]
block|,
name|MRCDATA
operator|+
name|MPHRASE
block|}
block|,
block|{
name|key
index|[
name|KCDATA
index|]
block|,
name|MCDATA
operator|+
name|MPHRASE
block|}
block|,
block|{
name|key
index|[
name|KANY
index|]
block|,
name|MANY
operator|+
name|MCHARS
operator|+
name|MGI
block|}
block|,
block|{
name|key
index|[
name|KEMPTY
index|]
block|,
name|MNONE
operator|+
name|MPHRASE
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|map
name|deftab
index|[]
init|=
block|{
comment|/* Default value keywords. */
block|{
name|key
index|[
name|KIMPLIED
index|]
block|,
name|DNULL
block|}
block|,
block|{
name|key
index|[
name|KREQUIRED
index|]
block|,
name|DREQ
block|}
block|,
block|{
name|key
index|[
name|KCURRENT
index|]
block|,
name|DCURR
block|}
block|,
block|{
name|key
index|[
name|KCONREF
index|]
block|,
name|DCONR
block|}
block|,
block|{
name|key
index|[
name|KFIXED
index|]
block|,
name|DFIXED
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|map
name|dvtab
index|[]
init|=
block|{
comment|/* Declared value: keywords and type codes.*/
comment|/*                                TYPE      NUMBER   */
comment|/*   grp             ANMTGRP      Case 1 0  Grp size */
comment|/*   grp member      ANMTGRP      Case   0  Position */
comment|/*   grp             ANOTEGRP     Case 1 1  Grp size */
block|{
name|key
index|[
name|KNOTATION
index|]
block|,
name|ANOTEGRP
block|}
block|,
comment|/* Case   1  Position */
block|{
name|key
index|[
name|KCDATA
index|]
block|,
name|ACHARS
block|}
block|,
comment|/* Case   2  Always 0 */
block|{
name|key
index|[
name|KENTITY
index|]
block|,
name|AENTITY
block|}
block|,
comment|/* Case   3  Normal 1 */
block|{
name|key
index|[
name|KID
index|]
block|,
name|AID
block|}
block|,
comment|/* Case   4  Normal 1 */
block|{
name|key
index|[
name|KIDREF
index|]
block|,
name|AIDREF
block|}
block|,
comment|/* Case   5  Normal 1 */
block|{
name|key
index|[
name|KNAME
index|]
block|,
name|ANAME
block|}
block|,
comment|/* Case   6  Normal 1 */
block|{
name|key
index|[
name|KNMTOKEN
index|]
block|,
name|ANMTOKE
block|}
block|,
comment|/* Case   7  Normal 1 */
block|{
name|key
index|[
name|KNUMBER
index|]
block|,
name|ANUMBER
block|}
block|,
comment|/* Case   8  Normal 1 */
block|{
name|key
index|[
name|KNUTOKEN
index|]
block|,
name|ANUTOKE
block|}
block|,
comment|/* Case   9  Normal 1 */
block|{
name|key
index|[
name|KENTITIES
index|]
block|,
name|AENTITYS
block|}
block|,
comment|/* Case   A  Normal 1 */
block|{
name|key
index|[
name|KIDREFS
index|]
block|,
name|AIDREFS
block|}
block|,
comment|/* Case   B  # tokens */
block|{
name|key
index|[
name|KNAMES
index|]
block|,
name|ANAMES
block|}
block|,
comment|/* Case   C  # tokens */
block|{
name|key
index|[
name|KNMTOKENS
index|]
block|,
name|ANMTOKES
block|}
block|,
comment|/* Case   D  # tokens */
block|{
name|key
index|[
name|KNUMBERS
index|]
block|,
name|ANUMBERS
block|}
block|,
comment|/* Case   E  # tokens */
block|{
name|key
index|[
name|KNUTOKENS
index|]
block|,
name|ANUTOKES
block|}
block|,
comment|/* Case   F  # tokens */
block|{
name|NULL
block|,
literal|0
block|}
comment|/* Case   0  ERROR    */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|map
name|enttab
index|[]
init|=
block|{
comment|/* Entity declaration second parameter. */
block|{
name|key
index|[
name|KCDATA
index|]
block|,
name|ESC
block|}
block|,
block|{
name|key
index|[
name|KSDATA
index|]
block|,
name|ESX
block|}
block|,
block|{
name|key
index|[
name|KMS
index|]
block|,
name|ESMS
block|}
block|,
block|{
name|key
index|[
name|KPI
index|]
block|,
name|ESI
block|}
block|,
block|{
name|key
index|[
name|KSTARTTAG
index|]
block|,
name|ESS
block|}
block|,
block|{
name|key
index|[
name|KENDTAG
index|]
block|,
name|ESE
block|}
block|,
block|{
name|key
index|[
name|KMD
index|]
block|,
name|ESMD
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|map
name|exttab
index|[]
init|=
block|{
comment|/* Keywords for external identifier. */
block|{
name|key
index|[
name|KSYSTEM
index|]
block|,
name|EDSYSTEM
block|}
block|,
block|{
name|key
index|[
name|KPUBLIC
index|]
block|,
name|EDPUBLIC
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|map
name|extettab
index|[]
init|=
block|{
comment|/* Keywords for external entity type. */
block|{
name|key
index|[
name|KCDATA
index|]
block|,
name|ESNCDATA
block|}
block|,
block|{
name|key
index|[
name|KNDATA
index|]
block|,
name|ESNNDATA
block|}
block|,
block|{
name|key
index|[
name|KSDATA
index|]
block|,
name|ESNSDATA
block|}
block|,
block|{
name|key
index|[
name|KSUBDOC
index|]
block|,
name|ESNSUB
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|map
name|funtab
index|[]
init|=
block|{
comment|/* Function character reference names. */
block|{
name|key
index|[
name|KRE
index|]
block|,
name|RECHAR
block|}
block|,
block|{
name|key
index|[
name|KRS
index|]
block|,
name|RSCHAR
block|}
block|,
block|{
name|key
index|[
name|KSPACE
index|]
block|,
name|SPCCHAR
block|}
block|,
comment|/* We should use an extra table for added functions. */
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"TAB"
block|,
name|TABCHAR
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|map
name|mstab
index|[]
init|=
block|{
comment|/* Marked section keywords. */
block|{
name|key
index|[
name|KTEMP
index|]
block|,
name|MSTEMP
block|}
block|,
block|{
name|key
index|[
name|KINCLUDE
index|]
block|,
name|MSTEMP
block|}
block|,
comment|/* Treat INCLUDE like TEMP; both are NOPs.*/
block|{
name|key
index|[
name|KRCDATA
index|]
block|,
name|MSRCDATA
block|}
block|,
block|{
name|key
index|[
name|KCDATA
index|]
block|,
name|MSCDATA
block|}
block|,
block|{
name|key
index|[
name|KIGNORE
index|]
block|,
name|MSIGNORE
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|map
name|pubcltab
index|[]
init|=
block|{
comment|/* Names for public text class. */
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"CAPACITY"
block|,
name|FPICAP
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"CHARSET"
block|,
name|FPICHARS
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"DOCUMENT"
block|,
name|FPIDOC
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"DTD"
block|,
name|FPIDTD
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"ELEMENTS"
block|,
name|FPIELEM
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"ENTITIES"
block|,
name|FPIENT
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"LPD"
block|,
name|FPILPD
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"NONSGML"
block|,
name|FPINON
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"NOTATION"
block|,
name|FPINOT
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"SHORTREF"
block|,
name|FPISHORT
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"SUBDOC"
block|,
name|FPISUB
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"SYNTAX"
block|,
name|FPISYN
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"TEXT"
block|,
name|FPITEXT
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|UNCH
name|indefent
index|[]
init|=
literal|"\12#DEFAULT"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal name: default entity name. */
end_comment

begin_decl_stmt
name|UNCH
name|indefetd
index|[]
init|=
literal|"\12*DOCTYPE"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal name: default document type. */
end_comment

begin_decl_stmt
name|UNCH
name|indocent
index|[]
init|=
literal|"\12*SGMLDOC"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal name: SGML document entity. */
end_comment

begin_decl_stmt
name|UNCH
name|indocetd
index|[]
init|=
literal|"\6*DOC"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal name: document level etd. */
end_comment

begin_decl_stmt
name|UNCH
name|indtdent
index|[]
init|=
literal|"\11*DTDENT"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal name: external DTD entity. */
end_comment

begin_decl_stmt
name|struct
name|etd
name|dumetd
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|entity
modifier|*
name|dumpecb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|UNCH
name|sgmlkey
index|[]
init|=
literal|"SGML"
decl_stmt|;
end_decl_stmt

end_unit

