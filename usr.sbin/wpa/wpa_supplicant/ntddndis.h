begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_NTDDNDIS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NTDDNDIS_H_
end_define

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Fake up some of the Windows type definitions so that the NDIS  * interface module in wpa_supplicant will build.  */
end_comment

begin_define
define|#
directive|define
name|ULONG
value|uint32_t
end_define

begin_define
define|#
directive|define
name|USHORT
value|uint16_t
end_define

begin_define
define|#
directive|define
name|UCHAR
value|uint8_t
end_define

begin_define
define|#
directive|define
name|LONG
value|int32_t
end_define

begin_define
define|#
directive|define
name|SHORT
value|int16_t
end_define

begin_define
define|#
directive|define
name|CHAR
value|int8_t
end_define

begin_define
define|#
directive|define
name|ULONGLONG
value|uint64_t
end_define

begin_define
define|#
directive|define
name|LONGLONG
value|int64_t
end_define

begin_define
define|#
directive|define
name|BOOLEAN
value|uint8_t
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|LPADAPTER
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|PTSTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|PCHAR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|OID_802_3_CURRENT_ADDRESS
value|0x01010102
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NTDDNDIS_H_ */
end_comment

end_unit

