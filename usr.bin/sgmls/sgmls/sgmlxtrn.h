begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SGMLXTRN.H: External declarations for SGML public variables.                Exceptions: Constants lex????? and del????? are defined in                LEX?????.C modules; constants pcb????? are defined in PCB?????.c. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SGMLXTRN
end_ifndef

begin_comment
comment|/* Don't include this file more than once. */
end_comment

begin_define
define|#
directive|define
name|SGMLXTRN
end_define

begin_decl_stmt
specifier|extern
name|int
name|badresw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=REF_ out of context; 0=valid. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|charmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*>0=in #CHARS; 0=not. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|conactsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=return saved content action 0=get new one.*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|conrefsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=content reference att specified; 0=no. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|contersv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save contersw while processing pending REF. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|contersw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=element or #CHARS out of context; 0=valid. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|datarc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return code for data: DAF_ or REF_. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|delmscsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=DELMSC must be read on return to es==0. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|didreq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=required implied tag processed; 0=no. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|docelsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=had document element; 0=no */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dostag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=retry newetd instead of parsing; 0=parse. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dtdsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DOCTYPE declaration found: 1=yes; 0=no. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|entdatsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 2=CDATA entity; 4=SDATA; 8=NDATA; 0=none. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|entpisw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4=PI entity occurred; 0=not. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|eodsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=eod found in error; 0=not yet. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|eofsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=eof found in body of document; 0=not yet. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|etagimct
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Implicitly ended elements left on stack. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|etagimsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=end-tag implied by other end-tag; 0=not. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|etagmin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Minim: NONE NULL NET DATA; implied by S/ETAG*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|etictr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of "NET enabled" tags on stack. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|etisw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=tag ended with eti; 0=did not. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|indtdsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we in the DTD? 1=yes; 0=no. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mslevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nesting level of marked sections. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|msplevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nested MS levels subject to special parse. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|prologsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=in prolog; 0=not. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pss
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SGMLACT: scbsgml stack level. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sgmlsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SGML declaration found: 1=yes; 0=no. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stagmin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Minimization: NONE, NULL tag, implied by STAG*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tagctr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tag source chars read. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tages
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ES level at start of tag. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index of current tag in stack. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
modifier|*
name|propcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current PCB for prolog parse. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|aentctr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of ENTITY tokens in this att list. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|conact
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return code from content parse. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|conrefsv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save conrefsw when doing implied start-tag.*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dtdrefsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* External DTD? 1=yes; 0=no. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|etiswsv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save etisw when processing implied start-tag.*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|grplvl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current level of nested grps in model. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|idrctr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of IDREF tokens in this att list. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mdessv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ES level at start of markup declaration. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|notadn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Position of NOTATION attribute in list. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|parmno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current markup declaration parameter number. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pexsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=tag valid solely because of plus exception.*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rcessv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ES level at start of RCDATA content. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tagdelsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=tag ended with delimiter; 0=no delimiter. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tokencnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of tokens found in attribute value. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|entity
modifier|*
name|ecbdeflt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* #DEFAULT ecb (NULL if no default entity). */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|etd
modifier|*
name|docetd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The etd for the document as a whole. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|etd
modifier|*
name|etagreal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Actual or dummy etd that implied this tag. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|etd
modifier|*
name|newetd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The etd for a start- or end-tag recognized. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|etd
modifier|*
name|nextetd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ETD that must come next (only one choice). */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|etd
modifier|*
name|lastetd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Most recently ended ETD. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|etd
modifier|*
name|stagreal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Actual or dummy etd that implied this tag. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
modifier|*
name|conpcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current PCB for content parse. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
modifier|*
name|data
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to returned data in buffer. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
modifier|*
name|mdname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of current markup declaration. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
modifier|*
name|ptcon
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current pointer into tbuf. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
modifier|*
name|ptpro
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current pointer into tbuf. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
modifier|*
name|rbufs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DOS file read area: start position for read. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
modifier|*
name|subdcl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Subject of markup declaration (e.g., GI). */
end_comment

begin_decl_stmt
specifier|extern
name|UNS
name|conradn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=CONREF attribute in list (0=no). */
end_comment

begin_decl_stmt
specifier|extern
name|UNS
name|datalen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Length of returned data in buffer. */
end_comment

begin_decl_stmt
specifier|extern
name|UNS
name|entlen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Length of TAG or EXTERNAL entity text. */
end_comment

begin_decl_stmt
specifier|extern
name|UNS
name|idadn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of ID attribute (0 if none). */
end_comment

begin_decl_stmt
specifier|extern
name|UNS
name|noteadn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of NOTATION attribute (0 if none). */
end_comment

begin_decl_stmt
specifier|extern
name|UNS
name|reqadn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Num of atts with REQUIRED default (0=none). */
end_comment

begin_decl_stmt
specifier|extern
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
specifier|extern
name|struct
name|ad
modifier|*
name|al
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current attribute list work area. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|dcncb
modifier|*
name|dcntab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of data content notation names. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|entity
modifier|*
name|etab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Entity hash table. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|etd
modifier|*
name|etdtab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Element type definition hash table. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|fpi
name|fpidf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fpi for #DEFAULT entity. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|id
modifier|*
name|itab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Unique identifier hash table. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|etd
modifier|*
modifier|*
name|nmgrp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Element name group */
end_comment

begin_decl_stmt
specifier|extern
name|PDCB
modifier|*
name|nnmgrp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Notation name group */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|restate
modifier|*
name|scbsgml
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SGMLACT: return action state stack. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|srh
modifier|*
name|srhtab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of SHORTREF table headers. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sgmlstat
name|ds
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Document statistics. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|switches
name|sw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parser control switches set by text proc. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|tag
modifier|*
name|tags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stack of open elements ("tag stack"). */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|thdr
modifier|*
name|gbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer for creating group. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|thdr
name|prcon
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0-2: Model for *DOC content. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|thdr
name|undechdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0: Default model hdr for undeclared content. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
modifier|*
name|dtype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Document type name. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
modifier|*
name|entbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer for entity reference name. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
name|fce
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* String form of FCE char (fce[1] must be EOS).*/
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
name|nonchbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer for valid nonchar character reference.*/
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
modifier|*
name|tbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Work area for tokenization. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
modifier|*
name|lbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In tbuf: Literal parse area; TAGLEN limit.*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|entity
modifier|*
name|dumpecb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SRMNULL points to this. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
modifier|*
name|sysibuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UNCH
modifier|*
name|pubibuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UNCH
modifier|*
name|nmbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name buffer used by mdentity. */
end_comment

begin_decl_stmt
specifier|extern
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
specifier|extern
name|int
name|scbsgmnr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SCBSGML: new record; do not ignore RE. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|scbsgmst
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SCBSGML: trailing stag or markup; ignore RE. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|map
name|dctab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Keywords for declared content parameter. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|map
name|deftab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default value keywords. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|map
name|dvtab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declared value: keywords and type codes.*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|map
name|enttab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Entity declaration second parameter. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|map
name|exttab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Keywords for external identifier. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|map
name|extettab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Keywords for external entity type. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|map
name|funtab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function character reference names. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|map
name|mstab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Marked section keywords. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|map
name|pubcltab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Keywords for public text class. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
name|indefent
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal name: default entity name. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
name|indefetd
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal name: default document type. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
name|indocent
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal name: SGML document entity. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
name|indocetd
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal name: etd for document as a whole. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
name|indtdent
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal name: external DTD entity. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|license
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SGML Users' Group free license. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef SGMLXTRN */
end_comment

end_unit

