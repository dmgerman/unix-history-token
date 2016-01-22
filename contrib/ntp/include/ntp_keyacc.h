begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  ntp_keyacc.h - key access stuff  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_KEYACC_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_KEYACC_H
end_define

begin_typedef
typedef|typedef
name|struct
name|keyaccess
name|KeyAccT
typedef|;
end_typedef

begin_struct
struct|struct
name|keyaccess
block|{
name|KeyAccT
modifier|*
name|next
decl_stmt|;
name|sockaddr_u
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_KEYACC_H */
end_comment

end_unit

