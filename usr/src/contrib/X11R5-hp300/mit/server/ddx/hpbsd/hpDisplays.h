begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * HP display types  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HPDISPLAYS_H__
end_ifndef

begin_define
define|#
directive|define
name|__HPDISPLAYS_H__
end_define

begin_comment
comment|/* allowed types for the gcid */
end_comment

begin_define
define|#
directive|define
name|GCID_GATORBOX
value|8
end_define

begin_define
define|#
directive|define
name|GCID_TOPCAT
value|9
end_define

begin_define
define|#
directive|define
name|GCID_CATSEYE
value|9
end_define

begin_define
define|#
directive|define
name|GCID_RENAISSANCE
value|10
end_define

begin_define
define|#
directive|define
name|GCID_FIREEYE
value|11
end_define

begin_define
define|#
directive|define
name|GCID_HYPERION
value|12
end_define

begin_define
define|#
directive|define
name|GCID_DAVINCI
value|14
end_define

begin_comment
comment|/* hardware ids  -- to distinguish topcats/catseyes */
end_comment

begin_define
define|#
directive|define
name|ID2_TC
value|2
end_define

begin_define
define|#
directive|define
name|ID2_LCC
value|5
end_define

begin_define
define|#
directive|define
name|ID2_HRC
value|6
end_define

begin_define
define|#
directive|define
name|ID2_HRM
value|7
end_define

begin_define
define|#
directive|define
name|ID2_CC
value|9
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|VOLATILE
value|volatile
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|VOLATILE
value|__volatile
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VOLATILE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|vu_char
value|VOLATILE u_char
end_define

begin_struct
struct|struct
name|hp_grfreg
block|{
name|char
name|gr_pad0
decl_stmt|;
name|vu_char
name|gr_id
decl_stmt|;
comment|/* +0x01 */
name|char
name|gr_pad1
index|[
literal|0x13
index|]
decl_stmt|;
name|vu_char
name|gr_id2
decl_stmt|;
comment|/* +0x15 */
name|char
name|gr_pad2
decl_stmt|;
name|vu_char
name|gr_bits
decl_stmt|;
comment|/* +0x17 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|getGpHardware
parameter_list|(
name|pScreen
parameter_list|)
define|\
value|((struct hp_grfreg *) (getPrivScreenPtr(pScreen)->pHardwareScreen))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

