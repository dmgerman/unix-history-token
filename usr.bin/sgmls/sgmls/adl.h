begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ADL.H: Definitions for attribute descriptor list processing. */
end_comment

begin_comment
comment|/* N/C/SDATA external entity types for nxetype member of ne structure. */
end_comment

begin_define
define|#
directive|define
name|ESNCDATA
value|1
end_define

begin_comment
comment|/* External character data entity. */
end_comment

begin_define
define|#
directive|define
name|ESNNDATA
value|2
end_define

begin_comment
comment|/* Non-SGML data entity. */
end_comment

begin_define
define|#
directive|define
name|ESNSDATA
value|3
end_define

begin_comment
comment|/* External specific character data entity. */
end_comment

begin_define
define|#
directive|define
name|ESNSUB
value|4
end_define

begin_comment
comment|/* SGML subdocument entity. */
end_comment

begin_comment
comment|/* N/C/SDATA control block for AENTITY attributes and NDATA returns.*/
end_comment

begin_struct
struct|struct
name|ne
block|{
comment|/* N/C/SDATA entity control block. */
name|UNIV
name|neid
decl_stmt|;
comment|/* Files for NDATA entity. */
name|UNCH
modifier|*
name|nepubid
decl_stmt|;
comment|/* Public identifier if specified. */
name|UNCH
modifier|*
name|nesysid
decl_stmt|;
comment|/* System identifier if specified. */
name|PDCB
name|nedcn
decl_stmt|;
comment|/* Data content notation control block. */
name|struct
name|ad
modifier|*
name|neal
decl_stmt|;
comment|/* Data attribute list (NULL if none). */
name|UNCH
modifier|*
name|neename
decl_stmt|;
comment|/* Ptr to entity name (length and EOS). */
name|UNCH
name|nextype
decl_stmt|;
comment|/* Entity type: NDATA SDATA CDATA SUBDOC. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NESZ
value|(sizeof(struct ne))
end_define

begin_typedef
typedef|typedef
name|struct
name|ne
modifier|*
name|PNE
typedef|;
end_typedef

begin_comment
comment|/* NDATA entity control block fields. */
end_comment

begin_define
define|#
directive|define
name|NEID
parameter_list|(
name|p
parameter_list|)
value|(((PNE)p)->neid)
end_define

begin_comment
comment|/* File ID of NDATA entity. */
end_comment

begin_define
define|#
directive|define
name|NESYSID
parameter_list|(
name|p
parameter_list|)
value|(((PNE)p)->nesysid)
end_define

begin_comment
comment|/* System ID of NDATA entity. */
end_comment

begin_define
define|#
directive|define
name|NEPUBID
parameter_list|(
name|p
parameter_list|)
value|(((PNE)p)->nepubid)
end_define

begin_comment
comment|/* Public ID of NDATA entity. */
end_comment

begin_define
define|#
directive|define
name|NEDCN
parameter_list|(
name|p
parameter_list|)
value|(((PNE)p)->nedcn->ename)
end_define

begin_comment
comment|/* Data content notation name. */
end_comment

begin_define
define|#
directive|define
name|NEDCNSYSID
parameter_list|(
name|p
parameter_list|)
value|(((PNE)p)->nedcn->sysid)
end_define

begin_comment
comment|/* Notation system ID.*/
end_comment

begin_define
define|#
directive|define
name|NEDCNPUBID
parameter_list|(
name|p
parameter_list|)
value|(((PNE)p)->nedcn->pubid)
end_define

begin_comment
comment|/* Notation public ID.*/
end_comment

begin_define
define|#
directive|define
name|NEDCNDEFINED
parameter_list|(
name|p
parameter_list|)
value|(((PNE)p)->nedcn->defined)
end_define

begin_comment
comment|/* Notation defined? */
end_comment

begin_define
define|#
directive|define
name|NEDCNADL
parameter_list|(
name|p
parameter_list|)
value|(((PNE)p)->nedcn->adl)
end_define

begin_comment
comment|/* Data content notation attlist.*/
end_comment

begin_define
define|#
directive|define
name|NEENAME
parameter_list|(
name|p
parameter_list|)
value|(((PNE)p)->neename)
end_define

begin_comment
comment|/* Entity name pointer. */
end_comment

begin_define
define|#
directive|define
name|NEXTYPE
parameter_list|(
name|p
parameter_list|)
value|(((PNE)p)->nextype)
end_define

begin_comment
comment|/* External entity type. */
end_comment

begin_define
define|#
directive|define
name|NEAL
parameter_list|(
name|p
parameter_list|)
value|(((PNE)p)->neal)
end_define

begin_comment
comment|/* Data attributes (if any). */
end_comment

begin_define
define|#
directive|define
name|NEDCNMARK
parameter_list|(
name|p
parameter_list|)
value|DCNMARK(((PNE)p)->nedcn)
end_define

begin_comment
comment|/* Attribute descriptor list entry. */
end_comment

begin_struct
struct|struct
name|ad
block|{
name|UNCH
modifier|*
name|adname
decl_stmt|;
comment|/* Attribute name with length and EOS. */
name|UNCH
name|adflags
decl_stmt|;
comment|/* Attribute flags. */
name|UNCH
name|adtype
decl_stmt|;
comment|/* Value type. */
name|UNS
name|adnum
decl_stmt|;
comment|/* Group size or member pos in grp. */
name|UNS
name|adlen
decl_stmt|;
comment|/* Length of default or value (for capacity). */
name|UNCH
modifier|*
name|addef
decl_stmt|;
comment|/* Default value (NULL if REQUIRED or IMPLIED). */
union|union
block|{
name|PNE
name|n
decl_stmt|;
comment|/* AENTITY: NDATA control block. */
name|PDCB
name|x
decl_stmt|;
comment|/* ANOTEGRP: DCN control block. */
block|}
name|addata
union|;
comment|/* Special data associated with some attributes.*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ADSZ
value|(sizeof(struct ad))
end_define

begin_comment
comment|/* Size of an ad structure. */
end_comment

begin_comment
comment|/* Attribute flags for entire list adflags: ADLF. */
end_comment

begin_define
define|#
directive|define
name|ADLREQ
value|0x80
end_define

begin_comment
comment|/* Attribute list: 1=REQUIRED att defined. */
end_comment

begin_define
define|#
directive|define
name|ADLNOTE
value|0x40
end_define

begin_comment
comment|/* Attribute list: 1=NOTATION att defined. */
end_comment

begin_define
define|#
directive|define
name|ADLCONR
value|0x20
end_define

begin_comment
comment|/* Attribute list: 1=CONREF att defined. */
end_comment

begin_comment
comment|/* Attribute flags for list member adflags: ADFLAGS(n). */
end_comment

begin_define
define|#
directive|define
name|AREQ
value|0x80
end_define

begin_comment
comment|/* Attribute: 0=null; 1=required. */
end_comment

begin_define
define|#
directive|define
name|ACURRENT
value|0x40
end_define

begin_comment
comment|/* Attribute: 0=normal; 1=current. */
end_comment

begin_define
define|#
directive|define
name|AFIXED
value|0x20
end_define

begin_comment
comment|/* Attribute: 0=normal; 1=must equal default. */
end_comment

begin_define
define|#
directive|define
name|AGROUP
value|0x10
end_define

begin_comment
comment|/* Attribute: 0=single; 1=group of ad's. */
end_comment

begin_define
define|#
directive|define
name|ACONREF
value|0x08
end_define

begin_comment
comment|/* Attribute: 0=normal; 1=att is CONREF. */
end_comment

begin_define
define|#
directive|define
name|AINVALID
value|0x04
end_define

begin_comment
comment|/* Attribute: 1=value is invalid; 0=o.k. */
end_comment

begin_define
define|#
directive|define
name|AERROR
value|0x02
end_define

begin_comment
comment|/* Attribute: 1=error was specified; 0=o.k. */
end_comment

begin_define
define|#
directive|define
name|ASPEC
value|0x01
end_define

begin_comment
comment|/* Attribute: 1=value was specified; 0=default. */
end_comment

begin_comment
comment|/* Attribute types for adtype. */
end_comment

begin_define
define|#
directive|define
name|ANMTGRP
value|0x00
end_define

begin_comment
comment|/* Attribute: Name token group or member. */
end_comment

begin_define
define|#
directive|define
name|ANOTEGRP
value|0x01
end_define

begin_comment
comment|/* Attribute: Notation (name group). */
end_comment

begin_define
define|#
directive|define
name|ACHARS
value|0x02
end_define

begin_comment
comment|/* Attribute: Character string. */
end_comment

begin_define
define|#
directive|define
name|AENTITY
value|0x03
end_define

begin_comment
comment|/* Attribute: Data entity (name). */
end_comment

begin_define
define|#
directive|define
name|AID
value|0x04
end_define

begin_comment
comment|/* Attribute: ID value (name). */
end_comment

begin_define
define|#
directive|define
name|AIDREF
value|0x05
end_define

begin_comment
comment|/* Attribute: ID reference value (name). */
end_comment

begin_define
define|#
directive|define
name|ANAME
value|0x06
end_define

begin_comment
comment|/* Attribute: Name. */
end_comment

begin_define
define|#
directive|define
name|ANMTOKE
value|0x07
end_define

begin_comment
comment|/* Attribute: Name token. */
end_comment

begin_define
define|#
directive|define
name|ANUMBER
value|0x08
end_define

begin_comment
comment|/* Attribute: Number. */
end_comment

begin_define
define|#
directive|define
name|ANUTOKE
value|0x09
end_define

begin_comment
comment|/* Attribute: Number token. */
end_comment

begin_define
define|#
directive|define
name|ATKNLIST
value|0x0A
end_define

begin_comment
comment|/* Attribute:>= means value is a token list. */
end_comment

begin_define
define|#
directive|define
name|AENTITYS
value|0x0A
end_define

begin_comment
comment|/* Attribute: Data entities (name list). */
end_comment

begin_define
define|#
directive|define
name|AIDREFS
value|0x0B
end_define

begin_comment
comment|/* Attribute: ID reference value (name list). */
end_comment

begin_define
define|#
directive|define
name|ANAMES
value|0x0C
end_define

begin_comment
comment|/* Attribute: Name list. */
end_comment

begin_define
define|#
directive|define
name|ANMTOKES
value|0x0D
end_define

begin_comment
comment|/* Attribute: Name token list. */
end_comment

begin_define
define|#
directive|define
name|ANUMBERS
value|0x0E
end_define

begin_comment
comment|/* Attribute: Number list. */
end_comment

begin_define
define|#
directive|define
name|ANUTOKES
value|0x0F
end_define

begin_comment
comment|/* Attribute: Number token list. */
end_comment

begin_comment
comment|/* Field definitions for entries in an attribute list.    The first argument to all of these is the list address. */
end_comment

begin_comment
comment|/* Attribute list: flags. */
end_comment

begin_define
define|#
directive|define
name|ADLF
parameter_list|(
name|a
parameter_list|)
value|((a)[0].adflags)
end_define

begin_comment
comment|/* Attribute list: number of list members. */
end_comment

begin_define
define|#
directive|define
name|ADN
parameter_list|(
name|a
parameter_list|)
value|((a)[0].adtype)
end_define

begin_comment
comment|/* Attribute list: number of attributes. */
end_comment

begin_define
define|#
directive|define
name|AN
parameter_list|(
name|a
parameter_list|)
value|((a)[0].adnum)
end_define

begin_comment
comment|/* Nth attribute in list: name. */
end_comment

begin_define
define|#
directive|define
name|ADNAME
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|(((a)[n].adname+1))
end_define

begin_comment
comment|/* Nth att in list: number of val)ues. */
end_comment

begin_define
define|#
directive|define
name|ADNUM
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|((a)[n].adnum)
end_define

begin_comment
comment|/* Nth attribute in list: flags. */
end_comment

begin_define
define|#
directive|define
name|ADFLAGS
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|((a)[n].adflags)
end_define

begin_comment
comment|/* Nth attribute in list: type. */
end_comment

begin_define
define|#
directive|define
name|ADTYPE
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|((a)[n].adtype)
end_define

begin_comment
comment|/* Nth attribute in list: len of def or val.*/
end_comment

begin_define
define|#
directive|define
name|ADLEN
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|((a)[n].adlen)
end_define

begin_comment
comment|/* Nth attribute in list: def or value. */
end_comment

begin_define
define|#
directive|define
name|ADVAL
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|((a)[n].addef)
end_define

begin_comment
comment|/* Nth attribute in list: special data. */
end_comment

begin_define
define|#
directive|define
name|ADDATA
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|((a)[n].addata)
end_define

begin_comment
comment|/* Nth att: token at Pth pos in value. */
end_comment

begin_define
define|#
directive|define
name|ADTOKEN
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
value|(((a)[n].addef+(p)))
end_define

begin_define
define|#
directive|define
name|IDHASH
value|101
end_define

begin_comment
comment|/* Size of ID hash table.  Must be prime. */
end_comment

begin_struct
struct|struct
name|id
block|{
comment|/* ID attribute control block. */
name|struct
name|id
modifier|*
name|idnext
decl_stmt|;
comment|/* Next ID in chain. */
name|UNCH
modifier|*
name|idname
decl_stmt|;
comment|/* ID name with length prefix and EOS. */
name|UNCH
name|iddefed
decl_stmt|;
comment|/* Non-zero if it has been defined. */
name|struct
name|fwdref
modifier|*
name|idrl
decl_stmt|;
comment|/* Chain of forward references to this ID. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IDSZ
value|sizeof(struct id)
end_define

begin_typedef
typedef|typedef
name|struct
name|id
modifier|*
name|PID
typedef|;
end_typedef

begin_comment
comment|/* Ptr to ID attribute control block. */
end_comment

end_unit

