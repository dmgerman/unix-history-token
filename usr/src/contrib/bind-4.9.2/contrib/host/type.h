begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** Various new resource record type and class values. ** **	They belong in<arpa/nameser.h> ** **	@(#)type.h              e07@nikhef.nl (Eric Wassenaar) 930919 */
end_comment

begin_comment
comment|/* missing in some old versions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|T_TXT
end_ifndef

begin_define
define|#
directive|define
name|T_TXT
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined per RFC 1183 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|T_RP
end_ifndef

begin_define
define|#
directive|define
name|T_RP
value|17
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_AFSDB
end_ifndef

begin_define
define|#
directive|define
name|T_AFSDB
value|18
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_X25
end_ifndef

begin_define
define|#
directive|define
name|T_X25
value|19
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_ISDN
end_ifndef

begin_define
define|#
directive|define
name|T_ISDN
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_RT
end_ifndef

begin_define
define|#
directive|define
name|T_RT
value|21
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined per RFC 1348 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|T_NSAP
end_ifndef

begin_define
define|#
directive|define
name|T_NSAP
value|22
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_NSAPPTR
end_ifndef

begin_define
define|#
directive|define
name|T_NSAPPTR
value|23
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* never used in practice */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|C_CSNET
end_ifndef

begin_define
define|#
directive|define
name|C_CSNET
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* missing in some old versions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|C_HS
end_ifndef

begin_define
define|#
directive|define
name|C_HS
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

