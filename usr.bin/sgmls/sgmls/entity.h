begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Struct dcncb: attribute list added to support data attributes.             */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ENTITY_H
end_ifndef

begin_comment
comment|/* Don't include this file more than once. */
end_comment

begin_define
define|#
directive|define
name|ENTITY_H
end_define

begin_comment
comment|/* ENTITY.H: Definitions and control block templates for entity management. */
end_comment

begin_include
include|#
directive|include
file|"tools.h"
end_include

begin_comment
comment|/* Definitions for type declarations, etc. */
end_comment

begin_include
include|#
directive|include
file|"msgcat.h"
end_include

begin_include
include|#
directive|include
file|"catalog.h"
end_include

begin_define
define|#
directive|define
name|STDINNAME
value|"-"
end_define

begin_comment
comment|/* File name that refers to standard input. */
end_comment

begin_define
define|#
directive|define
name|EOS
value|'\0'
end_define

begin_comment
comment|/* NONCHAR: EE (entity end: strings). */
end_comment

begin_define
define|#
directive|define
name|AVALCASE
value|2
end_define

begin_comment
comment|/* 2=untranslated string of name characters. */
end_comment

begin_define
define|#
directive|define
name|REFNAMELEN
value|8
end_define

begin_comment
comment|/* reference quantity set NAMELEN */
end_comment

begin_define
define|#
directive|define
name|REFLITLEN
value|240
end_define

begin_comment
comment|/* reference quantity set LITLEN */
end_comment

begin_comment
comment|/* Minimization status of returned tags. */
end_comment

begin_define
define|#
directive|define
name|MINNONE
value|0
end_define

begin_comment
comment|/* Minimization: tag not minimized. */
end_comment

begin_define
define|#
directive|define
name|MINNULL
value|1
end_define

begin_comment
comment|/* Minimization: tag was null. */
end_comment

begin_define
define|#
directive|define
name|MINNET
value|2
end_define

begin_comment
comment|/* Minimization: end-tag was NET delimiter. */
end_comment

begin_define
define|#
directive|define
name|MINDATA
value|3
end_define

begin_comment
comment|/* Minimization: end-tag was data tag. */
end_comment

begin_define
define|#
directive|define
name|MINSTAG
value|4
end_define

begin_comment
comment|/* Minimization: tag implied by start-tag. */
end_comment

begin_define
define|#
directive|define
name|MINETAG
value|5
end_define

begin_comment
comment|/* Minimization: end-tag implied by end-tag. */
end_comment

begin_comment
comment|/* Formal public identifier public text classes. */
end_comment

begin_define
define|#
directive|define
name|FPICAP
value|1
end_define

begin_define
define|#
directive|define
name|FPICHARS
value|2
end_define

begin_define
define|#
directive|define
name|FPINOT
value|3
end_define

begin_define
define|#
directive|define
name|FPISYN
value|4
end_define

begin_define
define|#
directive|define
name|FPICMINV
value|5
end_define

begin_comment
comment|/* Minimum fpic value for versionable text. */
end_comment

begin_define
define|#
directive|define
name|FPIDOC
value|5
end_define

begin_define
define|#
directive|define
name|FPIDTD
value|6
end_define

begin_define
define|#
directive|define
name|FPIELEM
value|7
end_define

begin_define
define|#
directive|define
name|FPIENT
value|8
end_define

begin_define
define|#
directive|define
name|FPILPD
value|9
end_define

begin_define
define|#
directive|define
name|FPINON
value|10
end_define

begin_define
define|#
directive|define
name|FPISHORT
value|11
end_define

begin_define
define|#
directive|define
name|FPISUB
value|12
end_define

begin_define
define|#
directive|define
name|FPITEXT
value|13
end_define

begin_struct
struct|struct
name|fpi
block|{
comment|/* Formal public identifier. */
name|UNCH
name|fpiot
decl_stmt|;
comment|/* Owner type: + or - or ! (for ISO). */
name|UNS
name|fpiol
decl_stmt|;
comment|/* Length of owner identifier. */
name|UNS
name|fpio
decl_stmt|;
comment|/* Offset in pubis of owner identifier (no EOS).*/
name|int
name|fpic
decl_stmt|;
comment|/* Public text class. */
name|UNCH
name|fpitt
decl_stmt|;
comment|/* Text type: - or + (for available). */
name|UNS
name|fpitl
decl_stmt|;
comment|/* Length of text identifier. */
name|UNS
name|fpit
decl_stmt|;
comment|/* Offset in pubis of text identifier (no EOS). */
name|UNS
name|fpill
decl_stmt|;
comment|/* Language/designating sequence length. */
name|UNS
name|fpil
decl_stmt|;
comment|/* Offset in pubis of language. */
name|UNS
name|fpivl
decl_stmt|;
comment|/* Length of display version . */
name|UNS
name|fpiv
decl_stmt|;
comment|/* Offset in pubis of display version (no EOS). */
name|int
name|fpiversw
decl_stmt|;
comment|/* 1=use best ver; 0=use stated ver; -1=error. */
name|UNCH
modifier|*
name|fpinm
decl_stmt|;
comment|/* Entity/DCN name (EOS, no length). */
name|UNCH
name|fpistore
decl_stmt|;
comment|/* 1=NDATA 2=general 3=parm 4=DTD 5=LPD 6=DCN. */
comment|/* Name of the entity's DCN.  Valid only when fpistore == 1. 	NULL if it's a SUBDOC. */
name|UNCH
modifier|*
name|fpinedcn
decl_stmt|;
name|UNCH
modifier|*
name|fpipubis
decl_stmt|;
comment|/* Public ID string (EOS). */
name|UNCH
modifier|*
name|fpisysis
decl_stmt|;
comment|/* System ID string (EOS). */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FPISZ
value|sizeof(struct fpi)
end_define

begin_typedef
typedef|typedef
name|struct
name|fpi
modifier|*
name|PFPI
typedef|;
end_typedef

begin_comment
comment|/* Ptr to FPI control block. */
end_comment

begin_comment
comment|/* General control blocks. */
end_comment

begin_define
define|#
directive|define
name|NONONCH
value|1
end_define

begin_comment
comment|/* Character references to non-chars invalid. */
end_comment

begin_define
define|#
directive|define
name|OKNONCH
value|0
end_define

begin_comment
comment|/* Character references to non-chars allowed. */
end_comment

begin_struct
struct|struct
name|parse
block|{
comment|/* Parse control block. */
name|char
modifier|*
name|pname
decl_stmt|;
comment|/* Parse name; content, tag, etc. */
name|UNCH
modifier|*
name|plex
decl_stmt|;
comment|/* Lexical analysis table. */
name|UNCH
modifier|*
modifier|*
name|ptab
decl_stmt|;
comment|/* State and action table. */
name|UNS
name|state
decl_stmt|;
comment|/* State. */
name|UNS
name|input
decl_stmt|;
comment|/* Input. */
name|UNS
name|action
decl_stmt|;
comment|/* Action. */
name|UNS
name|newstate
decl_stmt|;
comment|/* Next state. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|restate
block|{
name|UNS
name|sstate
decl_stmt|;
comment|/* State. */
name|UNS
name|sinput
decl_stmt|;
comment|/* Input. */
name|UNS
name|saction
decl_stmt|;
comment|/* Action. */
name|UNS
name|snext
decl_stmt|;
comment|/* Next state. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|map
block|{
name|UNCH
modifier|*
name|mapnm
decl_stmt|;
comment|/* Name followed by EOS. */
name|int
name|mapdata
decl_stmt|;
comment|/* Data associated with that name. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hash
block|{
comment|/* Dummy structure for function arguments. */
name|struct
name|hash
modifier|*
name|enext
decl_stmt|;
comment|/* Next entry in chain. */
name|UNCH
modifier|*
name|ename
decl_stmt|;
comment|/* Entry name with size and EOS. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|hash
modifier|*
name|PHASH
typedef|;
end_typedef

begin_comment
comment|/* Ptr to hash table entry. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|hash
modifier|*
modifier|*
name|THASH
typedef|;
end_typedef

begin_comment
comment|/* Ptr to hash table. */
end_comment

begin_struct
struct|struct
name|fwdref
block|{
comment|/* A forward id reference. */
name|struct
name|fwdref
modifier|*
name|next
decl_stmt|;
comment|/* Pt to next reference in chain. */
name|UNIV
name|msg
decl_stmt|;
comment|/* Ptr to saved error messsage. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FWDREFSZ
value|sizeof(struct fwdref)
end_define

begin_struct
struct|struct
name|dcncb
block|{
comment|/* Data content notation control block. */
name|struct
name|dcncb
modifier|*
name|enext
decl_stmt|;
comment|/* Next DCN in chain. */
name|UNCH
modifier|*
name|ename
decl_stmt|;
comment|/* Notation name followed by EOS. */
name|UNCH
name|mark
decl_stmt|;
comment|/* For use by application. */
name|UNCH
name|entsw
decl_stmt|;
comment|/* Entity defined with this notation? */
name|UNCH
name|defined
decl_stmt|;
comment|/* Has this notation been defined. */
name|UNCH
modifier|*
name|sysid
decl_stmt|;
comment|/* System identifier of notation. */
name|UNCH
modifier|*
name|pubid
decl_stmt|;
comment|/* Public identifier of notation. */
name|struct
name|ad
modifier|*
name|adl
decl_stmt|;
comment|/* Data attribute list (NULL if none). */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DCBSZ
value|sizeof(struct dcncb)
end_define

begin_define
define|#
directive|define
name|DCNMARK
parameter_list|(
name|p
parameter_list|)
value|((p)->mark ? 1 : ((p)->mark = 1, 0))
end_define

begin_typedef
typedef|typedef
name|struct
name|dcncb
modifier|*
name|PDCB
typedef|;
end_typedef

begin_comment
comment|/* Ptr to DCN control block. */
end_comment

begin_comment
comment|/* Number of capacities in a capacity set. */
end_comment

begin_define
define|#
directive|define
name|NCAPACITY
value|17
end_define

begin_struct
struct|struct
name|sgmlcap
block|{
name|char
modifier|*
modifier|*
name|name
decl_stmt|;
name|UNCH
modifier|*
name|points
decl_stmt|;
name|long
modifier|*
name|number
decl_stmt|;
name|long
modifier|*
name|limit
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sgmlstat
block|{
comment|/* Document statistics. */
name|UNS
name|dcncnt
decl_stmt|;
comment|/* Number of data content notations defined. */
name|UNS
name|pmexgcnt
decl_stmt|;
comment|/* Number of plus or minus exception groups. */
name|UNS
name|etdcnt
decl_stmt|;
comment|/* Number of element types declared. */
name|UNS
name|etdercnt
decl_stmt|;
comment|/* Number of element types defined by default. */
name|UNS
name|pmexcnt
decl_stmt|;
comment|/* Number of plus/minus exception grp members. */
name|UNS
name|modcnt
decl_stmt|;
comment|/* Number of content model tokens defined. */
name|UNS
name|attcnt
decl_stmt|;
comment|/* Number of attributes defined. */
name|UNS
name|attdef
decl_stmt|;
comment|/* Characters of attribute defaults defined. */
name|UNS
name|attgcnt
decl_stmt|;
comment|/* Number of att value grp members (incl dcn). */
name|UNS
name|idcnt
decl_stmt|;
comment|/* Number of ID attributes specified. */
name|UNS
name|idrcnt
decl_stmt|;
comment|/* Number of ID references specified. */
name|UNS
name|ecbcnt
decl_stmt|;
comment|/* Number of entities declared. */
name|UNS
name|ecbtext
decl_stmt|;
comment|/* Characters of entity text defined. */
name|UNS
name|srcnt
decl_stmt|;
comment|/* Number of short reference tables defined. */
name|UNS
name|dcntext
decl_stmt|;
comment|/* Characters of notation identifiers defined. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|switches
block|{
comment|/* Parser control switches (1=non-standard). */
name|int
name|swdupent
decl_stmt|;
comment|/* 1=msg if duplicate ENTITY def attempted;0=no.*/
name|int
name|swcommnt
decl_stmt|;
comment|/* 1=return comment declarations as data; 0=no. */
name|int
name|swrefmsg
decl_stmt|;
comment|/* 1=msg if undeclared ref is defaulted; 0=no. */
name|UNS
name|swbufsz
decl_stmt|;
comment|/* Size of source file buffer for READ(). */
name|int
name|swenttr
decl_stmt|;
comment|/* 1=trace entity stack in error messages; 0=no.*/
name|int
name|sweltr
decl_stmt|;
comment|/* 1=trace element stack in error messages; 0=no. */
name|int
name|swambig
decl_stmt|;
comment|/* 1=check content model ambiguity */
name|int
name|swundef
decl_stmt|;
comment|/* 1=warn about undefined elements. */
name|int
name|swcap
decl_stmt|;
comment|/* 1=report capcity errors */
name|char
modifier|*
name|prog
decl_stmt|;
comment|/* Program name for error messages. */
ifdef|#
directive|ifdef
name|TRACE
name|char
modifier|*
name|trace
decl_stmt|;
comment|/* What to trace in the body. */
name|char
modifier|*
name|ptrace
decl_stmt|;
comment|/* What to trace in the prolog. */
endif|#
directive|endif
comment|/* TRACE */
name|nl_catd
name|catd
decl_stmt|;
comment|/* Message catalog descriptor. */
name|long
name|nopen
decl_stmt|;
comment|/* Number of open document entities */
name|int
name|onlypro
decl_stmt|;
comment|/* Parse only the prolog. */
name|char
modifier|*
modifier|*
name|includes
decl_stmt|;
comment|/* List of parameter entities to be defined 			         as "INCLUDE"; NULL terminated.*/
name|VOID
argument_list|(
argument|*die
argument_list|)
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* Function to call on fatal error. */
name|CATALOG
name|catalog
decl_stmt|;
comment|/* Catalog for generating system identifiers. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|markup
block|{
comment|/* Delimiter strings for text processor. */
name|UNCH
modifier|*
name|cro
decl_stmt|;
comment|/* LEXCON markup string: CRO        */
name|UNCH
modifier|*
name|dso
decl_stmt|;
comment|/* LEXCON markup string: DSO        */
name|UNCH
modifier|*
name|ero
decl_stmt|;
comment|/* LEXCON markup string: ERO        */
name|UNCH
modifier|*
name|etag
decl_stmt|;
comment|/* LEXMARK markup string: end-tag   */
name|UNCH
modifier|*
name|lit
decl_stmt|;
comment|/* LEXMARK markup string: LIT       */
name|UNCH
modifier|*
name|lita
decl_stmt|;
comment|/* LEXMARK markup string: LITA      */
name|UNCH
modifier|*
name|mdc
decl_stmt|;
comment|/* LEXCON markup string: MDC       */
name|UNCH
modifier|*
name|mdo
decl_stmt|;
comment|/* LEXCON markup string: MDO       */
name|UNCH
modifier|*
name|mse
decl_stmt|;
comment|/* LEXCON markup string: mse        */
name|UNCH
modifier|*
name|mss
decl_stmt|;
comment|/* LEXCON markup string: mss        */
name|UNCH
modifier|*
name|mssc
decl_stmt|;
comment|/* LEXCON markup string: mss CDATA  */
name|UNCH
modifier|*
name|mssr
decl_stmt|;
comment|/* LEXCON markup string: mss RCDATA */
name|UNCH
modifier|*
name|pic
decl_stmt|;
comment|/* LEXCON markup string: PIC        */
name|UNCH
modifier|*
name|pio
decl_stmt|;
comment|/* LEXCON markup string: PIO        */
name|UNCH
modifier|*
name|refc
decl_stmt|;
comment|/* LEXGRP markup string: REFC       */
name|UNCH
modifier|*
name|stag
decl_stmt|;
comment|/* LEXMARK markup string: start-tag */
name|UNCH
modifier|*
name|tagc
decl_stmt|;
comment|/* LEXMARK markup string: TAGC      */
name|UNCH
modifier|*
name|vi
decl_stmt|;
comment|/* LEXMARK markup string: VI        */
name|int
name|lennet
decl_stmt|;
comment|/* LEXMARK markup string length: null end-tag. */
name|int
name|lennst
decl_stmt|;
comment|/* LEXMARK markup string length: null start-tag.*/
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef ENTITY_H */
end_comment

end_unit

