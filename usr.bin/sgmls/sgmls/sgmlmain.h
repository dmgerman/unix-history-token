begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SGMLMAIN: Main interface to SGML services.  Preprocessor variable names are the only supported interface to data maintained by SGML.  They are defined in this file or in adl.h. */
end_comment

begin_comment
comment|/* Return control block types (RCBTYPE) from calls to parser (SGML):    Names and strings follow the convention for the IPBs. */
end_comment

begin_enum
enum|enum
name|sgmlevent
block|{
name|SGMLEOD
block|,
comment|/* End of document. */
name|SGMLDAF
block|,
comment|/* Data found. */
name|SGMLSTG
block|,
comment|/* Start-tag found. */
name|SGMLETG
block|,
comment|/* End-tag found. */
name|SGMLREF
block|,
comment|/* Record end found. */
name|SGMLPIS
block|,
comment|/* Processing instruction (string). */
name|SGMLAPP
comment|/* APPINFO (string) */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|rcbdata
block|{
comment|/* Return control block: DAF EOD REF PIS APP. */
name|UNS
name|contersw
decl_stmt|;
comment|/* 1=context error; 2,4,8=data type; 0=not. */
name|UNS
name|datalen
decl_stmt|;
comment|/* Length of data or PI (0=single nonchar). */
name|UNCH
modifier|*
name|data
decl_stmt|;
comment|/* Data, PI, single nonSGML, or NDATA ecb ptr. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rcbtag
block|{
comment|/* Return control block for STG and ETG. */
name|UNS
name|contersw
decl_stmt|;
comment|/* 1=context error; 2=NET enabled; 0/0=not. */
name|UNS
name|tagmin
decl_stmt|;
comment|/* Minim: NONE NULL NET DATA; implied by S/ETAG */
name|UNCH
modifier|*
name|curgi
decl_stmt|;
comment|/* Start-tag (or end-tag) GI. */
union|union
block|{
name|struct
name|ad
modifier|*
name|al
decl_stmt|;
comment|/* Start-tag: attribute list. */
name|UNCH
modifier|*
name|oldgi
decl_stmt|;
comment|/* End-tag: resumed GI. */
block|}
name|ru
union|;
name|struct
name|ad
modifier|*
name|lal
decl_stmt|;
comment|/* Start-tag: link attribute list (UNUSED). */
name|UNS
name|format
decl_stmt|;
comment|/* Format class for default processing. */
name|struct
name|etd
modifier|*
name|tagreal
decl_stmt|;
comment|/* Dummy etd or ptr to GI that implied this tag.*/
name|int
name|etictr
decl_stmt|;
comment|/* Number of elements on stack with NET enabled.*/
name|UNCH
modifier|*
name|srmnm
decl_stmt|;
comment|/* Current SHORTREF map name (NULL=#EMPTY). */
block|}
struct|;
end_struct

begin_comment
comment|/* Accessors for rcbdata and rcbtag. */
end_comment

begin_comment
comment|/* Datatype abbreviations: C=unsigned char  S=string  U=unsigned int L=4 bytes                            A=array  P=ptr to structure N=name (see sgmlcb.h) */
end_comment

begin_comment
comment|/* Data control block fields: processing instructions (SGMLPIS). */
end_comment

begin_define
define|#
directive|define
name|PDATA
parameter_list|(
name|d
parameter_list|)
value|((d).data)
end_define

begin_comment
comment|/*S  PI string. */
end_comment

begin_define
define|#
directive|define
name|PDATALEN
parameter_list|(
name|d
parameter_list|)
value|((d).datalen)
end_define

begin_comment
comment|/*U  Length of PI string. */
end_comment

begin_define
define|#
directive|define
name|PIESW
parameter_list|(
name|d
parameter_list|)
value|(((d).contersw& 4))
end_define

begin_comment
comment|/*U  1=PIDATA entity returned. */
end_comment

begin_comment
comment|/* Data control block fields: other data types. */
end_comment

begin_define
define|#
directive|define
name|CDATA
parameter_list|(
name|d
parameter_list|)
value|((d).data)
end_define

begin_comment
comment|/*S  CDATA content string. */
end_comment

begin_define
define|#
directive|define
name|CDATALEN
parameter_list|(
name|d
parameter_list|)
value|((d).datalen)
end_define

begin_comment
comment|/*U  Length of CDATA content string. */
end_comment

begin_define
define|#
directive|define
name|CONTERSW
parameter_list|(
name|d
parameter_list|)
value|(((d).contersw&1))
end_define

begin_comment
comment|/*U  1=CDATA or TAG out of context. */
end_comment

begin_define
define|#
directive|define
name|CDESW
parameter_list|(
name|d
parameter_list|)
value|(((d).contersw& 2))
end_define

begin_comment
comment|/*U  1=CDATA entity returned. */
end_comment

begin_define
define|#
directive|define
name|SDESW
parameter_list|(
name|d
parameter_list|)
value|(((d).contersw& 4))
end_define

begin_comment
comment|/*U  1=SDATA entity returned. */
end_comment

begin_define
define|#
directive|define
name|NDESW
parameter_list|(
name|d
parameter_list|)
value|(((d).contersw& 8))
end_define

begin_comment
comment|/*U  1=NDATA entity returned. */
end_comment

begin_define
define|#
directive|define
name|NEPTR
parameter_list|(
name|d
parameter_list|)
value|((PNE)(d).data)
end_define

begin_comment
comment|/*P  Ptr to NDATA control block. */
end_comment

begin_define
define|#
directive|define
name|MARKUP
parameter_list|(
name|d
parameter_list|)
value|((d).data)
end_define

begin_comment
comment|/*A  Markup delimiter strings. */
end_comment

begin_define
define|#
directive|define
name|DTYPELEN
parameter_list|(
name|d
parameter_list|)
value|((d).datalen)
end_define

begin_comment
comment|/*U  Length of doc type name +len+EOS. */
end_comment

begin_define
define|#
directive|define
name|DOCTYPE
parameter_list|(
name|d
parameter_list|)
value|((d).data)
end_define

begin_comment
comment|/*S  Document type name (with len+EOS). */
end_comment

begin_define
define|#
directive|define
name|ADATA
parameter_list|(
name|d
parameter_list|)
value|((d).data)
end_define

begin_comment
comment|/*S  APPINFO */
end_comment

begin_define
define|#
directive|define
name|ADATALEN
parameter_list|(
name|d
parameter_list|)
value|((d).datalen)
end_define

begin_comment
comment|/*U  Length of APPINFO string.  */
end_comment

begin_comment
comment|/* Tag control block fields. */
end_comment

begin_define
define|#
directive|define
name|ALPTR
parameter_list|(
name|t
parameter_list|)
value|((t).ru.al)
end_define

begin_comment
comment|/*P  Ptr to SGML attribute list. */
end_comment

begin_define
define|#
directive|define
name|CURGI
parameter_list|(
name|t
parameter_list|)
value|((t).curgi+1)
end_define

begin_comment
comment|/*N  GI of started or ended element. */
end_comment

begin_define
define|#
directive|define
name|OLDGI
parameter_list|(
name|t
parameter_list|)
value|((t).ru.oldgi)
end_define

begin_comment
comment|/*S  GI of resumed element. */
end_comment

begin_define
define|#
directive|define
name|TAGMIN
parameter_list|(
name|t
parameter_list|)
value|(t).tagmin
end_define

begin_comment
comment|/*U  Minimization for current tag. */
end_comment

begin_define
define|#
directive|define
name|TAGREAL
parameter_list|(
name|t
parameter_list|)
value|((t).tagreal)
end_define

begin_comment
comment|/*P  Dummy etd that implied this tag. */
end_comment

begin_define
define|#
directive|define
name|TAGRLNM
parameter_list|(
name|t
parameter_list|)
value|((UNCH *)(t).tagreal)
end_define

begin_comment
comment|/*P GI of tag that implied this tag.*/
end_comment

begin_define
define|#
directive|define
name|ETISW
parameter_list|(
name|t
parameter_list|)
value|(((t).contersw& 2))
end_define

begin_comment
comment|/*U  1=NET delimiter enabled by ETI. */
end_comment

begin_define
define|#
directive|define
name|PEXSW
parameter_list|(
name|t
parameter_list|)
value|(((t).contersw& 4))
end_define

begin_comment
comment|/*U  1=Element was plus exception. */
end_comment

begin_define
define|#
directive|define
name|MTYSW
parameter_list|(
name|t
parameter_list|)
value|(((t).contersw& 8))
end_define

begin_comment
comment|/*U  1=Element is empty. */
end_comment

begin_define
define|#
directive|define
name|ETICTR
parameter_list|(
name|t
parameter_list|)
value|((t).etictr)
end_define

begin_comment
comment|/*U  Number of active NET delimiters. */
end_comment

begin_define
define|#
directive|define
name|SRMNM
parameter_list|(
name|t
parameter_list|)
value|((t).srmnm)
end_define

begin_comment
comment|/*S  Name of current SHORTREF map. */
end_comment

begin_define
define|#
directive|define
name|SRMCNT
parameter_list|(
name|t
parameter_list|)
value|((t).contersw)
end_define

begin_comment
comment|/*U  Number of SHORTREF maps defined. */
end_comment

begin_define
define|#
directive|define
name|FORMAT
parameter_list|(
name|t
parameter_list|)
value|((t).format)
end_define

begin_comment
comment|/*U  Format class.*/
end_comment

begin_comment
comment|/* These function names are chosen so as to be distinct in the first 6 letters. */
end_comment

begin_comment
comment|/* Initialize. */
end_comment

begin_decl_stmt
name|struct
name|markup
modifier|*
name|sgmlset
name|P
argument_list|(
operator|(
expr|struct
name|switches
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cleanup and return capacity usage statistics. */
end_comment

begin_decl_stmt
name|VOID
name|sgmlend
name|P
argument_list|(
operator|(
expr|struct
name|sgmlcap
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set document entity. */
end_comment

begin_decl_stmt
name|int
name|sgmlsdoc
name|P
argument_list|(
operator|(
name|UNIV
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get entity. */
end_comment

begin_decl_stmt
name|int
name|sgmlgent
name|P
argument_list|(
operator|(
name|UNCH
operator|*
operator|,
name|PNE
operator|*
operator|,
name|UNCH
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mark an entity.  Return is non-zero if already marked.*/
end_comment

begin_decl_stmt
name|int
name|sgmlment
name|P
argument_list|(
operator|(
name|UNCH
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the next sgml event. */
end_comment

begin_decl_stmt
name|enum
name|sgmlevent
name|sgmlnext
name|P
argument_list|(
operator|(
expr|struct
name|rcbdata
operator|*
operator|,
expr|struct
name|rcbtag
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the error count. */
end_comment

begin_decl_stmt
name|int
name|sgmlgcnterr
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the current location. */
end_comment

begin_decl_stmt
name|int
name|sgmlloc
name|P
argument_list|(
operator|(
name|unsigned
name|long
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write out the SGML declaration. */
end_comment

begin_decl_stmt
name|VOID
name|sgmlwrsd
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Note subdocument capacity usage. */
end_comment

begin_decl_stmt
name|VOID
name|sgmlsubcap
name|P
argument_list|(
operator|(
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

