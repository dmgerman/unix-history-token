begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ETYPE.H: Definitions for element type and group processing. */
end_comment

begin_define
define|#
directive|define
name|MCHARS
value|0x80
end_define

begin_comment
comment|/* Model: contains #CHARS. */
end_comment

begin_define
define|#
directive|define
name|MGI
value|0x40
end_define

begin_comment
comment|/* Model: contains GI names. */
end_comment

begin_define
define|#
directive|define
name|MPHRASE
value|0x20
end_define

begin_comment
comment|/* Model: first token is #CHARS. */
end_comment

begin_define
define|#
directive|define
name|MKEYWORD
value|0x1F
end_define

begin_comment
comment|/* Model: defined with single keyword. */
end_comment

begin_define
define|#
directive|define
name|MNONE
value|0x10
end_define

begin_comment
comment|/* Model: contains no GIs or #CHARS. */
end_comment

begin_define
define|#
directive|define
name|MANY
value|0x08
end_define

begin_comment
comment|/* Model: contains any GIs or #CHARS. */
end_comment

begin_define
define|#
directive|define
name|MRCDATA
value|0x04
end_define

begin_comment
comment|/* Model: contains RCDATA. */
end_comment

begin_define
define|#
directive|define
name|MCDATA
value|0x02
end_define

begin_comment
comment|/* Model: contains CDATA. */
end_comment

begin_define
define|#
directive|define
name|TOREP
value|(TOPT+TREP)
end_define

begin_comment
comment|/* 11000000 Optional and repeatable. */
end_comment

begin_define
define|#
directive|define
name|TOPT
value|0x80
end_define

begin_comment
comment|/* Token: 1=optional; 0=required. */
end_comment

begin_define
define|#
directive|define
name|TREP
value|0x40
end_define

begin_comment
comment|/* Token: 1=repeatable; 0=not. */
end_comment

begin_define
define|#
directive|define
name|TXOREP
value|(TXOPT+TXREP)
end_define

begin_comment
comment|/* * explicitly specified */
end_comment

begin_define
define|#
directive|define
name|TXOPT
value|0x20
end_define

begin_comment
comment|/* ? explicitly specified */
end_comment

begin_define
define|#
directive|define
name|TXREP
value|0x10
end_define

begin_comment
comment|/* + explicitly specified */
end_comment

begin_define
define|#
directive|define
name|TTMASK
value|0x0F
end_define

begin_comment
comment|/* 00001111 Mask for testing token type. */
end_comment

begin_define
define|#
directive|define
name|TTETD
value|4
end_define

begin_comment
comment|/* 00000100 Token is an ETD. */
end_comment

begin_define
define|#
directive|define
name|TTAND
value|3
end_define

begin_comment
comment|/* 00000011 Token is an AND group. */
end_comment

begin_define
define|#
directive|define
name|TTSEQ
value|2
end_define

begin_comment
comment|/* 00000010 Token is a sequence group. */
end_comment

begin_define
define|#
directive|define
name|TTOR
value|1
end_define

begin_comment
comment|/* 00000001 Token is an OR group. */
end_comment

begin_define
define|#
directive|define
name|TTCHARS
value|0
end_define

begin_comment
comment|/* 00000000 Token is #CHARS. */
end_comment

begin_struct
struct|struct
name|thdr
block|{
comment|/* Token header or model header. */
name|UNCH
name|ttype
decl_stmt|;
comment|/* Token type attributes or model content. */
union|union
block|{
name|int
name|tnum
decl_stmt|;
comment|/* Group token: tokens in group.  				 Model header: content tokens at any level. */
name|struct
name|etd
modifier|*
name|thetd
decl_stmt|;
comment|/* GI token: ptr to etd. */
block|}
name|tu
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|THSZ
value|(sizeof(struct thdr))
end_define

begin_define
define|#
directive|define
name|ETDHASH
value|211
end_define

begin_comment
comment|/* Size of element hash table. Must be prime. */
end_comment

begin_define
define|#
directive|define
name|SMO
value|0x40
end_define

begin_comment
comment|/* ETDMIN: Start-tag O minimization. */
end_comment

begin_define
define|#
directive|define
name|EMO
value|0x04
end_define

begin_comment
comment|/* ETDMIN: End-tag O minimization. */
end_comment

begin_define
define|#
directive|define
name|EMM
value|0x02
end_define

begin_comment
comment|/* ETDMIN: End-tag minimization explicitly 				 specified to be minus */
end_comment

begin_define
define|#
directive|define
name|ETDDCL
value|0x80
end_define

begin_comment
comment|/* ETDMIN: Element was declared. */
end_comment

begin_define
define|#
directive|define
name|ETDUSED
value|0x20
end_define

begin_comment
comment|/* ETDMIN: Element used in another declaration. */
end_comment

begin_define
define|#
directive|define
name|ETDOCC
value|0x10
end_define

begin_comment
comment|/* ETDMIN: Element occurred in document. */
end_comment

begin_struct
struct|struct
name|etd
block|{
comment|/* Element type definition. */
name|struct
name|etd
modifier|*
name|etdnext
decl_stmt|;
comment|/* Next element type definition in hash chain. */
name|UNCH
modifier|*
name|etdgi
decl_stmt|;
comment|/* GI preceded by its length, followed by EOS. */
name|UNCH
name|etdmin
decl_stmt|;
comment|/* Flag bits: minimization. */
name|UNCH
name|mark
decl_stmt|;
comment|/* Mark bit: for ambiguity checking */
name|struct
name|thdr
modifier|*
name|etdmod
decl_stmt|;
comment|/* Content model. */
name|struct
name|etd
modifier|*
modifier|*
name|etdmex
decl_stmt|;
comment|/* Minus exceptions. */
name|struct
name|etd
modifier|*
modifier|*
name|etdpex
decl_stmt|;
comment|/* Plus exceptions. */
name|struct
name|ad
modifier|*
name|adl
decl_stmt|;
comment|/* Attribute descriptor list. */
name|struct
name|entity
modifier|*
modifier|*
name|etdsrm
decl_stmt|;
comment|/* Short reference map. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ETDSZ
value|(sizeof(struct etd))
end_define

begin_typedef
typedef|typedef
name|struct
name|etd
modifier|*
name|PETD
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|struct
name|etd
name|dumetd
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of bits in a long must be>= 1<<LONGPOW */
end_comment

begin_define
define|#
directive|define
name|LONGPOW
value|5
end_define

begin_define
define|#
directive|define
name|LONGBITS
value|(1<<LONGPOW)
end_define

begin_struct
struct|struct
name|mpos
block|{
comment|/* Position of current element in model. */
name|UNCH
name|g
decl_stmt|;
comment|/* Index of this group in the model. */
name|UNCH
name|t
decl_stmt|;
comment|/* Index of the current token in this group. */
name|UNCH
name|tstart
decl_stmt|;
comment|/* Index of starting token for AND group 				 testing. */
name|unsigned
name|long
modifier|*
name|h
decl_stmt|;
comment|/* Hit bits of this group's tokens. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HITCLEAR
parameter_list|(
name|h
parameter_list|)
value|MEMZERO((UNIV)(h), grplongs*sizeof(unsigned long))
end_define

begin_define
define|#
directive|define
name|TAGCONER
value|0x01
end_define

begin_comment
comment|/* 00000001 (contersw) Tag was out of context. */
end_comment

begin_define
define|#
directive|define
name|TAGNET
value|0x02
end_define

begin_comment
comment|/* 00000010 (etisw)    Tag has NET enabled. */
end_comment

begin_define
define|#
directive|define
name|TAGPEX
value|0x04
end_define

begin_comment
comment|/* 00000100 (pexsw)    Tag was plus exception. */
end_comment

begin_define
define|#
directive|define
name|TAGREF
value|0x08
end_define

begin_comment
comment|/* 00001000 (conrefsw) Tag had CONREF or EMPTY.*/
end_comment

begin_struct
struct|struct
name|tag
block|{
comment|/* Tag control block. */
name|UNCH
name|status
decl_stmt|;
comment|/* Status of context check. */
name|UNCH
name|tflags
decl_stmt|;
comment|/* Flags: TAGCONER TAGNET TAGPEX TAGREF */
name|struct
name|etd
modifier|*
name|tetd
decl_stmt|;
comment|/* Element type definition for tag. */
name|struct
name|entity
modifier|*
modifier|*
name|tsrm
decl_stmt|;
comment|/* Current short reference map. */
name|struct
name|mpos
modifier|*
name|tpos
decl_stmt|;
comment|/* Position of next tag in this model. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RCEND
value|1
end_define

begin_comment
comment|/* No more tokens: end element and retry GI. */
end_comment

begin_define
define|#
directive|define
name|RCREQ
value|2
end_define

begin_comment
comment|/* Required GI must precede proposed GI. */
end_comment

begin_define
define|#
directive|define
name|RCMISS
value|3
end_define

begin_comment
comment|/* GI invalid: not element end; no required GI. */
end_comment

begin_define
define|#
directive|define
name|RCHIT
value|4
end_define

begin_comment
comment|/* GI is the one expected next. */
end_comment

begin_define
define|#
directive|define
name|RCMEX
value|5
end_define

begin_comment
comment|/* GI invalid: minus exception. */
end_comment

begin_define
define|#
directive|define
name|RCHITMEX
value|6
end_define

begin_comment
comment|/* RCMEX with invalid attempted minus exclusion.*/
end_comment

begin_define
define|#
directive|define
name|RCPEX
value|7
end_define

begin_comment
comment|/* GI is valid solely because of plus exclusion.*/
end_comment

begin_define
define|#
directive|define
name|RCNREQ
value|8
end_define

begin_comment
comment|/* Token is not required; can retry invalid GI. */
end_comment

end_unit

