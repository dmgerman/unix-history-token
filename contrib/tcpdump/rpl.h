begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_RPL_H_
end_ifndef

begin_comment
comment|/*  * NOTE: the contents of this file are an interpretation of RFC6550.  *       no copyright is asserted on this file, as it transcribes  *       a public specification.  *  */
end_comment

begin_comment
comment|/*  * DIO: Updated to RFC6550, as published in 2012: section 6. (page 30)  */
end_comment

begin_define
define|#
directive|define
name|ND_RPL_MESSAGE
value|155
end_define

begin_comment
comment|/* 0x9B */
end_comment

begin_enum
enum|enum
name|ND_RPL_CODE
block|{
name|ND_RPL_DAG_IS
init|=
literal|0x00
block|,
name|ND_RPL_DAG_IO
init|=
literal|0x01
block|,
name|ND_RPL_DAO
init|=
literal|0x02
block|,
name|ND_RPL_DAO_ACK
init|=
literal|0x03
block|,
name|ND_RPL_SEC_DAG_IS
init|=
literal|0x80
block|,
name|ND_RPL_SEC_DAG_IO
init|=
literal|0x81
block|,
name|ND_RPL_SEC_DAG
init|=
literal|0x82
block|,
name|ND_RPL_SEC_DAG_ACK
init|=
literal|0x83
block|,
name|ND_RPL_SEC_CONSIST
init|=
literal|0x84
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|ND_RPL_DIO_FLAGS
block|{
name|ND_RPL_DIO_GROUNDED
init|=
literal|0x80
block|,
name|ND_RPL_DIO_DATRIG
init|=
literal|0x40
block|,
name|ND_RPL_DIO_DASUPPORT
init|=
literal|0x20
block|,
name|ND_RPL_DIO_RES4
init|=
literal|0x10
block|,
name|ND_RPL_DIO_RES3
init|=
literal|0x08
block|,
name|ND_RPL_DIO_PRF_MASK
init|=
literal|0x07
block|,
comment|/* 3-bit preference */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|DAGID_LEN
value|16
end_define

begin_comment
comment|/* section 6 of draft-ietf-roll-rpl-19 */
end_comment

begin_struct
struct|struct
name|nd_rpl_security
block|{
name|uint8_t
name|rpl_sec_t_reserved
decl_stmt|;
comment|/* bit 7 is T-bit */
name|uint8_t
name|rpl_sec_algo
decl_stmt|;
name|uint16_t
name|rpl_sec_kim_lvl_flags
decl_stmt|;
comment|/* bit 15/14, KIM */
comment|/* bit 10-8, LVL, bit 7-0 flags */
name|uint32_t
name|rpl_sec_counter
decl_stmt|;
if|#
directive|if
literal|0
block|uint8_t  rpl_sec_ki[0];
comment|/* depends upon kim */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* section 6.2.1, DODAG Information Solication (DIS_IS) */
end_comment

begin_struct
struct|struct
name|nd_rpl_dis_is
block|{
name|uint8_t
name|rpl_dis_flags
decl_stmt|;
name|uint8_t
name|rpl_dis_reserved
decl_stmt|;
if|#
directive|if
literal|0
block|uint8_t rpl_dis_options[0];
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* section 6.3.1, DODAG Information Object (DIO) */
end_comment

begin_struct
struct|struct
name|nd_rpl_dio
block|{
name|uint8_t
name|rpl_instanceid
decl_stmt|;
name|uint8_t
name|rpl_version
decl_stmt|;
name|uint16_t
name|rpl_dagrank
decl_stmt|;
name|uint8_t
name|rpl_mopprf
decl_stmt|;
comment|/* bit 7=G, 5-3=MOP, 2-0=PRF */
name|uint8_t
name|rpl_dtsn
decl_stmt|;
comment|/* Dest. Advertisement Trigger Sequence Number */
name|uint8_t
name|rpl_flags
decl_stmt|;
comment|/* no flags defined yet */
name|uint8_t
name|rpl_resv1
decl_stmt|;
name|uint8_t
name|rpl_dagid
index|[
name|DAGID_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RPL_DIO_GROUND_FLAG
value|0x80
end_define

begin_define
define|#
directive|define
name|RPL_DIO_MOP_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|RPL_DIO_MOP_MASK
value|(7<< RPL_DIO_MOP_SHIFT)
end_define

begin_define
define|#
directive|define
name|RPL_DIO_PRF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RPL_DIO_PRF_MASK
value|(7<< RPL_DIO_PRF_SHIFT)
end_define

begin_define
define|#
directive|define
name|RPL_DIO_GROUNDED
parameter_list|(
name|X
parameter_list|)
value|((X)&RPL_DIO_GROUND_FLAG)
end_define

begin_define
define|#
directive|define
name|RPL_DIO_MOP
parameter_list|(
name|X
parameter_list|)
value|(enum RPL_DIO_MOP)(((X)&RPL_DIO_MOP_MASK)>> RPL_DIO_MOP_SHIFT)
end_define

begin_define
define|#
directive|define
name|RPL_DIO_PRF
parameter_list|(
name|X
parameter_list|)
value|(((X)&RPL_DIO_PRF_MASK)>> RPL_DIO_PRF_SHIFT)
end_define

begin_enum
enum|enum
name|RPL_DIO_MOP
block|{
name|RPL_DIO_NONSTORING
init|=
literal|0x0
block|,
name|RPL_DIO_STORING
init|=
literal|0x1
block|,
name|RPL_DIO_NONSTORING_MULTICAST
init|=
literal|0x2
block|,
name|RPL_DIO_STORING_MULTICAST
init|=
literal|0x3
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|RPL_SUBOPT
block|{
name|RPL_OPT_PAD0
init|=
literal|0
block|,
name|RPL_OPT_PADN
init|=
literal|1
block|,
name|RPL_DIO_METRICS
init|=
literal|2
block|,
name|RPL_DIO_ROUTINGINFO
init|=
literal|3
block|,
name|RPL_DIO_CONFIG
init|=
literal|4
block|,
name|RPL_DAO_RPLTARGET
init|=
literal|5
block|,
name|RPL_DAO_TRANSITINFO
init|=
literal|6
block|,
name|RPL_DIO_DESTPREFIX
init|=
literal|8
block|,
name|RPL_DAO_RPLTARGET_DESC
init|=
literal|9
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|rpl_dio_genoption
block|{
name|uint8_t
name|rpl_dio_type
decl_stmt|;
name|uint8_t
name|rpl_dio_len
decl_stmt|;
comment|/* suboption length, not including type/len */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RPL_DIO_GENOPTION_LEN
value|2
end_define

begin_define
define|#
directive|define
name|RPL_DIO_LIFETIME_INFINITE
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|RPL_DIO_LIFETIME_DISCONNECT
value|0
end_define

begin_struct
struct|struct
name|rpl_dio_destprefix
block|{
name|uint8_t
name|rpl_dio_type
decl_stmt|;
name|uint8_t
name|rpl_dio_len
decl_stmt|;
name|uint8_t
name|rpl_dio_prefixlen
decl_stmt|;
comment|/* in bits */
name|uint8_t
name|rpl_dio_prf
decl_stmt|;
comment|/* flags, including Route Preference */
name|uint32_t
name|rpl_dio_prefixlifetime
decl_stmt|;
comment|/* in seconds */
if|#
directive|if
literal|0
block|uint8_t rpl_dio_prefix[0];
comment|/* variable number of bytes */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* section 6.4.1, DODAG Information Object (DIO) */
end_comment

begin_struct
struct|struct
name|nd_rpl_dao
block|{
name|uint8_t
name|rpl_instanceid
decl_stmt|;
name|uint8_t
name|rpl_flags
decl_stmt|;
comment|/* bit 7=K, 6=D */
name|uint8_t
name|rpl_resv
decl_stmt|;
name|uint8_t
name|rpl_daoseq
decl_stmt|;
name|uint8_t
name|rpl_dagid
index|[
name|DAGID_LEN
index|]
decl_stmt|;
comment|/* present when D set. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ND_RPL_DAO_MIN_LEN
value|4
end_define

begin_comment
comment|/* length without DAGID */
end_comment

begin_comment
comment|/* indicates if this DAO is to be acK'ed */
end_comment

begin_define
define|#
directive|define
name|RPL_DAO_K_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|RPL_DAO_K_MASK
value|(1<< RPL_DAO_K_SHIFT)
end_define

begin_define
define|#
directive|define
name|RPL_DAO_K
parameter_list|(
name|X
parameter_list|)
value|(((X)&RPL_DAO_K_MASK)>> RPL_DAO_K_SHIFT)
end_define

begin_comment
comment|/* indicates if the DAGID is present */
end_comment

begin_define
define|#
directive|define
name|RPL_DAO_D_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|RPL_DAO_D_MASK
value|(1<< RPL_DAO_D_SHIFT)
end_define

begin_define
define|#
directive|define
name|RPL_DAO_D
parameter_list|(
name|X
parameter_list|)
value|(((X)&RPL_DAO_D_MASK)>> RPL_DAO_D_SHIFT)
end_define

begin_struct
struct|struct
name|rpl_dao_target
block|{
name|uint8_t
name|rpl_dao_type
decl_stmt|;
name|uint8_t
name|rpl_dao_len
decl_stmt|;
name|uint8_t
name|rpl_dao_flags
decl_stmt|;
comment|/* unused */
name|uint8_t
name|rpl_dao_prefixlen
decl_stmt|;
comment|/* in bits */
if|#
directive|if
literal|0
block|uint8_t rpl_dao_prefix[0];
comment|/* variable number of bytes */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* section 6.5.1, Destination Advertisement Object Acknowledgement (DAO-ACK) */
end_comment

begin_struct
struct|struct
name|nd_rpl_daoack
block|{
name|uint8_t
name|rpl_instanceid
decl_stmt|;
name|uint8_t
name|rpl_flags
decl_stmt|;
comment|/* bit 7=D */
name|uint8_t
name|rpl_daoseq
decl_stmt|;
name|uint8_t
name|rpl_status
decl_stmt|;
name|uint8_t
name|rpl_dagid
index|[
name|DAGID_LEN
index|]
decl_stmt|;
comment|/* present when D set. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ND_RPL_DAOACK_MIN_LEN
value|4
end_define

begin_comment
comment|/* length without DAGID */
end_comment

begin_comment
comment|/* indicates if the DAGID is present */
end_comment

begin_define
define|#
directive|define
name|RPL_DAOACK_D_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|RPL_DAOACK_D_MASK
value|(1<< RPL_DAOACK_D_SHIFT)
end_define

begin_define
define|#
directive|define
name|RPL_DAOACK_D
parameter_list|(
name|X
parameter_list|)
value|(((X)&RPL_DAOACK_D_MASK)>> RPL_DAOACK_D_SHIFT)
end_define

begin_define
define|#
directive|define
name|_RPL_H_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RPL_H_ */
end_comment

begin_comment
comment|/*  * Local Variables:  * c-basic-offset:4  * c-style: whitesmith  * End:  */
end_comment

end_unit

